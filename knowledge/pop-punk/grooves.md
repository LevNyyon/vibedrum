# Pop punk grooves: groove vocabulary

Scope: the steady groove (not fills) in pop punk, from the 90s wave to the modern scene and easycore. Positions are grid=16 cell indexes 0-15 of a 4/4 bar unless a grid is named: beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12, the "and" of 4 = 14. Digits: 9 = 127, 8 = 112, 7 = 98, 6 = 84, 5 = 70, 4 = 56, 3 = 42. A written digit is exact, a shown digit is a band 14 wide: check levels with `show --vel`. `[n]` = source list at the bottom. "unconfirmed" = working practice or arithmetic, no cited source. Velocity numbers carry no source unless one is given. Song tempos are the cited figures, not measurements. `EP n` = rule n of knowledge/editing-principles.md: every recipe here obeys it, and where a line here seems to differ the EP rule wins.
How to use the worked answers (EP 20): the numbered steps are the recipe, the `vd` block under them is one run of it on an example file that its `#` comments describe. Read the same things in his file with `show --vel` (where the kick plays, which lanes have notes, how each fill is built and what it lands on) and write your own lines: another file gives other bars, cells and levels. Never paste a block, and never give two fills one line. After every apply run `vibedrum diff ORIGINAL RESULT` and `show RESULT --vel` on the changed bars and go through the acceptance tests at the end of the principles. If one fails, change the script and apply again from the same starting file. The loop test covers the rows an edit rewrote: bars the script did not touch may still fold into `# bar N = bar M`, which is his loop and gets one line in the report.

## 1. Tempo notation trap: read this first
The same fast beat is written two ways. Decide which one the file uses before reading any pattern. Everything below is notation A unless marked B.

| | notation A (fast file) | notation B (slow file) |
|---|---|---|
| bpm in the `# tempo:` header line | 150-220 | 75-110 |
| fast punk beat | feel `normal`: snare 4 12, kick 0 8 | feel `double`: snare 2 6 10 14, kick 0 4 8 12 |
| its eighth note keeper | even cells, 8 per bar | every cell, 16 per bar |
| its half time | feel `half`: snare 8 | feel `normal`: snare 4 12 |
| breakdown at quarter speed (rare) | snare on cell 0 of every second bar: bars alternate `open` and `other` | feel `half` |
| a push (section 5) | cell 14 | cells 7 and 15 |
| conversion | two A bars = one B bar | A cell c of the first bar = B cell c/2, of the second bar = B cell 8 + c/2 |

- Evidence that both exist: Dammit is published at 215 [16] and listed at 109 in a tempo database [25]. Misery Business sheet music says 86 [16] for a beat that moves at about 172. First Date is listed at 96 [25]. Drumeo gives Dumpweed at 200 and counts the punk beat with the snare on every "and" [1], and a double time lesson writes the pop punk beat the same way [7]. The cited sheet music is mostly A, and pop punk MIDI packs are sold at 116-204 bpm (figure from dynamics-and-feel.md, unconfirmed here), which points to A as the common one. For files from other sources it is unconfirmed.
- Backbeat rate R = strong snares per minute: `normal` = bpm / 2, `double` = bpm, `half` = bpm / 4. Fast punk beat: R 75-110. Mid tempo rock beat: R 47-75. Half time and breakdowns: R 37-55, told from a slow song by the `half` label (bands unconfirmed). feel `normal` at 150+ bpm with kick/bar 2-5 = fast punk beat in A (150-165 overlaps the straight rock beat of section 2: same cells, either name). feel `double` at 75-110 = the same beat in B, kick/bar 4-8. feel `normal` at 75-110 = a mid tempo rock beat, or the half time of a B file: check whether other sections read `double`. feel `double` at 125+ = skate punk or hardcore speed (250+ in A), above the songs in scope, or a 1-2 bar burst (unconfirmed). Never convert a file between notations: write new bars in the notation the file already uses.

How the engine labels a bar (read from the engine source, valid for this version):
- `feel` counts only snare and rim hits of velocity 60+ (ghosts stay under 60), at eighth note resolution. 8 or more in a bar: `blast`, which in this style is a snare build or a long snare fill, never a blast beat. Snare on all four quarters: `normal`. Snare on beat 4 only, or on beat 1 only: `other`. No snare at all: `open`.
- `keeper` needs 2 or more hits of one cymbal family in the bar. hh and hh_pedal read `hh`, hh_open reads `hh_open`: a tight hat verse and a sloshy hat chorus are two sections, and a section moved to the open hat prints a new keeper name. One bark in a bar leaves it `hh`, and a tie goes to the name first in the alphabet (the dance beat reads `hh`). ride and ride_bell both read `ride`. A floor tom ride reads `none`.
- `# fills:` also lists a snare build and a 1-2 bar tom groove (more snare or tom hits in a beat than the section usually has). They are grooves: keep the `fills` selector off them. `show` folds a bar into `# bar N = bar M` only when its drum rows and its `# riff` row both match an earlier bar, so a folded bar sits under the same guitar. To see one bar in full anyway, print it by itself: `show FILE --bars 9,10,11,12`.

