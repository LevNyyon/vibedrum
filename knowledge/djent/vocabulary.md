# Vocabulary: the request playbook

What a word means in modern metal and djent, what to do without asking, and where the detail lives. Workflow: resolve the scope (section 1), look up the word (section 4) and the target (section 5), settle doubt with section 2, check section 3 before you apply.

Pointers: "grooves 4" = grooves.md section 4, "fills" = fills.md, "feel" = dynamics-and-feel.md, "song" = song-structure.md. Cells are grid=16 indexes 0-15 (beat 1 = cell 0, beat 3 = cell 8). `SEL` = the resolved selector, for example `bars=9-16`. Tick values are for 140 bpm at 480 ppq (feel 8 rescales them). "unconfirmed" = working default of this pack, no source found.

## 1. Scope: what the words select

| he says | selector | watch for |
|---|---|---|
| fills, rolls, "my fills" | `fills` once every span in `# fills:` is confirmed and none is missing (fills 2), else `bars=N beats=A-B` per fill. Beat 1 of the next bar (the landing) belongs to the fill | the header misses kick only fills, stops, stabs and short pickups, and wrongly flags tom grooves and ghost clusters |
| hats, hi hat | `lanes=42` closed, `lanes=46` open, `lanes=hat` both plus the foot (44) | the keeper of the scope is not a hat: he means the cymbal that keeps time. Edit that keeper and say so |
| cymbals | `lanes=cym` (crash, china, splash), plus `lanes=ride` | in a hat section "the cymbals" are the crashes and accents, not the hat |
| kick, feet, double bass | `lanes=kick` | lock 85% or more: the riff owns the row, change velocities only (grooves 1) |
| snare | backbeats `lanes=38 v=100-127`. `lanes=snare` also matches rim 37 and snare2 40 | ghosts and fill notes are not "the snare" unless he names them |
| ghost notes | `lanes=38 v=1-62`, with fill bars left out of `bars=` | always under 60 (feel 9) |
| toms | `lanes=tom`, one drum `lanes=tom5` | toms that repeat bar after bar are a tom groove, not fills (fills 2) |
| a named section | `bars=A-B` of every occurrence | the mapping rules below |
| the whole song | drop `bars=` only when one recipe fits every section. Otherwise one group of ops per section, with that section's values | sections that return get the same edit |

- Bar numbers he gives win over everything else.
- "My fills", "the fills": every confirmed fill of the song. "The fill", "that fill": the one inside the bars last shown, played or edited, else the last fill before the section just discussed.
- "The chorus", "the verse": every occurrence. "First", "second", "last" pick one. "Into X", "before X", "the transition": the last bar before X (two bars if he says long) plus beat 1 of X. "The end of X": its last bar.
- "Here", "this part", "that riff": the bars of the last `show --bars`, `play --bars` or edit in this conversation. No such context: ask (section 2).
- "The intro", "the ending": first and last section. "The heavy part", "the quiet part", "the fast part", "the Meshuggah part": the wording column of song 9.
- A lane with no scope ("the hats"): every section where that lane plays. A word with no target and no scope ("heavier"): the bars last discussed, else the whole song, on the word's default target (section 4).
- Scope never grows on its own. A hat request leaves kick, snare and fills alone. A fill request leaves the groove bars alone, except the landing cell.

Section names to the engine's letters:

1. `# markers:` in the header names sections directly. Markers win.
2. No markers: a letter means one keeper plus one feel, not a song function (song 1). Give each letter a function with song 2 and song 9, then the position prior: intro, verse, pre chorus, chorus, verse, pre chorus, chorus, bridge or breakdown, chorus, outro.
3. Quick tells. Verse: hh or ride keeper, ghosts, lock 70%+. Chorus: the returning letter with the highest vel and the plainest snare row. Breakdown: china or crash on quarters, feel half, lock 90%+, rests in the kick row. Clean part: every lane at digits 3-5.
4. A function can be a slice of a letter (a 1 or 2 bar build, drop or pre chorus never gets its own letter), and one function can span two letters. Always end at `bars=A-B`.
5. The same letter at two places is the same pattern returning: "the second verse" is the second range of the verse's letter.
6. Say the mapping in the report: "chorus = B, bars 9-16 and 25-32".

