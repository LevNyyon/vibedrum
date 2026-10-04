# Dynamics and feel: velocity, articulation, micro timing

Scope: djent and progressive metalcore drum parts. Units: velocity 1-127, grid cells, beats (quarter notes), ticks at 480 ppq. Cell numbers are grid=16 indexes 0-15 as in grooves.md: beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12. A grid digit d is velocity d*14 (9 = 127). `accent` uses the same digits, so it moves in steps of 14: set the shape with `accent`, fine tune with `vel`, `ramp`, `humanize`. `[n]` = source in section 11. "unconfirmed" = working default, no source found.

Selectors used below: closed hat `lanes=42`, every hat articulation `lanes=hat`, ghosts `lanes=38 v=1-62`, backbeats `lanes=38 v=100-127`. Inside fill spans soft snare notes are fill notes, not ghosts: keep fill bars out of ghost ops. Give every op a `lanes=` part: without one it hits every drum note. `accent`, `vel` and `ramp` only change notes that exist, they never add or delete. Order inside one script: bar blocks, then `copy`, `remap`, `delete`, then `accent`, `vel`, `ramp`, then `humanize`, then `shift` last. A script runs top to bottom, bar rows included, so the one exception is a bar block that edits a bar a `copy` writes into: it goes after that `copy` (fills.md section 6). Reasons: `accent` and `vel set=` erase the spread `humanize` made, `humanize` pushes velocities across the `v=` bands, and a note shifted more than 20 ticks early leaves its cell, so `beats=` windows stop finding it (`humanize time=` is capped at 20 ticks and never does that). `show` hides micro timing and velocity inside a digit band, so run `humanize` and `shift` once per lane per section: a second run stacks on the first. To redo one, apply the new script to the version before it.

## 1. Velocity ranges per lane

| lane | hit | velocity | digit | healthy sd | basis |
|---|---|---|---|---|---|
| kick 36 | hit that lands on a `# riff` x | 112-127, default 120 and up | 8-9 | 0-4 | [17][18][21], exact band unconfirmed |
| kick 36 | notes of a run (4+ adjacent cells at grid=32 or 24) | first note 112-127, the rest 98-112 with the weak foot lower | 7-9 | 3-6 | the numbers of grooves.md section 6; [18][19] softer strokes for evenness, numbers unconfirmed |
| snare 38 | backbeat, rimshot | 116-127 | 8-9 | 2-5 | [1][2][3][17] |
| snare 38 | blast, fast alternating singles | 100-115 alternating, 115-127 when it has to cut | 7-9 | 5-8 | low [3][23], high [2][4] |
| snare 38 | ghost | 25-50, up to 58 in a dense mix, never 60 or more (section 9) | 2-4 | 4-9 | [1][5][15], 40-70 in [4] |
| snare 38 | flam grace | 45-75 light, 84-104 heavy flat flam (the bands of fills.md section 5) | 3-7 | | [7] says slightly quieter than the main, numbers unconfirmed |
| rim 37 | cross stick, clean sections | 85-110 | 6-8 | 4-7 | unconfirmed |
| hh 42 | shoulder accent | 100-118 | 7-8 | lane total 10-20 | [1][5][10][11] |
| hh 42 | tip | 60-98 | 5-7 | | [1][15] |
| hh 42 | "e" and "a" of sixteenths | 55-85: about 70 one handed, about 84 two handed (section 3) | 4-6 | | unconfirmed |
| hh_open 46 | sloshy keeper on quarters or eighths | 95-115 | 7-8 | 5-9 | usage [18], numbers unconfirmed |
| hh_open 46 | single offbeat opening | 98-112 | 7-8 | | unconfirmed |
| hh_pedal 44 | foot chick | 42-70 as a metronome under a ride, china or crash keeper, 70-85 when it has to close an open hat or keep time alone in a fill | 3-6 | 3-6 | usage [9][11][17][20], numbers unconfirmed |
| ride 51 | bow | 84-112 as the keeper of a heavy section, 70-84 in clean passages | 5-8 | 8-14 | unconfirmed |
| ride_bell 53 | bell | 100-122 | 7-9 | 4-8 | unconfirmed |
| crash1 49, crash2 57 | accent with the riff; section start or landing after a fill | accents 108-124; section start or landing 119-127 (digit 9, fills.md section 6) | 8-9 | 4-8 | under 127 per [6] for ordinary accents, bands unconfirmed |
| crash1 49 | crash keeper on quarters or eighths | 95-115 | 7-8 | 6-10 | unconfirmed |
| china 52 | quarter note keeper | 105-124 | 8-9 | 4-8 | unconfirmed |
| splash 55 | short accent | 90-112 | 7-8 | | unconfirmed |
| tom1 to tom6 | fill notes | 95-125 | 7-9 | 6-12 | weak hand lower [6], band unconfirmed |

