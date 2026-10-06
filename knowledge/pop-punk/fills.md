# Fills: pop punk

Units: beats are quarter notes (1 to 5 in 4/4), cells are counted at the stated grid, velocity is 1 to 127 (grid digit x 14, 9 = 127). Everything is written in fast notation (section 1) at 180 bpm and 480 ppq: a 16th cell is 120 ticks or 83 ms, one tick is 0.69 ms (ms = ticks x 60000 / (bpm x ppq)). Read the real `ppq` and `# tempo:` from the `show` header. The examples share one groove (hh on 8ths as the keeper, snare on 2 and 4, `feel` normal, kick on 1, 2.5 and 3), and the worked answers of section 10 share one example file, described in recipe Bigger: a pickup in bar 2, a fill into a new section in bar 4, the biggest fill in bar 6. A recipe is a pattern, not a script to paste (EP 20): every worked answer names the grid it was written for and says how its cells, levels and bars were read from that grid. Another file has its kick, its drums and its fills elsewhere and gets other lines. "EP 9" is rule 9 of `knowledge/editing-principles.md`. Every recipe follows it: the two or three levers with the most impact, graded by rank (section 4), closed by the shape step (section 6), and checked with `vibedrum diff` and `show --vel` against the acceptance tests before the report.

## 1. Which notation the file uses
| | fast notation | slow notation |
|---|---|---|
| `# tempo:` | 150 to 220 | 75 to 110 |
| `feel` of the main beat | `normal`: snare on 2 and 4 | `double`: snare on 1.5, 2.5, 3.5, 4.5 |
| keeper row at grid=16 | every second cell (8ths) | every cell (16ths) |
| half time chorus, bridge, breakdown | `half`: snare on 3 | `normal` |
| real double time: snare on every offbeat 8th of the fast pulse (skate punk and hardcore speed, in this style short bursts only) | `double` | `blast`: 8 snares per bar on the off 16ths |
| 16th note fill, sextuplets | grid=16 (4 cells per beat), grid=24 | grid=32 (8 cells per beat), grid=48 |
| phrase | 8 bars | 4 bars |
| 2 beat fill slot at a phrase end | `beats=3-5` | `beats=4-5` |

