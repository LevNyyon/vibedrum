# vibedrum format

One text format, both directions. `vibedrum show` prints it, `vibedrum apply` reads it.
Everything `show` prints is a valid edit script that changes nothing, so an edit is:
copy the bars you want, change cells, add bulk ops, apply.

## Grid

```
bar 17 grid=16   # 4/4 140bpm sec=B fill=3-5
#            1    2    3    4
china 52   |9--- 9--- 9--- 9---|
snare 38   |---- ---- 9--- --37|
kick 36    |9-99 --9- 9--9 9-9-|
# riff     |x-xx --x- x--x x-x-|
```

- One row per pitch: `<lane> <pitch> |cells|`. Spaces and extra `|` inside the cells are ignored.
  The pitch may be left out when the lane name is unambiguous.
- `grid=G`: one cell is 1/G of a whole note. 16 = sixteenths, 32 = thirty-seconds,
  12 = eighth triplets, 24 = sixteenth triplets (sextuplets), 48 = thirty-second triplets.
  Cells per bar = G * num / den: 16 in 4/4 at grid=16, 14 in 7/8, 32 in 4/4 at grid=32.
- A beat is always a quarter note. 4/4 spans beats 1 to 5, 7/8 spans 1 to 4.5.
- Cell characters: `-` rest. `1` to `9` hit, velocity = digit * 14 (9 = 127).
  `x` hit that keeps its velocity (on an empty cell: the lane's typical velocity).
  Shown digit bands: 1 = 1-20, 2 = 21-34, 3 = 35-48, 4 = 49-62, 5 = 63-76, 6 = 77-90,
  7 = 91-104, 8 = 105-118, 9 = 119-127.
- `# riff` is read only: onsets of the main pitched track (guitar or bass) when the file has one.
- `# bar 18 = bar 17` means the bar is cell-identical to an earlier one. To edit it, write a full `bar 18 grid=G` block.
- `show` picks the coarsest grid that holds every onset of the bar. You may write a bar at any grid.

### How a bar block is applied

Each cell is compared with the current song rendered at the same grid.

- Same character: the note is untouched, exact velocity and micro timing survive.
- Digit changed: velocity is set, timing kept.
- Hit to `-`: note deleted.
- `-` to hit: note added exactly on the grid line.
- Rows you do not write are untouched. A row of only `-` clears that pitch in that bar.
- A row with the wrong cell count rejects the whole script. Nothing is written.

## Bulk ops

```
<op> [selector...] [args...]
```

Selector, all parts optional, combined with AND:

| part | meaning |
|---|---|
| `bars=17-24,33` | bars, 1 based. Default: every bar. |
| `beats=3-5` | inside each selected bar, from beat 3 up to but not including beat 5. Fractions allowed: `beats=4.5-5`. `beats=4` means 4-5. |
| `fills` | the fill spans listed in the `show` header (within `bars=` if given). |
| `lanes=hh*,snare,36` | comma list. Each item matches a lane name, a role, or a pitch. `*` is a wildcard. Default: every drum note. |
| `v=1-60` | only notes whose velocity is in the range. |

Roles: `kick`, `snare` (snare and rim lanes), `hat` (hh lanes), `tom`, `ride`, `cym` (crash, china, splash, stack), `perc`.

Ops, run top to bottom, each sees the result of the ones before:

| op | effect |
|---|---|
| `vel <sel> [set=N] [scale=F] [add=N] [min=N] [max=N]` | velocity = set, or v * scale + add, then clamped to min..max |
| `ramp <sel> from=N to=N` | linear velocity ramp over time, restarted in each selected span (each fill, each beats window, each contiguous bar range) |
| `accent <sel> grid=G pattern=9575 [mix=F]` | cyclic velocity pattern by cell position in the bar. Pattern digits as in the grid, `-` leaves a step alone. mix 0..1 blends toward the pattern (default 1). |
| `humanize <sel> [vel=N] [time=N] [seed=N]` | random plus or minus N velocity and plus or minus N ticks, repeatable per seed. time is capped at ppq/24 (20 ticks at 480 ppq) so a note never leaves its cell. |
| `shift <sel> ticks=N` | move notes later (negative: earlier) |
| `delete <sel>` | remove notes |
| `remap <sel> to=<lane or pitch>` | change the pitch, for example closed hat to open hat |
| `copy from=17-20 to=21-28 [lanes=...]` | replace the destination bars (those lanes) with the source bars, tiled |

Fill spans and sections are computed once from the song as it was before the script.

## Lanes (built in General MIDI map)

| pitch | lane | pitch | lane |
|---|---|---|---|
| 36 | kick | 46 | hh_open |
| 35 | kick2 | 49 | crash1 |
| 38 | snare | 57 | crash2 |
| 40 | snare2 | 52 | china |
| 37 | rim | 55 | splash |
| 42 | hh | 51 | ride |
| 44 | hh_pedal | 53 | ride_bell |
| 50 | tom1 (highest) | 59 | ride2 |
| 48 | tom2 | 54 | perc_tamb |
| 47 | tom3 | 56 | perc_cowbell |
| 45 | tom4 | 39 | perc_clap |
| 43 | tom5 (floor) | other | p<pitch>, reported as unmapped |
| 41 | tom6 (low floor) | | |

A custom map replaces this: `--map file`, lines of `<pitch> <lane> [gm pitch for playback]`.
The lane name prefix sets the role: kick, snare, rim, hh, tom, ride, crash, china, splash, stack. Anything else is perc.

## The show header

```
# lanes: pitch lane count vel min/avg/max sd     how each lane is played. sd near 0 = machine gun.
# sections: name bars keeper feel kick/bar vel lock
# fills: 8:3-5 16:1-5                            bar:fromBeat-toBeat
```

- keeper: the cymbal family that keeps time in the section (hh, ride, china, crash1, ...).
- feel: `normal` (snare on 2 and 4), `half` (snare on 3), `double` (snare on every offbeat eighth), `blast`, `open` (no snare), `odd` (not 4/4), `other`.
- lock: share of riff onsets that land together with a kick.
- Sections and fills are heuristics. They are candidates, the reader of the grid has the last word.

## CLI

```
vibedrum show  in.mid [--bars 17-24] [--summary] [--map FILE] [--track N] [--riff N]
vibedrum apply in.mid edits.txt -o out.mid [--map FILE] [--track N]
vibedrum play  in.mid [--bars 17-24] [--loop] [--drums-only] [--gain 0.5]
vibedrum clip                 # path of the .mid file copied in Finder
vibedrum clip  out.mid        # put out.mid on the clipboard, paste it into Finder or the DAW
vibedrum new   out.mid [--bars 16] [--bpm 140] [--sig 4/4]
vibedrum selfcheck
```
