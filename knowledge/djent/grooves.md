# Djent grooves: groove vocabulary

Scope: the steady groove (not fills) in djent and progressive metalcore. Positions are grid=16 cell indexes 0-15 of a 4/4 bar unless a grid is named: beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12. Digits: 9 = 127, 8 = 112, 7 = 98, 6 = 84, 5 = 70, 4 = 56, 3 = 42, 2 = 28. A written digit is exact, a shown digit is a band 14 wide (9 = 119-127): check levels with `show --vel`. `[n]` = source list at the bottom. "unconfirmed" = working practice, no cited source. `EP n` = rule n of knowledge/editing-principles.md. Every recipe here obeys it, and where a line here seems to differ the EP rule wins.

Using a worked answer (EP 20): each one names the grid it was written for and shows how its cells, levels and bars were read from that grid. Read your file the same way: its kick sits elsewhere and its fills are built differently, so its cells, levels and bars come out different. Bar numbers are patterns, not ranges. After every apply run `vibedrum diff ORIGINAL RESULT` and `show RESULT --vel` on the changed bars and go through the acceptance tests at the end of the principles.

## 1. Kick and riff: `lock`, locked kicks, added kicks

- Base rule: in a riff section the kick plays the cells where `# riff` has `x` and nothing else. Haake: "I only do the hits with the guitar hits" [1]. Transcription analysis agrees: the pedal bass drum doubles guitar and bass [4].
- `lock` = riff onsets with a kick in the same cell / all riff onsets (read 85% as 0.85 if shown as a fraction). It does not count extra kicks, so read it together with kick/bar.

| lock | kick/bar | reading | action |
|---|---|---|---|
| 85-100% | 4-12 | unison riff or breakdown | the riff owns the kick row. Change velocities only, or move kicks only where `# riff` moves |
| 85-100% | 14-16 | double kick carpet under the riff, not unison | free to thin or reshape, riff accents stay covered |
| 50-85% | any | riff faster than the feet (tremolo sixteenths, kick marks group starts), or accents split between kick and snare [14] | inspect unlocked onsets: runs of adjacent cells are fine, isolated accents are candidates for a kick at 8 or 9 |
| under 50% | 1-6 | clean or ambient part (arpeggio riff, sparse kick), or `--riff` picked a lead track | intentional. Do not add kicks to raise it |
| under 50% | 8+ | blast or double time under tremolo picking, or a real mismatch | compare kick row and `# riff` cell by cell before editing |

