// vibedrum CLI: show, json, apply, play, render, clip, new, selfcheck. Usage and format: docs/FORMAT.md
#include "vibedrum.h"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>

#ifdef __APPLE__
#include <AudioToolbox/AudioToolbox.h>
#include <unistd.h>
#endif

struct Args { std::vector<std::string> pos; std::map<std::string, std::string> opt; };

static std::vector<uint8_t> slurp(const std::string& path) {
    std::istream* in = &std::cin; std::ifstream f;
    if (path != "-") { f.open(path, std::ios::binary); if (!f) throw std::runtime_error("cannot read " + path); in = &f; }
    return {std::istreambuf_iterator<char>(*in), {}};
}

static vd::Song load(const Args& a, size_t which = 0) {
    if (a.pos.size() <= which) throw std::runtime_error("which MIDI file?");
    auto s = vd::parseMidi(slurp(a.pos[which]));
    if (a.opt.count("map")) { auto m = slurp(a.opt.at("map")); vd::loadMap(s, {m.begin(), m.end()}); }
    if (a.opt.count("track") || a.opt.count("riff"))
        vd::pickParts(s, a.opt.count("track") ? atoi(a.opt.at("track").c_str()) : -1, a.opt.count("riff") ? atoi(a.opt.at("riff").c_str()) : -1);
    return s;
}

static std::vector<std::pair<int, int>> barRanges(const Args& a) {   // --bars 17-24 or 17 or 4-5,12-13. None: the whole song.
    std::vector<std::pair<int, int>> out;
    std::string v = a.opt.count("bars") ? a.opt.at("bars") : "";
    for (size_t p = 0; p < v.size();) {
        size_t q = std::min(v.find(',', p), v.size());
        std::string part = v.substr(p, q - p); auto dash = part.find('-');
        int from = atoi(part.c_str()), to = dash == part.npos ? from : atoi(part.c_str() + dash + 1);
        if (from < 1 || to < from) throw std::runtime_error("bad --bars " + part + ", use 17-24 or 4-5,12-13");
        out.push_back({from, to}); p = q + 1;
    }
    if (out.empty()) out.push_back({1, 0});
    return out;
}

// ponytail: plays through the built in macOS General MIDI synth, enough to judge a pattern.
// Real kit sounds come when the core sits in a plugin in front of a drum sampler.
static int play(const vd::Song& s, int from, int to, bool loop, bool drumsOnly, double gain) {
#ifdef __APPLE__
    auto B = vd::bars(s);
    if (B.empty()) throw std::runtime_error("nothing to play");
    if (to <= 0 || to > (int)B.size()) to = B.size();
    from = std::min(std::max(1, from), to);
    int t0 = B[from - 1].start, t1 = B[to - 1].start + B[to - 1].len, early = s.ppq / 24;
    double q = s.ppq, bpm = 120;

    MusicSequence seq; MusicTrack tempo;
    NewMusicSequence(&seq); MusicSequenceGetTempoTrack(seq, &tempo);
    for (auto& [tick, us] : vd::tempos(s)) if (tick <= t0) bpm = 60e6 / us;
    MusicTrackNewExtendedTempoEvent(tempo, 0, bpm);
    for (auto& [tick, us] : vd::tempos(s)) if (tick > t0 && tick < t1) MusicTrackNewExtendedTempoEvent(tempo, (tick - t0) / q, 60e6 / us);
    for (size_t ti = 0; ti < s.tracks.size(); ti++) {
        MusicTrack tr; MusicSequenceNewTrack(seq, &tr);
        for (auto& e : s.tracks[ti].events) if (e.bytes.size() == 2 && (e.bytes[0] & 0xf0) == 0xc0 && e.tick < t1) {
            MIDIChannelMessage m{e.bytes[0], e.bytes[1], 0, 0};
            MusicTrackNewMIDIChannelEvent(tr, std::max(0, e.tick - t0) / q, &m);
        }
        for (auto& n : s.tracks[ti].notes) {
            bool drum = vd::isDrum(s, ti, n);
            if (n.tick < t0 - early || n.tick >= t1 - early || (drumsOnly && !drum)) continue;
            auto gm = s.gm.find(n.pitch);
            MIDINoteMessage m{UInt8(drum ? 9 : n.ch), UInt8(drum && gm != s.gm.end() ? gm->second : n.pitch), UInt8(std::max(1.0, n.vel * gain)), 0, Float32(n.dur / q)};
            MusicTrackNewMIDINoteEvent(tr, std::max(0, n.tick - t0) / q, &m);
        }
    }
    MusicPlayer p; NewMusicPlayer(&p);
    OSStatus err = MusicPlayerSetSequence(p, seq);
    if (!err) err = MusicPlayerPreroll(p);
    if (!err) err = MusicPlayerStart(p);
    if (err) throw std::runtime_error("playback failed, OSStatus " + std::to_string(err));
    printf("playing bars %d-%d at %g bpm%s, ctrl-c stops\n", from, to, bpm, loop ? ", looping" : "");
    double len = (t1 - t0) / q;
    for (MusicTimeStamp now = 0;; usleep(10000)) {
        MusicPlayerGetTime(p, &now);
        if (loop && now >= len) MusicPlayerSetTime(p, 0);
        if (!loop && now >= len + 2) break;   // two beats of cymbal tail
    }
    MusicPlayerStop(p); DisposeMusicPlayer(p); DisposeMusicSequence(seq);
    return 0;
#else
    throw std::runtime_error("play is macOS only, open the MIDI file in a DAW");
#endif
}

