# Fills: djent and progressive metalcore

Units: beats are quarter notes (1 to 5 in 4/4), cells are counted at the stated grid, velocity is 1 to 127 (grid digit x 14, 9 = 127). The examples share one groove: china on every beat (the keeper), snare on 3 (`feel` half), kick on 1, 1.5, 2.5, 3.5 and 4. Recipes are written for the span `bars=4 beats=3-5`: substitute the confirmed span you are editing. Tick math assumes 140 bpm and 480 ppq: read the real values from the `show` header (`ppq` in its first line, `# tempo:`).

## 1. What a fill is in the grid

A fill is a span of 0.5 to 8 beats (usual: 1, 2 or 4) that ends at a phrase boundary and shows at least two of these signs:

1. Keeper drop: the section's `keeper` lane has no hits in the span, or fewer than in the same beats one bar earlier. Both hands left the cymbal.
2. Hand departure: any `tom` hit, or snare hits at digit 6 or higher on cells that are not the backbeat of the section `feel` (normal: beats 2 and 4, half: beat 3) and that are empty in the same beats one bar earlier.
3. Kick departure: a run of 3 or more consecutive kick cells that neither repeats the bar before nor sits on `# riff` onsets, or the kick silent where the bar before had kicks. A kick row that changes every bar but follows `# riff` is a polymetric groove, not a sign.
4. Landing: beat 1 of the next bar has a `cym` hit (crash1, crash2, china) at digit 8 or 9 on the same cell as a kick at digit 8 or 9, and the groove resumes there.

The timekeeping pattern resumes right after a fill, and fills vary from one occurrence to the next. A departure that lasts more than 2 bars, or that repeats bar after bar, is a section (tom groove, build), not a fill. If the `# riff` row is also empty across the span it is a break (the band stops): edit it like a fill, but cells that are silent in every row stay silent.

## 2. Checking the engine's candidates

`# fills: 8:3-5 16:1-5` and the bar comment `fill=3-5` are guesses made beat by beat: inside each section a beat is flagged when it holds more tom hits than the section's median for that beat, or at least 2 more snare hits than the median. Velocity, kick, cymbals and `# riff` are ignored. Spans are whole beats inside one bar: a fill on 4.5 to 5 prints as `4-5`, a 2 bar fill as two spans (`7:3-5 8:1-5`). Show the bar with its neighbours (`--bars 7-9`). Confirm a span when all three hold: (a) it ends within 2 sixteenth cells of a bar line, and that bar is the last of a 2 or 4 bar group counted from the section start or the last bar of the section; (b) sign 1 or sign 2 holds, and sign 4 holds or the next bar starts a new section in `# sections`; (c) its cells differ from the same beats one bar earlier.

Reject when any of these holds:
- Tom groove: the same tom cells appear in 3 of the 4 previous bars, or the bar prints as `# bar N = bar N-1`. That is timekeeping. The engine flags it whenever the toms play in half or fewer of the section's bars, and flags every tom in a section shorter than 3 bars.
- `feel` is `blast` or `double` and the span holds only snare and kick at steady digits while the keeper keeps running.
- Ghost notes: every extra snare hit is digit 1 to 4 and the keeper continues (2 extra ghosts in one beat are enough to flag it). Ghost notes between accents are groove texture in this style (Haake, Postones).
- Riff accents: tom or snare hits sit only on `# riff` onsets, the keeper continues and the figure recurs every bar or every riff cycle. Haake plays toms on the guitar hits together with the kick as part of the groove, not as a fill on top.
- The span sits in beats 1 to 2 of the first bar of a section: it is the tail of a landing.

Fix the edges before editing: the engine's edges are whole beats. Start: the first cell where the keeper goes missing, or the first tom or off backbeat snare, rounded down to a half beat. End: the last cell before the landing. The candidates miss the fill types below. Scan the last bar of every 4 bar group for them yourself. A stop or a silent gap is a finished fill: for "busier" or "heavier" add at most one pickup hit before the landing and leave the silence.

