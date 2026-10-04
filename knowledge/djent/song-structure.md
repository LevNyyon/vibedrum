# Song structure: the language above the drum layer

Read with docs/FORMAT.md and knowledge/editing-principles.md. This file names the lettered sections of the `show` header, says what each section type looks like in the grid, and turns song level requests into edits.

Conventions. Cells are grid=16 indexes 0-15 in 4/4, the same numbering as grooves.md and dynamics-and-feel.md: beats 1, 2, 3, 4 = cells 0, 4, 8, 12; the "and" of each beat = cells 2, 6, 10, 14. Velocities are grid digits or raw 1-127: a written digit d sets d x 14 exactly (9 = 127, 8 = 112, 7 = 98), a shown digit is a band 14 wide (9 = 119-127, 2-3 = ghost), so levels are checked with `show --vel`. "At 9" means the shown band, never every note at exactly 127. kick/bar = kick hits in one 4/4 bar. lock is in percent, as the header prints it (85% = 0.85). `[n]` = entry in the source list. `EP n` = rule n of knowledge/editing-principles.md: every recipe here obeys it, and where a line here seems to differ the EP rule wins. "unconfirmed" = working convention, no source located. All kick/bar, vel and lock ranges are working ranges, not measured statistics (unconfirmed).

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
- Heavy sections keep kick and snare at 8-9 throughout (backbeats 115-127 [10][11]); their level differences come from keeper, feel and density, not from kick or snare velocity (unconfirmed as a rule). A lane flat at exactly 127 is a stiff file, not a target: the keeper sits a step under kick and backbeat, and exactly 127 belongs to section starts and phrase starts (grooves.md section 4).
- The lock column needs a riff track. Without one, read the other columns and say that lock could not be read (EP 15).

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
- Phrase start: a cymbal + kick on cell 0, sized by rank (EP 4). First bar of a section: crash1 or crash2 + kick at 9; only there a stack (crash + china on one cell, two hands, no snare) is possible, and not when the song opens on a single crash unless he asks for the biggest entrance. Phrase start inside a section: one cymbal, either the china or crash keeper at 9 on that cell, or one crash in place of the hat or ride keeper hit (the same hand plays it). No phrase start or landing outranks the first hit of its section or of the song, and the next section's keeper never sounds before its first bar.
- Phrase end: a fill listed in the header (`8:3-5` = bar 8, beats 3 to 5), or a keeper change such as an hh_open on cell 14 leading into the next bar (unconfirmed).
- Measuring phrase length: (a) bars between crash hits on cell 0; (b) `# bar N = bar M` lines: bar 5 = bar 1 means a 4 bar cycle; (c) spacing of the fills list: bars 8, 16, 24 mean 8 bar phrases.
- Odd lengths: 3, 5, 6 or 7 bar phrases, or 4 + 4 + 4 + 2. Usual cause: an odd riff cycle cut to fit. "The Abysmal Eye" per one transcription [4]: a 26 quarter note cycle 4 times + 24 beats, and a 15 quarter cycle 4 times + 4 beats. Derived totals: 128 beats = 32 bars and 64 beats = 16 bars.
- Cycle reset: cell 0 of the first bar of the next 8 or 16 bar block, marked by a crash; the last cycle before it is cut short [5]. The kick row and `# riff` restart from their first cells there.
- Polymetric sections: bars that differ from each other are the cycle rotating, not mistakes. Never `copy` bar 1 over the phrase. Edit kicks cell by cell under `# riff`; leave the hands alone unless asked.
- One bar of 2/4 or 6/4 at a phrase end is a cut or an extension. Keep the fill inside it and the crash on cell 0 of the bar after it.

## 5. Energy without a tempo change

Ops cannot change tempo or meter. Answer "faster", "slower", "bigger", "smaller", "harder" with these levers: one per request, the first that has room in this file, a second only when the first is small (EP 1). He can say "more".

