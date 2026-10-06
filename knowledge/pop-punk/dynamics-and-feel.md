# Dynamics and feel: velocity, articulation, micro timing (pop punk)

Scope: pop punk from the 90s and 2000s wave to the modern scene and its easycore edge. Units: velocity 1-127, grid cells, beats (quarter notes), ticks at 480 ppq. Cell numbers are grid=16 indexes 0-15: beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12, the "and"s = 2, 6, 10, 14. A grid digit d is velocity d*14 (9 = 127) and `accent` uses the same digits. Everything below is written for notation A at 180 bpm (section 1) unless the line says otherwise, and every example for bars 1-8 of one section. A worked answer is one example: its comments show how each cell, level and bar was read from that example's grid. Another file gives other cells, so never carry a line over: do the reading on his file (EP 20). `[n]` = source in section 10. "unconfirmed" = working default, no source found. "EP n" = rule n of `knowledge/editing-principles.md`, which rules every recipe here.

Selectors: closed hat `lanes=42`, its shoulder strokes `lanes=42 v=100-127`, its tips `lanes=42 v=1-99`. `lanes=hat` also selects the open hat 46 and the foot 44: use it only when every articulation is meant (EP 19). Backbeats `lanes=38 v=100-127`, ghosts `lanes=38 v=1-59` (the engine counts a snare or rim hit of 60 or more as a backbeat when it labels the feel). `lanes=snare` also selects `rim` 37, and a fill note of 100 or more matches the backbeat selector: keep fill and build bars out of the `bars=` of a backbeat op. The map has no rimshot pitch: a rimshot is `snare` 38 at 116 or more, `rim` 37 is the cross stick. Give every op a `lanes=` part: without one it hits every drum note. `accent`, `vel`, `ramp` and `humanize` only change notes that exist, and a selector that finds nothing is silent: check every line in `show --vel`.

The kit and the file: `hh_open` 46 and `hh_pedal` 44 are articulations of the hat he has, so a hat request may use them. `crash2`, `china`, `splash`, `ride_bell` and `rim` are other instruments: use one only when `# lanes` shows notes on it or he asks, else the nearest lane that has notes, and say so (EP 24). No riff track (no `# riff` row, no lock column): skip every step that names them, say so, and leave every groove kick where it is (EP 21). The kick row is still read: the leans of section 4 need no riff track. A fill in the last bar of the file has no landing (EP 22). A fill that lands on a plain bar with no crash: a feel request leaves it and names it in the report, a fill request gives it one (fills.md, EP 23).

Direction (EP 3). "Alive", "less robotic", "more human" and "more dynamic" keep the average about level: strong notes rise, plain "and"s may come down, and the report says what came down. A request for more ("punchier", "more energy", "more driving", "more aggressive") never leaves a note in its scope quieter. "Softer" leaves none louder. Order inside one script (EP 16): (1) notes: bar blocks, `copy`, `remap`, `delete`. (2) Level, the ops that overwrite a part: `accent` at mix 1, `vel set=` on a lane. They erase the shape that was there, so they are for flat parts. A part that has shape takes relative ops (`vel add=`, `vel scale=`, `ramp scale=A-B`). (3) `humanize`, one named pitch at a time, `vel=2` on a keeper and 3 on kick or backbeat: a finish, never what makes two bars differ (EP 17). (4) Gestures, after the spread so it cannot blur them: `vel add=`, `vel set=` on one designed note, `max=` for a handover, and last the lift of section 6. A gesture meant to be heard is 15 to 25 (EP 17). (5) `shift` last. Walls (EP 13): shoulder against tip at 100 on the closed hat, ghost against backbeat at 60 on the snare. A note is written on one side on purpose and no `scale`, `add` or `humanize` may carry it across. `show` hides micro timing and everything inside a digit band (14 wide), `show --vel` prints the exact values. Run `humanize` and `shift` once per lane per section: a second run stacks on the first.

## 1. Which notation the file uses
The same beat can be stored two ways. Read the bpm from the `# tempo:` header line and the feel of the longest verse or chorus from the `# sections` line, then compute backbeats per minute: `normal` = bpm / 2, `double` = bpm, `half` = bpm / 4. The fast beat of the style sits at 75-110 backbeats per minute, which is 150-220 bpm with the snare on 2 and 4 [1][24][32]. Mid tempo songs sit at 47-75 (Down is 94 bpm [15], pack tempos start at 116 [20]). Decide once per file, not per section, and never convert a file: write in the notation it already uses. A short section labelled `blast` is a snare build (8 or more snare hits of 60+ per bar), not a blast beat.

| the file shows | notation | snare | hats |
|---|---|---|---|
| bpm 150-220, feel `normal` | A, full tempo. The common one: MIDI packs run up to 204 bpm [20], pop punk examples sit at 180-200 [1][24] | cells 4 and 12 | eighths on the 8 even cells, one handed |
| bpm 75-110, feel `double` | B, half tempo: the same music, one bar holds two bars of A. Drum lessons write the punk beat this way [1][21][22]. A `normal` section inside such a file is its half time part | cells 2, 6, 10, 14, kick mostly on 0, 4, 8, 12 | all 16 cells = A's eighths, still one handed, so hats on the snare cells are correct. Only the 8 even cells = A's quarters |
| bpm 150-220, feel `double` | A, real double time: the alternation of the fast beat at twice its rate. Hardcore edge, short bursts (how common is unconfirmed) | every "and" | keeper on quarters, in unison with the kick |
| bpm 150-220, feel `half` | A, half time bridge or easycore breakdown [31][32] | cell 8 | quarters on crash, china, ride or open hat |
| bpm under 150, feel `normal` in every section | A, a real mid tempo song: no section of the file reads `double` | cells 4 and 12 | eighths, one handed sixteenths under about 110 bpm, ghosts are in play (section 2) |

- A to B, patterns: drop the `-` between hat hits. A `grid=16 pattern=8-6-8-6-7-6-8-6-` is B `pattern=86867686`. A's sixteenths are B's grid=32, an 8 bar A phrase is 4 B bars.
- A to B, positions: A bar n beat b is B bar (n+1)/2 beat (b+1)/2 for odd n, and B bar n/2 beat (b+1)/2 + 2 for even n. The A backbeat windows `beats=2-2.25` and `beats=4-4.25` become four B windows: `beats=1.5-1.625`, `2.5-2.625`, `3.5-3.625`, `4.5-4.625`.
- A to B, ticks: one tick lasts twice as long, so halve every `time=` and `ticks=` value (5 ms is 7 ticks at 180 bpm, 4 ticks at 90). The `humanize time=` cap of 20 ticks is 28 ms at 90 bpm: stay at `time=3` or less in B.