## 2. Core beats: cells, header signature, tempo, use
| # | beat | cells in notation A | header and bpm | where |
|---|---|---|---|---|
| 1 | straight eighth rock beat | hh on even cells, snare 4 12, kick 0 8 plus 0-2 of cells 6, 10, 14 | keeper hh, feel normal, kick/bar 2-4. 100-165 bpm: Adam's Song 136, All the Small Things 150, What's My Age Again 158 [16] | verses and choruses of mid tempo songs, verses of fast songs: the eighth note groove is the usual pop punk verse [1] |
| 2 | fast punk beat. Other names: punk time [11], double time polka beat [3], skank beat [22]. "Skate beat" and "two step" as names are unconfirmed | the cells of row 1, kick and snare alternating on the quarters. Only the bpm tells it from row 1 | keeper hh, hh_open, ride or crash1, feel normal, kick/bar 2-5. 150-220 bpm: Basket Case about 174 [13], My Friends Over You 180 [1], The Rock Show 182 [16], American Idiot 189 [1], Dumpweed 200 [1], Dammit 215 [16], easycore verses and choruses 160-200 [17] | choruses, fast verses, whole songs in the 90s wave |
| 3 | four on the floor | kick 0 4 8 12 [28], snare 4 12 | kick/bar 4 or more. 110-190 bpm (unconfirmed) | New Found Glory: a song opening, the second half of a chorus, and under fills that follow the guitar solo [14]. Pre-chorus, gang vocal parts (unconfirmed) |
| 4 | dance (disco) beat | row 3 plus hh_open on 2 6 10 14 and hh on 0 4 8 12 [27] | keeper hh (4 closed against 4 open hats: the tie reads hh), kick/bar 4 | pre-chorus and dance type choruses. Dance, Dance (listed at 114 bpm) pre-chorus, from a search excerpt [24] that the page itself did not confirm. Use by other bands unconfirmed |
| 5 | half time | snare 8 only, kick 0 plus riff accents, keeper on quarters | feel half, kick/bar 2-5. File tempo, felt at half of it | bridge, tag of a chorus (Misery Business drops to half time 8 bars into the chorus [24]), any drop in energy [2]. Half time choruses in the modern scene (unconfirmed) |
| 6 | easycore breakdown | row 5 with china or crash quarters, kick = riff chug, adjacent kick cells, holes of 3+ cells | feel half, kick/bar 5-10, keeper china or crash1, lock 85%+. Felt 80-100 in a 160-200 file ([17] says 70-100) | A Day to Remember, Four Year Strong type |
| 7 | floor tom verse | tom5 43 on even cells in place of the hat [6], snare 4 12 | keeper none, feel normal. 130-200 bpm (unconfirmed) | verses, bridges, intros [1][6][11] |
| 8 | tom groove without backbeat | toms on eighths, or on eighth triplets in a grid=12 bar, no snare or crash | keeper none, feel open | Longview type verse: triplets around the toms [29], no snare or crash until the fill into the chorus [12]. A Green Day shuffle (Holiday) prints at grid=12: keep the triplet grid [29] |
| 9 | snare on all four quarters | snare 0 4 8 12 in unison with hat or crash quarters, kick on 2 6 10 14 or four on the floor [4][5] | feel normal, 4 snare hits per bar | last 2-4 bars of a pre-chorus, end of a chorus (Misery Business [24]), endings |
| 10 | drum and bass or hip hop type verse | kick 0 and 10 (first and sixth eighth [27]), snare 4 12, hh_open eighths [9] | keeper hh_open, feel normal, kick/bar 2-3. 90-175 bpm (unconfirmed) | Barker type verses: Feeling This, 173 bpm, a drum and bass beat played with open hats [9][16] |

- Kick rows for beats 1 and 2, snare fixed on 4 and 12. Single: 0 8. Doubled: 0 8 10 (kick, snare, kick kick, snare [2]). "And" of 2 and "and" of 3: 0 6 10 [2]. Pickup: 0 6 8, or 0 8 14 where 14 leads into the next cell 0 (unconfirmed). Around the snare: 0 6 8 14 (unconfirmed). Galloped: 0 7 8, or 0 8 15 into the next 0: a sixteenth pair, the fast kick doubles of punk [1][4][5], played with slide or heel toe technique [2][4], limits in section 7. Lessons also show an eighth triplet kick [4][5]: its place in a notation A bar is unconfirmed, do not write it unasked.
- 2-4 kicks per bar. Keep one kick row for 2-4 bars, change one cell in bar 4 or 8 (unconfirmed). Levels (dynamics-and-feel.md, unconfirmed): a kick on a beat or a riff accent 110-124, the off beat note of a double (a kick 1 or 2 cells from another) 100-112, 127 only on a section start, a push into a section or a stab. Every backbeat is an accent or a rim shot [1]: snare 38 at 116-127, sd 3-5. Kick and backbeat nearly flat are the style, not the machine gun flaw. Both at min = max = 127 in `# lanes`: neither can be raised (section 3, ceiling). A push has no header field: find it in the grid (section 5). The Barker layer shows in `# lanes` as splash, perc_cowbell, ride_bell or hh_open with small counts and a snare vel min under 60.

## 3. Keepers: tight, sloshy, ride, crash
| keeper | lane and cells | velocity | where |
|---|---|---|---|
| tight hat | hh 42, even cells | beat 112, "and" 84 (numbers unconfirmed): shoulder then tip [2], the wall between them is 100. Reversed (84, 112) saves the arm above 200 bpm [2] | verses [21], palm muted parts (unconfirmed) |
| sloshy hat | hh_open 46, even cells, or quarters at very fast tempos [4] (from about 190 bpm, number unconfirmed). Half open = hh_open at 92-118, the map has no half open pitch (unconfirmed) | beat 104-118, "and" 92-108 | choruses in the older approach (closed verse, open chorus [21]), fast verses, pre-chorus. Drumeo names sloshy open hats next to the upbeat snare and the kick doubles as the punk sound [1], and loosening the hat is the first step toward it [4] |
| sixteenth open hat | hh_open 46 on all cells except the snare cells, two handed (sticking unconfirmed) | 84-105 | a New Found Glory chorus [14]. Up to about 180 bpm, the two handed limit of section 7 |
| ride, ride bell | ride 51 on even cells. ride_bell 53 on quarters, on 2 6 10 14, or as single accents | ride 84-112, bell 105-122 | choruses: Basket Case moves from hat to ride for the chorus [13], Tre Cool marks choruses with ride or bell [12]. Bell: bridges, last chorus, Barker's syncopated bell patterns [3] |
| crash quarters | crash1 49 on 0 4 8 12 | 127 on cell 0 of the section, then 88-112: beats 108, plain beats 94 (dynamics-and-feel.md section 2) | choruses and endings at any tempo. Header: keeper crash1 |
| crash eighths | crash1 49, even cells | 112, 98 | the biggest choruses, up to about 175 bpm, the one handed eighth limit of section 7 (unconfirmed) |
| china | china 52 on quarters | 108-124 | easycore breakdowns. Unconfirmed for the 90s bands |

- Ladder for "bigger" and "more energy" on a named section (one rung up) and "smaller", "calmer" (one rung down): hh 42, then hh_open 46 or ride 51, then crash quarters, then crash eighths (order unconfirmed). Open hat and ride share a rung: the open hat is the default (the same instrument, the punk sound [1][4]), the ride is the cleaner one (the Basket Case chorus [13]) and needs notes in `# lanes` or his word. The lead hand may also move to the toms [2].
  1. One rung per request, every occurrence of the section the same. Onto the keeper of the section that follows only when that section still enters as something new (another feel such as half time, a stop or air before it, a stacked entrance: EP 6), and the chorus stays a rung above the verse. A bigger chorus is first of all a wider cymbal: when a rung is free under that rule, take it before anything else. No rung free: stay on the lane and take levers 2 and 3 below. A crash rung above about 175 bpm is quarters: remap, then thin (section 7), and report the rate.
  2. `remap` by pitch: `lanes=hat` also takes the open hat and the foot (EP 19). Cells, fills, crashes and the kick row stay (EP 7). One keeper per section. One rung down is the mirror: remap to the lower lane, `vel ... scale=` into its band, closed hat tips clamped with `max=99` on 42 (EP 13), nothing raised.