1. Keeper ladder, low to high, as lane (rate, digit): none or hh_pedal 44 (quarters, 3-5) < hh 42 closed (eighths, 6-8, accented 8-7) < hh 42 with hh_open 46 on cell 14 or on the offbeats (7-8) < hh_open 46 (quarters or eighths, 7-8) < ride 51 (eighths, 6-8) < ride_bell 53 (quarters, 8) < crash1 49 or crash2 57 ridden (quarters 8, offbeat eighths 7) < china 52 (quarters, 8). The top two are flavours: crash riding reads wide (chorus), china reads harsh (breakdown, heavy verse). Sourced: hat to ride as a section change [12], a ridden crash fills more than hat or ride [18]. The rest of the order is a convention (unconfirmed); hh_open and ride are neighbours, swap them freely (ride reads cleaner, hh_open dirtier). The header prints `hh` for both hat rungs: check the rows. For "heavier" and "more aggressive" step only through hh, hh_open, ridden crash, china (the four rungs of grooves.md section 4): the ride rungs are the clean and melodic side steps, not a step toward heavy. One rung per request, remapped by pitch, never onto the keeper of the next section (EP 4). A remap carries the old velocities: a flat row then gets the new rung's shape with `accent`, a shaped row keeps its own.
2. Keeper rate: half notes (cells 0, 8) < quarters < eighths < sixteenths. Fewer cymbal hits per bar go with slower feels, more with faster ones [1]. The rate follows the snare: quarters under `half`, half notes only in quarter time or when he asks for a slower cymbal by name. Thinning the keeper while kick and snare stay does not add weight, the section only loses its pulse (trial finding), so it is never a step of "harder" or "heavier". Inside a section the rate stays constant (grooves.md section 2). When he asks for a change mid section: start it on a phrase start, keep fill bars at the old rate so each still holds 2 keeper hits, and mark the first bar with one crash in place of the keeper on cell 0: `delete bars=A-B beats=2-3 lanes=52`, `delete bars=A-B beats=4-5 lanes=52`, `remap bars=A beats=1-1.25 lanes=52 to=crash1`. Sixteenth cymbals at speed belong to the fastest feels [1]; sixteenth hats in a slow groove (one handed up to about 110 bpm, unconfirmed) are colour, not a peak.
3. Feel [1][17]: `half` (snare on cell 8) sounds half as fast; `normal` (cells 4, 12); `double` (cells 2, 6, 10, 14) sounds twice as fast; `blast` is the ceiling. Moving the snare changes perceived speed by 2x at the same bpm, so it needs a feel word from him ("half time", "double time") or a yes to one question. To switch: rewrite the snare row of one bar, then `copy from=N to=A-B lanes=snare`. `copy` replaces every snare lane note of the destination, so leave fill bars out of `to=`.
4. Kick density at grid=16: 2-4 sparse, 5-8 medium, 9-12 dense, 16 = constant double kick. 24 at grid=24 or 32 at grid=32 is the ceiling. A kick row that follows the riff is not a lever: density changes only where he asks for double kick or a sparser riff.
5. Ghost notes: snare at 20-50, digits 2-3 [9][10]. Adding them raises motion at low volume (verse, clean part). Deleting them makes a bar starker (chorus, breakdown). Select them as `lanes=38 v=1-62`; no op carries one over 59 (EP 9).
6. Open hat: hh_open on cell 14 or on all offbeats lifts; closing it tightens.
7. No keeper: kick + snare only. Loud it reads stark and heavy (first 2 bars of a breakdown repeat), at 3-5 it reads as a drop.
8. Velocity: general programming advice puts the kick at 100-115 on main hits and 75-95 on syncopations and the backbeat at 100-120 [9]; metal backbeats sit at 115-127 [10][11] and riff locked kicks in digits 8-9. Clean parts drop the whole kit to 3-5. Room check first (EP 2): `# lanes` gives min/avg/max per lane for the whole song, `show --vel --bars A-B` the section. Headroom (the loudest note of the voice in the section is under 127): `vel SEL lanes=PITCH add=N` with N = 127 minus that note, so the top reaches 127 and every difference survives. Never `min=` or `set=` on a whole voice (EP 7). Ceiling (the voice is flat at 127, sd 0): nothing can be raised, the lever is contrast. Kick and backbeat stay, the keeper comes down around them: 20 on beats 2 and 4, 10 on beats 1 and 3, phrase starts left at 127 (the script is in section 10).

