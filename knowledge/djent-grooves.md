# Djent grooves: groove vocabulary

Scope: the steady groove (not fills) in djent and progressive metalcore. Positions are grid=16 cell indexes 0-15 of a 4/4 bar unless a grid is named: beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12. Digits: 9 = 127, 8 = 112, 7 = 98, 6 = 84, 5 = 70, 4 = 56, 3 = 42, 2 = 28. `[n]` = source list at the bottom. "unconfirmed" = working practice, no cited source.

## 1. Kick and riff: what `lock` means

- Base rule: in a riff section the kick plays the cells where `# riff` has `x` and nothing else. Haake: "I only do the hits with the guitar hits" [1]. Transcription analysis agrees: the pedal bass drum doubles guitar and bass [4].
- `lock` = riff onsets with a kick in the same cell / all riff onsets (read 85% as 0.85 if shown as a fraction). It does not count extra kicks, so read it together with kick/bar.

| lock | kick/bar | reading | action |
|---|---|---|---|
| 85-100% | 4-12 | unison riff or breakdown | the riff owns the kick row. Change velocities only, or move kicks only where `# riff` moves |
| 85-100% | 14-16 | double kick carpet under the riff, not unison | free to thin or reshape, riff accents stay covered |
| 50-85% | any | riff faster than the feet (tremolo sixteenths, kick marks group starts), or accents split between kick and snare [14] | inspect unlocked onsets: runs of adjacent cells are fine, isolated accents are candidates for a kick at 8 or 9 |
| under 50% | 1-6 | clean or ambient part (arpeggio riff, sparse kick), or `--riff` picked a lead track | intentional. Do not add kicks to raise it |
| under 50% | 8+ | blast or double time under tremolo picking, or a real mismatch | compare kick row and `# riff` cell by cell before editing |

- Riff rest = kick rest. Where `# riff` has 4 or more empty cells the kick row is empty too; only the cymbal anchor and the snare continue (unconfirmed, follows from [1]).
- "Tighten the kick to the guitar": add a kick (8 or 9) on each unlocked riff onset, delete kicks with no riff onset, leave carpets and fills alone.
- Kick velocity in unison parts: 112-127, nearly flat. A kick lane sd of 3-8 is normal (triggered kick sound) and is not the machine gun flaw. The same sd on hats or snare is (numbers unconfirmed).

## 2. Hand layer: the 4/4 anchor over a shifting riff

- One hand keeps a pulse on one cymbal: quarters (cells 0 4 8 12) in the heaviest parts, eighths (even cells) for more drive. The snare stays on a fixed backbeat: beat 3 (cell 8) in the Meshuggah model [4][5], beats 2 and 4 (cells 4 12) in the programming recipes [21][22]. Guitars, bass and kick run an odd length cycle underneath [4][5][21]. Haake: a nine hit cycle repeats against an 8/8 bar "while my cymbal/hi-hat hand and the snare play a straight beat" [2]. DRUM!: cycles of 17, 23 or 34 are not odd time signatures, "it's all built around 4/4" [1].
- Cycle arithmetic: riff cycle L sixteenths, block of N bars = 16N cells. Tile the cycle from cell 0 of the block, cut or pad the last copy so the block ends exactly, restart at the next block. Rational Gaze: 25+25+25+25+28 = 128 sixteenths = 8 bars, played twice [4], so the layers meet again at beat 64 = 16 bars [5]. New Millennium Cyanide Christ: 23 x 5 + 13 = 128 = 8 bars [23]. Periphery type recipe: a 7/8 kick bar (14 sixteenths) x 4 + 8 = 64 = 4 bars, "chop off whatever doesn't fit" [22]. Expect the full restart every 4, 8 or 16 bars.
- Recognise it: cymbal and snare rows identical in every bar of the section; kick row different in every bar (no `# bar N = bar M` lines for 4+ bars); the kick motif reappears shifted by a constant cell count (L = distance between two motif starts, counted across barlines); at the block boundary the motif restarts on cell 0 and crash1 replaces the keeper on that cell.
- Editing rules: never `copy` one bar of such a kick row over the others. `copy` whole blocks only (`copy from=1-8 to=9-16`). Variation requests go to the hand layer or to fills. To write one: pick L from 5, 7, 9, 11, 13, 14, 17, 23 sixteenths, tile, cut at 16N cells (P1).
- Roles can swap: "Sometimes it's the feet doing the riff, and the hands are going straight over it", sometimes the hands do the riff [3]. Hand cycles: cymbal + kick accents every 3 sixteenths reset per bar (3+3+3+3+4, cells 0 3 6 9 12, P4), or every 3 eighths reset every 2 bars (bar 1 cells 0 6 12, bar 2 cells 2 8 14). The keeper is the tempo marker: Car Bomb's Lights Out shortens the cymbal spacing by one eighth per subsection and it is heard as a tempo change [15], so keep the keeper spacing constant inside a section unless that effect is asked for. Keep the snare on its backbeat cells so the bar stays countable (Postones on giving the listener a pulse under 5s, 7s and 9s [13], search excerpt only).
- Left foot: hh_pedal 44 on quarters, or eighths under tricky parts [13], as a metronome under crash or china riding. Haake: "That's my solid point in a sense whenever I'm not playing both bass drums" [1]. Velocity 42-70 (unconfirmed). Only in bars where one foot can play the kick row: no kicks on adjacent cells above about 130 bpm (threshold unconfirmed).