// render: the same General MIDI synth as play, offline into a WAV file, so a pattern can be sent and heard anywhere.
// ponytail: stock GM kit, same ceiling as play. A sampled kit means a SoundFont or the plugin in front of a drum sampler.
static int render(const vd::Song& s, const std::string& out, int from, int to, bool drumsOnly, double gain) {
#ifdef __APPLE__
    auto B = vd::bars(s);
    if (B.empty()) throw std::runtime_error("nothing to render");
    if (to <= 0 || to > (int)B.size()) to = B.size();
    from = std::min(std::max(1, from), to);
    int t0 = B[from - 1].start, t1 = B[to - 1].start + B[to - 1].len, early = s.ppq / 24;
    auto T = vd::tempos(s);
    auto sec = [&](int tick) {   // seconds after t0, through the tempo map
        double us = 500000, t = 0; int at = t0;
        for (auto& [tk, u] : T) if (tk <= t0) us = u;
        for (auto& [tk, u] : T) { if (tk <= at) continue; if (tk >= tick) break; t += (tk - at) * us / 1e6 / s.ppq; at = tk; us = u; }
        return t + (tick - at) * us / 1e6 / s.ppq;
    };

    AudioStreamBasicDescription fmt{44100, kAudioFormatLinearPCM, kAudioFormatFlagsNativeFloatPacked | kAudioFormatFlagIsNonInterleaved, 4, 1, 4, 2, 32, 0};
    auto frame = [&](int tick) { return std::max(0L, std::lround(sec(tick) * fmt.mSampleRate)); };
    struct Ev { long frame; UInt8 st, d1, d2; };
    std::vector<Ev> ev;
    for (size_t ti = 0; ti < s.tracks.size(); ti++) {
        for (auto& e : s.tracks[ti].events) if (e.bytes.size() == 2 && (e.bytes[0] & 0xf0) == 0xc0 && e.tick < t1) ev.push_back({frame(e.tick), e.bytes[0], e.bytes[1], 0});
        for (auto& n : s.tracks[ti].notes) {
            bool drum = vd::isDrum(s, ti, n);
            if (n.tick < t0 - early || n.tick >= t1 - early || (drumsOnly && !drum)) continue;
            auto gm = s.gm.find(n.pitch);
            UInt8 ch = drum ? 9 : n.ch, p = drum && gm != s.gm.end() ? gm->second : n.pitch;
            long on = frame(n.tick);
            ev.push_back({on, UInt8(0x90 | ch), p, UInt8(std::clamp(int(n.vel * gain), 1, 127))});
            ev.push_back({std::max(on + 1, frame(n.tick + n.dur)), UInt8(0x80 | ch), p, 0});
        }
    }
    std::stable_sort(ev.begin(), ev.end(), [](const Ev& a, const Ev& b) { return a.frame < b.frame; });

    AudioComponentDescription d{kAudioUnitType_MusicDevice, kAudioUnitSubType_DLSSynth, kAudioUnitManufacturer_Apple, 0, 0};
    AudioComponent c = AudioComponentFindNext(nullptr, &d);
    AudioUnit u;
    if (!c || AudioComponentInstanceNew(c, &u)) throw std::runtime_error("no General MIDI synth");
    UInt32 one = 1;
    AudioUnitSetProperty(u, kAudioUnitProperty_OfflineRender, kAudioUnitScope_Global, 0, &one, sizeof one);
    OSStatus err = AudioUnitSetProperty(u, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Output, 0, &fmt, sizeof fmt);
    if (!err) err = AudioUnitInitialize(u);
    if (err) throw std::runtime_error("synth setup failed, OSStatus " + std::to_string(err));

    AudioStreamBasicDescription wav{fmt.mSampleRate, kAudioFormatLinearPCM, kLinearPCMFormatFlagIsSignedInteger | kLinearPCMFormatFlagIsPacked, 4, 1, 4, 2, 16, 0};
    CFURLRef url = CFURLCreateFromFileSystemRepresentation(nullptr, (const UInt8*)out.c_str(), out.size(), false);
    ExtAudioFileRef f;
    err = ExtAudioFileCreateWithURL(url, kAudioFileWAVEType, &wav, nullptr, kAudioFileFlags_EraseFile, &f);
    CFRelease(url);
    if (!err) err = ExtAudioFileSetProperty(f, kExtAudioFileProperty_ClientDataFormat, sizeof fmt, &fmt);
    if (err) throw std::runtime_error("cannot write " + out + ", OSStatus " + std::to_string(err));

    const UInt32 N = 512;
    std::vector<float> L(N), R(N);
    struct { UInt32 n; AudioBuffer b[2]; } abl;   // an AudioBufferList with room for two channels
    long total = std::lround((sec(t1) + 2) * fmt.mSampleRate);   // two seconds of cymbal tail
    size_t k = 0;
    for (long at = 0; at < total; at += N) {
        for (; k < ev.size() && ev[k].frame < at + N; k++) MusicDeviceMIDIEvent(u, ev[k].st, ev[k].d1, ev[k].d2, UInt32(ev[k].frame - at));
        abl.n = 2; abl.b[0] = {1, N * 4, L.data()}; abl.b[1] = {1, N * 4, R.data()};
        AudioTimeStamp ts{}; ts.mSampleTime = at; ts.mFlags = kAudioTimeStampSampleTimeValid;
        AudioUnitRenderActionFlags fl = 0;
        if ((err = AudioUnitRender(u, &fl, &ts, 0, N, (AudioBufferList*)&abl)) || (err = ExtAudioFileWrite(f, N, (AudioBufferList*)&abl)))
            throw std::runtime_error("render failed, OSStatus " + std::to_string(err));
    }
    ExtAudioFileDispose(f); AudioUnitUninitialize(u); AudioComponentInstanceDispose(u);
    printf("rendered bars %d-%d to %s, %.1f s\n", from, to, out.c_str(), total / fmt.mSampleRate);
    return 0;
#else
    throw std::runtime_error("render is macOS only, open the MIDI file in a DAW");
#endif
}