The standard fast beat of the style (kick, snare, kick, snare under steady hats) is written both ways. Decide which one the file uses before reading any fill: beat numbers, grids, bar counts and the meaning of `feel` all change. Test: snare backbeats per minute = bpm x 0.5 for `normal`, bpm x 1 for `double`, bpm x 0.25 for `half`. 75 to 110 is the standard beat in either notation, 37 to 55 is half time, 150 to 220 is real double time, 47 to 75 is a mid tempo song with the snare on 2 and 4 (Down at 94 bpm, Adam's Song at 136, All The Small Things at about 150, tempos from grooves.md and dynamics-and-feel.md): read it as fast notation. Where 47 to 55 overlaps half time the `feel` label decides: `half` is half time, `normal` is a slow song. A 75 to 110 file whose sections are all `normal` is a slow song, not half time. Song transcriptions mostly use fast notation (Basket Case at about 174 bpm with the snare on 2 and 4, 180 to 200 quoted for New Found Glory, Green Day and blink-182 songs). Beat lessons often write the same beat slow, with the snare on every "and" (Drum Town), and BPM databases list Basket Case at 85 with 170 as its double time value. MIDI packs are sold at 116 to 204 bpm (Toontrack, dynamics-and-feel.md source 20), which points to fast notation as the common one. For files from other sources it is unconfirmed. Never convert a file between notations: write in the one it has. For a slow notation file convert every position in this document: slow beat = 1 + (fast beat - 1) / 2 for the first fast bar of a pair, 2 more for the second, every grid doubled, every bar count halved.
```vd
# slow notation, 90 bpm, two fast bars in one: hh on 16ths, snare on the offbeat 8ths, kick on the beats plus the groove's extra kick on 1.75 and 3.75. The L3 snare roll of section 8 sits in beat 4 at grid=32
bar 1 grid=32
hh 42      |8-7-8-7- 8-7-8-7- 8-7-8-7- --------|
snare 38   |----9--- ----9--- ----9--- 87778778|
kick 36    |9-----9- 9------- 9-----9- 9---9---|
```

## 2. What a fill is in the grid
A fill is a span of 0.5 to 8 beats (usual: 1, 2 or 4) that ends at a phrase boundary and shows at least two of the signs below. A departure that repeats for more than 2 bars is a section (tom groove, marching snare bridge, build), not a fill. A span where every drum row is `-` is a stop: it counts as a fill and its silent cells stay silent.
1. Keeper drop: the section's `keeper` lane (hh, ride, or crash1 in a chorus that rides the crash) has fewer hits in the span than in the same beats one bar earlier.
2. Hand departure: any `tom` hit, or snare hits at digit 6 or higher on cells that are not the backbeat of the section `feel` and that are empty in the same beats one bar earlier.
3. Kick change: kick on every quarter or under every hand cell where the bar before had the groove pattern, or no kick where the bar before had kicks. Kick patterns in this style follow the guitar and vary from bar to bar, so this sign never counts alone.
4. Landing: a `cym` hit at digit 8 or 9 on the same cell as a kick (or snare) at digit 8 or 9, on beat 1 of the next bar or on the and of 4 (pushed, section 7), and the groove resumes there.

## 3. Checking the engine's candidates
`# fills: 8:3-5 16:1-5` and the bar comment `fill=3-5` are guesses made beat by beat inside each section: a beat is flagged when it holds more tom notes than the section's median for that beat (taken as 0 in sections shorter than 3 bars), or at least 2 more snare notes than that median. Kick, cymbals, velocity and `# riff` are ignored, and spans are whole beats inside one bar. In fast notation the snare median is 1 on beats 2 and 4 and 0 on beats 1 and 3: the threshold is 3 snare notes on beats 2 and 4, 2 on beats 1 and 3. In slow notation it is 3 on every beat. A flam counts as 2 notes. Show the bar with its neighbours (`--bars 7-9`). Confirm a span when all three hold: (a) it ends within half a beat of a bar line and that bar is bar 4 or bar 8 of an 8 bar group counted from the section start, or the last bar of the section; (b) sign 1 or 2 holds (a missing landing does not reject it: a fill with no crash after it is still a fill, and a fill request gives it one, section 7, EP 23); (c) its cells differ from the same beats one bar earlier. Reject when any of these holds:
- Tom groove: floor tom 8ths in place of the hats in a verse, intro or bridge. The same tom cells appear in 3 of the 4 previous bars, or the bar prints as `# bar N = bar N-1`. The engine flags it whenever the toms play in half or fewer of the section's bars.
- Marching snare bridge (Barker: rudiments with accents on the snare, All The Small Things, Going Away To College): snare 8ths or 16ths with the keeper absent for 4 to 16 bars. A section. Only its last bar can hold a fill.
- Snare on every quarter for more than 2 bars: a groove or a build (figure 5), edited as one block.
- Every extra snare note is a ghost (digit 1 to 4) under a running keeper, or the span sits in beats 1 to 2 of the first bar of a section (the tail of a landing, snare with the crash on beat 1).

Fix the edges before editing. The engine's edges are whole beats: the real start is the first cell where the keeper goes missing or the first tom or off backbeat snare, often an offbeat (the First Date intro fill starts on the "and" of 4 in the Drums The Word transcription). A snare run on 8ths prints in fast notation as two spans, `8:1-2 8:3-4`, because beats 2 and 4 stay under the threshold: it is one span 1-5. The candidates miss the types below: scan bars 4 and 8 of every 8 bar group and the last 2 bars of every section for them yourself. A stop or a silent bar is a finished fill: for "bigger" or "busier" add at most a pickup in its last beat and leave the silence.

| type | what the grid shows | why the engine misses it |
|---|---|---|
| band stop | crash + kick (+ snare) on one cell, then every row `-` to the bar line, `# riff` empty over the same cells | no extra snare or tom |
| stabs, kick and crash unisons | 2 to 6 cells of crash or china + kick (+ snare) on `# riff` onsets or on the quarters, all rows empty between | kick and cymbals are ignored, at most 1 snare per beat |
| two note pickup | snare on 4 and 4.5, keeper may continue | 2 notes on a backbeat beat is under 3 |
| flam pickup | one snare flam on a backbeat: two snare notes less than a cell apart. Closer than ppq/24 ticks they print as one cell, wider the bar prints at grid=32 or 48 with a lower digit one cell before a 9 | same |
| quarter or 8th build | snare on every quarter for 1 to 4 bars: missed. Snare on every 8th: only beats 1 and 3 flagged. With tom5 doubled on the same cells it is flagged through the toms | 1 or 2 snares per beat |
| silent bar | `# bar N empty` before a section start | nothing to count |

## 4. Where fills go, how long, and their rank
| slot (fast notation) | rank | length in beats | selector | content |
|---|---|---|---|---|
| bar 4 of an 8 bar group | 1 | 0 to 1 | `beats=4-5` | nothing, L1, L2, or one crash + kick on a `# riff` accent |
| bar 8, section continues (verse under vocals) | 2 | 1 to 2 | `beats=4-5`, `beats=3-5` | L1 to L3 |
| verse into pre-chorus, chorus into verse | 3 | 2 | `beats=3-5` | L2 to L5. Into a quieter section a shorter fill (1 to 2 beats) or a stop. It still ends on its top (EP 9): do not fade it out |
| into a chorus, from a verse or a pre-chorus | 3 | 2 to 8 | `beats=3-5`, `bars=8`, `bars=7-8` | L3 to L6, the build (figures 4 and 5), or stabs and a pickup (figure 9) |
| bridge into the last chorus | 3, the biggest | 4 to 8, or a silent bar | `bars=8` | the biggest fill of the song: L6, the 2 bar build, or a stop |
| into a half time breakdown | 3 | 2 to 4 | `beats=3-5` | the easycore ending of recipe Heavier: unisons, then air |
- Phrase grid: take the section bar ranges from `# sections` and cut each into 8 bar groups from its first bar (a `# riff` row equal to the section's first bar again confirms a group start). Bar 8 of a group is a fill slot, bar 4 a half slot. Fills close one part and lead into the next, usually within one or two bars (Native Instruments). Rock fills come as a full bar, a half bar or a quarter bar, and the quarter bar is small enough to duck under a vocal line (Drumeo). How often is a per song choice and the sources disagree even on Basket Case: few and sharp, a quick tom run back into the downbeat (Drum Ninja), against rapid, tight fills throughout that never overplay (Drumhead Authority). Both describe them as short.
- Rank comes from the slot, not from the length the file happens to have, and every edit keeps it (EP 5): a pickup inside a phrase stays smaller than a phrase end fill, which stays smaller than the fill into a new section. One fill is the biggest of the song: the last rank 3 fill that has a landing bar, usually bridge into last chorus. A fill in the last bar of the file ends the song and takes the rank 3 top whatever its length. Rank shows in four places: length, the top (section 6: a rank 3 fill ends on 117 under an entrance at 127, each lower rank peaks 10 or more under the one above), the weight under the fill (which levers of a recipe it takes, section 10) and the landing (section 7). Two fills of one rank still differ in one designed thing: the drum that carries the top, the cells of the lean, or the size of the rise. Never one treatment for every fill.
- At most one fill per 8 bars in a verse, one per 4 bars in a chorus. No two fills in one section cell identical: if a fill bar prints as `# bar 16 = bar 8`, change one of them (plan unconfirmed).
- Subdivision by tempo: notes per second = bpm x G / 240. Hands alone stay under about 14 per second (unconfirmed): 16ths up to 210 bpm, above that 8ths with bursts of at most 4 sixteenth cells. Sextuplets (grid=24): hands alone up to 140 bpm. Groups of 4 hand cells + 2 kick cells: up to about 135 bpm on one pedal (the two kicks are 74 ms apart there, the single pedal limit of grooves.md section 7), up to about 160 with a double pedal (easycore). In faster files the triplet figure is the 8th triplet (bpm / 20 notes per second, 9 at 180) or a 3 note ruff. No 32nds in fast notation.
- Grid caution: a bar block has one grid for all its rows and it must hold every existing onset of the rows you write. Start from the grid `show` printed for the bar and go finer only (16 to 32 or 48, 24 to 48).
- Limb rule: at most 2 hand lanes per cell (snare, toms, hats and cymbals are all hands) plus kick. While both hands are on drums the keeper row is empty. A one handed figure (L1) keeps the keeper. At 150 bpm or more no hand plays three 16th cells in a row (derived from the one handed 16th limit of grooves.md section 7, unconfirmed). Count it: any three adjacent 16th cells hold at most 4 hand notes, a unison counts 2 and the landing cymbals count too. So unisons sit on 8ths (L4), on the first cell of a run, or next to an empty 16th cell, and the last 16th before a two cymbal landing holds no hand note (EP 15). Kick, single pedal: never three adjacent 16th cells at 150 bpm or more, the landing kick included. Three in a row need a double pedal (easycore).
- Kit: use the tom lanes that have notes in `# lanes` and keep the number of voices and the descent (EP 8, 24). Kits of the style are small: Barker plays one rack tom and one floor tom, so his descent is snare, tom1, tom5. A figure written here for tom1, tom3, tom5 goes onto the toms the file has, highest to lowest. "The floor tom" in a recipe is the lowest tom lane that has notes, "the rack tom" the highest. A kit with no tom notes skips every lever that names a tom.

## 5. Vocabulary
| # | figure | grid shape (fast notation, grid=16 unless stated) | velocity |
|---|---|---|---|
| 1 | two note pickup | snare on 4 and 4.5, keeper through beat 4 (L1). Variant: 4.5 and 4.75 | the note on 4 is the backbeat and stays at full. The added note takes the top of its rank (section 6): 117 into a new section, 102 to 107 inside a phrase |
| 2 | snare roll | snare on every 16th for 1 beat (4 notes) or 2 beats (8 notes), single strokes, kick on the quarters (L2, L3). Drumeo's half bar and quarter bar snare rolls | beat cells strongest, the others 6 to 7, rising to the top of its rank on the last note |
| 3 | tom run | 16ths high to low: 4 notes per drum over a bar, 2 per drum over 2 beats, snare, tom1, tom3, tom5 (L5). With one rack and one floor tom: snare, tom1, tom5, the floor tom taking the second half | first note on each drum one digit over the second, the last drum takes the top on its last note, the note before it within 10 of it |
| 4 | unison 8ths | snare + tom5 on the same cell on every 8th, kick on the quarters (L4). Drumeo's 8th note build | digits rising 5 to 8, one digit per hit |
| 5 | quarter, 8th, 16th build | 2 bars: unison quarters for 2 beats, unison 8ths for 4 beats, snare 16ths for 2 beats (bars 1 to 2 below). 1 bar: 8ths in beats 1 to 2, 16ths in beats 3 to 4 (recipe "longer"). Layout unconfirmed | digits rising 5 to 8 (70 to 112), the 8 on the last note |
| 6 | flam accent | classic: a grace note 15 to 20 ms before a snare or tom hit. Flat flam, the form of this style (Pop Punk Drumming: the grace is dropped and a full hit is played): snare + tom5 or tom1 + tom5 on one cell (Tre Cool's flams between floor tom and snare in Basket Case). Both are in bar 5 below. Also flam then kick, alternating on 8ths or 16ths | section 6 |
| 7 | Barker singles and sextuplets | hard, fast single strokes with accents dropped anywhere, by his own account no double stroke rolls (a later Drumeo lesson shows his six stroke roll around the kit, sometimes with a kick double at the end: same cells, accents on notes 1 and 6). 16ths with the accents moved off the beat (`pattern=86866868`: the last note is an accent). Sextuplets at grid=24: 4 hand cells then 2 kick cells per beat (bar 4 below, tempo limits in section 4). In a fast file the triplet figure is the 8th triplet: grid=24, every second cell, per beat hand, hand, kick (snare `8-----`, tom5 `--7---`, kick `----8-`). 3 note ruff: 3 sextuplet cells into an accent | accents 8, others 6 to 7 |
| 8 | linear hand and foot | a kick takes the place of a hand note, hands and kick never on the same cell: 2 hands + 2 kicks, 3 hands + 1 kick, groups of 3 (kick, tom5, snare). All The Small Things: 3 hand notes on different drums, kick, snare + half open hat, kick, the same 6 cells again, then 4 snare 16ths (slot form: recipe "more Travis Barker") | hands 7 to 8, kick 8 to 9 |
| 9 | stabs and stop | crash + snare + kick on quarters or on `# riff` onsets, all rows empty between (bar 3 below). Stop: one stab, then silence to the bar line | 112 to 127, the last stab the strongest |
| 10 | tom and kick gallop | per beat: tom5 on cell 1, kick on cells 3 and 4 (tom5 `8--- 8---`, kick `--78 --78`). It ends on two kicks: land on snare + crash (section 7). Heavier form: kick also under the tom, three kick cells in a row, double pedal only | tom 8, kicks 7 then 8 |
| 11 | cymbal punctuation | crash + kick, china + kick, or hh_open + snare on one cell inside the run in place of a tom hit. Never the keeper cymbal of the section that follows (EP 6): no china stab before a china breakdown | 112 to 127 |
```vd
# bars 1-2, figure 5: snare + floor tom on quarters, then 8ths, then snare 16ths, kick on the quarters, digits rising 5 to 8 with the weaker hand one lower in the 16ths
bar 1 grid=16
snare 38   |5--- 5--- 5-5- 6-6-|
tom5 43    |5--- 5--- 5-5- 6-6-|
kick 36    |9--- 9--- 9--- 9---|
bar 2 grid=16
snare 38   |6-6- 7-7- 7676 8778|
tom5 43    |6-6- 7-7- ---- ----|
kick 36    |9--- 9--- 9--- 9---|
# bar 3, figures 9 and 1: stabs on 1, 2 and 3 (112, 112, 127), two note pickup on 4 and 4.5 (98, 112)
bar 3 grid=16
crash1 49  |8--- 8--- 9--- ----|
snare 38   |8--- 8--- 9--- 7-8-|
kick 36    |9--- 9--- 9--- ----|
# bar 4, figure 7 in the slot, 135 bpm or slower on one pedal: per beat 4 hand sextuplets then 2 kicks. It ends on two kicks, so the next bar lands on snare + crash
bar 4 grid=24
hh 42      |8--7-- 8--7-- ------ ------|
snare 38   |------ 9----- 8767-- ------|
tom1 50    |------ ------ ------ 87----|
tom5 43    |------ ------ ------ --88--|
kick 36    |9----- ---9-- ----88 ----88|
# bar 5, figure 6: classic flam on the backbeat 4 (grace written one 32nd cell early, then moved 32 ticks later: 28 ticks, 19 ms before the hit) and a flat flam on 4.5 (floor tom 10 ticks early)
bar 5 grid=32
snare 38   |-------- 9------- -------6 9---8---|
tom5 43    |-------- -------- -------- ----8---|
shift bars=5 beats=3.875-4 lanes=snare ticks=32
shift bars=5 beats=4.5-5 lanes=tom5 ticks=-10
# bars 6-7, pushed landing into a new section (section 7): the roll ends on 4.25 at 112, crash + kick at 127 on 4.5, then no crash, no kick and no hat on the next beat 1, hats back on 1.5
bar 6 grid=16
crash1 49  |---- ---- ---- --9-|
hh 42      |8-7- 8-7- ---- ----|
snare 38   |---- 9--- 7676 88--|
kick 36    |9--- --9- 9--- 9-9-|
bar 7 grid=16
hh 42      |--7- 8-7- 8-7- 8-7-|
snare 38   |---- 9--- ---- 9---|
kick 36    |---- --9- 9--- ----|
```

## 6. Velocity and timing inside a fill
- Level: the style is played loud. Backbeats are accents or rimshots, 116 to 127 (Toontrack programs backbeats at 100 to 120 with rimshots at or near maximum). Fill notes sit under the backbeats (Nail The Mix keeps fills and fast passages a little lower and saves the highest velocities for 2 and 4): 98 to 122, the start of a build down to 70, 127 only on a backbeat cell or on a top with air. Ghost notes (40 to 58 in this pack, always under 60) do not belong inside fills: the unaccented notes of a Barker type marching figure sit at 60 to 100.
- Read first, per fill, in `show --vel`: its level, its rank (section 4), the cymbal on its landing cell and that cymbal's level (section 7), and whether its first note sits on a backbeat cell (beat 2 or 4 in `normal`, beat 3 in `half`).
- Tops. A fill ends on its top (EP 9): the last note is the loudest of the fill or within 5 of it, it is a strong stroke (in a fill that moves down the kit it sits on the lowest drum), and it stays 10 or more under the cymbal it lands on, so the entrance stands above it (EP 6). Or the fill ends with air: the last 16th cell of the bar, or more, empty in every hand row and in the kick row (83 ms at 180 bpm). Air is what lets a top of 127 stand in front of an entrance at 127.

| fill | last note | loudest note |
|---|---|---|
| rank 3, running to the bar line | 10 under its landing: 117 under 127 | up to 5 over the last note: 117 to 122 |
| a rank 2 or 3 fill that ends with air (Bigger and Heavier give air to the biggest fill) | the level of the section's backbeats: 127 | the same |
| each lower rank the song has | 10 under its own landing (102 under a crash you add at 112), and its loudest note 10 or more under the loudest note of the rank above (107 under 117, with three ranks in one song 122, 112 and 102). Never under the level it has: nothing is lowered | up to 5 over the last note |
| a fill in the last bar of the file | the rank 3 top: nothing follows it and it ends the song (EP 22) | up to 5 over the last note |
- Backbeat cell. `diff` prints the loudest note of the span as the fill's peak, so a note on the backbeat cell decides how the whole fill reads. A real backbeat there (116 or more) is never lowered (EP 9): when the fill cannot end within 5 of it, say in the report that the peak `diff` prints is the backbeat. A note there at fill level, as stiff files have it: in a fill that ends on 127 with air, bring it up to the other backbeats first (`vel bars=6 beats=3-3.25 lanes=38 min=127`, the value from `show --vel`). In every other fill it is the fill's first strong stroke and takes the lean: at 127 in front of a pickup that tops at 102 it would make the pickup read as a fill that fizzles. A roll that only passes a backbeat cell leans on it like on any beat cell.
- Strong strokes are read from the figure, never from cell parity (EP 10). A roll on one drum: its beat cells, where the kick is. Two notes per drum going down: the first note on each drum. Snare and tom alternating: every tom note, the low drum is the heavy voice also on the "e" and the "a". Unisons, and the hits of a fill thinned to 8ths: all of them. The last note, always.
- Shape step, for a flat fill (three notes in a row within 6 of each other in `show --vel`) on a request for more. One fill at a time, after its notes are final. All three lines only raise (EP 3, 11):
  1. Lean: the strong strokes 12 to 16 over the weak ones. `accent SPAN lanes=P grid=16 pattern=PAT mix=M`. PAT is `9---` for beat cells, `9-` for the first of two per drum, `9-9--9-9` for marching accents. M = 15 / (127 - level), 0.5 at 98. For single notes `vel ... add=15`.
  2. Lift and rise: `ramp SPAN lanes=P scale=A-B`. A is the lift from the first note on (1.03 to 1.1 at ranks 2 and 3, so the fill starts above its old level, 1 under marching accents, whose plain notes stay), B - A is the rise (0.03 to 0.09, up to 0.19 when the rise is the whole shape). A is 1 or more, so the ramp never undoes the lean (EP 18).
  3. Top: `vel bars=4 beats=4.75-5 lanes=43 min=117`: the last note, with the pitch of its drum and the top of its rank. Two last notes on one drum: the first 2 to 10 away from the top.
- Then read the fill in `show --vel`: the last note is the top, the loudest note is at most 5 over it (else a smaller B), no note is under its old value, the lean is 12 or more. A rank 1 pickup takes less: `add=9` on its first strong stroke or `add=7` on its tom notes, `scale=1-1.04`, its top by `min=`. No two fills get the same three lines: PAT follows the figure, A and B the rank (EP 5). The same figure at the same rank twice: the second one leans on its "and" cells too (`9-8-`) or takes another A and B. A fill that has a lean of 10 or more already: `vel SPAN lanes=P scale=F`, F = top / its last note, 1.2 at most, then line 3. A fill at its top already: nothing. For less, or for another character, the shape comes from lowering and the last note stays: `ramp ... scale=0.86-1`. `ramp from= to=`, `vel set=` and `vel min=` over a whole span erase the shape (EP 18): `min=` is for one named note. New notes are written with digits that end on the digit of the rank (8 into a new section, 7 inside a phrase) and then take line 3.
- Ceiling (EP 4): a fill that is itself flat at 127 cannot go up. Take weight (a kick on the quarters, the floor tom under the first hit) and air (the last 16th out), and only then lower its weak strokes by 15 to 25 (`accent bars=4 beats=3-5 lanes=38 grid=16 pattern=-8-8-8--` on a roll of 8: `127 112 127 112 127 112 127 127`), never a strong stroke or the last note and never as the only step. `diff` lists those notes as quieter: report them as contrast, not as louder.
- Classic flam: grace 6 to 30 ms early and slightly quieter (Sound On Sound). Use 15 to 20 ms (22 to 29 ticks at 180 bpm, inside the 12 to 20 ms of dynamics-and-feel.md section 7 and wide enough to print as its own cell) and a grace of 70 to 99: 84 to 99 for a power flam under a main of 112 or more, 70 to 75 for a light one (at 100 or more the backbeat selector `v=100-127` catches the grace). Above 40 ms it reads as two notes (grace velocity and the 40 ms limit unconfirmed). A grace closer than ppq/24 ticks (20 at 480 ppq) shares the cell of its main hit: there a new digit scales both and `-` deletes both. A wider grace makes `show` print the bar at grid=32 or 48 from then on. Flat flam: both lanes on one cell at the same digit, optionally one lane 8 to 12 ticks early (unconfirmed amount).
- Order (EP 16): notes first (bar blocks, `copy`, `remap`, `delete`), then `humanize` if he asked for a human feel, then the shape lines (lean, lift and rise, top), `shift` last. No recipe here needs `humanize`: the shape step gives every note its own value, and a random spread is never what makes two fills differ. If used, `vel=3` at most, a third of the lean or less (EP 17), and `time=4` (dynamics-and-feel.md section 7). Programmed punk sounds right at 90 to 95 percent quantize, not 100 (Nail The Mix), but a fill request does not change timing. On request ("rushed", "pushing"): the hand notes of the run 8 to 12 ticks early (6 to 8 ms at 180 bpm, unconfirmed), kick and landing on the grid.

## 7. The landing
- Beat 1 of the next bar: crash1 and kick on the same cell (most drummers end a fill with a crash on beat 1, Drumeo). At a section start it is the entrance, both at 127. Inside a section it is one crash a digit lower (112) with the kick at its own level, and the keeper hit on that cell becomes `-`. An existing landing keeps its level. In a section that rides the crash (`keeper` crash1) the keeper's own hit on beat 1 is the landing: add nothing. A fill that ends on two kicks lands on snare + crash instead (Drum Helper).
- The entrance stands above the fill (EP 6): 10 or more over the fill's last note, or air before it. Compare the two before choosing the top (section 6). Room, a top of 117 into a crash at 127: the fill runs to the bar line. No room, a top of 127 into a crash at 127: the last 16th of the fill comes out and the top sits on the 8th cell before it. When they are too close the fill gives way, not the landing.
- Hierarchy (EP 6): no landing is bigger than the entrance of its own section or than the first hit of the song. A second cymbal (bigger: crash2, heavier: china; both hands, so no snare on that cell and no hand note on the 16th before it) belongs to a section start only. On a fill request: on a lane that has notes in `# lanes`, and only on "more" or when the first hit of the song has two cymbals too. On a section request at the ceiling it is the default (grooves.md section 3, song-structure.md section 10). Never the keeper cymbal of the next section before its first bar.
- Missing landing (EP 23): a confirmed fill with no cymbal on its landing cell gets one on any fill request that is not for less. crash1 at digit 8, the kick kept or added with `x`, the keeper hit on that cell removed (`delete bars=3 beats=1-1.25 lanes=42`). The fill in front of it then tops at 102. It sits outside the fill's bar: report it. A fill in the last bar of the file has no landing bar: leave it out and say so (EP 22).
- Pushed landing: the chord change arrives early (`# riff` has an onset on 4.5 and none on the next beat 1). The fill ends on 4.25, crash + kick sit on 4.5 (at 127 when the push is the entrance of a section, inside a section one crash at digit 8: grooves.md section 5), the next beat 1 has no crash, no kick and no keeper, and the keeper resumes on 1.5 or 2 (bars 6 to 7 of section 5, grooves.md section 5). Do not repair the empty beat 1: crash on 4.5 followed by crash + kick on 1 is a pickup, not a push. Punk drummers mark arrival points in the riff with a crash (Pearson). With no `# riff` row use it only on request ("push it"). In slow notation the push is on 4.75, or on 2.75 for the first fast bar of a pair. Layout unconfirmed.
- The bar after is the plain groove from beat 2 at the latest: no leftover toms or extra snares. A script runs top to bottom, so a `copy` that covers this bar goes before its bar block.

## 8. Intensity ladder for one slot
One slot, six versions from lightest to biggest, written as new notes into a new section at 127. They stand side by side in bars 1 to 6 so they can be compared: on a song each goes into the bar of its slot (`bars=4 beats=3-5`). What grows: the span (L1 to L3), then drums per hit (L4), then the number of drums (L5), then both (L6). Beats 1 to 2 are the unchanged groove. The digits follow section 6: the last note carries the top, 8 into a new section (line 3 of the shape step then takes it from 112 to 117), 7 inside a phrase. A 9 inside the span is a real backbeat (L1, L2) or a top with air (L6). On a real song write only the rows you change, always write the keeper row so its cells in the span are cleared (`hh 42 |8-7- 8-7- ---- ----|` for L3 to L6), and clear any other hand lane the groove leaves there (`delete bars=4 beats=3-5 lanes=hh_open,ride`).
```vd
# bar 1 = L1 pickup: the keeper stays, snare on 4 (the backbeat, 127) and 4.5 (112, inside a phrase 98), kick row untouched
bar 1 grid=16
hh 42      |8-7- 8-7- 8-7- 8-7-|
snare 38   |---- 9--- ---- 9-8-|
# bar 2 = L2 one beat roll: the keeper leaves beat 4, four snare 16ths on the backbeat cell: 127 (the backbeat stays), 98, 98, 112, kick on 4. `diff` prints that backbeat as the peak
bar 2 grid=16
hh 42      |8-7- 8-7- 8-7- ----|
snare 38   |---- 9--- ---- 9778|
kick 36    |9--- --9- 9--- 9---|
# bar 3 = L3 two beat roll: eight snare 16ths, the beat cells (with the kick) and the last note at 112, the others 98, kick on 3 and 4
bar 3 grid=16
snare 38   |---- 9--- 8777 8778|
kick 36    |9--- --9- 9--- 9---|
# bar 4 = L4 unison 8ths: snare + floor tom on 3, 3.5, 4 and 4.5, rising 70, 84, 98, 112, kick on 3 and 4
bar 4 grid=16
snare 38   |---- 9--- 5-6- 7-8-|
tom5 43    |---- ---- 5-6- 7-8-|
kick 36    |9--- --9- 9--- 9---|
# bar 5 = L5 tom run: two 16ths per drum going down, the first note on each drum a digit over the second, the floor tom 112 and 112
bar 5 grid=16
snare 38   |---- 9--- 87-- ----|
tom1 50    |---- ---- --87 ----|
tom3 47    |---- ---- ---- 87--|
tom5 43    |---- ---- ---- --88|
kick 36    |9--- --9- 9--- 9---|
# bar 6 = L6 the biggest: flat flam on 3 (snare + floor tom + kick), a run down the toms, flat flam + kick on 4.5 at 127, the last 16th empty: air, and both hands reach the landing
bar 6 grid=16
snare 38   |---- 9--- 87-- --9-|
tom1 50    |---- ---- --87 ----|
tom3 47    |---- ---- ---- 87--|
tom5 43    |---- ---- 8--- --9-|
kick 36    |9--- --9- 9--- 9-9-|
```

## 9. Bigger, heavier, busier
| control | bigger | heavier | busier |
|---|---|---|---|
| hand notes in the span | the same notes | a fill on one drum: only its 8th cells. A fill across drums keeps its notes | more: empty 16th cells filled, or an earlier start |
| drums | more kit at the ends: the tail of a snare fill onto the floor tom, a flat flam under the first note of a run | the floor tom under every kept hit of a one drum fill (unison 8ths). Same voices, the descent kept (EP 8) | the drums already there, 1 per cell |
| kick | on every quarter of the span | under every hand 8th cell | ranks 2 and 3: on every 8th cell. The kicks that are there stay |
| velocity | the shape step, each fill to the top of its rank, nothing quieter (section 6) | the same tops, toms over the snare | added notes one digit lower, then the shape step |
| the biggest fill | flat flams on its first note and on its top, 127 and a 16th of air | hits on its 8th cells, 127 on the last, the last 8th empty | no extra |
| cymbals | a missing landing repaired. On "more": a second crash on a section start (section 7) | the same. On "more": china on the landing into a breakdown, when the kit has one | the same. On "more": hh_open or splash + snare inside the run |
| span | same. On "more": one step longer (recipe Longer) | same, less the air | up to an 8th earlier |
| the bar after | same groove | half time only when that section is already `half` or he asks | same groove |

Three different requests. Bigger is the same fill with more kit, more weight and a crescendo. Busier is more notes. Heavier in this style means the easycore direction (A Day To Remember, Four Year Strong: pop punk with metalcore and hardcore breakdowns): floor tom and kick unisons, fewer and slower notes, the kick locked under the hands, air before the landing. It never means more hand notes, a finer grid or more of the kit, and it does not mean every tom remapped to the floor tom: the descent and the number of drums stay (EP 8).

## 10. Recipes
Every recipe is a procedure, not a script. For each fill in scope read in `show --vel`: its rank and its landing (sections 4, 7), its drums and its figure, the kick row under it, its first cell (backbeat cell or not) and its level. Then write lines for that fill. The worked answers do this on one example file: another file has other kicks, drums and figures and gets other cells, levels and bars, and a second fill of the same rank is read again and gets lines of its own (EP 5, 20). Default: the levers named as default, in that order, graded by rank. Then stop, report, and offer the next lever (EP 1, 2). A lever that would change nothing in a fill is skipped for that fill. On every request that is not for less, a missing landing is repaired (section 7) and a flat fill is closed with the shape step (section 6), each fill to its own top.
Write per fill (`bars=N beats=A-B`): the bulk `fills` selector gives every fill one treatment and means the spans of the song before the script. Name the voice (EP 19): `lanes=38` for the snare (`lanes=snare` also takes rim and snare2), `lanes=43` for one tom, `lanes=38,tom` for a run. Notes come first. Adding or removing a note needs a bar block: `x` keeps a note with its velocity and on an empty cell writes one at the lane's usual velocity (use it for added kicks and for rows copied from `show`), a digit writes that level, `-` deletes. Then `remap` and `delete`, then the shape lines.
Cases (EP 21 to 24). No `# riff` row: skip every lever that names the riff, say so, and move no groove kick: kicks are only added, inside the span. A fill in the last bar of the file: no landing, say so. A lane with no notes in `# lanes`: a tom goes to the nearest tom that has notes with the number of voices kept, a cymbal is left out. Check before the report with `vibedrum diff ORIGINAL RESULT` and `show RESULT --vel` on the changed bars. For more: no lane with quieter notes, every `# fills` line with last within 5 of peak, pickup peaks 10 or more under the section fills, no two fills with one velocity sequence, each landing 10 over the last fill note or after air, `# bars changed` holding the fill bars plus the landing bars you name. A failed test changes the script, not the report. Report in two or three lines: what got louder, notes added and removed with their count, bars touched outside the fills, what a case skipped.
**Bigger.** More kit, more weight under it and a crescendo, on the notes that are there. Levers, default 1 to 3: (1) Weight: an `x` kick on every quarter of the span that holds a hand note and no kick. (2) Kit, ranks 2 and 3: a fill that ends on the snare moves its last 8th (two 16ths) onto the floor tom with `remap`. A fill that already ends on a tom gets the floor tom under its first note (flat flam, written with the digit of the note it doubles). The biggest fill gets a flat flam at both ends: under its first note, and as its top on the last 8th cell (snare + floor tom + kick at 127) with the last 16th taken out for air. A rank 1 pickup keeps its drums. (3) Level: the shape step. On "more": (4) one step longer, the biggest fill first (recipe Longer); (5) a second crash on a section start (section 7); (6) one step up the ladder: a roll moved onto the toms (L3 to L5).
```vd
# input, the example file: 180 bpm, no riff track, kick, crashes and backbeats at 127, every fill note at 98. verse on hh in bars 1-4, half time bridge on ride quarters in bars 5-6, last chorus from bar 7
# bar 2 beats 4-5, rank 1: snare |---- 9--- ---- 7777| over kick |9--- --9- 9--- ----|. bar 3 starts on hat + kick, no crash
# bar 4 beats 3-5, rank 3: snare |---- 9--- 7777 7777| over kick |9--- --9- 9--- ----|. bar 5 starts on crash1 + kick at 127
# bar 6 beats 3-5, the biggest (bridge into the last chorus), beat 3 is the backbeat cell of half: snare |---- ---- 77-- ----| tom1 |---- ---- --77 ----| tom5 |---- ---- ---- 7777| over kick |9--- --9- ---- ----|. bar 7 starts on crash1 + kick at 127
# said back: bigger fills by rank. a kick under each. the roll in bar 4 drops onto the floor tom and climbs to 117. the run in bar 6 opens and ends on a snare + floor tom hit at 127, with a 16th of air before the last chorus. the pickup in bar 2 stays the small one and gets the crash it lacked on bar 3
# 1 weight, read from each kick row: bar 2 has no kick on 4. bar 4 has the groove kick on 3 and none on 4. bar 6 has none on 3 and 4, and its top on 4.5 gets one. 2 kit: bar 6 already ends on tom5, so tom5 goes under its first note and the snare joins its top on 4.5, the last 16th out. bar 4 ends on the snare: the remap below. landing: bar 3 gets crash1 at 8 and loses its hat on beat 1
bar 2 grid=16
kick 36    |9--- --9- 9--- x---|
bar 3 grid=16
crash1 49  |8--- ---- ---- ----|
bar 4 grid=16
kick 36    |9--- --9- 9--- x---|
bar 6 grid=16
snare 38   |---- ---- xx-- --9-|
tom5 43    |---- ---- 9--- xxx-|
kick 36    |9--- --9- x--- x-x-|
delete bars=3 beats=1-1.25 lanes=42
remap bars=4 beats=4.5-5 lanes=38 to=tom5
# 3 bar 2, rank 1: its first note is its strong stroke. the crash on bar 3 is 112, so the top is 102
vel bars=2 beats=4-4.25 lanes=38 add=9
ramp bars=2 beats=4.25-5 lanes=38 scale=1-1.04
# bar 4, rank 3 under an entrance at 127, top 117: lean on its beat cells (the kicks), lift and rise, the floor tom pair 113 then 117
accent bars=4 beats=3-5 lanes=38 grid=16 pattern=9--- mix=0.5
ramp bars=4 beats=3-5 lanes=38,43 scale=1.03-1.1
vel bars=4 beats=4.5-4.75 lanes=43 add=6
vel bars=4 beats=4.75-5 lanes=43 min=117
# bar 6 ends with air: backbeat cell to 127, lean on the first note on each drum, lift and rise, top 127
vel bars=6 beats=3-3.25 lanes=38 min=127
accent bars=6 beats=3.25-4.5 lanes=38,tom grid=16 pattern=9- mix=0.5
ramp bars=6 beats=3.25-4.5 lanes=38,tom scale=1.04-1.1
vel bars=6 beats=4.5-4.75 lanes=43 min=127
```
`show --vel` then reads bar 2 `107 98 100 102` into the crash at 112, bar 4 `116 102 103 104 121 106` on the snare and `113 117` on the floor tom into the entrance at 127, bar 6 `127 102 119 105 123 108 127`, then a 16th of air. `diff` reads peaks 107, 121 and 127, every last note within 5 of its peak, nothing quieter. Other figures read differently: a pickup that goes snare then tom rises on its tom notes and may top at 107 when it lands on a keeper crash at 127, a run of two per drum that is not the biggest leans on the first note on each drum and tops at 117 on its last floor tom note, a build of 8ths then 16ths on the snare ends on the snare, so its top is where the floor tom joins.
**Heavier.** Fewer and bigger hits with the kick locked under them: the easycore direction. Levers, default 1 to 3: (1) Kick: an `x` kick under every 8th cell of the span that holds a hand note. (2) Hits, ranks 2 and 3: a fill on one drum (a snare roll, a build) keeps only its 8th cells and every kept hit gets the floor tom under it, written with the digit of the snare note (unison 8ths, figure 4). A fill that moves across drums keeps its notes and its descent (EP 8). A rank 1 pickup keeps its notes. The biggest fill takes the easycore ending: only the hits on its 8th cells, the last 8th of the bar empty in every row, 127 on the last hit. If that last 8th holds the only notes of a drum, the hit on 4.5 stays as the top and only the last 16th goes. (3) Level: the shape step. The hits with a kick under them are the strong strokes, toms sit over the snare, the top is on the lowest drum. On "more": (4) china or a second crash on the landing of a section start (section 7); (5) half time after the landing (snare on 3 only, crash or china quarters), only when the next section's `feel` is already `half` or he asks: then rewrite that whole phrase, not one bar. Never a finer grid, never every tom remapped to the floor tom.
```vd
# input: the example file of Bigger. said back: heavier fills, fewer and bigger hits. the kick under every 8th, the roll in bar 4 becomes four snare + floor tom hits, the run in bar 6 three hits down the kit, 127 on the last, then an 8th of air. the pickup keeps its notes
# 1 kick, read from each kick row: bar 2 gets 4 and 4.5. bar 4 has 3, so 3.5, 4 and 4.5. bar 6 gets 3, 3.5 and 4. 2 hits: bar 4 is on one drum, so its 8th cells stay and tom5 goes under each. bar 6 is the biggest: its 8th cells hold the first note on each drum, so every drum still sounds, and the hit on 4.5 goes for the air. bar 2 keeps its notes: its landing and its two shape lines are those of Bigger
bar 2 grid=16
kick 36    |9--- --9- 9--- x-x-|
bar 4 grid=16
snare 38   |---- 9--- x-x- x-x-|
tom5 43    |---- ---- 7-7- 7-7-|
kick 36    |9--- --9- 9-x- x-x-|
bar 6 grid=16
snare 38   |---- ---- x--- ----|
tom1 50    |---- ---- --x- ----|
tom5 43    |---- ---- ---- x---|
kick 36    |9--- --9- x-x- x---|
# 3 bar 4: every hit is a strong stroke, so no lean: a lift from the first hit and a rise to 117, `108 111 114 117` on both drums. bar 6: backbeat cell and last hit at 127, the rack tom between them up 15: `127 113 127`
ramp bars=4 beats=3-5 lanes=38,43 scale=1.1-1.19
vel bars=6 beats=3-3.25 lanes=38 min=127
vel bars=6 beats=3.5-3.75 lanes=50 add=15
vel bars=6 beats=4-4.25 lanes=43 min=127
```
**Busier.** More notes: the hands first, then the feet. Nothing moves to another drum. Levers, default 1 or 2, whichever has room in that fill, plus 3 and 4: (1) Hands: an empty 16th cell inside the span gets a note on the drum of the note before it, one digit under it (`7-7-` becomes `7676`). (2) Span full: it starts earlier, on its first drum, a digit under its first note (6 under a 7). A rank 1 pickup by one 16th (the "a" in front of it, where no keeper sits), ranks 2 and 3 by an 8th (two 16ths: the keeper hit on that 8th goes, the kick stays). Never over a backbeat: start behind it. (3) Feet, ranks 2 and 3: an `x` kick on every 8th cell of the span that has none, never three 16th kick cells in a row. (4) Level: the shape step, so the fill still ends on its top. At 135 bpm or slower a full span can become the sextuplets of bar 4 in section 5 instead. Faster than that the hands are at their cap (section 4): on "more" offer Longer.
```vd
# input: the example file of Bigger, bars 2 and 4. both spans are full of 16ths, so lever 2. bar 2 starts on the "a" of 3. bar 4 starts on 2.5, behind the backbeat on 2: the hat on 2.5 goes, the kick there stays. feet: bar 4 has a kick on 3, so 3.5, 4 and 4.5
bar 2 grid=16
snare 38   |---- 9--- ---6 xxxx|
bar 4 grid=16
hh 42      |7-7- 7--- ---- ----|
snare 38   |---- 9-66 xxxx xxxx|
kick 36    |9--- --9- 9-x- x-x-|
# then the landing on bar 3 and the shape step. bar 4 stays on the snare, so its top is on the snare: `84 84 116 102 103 104 121 106 107 117`
accent bars=4 beats=3-5 lanes=38 grid=16 pattern=9--- mix=0.5
ramp bars=4 beats=3-5 lanes=38 scale=1.03-1.1
vel bars=4 beats=4.75-5 lanes=38 min=117
```
**Simpler.** A request for less: nothing gets louder, no kick or crash is added, a missing landing is only mentioned. Levers, default 1 and 2: (1) Ghosts and graces out of the span (`delete ... v=1-59`). (2) Only the 8th cells stay. In a run of two per drum that is the first note on each drum, so every drum still sounds (EP 8). Snare and tom alternating: write the bar by hand and keep the first snare and the last tom note. (3) One step down the ladder: the floor is L1, then no fill and only the landing crash. A flat fill is then shaped by lowering its front: the last note stays, a note on the backbeat cell stays, and pickups come down 10 as a whole so the ranks stay apart. Below, on bars 2 and 4 of the example file: `84 88` and `78 85 91 98`.
```vd
bar 2 grid=16
snare 38   |---- 9--- ---- x-x-|
bar 4 grid=16
snare 38   |---- 9--- x-x- x-x-|
ramp bars=2 beats=4-5 lanes=38 scale=0.86-0.9
ramp bars=4 beats=3-5 lanes=38 scale=0.8-1
```
**Longer.** Double the span backwards (1 to 2 beats, 2 to 4 beats, 4 beats to 2 bars). The old fill stays as the tail. The new front half has half the density and sits a digit or more under the tail, a backbeat it crosses stays at full, and the kick row is not touched. A front on one drum (snare 8ths) plays under the keeper, one hand each. A unison front (snare + floor tom, ranks 2 and 3) clears the keeper there. No fill may outrank the last fill of its section: when the pickups grow, the section fills grow too. For 2 bars use figure 5. Then the shape step on each tail. Below, on the example file: bar 2 gets 8ths on 3 and 3.5 under the hat, bar 4 unison 8ths on 1, 1.5 and 2.5 around its backbeat (70, 84, 127, 98) with the hat cleared.
```vd
bar 2 grid=16
snare 38   |---- 9--- 6-6- xxxx|
bar 4 grid=16
hh 42      |---- ---- ---- ----|
snare 38   |5-6- 9-7- xxxx xxxx|
tom5 43    |5-6- --7- ---- ----|
```
**Shorter.** A request for less. Keep the tail and restore the groove in the front of the span: keeper, backbeat and kick rows as in the same beats one bar earlier, copied from `show`. Never keep the front and cut the tail: the tail carries the top and the landing. When the cut would drop a drum of a descent, `remap` the kept notes so every drum still sounds once, highest first (EP 8): L5 cut to beat 4 becomes snare, tom1, tom3, tom5 with `delete bars=4 beats=3-4 lanes=38,tom`, then `remap bars=4 beats=4-4.25 lanes=47 to=38`, `remap bars=4 beats=4.25-4.5 lanes=47 to=50`, `remap bars=4 beats=4.5-4.75 lanes=43 to=47`. A tail that now starts on a backbeat cell keeps the level it has: its first note is not raised. A flat tail is shaped by lowering the notes between its first and its last (`ramp bars=4 beats=4.25-4.75 lanes=38,tom scale=0.9-0.95`), each tail with its own factors. A 1 beat pickup is the shortest slot already and keeps its notes: as in Simpler it comes down 10 as a whole so the ranks stay apart.
**More interesting.** A change of character, not of level: accents go up to the top of the rank, nothing is lowered. One change per fill, no change twice in a song, section fills first. Pickups only take the shape step. (1) Accents regrouped 3-3-2 (beats 3, 3.75 and 4.5) with a kick under each. (2) A hole: the last 16th out, so the fill ends on its accent with air. (3) A kick in place of the second note on one drum of a run: every drum still sounds. (4) hh_open + snare in place of one hand note, closed by the next closed hat or hh_pedal, when `# lanes` has hh_open. (5) A flat flam on the first note. (6) Stabs moved onto `# riff` onsets. Below: 1 and 2 on the roll in bar 4 of the example file, whose kick on 3 is there already. Result: `117 98 98 117 98 98 117`, the last 16th empty.
```vd
bar 4 grid=16
snare 38   |---- 9--- xxxx xxx-|
kick 36    |9--- --9- 9--x --x-|
accent bars=4 beats=3-5 lanes=38 grid=16 pattern=9--9--9- mix=0.65
```
**More Travis Barker.** Hard single strokes with one device per fill, the biggest fill first, no device twice in a song: he keeps his first idea for a part and adds embellishments where they fit (DRUM!). Default: the first three devices the file has a fill for, a kick on the quarters under each of those fills (Bigger lever 1), and the shape step on every fill, pickups included. (1) The linear unit on the biggest fill: snare, rack tom, floor tom, kick, snare, kick, then snare and floor tom, hands and kick never on one cell (figure 8). With hh_open in `# lanes` it opens with the snare on 4. (2) Marching accents on a snare roll of 8 notes or more: `pattern=9-9--9-9`, accents on notes 1, 3, 6 and 8, so the last note is an accent and the top. (3) A flat flam under the first note of a run down the toms (Bigger lever 2). (4) At 135 bpm or slower the sextuplets of bar 4 in section 5, faster the 8th triplets of figure 7. (5) A splash (55) or crash + kick in place of one hand note inside the run, never the keeper of the next section. (6) On "more": a full bar of singles around his kit (snare, one rack tom, one floor tom), at the biggest transition only.
```vd
# input: the example file of Bigger. bar 6 is the biggest: its eight notes become the linear unit on the drums it has (snare, tom1, tom5). bar 4 is a snare roll: marching accents, and a kick on 4 next to the groove kick on 3. bar 2: a kick on 4, its landing and its shape lines as in Bigger
bar 4 grid=16
kick 36    |9--- --9- 9--- x---|
bar 6 grid=16
snare 38   |---- ---- x--- 7-7-|
tom1 50    |---- ---- -7-- ----|
tom5 43    |---- ---- --7- ---x|
kick 36    |9--- --9- ---x -x--|
# bar 4: accents 16 over the rest, a rise of 3, the last accent is the top: `114 98 115 99 100 116 101 117`
accent bars=4 beats=3-5 lanes=38 grid=16 pattern=9-9--9-9 mix=0.55
ramp bars=4 beats=3-5 lanes=38 scale=1-1.03
# bar 6 runs to the bar line, so its backbeat cell takes the lean, not 127. lean on the 8th cells (the strong hand), top 117 on the floor tom: snare 115, tom1 103, tom5 117, kick, snare 119, kick, snare 120, tom5 117
accent bars=6 beats=3-5 lanes=38,tom grid=16 pattern=9- mix=0.45
ramp bars=6 beats=3-5 lanes=38,tom scale=1.04-1.09
vel bars=6 beats=4.75-5 lanes=43 min=117
```
**More energy.** Forward motion, not weight: no drum is moved and none is added. Levers, default 1 to 3: (1) no empty 16th cell in the last beat of the span (Busier lever 1); (2) a kick on every quarter under the fill (Bigger lever 1); (3) the shape step with the steepest rise the top allows: on a roll the lean sits on the first note only and B is chosen so that the last note reaches the top without a `min=` line; (4) a pushed landing (section 7) when `# riff` has it. On a full roll this is Bigger without its kit lever: say so. On the roll in bar 4 of the example file: the kick row of Bigger, then `accent bars=4 beats=3-5 lanes=38 grid=16 pattern=9------- mix=0.5` and `ramp bars=4 beats=3-5 lanes=38 scale=1-1.19`, which reads `113 101 103 106 109 111 114 117`.
**Less cheesy.** Cheesy in the grid: a full bar of 16ths, four notes per drum from the snare down through every tom, flat velocity, no kick, the same bar at every phrase end. The round the kit bar itself is real vocabulary (figure 3): flat, unsupported and repeated is what makes it cheesy. Fix, in this order: Shorter to the last 2 beats with two notes per drum (the groove back in beats 1 to 2, every drum kept), Bigger levers 1 and 3 on what is left (a kick on the quarters, the shape step with `pattern=9-`), and every second such fill in the section turned into L1 or the plain groove, so no two phrase ends match.

## Sources and unconfirmed items
Unconfirmed (working numbers of this document, not found in a source): the sign thresholds of sections 2 and 3; which notation MIDI files outside the commercial packs use; the 14 notes per second hand cap, the three 16ths in a row rule for a hand or a single pedal, and the tempo limits derived from them; the fill plan per section and how often fills come (the two Basket Case sources disagree); the three ranks and every size of section 6 (tops 117, 107, 102 and 127, the lean of 12 to 16, 10 between ranks and from fill to landing, the 16th of air: these come from the blind trial judges of this project, not from a drum source); which levers each request takes by default; grace velocities, the 40 ms limit, flat flam and urgency shifts in ticks; the pushed landing and the crash ride landing; the 2 bar build layout; the slot form of the All The Small Things unit and its ending on the floor tom; whether the First Date lesson is written in fast or slow notation; that real double time is rare in the style. The recipes were run on a 24 bar, 180 bpm file with flat fills and no riff track and checked with `diff`: every riff clause is unconfirmed. No usable source was found for the fills of Cyrus Bolooki, Steve Jocz, Longineu Parsons, Rian Dawson, Zac Farro, Andy Hurley or Josh Freese: nothing here is attributed to them. Not retrievable (paywall or blocked): Modern Drummer on Andy Hurley, MusicRadar on Barker's stickings, the Gearspace thread on fill programming. Engine behaviour (how candidates and `feel` are computed, how flams print, script order) was read from `core/vibedrum.cpp`: recheck it if the engine changes.
- Notation and tempo: https://thedrumninja.com/basket-case-drum-transcription-by-greenday/ , https://songbpm.com/@green-day/basket-case , https://drum.town/lessons/rock-double-time/ , https://www.drumeo.com/beat/a-drummers-guide-to-punk/ , https://www.drumlessons.com/drum-lessons/rock-drumming/beginner-punk-rock-drum-beats/ , https://mtosmt.org/issues/mto.19.25.1/mto.19.25.1.pearson.html (crash accents on chord arrivals, stops and unison accents as punctuation)
- Drummers. Travis Barker: single strokes only because doubles sound weaker, his first idea kept and embellished, a 12 inch rack tom and a 16 inch floor tom, fills made up as he goes and a fill that crosses the toms in Feeling This (DRUM!, two articles); rudiments, flams, six stroke roll with a kick double (Drumeo); snare in his school marching band, rudimental snare patterns in Going Away To College and All The Small Things, hard fast single strokes with accents, one rack and one floor tom, cymbals inside the beat (Drumhead Authority); the two All The Small Things fills, the First Date intro, the triplet lick with kick (Drums The Word). Tre Cool: flams between floor tom and snare in the second Basket Case fill (Drums The Word), frequent but tight fills and crashes on chord changes (Drumhead Authority), against "few and sharp" fills on Basket Case (Drum Ninja, listed under notation): https://drummagazine.com/travis-barker-in-2000-punk-drumming-grows-up/ , https://drummagazine.com/how-to-play-feeling-this-by-blink-182/ , https://www.drumeo.com/beat/blink-182-travis-barker-genius/ , https://www.drumeo.com/beat/travis-barker-warmup-rudiments/ , https://drumheadauthority.com/articles/travis-barker/ , https://www.drumstheword.com/all-small-things-famous-drum-fill-drum-lesson-travis-barker-blink-182/ , https://www.drumstheword.com/first-date-drum-fill-drum-lesson-travis-barker-blink-182/ , https://www.drumstheword.com/travis-barker-lick-fill-free-video-drum-lesson/ , https://www.drumstheword.com/basket-case-drum-fill-drum-lesson-tre-cool-greenday-free-video-drum-lesson/ , https://drumheadauthority.com/articles/tre-cool/
- Fill vocabulary: silence as a fill, the 8th note build on snare and floor tom with the kick on the quarters, the 16th tom run, Bonham triplets, half and quarter bar snare rolls, the flam fill, crash on beat one (Drumeo); 12 punk fills with hand and foot groups, flam and kick, sextuplets of 4 hands and 2 feet, snare + crash landing (Drum Helper); flams as two full hits with no grace note, between toms and snare, marching rudiments in B sections and bridges (Pop Punk Drumming); tom and kick unisons (Drumlessons): https://www.drumeo.com/beat/common-rock-drum-fills/ , https://www.drumeo.com/beat/beginner-drum-fills/ , https://drumhelper.com/learning-drums/punk-drum-fills/ , https://poppunkdrumming.wordpress.com/ , https://www.drumlessons.com/drum-lessons/rock-drumming/intermediate-punk-rock-drum-beats/ , https://dddrums.com/5-must-learn-punk-rock-fills-for-beginners-drum-lesson/
- Programming: fills slightly under the backbeats, 90 to 95 percent quantize (Nail The Mix); backbeats 100 to 120, rimshots at or near maximum, ghosts 20 to 45 (Toontrack); flam 6 to 30 ms and slightly quieter, roll crescendo from 1 to about 120, four limbs (Sound On Sound); fills at the end of a part, usually one or two bars, rising snare velocity (Native Instruments); half time breakdowns, china for aggression, simple fills (Oracle Sound). Easycore: definition and bands (Wikipedia); Alex Shelnutt on Barker, double bass and breakdown kick patterns and fills (Modern Drummer): https://www.nailthemix.com/toontrack-pop-punk-ezx , https://www.toontrack.com/blog/how-to-program-drums/ , https://www.soundonsound.com/techniques/making-midi-sequencing-more-realistic-part-2-drum-parts , https://blog.native-instruments.com/drum-fills/ , https://www.oraclesound.com/blogs/news/drum-programming-techniques-for-punk-and-hardcore-music , https://en.wikipedia.org/wiki/Easycore , https://www.moderndrummer.com/2016/08/alex-shelnutt-day-remember-bad-vibrations/
