# Dynamics and feel: velocity, articulation, micro timing

Scope: djent and progressive metalcore drum parts. Units: velocity 1-127, grid cells, beats (quarter notes), ticks at 480 ppq. Cell numbers are grid=16 indexes 0-15 as in grooves.md: beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12. An "and" is cell 2, 6, 10 or 14. A grid digit d is velocity d*14 (9 = 127), and `accent` writes the same digits. `[n]` = source in section 11. "unconfirmed" = working default, no source found. "Principle N" = rule N of knowledge/editing-principles.md. Every recipe here obeys it, and where a line seems to differ the principle wins.

Selectors: closed hat `lanes=42`, open hat `lanes=46`, foot `lanes=44`. `lanes=hat` selects all three at once, so a level or a spread meant for the stick hat also lands on the opening and the foot: name the pitch (principle 19). Ghosts `lanes=38 v=1-62`, backbeats `lanes=38 v=100-127`. Inside fill spans soft snare notes are fill notes, not ghosts: keep fill bars out of ghost ops. Give every op a `lanes=` part: without one it hits every drum note. `accent`, `vel` and `ramp` only change notes that exist, and an op that matches nothing is silent. The `~` count of `apply` does not prove that an op hit: `vibedrum diff` and `show --vel` do.

Order inside one script (principle 16):

1. Notes: bar blocks, `copy`, `remap`, `delete`. A bar block that edits a bar a `copy` writes into goes after that `copy`.
2. Level: the base `accent` over the whole part and the `vel` steps that set its levels.
3. `humanize`: a finish, one `vel=` run per lane per section, any `seed=`. It is never what makes two bars differ. To redo it, apply the new script to the version before.
4. Designed gestures, after `humanize` so the spread cannot blur them: `vel add=` or `set=` on single cells, `ramp`, `max=` caps and wall clamps on one pitch.
5. `shift` last: a note shifted more than 20 ticks early leaves its cell and `beats=` windows stop finding it.

Sizes (principle 17): an accent meant to be heard is 15 to 25 over the notes around it. One digit (14) is the smallest step used here, 10 is the floor for a subtle variation, under 7 is the same sample. `humanize vel=` stays at or under a third of the smallest designed difference: 2 on a hat built in steps of 14. `ramp from= to=` writes absolute values and erases the accent shape, `ramp scale=A-B` keeps it (principle 18). A digit is a band 14 wide, so a digit that changes at a band edge (90 against 91) is not a gesture: read levels with `show FILE --vel --bars A-B`, and what the edit did with `vibedrum diff ORIGINAL RESULT` (it also counts the notes moved in time).

Direction (principle 3). Words that ask for more (punchier, more aggressive, harder, heavier): no note in scope ends quieter. Words that ask for less (softer, smoother): none ends louder. Alive, dynamic, less robotic, more human, tighter and groovier are not loudness words: strong notes rise, weak ones may fall, the section's `vel` in the `# sections` lines of the diff stays within 3, and the report says what came down.

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
| hh 42 | carrying beat: beat 1 and the backbeat cell | 114-118 | 8 | lane total 10-20 | hierarchy [5], shoulder on the beat [10][11], level unconfirmed |
| hh 42 | plain beat | 100-104 | 7 | | [1][5], level unconfirmed |
| hh 42 | lean: an "and" with a kick under it | 106-110, 24 over the tips | 8 | | unconfirmed |
| hh 42 | tip on a plain "and" | 82-86 as written here, anything in 60-99 is a tip | 6 | | [1][15] |
| hh 42 | "e" and "a" of sixteenths | 70-84 | 5-6 | | [13], numbers unconfirmed |
| hh_open 46 | sloshy keeper on quarters or eighths | 95-115, a phrase start up to 126 | 7-9 | 5-9 | usage [18], numbers unconfirmed |
| hh_open 46 | single opening | 100-120, 14 or more between phrases (section 5) | 7-9 | | unconfirmed |
| hh_pedal 44 | foot chick | 42-70 as a metronome under a ride, china or crash keeper, 70-85 when it has to close an open hat | 3-6 | 3-6 | usage [9][11][17][20], numbers unconfirmed |
| ride 51 | bow | 78-112 as the keeper of a heavy section (a phrase start up to 120), 70-84 in clean passages | 5-8 | 8-14 | unconfirmed |
| ride_bell 53 | bell | 100-122 | 7-9 | 4-8 | unconfirmed |
| crash1 49, crash2 57 | section start | 119-127 | 9 | | bands unconfirmed |
| crash1 49, crash2 57 | landing inside a section, accent with the riff | 105-113, one digit under the start of its section (principles 6 and 23) | 8 | 4-8 | under 127 per [6], bands unconfirmed |
| crash1 49 | crash keeper on quarters or eighths | 95-120 | 7-8 | 6-10 | unconfirmed |
| china 52 | quarter note keeper | 104-124, phrase starts up to 127 | 8-9 | 4-8 | unconfirmed |
| splash 55 | short accent | 90-112 | 7-8 | | unconfirmed |
| tom1 to tom6 | fill notes | 85-127, shape and rank in fills.md section 5 | 6-9 | 6-12 | weak hand lower [6], band unconfirmed |

How this style differs from rock, funk and pop programming:

- Kick and backbeat are sample reinforced on the records: Haake describes the album drum sound as close mics mixed with close mic samples and the room [18], he rimshots every snare and does not call Meshuggah a dynamic band [17], and Garstka says bass drums give no dynamics [21]. Kick and backbeat therefore live in digits 8-9 with sd under 5. That is correct, do not "fix" it.
- One single value is still wrong: an identical velocity fires one sample over and over [22][23]. Guides alternate backbeats inside 120-127 [3], or keep normal backbeats at 115-120 and save 125-127 for blasts that must cut [2]. 110-120 is closer to a real hard hit than 127 in most libraries [6].
- General guides put primary kicks at 100-115, secondary kicks at 75-95 and backbeats at 100-120 [5]. Too soft for this style: do not apply that to kicks that double the riff (unconfirmed, follows from [17][21]).
- The dynamic range lives in four places: hats and ride (30 or more between a tip and a carrying beat), ghosts (25-50 under a 116+ backbeat), tom fills (fills.md), cymbal choice and crash velocity. So a feel request edits hats, cymbals and ghosts first. Kick or backbeat velocity changes only for "tighter", "punchier", "more aggressive", "softer".
- Ceiling (principle 4): a lane with min = max = 127 cannot be raised. `vel min=` and `set=127` do nothing there, and "louder" is not a true report. For a "more" word the levers are then weight, air and other lanes with headroom (song-structure.md section 10, fills.md section 9), never a trim of the lane itself. Lowering weak positions by 15 to 25 belongs to the words that are not about loudness (alive, less robotic), and it never touches the hits themselves.

## 2. Machine gun: reading it and curing it

Header line `# lanes: pitch lane count vel min/avg/max sd`. Machine gun = sd under 3, or min = max, or every cell of the lane in the section shows one digit (the header is song wide: for one section read `show --vel --bars`). The snare lane mixes two bands: sd under 6 means no ghosts exist, sd 30+ built from only two digits means each band is still a machine gun. sd finds a flat lane. It is not the test of a cure: `humanize` on a one beat pattern reaches any sd and is still a one beat loop, and `humanize vel=N` alone adds an sd of only about 0.6 N. A cure is a shape read from the grid, then a small spread, then the loop test of section 6. A flat lane outside the request is not cured: one line in the report. The cures that lower notes (kick run, blast, quarter keeper) answer "less robotic", "more human" and "alive", never a "more" word. Add `bars=` to every op.

| lane | verdict at sd under 3 | cure |
|---|---|---|
| kick on riff | correct | none. If asked for less robotic: `humanize lanes=kick vel=3`, never `time=` |
| kick run at grid=32 | fix | strong foot, weak foot, on the beats of the run only (here beat 4): `accent beats=4-5 lanes=kick grid=32 pattern=87` (112 and 98, the numbers of grooves.md section 6), then the first note back up: `vel beats=4-4.125 lanes=kick set=127`. Run that starts on an odd cell: `pattern=78`. Kicks outside the run keep their level |
| backbeat | nearly correct | `humanize lanes=38 v=100-127 vel=3`, then the wall `vel lanes=38 v=100-127 min=116` |
| blast snare on eighths | fix | `accent lanes=38 v=90-127 grid=16 pattern=8-7- mix=0.8` (115 and 104 from a flat 127 [3][23]), `humanize lanes=38 v=90-127 vel=4`. Blast that has to cut: `pattern=9-8-` (127 and 115 [2][4]). Snares on the odd cells: `-8-7`. Blast written at grid=32: same patterns with `grid=32` |
| ghosts | fix | pairs first, in bar blocks: digit 2 then digit 3 (28, 42). Then `humanize lanes=38 v=1-62 vel=5` and the wall `vel lanes=38 v=1-62 min=25 max=58` (section 9) |
| hh or ride keeper in eighths or sixteenths | fix, this is the main case | sections 3, 5 and 6: levels and leans read from the grid, openings on kick hits, motion over the phrase. Worked in section 10 |
| quarter keeper: open hat, china, crash | fix. Flat at 127 it is the ceiling case | section 4 |
| toms and snare in fills | fix, but not from this document | fills.md sections 5 and 9: one fill at a time, graded by rank, the last note on top (principles 5 and 9). No fill op lives here |

## 3. Keeper shape: read the grid, then write

Mechanics: an accent is the shoulder of the stick on the edge, a non accent is the tip on top of the hat, and easing the pedal a little makes the accent bigger [10][11]. Samplers ship these as edge and tip articulations [12]. The built in map has one closed pitch (42), so shoulder against tip is velocity only: 100 and up reads as shoulder, 99 and down as tip (working line, unconfirmed). That line is a wall (principle 13): a note is written on one side of it on purpose, and no scale or spread may carry it across. So designed levels sit 2 or more away from it and the spread is 2. Every hat part needs a hierarchy of hits [5], and offbeat hits sit below on beat hits [1][5][9]. The levels below are working numbers (unconfirmed).

One row tiled over a section (`8-6-` on every beat) plus `humanize` is the "accent pattern plus randomizer" sound: a one beat loop however large its sd. A fixed cell lifted in odd and even bars is the same loop two bars long. So nothing here is a pattern to paste: the cells come from the file. Read `show FILE --vel --bars S` and write four lists. They go into the script as its first comments (principle 20):

1. Keeper: lane, rate (which cells hold a note), level now, and the cells with no keeper note (a crash on beat 1, a fill).
2. Carrying beats: beat 1 and the backbeat cell. Feel `half`: beats 1 and 3. Feel `normal`: beat 1 and the backbeats on 2 and 4. No snare (`open`): beats 1 and 3 (unconfirmed).
3. Kick "and"s: for each bar, the "and" cells where a kick sits under a keeper note. Bars with the same kick row form a group. This needs no riff track: the kick row is read, never moved. With a `# riff` row, a kick "and" that also has a riff x wins a tie between two cells.
4. Phrases and fills. A phrase starts at the section start, at a crash on cell 0 and after a fill, else every 4 bars. For each fill: bar, first beat, length, whether it ends a phrase or the section, and H = the velocity of its first note.

