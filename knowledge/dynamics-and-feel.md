# Dynamics and feel: velocity, articulation, micro timing

Scope: djent and progressive metalcore drum parts. Units: velocity 1-127, grid cells, beats (quarter notes), ticks at 480 ppq. A grid digit d is velocity d*14 (9 = 127). `accent` uses the same digits, so it moves in steps of 14: set the shape with `accent`, fine tune with `vel`, `ramp`, `humanize`. `[n]` = source in section 11. "unconfirmed" = working default, no source found.

Selectors used below: closed hat `lanes=42`, every hat articulation `lanes=hat`, ghosts `lanes=38 v=1-62`, backbeats `lanes=38 v=100-127`. Order inside one script: bar blocks, then `copy`, `remap`, `delete`, then `accent`, `vel`, `ramp`, then `humanize` and `shift` last (they move notes off the cell lines that `beats=` windows select). `show` hides micro timing and velocity inside a digit band, so run `humanize` and `shift` once per lane per section: a second run stacks on the first. To redo, reset the shape first with `accent` or `vel set=`.

## 1. Velocity ranges per lane

| lane | hit | velocity | digit | healthy sd | basis |
|---|---|---|---|---|---|
| kick 36 | hit that lands on a `# riff` x | 118-127 | 9 | 0-4 | [17][18][21], exact band unconfirmed |
| kick 36 | inner notes of a run (4+ adjacent cells at grid=32 or 24) | 105-120 | 8 | 3-6 | [18][19] softer strokes for evenness, numbers unconfirmed |
| snare 38 | backbeat, rimshot | 118-127 | 9 | 2-5 | [1][2][3][17] |
| snare 38 | blast, fast alternating singles | 100-125 alternating | 7-9 | 5-8 | [3][4][23] |
| snare 38 | ghost | 25-50, up to 60 in a dense mix | 2-4 | 5-9 | [1][4][5][15] |
| snare 38 | flam grace | 45-75 | 4-5 | | [7] says quieter than the main, numbers unconfirmed |
| rim 37 | cross stick, clean sections | 85-110 | 6-8 | 4-7 | unconfirmed |
| hh 42 | shoulder accent | 100-118 | 7-8 | lane total 10-20 | [1][5][10][11] |
| hh 42 | tip | 60-98 | 5-7 | | [1][15] |
| hh 42 | filler sixteenth | 45-65 | 4-5 | | unconfirmed |
| hh_open 46 | sloshy keeper on quarters or eighths | 95-115 | 7-8 | 5-9 | usage [18], numbers unconfirmed |
| hh_open 46 | single offbeat opening | 98-112 | 7-8 | | unconfirmed |
| hh_pedal 44 | foot chick | 60-90 | 5-6 | 3-6 | usage [11][17][20], numbers unconfirmed |
| ride 51 | bow | 70-100 | 5-7 | 8-14 | unconfirmed |
| ride_bell 53 | bell | 100-122 | 7-9 | 4-8 | unconfirmed |
| crash1 49, crash2 57 | accent with the riff, section start | 108-124 | 8-9 | 4-8 | [6] |
| crash1 49 | crash keeper on quarters or eighths | 95-115 | 7-8 | 6-10 | unconfirmed |
| china 52 | quarter note keeper | 105-124 | 8-9 | 4-8 | unconfirmed |
| splash 55 | short accent | 90-112 | 7-8 | | unconfirmed |
| tom1 to tom6 | fill notes | 95-125 | 7-9 | 6-12 | [6] |

How this style differs from rock, funk and pop programming:

- Kick and backbeat are sample reinforced on the records: Meshuggah album drums are library samples blended with close mics [18], Haake rimshots every snare and calls the band "not a dynamic band" [17], triggers remove kick dynamics [21]. Kick and backbeat therefore live in digits 8-9 with sd under 5. That is correct, do not "fix" it.
- One single value is still wrong: an identical velocity fires one sample over and over [22][23]. Backbeats alternate inside 120-127 [3]. A normal backbeat is 115-120 with 125-127 kept for peaks [2]. 110-120 is closer to a real hard hit than 127 in most libraries [6].
- General guides put secondary kicks at 75-95 [5]. Do not apply that to kicks that double the riff (unconfirmed, follows from [17][21]).
- The dynamic range lives in four places: hats and ride (40-60 units between tip and shoulder), ghosts (25-50 under a 120+ backbeat), tom fills (ramps, weak hand 5-25 lower [6]), cymbal choice and crash velocity.
- So a feel request edits hats, cymbals, ghosts and toms first. Change kick or backbeat velocity only for "punchier", "more aggressive", "softer".