How this style differs from rock, funk and pop programming:

- Kick and backbeat are sample reinforced on the records: Haake describes the album drum sound as close mics mixed with close mic samples and the room [18], he rimshots every snare and calls Meshuggah "not a dynamic band" [17], Garstka: "you don't get dynamics with bass drums" [21]. Kick and backbeat therefore live in digits 8-9 with sd under 5. That is correct, do not "fix" it.
- One single value is still wrong: an identical velocity fires one sample over and over [22][23]. Guides alternate backbeats inside 120-127 [3], or keep normal backbeats at 115-120 and save 125-127 for blasts that must cut [2]. 110-120 is closer to a real hard hit than 127 in most libraries [6].
- General guides put primary kicks at 100-115, secondary kicks at 75-95 and backbeats at 100-120 [5]. Too soft for this style: do not apply that to kicks that double the riff (unconfirmed, follows from [17][21]).
- The dynamic range lives in four places: hats and ride (15-45 units between tip and shoulder), ghosts (25-50 under a 116+ backbeat), tom fills (ramps, weak hand 5-25 lower [6]), cymbal choice and crash velocity.
- So a feel request edits hats, cymbals, ghosts and toms first. Change kick or backbeat velocity only for "tighter", "punchier", "more aggressive", "softer".

## 2. Machine gun: reading it and curing it

Header line `# lanes: pitch lane count vel min/avg/max sd`. Machine gun = sd under 3, or min = max, or every cell of the lane in the section shows one digit (the header is song wide, the grid is the truth for a section). The snare lane mixes two bands: sd under 6 means no ghosts exist. sd 30+ built from only two digits (9 and one ghost digit) means each band is still a machine gun. `humanize vel=N` is a uniform plus or minus N and adds an sd of only about 0.6 N (vel=6 gives 3.7): alone it cannot bring a hat lane to sd 10-20, the shape has to come from `accent` first. Add `bars=` to every op in the table.

| lane | verdict at sd under 3 | cure |
|---|---|---|
| kick on riff | correct | none. If asked for less robotic: `humanize lanes=kick vel=3`, never `time=` |
| kick run at grid=32 | fix | strong foot, weak foot, on the beats of the run only (here beat 4): `accent beats=4-5 lanes=kick grid=32 pattern=87` (112 and 98, the numbers of grooves.md section 6), then the first note back up: `vel beats=4-4.125 lanes=kick set=127`. Run that starts on an odd cell: `pattern=78`. Kicks outside the run keep their level |
| backbeat | nearly correct | `humanize lanes=38 v=100-127 vel=3` then `vel lanes=38 v=100-127 min=116` |
| blast snare on eighths | fix | `accent lanes=38 v=90-127 grid=16 pattern=8-7- mix=0.8` (115 and 104 from a flat 127 [3][23]), `humanize lanes=38 v=90-127 vel=4`. Blast that has to cut: `pattern=9-8-` (127 and 115 [2][4]). Snares on the odd cells: `-8-7`. Blast written at grid=32: same patterns with `grid=32` |
| ghosts | fix | `vel lanes=38 v=1-62 min=25 max=50`, `humanize lanes=38 v=1-62 vel=6` |
| hh, ride keeper | fix, this is the main case | shape with `accent` (section 3), then `humanize lanes=hat,ride vel=5` to `vel=8` [4]. Target sd 10-20 |
| china or crash keeper on quarters | fix | `accent lanes=china grid=16 pattern=9---8---8---8---`, `vel lanes=china add=-4` (123 on beat 1, 108 after), `humanize lanes=china vel=4`. Crash keeper: `lanes=crash1` with `pattern=8---7---7---7---`. Target sd 4-8 |
| toms and snare in fills | fix | `ramp fills lanes=tom,38 from=100 to=124`, then weak hand: `accent fills lanes=tom,38 grid=16 pattern=-6 mix=0.3` (use grid=32 for 32nd fills), `humanize fills lanes=tom,38 vel=5` |