Lever 1: levels and leans. Eighth note closed hat, feel `half`:

| hit | level | op |
|---|---|---|
| carrying beat | 116 | `accent S lanes=42 grid=16 pattern=8-6-7-6-`, then `vel S lanes=42 v=91-127 add=4` (112 and 98 become 116 and 102). Feel `normal`: `pattern=8-6-8-6-7-6-8-6-` |
| plain beat | 102 | the same two lines |
| tip, a plain "and" | 84 | the same `accent` |
| lean, an "and" with a kick under it | 108, 24 over the tips | after `humanize`: `vel bars=<group> beats=<that cell> lanes=42 add=24` |

- Which kick "and"s lean. All of them in every bar is a formula too: it prints the kick's loop onto the hat. First phrase: one lean per bar, on the kick "and" nearest the backbeat (two equally near: the one before it). Two bars of the phrase that share a kick row take different kick "and"s. Later phrases: every kick "and", three per bar at most. A cell inside a fill, in the beat before a fill (section 6) or taken by an opening (section 5) is not available. A bar with no kick "and" gets no lean: do not invent one.
- On beat hats do not lean, they are shoulders already. Closed hats stop at 118: 127 on a closed hat fires the hardest sample and competes with the snare.
- A hat that was flat between 90 and 105 keeps its average: carrying beats and leans rise, the plain "and"s fall about 14. Say that they came down. Flat above 105 the part comes down on average, sixteenths come down about 8: say so.
- A part that already shows two or more levels per beat: skip the `accent`, keep his shape, add the leans it lacks (`add=` 15 to 24) and levers 2 and 3.
- The finish goes between the level lines and the leans: `humanize S lanes=42 vel=2`. Then lever 2 (section 5) and lever 3 (section 6). The default answer to "alive" is all three in one script (section 10).

## 4. Other keepers: sixteenths, ride, quarter notes

The four lists and the three levers are the same. What changes:

| keeper | against the eighth note hat |
|---|---|
| sixteenth hats, two hands (above about 110 bpm, threshold unconfirmed, most djent tempos) | base `pattern=86667666` (feel `half`), then the same `add=4`: carrying beats 116, plain beats 102, everything between 84. Only kick "and"s lean: they are the right hand. "e" and "a" are the left hand, under the right hand's beats ([6][8] give 5-25) and never leaned. The right hand leaves for the backbeat, so the snare cell has no hat [9]: a file that has one there is shaped as it is, deleting it is a limb fix ("more human"). The lift takes the last six notes |
| sixteenth hats, one hand (the measured case is 96 bpm [13], most players top out near 100 [24]) | base `pattern=85657565`: "e" and "a" at 70, the high low medium low shape of [13]. The hat hand plays the snare cells too |
| ride bow 51 | the hat procedure on `lanes=51`, every level 6 lower (`vel S lanes=51 add=-6` after the level lines), no wall at 100. A ride has no opening: lever 2 is a bell hit on the same cells (`remap ... to=ride_bell`, 110-120) only when 53 already has notes in `# lanes` (principle 24). Else lever 2 has no room: say so |
| any keeper on quarters with headroom: open hat 46, ride, china or crash with max under 120 | four notes a bar: no tips, no "and"s, no openings, no lift. List 3 is read on the beats: the non carrying beats with a kick under them. (1) Hierarchy: `accent S lanes=L grid=16 pattern=8---7---` (feel `half`), then `vel ... add=` lines on `v=105-127` and `v=91-104` that put the carrying beats at the top of the lane's band and the other beats 16 under it (open hat 114 and 98, ride 108 and 92, china 120 and 104). (2) Finish: `humanize S lanes=L vel=2`. (3) Growth: the first phrase stays plain. In the later phrases each non carrying beat with a kick under it comes up 16, to the carrying level. (4) Start: a phrase start with no crash, `set=126` on the hat, `set=127` on china, `set=120` on a ride. (5) Into a fill: the last keeper hit before a fill of 2 beats or more comes up to the carrying level, H at most (section 6). Before a 1 beat pickup, or when H is under the plain level: only the handover of section 6. Worked below |
| quarter china or crash at the ceiling (flat 127) | nothing can be raised, so the same shape is cut from the top. Carrying beats, phrase starts and the last hit before a fill keep their 127. First phrase: the other beats `add=-16`. Later phrases: only the other beats with no kick under them. Then `humanize S lanes=52 vel=2`. Only for alive and less robotic. For harder, heavier or bigger the china is not touched (principle 4) |

- Both sixteenth kinds: no hats during a tom fill, the hands are busy [8]. At most two hand lanes sound on one cell [6].
- A quarter keeper is an anchor: the cymbal hand plays straight while the kick follows the guitar [18][20]. With four notes a bar, bars inside a phrase may be alike. Its phrases differ: the start, and the beats the kick brings up. No kick under any non carrying beat: only the starts differ. Say so, do not invent a lean.

