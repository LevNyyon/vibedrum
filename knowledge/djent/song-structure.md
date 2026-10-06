# Song structure: the language above the drum layer

Read with docs/FORMAT.md and knowledge/editing-principles.md. This file names the lettered sections of the `show` header, says what each section type looks like in the grid, and turns section and song level requests into edits.

Conventions. Cells are grid=16 indexes 0-15 in 4/4, the same numbering as grooves.md and dynamics-and-feel.md: beats 1, 2, 3, 4 = cells 0, 4, 8, 12; the "and" of each beat = cells 2, 6, 10, 14. Velocities are grid digits or raw 1-127: a written digit d sets d x 14 exactly (9 = 127, 8 = 112, 7 = 98), a shown digit is a band 14 wide (9 = 119-127, 2-3 = ghost), so levels are checked with `show --vel`. "At 9" means the shown band, never every note at exactly 127. kick/bar = kick hits in one 4/4 bar. lock is in percent, as the header prints it (85% = 0.85). `[n]` = entry in the source list. `EP n` = rule n of knowledge/editing-principles.md (second version: 24 rules and the acceptance tests): every recipe here obeys it, and where a line here seems to differ the EP rule wins. "unconfirmed" = working convention, no source located. All kick/bar, vel and lock ranges are working ranges, not measured statistics (unconfirmed).

## 1. Naming the lettered sections

- Header line per section: `#   A 1-8 hh half 6.4 111 85%` = name, bars, keeper, feel, kick/bar, vel, lock. vel is the mean velocity of every drum note in the section: a clean part reads under 80, a chorus or breakdown 115+. lock is printed only when the file has a riff track.
- keeper `hh` covers every hat lane (42, 44, 46) and `ride` covers ride and ride_bell; crash1, crash2 and china print by lane, so a keeper that moves from crash1 to crash2 for 2 bars opens a new letter. Read the rows to tell closed from open hat and bow from bell.
- A letter labels a drum pattern, not a song function: the same letter means the same keeper and the same feel, nothing more. A verse and a solo on the same hat and feel share a letter. When the file has markers, the marker text replaces the letter: trust it over this document.
- A new letter needs a marker, a meter change, or a keeper or feel change that holds for 2 to 3 bars. So a 1 or 2 bar build, drop, tag or short pre chorus sits inside its neighbour's letter: find those on the grid and in the `# fills:` list. Header fields are heuristics; the grid wins.
- Assign a function to each letter with the table in section 2 and the recogniser in section 9. Position prior: intro, verse, pre chorus, chorus, verse, pre chorus, chorus, bridge or breakdown, chorus, outro is the stated standard layout, and bands leave it constantly [14]. Djent often leaves it (riff chains that never return, instrumentals with no vocal sections); then name sections by drum function: riff, half time riff, breakdown, clean, solo.
- Two sections are the same function returning (verse 1 and 2; chorus 1, 2, 3) when they share keeper and feel, kick/bar is within 1 and the kick rows match. Among returning sections the one with the highest vel is usually the chorus. The last chorus is normally the energy peak (unconfirmed for metal).
- Resolve every user word to `bars=A-B` before writing an op. If two sections fit ("the heavy part" with two breakdowns), edit both or ask.

## 2. Section signatures

| section | keeper | feel | kick/bar | vel | lock | grid tells |
|---|---|---|---|---|---|---|
| intro | none, or the keeper of the section it previews | `open`, or as verse or chorus | 0-8 | rising | high | first section; kick + crash stabs on riff accents with rests between, or guitar alone (`# bars 1-4 empty`) then full kit at bar 5 or 9 |
| verse | hh 42 eighths; ride 51 eighths; china 52 quarters when heavy | `normal` or `half` | 6-12, syncopated | snare 8-9, keeper 6-8 | 70-100% | kick row mirrors `# riff`; ghost snares at 2-3; fills only in the last bar of 4 or 8 |
| pre chorus | differs from the verse: hh_open 46, ride, or toms | `half`, `open`, or as verse | below the verse, or rising bar over bar | rising | mid | 2, 4 or 8 bars; last bar ends in a fill of 2+ beats, or everything drops out |
| chorus | crash1 49 or crash2 57 on quarters or eighths; ride_bell 53 quarters; hh_open | `normal` or `half` | 4-8 on chord attacks, or 16 (constant double kick) | high: snare 9, keeper 7-8, 127 on its first hit | high over held chords (few onsets), 40-80% over strummed or tremolo guitars | plainest snare row of the song, no ghosts, identical rows on every return |
| post chorus | chorus keeper stays | as chorus | back to verse level | high | 80%+ | 2-4 bars; kick rows often equal the intro |
| breakdown | china 52 or crash on quarters; half notes (cells 0, 8) only in quarter time | `half`: snare on cell 8 only | 4-10 in bursts, rests of 2+ cells | kick and backbeat in digit 9; keeper 105-120, 127 on phrase starts only | 90-100% | no ghosts, no hand hats; the empty cells are part of the riff; often a gap right before it |
| bridge | toms, ride, or none | `odd`, `other`, `half` | any | mid | any | a letter that occurs once, last third of the song, often with a meter or tempo change |
| ambient or clean | ride or hh at 3-5, hh_pedal 44, or none | `open`, `half` or `other` | 0-3 | lowest: every lane at 3-5 (35-76) | low | rim 37 in place of snare (rim counts as snare for feel), ghosts, long empty spans, sparse `# riff` |
| build | none, or a crash swell | `normal` (snare on every quarter), `blast` (8+ loud snares), `other` | 4 (quarters), or rising | rising, about 60 to 127 | low | last 1-2 bars of a letter, seldom its own; snare or tom hits per beat go 1, 2, 4; the fill span covers the whole bar |
| solo section | ride or hh, steady | `normal`, `half` or `double` | 4-8, constant bar to bar | high, flat | mid | 8 or 16 bars, fills only at phrase ends |
| outro | chorus or breakdown keeper | as its source | equal or falling | equal or falling | as source | last section; final bar is crash + kick on cell 0, then empty |

