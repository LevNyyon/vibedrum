# vibedrum

Tell Claude what to change in your drum part, in plain words. See every note on a page, hear it, and copy it back into your DAW.

> "Add a 4 bar intro with big toms." "Make the fills heavier." "Less busy in the verse."

You talk to Claude Code. The page shows what changed: new notes in green, removed notes outlined in red, softer or harder hits in amber. Every step is saved as its own version, so you can always go back.

## What you need

- A Mac. (The sound and the clipboard only work on a Mac. Windows and Linux are untested.)
- Claude Code, signed in. The Code tab of the Claude desktop app works, so does the terminal version.
- Apple's free developer tools. If they are missing, the first start opens Apple's installer for you. It takes a few minutes, once.
- A drum part from your DAW as a MIDI file. No file yet? Use `demo/pop-punk-demo.mid` or `demo/djent-demo.mid`, or ask Claude to write one from scratch.

## Set up (once)

**Option A, Terminal.** Paste this:

```
git clone https://github.com/LevNyyon/vibedrum
cd vibedrum
claude
```

**Option B, no Terminal.** On the GitHub page click Code, then Download ZIP. Unzip it, then open the unzipped folder (it is called `vibedrum-main`) in the Claude desktop app (Code tab).

## Start (every time)

Open Claude Code inside the vibedrum folder (the one with this README in it) and paste this:

```
Start vibedrum. Build it if needed and open the page. I will drop in a drum MIDI file, then tell you what to change in plain words. After each change, tell me in a line or two what you did.
```

The first start takes about half a minute while it builds. Then a page opens at http://localhost:8790.

Claude Code will ask permission before it runs commands. For this project that means starting the page (`sh start.sh`) and running `./build/vibedrum`. Say yes.

**Starting the page yourself, without Claude.** Double click `start.command` in the vibedrum folder. It opens a Terminal window and then the page. Or open Terminal in the vibedrum folder and run `sh start.sh`.
To stop it, press Ctrl+C in that Terminal window, or close the window. (When Claude started it for you, ask Claude to stop it.)
If macOS says it cannot open `start.command` (this can happen after a ZIP download), right click the file, choose Open. The `sh start.sh` route works either way.

## Use it

1. **Get your drum part out of the DAW as a .mid file.** Most DAWs let you drag the region or clip to the Desktop, or have an export MIDI option. (Not tested in every DAW. Copying notes inside the DAW does not work, DAWs keep those in a private format.)
2. **Drop the file on the page.** Or copy the file in Finder and press Cmd+V on the page.
3. **Tell Claude what to change, in Claude Code.** Not on the page. Things you can say:
   - "Make the fills heavier."
   - "The hi hat sounds robotic, make it more alive."
   - "Add a 4 bar intro with big toms and an interesting kick pattern. Call it Intro."
   - "After the intro I want a 2 bar break with big empty crashes, then the verse."
   - "More space in the verse."
   - "Remove the crash in bar 3."
   - "Go back to version 2 and try that again, less busy." (Claude builds the new version from version 2. The page compares each version with the one before it in the tab row, so the new version shows against the previous one, not against version 2.)
   - "Write me a 4 bar pop punk beat at 180 bpm." (starts from nothing)
4. **The page switches to the new version by itself.** The tabs v0, v1, v2 are every step. v0 is your original, and it is never changed.
5. **Press Play** to hear any version. The sound is the basic Mac drum kit, enough to judge the pattern. Your own drum plugin will sound different.
6. **Press Copy MIDI** when you like it. Paste it into a Finder window, then drag the file into your DAW.

Parts you name (Intro, Verse, Break) show as titles above the bars and are saved in the MIDI file as markers. Some DAWs show markers in the arrangement. Not tested in every DAW.

Every version is also a .mid file in the `work` folder inside vibedrum. Nothing is lost, and it is safe to delete.

## If something goes wrong

- **The page says "Lost the server".** Tell Claude "restart the page", or double click `start.command`, or run `sh start.sh` in Terminal.
- **Starting says something else is using http://localhost:8790.** Another program, or another copy of the vibedrum folder, is using the page's port. Quit that program, or press Ctrl+C in the Terminal window of the other copy, then start again.
- **The page did not open.** Go to http://localhost:8790 in your browser.
- **Pasting says there is no MIDI file on the clipboard.** Copy the .mid file in Finder (select it, Cmd+C). Notes copied inside a DAW can not be read.
- **The drum names look wrong, like p47.** The page expects the standard General MIDI drum layout. Some drum plugins use their own. Tell Claude which plugin you use: it can write a small map file for it (a list of which note is which drum) in the `work` folder, and the page picks it up.

## What it does and does not do

- It edits the drum track. Other tracks in the file are kept.
- It can add bars, name parts and change notes. It can not change the tempo or the time signature.
- Genre guides so far: djent and pop punk. Other styles work too, but Claude has no written guide for them, so expect less polish.
- It was built and tested with Claude Code only.
- The page runs on your Mac and your files stay on it. What you tell Claude, and the notes it reads to do the edit, go to Claude like anything else you type.

## Other AI tools

The engine is an ordinary program that reads and writes MIDI. There is no AI inside it. Any assistant that can run Terminal commands and read the instructions in `CLAUDE.md` could drive it, for example Codex CLI or Gemini CLI. They look for their own instruction file name instead of CLAUDE.md (check their docs), and none of that is tested here. The ChatGPT chat window can not run it, because it can not reach files or run programs on your Mac. You could copy the text grid in and the edit script out by hand, but that is slow and not meant for non-technical use.

## For developers

- `CLAUDE.md` is the brief Claude reads: layout, how a request is handled, the rules.
- `docs/FORMAT.md` is the text grid and the edit commands.
- `knowledge/README.md` is the genre packs.
- `core/` is a std only C++17 library, built to sit inside a plugin later. `cli/` is the `vibedrum` program. `ui/` is the page.
- Checks: `./build/vibedrum selfcheck` and `python3 tools/check_knowledge.py knowledge/*.md knowledge/*/*.md`
- cmake also works: `cmake -S . -B build -G Ninja && cmake --build build`
