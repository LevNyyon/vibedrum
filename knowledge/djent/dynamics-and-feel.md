# Dynamics and feel: velocity, articulation, micro timing

Scope: djent and progressive metalcore drum parts. Units: velocity 1-127, grid cells, beats (quarter notes), ticks at 480 ppq. Cell numbers are grid=16 indexes 0-15 as in grooves.md: beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12. A grid digit d is velocity d*14 (9 = 127), and `accent` writes the same digits. `[n]` = source in section 11. "unconfirmed" = working default, no source found. "Principle N" = rule N of knowledge/editing-principles.md. Every recipe here obeys it.

Selectors: closed hat `lanes=42`, open hat `lanes=46`, foot `lanes=44`. `lanes=hat` selects all three at once, so a level or a spread meant for the stick hat also lands on the opening and the foot: name the pitch (principle 14). Ghosts `lanes=38 v=1-62`, backbeats `lanes=38 v=100-127`. Inside fill spans soft snare notes are fill notes, not ghosts: keep fill bars out of ghost ops. Give every op a `lanes=` part: without one it hits every drum note. `accent`, `vel` and `ramp` only change notes that exist. An op that matches nothing is silent: read the `~` count `apply` prints for the lane.

Order inside one script (principle 11). A whole part `accent` or a `vel set=` after `humanize` erases the spread, a gesture before `humanize` is blurred by it, and scaling or spread carries notes across the walls. So:

1. Notes: bar blocks, `copy`, `remap`, `delete`. A bar block that edits a bar a `copy` writes into goes after that `copy`.
2. Level: the base shape (`accent` over the whole part) and `vel set= scale= min= max=`.
3. `humanize`: one `vel=` run and one `time=` run per lane per section. A second run stacks on the first. To redo one, apply the new script to the version before it.
4. Designed gestures: `accent` on single cells, `vel add=`, `ramp scale=`. On a version that is already humanized these go straight on top.
5. Wall clamps: `vel ... min=` or `max=` on one pitch, with a `v=` band or a `beats=` window that holds only the notes meant (principle 9).
6. `shift` last: a note shifted more than 20 ticks early leaves its cell and `beats=` windows stop finding it.

Sizes (principle 12): a designed difference is 10 velocity or more. One digit (14) is the safe unit, under 7 is the same sample. `humanize vel=` stays at or under half the smallest designed difference: 4 next to digit steps and 10 point gestures. `ramp from= to=` writes absolute values and erases the accent shape: on a shaped part use `ramp scale=A-B` (principle 13). Check every edit with `show FILE --vel --bars A-B`: it prints the exact velocities under each row, in hit order. A digit is a band 14 wide, so a digit that changes at a band edge (90 against 91) is not a gesture. Timing is never printed.

## 1. Velocity ranges per lane

| lane | hit | velocity | digit | healthy sd | basis |
|---|---|---|---|---|---|
| kick 36 | hit that lands on a `# riff` x | 112-127, default 120 and up | 8-9 | 0-4 | [17][18][21], exact band unconfirmed |
| kick 36 | notes of a run (4+ adjacent cells at grid=32 or 24) | first note 112-127, the rest 98-112 with the weak foot 14 lower | 7-9 | 3-6 | the numbers of grooves.md section 6; [18][19] softer strokes for evenness, numbers unconfirmed |
| snare 38 | backbeat, rimshot | 116-127 | 8-9 | 2-5 | [1][2][3][17] |
| snare 38 | blast, fast alternating singles | 100-115 alternating, 115-127 when it has to cut | 7-9 | 5-8 | low [3][23], high [2][4] |
| snare 38 | ghost | 25-50, up to 58 in a dense mix, never 60 or more (section 9) | 2-4 | 4-9 | [1][5][15], 40-70 in [4] |
| snare 38 | flam grace | 45-75 light, 84-104 heavy flat flam | 3-7 | | [7] says slightly quieter than the main, numbers unconfirmed |
| rim 37 | cross stick, clean sections | 85-110 | 6-8 | 4-7 | unconfirmed |
| hh 42 | shoulder accent | 100-118 | 7-8 | lane total 10-20 | [1][5][10][11] |
| hh 42 | tip | 60-99 | 5-7 | | [1][15] |
| hh 42 | "e" and "a" of sixteenths | 55-85: about 70 one handed, about 84 two handed (section 3) | 4-6 | | unconfirmed |
| hh_open 46 | sloshy keeper on quarters or eighths | 95-115 | 7-8 | 5-9 | usage [18], numbers unconfirmed |
| hh_open 46 | single offbeat opening | 98-112 | 7-8 | | unconfirmed |
| hh_pedal 44 | foot chick | 42-70 as a metronome under a ride, china or crash keeper, 70-85 when it has to close an open hat or keep time alone in a fill | 3-6 | 3-6 | usage [9][11][17][20], numbers unconfirmed |
| ride 51 | bow | 84-112 as the keeper of a heavy section, 70-84 in clean passages | 5-8 | 8-14 | unconfirmed |
| ride_bell 53 | bell | 100-122 | 7-9 | 4-8 | unconfirmed |
| crash1 49, crash2 57 | section start | 119-127 | 9 | | bands unconfirmed |
| crash1 49, crash2 57 | landing inside a section, accent with the riff | 105-120, never above the start of its section (principle 4) | 8 | 4-8 | under 127 per [6], bands unconfirmed |
| crash1 49 | crash keeper on quarters or eighths | 95-115 | 7-8 | 6-10 | unconfirmed |
| china 52 | quarter note keeper | 105-124, phrase starts up to 127 | 8-9 | 4-8 | unconfirmed |
| splash 55 | short accent | 90-112 | 7-8 | | unconfirmed |
| tom1 to tom6 | fill notes | 85-127, the other hand 10-25 under the leading hand | 6-9 | 6-12 | weak hand lower [6], band unconfirmed |

