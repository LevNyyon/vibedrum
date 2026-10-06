# vibedrum

Engine for editing drum MIDI from plain language ("make my fills heavier", "make the hi hat more alive").
You are the musical brain. The engine shows you a MIDI file as a text grid and applies the edit script you write.
Genres live in knowledge packs, one folder each. Djent came first.

## Layout

- `core/`: std only C++17 library (MIDI in, analysis, grid, edit ops, MIDI out). This is what a VST3 will link. No file or audio I/O in here.
- `cli/main.cpp`: the `vibedrum` binary (show, diff, json, apply, play, render, clip, new, selfcheck). Playback and clipboard are macOS only and stay out of core.
- `ui/`: the local page (`python3 ui/server.py`, http://localhost:8790, launch config `vibedrum-ui`). He drops or pastes a MIDI,
  it lands as `work/<song>.v0.mid`, and the page shows the newest version of the newest song with its changes against the one before.
- `docs/FORMAT.md`: the grid, ops, selectors, header. Read it before writing an edit.
- `knowledge/`: the musical knowledge, one pack per genre. Start at `knowledge/README.md`.
- `tools/check_knowledge.py`: runs every `vd` example of the knowledge docs through the engine. Run it after editing a doc.
- `demo/`: four demos to try things on (`.mid`, and the `.txt` script that built each): djent-demo, djent-riff-demo, pop-punk-demo, pop-punk-riff-demo. The riff ones have a guitar track.

`sh start.sh` builds the engine on the first run (clang++ only, no cmake needed), runs the self-check, starts the page and opens it.
Run twice it just reopens the page, and it refuses (exit 1, says so) when another program or another copy of this folder holds the port.
`start.command` is the same thing for double clicking in Finder. Developers can also build with
`cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release && cmake --build build && ./build/vibedrum selfcheck`.

## Starting for him

He may not be technical. Never ask him to run a command or edit a file, do it yourself.
When he says start, or opens the project, or the page says it lost the server: start the page detached, in a normal Bash call.
Never with run_in_background: that kills the server after at most 2 hours and he sees "Lost the server".

    nohup sh start.sh >/dev/null 2>&1 &
    sleep 2; curl -s http://localhost:8790/api/state

The answer must contain `"root"` with this folder's path. Empty on the very first run means the build is still going (about half a minute):
wait and ask again, and if `build/vibedrum` is still missing after a minute, run the clang++ line of `start.sh` by hand to see the error.
If the answer names another folder, or is not vibedrum's, tell him in one line that another program or another copy holds port 8790.
Then tell him in one line to drop a MIDI file on the page, or to say what he wants written from scratch.
To stop the page: `lsof -nP -tiTCP:8790 -sTCP:LISTEN` prints its PID, kill that PID only, and only after the curl shows it is this folder's server.
`README.md` is the page he reads, keep it true when behaviour changes.

## Handling a request

1. Get the file: a path he gives, `./build/vibedrum clip` (the .mid he copied in Finder), or the newest `work/<song>.v0.mid` he dropped in the UI.
   No file at all: `mkdir -p work`, `vibedrum new work/<name>.v0.mid --bars N --bpm B`, then write the part as v1.
2. `vibedrum show FILE --summary`, then `show FILE --bars A-B` for the bars the request touches. Short songs: just `show FILE`.
   Read the header first. A `# unmapped:` line, lane names that look wrong (p47, hats under a tom name), `# WARNING:` or `# also drums:`
   means the wrong track or the wrong map: tell him in one line, never carry on silently. Fix it with `--track N` on every `show` and `apply`,
   or, for a drum plugin with its own layout, a map file `work/<song>.map` (format in `docs/FORMAT.md`, `<song>` is the file name before `.v<n>.mid`)
   plus `--map` on every `show` and `apply`. The page picks the map file up by itself, but it ignores `--track`.
3. Read `knowledge/editing-principles.md`. Pick the genre pack (`knowledge/README.md`), read its `vocabulary.md` for the words of the request, then the detail doc it points to.
4. Decide scope and interpretation yourself. The fill and section lists are candidates, check them against the grid.
   State the interpretation in one line. Ask only when two readings would give clearly different music.
5. Write the edit script to `work/<song>.<n>.txt`, apply it to `work/<song>.v<n>.mid`. Never overwrite his original.
   Each version builds on the previous one, so any step can be undone.
6. Judge your own result before he does: `vibedrum diff ORIGINAL RESULT` and `vibedrum show RESULT --vel` on the changed bars,
   then run the acceptance tests at the end of `knowledge/editing-principles.md`. If one fails, fix the script and apply again.
7. `vibedrum clip work/<song>.v<n>.mid` so he can paste the result out. `vibedrum play ... --bars A-B` only when he asks to hear it.
8. Report in musical terms, two or three lines: what changed, where, and anything changed outside the scope he named.

## Rules

- Bulk ops for wide changes, grid rewrites for specific bars. Unchanged cells keep their exact timing and velocity,
  so copy rows from `show` and change only the cells you mean to.
- Count cells. A row with the wrong cell count rejects the whole script.
- A part you add, or one he names, gets a `title` (what it is, in his words: "Intro, big toms"), and so does the part after it,
  so each title ends where its part ends. New bars come from `insert`, never from rewriting bars he already has.
- The kick stays locked to the riff unless he asks otherwise. A fill keeps its landing: crash and kick on the next downbeat, or on the push.
- Code changes follow ponytail: no new dependencies, core stays std only, one self-check, shortcuts marked with `ponytail:`.