## 2. Machine gun: reading it and curing it

Header line `# lanes: pitch lane count vel min/avg/max sd`. Machine gun = sd under 3, or min = max, or every cell of the lane in the section shows one digit (the header is song wide, the grid is the truth for a section). The snare lane mixes two bands: sd under 6 means no ghosts exist. sd 30+ built from only two digits (9 and one ghost digit) means each band is still a machine gun.

| lane | verdict at sd under 3 | cure |
|---|---|---|
| kick on riff | correct | none. If asked for less robotic: `humanize lanes=kick vel=3`, never `time=` |
| kick run at grid=32 | fix | strong foot, weak foot: `accent lanes=kick grid=32 pattern=98 mix=0.6` on those bars only |
| backbeat | nearly correct | `humanize lanes=38 v=100-127 vel=3` then `vel lanes=38 v=100-127 min=116` |
| blast snare on eighths | fix | `accent lanes=38 grid=16 pattern=9-8- mix=0.8` (125 and 115 alternating [4]), `humanize vel=4` |
| ghosts | fix | `vel lanes=38 v=1-62 min=25 max=50`, `humanize lanes=38 v=1-62 vel=6` |
| hh, ride keeper | fix, this is the main case | shape with `accent` (section 3), then `humanize vel=5` to `vel=8` [3][4]. Target sd 10-20 |
| china or crash keeper on quarters | fix | `accent grid=16 pattern=9---8---8---8---`, `humanize vel=4`. Target sd 4-8 |
| toms and snare in fills | fix | `ramp fills lanes=tom,38 from=100 to=124`, then weak hand: `accent fills lanes=tom,38 grid=16 pattern=-6 mix=0.3` (use grid=32 for 32nd fills), `humanize fills vel=5` |

## 3. Hat and ride accent patterns

Mechanics: an accent is the shoulder of the stick on the edge, a non accent is the tip on top of the hat, and easing the pedal a little makes the accent bigger [10][11]. Samplers ship these as edge and tip articulations [12]. The built in map has one closed pitch (42), so shoulder versus tip is velocity only: 100 and up reads as shoulder, 98 and down as tip. Every hat part needs a hierarchy of hits [5]. Offbeat hits sit below on beat hits by default [1][8].

| part | `accent grid=16 pattern=` | velocities | when |
|---|---|---|---|
| quarters | `8---7---` | 112, 98 | keeper over a polymetric kick, hand stays in 4/4 [18][20] |
| eighths, downbeat accent | `8-6-` | 112, 84 | default: shoulder on the beat, tip on the "and" [5][10] |
| eighths, hot | `8-7-` | 112, 98 | loud chorus, the 110 and 95 advice [1] |
| eighths, upbeat accent | `6-8-` | 84, 112 | pushes forward, halftime sections [10] |
| sixteenths, one hand | `8565` | 112, 70, 84, 70 | 9575 one step lower |
| sixteenths, one hand, 2 beat cycle | `75658565` | beats 2 and 4 strongest | high low medium low, very high low medium low, measured on a one handed part [13] |
| sixteenths, one hand, 1 bar cycle | `7565856575658575` | last "and" lifted | leads into the next bar |
| sixteenths, two hands | `8676` | 112, 84, 98, 84 | section 4, no hat on snare cells |
| sixteenths, accent every 3rd cell | `8558558558558558` | 112, 70 | displaced accents that follow a riff grouped in threes (unconfirmed for this style) |

Why not plain `9575`: (a) 127 on a closed hat fires the hardest sample on every beat and competes with the snare, (b) all four beats are identical, so it loops after one beat however large the sd is (about 24), (c) it puts hats under the snare, wrong for two handed parts. Use it one step lower, on a 2 beat or 1 bar cycle, then `humanize vel=5`. `mix=0.5` to `0.7` keeps part of what was there. For the ride: same patterns on 51, then turn the accents into bell hits.

