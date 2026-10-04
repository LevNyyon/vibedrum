// vibedrum core: drum MIDI in, text grid out, edit script in, MIDI out.
// std only, no file or audio I/O, so a VST3 can link it as is. Format: docs/FORMAT.md
#pragma once
#include <cstdint>
#include <map>
#include <string>
#include <utility>
#include <vector>

namespace vd {

struct Note  { int tick, dur, pitch, vel, ch; };
struct Event { int tick; std::vector<uint8_t> bytes; };   // any non-note event, raw: channel msg, FF type data, F0 data
struct Track { std::string name; std::vector<Event> events; std::vector<Note> notes; int end = 0; };
struct Bar   { int start, len, num, den; };
struct Span  { int bar; double from, to; };               // bar 1 based, beats 1 based in quarter notes, to exclusive
struct Section { int from, to; std::string name, keeper, feel; double kicks, vel, lock; };

struct Song {
    int format = 1, ppq = 480;
    std::vector<Track> tracks;
    int drumTrack = 0, drumCh = -1;      // drumCh -1: every channel of that track
    int riffTrack = -1, riffCh = -1;     // the pitched part shown as the read only riff row, -1: none
    std::map<int, std::string> lanes;    // pitch -> lane name (the drum map)
    std::map<int, int> gm;               // pitch -> General MIDI pitch, for playback of custom maps
};

Song parseMidi(const std::vector<uint8_t>& bytes);        // throws std::runtime_error
std::vector<uint8_t> writeMidi(const Song&);
Song newSong(int bars, double bpm, int num, int den);
void loadMap(Song&, const std::string& text);             // lines "<pitch> <lane> [gm pitch]", replaces the GM default
void pickParts(Song&, int drumTrack = -1, int riffTrack = -1);   // -1: guess

bool isDrum(const Song&, int track, const Note&);
std::vector<Bar> bars(const Song&);
std::vector<std::pair<int, int>> tempos(const Song&);     // tick, microseconds per quarter
std::vector<Section> sections(const Song&);
std::vector<Span> fills(const Song&);
std::vector<std::pair<int, std::string>> rows(const Song&);   // drum pitches in use with lane names, top to bottom as show prints them

struct ShowOpts { bool summaryOnly = false, header = true, exactVel = false; };   // exactVel: a comment line of exact velocities under each row
std::string show(const Song&, int barFrom = 1, int barTo = 0, ShowOpts = {});
std::string diff(const Song& before, const Song& after);    // what an edit did, in numbers: per section, lane, fill and bar
std::string apply(Song&, const std::string& script);      // returns the change summary; throws with a line number and leaves the song untouched

}  // namespace vd