How this style differs from rock, funk and pop programming:

- Kick and backbeat are sample reinforced on the records: Haake describes the album drum sound as close mics mixed with close mic samples and the room [18], he rimshots every snare and calls Meshuggah "not a dynamic band" [17], Garstka: "you don't get dynamics with bass drums" [21]. Kick and backbeat therefore live in digits 8-9 with sd under 5. That is correct, do not "fix" it.
- One single value is still wrong: an identical velocity fires one sample over and over [22][23]. Guides alternate backbeats inside 120-127 [3], or keep normal backbeats at 115-120 and save 125-127 for blasts that must cut [2]. 110-120 is closer to a real hard hit than 127 in most libraries [6].
- General guides put primary kicks at 100-115, secondary kicks at 75-95 and backbeats at 100-120 [5]. Too soft for this style: do not apply that to kicks that double the riff (unconfirmed, follows from [17][21]).
- The dynamic range lives in four places: hats and ride (15-45 units between tip and shoulder), ghosts (25-50 under a 116+ backbeat), tom fills (a direction, the other hand 10-25 lower; [6] gives 5-25), cymbal choice and crash velocity.
- So a feel request edits hats, cymbals, ghosts and toms first. Change kick or backbeat velocity only for "tighter", "punchier", "more aggressive", "softer".
- Ceiling (principle 2): a lane with min = max = 127 cannot be raised. `vel min=` and `set=127` do nothing there, and "louder" is not a true report. The lever is contrast: the hits that should land stay at full, what surrounds them drops 10 to 15 (the keeper cymbal between phrase starts, the inner crashes, the tips of the hat, the ghosts).

## 2. Machine gun: reading it and curing it

Header line `# lanes: pitch lane count vel min/avg/max sd`. Machine gun = sd under 3, or min = max, or every cell of the lane in the section shows one digit (the header is song wide: for one section read `show --vel --bars`). The snare lane mixes two bands: sd under 6 means no ghosts exist, sd 30+ built from only two digits means each band is still a machine gun. sd finds a flat lane. It is not the test of a cure: `humanize` on a one beat pattern reaches any sd and is still a one beat loop (principle 8), and `humanize vel=N` alone adds an sd of only about 0.6 N. A cure is a shape, then a small spread, then the loop test of section 6. A flat lane outside the request is not cured: one line in the report. Add `bars=` to every op in the table.

| lane | verdict at sd under 3 | cure |
|---|---|---|
| kick on riff | correct | none. If asked for less robotic: `humanize lanes=kick vel=3`, never `time=` |
| kick run at grid=32 | fix | strong foot, weak foot, on the beats of the run only (here beat 4): `accent beats=4-5 lanes=kick grid=32 pattern=87` (112 and 98, the numbers of grooves.md section 6), then the first note back up: `vel beats=4-4.125 lanes=kick set=127`. Run that starts on an odd cell: `pattern=78`. Kicks outside the run keep their level |
| backbeat | nearly correct | `humanize lanes=38 v=100-127 vel=3`, then the wall `vel lanes=38 v=100-127 min=116` |
| blast snare on eighths | fix | `accent lanes=38 v=90-127 grid=16 pattern=8-7- mix=0.8` (115 and 104 from a flat 127 [3][23]), `humanize lanes=38 v=90-127 vel=4`. Blast that has to cut: `pattern=9-8-` (127 and 115 [2][4]). Snares on the odd cells: `-8-7`. Blast written at grid=32: same patterns with `grid=32` |
| ghosts | fix | pairs first, in bar blocks: digit 2 then digit 3 (28, 42). Then `humanize lanes=38 v=1-62 vel=5` and the wall `vel lanes=38 v=1-62 min=25 max=58` (section 9) |
| hh, ride keeper | fix, this is the main case | rung 1 of the ladder in section 10: base row, `humanize lanes=42 vel=4`, 2 bar cell (section 3) |
| china or crash keeper on quarters | fix. Flat at 127 it is the ceiling case | body down 15, phrase starts at full: `accent lanes=china grid=16 pattern=8---` (112), `humanize lanes=china vel=4`, then for each phrase start inside the section (bar 5 of an 8 bar section) `vel bars=5 beats=1-1.25 lanes=china set=127`. The section start keeps its crash. Crash keeper: `lanes=crash1`, `pattern=7---`, phrase starts `set=120`. A quarter note anchor stays plain between phrase starts: do not invent more |
| toms and snare in fills | fix, one fill at a time (principle 3) | hands: `accent bars=N beats=A-B lanes=38,tom v=1-118 grid=16 pattern=87` (leading hand 112, other hand 98. `grid=32` for a 32nd fill, `pattern=8-7-` for an eighth note fill. `v=1-118` keeps a backbeat inside the window out). Direction, graded by the slot of the fill: `ramp bars=N beats=A-B lanes=38,tom v=1-118 scale=0.88-1.0` for a 1 beat pickup inside a phrase, `scale=0.9-1.08` for a phrase ending fill, `scale=0.92-1.16` for the fill into a new section or the last fill of the song. The ramp already makes every note different: no `humanize`. No `remap`: every drum keeps its voice. Never one op on the bulk `fills` selector: it pastes one size on every slot |

## 3. Hat and ride accent patterns

Mechanics: an accent is the shoulder of the stick on the edge, a non accent is the tip on top of the hat, and easing the pedal a little makes the accent bigger [10][11]. Samplers ship these as edge and tip articulations [12]. The built in map has one closed pitch (42), so shoulder versus tip is velocity only: 100 and up reads as shoulder, 99 and down as tip. That line is a wall (principle 9): no scale, lift or spread may carry a shoulder under 100 or a tip over 99. Every hat part needs a hierarchy of hits [5]. Offbeat hits sit below on beat hits by default [1][5][9]. Sixteenth hats at djent tempos are two handed (section 4): `8676` is the default there, the one hand rows are for parts under about 110 bpm. The rows below are base rows: step 2 of the order, before `humanize`.