- A request for more on a section whose keeper has a rung above it ("more energy in the verse", "bigger"): three levers, in this order (EP 1, 2). Read first, in `show --vel` of the section: the keeper lane and whether its row is flat, the keeper of the next section, the kick cells of every bar (which of the "and"s 2, 6, 10, 14 hold a kick), each phrase start (every 4 bars from the section start) and what sits on its cell 0, and every fill: span, drums, the cell it starts on, what it lands on. Lever 1 is the rung, by the rules above: it changes the sound of every hit, so it is heard first.
  2. The shape of the new row, raising only (EP 3). A flat row: the beats go up 15 to 20 and the "and"s stay, `accent ... pattern=9--- mix=M` with M = rise / (127 - level), 0.55 for 98 to 114. Then `humanize vel=2`, a third of that gap or less (EP 17). Then accents of 20 on "and"s that hold a kick (EP 12): first an "and" of 4 that leads into the next bar, and one more of them in the second phrase than in the first, so the row moves toward the next section. Not the same cell in every bar, and not the hat right before a fill (EP 14). No "and" holds a kick: no accents, the crash and the fills carry the phrase. A row that already has two levels: `vel ... scale=` or `add=` into the band of the table, no shape step, never `min=` or `set=` (EP 11).
  3. The phrase. Each phrase start inside the section whose cell 0 holds a kick and no crash gets one crash at digit 8 over that kick, keeper off the cell: it is also the landing a fill before it lacked (EP 6, 23). A pushed phrase start (section 5) keeps its empty cell 0. Then the fills of the section, each by its slot (next bullet).
- Fills inside a section request, each from its own grid, raising only (fills.md has the full treatment). The last note is the top and sits 10 under the hit it lands on: 117 into a section that enters at 127, 107 at most for a pickup or phrase end fill that lands inside the section, and a pickup that lands on a new digit 8 crash keeps its level. One `ramp ... scale=A-B` per fill, A at 1 or above (EP 18), B = top / its level. A fill that starts on a backbeat cell (beat 2 or 4, beat 3 in `half`): a real backbeat there (116 or more) stays, the ramp starts one cell later, and `diff` prints it as the fill's peak: say so. A note there at fill level is the first stroke of the rise, and comes up to the backbeats only when the fill ends on 127 with air (fills.md section 6). A fill in the last bar of the file has no landing: it ends on its top, 117 or more, and the report says so (EP 22).
```vd
# "more energy in the verse". Example file: verse = bars 1-8, the chorus after it rides crash1 and enters at 127
# read: hh 42 8ths flat at 98 (next rung hh_open, not the chorus keeper), crash1 + kick on bar 1. kick and backbeats at 127. kick on an "and": cell 10 in odd bars, cells 6 and 14 in even bars
# fills at 98. 4:4-5 = four snares from the backbeat cell, and bar 5 opens on hat + kick: no landing. 8:3-5 = snare snare, tom1 tom1, tom2 tom2, tom5 tom5 into the chorus
# 1 the rung. 3 the phrase start of bar 5 gets its crash over the kick that is there, keeper off the cell (notes first, EP 16)
remap bars=1-8 lanes=42 to=hh_open
delete bars=5 beats=1-1.25 lanes=46
bar 5 grid=16
crash1 49  |8--- ---- ---- ----|
# 2 shape: beats 98 to 114, "and"s stay at 98, spread 2
accent bars=1-8 lanes=46 grid=16 pattern=9--- mix=0.55
humanize bars=1-8 lanes=46 vel=2 seed=3
# 2 accents with the kick: the "and" of 4 of bars 2 and 6 (kick on cell 14, bars 4 and 8 hold fills there). second phrase one more: the "and" of 3 of bar 7 (kick on cell 10)
vel bars=2,6 beats=4.5-4.75 lanes=46 add=20
vel bars=7 beats=3.5-3.75 lanes=46 add=20
# 3 fills. bar 4 lands on the new crash at 112 and keeps its level, 14 under it. bar 8: one rise over the descent, 106 to 117, 10 under the chorus entrance
ramp bars=8 beats=3-5 lanes=snare,tom scale=1.08-1.19
```
  Check in `diff`: the section's vel is up and its note count the same (the remap prints as notes removed on hh and added on hh_open), no lane has notes quieter by more than 3, the section fill has last = peak. In `show --vel`: no `# bar N = bar M` line inside the section, the header names the new keeper. Report the rung, the accents, the crash and the fills, in two or three lines.
- Ceiling (EP 3, 4): `# lanes` shows the keeper, the kick and the backbeat at min = max = 127 (the line is song wide: confirm the section with `show --vel`). Nothing there can be raised, and a request for more never lowers. Three levers still have room, in this order (for a section he names, song-structure.md section 10 adds the tag after step 1: snare on all four quarters into its closing fill). Read first: what sits on the section's first cell and on the sixteenth before it, how the fill that leads in is built, the fills inside, and which cymbal lanes have notes.
  1. The entrance, every occurrence of the section. Weight: a second cymbal at 9 with the crash on the first cell: the crash2, china or other crash that has notes in `# lanes`. None has notes: crash2 is a new lane, add it on this cell only and say so (EP 24). Air: both hands go to the cymbals, so the sixteenth before them holds no hand note (EP 15). A fill that runs to the bar line gives up its last note, by `delete`, when that drum still sounds earlier in the fill. If that note is the only hit of its drum, keep the fill whole and stay with one crash. Set up: that fill then goes by its slot (bullet above) and rises to 117 on its new last note, unless it already ends there. Its bar lies outside the section: name it in the report (EP 7).
  2. Headroom: the fills inside the section, each by its slot (bullet above).
  3. A phrase start inside the section (bar 5 of 8): its keeper hit on cell 0 moves to the second crash, `remap bars=N beats=1-1.25 lanes=49 to=crash2`. Only when that lane has notes in `# lanes`: a silent lane would leave a hole there. One cymbal, never the stack (EP 6). Then stop. Keeper row, kick and backbeats are as they were: the report says they were already at full, names the bars that still fold as his loop, and offers step 4, never more level.
  4. Only when he asks again, or the word is more dynamic, alive or less robotic (dynamics-and-feel.md section 3): contrast. The "and"s of the keeper come down 15 to 25, never the beats, the kick or the backbeat, deepest at each phrase start and closing toward its fill: `accent SEL lanes=49 grid=16 pattern=--8-`, `humanize SEL lanes=49 v=100-119 vel=2`, then one line per 4 bar phrase, `ramp bars=5-8 lanes=49 v=100-119 scale=0.9-1.03` ("and"s from about 102 to 114 under beats that stay at 127). `diff` lists those notes as quieter and the section average drops: report it as contrast, never as bigger or louder. With a kick row of 2 or 3 per bar the other offer is four on the floor in the second half of the section (P5 bar 1 [14]).