## 3. Snare placement and feel

| feel | snare cells | velocity | where |
|---|---|---|---|
| half | 8 | 120-127 [7] | default for djent riffs and breakdowns. Felt tempo = half the file tempo |
| normal | 4, 12 | 115-127 [7][9] | choruses, driving verses, hat grooves |
| double | 2, 6, 10, 14, kick on 0, 4, 8, 12 | 112-127 | lifts of 2-4 bars, thrash type drive (usage unconfirmed) |
| blast | every other cell at the fastest grid. Kick between the snares (traditional), on every cell (bomb) or with the snare (hammer) [12] | 105-115 [8] | bursts of 1-4 bars at a peak, under tremolo picking. Not a default groove here (usage unconfirmed) |
| open | none | | intros, build-ups, the bar before a drop |
| other | snare is part of the odd cycle | | Haake's "pattern of snare and kick" cycles [2]. Keep it, do not move it to cell 8 |

- Sources disagree on blast snare velocity: 105-115 against a 125 backbeat [8], alternating 115 and 125 [20], or 125-127 so it cuts through [9]. Default 105-115 (digit 8 plus `humanize vel=5`). Go to 9 only when the user asks for the blast to cut.
- Section lift with no bpm change: half to normal doubles the felt tempo ("more driving"), normal to half halves it ("heavier, slower") (unconfirmed, practice).
- In a groove the snare lane has two zones only: backbeats 112-127 and ghosts 20-50 [7][8] (40-70 in [20]). Values 75-105 belong to fills, crescendos and blasts (unconfirmed, practice).

## 4. Which cymbal keeps time

| keeper | lane | usual cells | velocity | signals |
|---|---|---|---|---|
| closed hat | hh 42 | eighths or sixteenths | about 110 on the beat, 95 between [7]. Working ranges 105-115 and 85-100 | tight, quiet: verses, clean parts, ghost note grooves |
| loose hat | hh_open 46 | quarters or eighths | 100-120 | heavy verse, pre-chorus. Haake keeps an "open trashy hi-hat" [1] |
| ride | ride 51 | eighths | 85-105 | clean or ambient passages, bridges |
| ride bell | ride_bell 53 | quarters or offbeat eighths (cells 2 6 10 14) | 105-120 | melodic chorus, solo backing, cuts through distortion |
| crash riding | crash1 49, crash2 57 | quarters or eighths | 110-125 | chorus, climax, widest wash |
| china | china 52 | quarters | 115-127 | heaviest half time riffs and breakdowns: trashy, short sustain, accent role [19]. Haake: no ride, "just big crashes and Chinas" [3] |
| stack | no built in lane: splash 55 as stand in, or a custom map lane named stack | sixteenth figures, odd groupings, accents with the kick | 90-115 | short dry hit for fast articulate patterns. Halpern's signature stack: 17 inch crash on top of an 18 inch china [18] |
| foot hat | hh_pedal 44 | quarters | 42-70 | metronome under crash or china riding [1][13] |