| part | `accent grid=16 pattern=` | velocities | when |
|---|---|---|---|
| quarters | `8---7---` | 112, 98 | keeper over a polymetric kick, hand stays in 4/4 [18][20] |
| eighths, downbeat accent | `8-6-` | 112, 84 | default: shoulder on the beat, tip on the "and" [5][10] |
| eighths, hot | `8-7-` | 112, 98 | loud chorus, the 110 and 95 advice [1] |
| eighths, upbeat accent | `6-8-` | 84, 112 | accent placement from [10]. Offbeat drive, the open hat on the "and" does the same job louder (feel unconfirmed) |
| sixteenths, one hand | `8565` | 112, 70, 84, 70 | 9575 with the beat and the "and" one step lower |
| sixteenths, one hand, 2 beat cycle | `75658565` | beats 2 and 4 strongest | high low medium low, very high low medium low, measured on a one handed part [13] |
| sixteenths, one hand, 1 bar cycle | `7565856575658575` | last "and" lifted | leads into the next bar |
| sixteenths, two hands | `8676` | 112, 84, 98, 84 | section 4, no hat on snare cells |
| sixteenths, accent every 3rd cell | `8558558558558555` | 112, 70 | 3+3+3+3+4, accents on cells 0 3 6 9 12: follows a riff grouped in threes (unconfirmed for this style) |

A base row loops after one beat (or one bar) however large its sd is. One row tiled over a section plus `humanize` is the "accent pattern plus randomizer" sound. So every base row gets a 2 bar cell on top: one weak cell per bar goes one digit up, a different cell in odd and in even bars. These are gestures (step 4, after `humanize`), and "odd" counts from the first bar of the section:

| part | odd bars of the section | even bars |
|---|---|---|
| eighths `8-6-` | the last "and": `pattern=--------------7-` | the "and" of 3: `pattern=----------7-----` |
| sixteenths, two hands `8676` | the last "a": `pattern=---------------7` | the "a" of 3: `pattern=-----------7----` |
| sixteenths, one hand | base row `7565856575658575` | base row `75658565` (both before `humanize`) |
| quarters | none | none: a quarter anchor stays plain, its designed cell is the phrase start (section 2) |

The lifted cell is exactly 98: still a tip, and 10 or more over the tips around it (84 plus or minus 4). One lifted cell per bar. A base row that holds a 7 (`8-7-`, `8676`, the one hand cycles) puts tips at 98 before the spread, so it needs the wall right after `humanize`: `vel S lanes=42 v=91-104 max=99`. Where that cell is inside a fill or under a crash there is no note and nothing happens: the fill is that bar's difference. Why never `9575`: 127 on a closed hat fires the hardest sample on every beat and competes with the snare. A part that already has a shape: `mix=0.5` to `0.7` on the base row keeps part of it. Ride: the same rows and cells on `lanes=51`, the bow has no wall at 100. Bell hits on the beat are another part: only on request.

## 4. One handed versus two handed sixteenths

- One handed: the hat hand plays every cell, including the snare cells. Natural shape `8565` or `75658565`: accent on the beat, medium on the "and", lowest on "e" and "a" [13]. The measured case is 96 bpm [13] and most players top out near 100 [24]. Above about 110 bpm assume sixteenth hats are two handed (threshold unconfirmed). That covers most djent tempos.
- Two handed (RLRL): right hand on the beat and the "and", left hand on "e" and "a", one digit lower ([6][8] give 5-25). The right hand leaves for the backbeat, so the snare cell has no hat [9]. Shape `8676` with a hole: flatter (28 units of range against 42).
- Both: no hats during a tom fill, the hands are busy [8]. At most two hand lanes sound on one cell [6].
- A file that has hats on the snare cells of two handed sixteenths: deleting them is a limb fix ("more human"), not part of any other feel request. Shape what is there and mention it.

```vd
# bar 1 one handed (100 bpm), bar 2 two handed (140 bpm): no hat on the snare cells 4 and 12
bar 1 grid=16
#            1    2    3    4
hh 42      |7565 8565 7565 8565|
snare 38   |---- 9--- ---- 9---|
kick 36    |9--9 --9- 9-9- ----|
bar 2 grid=16
hh 42      |8676 -676 8676 -676|
snare 38   |---- 9--- ---- 9---|
kick 36    |9--9 --9- 9-9- ----|
```

## 5. Open hat, pedal hat, mixing articulations

- Offbeat opening: `remap` one closed hat on the "and" of 4 (beat 4.5, cell 14) to `hh_open`, in the 2nd bar of each 4 bar phrase. If that cell is inside a fill or has no hat, the `remap` matches nothing: leave that bar out, or on "more" take the "and" of 2 (cell 6). Velocity 98-112 (placement and numbers unconfirmed). The note keeps the velocity it had as a closed hat, so set it after the `remap`, on `lanes=46`. An opening is the accent of its bar: keep it out of the closed hat's spread and out of a quieter repeat.
- Choke: open and closed hats share a choke group [9]. The next hat position after an opening (normally one eighth later) must hold `hh` 42 or `hh_pedal` 44, or the open hat rings on. If that cell has a crash (hand busy), write `hh_pedal` at 70-85 there and report the added note.
- Sloshy keeper: quarter notes on `hh_open` at 95-115 with the snare on 3 (feel `half`) is a documented Haake pattern [18]. The map has no half open pitch. `hh_open` at 85-100 is the stand in (unconfirmed per sampler).
- Pedal hat under a ride, china or crash keeper: chick on 2 and 4 or on all four quarters [11], or eighths [20], at 42-70. Haake keeps the hat foot going whenever he is not on both bass drums [17]. Never on a cell where a stick plays `hh` 42 (the hat is already shut). Only where the left foot is free: no `hh_pedal` in a beat with a kick run at grid=32 or 24, or with kicks on adjacent sixteenth cells above about 130 bpm (threshold unconfirmed).
- Pedal hat under a fill [9]: the chick is masked by the hands and it adds notes inside the fill span, so it is not part of "alive" or any other feel word. Only when he asks for the foot. Then under every fill of 2 beats or more in the scope, never under one fill alone, at 70-85, with its own ops on `lanes=44`.
- Crash or china on a cell: the closed hat on that cell goes (one handed eighths: the hat hand plays the cymbal). In a feel request that is a limb fix: report it.