## 2. Velocity ranges per lane
| lane | hit | velocity | basis |
|---|---|---|---|
| kick 36 | main hits: beats 1 and 3, any cell with a `# riff` x. Lower band: the off beat note of a double (two kicks 1 or 2 cells apart) | main 110-124, default 116. Off beat note 100-112 | sample layered or programmed [17][18]. Bands unconfirmed: general guides say 100-115 and 75-95 [2], too soft for this mix |
| snare 38 | backbeat, always a rimshot: pitch 38 hit hard, never `rim` 37 | 116-127 | [1][2][18][19] |
| snare 38, toms | fills and builds | under the backbeats, the top by rank on the last note: 117 into a new section, 107 at most inside a section, a pickup 10 under its landing (102 under a crash at 112). fills.md section 6 owns the shape | [3][19]. Ranks: EP 5, 6, 9 |
| snare 38 | ghost: mid tempo songs (to about 160 bpm) and half time parts, none in the fast beat | 40-58, never 60 or more | Barker's ghosts are fully heard (grooves.md section 6), louder than the 20-45 of general guides [2]. Usage [15][24]. Band and tempo limit unconfirmed |
| rim 37 | cross stick, quiet verse or intro | 85-105 | unconfirmed |
| hh 42 | closed: shoulder on the beat, tip on the "and" | carrying beat 116, other beat 102, tip 84, lean 108 (section 4). The wall is 100. Never over 118: 127 fires the hardest sample on every beat and fights the snare | [2][6][7][11]. Numbers unconfirmed |
| hh_open 46 | sloshy keeper (chorus, loud verse). One opening (bark) | keeper beats 112, "and"s 98, band 88-124. Opening 104-120 | usage [1][14][21][29], numbers unconfirmed |
| hh_pedal 44 | foot: closing an opening under a crash, a chick under a crash or ride keeper | 50-80, 84 when it closes an opening | usage [6][15][28], numbers unconfirmed |
| crash1 49, crash2 57 | ridden as the keeper: the wash, shoulder of the stick on the edge [8], kept under its starts | beats 108, "and"s and plain beats 94, band 88-112 | [8][21][23], numbers unconfirmed |
| crash1 49, crash2 57 | accent, full stroke: section start, landing after a fill, stab on a kick | section start 122-127. A landing, phrase start or stab inside the section 10 under it (112-118) | [8]. 127 only on the biggest hits [3]. The bands touch: tell a ridden hit from an accent by its cell, not by `v=` |
| ride 51, ride_bell 53 | chorus or bridge keeper | bow 84-112, bell 105-122 | usage [12][13][15], numbers unconfirmed |
| china 52, splash 55 | china: breakdown quarters. splash: short accent inside a groove or fill | china 108-124, splash 95-115 | usage [12][31], numbers unconfirmed |

- Production: loud, compressed, sample reinforced. The kick is about 90 percent live and 10 percent sample for constant low end [17], or tracked hands only and programmed as MIDI afterwards [18]. The snare is hit hard and consistently, then layered with samples [17][18], and every backbeat is a rimshot [1]. So kick and backbeat live in digits 8-9 with an `sd` of 2-5. That is the style: do not widen it.
- One exact value is still wrong: 110-120 is closer to a real hard hit than a wall of 127 [3]. 127 belongs to section starts, flammed backbeats, the last backbeat before a fill and the last chorus. Highest velocities go to the backbeats, lower ones to ghosts, fills and fast passages [19].
- Dynamics come from instrument choice, not from softer strokes: Barker plays loud throughout and gets quieter by closing the hats or swapping a drum for a smaller sound [12]. Verses sit on a closed hat, choruses open up to half open hat, crash or ride [13][14][30]. A feel request therefore edits, in this order: how the keeper is played (this document), which lane keeps time (grooves.md section 3), then fills (fills.md). The level of kick or backbeat changes only for "punchier", "more aggressive", "softer", "tighter", and to take a wall of 127 off the ceiling in "less robotic".
- Ghost notes are rare at full speed: at 180-200 bpm there is no room, fills are one bar, quick and tight [24]. They belong to mid tempo songs (Down, 94 bpm [15]) and half time bridges.

## 3. Machine gun: reading it and curing it per lane
Header line `# lanes: pitch lane count vel min/avg/max sd`. Machine gun = `sd` under 3, or min = max, or one digit in every cell of the lane in the section (the header is song wide: for one section read `show --vel --bars`). A lane can hold two bands (hat shoulder and tip, backbeats and fill notes): a large `sd` built from two exact values is still two machine guns. `sd` finds a flat lane. It is never the test of a cure: `humanize` on a one beat pattern reaches any `sd` and is still a one beat loop. A cure is a shape read from the grid (section 4), motion over the phrase (section 6), and only then a small spread. A flat lane outside the request is not cured: one line in the report. `S` = the section selector, for example `bars=1-8`.

| lane | verdict at sd under 3 | cure |
|---|---|---|
| kick | nearly correct [17][18] | `humanize S lanes=kick vel=3`. Never `time=`, never a `min=` floor. At 127 the spread can only go down (124-127): leave the level, a lower kick is a "softer" request |
| backbeat | nearly correct [1][18]. Fix only a wall (min = max) | `vel S lanes=38 v=100-127 add=-5`, `humanize S lanes=38 v=100-127 vel=3` (119-125), with every fill bar left out of `S`: the last backbeat before a fill keeps its 127, the designed top. A lane with `sd` 3 or more: leave it |
| hat, ride or ridden crash in eighths | fix, the main case | sections 4 to 6: levels and leans read from the grid, openings on kick hits, motion over the phrase. Worked in section 9 |
| quarter keeper: open hat, ride, crash, china | fix | the quarter row of section 5 |
| a keeper flat at 119-127 | fix only for "alive", "less robotic", "more human", "more dynamic" | the ceiling rows of section 5. The report says what came down |
| crash accents all at 127 | fix by rank | section 6 |
| snare and toms in fills and builds | fix, but not from this document | fills.md section 6: one fill at a time, by rank, the last note on top (EP 5, 9). No fill op lives here |

Ceiling (EP 3, 4). A lane flat at 127 cannot go up. The feel words above shape it by lowering its weak positions only. A request for more ("punchier", "more energy", "more aggressive", "bigger", "harder") never lowers. It takes, in this order, what has room: weight (a second cymbal on the section start, a kick under a hit), air before the start, the lanes with headroom (fills at 98 under a section at 127). grooves.md section 3 and fills.md sections 9 and 10 hold those scripts. Lowering the weak positions comes last, only when he asks again, never alone, and the report calls it quieter.
```vd
# "less robotic" on a chorus at the ceiling. no note added or removed, and the report says what came down
# 1 keeper: crash1 eighths flat at 127, bars 1-8. no crash in bar 8 beats 3-4 (fill)
# 2 the ceiling: every beat keeps its level
# 3 kick under an "and": bars 1 3 5 7  kick 9-9- ---- 9--- --9-  cells 2 and 14. bars 2 4 6  kick 9--- --9- 9-9- ----  cells 6 and 10
# 4 phrases 1-4 and 5-8. fill 8:3-5, 2 beats, ends the section
# the plain "and"s come down 20 (107). bar 8 holds the fill and stays out: full into it
accent bars=1-7 lanes=49 grid=16 pattern=--7- mix=0.7
humanize bars=1-8 lanes=49 vel=2 seed=5
# a lean keeps its level. phrase 1, one per bar, no cell twice: 2, 6, then 14 and 10
vel bars=1 beats=1.5-1.75 lanes=49 add=20
vel bars=2 beats=2.5-2.75 lanes=49 add=20
vel bars=3 beats=4.5-4.75 lanes=49 add=20
vel bars=4 beats=3.5-3.75 lanes=49 add=20
# phrase 2: every kick "and"
vel bars=5,7 beats=1.5-1.75 lanes=49 add=20
vel bars=5,7 beats=4.5-4.75 lanes=49 add=20
vel bars=6 beats=2.5-2.75 lanes=49 add=20
vel bars=6 beats=3.5-3.75 lanes=49 add=20
# kick flat at 127: spread only. backbeats flat at 127: 5 down and a spread. bar 8 stays out, its backbeat keeps 127 before the fill
humanize bars=1-8 lanes=kick vel=3 seed=4
vel bars=1-7 lanes=38 v=100-127 add=-5
humanize bars=1-7 lanes=38 v=100-127 vel=3 seed=3
```