```vd
# eighth hats in bars 1-4: shoulder 112 on the beat, tip 84 on the "and"
accent bars=1-4 lanes=42 grid=16 pattern=8-6-
# ride in bars 5-8: same shape, then every hit of 105 and up becomes a bell hit
accent bars=5-8 lanes=51 grid=16 pattern=8-6-
remap bars=5-8 lanes=51 v=105-127 to=ride_bell
humanize bars=1-8 lanes=hat,ride vel=5 seed=11
```

## 4. One handed versus two handed sixteenths

- One handed: the hat hand plays every cell, including the snare cells. Natural shape `8565` or `75658565`: accent on the beat, medium on the "and", lowest on "e" and "a" [13]. Measured case is 96 bpm [13]. Above about 110 bpm assume sixteenth hats are two handed (threshold unconfirmed).
- Two handed (RLRL): right hand on the beat and the "and", left hand on "e" and "a", left 5-25 lower [6][8]. The right hand leaves for the backbeat, so the snare cell has no hat [9]. Shape `8676` with a hole: flatter (28 units of range against 42).
- Both: no hats during a tom fill, the hands are busy [8]. At most two hand lanes sound on one cell [6].

```vd
# bar 1 one handed (100 bpm), bar 2 two handed (140 bpm): no hat on the snare cells 5 and 13
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

- Offbeat opening: `remap` one closed hat on the "and" of 4 (beat 4.5) to `hh_open` every 2nd or 4th bar. The "and" of 2 is the second choice. Velocity 98-112.
- Choke: open and closed hats share a choke group [9]. The cell after an opening must hold `hh` 42 or `hh_pedal` 44, or the open hat rings on. If that cell has a crash (hand busy), write `hh_pedal` at 70-85 there.
- Sloshy keeper: quarter notes on `hh_open` at 95-115 with the snare on 3 (feel `half`) is a documented Haake pattern [18]. The map has no half open pitch. `hh_open` at 85-100 is the stand in (unconfirmed per sampler).
- Pedal hat: chick on 2 and 4 or on all four quarters [11], or eighths under a ride or china keeper [20]. Only where the left foot is free: no `hh_pedal` in a beat with a kick run at grid=32 or 24, or with kicks on adjacent sixteenth cells at 120 bpm and up (threshold unconfirmed). Haake keeps the hat foot going whenever he is not on both bass drums [17].
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

- Loop detector: `# bar N = bar M` lines. Three or more in a row inside a section means the keeper needs variation. Vary hats, ride, ghosts. Do not vary a riff locked kick.
- Unit: a 2 bar cell. Bar 4 differs by one event (extra opening, one accent moved). Bar 8 differs more (lift, fill). Changing sounds every 1, 2 or 4 bars is the standard advice [9].
- Quieter repeat: when a 4 bar phrase repeats, scale the keeper by 0.90-0.94 for the first 2 bars of the repeat, full level after. Kick and backbeat unchanged (unconfirmed as a rule, common practice).
- Lift into a fill: over the 2 beats before the fill, `ramp` closed hats from tip level to 118, or open the last eighth. Inside a two handed fill, delete hats [8].
- After a fill: crash at 118-124 plus kick on beat 1, hat back on the "and".

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

- Keeper ladder, low to high intensity: `hh` eighths, `hh_open` quarters or eighths, `ride` bow, `ride_bell`, `crash1` quarters, `china` quarters. "Heavier" or "more aggressive" moves one step up, "softer" one step down (ordering unconfirmed). The cymbal hand stays on a straight 4/4 pulse while kick and snare follow the guitar cycle [18][19][20].
- Accent with the riff: a crash or china always has a kick on the same cell. Haake plays hits only with the guitar hits [17].
- Stacked accent: `china` 52 plus `crash1` 49 on one cell uses both hands, so no snare, hat or tom on that cell [6]. Keep it for section downbeats and the last hit of a phrase.
- Alternating: accent hits closer than a quarter note alternate `crash1` (strong hand, 112-124) and `crash2` (weak hand, 5-25 lower [6]). The same cymbal twice at one velocity is a machine gun [22]. Which side leads is unconfirmed.
- Crash velocity: 108-124 by importance, phrase start highest. 127 at most once or twice per section [6].
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