```vd
bar 1 grid=16
#             1    2    3    4
hh_open 46  |---- ---- ---- --7-|
hh 42       |8-6- 8-6- 8-6- 8---|
snare 38    |---- 9--- ---- 9---|
kick 36     |9--- --9- 9-9- ----|
bar 2 grid=16
# crash on 1: the foot closes the hat, the hand comes back on the "and"
crash1 49   |8--- ---- ---- ----|
hh_pedal 44 |6--- ---- ---- ----|
hh 42       |--6- 8-6- 8-6- 8-6-|
snare 38    |---- 9--- ---- 9---|
kick 36     |9--- --9- 9-9- ----|
```

## 6. No loops: the loop test, lift, quieter repeat

- Loop test, on the keeper rows of the section in `show --bars A-B`. A bar repeats when its keeper digits and lanes equal those of the bar before it. Before an edit: 3 repeats in a row are a loop. After an edit (principle 8): at least a third of the bars differ from the bar before them in a cell you designed (a lifted cell, an opening, a lift, a quieter bar). A fill that was already there does not count. `# bar 7 = bar 3` lines are fine, an A B A B part prints them: only neighbours count. Differences that `humanize` made do not count, and neither does sd. In a polymeter section the kick differs in every bar, so no `=` lines print while the keeper still loops: read the keeper row.
- Unit: the 2 bar cell of section 3. Above it the 4 bar phrase: its 2nd bar may open the hat, its last bar may carry a fill. Changing sounds every 1, 2 or 4 bars is the standard advice [9]. Never vary a riff locked kick to break a loop.
- Lift into a fill: only into the fill that ends a phrase or a section, never into a 1 beat pickup (principle 3). Over the 2 beats of hats before the fill: `ramp ... lanes=42 scale=0.95-1.13`. The first hit pulls back a little (the hat has no room above 118, principle 2), then both hands rise 10 or more, and every shoulder stays over its tip. `ramp from= to=` here would erase the shoulder and tip shape. Two walls after it: shoulders stop at 118, the last "and" of the window stays at 99 or under. Inside a two handed fill there are no hats [8].
- Quieter repeat: when the second half of a section repeats the first (the kick rows of bars 5-6 equal those of bars 1-2, a different fill does not matter), the closed hat drops 10 for the first 2 bars of the repeat: `vel ... lanes=42 add=-10`, then the wall `v=95-127 min=100`. Never `scale=` on `lanes=hat`: it drags the opening and the foot along and drops shoulders through the wall. Kick, backbeat and openings unchanged (unconfirmed as a rule, common practice).
- After a fill: the landing (crash and kick on beat 1) belongs to fills.md. A fill with no crash after it is still a fill (principle 17): a hat or feel request leaves it alone and mentions it. A fill in the last bar of the song has no landing bar at all (principle 16). After a crash the hat comes back on the "and".

```vd
# "more" on a hat part that is already shaped and humanized (section 10, rungs 3 and 4)
# input: bars 1-8, eighth hats, bars 5-8 repeat bars 1-4, fill at 8:3-5 that ends the section
# lift: the four eighths before the fill go from about 106 85 to 118 95, shoulder over tip all the way
ramp bars=8 beats=1-3 lanes=42 scale=0.95-1.13
# walls: shoulders stop at 118, the last "and" of the window stays a tip
vel bars=8 beats=1-3 lanes=42 v=100-127 max=118
vel bars=8 beats=2.5-2.75 lanes=42 max=99
# quieter repeat: bars 5-6, closed hat 10 down. the opening on 46 keeps its level
vel bars=5-6 lanes=42 add=-10
# wall: what is 95 or more after the drop is a shoulder and stays one
vel bars=5-6 lanes=42 v=95-127 min=100
```

## 7. Cymbal choice, stacking, alternating crashes