```vd
# "make the chorus bigger" at the ceiling. Example file: a verse ends in bar 4, chorus = bars 5-8, a bridge follows and enters at 127
# read: crash1 8ths, kick and backbeats all at 127, crash1 + kick on bar 5 cell 0. `# lanes` lists a crash2 with notes
# the fill into the chorus, 4:3-5 = eight snares at 98 up to the bar line. the fill inside, 8:3-5 = snare snare, tom1 tom1, tom2 tom2, tom5 tom5 at 98, into the bridge
# 1 entrance. air: the last snare of bar 4 goes (seven are left, so the drum still sounds). set up: they rise from 98 to 117. weight: crash2 joins crash1 + kick
delete bars=4 beats=4.75-5 lanes=38
ramp bars=4 beats=3-5 lanes=38 scale=1-1.19
bar 5 grid=16
crash2 57  |9--- ---- ---- ----|
# 2 the fill inside leads into the next section: up from its first note, 106 to 117 on the floor tom
ramp bars=8 beats=3-5 lanes=snare,tom scale=1.08-1.19
```
  An 8 bar chorus also has a pickup in its bar 4 and a phrase start in its bar 5: the pickup goes by its slot (up to 107, its first note the first stroke of the rise), the phrase start by step 3. Check in `diff`: the section has more notes and a higher vel, nothing is quieter, every fill has last = peak, `# bars changed` holds the section's bars plus the bar of the lead in fill. Report the entrance (cymbal, air, the bar outside the section), the fills, and that the groove was already at full.
- Crash accents inside a section: Tre Cool crashes on chord changes and momentum shifts [12]. One crash (crash1 or crash2) + kick on cell 0 every 2 or 4 bars: digit 8 (112-118), 10 or more under the section start, which keeps the 9 (EP 6). Delete the keeper hit on that cell: the hat hand is on the crash. A single open hat (bark) needs hh 42 or hh_pedal 44 on the next eighth, or it rings on.

## 4. Kick against guitar and bass: what `lock` means here
- No riff track (the header has no `# riff:` line): there is no `# riff` row and no lock column, so nothing in this section can be read. Skip every step that names the riff or lock and say so, offer `--riff N` when the file has a pitched track, and treat every groove kick as locked: none added, moved or deleted unless he asks for exactly that (EP 21).
- The guitar strums or palm mutes constant eighths. The kick does not copy the strum: it marks beat 1, the accents, the chord changes and the pushes. Match the guitar rhythm, and when the guitar pushes the kick pushes with it [2]. American Idiot: the kick follows the rhythm of bass and guitar [1]. Basket Case: the kick sits under the rhythm guitar without competing [13]. Align kicks with power chord changes and crash accents with guitar stabs [20]. Kicks never take `humanize time=` or `shift`: they stay on the grid.
- `lock` = riff onsets with a kick in the same sixteenth cell / all riff onsets. A full strum row has 8 onsets per bar, so a correct part reads low. The ranges below are arithmetic from that definition, real file ranges unconfirmed. Sort each bar by its own `# riff` row (print the bars one by one, section 1):

| `# riff` row of the bar | kick/bar | lock | reading | on "follow the guitar", "tighten the kick to the guitar" |
|---|---|---|---|---|
| all 8 even cells (strummed or palm muted eighths) | 2-4 | 25-50% | normal. Never add kicks to raise it | nothing to delete. Pushes and accents only (moves 1, 2) |
| same | 8 | 100% | kick on every strum: double kick part in easycore, otherwise over programmed | a kick row of section 2, on his word |
| 3-6 onsets with rests of 2+ cells (syncopated chords, stabs) | the onsets, plus cells 0 and 8 | 75-100% | the guitar has a rhythm of its own and the kick plays it | moves 1, 2 and 3 |
| 1-2 onsets (held chords) | 2-4 | any | the chord rings, the kick keeps its own row | each onset has a kick or the backbeat (move 2). Nothing deleted |
| 12-16 onsets (lead, tremolo, octave line) | 2-5 | 12-40% | `--riff` picked a lead track. Ignore lock | nothing: say so |
| chug with holes (breakdown) | = onsets | 85-100% | unison. Riff rest = kick rest | moves 1, 2 and 3, cells 0 and 8 included |

"Follow the guitar" is these three moves, in this order, and never lock 100%:
1. Pushes: a riff x on cell 14 and no x on cell 0 of the next bar (often cells 0-3 are empty). The drums take the push of section 5.
2. Missing kicks: a riff x that follows 2 or more empty cells is an accent and gets a kick: `x` in the kick row writes the lane's typical velocity. An accent on a backbeat cell is carried by the snare: add nothing. `# riff` shows onsets only, palm mute against open chord is invisible: on a full row do not invent accents, use the kick rows of section 2.
3. Stray kicks, only in bars of the 3-6 row and in a chug: a kick on a cell with no riff x goes. These stay: cells 0 and 8 (the base of the beat), four on the floor, every kick inside a fill span, and the first note of a sixteenth pair whose second note sits on an x. No bar ends with fewer than 2 kicks. A riff sixteenth pair (cells 7 8, or 15 into 0) may be copied by the kick inside the limits of section 7.
```vd
# "the kick should follow the guitar". Example file, bars 1-4, keeper hh, each bar printed by itself (`show --bars 1,2,3,4`). before:
#   bar 1  kick |9-9- --9- 9-9- --9-|  riff |x--- --x- x--- x---|   4 onsets with rests: move 3. kicks on cells 2, 10, 14 sit in rests: out. the x on 12 is on the backbeat: the snare has it
#   bar 2  kick |9-9- --9- -99- --9-|  riff |x--- --x- --x- --x-|   cell 2 out. the pair 9 10 stays: it ends on an x
#   bar 3  kick |9--- --9- 9--- ----|  riff |x--- --x- x--- --x-|   x on 14 after five empty cells, and bar 4 is empty on cells 0-3: a push with no kick. move 1
#   bar 4  kick |9--- --9- 9-9- ----|  riff |---- x-x- x-x- x-x-|   the pushed downbeat. the riff comes back on cell 4
delete bars=1,2 beats=1.5-1.75 lanes=kick
delete bars=1 beats=3.5-3.75 lanes=kick
delete bars=1 beats=4.5-4.75 lanes=kick
# the push, written as bar blocks: x keeps a note as it is, - removes it. bar 3: crash at 8 and a new kick on cell 14, hat off that cell. bar 4: kick and hat leave cell 0, the hat returns on cell 4 with the riff
bar 3 grid=16
crash1 49  |---- ---- ---- --8-|
hh 42      |x-x- x-x- x-x- x---|
kick 36    |x--- --x- x--- --x-|
bar 4 grid=16
hh 42      |---- x-x- x-x- x-x-|
kick 36    |---- --x- x-x- ----|
```
  Check: every kick left has an x under it, sits on cell 0 or 8, or leads a pair. The lock column of `# sections` is not lower than before and kick/bar stays at 2 or more. Report kicks removed, kicks added and the pushes, by section, and offer to put the removed kicks back: on "only the pushes" or "keep my kick" moves 1 and 2 alone are the answer.

