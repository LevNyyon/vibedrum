# djent pack

Modern metal and djent (Meshuggah, Periphery, TesseracT, Animals as Leaders, Monuments, Vildhjarta and similar).

It is this genre when: the kick follows a syncopated guitar riff in sixteenths or thirty-seconds (lock 70% or more when the file has a riff track), the feel is mostly `half`, the keeper in heavy parts is china or crash in quarters, riff cycles run across the bar line or the meter is odd.

Read docs/FORMAT.md once (grid, ops, selectors, header) and knowledge/editing-principles.md (EP 1 to 21, which every recipe of this pack obeys). Then, per request: vocabulary.md first, and only the sections it points to.

| document | read it when |
|---|---|
| vocabulary.md | every request. Maps his words to a scope, a default first step and what "more" adds, lists what an edit in this style must never break and the cases the file decides (ceiling, no riff track, last bar fill, missing landing, two tom kit), and holds worked default answers |
| dynamics-and-feel.md | the request is about how notes are played: velocity bands and walls, hat and cymbal articulation, ghost notes, micro timing ("alive", "robotic", "tight", "punchy", "groovy") |
| fills.md | the request touches fills: confirming them in the grid, the rank of each slot, bands and shape inside a fill, landings by rank, the recipe ladders, heavier versus busier |
| grooves.md | the request touches the groove itself: kick and riff lock, polymeter, feels, the keeper ladder and its ceiling case, double kick, style references, or you write bars from nothing |
| song-structure.md | the request names a section or the whole song: letters to verse, chorus and breakdown, phrase lengths, energy levers, and the section recipes (bigger, breathe, build, hit harder, drop) |

Reading order by request type. Every request starts with vocabulary 1 (scope and the cases the file decides), 4 (the word), 2 and 3:

1. Feel words on hats, cymbals, ghosts ("make the hi hat more alive", "less robotic", "groovier"): vocabulary 1 and 4, dynamics-and-feel 10 (how to read the table, the ladder), the sections 2 to 9 its recipe cites, dynamics-and-feel 6 (loop test).
2. Fill requests ("make my fills heavier", "busier", "simpler fills"): vocabulary 1 and 4, fills 2 (confirm, file cases), fills 3 (rank of each fill), fills 9 (ladder and worked scripts), fills 5 (bands, lean, direction, top), fills 6 (landing by rank).
3. Kick requests ("lock the kick", "follow the guitar", "tighter"): vocabulary 4, grooves 1 and 2, song-structure 7, grooves 6 for runs. No riff track: the first bullet of grooves 1.
4. Section and song requests ("the chorus bigger", "hit harder", "breathe", "build up", "drop", "half time"): vocabulary 1 (scope), song-structure 1 and 9 (name the sections), the rules list at the top of song-structure 10, then its recipe, then 5 and 6, fills 3 for the rank of the fills in and around the section.
5. Style references ("more like Meshuggah", "more like Periphery"): vocabulary 4 and 6, grooves 2, 4, 5, 8 and 9, fills 3 and 4.
6. Writing bars from nothing: grooves 9 (polymeter bars are P1), song-structure 2 and 3, song-structure 6 (the two bar build), fills 7, dynamics-and-feel 1.
7. Checking a result before handing it over: `show --vel` on the changed bars (EP 20), then vocabulary 3, grooves 10, dynamics-and-feel 6 (loop test) and fills 5 (bands), on the bars and lanes the edit touched. sd is not a test of success. A flaw that was already in the file outside the request is named in one line, not fixed.

Shared conventions:

- Cells are grid=16 indexes 0-15: beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12. `beats=` selectors count quarter notes from 1.
- A written digit d sets velocity d x 14, 9 sets 127. A shown digit is a band 14 wide (9 = 119-127): check levels with `show --vel`. Ghosts stay under 60. Backbeats and riff kicks live in digits 8-9, keeper cymbals at 105-120 with 127 on section and phrase starts only.
- Tempo dependent numbers are formulas: ticks = ms x bpm x ppq / 60000, an eighth = ppq / 2 ticks. Read bpm and ppq in the header. The demo is 130 bpm, examples at 140 are only examples.
- lock: 85% or more means the riff owns the kick row. 70% or more means kick timing never moves. No riff track: no lock column, skip every riff and lock step and say so.
- A script runs top to bottom, bar rows included. Order (EP 11): notes (bar blocks, `copy`, `remap`, `delete`), level (the base `accent` over a whole part, `vel`), `humanize` (one `vel=` run and one `time=` run per lane per section), gestures (`accent` on single bars or cells, `vel add=`, `ramp scale=`, `set=` on one note), wall clamps, `shift` last.
- Engine facts that FORMAT.md does not state: a bar block at a grid that does not divide the old one keeps existing notes at their old ticks (`delete` the rewritten lanes first). `# fills:` also lists bars with new ghosts, a blast or a double time burst, so reread it before any bulk `fills` op. After `remap` 42 to 46 `# sections` still prints keeper `hh`: the change shows in `# lanes`. `shift` can move a cell 0 note in front of its bar line.
- Examples are written for bars 1 to 8 in 4/4. That is a pattern, not a range: map each bar by its role and look at what the mapped bar holds.
- `[n]` points to the source list of the same document. "unconfirmed" marks a working default with no source.
- The header's sections and fills are candidates. The grid has the last word.