- Keeper ladder, low to high intensity: `hh` eighths, `hh_open` quarters or eighths, `crash1` quarters, `china` quarters (the four rungs of grooves.md section 4). Side steps: `ride` bow is the clean alternative to the hat rungs, `ride_bell` the melodic alternative next to crash riding. "Heavier" or "more aggressive" moves one step up the four rungs and never onto the ride, "softer" moves one step down, or onto the ride in a clean passage (ordering unconfirmed; `hh_open` and `ride` are close in level, `hh_open` is the dirty one, `ride` the clean one). The cymbal hand and the snare stay on a straight 4/4 pulse while the kick follows the guitar cycle [18][20]. A keeper change is a note edit of a whole section: only when the request names that section, and never bring a section's keeper cymbal in before that section starts (principle 4).
- Accent with the riff: put a crash or china accent only on a `# riff` onset, with a kick on the same cell. Haake: "I only do the hits with the guitar hits" [17]. No riff track: add no accents, and say so (principle 15).
- Stacked accent: `china` 52 plus `crash1` 49 on one cell uses both hands, so no snare, hat or tom on that cell [6]. It belongs to a section start. A landing inside a section gets one crash, and no landing is bigger than the start of its section or the first hit of the song (principle 4). Look one cell back (principle 10): hands that play a floor tom sixteenth right before a stack have to travel, so at fast tempos that last cell is left to the kick.
- Alternating: accent hits closer than a quarter note alternate strong hand and weak hand, the weak one 10-25 lower ([6] gives 5-25). The same cymbal twice at one velocity is a machine gun [22]. `crash2` only when it already has notes in `# lanes` (principle 6), else every second `crash1` hit 12 lower. Which side leads is unconfirmed.
- Crash velocity by rank: section start 119-127, landing inside a section 10 or more under it, riff accents 10 lower again. Exactly 127 on one or two hits per 4 bar phrase at most (unconfirmed, follows from [6]). Crashes all at 127: lower the inner ones per hit (`vel bars=N beats=B lanes=49 add=-10`), never one `max=` over the lane.
- A physical stack cymbal (Haake: 15 inch crash on a 19 inch china [17]) is not in the built in map. Stand in: `splash` 55, or `china` at 90-105 (unconfirmed).

```vd
# bar 1 is a section start: the only place for the china + crash1 stack. riff accents after it: crash1 112, weak hand crash2 98, a kick under each
bar 1 grid=16
#            1    2    3    4
china 52   |9--- ---- ---- ----|
crash1 49  |9--- --8- ---- -8--|
crash2 57  |---7 ---- --7- ----|
snare 38   |---- ---- 9--- ----|
kick 36    |9--9 --9- --9- -9--|
```

## 8. Micro timing

ticks = ms * bpm * ppq / 60000. Compute it for the file's tempo (`# tempo:` in the header), the table is only a check. One cell at 480 ppq: grid=16 is 120 ticks, grid=32 is 60, grid=24 is 80, grid=48 is 40.

| bpm | ms per tick | sixteenth cell | 5 ms | 10 ms | 20 ms | 30 ms | 20 ticks, the `humanize time=` cap |
|---|---|---|---|---|---|---|---|
| 100 | 1.25 | 150 ms | 4 ticks | 8 | 16 | 24 | 25 ms |
| 130 | 0.96 | 115 ms | 5 ticks | 10 | 21 | 31 | 19 ms |
| 140 | 0.89 | 107 ms | 6 ticks | 11 | 22 | 34 | 18 ms |
| 180 | 0.69 | 83 ms | 7 ticks | 14 | 29 | 43 | 14 ms |

Anchors: an unquantized one handed hat part at 96 bpm has 8.7 ms sd on its sixteenth intervals [13]. Metal guides advise quantize strength 85-95 percent instead of 100 [2][3][4], or 2-5 percent timing humanisation [6]. One guide nudges notes about 20 ticks, ppq not stated [16]: read that as an upper bound. 5 and 10 ms are the useful push or drag amounts, 20 ms is the edge of sounding wrong, and against programmed parts stay at 5-10 [14]. `humanize time=N` is uniform: the intervals get an sd of about 0.8 N, and a spread under 5 ms is not heard as feel. Velocity spread of plus or minus 5-10 is the stated range [4], this pack stays lower because of principle 12. `humanize` never moves a note on a bar line in front of it. The per lane split is a working default (unconfirmed).

| selector | `humanize vel=` | `time=` at 100 / 130 / 140 / 180 bpm | in ms |
|---|---|---|---|
| `lanes=kick` | 0-3 | 0 | 0 |
| `lanes=38 v=100-127` | 3 | 0-1 / 0-2 / 0-2 / 0-2 | 0-1.5 |
| `lanes=cym` on riff accents | 3-4 | 0-1 / 0-2 / 0-2 / 0-2 | 0-1.5 |
| `lanes=42,46` or `lanes=51` | 4 | 5-8 / 6-10 / 7-11 / 9-14 | 6-10 |
| `lanes=tom` in fills | 0-4 | 2-4 / 3-5 / 3-6 / 4-7 | 3-5 |
| `lanes=38 v=1-62` | 5 | 3-6 / 4-8 / 5-9 / 6-11 | 4-8 |

- Stays on the grid: every kick where the section `lock` is 70% or more or the cell has a `# riff` x, every kick when the file has no riff track (assume the guitar doubles it, and say that lock could not be read), cymbal hits that share a cell with a riff accent. The backbeat gets no random timing beyond 2 ticks: a constant `shift` is a feel choice (below). A quantized kick is the foundation while hats and snare may float [7].
- May move: hats, ride, ghosts, inner notes of tom fills, flam grace notes.
- No quantize op exists. To snap a lane back, in one script: `delete <sel>` first, then bar blocks that rewrite the rows from the `show` digits. New notes land exactly on the cell line at digit * 14, so reshape the velocities after.

Flams: the main note stays on the grid, the grace comes 6-30 ms earlier and slightly quieter [7]. Use 15-30 ms, constant in ms at any tempo: 12-24 ticks at 100 bpm, 16-31 at 130, 17-34 at 140, 22-43 at 180. Grace velocity: 45-75 for a light grace (about 60), 84-104 for a fat two stick accent (unconfirmed). One grid=32 cell (60 ticks, 54 ms at 140) is a loose flam that reads as a drag: write the grace one grid=32 cell early, then `shift` it later. A grace 20 ticks or less before the main shares the main's cell in `show` (only the louder digit prints), and changing that digit sets both notes to one velocity. A flam is an added note: only when he asks for flams or for "more human", on a backbeat before a section change or the first or last note of a fill, at most 1-2 per 4 bars (unconfirmed), and reported.