```vd
# input: open hat 46 on quarters, flat at 100, bars 1-8, feel half. crash on bar 1 beat 1, phrases 1-4 and 5-8
# fills: 4:4-5, a 1 beat pickup, first note 98. 8:3-5, 2 beats, first note 112
# kick under a non carrying beat: beat 2 in bars 1 3 5 7, beat 4 in bars 2 and 6. another file gives other beats
# hierarchy: beats 1 and 3 at 114, beats 2 and 4 at 98
accent bars=1-8 lanes=46 grid=16 pattern=8---7---
vel bars=1-8 lanes=46 v=105-127 add=2
humanize bars=1-8 lanes=46 vel=2 seed=4
# growth, bars 5-8 only: the beats with a kick under them come up to the carrying level
vel bars=5,7 beats=2-2.25 lanes=46 add=16
vel bars=6 beats=4-4.25 lanes=46 add=16
# start: bar 5 has no crash
vel bars=5 beats=1-1.25 lanes=46 set=126
# into the fills: bar 8 beat 2 is the last hit before a 2 beat fill, H = 112. bar 4 beat 3 stands before a pickup, H = 98
vel bars=8 beats=2-2.25 lanes=46 set=112
vel bars=4 beats=3-4 lanes=46 max=98
```

## 5. Open hat, pedal hat, mixing articulations

- Lever 2, openings. An opening is a closed hat `remap`ped to `hh_open` on a cell where a kick sits under it and the next hat cell holds `hh` 42. Read both in the grid. Open and closed hats share a choke group [9]: without that next closed note the opening rings on. Never open a plain tip with nothing under it.
- Where. First phrase: one, in its second bar (the third if the second has no such cell), on the last kick "and" of the bar. Later phrases: the phrase start, when its beat 1 holds a hat and a kick and no crash, plus one in the second bar on a kick "and" the phrase before did not use. Two per phrase at most in the default answer. No two phrases open the same cell.
- Level: the note keeps its closed velocity, so set it after the `remap`, per bar: `vel bars=N lanes=46 set=`. First phrase 104, later phrases 118, a phrase start 120: 14 or more between phrases. An open hat rings longer than a closed one, so the first one needs no more than a lean (unconfirmed per sampler).
- No candidate cell (no kick "and" before a closed hat, or every one inside a fill): lever 2 has no room. Say so, do not force it.
- The next hat cell holds a crash (hand busy): write `hh_pedal` at 70-85 there to close the opening, and report the added note.
- Sloshy keeper: quarter notes on `hh_open` at 95-115 with the snare on 3 (feel `half`) is a documented Haake pattern [18]. The map has no half open pitch. `hh_open` at 85-100 is the stand in (unconfirmed per sampler).
- Pedal hat under a ride, china or crash keeper: chick on 2 and 4 or on all four quarters [11], or eighths [20], at 42-70. Haake keeps the hat foot going whenever he is not on both bass drums [17]. Never on a cell where a stick plays `hh` 42. Only where the left foot is free: no `hh_pedal` in a beat with a kick run at grid=32 or 24, or with kicks on adjacent sixteenth cells above about 130 bpm (threshold unconfirmed). It adds notes: only when he asks for the foot.
- Pedal hat under a fill [9]: masked by the hands, and it adds notes inside the fill span. Not part of "alive" or any other feel word.
- Crash or china on a cell: the closed hat on that cell goes (one handed eighths: the hat hand plays the cymbal). In a feel request that is a limb fix: report it.

## 6. Motion over the phrase: growth, handover, lift, loop test

Lever 3. A part is alive when it moves over the phrase: a start, a middle, an end (principle 12).

- Start. The first phrase start is the section's entrance and stays as he wrote it. A later phrase start under a crash is marked already. One with no crash takes the opening of section 5. If it has no hat or no kick on beat 1, it keeps the carrying level and nothing more.
- Growth. The later phrase answers the first with more: every kick "and" leans (section 3), its openings are 14 higher and on other cells (section 5), and it holds the lift. One phrase only (4 bars): bars 1-2 follow the first phrase rules, bars 3-4 the later ones. Three or more phrases: grow in steps (one lean, every lean, every lean and a second opening), never two phrases alike.
- Handover (principle 14). H = the velocity of the fill's first note, 118 at most. In the beat before a fill no keeper note is over H: `vel bars=N beats=B lanes=42 max=H`. A hat that ends over the fill makes the fill smaller. A keeper that was over the fill before the edit (a china at 127 into a fill at 98) is his mix: leave it and name it.
- Lift: into the fill that ends a phrase or the section and is 2 beats or longer. Not into a 1 beat pickup: the smaller fill gets the smaller approach, the handover alone (principle 5). The last three keeper notes before the fill climb in even steps to H: `ramp bars=N beats=A-B lanes=42 from=H-24 to=H`, the last line of the script. Absolute values on purpose: the strokes even out and climb, a lean inside the window is replaced. Beat 1 of the bar stays out of the window, it carries the bar. Fewer than three keeper notes between beat 1 and the fill: no lift. A fill that starts on beat 1: the window is the last three keeper notes of the bar before (`beats=3.5-5` on eighths).
- Weak fills (H under 100) keep the lift low. Never raise fill notes in a hat request. Say it in the report: with heavier fills the hat can climb higher.
- Loop test (principle 12, the "not a loop" acceptance test), on `show RESULT --vel --bars S`. Write down the keeper row of each bar. Two rows differ when one cell differs by 13 or more, by an opening, or by a missing note. No two neighbouring bars may have the same row, the section may not read A B A B, and two phrases may not match bar for bar. A quarter keeper is tested by phrase: bars inside a phrase may be alike, two phrases may not. Differences that `humanize` made do not count: after any spread no `# bar N = bar M` line prints, so a missing fold proves nothing, and neither does sd. Before an edit: 3 equal rows in a row are a loop.
- The loop test belongs to the words that ask for life: alive, dynamic, less robotic, more human, groovier. After a level word (punchier, softer, tighter, smoother) a part that looped before still loops: one line in the report, not a reason to add gestures he did not ask for (principle 7).
- In a polymeter section the kick differs in every bar while the keeper still loops: read the keeper row. Never vary a riff locked kick to break a loop.
- After a fill: the landing (crash and kick on beat 1) belongs to fills.md. A fill with no crash after it is still a fill: a hat or feel request leaves it alone and names it in the report (principle 23). A fill in the last bar of the song has no landing bar (principle 22). After a crash the hat comes back on the "and".

