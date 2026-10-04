# Editing principles

Genre independent. They come from two rounds of blind trials: fresh sessions followed pack recipes literally and strict judges graded the results. Round one failed by doing everything at once (every fill maxed, flattened and pasted). Round two failed the other way: timid edits nobody would hear, and a "hit harder" request answered with softer notes. Every edit, and every recipe and worked answer in the packs, sits between those two.

## Choosing what to do

1. Decisive, not exhaustive. The edit must be heard as what he asked for on the first listen, in the place he meant. Use the two or three levers with the most impact on this file. Not the whole list, and not only the safest one. He can say "more" or "less".
2. Order levers by impact, not by safety. The lever a producer would reach for first comes first: weight under the hits, air before an entrance, the top of a fill, a real accent. Fine shaping comes after and never alone.
3. Direction. A request for more (heavier, bigger, harder, louder, more aggressive, more energy) never leaves the notes in scope quieter than they were. Shape a flat part by raising its strong notes and leaving the weak ones where they are. Lowering is for requests for less, and for "alive" or "dynamic" where the average stays about level.
4. Read the room first. Look at `# lanes`. A lane at the ceiling (min and max 127) cannot be raised. Then use what still has room, in this order: weight (a kick under the hit, a second cymbal on the entrance, a lower drum), air (silence right before the hit), other lanes in scope with headroom (fills at 98 inside a section at 127). Lowering the surroundings comes last, by 15 to 25, on the weak positions only, never on the hits themselves, and never as the whole answer.
5. Grade by role, never paste. Fills, landings and accents have ranks: a one beat pickup inside a phrase is smaller than a phrase ending fill, which is smaller than the fill into a new section. Ranks differ by a clear margin: a digit (14) at the top, and usually in length or weight too. Two fills of the same rank still differ in something designed: which drum carries the top, where the accent sits, the contour. Never one template with only the bar numbers changed.
6. Landing hierarchy. A stacked two cymbal landing belongs to a section start. A landing inside a section gets one crash. No landing is bigger than the entrance of its own section or than the opening hit of the song. An entrance stands above what comes right before it: 10 or more over the last fill note, or air before it. Never bring in a section's keeper cymbal before that section starts.
7. Stay in scope. An edit outside the named bars or lanes needs a reason (a landing, a setup) and gets reported. Never change the keeper pattern, the backbeat or the kick row of a section the request did not name.

## Keeping it musical

8. Keep contour and voices. Do not merge two drums into one. After the edit a fill uses as many distinct drums as before, and a descent still descends (tom1 is the highest, tom6 the lowest). On a kit with few toms, "lower" means more weight on the low drum (the last notes on it, more of its notes), not every tom remapped to it. Use only tom lanes that already have notes in `# lanes`, unless he asks for more drums.
9. A fill ends on its top. The last note is the loudest, or within 5 of it, and it sits on the strong hand and the heaviest drum of the fill. A fill that starts on the backbeat cell keeps that backbeat at full. Never end a fill, a section or the song on a weak stroke.
10. The heavy voice stays heavy. In an alternation between a high and a low drum (snare and floor tom), the low drum is not the weak hand. Read which notes are the strong ones from the figure, not from cell parity.
11. Never flatten. `vel min=` and `set=` erase shape. After a level op, restore shape with leading hand accents and a direction. 127 on one or two notes of a phrase at most. No hand lane ends with sd under 3.
12. Shape follows the music, not a formula. Accents go where something happens: with the kick, on the beat that carries the bar, at a phrase start, into a fill. A part is alive when it moves over the phrase (4 or 8 bars: a start, a middle, a lift into the fill), not when a 1 or 2 bar pattern repeats with random spread. If `show` still prints `# bar 7 = bar 3`, or the bars go A B A B, it is still a loop.
13. Thresholds are walls. When a pack names a boundary (shoulder against tip, ghost against backbeat), scaling and humanize must not carry notes across it. Clamp afterwards with `vel ... min=` or `max=` on that exact pitch.
14. Balance with the neighbours. Raising one lane changes how the lanes around it read. Hats raised over the fill they hand to make the fill smaller. Check the lanes that share the bars.
15. Playable by two hands and two feet. Two hand lanes per cell at most (kick and hh_pedal are feet). Look one cell back: a two cymbal landing straight after a floor tom sixteenth needs both hands to travel.

## Writing the script

16. Order. Notes first (bar blocks, `copy`, `remap`, `delete`), then level (`vel`), then `humanize`, then the designed gestures last (`accent`, `vel add=`, `ramp scale=`). A gesture written before humanize is blurred by it.
17. Sizes. An accent meant to be heard is 15 to 25 over its neighbours (one digit or more). 10 is the floor for a subtle variation, not a target. Under 7 it is the same sample. Humanize spread stays at or under a third of the smallest designed difference, and it is never what makes two bars differ.
18. `ramp from= to=` writes absolute values and flattens accents. For a crescendo over a shaped part use `ramp scale=A-B`. A ramp that multiplies must not undo the level step before it: when a fill is raised and then ramped, the start of the ramp is 1 or close to it and the end goes above 1.
19. Name the voice. `lanes=hat` also selects hh_open and hh_pedal. `lanes=snare` also selects rim, ghosts and fill notes. When a step is meant for one voice, select its pitch and a `v=` band.
20. A recipe is a pattern, not a script to paste. Map every bar number to this file and look at what each mapped bar holds. A worked answer in a pack shows the moves on one example. Decide the cells, levels and bars from this file's grid: where its kick is, which drums it has, how its fills are built.

## Cases the file can put you in

21. No riff track: skip every step that mentions the riff or lock, and say so. Every groove kick then counts as locked: do not move it.
22. A fill in the last bar has no landing bar. Leave the landing out and say so. It still ends on its top.
23. A fill candidate with no crash after it is still a fill. When the request is about fills, give it its landing as part of the edit: one crash and a kick, a digit under the section entrance. Report it.
24. A recipe names lanes the kit does not have: translate to the nearest lanes that have notes, and keep the number of voices.

## Acceptance tests, before reporting

Run `vibedrum diff ORIGINAL RESULT` and `vibedrum show RESULT --vel` on the changed bars. Every test below must pass. If one fails, change the script and apply again from the same starting file.

- Direction: for a "more" request, `# sections` shows the named scope at the same or a higher velocity or with more notes, and `# lanes` shows no lane in scope with notes quieter by more than 3. For a "less" request, the mirror.
- Audible: the main gesture is 15 or more in velocity, or it adds or removes notes. If the largest change in the diff is about 10, the edit is too small: take the next lever.
- Fills: in `# fills`, every fill in scope has last within 5 of peak. Peaks step up by rank with 10 or more between ranks. No two fills have the same velocity sequence.
- Entrance: a section start or landing in scope is 10 or more above the note before it, or has air before it.
- Not a loop: the changed section does not fold into `# bar N = bar M` lines in `show --vel`, and it does not read A B A B.
- Scope: `# bars changed` holds only bars in scope plus the ones you will name in the report.
- Report: two or three lines. Every claim maps to a line of the diff or of `show --vel`. Say what got louder, what got quieter, what was added, and anything outside the named scope. Do not say "harder" or "heavier" for a change the diff shows as quieter.