```vd
# 140 bpm, flam on the backbeat of beat 4. copy the snare row from show and add only the grace (digit 4)
bar 2 grid=32
#            1        2        3        4
snare 38   |-------- 9------- -------4 9-------|
# the grace sits 60 ticks early. move it 38 later: 22 ticks before the main, 20 ms at 140 bpm
shift bars=2 beats=3.85-4 lanes=38 v=40-70 ticks=38
```

Push and laid back: a constant offset on one limb, not randomness [14]. Laid back (heavier, wider halftime): backbeat 5-10 ms late [7]. Push (urgent): snare 5 ms early [7][15], or the keeper early instead (unconfirmed). General guides also drag the kick 5-20 ms late [2][15]: not here, a kick that doubles the riff never moves. If the shifted hit shares a cell with a `# riff` x, stay at 5 ms or less (unconfirmed, it would flam against the guitar). `shift` has no bar line guard: a negative shift on a beat 1 note puts it in the bar before, so keep beat 1 out with `beats=1.25-5`.

```vd
# 140 bpm. laid back backbeat in bars 1-4: 6 ticks is 5 ms late
shift bars=1-4 lanes=38 v=100-127 ticks=6
# pushed keeper in bars 5-8: stick hats 6 ticks (5 ms) early, beat 1 stays on its bar line. crash and china accents stay with the riff
shift bars=5-8 beats=1.25-5 lanes=42,46 ticks=-6
```

## 9. Ghost notes (needed by the recipes)

Velocity 25-50 [1][5][15], always under 60: `show` counts a snare hit of 60 or more as a backbeat when it labels the feel. That is a wall: after any spread or lift on ghosts, `vel lanes=38 v=1-62 min=25 max=58`. Singles or pairs only, never three in a row [5]. In a pair the second note is 14 over the first (28 then 42). One guide warns against the sixteenth directly before and directly after a backbeat [5], drum lessons do use the one before (grooves.md section 5): keep those where they exist, add new ones elsewhere first. Prefer cells with no kick. Backbeat on cells 4 and 12: good ghost cells are 7, 9, 15, then 1, 6, 10, 14. Backbeat on cell 8 (feel `half`): 3, 5, 11, 13, 15 (unconfirmed). Ghost notes are part of Haake's signature [19], but under china or crash riding they get lost: use 40-58 there or leave them out (unconfirmed). Adding ghosts adds notes: only when he names ghosts or the word asks for them ("groovier", "busier"), different cells in odd and even bars, and the report says notes were added. Two or more ghosts added inside one beat in only a few bars can make a later `show` list that beat as a fill: check the grid before using `fills` again.

```vd
bar 1 grid=16
#            1    2    3    4
hh 42      |8-6- 8-6- 8-7- 8-6-|
snare 38   |---- 9--3 -2-- 9--3|
kick 36    |9-9- ---- --9- --9-|
humanize bars=1 lanes=38 v=1-62 vel=5 time=5 seed=5
vel bars=1 lanes=38 v=1-62 min=25 max=58
```

## 10. Request recipes

`S` stands for the section selector, for example `bars=1-8`. `T` = ticks for the file's tempo from section 8. `N`, `A-B`, `B` = one bar, one beat window, one beat. Feel `half`: the backbeat is beat 3, so use `beats=3-3.25` where a recipe names beats 2 and 4. The hat column also serves a ride keeper (`lanes=51` for `lanes=42`).

How to read the table (principle 1). A row is a menu, never one script.

1. Pick one column: the lane he named, else the default target of the word (vocabulary 4). "Less robotic" and "more human" name every flat lane: there, each column whose lane has sd under 3.
2. Inside a cell the levers are in order. Take the first one or two the file has room for, then stop, and name the next lever in the report. He can say "more".
3. No room = already there, nothing to select, or the lane is at its ceiling (section 1). Skip that lever, never force it.
4. Other columns: only when he names them or says "more". A deleted or added note is always reported (principle 21).