- Intensity ladder for "heavier" and "calmer" requests: hh, hh_open, crash riding, china. Side steps: ride replaces hh in clean or ambient parts, ride_bell is the melodic option next to crash riding. Move one or two steps with `remap bars=A-B lanes=hh to=china`, then clamp into the target row's range with `vel bars=A-B lanes=china min=115`. Eighths that must become quarters: after the remap run `delete bars=A-B lanes=china beats=1.5-2`, then the same with `2.5-3`, `3.5-4`, `4.5-5` (ladder order and velocity ranges without a source number are unconfirmed).
- One keeper per section. Change it on a section boundary and mark the boundary with crash1 + kick on cell 0.
- One right hand: never two keepers on the same cell (china + closed hat). hh_pedal is a foot and may coexist.

## 5. Ghost notes and linear playing

- Ghost = snare at 20-50 (digits 2, 3) between backbeats [7][8]. Placements from [16]: the "a" of beats 2 and 4 (cells 7 and 15), so the ghost leads into the kick on the next beat. Then the last grid=32 cell before that beat, then two grid=32 cells (a drag). Also used: the cell before or after a backbeat (3, 5, 11, 13) (unconfirmed).
- The left hand plays them, "using the left hand to fill in the gaps of a beat with ghost notes" [13]: never on a backbeat cell, best on cells with no kick, 2-5 per bar (count unconfirmed).
- Where: hat or ride sections in Periphery, TesseracT, Animals as Leaders type songs. Haake: ghost notes "just get lost in the mix and only the big hits come out" [3], so under china or crash riding raise them to 40-70 [20] (digits 3-5) or leave them out.
- Linear = no cell has two limbs. Check each column: at most one of kick, snare, hat or cymbal. The hat row has holes exactly where kick or snare play (P3 bar 2).
- Garstka splits riff accents between snare and kick because "you don't get dynamics with bass drums" [14], for example one snare then four kicks (Ka$cade intro) [14]. For a riff group of 5 onsets: snare 9 on the first, kick on the other 4. This lowers `lock` on purpose.
- Writing a linear bar: 1. kick on the riff onsets. 2. snare 9 on the backbeat cells. 3. hat at 84-112 on the remaining cells, loudest on beats (empty cells are allowed). 4. swap 2-3 hat cells next to backbeats for ghosts at 2 or 3.

## 6. Double kick vocabulary

| type | grid signature | velocity | use |
|---|---|---|---|
| steady sixteenths | grid=16, all 16 cells | right foot (even cells) harder than left [11], by 5-15, 105-127 | under sustained chords, choruses, tremolo riffs |
| thirty-second burst | grid=32, 2-8 adjacent cells | first note highest, then descending [11], 98-112 | last beat or half beat before a snare or crash, or wherever the riff does it |
| herta | grid=32, `xxx-x-` every 6 cells (3 sixteenths) | 112-127 | Bleed: "two 32nd notes coming in every 3rd 16th note", hands in half time eighths [6] |
| gallop | grid=16, `x-xx` per beat, reverse `xx-x` | 112-127 | galloped palm mutes |
| eighth triplets | grid=12, up to 3 cells per beat | 112-127 | triplet riffs, 12/8 type sections |
| sextuplets | grid=24, 6 adjacent cells per beat | 98-115 | runs of 1-2 beats under a steady hand pattern |

- The velocity numbers in this table are unconfirmed; only the shapes carry a source.
- Speed check: note spacing in ms = 60000 / bpm / notes per beat. Thirty-seconds at 115 bpm = sixteenths at 230 bpm = 65 ms [6]. Haake: comfortable at 140, awkward between 160 and 180 [1][2]. A whole section of kicks faster than 65 ms apart is beyond these sources: cut it into bursts (limit unconfirmed).
- The descending shape 84, 70, 59, 44 in [11] suits a natural kit. Modern metal kicks stay above 98: keep the shape, compress the range to 127, 112, 105, 98 (unconfirmed).
- Garstka: top speed = the speed where the sound stays even and powerful [14]. `humanize vel` above 8 on a fast kick run sounds like a weak player, not a human one (unconfirmed).

