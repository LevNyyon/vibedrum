# Song structure: the language above the drum layer

Read with docs/FORMAT.md. This file names the lettered sections of the `show` header, says what each section type looks like in the grid, and turns song level requests into edits.

Conventions. Cells are grid=16 indexes 0-15 in 4/4, the same numbering as grooves.md and dynamics-and-feel.md: beats 1, 2, 3, 4 = cells 0, 4, 8, 12; the "and" of each beat = cells 2, 6, 10, 14. Velocities are grid digits (a written digit d sets d x 14, 9 = 127; a shown 9 = 119-127; 2-3 = ghost) or raw 1-127. kick/bar = kick hits in one 4/4 bar. lock is in percent, as the header prints it (85% = 0.85). `[n]` = entry in the source list. "unconfirmed" = working convention, no source located. All kick/bar, vel and lock ranges are working ranges, not measured statistics (unconfirmed).

## 1. Naming the lettered sections

- Header line per section: `#   A 1-8 hh half 6.4 111 85%` = name, bars, keeper, feel, kick/bar, vel, lock. vel is the mean velocity of every drum note in the section: a clean part reads under 80, a chorus or breakdown 115+. lock is printed only when the file has a riff track.
- keeper `hh` covers every hat lane (42, 44, 46) and `ride` covers ride and ride_bell; crash1, crash2 and china print by lane. Read the rows to tell closed from open hat and bow from bell.
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
| chorus | crash1 49 or crash2 57 on quarters or eighths; ride_bell 53 quarters; hh_open | `normal` or `half` | 4-8 on chord attacks, or 16 (constant double kick) | high: snare 9, keeper 7-9 | high over held chords (few onsets), 40-80% over strummed or tremolo guitars | plainest snare row of the song, no ghosts, identical rows on every return |
| post chorus | chorus keeper stays | as chorus | back to verse level | high | 80%+ | 2-4 bars; kick rows often equal the intro |
| breakdown | china 52 or crash on quarters; half notes (cells 0, 8) when slow | `half`: snare on cell 8 only | 4-10 in bursts, rests of 2+ cells | max: kick, snare, china at 9 | 90-100% | no ghosts, no hand hats; the empty cells are part of the riff; often a gap right before it |
| bridge | toms, ride, or none | `odd`, `other`, `half` | any | mid | any | a letter that occurs once, last third of the song, often with a meter or tempo change |
| ambient or clean | ride or hh at 3-5, hh_pedal 44, or none | `open`, `half` or `other` | 0-3 | lowest: every lane at 3-5 (35-76) | low | rim 37 in place of snare (rim counts as snare for feel), ghosts, long empty spans, sparse `# riff` |
| build | none, or a crash swell | `normal` (snare on every quarter), `blast` (8+ loud snares), `other` | 4 (quarters), or rising | ramp 50-60 to 127 | low | last 1-2 bars of a letter, seldom its own; snare or tom hits per beat go 1, 2, 4; the fill span covers the whole bar |
| solo section | ride or hh, steady | `normal`, `half` or `double` | 4-8, constant bar to bar | high, flat | mid | 8 or 16 bars, fills only at phrase ends |
| outro | chorus or breakdown keeper | as its source | equal or falling | equal or falling | as source | last section; final bar is crash + kick on cell 0, then empty |

- Breakdown: half time or slower feel at unchanged tempo, quarter note crash or china (half notes when very slow), kick doubling the palm muted chugs, plain hands over a syncopated kick, silence between the notes [1][2][3]. Quarter time [3]: one snare every second bar, so half the bars have no snare and the header may read `half` or `open`.
- Verse at lower intensity, pre chorus builds anticipation, chorus is the peak [14][15]. A verse to chorus change can be as small as hat to ride [12].
- Heavy sections keep kick and snare at 8-9 throughout (backbeats 115-127 [10][11]); their level differences come from keeper, feel and density, not from kick or snare velocity (unconfirmed as a rule).

## 3. Reference bars