Arc template (unconfirmed): intro riff on crash or china for 4 to 8 bars; verse 1 on closed hat; pre chorus 1 to 2 rungs up; chorus on ride_bell or crash; verse 2 one rung above verse 1; breakdown on china at `half` after chorus 2; clean bridge with no keeper; last chorus = chorus plus one lever (crash on every phrase start, or kick/bar 16). Two adjacent sections with every lever at maximum cancel each other. The cure is to lower the first one, which is an edit outside the section he named: offer it, and do it when he names both sections or says yes (EP 5).

## 6. Transitions

- Fill: last beat (`beats=4-5`), last 2 beats (`beats=3-5`) or whole bar (`beats=1-5`) of the final bar of a phrase. The keeper stops where the fill starts. Velocities climb into the landing [10], for example 90 to 127: on notes that are already there use `ramp scale=A-B`, which keeps the hand shape; `ramp from= to=` only on a row you just wrote flat (EP 13). Haake: a fill has to flow with the music and add to the buildup, not pull attention [6]. Working rule (unconfirmed): put fill hits on cells where `# riff` has onsets.
- Fill ranks (EP 3): a one beat pickup inside a phrase < a phrase or section ending fill < the fill into a new section. After any edit the order still holds in length, peak velocity and landing, and 127 is kept for the last hit of the biggest.
- Landing: the cymbal + kick on cell 0 after a fill, sized as the phrase start it is (section 4). A hat or ride keeper starts again on cell 2 or 4. A fill in the last bar of the file has no landing bar: leave it out and say so (EP 16). A fill with no crash after it is still a fill; adding that crash is a fill request (fills.md section 6), in the recipes here it is mentioned at most (EP 17).
- Drop to silence: every lane empty for the last eighth (`beats=4.5-5`), the last beat (`beats=4-5`) or a whole bar before a breakdown or a last chorus. Silence or a brief pause before a breakdown raises its impact [14]. An eighth lasts 30000 / bpm ms: 214 ms at 140 bpm, 231 at 130. A crash or china struck before the gap rings through it (the lane map has no choke): for a dead stop end on snare, toms or kick; a stab left ringing is the other option. If `# riff` has onsets in the window the band plays through: no gap there.
- Writing the gap. It sits in the bar before the section he named: allowed as setup, always reported (EP 5). Plain groove bar: `delete bars=N beats=4.5-5 lanes=42,46,51,36`, lanes named; a kick in that window goes with the hands and is counted in the report. A bar whose fill runs to the bar line: never cut the tail. Take the fill's first eighth out and slide the rest an eighth earlier: `delete bars=N beats=3-3.5 lanes=38`, then `shift bars=N beats=3.5-5 lanes=38,48,43 ticks=-240` (an eighth = ppq / 2 ticks, lanes = the fill's pitches). Velocities and the order of the drums stay, two notes go: say so.
- Pickup: 1 to 3 hits on cells 13-15 after a gap (snare, toms, or kick + crash on `# riff` onsets), rising by 10 or more.
- Build: the pulse goes from quarters to eighths "or even faster" and aims at a snare roll or a crash [13]. In the grid: hits per beat go 1, 2, 4, one rise from about 60 to 127, no keeper (block below).
- Cymbal swell: crash or ride on every eighth or sixteenth for 1 to 2 bars, written flat, then `ramp from=30 to=110`, then a gap or a landing (numbers unconfirmed).
- Feel switch: `normal` to `half` on the bar line is the standard way into a breakdown [1][3]. `half` to `normal` or `double` is the release.
- Down pre chorus: the bars before the chorus drop out instead of building. Measured in pop: 15% of the songs with a pre chorus in a 100 song corpus [16]. In metal the same shape is a clean or kick only bar before the chorus (unconfirmed).
- Tempo or meter change: shown on the bar header where it happens (`# 7/8 150bpm`) and in the summary lists (section 8). No op creates or moves one. Drums announce it: the last fill uses the new subdivision, for example a grid=12 or grid=24 fill before a triplet section (unconfirmed).
- Metric modulation: the tempo jumps by a ratio. x 3/2: quarter triplet becomes the quarter (120 to 180). x 4/3: dotted eighth becomes the quarter (120 to 160). x 2/3: dotted quarter becomes the quarter (150 to 100). Set it up one bar early by playing the new pulse on the keeper; a hit every third sixteenth is `9--9 --9- -9-- 9--9`.