- Breakdown: half time or slower feel at unchanged tempo, quarter note crash or china, kick doubling the palm muted chugs, plain hands over a syncopated kick, silence between the notes [1][2][3]. Quarter time [3]: one snare every second bar, so half the bars have no snare and the header may read `half` or `open`; only there the keeper drops to half notes.
- Verse at lower intensity, pre chorus builds anticipation, chorus is the peak [14][15]. A verse to chorus change can be as small as hat to ride [12].
- Heavy sections keep kick and snare at 8-9 throughout (backbeats 115-127 [10][11]); their level differences come from keeper, feel and density, not from kick or snare velocity (unconfirmed as a rule). A lane flat at exactly 127 is a stiff file, not a target: the keeper sits a step under kick and backbeat, and exactly 127 belongs to section starts and phrase starts (grooves.md section 4). The table is for naming a section, not a level to edit toward: no recipe here lowers a lane to reach it.
- The lock column needs a riff track. Without one, read the other columns and say that lock could not be read (EP 21).

## 3. Reference bars

Verse: closed hat eighths accented 8-7 (112 and 98, near the 110 and 95 of [10]), backbeat on cells 4 and 12, two ghosts at 2 on cells with no kick, 8 kicks on the riff.
```vd
bar 1 grid=16
#            1    2    3    4
hh 42      |8-7- 8-7- 8-7- 8-7-|
snare 38   |---- 9--2 -2-- 9---|
kick 36    |9-99 --9- 9-9- --99|
```
Chorus, first bar: crash ridden on eighths, 9 on the first hit only, backbeat at 9, 4 kicks on chord attacks, no ghosts.
```vd
bar 2 grid=16
#            1    2    3    4
crash1 49  |9-7- 8-7- 8-7- 8-7-|
snare 38   |---- 9--- ---- 9---|
kick 36    |9--- --9- 9-9- ----|
```
Breakdown, first bar of a phrase: china quarters with the 9 on the phrase start and 8 after, one snare on cell 8, 8 kicks in bursts with holes. Later bars of the phrase start on 8.
```vd
bar 3 grid=16
#            1    2    3    4
china 52   |9--- 8--- 8--- 8---|
snare 38   |---- ---- 9--- ----|
kick 36    |99-9 --99 -9-- 99--|
```

## 4. Phrase structure

- Sizes: riff cycle 1, 2 or 4 bars; phrase 4 or 8 bars; section 8 or 16 bars. Odd riff cycles are cut to fit the same blocks: the last loop is cut so the cycle restarts after "say eight bars of 4/4" [5]. Fills go at the end of the 8 bar block [12] and at transitions only [15].
- Phrase start: a cymbal + kick on cell 0, sized by rank (EP 6). First bar of a section: crash1 or crash2 + kick at 9. A stack (two cymbals on one cell, two hands, no snare) belongs there and nowhere else: take it when the request is about that section's entrance or impact. Phrase start inside a section: one cymbal, either the china or crash keeper at 9 on that cell, or one crash in place of the keeper hit (the same hand plays it). No phrase start or landing inside a section outranks the first hit of that section or of the song, and the next section's keeper never sounds before its first bar.
- Phrase end: a fill listed in the header (`8:3-5` = bar 8, beats 3 to 5), or a keeper change such as an hh_open on cell 14 leading into the next bar (unconfirmed).
- Measuring phrase length: the distance between fills, or between crash hits on cell 0, whichever is shorter (fills in bars 4, 8, 12, 16 = 4 bar phrases, each starting in the bar after a fill). `# bar 5 = bar 3` lines give the riff cycle, which is often shorter than the phrase: a 2 bar riff inside 4 bar phrases is normal.
- Odd lengths: 3, 5, 6 or 7 bar phrases, or 4 + 4 + 4 + 2. Usual cause: an odd riff cycle cut to fit. "The Abysmal Eye" per one transcription [4]: a 26 quarter note cycle 4 times + 24 beats, and a 15 quarter cycle 4 times + 4 beats. Derived totals: 128 beats = 32 bars and 64 beats = 16 bars.
- Cycle reset: cell 0 of the first bar of the next 8 or 16 bar block, marked by a crash; the last cycle before it is cut short [5]. The kick row and `# riff` restart from their first cells there.
- Polymetric sections: bars that differ from each other are the cycle rotating, not mistakes. Never `copy` bar 1 over the phrase. Edit kicks cell by cell under `# riff`; leave the hands alone unless asked.
- One bar of 2/4 or 6/4 at a phrase end is a cut or an extension. Keep the fill inside it and the crash on cell 0 of the bar after it.

## 5. Energy without a tempo change

Ops cannot change tempo or meter. "Faster", "slower", "bigger", "smaller", "harder" are answered with these levers. The list is the inventory, not the order: a request takes the two or three levers with the most impact in this file (EP 1, 2), and for a section the order is entrance, then weight and width, then its fills (section 10). He can say "more" or "less".