| request | hat lane (42, 46) | ghosts | cymbals | kick and backbeat |
|---|---|---|---|---|
| more alive | the ladder below, rungs 1 and 2 | ghosts exist: pairs rise, written in bar blocks as digit 2 then digit 3, then `humanize S lanes=38 v=1-62 vel=5` and the wall of section 9. None exist: add them only when he names ghosts | keeper is china or crash: the contrast cure of section 2. Crash accents closer than a quarter: every second one 12 lower (section 7) | none |
| less robotic | rung 1 of the ladder and nothing else, no note changes. Then rung 5 (timing) | `humanize S lanes=38 v=1-62 vel=5 time=T`, then the wall `vel S lanes=38 v=1-62 min=25 max=58` | keeper: the cure of section 2. Crash accents: `humanize S lanes=49,57 vel=4` | `humanize S lanes=kick vel=3`, `humanize S lanes=38 v=100-127 vel=3`, then the wall `vel S lanes=38 v=100-127 min=116` |
| more human | less robotic first. Then limb fixes, each reported as notes removed: `delete bars=N beats=A-B lanes=42,46` inside a two hand fill, the hat cell under a crash blanked in a bar block, two handed sixteenths: `delete S beats=2-2.25 lanes=42` and the same for `beats=4-4.25` | as less robotic. One flam per 4 bars only if he asks (section 8) | the second crash of a close pair 12 lower: `vel bars=N beats=B lanes=49 add=-12` | weak foot in runs: the kick run cure of section 2 |
| tighter | half the spread inside each articulation: `vel S lanes=42 v=100-127 scale=0.5 add=56`, then `vel S lanes=42 v=1-99 scale=0.5 add=42`. Next: openings closed, `remap S lanes=46 to=hh`. No `time=`. Notes off the grid: delete and rewrite (section 8) | `vel S lanes=38 v=1-62 scale=0.8`. Next: `delete S lanes=38 v=1-30`, reported | none. If he names them: crashes stay only on section starts, fill landings and riff accents, the others blanked in bar blocks and reported | `vel S lanes=kick min=120` when the kick min is under 120 (a flat kick is correct). Already at 127: nothing, say so. Timing untouched |
| punchier | contrast, not level. Tips one digit down, the bar differences stay: `vel S lanes=42 v=1-99 add=-14 min=60`. Flat part: rung 1 of the ladder first | `vel S lanes=38 v=1-62 scale=0.8` (a bigger gap to the backbeat) | crash accents with room go to 112-120, per hit: `vel bars=N beats=B lanes=49 set=116`, each with a kick. The section start stays on top | room (min under 120): `vel S lanes=kick,38 v=100-127 min=120`, then `humanize S lanes=kick,38 v=100-127 vel=3`. At the ceiling: skip, the hat and ghost columns are the lever |
| softer | openings closed and the whole hat on the tip, on purpose (112 becomes 90, 84 becomes 67, the gap stays): `remap S lanes=46 to=hh`, `vel S lanes=42 scale=0.8 max=96` | `vel S lanes=38 v=1-62 scale=0.8 min=20` | `vel S lanes=cym,ride scale=0.85` (the ranks stay). Next: keeper one rung down (section 7), `remap S lanes=china to=crash1`, or `to=ride` in a clean passage | heavy section: none. Clean section: `remap S lanes=38 v=100-127 to=rim`, `vel S lanes=37 scale=0.82`, `vel S lanes=kick scale=0.85 min=95` |
| more dynamic | flat part: rung 1 of the ladder. Shaped part: rung 3 (lift), then rung 4 (quieter repeat) | pairs rise: first 28, second 42 | rank the crashes (section 7): start of the section on top, landings inside it 10 lower, riff accents 10 lower again, per hit with `vel bars=N beats=B lanes=49 add=-10` | none. Fills: the fill cure of section 2, graded by slot |
| more aggressive | one rung up the keeper ladder (section 7): `remap S lanes=42 to=hh_open`, base row `accent S lanes=46 grid=16 pattern=8-7-`, `humanize S lanes=46 vel=3`, then the 2 bar cell of section 3 on `lanes=46` with digit 8 (112 against 98). For quarters, before the base row: `delete S beats=1.25-2 lanes=46` and the same for 2.25-3, 3.25-4, 4.25-5 | louder, still ghosts: `vel S lanes=38 v=1-62 add=14 max=58`. Or out: `delete S lanes=38 v=1-34`, reported | china + crash1 stacked on the section start only (section 7) | room: `vel S lanes=kick,38 v=100-127 min=124`, then `humanize S lanes=kick,38 v=100-127 vel=3`. At the ceiling: skip |
| smoother | less contrast, the bar differences stay: `vel S lanes=42 v=100-127 scale=0.5 add=50` (112 becomes 106). Next: `remap S lanes=46 to=hh` | `vel S lanes=38 v=1-62 scale=0.8`, no flams | `vel S lanes=ride_bell scale=0.85`, `vel S lanes=cym scale=0.92` | none |
| groovier | rung 2 of the ladder (openings). Flat part: rung 1 with it. One handed sixteenths: the 2 beat cycle `75658565` | 2 per bar on cells 7, 9, 15 at 30-45 (section 9), reported as notes added | none | backbeat 5 ms late: `shift S lanes=38 v=100-127 ticks=T` (5 at 130 bpm, 6 at 140). Kick never shifts |

"Make the hi hat more alive": the ladder. Scope: the bars where 42 keeps time. A section kept by china or crash is not part of a hat request: leave it and mention it. Only a song with no hat at all turns "the hat" into the keeper cymbal (cymbals column). Default: rungs 1 and 2 in one script (below), then stop. Each later rung is one "more", applied on top of the version before.

1. Shape: base row of section 3 on `lanes=42`, `humanize lanes=42 vel=4`, then the 2 bar cell. No room: the hat already shows two digits per beat and a cell that changes between neighbouring bars.
2. Openings (section 5): the "and" of 4 in the 2nd bar of each 4 bar phrase, graded with `ramp S lanes=46 from=100 to=110` so the later one is the bigger one (a single opening: `vel S lanes=46 set=104`). No room: openings exist, or every such cell sits in a fill.
3. Lift into the fill that ends the phrase or the section (section 6). No room: fewer than four hats in the 2 beats before it, or the only fills are 1 beat pickups.
4. Quieter repeat (section 6). No room: the section has no repeat or is shorter than 8 bars.
5. Timing: `humanize S lanes=42,46 time=T`, T = 6 to 10 ms (8 ticks at 130 bpm). Velocities stay as they are.
6. Foot under the fills: only when he asks for the foot (section 5).

Never part of this request: kick, backbeat, fill notes, hats deleted on snare cells, a landing crash for a fill that has none, a backbeat "lean" of a few points (under 10 it is not there).

```vd
# said back: the hat keeps its eighths. shoulder on the beat, tip on the "and", one "and" per bar lifted (a different one in odd and even bars), open hat on the "and" of 4 in bars 2 and 6. kick, snare and fills untouched
# input: bars 1-8, keeper hh, eighth hats on 42 at one velocity, fill at 8:3-5. any feel, any tempo
# 1 notes: the openings, 2nd bar of each phrase. the closed hat on the next beat 1 chokes each
remap bars=2,6 beats=4.5-4.75 lanes=42 to=hh_open
# 2 level: shoulder 112, tip 84. the first opening 100, the last 110
accent bars=1-8 lanes=42 grid=16 pattern=8-6-
ramp bars=1-8 lanes=46 from=100 to=110
# 3 spread, closed hat only: shoulders 108-116, tips 80-88, nothing near the wall at 100
humanize bars=1-8 lanes=42 vel=4 seed=7
# 4 gestures last, the 2 bar cell: one tip per bar goes to exactly 98
accent bars=1,3,5,7 lanes=42 grid=16 pattern=--------------7-
accent bars=2,4,6,8 lanes=42 grid=16 pattern=----------7-----
```