// json: the drum notes at their exact ticks, for the UI piano roll (ui/).
static std::string json(const vd::Song& s) {
    auto n = [](long x) { return std::to_string(x); };
    auto close = [](std::string& o) { if (o.back() == ',') o.back() = ']'; else o += ']'; };
    std::string o = "{\"ppq\":" + n(s.ppq) + ",\"bars\":[";
    for (auto& b : vd::bars(s)) o += "[" + n(b.start) + "," + n(b.len) + "," + n(b.num) + "," + n(b.den) + "],";
    close(o); o += ",\"rows\":[";
    for (auto& [p, lane] : vd::rows(s)) {
        std::string q;
        for (char c : lane) { if (c == '"' || c == '\\') q += '\\'; q += c; }
        o += "[" + n(p) + ",\"" + q + "\"],";
    }
    close(o); o += ",\"notes\":[";
    for (size_t ti = 0; ti < s.tracks.size(); ti++) for (auto& x : s.tracks[ti].notes)
        if (vd::isDrum(s, ti, x)) o += "[" + n(x.tick) + "," + n(x.dur) + "," + n(x.pitch) + "," + n(x.vel) + "],";
    close(o);
    return o + "}\n";
}

// clip: the macOS clipboard as the way in and out. No argument: print the path of the .mid file copied in Finder.
// With a file: put it on the clipboard, ready to paste into Finder or a DAW that accepts pasted files.
// ponytail: file references only. Notes copied inside a DAW piano roll use a private format per DAW, add per DAW when needed.
static int clip(const Args& a) {
    auto run = [](const std::string& cmd) {
        std::string out; char buf[1024];
        FILE* p = popen(cmd.c_str(), "r");
        for (size_t n; p && (n = fread(buf, 1, sizeof buf, p)) > 0;) out.append(buf, n);
        int rc = p ? pclose(p) : 1;
        while (!out.empty() && out.back() == '\n') out.pop_back();
        return rc ? std::string() : out;
    };
    if (a.pos.empty()) {
        auto path = run("osascript -e 'POSIX path of (the clipboard as «class furl»)' 2>/dev/null");
        if (path.empty() || access(path.c_str(), R_OK)) throw std::runtime_error("no file on the clipboard, copy a .mid file in Finder first");   // text also coerces to a path, so check it exists
        puts(path.c_str());
        return 0;
    }
    char* abs = realpath(a.pos[0].c_str(), nullptr);
    if (!abs) throw std::runtime_error("cannot find " + a.pos[0]);
    std::string q;
    for (char c : std::string(abs)) q += c == '\'' ? std::string("'\\''") : std::string(1, c);
    free(abs);
    run("osascript -e 'on run argv' -e 'set the clipboard to POSIX file (item 1 of argv)' -e 'end run' '" + q + "'");
    printf("on the clipboard: %s\n", a.pos[0].c_str());
    return 0;
}

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "selfcheck FAILED, line %d: %s\n", __LINE__, #c); return 1; } } while (0)