## 3. Hat and ride accent patterns

Mechanics: an accent is the shoulder of the stick on the edge, a non accent is the tip on top of the hat, and easing the pedal a little makes the accent bigger [10][11]. Samplers ship these as edge and tip articulations [12]. The built in map has one closed pitch (42), so shoulder versus tip is velocity only: 100 and up reads as shoulder, 99 and down as tip. Every hat part needs a hierarchy of hits [5]. Offbeat hits sit below on beat hits by default [1][5][9]. Sixteenth hats at djent tempos are two handed (section 4): `8676` is the default there, the one hand rows are for parts under about 110 bpm.

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

Why not plain `9575`: (a) 127 on a closed hat fires the hardest sample on every beat and competes with the snare, (b) all four beats are identical, so it loops after one beat however large the sd is (about 24), (c) `accent` never removes notes, so on a two handed part the hats on the snare cells are still there and have to be deleted first. Use it one step lower, on a 2 beat or 1 bar cycle, then `humanize lanes=hat vel=5`. `mix=0.5` to `0.7` keeps part of what was there. For the ride: same patterns on 51, then turn the accents into bell hits.

```vd
# eighth hats in bars 1-4: shoulder 112 on the beat, tip 84 on the "and"
accent bars=1-4 lanes=42 grid=16 pattern=8-6-
# ride in bars 5-8: same shape, then every hit of 105 and up becomes a bell hit
accent bars=5-8 lanes=51 grid=16 pattern=8-6-
remap bars=5-8 lanes=51 v=105-127 to=ride_bell
humanize bars=1-8 lanes=hat,ride vel=5 seed=11
```

## 4. One handed versus two handed sixteenths

- One handed: the hat hand plays every cell, including the snare cells. Natural shape `8565` or `75658565`: accent on the beat, medium on the "and", lowest on "e" and "a" [13]. The measured case is 96 bpm [13] and most players top out near 100 [24]. Above about 110 bpm assume sixteenth hats are two handed (threshold unconfirmed). That covers most djent tempos.
- Two handed (RLRL): right hand on the beat and the "and", left hand on "e" and "a", left 5-25 lower [6][8]. The right hand leaves for the backbeat, so the snare cell has no hat [9]. Shape `8676` with a hole: flatter (28 units of range against 42).
- Both: no hats during a tom fill, the hands are busy [8]. At most two hand lanes sound on one cell [6].

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

- Offbeat opening: `remap` one closed hat on the "and" of 4 (beat 4.5, cell 14) to `hh_open` every 2nd or 4th bar. The "and" of 2 (cell 6) is the second choice. Velocity 98-112 (placement and numbers unconfirmed).
- Choke: open and closed hats share a choke group [9]. The next hat position after an opening (normally one eighth later) must hold `hh` 42 or `hh_pedal` 44, or the open hat rings on. If that cell has a crash (hand busy), write `hh_pedal` at 70-85 there.
- Sloshy keeper: quarter notes on `hh_open` at 95-115 with the snare on 3 (feel `half`) is a documented Haake pattern [18]. The map has no half open pitch. `hh_open` at 85-100 is the stand in (unconfirmed per sampler).
- Pedal hat: under a ride, china or crash keeper, chick on 2 and 4 or on all four quarters [11], or eighths [20]. Also on the beats of a fill while the hands are away [9]. Never on a cell where a stick plays `hh` 42 (the hat is already shut). Only where the left foot is free: no `hh_pedal` in a beat with a kick run at grid=32 or 24, or with kicks on adjacent sixteenth cells above about 130 bpm (threshold unconfirmed). Haake keeps the hat foot going whenever he is not on both bass drums [17].
- Crash or china on a cell: delete the closed hat on that cell (one handed eighths: the hat hand plays the cymbal).

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

## 6. No loops: variation, quieter repeat, lifts