Build, 2 bars, for plain groove bars (clear their keeper with a row of `-`; leave the kick rows out when the kick follows a riff or the file has no riff track): no keeper, snare + lowest tom in unison at 1 then 2 hits per beat (snare a digit over the tom), snare alone at 4 per beat with the leading hand a digit up, one rise across both bars. The digits carry the hand shape, `ramp scale=` the rise, and the lowest snare stays over the ghost wall of 60 (EP 9). One bar build: bar 6 alone with the same ramp over `bars=6`. tom5 stands for the lowest tom with notes in `# lanes` (EP 18). Read back with `show --vel`: snare 64 to 125 with the sixteenths 113 over 99 up to 125 over 109, tom 55 to 93.
```vd
bar 5 grid=16
#            1    2    3    4
snare 38   |7--- 7--- 7-7- 7-7-|
tom5 43    |6--- 6--- 6-6- 6-6-|
kick 36    |9--- 9--- 9--- 9---|
bar 6 grid=16
#            1    2    3    4
snare 38   |7-7- 7-7- 7676 7676|
tom5 43    |6-6- 6-6- ---- ----|
kick 36    |9--- 9--- 9-9- 9-9-|
ramp bars=5-6 lanes=38,43 scale=0.65-1.3
```

## 7. Drums against the other parts

