# djent pack

Modern metal and djent (Meshuggah, Periphery, TesseracT, Animals as Leaders, Monuments, Vildhjarta and similar).

It is this genre when: the kick follows a syncopated guitar riff in sixteenths or thirty-seconds (lock 70% or more when the file has a riff track), the feel is mostly `half`, the keeper in heavy parts is china or crash in quarters, riff cycles run across the bar line or the meter is odd.

Read docs/FORMAT.md once (grid, ops, selectors, header). Then, per request: vocabulary.md first, and only the sections it points to.

| document | read it when |
|---|---|
| vocabulary.md | every request. Maps his words to a scope, a default interpretation and a recipe, lists what an edit must never break, and holds complete answer scripts |
| dynamics-and-feel.md | the request is about how notes are played: velocity, hat and cymbal articulation, ghost notes, micro timing ("alive", "robotic", "tight", "punchy", "groovy") |
| fills.md | the request touches fills: confirming them in the grid, where they go, the intensity ladder, landings, heavier versus busier |
| grooves.md | the request touches the groove itself: kick and riff lock, polymeter, feels, which cymbal keeps time, double kick, style references, or you write bars from nothing |
| song-structure.md | the request names a section or the whole song: letters to verse, chorus and breakdown, phrase lengths, energy levers, builds, drops, transitions, meter and tempo |

Reading order by request type:

1. Feel words on hats, cymbals, ghosts ("make the hi hat more alive", "less robotic", "groovier"): vocabulary 4 and 3, dynamics-and-feel 10, then the sections 2 to 9 its recipe cites.
2. Fill requests ("make my fills heavier", "busier", "simpler fills"): vocabulary 4, fills 2 (confirm the spans), fills 8 and 9, fills 6 (landing), fills 5 for flams and shapes.
3. Kick requests ("lock the kick", "follow the guitar", "tighter"): vocabulary 4, grooves 1 and 2, song-structure 7, grooves 6 for runs.
4. Section and song requests ("the chorus bigger", "build up", "drop", "half time", "more space"): vocabulary 1 (scope), song-structure 1 and 9 (name the sections), song-structure 10, then 5 and 6, fills 3 for the fill slots.
5. Style references ("more like Meshuggah", "more like Periphery"): vocabulary 4, grooves 2, 5, 8 and 9, fills 3 and 4.
6. Writing bars from nothing: grooves 9, song-structure 2 and 3, fills 7, dynamics-and-feel 1.
7. Checking a result before handing it over: vocabulary 3, grooves 10, dynamics-and-feel 2.

Shared conventions:

- Cells are grid=16 indexes 0-15: beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12. `beats=` selectors count quarter notes from 1.
- A written digit d sets velocity d x 14, 9 sets 127. Ghosts stay under 60. Backbeats and riff kicks live in digits 8-9.
- lock: 85% or more means the riff owns the kick row. 70% or more means kick timing never moves.
- A script runs top to bottom, bar rows included. Usual order: bar blocks, `copy`, `remap`, `delete`, `accent`, `vel`, `ramp`, `humanize`, `shift`.
- `[n]` points to the source list of the same document. "unconfirmed" marks a working default with no source.
- The header's sections and fills are candidates. The grid has the last word.
