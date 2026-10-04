# vibedrum

Engine for editing drum MIDI from plain language ("make my fills heavier", "make the hi hat more alive").
You are the musical brain. The engine shows you a MIDI file as a text grid and applies the edit script you write.
Genres live in knowledge packs, one folder each. Djent came first.

## Layout

- `core/`: std only C++17 library (MIDI in, analysis, grid, edit ops, MIDI out). This is what a VST3 will link. No file or audio I/O in here.
- `cli/main.cpp`: the `vibedrum` binary (show, json, apply, play, render, clip, new, selfcheck). Playback and clipboard are macOS only and stay out of core.
- `ui/`: the local page (`python3 ui/server.py`, http://localhost:8790, launch config `vibedrum-ui`). He drops or pastes a MIDI,
  it lands as `work/<song>.v0.mid`, and the page shows the newest version of the newest song with its changes against the one before.
- `docs/FORMAT.md`: the grid, ops, selectors, header. Read it before writing an edit.
- `knowledge/`: the musical knowledge, one pack per genre. Start at `knowledge/README.md`.
- `tools/check_knowledge.py`: runs every `vd` example of the knowledge docs through the engine. Run it after editing a doc.
- `demo/`: a stiff 16 bar djent song to try things on.

Build and check:

    cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release && cmake --build build && ./build/vibedrum selfcheck

## Handling a request

1. Get the file: a path he gives, `./build/vibedrum clip` (the .mid he copied in Finder), or the newest `work/<song>.v0.mid` he dropped in the UI.
2. `vibedrum show FILE --summary`, then `show FILE --bars A-B` for the bars the request touches. Short songs: just `show FILE`.
3. Pick the genre pack (`knowledge/README.md`), read its `vocabulary.md` for the words of the request, then the detail doc it points to.
4. Decide scope and interpretation yourself. The fill and section lists are candidates, check them against the grid.
   State the interpretation in one line. Ask only when two readings would give clearly different music.
5. Write the edit script to `work/<song>.<n>.txt`, apply it to `work/<song>.v<n>.mid`. Never overwrite his original.
   Each version builds on the previous one, so any step can be undone.
6. `vibedrum clip work/<song>.v<n>.mid` so he can paste the result out. `vibedrum play ... --bars A-B` only when he asks to hear it.
7. Report in musical terms, two or three lines: what changed and where.

## Rules

- Bulk ops for wide changes, grid rewrites for specific bars. Unchanged cells keep their exact timing and velocity,
  so copy rows from `show` and change only the cells you mean to.
- Count cells. A row with the wrong cell count rejects the whole script.
- The kick stays locked to the riff unless he asks otherwise. A fill keeps its landing: crash and kick on the next downbeat, or on the push.
- Code changes follow ponytail: no new dependencies, core stays std only, one self-check, shortcuts marked with `ponytail:`.