## 2. Ambiguity: default or ask

Act on the default and state it in one line when:

- the word has a default target in section 4 and the scope resolves with section 1;
- the only open point is how much: take one step (one ladder rung, one fill level, one rate step);
- two readings differ in size, not in kind;
- the edit stays inside hands, velocities or one fill. Every version is a new file, so a wrong guess costs him one undo.

Ask exactly one question, two concrete options, the default first, when:

- "here" or "this part" has no context, or a section name fits two sections that need different edits ("the heavy part" with both a breakdown and a blast section);
- the request can only be met by breaking a rule of section 3: thinning or moving a riff locked kick, moving the backbeat without a feel word, removing a landing crash;
- the word has two kinds of meaning and the grid does not decide: "drop" as a gap or as the breakdown, "tighter" when the hands are already plain and lock is 85%+ (levels, timing or kick placement);
- "more like" names a band this pack does not cover: ask for the one trait he wants (keeper, feel, kick style or fills).

Never ask what the grid answers: where the fills are, which bars the chorus is, the tempo, whether a riff track exists. Never ask a second question. After the answer, act.

The one line holds the interpretation, the scope and what stayed: "Heavier fills: lower toms, kick under every hit, 120 and up, two cymbal landings, on the fills in bars 4, 8, 12 and 16. Groove bars untouched."

## 3. Do no harm

Whatever the word was, an edit in this style never breaks these:

1. Kick and riff lock. Kicks on `# riff` x cells are never deleted, moved, shifted or given `humanize time=`. `lock` after the edit is not lower than before. New kicks go on riff onsets, into a carpet, or into a fill he asked for. No kicks into the rests of a breakdown riff.
2. Polymeter. Where the kick row differs in every bar under identical hand rows, never `copy` one bar of kick over the others (whole blocks only). The keeper spacing and the snare cell stay constant: they are the 4/4 anchor.
3. The backbeat. It stays on its cells (4 and 12, or 8) unless he used a feel word, stays in digits 8-9, gets no random timing beyond 2 ticks, and no ghost op reaches it: bound ghost ops with `v=1-62`.
4. Crash landings. Beat 1 after every fill keeps its crash (or the section's keeper at digit 9) plus a kick on the same cell. Shorten a fill from the front, never cut its tail. A fill you add gets a landing. A push does not remove the crash on the next beat 1.
5. Phrase and section starts. Crash + kick on cell 0 stays. The bar after a fill is the plain groove from beat 2 at the latest.
6. Untouched notes. Copy rows from `show` and change only the cells you mean: a kept character keeps its exact velocity and micro timing. Never rewrite a bar at a coarser grid than `show` printed. A row of only `-` clears the lane in that bar. `copy` replaces the destination lanes: keep fill bars out of `to=`.
7. Selector hygiene. Every op carries `lanes=` and, unless the whole song is meant, `bars=`. `lanes=snare` includes the rim, `lanes=hat` includes the foot, `lanes=ride` includes the bell.
8. Limbs. At most two hand lanes on a cell, plus kick, plus hh_pedal. No keeper while both hands are on drums. No closed hat on a crash or china cell. No hh_pedal on a cell with a stick hat or in a beat with a kick run.
9. One keeper per section. It changes only on a section boundary, marked with crash1 + kick on cell 0.
10. Silence. Gaps before a drop, stops and the holes of a breakdown riff stay empty. "Busier" and "heavier" add at most one pickup hit there.
11. Fill inventory. At most one fill per 4 bars, no two identical in a section, none added inside a lock 85%+ section with a quarter note china or crash keeper unless he asks (there: unison hits on riff onsets at the section end).
12. Velocity bounds. Ghosts under 60 (`show` reads 60 or more as a backbeat, which can flip the feel label). No hand lane flat at one value, nothing flat at 127. Kick on the riff and backbeats live in digits 8-9: never spread them wider than `humanize vel=3`.
13. Once only. `humanize` and `shift` stack: run each once per lane per section, and redo from the version before. Bar blocks first, `shift` last. A bar block for a `copy` destination goes after that `copy`.
14. Out of reach. Ops cannot change tempo or meter, and a bar in 7/8 has 14 cells at grid=16. Say what you did instead: "half time feel at the same bpm".
15. The file. Never overwrite his original. One new version per request, so every step can be undone.

After applying, `show` again and check: lock not lower, feel label as intended, `# fills:` still lists the fills you kept.

## 4. The words

| word | meaning in this style | default target with none named | recipe | detail |
|---|---|---|---|---|
| heavier | more weight, not more notes: lower drums, fewer and bigger hits, a harsher cymbal, kick under the hands, a slower feel | the keeper and levels of the section. On fills: the fill recipe | Fills: fills 9 Heavier (block 1). Section: keeper one rung up hh, hh_open, ridden crash, china (`remap SEL lanes=42 to=hh_open`), `delete SEL lanes=38 v=1-34`, `vel SEL lanes=kick,38 v=100-127 min=120`. Asked again: `half` feel. Never a finer grid, never onto the ride | fills 8, 9. grooves 4. feel 7 |
| lighter | less weight: softer and higher, same placement | the hand layer of the section | Fills: fills 9 Lighter. Section: feel 10 "softer" row (keeper one rung down, `vel SEL lanes=hat scale=0.8 max=96`, ghosts scaled 0.8, clean part: backbeat to rim). Kick placement stays | fills 9. feel 10 |
| busier | more notes per beat in the hands. Not louder, not lower | the fills of the scope. A section named with no fills meant: its hand layer | Fills: fills 9 Busier (fill the empty cells, then grid=24 or a 32nd burst, tempo cap in fills 3). Groove: 2-3 ghosts per bar in a bar block (feel 9), keeper rate one step up (quarters to eighths, eighths to two handed sixteenths `8676`). Kick: only on `# riff` onsets, or a burst before a landing (grooves 6) | fills 8, 9. feel 4, 9 |
| simpler | fewer notes, hands first. The kick is the riff and stays | the hand layer and the fills of the scope | Fills: fills 9 Simpler, or one ladder level down. Groove: ghosts out (`delete SEL lanes=38 v=1-62`, fill bars left out), keeper rate one step down (mask idiom, block 5), openings closed (`remap SEL lanes=46 to=hh`). "Simpler kick": only the kicks on `# riff` x cells, first cell of each fast group | fills 9. song 7 |
| more alive | what a drummer varies without changing the part: velocity shape, articulation, small timing, a lift into the fill | the keeper lane of the scope. Kick and backbeat untouched | feel 10 complete script: shape `8-6-`, backbeat lean, openings on the "and" of 4, quieter repeat, lift, `humanize`. Two handed sixteenths or feel half: block 2. China or crash keeper: the cymbals column of feel 10 | feel 2, 3, 5, 6, 10 |
| less robotic | the same notes with a human spread. Nothing added, nothing removed | every lane with sd near 0, whole song when no scope | feel 10 "less robotic" row: `accent SEL lanes=42 grid=16 pattern=8-6- mix=0.6`, then `humanize` per lane: hats vel=7 time=4, ghosts vel=6 time=5, cymbals vel=5 time=2, kick and backbeat vel=3 with no `time=`. A kick sd of 0-4 is correct, not a flaw | feel 2, 8, 10. grooves 10 |
| tighter | controlled and exact: closed sounds, narrow spread, kick with the guitar, on the grid | the hands of the scope, plus the kick row where a riff section shows lock under 85% | feel 10 "tighter" row (`remap SEL lanes=46 to=hh`, `vel SEL lanes=42 scale=0.5 add=48`, quiet ghosts out, `vel SEL lanes=kick min=120`). Lock repair: "lock the kick". Notes off the grid: delete and rewrite the rows (feel 8). No `humanize time=` | feel 8, 10. grooves 1 |
| looser | more slosh and sway in the hands. The kick does not loosen (unconfirmed) | hats, ghosts and backbeat placement of the scope | more openings (`remap bars=2,4,6,8 beats=4.5-4.75 lanes=42 to=hh_open`), spread at the top of the feel 8 table (`humanize SEL lanes=hat,ride vel=8 time=6`, `humanize SEL lanes=38 v=1-62 vel=8 time=9`), backbeat laid back (`shift SEL lanes=38 v=100-127 ticks=6`) | feel 5, 8 |
| groovier | pocket: a backbeat that sits back, ghosts that lead into kicks, hat openings, one bar in four that answers | hat or ride sections of the scope. Under china or crash only the laid back backbeat | feel 10 "groovier" row: opening on the "and" of 4 every 2nd bar, ghosts on cells 7, 9, 15 at 30-45, `shift SEL lanes=38 v=100-127 ticks=6`. A linear bar at a phrase end (grooves P3 bar 2). The kick never shifts | feel 9, 10. grooves 5 |
| more aggressive | harder, harsher, pushing forward | the keeper and levels of the section | feel 10 "more aggressive" row: keeper one rung up, ghosts out or 45-58, `vel SEL lanes=kick,38 v=100-127 min=124` then `humanize SEL lanes=kick,38 v=100-127 vel=3`, china + crash1 stacked on phrase starts. Push: `shift SEL lanes=38 v=100-127 ticks=-6`. Section is `half` and he wants drive: `normal` | feel 7, 10. song 5 |
| more space | notes come out, they are not turned down. Rests are part of the riff | the hand layer, then the phrase ends | keeper rate one step down, ghosts thinned and capped at 34, no pickups before the last bar of the phrase, an eighth of air where the phrase turns (block 5). Kick: delete only kicks on cells with no `# riff` onset. More still: `half` feel | song 10 "breathe". song 5 |
| bigger | the section stands taller than its neighbours: wider cymbal, plainer and louder hands, a smaller bar before it | the chorus. On fills: longer and lower (fills 9 Longer, then Heavier steps 1-3) | song 10 "chorus bigger": keeper to crash riding (`remap SEL lanes=hh,hh_open to=crash1`, `accent SEL lanes=crash* grid=16 pattern=8-7-`), ghosts out, backbeat and kick floor 120, crash + kick at 127 on phrase starts, a gap or drop in the bar before. Last chorus only: kick/bar 16 | song 5, 6, 10. grooves P5 |
| punchier | more contrast between the accents and everything else, not more level | backbeat, kick and accent crashes of the scope | feel 10 "punchier" row: `vel SEL lanes=kick,38 v=100-127 min=120`, `vel SEL lanes=38 v=1-62 max=40`, hats `pattern=8-5-`, the hat blanked under each crash, accent crashes 120-124 each with a kick | feel 7, 10 |
| more dynamic | a wider range over time: quiet repeats, ramps into fills, crashes ranked by importance, sections at different levels | hands and fills of the scope. Kick and backbeat stay in digits 8-9 | feel 10 "more dynamic" row: hats `pattern=8-5-`, `vel bars=5-6 lanes=hat scale=0.9`, `ramp` over the 2 beats before each fill, `vel SEL lanes=crash* max=115` then phrase starts `set=124`, `ramp SEL fills lanes=tom,38 from=95 to=125`. Song level: lower the section before the peak | feel 6, 10. song 5 |
| build up | density and velocity rise into a section start | the last bar before the named section (2 bars if he says long) | keeper out, snare (plus floor tom) hits per beat go 1, 2, 4, kick quarters then eighths, one `ramp` to 127 from 60 (one bar) or 50 (two bars), last eighth empty before a breakdown, landing at 127 | song 6, 10. fills 4 figure 6 |
| drop | "a drop", "drop out": the band falls away before a section. "The drop": the breakdown or the heaviest entry (song 9) | "add a drop": the bar before the named section, else before the last chorus | crash1 + kick stab on cell 0 left ringing, silence up to beat 4.5, 1-3 pickup hits on cells 13-15, landing at 127. Variants: the whole bar empty, or 2 bars of kick only. "Make the drop hit harder": song 10 "the breakdown should hit harder" | song 6, 10 |
| half time | a feel, not a tempo: one snare per bar on beat 3, felt tempo halves, the keeper usually goes to quarters | the named section, else the bars last discussed | snare row of the first bar rewritten with one 9 on cell 8, then `copy from=N to=A-B lanes=snare` with fill bars left out of `to=` (the ghosts go with it). Keeper to quarters as in block 4. Kick row untouched | song 5 lever 3. grooves 3 |
| double time | a feel, not a tempo: the snare comes twice as often. One step: `half` to `normal` (cells 4, 12), `normal` to `double` (cells 2, 6, 10, 14) | the named section. 2-4 bars when he calls it a lift | snare row of one bar, then `copy ... lanes=snare`. With a riff locked kick only the snare moves. In a free section the kick goes to cells 0, 4, 8, 12 (grooves P9 bar 1). Ops cannot change bpm: say so if he means tempo | song 5 lever 3. grooves 3 |
| "follow the guitar" | the drums take the riff's rhythm: feet on every guitar hit, cymbal accents on the riff accents, fill hits on riff onsets. Keeper and backbeat stay straight | kick row and accents of the scope | Kick: as "lock the kick". Accents: crash or china + kick at 9 on a riff onset after a rest of 2+ cells, on a chord change or on a push (song 7). Fills: hits moved onto `# riff` x cells (fills 9 Heavier step 5). Hands joining the riff: grooves P4 | grooves 1, 2. song 7. feel 7 |
| "lock the kick" | kick row = the `# riff` x cells and nothing else, on the grid | the named section, else every riff section with lock under 85% | bar blocks: `x` on each riff onset with no kick, `-` on each kick with no riff onset (block 3). Left alone: fills, carpets (kick/bar 14-16), onsets that carry a snare or tom, the inner cells of riff runs faster than the feet. Polymeter: every bar by hand. No riff track in the file: say so and offer `--riff N` | grooves 1. song 7 |
| "more like Meshuggah" | half time polymeter: china, crash or sloshy open hat on quarters, one snare on beat 3, kick only on the guitar hits, near flat loud velocities, no stand alone fills | the hand layer of the scope. The kick row gets lock repair at most | block 4. Then: fills become unison hits on riff onsets (fills 3, fills 4 figure 7), ghosts out or 40-58, hh_pedal quarters where one foot can play the kick row (grooves 2). Never `copy` one kick bar over the cycle | grooves 2, 8, P1, P2. fills 3. song 8 |
| "more like Periphery" | the other pole of the style: hat, ride or stack keeper with shaped accents, ghost notes, linear bars, thirty-second kick bursts, hand and foot fills, crash riding in the chorus (working reading, unconfirmed) | hand layer and fills of the scope | Verse: ghost groove (grooves P3) or two handed sixteenths (grooves P10), a linear bar at phrase ends. Kick: riff onsets plus a burst before landings (grooves P8). Fills: quads and linear sextuplets (fills 4 figures 2, 3, ladder L4). Chorus: crash riding or ride_bell. Splash 55 stands in for the stack | grooves 4, 5, 6. fills 4, 7. feel 3, 9 |

## 5. The targets

| target | what can move | what stays |
|---|---|---|
| fills | length, density, which drums, velocity shape, kick under the hands, flams, size of the landing (fills 7, 9) | the tail and its landing, the phrase slot, the silence of a stop |
| hats | velocity shape, open, closed and foot, rate, timing spread (feel 3 to 6) | no hat on a crash cell, on the snare cell of two handed sixteenths, or inside a two hand fill |
| cymbals | which cymbal keeps time, its rate, crash level by importance, crash1 and crash2 alternation, stacks on phrase starts (feel 7, grooves 4) | one keeper per section, accents only on riff onsets with a kick, the landing crashes |
| kick | placement on riff onsets, the 112-127 band, run shapes with a weaker foot, carpets and bursts (grooves 1, 6) | lock, grid timing, the rests of the riff |
| snare | the feel (which cells), backbeat level inside digits 8-9, flams, a constant early or late shift (feel 8, grooves 3) | the backbeat cells inside a section, two velocity zones in a groove |
| ghost notes | count (2-5 per bar), cells, level 25-50 (40-58 under china or crash), spread (feel 9, grooves 5) | under 60, never on a backbeat cell, never three in a row, best on cells with no kick |
| toms | which drums (higher or lower), run shape, slams, the weak hand (fills 4, 5) | two hands are busy: no keeper under a tom run. A tom groove is timekeeping, not a fill |
| a section | keeper, feel, density, level against its neighbours, the way in and out (song 2, 5, 6) | its length, its kick and riff relation, what its returns share |
| the whole song | the arc: which section peaks, contrast between neighbours, fill sizes growing toward section ends (song 5, fills 3) | every rule of section 3. Work section by section |

## 6. Worked answers

Each block is the whole script for the request above it. Its first comment is the one line you say back to him, the second names the input the script was written for: on a real song the bar numbers and the copied rows come from `show`. Two idioms: `x` writes a new note at the lane's typical velocity, so added kicks match the old ones. Mask: to delete notes by cell position, mark them with `accent` (digit 1 on the cells to drop, `-` elsewhere), then `delete ... v=1-20`.

"make my fills heavier"

```vd
# said back: heavier is weight, not notes (fills 8). lower drums, kick under every hit, 120 and up, two cymbal landing, on every confirmed fill
# input: 8 bars, keeper china on quarters, feel half, 140 bpm. header fills 4:3-5 and 8:3-5, both confirmed: tom runs on 16ths (snare, tom1, tom3, tom5), kick on the beats
# 1 kick under every hand cell of both fills. beats 1 and 2 are copied from show, so those kicks stay untouched
bar 4 grid=16
kick 36    |9-9- --9- 9999 9999|
bar 8 grid=16
kick 36    |9-9- --9- 9999 9999|
# 2 every drum one step lower, lowest lane first so no note is remapped twice (tom6 only if the kit has it in the lanes header)
remap fills lanes=tom5 to=tom6
remap fills lanes=tom3 to=tom5
remap fills lanes=tom1 to=tom4
# 3 no ghosts or drags, hands and feet at 120 or more
delete fills lanes=snare,tom v=1-62
vel fills lanes=snare,tom,kick min=120
# 4 landing of the bar 4 fill: crash1 added over the china that is already on beat 1 of bar 5, all three at 127
bar 5 grid=16
crash1 49  |9--- ---- ---- ----|
vel bars=5 beats=1-1.25 lanes=crash1,china,kick set=127
# the bar 8 fill lands on bar 9: the same two lines there on a longer song
```

"make the hi hat more alive"

```vd
# said back: the hat keeps time in sixteenths, two handed at this tempo, so it gets the two handed shape, openings, a quieter repeat and a lift. kick and snare untouched
# eighth note hats in feel normal: use the script in feel 10 instead
# input: bars 1-8, keeper hh, feel half (snare on beat 3), 140 bpm. closed hat 42 on all 16 cells at one velocity. fill at 8:3-5 with the kick on the beats
# 1 the left foot keeps time under the fill
bar 8 grid=16
hh_pedal 44 |---- ---- 6--- 6---|
# 2 the right hand leaves for the backbeat, so no hat on beat 3. no stick hats inside the fill
delete bars=1-8 beats=3-3.25 lanes=42
delete bars=8 beats=3-5 lanes=42,46
# 3 opening on the "and" of 4 in bars 2 and 6. its "a" goes so it rings an eighth, the hat on the next beat 1 closes it
remap bars=2,6 beats=4.5-4.75 lanes=42 to=hh_open
delete bars=2,6 beats=4.75-5 lanes=42
# 4 shape: right hand 112 on the beat and 98 on the "and", left hand 84 on "e" and "a"
accent bars=1-8 lanes=42 grid=16 pattern=8676
vel bars=2,6 lanes=46 set=104
# 5 phrase starts marked, bar 4 answers on the "and" of 3
vel bars=1,5 beats=1-1.25 lanes=42 add=6
vel bars=4 beats=3.5-3.75 lanes=42 add=10
# 6 the repeat starts 8 percent down, bar 7 is back at full level
vel bars=5-6 lanes=hat scale=0.92
# 7 lift: the hats of bar 8 rise into the fill
ramp bars=8 beats=1-3 lanes=42 from=90 to=118
# 8 spread last: plus or minus 6 velocity, plus or minus 4 ticks
humanize bars=1-8 lanes=hat vel=6 time=4 seed=7
```

"lock the kick to the guitar in the verse"

```vd
# said back: kick on every guitar hit and nowhere else in bars 1-3, lock goes from about 79% to 96%. the fill in bar 4 is left alone
# input: verse = bars 1-4, keeper hh, feel normal, lock 79%. show printed "bar 3 = bar 1". bar 4: beats 1-2 already locked, beats 3-5 are a fill
# bar 1 before: kick |9--9 9-9- 9--- 9-9-|  riff onsets with no kick on cells 2 and 11, a kick with no riff onset on cell 4
bar 1 grid=16
# riff     |x-xx --x- x--x x-x-|
kick 36    |9-x9 --9- 9--x 9-9-|
# bar 2 before: kick |9--9 --9- --9- 9-9-|  riff onset with no kick on cell 9, a kick with no riff onset on cell 14
bar 2 grid=16
# riff     |x--x --x- -xx- x---|
kick 36    |9--9 --9- -x9- 9---|
# bar 3 is the same bar as bar 1 and the riff repeats, so it takes the same kick row. not polymeter, so copy is safe here
copy from=1 to=3 lanes=kick
# no vel, no humanize: old kicks keep their velocity and timing, new ones sit on the grid at the lane's typical velocity
```

"more like Meshuggah"

```vd
# said back: the hands go to the Meshuggah model, china on quarters and one snare on beat 3. the kick already plays only the guitar hits, so it stays as it is
# input: bars 1-8, keeper hh eighths (42, a few 46), feel normal with ghosts, lock 90%, kick row different in every bar, crash1 + kick on bar 1 beat 1, no fills
# 1 snare: one backbeat on beat 3. copy replaces the whole snare lane of bars 2-8, so the ghosts go with it
bar 1 grid=16
snare 38   |---- ---- 9--- ----|
copy from=1 to=2-8 lanes=snare
# 2 keeper: hats become china, then eighths become quarters
remap bars=1-8 lanes=42,46 to=china
delete bars=1-8 beats=1.5-2 lanes=china
delete bars=1-8 beats=2.5-3 lanes=china
delete bars=1-8 beats=3.5-4 lanes=china
delete bars=1-8 beats=4.5-5 lanes=china
# 3 loud and near flat, never one value: china 123 on beat 1 and 108 after, backbeats 124 to 127
accent bars=1-8 lanes=china grid=16 pattern=9---8---8---8---
vel bars=1-8 lanes=china add=-4
humanize bars=1-8 lanes=china,38 vel=3 seed=4
# the kick row is not touched and never copied: its cycle crosses the bar lines
```

"the verse is too busy, give it more space"

```vd
# said back: space comes from the hands. hats to eighths, ghosts only in the second half of the bar and quiet, pickups out, an eighth of air where the phrase turns. the kick is the riff and stays
# input: verse = bars 1-8, keeper hh two handed sixteenths shaped 8676, feel normal, 3-4 ghosts per bar, a tom hit on the last sixteenth of bars 2 and 6, fill at 8:3-5, lock 88%
# 1 hats to eighths with the mask idiom: digit 1 on the "e" and "a" cells, then delete what is marked. beats 2 and 4 keep no hat, as before
accent bars=1-8 lanes=42 grid=16 pattern=-1-1
delete bars=1-8 lanes=42 v=1-20
# 2 ghosts only in beats 3 and 4, capped at 34. bar 8 holds the fill and stays out
delete bars=1-7 beats=1-3 lanes=38 v=1-62
vel bars=1-7 lanes=38 v=1-62 max=34
# 3 pickups inside the phrase go, the fill at the end of bar 8 stays
delete bars=2,6 beats=4.75-5 lanes=tom
# 4 an eighth of air where the phrase turns: the last hat of bar 4
delete bars=4 beats=4.5-5 lanes=hat
```