## 4. Keeper shape: read the grid, then write
Mechanics: the beats are played with the shoulder of the stick on the edge of the hats, the "and"s with the tip on top [2][7][27], and the accents make the eighths read as quarter notes [27]. At punk speed that is one down and up motion per beat (unconfirmed). Easing the pedal a little thickens the accent [7]. The map has one closed pitch, so shoulder against tip is velocity only: 100 and up reads as shoulder, 99 and down as tip. Designed levels sit 2 or more away from that wall and the spread is 2. Offbeat hats sit below on beat hats [2][6], and a measured hat part is strongest where the hand lands with the snare [11]. The levels below, and the rules for leans, openings, handover and lift in sections 4 to 6, are working defaults (unconfirmed).

One row tiled over a section (`8-6-` on every beat) plus `humanize` is a one beat loop however large its `sd`. A fixed cell lifted in odd and even bars is the same loop two bars long. So nothing here is a pattern to paste: the cells come from the file. Read `show FILE --vel --bars S` and write four lists. They go into the script as its first comments:

1. Keeper: lane, rate (which cells hold a note), level now, and the cells with no keeper note (a crash on beat 1, a fill).
2. Carrying beats: beat 1 and the backbeat cells. Feel `normal`: beats 1, 2 and 4. Feel `half`: beats 1 and 3.
3. Kick "and"s: for each bar, the "and" cells (2, 6, 10, 14) where a kick sits under a keeper note. Bars with the same kick row form a group. The kick row is read, never moved. With a `# riff` row, of two candidates the one with a riff x goes first.
4. Phrases and fills. A phrase starts at the section start, at a crash on cell 0 and after a fill, else every 4 bars. For each fill: bar, first beat, length, whether it ends a phrase or the section, and H = the velocity of its first note.

Lever 1: levels and leans. Eighth note closed hat, feel `normal`:

| hit | level | op |
|---|---|---|
| carrying beat | 116 | `accent S lanes=42 grid=16 pattern=8-6-8-6-7-6-8-6-`, then `vel S lanes=42 v=91-127 add=4` (112 and 98 become 116 and 102). Feel `half`: `pattern=8-6-7-6-` |
| other beat | 102 | the same two lines |
| tip, a plain "and" | 84 | the same `accent` |
| lean, an "and" with a kick under it | 108, 24 over the tips | after `humanize`: `vel bars=<bar> beats=<that cell> lanes=42 add=24` |

- First phrase: one lean per bar at most, on the bar's first kick "and" that no earlier bar of the phrase leaned on. None left: the bar stays plain.
- Later phrases: every kick "and" of the bar. A bar with more than two takes that same pick, counted anew for this phrase, plus its last one.
- Not available: a cell that is an opening (section 5), inside a fill, or in the beat before a fill (section 6).
- Two neighbouring bars never end with the same row: the second drops its lean, or, after a plain bar, leans on its first kick "and".
- A bar with no kick "and" gets no lean: do not invent one. A lean on every kick "and" of every bar is a formula too: it prints the kick's loop onto the hat. On beat hats do not lean, they are shoulders already.
- The finish goes between the level lines and the leans: `humanize S lanes=42 vel=2`.
- A hat that was flat between 90 and 105 keeps its average: carrying beats and leans rise, the plain "and"s fall about 14. Say that they came down. Flat above 105 the part comes down on average: say so. A part that already shows two or more levels per beat: skip `accent`, `add=4` and `humanize`, keep his shape, and add the leans it lacks (`add=` 15 to 24) and levers 2 and 3.

Rate and tempo. One hand on eighths plays 5.3 strokes per second at 160 bpm, 6 at 180, 6.7 at 200, the rate of sixteenths at 80, 90 and 100 bpm. An edit keeps the rate the file has: changing it is a request of its own (grooves.md section 7).

| bpm (A) | keeper rate | base row | notes |
|---|---|---|---|
| 75-110 | sixteenths, one hand | `pattern=8565`, 2 beat cycle `75658565` (112, 70, 84, 70) | measured shape: high low medium low, very high low medium low [11]. Barker plays accented sixteenth hats at 94 bpm [15]. Above about 110 bpm: two hands, or eighths (limit unconfirmed) |
| 110-185 | eighths | the three levels above | default for verses [1][21] |
| 185-210 | eighths at the one hand limit | the same with digit 5 for the tips (70) | the up stroke thins out (unconfirmed) |
| 190-220 | quarters, for power | the quarter row of section 5 | accepted substitute for eighths at punk speed [26]. Usual as open hat or crash quarters [16][21][23] |
| under about 180 | sixteenths, two hands (bridge, build) | `pattern=8676` (112, 84, 98, 84) | the right hand leaves for the backbeat: no hat on cells 4 and 12 [6]. Only kick "and"s lean, they are the right hand. Misery Business bridge, 173 bpm [33] |
| any | upbeat accent | `pattern=6-8-`, then `vel S lanes=42 v=105-127 add=4` | accent placement from [7]. The bouncy form (feel unconfirmed) |

