# Fills: djent and progressive metalcore

Units: beats are quarter notes (1 to 5 in 4/4), cells are counted at the stated grid (at grid=16 cell 0 = beat 1, cell 8 = beat 3), velocity is 1 to 127 (grid digit x 14, 9 = 127). The examples share one groove: china on every beat (the keeper), snare on 3 (`feel` half), kick on 1, 1.5, 2.5, 3.5 and 4. Every recipe obeys knowledge/editing-principles.md (EP): the two or three levers with the most impact, graded by rank (section 3), a request for more never leaves a note quieter, every fill ends on its top, and the result is checked with `vibedrum diff` and `show --vel` against the acceptance tests. A recipe is a procedure and a worked answer is one example: its cells, levels and bars were read from that example's grid (where its kick is, which drums it has, how the fill is built). Another file gives other cells: read each fill of his file and decide again. Tick math assumes 140 bpm and 480 ppq: read the real values from the `show` header (one tick = 60000 / (bpm x ppq) ms).

## 1. What a fill is in the grid

A fill is a span of 0.5 to 8 beats (usual: 1, 2 or 4) that ends at a phrase boundary and shows at least two of these signs:

1. Keeper drop: the section's `keeper` lane has no hits in the span, or fewer than in the same beats one bar earlier. Both hands left the cymbal.
2. Hand departure: any `tom` hit, or snare hits at digit 6 or higher on cells that are not the backbeat of the section `feel` (normal: beats 2 and 4, half: beat 3) and that are empty in the same beats one bar earlier.
3. Kick departure: a run of 3 or more consecutive kick cells that neither repeats the bar before nor sits on `# riff` onsets, or the kick silent where the bar before had kicks. A kick row that changes every bar but follows `# riff` is a polymetric groove, not a sign.
4. Landing: beat 1 of the next bar has a `cym` hit (crash1, crash2, china) at digit 8 or 9 on the same cell as a kick at digit 8 or 9, and the groove resumes there. A fill can lack this sign (section 6).

The timekeeping pattern resumes right after a fill, and fills vary from one occurrence to the next. A departure that lasts more than 2 bars, or that repeats bar after bar, is a section (tom groove, build), not a fill. If the `# riff` row is also empty across the span it is a break (the band stops): edit it like a fill, but cells that are silent in every row stay silent.

## 2. Checking the engine's candidates

`# fills: 8:3-5 16:1-5` and the bar comment `fill=3-5` are guesses made beat by beat (FORMAT.md, "How the engine decides"): inside each section a beat is flagged when it holds more tom hits than the section's median for that beat, or at least 2 more snare hits than the median. Velocity, kick, cymbals and `# riff` are ignored. Spans are whole beats inside one bar: a fill on 4.5 to 5 prints as `4-5`, a 2 bar fill as two spans (`7:3-5 8:1-5`). Show the bar with its neighbours (`--bars 7-9`). Confirm a span when all three hold: (a) it ends within 2 sixteenth cells of a bar line, and that bar is the last of a 2 or 4 bar group counted from the section start, or the last bar of the section or of the file; (b) sign 1 or sign 2 holds; (c) its cells differ from the same beats one bar earlier. The landing (sign 4) is not part of the test. A confirmed fill whose next beat 1 holds only a hat or ride hit, or no cymbal, has a missing landing, and a fill in the last bar of the file has no landing bar at all: both are fills, section 6 says what to do. A candidate that nothing here confirms or rejects: leave it alone and say so.

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

- File case, no riff track (the header has no `# riff:` line): sign 3 loses its riff clause, and the riff accent reject, the pushed landing (section 6) and every step that says "`# riff` onsets" do not apply. Skip them and say so.
- File case, a kit with one or two toms: `# lanes` lists the drums he has. A recipe that names other tom lanes is translated to the lanes with notes, lowest to lowest, and the fill keeps its number of drums. Never merge two drums into one, never write to a tom lane that has no notes (it may be silent in his kit, unconfirmed).

## 3. Where fills go, how long, and their rank