## 7. Cymbal choice, stacking, alternating crashes

- Which cymbal keeps time, and moving it one rung ("heavier", "more aggressive", "softer"): grooves.md section 4 holds the ladder and its script. A keeper change is a note edit of a whole section: only when the request names that section, and never bring a section's keeper cymbal in before that section starts (principle 6). That script shapes the new row itself: no second pass with section 3 or 4. The cymbal hand and the snare stay on a straight 4/4 pulse while the kick follows the guitar cycle [18][20].
- Accent with the riff: put a crash or china accent only on a `# riff` onset, with a kick on the same cell. Haake plays his accents only together with the guitar hits [17]. No riff track: add no accents, and say so (principle 21).
- Stacked accent: `china` 52 plus `crash1` 49 on one cell uses both hands, so no snare, hat or tom on that cell [6]. It belongs to a section start. A landing inside a section gets one crash, and no landing is bigger than the start of its section or the first hit of the song (principle 6). Look one cell back (principle 15): hands that play a floor tom sixteenth right before a stack have to travel, so at fast tempos that last cell is left to the kick.
- Alternating: accent hits closer than a quarter note alternate strong hand and weak hand, the weak one 14-25 lower ([6] gives 5-25). The same cymbal twice at one velocity is a machine gun [22]. `crash2` only when it already has notes in `# lanes` (principle 24), else every second `crash1` hit 14 lower. Which side leads is unconfirmed.
- Crash velocity by rank: section start 119-127, a landing inside a section one digit under it, riff accents one digit lower again. Exactly 127 on one or two hits per 4 bar phrase at most (unconfirmed, follows from [6]). Crashes all at 127, for a word that is not about loudness: lower the inner ones per hit (`vel bars=N beats=B lanes=49 add=-14`), never one `max=` over the lane. For a "more" word leave them.
- A physical stack cymbal (Haake: 15 inch crash on a 19 inch china [17]) is not in the built in map. Stand in: `splash` 55, or `china` at 90-105 (unconfirmed).

## 8. Micro timing

ticks = ms * bpm * ppq / 60000. Compute it for the file's tempo (`# tempo:` in the header), the table is only a check. One cell at 480 ppq: grid=16 is 120 ticks, grid=32 is 60, grid=24 is 80, grid=48 is 40.

| bpm | ms per tick | sixteenth cell | 5 ms | 10 ms | 20 ms | 30 ms | 20 ticks, the `humanize time=` cap |
|---|---|---|---|---|---|---|---|
| 100 | 1.25 | 150 ms | 4 ticks | 8 | 16 | 24 | 25 ms |
| 130 | 0.96 | 115 ms | 5 ticks | 10 | 21 | 31 | 19 ms |
| 140 | 0.89 | 107 ms | 6 ticks | 11 | 22 | 34 | 18 ms |
| 180 | 0.69 | 83 ms | 7 ticks | 14 | 29 | 43 | 14 ms |

Anchors: an unquantized one handed hat part at 96 bpm has 8.7 ms sd on its sixteenth intervals [13]. Metal guides advise quantize strength 85-95 percent instead of 100 [2][3][4], or 2-5 percent timing humanisation [6]. One guide nudges notes about 20 ticks, ppq not stated [16]: read that as an upper bound. 5 and 10 ms are the useful push or drag amounts, 20 ms is the edge of sounding wrong, and against programmed parts stay at 5-10 [14]. `humanize time=N` is uniform: the intervals get an sd of about 0.8 N, and a spread under 5 ms is not heard as feel. Velocity spread of plus or minus 5-10 is the stated range [4], this pack stays lower because of principle 17. `humanize` never moves a note on a bar line in front of it. Timing is not printed by `show`: the diff counts the notes moved in time. The per lane split is a working default (unconfirmed).

| selector | `humanize vel=` | `time=` at 100 / 130 / 140 / 180 bpm | in ms |
|---|---|---|---|
| `lanes=kick` | 0-3 | 0 | 0 |
| `lanes=38 v=100-127` | 3 | 0-1 / 0-2 / 0-2 / 0-2 | 0-1.5 |
| `lanes=cym` on riff accents | 3 | 0-1 / 0-2 / 0-2 / 0-2 | 0-1.5 |
| `lanes=42,46` or `lanes=51` | 2 | 5-8 / 6-10 / 7-11 / 9-14 | 6-10 |
| `lanes=tom` in fills | fills.md section 5 | 2-4 / 3-5 / 3-6 / 4-7 | 3-5 |
| `lanes=38 v=1-62` | 5 | 3-6 / 4-8 / 5-9 / 6-11 | 4-8 |

