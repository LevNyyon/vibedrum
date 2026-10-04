# Vocabulary: the request playbook

What a word means in modern metal and djent, what to do without asking, and where the detail lives. Workflow: resolve the scope (section 1), look up the word (section 4) and the target (section 5), settle doubt with section 2, check section 3 before you apply.

Pointers: "grooves 4" = grooves.md section 4, "fills" = fills.md, "feel" = dynamics-and-feel.md, "song" = song-structure.md, `EP n` = rule n of knowledge/editing-principles.md. Every row and worked answer here obeys the EP rules, and where a line seems to differ the EP rule wins. Cells are grid=16 indexes 0-15 (beat 1 = cell 0, beat 3 = cell 8). `SEL` = the resolved selector, for example `bars=9-16`. A written digit is exact (8 = 112), a shown digit is a band 14 wide (9 = 119-127): read levels with `show --vel`. Ticks and ms come from the file's tempo and ppq, not from a table: ticks = ms x bpm x ppq / 60000, an eighth = ppq / 2 ticks = 30000 / bpm ms (feel 8, song 6). `T` = 5 ms in ticks: 5 at 130 bpm, 6 at 140, at 480 ppq. "unconfirmed" = working default of this pack, no source found.

## 1. Scope: what the words select

| he says | selector | watch for |
|---|---|---|
| fills, rolls, "my fills" | one group of ops per fill or per rank group (`bars=4,12 beats=4-5`), rank from fills 3. The bulk `fills` selector only for a uniform nudge (one level scale, deleting ghosts), and only once every span in `# fills:` is confirmed and none is missing (fills 2) | the header misses kick only fills, stops, stabs and short pickups, and wrongly flags tom grooves, ghost clusters and bars with a new blast or double time burst. A fill with a plain keeper hit after it, or in the last bar of the file, is still a fill |
| hats, hi hat | `lanes=42` closed, `lanes=46` open, `lanes=44` the foot. `lanes=hat` takes all three at once: name the pitch (EP 14) | a hat request covers the bars where 42 keeps time. A section kept by china or crash is mentioned, not edited. Only a song with no hat at all turns "the hat" into the keeper cymbal (feel 10) |
| cymbals | `lanes=cym` (crash, china, splash) plus `lanes=ride`. One voice: its pitch (`lanes=49`, `lanes=52`) | in a hat section "the cymbals" are the crashes and accents, not the hat |
| kick, feet, double bass | `lanes=36` | lock 85% or more: the riff owns the row, change velocities only (grooves 1). No riff track: every groove kick counts as locked |
| snare | backbeats `lanes=38 v=100-127`. `lanes=snare` also matches rim 37, snare2 40, ghosts and fill notes | ghosts and fill notes are not "the snare" unless he names them |
| ghost notes | `lanes=38 v=1-62`, with fill bars left out of `bars=` | 60 is a wall (feel 9, grooves 3): after any lift or spread clamp with `max=58` |
| toms | `lanes=tom`, one drum by pitch (`lanes=43`) | toms that repeat bar after bar are a tom groove, not fills (fills 2). Only tom lanes with notes in `# lanes` |
| a named section | `bars=A-B` of every occurrence | the mapping rules below |
| the whole song | drop `bars=` only when one recipe fits every section. Otherwise one group of ops per section, with that section's values | sections that return get the same edit |

- Bar numbers he gives win over everything else.
- "My fills", "the fills": every confirmed fill of the song. "The fill", "that fill": the one inside the bars last shown, played or edited, else the last fill before the section just discussed.
- "The chorus", "the verse": every occurrence. "First", "second", "last" pick one. "Into X", "before X", "the transition": the last bar before X (two bars if he says long) plus beat 1 of X. "The end of X": its last bar.
- "Here", "this part", "that riff": the bars of the last `show --bars`, `play --bars` or edit in this conversation. No such context: ask (section 2).
- "The intro", "the ending": first and last section. "The heavy part", "the quiet part", "the fast part", "the Meshuggah part": the wording column of song 9.
- A lane with no scope ("the hats"): every section where that lane keeps time, and no other section. A word with no target and no scope ("heavier"): the bars last discussed, else the whole song, on the word's default target (section 4).
- Scope never grows on its own (EP 5). A hat request leaves kick, snare and fills alone. A fill request leaves the groove bars alone: a landing that is there keeps its level, a missing one is mentioned, and adding it is a rung of its own (fills 9 Heavier rung 4), reported.
- A section request may also touch the bar before the section (a gap, a build, the fill into it) and cell 0 after it, as setup and landing. Each such change gets its own line in the report (song 10). In every other section the keeper, the backbeat and the kick row stay.

Cases the file decides, not the request (EP 2, 15 to 19). Read `# lanes` and the header before choosing a rung:

- Ceiling: a lane at min = max = 127 (sd 0) cannot be raised. `min=` and `set=127` do nothing there and "louder" is not a true report. The lever is contrast, by word: "hit harder" takes song 10 rung 3, "heavier", "more aggressive" and "punchier" on a china or crash keeper take the grooves 4 ceiling case, fills at the ceiling take fills 9 Heavier rung 1 (the body comes down, the top stands out). Kick and backbeat at 127 are never the lever (grooves 1, 3).
- No riff track (no `# riff:` line in the header): no riff row, no lock column. Skip every step that names the riff or lock, treat every groove kick as locked, say so, and offer `--riff N` when the file has a pitched track.
- A fill in the last bar of the file: confirmed, rank 2, and it has no landing bar. Leave the landing out and say so (fills 6).
- A fill with a plain keeper hit on the next beat 1: confirmed, its landing is missing (fills 2). Hat, feel and section requests mention it. A fill request may add it as its own rung: one crash a digit under the section's entrance, reported.
- A kit with one or two toms: use only tom lanes with notes in `# lanes`. A fill keeps its number of drums and its descent. "Lower" = its last note on the low drum, never a whole lane remapped (fills 2, fills 9 rung 2).
- A recipe names a lane the kit has no notes on: the nearest lane with notes, same number of voices (EP 18). hh_open and hh_pedal count as the hat he has.
- Bars 1 to 8 in a recipe are a pattern: map each bar by its role and look at what the mapped bar holds. A fill bar inside a range keeps its fill.

Section names to the engine's letters:

1. `# markers:` in the header names sections directly. Markers win.
2. No markers: a letter means one keeper plus one feel, not a song function (song 1). Give each letter a function with song 2 and song 9, then the position prior: intro, verse, pre chorus, chorus, verse, pre chorus, chorus, bridge or breakdown, chorus, outro.
3. Quick tells. Verse: hh or ride keeper, ghosts, lock 70%+. Chorus: the returning letter with the highest vel and the plainest snare row. Breakdown: china or crash on quarters, feel half, lock 90%+, rests in the kick row. Clean part: every lane at digits 3-5. No riff track: lock cannot be read, match the other tells and say so (song 9).
4. A function can be a slice of a letter (a 1 or 2 bar build, drop or pre chorus never gets its own letter), and one function can span two letters. Always end at `bars=A-B`.
5. The same letter at two places is the same pattern returning: "the second verse" is the second range of the verse's letter.
6. Say the mapping in the report: "chorus = B, bars 9-16 and 25-32".

## 2. Ambiguity: default or ask

Act on the default and state it in one line when:

- the word has a default target in section 4 and the scope resolves with section 1;
- the only open point is how much: take the first one or two rungs the file has room for (EP 1), and name the next rung in the report so he can say "more";
- two readings differ in size, not in kind;
- the edit stays inside hands, velocities or one fill. Every version is a new file, so a wrong guess costs him one undo.

Ask exactly one question, two concrete options, the default first, when:

- "here" or "this part" has no context, or a section name fits two sections that need different edits ("the heavy part" with both a breakdown and a blast section);
- the request can only be met by breaking a rule of section 3: thinning or moving a riff locked kick, moving the backbeat without a feel word, removing a landing crash, cutting the tail of a fill;
- the word has two kinds of meaning and the grid does not decide: "drop" as a gap or as the breakdown, "tighter" when the hands are already plain and lock is 85%+ (levels, timing or kick placement);
- "more like" names a band this pack does not cover: ask for the one trait he wants (keeper, feel, kick style or fills).

Never ask what the grid answers: where the fills are, which bars the chorus is, the tempo, whether a riff track exists. Never ask a second question. After the answer, act.

The one line holds the interpretation, the scope and what stayed, and promises only what the script does (EP 21): "Heavier fills by weight, not notes: a leading hand, a rise in the long fills, the top hit on the floor tom, the pickups kept under the backbeat, on the fills in bars 4, 8, 12 and 16. No notes added, groove bars untouched."

## 3. Do no harm

knowledge/editing-principles.md holds the general rules: one step, room, rank, landing hierarchy, scope, contour, never flatten, shape not noise, walls, limbs, order, sizes, file cases, check, report. They are not repeated here. What follows is specific to this style, and no word overrides it:

1. Kick and riff lock. Kicks on `# riff` x cells are never deleted, moved, shifted or given `humanize time=`. `lock` after the edit is not lower than before. New kicks go on riff onsets, into a carpet he asked for, or under the leading hand of a fill when he asks for heavier fills a second time (fills 9 rung 3). No kicks into the rests of a breakdown riff. No riff track: every groove kick counts as locked (grooves 1).
2. Polymeter. Where the kick row differs in every bar under identical hand rows, never `copy` one bar of kick over the others (whole blocks only). Keeper spacing and snare cell are the 4/4 anchor: constant inside a section. A keeper is never thinned in half a section, and never for "harder" or "heavier" (grooves 2, song 5 lever 2).
3. The backbeat. It stays on its cells (4 and 12, or 8) unless he used a feel word, stays in digits 8-9, gets no random timing beyond 2 ticks, and no ghost op reaches it: bound ghost ops with `v=1-62`.
4. Landings. Beat 1 after a fill keeps the crash it has (or the section's keeper hit) and its kick, at their level. No crash there: mention it. Adding one is fills 9 Heavier rung 4, on a fill request only. A fill in the last bar of the file has no landing: say so (fills 6). Shorten a fill from the front, never cut its tail: delete its first eighth, then `shift` the rest by minus ppq / 2 ticks (song 6). A fill you add gets a landing by rank (fills 6). A push does not remove the crash on the next beat 1.
5. Phrase and section starts. Crash + kick on cell 0 stays, and stays the biggest hit of its section: a two cymbal stack only on a section start, one crash inside a section, never the next section's keeper before its first bar (EP 4, fills 6). The bar after a fill is the plain groove from beat 2 at the latest.
6. Untouched notes. Copy rows from `show` and change only the cells you mean: a kept character keeps its exact velocity and micro timing. Never rewrite a bar at a coarser grid than `show` printed. At a grid that does not divide the old one (triplets over sixteenths) `delete` the rewritten lanes first, or the old notes keep their ticks (grooves 7). A row of only `-` clears the lane in that bar. `copy` replaces the destination lanes: keep fill bars out of `to=`.
7. Selector hygiene. Every op carries `lanes=` and, unless the whole song is meant, `bars=` or `fills`. One voice = its pitch plus a `v=` band (EP 14): `lanes=snare` includes rim, ghosts and fill notes, `lanes=hat` the open hat and the foot, `lanes=ride` the bell.
8. Limbs (EP 10). At most two hand lanes on a cell, plus kick, plus hh_pedal. No keeper while both hands are on drums. No closed hat on a crash or china cell. No hh_pedal on a cell with a stick hat or in a beat with a kick run. Look one cell back: before a two cymbal stack the last sixteenth belongs to the kick, not to a floor tom, from 120 bpm up (fills 6).
9. One keeper per section. It changes only on a section boundary, marked with one crash1 + kick on cell 0, and by one rung per request (grooves 4).
10. Silence. Gaps before a drop, stops and the holes of a breakdown riff stay empty. "Busier" and "heavier" add at most one pickup hit there.
11. Fill inventory and rank. At most one fill per 4 bars, no two identical in a section, none added inside a lock 85%+ section with a quarter note china or crash keeper unless he asks (there: unison hits on riff onsets at the section end). After any edit the ranks hold (fills 3): pickup under phrase end under section change, in length, top velocity and landing. A fill keeps its number of drums and its descent (EP 6).
12. Velocity bounds. Ghosts under 60 (`show` reads 60 or more as a backbeat, which can flip the feel label). Closed hat: shoulder 100 and up, tip 99 and down (feel 3). Fill body 118 and under, 127 on one or two notes of a fill (fills 5). Keeper cymbals 105-120, 127 on section and phrase starts only (grooves 4). Kick on the riff and backbeats live in digits 8-9: never spread them wider than `humanize vel=3`. No hand lane the edit touched ends flat at one value, and nothing new sits flat at 127.
13. Order and once only (EP 11). Notes (bar blocks, `copy`, `remap`, `delete`), level (the base `accent` over a whole part, `vel`), `humanize`, gestures (`accent` on single bars or cells, `vel add=`, `ramp scale=`, `set=` on one note), wall clamps, `shift` last. A base `accent` after `humanize` erases the spread, a gesture before it is blurred. `humanize` and `shift` stack: one `vel=` run and one `time=` run per lane per section, and redo from the version before. A bar block for a `copy` destination goes after that `copy`.
14. Out of reach. Ops cannot change tempo or meter, and a bar in 7/8 has 14 cells at grid=16. Say what you did instead: "half time feel at the same bpm". `shift` has no bar line guard: never move a cell 0 note earlier (`beats=1.25-5`).
15. The file. Never overwrite his original. One new version per request, so every step can be undone.

After applying, read `show OUT --vel` on the changed bars (EP 20). The check covers the bars and lanes the edit touched: every gesture of the said back line is in the numbers, lock is not lower (no riff track: there is no lock column, skip and say so), the feel label is as intended, `# fills:` still lists the fills you kept (new ghosts, a blast or a double time burst add candidates: recheck before any `fills` op), and a hat rung shows in `# lanes` (`# sections` prints `hh` for closed and open alike). A flaw that was in the file before and lies outside the request (a lane flat at 127, a missing landing) is named in one line, not fixed (grooves 10). Report in two or three lines: what changed, where, notes added or removed with their count, anything changed outside the named scope, the next rung on offer.

## 4. The words

Every recipe cell is a ladder: levers in order. Take the first one or two the file has room for, stop, and name the next one as an offer (EP 1). No room = already there, nothing to select, or the lane is at its ceiling (section 1): skip that lever, never force it, never report it as done. "block N" = the Nth worked answer of section 6. `N` in `add=N` = 127 minus the loudest note of that voice in the section.

| word | meaning in this style | default target with none named | recipe | detail |
|---|---|---|---|---|
| heavier | more weight, not more notes and not maximum level: the weight on the low drum, a harsher cymbal, bigger single hits. A slower feel only on his word | the keeper of the section. On fills: the fill recipe | Fills: fills 9 Heavier, rungs 1 and 2 by rank (block 1). Asked again: rung 3 (a kick under the leading hand, counted as notes added), then rung 4 (a missing landing). Section: one rung of the grooves 4 keeper ladder (hh, hh_open, ridden crash, china), by pitch, in the named section, never onto the keeper of the next section or a cymbal lane with no notes, shaped as grooves 4 says. A china or crash keeper flat at 127: the grooves 4 ceiling case. Asked again: quiet ghosts out (`delete SEL lanes=38 v=1-34`, counted), then level only with headroom (`vel SEL lanes=36 add=N`). `half` feel needs a feel word or a yes. Never a finer grid, never onto the ride, never a `min=` floor on hands or keeper | fills 8, 9. grooves 4. song 5 levers 1, 3, 8 |
| harder, hit harder, more impact | contrast and weight on the hits that are there. Not more notes and, at the ceiling, not more level | the named section: its hands, its keeper and its own fills. Fills alone: "heavier" | song 10 "the breakdown should hit harder", the first two rungs with room: (1) plain hands: hand hats, ride and ghosts out under a china or crash keeper; (2) level only with headroom, `add=N`, never a `min=` floor; (3) keeper contrast when it is flat or all inside digit 9: down 20, beats 1 and 3 back up 10, phrase starts at 127; (4) its fills lifted by rank, the fill into it included and reported. "More": an eighth of silence before it (song 6). Never thin the keeper, never add kicks in the rests. A section at 127 with plain hands: rungs 3 and 4 | song 10. song 5 lever 8. grooves 1, 3, 4 |
| lighter, softer, calmer | less weight: softer, same placement, the ranks kept | the keeper lane of the section | Fills: fills 9 Lighter rung 1 (`scale=0.85`, shape kept). Section: feel 10 "softer" row, one column. Hat keeper: openings closed (`remap SEL lanes=46 to=hh`), then `vel SEL lanes=42 scale=0.8 max=96`. China or crash keeper: `vel SEL lanes=cym,ride scale=0.85`. "More": ghosts `vel SEL lanes=38 v=1-62 scale=0.8 min=20`, then the keeper one rung down. Said as "calmer": the keeper one rung down is the first step (grooves 4). Clean part only: backbeat to rim. Kick placement stays | fills 9. feel 10. grooves 4 |
| busier | more notes per beat in the hands. Not louder, not lower | the fills of the scope. A section named with no fills meant: its hand layer | Fills: fills 9 Busier, one rung per request (fill the empty cells, then a 32nd burst, then L4 at grid=24, tempo cap in fills 3). Groove: ghosts first, 2 per bar at digit 2 or 3 on cells with no kick, not the same cells in every bar (grooves 5, feel 9). Asked again: keeper rate one step up for the whole section (quarters to eighths, eighths to two handed sixteenths, base `8676`). Kick: only when he asks for double kick (grooves 6). Notes added are counted in the report | fills 8, 9. grooves 5, 6. feel 4, 9 |
| simpler | fewer notes, hands first. The kick is the riff and stays | the hand layer and the fills of the scope | Fills: fills 9 Simpler rung 1, then one ladder level down. Groove, in order: ghosts out (`delete SEL lanes=38 v=1-62`, fill bars left out), openings closed (`remap SEL lanes=46 to=hh`), keeper rate one step down for the whole section (mask idiom, block 5, every bar keeps 2 keeper hits). "Simpler kick": the kicks with no `# riff` onset come out (grooves 1 rung 2). No riff track: ask which kicks. Notes removed are counted | fills 9. song 7. grooves 1 |
| more alive | what a drummer varies on purpose without changing the part: an accent shape, a cell that differs between neighbouring bars, an opening, a lift. Not random spread (EP 8) | the closed hat where it keeps time. Kick, backbeat and fills untouched | feel 10 ladder, default rungs 1 and 2 (block 2): base row `8-6-` on 42, `humanize lanes=42 vel=4`, one lifted "and" per bar that alternates between odd and even bars, openings on the "and" of 4 in the 2nd bar of each 4 bar phrase. "More": rung 3, the lift into the fill that ends the phrase, then rung 4, the quieter repeat (script in feel 6). Two handed sixteenths: base `8676`, the wall line, the sixteenth cells of feel 3. A china or crash keeper, when he names that section: the contrast cure of feel 2 | feel 3, 5, 6, 10 |
| less robotic, more human | the same notes, each flat lane shaped and then spread a little. "Less robotic" adds and removes nothing. "More human" may then take out notes no limb can play | every lane with sd under 3 in the scope, whole song when none, each in its own column of feel 10 | feel 10 "less robotic" row. Hats: rung 1 of the ladder with no note changes, then timing: `humanize SEL lanes=42,46 time=8` at 130 bpm (6-10 ms, feel 8). Ghosts: `humanize SEL lanes=38 v=1-62 vel=5 time=T`, then the wall `vel SEL lanes=38 v=1-62 min=25 max=58`. China or crash keeper: the cure of feel 2. Crash accents `vel=4`. Kick and backbeat `vel=3`, no `time=` on the kick. A kick sd of 0-4 is correct, not a flaw. Fills: the per fill cure of feel 2. "More human": then the limb fixes of that row, each reported as notes removed | feel 2, 8, 10. grooves 10 |
| tighter | controlled and exact: kick with the guitar, narrow spread, closed sounds, on the grid | a riff section with lock under 85%: the kick row. Otherwise, and with no riff track: the hat lane, then ghosts | Kick: "lock the kick" rung 1. Hands, feel 10 "tighter" row. Hats: half the spread inside each articulation, two ops so nothing crosses the wall at 100: `vel SEL lanes=42 v=100-127 scale=0.5 add=56`, then `vel SEL lanes=42 v=1-99 scale=0.5 add=42`. Next: openings closed. Ghosts: `vel SEL lanes=38 v=1-62 scale=0.8`, deleting the quiet ones only as the next lever. Kick level: `vel SEL lanes=kick min=120` only when its min is under 120, at 127 nothing. Notes off the grid: delete and rewrite the rows (feel 8). No `humanize time=` | feel 8, 10. grooves 1 |
| looser | more slosh and sway in the hands. The kick does not loosen (unconfirmed) | hats and ghosts of the scope, then the backbeat placement | (1) openings: rung 2 of the feel 10 ladder. (2) timing spread at the top of the feel 8 range, velocities left alone: `humanize SEL lanes=42,46 time=10` at 130 bpm (10 ms), ghosts `humanize SEL lanes=38 v=1-62 time=8` (8 ms). (3) "More": backbeat laid back, `shift SEL lanes=38 v=100-127 ticks=T`. A flat hat gets rung 1 first. A spread under 5 ms is not reported as a gesture | feel 5, 8, 10. grooves 7 |
| groovier | pocket: hat openings, a backbeat that sits back, ghosts that lead into kicks | hat or ride sections of the scope. Under china or crash only the laid back backbeat | feel 10 "groovier" row: (1) rung 2 of the ladder (openings), a flat part gets rung 1 with it. (2) backbeat 5 ms late: `shift SEL lanes=38 v=100-127 ticks=T`. (3) "More": ghosts, 2 per bar on cells 7, 9, 15 at 30-45, counted as notes added. A linear bar at a phrase end (grooves P3 bar 2) only when he asks. The kick never shifts | feel 9, 10. grooves 5 |
| more aggressive | harder, harsher, pushing forward | the keeper of the section | one rung of the grooves 4 keeper ladder (script there), in the named section, never onto the keeper of the next section. Keeper already china or crash at 127: the grooves 4 ceiling case. "More": ghosts louder inside the wall (`vel SEL lanes=38 v=1-62 add=14 max=58`) or out, then kick and backbeat only with room (`vel SEL lanes=kick,38 v=100-127 min=124`, then `humanize ... vel=3`). A china + crash1 stack only on the section start, never on phrase starts, and only when the song itself opens on a stack or he asks (fills 6). Push: `shift SEL lanes=38 v=100-127 ticks=-T`. `normal` feel for drive: on a feel word | feel 7, 10. grooves 4. song 5 |
| smoother | less contrast between the accents and the rest. The bar differences stay | the hat lane of the scope | feel 10 "smoother" row: `vel SEL lanes=42 v=100-127 scale=0.5 add=50` (112 becomes 106). "More": openings closed, ghosts `scale=0.8` | feel 10 |
| more space, breathe | notes come out of the hands, they are not turned down. Rests are part of the riff, and the kick is the riff | the hand layer, then the phrase ends | song 10 "breathe", the first one or two rungs with room (block 5): (1) ghosts scaled 0.75 and out of beats 1 and 2; (2) keeper one step down, one rate step (mask idiom) or one rung, then its shape; (3) an eighth of air in the last bar of a phrase, never where a fill runs to the bar line; (4) kicks on cells with no `# riff` onset, on his word, never without a riff track. `half` feel only on a feel word | song 10, song 5 |
| bigger | the section stands taller than its neighbours: a wider cymbal first, level only where there is room, a smaller bar before it | the chorus. On fills: fills 9 Longer, then Heavier rungs 1 and 2 | song 10 "chorus bigger", default rung 1: `remap SEL lanes=42,46 to=crash1`, `accent SEL lanes=49 grid=16 pattern=8-7-`, 127 on the first hit of the chorus only. One crash lane for the whole chorus, and not the keeper of the next section. Rung 2 only with headroom: `add=N` on backbeat and kick, ghosts out, no `min=` floor. Rung 3, the bar before it (gap or drop), is setup and reported. Last chorus, on his word: kick/bar 16 | song 5, 6, 10. grooves 4, P5 |
| punchier | more contrast between the accents and everything else, not more level | kick and backbeat when they have room, else the hat tips and ghosts under them | feel 10 "punchier" row. Room (kick or backbeat min under 120): `vel SEL lanes=kick,38 v=100-127 min=120`, then `humanize ... vel=3`. At the ceiling skip that: hat tips one digit down (`vel SEL lanes=42 v=1-99 add=-14 min=60`, a flat hat gets rung 1 first), ghosts `scale=0.8`. China or crash keeper at 127: grooves 4 ceiling case. "More": accent crashes with room to 112-120, per hit, each with a kick, under the section start | feel 7, 10. grooves 4 |
| more dynamic | a wider range over time: a lift into the phrase ending fill, a quieter repeat, crashes ranked, fills graded by slot | the hands of the scope. Kick and backbeat stay in digits 8-9 | feel 10 "more dynamic" row. Hats: a flat part gets ladder rung 1, a shaped part rung 3 (lift, `ramp ... lanes=42 scale=0.95-1.13` plus its two walls), then rung 4 (quieter repeat, `vel ... lanes=42 add=-10`, then `v=95-127 min=100`). Crashes ranked per hit: landings inside the section 10 under its start (`vel bars=N beats=B lanes=49 add=-10`), riff accents 10 lower again. Fills: the per fill cure of feel 2, graded by slot, never one op on `fills`. Lowering the section before the peak is outside the named scope: offer it (song 5) | feel 2, 6, 7, 10. song 5 |
| build up | density and velocity rise into a section start | the last bar before the named section (2 bars if he says long) | keeper out, snare (plus the lowest tom) hits per beat go 1, 2, 4. The digits carry the hand shape, `ramp scale=0.65-1.3` the rise (block in song 6). A bar that already ends in a fill keeps the fill as the top of the build: only the front is written, `ramp scale=0.7-1.13`, last hit 127 (song 10). The kick row stays when lock is 70%+ or there is no riff track. The empty last eighth before a breakdown: only in a plain bar. Landing: the crash + kick already on the next cell 0 | song 6, 10. fills 4 figure 6 |
| drop | "a drop", "drop out": the band falls away before a section. "The drop": the breakdown or the heaviest entry (song 9) | "add a drop": the bar before the named section, else before the last chorus | song 10 "add a drop": one crash1 + kick stab on cell 0, the crash written at 8 and left ringing, silence, then a pickup. The crash + kick already on the next cell 0 stay as they are. A bar that holds a fill keeps the fill whole as the pickup. The hats and kicks that go are counted in the report. On his word: the whole bar empty, or 2 bars of kick only. "Make the drop hit harder": the "harder" row | song 6, 10 |
| half time | a feel, not a tempo: one snare per bar on beat 3, felt tempo halves | the named section, else the bars last discussed | snare row of the first bar rewritten with one backbeat on cell 8, then `copy from=N to=A-B lanes=snare` with fill bars left out of `to=` (the ghosts go with it: say so). Kick row untouched. The keeper keeps its rate. "More": keeper to quarters for the whole section (mask idiom), fill bars keep 2 keeper hits. Half notes only in quarter time or when he asks. A rate change that starts inside a section begins on a phrase start and is marked with one crash (song 5 lever 2) | song 5 levers 2, 3. grooves 2, 3 |
| double time | a feel, not a tempo: the snare comes twice as often. One step: `half` to `normal` (cells 4, 12), `normal` to `double` (cells 2, 6, 10, 14) | the named section. 2-4 bars when he calls it a lift | snare row of one bar, then `copy ... lanes=snare`, fill bars left out. Only the snare moves: the kick row stays when lock is 70%+ or there is no riff track. In a free section, on his word, the kick goes to cells 0, 4, 8, 12 (grooves P9 bar 1). Ops cannot change bpm: say so if he means tempo | song 5 lever 3. grooves 3 |
| "follow the guitar" | the drums take the riff's rhythm: feet on every guitar hit, cymbal accents on the riff accents, fill hits on riff onsets. Keeper and backbeat stay straight | kick row and accents of the scope | needs a riff track: without one say so and offer `--riff N`. The first one or two with room: (1) kick as "lock the kick"; (2) accents: one crash or china + kick, the cymbal at digit 8, on a riff onset after a rest of 2+ cells, on a chord change or on a push (song 7); (3) fills: hits moved onto `# riff` x cells (fills 9 Heavier rung 7); (4) on his word, hands joining the riff: grooves P4 | grooves 1, 2. song 7. feel 7 |
| "lock the kick" | a kick under every `# riff` onset, on the grid. "Only the riff": and nothing else | the named section, else every riff section with lock under 85% | grooves 1 ladder, one rung per request: (1) add: `x` under each isolated riff onset with no kick, in bar blocks copied from `show` (block 3). Default: stop here. (2) "only the riff", or asked again: `-` on each kick with no riff onset, counted in the report. Left alone: fills, carpets (kick/bar 14-16), onsets that carry a snare or tom, the inner cells of riff runs faster than the feet. Polymeter: every bar by hand. No riff track: nothing to lock to, say so and offer `--riff N` | grooves 1. song 7 |
| "more like Meshuggah" | half time polymeter: china, crash or sloshy open hat on quarters, one snare on beat 3, kick only on the guitar hits, near flat loud velocities, no stand alone fills | the hand layer of the scope. The kick row gets lock repair at most | default (block 4): the keeper becomes a quarter note anchor, one rung up the grooves 4 ladder, never the keeper of the next section. "More", one per request: ghosts out or at 40-58; one snare on beat 3 when the section is `normal` (a feel change: on his yes); the next keeper rung; fills as unison hits on riff onsets (fills 3, fills 4 figure 7, needs a riff track). hh_pedal quarters only when he asks for the foot (grooves 2). Never `copy` one kick bar over the cycle | grooves 2, 4, 8, P1, P2. fills 3. song 8 |
| "more like Periphery" | the other pole of the style: hat, ride or stack keeper with shaped accents, ghost notes, linear bars, thirty-second kick bursts, hand and foot fills, crash riding in the chorus (working reading, unconfirmed) | hand layer and fills of the scope | the first one or two with room: (1) hat or ride keeper shaped: feel 10 ladder rungs 1 and 2; (2) ghosts on cells with no kick (grooves 5, P3), counted as notes added. "More", one per request: a linear bar at a phrase end (grooves P3 bar 2); one fill as quads or linear sextuplets (fills 4 figures 2, 3, L4 in fills 7); two handed sixteenths (grooves P10); a kick burst before a landing only when he asks for double kick (grooves 6, P8); chorus: "bigger". China or crash keeper: one rung down first. Splash 55 stands in for the stack | grooves 4, 5, 6. fills 4, 7. feel 3, 9 |

## 5. The targets

| target | what can move | what stays |
|---|---|---|
| fills | level and shape by rank (fills 3, 5), which drum carries the weight, length, density, the kick under the leading hand, flams, the landing by rank (fills 6, 9) | the rank order, the number of drums and the descent, the tail, the phrase slot, the silence of a stop |
| hats | velocity shape, a cell that differs between bars, openings, rate, timing spread (feel 3 to 6). The foot only when he asks | the wall at 100, no hat on a crash cell or inside a two hand fill, the bars kept by another cymbal |
| cymbals | which cymbal keeps time (one rung), its rate, crash level by rank, crash1 and crash2 alternation, a stack on a section start (feel 7, grooves 4) | one keeper per section, accents only on riff onsets with a kick, the landing crashes, the entrance as the biggest hit |
| kick | placement on riff onsets, the 112-127 band, run shapes with a weaker foot, carpets and bursts when he asks (grooves 1, 6) | lock, grid timing, the rests of the riff. At 127 it is never the lever |
| snare | the feel (which cells, on a feel word), backbeat level inside digits 8-9, flams, a constant early or late shift (feel 8, grooves 3) | the backbeat cells inside a section, two velocity zones in a groove |
| ghost notes | count (2-5 per bar), cells, level 25-50 (40-58 under china or crash), spread (feel 9, grooves 5) | under 60, never on a backbeat cell, never three in a row, best on cells with no kick |
| toms | which drum carries the weight, run shape, slams, the weak hand (fills 4, 5, 9) | the drums his kit has, two hands are busy: no keeper under a tom run. A tom groove is timekeeping, not a fill |
| a section | keeper, feel, density, level against its neighbours, the way in and out (song 2, 5, 6, 10) | its length, its kick and riff relation, what its returns share. The neighbours, except the bar before and cell 0 after, reported |
| the whole song | the arc: which section peaks, contrast between neighbours, fill sizes growing toward section ends (song 5, fills 3) | every rule of section 3. Work section by section |

## 6. Worked answers

Each block is the default answer to the request above it: the first one or two rungs, not the whole ladder. Its first comment is the one line you say back to him, the second names the input the script was written for, and the lines under the block say what the numbers must show and what "more" adds. Bars 1 to 8 are a pattern (EP 19). Each answer was adapted to demo/djent-demo.mid (16 bars, 130 bpm, flat levels, two toms, no riff track) and read back with `show --vel`. Two idioms: `x` writes a new note at the lane's own level, so added kicks match the old ones. Mask: to delete notes by cell position, mark them with `accent` (digit 1 on the cells to drop, `-` elsewhere), then `delete ... v=1-20`.

More proved scripts live in the detail documents: "the breakdown should hit harder", "make the chorus bigger", "build into the breakdown", "add a drop" (song 10), heavier fills asked again (fills 9), the hat's "more" (feel 6), one keeper rung and the ceiling case (grooves 4).

"make my fills heavier"

```vd
# said back: heavier fills by weight, not notes: a leading hand, a rise in the long fill, the top hit on the floor tom. the pickup in bar 4 stays under the backbeat, the fill into the new section in bar 8 ends on two full hits. no notes added, groove bars untouched
# input: hat section bars 1-8, bar 9 starts a new section. fills 4:4-5 (snare snare tom2 tom2, rank 1) and 8:3-5 (four snares, tom2 tom2 tom5 tom5, rank 3), every fill note 98. toms in # lanes: tom2 and tom5
# rung 2, notes first: the pickup never reaches the floor tom, so its last note goes there. bar 8 already ends on it
remap bars=4 beats=4.75-5 lanes=48 to=tom5
# rung 1, level by rank: F = 107 / 98 and 122 / 98, then the small spread a flat fill needs
vel bars=4 beats=4-5 lanes=38,tom scale=1.09
vel bars=8 beats=3-5 lanes=38,tom scale=1.25
humanize bars=4 beats=4-5 lanes=38,tom vel=2 seed=4
humanize bars=8 beats=3-5 lanes=38,tom vel=2 seed=4
# lean on both fills (the weak hand about 14 down), the rise only on the long one
accent bars=4 beats=4-5 lanes=38,tom grid=16 pattern=-1 mix=0.15
accent bars=8 beats=3-5 lanes=38,tom grid=16 pattern=-1 mix=0.15
ramp bars=8 beats=3-5 lanes=38,tom scale=0.88-1
# wall at 118, then the top by rank on the floor tom
vel bars=4 beats=4-5 lanes=38,tom max=118
vel bars=8 beats=3-5 lanes=38,tom max=118
vel bars=4 beats=4.75-5 lanes=43 set=117
vel bars=8 beats=4.5-5 lanes=43 set=127
```

In `show --vel`: bar 4 reads 106 91 107 117, bar 8 reads 107 94 112 100 118 103 127 127. On the demo the pickup in bar 12 joins the bar 4 lines (`bars=4,12`, no remap: it already ends on tom5) and the bar 16 fill joins the bar 8 lines as rank 2 with one top note (`beats=4.75-5`): the tops are 117 in bars 4 and 12, one 127 in bar 16 and two in bar 8, 248 notes before and after. To report: bar 5 has no crash after the bar 4 fill, bar 16 ends the file so its fill has no landing, and hats, china and kick are still flat (not asked). "More" (second script of fills 9): rung 3, a kick under the leading hand of the fills that have none, counted, then rung 4, one crash on bar 5 a digit under the bar 1 entrance. Never a kick carpet, a whole tom lane remapped, a `min=` floor or a stack on every landing.

"make the hi hat more alive"

```vd
# said back: the hat keeps its eighths. shoulder on the beat, tip on the "and", one "and" per bar lifted (a different one in odd and even bars), open hat on the "and" of 4 in bars 2 and 6. kick, snare and fills untouched
# input: bars 1-8, keeper hh, eighth hats on 42 at one velocity, fill at 8:3-5. any feel, any tempo
# 1 notes: the openings, 2nd bar of each phrase. the closed hat on the next beat 1 chokes each. a bar whose beat 4 is inside a fill is left out
remap bars=2,6 beats=4.5-4.75 lanes=42 to=hh_open
# 2 level: shoulder 112, tip 84. the first opening 100, the last 110
accent bars=1-8 lanes=42 grid=16 pattern=8-6-
ramp bars=1-8 lanes=46 from=100 to=110
# 3 spread, closed hat only: shoulders 108-116, tips 80-88, nothing near the wall at 100
humanize bars=1-8 lanes=42 vel=4 seed=7
# 4 gestures last, the 2 bar cell: one tip per bar goes to exactly 98
accent bars=1,3,5,7 lanes=42 grid=16 pattern=--------------7-
accent bars=2,4,6,8 lanes=42 grid=16 pattern=----------7-----
```

In `show --vel` (the demo takes the script as it is, bars 9-16 are kept by china and only mentioned): on beat hats 108-116, "and" hats 80-88, the lifted cells 98, openings 100 and 110, every bar differs from the one before in a lifted cell or an opening, `apply` lists `hh` and `hh_open` only. Two handed sixteenths: base `8676`, the wall `vel bars=1-8 lanes=42 v=91-104 max=99` right after `humanize`, the sixteenth cells of feel 3. "More": rung 3, the lift into the bar 8 fill, then rung 4, the quieter repeat (script in feel 6). Never part of this request: the foot under a fill, hats deleted on snare cells, a landing crash, a lean of a few points, kick or snare.

"lock the kick to the guitar in the verse"

```vd
# said back: a kick under each guitar hit that had none in bars 1-3, 5 kicks added. no kick removed or moved, the fill in bar 4 is left alone
# input: verse = bars 1-4, keeper hh, feel normal, lock 79%. show printed "bar 3 = bar 1". bar 4: beats 1-2 already locked, beats 3-5 are a fill
# bar 1 before: kick |9--9 9-9- 9--- 9-9-|  riff onsets with no kick on cells 2 and 11
bar 1 grid=16
# riff     |x-xx --x- x--x x-x-|
kick 36    |9-x9 9-9- 9--x 9-9-|
# bar 2 before: kick |9--9 --9- --9- 9-9-|  riff onset with no kick on cell 9
bar 2 grid=16
# riff     |x--x --x- -xx- x---|
kick 36    |9--9 --9- -x9- 9-9-|
# bar 3 is the same bar as bar 1 and the riff repeats, so it takes the same kick row. not polymeter, so copy is safe here
copy from=1 to=3 lanes=kick
```

No `vel`, no `humanize`: old kicks keep their velocity and timing, new ones sit on the grid at the lane's own level. Check the lock column of the header: higher than before. "More" ("only the riff", or asked again): the kicks with no guitar hit under them come out, cell 4 in bars 1 and 3 and cell 14 in bar 2, counted in the report. The demo has no riff track: nothing to lock to, change nothing, say so and offer `--riff N`.

"more like Meshuggah"

```vd
# said back: toward the Meshuggah model in the hands: the hat becomes a quarter note anchor on the loose hat, about 112 on beats 1 and 3 and 98 on 2 and 4, beat 4 of every second bar pushed up. half of the hat notes go. snare, kick and fills untouched
# input: bars 1-8, keeper hh, eighth hats on 42 at one velocity, kick row different in every bar, crash1 + kick on bar 1 beat 1. bar 9 starts a china section, so china is not an option here
# 1 notes, the anchor: quarters with the mask idiom, then one rung up the keeper ladder, closed hat to loose hat
accent bars=1-8 lanes=42 grid=16 pattern=--1-
delete bars=1-8 lanes=42 v=1-20
remap bars=1-8 lanes=42 to=hh_open
# 2 level: the base row of a quarter anchor, then a spread under half of its 14 point gap
accent bars=1-8 lanes=46 grid=16 pattern=8---7---
humanize bars=1-8 lanes=46 vel=3 seed=4
# 3 gesture last: beat 4 of every second bar goes to exactly 112 and pushes into the next bar. a bar whose fill covers beat 4 has no hat there and stays as it is
accent bars=2,4,6,8 lanes=46 grid=16 pattern=------------8---
```

On the demo (bars 1-8, feel already `half`): 28 loose hats on quarters, 109-115 on beats 1 and 3, 95-100 on 2 and 4, the push at 112 in bars 2 and 6 (bars 4 and 8 have their fill there), 29 hat notes out, `# sections` still prints `hh`. Bars 9-16 already are the model and sit flat at 127: mentioned, not edited. "More", one per request: ghosts out or at 40-58, one snare on beat 3 when the section is `normal` (on his yes), the next keeper rung (ridden crash, then china where no china section follows).

"the verse is too busy, give it more space"

```vd
# said back: space comes out of the hands. the ghosts drop a quarter and stay only in the second half of the bar, the hat goes from sixteenths to eighths. the kick is the riff and stays, and so does the fill in bar 8
# input: verse = bars 1-8, keeper hh two handed sixteenths shaped 8676, feel normal, 3-4 ghosts per bar, fill at 8:3-5, lock 88%
# rung 1 notes: ghosts out of beats 1 and 2. bar 8 holds the fill and stays out of every ghost op
delete bars=1-7 beats=1-3 lanes=38 v=1-62
# rung 2 notes: hats to eighths with the mask idiom: digit 1 on the "e" and "a" cells, then delete what is marked. what is left keeps its shape, 112 on the beat and 98 on the "and"
accent bars=1-8 lanes=42 grid=16 pattern=-1-1
delete bars=1-8 lanes=42 v=1-20
# rung 1 level: the ghosts that stay drop by a quarter, each pair keeps its rise
vel bars=1-7 lanes=38 v=1-62 scale=0.75
```

Proved on a copy of the demo with sixteenth hats and ghosts written into bars 1-8: 57 hat notes and 14 ghosts out, ghosts 28 and 42 become 21 and 32, hats 112 and 98, fills and kick as before. The demo itself has no ghosts, so rung 1 has no room and rung 2 is the eighths to quarters step with its shape (the block of song 10 "breathe": 29 hats out, 112 on beat 1, 98 after). "More": rung 3, an eighth of air in the last bar of a phrase (`delete bars=4 beats=4.5-5 lanes=42,46`), never where a fill runs to the bar line, as both fills of the demo do.