| bpm | ms per tick | sixteenth cell | 5 ms | 10 ms | 20 ms | 30 ms |
|---|---|---|---|---|---|---|
| 100 | 1.25 | 150 ms | 4 ticks | 8 | 16 | 24 |
| 140 | 0.89 | 107 ms | 6 ticks | 11 | 22 | 34 |
| 180 | 0.69 | 83 ms | 7 ticks | 14 | 29 | 43 |

Anchors: an unquantized one handed hat part at 96 bpm has 8.7 ms sd on its sixteenth intervals [13]. Metal edits are quantized to 85-95 percent strength, not 100 [2][3][4]. 5 and 10 ms are the useful push or drag amounts, 20 ms is the edge of sounding wrong, and against programmed parts stay at 5-10 [14]. Velocity spread of plus or minus 5-10 is the stated range [3][4]. The per lane split below is a working default (unconfirmed).

| selector | `humanize vel=` | `time=` at 100 / 140 / 180 bpm | in ms |
|---|---|---|---|
| `lanes=kick` | 0-3 | 0 / 0 / 0 | 0 |
| `lanes=38 v=100-127` | 3-4 | 0-1 / 0-2 / 0-2 | 0-1.5 |
| `lanes=cym` on riff accents | 4-5 | 1-2 / 2 / 2-3 | under 2 |
| `lanes=hat,ride` | 5-8 | 2-4 / 3-6 / 4-7 | 3-5 |
| `lanes=tom` in fills | 5-8 | 2-4 / 3-6 / 4-7 | 3-5 |
| `lanes=38 v=1-62` | 5-8 | 3-6 / 5-9 / 6-11 | 4-8 |

- Stays on the grid: every kick where the section `lock` is 0.8 or more or the cell has a `# riff` x, the backbeat [2], cymbal hits that share a cell with a riff accent. A quantized kick is the foundation while hats and snare may float [7].
- May move: hats, ride, ghosts, inner notes of tom fills, flam grace notes.
- No quantize op exists. To snap a lane back: one script with `delete <sel>`, apply, then a second script that rewrites the rows (new notes land exactly on the cell line).

Flams: the main note stays on the grid, the grace comes 6-30 ms earlier and quieter [7]. Use 15-30 ms, constant in ms at any tempo: 12-24 ticks at 100 bpm, 17-34 at 140, 22-43 at 180. Grace velocity 40-60 percent of the main (unconfirmed). One grid=32 cell (60 ticks, 54 ms at 140) is too wide and reads as a drag: write the grace one grid=32 cell early, then `shift` it later. Place flams on a backbeat before a section change or the first or last note of a fill, at most 1-2 per 4 bars (unconfirmed).

```vd
bar 2 grid=32
#            1        2        3        4
snare 38   |-------- -------- -------4 9-------|
kick 36    |9------- -------- -------- --------|
# grace sits 60 ticks early. move it 38 later: 22 ticks before the main, 20 ms at 140 bpm
shift bars=2 beats=3.75-4 lanes=38 v=40-70 ticks=38
```

Push and laid back: a constant offset on one limb, not randomness [14]. Laid back (heavier, wider halftime): backbeat 5-10 ms late. Push (urgent): keeper or snare 5 ms early [7][15]. The kick never moves. If the shifted hit shares a cell with a `# riff` x, stay at 5 ms or less (unconfirmed, it would flam against the guitar).

```vd
# 140 bpm. laid back backbeat in bars 1-4: 6 ticks is 5 ms late
shift bars=1-4 lanes=38 v=100-127 ticks=6
# pushed keeper in bars 5-8: hats, ride and cymbals 4 ticks early
shift bars=5-8 lanes=hat,ride,cym ticks=-4
```

## 9. Ghost notes (needed by the recipes)

Velocity 25-50 [1][5][15]. Singles or pairs only, never three in a row. Avoid the sixteenth directly before and directly after a backbeat [5]. Prefer cells with no kick. With the backbeat on cells 5 and 13 at grid=16, good ghost cells are 8, 10, 16, then 2, 7, 11, 15. Haake and Garstka parts are full of ghosts [19][21].

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