- Stays on the grid: every kick where the section `lock` is 70% or more or the cell has a `# riff` x, every kick when the file has no riff track (principle 21), cymbal hits that share a cell with a riff accent. The backbeat gets no random timing beyond 2 ticks: a constant `shift` is a feel choice (below). A quantized kick is the foundation while hats and snare may float [7].
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
# 140 bpm. laid back backbeat in bars 1-4: 9 ticks is 8 ms late
shift bars=1-4 lanes=38 v=100-127 ticks=9
# pushed keeper in bars 5-8: stick hats 6 ticks (5 ms) early, beat 1 stays on its bar line. crash and china accents stay with the riff
shift bars=5-8 beats=1.25-5 lanes=42,46 ticks=-6
```

## 9. Ghost notes (needed by the recipes)

Velocity 25-50 [1][5][15], always under 60: `show` counts a snare hit of 60 or more as a backbeat when it labels the feel. That is a wall: after any spread or lift on ghosts, `vel lanes=38 v=1-62 min=25 max=58`. Singles or pairs only, never three in a row [5]. In a pair the second note is 14 over the first (28 then 42). One guide warns against the sixteenth directly before and directly after a backbeat [5], drum lessons do use the one before (grooves.md section 5): keep those where they exist, add new ones elsewhere first. Prefer cells with no kick: read the kick row of each bar, as for the leans. Backbeat on cells 4 and 12: good ghost cells are 7, 9, 15, then 1, 6, 10, 14. Backbeat on cell 8 (feel `half`): 3, 5, 11, 13, 15 (unconfirmed). Ghost notes are part of Haake's signature [19], but under china or crash riding they get lost: use 40-58 there or leave them out (unconfirmed). Adding ghosts adds notes: only when he names ghosts or the word asks for them ("groovier" asked again, "busier"), not the same cells in every bar, and the report says notes were added. Two or more ghosts added inside one beat in only a few bars can make a later `show` list that beat as a fill: check the grid before using `fills` again.

```vd
# one bar, feel normal: kick on cells 0 2 10 14, so the ghosts take the free cells 7 9 15. another bar has another kick row
bar 1 grid=16
#            1    2    3    4
snare 38   |---- 9--3 -2-- 9--3|
humanize bars=1 lanes=38 v=1-62 vel=5 time=5 seed=5
vel bars=1 lanes=38 v=1-62 min=25 max=58
```

## 10. Request recipes

`S` stands for the section selector, for example `bars=1-8`. `T` = ticks for the file's tempo from section 8. `N`, `A-B`, `B` = one bar, one beat window, one beat. Feel `half`: the backbeat is beat 3, so use `beats=3-3.25` where a recipe names beats 2 and 4.

How to read the table:

1. Pick one column: the lane he named, else the default target of the word (vocabulary 4). "Less robotic" and "more human" name every flat lane: there, each column whose lane has sd under 3.
2. Inside a cell the levers are in order of impact (principle 2). The default answer is the first two or three the file has room for, in one script (principle 1): not the safest one alone, not the whole list. He can say "more" or "less".
3. No room = already there, nothing to select, or the lane is at its ceiling (section 1). Skip that lever and say so, never force it.
4. Direction as in the intro. Other columns: only when he names them or says "more". A deleted or added note is always reported.

| request | hat lane (42, 46) | ghosts | cymbals | kick and backbeat |
|---|---|---|---|---|
| more alive | the default answer below: levels and leans (section 3), openings (5), motion over the phrase (6) | ghosts exist: pairs rise, written in bar blocks as digit 2 then digit 3, then `humanize S lanes=38 v=1-62 vel=5` and the wall of section 9. None exist: add them only when he names ghosts | quarter keeper: section 4. Crash accents closer than a quarter: every second one 14 lower (section 7) | none |
| less robotic | the default answer without its `remap` lines (an opening cell on an "and" takes a lean, a phrase start keeps its carrying level), then timing on the same `humanize` line: `time=T`, 6-10 ms. Nothing added or removed | `humanize S lanes=38 v=1-62 vel=5 time=T`, then the wall `vel S lanes=38 v=1-62 min=25 max=58` | keeper: section 4. Crash accents: `humanize S lanes=49,57 vel=3` | `humanize S lanes=kick vel=3`, `humanize S lanes=38 v=100-127 vel=3`, then the wall `vel S lanes=38 v=100-127 min=116` |
| more human | less robotic first. Then limb fixes, each reported as notes removed: `delete bars=N beats=A-B lanes=42,46` inside a two hand fill, the hat cell under a crash blanked in a bar block, two handed sixteenths: `delete S beats=3-3.25 lanes=42` on the backbeat cell | as less robotic. One flam per 4 bars only if he asks (section 8) | the second crash of a close pair 14 lower: `vel bars=N beats=B lanes=49 add=-14` | weak foot in runs: the kick run cure of section 2 |
| tighter | (1) openings closed: `remap S lanes=46 to=hh`, then each of those cells to a closed accent, `vel bars=N beats=B lanes=42 set=108` on an "and", `set=116` on a beat. (2) notes off the grid: delete and rewrite (section 8). (3) half the spread inside each articulation: `vel S lanes=42 v=100-127 scale=0.5 add=56`, then `vel S lanes=42 v=1-99 scale=0.5 add=42`. Step 3 moves notes by 7 at most: when it is the only one with room, say that the hat was tight already. No `time=` | `delete S lanes=38 v=1-30`, reported. Next: `vel S lanes=38 v=1-62 scale=0.8 min=25` | none. If he names them: crashes stay only on section starts, fill landings and riff accents, the others blanked in bar blocks and reported | `vel S lanes=kick min=120` when the kick min is under 120 (a flat kick is correct). Already at 127: nothing, say so. Timing untouched |
| punchier | second lever, never tips down. Flat hat: only the carrying beats rise, `vel S beats=1-1.25 lanes=42 set=116` and the same on the backbeat cell, the beat before a fill left out. Shaped hat: no room | none: quieter ghosts break principle 3, louder ones take the punch away | crash accents with room go to 112-120, per hit: `vel bars=N beats=B lanes=49 set=116`, each with a kick. The section start stays on top | first lever. Room (min under 122): `vel S lanes=kick,38 v=100-127 min=122`, then `humanize S lanes=kick,38 v=100-127 vel=3`. At the ceiling nothing here has room: say so, the next levers are weight and air (song-structure.md section 10, fills.md section 9) |
| softer | openings closed and the whole hat on the tip, on purpose (116 becomes 93, 84 becomes 67, the gaps stay): `remap S lanes=46 to=hh`, `vel S lanes=42 scale=0.8 max=96` | `vel S lanes=38 v=1-62 scale=0.8 min=20` | `vel S lanes=cym,ride scale=0.85` (the ranks stay). Next: keeper one rung down (grooves.md section 4) | heavy section: none. Clean section: `remap S lanes=38 v=100-127 to=rim`, `vel S lanes=37 scale=0.82`, `vel S lanes=kick scale=0.85 min=95` |
| more dynamic | flat part: the default answer below. Shaped part: what it lacks of section 6, in this order: the lift into the phrase ending fill, the growth of the later phrase, openings 14 apart | pairs rise: first 28, second 42 | rank the crashes (section 7): the start of the section on top, landings inside it one digit lower, riff accents one digit lower again, per hit with `vel bars=N beats=B lanes=49 add=-14` | none. Fills: fills.md sections 5 and 9 |
| more aggressive | one rung up the keeper ladder: grooves.md section 4 holds the rule and the script, which shapes the new row itself | louder, still ghosts: `vel S lanes=38 v=1-62 add=14 max=58` | china + crash1 stacked on the section start only (section 7) | room: `vel S lanes=kick,38 v=100-127 min=124`, then `humanize S lanes=kick,38 v=100-127 vel=3`. At the ceiling: skip and say so |
| smoother | (1) openings closed: `remap S lanes=46 to=hh`, each of those cells then to its plain level, `set=84` on an "and", `set=102` on a beat. (2) the carrying beats down to the plain beats: `vel S lanes=42 v=112-127 add=-14`. The leans and the bar differences stay | `vel S lanes=38 v=1-62 scale=0.8`, no flams | `vel S lanes=ride_bell scale=0.85`, `vel S lanes=cym scale=0.9` | none |
| groovier | openings on kick hits (section 5). A flat part gets lever 1 of section 3 with it. One handed sixteenths: base `75658565` [13] | asked again: 2 per bar at 30-45 on cells with no kick (section 9), reported as notes added | none | backbeat laid back 5-10 ms: `shift S lanes=38 v=100-127 ticks=T` (8 ticks at 130 bpm is 8 ms). Kick never shifts |

"Make the hi hat more alive". Scope: the bars where 42 keeps time. A section kept by china or crash is not part of a hat request: leave it and name it. Only a song with no hat at all turns "the hat" into the keeper cymbal (section 4). Default answer, one script: lever 1 (levels and leans), lever 2 (openings), lever 3 (growth, handover, lift), with `humanize vel=2` as the finish. Not part of it: kick, backbeat, fill notes, a landing crash for a fill that has none, hats deleted on snare cells, the foot, timing.

The example below is one file. Its input, as the four lists of section 3:

```
1 keeper: closed hat 42 on every eighth, flat at 98. no hat on bar 1 beat 1 (crash), in bar 4 beat 4 and in bar 8 beats 3-4 (fills)
2 carrying beats: feel half (snare on beat 3), so beats 1 and 3
3 kick under an "and":  bars 1 3 5 7  kick 9--9 --9- ---9 --9-  cells 6 and 14
                        bars 2 4 6 8  kick 9-9- ---9 --9- 9---  cells 2 and 10 (bar 4 stops at beat 4, bar 8 at beat 3)