| type | what the grid shows |
|---|---|
| kick only fill | keeper and snare rows empty (or one held crash), kick has 4 or more consecutive cells at 16ths, sextuplets or 32nds in the last 1 to 2 beats |
| choke or stop | one cell with cym + kick (+ snare) at digit 9, then all rows `-` for 1 to 4 beats up to the bar line. A choke key prints as a `p<pitch>` row and in `# unmapped:`, an aftertouch choke is not a note and prints nowhere |
| unison stabs | 2 to 5 cells where kick + snare or kick + cym coincide with `# riff` onsets, all rows empty between them, keeper absent (one snare per beat stays under the engine's threshold) |
| silent gap | every row `-` for the last 2 to 4 beats (or the whole bar) before a section start, often with an empty `# riff` row |
| snare flam | two hits on one lane less than a cell apart. Closer than ppq/24 ticks (20 ticks at 480 ppq, 18 ms at 140 bpm) they print as one cell showing the louder hit. Wider, the bar prints at grid=32 or 48 while its neighbours print at 16, with a lower digit one cell before a 9. A flam on a backbeat adds one snare hit, below the threshold |
| short pickup | 1 snare hit, or 1 to 3 kick hits, inside beats 4.5-5 with the keeper still present (2 snare hits or any tom are flagged) |

## 3. Where fills go and how long

Phrase grid: take the section bar ranges from `# sections` and cut each into 4 bar groups from its first bar. A riff reset (the `# riff` row equal to the section's first bar again) confirms a group start. Fill slots are the last bar of each group. Fills belong at the end of 4 or 8 bar phrases, the bigger ones every 8 or 16 bars, and their length signals the size of the change: 1 beat is a ripple inside a phrase, 2 beats relaunch a 4 or 8 bar phrase, a full bar marks a section change, more than a bar marks a major transition. Polymetric sections (kick and `# riff` loop a cycle that is not a whole number of bars: hand rows identical in every bar, kick row different in every bar) have one phrase, the whole 8 or 16 bar block: fill only its last bar, where the cycle is cut, and keep the kick on the riff until the fill starts.

| slot | length | selector | content |
|---|---|---|---|
| end of bar 4 inside an 8 bar phrase | 0 to 1 beat | `beats=4.5-5` or `beats=4` | pickup, keeper may stay, 1 to 4 notes (L1, L2) |
| end of an 8 bar phrase, section continues | 2 beats | `beats=3-5` | L2 to L4 |
| last bar of a section, next section of equal weight | 2 to 4 beats | `beats=3-5` or `beats=1-5` | L3 to L5 |
| into a chorus, the heaviest riff or a breakdown | 4 beats, 8 beats (2 bars) at most once per song | `beats=1-5`, 2 bars: `bars=7-8` | L5, L6, snare roll crescendo, or stab plus silent gap |
| into a quieter section | 0 to 2 beats | `beats=3-5` | velocities falling 120 to 80, landing crash kept at digit 6 to 7 |

- At most one fill per 4 bars. Default plan for a 16 bar section: bar 4 nothing or half a beat, bar 8 two beats, bar 12 one beat, bar 16 four beats. Size grows toward the section end (unconfirmed as a djent specific rule). No two fills in one section cell identical: if a fill bar prints as `# bar 16 = bar 8`, change one of them.
- Sections with `lock` of 85% or more (the unison band of grooves.md section 1) and a quarter note china or crash keeper (Meshuggah type): by default no stand alone fills inside. At the section end use unison hits on riff onsets (vocabulary 7). Haake describes his tom parts this way: the toms hit where the guitars hit, together with the kick, instead of a fill laid on top.
- Subdivision by tempo: notes per second = bpm x G / 240. Hands alone stay under about 14 per second (rule of thumb, unconfirmed): 16ths up to 210 bpm, sextuplets (grid=24) up to 140, 32nds up to 105. Above that use hand and foot patterns (vocabulary 2, 3) or bursts of at most 4 cells.
- Grid caution: a bar block has one grid for all its rows, and it must hold every existing onset of the rows you write. Start from the grid `show` printed for the bar and go finer only: 16 to 32 or 48, 12 to 24 or 48, 24 to 48. Sextuplets in a bar that also has 16th notes on a written row: grid=48 (48 cells in 4/4, a 16th is 3 cells, a sextuplet is 2). Rows you do not write may sit off your grid.
- Other meters: beats still count quarter notes. A 7/8 bar spans beats 1 to 4.5, its last 2 beats are `beats=2.5-4.5` and a grid=16 row has 14 cells.

## 4. Vocabulary

Limb rule for everything below: at most 2 hand lanes per cell (snare, toms, hats and cymbals are all hands) plus kick. While both hands are on drums the keeper has no hits.

| # | figure | grid shape |
|---|---|---|
| 1 | descending tom run | 16ths, 2 notes per drum: snare, tom1, tom3, tom5 (L3). Skip tom1 for a darker run. Programmers build it by moving snare hits onto tom lanes while the hits on the beats stay on the snare |
| 2 | linear sextuplet | grid=24, per beat 4 hand cells then 2 kick cells (R L R L K K), hands walking down the drums (L4). Also groups of 3 (R L K), 4 (R L R K) and 5 (R L R L K) chained: 3 + 4 + 5 = 12 cells = 2 beats |
| 3 | quads | 2 hand cells then 2 kick cells (R L K K) at grid=16, 24 or 32 (bar 2 below). Halpern builds linear fills by splitting paradiddle type stickings between hands and feet (lesson body not read) |
| 4 | kick doubled toms | every snare or tom cell has a kick on the same cell: hands on 8ths, feet on 16ths (L5) |
| 5 | flam | grace note 15 to 30 ms before a main hit, on the last 1 or 2 hits or on every slam, also between two toms (section 5) |
| 6 | snare roll crescendo | snare on every cell for 2 to 4 beats (32nds up to 105 bpm, sextuplets up to 140, 16ths above), `ramp from=60 to=127`, kick on the beats, keeper row cleared (L2 is the one beat form). Two bar build: snare on quarters for 2 beats, 8ths for 4 beats, then 16ths for the last 2 beats, one ramp from 50 (the block is in song-structure.md section 6) |
| 7 | unison stabs | kick + snare + cym, or kick + snare + floor tom, on one cell, placed on `# riff` onsets, nothing or only kick between (bar 3 below, L6) |
| 8 | thirty-second burst | 4 cells at grid=32 on one drum in the last half beat, 8 cells only at 105 bpm or slower (recipe "busier") |
| 9 | china punctuation | china (52) + kick on a syncopated cell inside the fill instead of a tom hit. The built in map has no stack lane: use china or splash (55) unless a custom map defines `stack*` |
| 10 | kick only, stop, gap | hands rest or hold one crash while the kick runs into the downbeat (bar 1 below). Stop: a stab, then silence to the bar line (bar 3 below) |

```vd
# bar 1, kick only: keeper stops, crash and snare on 3, then the feet run 16ths into the downbeat
bar 1 grid=16
crash1 49  |---- ---- 9--- ----|
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 9--- ----|
kick 36    |9-9- --9- -888 8899|
# bar 2, quads over beats 3 and 4: snare, floor tom, kick, kick
bar 2 grid=16
china 52   |9--- 9--- ---- ----|
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

- Accents are digit 9 (119 to 127). Metal backbeats are programmed at 120 to 127 and the hardest hits are rimshot samples. Other fill notes sit at 105 to 118 (digit 8): 110 to 120 sounds closer to a real hard hit than constant 127. Ghost or drag notes inside a fill: 20 to 50.
- Leading hand: in 16th and 32nd runs the weaker hand is 2 to 15 lower (one digit). Odd cells are the leading hand: `accent ... grid=16 pattern=98`. R L R L K K sextuplets: hands 9 7 8 7 (beat accent, weak, lead, weak).
- Overall shape, never flat. Tom runs: the first hit is the strongest and the next ones fall slightly (120, 115, 110), restarted on each new drum (the 9 8 pairs of L3). Rolls and builds rise, and their last note before the landing is the loudest: `ramp from=60 to=127` (60 is this document's start value so the first hits still cut through; Sound On Sound ramps an orchestral roll from 1 to about 120). Into a quiet section invert it: `ramp from=120 to=80`. "Heavier": the last low notes are 127.
- Speed: the faster one drum is played, the quieter it gets. Above 12 notes per second on one drum pull the whole run down to 100 to 115 (threshold unconfirmed).
- Kick under a fill: keep the digit the section's kick already has (in this style near constant, digit 8 to 9), all 9 for "heavier". In runs of 16ths or faster the weaker foot is 2 to 15 lower (`9898`).
- Flam: grace note 6 to 30 ms before the main note and quieter. Use 15 to 30 ms: 17 to 34 ticks at 140 bpm and 480 ppq (ms = ticks x 60000 / (bpm x ppq), one tick is 0.89 ms, one 32nd cell is 60 ticks). Classic flam: grace at 45 to 75. Heavy flat flam: grace at 84 to 104. Above 40 ms it reads as two notes (the velocities and the 40 ms limit are unconfirmed). A grace closer than ppq/24 ticks to its main hit shares its cell: there a new digit scales both hits and `-` deletes both. A wider grace makes `show` print the bar at grid=32 or 48 from then on (bar 6 below prints at grid=48, the grace one cell before the 9). Tom slam (two drums on one cell): one tom 10 to 12 ticks early, the other the same amount late, kick on the grid.
- Feel: this style is edited tight, so by default fills stay on the grid. Only on request: toms 4 to 10 ticks late (`shift ... lanes=tom ticks=6`) drag into a section, a snare run 3 to 6 ticks early adds urgency (tick amounts unconfirmed). Keep the kick on the grid when `lock` is 70% or more. Finish with `humanize ... vel=5 time=3`. A tom lane with `sd` near 0 in `# lanes` needs the leading hand and overall shapes above.

```vd
# same lane flam on 3.5: write the grace (digit 4) one 32nd cell (60 ticks) early, then move it 32 ticks later, 28 ticks (25 ms) before the main hit
bar 6 grid=32
china 52   |9--- ---- 9--- ---- ---- ---- ---- ----|
snare 38   |---- ---- ---- ---- 9--4 9--- ---- ----|
tom4 45    |---- ---- ---- ---- ---- ---- 9--- 9---|
tom5 43    |---- ---- ---- ---- ---- ---- 9--- 9---|
kick 36    |9--- 9--- ---- 9--- 9--- 9--- 9--- 9---|
shift bars=6 beats=3.25-3.5 lanes=snare ticks=32
# tom slams on 4 and 4.5: tom4 12 ticks early, tom5 12 ticks late (21 ms apart), kick on the grid
shift bars=6 beats=4-5 lanes=tom4 ticks=-12
shift bars=6 beats=4-5 lanes=tom5 ticks=12
```

## 6. The landing and the bar after

- Beat 1 of the next bar: crash1 or crash2 at 127 and kick at 127 on the same cell. If the new section's keeper is china or a ridden crash, the landing is that keeper's first hit at digit 9 plus the kick, and its other hits keep the digits they have in the section. Into a quiet section soften it: crash at 84 to 98 with kick at 100.
- The crash replaces the keeper hit on that cell: the hat or ride hit on beat 1 becomes `-`, the keeper resumes on its next cell.
- Heavier landing: crash1 + china (or crash1 + crash2) + kick, all 127. Both hands are on cymbals, so no snare on that cell.
- Pushed landing (unconfirmed, common practice): if `# riff` has an onset on the last 8th or 16th of the fill bar and none on the next beat 1, add crash + kick on that cell. The crash on the next beat 1 stays unless he asks to remove it.
- The bar after is the plain groove from beat 2 at the latest: no leftover toms or extra snares in beats 1 to 2, ghost notes return from beat 2. Write it as a full bar block. A script runs top to bottom, bar rows included: a `copy` that covers this bar goes before its bar block, never after.

```vd
# bar after a fill in bar 4: crash + kick on 1, china keeper back on beat 2, groove intact
bar 5 grid=16
crash1 49  |9--- ---- ---- ----|
china 52   |---- 9--- 9--- 9---|
snare 38   |---- ---- 9--- ----|
kick 36    |9-9- --9- --9- 9---|
```

## 7. Intensity ladder for one slot

One slot, `bars=4 beats=3-5`, six versions from lightest to heaviest. Beats 1 to 2 are the unchanged groove. On a real song write only the rows you change, always write the keeper row so its cells in the span are cleared, and clear every other hand lane the groove leaves in the span (`delete bars=4 beats=3-5 lanes=hh,hh_open,ride`, ghost snares by writing the snare row).

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
| velocity | hands and kick 120 to 127 (digit 9), no ghosts, flams on the big hits | accents kept, added notes at 84 to 104 |
| relation to the riff | hits moved onto `# riff` onsets, china + kick stabs, two cymbal landing | independent of the riff |
| grid | 16 or coarser | 24 or 32 |

## 9. Recipes

Swap `bars=4 beats=3-5` for `fills` (optionally with `bars=`) only when every span in `# fills` is confirmed and none is missing. `fills` always means the spans of the song as it was before the script: a fill written by this script is selected with `bars=` and `beats=`. Adding notes needs a bar block, the bulk ops (`copy` aside) only change or remove notes. A script runs top to bottom, bar rows included, so a bar block goes before the ops that reshape its notes.

**Heavier.** Stop when it is enough: (1) lower every tom, lowest lane first so no note is remapped twice; (2) kick on every hand cell or 16ths under; (3) snare, toms and kick to 120 or more, ghosts (`v=1-62`) deleted; (4) flam the last hit (section 5); (5) move hits onto `# riff` onsets; (6) crash1 + china landing; (7) still not enough: fewer and bigger notes, replace the span with L5 or L6. Never move to a finer grid for this request. Below: steps 1 to 3 on L3.
```vd
bar 4 grid=16
kick 36    |9-9- --9- 9999 9999|
remap bars=4 beats=3-5 lanes=tom5 to=tom6
remap bars=4 beats=3-5 lanes=tom3 to=tom5
remap bars=4 beats=3-5 lanes=tom1 to=tom4
vel bars=4 beats=3-5 lanes=snare,tom,kick min=120
```
**Lighter.** Kick only on the beats, toms up two lanes (highest lane first), 85 percent velocity capped at 110, landing crash capped at 105. Or step down one ladder level. The keeper may return in the first half of the span (write its row). Below: on L5.
```vd
delete bars=4 beats=3.25-4 lanes=kick
delete bars=4 beats=4.25-5 lanes=kick
remap bars=4 beats=3-5 lanes=tom4 to=tom2
remap bars=4 beats=3-5 lanes=tom5 to=tom3
remap bars=4 beats=3-5 lanes=tom6 to=tom4
vel bars=4 beats=3-5 lanes=snare,tom scale=0.85 max=110
vel bars=5 beats=1-1.25 lanes=cym max=105
```
**Busier.** Keep the accent cells and their digits. Fill the empty cells of the span: a kick where the neighbours are hand notes, else a hand note on the drum of the previous hand note at digit 6 to 7. Span already full at grid=16: rewrite it as L4 at grid=24, or turn the last half beat into a 32nd burst and add 8th note kicks, as below on L3. Check the tempo cap. Do not lower drums or raise velocities.
```vd
bar 4 grid=32
tom5 43    |---- ---- ---- ---- ---- ---- ---- 9787|
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
**More interesting.** Change one thing at a time: (1) regroup the accents as 3-3-2; (2) accents on a low drum, filler on the snare; (3) linear ending: the last two hand notes become kicks; (4) a hole: delete one unaccented cell; (5) weak hand lead (Haake starts fills on the hand that should not lead, so the accents land on the "wrong" drums): move every accent one cell later, `pattern=69669669`; (6) hits only on `# riff` onsets; (7) china + kick in place of one tom hit. Below: 1 and 2 on L3, with a kick under each accent.
```vd
bar 4 grid=16
kick 36    |9-9- --9- 9--9 --9-|
accent bars=4 beats=3-5 lanes=snare,tom grid=16 pattern=96696696
remap bars=4 beats=3-5 lanes=snare,tom v=119-127 to=tom5
remap bars=4 beats=3-5 lanes=tom v=1-118 to=snare
```
**More tom.** Move the fill's snare notes onto toms by position, high to low. For more crack leave the snare on the beat cells and move only the cells between. Use only tom lanes with a count above 0 in `# lanes`: other pitches may be silent in the user's kit (unconfirmed caution).
```vd
bar 4 grid=16
snare 38   |---- ---- 9898 9898|
remap bars=4 beats=3.5-4 lanes=snare to=tom1
remap bars=4 beats=4-4.5 lanes=snare to=tom3
remap bars=4 beats=4.5-5 lanes=snare to=tom5
```
**Less cheesy.** Cheesy in the grid: a full bar of 16ths, 4 notes per drum from snare down through tom1, flat velocity, no kick under it, repeated every 4 bars. Fix: cut it to the last 2 beats, drop tom1, two drums at most, last two hand notes become kicks, shaped velocity, and rewrite every second such fill in the section as the plain groove. The block writes the stock fill (with the china and kick rows of the fix), then fixes it.
```vd
bar 8 grid=16
china 52   |9--- 9--- ---- ----|
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

Unconfirmed (working numbers of this document, not found in a source): the sign thresholds in sections 1 and 2 and the `lock` cutoffs 70% and 85%; the 14 notes per second hand cap, the 12 per second velocity threshold and the tempo limits derived from them; the 16 bar fill plan and the once per song 2 bar fill; flam grace velocities and the 40 ms limit; the ramp start of 60; shift and slam amounts in ticks; the pushed landing; the two bar build layout; whether unused tom pitches sound in a given kit. Seen only as search snippets (page bodies not retrievable): Halpern's paradiddle lesson, the MusicRadar and Computer Music fill articles, the Postones interview. Engine behaviour (how candidates are found, how flams print, script order, the `ppq` header line) was read from `core/vibedrum.cpp`, not from FORMAT.md: recheck it if the engine changes.

- Haake: toms on the guitar hits with the kick, rimshots (Drum Magazine); ghost notes between accents (Drumeo, Modern Drummer); fills started on the weak hand (substack): https://drummagazine.com/tomas-haake-meshuggahs-djentle-giant/ , https://www.moderndrummer.com/2013/06/web-exclusive-interview-with-meshuggahs-tomas-haake/ , https://www.drumeo.com/beat/meshuggah-tomas-haake-genius/ , https://asiwalkintothesettingsun.substack.com/p/clockworks-by-meshuggah-drumming
- Fill definition, pattern resumes, fills vary (Wikipedia); length per slot, crash with kick on beat 1, fill versus break (Maurisson): https://en.wikipedia.org/wiki/Fill_(music) , https://musichub.maurisson.com/en/guide/fills-et-breaks-a-la-batterie/ , https://www.musicradar.com/tuition/tech/learn-how-drum-fills-work-in-5-easy-steps-639154 (snippet), https://www.pressreader.com/australia/computer-music/20160518/281526520271381 (snippet)
- Four limbs, flam 6 to 30 ms early and quieter, roll crescendo from 1 to about 120 (Sound On Sound); loudest hits near 115, dragging a tom fill, one foot weaker (Audient): https://www.soundonsound.com/techniques/making-midi-sequencing-more-realistic-part-2-drum-parts , https://audient.com/tutorial/programming-realistic-drums/
- 110 to 120 as a realistic hard hit, flams in slow fills (URM); stronger hand or foot 2 to 15 higher, faster means quieter, tom slam split around the grid (Drum Audio Editing): https://urm.academy/5-drum-programming-tips-for-maximum-realism/ , https://www.drumaudioediting.com/post/how-to-program-drums-so-that-they-sound-and-feel-human
- Backbeats 120 to 127, ghosts 20 to 50, fast fills rising into the crash, tom fill 120, 115, 110, rimshots as the hardest hits, a snare hit moved a few ms early for urgency (Toontrack, Nail The Mix): https://www.toontrack.com/blog/how-to-program-drums/ , https://www.nailthemix.com/drum-programming-faqs , https://www.nailthemix.com/toontrack-metal-mania-ezx , https://www.nailthemix.com/getgood-drums-matt-halpern-drums-library , https://www.nailthemix.com/getgood-drums-the-invasion
- Hand and foot vocabulary (quads, groups of 3, 4, 5 and 6, double bass under the hands, unison figures), then Halpern and Postones at snippet level: https://www.drumstheword.com/free-drum-lesson-quads-four-note-linear-hand-and-foot-combinations-licks-grooves-and-ideas/ , https://mixdownmag.com.au/features/columns/6-hand-foot-combinations-to-improve-your-drumming-skills/ , https://www.drumlessons.com/drum-lessons/bass-drum-lessons/intermediate-double-bass-drum-fills/ , https://www.musicradar.com/tuition/drums/matt-halpen-guest-lesson-fills-using-paradiddles-with-hands-and-feet-580337 , https://www.scribd.com/doc/218944485/Interview-with-Jay-Postones-TesseracT-by-Sina-Najaflou