## 5. Pushes (anticipations)
- The whole band hits the "and" of 4 and holds over the bar line. The "and" of 4 is the most common anticipated crash [23]. New Found Glory riffs that start on the upbeat get left hand crashes [14].
- Signature: `# riff` x on cell 14, then cell 0 (often cells 0-3) of the next bar empty. A crash on 14 followed by crash + kick on 0 is a pickup, not a push.
- The edit, read from the two bars (worked in section 4, bars 3 and 4, and as a pattern in P9). Bar N: one crash on cell 14 (a section that rides the crash already has it there), the kick on 14 kept or added, the keeper hit on 14 out, the snare on 12 stays. Bar N+1: kick, crash and keeper leave cell 0, the keeper comes back on the cell of the riff's first onset in that bar (cell 2 or 4, with no riff row cell 4, unconfirmed), the snare plays 4 as usual. Do not "repair" the empty cell 0 with crash + kick: the missing downbeat is the push.
- Rank (EP 6): a push inside a section is one crash at digit 8, the kick at its own level, 10 or more under the section entrance. A push that is the entrance of the next section takes crash + kick at 9, and that section's cell 0 stays empty. Never two cymbals on a push inside a section. Default: only the hit on cell 14 and the empty cell 0. The set up (hh_open on cell 10 [23], or snare or tom pickup notes on 12-13, unconfirmed) is added notes: on "more". A fill before a push lands on cell 14, not on the next cell 0.
- Where: usually the last bar of a 2 or 4 bar chord cycle, in every cycle: if `# riff` pushes in bars 2, 4, 6 and 8, all four get the push. No riff track: only the bar he names, and say that the guitar could not be read (EP 21). A push in the last bar of the file has no next bar to clear. Other positions: cell 6 (the chord change of beat 3 pulled early) with crash + kick and no kick on 8 (unconfirmed). Notation B: cells 7 and 15.

## 6. Barker layer versus the plain layer
| device | grid | basis |
|---|---|---|
| hat bark | one hh_open at 104-122 on an "and" (first choice cell 14, then 6 or 10), closed by hh 42 on the next eighth | cymbals placed inside the groove, not only as timekeeping [11] |
| splash, bell and china accents | splash 55 at 95-115 with the kick on cell 0 or on a push, in place of a crash. ride_bell 53 on cell 6 or other offbeats. china 52 with kick + snare stabs | Adam's Song opens its bar with kick + splash, puts a bell on the "and" of 2 and lets an open hat ring through beat 3 [16] (P7 bar 2). Bolooki uses a splash for accents smaller than a crash [14]. Syncopated bell patterns [3]. China unconfirmed for Barker, used in easycore |
| cowbell | perc_cowbell 56, left hand, clave type row. The right hand moves between hat and snare | Feeling This chorus: a syncopated beat with a Latin tinge [16], the left hand plays the cowbell rhythm [9][10]. Exact cells unconfirmed |
| ghost snares | snare at 40-58 on cells 7, 9, 15, never 60+ | Barker: a ghost note on his tight snare is fully heard [8], so above the 20-45 of general guides [19]. Band unconfirmed |
| hat doubles | bar at grid=32, two adjacent hh cells on beats 1 and 2, under about 150 bpm (unconfirmed) | double strokes on the hat for verse texture [3] |
| rim click, instrument swaps, marching snare bridge | rim 37 in place of the snare or of the hat. Close the hat and swap some snares for cowbell. Bridge: snare only, grid=16, accents 9, taps 3-4 | dynamics by instrument choice instead of lower velocity [3][11]. rim counts as snare for `feel`. Rudiments with odd accents as the signature bridge [11], single strokes only, no double stroke rolls [8] |

- Plain layer (Tre Cool, early New Found Glory, Simple Plan, Good Charlotte type): hat eighths, snare 4 12, no ghost notes [13]. Verse hat, chorus ride or crash [12][13]. Kick under the guitar and bass rhythm [1][13]. Few, short fills [13][14] (Shelnutt advises against a big fill every eight bars [23]), and Tre Cool's rule is to play the song, not the instrument [12]. Modern scene (The Story So Far, Neck Deep, State Champs, Knuckle Puck, The Wonder Years): plain layer with fast beat verses and choruses, half time bridges and occasional easycore breakdowns (no source fetched, unconfirmed).
- Default to the plain layer. Barker devices are added notes: only on request ("busier", "more Travis", "more interesting") or where the file already has them, in verses, intros and bridges. Choruses stay plain (unconfirmed). The answer to such a request is a device in about every second bar of the section, never in every bar and never more than 2 in a bar (P7 bar 2 is a whole Barker bar, written only when he asks for one), more of them in the second phrase than in the first (EP 1, 12). Read first: the "and"s where the kick plays, the bars that hold a fill, push or crash, the phrase starts, the tempo, and `# lanes`. Then, in this order:
  1. Barks where the kick plays an "and" and the next eighth is a closed hat: `remap` that hat to hh_open, 14 over the hats around it, and one of them, on an "and" of 4 in the second phrase, 10 over the others. Not in a bar's fill beats, not on a cell with a crash.
  2. Each phrase start inside the section: splash + kick in place of the crash or of the hat on cell 0. A lane with count 0 in `# lanes` (splash, bell, cowbell) is written only when his words name Barker or that instrument, and the report says it is new. Otherwise take the nearest lane with notes: crash1 at digit 8 for the splash, the ride for the bell (EP 24).
  3. Under about 160 bpm: ghosts at digit 3 on cells 7 and 15, not on the same cells in every bar. Above it none. On "more": a bell on an offbeat, a cowbell row, or hat doubles, one per phrase.
```vd
# "more like Travis Barker" on a plain verse, steps 1 and 2. Example file: the verse of the block in section 3, 180 bpm (no ghosts), hats flat at 98, fills in bars 4 and 8
# barks: kick on cell 14 in bars 2 and 6 with a closed hat on the next bar's cell 0. second phrase one more: bar 7, kick on cell 10, closed by the hat on cell 12
remap bars=2,6 beats=4.5-4.75 lanes=42 to=hh_open
remap bars=7 beats=3.5-3.75 lanes=42 to=hh_open
vel bars=2,7 lanes=46 add=14
vel bars=6 lanes=46 add=24
# phrase start bar 5 holds hat + kick: the splash takes the hat's cell (he named Barker, so a splash lane with no notes is written and reported)
delete bars=5 beats=1-1.25 lanes=42
bar 5 grid=16
splash 55  |8--- ---- ---- ----|
```
  Check: `diff` shows only added and removed notes on hh, hh_open and splash, and in `show --vel` every changed bar differs from every other bar. The hats around the devices are as flat as before: name that in the report, do not fix it unasked (EP 7).