Verse: closed hat eighths accented 8-7 (112 and 98, near the 110 and 95 of [10]), backbeat on cells 4 and 12, two ghosts at 2 on cells with no kick, 8 kicks on the riff.
```vd
bar 1 grid=16
#            1    2    3    4
hh 42      |8-7- 8-7- 8-7- 8-7-|
snare 38   |---- 9--2 -2-- 9---|
kick 36    |9-99 --9- 9-9- --99|
```
Chorus: crash ridden on eighths, backbeat at 9, 4 kicks on chord attacks, no ghosts.
```vd
bar 2 grid=16
#            1    2    3    4
crash1 49  |9-7- 8-7- 8-7- 8-7-|
snare 38   |---- 9--- ---- 9---|
kick 36    |9--- --9- 9-9- ----|
```
Breakdown: china quarters, one snare on cell 8, 8 kicks in bursts with holes, everything at 9.
```vd
bar 3 grid=16
#            1    2    3    4
china 52   |9--- 9--- 9--- 9---|
snare 38   |---- ---- 9--- ----|
kick 36    |99-9 --99 -9-- 99--|
```

## 4. Phrase structure

- Sizes: riff cycle 1, 2 or 4 bars; phrase 4 or 8 bars; section 8 or 16 bars. Odd riff cycles are cut to fit the same blocks: the last loop is cut so the cycle restarts after "say eight bars of 4/4" [5]. Fills go at the end of the 8 bar block [12] and at transitions only [15].
- Phrase start: crash1 or crash2 (china in a breakdown) + kick on cell 0, both at 9. A hat or ride keeper skips that cell (the same hand plays the crash). China or a second crash may share it: a two hand hit, possible because no snare falls on cell 0 outside `blast`.
- Phrase end: a fill listed in the header (`8:3-5` = bar 8, beats 3 to 5), or a keeper change such as an hh_open on cell 14 leading into the next bar (unconfirmed).
- Measuring phrase length: (a) bars between crash hits on cell 0; (b) `# bar N = bar M` lines: bar 5 = bar 1 means a 4 bar cycle; (c) spacing of the fills list: bars 8, 16, 24 mean 8 bar phrases.
- Odd lengths: 3, 5, 6 or 7 bar phrases, or 4 + 4 + 4 + 2. Usual cause: an odd riff cycle cut to fit. "The Abysmal Eye" per one transcription [4]: a 26 quarter note cycle 4 times + 24 beats, and a 15 quarter cycle 4 times + 4 beats. Derived totals: 128 beats = 32 bars and 64 beats = 16 bars.
- Cycle reset: cell 0 of the first bar of the next 8 or 16 bar block, marked by a crash; the last cycle before it is cut short [5]. The kick row and `# riff` restart from their first cells there.
- Polymetric sections: bars that differ from each other are the cycle rotating, not mistakes. Never `copy` bar 1 over the phrase. Edit kicks cell by cell under `# riff`; leave the hands alone unless asked.
- One bar of 2/4 or 6/4 at a phrase end is a cut or an extension. Keep the fill inside it and the crash on cell 0 of the bar after it.

## 5. Energy without a tempo change

Ops cannot change tempo or meter. Answer "faster", "slower", "bigger", "smaller" with these levers.

1. Keeper ladder, low to high, as lane (rate, digit): none or hh_pedal 44 (quarters, 3-5) < hh 42 closed (eighths, 6-8, accented 8-7) < hh 42 with hh_open 46 on cell 14 or on the offbeats (7-8) < hh_open 46 (quarters or eighths, 7-8) < ride 51 (eighths, 6-8) < ride_bell 53 (quarters, 8-9) < crash1 49 or crash2 57 ridden (quarters 8-9, offbeat eighths 7) < china 52 (quarters, 9). The top two are flavours: crash riding reads wide (chorus), china reads harsh (breakdown, heavy verse). Sourced: hat to ride as a section change [12], a ridden crash fills more than hat or ride [18]. The rest of the order is a convention (unconfirmed); hh_open and ride are neighbours, swap them freely (ride reads cleaner, hh_open dirtier). The header prints `hh` for both hat rungs: check the rows. For "heavier" and "more aggressive" step only through hh, hh_open, ridden crash, china (the four rungs of grooves.md section 4): the ride rungs are the clean and melodic side steps, not a step toward heavy.
2. Keeper rate: half notes (cells 0, 8) < quarters < eighths < sixteenths. Fewer cymbal hits per bar go with slower feels, more with faster ones [1]. Slower on a loud cymbal = more weight. Sixteenth cymbals at speed belong to the fastest feels [1]; sixteenth hats in a slow groove (one handed up to about 110 bpm, unconfirmed) are colour, not a peak.
3. Feel [1][17]: `half` (snare on cell 8) sounds half as fast; `normal` (cells 4, 12); `double` (cells 2, 6, 10, 14) sounds twice as fast; `blast` is the ceiling. Moving the snare changes perceived speed by 2x at the same bpm. To switch: rewrite the snare row of one bar, then `copy from=N to=A-B lanes=snare`. `copy` replaces every snare lane note of the destination, so leave fill bars out of `to=`.
4. Kick density at grid=16: 2-4 sparse, 5-8 medium, 9-12 dense, 16 = constant double kick. 24 at grid=24 or 32 at grid=32 is the ceiling.
5. Ghost notes: snare at 20-50, digits 2-3 [9][10]. Adding them raises motion at low volume (verse, clean part). Deleting them makes a bar starker (chorus, breakdown).
6. Open hat: hh_open on cell 14 or on all offbeats lifts; closing it tightens.
7. No keeper: kick + snare only. At 9 it reads stark and heavy (first 2 bars of a breakdown repeat), at 3-5 it reads as a drop.
8. Velocity: general programming advice puts the kick at 100-115 on main hits and 75-95 on syncopations and the backbeat at 100-120 [9]; metal backbeats sit at 115-127 [10][11] and riff locked kicks at 9. Clean parts drop the whole kit to 3-5.

