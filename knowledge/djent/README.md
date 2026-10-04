# djent pack

Modern metal and djent (Meshuggah, Periphery, TesseracT, Animals as Leaders, Monuments, Vildhjarta and similar).

It is this genre when: the kick follows a syncopated guitar riff in sixteenths or thirty-seconds (lock 70% or more when the file has a riff track), the feel is mostly `half`, the keeper in heavy parts is china or crash in quarters, riff cycles run across the bar line or the meter is odd.

Read docs/FORMAT.md once (grid, ops, selectors, header, `diff`) and knowledge/editing-principles.md (EP 1 to 24 and the acceptance tests, which every recipe of this pack obeys). Then, per request: vocabulary.md first, and only the sections it points to.

| document | read it when |
|---|---|
| vocabulary.md | every request. Maps his words to a scope, a decisive default answer and what "more" and "less" change, lists what an edit in this style must never break and the cases the file decides (ceiling, no riff track, last bar fill, missing landing, two tom kit), and says where each worked answer lives and how to use one |
| dynamics-and-feel.md | the request is about how notes are played: velocity bands and walls, hat and cymbal articulation, ghost notes, micro timing ("alive", "robotic", "tight", "punchy", "groovy") |
| fills.md | the request touches fills: confirming them in the grid, the rank of each slot, strokes and tops inside a fill, air and landings, the recipes, heavier versus busier |
| grooves.md | the request touches the groove itself: kick and riff lock and when a kick may be added, polymeter, feels, the keeper ladder and its ceiling case, double kick, style references, or you write bars from nothing |
| song-structure.md | the request names a section or the whole song: letters to verse, chorus and breakdown, phrase lengths, energy levers, air before an entrance, and the section recipes (hit harder, bigger, breathe, build, drop) |

Reading order by request type. Every request: vocabulary 1 (scope and the cases the file decides), 4 (the row of the word), 5 (the target), 2, 3 and the opening of 6 (how to use a worked answer). Then:

1. Feel words on hats, cymbals, ghosts ("make the hi hat more alive", "less robotic", "groovier"): dynamics-and-feel 3 (four lists, lever 1), 5 (openings), 6 (growth, handover, lift, loop test), 10 (table and worked hat answer), and 4 when the keeper is sixteenths, a ride or on quarters.
2. Fill requests ("make my fills heavier", "busier", "simpler fills"): fills 2 (confirm, file cases), fills 3 (rank table: top, body, kick, landing), fills 9 (Heavier levers, worked answers are examples to read, not scripts to paste), fills 5 (strong and weak strokes, backbeat cell, top, ending), fills 6 (air, missing landing). A request for weight: also grooves 1 (when a kick may be added, with and without a riff track).
3. Kick requests ("lock the kick", "follow the guitar", "tighter"): grooves 1 and 2, song-structure 7, grooves 6 for runs. No riff track: the bullet named "No riff track" in grooves 1.
4. Section and song requests ("hit harder", "the chorus bigger", "breathe", "build up", "drop", "half time"): song-structure 1 and 9 (name the sections), the rules list at the top of song-structure 10 (its fills rule gives the tops, pickup against section fill), then its recipe, then song-structure 5 and 6 (the air). fills 3 only to confirm fills and phrases. A request for weight: also grooves 1.
5. Style references ("more like Meshuggah", "more like Periphery"): vocabulary 6, grooves 2, 4, 5, 8 and 9, dynamics-and-feel 4, fills 3 and 4.
6. Writing bars from nothing: grooves 9 (polymeter bars are P1), song-structure 2 and 3, song-structure 10 (the build recipe), fills 7, dynamics-and-feel 1.
7. Checking a result before handing it over: `vibedrum diff ORIGINAL RESULT`, `show RESULT --vel` on the changed bars and the acceptance tests of the principles, then grooves 10 on the touched bars. The loop test (dynamics-and-feel 6) belongs to the words that ask for life (alive, dynamic, less robotic, more human, groovier) and to the groove bars of a section recipe. sd is not a test of success. A flaw that was already in the file outside the request gets a few words in the report, not a fix.

Shared conventions:

- Cells are grid=16 indexes 0-15: beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12. `beats=` selectors count quarter notes from 1.
- A written digit d sets velocity d x 14, 9 sets 127. A shown digit is a band 14 wide (9 = 119-127): check levels with `show --vel`. Ghosts stay under 60. Backbeats and riff kicks live in digits 8-9. Keeper cymbal bands (dynamics-and-feel 1: china 104-124, open hat keeper 95-115, a phrase start up to 127 or 126) are a reading aid and the level of bars written new, not a level to lower toward: a keeper of his at 127 is never turned down on a request for more.
- Tempo dependent numbers are formulas: ticks = ms x bpm x ppq / 60000, an eighth = ppq / 2 ticks. Read bpm and ppq in the header. The demo is 130 bpm, examples at 140 are only examples.
- lock: 85% or more means the riff owns the kick row. 70% or more means kick timing never moves. No riff track: no lock column. Take the "without a riff track" branch where a recipe has one, skip what only reads the riff or lock, and say so.
- A script runs top to bottom, bar rows included. Order (EP 16): notes (bar blocks, `copy`, `remap`, `delete`), level (the base `accent` over a whole part, `vel`), `humanize` (one `vel=` run and one `time=` run per lane per section), gestures (`accent` on single bars or cells, `vel add=`, `ramp scale=`, `ramp from= to=` for the hat lift, `set=` on one note), wall clamps, `shift` last.
- Engine facts that FORMAT.md does not state: a bar block at a grid that does not divide the old one keeps existing notes at their old ticks (`delete` the rewritten lanes first). `# fills:` also lists bars with new ghosts, a blast or a double time burst, so reread it before any bulk `fills` op. A tom on the same beat of most bars of a section is not listed there, a tom in a few bars is. `diff` counts a slid or remapped note as removed and added, not as moved or louder. The engine takes the busiest pitched track as the riff by itself: no `# riff:` line means the file has none. `shift` can move a cell 0 note in front of its bar line.
- Examples are written for bars 1 to 8 in 4/4. That is a pattern, not a range: map each bar by its role and look at what the mapped bar holds.
- `[n]` points to the source list of the same document. "unconfirmed" marks a working default with no source.
- The header's sections and fills are candidates. The grid has the last word.