## 7. Tempo and subdivision

- File tempo 100-140 bpm with sixteenths is the centre. Riffs written at 145-155 are usually felt in half time, about 75 [17]. Reference points: Bleed 115 [6], Haake's comfort zone 140, obZen 170 [1][2]. Blast = sixteenths at 180-280 bpm [12], which in a 100-140 bpm file shows as grid=32.
- Grid by content: grid=16 default. grid=32 for bursts, herta, blasts. grid=12 or 24 when the riff is in triplets. A bar that `show` prints at grid=48 mixes thirty-seconds and triplets.
- Cell length: sixteenth = 15000 / bpm ms (125 ms at 120 bpm, 107 ms at 140). Ticks = ms x bpm x PPQ / 60000 (480 PPQ, 140 bpm: 5 ms = 5.6 ticks).
- Micro timing: guides use 85-95% quantize and nudges of "a few milliseconds" [7][8][9], or 2-5% randomisation [10]. Working values: hands plus or minus 2-5 ms, kick in unison parts 0-2 ms (ms values unconfirmed). Snare a few ms early = urgency, kick a few ms late = pocket [9].

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
| blast | feel blast | snare on every other cell, kick between them or on all cells |

## 9. Canonical patterns

Writing any bar: 1. kick = `# riff` onsets (unison) or a type from section 6. 2. snare per the feel table at 9. 3. one keeper from section 4; cell 0 of a section's first bar is crash1 9 + kick. 4. limb check per cell: at most 2 hand hits plus kick plus hh_pedal. 5. no hand lane with one digit for the whole bar except quarter cymbals, which alternate 9 and 8. 6. `humanize` hands vel=5-8 and 2-5 ms of ticks, kick vel=3 and 0-2 ms.

```vd
# P1 half time polymeter. China quarters and snare on 3 fixed, kick cycle of 7 sixteenths (9-98-9-) cut at the end of bar 2. Main riffs, Meshuggah type
bar 1 grid=16
crash1 49  |9--- ---- ---- ----|
china 52   |---- 8--- 9--- 8---|
snare 38   |---- ---- 9--- ----|
kick 36    |9-98 -9-9 -98- 9-9-|
bar 2 grid=16
china 52   |9--- 8--- 9--- 8---|
snare 38   |---- ---- 9--- ----|
kick 36    |98-9 -9-9 8-9- 9-98|
```

```vd
# P2 herta kick cycle at grid=32: 6 cells (989-9-) = 3 sixteenths, hands play half time eighths. Bleed type, about 115 bpm
bar 1 grid=32
crash1 49  |9--- 7--- 8--- 7--- 9--- 7--- 8--- 7---|
snare 38   |---- ---- ---- ---- 9--- ---- ---- ----|
kick 36    |989- 9-98 9-9- 989- 9-98 9-9- 989- 9-98|
```

```vd
# P3 bar 1: backbeat groove with ghost notes, closed hat eighths 112/98, ghosts at 28-42 on cells with no kick. Verses, clean and groove sections
# P3 bar 2: linear bar, exactly one limb per cell. Groove sections and transitions, Garstka and Halpern type
bar 1 grid=16
hh 42      |8-7- 8-7- 8-7- 8-7-|
snare 38   |---- 9--2 -3-- 9--2|
kick 36    |9--9 --9- --98 --9-|
bar 2 grid=16
hh 42      |-76- -7-- 8--6 --7-|
snare 38   |---- 9--2 ---- 93--|
kick 36    |9--9 --9- -98- ---9|
humanize bars=1-2 lanes=hat vel=6 time=3 seed=7
```

```vd
# P4 breakdown where the hands join the riff: crash + kick on 3+3+3+3+4 sixteenths, snare stays on 3, kick pickup on cells 14-15. Slow breakdowns
bar 1 grid=16
crash1 49  |9--9 --9- -9-- 9---|
snare 38   |---- ---- 9--- ----|
kick 36    |9--9 --9- -9-- 9-98|
```

```vd
# P5 chorus carpet: crash riding quarters, normal backbeat, steady sixteenth double kick with right foot 127 and left foot 112
bar 1 grid=16
crash1 49  |9--- 8--- 8--- 8---|
snare 38   |---- 9--- ---- 9---|
kick 36    |9898 9898 9898 9898|
```