Arc template (unconfirmed): intro riff on crash or china for 4 to 8 bars; verse 1 on closed hat; pre chorus 1 to 2 rungs up; chorus on ride_bell or crash; verse 2 one rung above verse 1; breakdown on china at `half` after chorus 2; clean bridge with no keeper; last chorus = chorus plus one lever (crash on every bar start, or kick/bar 16). Two adjacent sections with every lever at maximum cancel each other: lower the first one.

## 6. Transitions

- Fill: last beat (`beats=4-5`), last 2 beats (`beats=3-5`) or whole bar (`beats=1-5`) of the final bar of a phrase. The keeper stops where the fill starts. Velocities climb into the landing [10], for example 90 to 127. Haake: a fill has to flow with the music and add to the buildup, not pull attention [6]. Working rule (unconfirmed): put fill hits on cells where `# riff` has onsets.
- Crash landing: crash1 or crash2 + kick on cell 0 of the new section, both at 9. A china or crash keeper may share that cell; a hat or ride keeper starts on cell 2 or 4.
- Drop to silence: every lane empty for the last eighth (`beats=4.5-5`), the last beat (`beats=4-5`) or a whole bar before a breakdown or a last chorus. Silence or a brief pause before a breakdown raises its impact [14]. At 140 bpm an eighth is 214 ms, a beat 429 ms. A crash or china struck before the gap rings through it (the lane map has no choke): for a dead stop end on snare, toms or kick; a stab left ringing is the other option.
- Pickup: 1 to 3 hits on cells 13-15 after a gap (snare, toms, or kick + crash on `# riff` onsets).
- Build: the pulse goes from quarters to eighths "or even faster" and aims at a snare roll or a crash [13]. In the grid: hits per beat go 1, 2, 4, one ramp up to 127 (from 60 over one bar, as in fills.md, from 50 over two bars), no keeper.
- Cymbal swell: crash or ride on every eighth or sixteenth for 1 to 2 bars with `ramp from=30 to=110`, then a gap or a landing (numbers unconfirmed).
- Feel switch: `normal` to `half` on the bar line is the standard way into a breakdown [1][3]. `half` to `normal` or `double` is the release.
- Down pre chorus: the bars before the chorus drop out instead of building. Measured in pop: 15% of the songs with a pre chorus in a 100 song corpus [16]. In metal the same shape is a clean or kick only bar before the chorus (unconfirmed).
- Tempo or meter change: shown on the bar header where it happens (`# 7/8 150bpm`) and in the summary lists (section 8). No op creates or moves one. Drums announce it: the last fill uses the new subdivision, for example a grid=12 or grid=24 fill before a triplet section (unconfirmed).
- Metric modulation: the tempo jumps by a ratio. x 3/2: quarter triplet becomes the quarter (120 to 180). x 4/3: dotted eighth becomes the quarter (120 to 160). x 2/3: dotted quarter becomes the quarter (150 to 100). Set it up one bar early by playing the new pulse on the keeper; a hit every third sixteenth is `9--9 --9- -9-- 9--9`.