4 phrases: bars 1-4 and 5-8. fills: 4:4-5, a 1 beat pickup, first note 98. 8:3-5, 2 beats, ends the section, first note 112
```

```vd
# said back: the hat keeps its eighths. beats 1 and 3 carry the bar, the plain "and"s come down, it leans where the kick lands (harder in the second phrase), opens on three kick hits and climbs into the bar 8 fill. kick, snare and fills untouched
# 1 notes, lever 2. bar 2: its last kick "and" is cell 10, and cell 12 holds a closed hat. bar 5: phrase start, hat and kick on beat 1, no crash. bar 6: the kick "and" bar 2 did not use, cell 2
remap bars=2 beats=3.5-3.75 lanes=42 to=hh_open
remap bars=5 beats=1-1.25 lanes=42 to=hh_open
remap bars=6 beats=1.5-1.75 lanes=42 to=hh_open
# 2 level, lever 1: carrying beats 116, plain beats 102, tips 84
accent bars=1-8 lanes=42 grid=16 pattern=8-6-7-6-
vel bars=1-8 lanes=42 v=91-127 add=4
# 3 finish
humanize bars=1-8 lanes=42 vel=2 seed=3
# 4 leans, phrase 1, one per bar. bar 1: cell 6, the kick "and" nearest the backbeat. bar 3 shares its kick row and takes the other, 14
vel bars=1 beats=2.5-2.75 lanes=42 add=24
vel bars=3 beats=4.5-4.75 lanes=42 add=24
# bars 2 and 4: cell 10 is the opening in bar 2 and the beat before the fill in bar 4, so both lean on cell 2
vel bars=2,4 beats=1.5-1.75 lanes=42 add=24
# phrase 2, every kick "and": bars 5 7 cells 6 14, bar 6 cell 10 (2 is its opening). bar 8 cell 2 is inside the lift
vel bars=5,7 beats=2.5-2.75 lanes=42 add=24
vel bars=5,7 beats=4.5-4.75 lanes=42 add=24
vel bars=6 beats=3.5-3.75 lanes=42 add=24
# 5 openings by phrase: 104, then 120 on the phrase start and 118
vel bars=2 lanes=46 set=104
vel bars=5 lanes=46 set=120
vel bars=6 lanes=46 set=118
# 6 lever 3. handover: bar 4 beat 3 is the beat before the pickup, H = 98. lift: the three hats before the bar 8 fill, H = 112
vel bars=4 beats=3-4 lanes=42 max=98
ramp bars=8 beats=1.5-3 lanes=42 from=88 to=112
```

Another file gives other cells, other bars, another H, maybe no opening at all. Do not carry a line of this script over: write the four lists for his section, decide each lever from them, and put the lists in your script as comments (principle 20). Every `beats=` window and every `bars=` group above exists only because of this example's kick row and fills.

Asked again ("more"), one per request: (1) timing, `humanize S lanes=42,46 time=T` with T = 6 to 10 ms (8 ticks at 130 bpm), velocities stay and the diff shows the notes as moved in time. (2) one more opening per phrase on a kick "and" that has none yet. The foot under a fill only when he asks for it (section 5).

Check before reporting, with the numbers of `vibedrum diff ORIGINAL RESULT` and `show RESULT --vel --bars S` (the acceptance tests of the principles, read for this request):

- Scope: `# bars changed` holds the hat section only, `# lanes` lists `hh` and `hh_open` only, 0 notes moved in time.
- Direction: the section's `vel` is within 3 of before (sixteenths, or a hat that was flat above 105: lower, and said). The notes under `quieter` are the plain "and"s and the start of the lift, nothing else.
- Audible: carrying beats 114-118 (one capped by the handover excepted), plain beats 100-104, tips 82-86, every lean 20 or more over the tips, openings 14 or more apart between phrases, the lift rises 20 or more.
- Not a loop: the loop test of section 6 over every bar of the section.
- Neighbours: in the beat before each fill no hat is over H, the lift ends on H, every opening has a kick under it and a closed hat on the next hat cell.
- Fills: every `# fills` line reads before = after. A fill with no landing is named in the report, not fixed here.
- Report, two or three lines: what the hat does now with bars and levels, what came down (the plain "and"s, from what to what) and the note count (a `remap` is a hat that became an opening, not a note added), then what he should know: fills weaker than the hat, a section kept by another cymbal. No word the numbers do not show.