## 5. Other keepers, openings, the pedal, the keeper ladder
The four lists and the three levers are the same on every keeper. What changes against the closed eighth hat (`L` = the keeper's pitch):

| keeper | base on a flat row | lean | phrase start with no crash | notes |
|---|---|---|---|---|
| ride 51, eighths | the hat `accent` on `lanes=51` with no `add=`: 112, 98, 84. No wall at 100 | `add=24` | the carrying level it has | no openings. Bell hits [12][13] only when `ride_bell` has notes in `# lanes`: the carrying beats of the later phrase, `remap bars=<later phrase> lanes=51 v=105-127 to=ride_bell` right after the `accent` |
| sloshy hat 46, eighths | two levels, the wash hides a finer step (unconfirmed): `accent S lanes=46 grid=16 pattern=8-7-`, beats 112, "and"s 98 | `add=16` | `set=124` | lever 2 has no room: it is open already |
| ridden crash, eighths, max under 119 | `accent S lanes=L grid=16 pattern=8-7-`, then `vel S lanes=L add=-4`: 108 and 94, under its starts | `add=14` | `set=118` | the `accent` also hits the section start: set it back, `vel bars=1 beats=1-1.25 lanes=L set=127` |
| quarters: open hat, ride, crash (fast tempos, or feel `half`) | carrying beats over the others: `accent S lanes=L grid=16 pattern=8---8---7---8---` (`half`: `8---7---`), 112 and 98, crash then `add=-4` | later phrases only: a plain beat with a kick under it `add=14`. Every bar has that kick: every second bar | as its eighth row | no "and"s, no lift: the last hit before a fill of 2 beats or more takes the carrying level, H at most. Two bars inside a phrase may be alike, its phrases still differ |
| eighths flat at 119-127, the ceiling | nothing can rise. Every beat stays. The plain "and"s come down 20: `accent S lanes=L grid=16 pattern=--7- mix=0.7` (107) | a lean keeps its level: `add=20` after the spread | stays | the bar that holds a fill of 2 beats or more stays out of the `accent`: full into the fill |
| quarters flat at 119-127, the ceiling | carrying beats, phrase starts and the last hit before a fill stay. First phrase: the plain beats `add=-16` | later phrases: only the plain beats with no kick under them come down | stays | both ceiling rows: feel words only (section 3) |

- Lever 2, openings. An opening is a closed hat `remap`ped to `hh_open` on an "and" with a kick under it, closed by the next hat cell. Read both in the grid. Open and closed hats share a choke group [6]: `hh` 42 on the next hat cell cuts it. A crash there (the hand is busy): write `hh_pedal` at digit 6 on that cell, the foot closes alone [28], and report the added note. Never `hh_pedal` on a cell where a stick plays `hh` 42, and never open a plain tip with nothing under it.
- Where. First phrase: one, the bark on the "and" of 4 (cell 14), the most common open hat move in rock [29], in the last bar of the phrase that has a hat and a kick on that cell. No such bar: the last kick "and" of the phrase's second bar. Later phrases: the phrase start, when its beat 1 holds a hat and a kick and no crash, plus one in the second bar on a kick "and" the phrase before did not open. Two per phrase at most: a bark in every bar is the Barker layer (grooves.md section 6), not this.
- Level: a `remap` keeps the closed velocity, so set it after, per bar: `vel bars=N lanes=46 set=`. First phrase 104, later phrases 118, a phrase start 120: 14 or more between phrases. To undo an opening: `vel <sel> lanes=46 max=96` first, then `remap <sel> lanes=46 to=hh`.
- No candidate cell (no kick "and" before a closed hat, or every one inside a fill): lever 2 has no room. Say so, do not force it.
- Limbs: a crash or ride hit replaces the hat hit on that cell [3], and there are no stick hats during a two handed fill [5]. A hat that sits under a crash or inside a fill is left alone in a feel request: name it, deleting it is "more human".
- Foot under another keeper (on the "and"s under a ride, on the beats during a fill [6], foot eighths under an offbeat ride at 154 bpm [15]): `hh_pedal` at 50-70, only when he asks for the foot. Under a crash wash or a fill it is close to inaudible (unconfirmed), and it adds notes inside spans nobody named.
- Half open: the map has no half open pitch. Stand in: `hh_open` 46 at 88-124. Each hit cuts the last one: that is the slosh. Not too wide [21].
- Keeper ladder, low to high energy: closed hat, half open hat, ride or ride bell, crash riding, china quarters. Evidence: hats in verses and ride or bell in choruses (Tre Cool [13]). Hat partially open in every chorus and parts of two verses (Barker on the Low remix [14]). Verse with a lighter hat, chorus with crash, fuller stroke or ride [30]. Crash on 1, then open hat on the other three beats (First Date [16]). Kick on the guitar rhythm under quarter note crash (The Story So Far [23]). Crash on all quarters [21]. Breakdown: quarters on crash or china, snare on 3 [31]. The order of ride and crash is unconfirmed, and half open hat and ride count as one rung when a section moves (grooves.md section 3). Usual plan: verse closed hat, pre chorus half open or ride, chorus crash, ride or half open hat, last chorus one rung above the first, bridge or breakdown feel `half` on quarters (unconfirmed as a fixed rule).
- Moving a section one rung is a note edit of that whole section, from its bar 1 and never earlier (EP 6), only when the request names the section. grooves.md section 3 holds the rule and the hat to sloshy script, the crash rung is the script below. A crash rung written new is quarters above about 175 bpm and eighths below (the one handed limit of grooves.md section 7, unconfirmed). A file that already rides eighths keeps them: thinning is a rate change he has to ask for. Crash riding is the wash, shoulder of the stick on the edge. Tip on the bow is the quieter variant [8].
```vd
# "more energy in the chorus", the crash rung (180 bpm, so quarters), written here from a closed hat. from the sloshy hat or the ride: the same lines with 46 or 51 in lanes=
# 1 keeper: hh 42 eighths flat at 98, bars 1-8. crash1 + kick on bar 1 beat 1 with no hat under it. no hat in bar 8 beats 3-4 (fill)
# 2 carrying beats 1, 2 and 4. 3 kick under the plain beat 3: bars 1 3 5 7 only (bars 2 4 6 play cells 6 and 10)
# 4 phrases 1-4 and 5-8, no crash on bar 5. fill 8:3-5, 2 beats, first note 112
# notes: the "and"s out, the beats to crash1
delete bars=1-8 beats=1.5-2 lanes=42
delete bars=1-8 beats=2.5-3 lanes=42
delete bars=1-8 beats=3.5-4 lanes=42
delete bars=1-8 beats=4.5-5 lanes=42
remap bars=1-8 lanes=42 to=crash1
# level: carrying beats 108, beat 3 94, spread
accent bars=1-8 lanes=49 grid=16 pattern=8---8---7---8---
vel bars=1-8 lanes=49 add=-4
humanize bars=1-8 lanes=49 vel=2 seed=5
# gestures: the section start back to 127, the phrase start of bar 5 at 118, and in the later phrase beat 3 comes up where the kick is under it
vel bars=1 beats=1-1.25 lanes=49 set=127
vel bars=5 beats=1-1.25 lanes=49 set=118
vel bars=5,7 beats=3-3.25 lanes=49 add=14
# bar 8 beat 2 is the last hit before the fill: 108, under H = 112, so no handover line
```

## 6. Motion over the phrase: growth, handover, lift, loop test, crash ranks
Lever 3. A part is alive when it moves over the phrase: a start, a middle, an end (EP 12).

- Start. The section start stays as he wrote it. A later phrase start under a crash is marked already. One with no crash takes the opening of section 5, or the level of its keeper row there.
- Growth. The later phrase answers the first with more: every kick "and" leans (section 4), its openings are 14 higher and on other cells (section 5), and it holds the lift. A section of one phrase (4 bars): bars 1-2 follow the first phrase rules, bars 3-4 the later ones. Three or more phrases: grow in steps (one lean, every lean, every lean and a second opening), never two phrases alike.
- Handover (EP 14). H = the velocity of the fill's first note, 118 at most. In the beat before a fill no keeper note is over H: `vel bars=N beats=B lanes=42 max=H`. A hat that ends over the fill makes the fill smaller. A keeper that was over the fill before the edit (a crash at 127 into a fill at 98) is his mix: leave it and name it.
- Lift: into a fill of 2 beats or more that ends a phrase or the section. The last three keeper notes before it climb in even steps to H: `ramp bars=N beats=A-B lanes=42 from=H-24 to=H`, the last line of the script. Absolute values on purpose: the strokes even out and climb, and a lean inside the window is replaced. Beat 1 of the bar stays out of the window, it carries the bar. Fewer than three keeper notes between beat 1 and the fill: no lift. A fill that takes the whole bar: the lift sits in the bar before it. Never into a 1 beat pickup: the smaller fill gets the smaller approach, the handover alone (EP 5).
- Weak fills (H under 100) keep the lift low. Never raise fill notes in a hat request. Say it in the report: with heavier fills the hat can climb higher.
- Loop test (EP 12), on `show RESULT --vel --bars S`. Write down the keeper row of each bar. Two rows differ when one cell differs by 13 or more, by an opening, or by a missing note. No bar has the row of the bar before it, the section does not read A B A B, and the later phrase differs from the first in two bars or more. Differences that `humanize` made do not count: after any spread no `# bar N = bar M` line prints, so a missing fold proves nothing, and neither does `sd`. Before an edit: 3 equal rows in a row are a loop. Never vary a kick to break a loop. Adding kick notes over a 4 to 8 bar phrase is a Barker device [14] and a kick request: only on cells with a `# riff` x.
- Crash accents mark chord changes and section starts [13]: beat 1 of bar 1 always, of bar 5 usually, every 2 bars for more energy, each on a cell with a kick. Rank (EP 6): the section start is the biggest hit, 122-127, and the only place for two cymbals at once. A landing or phrase start inside the section is one crash 10 or more under it (112-118). No landing is bigger than the start of its own section or the first hit of the song, and a start stands 10 or more over the last note of the fill before it. Accents all at 127: the section start stays, every other one comes down by rank with a relative op named by bar and beat, never `max=`: `vel bars=5 beats=1-1.25 lanes=crash* add=-10`.
- Accents less than a bar apart alternate `crash1` and `crash2`, the second a digit lower (weak hand, 5-25 [3]). A kit with one crash: both on `crash1`, the second a digit lower. No hat under either. Riding stays on the pitch the header names as keeper and accents go to the other one. Which pitch is the left or right cymbal depends on the file (unconfirmed).

## 7. Micro timing
ticks = ms * bpm * ppq / 60000. One cell at 480 ppq: grid=16 is 120 ticks, grid=32 is 60.

| bpm | ms per tick | eighth, 240 ticks | sixteenth, 120 ticks | 3 ms | 5 ms | 10 ms | 15 ms | 20 ticks, the `humanize time=` cap |
|---|---|---|---|---|---|---|---|---|
| 160 | 0.78 | 188 ms | 94 ms | 4 ticks | 6 | 13 | 19 | 15.6 ms |
| 180 | 0.69 | 167 ms | 83 ms | 4 ticks | 7 | 14 | 22 | 13.9 ms |
| 200 | 0.63 | 150 ms | 75 ms | 5 ticks | 8 | 16 | 24 | 12.5 ms |
| 90, notation B | 1.39 | 333 ms | 167 ms | 2 ticks | 4 | 7 | 11 | 27.8 ms |

Anchors: a one handed hat part on a record has 8.7 ms sd on its sixteenths at 96 bpm, and a drummer playing to a metronome at 180 bpm in a lab study had 15.6 ms [11]. Pop punk records are tracked to a click and edited tight [24][32]. Listeners rate a fully quantized rock pattern above the same pattern with kick or snare displaced by 15 or 25 ms, the larger shift lowest [10]. Guides: quantize strength 90-95 percent [19], timing humanise 2-5 percent [3]. Useful push amounts are 5 and 10 ms, 20 ms is the edge of sounding wrong [9]. So in this style: random spread 2-4 ms, constant offsets 5-10 ms, nothing near 15 ms. A random spread this small is felt more than heard: `time=` belongs to "more human" and "looser", never to the default of another request, and the report says so. The per lane split is a working default (unconfirmed).

| selector | `humanize vel=` | `time=` at 160 / 180 / 200 bpm | in ms |
|---|---|---|---|
| `lanes=kick` | 0-3 | 0 / 0 / 0 | 0 |
| `lanes=38 v=100-127` | 3 | 0-2 / 0-2 / 0-2 | 0-1.5 |
| `lanes=cym` accents and quarter note crash riding | 2 | 0-2 / 0-2 / 0-2 | 0-1.5 |
| `lanes=42`, `lanes=46`, `lanes=51`, each on its own | 2 | 3-5 / 4-6 / 4-6 | 2.5-4 |
| `lanes=tom`, snare inside fills | 0-3 | 3-5 / 4-6 / 4-6 | 2.5-4 |
| `lanes=38 v=1-59` | 3 | 4-6 / 4-7 / 5-8 | 3-5 |

- Stays on the grid: every kick (section `lock` of 70 percent or more, a `# riff` x on the cell, or no riff track: assume bass and guitar double it [1][23]). A quantized kick is the foundation while hat and snare may float [4]. Also: crash accents that share a cell with a kick, unison stabs, quarter note crash riding (every hit lands with a kick or a snare). Backbeat: random timing of 2 ticks at most, a constant `shift` is a feel choice. May move: hats, ride, ghosts, inner notes of fills, flam graces. No quantize op exists: to snap a lane, `delete <sel>` first, then bar blocks that rewrite the rows from the `show` digits. New notes land on the cell line at digit * 14, so reshape the velocities after.

On top of the beat: punk urgency is a constant early offset on one limb, not randomness and not a faster tempo [9]. A snare that comes a fraction early makes a track drive [4]. Recipe at 180 bpm: every snare note that is not a ghost 7 ticks early (5 ms), `shift S lanes=38 v=60-127 ticks=-7`, so the snare notes of a fill and a flam grace move with the backbeats. Asked again: 14 ticks (10 ms), the ceiling. 15 ms is rated below quantized [10], and past 20 ticks a note leaves its cell. Hats, toms, crashes and the kick stay: the kick and bass lock survives because the kick never moves, and a crash on a kick cell would flam against it. A note at tick 0 (bar 1, beat 1) cannot move earlier. At other tempos keep the ms and take the ticks from the table. `diff` counts these notes as moved in time: report the number.

Flams: the main note stays on the grid, the grace comes 6-30 ms earlier and slightly quieter [4]. Barker uses power flams, and flams on snare and toms as accents [14][15]. Use 12-20 ms: 15-26 ticks at 160 bpm, 17-29 at 180, 19-32 at 200. Light grace 70-75, power flam grace 84-99 under a main of 112 or more: at 100 or more the backbeat selector `v=100-127` would catch it (bands unconfirmed). Write the grace one grid=32 cell early (60 ticks), then `shift` it later. A grace 20 ticks or less before the main shares the main's cell in `show`: only the louder digit prints, and changing that digit rescales both notes. A wider flam makes `show` print that bar at grid=48 with the grace in its own cell. Place flams on the last backbeat before a fill or a section change, the first note of a fill, or half time backbeats, 1-2 per 4 bars at most (unconfirmed). A flam adds a note: report it.
```vd
# 180 bpm, fill at 8:3-5. power flam on the last backbeat before the fill bar (bar 7 beat 4): copy the snare row from show at grid=32, add only the grace (digit 7)
bar 7 grid=32
#            1        2        3        4
snare 38   |-------- 9------- -------7 9-------|
# the grace sits 60 ticks early. 36 later leaves it 24 before the main (17 ms)
shift bars=7 beats=3.85-4 lanes=38 ticks=36
# push, bars 1-8: every snare note that is not a ghost 7 ticks early (5 ms). the grace moves with its main, so the flam keeps its width. kick, hats, crashes and toms stay
shift bars=1-8 lanes=38 v=60-127 ticks=-7
```

## 8. Stamina realism at fast tempos
- Rates: sixteenth singles hand to hand are 10.7 notes per second at 160 bpm, 12 at 180, 13.3 at 200, each hand at the eighth note rate of section 4. Players condition for it (Barker trains so he does not run out of steam [25]), weaker players get tired and sloppy toward the end of a song [21], four on the floor is tiring at fast tempos [30], and at 180-200 bpm fills stay one bar, quick and tight [24].
- Hand to hand: a sixteenth run at grid=16 is RLRL, right hand on the even cells. On a real take the weak hand is 5-25 lower [3][5], and Barker drops hard accents into single stroke runs [12]. An edit makes that difference by raising the strong notes, never by lowering the weak ones on a request for more, and the last note carries the top even when it falls to the weak hand (EP 3, 9, 10). fills.md section 6 holds the three lines (lean, rise, top).
- No sag on a fill or a build: a run that drifts down ends on a weak stroke. Builds rise and end 10 under the 127 they land on (rolls rise to about 120 [4]). Written new: rising digits from about 70 to 117 over one bar (fills.md section 5). A flat build that exists: `ramp F lanes=38 scale=1-B` with B = 117 / its level (1.19 from 98), so nothing starts lower than it was (EP 18). The kick is often programmed on the records [18], so a level kick is authentic: no sag there either.
- Fatigue (hat tips sagging about 10 across a long fast section [21], unconfirmed) only when he asks for a tired or live take: `ramp S lanes=42 v=1-99 scale=1-0.88`.
- Engine label: a bar with 8 or more snare hits of 60+ counts as feel `blast`, and a build of 3 bars or more prints as its own `blast` section. It is still a build.

## 9. Request recipes
`S` = the section selector, for example `bars=1-8`, `F` = one fill span, `N` and `B` = one bar and one beat window. Feel `half`: the backbeat is beat 3, so use `beats=3-3.25` where a recipe names beats 2 and 4. Notation B: convert with section 1. `ticks=` values are for 180 bpm: rescale with the table in section 7. How to read the table:

1. Pick one column: the lane he named, else the default target of the word (vocabulary.md section 5), else the hat column. "Less robotic" and "more human" name every flat lane: there, each column whose lane is flat. The hat column serves whichever lane keeps time, with the levels of its row in section 5.
2. Inside a cell the levers are in order of impact (EP 2). The default answer is the first two or three the file has room for, in one script (EP 1): not the safest one alone, not the whole list. He can say "more" or "less".
3. No room = already there, nothing to select, or the lane is at its ceiling (section 3). Skip that lever and say so, never force it. Every note added or deleted is reported.
4. Direction as in the intro. Other columns only when he names them or says "more". Check with `vibedrum diff`.

| request | keeper lane | snare | cymbals | toms and kick |
|---|---|---|---|---|
| more alive | the default answer below: levels and leans (section 4), openings (5), motion over the phrase (6) | none. He names the snare: a wall of 127 off the ceiling (section 3), then one power flam on the last backbeat before the fill that ends the section (section 7) | keeper is a ride or a ridden crash: its row in section 5. Accent crashes less than a bar apart: the second a digit lower | none. Fills: fills.md section 6 |
| less robotic | the default answer without its `remap` lines: an opening cell on an "and" is free for a lean, a phrase start keeps its carrying level. Nothing added or removed | a wall of 127: the backbeat line of section 3. Otherwise none | keeper: its row in section 5, the ceiling rows at 127. Accents all at 127: by rank (section 6) | `humanize S lanes=kick vel=3`, no `time=`. Fills: fills.md section 6, each by its rank |
| more human | less robotic first. Then limb fixes, each reported as a note removed or added: the hat cell under a crash blanked (bar block), `delete F lanes=42,46` inside a two handed fill. Two handed sixteenths: `delete S beats=2-2.25 lanes=42` and the same for `beats=4-4.25`. Then timing: `humanize S lanes=42 time=4` | one flam per 4-8 bars (section 7) | the second crash of a close pair 14 lower: `vel bars=N beats=B lanes=crash* add=-14` | the off beat note of a kick double one digit lower (bar block) |
| tighter | openings closed: `vel S lanes=46 max=96`, `remap S lanes=46 to=hh`. Then half the spread inside each articulation, the shape stays: `vel S lanes=42 v=100-127 scale=0.5 add=56`, then `vel S lanes=42 v=1-99 scale=0.5 add=42`. That moves notes by 7 at most: when it is the only step with room, say that the hat was tight already. No `time=`. Notes off the grid: delete and rewrite (section 7) | `delete S lanes=38 v=1-59` (fill and build bars left out), reported. No flams. Backbeats only when their `sd` is over 6: `vel S lanes=38 v=100-127 scale=0.5 add=61` | crashes stay only on section starts and landings: blank the others in bar blocks, reported | kick `sd` over 5: `vel S lanes=kick scale=0.5 add=58`. Fills: none |
| punchier | second lever, and never the tips down (EP 3). A flat hat: only the carrying beats rise, `accent S lanes=42 grid=16 pattern=8---8-------8---`, then `vel S lanes=42 v=105-127 add=4`, the beat before a fill left out. A shaped hat: no room | first lever. Room (backbeat avg under 118): `vel S lanes=38 v=100-127 add=8 max=127`, fill bars left out. At the ceiling: skip and say so, the next levers are weight and air (section 3) | the section start crash, on a kick cell, up to the top when it is lower: `vel bars=1 beats=1-1.25 lanes=crash* set=127`. Landings inside the section stay 10 under it | room (kick avg under 114): `vel S lanes=kick add=6 max=124`. A fill under its rank: fills.md section 10 |
| more energy | one rung up the keeper ladder from bar 1 of the section: grooves.md section 3, the crash rung is the script of section 5. The new row takes its shape from sections 4 to 6 | next: a 2 beat or 1 bar build into the section (fills.md section 10) | next: one crash at 118 on the phrase start of bar 5 where the kick plays (bar block, the hat cell under it blanked) | none. Fills: fills.md |
| more driving | steady and forward. A flat hat: the beats up into a pulse, the "and"s stay, `accent S lanes=42 grid=16 pattern=8---`. A shaped hat: the tips up toward a wall of eighths, `vel S lanes=42 v=1-99 scale=0.3 add=69` (84 becomes 94). Keeper on quarters under about 190 bpm: the "and"s back in is a rate change, offer it. Mid phrase openings closed (the two lines of "tighter") | with the hat: the push of section 7, `shift S lanes=38 v=60-127 ticks=-7` | never shifted | never shifted. Kick on every beat only where the riff has an onset on every beat |
| softer | instrument first [12]: openings closed and the whole hat on the tip, on purpose: `remap S lanes=46 to=hh`, `vel S lanes=42 scale=0.8 max=96` (116 becomes 93, 84 becomes 67, the shape stays). A ridden crash: one rung down, back to the hat (grooves.md section 3) | verse, cross stick when `# lanes` has a `rim` or he asks: `remap S lanes=38 v=100-127 to=rim`, `vel S lanes=rim scale=0.82`, in a fill bar only its backbeat beat. Chorus: `vel S lanes=38 v=100-127 add=-10` | crashes inside the phrase deleted, reported. `vel S lanes=cym,ride scale=0.9`, the ranks stay | `vel S lanes=kick add=-10 min=100`. Fills: `vel F lanes=snare,tom scale=0.9`, one line per fill |
| more dynamic | a wider range over time, the average stays. A flat keeper: the default answer below. A shaped one: what it lacks of section 6, in this order: the lift into the phrase ending fill, the growth of the later phrase, openings 14 apart. Between sections: verse tips down a digit (`vel <verse bars> lanes=42 v=1-99 add=-14`), chorus one rung up | a flat build rises (section 8). A sudden accent followed by a crescendo is a Barker device [14] | crash accents by rank (section 6). The ridden crash under its starts (section 5) | fills: fills.md section 6, each by its rank. Kick: none |
| more aggressive | one rung up, to the sloshy hat (grooves.md section 3). Breakdown (feel `half`): keeper to china quarters only when `# lanes` has a china or he asks, else crash quarters | room: `vel S lanes=38 v=100-127 add=6 max=127`, fill bars left out. At the ceiling: skip and say so. Next: a power flam on the last backbeat before each fill, then the push (section 7) | a second cymbal (`china`, else `crash2`) stacked on `crash1` on the section start only: grooves.md section 3, both hands, so no hand note on that cell or one sixteenth before it (EP 15) | room: `vel S lanes=kick add=6 max=126`. Fills: fills.md |
| bouncier | offbeat lift: openings on kick "and"s as lever 2 (section 5), two per phrase from the first phrase on, at 104 and 118. Or the upbeat accent of section 4. Selective open hits for bounce [23]. At 190 bpm and up: half open quarters [21] | under about 160 bpm: ghosts on cells 7 and 15, digit 3 (bar block), reported. Above: none | none | kick on the "and"s (cells 6, 10, 14) only where `# riff` has an x [21][23]. No `shift` anywhere |

"Make the hi hat more alive". Scope (vocabulary.md section 1): with no section named, the bars where `hh` keeps time. Sections kept by a crash or the ride are left alone and named in the report. Only when he names a section whose keeper is not a hat, or the song has no hat at all, does "the hat" mean the keeper cymbal (section 5). Default answer, one script: lever 1 (levels and leans), lever 2 (openings), lever 3 (growth, handover, lift), with `humanize vel=2` as the finish. Not part of it: kick, backbeat, fill notes, a landing crash for a fill that has none, hats deleted under a crash or inside a fill, the foot under fills, timing.

The example below is one file: a verse on closed eighth hats flat at 98, crash1 + kick on beat 1 of bars 1 and 5, one fill. Its four lists are the first comments of the script.
```vd
# said back: the hat keeps its eighths. beat 1 and the snare beats carry the bar, the plain "and"s come down, it leans where the kick lands (more in the second phrase), opens on two kick hits and climbs into the bar 8 fill. kick, snare and the fill untouched
# 1 keeper: closed hat 42 on every eighth, flat at 98. no hat on beat 1 of bars 1 and 5 (crash) and in bar 8 beats 3-4 (fill)
# 2 carrying beats: feel normal, so beats 1, 2 and 4
# 3 kick under an "and": bars 1 3 5 7  kick 9--- ---- 9-9- ----  cell 10
#                        bars 2 4 6    kick 9--- --9- 9--- --9-  cells 6 and 14
#                        bar 8         kick 9--- --9- ---- ----  cell 6
# 4 phrases: bars 1-4 and 5-8, both start on a crash. fill: 8:3-5, 2 beats, ends the section, first note 112, so H = 112
# notes, lever 2. first phrase: the last bar with a hat and a kick on cell 14 is bar 4. the next hat cell is the bar 5 crash, so the foot closes it. second phrase: its start has a crash. bar 6: cell 14 was opened before, so cell 6, closed by the hat on beat 3
remap bars=4 beats=4.5-4.75 lanes=42 to=hh_open
bar 5 grid=16
hh_pedal 44 |6--- ---- ---- ----|
remap bars=6 beats=2.5-2.75 lanes=42 to=hh_open
# level, lever 1: carrying beats 116, beat 3 102, tips 84. then the finish
accent bars=1-8 lanes=42 grid=16 pattern=8-6-8-6-7-6-8-6-
vel bars=1-8 lanes=42 v=91-127 add=4
humanize bars=1-8 lanes=42 vel=2 seed=3
# leans, phrase 1, one per bar, no cell twice: bar 1 cell 10, bar 2 cell 6. bar 3 has only cell 10 again and stays plain. bar 4: cell 6 is used and cell 14 is its opening, plain
vel bars=1 beats=3.5-3.75 lanes=42 add=24
vel bars=2 beats=2.5-2.75 lanes=42 add=24
# phrase 2, every kick "and": bars 5 and 7 cell 10, bar 6 cell 14 (cell 6 is its opening). bar 8 cell 6 is inside the lift
vel bars=5,7 beats=3.5-3.75 lanes=42 add=24
vel bars=6 beats=4.5-4.75 lanes=42 add=24
# openings by phrase: 104, then 118
vel bars=4 lanes=46 set=104
vel bars=6 lanes=46 set=118
# lever 3. no handover line: the only fill is the one the lift runs into. lift: the three hats before the bar 8 fill climb 88, 100, 112
ramp bars=8 beats=1.5-3 lanes=42 from=88 to=112
```
Another file gives other cells, other bars, another H, maybe no opening at all. Do not carry a line of this script over: write the four lists for his section, decide each lever from them, and put the lists in your script as comments. Every `beats=` window and every `bars=` group above exists only because of this example's kick row, crashes and fill. What other files bring:

- A pickup fill inside the phrase (1 beat): no lift into it, a handover line for the beat before it, and the cells it covers are not available for a bark or a lean.
- A phrase start with a hat and a kick on beat 1 and no crash: it takes an opening at 120. If a fill lands there, name the missing crash in the report.
- No crash after an opening: the `hh_pedal` row is not needed, the next closed hat cuts it.
- Feel `half`: base `pattern=8-6-7-6-`. Quarter, sloshy, ride or crash keeper: its row in section 5. Notation B: 4 bars hold the 8 bar phrase, base `pattern=86867686`, every position converted with section 1.

Asked again ("more"), one per request: (1) one more opening per phrase on a kick "and" that has none yet. (2) Timing, `humanize S lanes=42,46 time=4` (3 ms): the velocities stay, `diff` shows the notes as moved in time, and it is felt more than heard: say so.

Check before reporting, with the numbers of `vibedrum diff ORIGINAL RESULT` and `show RESULT --vel --bars S` (the acceptance tests of the principles, read for this request):

- Scope: `# bars changed` holds the hat section only, `# lanes` lists `hh`, `hh_open` and, when a foot note was written, `hh_pedal`. 0 notes moved in time.
- Direction: the section's `vel` is within 3 of before (a hat that was flat above 105: lower, and said. A sloshy, ride or crash keeper with headroom: up to 5 higher, its weak notes stay). The notes under `quieter` are the plain "and"s, the handover and the start of the lift, nothing else.
- Audible: carrying beats 114-118, other beats 100-104, tips 82-86, every lean 20 or more over the tips, openings 14 or more apart between phrases, the lift rises 20 or more.
- Not a loop: the loop test of section 6 over every bar of the section.
- Neighbours: in the beat before each fill no hat is over H, the lift ends on H, every opening has a kick under it and is closed on the next hat cell.
- Fills: every `# fills` line reads before = after. A fill with no landing is named, not fixed here.
- Report, two or three lines: what the hat does now with bars and levels, what came down (the plain "and"s, from what to what), the note count (a `remap` is a hat that became an opening, a foot note is a note added), then what he should know: fills weaker than the hat, a section kept by another cymbal. No word the numbers do not show.

## 10. Sources
1. https://www.drumeo.com/beat/a-drummers-guide-to-punk/ (pop punk examples at 180, 189 and 200 bpm, punk beat counted with the snare on every upbeat, every backbeat an accent or rimshot, sloshy open hats, kick follows bass and guitar)
2. https://www.toontrack.com/blog/how-to-program-drums/ (edge on the beats and tip on the "and"s, a hierarchy of hits, kick 100-115 and 75-95, backbeat 100-120 with rimshots near maximum, ghosts 20-45)
3. https://urm.academy/5-drum-programming-tips-for-maximum-realism/ (110-120 over 127, weak hand 5-25 lower, never three hand hits at once, timing humanise 2-5 percent)
4. https://www.soundonsound.com/techniques/making-midi-sequencing-more-realistic-part-2-drum-parts (flam 6-30 ms early and slightly quieter, kick quantized while hat and snare float, snare early drives, rolls rise to about 120)
5. https://www.soundonsound.com/techniques/programming-realistic-drum-parts (every other hit lower for alternate hands, no hats in a tom fill)
6. https://www.production-expert.com/production-expert-1/6-killer-hi-hat-programmingnbsptipsnbspfor-musicnbspproducers (offbeat hats quieter, two handed sixteenths skip the snare cell, choke group, pedal hat under a ride and in fills, new hat sound every 1, 2 or 4 bars)
7. https://drummagazine.com/lesson-how-to-get-that-tasty-16th-note-hi-hat-feel/ (tip on top, shoulder for accents, downbeat and upbeat accent placements, pedal pressure)
8. https://rhythmnotes.net/cymbal-sounds/ (riding a crash: the shoulder of the stick on the edge gives the louder wash, the tip on the bow is quieter and washy)
9. https://www.confidentdrummer.com/playing-ahead-or-behind-the-beat-full-course-part-1-theory/ (5 and 10 ms, 20 ms is the edge, ahead means urgency, overdone means anxiety, move one limb)
10. https://www.researchgate.net/publication/237423294_Music_on_the_timing_grid_The_influence_of_microtiming_on_the_perceived_groove_quality_of_a_simple_drum_pattern_performance (rock pattern at 120 bpm, kick or snare displaced by 15 or 25 ms early or late: quantized rated best, larger displacements lower. Search excerpt only, page fetch failed)
11. https://journals.plos.org/plosone/article?id=10.1371/journal.pone.0127902 (one handed sixteenth hats at 96 bpm on a 1982 record: 8.7 ms sd, against 15.6 ms for a drummer with a metronome at 180 bpm in a lab study. Loudness high low medium low, very high low medium low, the peaks where the snare lands)
12. https://drumheadauthority.com/articles/travis-barker/ (dynamics through instrument choice, always loud and fast, open hats, splashes, crashes and ride bell inside grooves, accents in single stroke runs)
13. https://drumheadauthority.com/articles/tre-cool/ (hats in verses, ride or bell in choruses, crashes mark chord changes)
14. https://drummercafe.com/education/articles/travis-barker-low-remix.html (hat partially open in choruses, power flams, sudden accents then crescendos, kick notes added over 4 to 8 bar phrases)
15. https://www.drumeo.com/beat/travis-barker-drum-beats/ (Down at 94 bpm with accented sixteenth hats and ghosts, Stockholm Syndrome at 174 with flams, Tiny Voices at 154 with foot hat eighths under an offbeat ride)
16. https://www.drumstheword.com/first-date-drum-fill-drum-lesson-travis-barker-blink-182/ (crash on beat 1, open hat on the other three downbeats)
17. https://www.nailthemix.com/state-champs-secrets-kyle-black-mix (kick 90 percent live and 10 percent sample, snare sample for body)
18. https://www.nailthemix.com/mixing-a-day-to-remember-andrew-wades-production-arrangement-tricks (hands only tracking with programmed kicks, snare hit hard and consistently, short tight toms)
19. https://www.nailthemix.com/toontrack-pop-punk-ezx (highest velocities for the backbeats, lower for ghosts, fills and fast passages, quantize 90-95 percent)
20. https://www.toontrack.com/product/pop-punk-midi/ (pack tempos 116-204 bpm)
21. https://drumhelper.com/learning-drums/punk-drum-beats-and-rhythms/ (punk beat written with the snare on the "and"s, hats played loud, open hats not too wide, open quarter hats for an aggressive sound, crash on all quarters, stamina)
22. https://en.wikipedia.org/wiki/Half-time_(music) (double time: the snare moves to the "and"s. half time: snare on 3)
23. https://www.guiltystateofmind.com/home/blog/may-2022/may-24-31/525-favorite-pop-punk-drums (The Story So Far: selective open hats for bounce, kick with the guitar under quarter note crash)
24. https://www.musicradar.com/news/drums/rian-dawsons-6-tips-for-pop-punk-perfection-638229 (180 to 200 bpm, one bar fills quick and tight, no long ghost noted fills, click. Search excerpt only, page fetch truncated)
25. https://www.moderndrummer.com/article/september-2012-travis-barker/ (conditioning so he does not run out of steam)
26. https://www.drummerworld.com/forums/index.php?threads/tips-for-punk-speed-hi-hat.84118/ (quarters on the hat instead of eighths at punk speed, more power. Search excerpt only, page fetch failed)
27. https://www.drumchat.com/showthread.php/2075-Notes-On-The-Hi-Hat (beats with the shoulder on the edge, "and"s with the tip on top, accents read as quarter notes. Search excerpt only, page fetch failed)
28. https://bangthedrumschool.com/open-hi-hat-beginners/ (strike when it opens, the foot makes the closing sound alone)
29. https://drumbeatsonline.com/blog/how-to-play-hi-hat-techniques-every-drummer-needs-to-know (open on the "and" of 4, close on beat 1)
30. https://drumbeatsonline.com/blog/rock-drum-beats-essential-patterns-every-drummer-should-know (verse lighter hat and softer snare, chorus crash, fuller stroke or ride, four on the floor tiring at fast tempos)
31. https://en.wikipedia.org/wiki/Breakdown_(music) (breakdown: quarters on crash or china, snare on beat 3, kick with the guitar chugs)
32. https://www.melodigging.com/genre/easycore (160-200 bpm, half time breakdowns, edited tightness)
33. https://melodics.com/learn-to-play/misery-business-by-paramore-on-drums (173 bpm, bridge with eighths on the hat and the other hand filling the sixteenths. Search excerpt only)