- No riff track (no `# riff:` line in the header): there is no `# riff` row and no lock column. Skip every step in this file that reads them, treat the kick row as locked (no kick added, moved or deleted unless the request itself is a gap, a drop or a kick change), and say so in the report (EP 15). Offer `--riff N` when the file has a pitched track.
- Kick and riff. `# riff` shows guitar or bass onsets, `lock` the share of them that carry a kick. The kick doubles the palm muted chugs [2], and the standard heavy texture is a plain hand pattern over a syncopated kick [3]. Targets: breakdown 90-100%, riff verse 70-100%. To raise lock: add a kick (`x`, the lane's own level) on every `x` of `# riff` that has none. lock does not count extra kicks; deleting the kicks on cells where `# riff` is empty is the next rung, only when he asks again (grooves.md section 1), and never inside fills or constant double kick. Where `# riff` runs 4+ adjacent cells faster than the feet should go, kick the first cell of each group only.
- Lower lock can be on purpose: Garstka supplements bass drums with snares, for example one snare then four kicks on a riff group [8]. If a riff onset without a kick has a snare or tom on the same cell, leave it.
- Hands and feet: Haake keeps quarter note cymbals and the snare on beat 3 while the feet follow the guitar cycle [4][6]. So "simplify" means the hand rows first, "tighten" means the kick row.
- Vocals are not in the grid. Assume them in verse and chorus. Verse: one keeper, the same kick row on every riff cycle, fills only in the last bar of the phrase, ghosts under 45. Chorus: plain backbeat or `half`, crash or ride, kick on chord attacks, no fill before the last 2 beats of bar 4 or 8 (unconfirmed, practice).
- Accents. A riff onset after a rest of 2+ cells, a chord change, or a push (onset on cell 14 or 15 held over the bar line) takes one crash + kick on that cell, a step under the section's first hit (EP 4). After a push do not add a crash on cell 0 of the next bar (the riff has no onset there), but a crash that is already there stays unless he asks to remove it (fills.md section 6). Stabs: when `# riff` has isolated hits with rests between, write kick + crash on those cells and nothing else.
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

Match at least 3 features. No riff track: lock cannot be counted, so match 3 of the others and say that lock could not be read. The user wording column is inferred (unconfirmed).

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

- Each recipe is a ladder: rungs in order, each with the condition that gives it room. Default = the first one or two rungs that change something in this file (EP 1). Then stop, report, and name the next rung as an offer. A rung whose selector would match nothing (no hats to delete, a voice already at 127) is skipped and never reported as done.
- Room (EP 2): before choosing, read `# lanes` and `show --vel` of the section. Headroom or ceiling decides the rung (section 5, lever 8).
- Mapping (EP 19): the blocks are written for an 8 bar example. Map each bar by its role (first bar, phrase start, the bar before, each fill bar), then look at what the mapped bar holds. A fill bar inside a range keeps its fill: no keeper rate change in it, no `copy` over it, and a fill that runs to the bar line is never cut at its tail.
- Scope (EP 5): the named section is the scope. The bar before it (gap, build, the fill into it) and cell 0 after it are setup and landing: allowed, and each gets a line in the report. In every other section the kick row, the backbeat and the keeper stay.
- Order (EP 11): notes (bar blocks, `copy`, `remap`, `delete`, the cell slide with `shift` of section 6), then level (`vel add=` or `scale=`), then `humanize` if the request asks for spread, then gestures (`accent`, leans with `vel add=`, rises with `ramp scale=`, one note with `set=`). Every designed difference is 10 or more (EP 12).
- Voices (EP 14): one voice = its pitch. Backbeats are `lanes=38 v=100-127`, ghosts `lanes=38 v=1-62`, hand hats `lanes=42,46`. A role name (`hat`, `cym`, `tom`) only where every voice of the family is meant.
- Fills (EP 3, 6, 7): shape each fill by its rank (section 6) with its own `bars=N beats=A-B` lines, never with the bulk `fills` selector. Flat fill: hand shape first, `accent` with the fill's own digit on the weak cells and one digit more on the leading hand (`pattern=8787` for a fill flat at 98, `7878` when the leading hand sits on the odd cells), then the rise with `ramp scale=`. The rise takes 2 to 4 off the hand gap, which stays at 10 or more. Shaped fill: skip the accent. No remap: a fill keeps its drums and its descent.
- Cases (EP 15-18): no riff track: skip the riff and lock steps and say so (section 7). A fill in the last bar of the file has no landing, and a fill with no crash after it stays a fill (section 6). A tom the kit does not have: the pitches in the blocks stand for the toms the fill has, the nearest ones with notes in `# lanes`, same number of drums.
- Check and report (EP 20, 21): `show --vel` on every changed bar, find each gesture in the numbers, then two or three lines: what changed, where, what changed outside the named section, what was skipped and why. Notes added or removed are counted in the report.

"Make the chorus bigger". Ladder: (1) the keeper one step wider, hand hats to a ridden crash by pitch, shaped, 127 on the first hit of the chorus only. One crash lane for the whole chorus: a second half on crash2 splits the letter. (2) Level, only with headroom: `vel SEL lanes=38 v=100-127 add=N` and `vel SEL lanes=36 add=N` (section 5, lever 8), ghosts out with `delete SEL lanes=38 v=1-62`, fill bars left out. (3) The bar before it smaller: the gap of section 6 or the drop below, reported as setup. (4) Only on his word: `half` feel, or kick/bar 16 in the last chorus. Default on a hat chorus: rung 1, plus rung 2 when there is room.
```vd
# said back: chorus = bars 5-8. bigger = the hand moves from the closed hat to a ridden crash, shaped, first hit at full. kick and backbeat already reach 127, so no level step
# input: hat eighths flat at 98, feel half, fill at 8:3-5. a hat row that already has a shape carries it over: skip the accent
remap bars=5-8 lanes=42,46 to=crash1
accent bars=5-8 lanes=49 grid=16 pattern=8-7-
vel bars=5 beats=1-1.25 lanes=49 set=127
```
On the demo (bars 5-8): crash1 127 on bar 5 beat 1, then 112 on the beat and 98 between, sd 9.4. Kick, backbeat, the bar 8 fill and the hats of bars 1-4 unchanged, 248 notes, the header gains a letter for bars 5-8.

"The verse should breathe". Notes come out of the hands, the kick is the riff and stays. Ladder: (1) ghosts, when there are any: `vel SEL lanes=38 v=1-62 scale=0.75`, then `delete SEL beats=1-3 lanes=38 v=1-62`, fill bars left out. (2) The keeper one step down: one rung (china to closed hat, by pitch, then `vel ... add=` into the hat's range of lever 1) or one rate step (eighths to quarters with the mask idiom below), then its shape. (3) An eighth of air where the phrase turns: `delete bars=N beats=4.5-5 lanes=42,46` in the last bar of the phrase, not where a fill runs through it. (4) Kicks on cells with no `# riff` onset come out, in bar blocks copied from `show`. No riff track: skip and say so. (5) Only on his word: `half` feel, or a sparser riff.
```vd
# said back: verse = bars 1-8. space = the hat goes from eighths to quarters with beat 1 leaning. no ghosts in the file, no riff track so the kick row stays, both fills run to the bar line so no air is cut there
# input: hat eighths flat at 98, fills at 4:4-5 and 8:3-5
# mask idiom: digit 1 on the "and" hats, then delete what is marked
accent bars=1-8 lanes=42 grid=16 pattern=--1-
delete bars=1-8 lanes=42 v=1-20
vel bars=1-8 beats=1-1.25 lanes=42 add=14
```
On the demo (bars 1-8): hat quarters, 112 on beat 1 and 98 after (shoulder against tip, on purpose), sd 6.1, 29 hats out, nothing else moved.

"Build into the breakdown". The last bar before it becomes a build (2 bars when he says long): keeper out, hits per beat 1, 2, 4, one rise, 127 on the last hit, landing on the crash + kick that open the breakdown. The kick row stays when lock is 70%+ or there is no riff track; in a free bar it goes to quarters then eighths. Plain groove bar: the block of section 6, and for a dead stop its cells 14-15 left empty. A bar that already ends in a fill keeps the fill as the top of the build, and only the front is written:
```vd
# said back: build into the breakdown = bar 4. the hat stops, the snare builds from a quarter to eighths in front of the fill that is already there, one rise across the bar, last hit at 127. kick row untouched, the fill keeps its drums
# input: bar 4 = hat eighths, fill on beats 3-5 flat at 98 (snare sixteenths, then two toms). bar 5 = breakdown with crash + kick on cell 0
bar 4 grid=16
hh 42      |---- ---- ---- ----|
# beats 3 and 4 of the snare row are copied from show
snare 38   |7--- 7-7- 7777 ----|
accent bars=4 lanes=38,48,43 grid=16 pattern=8787
ramp bars=4 lanes=38,48,43 scale=0.7-1.13
vel bars=4 beats=4.75-5 lanes=43 set=127
```
On the demo (bar 8): snare 78, 91, 98, then 104, 94, 111, 100, tom2 117, 105, tom5 123, 127. 4 hats out, 3 snare notes in, `# fills:` now reads 8:2-5, bar 9 untouched.

"The breakdown should hit harder" (also "make the drop hit harder", "more impact"). Harder is not busier and, at the ceiling, not louder. Never add kicks in the rests: breakdown riffs come with silence between the notes [1]. Never thin the keeper for this request (section 5, lever 2). Ladder:

1. Plain hands, when they are not: hand hats and ride out under a china or crash keeper (`delete SEL lanes=42,46,51,53`), ghosts out (`delete SEL lanes=38 v=1-62`, fill bars left out of `bars=`).
2. Level, when kick or backbeat has headroom: `vel SEL lanes=36 add=N`, `vel SEL lanes=38 v=100-127 add=N` (section 5, lever 8). No `min=` floor: on `lanes=snare` it lifts the fill snares and leaves their toms behind.
3. Contrast in the keeper, when it is flat or all inside digit 9: down 20, beats 1 and 3 back up 10 (15 on average), each phrase start that holds the keeper back to 127. A keeper that already has 10 or more between its downbeats and the rest: skip.
4. The fills that belong to the breakdown, when they sit a digit or more under its groove: the pickups inside it, the fill that ends it, and the fill into it (the bar before: setup, reported). Hand shape on each, then the rise by rank: a one beat pickup `ramp scale=0.94-1.04` (the smallest lift: its gesture is the hand shape, its small rise is not one to report), the ending fill `scale=0.92-1.1`, the fill into the breakdown `scale=0.92-1.13` plus 127 on its last hit, the only 127 among them. No notes added, no kick written under the hands.
5. On "more": an eighth of silence before it (section 6, second block below). A stack on its first hit only under the rule of section 4.
6. Only on his word: `half` feel when the section is `normal` (lever 3), a slower keeper (lever 2, with its crash mark), the section before it lowered.

Default = the first two rungs with room. Everything at 127, no hats, no ghosts (the demo): rungs 3 and 4.
```vd
# said back: breakdown = bars 5-8. kick, backbeat and china are already at 127, so harder = contrast in the keeper and the fills lifted by rank. no notes added, kick row and backbeat untouched
# input: china quarters flat at 127, feel half, no hats, no ghosts. fills flat at 98: 4:3-5 runs into the breakdown, 6:4-5 is a pickup, 8:3-5 ends it. phrase starts: bar 5 (crash1 + kick), bar 7 (china + kick)
# rung 3, level: keeper down
vel bars=5-8 lanes=52 add=-20
# rung 3, gestures: beats 1 and 3 lean back up, the phrase start that holds a china returns to full
vel bars=5-8 beats=1-1.25 lanes=52 add=10
vel bars=5-8 beats=3-3.25 lanes=52 add=10
vel bars=7 beats=1-1.25 lanes=52 set=127
# rung 4: hand shape on each fill window (the window holds fill notes only), then the rise by rank: pickup, ending fill, the fill into the breakdown and its last hit
accent bars=4,8 beats=3-5 lanes=38,48,43 grid=16 pattern=8787
accent bars=6 beats=4-5 lanes=38,43 grid=16 pattern=8787
ramp bars=6 beats=4-5 lanes=38,43 scale=0.94-1.04
ramp bars=8 beats=3-5 lanes=38,48,43 scale=0.92-1.1
ramp bars=4 beats=3-5 lanes=38,48,43 scale=0.92-1.13
vel bars=4 beats=4.75-5 lanes=43 set=127
```
On the demo (breakdown 9-16, phrase starts 9 and 13, fills 8:3-5, 12:4-5, 16:3-5), read back with `show --vel`: china 117 on beats 1 and 3, 107 on 2 and 4, 127 on bar 13 beat 1, sd 5.7 (was 0). Bar 12 pickup: 105, 95, 113, 102. Bar 16: 103, 93, 109, 98, 115, 103, 120, 108. Bar 8: 103, 93, 110, 99, 116, 105, 123, 127. Peaks 113, 120, 127 in rank order, hand gaps 10 to 12, the leading hand rises 17 in bar 16 and 20 in bar 8, tom2 and tom5 both still in bars 8 and 16, 248 notes before and after. To report: the bar 8 fill changed outside the section, bar 16 ends the file so its fill has no landing, kick and backbeat stay flat at 127 (not asked), the gap is on offer.
```vd
# rung 5, said back: an eighth of silence before the breakdown. the bar 4 fill runs to the bar line, so its first eighth goes and the rest slides an eighth earlier: tail, drums and velocities stay, two snare notes go
delete bars=4 beats=3-3.5 lanes=38
shift bars=4 beats=3.5-5 lanes=38,48,43 ticks=-240
```
On the demo (bar 8, applied to the result above): snare 110, 99, tom2 116, 105, tom5 123, 127 on cells 8 to 13, cells 14 and 15 empty in every lane, 246 notes, crash1 + kick on bar 9 as before.

"Add a drop before the last chorus" (or before the breakdown). The bar before it empties: one crash + kick stab on cell 0 left ringing, silence, a pickup, then the crash + kick that are already on the next cell 0 (at a section start with no crash, write one). The stab is a crash at 8, a step under the landing so the entrance stays the biggest hit, and never the keeper of the section to come (EP 4). The kicks that go are riff kicks: that is the drop, and it is counted in the report. A bar that holds a fill: the fill stays whole as the pickup, shaped as the fill into a section, and the silence runs from the stab to its first note. Plain bar: write `snare 38 |---- ---- ---- --68|` in the bar block as the pickup and delete the kicks with `beats=1.25-5`. On his word: the whole bar empty, or 2 bars of kick only (`delete bars=3-4 lanes=hat,ride,cym,snare,tom`, role names on purpose).
```vd
# said back: drop before the last chorus = bar 4. one crash + kick stab on beat 1 left ringing, then silence up to the fill, which stays whole as the pickup and rises into the landing. the hats and the kicks after beat 1 of bar 4 go
# input: bar 4 = hat eighths, kick on cell 0 and later cells, fill on beats 3-5 flat at 98. bar 5 = chorus with crash + kick on cell 0
bar 4 grid=16
crash1 49  |8--- ---- ---- ----|
delete bars=4 lanes=42,46
delete bars=4 beats=1.25-3 lanes=36
accent bars=4 beats=3-5 lanes=38,48,43 grid=16 pattern=8787
ramp bars=4 beats=3-5 lanes=38,48,43 scale=0.92-1.13
vel bars=4 beats=4.75-5 lanes=43 set=127
```
On the demo (bar 8, drop before the breakdown): crash1 112 + kick 127 on cell 0, cells 1 to 7 empty, fill 103, 93, 110, 99, 116, 105, 123, 127, bar 9 untouched. 1 crash in, 4 hats and 3 kicks out.

"Make the second verse different from the first". The kick row and the backbeat stay, one thing changes in the hands (EP 1). Take the first that fits: (1) another keeper lane as a side step, hat to ride for cleaner or to hh_open for dirtier, never the keeper of the section that follows (EP 4). (2) A late entry: `delete bars=5-6 lanes=42,46`, one crash in place of the keeper on the re-entry. (3) Ghosts one step louder: `vel SEL lanes=38 v=1-62 add=10 max=58`, the clamp is the ghost wall (EP 9). (4) The other feel, only on a feel word. After a remap a flat row gets a two beat shape and an answer in every second bar.
```vd
# said back: verse 2 = bars 5-8, a repeat of verse 1. different = the hand moves from the hat to the ride, with a shape and an answer on the "and" of 4 in bar 6. kick row, backbeat and the bar 8 fill stay
# input: hat eighths flat at 98, show printed "# bar 5 = bar 1"
remap bars=5-8 lanes=42 to=ride
accent bars=5-8 lanes=51 grid=16 pattern=8-6-7-6-
vel bars=6 beats=4.5-4.75 lanes=51 add=14
```
On the demo (bars 5-8): ride 112, 84, 98, 84 twice per bar, bar 6 ends on 98 where bars 5 and 7 have 84, fill and kick unchanged, 248 notes. Bar 5 has no crash after the bar 4 fill: mentioned, not added (EP 17).

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

Unconfirmed working numbers of section 10 (trial findings and demo checks, no outside source): the keeper contrast amounts (20, 10, 127 on phrase starts), the fill rise ranges by rank, the build ramp 0.65 to 1.3, the 0.75 ghost scale, the shapes `8-7-` and `8-6-7-6-`.