1. Keeper ladder, low to high, as lane (rate, digit): none or hh_pedal 44 (quarters, 3-5) < hh 42 closed (eighths, 6-8, accented 8-7) < hh 42 with hh_open 46 on cell 14 or on the offbeats (7-8) < hh_open 46 (quarters or eighths, 7-8) < ride 51 (eighths, 6-8) < ride_bell 53 (quarters, 8) < crash1 49 or crash2 57 ridden (quarters 8, offbeat eighths 7) < china 52 (quarters, 8). The top two are flavours: crash riding reads wide (chorus), china reads harsh (breakdown, heavy verse). Sourced: hat to ride as a section change [12], a ridden crash fills more than hat or ride [18]. The rest of the order is a convention (unconfirmed); hh_open and ride are neighbours, swap them freely (ride reads cleaner, hh_open dirtier). The header prints `hh` for both hat rungs: check the rows. For "heavier" and "more aggressive" step only through hh, hh_open, ridden crash, china (the four rungs of grooves.md section 4): the ride rungs are the clean and melodic side steps, not a step toward heavy. One rung per request, remapped by pitch, never onto the keeper of the next section (EP 6). A remap carries the old velocities: a flat row then gets a shape read from this file (section 10, the chorus recipe), a shaped row keeps its own.
2. Keeper rate: half notes (cells 0, 8) < quarters < eighths < sixteenths. Fewer cymbal hits per bar go with slower feels, more with faster ones [1]. The rate follows the snare: quarters under `half`, half notes only in quarter time or when he asks for a slower cymbal by name. Thinning the keeper while kick and snare stay does not add weight, the section only loses its pulse (trial finding), so it is never a step of "harder" or "heavier". Inside a section the rate stays constant (grooves.md section 2). When he asks for a change mid section: start it on a phrase start, keep fill bars at the old rate so each still holds 2 keeper hits, and mark the first bar with one crash in place of the keeper on cell 0: `delete bars=A-B beats=2-3 lanes=52`, `delete bars=A-B beats=4-5 lanes=52`, `remap bars=A beats=1-1.25 lanes=52 to=crash1`. Sixteenth cymbals at speed belong to the fastest feels [1]; sixteenth hats in a slow groove (one handed up to about 110 bpm, unconfirmed) are colour, not a peak.
3. Feel [1][17]: `half` (snare on cell 8) sounds half as fast; `normal` (cells 4, 12); `double` (cells 2, 6, 10, 14) sounds twice as fast; `blast` is the ceiling. Moving the snare changes perceived speed by 2x at the same bpm, so it needs a feel word from him ("half time", "double time") or a yes to one question. To switch: rewrite the snare row of one bar, then `copy from=N to=A-B lanes=snare`. `copy` replaces every snare lane note of the destination, so leave fill bars out of `to=`.
4. Kick density at grid=16: 2-4 sparse, 5-8 medium, 9-12 dense, 16 = constant double kick. 24 at grid=24 or 32 at grid=32 is the ceiling. A kick row that follows the riff is not a lever: density changes only where he asks for double kick or a sparser riff. A kick under a hand hit that is already there is weight, not density (section 7).
5. Ghost notes: snare at 20-50, digits 2-3 [9][10]. Adding them raises motion at low volume (verse, clean part). Deleting them makes a bar starker (chorus, breakdown). Select them as `lanes=38 v=1-62`; no op carries one over 59 (EP 13).
6. Open hat: hh_open on cell 14 or on all offbeats lifts; closing it tightens.
7. No keeper: kick + snare only. Loud it reads stark and heavy (first 2 bars of a breakdown repeat), at 3-5 it reads as a drop.
8. Velocity and the ceiling (EP 3, 4). General programming advice puts the kick at 100-115 on main hits and 75-95 on syncopations and the backbeat at 100-120 [9]; metal backbeats sit at 115-127 [10][11] and riff locked kicks in digits 8-9. Clean parts drop the whole kit to 3-5. Room check first: `# lanes` gives min/avg/max per lane for the whole song, `show --vel --bars A-B` the section. Headroom (the loudest note of the voice in the section is under 127): `vel SEL lanes=PITCH add=N` with N = 127 minus that note, so the top reaches 127 and every difference survives. Never `min=` or `set=` on a whole voice (EP 11). Ceiling (the voice is flat at 127, sd 0): nothing can be raised and "louder" is not a true report. Then take, in this order: weight (a kick under the hit, a second cymbal on the entrance), air (silence right before the hit), the lanes of the section that still have room (its fills). Turning the keeper down around the hits is the last step, 15 to 25 on its weak positions only, and never the answer on its own (section 10, "hit harder", step 4).

Arc template (unconfirmed): intro riff on crash or china for 4 to 8 bars; verse 1 on closed hat; pre chorus 1 to 2 rungs up; chorus on ride_bell or crash; verse 2 one rung above verse 1; breakdown on china at `half` after chorus 2; clean bridge with no keeper; last chorus = chorus plus one lever (crash on every phrase start, or kick/bar 16). Two adjacent sections with every lever at maximum cancel each other. The cure is to lower the first one, which is an edit outside the section he named: offer it, and do it when he names both sections or says yes (EP 7).

## 6. Transitions

- Fill: last beat (`beats=4-5`), last 2 beats (`beats=3-5`) or whole bar (`beats=1-5`) of the final bar of a phrase. The keeper stops where the fill starts. Velocities climb into the landing [10]: on notes that are already there use `ramp scale=A-B` with A at 1 or above, which keeps the hand shape and lowers nothing; `ramp from= to=` only on a row you just wrote (EP 18). Haake: a fill has to flow with the music and add to the buildup, not pull attention [6]. Working rule (unconfirmed): put fill hits on cells where `# riff` has onsets.
- Fill ranks (EP 5): a one beat pickup inside a phrase < a section fill (the fill into a section, and the last fill of a section, which leads into whatever follows it). The ranks differ by a digit at the top and in length or weight. Two fills of one rank still differ in something designed: the contour, the drum that carries the top, the kick under it. Shaping: the fills rule of section 10.
- Entrance and landing (EP 6): the cymbal + kick on cell 0 after a fill, sized as the phrase start it is (section 4). It stands over what comes right before it: 10 or more over the last note of the fill, or air. A hat or ride keeper starts again on cell 2 or 4. A fill in the last bar of the file has no landing bar: leave it out and say so (EP 22). A fill with a plain keeper hit after it is still a fill: the recipes here mark the phrase starts of the named section only, anywhere else the missing crash is mentioned, not added (EP 23, fills.md section 6).
- Air: every lane empty for the last eighth (`beats=4.5-5`), the last beat (`beats=4-5`) or a whole bar before a breakdown or a last chorus. Silence or a brief pause before a breakdown raises its impact [14]. An eighth lasts 30000 / bpm ms: 214 ms at 140 bpm, 231 at 130. A crash or china struck before the gap rings through it (the lane map has no choke): for a dead stop end on snare, toms or kick; a stab left ringing is the other option. `# riff` onsets in the last eighth: the guitar plays through and the drums still stop, say so. A whole beat or more with riff onsets in it is a drop: on his word.
- Writing the air. It sits in the bar before the section he named: setup, always reported (EP 7). Plain groove bar: `delete bars=N beats=4.5-5 lanes=42,46,51`, lanes named. A kick in that window is locked and stays (section 7, EP 7): then there is no air, say so. A fill that runs to the bar line: never cut its tail. One eighth comes out of the drum that has the most notes in the fill, and every fill note after it slides an eighth earlier: `delete bars=N beats=A-B lanes=PITCH`, then `shift bars=N beats=B-5 lanes=<the fill's pitches> ticks=-T` with T = ppq / 2 (240 at ppq 480). Drums, order and velocities stay, two notes go, and the fill ends on its last drum an eighth early: say so. No drum holds more than two notes: an eighth would cost a voice, so take the last 16th out instead and let the top sit on the eighth cell before it. `diff` counts the slid notes as removed and added, not as moved. This is the air of a section entrance; the smaller air of a fill request (the last 16th out) is fills.md section 6.
- Pickup: 1 to 3 hits on cells 13-15 after a gap (snare, toms, or kick + crash on `# riff` onsets), rising by 10 or more.
- Build: the pulse goes from quarters to eighths "or even faster" and aims at a snare roll or a crash [13]. In the grid: hits per beat go 1, 2, 4, one rise, no keeper (recipe in section 10).
- Cymbal swell: crash or ride on every eighth or sixteenth for 1 to 2 bars, written flat, then `ramp from=30 to=110`, then a gap or a landing (numbers unconfirmed).
- Feel switch: `normal` to `half` on the bar line is the standard way into a breakdown [1][3]. `half` to `normal` or `double` is the release.
- Down pre chorus: the bars before the chorus drop out instead of building. Measured in pop: 15% of the songs with a pre chorus in a 100 song corpus [16]. In metal the same shape is a clean or kick only bar before the chorus (unconfirmed).
- Tempo or meter change: shown on the bar header where it happens (`# 7/8 150bpm`) and in the summary lists (section 8). No op creates or moves one. Drums announce it: the last fill uses the new subdivision, for example a grid=12 or grid=24 fill before a triplet section (unconfirmed).
- Metric modulation: the tempo jumps by a ratio. x 3/2: quarter triplet becomes the quarter (120 to 180). x 4/3: dotted eighth becomes the quarter (120 to 160). x 2/3: dotted quarter becomes the quarter (150 to 100). Set it up one bar early by playing the new pulse on the keeper; a hit every third sixteenth is `9--9 --9- -9-- 9--9`.