## 7. Physical limits
| part | limit | basis |
|---|---|---|
| one handed eighths on hat, ride or crash | free up to about 175 bpm. 175-210 only with two levels (8-6-, 8-5- or 6-8-), never flat. From about 190 quarters are the accepted substitute, above about 210 write quarters | eighths at about 174 bpm for a whole song are a grip endurance problem [13]. Reverse shank and tip technique above 200 [2]. Quarters on an open hat for very fast playing [4]. Some players top out at 140-150 [26]. Thresholds unconfirmed |
| sixteenth hats, hat on all 16 cells of a bar | one handed up to about 110 bpm, 130 with push pull [26]. Above that two handed up to about 180 bpm, no hat on snare cells. Notation A at 160+: implausible as a groove, 10.7+ hits per second. Notation B: normal, these are the eighths of the fast beat | |
| kick pair on adjacent sixteenth cells, single pedal | a short double kick pattern is taught at about 160 bpm and called hard there on one pedal, with heel toe, slide or a double pedal for more speed [4]: sixteenths there = 94 ms (subdivision unconfirmed). Down to about 75 ms (200 bpm) for a Barker level foot (unconfirmed) | fast single foot doubles [2][4][5] |
| 3+ kicks on adjacent sixteenth cells at 150+, kick on all 8 even cells | three adjacent: double pedal, easycore only [15][17]. All eighths: playable up to about 200 bpm [26], in style only for builds and easycore | |
| hands | at most two hand lanes per cell. The keeper stops on a cell with a crash and during two handed fills. A hand does not cross the kit in one sixteenth (EP 15) | |

- Time between hits in ms = 60000 / bpm / hits per beat (a sixteenth = 15000 / bpm). A fast beat with eighth hats rarely runs a whole song: keepers and feels change per section, and a tom verse or a half time bridge rests the hand (unconfirmed).
- Thin an eighth keeper to quarters (above the limit, as the crash rung of section 3, or on "more space"): by pitch (EP 19), for the whole section, never half of it. Read the fill bars first: no bar may end with fewer than 2 keeper hits, and a bar with a bark or a push on cell 14 stays out of the last line. `delete bars=A-B beats=1.5-2 lanes=49`, then the same line with `2.5-3`, `3.5-4` and `4.5-5`. Thinning takes notes out and turns nothing down: the beats keep their levels, also inside a request for more. A quarter row that is flat afterwards was flat before: say so. Levels come after it only on a request for less or for dynamics: "breathe" shapes the row downward (song-structure.md section 10), dynamics-and-feel.md section 5 holds the quarter row. Check: `diff` shows removed notes on that lane only, 4 per plain bar, nothing louder or quieter. Report the new rate.