```vd
# P6 gallop (9-98 per beat) under loose hat eighths, bar 2 is the reverse gallop (98-9). Used when the guitar gallops its palm mutes
bar 1 grid=16
hh_open 46 |9-7- 9-7- 9-7- 9-7-|
snare 38   |---- 9--- ---- 9---|
kick 36    |9-98 9-98 9-98 9-98|
bar 2 grid=16
hh_open 46 |9-7- 9-7- 9-7- 9-7-|
snare 38   |---- 9--- ---- 9---|
kick 36    |98-9 98-9 98-9 98-9|
```

```vd
# P7 triplet riffs. bar 1 grid=24 (6 cells per beat): eighth triplet kicks with sextuplet runs on beats 2 and 4. bar 2 grid=12 (3 cells per beat): triplet riff with rests
bar 1 grid=24
china 52   |9----- 8----- 9----- 8-----|
snare 38   |------ ------ 9----- ------|
kick 36    |9-9-9- 989898 9-9-9- 989898|
bar 2 grid=12
china 52   |9-- 8-- 9-- 8--|
snare 38   |--- --- 9-- ---|
kick 36    |99- 9-9 -99 9-9|
```

```vd
# P8 thirty-second kick burst on beat 4 (98 and 112, never 127 flat) resolving on crash + kick at the next downbeat
bar 1 grid=32
china 52   |9--- ---- 8--- ---- 9--- ---- 8--- ----|
snare 38   |---- ---- ---- ---- 9--- ---- ---- ----|
kick 36    |9--- 9-9- ---- 9--- ---- 9-9- 8787 8787|
bar 2 grid=16
crash1 49  |9--- ---- ---- ----|
kick 36    |9--- ---- ---- ----|
```

```vd
# P9 fast feels. bar 1 double time (snare on the offbeat eighths). bar 2 traditional blast (kick + cymbal together, snare between) [12]
# P9 bar 3: bomb blast (kick sixteenths, snare + cymbal on eighths) [12]. Blast snare at 112, not 127. At 100-140 bpm write blasts at grid=32
bar 1 grid=16
crash1 49  |9--- 8--- 8--- 8---|
snare 38   |--9- --9- --9- --9-|
kick 36    |9--- 9--- 9--- 9---|
bar 2 grid=16
ride 51    |8-7- 8-7- 8-7- 8-7-|
snare 38   |-8-8 -8-8 -8-8 -8-8|
kick 36    |8-8- 8-8- 8-8- 8-8-|
bar 3 grid=16
china 52   |9-8- 8-8- 8-8- 8-8-|
snare 38   |8-8- 8-8- 8-8- 8-8-|
kick 36    |8787 8787 8787 8787|
```

```vd
# P10 two handed sixteenth hat verse (no hat on the backbeat cells 4 and 12), written flat, then shaped: beat 112, e 70, and 98, a 84, last eighth opened
bar 1 grid=16
hh 42      |8888 -888 8888 -8--|
hh_open 46 |---- ---- ---- --8-|
snare 38   |---- 9--- ---- 9---|
kick 36    |9--- --9- -9-- ----|
accent bars=1 lanes=42 grid=16 pattern=8576
humanize bars=1 lanes=hat vel=5 time=2 seed=3
```

## 10. What makes it sound programmed or wrong

