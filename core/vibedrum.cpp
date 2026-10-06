#include "vibedrum.h"

#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <sstream>
#include <stdexcept>

namespace vd {
namespace {

// ---------- drum map

const std::pair<int, const char*> GM[] = {
    {35, "kick2"}, {36, "kick"}, {37, "rim"}, {38, "snare"}, {39, "perc_clap"}, {40, "snare2"},
    {41, "tom6"}, {42, "hh"}, {43, "tom5"}, {44, "hh_pedal"}, {45, "tom4"}, {46, "hh_open"},
    {47, "tom3"}, {48, "tom2"}, {49, "crash1"}, {50, "tom1"}, {51, "ride"}, {52, "china"},
    {53, "ride_bell"}, {54, "perc_tamb"}, {55, "splash"}, {56, "perc_cowbell"}, {57, "crash2"}, {59, "ride2"},
};

bool starts(const std::string& s, const char* p) { return s.rfind(p, 0) == 0; }

std::string lane(const Song& s, int pitch) {
    auto it = s.lanes.find(pitch);
    return it != s.lanes.end() ? it->second : "p" + std::to_string(pitch);
}

std::string low(std::string s) { for (auto& c : s) c = tolower((unsigned char)c); return s; }

std::string role(const std::string& name) {   // the lane name as written in the map, any case
    auto lane = low(name);
    if (starts(lane, "kick")) return "kick";
    if (starts(lane, "snare") || starts(lane, "rim")) return "snare";
    if (starts(lane, "hh") || starts(lane, "hat") || starts(lane, "hihat")) return "hat";
    if (starts(lane, "tom")) return "tom";
    if (starts(lane, "ride")) return "ride";
    for (auto p : {"crash", "china", "splash", "stack"}) if (starts(lane, p)) return "cym";
    return "perc";
}

int rank(const std::string& role) {   // row order, top to bottom like a drum tab
    const char* order[] = {"cym", "ride", "hat", "snare", "tom", "perc", "kick"};
    for (int i = 0; i < 7; i++) if (role == order[i]) return i;
    return 7;
}

bool glob(const char* p, const char* s) {
    if (!*p) return !*s;
    if (*p == '*') return glob(p + 1, s) || (*s && glob(p, s + 1));
    return *p == *s && glob(p + 1, s + 1);
}

std::vector<std::string> split(const std::string& s, char sep) {
    std::vector<std::string> out; std::istringstream is(s);
    for (std::string x; std::getline(is, x, sep);) if (!x.empty()) out.push_back(x);
    return out;
}

std::vector<std::string> words(const std::string& s) {
    std::vector<std::string> out; std::istringstream is(s);
    for (std::string x; is >> x;) out.push_back(x);
    return out;
}

std::string num(double v) { char b[32]; snprintf(b, sizeof b, "%g", std::round(v * 100) / 100); return b; }

// ---------- MIDI bytes

struct Reader {
    const std::vector<uint8_t>& b; size_t p = 0;
    uint8_t u8() { if (p >= b.size()) throw std::runtime_error("midi: truncated file"); return b[p++]; }
    uint32_t be(int n) { uint32_t v = 0; while (n--) v = v << 8 | u8(); return v; }
    uint32_t var() { uint32_t v = 0; for (int i = 0; i < 4; i++) { uint8_t c = u8(); v = v << 7 | (c & 0x7f); if (!(c & 0x80)) break; } return v; }
    std::vector<uint8_t> take(uint32_t n) { if (p + n > b.size()) throw std::runtime_error("midi: truncated file"); std::vector<uint8_t> v(b.begin() + p, b.begin() + p + n); p += n; return v; }
};

void putVar(std::vector<uint8_t>& o, uint32_t v) {
    if (v > 0x0fffffff) throw std::runtime_error("midi: file too long");   // a MIDI delta is 4 bytes at most, a negative one lands here too
    uint8_t buf[5]; int n = 0;
    do { buf[n++] = v & 0x7f; v >>= 7; } while (v);
    while (n--) o.push_back(buf[n] | (n ? 0x80 : 0));
}

void putBE(std::vector<uint8_t>& o, uint32_t v, int n) { while (n--) o.push_back(v >> (8 * n) & 0xff); }

void defaultMap(Song& s) { s.lanes.clear(); s.gm.clear(); for (auto& [p, l] : GM) s.lanes[p] = l; }

// ---------- bars and cells

int barOf(const std::vector<Bar>& b, int tick) {   // last bar starting at or before tick, -1 if none
    int lo = 0, hi = b.size();
    while (lo < hi) { int m = (lo + hi) / 2; if (b[m].start <= tick) lo = m + 1; else hi = m; }
    return lo - 1;
}

int cells(const Song& s, const Bar& b, int g) { return std::max(1L, ((long)b.len * g + 4 * s.ppq - 1) / (4 * s.ppq)); }

int cellOf(const Song& s, const Bar& b, int g, int tick) {
    return std::clamp((int)std::lround((tick - b.start) * g / (4.0 * s.ppq)), 0, cells(s, b, g) - 1);
}

int tickOf(const Song& s, const Bar& b, int g, int cell) { return b.start + (int)std::lround(cell * 4.0 * s.ppq / g); }

int digitOf(int vel) { return std::clamp((vel + 7) / 14, 1, 9); }
int velOf(int d) { return d == 9 ? 127 : d * 14; }

// the coarsest grid that holds every onset within ppq/24 ticks. Grid 48 always does.
int pickGrid(const Song& s, const Bar& b, const std::vector<int>& onsets) {
    for (int g : {16, 12, 24, 32, 48}) {
        if ((long)b.len * g % (4 * s.ppq)) continue;
        double cell = 4.0 * s.ppq / g; bool ok = true;
        for (int t : onsets) { double pos = t - b.start; if (std::fabs(pos - std::round(pos / cell) * cell) > s.ppq / 24.0 + 1e-9) { ok = false; break; } }
        if (ok) return g;
    }
    return (long)b.len * 96 % (4 * s.ppq) ? 16 : 96;   // ponytail: bars no grid divides (cut by a signature change) get a rounded 16 grid
}

// ---------- analysis

struct An {
    std::vector<Bar> B;
    std::vector<std::vector<const Note*>> drum, riff;   // per bar
    std::vector<std::string> keeper, feel, marker;      // per bar
    std::vector<Section> secs;
    std::vector<Span> fills;
};

An analyze(const Song& s) {
    An a; a.B = bars(s);
    int nb = a.B.size(), tol = s.ppq / 24;
    a.drum.resize(nb); a.riff.resize(nb); a.keeper.resize(nb); a.feel.resize(nb); a.marker.resize(nb);
    for (size_t ti = 0; ti < s.tracks.size(); ti++) {
        for (auto& n : s.tracks[ti].notes) {
            int b = barOf(a.B, n.tick + tol);
            if (b < 0) continue;
            if (isDrum(s, ti, n)) a.drum[b].push_back(&n);
            else if ((int)ti == s.riffTrack && (s.riffCh < 0 || n.ch == s.riffCh)) a.riff[b].push_back(&n);
        }
        for (auto& e : s.tracks[ti].events)
            if (e.bytes.size() > 2 && e.bytes[0] == 0xff && e.bytes[1] == 0x06) {
                int b = barOf(a.B, e.tick + tol);
                if (b >= 0) a.marker[b] = std::string(e.bytes.begin() + 2, e.bytes.end());
            }
    }

    // per bar: which cymbal family keeps time, and where the backbeat sits
    for (int b = 0; b < nb; b++) {
        std::map<std::string, int> fam; int strong = 0, any = 0; unsigned e8 = 0;
        for (auto n : a.drum[b]) {
            auto l = lane(s, n->pitch), r = role(l);
            if (r == "hat" || r == "ride" || r == "cym") fam[r == "hat" ? (low(l).find("open") != l.npos ? "hh_open" : "hh") : r == "ride" ? "ride" : l]++;   // open hats are their own keeper: closed verse, open chorus
            if (r == "snare") { any++; if (n->vel >= 60) { strong++; e8 |= 1u << (std::lround((n->tick - a.B[b].start) / (s.ppq / 2.0)) & 31); } }
        }
        std::string k = "none"; int kn = std::max(2, a.B[b].len / s.ppq / 2) - 1;
        for (auto& [f, c] : fam) if (c > kn) { k = f; kn = c; }
        a.keeper[b] = k;
        auto has = [&](int i) { return e8 >> i & 1; };
        a.feel[b] = a.drum[b].empty() ? "empty" : a.B[b].num != 4 || a.B[b].den != 4 ? "odd" : !any ? "open" : strong >= 8 ? "blast"
                  : has(1) && has(3) && has(5) && has(7) ? "double" : has(2) && has(6) ? "normal"
                  : has(4) && !has(2) && !has(6) ? "half" : "other";
    }

    // sections. ponytail: a cut is a keeper or feel change that persists, plus markers and meter changes.
    // Candidates only, whoever reads the grid has the last word.
    auto mode = [](const std::map<std::string, int>& m, bool skipNone) {
        std::string best = "none"; int n = 0;
        for (auto& [k, c] : m) if (c > n && !(skipNone && k == "none")) { best = k; n = c; }
        return best;
    };
    std::vector<int> cut; std::map<std::string, int> kc, fc;
    for (int b = 0; b < nb; b++) {
        bool c = b == 0 || !a.marker[b].empty() || a.B[b].num != a.B[b - 1].num || a.B[b].den != a.B[b - 1].den;
        if (!c) {
            auto run = [&](const std::vector<std::string>& v) { int n = 0; while (b + n < nb && v[b + n] == v[b]) n++; return n; };
            auto share = [&](const std::vector<std::string>& v) { int n = 0; for (int i = b; i < std::min(nb, b + 4); i++) n += v[i] == v[b]; return n; };
            c = (a.keeper[b] != mode(kc, true) && run(a.keeper) >= (a.keeper[b] == "none" ? 3 : 2))
             || (a.feel[b] != mode(fc, false) && share(a.feel) >= 3);
        }
        if (c) { cut.push_back(b); kc.clear(); fc.clear(); }
        kc[a.keeper[b]]++; fc[a.feel[b]]++;
    }
    std::map<std::string, std::string> letter;
    for (size_t i = 0; i < cut.size(); i++) {
        int f = cut[i], t = i + 1 < cut.size() ? cut[i + 1] : nb, nn = 0;
        std::map<std::string, int> k2, f2; double kicks = 0, vel = 0; std::set<std::pair<int, int>> R, K;
        auto c16 = [&](int b, const Note* n) { return (int)std::lround((n->tick - a.B[b].start) / (s.ppq / 4.0)); };
        for (int b = f; b < t; b++) {
            k2[a.keeper[b]]++; f2[a.feel[b]]++;
            for (auto n : a.drum[b]) { vel += n->vel; nn++; if (role(lane(s, n->pitch)) == "kick") { kicks++; K.insert({b, c16(b, n)}); } }
            for (auto n : a.riff[b]) R.insert({b, c16(b, n)});
        }
        Section sc{f + 1, t, a.marker[f], mode(k2, true), mode(f2, false), kicks / (t - f), nn ? vel / nn : 0, -1};
        if (!R.empty()) { int m = 0; for (auto& r : R) m += K.count(r); sc.lock = double(m) / R.size(); }
        sc.titled = !sc.name.empty();
        if (sc.name.empty()) {
            auto key = sc.keeper + "/" + sc.feel; size_t n = letter.size();
            if (!letter.count(key)) letter[key] = std::string(1, char('A' + n % 26));
            sc.name = letter[key];
        }
        a.secs.push_back(sc);
    }

    // fills. ponytail: per quarter, toms above the section's usual or a snare burst. Misses kick only fills,
    // chokes, stops and unison stabs: those are read off the grid by the LLM.
    for (auto& sc : a.secs) {
        int f = sc.from - 1, t = sc.to, qmax = 0;
        std::vector<std::vector<int>> tom(t - f), sn(t - f);
        for (int b = f; b < t; b++) {
            int q = std::max(1, (a.B[b].len + s.ppq - 1) / s.ppq); qmax = std::max(qmax, q);
            tom[b - f].assign(q, 0); sn[b - f].assign(q, 0);
            for (auto n : a.drum[b]) {
                int k = std::clamp((n->tick + tol - a.B[b].start) / s.ppq, 0, q - 1);
                auto r = role(lane(s, n->pitch));
                if (r == "tom") tom[b - f][k]++;
                if (r == "snare") sn[b - f][k]++;
            }
        }
        auto base = [&](std::vector<std::vector<int>>& v, int k, bool zeroIfShort) {   // lower median across the section
            std::vector<int> x;
            for (auto& bar : v) if (k < (int)bar.size()) x.push_back(bar[k]);
            std::sort(x.begin(), x.end());
            return x.empty() || (zeroIfShort && x.size() < 3) ? 0 : x[(x.size() - 1) / 2];
        };
        std::vector<int> bt(qmax), bs(qmax);
        for (int k = 0; k < qmax; k++) { bt[k] = base(tom, k, true); bs[k] = base(sn, k, false); }
        for (int b = f; b < t; b++) {
            int q = tom[b - f].size();
            auto hot = [&](int i) { return tom[b - f][i] > bt[i] || sn[b - f][i] >= bs[i] + 2; };
            for (int k = 0; k < q; k++) {
                if (!hot(k)) continue;
                int e = k;
                while (e + 1 < q && hot(e + 1)) e++;
                a.fills.push_back({b + 1, k + 1.0, std::min(e + 2.0, 1.0 + double(a.B[b].len) / s.ppq)});
                k = e;
            }
        }
    }
    return a;
}

}  // namespace

// ---------- public: MIDI in and out

bool isDrum(const Song& s, int track, const Note& n) { return track == s.drumTrack && (s.drumCh < 0 || n.ch == s.drumCh); }

void pickParts(Song& s, int drumTrack, int riffTrack) {
    int nt = s.tracks.size();
    auto ch9 = [&](int i) { int n = 0; for (auto& x : s.tracks[i].notes) n += x.ch == 9; return n; };
    s.drumGuess = false;
    if (drumTrack < 0 || drumTrack >= nt) {   // guess: channel 10 wins, then a track named like drums, then the busiest
        int best = 0; drumTrack = -1;
        for (int i = 0; i < nt; i++) if (ch9(i) > best) { best = ch9(i); drumTrack = i; }
        for (int i = 0; i < nt && drumTrack < 0; i++) {
            auto n = low(s.tracks[i].name);
            if (n.find("drum") != n.npos || n.find("kit") != n.npos || n.find("perc") != n.npos) drumTrack = i;
        }
        if (drumTrack < 0) {
            for (int i = 0; i < nt; i++) if (drumTrack < 0 || s.tracks[i].notes.size() > s.tracks[drumTrack].notes.size()) drumTrack = i;
            s.drumGuess = nt > 0;
        }
    }
    s.drumTrack = std::max(0, drumTrack);
    s.drumCh = nt && ch9(s.drumTrack) && ch9(s.drumTrack) < (int)s.tracks[s.drumTrack].notes.size() ? 9 : -1;   // format 0: drums share a track

    s.riffTrack = -1; s.riffCh = -1;
    if (riffTrack >= 0 && riffTrack < nt && riffTrack != s.drumTrack) { s.riffTrack = riffTrack; return; }
    std::map<std::pair<int, int>, int> count; int best = 0;   // ponytail: the busiest pitched part is taken as the riff, --riff overrides
    for (int i = 0; i < nt; i++) for (auto& n : s.tracks[i].notes) if (!isDrum(s, i, n) && n.ch != 9) count[{i, n.ch}]++;
    for (auto& [k, c] : count) if (c > best) { best = c; s.riffTrack = k.first; s.riffCh = k.second; }
}

Song parseMidi(const std::vector<uint8_t>& bytes) {
    Reader r{bytes};
    if (r.be(4) != 0x4d546864) throw std::runtime_error("midi: not a MIDI file");
    uint32_t hlen = r.be(4);
    Song s; s.format = r.be(2); r.be(2);
    int div = r.be(2);
    if (div & 0x8000) throw std::runtime_error("midi: SMPTE timing is not supported");
    s.ppq = std::max(1, div); r.p += hlen - 6;
    while (r.p + 8 <= bytes.size()) {
        uint32_t id = r.be(4), len = r.be(4);
        size_t end = std::min(bytes.size(), r.p + len);
        if (id != 0x4d54726b) { r.p = end; continue; }
        Track tr; int tick = 0; uint8_t status = 0;
        std::map<int, std::vector<size_t>> open;   // channel and pitch -> sounding notes, oldest first
        while (r.p < end) {
            int64_t d = r.var();
            if (tick + d > (1 << 30)) throw std::runtime_error("midi: file too long");
            tick += (int)d;
            uint8_t c = r.u8();
            if (c == 0xff) {
                uint8_t type = r.u8(); auto data = r.take(r.var());
                if (type == 0x2f) { tr.end = tick; continue; }
                if (type == 0x03 && tr.name.empty()) tr.name = std::string(data.begin(), data.end());
                data.insert(data.begin(), {0xff, type});
                tr.events.push_back({tick, data});
            } else if (c == 0xf0 || c == 0xf7) {
                auto data = r.take(r.var());
                data.insert(data.begin(), c);
                tr.events.push_back({tick, data});
            } else {
                uint8_t d1 = c;
                if (c & 0x80) { status = c; d1 = r.u8(); }
                if (!(status & 0x80)) throw std::runtime_error("midi: data byte without a status");
                int hi = status & 0xf0, ch = status & 0x0f, key = ch << 8 | d1;
                bool one = hi == 0xc0 || hi == 0xd0;
                uint8_t d2 = one ? 0 : r.u8();
                if (hi == 0x90 && d2 > 0) { open[key].push_back(tr.notes.size()); tr.notes.push_back({tick, -1, d1, d2, ch}); }
                else if (hi == 0x80 || hi == 0x90) { auto& o = open[key]; if (!o.empty()) { tr.notes[o.front()].dur = tick - tr.notes[o.front()].tick; o.erase(o.begin()); } }
                else tr.events.push_back({tick, one ? std::vector<uint8_t>{status, d1} : std::vector<uint8_t>{status, d1, d2}});
            }
        }
        for (auto& n : tr.notes) if (n.dur < 0) n.dur = s.ppq / 4;
        tr.end = std::max(tr.end, tick);
        r.p = end;
        s.tracks.push_back(tr);
    }
    if (s.tracks.empty()) throw std::runtime_error("midi: no tracks");
    defaultMap(s);
    pickParts(s);
    return s;
}

std::vector<uint8_t> writeMidi(const Song& s) {
    std::vector<uint8_t> o = {'M', 'T', 'h', 'd'};
    putBE(o, 6, 4); putBE(o, s.format, 2); putBE(o, s.tracks.size(), 2); putBE(o, s.ppq, 2);
    for (auto& tr : s.tracks) {
        struct Item { int tick, order; std::vector<uint8_t> bytes; };
        std::vector<Item> items;
        for (auto& e : tr.events) {
            std::vector<uint8_t> b;
            int head = e.bytes[0] == 0xff ? 2 : e.bytes[0] == 0xf0 || e.bytes[0] == 0xf7 ? 1 : 0;   // meta and sysex carry a length
            if (head) { b.assign(e.bytes.begin(), e.bytes.begin() + head); putVar(b, e.bytes.size() - head); b.insert(b.end(), e.bytes.begin() + head, e.bytes.end()); }
            else b = e.bytes;
            items.push_back({e.tick, 1, b});
        }
        for (auto& n : tr.notes) {   // at one tick: note offs, then other events, then note ons
            items.push_back({n.tick, 2, {uint8_t(0x90 | n.ch), uint8_t(n.pitch), uint8_t(n.vel)}});
            items.push_back({n.tick + std::max(1, n.dur), 0, {uint8_t(0x80 | n.ch), uint8_t(n.pitch), 0}});
        }
        std::stable_sort(items.begin(), items.end(), [](const Item& a, const Item& b) { return a.tick != b.tick ? a.tick < b.tick : a.order < b.order; });
        std::vector<uint8_t> body; int tick = 0;
        for (auto& it : items) { putVar(body, it.tick - tick); tick = it.tick; body.insert(body.end(), it.bytes.begin(), it.bytes.end()); }
        putVar(body, std::max(tr.end, tick) - tick); body.insert(body.end(), {0xff, 0x2f, 0x00});
        o.insert(o.end(), {'M', 'T', 'r', 'k'}); putBE(o, body.size(), 4); o.insert(o.end(), body.begin(), body.end());
    }
    return o;
}

Song newSong(int nbars, double bpm, int num, int den) {
    if (nbars < 1 || nbars > 10000) throw std::runtime_error("new: bars must be 1 to 10000");
    if (!(bpm >= 20 && bpm <= 400)) throw std::runtime_error("new: bpm must be 20 to 400");
    if (num < 1 || num > 32 || den < 1 || den > 64 || (den & (den - 1))) throw std::runtime_error("new: sig must be 1 to 32 over 1, 2, 4, 8, 16, 32 or 64");
    Song s;
    int us = int(60e6 / bpm), lg = 0;
    while ((1 << lg) < den) lg++;
    Track t0, t1;
    t0.events = {{0, {0xff, 0x51, uint8_t(us >> 16), uint8_t(us >> 8), uint8_t(us)}}, {0, {0xff, 0x58, uint8_t(num), uint8_t(lg), 24, 8}}};
    t1.name = "Drums"; t1.events = {{0, {0xff, 0x03, 'D', 'r', 'u', 'm', 's'}}};
    t0.end = t1.end = nbars * num * 4 * s.ppq / den;
    s.tracks = {t0, t1};
    defaultMap(s); s.drumTrack = 1; s.drumCh = -1;
    return s;
}

void loadMap(Song& s, const std::string& text) {
    std::map<int, std::string> lanes; std::map<int, int> gm;   // the song keeps its map when a line is bad
    std::istringstream in(text);
    int ln = 0;
    auto pitch = [&](const std::string& t) {   // a MIDI data byte, anything else would write a broken file
        char* e; long p = strtol(t.c_str(), &e, 10);
        if (*e || p < 0 || p > 127) throw std::runtime_error("map line " + std::to_string(ln) + ": pitch '" + t + "' is not a number from 0 to 127");
        return (int)p;
    };
    for (std::string line; std::getline(in, line);) {
        ln++;
        auto w = words(line.substr(0, line.find('#')));
        if (w.size() < 2) continue;
        int p = pitch(w[0]);
        lanes[p] = w[1];
        if (w.size() > 2) gm[p] = pitch(w[2]);
    }
    s.lanes = lanes; s.gm = gm;
}

std::vector<Bar> bars(const Song& s) {
    std::vector<std::array<int, 3>> sigs;   // tick, num, den
    long end = 0;
    for (auto& t : s.tracks) {
        end = std::max(end, (long)t.end);
        for (auto& n : t.notes) end = std::max(end, (long)n.tick + 1);
        for (auto& e : t.events)   // a denominator past 2^7 is nonsense, the event is ignored
            if (e.bytes.size() >= 4 && e.bytes[0] == 0xff && e.bytes[1] == 0x58 && e.bytes[2] && e.bytes[3] <= 7) sigs.push_back({e.tick, e.bytes[2], 1 << e.bytes[3]});
    }
    std::sort(sigs.begin(), sigs.end());
    std::vector<Bar> out; long tick = 0; int num = 4, den = 4; size_t i = 0;
    while (tick < end) {
        if (out.size() >= 100000) throw std::runtime_error("midi: file too long");
        while (i < sigs.size() && sigs[i][0] <= tick) { num = sigs[i][1]; den = sigs[i][2]; i++; }
        int len = std::max(1, num * 4 * s.ppq / den);
        if (i < sigs.size() && sigs[i][0] < tick + len) len = sigs[i][0] - tick;   // a signature change cuts the bar short
        out.push_back({(int)tick, len, num, den}); tick += len;
    }
    return out;
}

std::vector<std::pair<int, int>> tempos(const Song& s) {
    std::vector<std::pair<int, int>> t;
    for (auto& tr : s.tracks) for (auto& e : tr.events)
        if (e.bytes.size() >= 5 && e.bytes[0] == 0xff && e.bytes[1] == 0x51) t.push_back({e.tick, e.bytes[2] << 16 | e.bytes[3] << 8 | e.bytes[4]});
    std::stable_sort(t.begin(), t.end(), [](auto& a, auto& b) { return a.first < b.first; });
    if (t.empty() || t[0].first > 0) t.insert(t.begin(), {0, 500000});
    return t;
}

std::vector<Section> sections(const Song& s) { return analyze(s).secs; }
std::vector<Span> fills(const Song& s) { return analyze(s).fills; }

std::vector<std::pair<int, std::string>> rows(const Song& s) {
    std::set<int> used;
    for (size_t ti = 0; ti < s.tracks.size(); ti++) for (auto& n : s.tracks[ti].notes) if (isDrum(s, ti, n)) used.insert(n.pitch);
    std::vector<int> p(used.begin(), used.end());
    std::sort(p.begin(), p.end(), [&](int x, int y) { int rx = rank(role(lane(s, x))), ry = rank(role(lane(s, y))); return rx != ry ? rx < ry : x > y; });
    std::vector<std::pair<int, std::string>> out;
    for (int x : p) out.push_back({x, lane(s, x)});
    return out;
}

// ---------- public: show

std::string show(const Song& s, int from, int to, ShowOpts opt) {
    An a = analyze(s);
    int nb = a.B.size();
    auto T = tempos(s);
    std::ostringstream o;

    std::map<int, std::vector<int>> vels; int total = 0;
    for (auto& bar : a.drum) for (auto n : bar) { vels[n->pitch].push_back(n->vel); total++; }
    std::vector<int> pitches;
    for (auto& [p, name] : rows(s)) if (vels.count(p)) pitches.push_back(p);
    size_t W = 8;
    for (int p : pitches) W = std::max(W, lane(s, p).size() + 1 + std::to_string(p).size());

    if (opt.header) {
    o << "# vibedrum: ppq " << s.ppq << ", " << nb << " bars, drums: track " << s.drumTrack << " \""
      << (s.drumTrack < (int)s.tracks.size() ? s.tracks[s.drumTrack].name : "") << "\", " << total << " notes\n";
    if (s.drumGuess) o << "# WARNING: no channel 10 notes and no track named drums, guessed drum track " << s.drumTrack << " \"" << s.tracks[s.drumTrack].name << "\", use --track N if that is wrong\n";
    for (int i = 0; i < (int)s.tracks.size(); i++) {   // channel 10 notes on a track that was not taken as the drums
        int k = 0;
        for (auto& x : s.tracks[i].notes) k += i != s.drumTrack && x.ch == 9;
        if (k) o << "# also drums: track " << i << " \"" << s.tracks[i].name << "\" (" << k << " notes), use --track " << i << "\n";
    }
    o << "# timesig:";
    for (int b = 0; b < nb; b++) if (!b || a.B[b].num != a.B[b - 1].num || a.B[b].den != a.B[b - 1].den) o << " " << b + 1 << ":" << a.B[b].num << "/" << a.B[b].den;
    o << "\n# tempo:";
    for (size_t i = 0; i < T.size() && i < 12; i++) o << " " << std::max(1, barOf(a.B, T[i].first) + 1) << ":" << num(60e6 / T[i].second);
    if (T.size() > 12) o << " ... (" << T.size() << " changes)";
    o << "\n";
    bool anyMarker = false;
    for (int b = 0; b < nb; b++) if (!a.marker[b].empty()) { o << (anyMarker ? " " : "# markers: ") << b + 1 << ":" << a.marker[b]; anyMarker = true; }
    if (anyMarker) o << "\n";
    if (s.riffTrack >= 0) o << "# riff: track " << s.riffTrack << " \"" << s.tracks[s.riffTrack].name << "\"\n";
    o << "# lanes: pitch lane count vel min/avg/max sd\n";
    std::string unmapped, noRole;
    for (int p : pitches) {
        auto& v = vels[p]; double sum = 0, sq = 0;
        for (int x : v) sum += x;
        double avg = sum / v.size();
        for (int x : v) sq += (x - avg) * (x - avg);
        o << "#   " << p << " " << lane(s, p) << " " << v.size() << " " << *std::min_element(v.begin(), v.end()) << "/" << num(std::round(avg)) << "/"
          << *std::max_element(v.begin(), v.end()) << " " << num(std::round(std::sqrt(sq / v.size()) * 10) / 10) << "\n";
        if (!s.lanes.count(p)) unmapped += " " + std::to_string(p);
        else if (role(lane(s, p)) == "perc" && !starts(low(lane(s, p)), "perc")) noRole += " " + lane(s, p);
    }
    if (!unmapped.empty()) o << "# unmapped:" << unmapped << "\n";
    if (!noRole.empty()) o << "# note: lane names with no known role, read as perc, fills and keeper ignore them:" << noRole << "\n";
    o << "# map:";
    for (auto& [p, l] : s.lanes) o << (p == s.lanes.begin()->first ? " " : ", ") << p << " " << l;
    o << "\n# sections: name bars keeper feel kick/bar vel" << (s.riffTrack >= 0 ? " lock" : "") << "\n";
    for (auto& sc : a.secs) {
        o << "#   " << sc.name << " " << sc.from << "-" << sc.to << " " << sc.keeper << " " << sc.feel << " " << num(std::round(sc.kicks * 10) / 10) << " " << num(std::round(sc.vel));
        if (sc.lock >= 0) o << " " << num(std::round(sc.lock * 100)) << "%";
        o << "\n";
    }
    o << "# fills:";
    for (auto& f : a.fills) o << " " << f.bar << ":" << num(f.from) << "-" << num(f.to);
    o << "\n";
    }
    if (opt.summaryOnly) return o.str();

    if (to <= 0 || to > nb) to = nb;
    from = std::max(1, from);
    std::map<std::string, int> seen;   // bar content -> first bar that had it
    int runFrom = 0, runTo = 0, runRef = -1, lastGrid = 0; std::string runTag, lastSig;
    auto flush = [&] {
        if (!runFrom) return;
        o << "# bar" << (runTo > runFrom ? "s " : " ") << runFrom;
        if (runTo > runFrom) o << "-" << runTo;
        o << (runRef ? " = bar " + std::to_string(runRef) : " empty") << runTag << "\n";
        runFrom = 0;
    };
    for (int b = from - 1; b < to; b++) {
        for (auto& sc : a.secs) if (sc.from == b + 1 || (b == from - 1 && sc.from <= b + 1 && b + 1 <= sc.to)) {
            flush();
            o << "\n# --- section " << sc.name << ", bars " << sc.from << "-" << sc.to << ", keeper " << sc.keeper << ", feel " << sc.feel << "\n";
            lastGrid = 0;
        }
        std::vector<int> on;
        for (auto n : a.drum[b]) on.push_back(n->tick);
        for (auto n : a.riff[b]) on.push_back(n->tick);
        int g = pickGrid(s, a.B[b], on), n = cells(s, a.B[b], g);
        std::map<int, std::string> rows;   // pitch -> cells
        for (auto nt : a.drum[b]) {
            auto& r = rows[nt->pitch];
            if (r.empty()) r.assign(n, '-');
            char& c = r[cellOf(s, a.B[b], g, nt->tick)], d = '0' + digitOf(nt->vel);
            if (c == '-' || d > c) c = d;   // ponytail: two hits of one pitch in one cell show as the louder one
        }
        std::string tag, key = std::to_string(g);
        for (auto& f : a.fills) if (f.bar == b + 1) tag += " fill=" + num(f.from) + "-" + num(f.to);
        for (auto& [p, r] : rows) key += "/" + std::to_string(p) + r;
        std::map<int, std::string> vline;   // pitch -> exact velocities in hit order
        if (opt.exactVel) for (auto nt : a.drum[b]) vline[nt->pitch] += std::to_string(nt->vel) + " ";
        for (auto& [p, v] : vline) key += "," + v;   // with exact velocities shown, only exact repeats fold
        std::string riffRow(a.riff[b].empty() ? 0 : n, '-');
        for (auto nt : a.riff[b]) riffRow[cellOf(s, a.B[b], g, nt->tick)] = 'x';
        key += "/riff" + riffRow;   // a bar under a different riff is not a repeat
        auto it = seen.find(key);
        int ref = rows.empty() ? 0 : it != seen.end() ? it->second : -1;
        if (ref >= 0) {   // empty, or a repeat of an earlier bar
            if (runFrom && runRef == ref && runTag == tag && runTo == b) runTo = b + 1;
            else { flush(); runFrom = runTo = b + 1; runRef = ref; runTag = tag; }
            continue;
        }
        flush();
        seen[key] = b + 1;

        double us = T[0].second;
        for (auto& t : T) if (t.first <= a.B[b].start) us = t.second;
        std::string sig = std::to_string(a.B[b].num) + "/" + std::to_string(a.B[b].den) + " " + num(60e6 / us) + "bpm";
        o << "\nbar " << b + 1 << " grid=" << g;
        if (sig != lastSig || !tag.empty()) o << "   #" << (sig != lastSig ? " " + sig : "") << tag;
        o << "\n";
        auto grouped = [&](const std::string& r) { std::string x; int per = std::max(1, g / 4); for (int i = 0; i < n; i++) { if (i && i % per == 0) x += ' '; x += r[i]; } return x; };
        if (g != lastGrid) {
            int per = std::max(1, g / 4);
            o << "#" << std::string(W + 1, ' ');
            for (int i = 0; i * per < n; i++) { auto l = std::to_string(i + 1); o << l; if ((i + 1) * per < n) o << std::string(l.size() < (size_t)per + 1 ? per + 1 - l.size() : 0, ' '); }
            o << "\n";
        }
        std::vector<int> order;
        for (auto& [p, r] : rows) order.push_back(p);
        std::sort(order.begin(), order.end(), [&](int x, int y) { return std::find(pitches.begin(), pitches.end(), x) < std::find(pitches.begin(), pitches.end(), y); });
        for (int p : order) {
            std::string label = lane(s, p) + " " + std::to_string(p);
            o << label << std::string(W - label.size(), ' ') << " |" << grouped(rows[p]) << "|\n";
            if (opt.exactVel) o << "#" << std::string(W + 1, ' ') << vline[p] << "\n";
        }
        if (!riffRow.empty()) o << "# riff" << std::string(W - 6, ' ') << " |" << grouped(riffRow) << "|\n";
        lastGrid = g; lastSig = sig;
    }
    flush();
    return o.str();
}

// ---------- public: diff

std::string diff(const Song& a, const Song& b) {
    An A = analyze(a);
    int tol = a.ppq / 24, nb = A.B.size();
    std::vector<Note> x, y;
    for (size_t t = 0; t < a.tracks.size(); t++) for (auto& n : a.tracks[t].notes) if (isDrum(a, t, n)) x.push_back(n);
    for (size_t t = 0; t < b.tracks.size(); t++) for (auto& n : b.tracks[t].notes) if (isDrum(b, t, n)) y.push_back(n);
    auto ord = [](const Note& p, const Note& q) { return p.pitch != q.pitch ? p.pitch < q.pitch : p.tick < q.tick; };
    std::sort(x.begin(), x.end(), ord); std::sort(y.begin(), y.end(), ord);

    struct Lane { int add = 0, rem = 0, up = 0, down = 0, soft = 0; double upSum = 0, downSum = 0; };
    std::map<std::string, Lane> lanes; std::set<int> changed;
    int add = 0, rem = 0, up = 0, down = 0, moved = 0;
    auto bar = [&](const Note& n) { return std::clamp(barOf(A.B, n.tick + tol), 0, std::max(0, nb - 1)); };
    for (size_t i = 0, j = 0; i < x.size() || j < y.size();) {   // same pitch within the timing tolerance is the same note
        bool hx = i < x.size(), hy = j < y.size();
        if (hx && hy && x[i].pitch == y[j].pitch && std::abs(x[i].tick - y[j].tick) <= tol) {
            auto& l = lanes[lane(a, x[i].pitch)]; int dv = y[j].vel - x[i].vel;
            if (dv > 0) { l.up++; l.upSum += dv; up++; }
            if (dv < 0) { l.down++; l.downSum += dv; down++; l.soft += dv < -3; }
            if (x[i].tick != y[j].tick) moved++;
            if (dv || x[i].tick != y[j].tick) changed.insert(bar(x[i]));
            i++; j++;
        } else if (!hy || (hx && ord(x[i], y[j]))) { lanes[lane(a, x[i].pitch)].rem++; rem++; changed.insert(bar(x[i])); i++; }
        else { lanes[lane(b, y[j].pitch)].add++; add++; changed.insert(bar(y[j])); j++; }
    }

    struct Agg { int n = 0, peak = 0, last = 0, lastTick = -1; double sum = 0; };
    auto agg = [&](const std::vector<Note>& v, int from, int to, bool hands = false) {   // notes whose tick, with tolerance, falls in [from, to)
        Agg g;
        for (auto& n : v) if (from <= n.tick + tol && n.tick + tol < to) {
            if (hands) { auto r = role(lane(a, n.pitch)); if (r != "snare" && r != "tom") continue; }   // a fill is judged by its snare and tom notes
            g.n++; g.sum += n.vel; g.peak = std::max(g.peak, n.vel);
            if (n.tick > g.lastTick || (n.tick == g.lastTick && n.vel > g.last)) { g.lastTick = n.tick; g.last = n.vel; }
        }
        return g;
    };
    auto avg = [](const Agg& g) { return g.n ? num(std::round(g.sum / g.n * 10) / 10) : std::string("-"); };

    std::ostringstream o;
    o << "# diff: +" << add << " notes, -" << rem << ", " << up << " louder, " << down << " quieter, " << moved << " moved in time\n";
    if (!nb) return o.str();
    o << "# sections: name bars vel before -> after, notes before -> after\n";
    for (auto& sc : A.secs) {
        int f = A.B[sc.from - 1].start, t = A.B[sc.to - 1].start + A.B[sc.to - 1].len;
        Agg p = agg(x, f, t), q = agg(y, f, t);
        o << "#   " << sc.name << " " << sc.from << "-" << sc.to << " vel " << avg(p) << " -> " << avg(q) << ", notes " << p.n << " -> " << q.n << "\n";
    }
    o << "# lanes: added removed louder(avg) quieter(avg), quieter by more than 3\n";
    for (auto& [name, l] : lanes) if (l.add || l.rem || l.up || l.down)
        o << "#   " << name << " +" << l.add << " -" << l.rem << " " << l.up << "(" << (l.up ? "+" + num(std::round(l.upSum / l.up * 10) / 10) : "0") << ") "
          << l.down << "(" << (l.down ? num(std::round(l.downSum / l.down * 10) / 10) : "0") << "), " << l.soft << "\n";
    o << "# fills (snare and tom notes): span vel before -> after, peak, last note, notes\n";
    for (auto& f : A.fills) {
        int s0 = A.B[f.bar - 1].start, from = s0 + (int)std::lround((f.from - 1) * a.ppq), to = s0 + (int)std::lround((f.to - 1) * a.ppq);
        Agg p = agg(x, from, to, true), q = agg(y, from, to, true);
        o << "#   " << f.bar << ":" << num(f.from) << "-" << num(f.to) << " vel " << avg(p) << " -> " << avg(q) << ", peak " << p.peak << " -> " << q.peak
          << ", last " << p.last << " -> " << q.last << ", notes " << p.n << " -> " << q.n << "\n";
    }
    o << "# bars changed:";
    for (auto it = changed.begin(); it != changed.end();) {   // as ranges
        int first = *it, last = first;
        for (++it; it != changed.end() && *it == last + 1; ++it) last = *it;
        o << " " << first + 1;
        if (last > first) o << "-" << last + 1;
    }
    o << (changed.empty() ? " none\n" : "\n");
    return o.str();
}

// ---------- public: apply

std::string apply(Song& song, const std::string& script) {
    Song s = song;   // all or nothing: work on a copy
    if (s.drumTrack >= (int)s.tracks.size()) throw std::runtime_error("no drum track");
    auto B = bars(s); auto F = fills(s);
    int nb = B.size(), tol = s.ppq / 24, ln = 0;
    auto& notes = s.tracks[s.drumTrack].notes;
    int ch = s.drumCh >= 0 ? s.drumCh : 9;
    if (s.drumCh < 0 && !notes.empty()) ch = notes[0].ch;
    std::map<std::string, std::array<int, 3>> stat;   // lane -> added, removed, changed
    int nb0 = nb;

    auto fail = [&](const std::string& m) { throw std::runtime_error("line " + std::to_string(ln) + ": " + m); };
    auto drum = [&](const Note& n) { return isDrum(s, s.drumTrack, n); };
    auto drums = [&] { return std::count_if(notes.begin(), notes.end(), drum); };
    auto before = drums();
    auto pitchOf = [&](const std::string& name) {   // lane name or pitch number -> pitch. Of several pitches on one lane, the most used wins.
        if (!name.empty() && isdigit(name[0])) { int p = atoi(name.c_str()); if (p > 127) fail("bad pitch " + name); return p; }
        int best = -1, bestN = -1;
        for (auto& [p, l] : s.lanes) if (l == name) { int n = 0; for (auto& x : notes) n += x.pitch == p; if (n > bestN) { best = p; bestN = n; } }
        if (best < 0) fail("unknown lane '" + name + "'");
        return best;
    };
    auto typical = [&](int pitch) {   // median velocity of the pitch, 100 if it is new to the song
        std::vector<int> v;
        for (auto& n : notes) if (n.pitch == pitch && drum(n)) v.push_back(n.vel);
        std::sort(v.begin(), v.end());
        return v.empty() ? 100 : v[v.size() / 2];
    };
    auto erase = [&](std::set<int>& dead) {
        for (auto it = dead.rbegin(); it != dead.rend(); ++it) { stat[lane(s, notes[*it].pitch)][1]++; notes.erase(notes.begin() + *it); }
    };
    auto barList = [&](const std::string& v) {
        std::vector<int> out;
        for (auto& part : split(v, ',')) {
            auto dash = part.find('-');
            int a = atoi(part.c_str()), b = dash == part.npos ? a : atoi(part.c_str() + dash + 1);
            if (a < 1 || b < a || b > nb) fail("bars=" + part + " is outside the song, it has " + std::to_string(nb) + " bars");
            for (int i = a; i <= b; i++) out.push_back(i - 1);
        }
        return out;
    };

    static const std::map<std::string, std::string> OPS = {
        {"vel", "bars beats lanes v fills set scale add min max"}, {"ramp", "bars beats lanes v fills from to scale"},
        {"accent", "bars beats lanes v fills grid pattern mix"}, {"humanize", "bars beats lanes v fills vel time seed"},
        {"shift", "bars beats lanes v fills ticks"}, {"delete", "bars beats lanes v fills"},
        {"remap", "bars beats lanes v fills to"}, {"copy", "from to lanes"}, {"insert", "at count"},
    };

    int curBar = -1, curGrid = 16;
    std::istringstream in(script);
    for (std::string line; std::getline(in, line);) {
        ln++;
        auto tw = words(line);
        if (!tw.empty() && tw[0] == "title") {   // a MIDI marker on the bar start: the DAW shows it, and the analysis starts a section there. The text keeps any # or |.
            curBar = -1;
            int b = tw.size() > 1 ? atoi(tw[1].c_str()) - 1 : -1;
            if (b < 0 || b >= nb) fail("title needs a bar of the song, title N Some name, the song has " + std::to_string(nb) + " bars");
            std::string text;
            for (size_t i = 2; i < tw.size(); i++) text += (i > 2 ? " " : "") + tw[i];
            for (auto& tr : s.tracks) for (size_t i = tr.events.size(); i-- > 0;) {
                auto& e = tr.events[i];
                if (e.bytes.size() >= 2 && e.bytes[0] == 0xff && e.bytes[1] == 0x06 && barOf(B, e.tick + tol) == b) { tr.events.erase(tr.events.begin() + i); stat["title"][1]++; }
            }
            if (!text.empty()) {
                Event m{B[b].start, {0xff, 0x06}};
                m.bytes.insert(m.bytes.end(), text.begin(), text.end());
                s.tracks[0].events.push_back(m); stat["title"][0]++;
            }
            continue;
        }
        line = line.substr(0, line.find('#'));
        auto bar1 = line.find('|');
        if (bar1 != line.npos) {   // a grid row
            if (curBar < 0) fail("grid row outside a bar block, start with: bar N grid=G");
            auto head = words(line.substr(0, bar1));
            if (head.empty()) fail("row needs a lane name or pitch before the |");
            int pitch = pitchOf(head.back()), n = cells(s, B[curBar], curGrid);
            std::string row;
            for (char c : line.substr(bar1)) if (c != '|' && !isspace((unsigned char)c)) row += c;
            if ((int)row.size() != n) fail("bar " + std::to_string(curBar + 1) + " row " + head[0] + " has " + std::to_string(row.size()) + " cells, grid=" + std::to_string(curGrid) + " needs " + std::to_string(n));
            std::vector<std::vector<int>> occ(n);
            for (size_t i = 0; i < notes.size(); i++)
                if (drum(notes[i]) && notes[i].pitch == pitch && barOf(B, notes[i].tick + tol) == curBar) occ[cellOf(s, B[curBar], curGrid, notes[i].tick)].push_back(i);
            std::set<int> dead; int typ = typical(pitch);
            for (int c = 0; c < n; c++) {
                char x = row[c];
                if (x == '-' || x == '.') dead.insert(occ[c].begin(), occ[c].end());
                else if (x == 'x' || x == 'X' || (x >= '1' && x <= '9')) {
                    bool keep = x == 'x' || x == 'X';
                    int v = keep ? typ : velOf(x - '0');
                    if (occ[c].empty()) {
                        notes.push_back({tickOf(s, B[curBar], curGrid, c), std::max(1, std::min(s.ppq / 8, 4 * s.ppq / curGrid)), pitch, v, ch});
                        stat[lane(s, pitch)][0]++;
                    } else if (!keep) {
                        int loud = 0;
                        for (int i : occ[c]) loud = std::max(loud, notes[i].vel);
                        // the loudest hit takes the new velocity, a tight flam under it keeps its ratio
                        if (digitOf(loud) != x - '0') for (int i : occ[c]) { notes[i].vel = std::clamp(notes[i].vel * v / loud, 1, 127); stat[lane(s, pitch)][2]++; }
                    }
                } else fail(std::string("bad cell character '") + x + "', use - 1..9 x");
            }
            erase(dead);
            continue;
        }
        auto w = words(line);
        if (w.empty()) continue;
        if (w[0] == "bar") {
            if (w.size() < 2) fail("bar needs a number");
            curBar = atoi(w[1].c_str()) - 1; curGrid = 16;
            for (size_t i = 2; i < w.size(); i++) { if (!starts(w[i], "grid=")) fail("unknown argument '" + w[i] + "' for bar"); curGrid = atoi(w[i].c_str() + 5); }
            if (curBar < 0 || curBar >= nb) fail("bar " + w[1] + " does not exist, the song has " + std::to_string(nb) + " bars");
            if (curGrid < 1 || curGrid > 192) fail("bad grid");
            continue;
        }
        curBar = -1;
        auto op = OPS.find(w[0]);
        if (op == OPS.end()) fail("unknown op '" + w[0] + "'");
        auto allowed = words(op->second);
        std::map<std::string, std::string> arg;
        for (size_t i = 1; i < w.size(); i++) {
            auto eq = w[i].find('=');
            auto k = w[i].substr(0, eq);
            if (std::find(allowed.begin(), allowed.end(), k) == allowed.end()) fail("unknown argument '" + k + "' for " + w[0] + ", allowed: " + op->second);
            arg[k] = eq == w[i].npos ? "" : w[i].substr(eq + 1);
        }
        auto has = [&](const char* k) { return arg.count(k) > 0; };
        auto need = [&](const char* k) { if (!has(k)) fail(w[0] + " needs " + k + "="); };
        auto numArg = [&](const char* k, double def) {
            if (!has(k)) return def;
            char* e; double v = strtod(arg[k].c_str(), &e);
            if (arg[k].empty() || *e) fail(std::string("bad number for ") + k + "=");
            return v;
        };
        auto laneOk = [&](const Note& n) {
            if (!has("lanes")) return true;
            auto l = lane(s, n.pitch), r = role(l), p = std::to_string(n.pitch);
            for (auto& item : split(arg["lanes"], ',')) if (glob(item.c_str(), l.c_str()) || glob(item.c_str(), r.c_str()) || item == p) return true;
            return false;
        };

        if (w[0] == "insert") {   // empty bars before bar `at`, everything from there on moves later, as in a DAW
            need("at"); need("count");
            int at = (int)numArg("at", 0) - 1, k = (int)numArg("count", 0);
            if (!nb) fail("the song has no bars to insert next to");
            if (at < 0 || at > nb) fail("insert at=" + arg["at"] + " is outside the song, use 1 to " + std::to_string(nb + 1));
            if (k < 1 || k > 999) fail("insert count= takes 1 to 999 bars");
            Bar m = B[at ? at - 1 : 0];   // the new bars take the meter of the bar before them
            long add = (long)k * (m.num * 4 * s.ppq / m.den);
            if (B[nb - 1].start + B[nb - 1].len + add > (1L << 30)) fail("insert would make the song longer than 2^30 ticks");
            int t0 = at < nb ? B[at].start : B[nb - 1].start + B[nb - 1].len, d = (int)add;
            for (auto& tr : s.tracks) {
                for (auto& n : tr.notes) if (n.tick + tol >= t0) n.tick += d;
                // at bar 1 the start state (tempo, meter, names, programs) stays at tick 0 for the new bars. Titles move with their bar.
                for (auto& e : tr.events)
                    if (at ? e.tick + tol >= t0 : e.tick > 0 || (e.bytes.size() >= 2 && e.bytes[0] == 0xff && e.bytes[1] == 0x06)) e.tick += d;
                if (tr.end + tol >= t0) tr.end += d;
            }
            s.tracks[0].end = std::max(s.tracks[0].end, t0 + d);
            for (auto& f : F) if (f.bar - 1 >= at) f.bar += k;
            B = bars(s); nb = B.size();
            continue;
        }

        if (w[0] == "copy") {
            need("from"); need("to");
            auto src = barList(arg["from"]), dst = barList(arg["to"]);
            if (src.empty() || dst.empty()) fail("copy needs at least one bar in from= and in to=");
            std::vector<std::vector<Note>> snap(src.size());   // source notes, ticks relative to their bar
            for (auto& n : notes) if (drum(n) && laneOk(n)) {
                int b = barOf(B, n.tick + tol);
                for (size_t i = 0; i < src.size(); i++) if (src[i] == b) { snap[i].push_back(n); snap[i].back().tick -= B[b].start; }
            }
            for (size_t i = 0; i < dst.size(); i++) {   // the source is already snapshotted, so a destination that overlaps it is replaced like any other
                std::set<int> dead;
                for (size_t k = 0; k < notes.size(); k++) if (drum(notes[k]) && laneOk(notes[k]) && barOf(B, notes[k].tick + tol) == dst[i]) dead.insert(k);
                erase(dead);
                for (auto n : snap[i % src.size()]) {
                    if (n.tick >= B[dst[i]].len - tol) continue;
                    n.tick = std::max(0, n.tick + B[dst[i]].start);
                    notes.push_back(n); stat[lane(s, n.pitch)][0]++;
                }
            }
            continue;
        }

        // selector -> tick spans -> (note, span) hits
        std::vector<std::pair<int, int>> spans, hit;
        std::vector<int> bl;
        if (has("bars")) bl = barList(arg["bars"]); else for (int b = 0; b < nb; b++) bl.push_back(b);
        std::sort(bl.begin(), bl.end()); bl.erase(std::unique(bl.begin(), bl.end()), bl.end());
        double bf = 1, bt = 1e6;
        if (has("beats")) {
            auto dash = arg["beats"].find('-', 1);
            bf = atof(arg["beats"].c_str()); bt = dash == std::string::npos ? bf + 1 : atof(arg["beats"].c_str() + dash + 1);
            if (bf < 1 || bt <= bf) fail("beats=" + arg["beats"] + " is not FROM-TO with TO exclusive, beat 1 is the bar start");
        }
        auto window = [&](int b, double f, double t) {
            int a = B[b].start + (int)std::lround((f - 1) * s.ppq), e = std::min(B[b].start + B[b].len, B[b].start + (int)std::lround(std::min(t - 1, 1e5) * s.ppq));
            if (a < e) spans.push_back({a, e});
        };
        if (has("fills")) { for (auto& f : F) if (std::binary_search(bl.begin(), bl.end(), f.bar - 1)) window(f.bar - 1, std::max(f.from, bf), std::min(f.to, bt)); }
        else if (has("beats")) for (int b : bl) window(b, bf, bt);
        else for (int b : bl) { if (!spans.empty() && spans.back().second == B[b].start) spans.back().second += B[b].len; else spans.push_back({B[b].start, B[b].start + B[b].len}); }
        int vlo = 0, vhi = 127;
        if (has("v")) { auto dash = arg["v"].find('-'); vlo = atoi(arg["v"].c_str()); vhi = dash == std::string::npos ? vlo : atoi(arg["v"].c_str() + dash + 1); }
        for (size_t i = 0; i < notes.size(); i++) {
            auto& n = notes[i];
            if (!drum(n) || n.vel < vlo || n.vel > vhi || !laneOk(n)) continue;
            for (size_t k = 0; k < spans.size(); k++) if (spans[k].first <= n.tick + tol && n.tick + tol < spans[k].second) { hit.push_back({i, k}); break; }
        }
        auto setVel = [&](Note& n, double v) { int x = std::clamp((int)std::lround(v), 1, 127); if (x != n.vel) { n.vel = x; stat[lane(s, n.pitch)][2]++; } };

        if (w[0] == "vel") {
            double set = numArg("set", -1), scale = numArg("scale", 1), add = numArg("add", 0), lo = numArg("min", 1), hi = numArg("max", 127);
            for (auto& [i, k] : hit) setVel(notes[i], std::clamp(set >= 0 ? set : notes[i].vel * scale + add, lo, std::max(lo, hi)));
        } else if (w[0] == "ramp") {
            bool rel = has("scale");   // scale=A-B multiplies, so an accent shape survives the ramp
            double v0, v1;
            if (rel) {
                auto dash = arg["scale"].find('-', 1);
                if (dash == std::string::npos) fail("ramp scale= needs FROM-TO, for example scale=0.85-1.1");
                v0 = atof(arg["scale"].c_str()); v1 = atof(arg["scale"].c_str() + dash + 1);
            } else { need("from"); need("to"); v0 = numArg("from", 0); v1 = numArg("to", 0); }
            std::map<int, std::pair<int, int>> ext;   // span -> first and last selected tick
            for (auto& [i, k] : hit) { auto it = ext.emplace(k, std::make_pair(notes[i].tick, notes[i].tick)).first; it->second.first = std::min(it->second.first, notes[i].tick); it->second.second = std::max(it->second.second, notes[i].tick); }
            for (auto& [i, k] : hit) { auto [a, e] = ext[k]; double x = e > a ? v0 + (v1 - v0) * (notes[i].tick - a) / (e - a) : v1; setVel(notes[i], rel ? notes[i].vel * x : x); }
        } else if (w[0] == "accent") {
            need("pattern");
            int g = numArg("grid", 16); double mix = numArg("mix", 1); auto& pat = arg["pattern"];
            if (g < 1 || pat.empty()) fail("accent needs grid >= 1 and a pattern");
            for (auto& [i, k] : hit) {
                auto& n = notes[i];
                char c = pat[cellOf(s, B[barOf(B, n.tick + tol)], g, n.tick) % pat.size()];
                if (c >= '1' && c <= '9') setVel(n, n.vel + mix * (velOf(c - '0') - n.vel));
                else if (c != '-' && c != 'x') fail(std::string("bad pattern character '") + c + "'");
            }
        } else if (w[0] == "humanize") {
            // time is capped at ppq/24 so a note never leaves its cell and the bar renders the same
            int dv = numArg("vel", 0), dt = std::min((int)numArg("time", 0), tol);
            uint32_t x = (uint32_t)numArg("seed", 1) * 2654435761u + 1;
            auto rnd = [&](int n) { x ^= x << 13; x ^= x >> 17; x ^= x << 5; return n > 0 ? int(x % (2 * n + 1)) - n : 0; };
            for (auto& [i, k] : hit) {
                setVel(notes[i], notes[i].vel + rnd(dv));
                int d = rnd(dt), start = B[barOf(B, notes[i].tick + tol)].start;
                if (notes[i].tick >= start) d = std::max(d, start - notes[i].tick);   // a downbeat hit never slips in front of its bar line
                if (d) { notes[i].tick = std::max(0, notes[i].tick + d); stat[lane(s, notes[i].pitch)][2]++; }
            }
        } else if (w[0] == "shift") {
            need("ticks");
            for (auto& [i, k] : hit) { notes[i].tick = std::max(0, notes[i].tick + (int)numArg("ticks", 0)); stat[lane(s, notes[i].pitch)][2]++; }
        } else if (w[0] == "delete") {
            std::set<int> dead;
            for (auto& [i, k] : hit) dead.insert(i);
            erase(dead);
        } else if (w[0] == "remap") {
            need("to");
            int p = pitchOf(arg["to"]);
            std::set<std::pair<int, int>> taken; std::set<int> dead;   // (tick, pitch) of the target lane
            for (auto& n : notes) if (drum(n) && n.pitch == p) taken.insert({n.tick, p});
            for (auto& [i, k] : hit) if (notes[i].pitch != p) {
                if (!taken.insert({notes[i].tick, p}).second) { dead.insert(i); continue; }   // already a hit there: drop this one, two identical notes would be written
                stat[lane(s, notes[i].pitch)][1]++; notes[i].pitch = p; stat[lane(s, p)][0]++;
            }
            erase(dead);
        }
    }

    std::stable_sort(notes.begin(), notes.end(), [](const Note& a, const Note& b) { return a.tick < b.tick; });
    std::ostringstream o;
    for (auto& [l, c] : stat) if (c[0] || c[1] || c[2]) o << l << ": +" << c[0] << " -" << c[1] << " ~" << c[2] << "\n";
    if (nb != nb0) o << "bars: " << nb0 << " -> " << nb << "\n";
    if (o.str().empty()) o << "no changes\n";
    o << "notes: " << before << " -> " << drums() << "\n";
    song = std::move(s);
    return o.str();
}

}  // namespace vd