Phrase grid: take the section bar ranges from `# sections` and cut each into 4 bar groups from its first bar. A riff reset (the `# riff` row equal to the section's first bar again) confirms a group start. Fill slots are the last bar of each group. Fills belong at the end of 4 or 8 bar phrases, the bigger ones every 8 or 16 bars, and their length signals the size of the change: 1 beat is a ripple inside a phrase, 2 beats relaunch a 4 or 8 bar phrase, a full bar marks a section change, more than a bar marks a major transition. Polymetric sections (kick and `# riff` loop a cycle that is not a whole number of bars: hand rows identical in every bar, kick row different in every bar) have one phrase, the whole 8 or 16 bar block: fill only its last bar, where the cycle is cut, and keep the kick on the riff until the fill starts.

| slot | rank | length | selector | content |
|---|---|---|---|---|
| end of bar 4 inside an 8 bar phrase | 1, pickup | 0 to 1 beat | `beats=4.5-5` or `beats=4` | keeper may stay, 1 to 4 notes (L1, L2) |
| end of an 8 bar phrase, section continues | 2, phrase end | 2 beats | `beats=3-5` | L2 to L4 |
| last bar of a section, also when the file ends there | 3, section change | 2 to 4 beats | `beats=3-5` or `beats=1-5` | L3 to L5 |
| into a chorus, the heaviest riff or a breakdown | 3, section change | 4 beats, 8 beats (2 bars) at most once per song | `beats=1-5`, 2 bars: `bars=7-8` | L5, L6, snare roll crescendo, or stab plus silent gap |
| into a quieter section | 3, soft | 0 to 2 beats | `beats=3-5` | every level one digit lower, still ending on its top, landing crash at digit 6 to 7 |

Rank comes from the slot, not from the length the file happens to have, and every edit keeps it or makes it (EP 5). It shows in four places, by a clear margin. The numbers are for a backbeat at 127. A note already in its band stays, and on a request for more nothing goes down to reach a band:

| where | rank 1 | rank 2 | rank 3 |
|---|---|---|---|
| top, the last note | 12 to 14 under the backbeat (113 to 115), and 10 under any rank 2 top the file has | 10 under the rank 3 tops (117), or the backbeat's level when the fill starts on the backbeat cell | the backbeat's level: 127 |
| body | the first strong stroke up 10 to 12, weak strokes stay | as rank 3 | weak strokes 104 or more, strong strokes 110 to 118 |
| kick under it | the kicks the groove has in that beat | under its last beat | under the strong strokes of the whole span |
| landing | one crash a digit under the entrance, or the keeper's own hit | the same | the entrance of the next section, untouched |

- A fill that starts on the backbeat cell cannot end more than 5 under that backbeat (`diff` prints the backbeat as its peak). Ranks 2 and 3 can then share a peak: the step between them is the kick and the length, and the report says so.
- Never give two fills one treatment. Two fills of one rank differ in something read from their figures: where the kick goes, which strokes are strong, how the fill ends.
- At most one fill per 4 bars. Default plan for a 16 bar section: bar 4 nothing or half a beat, bar 8 two beats, bar 12 one beat, bar 16 four beats. Size grows toward the section end (unconfirmed as a djent specific rule). No two fills in one section cell identical: if a fill bar prints as `# bar 16 = bar 8`, change one of them.
- Sections with `lock` of 85% or more (the unison band of grooves.md section 1) and a quarter note china or crash keeper (Meshuggah type): by default no stand alone fills inside. At the section end use unison hits on riff onsets (figure 7 in section 4). Haake describes his tom parts this way: the toms hit where the guitars hit, together with the kick, instead of a fill laid on top.
- Subdivision by tempo: notes per second = bpm x G / 240. Hands alone stay under about 14 per second (rule of thumb, unconfirmed): 16ths up to 210 bpm, sextuplets (grid=24) up to 140, 32nds up to 105. Above that use hand and foot patterns (figures 2 and 3 in section 4) or bursts of at most 4 cells.
- Grid caution: a bar block has one grid for all its rows, and it must hold every existing onset of the rows you write. Start from the grid `show` printed for the bar and go finer only: 16 to 32 or 48, 12 to 24 or 48, 24 to 48. Sextuplets in a bar that also has 16th notes on a written row: grid=48 (48 cells in 4/4, a 16th is 3 cells, a sextuplet is 2). Rows you do not write may sit off your grid. Other meters: beats still count quarter notes. A 7/8 bar spans beats 1 to 4.5, its last 2 beats are `beats=2.5-4.5` and a grid=16 row has 14 cells.

## 4. Vocabulary

Limb rule for everything below: at most 2 hand lanes per cell (snare, toms, hats and cymbals are all hands) plus kick. While both hands are on drums the keeper has no hits.

| # | figure | grid shape |
|---|---|---|
| 1 | descending tom run | 16ths, 2 notes per drum: snare, tom1, tom3, tom5 (L3), or as many toms as the kit has. Programmers build it by moving snare hits onto tom lanes while the hits on the beats stay on the snare |
| 2 | linear sextuplet | grid=24, per beat 4 hand cells then 2 kick cells (R L R L K K), hands walking down the drums (L4). Also groups of 3 (R L K), 4 (R L R K) and 5 (R L R L K) chained: 3 + 4 + 5 = 12 cells = 2 beats |
| 3 | quads | 2 hand cells then 2 kick cells (R L K K) at grid=16, 24 or 32 (bar 2 below). Halpern builds linear fills by splitting paradiddle type stickings between hands and feet (lesson body not read) |
| 4 | kick doubled toms | hands on 8ths, feet on 16ths under them (L5). Not 16th feet under 16th hands: that is a wall, not weight |
| 5 | flam | grace note 15 to 30 ms before a main hit, on the last 1 or 2 hits or on every slam, also between two toms (section 5) |
| 6 | snare roll crescendo | snare on every cell for 2 to 4 beats (32nds up to 105 bpm, sextuplets up to 140, 16ths above), kick on the beats, keeper row cleared, `ramp from=60 to=115` so the crash at 127 still stands over its last note (the roll is written new and flat, so the absolute ramp erases nothing). L2 is the one beat form. Two bar build: snare on quarters for 2 beats, 8ths for 4 beats, then 16ths for the last 2 beats, written in digits, the rise with `ramp scale=` (the one bar block is in song-structure.md section 10) |
| 7 | unison stabs | kick + snare + cym, or kick + snare + floor tom, on one cell, placed on `# riff` onsets, nothing or only kick between (bar 3 below, L6) |
| 8 | thirty-second burst | 4 cells at grid=32 on one drum in one half beat, 8 cells only at 105 bpm or slower (recipe "busier") |
| 9 | china punctuation | china (52) + kick on a syncopated cell inside the fill instead of a tom hit. The built in map has no stack lane: use china or splash (55) unless a custom map defines `stack*` |
| 10 | kick only, stop, gap | hands rest or hold one crash while the kick runs into the downbeat (bar 1 below). Stop: a stab, then silence to the bar line (bar 3 below) |

```vd
# bar 1, kick only: keeper stops, crash and snare on 3, then the feet run 16ths rising to 112, so the downbeat at 127 still stands 15 over them
bar 1 grid=16
crash1 49  |---- ---- 9--- ----|
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 9--- ----|
kick 36    |9-9- --9- -667 7788|
# bar 2, quads over beats 3 and 4: snare, floor tom, kick, kick. the floor tom is the heavy voice and takes the top, the weaker foot is a digit lower
bar 2 grid=16
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 9--- 8---|
tom5 43    |---- ---- -8-- -9--|
kick 36    |9-9- --9- --98 --98|
# bar 3, unison stabs on 3 and 3.75 (kick + snare + china), the second china the bigger one, then beat 4 silent
bar 3 grid=16
china 52   |9--- 9--- 8--9 ----|
snare 38   |---- ---- 9--9 ----|
kick 36    |9-9- --9- 9--9 ----|
```

## 5. Velocity and timing inside a fill

Hands of a fill: `lanes=38,tom` (`lanes=snare` would take the rim too). Read the fill in `show --vel` before choosing any number.

- Three bands, and they are walls. Body: 60 to 118. Top: 119 to 127, on one or two notes of a fill (a backbeat the fill starts on is one of them). Ghost and drag notes: 20 to 50. Metal backbeats sit at 120 to 127 and the hardest hits are rimshot samples, so a body at 120 or more is as loud as the backbeat and reads as a machine gun: 110 to 120 sounds closer to a real hard hit than constant 127. Never `min=` or `set=` on a whole fill. `set=` is for one note, with its pitch named.
- Strong and weak strokes are read from the figure, not from cell parity (EP 10). Strong: the first note on each drum of a run, the tom each drop lands on (snare snare tom tom), the low drum in a snare and tom alternation (the floor tom is the heavy voice there, also on the "e" and "a" cells), the last note. Weak: the note that follows a strong one on the same drum. A snare pair that returns between two toms leads with half an accent. A strong stroke sits a digit over the weak ones (12 to 15: sources say 2 to 15, but under 7 both hands trigger the same sample layer in most libraries). Weak strokes that already sit over 104 stay: the margin is then what the wall at 118 leaves, and the weight comes from the kick and the top.
- Raise, do not lower. On a request for more (heavier, bigger, busier, longer) no fill note ends under its old level: the shape comes from raising the strong strokes with a written digit or `vel ... add=`, the weak ones stay or rise less. Lowering the weak strokes (`accent SPAN lanes=38,tom grid=16 pattern=-1 mix=0.15`: the odd cells about 10 down, `pattern=1-` for the even ones) belongs to Lighter only. `accent` works by cell, not by drum: look at which drum sits on the cells it hits.
- The backbeat cell. A fill that starts on the backbeat cell of the feel (beat 3 in `half`) keeps that backbeat at the level of the section's other backbeats, and every shaping op starts one cell later (`beats=3.25-5`). A file that holds a fill level note there instead (98 where the other bars have 127): a request for more writes it back to full (digit 9), a request for less scales it with the fill, so the fill still ends on its top.
- A run climbs. Three or more notes in a row on one drum rise toward the next drum instead of leaning: `ramp SPAN lanes=38 scale=A-B` with A at 1 or more and B higher (EP 18), 8 to 16 from the first note to the last. `ramp from= to=` writes absolute values and flattens: only for a roll you just wrote flat. Speed: the faster one drum is played, the quieter it gets. Above 12 notes per second on one drum pull the whole run down to 100 to 115 (threshold unconfirmed).
- Top by rank (table in section 3): the last note of the fill, on the lowest drum the fill has. It is one note, so a digit 9 or `set=` with the pitch named (`vel bars=4 beats=4.5-4.75 lanes=48 set=115`).
- The ending. The top is the last note and a strong stroke. When the landing needs air (section 6) the last 16th comes out and the top sits alone on the 8th cell before it, the leading hand, with the kick under it. A fill that runs to the bar line on two notes of one drum ends on a rising double (the leading hand plays both): the first a strong stroke, the last the top, 8 to 12 over it. Never two equal 127s, never a weak stroke after the top.
- Kick under a fill: the lane's own level (`x` in a bar block writes it). In runs of 16ths or faster the weaker foot is one digit lower (`98`). "Heavier" never raises the kick.
- Flam: grace note 6 to 30 ms before the main note and quieter. Use 15 to 30 ms: 17 to 34 ticks at 140 bpm and 480 ppq (one tick is 0.89 ms, one 32nd cell is 60 ticks). Classic flam: grace at 45 to 75. Heavy flat flam: grace at 84 to 104. Above 40 ms it reads as two notes (the velocities and the 40 ms limit are unconfirmed). A grace closer than ppq/24 ticks to its main hit shares its cell: there a new digit scales both hits and `-` deletes both. A wider grace makes `show` print the bar at grid=32 or 48 from then on (bar 6 below prints at grid=48, the grace one cell before the main hit). Tom slam (two drums on one cell): one tom 10 to 12 ticks early, the other the same amount late, kick on the grid.
- Feel: this style is edited tight, so fills stay on the grid: no `humanize time=`, and no `humanize vel=` on a fill whose notes have designed levels (a spread small enough to keep differences of 6 to 12 stays inside one sample layer). Only on request: toms 4 to 10 ticks late (`shift ... lanes=tom ticks=6`) drag into a section, a snare run 3 to 6 ticks early adds urgency (tick amounts unconfirmed). Keep the kick on the grid when `lock` is 70% or more.

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

- Landings have ranks too: no landing is bigger than the entrance of its own section or than the first hit of the song (EP 6). Inside a section (after a rank 1 or 2 fill): one cymbal plus kick on beat 1 of the next bar. A china or ridden crash keeper hit at digit 8 or 9 on that beat 1 is the landing: add nothing. Hat or ride keeper: crash1 or crash2. An existing landing keeps its level.
- Missing landing: beat 1 after a confirmed fill holds only a hat or ride hit, or no cymbal. A fill request for more or for another figure (Heavier, Busier, Longer, More tom, More interesting, Less cheesy) repairs it in the same script (EP 23): one crash at digit 8, a digit under the section's entrance crash (112 under 127), over the kick on that cell (`x` if there is none). The crash replaces the keeper hit on that cell: the hat or ride hit becomes `-`, the keeper resumes on its next cell. It changes a bar outside the fill: report it. Lighter, Simpler, Shorter and requests that are not about fills add nothing and mention it. A bar that prints as `# bar 5 = bar 3` needs its own `bar 5 grid=16` line.
- The landing stands over the fill: 10 or more over the fill's last note, or air before it. Compare the landing cymbal with the top you plan. Room (a top of 115 into a keeper or crash at 127, a fill left at 98 into a crash you add at 112): the fill runs to the bar line. No room (a top of 127 into a crash at 127, a top of 115 into a crash you add at 112): air. The last 16th of the fill comes out (`-` in the bar block), the top moves onto the 8th cell before it with the kick under it, and the landing comes after a 16th of silence. One hand note goes: report it. A fill that already ends on an 8th cell has its air.
- Section start (after a rank 3 fill): the crash + kick that are there, at their level. A stack (crash1 + china or crash1 + crash2, both hands, so no snare on that cell) belongs only here, and only when the first hit of the song is itself a stack, he asks for bigger landings, or the request is about that section's entrance or impact (song-structure.md section 4): otherwise the landing would outrank the opening. Never bring a section's keeper cymbal in before its first bar: no china landing inside a hat verse. Both hands travel to a stack, so at 16ths from 120 bpm up the last cell before it is empty or belongs to the kick.
- A fill in the last bar of the file has no landing bar and no op can add a bar. Leave the landing out, say so, and let the fill run to the bar line on its top. Bar 1 is its landing only if he says the clip loops.
- Into a quiet section soften it: crash at 84 to 98 with kick at 100.
- Pushed landing (unconfirmed, common practice, needs a riff track): if `# riff` has an onset on the last 8th or 16th of the fill bar and none on the next beat 1, add crash + kick on that cell. The crash on the next beat 1 stays unless he asks to remove it.
- The bar after is the plain groove from beat 2 at the latest: no leftover toms or extra snares in beats 1 to 2, ghost notes return from beat 2. Write only the rows you change, rows you leave out stay as they are. A `copy` that covers this bar goes before its bar block, never after.

## 7. Intensity ladder for one slot

One slot, `bars=4 beats=3-5`, six versions from lightest to heaviest. Beats 1 to 2 are the unchanged groove. The slot is a pattern, not a range: map it to the confirmed span you are editing and look at what that bar holds. Each version is shaped as section 5 says, ends on its top, and has at most two hand notes at 127 (the backbeat on 3 counts). On a real song write only the rows you change, always write the keeper row so its cells in the span are cleared, and clear every other hand lane the groove leaves in the span (`delete bars=4 beats=3-5 lanes=hh,hh_open,ride`, ghost snares by writing the snare row). Tom lanes: the ones his kit has (section 2).

L1 pickup, rank 1. Keeper stays, two snare 16ths at 4.5 and 4.75, a rising double (98, 112). No digit 9 in a pickup: the keeper hit at 127 on the next beat 1 stands 15 over it.
```vd
bar 4 grid=16
china 52   |9--- 9--- 9--- 9---|
snare 38   |---- ---- 9--- --78|
kick 36    |9-9- --9- --9- 9---|
```
L2 snare build. Keeper leaves beat 4, four snare 16ths rising 70, 84, 98, 112.
```vd
bar 4 grid=16
china 52   |9--- 9--- 9--- ----|
snare 38   |---- ---- 9--- 5678|
kick 36    |9-9- --9- --9- 9---|
```
L3 tom run. Keeper leaves beats 3 and 4, two 16ths per drum going down, strong strokes 112 over weak strokes 98, the kick under the strong strokes after the backbeat. The top sits alone on the floor tom on the last 8th and the last 16th is empty: air before a landing at 127.
```vd
bar 4 grid=16
china 52   |9--- 9--- ---- ----|
snare 38   |---- ---- 97-- ----|
tom1 50    |---- ---- --87 ----|
tom3 47    |---- ---- ---- 87--|
tom5 43    |---- ---- ---- --9-|
kick 36    |9-9- --9- --9- 9-9-|
```
L4 linear sextuplets, the busiest. Per beat four hand cells then two kick cells, 12 notes in 2 beats. The hands end on the top, the weaker foot is the last note before the landing.
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

Hand cells in the fill: L1 2, L2 4, L3 7, L4 8 plus 4 kick cells, L5 4, L6 3. Density peaks at L4, weight keeps rising to L6. The two requests move different controls:

| control | heavier | busier |
|---|---|---|
| hand notes in the span | same or fewer: a last 16th out for air, 8ths, 3-3-2 slams | more: 16ths, then sextuplets, then 32nds |
| drums | the same drums, the top on the lowest one the fill has, both hands on one cell | any, usually more drums, single strokes |
| kick | under the strong strokes on 8th cells, or 16ths under hands that play 8ths. Never 16ths under 16th hands | only in the gaps between hand notes (linear) |
| velocity | raised, never lowered: strong strokes a digit over the weak ones, the backbeat cell at full, the top by rank on the last note, no ghosts, a flam on the top | existing notes untouched, added notes a digit under the notes around them, the last note still the top |
| relation to the riff | kicks and hits on `# riff` onsets, china + kick stabs, landing by rank | independent of the riff |
| grid | 16 or coarser | 24 or 32 |

## 9. Recipes

Every recipe is a procedure. Read each fill in `show --vel`: its drums, its figure, the kick row under it and in the bar it otherwise repeats, the bar after it. Name its rank (section 3). Then write lines for that fill. The worked answers show this reading on example files. Another file gives other cells, and a second fill of the same rank is read again and gets lines of its own. The bulk `fills` selector is only for a step with no shape in it (deleting ghosts), and only when every span in `# fills` is confirmed and none is missing. Script order (EP 16): bar blocks, `remap`, `delete`, then `vel`, then `ramp scale=` and `accent`. Adding or removing a note needs a bar block. A fill with a missing landing gets it in the same script, or a mention, as section 6 says. Then run `vibedrum diff ORIGINAL RESULT` and `show RESULT --vel` on the changed bars and go through the acceptance tests of the principles: no fill note quieter on a request for more, every `# fills` line with last within 5 of peak, pickup peaks 10 or more under the fills that end a section, no two fills with one velocity sequence, each landing 10 over the last fill note or after air, `# bars changed` holding only the fill bars and the landing bars you name. A recipe that only adds, removes or moves notes leaves levels alone: a file that was flat stays flat in level, and the report says so in a clause. Report in two or three lines: what went up or down, notes added and removed with their count, bars touched outside the fills, what a file case skipped (no riff track, no landing bar).

**Heavier.** Weight, not more hand notes and not maximum level. Three levers in order of impact, all three in one script, each fill read from its own grid. Nothing ends under its old level.
1. Weight under the fill: in djent the hole under a fill is the main reason it sounds light. Compare the kick row in the span with the same beats of the bar it otherwise repeats (two bars back in a 2 bar groove).
   - A hole (the span is empty where that bar has kicks). A pickup takes the kicks the groove has in that beat. A longer fill takes `x` under strong strokes on 8th cells, rank 2 in its last beat only, rank 3 over the whole span: a straight run on every 8th cell that holds a hand note, drops (snare snare tom tom) on the cell each drop lands on. The backbeat cell stays as the groove has it.
   - A kick is already under the fill: leave the row. Those beats rest in the other bars too (a breakdown riff rest), or the fill is a stop or a gap: no kick.
   - Riff track: the lock decides, not the strokes. The kick goes only where `# riff` has an onset in the span: every onset of a syncopated riff (the groove's own kick coming back under the hands), the 8th cells of a riff in straight 16ths. A cell where the riff rests stays empty, unless the riff is silent through the whole span: then as with no riff track. Never remove a kick that sits on a riff onset.
   - Never a kick carpet (16th kicks under 16th hands, beyond a pair the riff itself holds), never a level change on the kick. Count the kicks for the report.
2. Level by rank, raising only (table in section 3, strokes in section 5): the backbeat cell back to full, strong strokes a digit over the weak ones, a run climbing, the low drum over the snare in an alternation, the top by rank on the last note. A rank 3 fill is up from its first note, not only in its last beat.
3. The ending and the landing (section 6): air where the landing cannot stand 10 over the top, the missing landing added.

Ceiling (fill notes already at 119 or more): level has no room and nothing comes down. Levers 1 and 3 are the answer, and the ranks then differ by kick, air and landing, not by peak: say so. Then the list below. Asked again, one per request: (4) fewer and bigger notes, rank 3 only: L5 or L6 built from the drums the fill has; (5) the top onto the low drum for a fill that never reaches it: one `remap` of its last tom note onto the lowest tom lane with notes in `# lanes`, only when no drum leaves the fill (one drum more is fine), never a whole lane; (6) a flam on the top (section 5); (7) with a riff track: hits moved onto `# riff` onsets. Never a kick carpet, a `min=` floor, a lowered weak hand or a stack on every landing.

Worked answer on a flat two tom file. The comments say what was read and why each cell and number was chosen.
```vd
# said back: heavier fills by weight: a kick under both fills, the long one up from its first note with its backbeat at full, each ending on its top, and a crash for the bar 4 fill to land on. the last 16th of each fill goes so the crash lands after a breath
# read: hat section bars 1-8, opens on crash + kick at 127, backbeats 127, kick lane 127. bar 9 opens the next section on crash + kick at 127. toms in # lanes: tom2, tom5. no riff track. every fill note 98
# fill 4:4-5, rank 1: snare snare tom2 tom2. its kick row is empty in beat 4 where bars 2 and 6 hold 9-9-: a hole. bar 5 beat 1 is hat + kick: the landing is missing
# fill 8:3-5, rank 3: four snares from the backbeat cell, tom2 tom2, tom5 tom5, one straight run. kick row empty in beats 3 and 4. it lands on a crash at 127
# notes first. bar 4: the kicks the groove has there. its last 16th goes: the crash it will land on is 112, not 10 over any top
bar 4 grid=16
tom2 48    |---- ---- ---- --7-|
kick 36    |9--9 -99- -9-- x-x-|
# bar 8: backbeat cell 9, kick on the 8ths after it (this groove leaves its backbeat bare), the strong tom2 stroke 8, the top 9 alone on the floor tom. its last 16th goes: the crash in bar 9 is 127, the same as the top
bar 8 grid=16
snare 38   |---- ---- 9777 ----|
tom2 48    |---- ---- ---- 87--|
tom5 43    |---- ---- ---- --9-|
kick 36    |9--9 -99- --x- x-x-|
# bar 5 printed as "= bar 3": one crash a digit under the bar 1 entrance over the kick that is there, the hat leaves that cell
bar 5 grid=16
crash1 49  |8--- ---- ---- ----|
hh 42      |--7- 7-7- 7-7- 7-7-|
# level. pickup: top 12 under the backbeat on its last note, its first stroke up 10, the weak stroke stays: 108 98 115
vel bars=4 beats=4.5-4.75 lanes=48 set=115
vel bars=4 beats=4-4.25 lanes=38 add=10
# long fill: the three snares after the backbeat are a run and climb 106 110 114 into the toms, the tom2 pair goes up 6: 127 106 110 114 118 104 127
ramp bars=8 beats=3.25-4 lanes=38 scale=1.08-1.16
vel bars=8 beats=4-4.5 lanes=48 add=6
```
The same three levers on two other figures give other lines:
```vd
# read: china section bars 1-8, china and kick 127, backbeats 127, bar 8 is the last bar of the file. every fill note 98
# fill 4:4-5, rank 1: snare and tom5 alternate, snare on the 8th cells. the kick row already has 9-9- under the snares and the other bars rest between them: lever 1 adds nothing. the floor tom is the heavy voice: its first note up 12, its last note the top, the snares stay: 98 110 98 115. bar 5 beat 1 is china + kick at 127, 12 over the top: no air, no landing to add
vel bars=4 beats=4.75-5 lanes=43 set=115
vel bars=4 beats=4.25-4.5 lanes=43 add=12
# fill 8:3-5, rank 3, ends the section and the file: snare snare tom2 tom2 snare snare tom5 tom5, two drops. kick under the tom each drop lands on. backbeat cell 9, tom entries 8, top 9 on the last note: nothing follows, so no air and a rising double on the floor tom
bar 8 grid=16
snare 38   |---- ---- 97-- 77--|
tom2 48    |---- ---- --87 ----|
tom5 43    |---- ---- ---- --89|
kick 36    |9-99 -9-9 --x- --x-|
# everything between the two 127s up 6 (weak strokes 104, tom entries 118), the snare between the drops 6 more so the toms stay over it: 127 104 118 104 110 104 118 127
vel bars=8 beats=3.25-4.75 lanes=38,tom add=6
vel bars=8 beats=4-4.25 lanes=38 add=6
```

**Lighter.** Less weight, same placement, down only: nothing in the fill gets louder. (1) Level down by rank, 14 to 24 on the body, never under 60. Ranks already 10 apart: one factor for all (`scale=0.85`). A flat file: 0.86 for ranks 2 and 3, 0.76 for rank 1, so the rank is made on the way down. A fill note on the backbeat cell at the fill's own level scales with it, a real backbeat stays (`beats=3.25-5`). (2) Shape, only for a flat fill: its weak strokes a digit further down, read per figure (section 5), the last note left out of the window so the fill still ends on its top. A run starts a little lower and climbs back. (3) Kick: delete only the fill's own run under the hands. Kicks that the bar it repeats also has, or that sit on `# riff` onsets, stay. Asked again: the landing crash of a rank 1 or 2 fill one digit down, never a section entrance, then one ladder level down. Toms are not moved up: on most kits that merges drums. Below: the first worked file of Heavier, untouched.
```vd
# said back: lighter fills: every fill note down, the pickup most, the weak hand a digit under, each fill still ending on its strongest note. no notes removed
vel bars=8 beats=3-5 lanes=38,tom scale=0.86
vel bars=4 beats=4-5 lanes=38,tom scale=0.76
# weak strokes: in both fills the second note of each pair, on the odd cells. the last note is outside the window
accent bars=4 beats=4-4.75 lanes=38,tom grid=16 pattern=-1 mix=0.15
accent bars=8 beats=3-4.75 lanes=38,tom grid=16 pattern=-1 mix=0.15
# bar 8 is one run: its snare half starts lower and climbs back
ramp bars=8 beats=3-4 lanes=38 scale=0.9-1
```
**Busier.** More hand notes per beat, existing notes untouched, graded by rank: a pickup gets one note, a long fill a burst. One rung per request: (1) the empty cells of the span: a kick where both neighbours are hand notes, else a hand note on the drum of the note before it, one digit under it; (2) span full at grid=16: 32nd notes. Rank 1: one 32nd before a note of its last half beat. Ranks 2 and 3: a burst of 4 cells in one half beat. New cells sit a digit under the notes around them, a new last note takes the level of the old last note so the fill still ends on its top, and nothing new comes after a top. Two long fills get their burst on different half beats; (3) rewrite it as L4 at grid=24. Check the tempo cap (section 3). Below: L3, the burst on the tom3 pair before the top.
```vd
bar 4 grid=32
tom3 47    |---- ---- ---- ---- ---- ---- 8676 ----|
```
**Simpler.** Fewer notes, levels untouched. (1) Each drum keeps one note, on the 8ths. Runs of two notes per drum: the second of each pair goes (the two lines below mark the odd cells with digit 1 and delete what is marked; ghosts and graces go first with `delete ... v=1-62`). A snare and tom alternation has its low drum on the odd cells and the mask would take the whole drum: write that bar by hand and keep the first snare and the last low drum note. (2) One ladder level down. Below: rung 1 on L3, leaving 127, 112, 112, 127 on snare, tom1, tom3, tom5.
```vd
accent bars=4 beats=3-5 lanes=38,tom grid=16 pattern=-1
delete bars=4 beats=3-5 lanes=38,tom v=1-20
```
**Longer.** Double the span backwards (1 to 2 beats, 2 to 4 beats, 4 beats to 2 bars). The old fill stays as the tail. The new front has half the density, rises, stays a digit or more under the tail and continues the figure: a run takes the same drum on 8ths, drops take one more drop at half speed, an alternation takes its low drum. The keeper stays under it (one hand each at 8ths) and leaves only a cell where both hands are on drums. A backbeat in the front stays at full, the kick row is not touched. It must not outrank the last fill of its section. For 2 bars put an L1 or L2 in the previous bar. Below: L3 extended to the whole bar.
```vd
bar 4 grid=16
snare 38   |--5- 6-7- 97-- ----|
```
**Shorter.** Keep the tail and restore the groove in the front: rows as in the same beats of the bar it otherwise repeats, the backbeat back at full. Never keep the front and cut the tail: the tail carries the top and the landing. A drum that lived only in the front goes with it: say so. A 1 beat pickup is already the shortest slot: leave it unless he names it. `diff` still measures the old span, so its peak is the backbeat you restored: read the tail in `show --vel`. Below: L3 cut to beat 4.
```vd
bar 4 grid=16
china 52   |9--- 9--- 9--- ----|
snare 38   |---- ---- 9--- ----|
delete bars=4 beats=3-4 lanes=tom
```
**More interesting.** For a fill that has a shape: a flat one gets Heavier lever 2 first. One change per fill, a different one on each, drums and descent kept, the top still the last note: (1) accents regrouped 3-3-2 between the backbeat and the top: one stroke a digit over taps at the weak level (on L3: 127, 98, 98, 112, 98, 98, 127); (2) a hole: one weak stroke out; (3) weak hand lead (Haake starts fills on the hand that should not lead, so the accents land on the "wrong" drums): the strong strokes one cell later; (4) china + kick in place of one tom hit that is not the top; (5) with a riff track: hits only on `# riff` onsets.

**More tom.** Move snare notes of the fill onto toms by position, high to low, levels untouched. The backbeat cell and the note after it stay on the snare for crack. One `remap` per tom lane that has notes in `# lanes`, the lowest last. A two tom kit takes only the last two remaps. Two fills do not end up as one figure: move a different pair in each. Below: a shaped snare run becomes L3.
```vd
bar 4 grid=16
snare 38   |---- ---- 9787 879-|
remap bars=4 beats=3.5-4 lanes=38 to=tom1
remap bars=4 beats=4-4.5 lanes=38 to=tom3
remap bars=4 beats=4.5-5 lanes=38 to=tom5
```
**Less cheesy.** Cheesy in the grid: a full bar of 16ths, 4 notes per drum from the snare down through the toms, flat velocity, no kick under it, repeated every 4 bars. In order of impact: (1) Heavier levers 1 and 2, the kick and the shape; (2) Shorter: keep the last 2 beats; (3) every second such fill gets one More interesting change, so no two are alike.

## Sources and unconfirmed items

Unconfirmed (working numbers of this document, not found in a source): the sign thresholds in sections 1 and 2 and the `lock` cutoffs 70% and 85%; the 14 notes per second hand cap, the 12 per second velocity threshold and the tempo limits derived from them; the 16 bar fill plan and the once per song 2 bar fill; the three ranks and their numbers (tops 113 to 115, 117 and 127, weak strokes 104, strong strokes 110 to 118, the body wall at 118, lifts of 6 to 12, the Lighter factors, the landing a digit under the entrance); which fill requests repair a missing landing; the strong over weak margin of 12 to 15 and every size taken from the blind trial judges (10 between ranks, 10 from fill to landing, sources allow 2 to 15); the 16th of air before a landing and the rising double; where the kick goes under each figure; flam grace velocities and the 40 ms limit; the ramp start of 60; shift and slam amounts in ticks; the pushed landing; the two bar build layout; whether unused tom pitches sound in a given kit. Seen only as search snippets (page bodies not retrievable): Halpern's paradiddle lesson, the MusicRadar and Computer Music fill articles, the Postones interview. Engine behaviour: how candidates are found, the ppq/24 tolerance and script order are in FORMAT.md ("How the engine decides"). How flams print and the lower median of the candidate rule were read from `core/vibedrum.cpp`: recheck them if the engine changes. Heavier, Lighter, Busier, Simpler, Longer, Shorter and More tom were run on a 16 bar, 130 bpm, two tom file with flat fills and no riff track and checked with `diff`. More interesting and Less cheesy were not run. Nothing here was run on a file with a riff track: every riff clause is unconfirmed.

- Haake: toms on the guitar hits with the kick, rimshots (Drum Magazine); ghost notes between accents (Drumeo, Modern Drummer); fills started on the weak hand (substack): https://drummagazine.com/tomas-haake-meshuggahs-djentle-giant/ , https://www.moderndrummer.com/2013/06/web-exclusive-interview-with-meshuggahs-tomas-haake/ , https://www.drumeo.com/beat/meshuggah-tomas-haake-genius/ , https://asiwalkintothesettingsun.substack.com/p/clockworks-by-meshuggah-drumming
- Fill definition, pattern resumes, fills vary (Wikipedia); length per slot, crash with kick on beat 1, fill versus break (Maurisson): https://en.wikipedia.org/wiki/Fill_(music) , https://musichub.maurisson.com/en/guide/fills-et-breaks-a-la-batterie/ , https://www.musicradar.com/tuition/tech/learn-how-drum-fills-work-in-5-easy-steps-639154 (snippet), https://www.pressreader.com/australia/computer-music/20160518/281526520271381 (snippet)
- Four limbs, flam 6 to 30 ms early and quieter, roll crescendo from 1 to about 120 (Sound On Sound); loudest hits near 115, dragging a tom fill, one foot weaker (Audient): https://www.soundonsound.com/techniques/making-midi-sequencing-more-realistic-part-2-drum-parts , https://audient.com/tutorial/programming-realistic-drums/
- 110 to 120 as a realistic hard hit, flams in slow fills (URM); stronger hand or foot 2 to 15 higher, faster means quieter, tom slam split around the grid (Drum Audio Editing): https://urm.academy/5-drum-programming-tips-for-maximum-realism/ , https://www.drumaudioediting.com/post/how-to-program-drums-so-that-they-sound-and-feel-human
- Backbeats 120 to 127, ghosts 20 to 50, fast fills rising into the crash, rimshots as the hardest hits, a snare hit moved a few ms early for urgency (Toontrack, Nail The Mix): https://www.toontrack.com/blog/how-to-program-drums/ , https://www.nailthemix.com/drum-programming-faqs , https://www.nailthemix.com/toontrack-metal-mania-ezx , https://www.nailthemix.com/getgood-drums-matt-halpern-drums-library , https://www.nailthemix.com/getgood-drums-the-invasion
- Hand and foot vocabulary (quads, groups of 3, 4, 5 and 6, double bass under the hands, unison figures), then Halpern and Postones at snippet level: https://www.drumstheword.com/free-drum-lesson-quads-four-note-linear-hand-and-foot-combinations-licks-grooves-and-ideas/ , https://mixdownmag.com.au/features/columns/6-hand-foot-combinations-to-improve-your-drumming-skills/ , https://www.drumlessons.com/drum-lessons/bass-drum-lessons/intermediate-double-bass-drum-fills/ , https://www.musicradar.com/tuition/drums/matt-halpen-guest-lesson-fills-using-paradiddles-with-hands-and-feet-580337 , https://www.scribd.com/doc/218944485/Interview-with-Jay-Postones-TesseracT-by-Sina-Najaflou