Build, 2 bars: no keeper, snare + tom5 unison at 1 then 2 hits per beat, snare alone at 4 per beat, one ramp across both bars.
```vd
bar 5 grid=16
#            1    2    3    4
snare 38   |5--- 5--- 5-5- 5-5-|
tom5 43    |5--- 5--- 5-5- 5-5-|
kick 36    |9--- 9--- 9--- 9---|
bar 6 grid=16
#            1    2    3    4
snare 38   |5-5- 5-5- 5555 5555|
tom5 43    |5-5- 5-5- ---- ----|
kick 36    |9--- 9--- 9-9- 9-9-|
ramp bars=5-6 lanes=snare,tom5 from=50 to=127
```
Into a breakdown: bar 7 ends the old section with a fill on beats 3 to 4.5 and one eighth of silence; bar 8 lands crash1 + china + kick on cell 0 and switches to `half`.
```vd
bar 7 grid=16
#            1    2    3    4
hh 42      |8-7- 8-7- ---- ----|
snare 38   |---- 9--- 99-- ----|
tom3 47    |---- ---- --99 ----|
tom5 43    |---- ---- ---- 99--|
kick 36    |9-99 --9- ---- ----|
bar 8 grid=16
#            1    2    3    4
crash1 49  |9--- ---- ---- ----|
china 52   |9--- 9--- 9--- 9---|
snare 38   |---- ---- 9--- ----|
kick 36    |9-99 --9- -99- 9-9-|
ramp bars=7 beats=3-4.5 lanes=snare,tom from=95 to=127
```

## 7. Drums against the other parts

- Kick and riff. `# riff` shows guitar or bass onsets, `lock` the share of them that carry a kick. The kick doubles the palm muted chugs [2], and the standard heavy texture is a plain hand pattern over a syncopated kick [3]. Targets: breakdown 90-100%, riff verse 70-100%. To raise lock: add a kick at 9 on every `x` of `# riff` that has none. lock does not count extra kicks, so to tighten further delete kicks on cells where `# riff` is empty (not inside fills or constant double kick). Where `# riff` runs 4+ adjacent cells faster than the feet should go, kick the first cell of each group only.
- Lower lock can be on purpose: Garstka supplements bass drums with snares, for example one snare then four kicks on a riff group [8]. If a riff onset without a kick has a snare or tom on the same cell, leave it.
- Hands and feet: Haake keeps quarter note cymbals and the snare on beat 3 while the feet follow the guitar cycle [4][6]. So "simplify" means the hand rows first, "tighten" means the kick row.
- Vocals are not in the grid. Assume them in verse and chorus. Verse: one keeper, the same kick row on every riff cycle, fills only in the last bar of the phrase, ghosts under 45. Chorus: plain backbeat or `half`, crash or ride, kick on chord attacks, no fill before the last 2 beats of bar 4 or 8 (unconfirmed, practice).
- Accents. A riff onset after a rest of 2+ cells, a chord change, or a push (onset on cell 14 or 15 held over the bar line) takes crash or china + kick at 9 on that cell. After a push do not add a crash on cell 0 of the next bar (the riff has no onset there), but a crash that is already there stays unless he asks to remove it (fills.md section 6). Stabs: when `# riff` has isolated hits with rests between, write kick + crash on those cells and nothing else.
- Solo. One groove for 4 or 8 bars, ride or hat keeper, kick on the rhythm guitar (`# riff` may be the rhythm part, not the lead). Fills only at phrase ends. Step one ladder rung up every 8 bars to build. Prefer ride or hat under a lead: china or crash riding competes with it (unconfirmed).

## 8. Meter and tempo