- Loop detector: three or more `# bar N = bar M` lines in a row, or a keeper row with the same digits in 4 or more bars in a row (in a polymeter section the kick differs in every bar, so no `=` lines print while the keeper still loops). Vary hats, ride, ghosts. Do not vary a riff locked kick. A quarter note china or crash anchor over a polymeter kick may stay the same in every bar: there, vary velocity only.
- Unit: a 2 bar cell. Bar 4 differs by one event (extra opening, one accent moved). Bar 8 differs more (lift, fill). Changing sounds every 1, 2 or 4 bars is the standard advice [9].
- Quieter repeat: when a 4 bar phrase repeats, scale the keeper by 0.90-0.94 for the first 2 bars of the repeat, full level after. Kick and backbeat unchanged (unconfirmed as a rule, common practice).
- Lift into a fill: over the 2 beats before the fill, `ramp` closed hats from tip level to 118, or open the last eighth. Inside a two handed fill, delete hats [8].
- After a fill: crash at digit 9 (119-127, fills.md section 6) plus kick on beat 1, hat back on the "and".

```vd
# 2 bar hat cell, tiled over 8 bars, then broken at bars 4 and 8
bar 1 grid=16
hh 42      |8-6- 8-6- 8-6- 8-7-|
bar 2 grid=16
hh_open 46 |---- ---- ---- --7-|
hh 42      |8-6- 8-7- 8-6- 8---|
copy from=1-2 to=3-8 lanes=hat
# bar 4: second opening on the "and" of 2. bar 8: lift over the last two beats
remap bars=4 beats=2.5-2.75 lanes=42 to=hh_open
ramp bars=8 beats=3-5 lanes=42 from=84 to=118
# first half of the repeat 8 percent quieter
vel bars=5-6 lanes=hat scale=0.92 min=50
humanize bars=1-8 lanes=hat vel=5 time=4 seed=3
```

## 7. Cymbal choice, stacking, alternating crashes

- Keeper ladder, low to high intensity: `hh` eighths, `hh_open` quarters or eighths, `crash1` quarters, `china` quarters (the four rungs of grooves.md section 4). Side steps: `ride` bow is the clean alternative to the hat rungs, `ride_bell` the melodic alternative next to crash riding. "Heavier" or "more aggressive" moves one step up the four rungs and never onto the ride, "softer" moves one step down, or onto the ride in a clean passage (ordering unconfirmed; `hh_open` and `ride` are close in level, `hh_open` is the dirty one, `ride` the clean one). The cymbal hand and the snare stay on a straight 4/4 pulse while the kick follows the guitar cycle [18][20].
- Accent with the riff: put a crash or china accent only on a `# riff` onset, with a kick on the same cell. Haake: "I only do the hits with the guitar hits" [17].
- Stacked accent: `china` 52 plus `crash1` 49 on one cell uses both hands, so no snare, hat or tom on that cell [6]. Keep it for section downbeats and the last hit of a phrase.
- Alternating: accent hits closer than a quarter note alternate `crash1` (strong hand, 112-124) and `crash2` (weak hand, 5-25 lower [6]). The same cymbal twice at one velocity is a machine gun [22]. Which side leads is unconfirmed.
- Crash velocity: accents 108-124 by importance; section starts and landings after a fill at digit 9 (119-127, fills.md section 6). Exactly 127 at most once or twice per section, on those hits (unconfirmed, follows from [6]).
- A physical stack cymbal (Haake: 15 inch crash on a 19 inch china [17]) is not in the built in map. Stand in: `splash` 55, or `china` at 90-105 (unconfirmed).

```vd
bar 1 grid=16
#            1    2    3    4
china 52   |9--- ---- ---- ----|
crash1 49  |8--- --8- ---- -8--|
crash2 57  |---7 ---- --7- ----|
snare 38   |---- ---- 9--- ----|
kick 36    |9--9 --9- --9- -9--|
```

## 8. Micro timing

ticks = ms * bpm * ppq / 60000. One cell at 480 ppq: grid=16 is 120 ticks, grid=32 is 60, grid=24 is 80, grid=48 is 40.

| bpm | ms per tick | sixteenth cell | 5 ms | 10 ms | 20 ms | 30 ms | 20 ticks, the `humanize time=` cap |
|---|---|---|---|---|---|---|---|
| 100 | 1.25 | 150 ms | 4 ticks | 8 | 16 | 24 | 25 ms |
| 140 | 0.89 | 107 ms | 6 ticks | 11 | 22 | 34 | 18 ms |
| 180 | 0.69 | 83 ms | 7 ticks | 14 | 29 | 43 | 14 ms |