1. Hand lanes with sd near 0: hats, ride, ghosts, toms at one velocity. Hats need at least the 110/95 alternation [7] plus 5-10 of random spread [20].
2. Everything at 127. Guides put normal hits at 110-120 and keep 127 for breakdown backbeats and accents [10][8].
3. Kick that ignores the riff: lock under 80% in a section that is plainly a unison chug [1][4].
4. Polymeter flattened: one kick bar copied over the others where the riff cycle crosses the barline, or a cymbal anchor that drifts with the kick so the 4/4 pulse disappears [4][13].
5. Impossible limbs: three hand hits on one cell, a keeper cymbal that continues through a two hand tom or snare run, china and closed hat on the same cell [10].
6. One handed sixteenth hats above about 120 bpm with snare hits on hat cells. Two handed sixteenths leave the backbeat cells without a hat (P10) (bpm unconfirmed).
7. Ghost notes at 60-90: they read as weak backbeats. Ghosts stacked on kick cells in every bar: mud (unconfirmed).
8. Blast snares or thirty-second kick runs at 127 flat. Blast snare 105-115 [8], burst kicks 98-112.
9. Random timing above plus or minus 2 ms on the kick in unison parts: flams against the guitar. Zero timing spread on the hands for a whole song: stiff [8][9] (ms values unconfirmed).
10. Strong and weak side identical in fast runs. Lower the weak hand or foot by 5-25 [10][11].
11. Section change with no crash + kick on cell 0, or a crash with no kick under it (unconfirmed, practice).
12. Sixteenth carpet under a clean or ambient part, or blast as the default groove (unconfirmed, practice).
13. Keeper lane switching inside a phrase with no section change or fill (unconfirmed, practice).

## Sources

1. DRUM! Magazine, Tomas Haake: Meshuggah's Djentle Giant. https://drummagazine.com/tomas-haake-meshuggahs-djentle-giant/
2. DRUM! Magazine, Tomas Haake: Meshuggah Goes It Alone. https://drummagazine.com/tomas-haake-meshuggah-goes-it-alone/
3. Modern Drummer, web exclusive interview with Tomas Haake (2013). https://www.moderndrummer.com/2013/06/web-exclusive-interview-with-meshuggahs-tomas-haake/
4. Jonathan Pieslak, Re-casting Metal: Rhythm and Meter in the Music of Meshuggah. https://pdfcoffee.com/re-casting-metal-rhythm-and-meter-in-the-music-of-meshuggah-pdf-free.html
5. Wikipedia, Meshuggah (musical style). https://en.wikipedia.org/wiki/Meshuggah
6. San Diego Modern Drum Lessons, Analyzing Bleed by Meshuggah. http://sandiegomoderndrumlessons.blogspot.com/2014/01/analyzing-bleed-by-meshuggah.html and https://forum.troygrady.com/t/meshuggah-bleed-pattern/48849
7. Nail The Mix, modern metal drum programming FAQs. https://www.nailthemix.com/drum-programming-faqs
8. Nail The Mix, GetGood Drums Invasion guide. https://www.nailthemix.com/getgood-drums-the-invasion
9. Nail The Mix, GetGood Drums Matt Halpern library guide. https://www.nailthemix.com/getgood-drums-matt-halpern-drums-library
10. URM Academy, 5 drum programming tips for maximum realism. https://urm.academy/5-drum-programming-tips-for-maximum-realism/
11. KVR Audio forum, programming metal double kick patterns. https://www.kvraudio.com/forum/viewtopic.php?t=251747
12. Wikipedia, Blast beat. https://en.wikipedia.org/wiki/Blast_beat
13. Jay Postones interviews, search excerpts only (page fetch failed). http://mikedolbear.com/interviews/jay-postones/ and https://ghostcultmag.com/interview-jay-postones-tesseract-polaris/
14. DRUM! Magazine, Matt Garstka: Let's Get Technical. https://drummagazine.com/matt-garstka-lets-get-technical/
15. Metal in Theory, Metric Complexity in Car Bomb's Lights Out. https://metalintheory.com/car-bomb-lights-out/
16. DRUM! Magazine, lesson: ghost note style and placement. https://drummagazine.com/lesson-ghost-note-style-and-placement/
17. Tempo ranges, search excerpts only. https://sevenstring.org/threads/the-perfect-djent-tempo.182690/ and https://www.melodigging.com/genre/djent
18. Gear Gods, Matt Halpern signature stack, search excerpt only. https://geargods.net/news/periphery-matt-halpern-double-down/
19. China cymbal role, search excerpts only. https://drumhelper.com/cymbals/best-china-cymbal/ and https://en.wikipedia.org/wiki/China_cymbal
20. Nail The Mix Toontrack guides, search excerpts only. https://www.nailthemix.com/toontrack-metal-machinery-sdx
21. Hack Music Theory, How to Make Djent Beats, search excerpt only. https://www.goodreads.com/author_blog_posts/22597465-how-to-make-djent-beats