- The summary lists changes as bar:value. `# timesig: 1:4/4 17:7/8 21:4/4` = 4/4 from bar 1, 7/8 from bar 17, 4/4 again from bar 21. `# tempo: 1:140 33:150` = 140 bpm from bar 1, 150 from bar 33. Each entry holds until the next one. A long tempo list, or one ending in `... (N changes)`, is a ramp or a recorded tempo map, not a list of section starts. Bar headers show meter and tempo where they change (`# 7/8 150bpm`).
- Cells per bar = G x num / den. At grid=16: 7/8 = 14, 5/4 = 20, 6/8 = 12, 9/8 = 18, 15/16 = 15, 17/16 = 17. Such sections report feel `odd`. `beats=` still counts quarters: the last eighth of a 7/8 bar is `beats=4-4.5`.
- One cell lasts 240000 / (bpm x G) ms: a sixteenth is 107 ms at 140 bpm, 150 ms at 100 bpm. Ticks depend on the file's PPQ (first header line): at 480 PPQ a sixteenth is 120 ticks. One writing guide suggests 90-120 bpm for heavy groove and 140-180 for aggression [15]; a 140-180 file in `half` feel is felt at 70-90.
- Odd meter: one crash on cell 0 per bar or per riff cycle, one strong snare per bar. Split the bar the way `# riff` groups it. 7/8 as 4 + 3 eighths with the snare on cell 8 is a common choice (unconfirmed).
- Alternating meters (4/4, 7/8, 4/4, 7/8): the pair is the unit, 30 sixteenths. Crash on the first bar of each pair, fill at the end of the second.
- Polymeter that resolves: hands in 4/4, kick and guitar loop a cycle of N cells [5][6][7]. Full realignment needs lcm(N, 16) cells: N=5 is 5 bars, N=6 is 3 bars, N=7 is 7 bars, N=9 is 9 bars, N=17 is 17 bars. Bands do not wait for it: the cycle is cut and restarted at bar 5, 9 or 17 [4][5]. Cases: nine hits over an 8/8 bar, repeating under a straight hand beat [6]; teaching examples of a 21/16 count restarting after 8 bars and a 17 note pattern grouped 1-3-1-2-3-3-2-2 [5]; a 17/16 guitar line in "Do Not Look Down" until the verse turns to plain 4/4 [7]; the "Clockworks" intro in groups of 2 and 3 eighths over 16 bars of 4/4 plus a 2 beat bar [19]; a 5 beat phrase over 4 beat bars meeting every 20 beats [15].
- Recognise it: meter 4/4, feel `half`, keeper on quarters, few `# bar N = bar M` lines, kick/bar moving by 1 or 2 between bars, the kick row repeating at a distance that is not 16 cells.
- Implied modulation with no tempo change: Garstka plays 11/16 with a dotted eighth feel on top in "Lippincott" [8]. In the grid: a keeper hit every 3 cells inside an odd bar.

Polymeter, 4 bar phrase: the kick loops a 5 cell cycle (`99-9-`) under 4/4 hands. 12 full cycles = 60 cells, the 13th is cut after 4 cells, the reset lands on the crash of bar 5. kick/bar reads 10, 10, 9, 10.
```vd
bar 1 grid=16
crash1 49  |9--- ---- ---- ----|
china 52   |9--- 9--- 9--- 9---|
snare 38   |---- ---- 9--- ----|
kick 36    |99-9 -99- 9-99 -9-9|
bar 2 grid=16
kick 36    |9-9- 99-9 -99- 9-99|
bar 3 grid=16
kick 36    |-9-9 9-9- 99-9 -99-|
bar 4 grid=16
kick 36    |9-99 -9-9 9-9- 99-9|
# hands repeat every bar, then the whole phrase repeats from bar 5
copy from=1 to=2-4 lanes=china,snare
copy from=1-4 to=5-8
```

## 9. Section recogniser

Match at least 3 features. The user wording column is inferred (unconfirmed).

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

Bar numbers below are stand-ins: swap in the real bars of the section. Order inside a script: bar blocks, then `copy`, `remap`, `delete`, then `accent`, `vel`, `ramp`. A script runs top to bottom, bar rows included, so the one exception is a bar block that edits a bar a `copy` writes into: it goes after that `copy` (fills.md section 6). Ops only change, move or delete notes; new notes need a bar block or `copy`.