Anchors: an unquantized one handed hat part at 96 bpm has 8.7 ms sd on its sixteenth intervals [13]. Metal guides advise quantize strength 85-95 percent instead of 100 [2][3][4], or 2-5 percent timing humanisation [6]. One guide nudges notes about 20 ticks, ppq not stated [16]: read that as an upper bound. 5 and 10 ms are the useful push or drag amounts, 20 ms is the edge of sounding wrong, and against programmed parts stay at 5-10 [14]. Velocity spread of plus or minus 5-10 is the stated range [4]. The per lane split below is a working default (unconfirmed).

| selector | `humanize vel=` | `time=` at 100 / 140 / 180 bpm | in ms |
|---|---|---|---|
| `lanes=kick` | 0-3 | 0 / 0 / 0 | 0 |
| `lanes=38 v=100-127` | 3-4 | 0-1 / 0-2 / 0-2 | 0-1.5 |
| `lanes=cym` on riff accents | 4-5 | 0-1 / 0-2 / 0-2 | 0-1.5 |
| `lanes=hat,ride` | 5-8 | 2-4 / 3-6 / 4-7 | 3-5 |
| `lanes=tom` in fills | 5-8 | 2-4 / 3-6 / 4-7 | 3-5 |
| `lanes=38 v=1-62` | 5-8 | 3-6 / 5-9 / 6-11 | 4-8 |

- Stays on the grid: every kick where the section `lock` is 70% or more or the cell has a `# riff` x, every kick when the file has no riff track (assume the guitar doubles it), cymbal hits that share a cell with a riff accent. The backbeat gets no random timing beyond 2 ticks: a constant `shift` is a feel choice (below). A quantized kick is the foundation while hats and snare may float [7].
- May move: hats, ride, ghosts, inner notes of tom fills, flam grace notes.
- No quantize op exists. To snap a lane back, in one script: `delete <sel>` first, then bar blocks that rewrite the rows from the `show` digits. New notes land exactly on the cell line at digit * 14, so reshape the velocities after.

Flams: the main note stays on the grid, the grace comes 6-30 ms earlier and slightly quieter [7]. Use 15-30 ms, constant in ms at any tempo: 12-24 ticks at 100 bpm, 17-34 at 140, 22-43 at 180. Grace velocity: 45-75 for a light grace (about 60), 84-104 for a fat two stick accent (unconfirmed, the bands of fills.md section 5). One grid=32 cell (60 ticks, 54 ms at 140) is a loose flam that reads as a drag: write the grace one grid=32 cell early, then `shift` it later. A grace 20 ticks or less before the main shares the main's cell in `show` (only the louder digit prints), and changing that digit sets both notes to one velocity. Place flams on a backbeat before a section change or the first or last note of a fill, at most 1-2 per 4 bars (unconfirmed).

```vd
# 140 bpm, flam on the backbeat of beat 4. copy the snare row from show and add only the grace (digit 4)
bar 2 grid=32
#            1        2        3        4
snare 38   |-------- 9------- -------4 9-------|
# the grace sits 60 ticks early. move it 38 later: 22 ticks before the main, 20 ms at 140 bpm
shift bars=2 beats=3.85-4 lanes=38 v=40-70 ticks=38
```

Push and laid back: a constant offset on one limb, not randomness [14]. Laid back (heavier, wider halftime): backbeat 5-10 ms late [7]. Push (urgent): snare 5 ms early [7][15], or the keeper early instead (unconfirmed). General guides also drag the kick 5-20 ms late [2][15]: not here, a kick that doubles the riff never moves. If the shifted hit shares a cell with a `# riff` x, stay at 5 ms or less (unconfirmed, it would flam against the guitar).

```vd
# 140 bpm. laid back backbeat in bars 1-4: 6 ticks is 5 ms late
shift bars=1-4 lanes=38 v=100-127 ticks=6
# pushed keeper in bars 5-8: hats and ride 6 ticks (5 ms) early. crash and china accents stay with the riff
shift bars=5-8 lanes=hat,ride ticks=-6
```

## 9. Ghost notes (needed by the recipes)