static int selfcheck() {
    auto same = [](const std::vector<vd::Note>& a, const std::vector<vd::Note>& b) {
        if (a.size() != b.size()) return false;
        for (size_t i = 0; i < a.size(); i++) if (a[i].tick != b[i].tick || a[i].dur != b[i].dur || a[i].pitch != b[i].pitch || a[i].vel != b[i].vel) return false;
        return true;
    };
    auto count = [](const vd::Song& s, int lo, int hi, int vel = -1) { int n = 0; for (auto& x : s.tracks[s.drumTrack].notes) n += x.pitch >= lo && x.pitch <= hi && (vel < 0 || x.vel == vel); return n; };

    // three groove bars and a fill bar, written as grid
    auto s = vd::newSong(4, 140, 4, 4);
    std::string groove = "hh 42 |9595 9595 9595 9595|\nsnare 38 |---- 9--- ---- 9---|\nkick 36 |9--9 ---- 9-9- ----|\n", script;
    for (int b = 1; b <= 3; b++) script += "bar " + std::to_string(b) + " grid=16\n" + groove;
    script += "bar 4 grid=16\nhh 42 |9595 9595 ---- ----|\nsnare |---- 9--- 99-- ----|\ntom1 50 |---- ---- --77 ----|\ntom5 43 |---- ---- ---- 7777|\nkick 36 |9--9 ---- ---- ----|\n";
    vd::apply(s, script);
    auto N = [&]() -> std::vector<vd::Note>& { return s.tracks[s.drumTrack].notes; };   // apply swaps the song, so no reference is held across it
    CHECK(N().size() == 85);

    // MIDI bytes round trip
    auto s2 = vd::parseMidi(vd::writeMidi(s));
    CHECK(s2.drumTrack == 1 && same(s2.tracks[1].notes, N()) && vd::show(s2) == vd::show(s));

    // the fill is found, and only there
    auto f = vd::fills(s);
    CHECK(f.size() == 1 && f[0].bar == 4 && f[0].from == 3 && f[0].to == 5);

    // show output is a script that changes nothing
    auto before = N();
    CHECK(vd::show(s).find("# bars 2-3 = bar 1") != std::string::npos);
    vd::apply(s, vd::show(s));
    CHECK(same(N(), before));

    // an unchanged cell keeps its micro timing and exact velocity, a new cell lands on the grid
    N()[0].tick = 7; N()[0].vel = 101;   // first note is the bar 1 hat, shown as 7
    vd::apply(s, "bar 1 grid=16\nhh 42 |7595 9595 9595 9595|\nkick 36 |9--9 ---- 9-9- 9---|\n");
    CHECK(N().size() == 86);
    bool kept = false, added = false;
    for (auto& n : N()) { kept |= n.pitch == 42 && n.tick == 7 && n.vel == 101; added |= n.pitch == 36 && n.tick == 3 * 480 && n.vel == 127; }
    CHECK(kept && added);

    // bulk op on the detected fill touches only what the selector names
    vd::apply(s, "vel fills lanes=tom set=120\n");
    CHECK(count(s, 43, 50, 120) == 6 && count(s, 42, 42, 70) == 8 * 3 + 4);

    // copy tiles a lane, a bad row rejects the whole script
    vd::apply(s, "copy from=4 to=2 lanes=tom\n");
    CHECK(count(s, 43, 50) == 12);
    before = N();
    try { vd::apply(s, "delete bars=1\nbar 1 grid=16\nkick 36 |9--9|\n"); CHECK(false); } catch (std::runtime_error&) {}
    CHECK(same(N(), before));

    // a pitched track becomes the riff row, and kicks on its onsets read as full lock
    vd::Track g; g.name = "Guitar";
    for (int t : {0, 360, 960, 1200, 1440}) g.notes.push_back({t, 100, 40, 100, 0});
    s.tracks.push_back(g);
    vd::pickParts(s);
    CHECK(s.drumTrack == 1 && s.riffTrack == 2);
    CHECK(vd::show(s).find("# riff") != std::string::npos && vd::sections(s)[0].lock == 1);

    puts("selfcheck ok");
    return 0;
}

