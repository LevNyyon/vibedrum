# Fills: djent and progressive metalcore

Units: beats are quarter notes (1 to 5 in 4/4), cells are counted at the stated grid, velocity is 1 to 127 (grid digit x 14, 9 = 127). The examples share one groove: china on every beat (the keeper), snare on 3 (`feel` half), kick on 1, 1.5, 2.5, 3.5 and 4. Recipes are written for the span `bars=4 beats=3-5`. That is a pattern, not a range: map every bar and beat to the confirmed span you are editing and look at what the mapped bar holds. Every recipe obeys knowledge/editing-principles.md: one or two rungs per request, graded by rank (section 3), shape after every level op, checked in `show --vel`. Tick math assumes 140 bpm and 480 ppq: read the real values from the `show` header (one tick = 60000 / (bpm x ppq) ms).

## 1. What a fill is in the grid

A fill is a span of 0.5 to 8 beats (usual: 1, 2 or 4) that ends at a phrase boundary and shows at least two of these signs:

1. Keeper drop: the section's `keeper` lane has no hits in the span, or fewer than in the same beats one bar earlier. Both hands left the cymbal.
2. Hand departure: any `tom` hit, or snare hits at digit 6 or higher on cells that are not the backbeat of the section `feel` (normal: beats 2 and 4, half: beat 3) and that are empty in the same beats one bar earlier.
3. Kick departure: a run of 3 or more consecutive kick cells that neither repeats the bar before nor sits on `# riff` onsets, or the kick silent where the bar before had kicks. A kick row that changes every bar but follows `# riff` is a polymetric groove, not a sign.
4. Landing: beat 1 of the next bar has a `cym` hit (crash1, crash2, china) at digit 8 or 9 on the same cell as a kick at digit 8 or 9, and the groove resumes there. A fill can lack this sign (section 6).

The timekeeping pattern resumes right after a fill, and fills vary from one occurrence to the next. A departure that lasts more than 2 bars, or that repeats bar after bar, is a section (tom groove, build), not a fill. If the `# riff` row is also empty across the span it is a break (the band stops): edit it like a fill, but cells that are silent in every row stay silent.

## 2. Checking the engine's candidates

`# fills: 8:3-5 16:1-5` and the bar comment `fill=3-5` are guesses made beat by beat (FORMAT.md, "How the engine decides"): inside each section a beat is flagged when it holds more tom hits than the section's median for that beat, or at least 2 more snare hits than the median. Velocity, kick, cymbals and `# riff` are ignored. Spans are whole beats inside one bar: a fill on 4.5 to 5 prints as `4-5`, a 2 bar fill as two spans (`7:3-5 8:1-5`). Show the bar with its neighbours (`--bars 7-9`). Confirm a span when all three hold: (a) it ends within 2 sixteenth cells of a bar line, and that bar is the last of a 2 or 4 bar group counted from the section start, or the last bar of the section or of the file; (b) sign 1 or sign 2 holds; (c) its cells differ from the same beats one bar earlier. The landing (sign 4) is not part of the test. A confirmed fill with a plain keeper hit on the next beat 1 has a missing landing, and a fill in the last bar of the file has no landing bar at all: both are fills, section 6 says what to do. A candidate that nothing here confirms or rejects: leave it alone and say so.

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

Two cases the file decides, not the request:
- No riff track (the header has no `# riff:` line): sign 3 loses its riff clause, and the riff accent reject, the pushed landing (section 6) and every step that says "onto `# riff` onsets" do not apply. Skip them and say so.
- A kit with one or two toms: `# lanes` lists the drums he has. A recipe that names other tom lanes is translated to the lanes with notes, lowest to lowest, and the fill keeps its number of drums. Never merge two drums into one, never write to a tom lane that has no notes (it may be silent in his kit, unconfirmed).

## 3. Where fills go, how long, and their rank