## 7. Drums against the other parts

- No riff track (no `# riff:` line in the header): there is no `# riff` row and no lock column. Skip every step that only reads them, take the "without a riff track" branch where a recipe has one, and say so in the report (EP 21). Every groove kick counts as locked: none is moved or deleted unless the request itself is a gap, a drop or a kick change. A kick added under a hand hit that is already there is weight, not a change to the riff. Under a backbeat: only where the kick already plays on both cells beside it, never in a rest of 2 or more cells. Under a fill of the scope: on its strong notes, the way the file's other fills carry the kick (section 10, fills rule).
- Kick and riff. `# riff` shows guitar or bass onsets, `lock` the share of them that carry a kick. The kick doubles the palm muted chugs [2], and the standard heavy texture is a plain hand pattern over a syncopated kick [3]. Targets: breakdown 90-100%, riff verse 70-100%. To raise lock: add a kick (`x`, the lane's own level) on every `x` of `# riff` that has none. lock does not count extra kicks; deleting the kicks on cells where `# riff` is empty is the next step, only when he asks again (grooves.md section 1), and never inside fills or constant double kick. Where `# riff` runs 4+ adjacent cells faster than the feet should go, kick the first cell of each group only.
- Lower lock can be on purpose: Garstka supplements bass drums with snares, for example one snare then four kicks on a riff group [8]. If a riff onset without a kick has a snare or tom on the same cell, leave it, unless a "hit harder" request puts the kick under that hit (section 10).
- Hands and feet: Haake keeps quarter note cymbals and the snare on beat 3 while the feet follow the guitar cycle [4][6]. So "simplify" means the hand rows first, "tighten" means the kick row.
- Vocals are not in the grid. Assume them in verse and chorus. Verse: one keeper, the same kick row on every riff cycle, fills only in the last bar of the phrase, ghosts under 45. Chorus: plain backbeat or `half`, crash or ride, kick on chord attacks, no fill before the last 2 beats of bar 4 or 8 (unconfirmed, practice).
- Accents. A riff onset after a rest of 2+ cells, a chord change, or a push (onset on cell 14 or 15 held over the bar line) takes one crash + kick on that cell, a step under the section's first hit (EP 6). After a push do not add a crash on cell 0 of the next bar (the riff has no onset there), but a crash that is already there stays unless he asks to remove it (fills.md section 6). Stabs: when `# riff` has isolated hits with rests between, write kick + crash on those cells and nothing else.
- Solo. One groove for 4 or 8 bars, ride or hat keeper, kick on the rhythm guitar (`# riff` may be the rhythm part, not the lead). Fills only at phrase ends. Step one ladder rung up every 8 bars to build. Prefer ride or hat under a lead: china or crash riding competes with it (unconfirmed).

## 8. Meter and tempo

- The summary lists changes as bar:value. `# timesig: 1:4/4 17:7/8 21:4/4` = 4/4 from bar 1, 7/8 from bar 17, 4/4 again from bar 21. `# tempo: 1:140 33:150` = 140 bpm from bar 1, 150 from bar 33. Each entry holds until the next one. A long tempo list, or one ending in `... (N changes)`, is a ramp or a recorded tempo map, not a list of section starts. Bar headers show meter and tempo where they change (`# 7/8 150bpm`).
- Cells per bar = G x num / den. At grid=16: 7/8 = 14, 5/4 = 20, 6/8 = 12, 9/8 = 18, 15/16 = 15, 17/16 = 17. Such sections report feel `odd`. `beats=` still counts quarters: the last eighth of a 7/8 bar is `beats=4-4.5`.
- One cell lasts 240000 / (bpm x G) ms: a sixteenth is 107 ms at 140 bpm, 115 at 130, 150 at 100. Ticks depend on the file's ppq (first header line): at 480 a sixteenth is 120 ticks, an eighth 240. One writing guide suggests 90-120 bpm for heavy groove and 140-180 for aggression [15]; a 140-180 file in `half` feel is felt at 70-90.
- Odd meter: one crash on cell 0 per bar or per riff cycle, one strong snare per bar. Split the bar the way `# riff` groups it. 7/8 as 4 + 3 eighths with the snare on cell 8 is a common choice (unconfirmed).
- Alternating meters (4/4, 7/8, 4/4, 7/8): the pair is the unit, 30 sixteenths. Crash on the first bar of each pair, fill at the end of the second.
- Polymeter that resolves: hands in 4/4, kick and guitar loop a cycle of N cells [5][6][7]. Full realignment needs lcm(N, 16) cells: N=5 is 5 bars, N=6 is 3 bars, N=7 is 7 bars, N=9 is 9 bars, N=17 is 17 bars. Bands do not wait for it: the cycle is cut and restarted at bar 5, 9 or 17 [4][5]. Cases: nine hits over an 8/8 bar, repeating under a straight hand beat [6]; teaching examples of a 21/16 count restarting after 8 bars and a 17 note pattern grouped 1-3-1-2-3-3-2-2 [5]; a 17/16 guitar line in "Do Not Look Down" until the verse turns to plain 4/4 [7]; the "Clockworks" intro in groups of 2 and 3 eighths over 16 bars of 4/4 plus a 2 beat bar [19]; a 5 beat phrase over 4 beat bars meeting every 20 beats [15].
- Worked arithmetic: a 5 cell kick cycle (`99-9-`) under 4/4 hands fills a 4 bar phrase with 12 full cycles = 60 cells, the 13th is cut after 4 cells, and the reset lands on the crash of bar 5. kick/bar reads 10, 10, 9, 10. The bars for such a pattern are grooves.md P1.
- Recognise it: meter 4/4, feel `half`, keeper on quarters, few `# bar N = bar M` lines, kick/bar moving by 1 or 2 between bars, the kick row repeating at a distance that is not 16 cells.
- Implied modulation with no tempo change: Garstka plays 11/16 with a dotted eighth feel on top in "Lippincott" [8]. In the grid: a keeper hit every 3 cells inside an odd bar.

## 9. Section recogniser

Match at least 3 features. No riff track: lock cannot be counted, so match 3 of the others and say that lock could not be read. The vel and lock numbers are working ranges: a stiff file at 127 everywhere still matches on keeper, feel and kick shape. The user wording column is inferred (unconfirmed).

| what the header and grid show | section | what the user calls it |
|---|---|---|
| keeper hh or ride, feel `normal` or `half`, kick/bar 6-12, lock 70%+, ghosts present, returns after the chorus | verse | "the verse", "the groove", "the riff part", "under the vocals" |
| 2-8 bars before the chorus, keeper differs from the verse, kick thinner or rising, last bar has a fill of 2+ beats | pre chorus | "the lift", "the part before the chorus", "the ramp" |
| keeper crash1 or crash2, `ride` with bell rows (53) or `hh` with open rows (46); highest vel among returning sections, kick/bar 4-8 or exactly 16, plain snare row, returns 2-3 times unchanged | chorus | "the hook", "the big part", "the melodic part", "the singing part" |
| keeper china or crash on quarters or half notes, feel `half`, lock 90%+, kick bursts with rests of 2+ cells, no ghosts, a gap before it | breakdown | "the heavy part", "the chugs", "the drop", "the slow part", "the mosh part" |
| no keeper or keeper at 3-5, kick/bar 0-3, rim 37 or no snare (feel `open`, `half` or `other`), every velocity under 77 | ambient or clean interlude | "the quiet part", "the clean part", "the atmospheric bit" |
| snare or tom hits per beat doubling, velocities rising left to right, keeper missing, fill span = whole bar | build | "the build", "the roll", "the riser" |
| first section; feel `open`, or kick + crash stabs on riff accents, or rows equal to a later section | intro | "the start", "the opening riff" |
| chorus keeper with verse level kick/bar and lock, 2-4 bars right after a chorus | post chorus | "the riff after the chorus", "the tag" |
| a letter that occurs once, last third of the song, feel `odd` or `other`, tom lanes on eighths or sixteenths with no cymbal keeper, meter or tempo change | bridge | "the middle part", "the weird part", "the tribal part" |
| steady ride or hat keeper, feel `normal`, `half` or `double`, kick/bar constant within 1, fills only every 4th or 8th bar, 8-16 bars | solo section | "under the solo", "the lead part", "the shred part" |
| last section; rows equal the chorus or breakdown; final bar = crash + kick on cell 0 then rests; density or vel falling | outro | "the ending", "the last hit", "the fade" |
| 4/4, feel `half`, keeper on quarters, kick rows differ bar to bar, kick/bar moves by 1-2 | polymetric riff (verse or main riff) | "the Meshuggah part", "the riff that goes over the bar" |
| feel `blast` or `double`, kick/bar 16+, snare on every eighth or sixteenth | fast section (verse or bridge variant) | "the fast part", "the blast part" |

## 10. Song level requests as edits

Rules for every recipe below:

- Order of impact (EP 1, 2). A section request is answered with these levers, in this order: (1) the entrance: air before it, the kick and a second cymbal on its first hit; (2) weight and width inside it: a kick under the hits, level where a voice has headroom, the keeper one step wider; (3) the fills in and around it brought up to the section, each ending on its top. The default answer is the two or three of these that have room in this file, all in one script. Fine shaping comes after them and never alone. A lever whose ops would change nothing is skipped and never reported as done.
- Direction (EP 3, 4). "Bigger", "harder", "more impact" and "build" never leave a note of the section quieter than it was: shape by raising the strong notes, and a `ramp scale=` on notes that are there starts at 1 or above. At the ceiling use weight, then air, then the lanes that still have room. Turning notes down is the last step, on his word, never the answer ("hit harder", step 4). "Breathe" and "smaller" are the mirror: nothing in scope gets louder.
- Read before writing: `show --vel` of the section, the bar before it and the bar after it. Note per bar: what sits on cell 0 (which cymbals, a kick), what sits under the backbeat (a kick on that cell, kicks on the cells beside it), where each phrase starts (section 4), and for each fill its span, the cell it opens on, its drums in order, pairs or alternation, the kick under it, and what follows it (a crash, a plain keeper hit, the end of the file).
- A worked answer is one example, not a script to paste (EP 20). Its `# input` lines name the grid facts each cell, level and bar came from. Another file gives other cells: write your own rows from `show`. Never keep a block and swap the bar numbers, and never put two fills on one line.
- Scope (EP 7): the named section is the scope. The bar before it (air, a build, the fill into it) and cell 0 after it are setup and landing: allowed, and each gets its words in the report. In every other section the kick row, the backbeat and the keeper stay, and a flaw there is named, not fixed.
- Fills (EP 5, 8, 9, 10). Shape each fill from its own figure: (a) raise, never trim: no note ends under its old value; (b) a one beat fill is one rise into its top (`ramp scale=A-B`, A at 1 or above). A longer fill leans one digit on its strong notes (the first note of each pair on one drum, and in a two drum alternation the notes of the lower drum, which is the heavy voice) and also rises through its body, `ramp scale=1-B` with B up to 1.1 and small enough that no note passes the top; (c) the last note is the loudest, on the lowest drum of the fill. Its level: 127 for a section fill with air or the end of the song after it, 10 or more under the entrance that follows when there is no air, 113 to 117 for a pickup inside a phrase; (d) a fill of the named section that opens on the backbeat cell carries the backbeat there, at the section's backbeat level, when it also ends at that level (air or the end of the song after it); (e) drums, order and note count stay, no remap; (f) the kick: a fill of 2 beats or more inside the named scope with no kick under it gets one under its strong notes, and under its last note when that is at 127. With a riff track the kick goes on the `# riff` onsets of the span instead (a span with no riff onset is the band leaving room for the fill: under the strong notes). Look first at how the file's other fills carry the kick. A pickup keeps the kick it has.
- Order of ops (EP 16 to 19): notes (bar blocks, `remap`, `delete`, the slide with `shift`), then level (`vel add=`), then gestures (`accent`, `ramp scale=`, `set=` on one note). One voice = its pitch: backbeats `lanes=38 v=100-127`, ghosts `lanes=38 v=1-62`, hand hats `lanes=42,46`. No `humanize` in these recipes: two bars differ by design (phrase, kick, fill), never by spread.
- Cases (EP 21 to 24): no riff track: take the "without a riff track" branch where a step has one, skip what only reads `# riff` or lock, and say so (section 7). A fill in the last bar of the file has no landing. A lane the kit has no notes on: the nearest lane with notes, same number of voices.
- Check after every apply, with `vibedrum diff ORIGINAL RESULT` and `show RESULT --vel` on the changed bars (the acceptance tests of the EP file). `# sections`: the named section at the same or a higher vel, or with more notes ("breathe": lower, or fewer), and its distance to the section before it not smaller. `# lanes`: 0 in the last column for the lanes of the section ("breathe": 0 louder). `# fills`: last within 5 of peak for every fill you touched, 10 or more between a pickup and a section fill, no two sequences alike. No `# bar N = bar M` line inside the section. `# bars changed`: the section plus the bars your report names. A failed line means another script from the same starting file.
- Report: two or three lines read off the diff: what got louder, what was added or removed with counts, what changed outside the named section, what was skipped and why. Never "harder" or "bigger" for a change the diff shows as quieter.

"The breakdown should hit harder" (also "make the drop hit harder", "more impact"). Harder is entrance and weight: not busier, not a trim, and never an answer that only lowers. Never kicks into the holes of the groove bars: breakdown riffs come with silence between the notes [1]. Never a thinner keeper (section 5, lever 2). The default is steps 1 to 3 in one script:

1. Entrance. Air: when the drums of the bar before the section run to the bar line, their last eighth goes silent (section 6: a plain bar by `delete`, a fill by the slide, so it ends early on its top). Already a gap there: nothing to do. First hit: cell 0 gets what it lacks of kick, crash and the section's keeper cymbal, so two cymbals and the kick sound together, only here (section 4).
2. Weight in the groove bars. Hands that are not plain are cleared first, as part of this step and never as the answer: hand hats and ride under a china or crash keeper go, ghosts go (`delete SEL lanes=42,46,51,53`, `delete SEL lanes=38 v=1-62`, fill bars left out). Then take the first of these that has room in this file. The next one is his "more":
   - Headroom: `vel SEL lanes=36 add=N`, `vel SEL lanes=38 v=100-127 add=N` (section 5, lever 8).
   - A kick under the hand hits that have none, written into the kick row copied from `show`. With a riff track: under the backbeat and under each keeper hit, on every such cell where `# riff` has an onset and the kick row is empty (lock rises with it; riff onsets with no kick and no hand hit are lock repair, section 7: name them, do not add them). Without a riff track: under the backbeat only, and only where the kick plays on both cells beside it (the snare sits inside a burst). A hit standing in a rest keeps its hole.
   - No cell for a kick: the lowest tom with notes joins the keeper and the kick on beat 1 of every bar after the section's first where the kick plays (the snare hand is free there, and a tom on the same beat of most bars does not turn up in `# fills:`).
   Grade what you add, so the section rises and bars that were equal in `show` do not stay equal: one digit under the kick's level in the first phrase (or half), at that level from the second phrase start on, and that phrase start gets one crash in place of the keeper hit (section 4).
3. The fills of the section, by the fills rule: the pickups inside it, its last fill with the kick under it, and the rise of the fill before it (setup, reported, no kick added there).
4. Keeper contrast is not part of the default: only when he asks for it (dynamics in the cymbal, or "more" after everything above). Weak positions only (beats 2 and 4 under a half feel), down 15 to 25, never beat 1, the backbeat cell or a phrase start: `vel SEL beats=2-3 lanes=52 add=-20`. It turns notes down, so `diff` lists the lane as quieter: report it in those words. `# sections` must still show the section at or above its starting vel and no closer to the section before it: take fewer positions (beat 2 only) before a smaller amount.

"More" after the default, in this order: the next lever of step 2; a whole beat of air; then, on his word, `half` feel when the section is `normal`, the section before it lowered, step 4.
```vd
# said back: breakdown = bars 5-8. harder = a bigger entrance (the bar 4 fill ends an eighth early and loses two notes, crash added to the china + kick of bar 5), a kick under the backbeats where the guitar plays and the kick did not, its fills raised to the section and ending on their tops. nothing gets quieter
# input: riff track, lock 81% in bars 5-8. bars 5-8 all at 127 except the fills at 98. bar 5 cell 0 = china + kick, no crash (crash1 has notes in bar 1). phrases 5-6 and 7-8
#   backbeat on cell 8: a riff onset and no kick in bars 5 and 7, bar 6 has its kick. every china hit on a riff onset has its kick
#   bar 4 fill 3-5 runs to the bar line: snare 8-9, tom3 10-11, tom5 12-15, no kick under it, the guitar plays through
#   bar 6 pickup 4-5: snare 12-13, tom5 14-15, kick under 12 and 14. bar 8 fill 3-5: snare 8-11, tom5 12-15, no kick, riff on 8, 10, 12, 14, 15, last bar of the file
# 1 entrance. air: the eighth comes out of tom5 (four notes, the most), its last two notes slide to cells 12-13. first hit: crash1 joins china + kick
delete bars=4 beats=4-4.5 lanes=43
shift bars=4 beats=4.5-5 lanes=43 ticks=-240
bar 5 grid=16
crash1 49  |9--- ---- ---- ----|
# 2 weight. kick row copied from show, one cell changed: cell 8, where the riff row has an x and the kick row had none. an 8 in phrase 1, a 9 in phrase 2
# riff     |xx-x --xx xx-- xx--|
kick 36    |99-9 --99 89-- 99--|
bar 7 grid=16
kick 36    |99-9 --99 99-- 99--|
# the second phrase start: one crash in place of the china, the stack stays with the entrance
remap bars=7 beats=1-1.25 lanes=52 to=crash1
# 3 fills, each from its own figure. bar 8 ends the section and the file: backbeat on cell 8, first note of each pair 8, last note 9, kick on the riff onsets of the span, then a rise through the middle
bar 8 grid=16
snare 38   |---- ---- 9787 ----|
tom5 43    |---- ---- ---- 8789|
# riff     |x--x xx-x x-x- x-xx|
kick 36    |9--9 99-9 9-9- 9-99|
ramp bars=8 beats=3.25-4.75 lanes=38,43 scale=1-1.1
# bar 6 pickup, one beat: one rise through both pairs, top on the last tom5, a digit under the section fills
ramp bars=6 beats=4-5 lanes=38,43 scale=1.04-1.18
# bar 4 (setup, outside the section): its toms rise into the last note before the air, the snare notes stay as written
ramp bars=4 beats=3.5-4.5 lanes=47,43 scale=1-1.3
```
What this example does not show. No riff track: step 2 reads the kick row instead of `# riff` (a kick under the backbeat where cells 7 and 9 hold a kick), and the kick under the last fill goes under the first note of each pair and under its last note. A pickup that alternates two drums (snare, floor tom, snare, floor tom) takes the rise on both and 8 more on the floor tom (`vel ... lanes=43 add=8`). A longer section has more groove bars and phrases: each bar gets its own kick row, and each later phrase differs from the one before in something added (the crash on its start, the next lever of step 2 in the last one). Outside the section only the rise into the air: every point added there closes the gap to the section.

"Make the chorus bigger". Width first, then level, then its fill. (1) Entrance and keeper: the hand moves one step wider (section 5, lever 1), hand hats to a ridden crash by pitch, one crash lane for the whole chorus, its first hit at 127 with the kick. The row keeps its level and leans one digit where the crash meets a kick or the backbeat, so each bar's row follows that bar's kick. (2) Level, only with headroom: `vel SEL lanes=38 v=100-127 add=N`, `vel SEL lanes=36 add=N`, ghosts out with `delete SEL lanes=38 v=1-62`, fill bars left out. (3) The fill that ends the chorus comes up to the new keeper (fills rule: a longer one also takes its lean and its kick). "More": air before the chorus (section 6). On his word: `half` feel, kick/bar 16 in the last chorus.
```vd
# said back: chorus = bars 5-8. bigger = the hand moves from the closed hat to a ridden crash that leans where the kick and the backbeat land, crash + kick at full on its first hit, the backbeat up to 127, the fill that ends it up to the new keeper
# input: bars 5-8 hat eighths flat at 98, hat + kick on bar 5 cell 0, half feel with the backbeat on cell 8 at 118 (9 of headroom), kick at 127
#   kick under the eighth cells 0, 6, 8, 10 in bars 5, 7 and 8, and under 0, 6, 8, 12, 14 in bar 6
#   fill 8:4-5 in pairs (snare 12-13, tom3 14-15) at 98, the hat stops under it. a section entrance follows it with no air
remap bars=5-8 lanes=42,46 to=crash1
# crash rows: 8 on the cells listed above, the old 7 elsewhere, 9 on the first hit
bar 5 grid=16
crash1 49  |9-7- 7-8- 8-8- 7-7-|
bar 6 grid=16
crash1 49  |8-7- 7-8- 8-7- 8-8-|
bar 7 grid=16
crash1 49  |8-7- 7-8- 8-8- 7-7-|
bar 8 grid=16
crash1 49  |8-7- 7-8- 8-8- ----|
vel bars=5-8 lanes=38 v=100-127 add=9
# the fill is one beat: one rise into its top on the last tom3, 10 under the 127 entrance that follows
ramp bars=8 beats=4-5 lanes=38,47 scale=1.05-1.19
```

"The verse should breathe". The mirror: notes and level come out of the hands, nothing gets louder, the kick is the riff and stays. (1) The keeper one rate step down (eighths to quarters, mask idiom below) or one rung down by pitch. (2) Ghosts out of the first half of each bar. (3) What is left of the keeper shaped downward: its weak beats 15 to 25 under the strong ones, each phrase relaxing toward its turn. "More": an eighth of air at a phrase turn that has no fill (`delete bars=N beats=4.5-5 lanes=42,46`); with a riff track, kicks on cells with no `# riff` onset come out. On his word: `half` feel, a sparser riff.
```vd
# said back: verse = bars 1-8. breathe = the hat goes from eighths to quarters with beats 2 and 4 softer, each phrase relaxes toward its fill, the ghosts leave the first half of each bar. nothing gets louder, kick and backbeat stay
# input: hat eighths flat at 98, ghosts at 30, half feel so beats 2 and 4 are the weak quarters, phrases 1-4 and 5-8, both end in a fill (bars 4 and 8) so no air is cut, no riff track so the kick row stays
# mask idiom: digit 1 on the "and" hats, then delete what is marked
accent bars=1-8 lanes=42 grid=16 pattern=--1-
delete bars=1-8 lanes=42 v=1-20
delete bars=1-3,5-7 beats=1-3 lanes=38 v=1-62
vel bars=1-8 beats=2-3 lanes=42 add=-16
vel bars=1-8 beats=4-5 lanes=42 add=-16
# each phrase starts at its level and relaxes, the second one deeper, so no two bars come out the same
ramp bars=1-4 lanes=42 scale=1-0.87
ramp bars=5-8 lanes=42 scale=1-0.78
```

"Build into the breakdown". The last bar before it becomes a build (2 bars when he says long): keeper out, hits per beat 1, 2, 4, one rise that ends on its top. The entrance must still stand over it (EP 6): the top stops 10 or more under the crash + kick it lands on, or reaches 127 with an eighth of air after it. The kick of the groove part stays when lock is 70%+ or there is no riff track (in a free bar it goes to quarters, then eighths); under a fill that has none it follows the fills rule (f). Plain groove bar: clear the keeper row and write snare and the lowest tom with notes in unison at 1 then 2 hits per beat (snare a digit over the tom), the snare alone at 4 per beat, in rising digits 5, 6, 7, 8, the lowest snare over the ghost wall of 60 (EP 13). A bar that already ends in a fill keeps the fill as the top of the build, and only the front is written:
```vd
# said back: build into the breakdown = bar 4. the hat stops, the snare builds 1 then 2 hits per beat in front of the fill that is there, a kick goes under the fill, and the fill rises to a top 10 under the crash + kick of bar 5
# input: no riff track. bar 4 = hat eighths on beats 1-2, no snare there, kick on cells 0, 2, 5, 7, fill on beats 3-5 at 98 in pairs (snare 8-9, tom3 10-11, tom5 12-13 and 14-15), no kick under it. bar 5 opens on crash + kick at 127 with no air, so the top is 116, not 127
bar 4 grid=16
hh 42      |---- ---- ---- ----|
# beat 1 one hit, beat 2 two hits, below the fill's level. x keeps the fill notes that are there
snare 38   |5--- 6-6- xx-- ----|
# kick row copied from show, a kick added under the first note of each pair of the fill
kick 36    |9-9- -9-9 9-9- 9-9-|
ramp bars=4 beats=3-5 lanes=38,47,43 scale=1-1.18
```

"Add a drop before the last chorus" (or before the breakdown). Air is the lever: the bar before it empties. One crash + kick stab on cell 0 left ringing (a crash at 8, a step under the landing, never the keeper of the section to come), silence, a pickup, then the crash + kick already on the next cell 0 (write one at a section start that has none). The kicks that go are riff kicks: that is the drop, and it is counted in the report. A bar that holds a fill: the fill stays whole as the pickup and the silence runs from the stab to its first note. The groove has stopped, so that first note is a pickup note, not a backbeat, the top stays 10 or more under the entrance, and no kick goes under the fill: the feet come back on the entrance. Plain bar: a two note pickup on cells 14-15 (`snare 38 |---- ---- ---- --78|` in the bar block) and the kicks deleted with `beats=1.25-5`. On his word: the whole bar empty, or 2 bars of kick only (`delete bars=3-4 lanes=hat,ride,cym,snare,tom`, role names on purpose).
```vd
# said back: drop before the last chorus = bar 4. one crash + kick stab on beat 1 left ringing, silence up to the fill, the fill stays whole as the pickup with no kick under it and rises to a top 10 under the entrance. the hats and 3 kicks of bar 4 go
# input: bar 4 = hat eighths on beats 1-2, kick on cells 0, 2, 5, 7, fill on beats 3-5 at 98 (snare, tom3, tom5). bar 5 = chorus with crash + kick on cell 0 at 127
bar 4 grid=16
crash1 49  |8--- ---- ---- ----|
delete bars=4 lanes=42,46
delete bars=4 beats=1.25-3 lanes=36
ramp bars=4 beats=3-5 lanes=38,47,43 scale=1-1.18
```

"Make the second verse different from the first". Not more and not less: the average stays about level, the kick row and the backbeat stay, one thing changes in the hands. The first that fits: (1) another keeper lane as a side step, hat to ride for cleaner or to hh_open for dirtier, by `remap`, never the keeper of the section that follows (EP 6), with a lean read from this file as in the chorus recipe; (2) a late entry: the keeper out for the first 2 bars (`delete bars=5-6 lanes=42,46`) and one crash in place of its first hit on the re-entry; (3) ghosts one step louder: `vel SEL lanes=38 v=1-62 add=10 max=58`, the clamp is the ghost wall (EP 13); (4) the other feel, only on a feel word. Afterwards the bars of that verse must not fold onto each other in `show --vel`: an answer in every second bar or a lift into its fill, 15 or more, makes the difference.

## Sources

1. Garza, "Transcending Time (Feels)", Music Theory Online 27.1: https://mtosmt.org/issues/mto.21.27.1/mto.21.27.1.garza.html
2. Wikipedia, Breakdown (music): https://en.wikipedia.org/wiki/Breakdown_(music)
3. Drumeo, A Drummer's Guide To Metal: https://www.drumeo.com/beat/a-drummers-guide-to-metal/
4. Drumstickler, The Abysmal Eye transcription overview: https://drumstickler.substack.com/p/the-abysmal-eye-transcription-overview
5. Modern Metal Academy, The Meshuggah algorithm unlocked: https://www.modernmetalacademy.com/post/the-meshuggah-algorithm-unlocked
6. DRUM! Magazine, Tomas Haake, Meshuggah Goes It Alone: https://drummagazine.com/tomas-haake-meshuggah-goes-it-alone/
7. Drumeo, Tomas Haake, 5 Reasons He's A Drumming Genius: https://www.drumeo.com/beat/meshuggah-tomas-haake-genius/
8. DRUM! Magazine, Matt Garstka, Let's Get Technical: https://drummagazine.com/matt-garstka-lets-get-technical/
9. Toontrack, How to program drums: https://www.toontrack.com/blog/how-to-program-drums/
10. Nail The Mix (URM), modern metal drum programming FAQs: https://www.nailthemix.com/drum-programming-faqs
11. Nail The Mix (URM), GetGood Drums Matt Halpern library: https://www.nailthemix.com/getgood-drums-matt-halpern-drums-library
12. Sound on Sound, Programming Realistic Drum Parts: https://www.soundonsound.com/techniques/programming-realistic-drum-parts
13. Nail The Mix (URM), How to create build ups in metal songs: https://www.nailthemix.com/how-to-create-build-ups-in-metal-songs
14. Develop Device, The Art of Crafting a Modern Metal Song: https://developdevice.com/blogs/news/the-art-of-crafting-a-modern-metal-song-a-comprehensive-guide
15. Lyric Assistant, How to Write Djent Songs: https://lyricassistant.com/how-to-write-djent-songs/
16. Geary, "Formal Functions of Drum Patterns in Post-Millennial Pop Songs, 2012-2021", Music Theory Online 30.2 (100 song pop corpus, not metal): https://mtosmt.org/issues/mto.24.30.2/mto.24.30.2.geary.html
17. Wikipedia, Half-time (music): https://en.wikipedia.org/wiki/Half-time_(music)
18. FreeDrumLessons, Drumming Dynamics, live lesson 17 (crash, ride and hat as timekeepers): https://freedrumlessons.com/drum-lessons/drumming-dynamics-live.php
19. Drumstickler, Clockworks intro breakdown: https://drumstickler.substack.com/p/clockworks-meshuggah-intro-breakdown

Tried and unreadable (truncated or paywalled), so nothing here rests on them: MusicRadar Periphery II track by track, MusicRadar Periphery guide to recording drums, Modern Drummer June 2019 Halpern feature, Prog Report Halpern interview.

Unconfirmed working numbers of section 10 (two blind trials and checks with `vibedrum diff`, no outside source): the order of the levers, the kick under the hand hits and the floor tom on beat 1 with their grading by phrase (8 then 9), the kick under a fill, the fill tops (127, 10 under the entrance, 113 to 117), the rises `1-1.1`, `1.04-1.18`, `1.05-1.19`, `1-1.18` and `1-1.3`, the keeper contrast of 15 to 25 on the weak positions, the breathe amounts (16 down, phrases to 0.87 and 0.78), the build digits 5, 6, 7, 8.