- Locked kicks. Every kick on a cell where `# riff` has `x` is locked: never deleted, moved, shifted or given `humanize time=`, and on a request for more never turned down (EP 3). A kick with no riff onset under it is still his: it stays unless he says "only the riff".
- A kick may be added in two cases and in no other. (a) On a riff onset that has no kick: the base rule, good for any kick or weight request, and the only way a backbeat gets a kick under it. (b) Where the riff rests for 4 or more `# riff` cells in a row and the request asks for weight (heavier, harder, bigger, EP 4): under fill notes that are already there, on eighth cells (fills.md section 9 picks them). Never a run or a carpet into the rest (that takes his word, section 6), never under a backbeat that stands alone in the rest, and never in the 1 to 3 empty cells between the onsets of a figure: those rests are the riff's rhythm [1] (the 4 cell line is unconfirmed). Everywhere else riff rest = kick rest: where `# riff` has 4 or more empty cells the kick row is empty too, and only the cymbal anchor and the snare continue (unconfirmed, follows from [1]).
- No riff track (the header has no `# riff:` line): there is no `# riff` row and no lock column, so the table and case (a) cannot be read. Skip every step that names the riff or lock and say so in the report (EP 21). Never write a riff row from the kick row. Every kick in the row counts as locked. On a weight request a kick is added in two places only, both read from the kick row: under a fill whose beats are empty where the bar it otherwise repeats has kicks (a hole, fills.md section 9), and under a backbeat with a kick on the cell before it and on the cell after it (the snare sits inside a burst, song-structure.md section 10). A fill or a backbeat in a rest that the other bars share keeps its hole, and nothing goes between the other kicks of the groove (working rule, unconfirmed).
- "Tighten the kick to the guitar", "lock the kick": what is heard is the missing kicks, so they are the answer (EP 1, 2).
  1. Bar by bar in the named section, hold the kick row against `# riff` and list the riff cells with no kick. Leave out runs of adjacent riff cells that are faster than the feet (the 50-85% row: the kick marks their group starts) and onsets that a snare or tom already carries (the split of section 5).
  2. Add a kick on each listed cell: copy the bar from `show` and write `x` in the kick row under the riff `x` (`x` takes the lane's usual velocity, so the new kicks sit level with the old ones). Each bar is written by itself, never one kick bar copied over the others (section 2). Report the count and `lock` before and after.
  3. Only when he says "only the riff" or asks again: delete the kicks that have no riff onset. Leave carpets (kick/bar 14+) and kicks under fills alone, and report how many went.
- Kick velocity in unison parts: 112-127, nearly flat. A kick lane sd of 0-8 is normal (triggered kick sound: 0-4 on riff hits, 3-6 inside runs, dynamics-and-feel.md section 1) and is not the machine gun flaw. The same sd on hats or snare is (numbers unconfirmed).
- Kick at the ceiling (`# lanes` shows min = max = 127): it cannot be raised, so "harder" or "punchier" never comes from kick level, and the kick row is not turned down to make room either (EP 3). The levers are weight and air (EP 4): section 4, ceiling case.

## 2. Hand layer: the 4/4 anchor over a shifting riff

- One hand keeps a pulse on one cymbal: quarters (cells 0 4 8 12) in the heaviest parts, eighths (even cells) for more drive. The snare stays on a fixed backbeat: beat 3 (cell 8) in the Meshuggah model [4][5], beats 2 and 4 (cells 4 12) in the programming recipes [21][22]. Guitars, bass and kick run an odd length cycle underneath [4][5][21]. Haake: a nine hit cycle repeats against an 8/8 bar "while my cymbal/hi-hat hand and the snare play a straight beat" [2]. DRUM!: cycles of 17, 23 or 34 are not odd time signatures, "it's all built around 4/4" [1].
- Cycle arithmetic: riff cycle L sixteenths, block of N bars = 16N cells. Tile the cycle from cell 0 of the block, cut or pad the last copy so the block ends exactly, restart at the next block. Rational Gaze: 25+25+25+25+28 = 128 sixteenths = 8 bars, played twice [4], so the layers meet again at beat 64 = 16 bars [5]. New Millennium Cyanide Christ: 23 x 5 + 13 = 128 = 8 bars [23]. Periphery type recipe: a 7/8 kick bar (14 sixteenths) x 4 + 8 = 64 = 4 bars, "chop off whatever doesn't fit" [22]. Expect the full restart every 4, 8 or 16 bars.
- Recognise it: cymbal and snare rows identical in every bar of the section; kick row different in every bar (no `# bar N = bar M` lines for 4+ bars); the kick motif reappears shifted by a constant cell count (L = distance between two motif starts, counted across barlines); at the block boundary the motif restarts on cell 0 and crash1 replaces the keeper on that cell.
- Editing rules: never `copy` one bar of such a kick row over the others. `copy` whole blocks only (`copy from=1-8 to=9-16`). Variation requests go to the hand layer or to fills. In a section the request did not name, the keeper cells, the backbeat cell and the kick row do not change at all (EP 7). To write one: pick L from 5, 7, 9, 11, 13, 14, 17, 23 sixteenths, tile, cut at 16N cells (P1).
- Roles can swap: "Sometimes it's the feet doing the riff, and the hands are going straight over it", sometimes the hands do the riff [3]. Hand cycles: cymbal + kick accents every 3 sixteenths reset per bar (3+3+3+3+4, cells 0 3 6 9 12, P4), or every 3 eighths reset every 2 bars (bar 1 cells 0 6 12, bar 2 cells 2 8 14). Keep the snare on its backbeat cells so the bar stays countable (Postones on giving the listener a pulse under 5s, 7s and 9s [13], search excerpt only).
- The keeper is the tempo marker: Car Bomb's Lights Out shortens the cymbal spacing by one eighth per subsection and it is heard as a tempo change [15]. So the keeper spacing stays constant inside a section. Thinning it in half a section (quarters to half notes from bar 5 on) was heard in the trial as notes gone missing, not as weight: change the spacing only when he asks for that effect, for the whole section, and never so that a bar (look at the fill bars) keeps fewer than 2 keeper hits.
- Left foot: hh_pedal 44 on quarters, or eighths under tricky parts [13], as a metronome under crash or china riding. Haake: "That's my solid point in a sense whenever I'm not playing both bass drums" [1]. Velocity 42-70 (unconfirmed). It adds notes: write it when he asks for the foot or in a bar you write new, never as a part of "more alive" or "heavier" (EP 7). Only in bars where one foot can play the kick row: no kicks on adjacent cells above about 130 bpm (threshold unconfirmed).

## 3. Snare placement and feel

| feel | snare cells | velocity | where |
|---|---|---|---|
| half | 8 | 120-127 [7] | default for djent riffs and breakdowns. Felt tempo = half the file tempo |
| normal | 4, 12 | 115-127 [7][9] | choruses, driving verses, hat grooves |
| double | 2, 6, 10, 14, kick on 0, 4, 8, 12 | 112-127 | lifts of 2-4 bars, thrash type drive (usage unconfirmed) |
| blast | every other cell at the fastest grid. Kick between the snares (traditional), on every cell (bomb) or with the snare (hammer) [12] | 105-115 [8] | bursts of 1-4 bars at a peak, under tremolo picking. Not a default groove here (usage unconfirmed) |
| open | none | | intros, build-ups, the bar before a drop |
| other | snare is part of the odd cycle | | Haake's "pattern of snare and kick" cycles [2]. Keep it, do not move it to cell 8 |

- Sources disagree on blast snare velocity: 105-115 against a 125 backbeat [8], alternating 115 and 125 [20], or 125-127 so it cuts through [9]. Default 105-115: digit 8 plus `humanize vel=5`, with the pulse (one digit of difference) in the cymbal row, as in P9. Go to 9 only when the user asks for the blast to cut.
- A feel change moves the backbeat, so it needs a feel word from him (half time, double time, blast) and stays inside the section he named (EP 7). With no bpm change, half to normal doubles the felt tempo ("more driving"), normal to half halves it ("heavier, slower") (unconfirmed, practice).
- In a groove the snare lane has two zones only: backbeats 112-127 and ghosts 20-50 [7][8] (40-70 in [20]). Values 75-105 belong to fills, crescendos and blasts (unconfirmed, practice). The gap between the zones is a wall (EP 13), and `show` reads a snare of 60 or more as a backbeat. After any scale or humanize on ghosts clamp them: `vel bars=A-B lanes=38 v=1-70 max=58`, with fill bars kept out of A-B. `lanes=snare` also takes rim, ghosts and fill notes: name 38 and a `v=` band (EP 19).
- Backbeats already at 120-127: a "harder snare" cannot come from level, and nothing around the backbeat is turned down for it (EP 3). Weight and air (EP 4): a kick under the backbeat only where section 1 allows it (a riff onset on that cell; no riff track: a kick on both cells beside it), and air from the ghosts in the two cells before it (`delete` them, report the count). After that a flam (dynamics-and-feel.md).

## 4. Which cymbal keeps time

| keeper | lane | usual cells | velocity | signals |
|---|---|---|---|---|
| closed hat | hh 42 | eighths or sixteenths | about 110 on the beat, 95 between [7]. Shoulder on the beat 100-118, tip between 60-99, 100 is the wall between them. Levels by role: dynamics-and-feel.md sections 1 and 3 | tight, quiet: verses, clean parts, ghost note grooves |
| loose hat | hh_open 46 | quarters or eighths | 90-122 | heavy verse, pre-chorus. Haake keeps an "open trashy hi-hat" [1] |
| ride | ride 51 | eighths | 85-112 | clean or ambient passages, bridges |
| ride bell | ride_bell 53 | quarters or offbeat eighths (cells 2 6 10 14) | 105-120 | melodic chorus, solo backing, cuts through distortion |
| crash riding | crash1 49, crash2 57 | quarters or eighths | 105-120, offbeat eighths about 98, 127 on the section start only | chorus, climax, widest wash |
| china | china 52 | quarters | 105-120, 127 on a phrase start only | heaviest half time riffs and breakdowns: trashy, short sustain, accent role [19]. Haake: no ride, "just big crashes and Chinas" [3] |
| stack | no built in lane: splash 55 as stand in, or a custom map lane named stack | sixteenth figures, odd groupings, accents with the kick | 90-115 | short dry hit for fast articulate patterns. Halpern's signature stack: 17 inch crash on top of an 18 inch china [18] |
| foot hat | hh_pedal 44 | quarters | 42-70 | metronome under crash or china riding [1][13] |

- Closed hat digits: 8 on the beat, 6 or 5 between. Digit 7 (98) sits 2 under the wall at 100, so a closed hat written at 7 needs `vel bars=A-B lanes=42 v=90-104 max=99` after `humanize` (EP 13, P10).
- Keeper ladder: hh 42, hh_open 46, crash riding 49, china 52. "Heavier" and "more aggressive" on a section go one rung up, "calmer" one rung down. Side steps: ride 51 for hh in clean or ambient parts, ride_bell 53 as the melodic option next to crash riding (ladder order and velocity ranges without a source number are unconfirmed). Read first: `# lanes` (which cymbal lanes have notes, the keeper's min and max), `show --vel` of the section (is the row flat, in which cells a kick sits under a keeper note, where each fill starts and how loud it is), and the keeper of the next section. One rung up is three levers in order of impact (EP 1, 2), then a check, and no note ends under its old level (EP 3):
  1. The rung. `remap` by pitch: cells and rate stay, fill bars keep their fill. One rung, in the named section only (EP 7). Onto the keeper of the next section only when that section still enters as something new (another feel, a stop or air before it, a stacked entrance: EP 6). Not onto a cymbal lane with count 0 in `# lanes`, which may be silent in his kit: take the nearest rung that has notes and say so (EP 24). hh_open 46 and hh_pedal 44 are articulations of a hat he already has.
  2. Weight where the foot lands (EP 12). Flat row: keeper notes that share their cell with a kick go 15 to 25 up (EP 17), the others stay. All of them in every bar would print the kick's own loop onto the keeper, so they come in by phrase: in the first phrase the offbeat ones (a kick "and" under a keeper note), from the second phrase on every one (a section of one phrase: its first half, its second half; the split is a working rule, unconfirmed). One `accent` line per kick row and phrase: bars with another kick row get another pattern, and a pattern cell with no keeper note does nothing. Row already shaped (two or more digits in `show`): its shape stays, and it moves into the new row's range with `vel ... scale=` or `add=`, never `min=` or `set=` (EP 11).
  3. The phrase (EP 12): the plain notes build over the last phrase of the section into its last fill (no fill there: into its last bar), `ramp ... scale=1-1.2` (EP 18), up to the level of the kick cells. After levers 2 and 3 no two bars of the section have the same keeper row.
  4. Hand-over check (EP 14). For each fill the keeper runs into, read the last keeper note before it, before and after the edit. If it rose and now stands over the fill, the fill goes up by the same amount, level only: `vel BAR beats=F-T lanes=38,tom add=N` (a backbeat at full inside the window: add `v=1-118`). Cap N so the hit after the fill still stands 10 over the fill's last note (EP 6). No room under that cap: make the build smaller. The fill's shape, a kick under it and its landing are a fill request (fills.md section 9): say in the report that they are open, do not start them here.
  5. Onto china, eighths become quarters: `delete bars=A-B beats=1.5-2 lanes=52`, then the same with `2.5-3`, `3.5-4`, `4.5-5` (sixteenth hats: `1.25-2` and so on). A quarter row has no kick cells to pick: flat notes go to about 112 with `vel ... v=98 add=14` (`v=` is their old value, so a 127 already in the lane is not touched) and cell 0 of each phrase start bar to 127. Report the rate change and the notes that went.
  "Calmer" is the mirror: one rung down, the row scaled into the lower range with `vel ... scale=`, nothing ends louder, accents stay on their cells.

```vd
# request: "make the verse heavier". Read from this example's grid: verse = bars 1-8, closed hat 42 in eighths, flat at 98, phrases 1-4 and 5-8. China keeps the next section
# a kick sits under a hat note on cells 0 2 6 12 in bars 1 3 5 7 (kick row 9-99 --9- -9-9 9---) and on cells 0 6 12 14 in bars 2 4 6 8 (9--9 -99- -9-- 9-9-)
# fills, flat at 98: a pickup at 4:4-5 (the two hats before it hold no kick and stay plain) and the section's last fill at 8:3-5. Bar 9 enters on crash1 + kick at 127
# 1 the rung
remap bars=1-8 lanes=42 to=hh_open
# 2 kick cells go 19 up: mix=0.65 moves a note 0.65 of the way to the digit (98 to 117), so a 9 can only raise. Phrase 1: the kick "and"s. Phrase 2: every kick cell
accent bars=1,3 lanes=46 grid=16 pattern=--9---9--------- mix=0.65
accent bars=2,4 lanes=46 grid=16 pattern=------9-------9- mix=0.65
accent bars=5,7 lanes=46 grid=16 pattern=9-9---9-----9--- mix=0.65
accent bars=6,8 lanes=46 grid=16 pattern=9-----9-----9-9- mix=0.65
# a spread of 2 that sits on top of the old level, so no note ends under 98
vel bars=1-8 lanes=46 add=2
humanize bars=1-8 lanes=46 vel=2 seed=4
# 3 the plain notes (v=1-108) build over the last phrase, bars 5-8, up to the level of the kick cells
ramp bars=5-8 lanes=46 v=1-108 scale=1-1.2
# 4 the last hat before the bar 8 fill rose from 98 to 119, so that fill goes with it: add=19 is the most that leaves the bar 9 entrance 10 above
vel bars=8 beats=3-5 lanes=38,tom add=19
```
  What `diff` and `show --vel` have to show: the old keeper lane gone and the new one there with the same count, no note under its old level, kick cells 15 to 25 over the plain notes, the plain notes of the last phrase rising by 15 or more, the raised fill 10 under the entrance. Loop test (dynamics-and-feel.md section 6): every two bars of the section differ by 13 or more in a keeper cell or by a missing note, and what `humanize` made does not count. The report names the fill that moved and says it is still flat. Another file has its kick under other cells (maybe one pattern per bar), other phrases, other fills, so other hand-overs or none.
- Ceiling case (EP 4): the section already rides china or crash, and `show --vel` of the section (`# lanes` is song wide) shows keeper, kick and backbeat at 127. No rung is left and no level. The keeper is not turned down for "heavier", "harder", "more aggressive" or "punchier": that answers a request for more with softer notes (EP 3), and the 105-120 of the table is for bars you write new. The answer is the recipe "the breakdown should hit harder" in song-structure.md section 10, whatever the section is called. Its steps and its worked answer live there only, so the two documents cannot drift. What it does, in order of impact, every lever that has room, in one script:
  1. The entrance. Air: the last eighth before the section's first bar empty in every lane. A groove bar: `delete` with the lanes named. A fill that runs to the bar line slides an eighth earlier and ends on its top. A kick in that eighth is locked and stays: no air, say so. A riff onset there with no kick: the guitar plays through and the drums still stop (song-structure.md section 6). Weight: a second cymbal with the crash on cell 0 of the first bar, the section's own keeper pitch, or crash2 when `# lanes` shows it has notes (EP 24). Only on a section start (EP 6), and only when both hands can get there: after the air, not straight after a hand sixteenth on cell 15 (EP 15).
  2. Weight under the hits: a kick under each backbeat where section 1 allows it, the kick row of every bar copied from `show` with that one cell changed. A kick or backbeat lane under 120 goes up first: `vel SEL lanes=36 add=N`, backbeats `vel SEL lanes=38 v=100-127 add=N`.
  3. The fills in the section, and the one that leads into it, when they sit a digit or more under its groove: raised, a kick under them where section 1 allows it, each by its rank and ending on its top (fills.md section 9).
  The keeper hits of the groove bars stay at their level. Only when he then asks for contrast or a less harsh cymbal: beats 2 and 4 of the keeper down 15 to 25, beats 1 and 3 left at full. That is an edit for less, and it is reported as quieter.
  What `diff` has to show: the section at the same or a higher vel and with more notes, no lane quieter, the last eighth before the entrance empty, every fill you touched with last within 5 of peak, `# bars changed` = the section and the bar before it (setup: report it and the notes that went).
- One keeper per section. It changes on a section boundary only, and the boundary is marked with crash1 + kick on cell 0. A second cymbal on that hit is for a section start only: a landing inside a section gets one crash and never outweighs the section's entrance or the first hit of the song (EP 6).
- One right hand: never two keepers on the same cell (china + closed hat). hh_pedal is a foot and may coexist.

## 5. Ghost notes and linear playing

- Ghost = snare at 20-50 (digits 2, 3) between backbeats [7][8]. Placements from [16]: the "a" of beats 2 and 4 (cells 7 and 15), so the ghost leads into the kick on the next beat. Then the last grid=32 cell before that beat, then two grid=32 cells (a drag). Also used: the cell before or after a backbeat (3, 5, 11, 13) (unconfirmed).
- The left hand plays them, "using the left hand to fill in the gaps of a beat with ghost notes" [13]: never on a backbeat cell, best on cells with no kick, 2-5 per bar (count unconfirmed).
- Adding ghosts (added notes: report the count). Read the kick row of each bar: a ghost leads into a kick [16], so it goes on the sixteenth right before a kick, on a cell with no kick, never on a backbeat cell, never inside a fill or in the beat before one. Up to 2 per bar: first the cell before a kick that sits on a beat (15 into beat 1 of the next bar, 11 into beat 4), then one before an offbeat kick. Digit 3 into a beat, digit 2 elsewhere. Bars with another kick row get other cells. Over the phrase (EP 12): its first bar takes one ghost, the middle bars two, and when a phrase repeats, one ghost of the repeat moves to another kick, so no bar folds onto an earlier one. A drag and a third ghost wait until he says "more". `# sections` vel drops because quiet notes came in: read the Direction test on the note count.
- Where: hat or ride sections in Periphery, TesseracT, Animals as Leaders type songs. Haake: ghost notes "just get lost in the mix and only the big hits come out" [3], so under china or crash riding raise them to 40-58 (digits 3-4; [20] goes up to 70, but 60 is the wall of section 3) or leave them out.
- Linear = no cell has two limbs. Check each column: at most one of kick, snare, hat or cymbal. The hat row has holes exactly where kick or snare play (P3 bar 2).
- Garstka splits riff accents between snare and kick because "you don't get dynamics with bass drums" [14], for example one snare then four kicks (Ka$cade intro) [14]. For a riff group of 5 onsets: snare 9 on the first, kick on the other 4. This lowers `lock` on purpose.
- Writing a linear bar: 1. kick on the riff onsets. 2. snare 9 on the backbeat cells. 3. hat on the remaining cells: 8 on a beat, 6 on an "and", 5 on "e" and "a" (empty cells are allowed). 4. swap 2-3 hat cells next to backbeats for ghosts at 2 or 3.

## 6. Double kick vocabulary

| type | grid signature | velocity | use |
|---|---|---|---|
| steady sixteenths | grid=16, all 16 cells | 98-127, leading foot (even cells) one digit (14-15) above the other | under sustained chords, choruses, tremolo riffs |
| thirty-second burst | grid=32, 2-8 adjacent cells | first note highest [11], then leading foot 112, other foot 98 | last beat or half beat before a snare or crash, or wherever the riff does it |
| herta | grid=32, `xxx-x-` every 6 cells (3 sixteenths) | 112-127 | Bleed: "two 32nd notes coming in every 3rd 16th note", hands in half time eighths [6] |
| gallop | grid=16, `x-xx` per beat, reverse `xx-x` | 112-127 | galloped palm mutes |
| eighth triplets | grid=12, up to 3 cells per beat | 112-127 | triplet riffs, 12/8 type sections |
| sextuplets | grid=24, 6 adjacent cells per beat | 98-115 | runs of 1-2 beats under a steady hand pattern |

- The velocity numbers in this table are unconfirmed; only the shapes carry a source. Weak side lower by 5-25 is the guide rule for hands [10], applied here to the feet at one digit: a gap under 10 is not heard (EP 17).
- Any of these types put into his kick row is added notes: only when he asks for double kick, one type per request, in the named section, and never into the rests of a unison riff (section 1, EP 7).
- Speed check: note spacing in ms = 60000 / bpm / notes per beat. Thirty-seconds at 115 bpm (Bleed [6]) = sixteenths at 230 bpm = 65 ms. A full bar of kicks closer than 65 ms (grid=32 above 115 bpm, grid=24 above 155 bpm) is extreme metal speed: in this style cut it into bursts or a herta (limit unconfirmed).
- The descending shape 84, 70, 59, 44 in [11] is for a natural kit. A metal kick loses its click that low: first note 112-127, the rest 98-112 (P8) (unconfirmed).
- Garstka: top speed = the speed where the sound stays even and powerful [14]. `humanize vel` above 5, a third of the gap between the feet (EP 17), on a fast kick run sounds like a weak player, not a human one (unconfirmed).

## 7. Tempo and subdivision

- File tempos cluster near 90, 120 and 140 bpm [17]. A riff at 140-155 is usually played half time, felt at 70-78 [17]. The same music can be notated slow: the Periphery type recipe is written at 80 bpm with the snare on 2 and 4 [22], which the header reports as feel `normal`. So 70-100 bpm + feel normal + kick detail at grid=32 = half time at double the tempo: apply the half time rules. Reference points: Bleed 115 [6]. Haake's comfort zone 140, awkward at 160-180, obZen title track 170 [1][2]. Blast = sixteenths at 180-280 bpm, 250 the usual ceiling [12], which in a 90-140 bpm file is grid=32.
- Grid by content: grid=16 default. grid=32 for bursts, herta, blasts. grid=12 or 24 when the riff is in triplets. A bar that `show` prints at grid=48 mixes thirty-seconds and triplets.
- Changing the grid of a bar that has notes: a hit written on a cell that already holds a note keeps that note at its old tick. Triplets written over sixteenths (or back) therefore stay straight: first `delete bars=N lanes=36` for each lane you rewrite, then the bar block. Sixteenths to grid=32 needs no delete.
- Cell length: sixteenth = 15000 / bpm ms (125 ms at 120 bpm, 107 ms at 140). Ticks = ms x bpm x PPQ / 60000. At 480 PPQ that is ms x bpm / 125, so one tick is about 1 ms between 100 and 140 bpm (5 ms at 140 bpm = 5.6 ticks). At 960 PPQ double the ticks.
- Micro timing: guides quantize to 85-95% instead of 100% [8][9][20], nudge single hits "a few milliseconds" [7][9], or humanise timing by 2-5% [10]. The engine has no quantize op: use `humanize time=N` (ticks) on hand lanes, 2-5, and no `time=` at all on a kick that doubles the riff (values unconfirmed). That spread only breaks sample exact stacking. Under about 5 ms nobody hears it as feel (trial finding): never report it as a gesture.
- A timing feel he asks for is a constant `shift` of about 5 ms, 6 ticks at 130-140 bpm (unconfirmed): a snare early in a fill = urgency, a kick late = laid back pocket [9]. `shift bars=A beats=F-T lanes=38 ticks=-6` on the chosen span, `shift bars=A-B lanes=36 ticks=6` only where the kick is not in unison with the riff. `shift` has no bar line guard: never move a note on cell 0 earlier.

## 8. Recognise the type in the grid

| type | header | grid |
|---|---|---|
| polymeter half time | feel half, keeper china or crash, lock 85%+ | cymbal and snare rows repeat every bar, kick row never does |
| unison breakdown | feel half or open, kick/bar 4-8 | gaps of 4+ empty kick cells, cymbal hits stacked on kick cells |
| carpet | kick/bar 14-16 | kick row full at grid=16 |
| herta, burst | bar printed at grid=32 | `xxx-x-` cycle, or 2-8 adjacent kick cells before a snare or crash |
| gallop | kick/bar 12 | `x-xx` in every beat |
| triplet | bar printed at grid=12 or 24 | 3 or 6 kick cells per beat |
| ghost groove | keeper hh or ride, snare lane vel min under 50 | digits 2-3 between the 9s of the snare row |
| linear | keeper hh, feel normal or other | no column with two hits |
| double time | feel double | snare on cells 2 6 10 14 |
| blast | feel blast | snare on every other cell, kick between them, on all cells or on the same cells |
| half time written slow | 70-100 bpm, feel normal, bars printed at grid=32 | snare on cells 8 and 24 of grid=32, kick detail in thirty-seconds: same music as feel half at double the bpm |

- No riff track: the lock conditions of this table cannot be read. Decide from the other signs and say that lock was not available (EP 21).
- `# fills:` is fooled by a groove change: a bar with new ghosts, a blast or a double time burst has 2 more snare hits in a beat than its section usually has, so it is listed as a candidate (seen with P3 and P9). It is not a fill: keep the `fills` selector off it (fills.md section 2).

## 9. Canonical patterns

Writing any bar: 1. kick = `# riff` onsets (unison) or a type from section 6. No riff track: his kick row stays. 2. snare per the feel table at 9. 3. one keeper from section 4. Cell 0 of a section's first bar is crash1 9 + kick, with the keeper blank on that cell. 4. limb check per cell: at most 2 hand hits plus kick plus hh_pedal, and look one cell back: a hand does not cross the kit in one sixteenth at speed (EP 15). 5. shape in the digits: a timekeeping row in eighths or faster never keeps one digit for a whole bar. Closed hat: 8 on the beat, 6 or 5 between. Quarter cymbals: 8, and 9 only where a section or phrase starts. Backbeats and unison kick accents may stay 9. Blast snare: one digit. These rows are a start: in his song the accents then go where his kick and his phrase are (section 4, EP 12). 6. op order (EP 16): bar blocks, `copy`, `remap`, `delete`, then level (`vel`, and the base `accent` over a whole part: at mix 1 it writes exact values and would erase a `humanize` run before it), then `humanize` at or under a third of the smallest designed gap (EP 17: hands vel=3-5 time=2-4, kick vel=3 and no time=, ticks at 480 PPQ), then the gestures (`accent` on single bars, `vel add=`, `ramp scale=`), each 15 or more, then wall clamps (EP 13).

Pasting a pattern into a song (EP 20): rows you do not write stay, so blank the old keeper with a row of `-`. A bar that holds a fill keeps its fill span. A pattern at another grid than the bar: `delete` the rewritten lanes first (section 7). A lane the kit lacks: lever 1 of the keeper ladder in section 4. A pattern is one or two bars: pasted over a section it is a loop until the kick and the phrase have shaped it.

```vd
# P1 half time polymeter. China quarters and snare on 3 fixed, kick cycle of 7 sixteenths (9-98-9-) cut at the end of bar 2. China at 8: the 9 belongs to the phrase start, here the crash. Main riffs, Meshuggah type
bar 1 grid=16
crash1 49  |9--- ---- ---- ----|
china 52   |---- 8--- 8--- 8---|
snare 38   |---- ---- 9--- ----|
kick 36    |9-98 -9-9 -98- 9-9-|
bar 2 grid=16
china 52   |8--- 8--- 8--- 8---|
snare 38   |---- ---- 9--- ----|
kick 36    |98-9 -9-9 8-9- 9-98|
humanize bars=1-2 lanes=52 vel=5 time=2 seed=1
```

```vd
# P2 herta kick cycle at grid=32: 6 cells (989-9-) = 3 sixteenths, hands play half time eighths: crash 9 on the section start only, then 8 on the beat and 7 between. Bleed type, about 115 bpm
bar 1 grid=32
crash1 49  |9--- 7--- 8--- 7--- 8--- 7--- 8--- 7---|
snare 38   |---- ---- ---- ---- 9--- ---- ---- ----|
kick 36    |989- 9-98 9-9- 989- 9-98 9-9- 989- 9-98|
```

```vd
# P3 bar 1: backbeat groove with ghost notes, closed hat eighths 112/84, ghosts at 28-42 on cells with no kick (verses, clean and groove sections). Bar 2: linear bar, one limb per cell, rests are also allowed (Garstka and Halpern type)
bar 1 grid=16
hh 42      |8-6- 8-6- 8-6- 8-6-|
snare 38   |---- 9--2 -3-- 9--2|
kick 36    |9--9 --9- --98 --9-|
bar 2 grid=16
hh 42      |-56- -5-- 8--5 --6-|
snare 38   |---- 9--2 ---- 93--|
kick 36    |9--9 --9- -98- ---9|
humanize bars=1-2 lanes=42 vel=5 time=3 seed=7
```

```vd
# P4 breakdown where the hands join the riff: crash + kick on 3+3+3+3+4 sixteenths (crash 9 on the bar start, 8 after), snare stays on 3, kick pickup on cells 14-15. Slow breakdowns
bar 1 grid=16
crash1 49  |9--8 --8- -8-- 8---|
snare 38   |---- ---- 9--- ----|
kick 36    |9--9 --9- -9-- 9-98|
```

```vd
# P5 chorus carpet, first bar of the section: crash riding quarters, normal backbeat, steady sixteenth double kick with right foot 127 and left foot 112. Later bars start on 8
bar 1 grid=16
crash1 49  |9--- 8--- 8--- 8---|
snare 38   |---- 9--- ---- 9---|
kick 36    |9898 9898 9898 9898|
```

```vd
# P7 triplet riffs. bar 1 grid=24 (6 cells per beat): eighth triplet kicks with sextuplet runs on beats 2 and 4. bar 2 grid=12 (3 cells per beat): triplet riff with rests
bar 1 grid=24
china 52   |8----- 8----- 8----- 8-----|
snare 38   |------ ------ 9----- ------|
kick 36    |9-9-9- 878787 9-9-9- 878787|
bar 2 grid=12
china 52   |8-- 8-- 8-- 8--|
snare 38   |--- --- 9-- ---|
kick 36    |99- 9-9 -99 9-9|
humanize bars=1-2 lanes=52 vel=5 time=2 seed=6
```

```vd
# P8 thirty-second kick burst on beat 4 (first note 127, then 98 and 112 alternating, never 127 flat) resolving on one crash + kick at the next downbeat, keeper blank on that cell
bar 1 grid=32
china 52   |8--- ---- 8--- ---- 8--- ---- 8--- ----|
snare 38   |---- ---- ---- ---- 9--- ---- ---- ----|
kick 36    |9--- 9-9- ---- 9--- ---- 9-9- 9787 8787|
bar 2 grid=16
crash1 49  |9--- ---- ---- ----|
china 52   |---- 8--- 8--- 8---|
kick 36    |9--- ---- ---- ----|
humanize bars=1-2 lanes=52 vel=5 time=2 seed=8
```

```vd
# P9 fast feels. bar 1 double time (snare on the offbeat eighths). bar 2 traditional blast (kick + cymbal together, snare between) [12]
# P9 bar 3: bomb blast (kick sixteenths, snare + cymbal on eighths) [12]. Blast snare at 112, not 127. The cymbal row carries the pulse (8 on the beat, 7 between)
# P9 bars 2-3 at grid=16 fit a file at 180+ bpm. In a 90-140 bpm file write the same alternation at grid=32 (32 cells per row)
bar 1 grid=16
crash1 49  |9--- 8--- 8--- 8---|
snare 38   |--9- --9- --9- --9-|
kick 36    |9--- 9--- 9--- 9---|
bar 2 grid=16
ride 51    |8-7- 8-7- 8-7- 8-7-|
snare 38   |-8-8 -8-8 -8-8 -8-8|
kick 36    |8-8- 8-8- 8-8- 8-8-|
bar 3 grid=16
china 52   |9-7- 8-7- 8-7- 8-7-|
snare 38   |8-8- 8-8- 8-8- 8-8-|
kick 36    |8787 8787 8787 8787|
humanize bars=2-3 lanes=38,51,52 vel=4 time=2 seed=5
```

```vd
# P10 two handed sixteenth hat verse (no hat on the backbeat cells 4 and 12), written flat, then shaped: beat 112, e 84, and 98, a 84 (a starting row: in his song the levels come from dynamics-and-feel.md section 4), last eighth opened. The "and" at 98 sits on the wall, so the clamp comes last
bar 1 grid=16
hh 42      |8888 -888 8888 -8--|
hh_open 46 |---- ---- ---- --8-|
snare 38   |---- 9--- ---- 9---|
kick 36    |9--- --9- -9-- ----|
accent bars=1 lanes=42 grid=16 pattern=8676
humanize bars=1 lanes=42,46 vel=4 time=2 seed=3
vel bars=1 lanes=42 v=90-104 max=99
```

## 10. What makes it sound programmed or wrong

Use: after the acceptance tests of the principles, read the bars and lanes the edit touched in `show --vel` against this list. A flaw from the list that was in his file before and lies outside the request is not fixed (EP 7): it gets a few words in the report at most.

1. Hand lanes with sd near 0: hats, ride, ghosts, toms at one velocity. Hats need at least the 110/95 alternation [7]. Random spread ([20] uses 5-10) stays at or under a third of the accent gap, 5 for a gap of 15 (EP 17), and is not life: one beat of shape plus spread is still a one beat loop. Life is accents where the kick is and motion over the phrase (EP 12, dynamics-and-feel.md).
2. Every lane at 127 in bars you wrote. Only snare backbeats, section start crashes, phrase start cymbals and unison kick accents sit at 120-127 [7][8]. [10] puts ordinary hard hits at 110-120 and [9] normal backbeats at 115-120: keeper cymbals, fast kicks, blast snares and unaccented tom notes stay at digit 8 or lower (fill accents on toms: fills.md section 5). A lane of his that sits at 127 is not turned down on a request for more: weight and air (section 4 ceiling case, EP 4).
3. Kick that ignores the riff: lock under 85% in a section that is plainly a unison chug [1][4]. No riff track: cannot be judged, skip it and say so (EP 21).
4. Polymeter flattened: one kick bar copied over the others where the riff cycle crosses the barline, or a cymbal anchor that drifts with the kick so the 4/4 pulse disappears [4][13].
5. Impossible limbs: three hand hits on one cell, a keeper cymbal that continues through a two hand tom or snare run, china and closed hat on the same cell [10].
6. One handed sixteenth hats above about 110 bpm with snare hits on hat cells. Two handed sixteenths leave the backbeat cells without a hat (P10) (bpm unconfirmed).
7. Ghost notes at 60-100: `show` and the ear read them as weak backbeats. Ghosts stacked on kick cells in every bar: mud (unconfirmed).
8. Blast snares or thirty-second kick runs at 127 flat. Blast snare 105-115 [8], burst kicks 98-112 after the first note.
9. Any `humanize time` on the kick in unison parts: flams against the guitar. Zero timing spread on the hands for a whole song: stiff [8][9] (tick values unconfirmed).
10. Strong and weak side identical in fast runs, or closer than 10 (EP 17). On a request for more raise the strong side by 15-25 and leave the weak side where it is (EP 3). Lowering the weak hand ([10] gives 5-25) or the weak foot is for a request for less, or for a part whose average should stay level.
11. Section change with no crash + kick on cell 0, or a crash with neither kick nor snare under it (unconfirmed, practice). The reverse too (EP 6): a two cymbal stack or a landing inside a section that outweighs the section's own entrance or the first hit of the song, or the next section's keeper sounding before its first bar.
12. Sixteenth carpet under a clean or ambient part, or blast as the default groove (unconfirmed, practice).
13. Keeper lane or keeper spacing switching inside a section with no section change (unconfirmed, practice).
14. A level op that left one value: `vel min=` or `set=` over a shaped row (EP 11). Redo it with `scale=` or `add=` on the version before.
15. An answer to "more" that the numbers show as less: a keeper, kick or weak hand turned down, a fill that starts under its old level or ends under its own peak (EP 3, 9). `vibedrum diff` shows it in `# lanes` and `# fills`.

## Sources

1. DRUM! Magazine, Tomas Haake: Meshuggah's Djentle Giant. https://drummagazine.com/tomas-haake-meshuggahs-djentle-giant/
2. DRUM! Magazine, Tomas Haake: Meshuggah Goes It Alone. https://drummagazine.com/tomas-haake-meshuggah-goes-it-alone/
3. Modern Drummer, web exclusive interview with Tomas Haake (2013). https://www.moderndrummer.com/2013/06/web-exclusive-interview-with-meshuggahs-tomas-haake/
4. Jonathan Pieslak, Re-casting Metal: Rhythm and Meter in the Music of Meshuggah. https://pdfcoffee.com/re-casting-metal-rhythm-and-meter-in-the-music-of-meshuggah-pdf-free.html
5. Wikipedia, Meshuggah (musical style). https://en.wikipedia.org/wiki/Meshuggah
6. San Diego Modern Drum Lessons, Analyzing Bleed by Meshuggah (kick and hand patterns). http://sandiegomoderndrumlessons.blogspot.com/2014/01/analyzing-bleed-by-meshuggah.html Tempo 115 bpm: https://songbpm.com/@meshuggah/bleed
7. Nail The Mix, modern metal drum programming FAQs. https://www.nailthemix.com/drum-programming-faqs
8. Nail The Mix, GetGood Drums Invasion guide. https://www.nailthemix.com/getgood-drums-the-invasion
9. Nail The Mix, GetGood Drums Matt Halpern library guide. https://www.nailthemix.com/getgood-drums-matt-halpern-drums-library
10. URM Academy, 5 drum programming tips for maximum realism. https://urm.academy/5-drum-programming-tips-for-maximum-realism/
11. KVR Audio forum, programming metal double kick patterns. https://www.kvraudio.com/forum/viewtopic.php?t=251747
12. Wikipedia, Blast beat. https://en.wikipedia.org/wiki/Blast_beat
13. Jay Postones interviews, search excerpts only (pages not fetchable: the foot hat and ghost note quote is confirmed by excerpt, the pulse remark is a paraphrase). http://mikedolbear.com/interviews/jay-postones/ and https://ghostcultmag.com/interview-jay-postones-tesseract-polaris/
14. DRUM! Magazine, Matt Garstka: Let's Get Technical. https://drummagazine.com/matt-garstka-lets-get-technical/
15. Metal in Theory, Metric Complexity in Car Bomb's Lights Out. https://metalintheory.com/car-bomb-lights-out/
16. DRUM! Magazine, lesson: ghost note style and placement. https://drummagazine.com/lesson-ghost-note-style-and-placement/
17. Tempo ranges, search excerpts only. https://sevenstring.org/threads/the-perfect-djent-tempo.182690/ and https://www.melodigging.com/genre/djent
18. Meinl Matt Halpern Double Down stack, retailer listing, search excerpt only. https://www.sweetwater.com/store/detail/DOUBLEDOWN--meinl-cymbals-artist-concept-model-matt-halpern-double-down-stack
19. China cymbal role, search excerpts only. https://drumhelper.com/cymbals/best-china-cymbal/ and https://en.wikipedia.org/wiki/China_cymbal
20. Nail The Mix, Toontrack Metal Machinery SDX guide. https://www.nailthemix.com/toontrack-metal-machinery-sdx
21. Hack Music Theory, How to Make Djent Beats (quarter note cymbal, snare on 2 and 4, kick in 17/16, 120 bpm). https://www.goodreads.com/author_blog_posts/22597465-how-to-make-djent-beats
22. Hack Music Theory, How to Write Polymeter Drums, from Periphery "Atropos" (80 bpm, 7/8 kick over 4 bars of 4/4). https://hackmusictheory.com/blogs/theory/posts/7168271/how-to-write-polymeter-drums-music-theory-from-periphery-atropos
23. Valentin Schuster, drum transcription of New Millennium Cyanide Christ (5 x 23/16 + 13/16), search excerpt only. https://valentinschuster.com/wp-content/uploads/2021/08/Meshuggah-New-Millenium-Cyanide-Christ.pdf