Phrase grid: take the section bar ranges from `# sections` and cut each into 4 bar groups from its first bar. A riff reset (the `# riff` row equal to the section's first bar again) confirms a group start. Fill slots are the last bar of each group. Fills belong at the end of 4 or 8 bar phrases, the bigger ones every 8 or 16 bars, and their length signals the size of the change: 1 beat is a ripple inside a phrase, 2 beats relaunch a 4 or 8 bar phrase, a full bar marks a section change, more than a bar marks a major transition. Polymetric sections (kick and `# riff` loop a cycle that is not a whole number of bars: hand rows identical in every bar, kick row different in every bar) have one phrase, the whole 8 or 16 bar block: fill only its last bar, where the cycle is cut, and keep the kick on the riff until the fill starts.

| slot | rank | length | selector | content |
|---|---|---|---|---|
| end of bar 4 inside an 8 bar phrase | 1, pickup | 0 to 1 beat | `beats=4.5-5` or `beats=4` | keeper may stay, 1 to 4 notes (L1, L2) |
| end of an 8 bar phrase, section continues. Also the last bar of the file | 2, phrase end | 2 beats | `beats=3-5` | L2 to L4 |
| last bar of a section, next section of equal weight | 3, section change | 2 to 4 beats | `beats=3-5` or `beats=1-5` | L3 to L5 |
| into a chorus, the heaviest riff or a breakdown | 3, section change | 4 beats, 8 beats (2 bars) at most once per song | `beats=1-5`, 2 bars: `bars=7-8` | L5, L6, snare roll crescendo, or stab plus silent gap |
| into a quieter section | 3, inverted | 0 to 2 beats | `beats=3-5` | velocities falling (`ramp ... scale=1-0.7`), landing crash at digit 6 to 7 |

- Rank comes from the slot, not from the length the file happens to have, and every edit keeps it: after a recipe a rank 1 fill is still smaller than a rank 2, and the rank 3 fill is the biggest of its section. Rank shows in four places: length, the top velocity (section 5), the kick under the fill (recipe Heavier) and the landing (section 6). Never give all fills one treatment.
- At most one fill per 4 bars. Default plan for a 16 bar section: bar 4 nothing or half a beat, bar 8 two beats, bar 12 one beat, bar 16 four beats. Size grows toward the section end (unconfirmed as a djent specific rule). No two fills in one section cell identical: if a fill bar prints as `# bar 16 = bar 8`, change one of them.
- Sections with `lock` of 85% or more (the unison band of grooves.md section 1) and a quarter note china or crash keeper (Meshuggah type): by default no stand alone fills inside. At the section end use unison hits on riff onsets (figure 7 in section 4). Haake describes his tom parts this way: the toms hit where the guitars hit, together with the kick, instead of a fill laid on top.
- Subdivision by tempo: notes per second = bpm x G / 240. Hands alone stay under about 14 per second (rule of thumb, unconfirmed): 16ths up to 210 bpm, sextuplets (grid=24) up to 140, 32nds up to 105. Above that use hand and foot patterns (figures 2 and 3 in section 4) or bursts of at most 4 cells.
- Grid caution: a bar block has one grid for all its rows, and it must hold every existing onset of the rows you write. Start from the grid `show` printed for the bar and go finer only: 16 to 32 or 48, 12 to 24 or 48, 24 to 48. Sextuplets in a bar that also has 16th notes on a written row: grid=48 (48 cells in 4/4, a 16th is 3 cells, a sextuplet is 2). Rows you do not write may sit off your grid.
- Other meters: beats still count quarter notes. A 7/8 bar spans beats 1 to 4.5, its last 2 beats are `beats=2.5-4.5` and a grid=16 row has 14 cells.

## 4. Vocabulary

Limb rule for everything below: at most 2 hand lanes per cell (snare, toms, hats and cymbals are all hands) plus kick. While both hands are on drums the keeper has no hits.

| # | figure | grid shape |
|---|---|---|
| 1 | descending tom run | 16ths, 2 notes per drum: snare, tom1, tom3, tom5 (L3), or as many toms as the kit has. Programmers build it by moving snare hits onto tom lanes while the hits on the beats stay on the snare |
| 2 | linear sextuplet | grid=24, per beat 4 hand cells then 2 kick cells (R L R L K K), hands walking down the drums (L4). Also groups of 3 (R L K), 4 (R L R K) and 5 (R L R L K) chained: 3 + 4 + 5 = 12 cells = 2 beats |
| 3 | quads | 2 hand cells then 2 kick cells (R L K K) at grid=16, 24 or 32 (bar 2 below). Halpern builds linear fills by splitting paradiddle type stickings between hands and feet (lesson body not read) |
| 4 | kick doubled toms | hands on 8ths, feet on 16ths under them (L5). Not 16th feet under 16th hands: that is a wall, not weight |
| 5 | flam | grace note 15 to 30 ms before a main hit, on the last 1 or 2 hits or on every slam, also between two toms (section 5) |
| 6 | snare roll crescendo | snare on every cell for 2 to 4 beats (32nds up to 105 bpm, sextuplets up to 140, 16ths above), kick on the beats, keeper row cleared, `ramp from=60 to=127` (the roll is written new and flat, so the absolute ramp erases nothing). L2 is the one beat form. Two bar build: snare on quarters for 2 beats, 8ths for 4 beats, then 16ths for the last 2 beats, written in digits, the rise with `ramp scale=0.65-1.3` (the block is in song-structure.md section 6) |
| 7 | unison stabs | kick + snare + cym, or kick + snare + floor tom, on one cell, placed on `# riff` onsets, nothing or only kick between (bar 3 below, L6) |
| 8 | thirty-second burst | 4 cells at grid=32 on one drum in the last half beat, 8 cells only at 105 bpm or slower (recipe "busier") |
| 9 | china punctuation | china (52) + kick on a syncopated cell inside the fill instead of a tom hit. The built in map has no stack lane: use china or splash (55) unless a custom map defines `stack*` |
| 10 | kick only, stop, gap | hands rest or hold one crash while the kick runs into the downbeat (bar 1 below). Stop: a stab, then silence to the bar line (bar 3 below) |

```vd
# bar 1, kick only: keeper stops, crash and snare on 3, then the feet run 16ths rising into the downbeat
bar 1 grid=16
crash1 49  |---- ---- 9--- ----|
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 9--- ----|
kick 36    |9-9- --9- -778 8899|
# bar 2, quads over beats 3 and 4: snare, floor tom, kick, kick, the weaker foot a digit lower
bar 2 grid=16
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 9--- 9---|
tom5 43    |---- ---- -7-- -8--|
kick 36    |9-9- --9- --98 --98|
# bar 3, unison stabs on 3 and 3.75 (kick + snare + china), then beat 4 silent
bar 3 grid=16
china 52   |9--- 9--- 8--9 ----|
snare 38   |---- ---- 9--8 ----|
kick 36    |9-9- --9- 9--9 ----|
```

## 5. Velocity and timing inside a fill

Hands of a fill: `lanes=38,tom` (`lanes=snare` would take the rim too). A fill that opens on the backbeat cell keeps that backbeat: start every op below one cell later (`beats=3.25-5`).

- Three bands, and they are walls. Body of the fill: 60 to 118, most of it in digits 7 and 8. Top: 119 to 127, on one or two notes of a fill, never on every leading hand note. Ghost and drag notes: 20 to 50. Metal backbeats sit at 120 to 127 and the hardest hits are rimshot samples, so a fill body at 120 or more is as loud as the backbeat and reads as a machine gun: 110 to 120 sounds closer to a real hard hit than constant 127. After any scaling clamp the body (`vel SPAN lanes=38,tom max=118`), then set the top. Never use `min=` or `set=` on a whole fill.
- Lean: the weaker hand sits one digit under the leading hand (10 to 15). Sources say 2 to 15, but under 7 both hands trigger the same sample layer in most libraries. In 16th runs the "e" and "a" cells are the weak hand. New notes: write `87`. Existing notes: `accent SPAN lanes=38,tom grid=16 pattern=-1 mix=0.15` pulls the weak cells 15 percent of the way toward digit 1, about 14 lower at any level, and keeps what was there. Fills on 8ths: `grid=8`.
- Direction, one of two. Rising into the landing (rolls, builds, fills of 2 beats or more): `ramp SPAN lanes=38,tom scale=0.88-1`, 10 or more from the first to the last leading hand note. Or falling per drum (the lean on a run of 2 notes per drum already gives it; a source gives 120, 115, 110 for a tom fill, widen such steps to 10). `ramp from= to=` writes absolute values and erases the lean: only for a roll you just wrote flat. Into a quiet section: `ramp ... scale=1-0.7`.
- Top by rank (section 3), on the last note, which after Heavier rung 2 is the lowest drum. Rank 1: last note 117, nothing above 118. Rank 2: last note 127. Rank 3: last two notes 127 when both are on that drum. These are single notes, so `set=` with the pitch named: `vel bars=4 beats=4.75-5 lanes=43 set=127`.
- Speed: the faster one drum is played, the quieter it gets. Above 12 notes per second on one drum pull the whole run down to 100 to 115 (threshold unconfirmed).
- Kick under a fill: the lane's own level (`x` in a bar block writes it). In runs of 16ths or faster the weaker foot is one digit lower (`98`). "Heavier" never raises the kick.
- Flam: grace note 6 to 30 ms before the main note and quieter. Use 15 to 30 ms: 17 to 34 ticks at 140 bpm and 480 ppq (one tick is 0.89 ms, one 32nd cell is 60 ticks). Classic flam: grace at 45 to 75. Heavy flat flam: grace at 84 to 104. Above 40 ms it reads as two notes (the velocities and the 40 ms limit are unconfirmed). A grace closer than ppq/24 ticks to its main hit shares its cell: there a new digit scales both hits and `-` deletes both. A wider grace makes `show` print the bar at grid=32 or 48 from then on (bar 6 below prints at grid=48, the grace one cell before the main hit). Tom slam (two drums on one cell): one tom 10 to 12 ticks early, the other the same amount late, kick on the grid.
- Feel: this style is edited tight, so fills stay on the grid: no `humanize time=`. A flat fill (hand notes within 7 of each other) gets `humanize SPAN lanes=38,tom vel=2` once, after the level op and before lean, direction and top, so the spread stays under half of the lean. A fill that already has a shape gets none. Only on request: toms 4 to 10 ticks late (`shift ... lanes=tom ticks=6`) drag into a section, a snare run 3 to 6 ticks early adds urgency (tick amounts unconfirmed). Keep the kick on the grid when `lock` is 70% or more.

```vd
# same lane flam on 3.5: write the grace (digit 4) one 32nd cell (60 ticks) early, then move it 32 ticks later, 28 ticks (25 ms) before the main hit
bar 6 grid=32
china 52   |9--- ---- 9--- ---- ---- ---- ---- ----|
snare 38   |---- ---- ---- ---- 9--4 8--- ---- ----|
tom4 45    |---- ---- ---- ---- ---- ---- 7--- 8---|
tom5 43    |---- ---- ---- ---- ---- ---- 8--- 9---|
kick 36    |9--- 9--- ---- 9--- 9--- 9--- 9--- 9---|
shift bars=6 beats=3.25-3.5 lanes=38 ticks=32
# tom slams on 4 and 4.5, the second one the top: tom4 12 ticks early, tom5 12 ticks late (21 ms apart), kick on the grid
shift bars=6 beats=4-5 lanes=tom4 ticks=-12
shift bars=6 beats=4-5 lanes=tom5 ticks=12
```

## 6. The landing and the bar after

Landings have ranks too. No landing is bigger than the entrance of its own section or than the first hit of the song.

- Inside a section (after a rank 1 or 2 fill): one cymbal plus kick on beat 1 of the next bar. Hat or ride keeper: crash1 or crash2. China or ridden crash keeper: that keeper's own hit on beat 1 is the landing, add nothing. An existing landing keeps its level. One you add sits a digit under the section's entrance crash (112 under an entrance at 127).
- Section start (after a rank 3 fill): crash at 127 plus kick. A stack (crash1 + china or crash1 + crash2, both hands, so no snare on that cell) belongs only here, and only when the first hit of the song is itself a stack or he asks for bigger landings: otherwise the landing would outrank the opening. Never bring a section's keeper cymbal in before its first bar: no china landing inside a hat verse. Both hands travel to a stack, so at 16ths from 120 bpm up the last cell before it belongs to the kick, not to a floor tom.
- The crash replaces the keeper hit on that cell: the hat or ride hit on beat 1 becomes `-`, the keeper resumes on its next cell.
- Missing landing: beat 1 after a confirmed fill is a plain keeper hit. Repairing it is one rung of its own (Heavier rung 4): one crash over the kick as above, only when the request is about fills, and reported, because it changes a bar outside the fill.
- A fill in the last bar of the file has no landing bar and no op can add a bar. Leave the landing out and say so. Bar 1 is its landing only if he says the clip loops.
- Into a quiet section soften it: crash at 84 to 98 with kick at 100.
- Pushed landing (unconfirmed, common practice, needs a riff track): if `# riff` has an onset on the last 8th or 16th of the fill bar and none on the next beat 1, add crash + kick on that cell. The crash on the next beat 1 stays unless he asks to remove it.
- The bar after is the plain groove from beat 2 at the latest: no leftover toms or extra snares in beats 1 to 2, ghost notes return from beat 2. Write only the rows you change, rows you leave out stay as they are. A bar that prints as `# bar 5 = bar 3` needs its own `bar 5 grid=16` line first. A `copy` that covers this bar goes before its bar block, never after.

```vd
# hat section, fill in bar 4, landing inside the section: one crash over the kick, a digit under the entrance crash. the hat leaves that cell and is back on the "and"
bar 5 grid=16
crash1 49  |8--- ---- ---- ----|
hh 42      |--7- 7-7- 7-7- 7-7-|
kick 36    |9-9- --9- --9- 9---|
```

## 7. Intensity ladder for one slot

One slot, `bars=4 beats=3-5`, six versions from lightest to heaviest. Beats 1 to 2 are the unchanged groove. Each is shaped: a leading hand or a direction, and at most two hand notes at 127 (the backbeat on 3 counts). On a real song write only the rows you change, always write the keeper row so its cells in the span are cleared, and clear every other hand lane the groove leaves in the span (`delete bars=4 beats=3-5 lanes=hh,hh_open,ride`, ghost snares by writing the snare row). Tom lanes: the ones his kit has (section 2).

L1 pickup, rank 1. Keeper stays, two snare 16ths at 4.5 and 4.75 (98, 112). No digit 9 in a pickup.
```vd
bar 4 grid=16
china 52   |9--- 9--- 9--- 9---|
snare 38   |---- ---- 9--- --78|
kick 36    |9-9- --9- --9- 9---|
```
L2 snare build. Keeper leaves beat 4, four snare 16ths rising 70, 84, 98, 112. At rank 2 or 3 the last one is a 9.
```vd
bar 4 grid=16
china 52   |9--- 9--- 9--- ----|
snare 38   |---- ---- 9--- 5678|
kick 36    |9-9- --9- --9- 9---|
```
L3 tom run. Keeper leaves beats 3 and 4, two 16ths per drum going down, leading hand 112 over weak hand 98, the top on the last floor tom note, kick on the beats.
```vd
bar 4 grid=16
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 97-- ----|
tom1 50    |---- ---- --87 ----|
tom3 47    |---- ---- ---- 87--|
tom5 43    |---- ---- ---- --89|
kick 36    |9-9- --9- 9--- 9---|
```
L4 linear sextuplets, the busiest. Per beat four hand cells then two kick cells, 12 notes in 2 beats.
```vd
bar 4 grid=24
china 52   |9----- 9----- ------ ------|
snare 38   |------ ------ 97---- ------|
tom1 50    |------ ------ --87-- ------|
tom3 47    |------ ------ ------ 87----|
tom5 43    |------ ------ ------ --89--|
kick 36    |9--9-- ---9-- ----98 ----98|
```
L5 kick doubled low toms, rank 3. Hands on 8ths only, low drums, 16th kicks under them, both floor toms on the last hit.
```vd
bar 4 grid=16
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 9--- ----|
tom4 45    |---- ---- --8- ----|
tom5 43    |---- ---- ---- 8-9-|
tom6 41    |---- ---- ---- --8-|
kick 36    |9-9- --9- 9898 9898|
```
L6 unison slams, the heaviest, rank 3. Snare + floor tom + kick on beats 3, 3.75 and 4.5 (3-3-2 cells), the floor tom rising 98, 112, 127, 16th kicks between. With a riff track move the three slam cells onto `# riff` onsets.
```vd
bar 4 grid=16
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 9--8 --8-|
tom5 43    |---- ---- 7--8 --9-|
kick 36    |9-9- --9- 9889 8898|
```

## 8. Heavier is not busier

Hand cells in the fill: L1 2, L2 4, L3 8, L4 8 plus 4 kick cells, L5 4, L6 3. Density peaks at L4, weight keeps rising to L6. The two requests move different controls:

| control | heavier | busier |
|---|---|---|
| hand notes in the span | same or fewer: 8ths, 3-3-2 slams | more: 16ths, then sextuplets, then 32nds |
| drums | the same drums, more of the fill on the lowest one, both hands on one cell | any, usually more drums, single strokes |
| kick | under the leading hand on 8ths, or 16ths under hands that play 8ths. Never 16ths under 16th hands | only in the gaps between hand notes (linear) |
| velocity | body 90 to 118 with a lean, the top at 127 on the last one or two notes, no ghosts, a flam on the top | accents kept, added notes at 84 to 104 |
| relation to the riff | hits moved onto `# riff` onsets, china + kick stabs, landing by rank | independent of the riff |
| grid | 16 or coarser | 24 or 32 |

## 9. Recipes

Every recipe is a ladder: rungs in order, the default takes the first one or two the fills have room for, in one script, and the report names the next rung. Anything that shapes is written per fill or per rank group (`bars=4,12 beats=4-5`). The bulk `fills` selector is only for a uniform nudge (one level scale, deleting ghosts), only when every span in `# fills` is confirmed and none is missing, and it always means the spans of the song as it was before the script. Script order: bar blocks, `remap`, `delete`, then `vel`, then `humanize`, then lean, direction and top last. Adding notes needs a bar block. Afterwards read `show --vel` on every changed bar and report only what the numbers show: notes added, bars touched outside the fills, and in one line what is still flat outside the request.

**Heavier.** Weight, not notes and not maximum level.
1. Level and shape. Room: the fill is flat, or its leading hand is under 105, or it sits at the ceiling. Per fill, in this order (all in section 5): `vel SPAN lanes=38,tom scale=F` with F = target / the level of its leading hand in `show --vel` (target 107 for rank 1, 122 for ranks 2 and 3; a single top note it already has does not count), `humanize` only if flat, the lean only if the weak hand is less than 10 under, the rising ramp only on fills of 2 beats or more that do not rise by 10 yet, then always the wall and the top by rank. Ceiling: a leading hand already at 119 or more gives F under 1. That is right: nothing can go up, so the body comes down and the top stands out. Say so.
2. Weight onto the low drum. The low drum is the lowest tom lane with notes in `# lanes`. A fill that never reaches it: its last tom note goes there, one `remap` of one cell. A fill that already ends on it, or has no toms: skip, rung 1 puts the top on its last note. Never remap a whole lane, never leave a fill with fewer drums than it had: on a two tom kit tom2 tom2 becomes tom2 tom5, not tom5 tom5.
3. Kick under the leading hand, only for fills with no kick under them: `x` on 8th cells that hold a hand note, rank 1 on its beat only, ranks 2 and 3 on every 8th of the span. With a riff track only on `# riff` onsets. No kick on a cell without a hand note: a stop, a gap and the rests of a breakdown riff stay empty. This adds notes: say how many.
4. Landing by rank (section 6): the missing landing first, a stack only where that section allows it.
5. Fewer and bigger notes, rank 3 only: replace the span with L5 or L6, built from the drums the fill had.
6. A flam on the top note (section 5). The grace is the only place this request may use a finer grid.
7. Hits moved onto `# riff` onsets. No riff track: skip and say so.

Below: rungs 1 and 2 on a flat two tom file, then rungs 3 and 4 when he asks again. A rank 2 fill takes the bar 8 lines with one top note (`beats=4.75-5`).
```vd
# said back: heavier fills by weight, not notes: a leading hand, a rise in the long fill, the top hit on the floor tom. the pickup in bar 4 stays under the backbeat, the fill into the new section in bar 8 ends on two full hits. no notes added, groove bars untouched
# input: hat section bars 1-8, bar 9 starts a new section. fills 4:4-5 (snare snare tom2 tom2, rank 1) and 8:3-5 (four snares, tom2 tom2 tom5 tom5, rank 3), every fill note 98, no kick under them. toms in # lanes: tom2 and tom5
# rung 2, notes first: the pickup never reaches the floor tom, so its last note goes there. bar 8 already ends on it
remap bars=4 beats=4.75-5 lanes=48 to=tom5
# rung 1, level by rank: F = 107 / 98 and 122 / 98, then the small spread a flat fill needs
vel bars=4 beats=4-5 lanes=38,tom scale=1.09
vel bars=8 beats=3-5 lanes=38,tom scale=1.25
humanize bars=4 beats=4-5 lanes=38,tom vel=2 seed=4
humanize bars=8 beats=3-5 lanes=38,tom vel=2 seed=4
# lean on both fills, the rise only on the long one
accent bars=4 beats=4-5 lanes=38,tom grid=16 pattern=-1 mix=0.15
accent bars=8 beats=3-5 lanes=38,tom grid=16 pattern=-1 mix=0.15
ramp bars=8 beats=3-5 lanes=38,tom scale=0.88-1
# wall, then the top by rank on the floor tom
vel bars=4 beats=4-5 lanes=38,tom max=118
vel bars=8 beats=3-5 lanes=38,tom max=118
vel bars=4 beats=4.75-5 lanes=43 set=117
vel bars=8 beats=4.5-5 lanes=43 set=127
```
Expected in `show --vel`: bar 4 about 106 91 107 117 (snare, snare, tom2, tom5), bar 8 about 107 94 112 100 118 103 127 127.
```vd
# asked again, said back: a kick under the leading hand of both fills (5 kicks added), and the bar 4 fill now lands on a crash in bar 5, a digit under the bar 1 entrance. the hat under that crash is the only groove note changed
# rung 3: cells outside the fill are copied from show, x writes the kick at the lane's own level
bar 4 grid=16
kick 36    |9--9 -99- -9-- x---|
bar 8 grid=16
kick 36    |9--9 -99- x-x- x-x-|
# rung 4: bar 5 beat 1 was hat + kick. bar 9 keeps its single crash: a stack there would outrank the one crash that opens the song
bar 5 grid=16
crash1 49  |8--- ---- ---- ----|
hh 42      |--7- 7-7- 7-7- 7-7-|
```
**Lighter.** (1) Level down with the shape kept: `scale=0.85`. A flat fill then gets the lean, and its last note one digit above the body instead of 127. (2) Kick: delete only the fill's own run under the hands and keep the beats. Kicks that the bar before also has, or that sit on `# riff` onsets, stay. (3) The landing crash one digit down (`vel bars=5 beats=1-1.25 lanes=49 scale=0.88`). (4) One ladder level down. Toms are not moved up: on most kits that merges drums. Below: rungs 1 and 2 on L5.
```vd
vel bars=4 beats=3.25-5 lanes=38,tom scale=0.85
delete bars=4 beats=3.25-4 lanes=kick
delete bars=4 beats=4.25-5 lanes=kick
```
**Busier.** One rung per request, accent cells and their digits kept, drums not lowered, velocities not raised: (1) fill the empty cells of the span: a kick where both neighbours are hand notes, else a hand note on the drum of the previous hand note, one digit under it; (2) span already full at grid=16: a 32nd burst on the last half beat, new cells at digit 7, as below on L3; (3) rewrite it as L4 at grid=24. Check the tempo cap (section 3).
```vd
bar 4 grid=32
tom5 43    |---- ---- ---- ---- ---- ---- ---- 8797|
```
**Simpler.** (1) Ghosts and graces out and only the 8th note cells stay (mask idiom: mark the cells between with digit 1, delete what is marked). Every drum keeps its first note, so the descent stays. Then restore a shape on what is left: a rise and the top. (2) One ladder level down. Below: rung 1 on L3, leaving 127, 95, 104, 127 on snare, tom1, tom3, tom5.
```vd
delete bars=4 beats=3-5 lanes=38,tom v=1-62
accent bars=4 beats=3-5 lanes=38,tom grid=16 pattern=-1
delete bars=4 beats=3-5 lanes=38,tom v=1-20
ramp bars=4 beats=3.25-5 lanes=tom scale=0.85-1
vel bars=4 beats=4.5-4.75 lanes=43 set=127
```
**Longer.** Double the span backwards (1 to 2 beats, 2 to 4 beats, 4 beats to 2 bars). The old fill stays as the tail. The new front half gets half the density, rises, and stays a digit or more under the tail so the fill accelerates. The keeper is cleared there, the kick row is not touched. It must not outrank the last fill of its section. For 2 bars put an L1 or L2 in the previous bar. Below: L3 extended to the whole bar.
```vd
bar 4 grid=16
china 52   |9--- ---- ---- ----|
snare 38   |--5- 6-7- 97-- ----|
```
**Shorter.** Keep the tail and restore the groove in the front of the span (rows as in the same beats one bar earlier). Never keep the front and cut the tail: the tail carries the top and the landing. Below: L3 cut to beat 4.
```vd
bar 4 grid=16
china 52   |9--- 9--- 9--- ----|
snare 38   |---- ---- 9--- ----|
kick 36    |9-9- --9- --9- 9---|
delete bars=4 beats=3-4 lanes=tom
```
**More interesting.** One change per request, drums and descent kept: (1) regroup the accents as 3-3-2 over taps one or two digits lower, as below on L3 (127, 112, 127 on cells 8, 11, 14, the backbeat untouched); (2) a hole: delete one tap; (3) weak hand lead (Haake starts fills on the hand that should not lead, so the accents land on the "wrong" drums): the accents one cell later, `pattern=-8768679`; (4) china + kick in place of one tom hit that is not the top; (5) with a riff track: hits only on `# riff` onsets.
```vd
accent bars=4 beats=3.25-5 lanes=38,tom grid=16 pattern=-6787696
```
**More tom.** Move the fill's snare notes onto toms by position, high to low. The beat cell of the first drum stays on the snare for crack. One `remap` per tom lane that has notes in `# lanes`, the lowest last. A two tom kit takes only the last two remaps. Below: a shaped snare run becomes L3.
```vd
bar 4 grid=16
snare 38   |---- ---- 9787 8789|
remap bars=4 beats=3.5-4 lanes=38 to=tom1
remap bars=4 beats=4-4.5 lanes=38 to=tom3
remap bars=4 beats=4.5-5 lanes=38 to=tom5
```
**Less cheesy.** Cheesy in the grid: a full bar of 16ths, 4 notes per drum from the snare down through the toms, flat velocity, no kick under it, repeated every 4 bars. Ladder: (1) the flat velocity is most of it: `humanize`, lean, rising ramp, wall and top as in Heavier rung 1, without its level line; (2) Shorter: keep the last 2 beats; (3) Heavier rung 3; (4) every second such fill in the section gets one More interesting change, so no two are cell identical.

## Sources and unconfirmed items

Unconfirmed (working numbers of this document, not found in a source): the sign thresholds in sections 1 and 2 and the `lock` cutoffs 70% and 85%; the 14 notes per second hand cap, the 12 per second velocity threshold and the tempo limits derived from them; the 16 bar fill plan and the once per song 2 bar fill; the three ranks and their numbers (level targets 107 and 122, tops 117 and 127, the body wall at 118, lean mix 0.15, ramp 0.88 to 1, landing a digit under the entrance); the 10 velocity minimum for a designed difference (from the blind trial judges, sources allow 2 to 15); flam grace velocities and the 40 ms limit; the ramp start of 60; shift and slam amounts in ticks; the pushed landing; the two bar build layout; whether unused tom pitches sound in a given kit. Seen only as search snippets (page bodies not retrievable): Halpern's paradiddle lesson, the MusicRadar and Computer Music fill articles, the Postones interview. Engine behaviour: how candidates are found, the ppq/24 tolerance and script order are in FORMAT.md ("How the engine decides"). How flams print and the lower median of the candidate rule were read from `core/vibedrum.cpp`: recheck them if the engine changes. Every script of section 9 was applied to demo/djent-demo.mid (16 bars, 130 bpm, flat fills, two toms, no riff track) and read back with `show --vel`, the ceiling case on a copy with every fill note at 120 to 127.

- Haake: toms on the guitar hits with the kick, rimshots (Drum Magazine); ghost notes between accents (Drumeo, Modern Drummer); fills started on the weak hand (substack): https://drummagazine.com/tomas-haake-meshuggahs-djentle-giant/ , https://www.moderndrummer.com/2013/06/web-exclusive-interview-with-meshuggahs-tomas-haake/ , https://www.drumeo.com/beat/meshuggah-tomas-haake-genius/ , https://asiwalkintothesettingsun.substack.com/p/clockworks-by-meshuggah-drumming
- Fill definition, pattern resumes, fills vary (Wikipedia); length per slot, crash with kick on beat 1, fill versus break (Maurisson): https://en.wikipedia.org/wiki/Fill_(music) , https://musichub.maurisson.com/en/guide/fills-et-breaks-a-la-batterie/ , https://www.musicradar.com/tuition/tech/learn-how-drum-fills-work-in-5-easy-steps-639154 (snippet), https://www.pressreader.com/australia/computer-music/20160518/281526520271381 (snippet)
- Four limbs, flam 6 to 30 ms early and quieter, roll crescendo from 1 to about 120 (Sound On Sound); loudest hits near 115, dragging a tom fill, one foot weaker (Audient): https://www.soundonsound.com/techniques/making-midi-sequencing-more-realistic-part-2-drum-parts , https://audient.com/tutorial/programming-realistic-drums/
- 110 to 120 as a realistic hard hit, flams in slow fills (URM); stronger hand or foot 2 to 15 higher, faster means quieter, tom slam split around the grid (Drum Audio Editing): https://urm.academy/5-drum-programming-tips-for-maximum-realism/ , https://www.drumaudioediting.com/post/how-to-program-drums-so-that-they-sound-and-feel-human
- Backbeats 120 to 127, ghosts 20 to 50, fast fills rising into the crash, tom fill 120, 115, 110, rimshots as the hardest hits, a snare hit moved a few ms early for urgency (Toontrack, Nail The Mix): https://www.toontrack.com/blog/how-to-program-drums/ , https://www.nailthemix.com/drum-programming-faqs , https://www.nailthemix.com/toontrack-metal-mania-ezx , https://www.nailthemix.com/getgood-drums-matt-halpern-drums-library , https://www.nailthemix.com/getgood-drums-the-invasion
- Hand and foot vocabulary (quads, groups of 3, 4, 5 and 6, double bass under the hands, unison figures), then Halpern and Postones at snippet level: https://www.drumstheword.com/free-drum-lesson-quads-four-note-linear-hand-and-foot-combinations-licks-grooves-and-ideas/ , https://mixdownmag.com.au/features/columns/6-hand-foot-combinations-to-improve-your-drumming-skills/ , https://www.drumlessons.com/drum-lessons/bass-drum-lessons/intermediate-double-bass-drum-fills/ , https://www.musicradar.com/tuition/drums/matt-halpen-guest-lesson-fills-using-paradiddles-with-hands-and-feet-580337 , https://www.scribd.com/doc/218944485/Interview-with-Jay-Postones-TesseracT-by-Sina-Najaflou