Velocity 25-50 [1][5][15], always under 60: `show` counts a snare hit of 60 or more as a backbeat when it labels the feel. Singles or pairs only, never three in a row [5]. One guide warns against the sixteenth directly before and directly after a backbeat [5], drum lessons do use the one before (grooves.md section 5): keep those where they exist, add new ones elsewhere first. Prefer cells with no kick. Backbeat on cells 4 and 12: good ghost cells are 7, 9, 15, then 1, 6, 10, 14. Backbeat on cell 8 (feel `half`): 3, 5, 11, 13, 15 (unconfirmed). Ghost notes are part of Haake's signature [19], but under china or crash riding they get lost: use 40-58 there or leave them out (unconfirmed). Two or more ghosts added inside one beat in only a few bars can make a later `show` list that beat as a fill: check the grid before using `fills` again.

```vd
bar 1 grid=16
#            1    2    3    4
hh 42      |8-6- 8-6- 8-7- 8-6-|
snare 38   |---- 9--3 -2-- 9--3|
kick 36    |9-9- ---- --9- --9-|
vel bars=1 lanes=38 v=1-62 min=25 max=50
humanize bars=1 lanes=38 v=1-62 vel=6 time=5 seed=5
```

## 10. Request recipes

`S` stands for the section selector, for example `bars=1-8`. Hat column applies to the ride as well (swap `lanes=42` for `lanes=51`). Feel `half`: the backbeat is beat 3, so use `beats=3-3.25` where a recipe names beats 2 and 4. `time=` and `ticks=` values are for 140 bpm: rescale with the table in section 8.

| request | hat lane | ghosts | cymbals | kick and backbeat |
|---|---|---|---|---|
| more alive | full script below: shape, backbeat lean, openings, repeat, lift, spread | add 2-3 per bar in a bar block (section 9), `humanize S lanes=38 v=1-62 vel=6 time=5` | alternate crash1 and crash2 (section 7). Keeper: `accent S lanes=china grid=16 pattern=9---8---8---8---`, `vel S lanes=china add=-4`, `humanize S lanes=china vel=4` | none |
| less robotic | no notes added or removed: `accent S lanes=42 grid=16 pattern=8-6- mix=0.6`, `humanize S lanes=hat vel=7 time=4` | `humanize S lanes=38 v=1-62 vel=6 time=5` | `humanize S lanes=cym,ride vel=5 time=2` | `humanize S lanes=kick vel=3`, `humanize S lanes=38 v=100-127 vel=3` |
| more human | less robotic, plus limb fixes. Two handed sixteenths: `delete S beats=2-2.25 lanes=42` and the same for `beats=4-4.25`. Hands leave for fills: `delete S fills lanes=42,46`. Hat cell under a crash: blank it in a bar block | same, plus one flam per 4 bars (section 8) | weak hand crash 5-25 lower: `vel S lanes=crash2 max=114` | weak foot in runs: the kick run cure of section 2 (`pattern=87` on the beats of the run) |
| tighter | `remap S lanes=46 to=hh` (openings back to closed), then halve the spread around 96: `vel S lanes=42 scale=0.5 add=48`. No `time=`. Timing snap: delete and rewrite (section 8) | `delete S lanes=38 v=1-30`, `vel S lanes=38 v=1-62 max=42` | crashes only on section starts and riff accents: blank the others in bar blocks | `vel S lanes=kick min=120`, timing untouched |
| punchier | more contrast, not more level: `accent S lanes=42 grid=16 pattern=8-5-`, blank the hat cell under each crash in a bar block | `vel S lanes=38 v=1-62 max=40` (bigger gap to the backbeat) | accent crashes, not a crash keeper: `vel S lanes=crash* min=120 max=124`, each with a kick | `vel S lanes=kick,38 v=100-127 min=120`, then `humanize S lanes=kick,38 v=100-127 vel=3` |
| softer | `remap S lanes=46 to=hh`, `vel S lanes=hat scale=0.8 max=96` | `vel S lanes=38 v=1-62 scale=0.8 min=20` | down the ladder: `remap S lanes=china to=crash1` (one step) or `to=ride` (clean passage), then `vel S lanes=cym,ride max=100` | heavy section: none. Clean section: `remap S lanes=38 v=100-127 to=rim`, `vel S lanes=rim max=105`, `vel S lanes=kick scale=0.85 min=95` |
| more dynamic | wider shape `accent S lanes=42 grid=16 pattern=8-5-`, quieter repeat `vel bars=5-6 lanes=hat scale=0.9`, `ramp` over the 2 beats before each fill (section 6) | pairs rise: first 28, second 42 (digits 2 then 3) | `vel S lanes=crash* max=115`, then phrase starts: `vel bars=1,5 beats=1-1.25 lanes=crash* set=124` | none. Fills: `ramp S fills lanes=tom,38 from=95 to=125` |
| more aggressive | one step up the ladder: `remap S lanes=42 to=hh_open`, then `accent S lanes=46 grid=16 pattern=8-7-`. For quarters, before the accent: `delete S beats=1.25-2 lanes=46` and the same for 2.25-3, 3.25-4, 4.25-5. Top step: `to=china` on quarters | `delete S lanes=38 v=1-34`, or `vel S lanes=38 v=1-62 min=45 max=58` | china plus crash1 stacked on phrase starts (section 7) | `vel S lanes=kick,38 v=100-127 min=124`, then `humanize S lanes=kick,38 v=100-127 vel=3` |
| smoother | less contrast: `remap S lanes=46 to=hh`, `accent S lanes=42 grid=16 pattern=7-6-`, `humanize S lanes=hat vel=3 time=3` | `vel S lanes=38 v=1-62 max=42`, no flams | `remap S lanes=ride_bell to=ride`, `vel S lanes=ride max=100`, `vel S lanes=cym max=115` | none |
| groovier | opening on the "and" of 4 every 2nd bar: `remap bars=2,4,6,8 beats=4.5-4.75 lanes=42 to=hh_open`. Shape: backbeat lean (script steps 4 and 5), or on one handed sixteenths the 2 beat cycle `pattern=75658565`, or the upbeat accent `pattern=6-8-` | add on cells 7, 9, 15 at 30-45 (section 9) | none | backbeat 5 ms late: `shift S lanes=38 v=100-127 ticks=6`. Kick never shifts |