## 8. Canonical patterns
Writing any bar: 1. fix the notation (section 1). 2. kick: base cells of the beat plus 0-2 riff accents (sections 2 and 4). Digits: 8 for a kick on a beat or a riff accent, 7 for the off beat note of a double, 9 only on a section start, a push into a section or a stab. On his file write `x` (the lane's typical velocity). 3. snare at 9 on the backbeat cells, no ghosts unless the Barker layer is asked for. 4. one keeper from section 3. Cell 0 of a section's first bar is crash1 9 + kick, keeper blank on that cell. 5. limb check per cell: at most 2 hand lanes, no keeper under a crash, and look one cell back (EP 15). 6. shape in the digits: eighth keepers 8-6- or 8-7-, quarters 9 on the section start, then 8. 7. then ops in EP 16 order: backbeats off the ceiling with `vel ... lanes=38 v=119-127 add=-6`, `humanize` per lane (backbeats `v=100-127 vel=3`, kick `vel=3` and never `time=`, keeper `vel=2`), then gestures of 15 or more on single bars where the kick or the phrase gives a reason (section 3), then `vel ... lanes=42 v=90-104 max=99` where a closed hat was written at 7, on the wall (EP 13). `show --vel` should then read backbeats at 116-127 and kicks within 3 of their digit. Guides quantize to 90-95%, not 100%, and warn against every snare at 127 [18]. Putting a pattern into his song (EP 20): a pattern is a set of cells, not his bar. Rows you do not write stay, so blank the old keeper with a row of `-`. A bar that holds a fill, a push or a stop keeps it. His kick row stays unless the request names the kick. A lane with count 0 in `# lanes` (china, splash, cowbell, tom5) may be silent in his kit: take the nearest lane that has notes (crash1 for china, his lowest tom for tom5) and keep the number of voices (EP 24).
```vd
# P1 straight eighth rock beat, tight hat 112/84. Verse or mid tempo chorus, 100-165 bpm. bar 1 starts a section, kick doubled on 3. bar 2: kick on the "and" of 2, hat bark on the "and" of 4, closed by the next bar's first hat (by hh_pedal 44 when a crash sits there)
bar 1 grid=16
crash1 49  |9--- ---- ---- ----|
hh 42      |--6- 8-6- 8-6- 8-6-|
snare 38   |---- 9--- ---- 9---|
kick 36    |9--- ---- 8-7- ----|
bar 2 grid=16
hh_open 46 |---- ---- ---- --8-|
hh 42      |8-6- 8-6- 8-6- 8---|
snare 38   |---- 9--- ---- 9---|
kick 36    |8--- --7- 8--- ----|
```
```vd
# P2 fast punk beat, notation A, 160-200 bpm, sloshy hat eighths (keeper hh_open). Chorus or fast verse. A catalog of kick rows, not a phrase (hold one row for 2-4 bars): bar 1 single, bar 2 doubled, bar 3 "and" of 2 and "and" of 3, bar 4 galloped
bar 1 grid=16
hh_open 46 |8-7- 8-7- 8-7- 8-7-|
snare 38   |---- 9--- ---- 9---|
kick 36    |8--- ---- 8--- ----|
copy from=1 to=2-4
bar 2 grid=16
kick 36    |8--- ---- 8-7- ----|
bar 3 grid=16
kick 36    |8--- --8- --8- ----|
bar 4 grid=16
kick 36    |8--- ---7 8--- ----|
# P3 the doubled beat of bar 2 in notation B (80-100 bpm, feel double), written here as bar 5. One B bar = two A bars: hat on every cell, snare on the "and"s, kick pairs on cells 4 5 and 12 13
bar 5 grid=16
hh 42      |8686 8686 8686 8686|
snare 38   |--9- --9- --9- --9-|
kick 36    |8--- 87-- 8--- 87--|
```
```vd
# P4 chorus keepers over one kick row, each shown as the first bar of its section. bar 1 crash quarters (any tempo), bar 2 crash eighths (up to about 175 bpm), bar 3 ride eighths with a crash on 1 (ride bell quarters for a bridge or last chorus: 8 on cells 4, 8, 12 of ride_bell 53)
bar 1 grid=16
crash1 49    |9--- 8--- 8--- 8---|
snare 38     |---- 9--- ---- 9---|
kick 36      |9--- --7- 8-7- ----|
copy from=1 to=2-3 lanes=snare,kick
bar 2 grid=16
crash1 49    |9-7- 8-7- 8-7- 8-7-|
bar 3 grid=16
crash1 49    |9--- ---- ---- ----|
ride 51      |--6- 8-6- 8-6- 8-6-|
```
```vd
# P5 bar 1 four on the floor under tight eighths: pre-chorus, second half of a chorus. bar 2 dance beat: open hat on every "and", closed hat on the beat
bar 1 grid=16
hh 42      |8-6- 8-6- 8-6- 8-6-|
snare 38   |---- 9--- ---- 9---|
kick 36    |8--- 8--- 8--- 8---|
bar 2 grid=16
hh_open 46 |--8- --8- --8- --8-|
hh 42      |6--- 6--- 6--- 6---|
snare 38   |---- 9--- ---- 9---|
kick 36    |8--- 8--- 8--- 8---|
# P8 snare on all four quarters, written here as bar 3: crash + snare unison, kick on the "and"s (or kick 0 4 8 12 under it). Reads feel normal. Last bars before a chorus: it rises and stays a digit under the entrance (EP 6). When that chorus rides crash1, write the cymbal row on hh_open 46 so its keeper is not heard early. As the ending of the song write 9 on beats 3 and 4
bar 3 grid=16
crash1 49  |7--- 7--- 8--- 8---|
snare 38   |7--- 7--- 8--- 8---|
kick 36    |--8- --8- --8- --8-|
```
```vd
# P6 two section starts. bar 1 half time (bridge, chorus tag): snare on 3, crash quarters, kick on riff accents. bar 2 easycore breakdown: china quarters, kick = chug with the second note of each pair one digit down: a double pedal, or a fast single foot (section 7)
bar 1 grid=16
crash1 49  |9--- 8--- 8--- 8---|
snare 38   |---- ---- 9--- ----|
kick 36    |9--- --8- ---- 8-7-|
bar 2 grid=16
china 52   |9--- 8--- 8--- 8---|
snare 38   |---- ---- 9--- ----|
kick 36    |9-87 --8- --87 -87-|
```
```vd
# P7 floor tom verse. bar 1 plain: the hat hand rides tom5, crash on 1. bar 2 Adam's Song type [16]: splash with the kick, bell on the "and" of 2, an open hat that rings through beat 3 on purpose and is closed by the foot on 4, kick + snare + floor tom on 4, tom pickup. Both bars read keeper `none`: no cymbal family has 2 hits
bar 1 grid=16
crash1 49    |9--- ---- ---- ----|
tom5 43      |--7- 8-7- 8-7- 8-7-|
snare 38     |---- 9--- ---- 9---|
kick 36      |9--- --7- 8--- ----|
bar 2 grid=16
splash 55    |7--- ---- ---- ----|
ride_bell 53 |---- --8- ---- ----|
hh_open 46   |---- ---- 8--- ----|
hh_pedal 44  |---- ---- ---- 5---|
tom5 43      |--7- 8--- --7- 8-67|
snare 38     |---- 9--- ---- 9---|
kick 36      |8--- ---- 8--- 8---|
```
```vd
# P9 push inside a section, written from nothing. `# riff` has x on cell 14 of bar 1 and nothing on cells 0-3 of bar 2. Crash at 8 + kick on 14 (9 only when the push is the entrance of a new section), cell 0 of bar 2 stays empty, the hat returns on beat 2. On his file keep his rows and change only these cells (section 5)
bar 1 grid=16
crash1 49  |9--- ---- ---- --8-|
hh 42      |--6- 8-6- 8-6- 8---|
snare 38   |---- 9--- ---- 9---|
kick 36    |9--- --7- 8--- --8-|
bar 2 grid=16
hh 42      |---- 8-6- 8-6- 8-6-|
snare 38   |---- 9--- ---- 9---|
kick 36    |---- --7- 8-7- ----|
```
```vd
# P10 Barker layer, written for 90-140 bpm (faster: leave the ghosts out), cowbell cells unconfirmed. bar 1 drum and bass type verse: kick 0 and 10, open hat eighths, ghosts under 60. bar 2 cowbell chorus: left hand clave type cowbell, right hand eighths between hat and snare. A linear lick (one limb per cell) closes Feeling This [10]: as a groove device unconfirmed
bar 1 grid=16
hh_open 46      |8-7- 8-7- 8-7- 8-7-|
snare 38        |---- 9--4 -3-- 9---|
kick 36         |8--- ---- --8- ----|
bar 2 grid=16
perc_cowbell 56 |7--7 --7- --7- 7---|
hh 42           |8-6- --6- 8-6- --6-|
snare 38        |---- 9--- ---- 9---|
kick 36         |8--- --8- -7-- ----|
```

## 9. What makes it sound programmed or wrong
Check the bars and lanes the edit touched, with `show --vel` and `diff`. A flaw of this list that was in his file before and lies outside the request is not fixed: name it in one line of the report (EP 7).
1. Hat on all 16 cells of a notation A bar at 160+, eighth keepers above about 210 bpm, or eighth hats at one flat velocity [2][13].
2. Kick on every guitar strum (lock near 100% on a full eighth row) outside an easycore double kick part [1][2][13]. A kick in the rest of a syncopated riff.
3. Push ignored: `# riff` hits cell 14 and rests on 0, the drums crash on 0. Or a push crash followed by crash + kick on 0 [2][23]. No riff track: cannot be judged, say so (EP 21).
4. Same keeper in verse and chorus: no lift. The chorus needs open hat, ride or crash, the verse tight hat or floor tom [12][13][21].
5. Ghost notes sprinkled into a plain fast beat [13]. Ghosts at 60+: weak backbeats that also flip the `feel` reading. Barker devices in every bar, or in a chorus that should be plain [11][12].
6. Backbeats wandering between 100 and 127: rim shot backbeats sit at 116-127 [1]. All snares at exactly 127 is the opposite fault [18]. A fill note at fill level on the backbeat cell.
7. 3 or more adjacent sixteenth kicks at 150+ in a song with no double pedal vocabulary, or sixteenth kick pairs closer than about 75 ms [4]. Half time breakdown with china and double kick in a 90s type song: that vocabulary belongs to easycore [17].
8. Keeper hit under a crash on the same cell, keeper running through a two handed fill, three hand lanes on one cell, two cymbals right after a hand note on the sixteenth before them. Open hat with no closing hat or pedal after it. Tight hat at 120+ on a chorus. Sloshy hat over a palm muted verse (unconfirmed).
9. Notation mixed up: fast beat bars written `double` inside an A file, or a B file read as a slow rock song and "fixed" with backbeats on 4 and 12.
10. Section start with no crash + kick on cell 0 (or on the push), a new kick row in every bar, or 16 identical bars with no change at bar 4 or 8 and no accent crash on chord changes [12].
11. An edit that is too small or goes the wrong way: the largest change under 15 with no note added or removed, a request for more that left notes quieter, a keeper turned down as the whole answer at the ceiling, a level op that left one value (`vel min=` or `set=` over a shaped row), a gesture smaller than the `humanize` after it (EP 3, 4, 11, 17).
12. A formula instead of a shape: accents on cells where nothing happens in the kick, the same accent cell in every bar, bars that go A B A B, one line pasted on two fills, a fill that ends under its own peak (EP 5, 9, 12).
13. Two cymbals on a landing or push inside a section, a landing louder than its section's entrance or than the first hit of the song, or the next section's keeper sounding before its first bar (EP 6).

## Sources
- [1] Drumeo, A Drummer's Guide To Punk. https://www.drumeo.com/beat/a-drummers-guide-to-punk/ [2] Drumeo, 5 Punk Drumming Tips For Beginners (And Beyond). https://www.drumeo.com/beat/5-ways-to-improve-your-punk-drumming/ [3] Drumeo, Blink-182's Travis Barker: 4+ Reasons He's A Drumming Genius. https://www.drumeo.com/beat/blink-182-travis-barker-genius/
- [4] Drum Helper, 10 Punk Drum Beats and Rhythms. https://drumhelper.com/learning-drums/punk-drum-beats-and-rhythms/ [5] Drumlessons.com, Beginner Punk Rock Drum Beats. https://www.drumlessons.com/drum-lessons/rock-drumming/beginner-punk-rock-drum-beats/ [6] Drumlessons.com, Beginner Tom-Tom Drum Beats. https://www.drumlessons.com/drum-lessons/rock-drumming/beginner-tom-tom-drum-beats/
- [7] Drum Town, Double-Time Grooves. https://drum.town/lessons/rock-double-time/ [8] DRUM! Magazine, Travis Barker In 2000: Punk Drumming Grows Up. https://drummagazine.com/travis-barker-in-2000-punk-drumming-grows-up/ [9] DRUM! Magazine, How To Play "Feeling This" By Blink-182. https://drummagazine.com/how-to-play-feeling-this-by-blink-182/
- [10] Benjamin Waterson, "Feeling This" drum transcription. https://www.benjaminwaterson.com/blog/drum-transcription-feeling-this/ [11] Drumhead Authority, Drum Analysis: What Makes Travis Barker So Special? https://drumheadauthority.com/articles/travis-barker/ [12] Drumhead Authority, Punk rock legend: Green Day drummer Tre Cool. https://drumheadauthority.com/articles/tre-cool/
- [13] The Drum Ninja, Basket Case drum transcription. https://thedrumninja.com/basket-case-drum-transcription-by-greenday/ [14] Modern Drummer, On the Beat and Track by Track with Cyrus Bolooki of New Found Glory. https://www.moderndrummer.com/2017/05/beat-track-track-cyrus-bolooki-new-found-glory/ [15] Modern Drummer, Alex Shelnutt of A Day to Remember on Bad Vibrations. https://www.moderndrummer.com/2016/08/alex-shelnutt-day-remember-bad-vibrations/
- [16] Wikipedia song articles, tempos from published sheet music and drum descriptions: https://en.wikipedia.org/wiki/Dammit https://en.wikipedia.org/wiki/The_Rock_Show https://en.wikipedia.org/wiki/All_the_Small_Things https://en.wikipedia.org/wiki/What%27s_My_Age_Again%3F https://en.wikipedia.org/wiki/Adam%27s_Song https://en.wikipedia.org/wiki/Feeling_This https://en.wikipedia.org/wiki/Misery_Business [17] Melodigging, Easycore. https://www.melodigging.com/genre/easycore [18] Nail The Mix, Toontrack Pop Punk EZX guide. https://www.nailthemix.com/toontrack-pop-punk-ezx
- [19] Toontrack, How to program drums. https://www.toontrack.com/blog/how-to-program-drums/ [20] Oracle Sound, Drum Programming Techniques for Punk and Hardcore Music. https://www.oraclesound.com/blogs/news/drum-programming-techniques-for-punk-and-hardcore-music [21] KVR Audio forum, When to use hats? When to use ride? https://www.kvraudio.com/forum/viewtopic.php?t=328431
- [22] Sick Drummer Magazine, The Skank Beat. https://sickdrummermagazine.com/news/lessons-advice/cameron-fleury-vlog/cameron-fleury-vlog-3-the-skank-beat/ [23] MusicRadar, search excerpts only: Next level grooves part 4: anticipated crashes, and Alex Shelnutt's Guide to Punk Pop Drumming. https://www.musicradar.com/how-to/next-level-grooves-part-4-anticipated-crashes and https://www.musicradar.com/news/drums/alex-shelnutts-guide-to-punk-pop-drumming-618944 [24] Melodics, Dance, Dance and Misery Business on drums, search excerpts only. https://melodics.com/learn-to-play/dance-dance-by-fall-out-boy-on-drums and https://melodics.com/learn-to-play/misery-business-by-paramore-on-drums
- [25] Tempo databases with the half tempo reading, search excerpts only. https://getsongbpm.com/song/dammit/l57RJV and https://tunebat.com/Info/First-Date-blink-182/1fJFuvU2ldmeAm5nFIHcPP [26] Hat and kick speed threads, search excerpts only. https://gearspace.com/threads/16th-note-hi-hats-question.797758/ and https://www.drumchat.com/showthread.php/35494-Some-new-questions [27] Disco beat and drum and bass two step definitions. https://www.soundbrenner.com/blogs/articles/disco-beat and https://blog.native-instruments.com/drum-patterns/
- [28] Drumeo, How To Play Four On The Floor. https://www.drumeo.com/beat/how-to-play-4-on-the-floor/ [29] Green Day tom and shuffle lessons. https://www.drumstheword.com/longview-green-day-tre-cool-free-video-drum-lesson-pdf-notation-learn-how-play-song-drums/ and https://www.onlinedrummer.com/blogs/drum-lessons/green-days-rock-shuffle-from-holiday