int main(int argc, char** argv) {
    Args a; std::string cmd = argc > 1 ? argv[1] : "";
    for (int i = 2; i < argc; i++) {
        std::string x = argv[i];
        if (x == "--summary" || x == "--loop" || x == "--drums-only" || x == "--vel") a.opt[x.substr(2)] = "1";
        else if (x.rfind("--", 0) == 0 && i + 1 < argc) a.opt[x.substr(2)] = argv[++i];
        else if (x == "-o" && i + 1 < argc) a.opt["o"] = argv[++i];
        else a.pos.push_back(x);
    }
    auto opt = [&](const char* k, const char* def) { return a.opt.count(k) ? a.opt[k] : std::string(def); };
    try {
        auto ranges = barRanges(a);
        if (ranges.size() > 1 && (cmd == "play" || cmd == "render")) throw std::runtime_error(cmd + " takes one bar range");
        int from = ranges[0].first, to = ranges[0].second;
        if (cmd == "show") {
            auto s = load(a);
            for (size_t i = 0; i < ranges.size(); i++)
                std::cout << vd::show(s, ranges[i].first, ranges[i].second, {a.opt.count("summary") > 0, i == 0, a.opt.count("vel") > 0});
        }
        else if (cmd == "json") std::cout << json(load(a));
        else if (cmd == "diff") std::cout << vd::diff(load(a, 0), load(a, 1));
        else if (cmd == "apply") {
            if (a.pos.size() < 2 || !a.opt.count("o")) throw std::runtime_error("usage: vibedrum apply in.mid edits.txt -o out.mid");
            auto s = load(a); auto script = slurp(a.pos[1]);
            std::cout << vd::apply(s, {script.begin(), script.end()});
            auto bytes = vd::writeMidi(s);
            std::ofstream(a.opt["o"], std::ios::binary).write((const char*)bytes.data(), bytes.size());
        } else if (cmd == "play") return play(load(a), from, to, a.opt.count("loop"), a.opt.count("drums-only"), atof(opt("gain", "1").c_str()));
        else if (cmd == "render") {
            if (!a.opt.count("o")) throw std::runtime_error("usage: vibedrum render in.mid -o out.wav [--bars 17-24] [--drums-only] [--gain 1]");
            return render(load(a), a.opt["o"], from, to, a.opt.count("drums-only"), atof(opt("gain", "1").c_str()));
        } else if (cmd == "new") {
            if (a.pos.empty()) throw std::runtime_error("usage: vibedrum new out.mid [--bars 16] [--bpm 140] [--sig 4/4]");
            auto sig = opt("sig", "4/4"); auto slash = sig.find('/');
            auto bytes = vd::writeMidi(vd::newSong(atoi(opt("bars", "16").c_str()), atof(opt("bpm", "140").c_str()), atoi(sig.c_str()), slash == sig.npos ? 4 : atoi(sig.c_str() + slash + 1)));
            std::ofstream(a.pos[0], std::ios::binary).write((const char*)bytes.data(), bytes.size());
        } else if (cmd == "clip") return clip(a);
        else if (cmd == "selfcheck") return selfcheck();
        else { fputs("usage: vibedrum show|json|diff|apply|play|render|clip|new|selfcheck ...   see docs/FORMAT.md\n", stderr); return 2; }
    } catch (std::exception& e) {
        fprintf(stderr, "vibedrum: %s\n", e.what());
        return 1;
    }
    return 0;
}
