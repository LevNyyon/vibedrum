# Fills: djent and progressive metalcore

Units: beats are quarter notes (1 to 5 in 4/4), cells are counted at the stated grid, velocity is 1 to 127 (grid digit x 14, 9 = 127). The examples share one groove: china on every beat (the keeper), snare on 3 (`feel` half), kick on 1, 1.5, 2.5, 3.5 and 4. Recipes are written for the span `bars=4 beats=3-5`: substitute the confirmed span you are editing. Tick math assumes 140 bpm.

## 1. What a fill is in the grid

A fill is a span of 0.5 to 8 beats (usual: 1, 2 or 4) that ends at a phrase boundary and shows at least two of these signs:

1. Keeper drop: the section's `keeper` lane has no hits in the span, or fewer than in the same beats one bar earlier. Both hands left the cymbal.
2. Hand departure: any `tom` hit, or snare hits at digit 6 or higher on cells that are not the backbeat of the section `feel` (normal: beats 2 and 4, half: beat 3), at least twice the snare count of the same beats one bar earlier.
3. Kick departure: kick cells differ from the same beats one bar earlier: a run of 3 or more consecutive cells, or the kick removed.
4. Landing: beat 1 of the next bar has a `cym` hit (crash1, crash2, china) at digit 8 or 9 on the same cell as a kick at digit 8 or 9, and the groove resumes there.

The timekeeping pattern resumes right after a fill, and fills vary from one occurrence to the next. If the pattern does not resume, the span is a new section. If the `# riff` row is also empty across the span it is a break (the band stops): edit it like a fill but never pave it over.

## 2. Checking the engine's candidates

`# fills: 8:3-5 16:1-5` and the bar comment `fill=3-5` are guesses. Show the bar with its neighbours (`--bars 7-9`). Confirm a span when all three hold: (a) it ends within 2 sixteenth cells of a bar line, and that bar is the last of a 4 bar group counted from the section start or the last bar of the section; (b) sign 1 or sign 2 holds, and sign 4 holds or the next bar starts a new section in `# sections`; (c) its cells differ from the same beats one bar earlier.

Reject when any of these holds:
- Tom groove: the same tom cells appear in 3 of the 4 previous bars, or the bar prints as `# bar N = bar N-1`. That is timekeeping.
- `feel` is `blast` or `double` and the span holds only snare and kick at steady digits while the keeper keeps running.
- Ghost notes: every extra snare hit is digit 1 to 4 and the keeper continues. Ghost notes between accents are groove texture in this style (Haake, Postones).
- Riff accents: tom or snare hits sit only on `# riff` onsets, the keeper continues and the figure recurs every bar or every riff cycle. Haake plays toms on the guitar hits together with the kick as part of the groove, not as a fill on top.
- The span sits in beats 1 to 2 of the first bar of a section: it is the tail of a landing.

Fix the edges before editing. Start: the first cell where the keeper goes missing, or the first tom or off backbeat snare, rounded down to a half beat. End: the last cell before the landing.

The candidates miss the fill types below. Scan the last bar of every 4 bar group for them yourself. A stop or a silent gap is a finished fill: for "busier" or "heavier" add at most one pickup hit before the landing and leave the silence.

| type | what the grid shows |
|---|---|
| kick only fill | keeper and snare rows empty (or one held crash), kick has 4 or more consecutive cells at 16ths, sextuplets or 32nds in the last 1 to 2 beats |
| choke or stop | one cell with cym + kick (+ snare) at digit 9, then all rows `-` for 1 to 4 beats up to the bar line. The choke itself is not a lane: it shows as an unmapped `p<pitch>` row or not at all (unconfirmed) |
| unison stabs | 2 to 5 cells where kick + snare or kick + cym coincide with `# riff` onsets, all rows empty between them, keeper absent |
| silent gap | every row `-` for the last 2 to 4 beats (or the whole bar) before a section start, often with an empty `# riff` row |
| snare flam | a digit 2 to 6 one cell before a 9 on the same lane, in a bar printed at grid=32 or 48 while its neighbours print at 16 (unconfirmed how `show` renders offsets smaller than a cell) |
| short pickup | 1 to 3 hits (snare, tom or kick) inside beats 4.5-5 with the keeper still present |

## 3. Where fills go and how long

