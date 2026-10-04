# pop punk pack: the 90s wave to the modern scene and easycore (Green Day, blink-182, New Found Glory, Paramore, The Story So Far, A Day To Remember and similar)

- It is this genre when: the file runs at 150-220 bpm with feel `normal`, or at 75-110 bpm with feel `double` (the same fast beat stored at half tempo: 75-110 backbeats per minute either way). Mid tempo songs go down to about 94 bpm. Kick/bar 2-5 on beats 1 and 3 plus guitar accents, lock only 25-50% under strummed eighths, every backbeat at digits 8-9, no ghost notes in the fast beat.
- Keepers and feels: tight hh eighths or a floor tom ride (keeper none) in verses, hh_open, ride or crash1 in choruses, a `half` bridge or easycore breakdown on crash, ride or china quarters.
- Forms: 8 bar phrases in the order intro, verse, pre-chorus, chorus, verse, pre-chorus, chorus, bridge, last chorus. Pushes on the "and" of 4, band stops, short fills at phrase ends.
- A request is pop punk when it names these bands, pop punk, easycore, a "punk beat" or a "skate beat".

Read docs/FORMAT.md once (grid, ops, selectors, header, `diff`) and knowledge/editing-principles.md (EP 1 to 24 and the acceptance tests, which rule every recipe of this pack). Then, per request: vocabulary.md first, then only the sections it points to.

| document | read it when |
|---|---|
| vocabulary.md | every request. Maps his words to a scope, a default answer (two or three levers in order) and what "more" and "less" change. Holds the notation trap, the cases the file decides (ceiling, no riff track, last bar fill, missing landing), what an edit must never break, the check, and where each worked answer lives |
| song-structure.md | the request names a section or the whole song (chorus bigger, last chorus the biggest, verse should breathe, build into the chorus, bridge drop, stop, second verse different), or you need forms, section signatures, phrase lengths or the recogniser that maps letters to verse and chorus |
| dynamics-and-feel.md | the request is about how notes are played: velocity per lane, hat and cymbal articulation, openings, crash riding, micro timing ("alive", "robotic", "tight", "punchy", "driving", "bouncy") |
| fills.md | the request touches fills, builds, stops or landings: confirming the engine's candidates, slots and ranks, tops and the shape step, the landing, bigger versus heavier versus busier |
| grooves.md | the request touches the groove itself: which beat, which keeper and the keeper ladder with its ceiling case, kick against the guitar, pushes, the Barker layer against the plain layer, physical limits, or you write bars from nothing |

Reading order by request type. Every request starts with vocabulary 2 (notation), 1 (scope, cases the file decides), 5 (the row of the word), 6 (the target), 3 and 4. Then:

1. Feel words on hats and cymbals ("make the hi hat more alive", "less robotic", "more driving", "bouncier"): dynamics-and-feel 9 (table and default answer), then 4, 5 and 6 (the four lists, the three levers), 7 only for timing words.
2. Fill requests ("make my fills bigger", "heavier", "busier", "simpler"): fills 1 and 3 (notation, confirm the spans), fills 4 (slot and rank), fills 9 and 10 (the recipe of the word), fills 6 (tops, backbeat cell, the shape step that closes every recipe for more), fills 7 (landing).
3. Kick and guitar requests ("follow the guitar", "push", "four on the floor", "tighter kick"): grooves 1 (how bars fold), grooves 4 and 5, grooves 2 (kick rows), grooves 7 (limits).
4. Section and song requests ("the chorus bigger", "more energy", "half time", "drop", "build up", "stop", "more space"): song-structure 9 (which section), the rules list of song-structure 10 and its recipe, then grooves 3 or dynamics-and-feel 5 only for a rung change, fills 4 and 6 for the fills. Half time and the stop before the last chorus are worked in vocabulary 7.
5. Style references ("more like Travis Barker", "Green Day", "easycore", "punk beat"): grooves 6 and 2, fills 10 and 5, fills 6 (the shape step).
6. Writing bars from nothing: grooves 1 and 8, dynamics-and-feel 2, fills 8, song-structure 3 and 6.
7. Checking a result before handing it over: `vibedrum diff ORIGINAL RESULT`, `show RESULT --vel` on the changed bars and the acceptance tests of the principles (vocabulary 4). Per request type: the third paragraph of fills 10, the Check bullet of song-structure 10, the check list at the end of dynamics-and-feel 9 with the loop test of dynamics-and-feel 6. Then grooves 9 on the touched bars. A flaw that was in the file before and lies outside the request gets one line in the report, not a fix.

Shared conventions:

- Notation first: grooves.md, dynamics-and-feel.md and song-structure.md say notation A and B, fills.md says fast and slow notation. Everything is written for A. Never convert a file.
- Cells are grid=16 indexes 0-15: beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12, the push = 14. `beats=` selectors count quarter notes from 1.
- A written digit d sets velocity d x 14, 9 sets 127. A shown digit is a band 14 wide: check levels with `show --vel`. Ghosts stay under 60, hat tips under 100, backbeats at 116-127, main kicks at 110-124. These bands are for reading and for bars written new: a lane of his at 127 is never turned down on a request for more.
- Script order (EP 16): notes (bar blocks, `copy`, `remap`, `delete`), level, `humanize`, gestures (`accent` on single bars, `vel add=`, `ramp scale=`), then the hat lift (`ramp from= to=` on three notes, dynamics-and-feel 6) as the last line, `shift` after it. `humanize` is a finish, never the design: `vel=2` on a keeper, `vel=3` on kick or backbeat, `time=` only for "looser" and "more human".
- Examples are written for bars 1 to 8 in 4/4 on an example file their comments describe. That is a pattern, not a range: map each bar by its role, read what the mapped bar holds, and write your own lines.
- Engine facts: `# sections` prints hh_open as a keeper of its own, so a verse moved to the open hat changes its keeper name and can change the section letters. `diff` prints a `remap` as notes removed and added. `show` folds a bar only when its drum rows and its `# riff` row both match an earlier bar. Plain `show` compares velocity digits, `show --vel` exact velocities.
- `[n]` points to the source list of the same document. "unconfirmed" marks a working default with no source.
- The header's sections and fills are candidates. The grid has the last word.