`S` stands for the section selector, for example `bars=1-8`. Hat column applies to the ride as well (swap `lanes=42` for `lanes=51`).

| request | hat lane | ghosts | cymbals | kick and backbeat |
|---|---|---|---|---|
| more alive | full script below: shape, backbeat lean, openings, repeat, lift, spread | add 2-3 per bar (section 9), `humanize vel=6 time=5` | alternate crash1 and crash2, keeper `accent pattern=9---8---8---8---` | none |
| less robotic | no notes added or removed: `accent S lanes=42 grid=16 pattern=8-6- mix=0.6`, `humanize S lanes=hat vel=7 time=4` | `humanize S lanes=38 v=1-62 vel=6 time=5` | `humanize S lanes=cym,ride vel=5 time=2` | `humanize S lanes=kick vel=3`, `humanize S lanes=38 v=100-127 vel=3` |
| more human | less robotic, plus limb fixes: delete hats on snare cells of two handed sixteenths, `delete fills lanes=42,46`, hat under a crash removed | same, plus one flam per 4 bars | weak hand crash 5-25 lower | weak foot in runs: `accent lanes=kick grid=32 pattern=98 mix=0.6` |
| tighter | halve the spread around 96: `vel S lanes=42 scale=0.5 add=48`. Openings back to closed: `remap S lanes=46 to=hh`. No `time=`. Snap by delete and rewrite | `delete S lanes=38 v=1-30`, `vel S lanes=38 v=1-62 max=42` | crashes only on section starts and riff accents | `vel S lanes=kick min=120`, timing untouched |
| punchier | more contrast, not more level: `accent S lanes=42 grid=16 pattern=8-5-`, delete hats on crash cells | `vel S lanes=38 v=1-62 max=40` (bigger gap to the backbeat) | accents 120-124, each with a kick | `vel S lanes=kick min=122`, `vel S lanes=38 v=100-127 min=122` |
| softer | `vel S lanes=hat scale=0.8 max=96`, `remap S lanes=46 to=hh` | `vel S lanes=38 v=1-62 scale=0.8 min=20` | one step down the ladder: `remap S lanes=china to=ride`, `vel S lanes=cym,ride max=100` | heavy section: none. Clean section: `remap S lanes=38 v=100-127 to=rim`, `vel S lanes=kick scale=0.85 min=95` |
| more dynamic | wider shape `pattern=8-5-`, quieter repeat (`scale=0.9` on bars 5-6), `ramp` into each fill | pair that rises into the backbeat: 28 then 45 | phrase start 124, mid phrase 108-115 | none. Fills: `ramp fills lanes=tom,38 from=95 to=125` |
| more aggressive | one step up the ladder: delete the "and" hats, `remap S lanes=42 to=hh_open`, `vel S lanes=46 set=112`, or `remap` to china on quarters | delete below 35 or raise to 45-60 | china plus crash1 stacked on phrase starts | `vel S lanes=kick min=124`, `vel S lanes=38 v=100-127 min=124` |
| smoother | less contrast: `accent S lanes=42 grid=16 pattern=7-6-`, `vel S lanes=42 max=104`, `remap S lanes=46 to=hh`, `humanize vel=3`, time 3 ticks or less | `vel S lanes=38 v=1-62 max=42`, no flams | `vel S lanes=cym max=115`, `remap S lanes=ride_bell to=ride` | none |
| groovier | upbeat accent `pattern=6-8-` or the 2 beat cycle `75658565`, opening on the "and" of 2 or 4 | add on cells 8, 10, 16 at 30-45 | none | backbeat 5 ms late: `shift S lanes=38 v=100-127 ticks=6` at 140 bpm. Kick never shifts |

Complete "make the hi hat more alive" script. Input: bars 1-8, keeper `hh`, feel `normal`, hats are eighth notes on 42 at one velocity (sd 0), fill at `8:3-5`, 140 bpm. Expected result: hh sd about 14, three articulations in use, no two neighbouring bars alike, kick and snare untouched.