Mapping the script to a file (principle 19):

- Bars 1-8 stand for his section. "Odd bars" are its 1st, 3rd, 5th bar, wherever it starts.
- A fill inside the range needs no change to the script: `accent`, `humanize` and `vel` skip cells that hold no hat. Only the `remap` names a cell: leave out every bar whose beat 4 is inside a fill.
- Beat 1 under a crash has no hat. Nothing to do there, add none.
- Two handed sixteenths: base row `8676` and the sixteenth cells of section 3. Hats that are already shaped: drop the base `accent` and the `humanize`, keep the rest.
- Hats flat at 127 or at any other level: the same script, `accent` writes absolute values.
- No riff track: nothing here needs one. A recipe that names a lane the kit has no notes on (`crash2`, `ride_bell`): the nearest lane that has notes (principle 18).

Check before reporting (principle 20), on `show OUT --vel --bars A-B`: every on beat hat reads 100-118 and every "and" 99 or less. Each lifted cell reads 98 against 80-88 around it. At least a third of the bars (with this script: every bar) differ from the bar before in a lifted cell or an opening. `apply` printed changes for `hh` and `hh_open` only. Report only what the numbers show, and name rung 3 as the next step.

## 11. Sources

1. https://www.nailthemix.com/drum-programming-faqs (backbeat 120-127, ghosts 20-50, hats 110 and 95)
2. https://www.nailthemix.com/getgood-drums-matt-halpern-drums-library (backbeat 115-120, blast 125-127, quantize 85 or 90 percent, snare a few ms early, kick slightly late)
3. https://www.nailthemix.com/toontrack-metal-foundry-sdx (alternate 120 and 127, blast 100-115, quantize 90-95 percent)
4. https://www.nailthemix.com/toontrack-metal-machinery-sdx (blast 115 and 125, ghosts 40-70, plus or minus 5-10 velocity, quantize 90-95 percent)
5. https://www.toontrack.com/blog/how-to-program-drums/ (hat hierarchy, edge on downbeats and tip on upbeats, ghosts 20-45, no ghost next to a backbeat, no three in a row, kick 100-115 and 75-95, backbeat 100-120)
6. https://urm.academy/5-drum-programming-tips-for-maximum-realism/ (110-120 over 127, never three hand hits at once, weak hand 5-25 lower, timing humanise 2-5 percent)
7. https://www.soundonsound.com/techniques/making-midi-sequencing-more-realistic-part-2-drum-parts (flam 6-30 ms early and slightly quieter, kick quantized while hat and snare float, snare early drives, snare late lays back)
8. https://www.soundonsound.com/techniques/programming-realistic-drum-parts (every other hit lower for alternate hands, no hats in a tom fill)
9. https://www.production-expert.com/production-expert-1/6-killer-hi-hat-programmingnbsptipsnbspfor-musicnbspproducers (two handed sixteenths skip the snare cell, choke group, pedal hat during fills, offbeat hits quieter, change every 1, 2 or 4 bars)
10. https://drummagazine.com/lesson-how-to-get-that-tasty-16th-note-hi-hat-feel/ (one handed sixteenths: shoulder accents, downbeat and upbeat accent placements, pedal pressure)
11. https://rhythmnotes.net/hi-hat-techniques/ (shoulder on edge, tip on top, degrees of open, foot chick on 2 and 4 or all four)
12. https://www.toontrack.com/forums/topic/tip-and-edge-of-hihat-what-do-you-mean/ (tip and edge articulations)
13. https://journals.plos.org/plosone/article?id=10.1371/journal.pone.0127902 (Jeff Porcaro, one handed sixteenth hats at 96 bpm: 8.7 ms sd, loudness pattern high low medium low, very high low medium low)
14. https://www.confidentdrummer.com/playing-ahead-or-behind-the-beat-full-course-part-1-theory/ (5, 10 and 20 ms, single limb offsets)
15. https://www.slamtracks.com/2025/12/20/5-secrets-to-humanizing-midi-drums/ (hats 60-95, ghosts 30-50, snare 5-15 ms early, kick 5-20 ms late)
16. https://www.slamtracks.com/how-to-program-midi-drums-to-sound-like-the-real-thing/ (about 20 ticks and 20 percent velocity variation, read as an upper bound)
17. https://drummagazine.com/tomas-haake-meshuggahs-djentle-giant/ (hat foot keeps going, not a dynamic band, rimshots, hits only with the guitar, stack cymbal)
18. https://drummagazine.com/tomas-haake-meshuggah-goes-it-alone/ (quarter notes on sloshy hats with snare on 3, album sound is close mics plus close mic samples plus room, softer strokes for evenness, cymbal hand and snare play straight)
19. https://www.drumeo.com/beat/meshuggah-tomas-haake-genius/ (dedicated use of ghost notes, lighter foot technique on Bleed)
20. https://clashplaids.tumblr.com/post/152393286901/form-analysis-and-partial-transcription/amp (Clockworks: right hand constant quarters, left foot eighths on the hat)
21. https://drummagazine.com/matt-garstka-lets-get-technical/ ("you don't get dynamics with bass drums")
22. https://www.nailthemix.com/3-killer-drum-sample-replacement-techniques-for-metal (identical hits are a machine gun, do not set everything to 127)
23. https://www.nailthemix.com/slate-trigger-2 (all 127 is a machine gun, blast hits 95-115)
24. https://gearspace.com/threads/16th-note-hi-hats-question.797758/ (one handed sixteenths top out near 100 bpm for most players. Search excerpt only, page fetch failed)