Phrase grid: take the section bar ranges from `# sections` and cut each into 4 bar groups from its first bar. A riff reset (the `# riff` row equal to the section's first bar again) confirms a group start. Fill slots are the last bar of each group. Fills belong at the end of 4 or 8 bar phrases, the bigger ones every 8 or 16 bars, and their length signals the size of the change: 1 to 2 beats relaunch a phrase, a full bar marks a section change, more than a bar marks a major transition.

| slot | length | selector | content |
|---|---|---|---|
| end of bar 4 inside an 8 bar phrase | 0 to 1 beat | `beats=4.5-5` or `beats=4` | pickup, keeper may stay, 1 to 4 notes (L1, L2) |
| end of an 8 bar phrase, section continues | 2 beats | `beats=3-5` | L2 to L4 |
| last bar of a section, next section of equal weight | 2 to 4 beats | `beats=3-5` or `beats=1-5` | L3 to L5 |
| into a chorus, the heaviest riff or a breakdown | 4 beats, 8 beats (2 bars) at most once per song | `beats=1-5` | L5, L6, snare roll crescendo, or stab plus silent gap |
| into a quieter section | 0 to 2 beats | `beats=3-5` | velocities falling 120 to 80, landing crash kept at digit 6 to 7 |

- At most one fill per 4 bars. Default plan for a 16 bar section: bar 4 nothing or half a beat, bar 8 two beats, bar 12 one beat, bar 16 four beats. Size grows toward the section end (unconfirmed as a djent specific rule).
- No two fills in one section cell identical. If a fill bar prints as `# bar 16 = bar 8`, change one of them.
- Sections with `lock` of 0.8 or more and a quarter note china or crash keeper (Meshuggah type): no fills inside. At the section end use unison hits on riff onsets (vocabulary 7). Haake plays far fewer stand alone fills than other extreme metal drummers.
- Subdivision by tempo: notes per second = bpm x G / 240. Hands alone stay under about 14 per second (rule of thumb, unconfirmed): 16ths up to 210 bpm, sextuplets (grid=24) up to 140, 32nds up to 105. Above that use hand and foot patterns (vocabulary 2, 3) or bursts of at most 4 cells.
- Grid caution: write a bar block at a grid that holds every existing onset of the rows you write. Sextuplet fill after a 16th note kick pattern in the same bar: write the kick row at grid=48 (48 cells in 4/4, a 16th is 3 cells, a sextuplet is 2).

## 4. Vocabulary

Limb rule for everything below: at most 2 hand lanes per cell (snare, toms, hats and cymbals are all hands) plus kick. While both hands are on drums the keeper has no hits.

| # | figure | grid shape |
|---|---|---|
| 1 | descending tom run | 16ths, 2 notes per drum: snare, tom1, tom3, tom5 (L3). Skip tom1 for a darker run. Programmers build it by moving snare hits onto tom lanes while the hits on the beats stay on the snare |
| 2 | linear sextuplet | grid=24, per beat 4 hand cells then 2 kick cells (R L R L K K), hands walking down the drums (L4). Also 4 note (R L R K) and 5 note (R L R L K) groups chained: 3 + 4 + 5 cells = 2 beats |
| 3 | quads | 2 hand cells then 2 kick cells (R L K K) at grid=16 or 32 (bar 2 below). Halpern builds such fills from paradiddle stickings split between hands and feet (details unconfirmed) |
| 4 | kick doubled toms | every snare or tom cell has a kick on the same cell: hands on 8ths, feet on 16ths (L5) |
| 5 | flam | grace note 15 to 30 ms before a main hit, on the last 1 or 2 hits or on every slam, also between two toms (section 5) |
| 6 | snare roll crescendo | snare on every cell for 2 to 4 beats (16ths above 150 bpm, 32nds below 105), `ramp from=60 to=127`, kick on the beats, keeper row cleared (L2 is the one beat form) |
| 7 | unison stabs | kick + snare + cym, or kick + snare + floor tom, on one cell, placed on `# riff` onsets, nothing or only kick between (bar 3 below, L6) |
| 8 | thirty-second burst | 4 to 8 cells at grid=32 on one drum in the last half beat or beat (recipe "busier") |
| 9 | china punctuation | china (52) + kick on a syncopated cell inside the fill instead of a tom hit. The built in map has no stack lane: use china or splash (55) unless a custom map defines `stack*` |
| 10 | kick only, stop, gap | hands rest or hold one crash while the kick runs into the downbeat (bar 1 below). Stop: a stab, then silence to the bar line (bar 3 below) |

```vd
# bar 1, kick only: crash and snare on 3, then the feet run 16ths into the downbeat
bar 1 grid=16
crash1 49  |---- ---- 9--- ----|
snare 38   |---- ---- 9--- ----|
kick 36    |9-9- --9- -888 8899|
# bar 2, quads over beats 3 and 4: snare, floor tom, kick, kick
bar 2 grid=16
snare 38   |---- ---- 9--- 9---|
tom5 43    |---- ---- -8-- -8--|
kick 36    |9-9- --9- --88 --88|
# bar 3, unison stabs on 3 and 3.75 (kick + snare + china), then beat 4 silent
bar 3 grid=16
china 52   |9--- 9--- 9--9 ----|
snare 38   |---- ---- 9--9 ----|
kick 36    |9-9- --9- 9--9 ----|
```

## 5. Velocity and timing inside a fill

- Accents are digit 9 (119 to 127). Metal backbeats are programmed at 115 to 127 and the hardest hits are rimshot samples. Other fill notes sit at 105 to 118 (digit 8): 110 to 120 sounds closer to a real hard hit than constant 127. Ghost or drag notes inside a fill: 20 to 50.
- Leading hand: in 16th and 32nd runs the weaker hand is 5 to 25 lower. Odd cells are the leading hand: `accent ... grid=16 pattern=98`. R L R L K K sextuplets: hands 9 7 8 7.
- Per drum: the first hit on each new drum is the strongest and the next ones fall (120, 115, 110). Fast runs fade on the floor tom, except when the request is "heavier": then the last low notes are 127.
- Speed: above 12 notes per second on one drum pull the whole run down to 100 to 115 (threshold unconfirmed).
- Crescendo: `ramp from=60 to=127` over a snare roll (start value unconfirmed, a concert roll starts near 1). The last note before the landing is the loudest of the fill. Into a quiet section invert it: `ramp from=120 to=80`.
- Kick under a fill: 105 to 120, flat. In kick runs the weaker foot is 2 to 15 lower.
- Flam: grace note 6 to 30 ms before the main note and quieter. Heavy flam: 15 to 25 ms, grace at 84 to 104. Classic flam: grace at 35 to 60. Above 40 ms it reads as two notes (these three number sets are unconfirmed). ms = ticks x 60000 / (bpm x ppq): at 480 ppq (assumed) and 140 bpm one tick is 0.89 ms and one 32nd cell is 60 ticks.
- Feel: toms 4 to 10 ticks late (`shift ... lanes=tom ticks=6`) drag into a section, a snare run 3 to 6 ticks early adds urgency (tick amounts unconfirmed). Keep the kick on the grid when `lock` is 0.7 or more. Finish with `humanize ... vel=5 time=3`. A tom lane with `sd` near 0 in `# lanes` needs the accent and per drum shapes above.

```vd
# same lane flam: write the grace one 32nd cell (60 ticks) early, then move it 32 ticks later, 28 ticks (25 ms) before the main hit
bar 6 grid=32
snare 38   |---- ---- ---- ---- 9--3 9--- ---- ----|
tom4 45    |---- ---- ---- ---- ---- ---- 8--- 8---|
tom5 43    |---- ---- ---- ---- ---- ---- 9--- 9---|
kick 36    |---- ---- ---- ---- 9--- 9--- 9--- 9---|
shift bars=6 beats=3-4 lanes=snare v=35-48 ticks=32
# two drum flam (tom slam): both toms on one cell, the higher one 25 ticks early, kick stays centred
shift bars=6 beats=4-5 lanes=tom4 ticks=-25
```

## 6. The landing and the bar after

- Beat 1 of the next bar: crash1 or crash2 at 127 and kick at 127 on the same cell. If the new section's keeper is china or a ridden crash, the landing is its first hit at digit 9 and the rest of the keeper stays at 7 to 8.
- The crash replaces the keeper hit on that cell: hat or ride cell 1 becomes `-`, the keeper resumes on its next cell.
- Heavier landing: crash1 + china (or crash1 + crash2) + kick, all 127. Both hands are on cymbals, so no snare on that cell.
- Pushed landing (unconfirmed, common practice): if `# riff` has an onset on the last 8th or 16th of the fill bar and none on the next beat 1, add crash + kick on that cell. The crash on the next beat 1 stays unless he asks to remove it.
- The bar after is the plain groove from beat 2 at the latest: no leftover toms or extra snares in beats 1 to 2, ghost notes return from beat 2. Write it as a full bar block. Do not mix `copy` and a bar block for the same bar and lane in one script: FORMAT.md does not state which runs first.
- Into a quiet section: keep the crash but soften it, crash at 84 to 98 with kick at 100.

```vd
# bar after a fill in bar 4: crash + kick on 1, china keeper back on beat 2, groove intact
bar 5 grid=16
crash1 49  |9--- ---- ---- ----|
china 52   |---- 9--- 9--- 9---|
snare 38   |---- ---- 9--- ----|
kick 36    |9-9- --9- --9- 9---|
```

## 7. Intensity ladder for one slot

One slot, `bars=4 beats=3-5`, six versions from lightest to heaviest. Beats 1 to 2 are the unchanged groove. On a real song write only the rows you change, and always write the keeper row so its cells in the span are cleared.

L1 pickup. Keeper stays, two snare 16ths at 4.5 and 4.75 (98, 127).
```vd
bar 4 grid=16
china 52   |9--- 9--- 9--- 9---|
snare 38   |---- ---- 9--- --79|
kick 36    |9-9- --9- --9- 9---|
```
L2 snare build. Keeper leaves beat 4, four snare 16ths rising 70, 84, 112, 127.
```vd
bar 4 grid=16
china 52   |9--- 9--- 9--- ----|
snare 38   |---- ---- 9--- 5689|
kick 36    |9-9- --9- --9- 9---|
```
L3 tom run. Keeper leaves beats 3 and 4, two 16ths per drum going down, leading hand 127, other hand 112, kick on the beats.
```vd
bar 4 grid=16
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 98-- ----|
tom1 50    |---- ---- --98 ----|
tom3 47    |---- ---- ---- 98--|
tom5 43    |---- ---- ---- --98|
kick 36    |9-9- --9- 9--- 9---|
```
L4 linear sextuplets, the busiest. Per beat four hand cells then two kick cells, 12 notes in 2 beats.
```vd
bar 4 grid=24
china 52   |9----- 9----- ------ ------|
snare 38   |------ ------ 97---- ------|
tom1 50    |------ ------ --87-- ------|
tom3 47    |------ ------ ------ 97----|
tom5 43    |------ ------ ------ --87--|
kick 36    |9--9-- ---9-- ----88 ----88|
```
L5 kick doubled low toms. Hands on 8ths only, low drums, 16th kicks under every hit, both floor toms on the last hit.
```vd
bar 4 grid=16
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 9--- ----|
tom4 45    |---- ---- --9- ----|
tom5 43    |---- ---- ---- 9-9-|
tom6 41    |---- ---- ---- --9-|
kick 36    |9-9- --9- 9898 9898|
```
L6 unison slams, the heaviest. Snare + floor tom + kick on beats 3, 3.75 and 4.5 (3-3-2 cells), 16th kicks between. On a real song move the three slam cells onto `# riff` onsets.
```vd
bar 4 grid=16
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 9--9 --9-|
tom5 43    |---- ---- 9--9 --9-|
kick 36    |9-9- --9- 9889 8898|
```

## 8. Heavier is not busier

Hand cells in the fill: L1 2, L2 4, L3 8, L4 8 plus 4 kick cells, L5 4, L6 3. Density peaks at L4, weight keeps rising to L6. The two requests move different controls:

| control | heavier | busier |
|---|---|---|
| hand notes in the span | same or fewer: 8ths, 3-3-2 slams | more: 16ths, then sextuplets, then 32nds |
| drums | lower: tom4, tom5, tom6 plus snare, both hands on one cell | any, usually more drums, single strokes |
| kick | on every hand cell, or 16ths under the hands | only in the gaps between hand notes (linear) |
| velocity | hands and kick 118 to 127, no ghosts, flams on the big hits | accents kept, added notes at 84 to 104 |
| relation to the riff | hits moved onto `# riff` onsets, china + kick stabs, two cymbal landing | independent of the riff |
| grid | 16 or coarser | 24 or 32 |

## 9. Recipes

Swap `bars=4 beats=3-5` for `fills` (optionally with `bars=`) only when every span in `# fills` is confirmed and none is missing. Adding notes needs a bar block, the bulk ops only change or remove notes. Put bar blocks before ops.

**Heavier.** Stop when it is enough: (1) lower every tom, lowest lane first so no note is remapped twice; (2) kick on every hand cell or 16ths under; (3) snare, toms and kick to 118 or more, ghosts (`v=1-62`) deleted; (4) flam the last hit (section 5); (5) move hits onto `# riff` onsets; (6) crash1 + china landing; (7) still not enough: fewer and bigger notes, replace the span with L5 or L6. Never move to a finer grid for this request.
```vd
bar 4 grid=16
kick 36    |9-9- --9- 9999 9999|
remap bars=4 beats=3-5 lanes=tom5 to=tom6
remap bars=4 beats=3-5 lanes=tom3 to=tom5
remap bars=4 beats=3-5 lanes=tom1 to=tom4
vel bars=4 beats=3-5 lanes=snare,tom,kick min=118
```
**Lighter.** Kick only on the beats, toms up two lanes (highest lane first), 85 percent velocity capped at 110, landing crash down to 105. Or step down one ladder level. The keeper may return in the first half of the span (write its row).
```vd
delete bars=4 beats=3.25-4 lanes=kick
delete bars=4 beats=4.25-5 lanes=kick
remap bars=4 beats=3-5 lanes=tom4 to=tom2
remap bars=4 beats=3-5 lanes=tom5 to=tom3
remap bars=4 beats=3-5 lanes=tom6 to=tom4
vel bars=4 beats=3-5 lanes=snare,tom scale=0.85 max=110
```
**Busier.** Keep the accent cells and their digits. Fill the empty cells of the span: a kick where the neighbours are hand notes, else a hand note on the drum of the previous hand note at digit 6 to 7. Span already full at grid=16: rewrite it as L4 at grid=24, or turn the last half beat into a 32nd burst and add 8th note kicks, as below on L3. Check the tempo cap. Do not lower drums or raise velocities.
```vd
bar 4 grid=32
tom5 43    |---- ---- ---- ---- ---- ---- ---- 9788|
kick 36    |9--- 9--- ---- 9--- 9--- 9--- 9--- 9---|
```
**Simpler.** Delete ghosts and graces, keep only the 8th note cells, use at most two drums. Or step down one ladder level.
```vd
delete bars=4 beats=3-5 lanes=snare,tom v=1-62
delete bars=4 beats=3.25-3.5
delete bars=4 beats=3.75-4
delete bars=4 beats=4.25-4.5
delete bars=4 beats=4.75-5
remap bars=4 beats=3-4 lanes=tom to=snare
remap bars=4 beats=4-5 lanes=tom to=tom5
```
**Longer.** Double the span backwards (1 to 2 beats, 2 to 4 beats, 4 beats to 2 bars). The old fill stays as the tail. The new front half gets half the density and at least 15 less velocity so the fill accelerates, and the keeper is cleared there. For 2 bars put an L1 or L2 in the previous bar. Below: L3 extended to the whole bar.
```vd
bar 4 grid=16
china 52   |9--- ---- ---- ----|
snare 38   |--7- 7-7- 98-- ----|
kick 36    |9-9- 9-9- 9--- 9---|
ramp bars=4 beats=1-3 lanes=snare from=84 to=110
```
**Shorter.** Keep the tail and restore the groove in the front of the span. Never keep the front and cut the tail: the tail carries the landing. Below: L3 cut to beat 4.
```vd
bar 4 grid=16
china 52   |9--- 9--- 9--- ----|
snare 38   |---- ---- 9--- ----|
kick 36    |9-9- --9- --9- 9---|
delete bars=4 beats=3-4 lanes=tom
```
**More interesting.** Change one thing at a time: (1) regroup the accents as 3-3-2; (2) accents on a low drum, filler on the snare; (3) linear ending: the last two hand notes become kicks; (4) a hole: delete one unaccented cell; (5) start on the weak hand so the accent falls on cell 2 or 3 and on an unexpected drum (Haake); (6) hits only on `# riff` onsets; (7) china + kick in place of one tom hit. Below: 1 and 2 on L3, with a kick under each accent.
```vd
bar 4 grid=16
kick 36    |9-9- --9- 9--9 --9-|
accent bars=4 beats=3-5 lanes=snare,tom grid=16 pattern=96696696
remap bars=4 beats=3-5 lanes=snare,tom v=119-127 to=tom5
remap bars=4 beats=3-5 lanes=tom1,tom3 v=1-118 to=snare
```
**More tom.** Move the fill's snare notes onto toms by position, high to low. For more crack leave the snare on the beat cells and move only the cells between. Use only tom lanes with a count above 0 in `# lanes`: other pitches may be silent in the user's kit (unconfirmed caution).
```vd
bar 4 grid=16
snare 38   |---- ---- 9898 9898|
remap bars=4 beats=3.5-4 lanes=snare to=tom1
remap bars=4 beats=4-4.5 lanes=snare to=tom3
remap bars=4 beats=4.5-5 lanes=snare to=tom5
```
**Less cheesy.** Cheesy in the grid: a full bar of 16ths, 4 notes per drum from snare down through tom1, flat velocity, no kick under it, repeated every 4 bars. Fix: cut it to the last 2 beats, drop tom1, two drums at most, last two hand notes become kicks, shaped velocity, and rewrite every second such fill in the section as the plain groove. The block writes the stock fill (with the kick row of the fix), then fixes it.
```vd
bar 8 grid=16
snare 38   |8888 ---- ---- ----|
tom1 50    |---- 8888 ---- ----|
tom3 47    |---- ---- 8888 ----|
tom5 43    |---- ---- ---- 8888|
kick 36    |9-9- --9- 9-9- 9-99|
delete bars=8 beats=1-3 lanes=snare,tom
delete bars=8 beats=4.5-5 lanes=tom
remap bars=8 beats=3-4 lanes=tom3 to=tom4
accent bars=8 beats=3-5 lanes=tom grid=16 pattern=9787
```

## Sources and unconfirmed items

Unconfirmed (working numbers of this document, or sources seen only as search snippets): the detection thresholds in sections 1 and 2 and the `lock` cutoffs 0.7 and 0.8; the 14 notes per second hand cap, the 12 per second velocity threshold and the tempo limits derived from them; the 16 bar fill plan; heavy and classic flam velocities and the 40 ms limit; the ramp start of 60; shift amounts in ticks; the pushed landing; 480 ppq; how `show` prints flams and chokes; whether unused tom pitches sound in a given kit; the content of Halpern's paradiddle lesson, of the MusicRadar and Computer Music fill articles and of the Postones interview (page bodies not retrievable).

- Haake on fills, toms on the guitar hits with the kick, rimshots, ghost notes, weak hand starts: https://drummagazine.com/tomas-haake-meshuggahs-djentle-giant/ , https://www.moderndrummer.com/2013/06/web-exclusive-interview-with-meshuggahs-tomas-haake/ , https://www.drumeo.com/beat/meshuggah-tomas-haake-genius/ , https://asiwalkintothesettingsun.substack.com/p/clockworks-by-meshuggah-drumming
- Fill definition, placement, length, landing: https://en.wikipedia.org/wiki/Fill_(music) , https://musichub.maurisson.com/en/guide/fills-et-breaks-a-la-batterie/ , https://www.musicradar.com/tuition/tech/learn-how-drum-fills-work-in-5-easy-steps-639154 (snippet), https://www.pressreader.com/australia/computer-music/20160518/281526520271381 (snippet)
- Limb limits, flam timing, roll crescendo, dragged tom fills: https://www.soundonsound.com/techniques/making-midi-sequencing-more-realistic-part-2-drum-parts , https://audient.com/tutorial/programming-realistic-drums/
- Weaker hand and foot, velocity ceiling, tom slams: https://urm.academy/5-drum-programming-tips-for-maximum-realism/ , https://www.drumaudioediting.com/post/how-to-program-drums-so-that-they-sound-and-feel-human
- Velocity ranges for metal libraries (Toontrack, GetGood Drums): https://www.toontrack.com/blog/how-to-program-drums/ , https://www.nailthemix.com/drum-programming-faqs , https://www.nailthemix.com/toontrack-metal-mania-ezx , https://www.nailthemix.com/getgood-drums-matt-halpern-drums-library , https://www.nailthemix.com/getgood-drums-the-invasion
- Hand and foot vocabulary (quads, 4, 5 and 6 note groups, double bass fills): https://www.drumstheword.com/free-drum-lesson-quads-four-note-linear-hand-and-foot-combinations-licks-grooves-and-ideas/ , https://mixdownmag.com.au/features/columns/6-hand-foot-combinations-to-improve-your-drumming-skills/ , https://www.drumlessons.com/drum-lessons/bass-drum-lessons/intermediate-double-bass-drum-fills/
- Halpern and Postones (snippet level): https://www.musicradar.com/tuition/drums/matt-halpen-guest-lesson-fills-using-paradiddles-with-hands-and-feet-580337 , https://www.scribd.com/doc/218944485/Interview-with-Jay-Postones-TesseracT-by-Sina-Najaflou