"Make the chorus bigger": keeper to crash riding (second half on crash2 for width, optional), backbeats to 120 and up (a floor, not one value for all: dynamics-and-feel.md section 1), ghosts out, kick floor 118, crash + kick at 127 on each phrase start. Also shrink the bar before it (section 6: gap or drop). Next steps if needed: `half` feel (section 5, lever 3), or kick/bar 16 in the last chorus only.
```vd
# chorus = bars 5-8, keeper was hat eighths
remap bars=5-8 lanes=hh,hh_open to=crash1
remap bars=7-8 lanes=crash1 to=crash2
delete bars=5-8 lanes=snare v=1-62
accent bars=5-8 lanes=crash* grid=16 pattern=8-7-
vel bars=5-8 lanes=snare v=100-127 min=120
vel bars=5-8 lanes=kick min=118
vel bars=5,7 beats=1-1.25 lanes=crash*,kick set=127
```
"The verse should breathe": hands first: keeper one or more rungs down and capped at 100, ghosts capped at 34, no tom fills before bar 4, one eighth of air at the phrase end. Kick: delete only the kicks on cells with no `# riff` onset, so the lock stays. For more air switch to `half`. Thin riff locked kicks only if he asks for a sparser riff.
```vd
# verse = bars 1-4 on china quarters. Bar 1 riff |x--x ---- x-x- --x-|, kick was |9-99 -9-9 9-99 -99-|
bar 1 grid=16
kick 36    |9--9 ---- 9-9- --9-|
remap bars=1-4 lanes=china to=hh
delete bars=1-3 beats=3-5 lanes=tom
delete bars=4 beats=4.5-5 lanes=hat,kick
vel bars=1-4 lanes=hh max=100
vel bars=1-4 lanes=snare v=1-62 max=34
```
"Build into the breakdown": the last bar before it (or the last 2, section 6) becomes a build: keeper out, snare + floor tom eighths then snare sixteenths, kick on quarters then eighths, one ramp, the last eighth empty, landing at 127.
```vd
# bar 4 = last bar before the breakdown (was a plain groove bar), bar 5 = breakdown bar 1
bar 4 grid=16
snare 38   |5-5- 5-5- 5555 55--|
tom5 43    |5-5- 5-5- ---- ----|
kick 36    |9--- 9--- 9-9- 9---|
delete bars=4 lanes=hat,ride,cym
ramp bars=4 lanes=snare,tom5 from=60 to=127
vel bars=5 beats=1-1.25 lanes=kick,cym set=127
```
"The breakdown should hit harder": contrast first (gap before it), then only china, snare and kick, all at 9, ghosts out, one snare per bar on cell 8 (if the feel is `normal`, switch it with section 5, lever 3), china slowed to half notes in the second half. Do not add kicks in the rests: breakdown riffs come with silence between the notes [1].
```vd
# breakdown = bars 5-8 on china quarters, bar 4 = the bar before it
delete bars=4 beats=4.5-5
delete bars=5-8 lanes=hat,ride
delete bars=5-8 lanes=snare v=1-62
delete bars=7-8 beats=2-3 lanes=china
delete bars=7-8 beats=4-5 lanes=china
vel bars=5-8 lanes=snare,kick,china min=120
vel bars=5 beats=1-1.25 lanes=kick,cym set=127
```
"Add a drop before the last chorus": one crash + kick stab on cell 0 left ringing, nothing else up to beat 4.5, 2 snare pickup hits, full landing. Variants: the whole bar empty (`delete bars=4`), or 2 bars of kick only (`delete bars=3-4 lanes=hat,ride,cym,snare,tom`).
```vd
# last chorus starts on bar 5, bar 4 becomes the drop
bar 4 grid=16
crash1 49  |9--- ---- ---- ----|
snare 38   |---- ---- ---- --79|
kick 36    |9--- ---- ---- ----|
delete bars=4 beats=1.25-4.5
delete bars=4 beats=1-1.25 lanes=hat,ride,tom
delete bars=4 beats=4.5-5 lanes=hat,ride,cym,tom,kick
vel bars=5 beats=1-1.25 lanes=kick,cym set=127
```
"Make the second verse different from the first": keep the kick row and its lock, change the hands. Options: another keeper rung (hh to ride, or to china for a heavier verse 2), a late entry (no keeper for 2 bars, crash on re-entry), louder ghosts, or the other feel (`normal` to `half` or back). One of them is often enough; the block stacks three.
```vd
# verse 2 = bars 5-8, a plain repeat of verse 1 (show printed "# bar 5 = bar 1")
remap bars=5-8 lanes=hh to=ride
delete bars=5-6 lanes=ride
remap bars=7 beats=1-1.25 lanes=ride to=crash2
accent bars=7-8 lanes=ride grid=16 pattern=8-6-
vel bars=7 beats=1-1.25 lanes=crash2,kick set=127
vel bars=5-8 lanes=snare v=1-62 add=10 max=48
```

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