```vd
# 1 foot keeps time under the fill in bar 8 (skip if the kick is doubled there)
bar 8 grid=16
hh_pedal 44 |---- ---- 6--- 6---|
# 2 openings: "and" of 4 in bars 2, 4, 6, plus the "and" of 3 in bar 4. the next closed hat chokes each one
remap bars=2,4,6 beats=4.5-4.75 lanes=42 to=hh_open
remap bars=4 beats=3.5-3.75 lanes=42 to=hh_open
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

## 11. Sources

1. https://www.nailthemix.com/drum-programming-faqs (backbeat 120-127, ghosts 20-50, hats 110 and 95)
2. https://www.nailthemix.com/getgood-drums-matt-halpern-drums-library (backbeat 115-120, blast 125-127, quantize 85-90 percent, backbeat rock solid)
3. https://www.nailthemix.com/toontrack-metal-foundry-sdx (alternate 120 and 127, blast 100-115, quantize 90-95 percent, plus or minus 5-10)
4. https://www.nailthemix.com/toontrack-metal-machinery-sdx (blast 115 and 125, ghosts 40-70, plus or minus 5-10)
5. https://www.toontrack.com/blog/how-to-program-drums/ (hat hierarchy, edge on downbeats and tip on upbeats, ghosts 20-45 and their placement, kick 100-115 and 75-95)
6. https://urm.academy/5-drum-programming-tips-for-maximum-realism/ (110-120 over 127, four limbs, weak hand 5-25 lower)
7. https://www.soundonsound.com/techniques/making-midi-sequencing-more-realistic-part-2-drum-parts (flam 6-30 ms early and quieter, kick quantized while hat and snare float, lead and lag)
8. https://www.soundonsound.com/techniques/programming-realistic-drum-parts (every other hit lower for alternate hands, no hats in a tom fill)
9. https://www.production-expert.com/production-expert-1/6-killer-hi-hat-programmingnbsptipsnbspfor-musicnbspproducers (two handed sixteenths skip the snare cell, choke group, pedal, change every 1, 2 or 4 bars)
10. https://drummagazine.com/lesson-how-to-get-that-tasty-16th-note-hi-hat-feel/ (shoulder accents, downbeat and upbeat accent placements, pedal pressure)
11. https://rhythmnotes.net/hi-hat-techniques/ (shoulder on edge, tip on top, degrees of open, foot chick on 2 and 4 or all four)
12. https://www.toontrack.com/forums/topic/tip-and-edge-of-hihat-what-do-you-mean/ (tip and edge articulations)
13. https://journals.plos.org/plosone/article?id=10.1371/journal.pone.0127902 (one handed sixteenth hats at 96 bpm: 8.7 ms sd, loudness pattern, long range correlation)
14. https://www.confidentdrummer.com/playing-ahead-or-behind-the-beat-full-course-part-1-theory/ (5, 10 and 20 ms, single limb offsets)
15. https://www.slamtracks.com/2025/12/20/5-secrets-to-humanizing-midi-drums/ (hats 60-95, ghosts 25-45, snare 5-15 ms early)
16. https://www.slamtracks.com/how-to-program-midi-drums-to-sound-like-the-real-thing/ (about 20 ticks and 20 percent velocity variation, read as an upper bound)
17. https://drummagazine.com/tomas-haake-meshuggahs-djentle-giant/ (hat foot keeps going, not a dynamic band, rimshots, hits only with the guitar, stack cymbal)
18. https://drummagazine.com/tomas-haake-meshuggah-goes-it-alone/ (quarter notes on sloshy hats with snare on 3, album drums are samples, softer strokes for evenness)
19. https://www.drumeo.com/beat/meshuggah-tomas-haake-genius/ (ghost notes, kick and snare follow the guitar, lighter foot technique on Bleed)
20. https://clashplaids.tumblr.com/post/152393286901/form-analysis-and-partial-transcription/amp (Clockworks: right hand constant quarters, left foot eighths on the hat)
21. https://drummagazine.com/matt-garstka-lets-get-technical/ (triggers remove bass drum dynamics)
22. https://www.nailthemix.com/3-killer-drum-sample-replacement-techniques-for-metal (identical hits are a machine gun, do not set everything to 127)
23. https://www.nailthemix.com/slate-trigger-2 (all 127 is a machine gun, blast hits 95-115)