## 11. Sources

1. https://www.nailthemix.com/drum-programming-faqs (backbeat 120-127, ghosts 20-50, hats 110 and 95)
2. https://www.nailthemix.com/getgood-drums-matt-halpern-drums-library (backbeat 115-120, blast 125-127, quantize 85 or 90 percent, snare a few ms early, kick slightly late)
3. https://www.nailthemix.com/toontrack-metal-foundry-sdx (alternate 120 and 127, blast 100-115, quantize 90-95 percent)
4. https://www.nailthemix.com/toontrack-metal-machinery-sdx (blast 115 and 125, ghosts 40-70, plus or minus 5-10 velocity, quantize 90-95 percent)
5. https://www.toontrack.com/blog/how-to-program-drums/ (hat hierarchy, edge on downbeats and tip on upbeats, ghosts 20-45, no ghost next to a backbeat, no three in a row, kick 100-115 and 75-95, backbeat 100-120)
6. https://urm.academy/5-drum-programming-tips-for-maximum-realism/ (110-120 over 127, never three hand hits at once, weak hand 5-25 lower, timing humanise 2-5 percent)
7. https://www.soundonsound.com/techniques/making-midi-sequencing-more-realistic-part-2-drum-parts (flam 6-30 ms early and slightly quieter, kick quantized while hat and snare float, snare early drives, snare late lays back)
8. https://www.soundonsound.com/techniques/programming-realistic-drum-parts (every other hit lower for alternate hands, no hats in a tom fill)
9. https://www.production-expert.com/production-expert-1/6-killer-hi-hat-programmingnbsptipsnbspfor-musicnbspproducers (two handed sixteenths skip the snare cell, choke group, pedal hat during fills, offbeat hits quieter)
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
21. https://drummagazine.com/matt-garstka-lets-get-technical/ (bass drums give no dynamics)
22. https://www.nailthemix.com/3-killer-drum-sample-replacement-techniques-for-metal (identical hits are a machine gun, do not set everything to 127)
23. https://www.nailthemix.com/slate-trigger-2 (all 127 is a machine gun, blast hits 95-115)
24. https://gearspace.com/threads/16th-note-hi-hats-question.797758/ (one handed sixteenths top out near 100 bpm for most players. Search excerpt only, page fetch failed)