Complete "make the hi hat more alive" script. Input: bars 1-8, keeper `hh`, feel `normal`, hats are eighth notes on 42 at one velocity (sd 0), fill at `8:3-5`, 140 bpm. Expected result: hh sd about 15 over these bars, three articulations in use, no two neighbouring bars alike, kick and snare untouched.

```vd
# 1 foot keeps time under the fill in bar 8 (skip if the kick is doubled there)
bar 8 grid=16
hh_pedal 44 |---- ---- 6--- 6---|
# 2 openings: "and" of 4 in bars 2, 4, 6, plus the "and" of 2 in bar 4. the next closed hat chokes each one
remap bars=2,4,6 beats=4.5-4.75 lanes=42 to=hh_open
remap bars=4 beats=2.5-2.75 lanes=42 to=hh_open
# 3 hands leave the hat for the fill. same as: delete fills bars=8 lanes=42,46
delete bars=8 beats=3-5 lanes=42,46
# 4 shape: shoulder 112 on the beat, tip 84 on the "and"
accent bars=1-8 lanes=42 grid=16 pattern=8-6-
vel bars=2,4,6 lanes=46 set=104
# 5 lean on the backbeat (beats 2 and 4), mark the phrase starts (bars 1 and 5)
vel bars=1-8 beats=2-2.25 lanes=42 add=4
vel bars=1-8 beats=4-4.25 lanes=42 add=4
vel bars=1,5 beats=1-1.25 lanes=42 add=6
# 6 the "and" of 3 answers in bars 2 and 6: 84 becomes 96
vel bars=2,6 beats=3.5-3.75 lanes=42 add=12
# 7 the repeat starts 8 percent down, bar 7 is back at full level
vel bars=5-6 lanes=hat scale=0.92
# 8 lift: the four eighths before the fill rise from 92 toward 120
ramp bars=8 beats=1-3 lanes=42 from=92 to=120
# 9 spread last: plus or minus 6 velocity, plus or minus 4 ticks (3.6 ms)
humanize bars=1-8 lanes=hat vel=6 time=4 seed=7
```

Variants. Feel `half`: replace the two lines of step 5 that lean on beats 2 and 4 with one on `beats=3-3.25`. Two handed sixteenth hats: before step 4 add `delete bars=1-8 beats=2-2.25 lanes=42` and the same for `beats=4-4.25`, then use `pattern=8676`. Keeper is china or crash: use the cymbals column instead of this script.

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
