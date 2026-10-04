# Editing principles

Genre independent. They come from blind trials: fresh sessions followed pack recipes literally, strict judges graded the results, and these are the ways the results went wrong. Every edit obeys them, and so does every recipe and worked answer in the packs.

## Choosing what to do

1. One step. A recipe lists levers in order. Take the first one or two the file has room for, then stop. Never run a whole ladder in one script. He can say "more".
2. Read the room first. Look at the `# lanes` line. A lane at the ceiling (min and max 127, sd 0) cannot be raised: the lever is then contrast. Lower what surrounds the moments that should hit (keeper down 10 to 15, phrase starts left at full) instead of adding level or notes.
3. Grade by role, never paste. Fills, landings and accents have ranks: a one beat pickup inside a phrase is smaller than a phrase ending fill, which is smaller than the fill into a new section. After the edit the ranks still hold and the biggest is clearly the biggest. The bulk `fills` selector is for a uniform level nudge only. Shape each fill by its slot.
4. Landing hierarchy. A stacked two cymbal landing belongs to a section start. A landing inside a section gets one crash. No landing is bigger than the entrance of its own section or than the opening hit of the song. Never bring in a section's keeper cymbal before that section starts.
5. Stay in scope. An edit outside the named bars or lanes needs a reason (a landing, a setup) and gets reported. Never change the keeper pattern, the backbeat or the kick row of a section the request did not name.

## Keeping it musical

6. Keep contour and voices. Do not merge two drums into one. After the edit a fill uses as many distinct toms as before, and a descent still descends (tom1 is the highest, tom6 the lowest). On a kit with few toms, "lower" means more weight on the low drum (the last notes on it, more of its notes), not every tom remapped to it. Use only tom lanes that already have notes in `# lanes`, unless he asks for more drums.
7. Never flatten. `vel min=` and `set=` erase shape. After any level op restore it: leading hand one digit (14) above the other hand, a direction (rising into the landing, or falling per drum), and 127 on one or two notes of a phrase at most. No hand lane ends with sd under 3.
8. Shape, not noise. "Alive" means bars differ by gestures a player makes on purpose: another accent cell, an opening, a lift, a quieter repeat. Random spread on a one beat pattern is still a one beat loop. The test is not sd. The test: at least a third of the bars in the section differ from their neighbour in a designed cell, visible at digit level.
9. Thresholds are walls. When a pack names a boundary (shoulder against tip, ghost against backbeat), scaling and humanize must not carry notes across it. Clamp afterwards with `vel ... min=` or `max=` on that exact pitch.
10. Playable by two hands and two feet. Count hand lanes per cell (two at most, kick and hh_pedal are feet). Also look one cell back: a two cymbal landing straight after a floor tom sixteenth needs both hands to travel. At fast tempos leave the last cell before a stacked landing to the kick.

## Writing the script

11. Order. Notes first (bar blocks, `copy`, `remap`, `delete`), then level (`vel`), then `humanize`, then the designed gestures last (`accent`, leans with `vel add=`, lifts with `ramp scale=`). A gesture written before humanize is blurred by it.
12. Sizes. A designed difference needs 10 velocity or more to be heard. Under 7 it is usually the same sample. Humanize spread stays at or under half the smallest designed difference. A lean of 4 under a humanize of 6 does not exist.
13. `ramp from= to=` writes absolute values and flattens accents. For a crescendo over a shaped part use `ramp scale=A-B`.
14. Name the voice. `lanes=hat` also selects hh_open and hh_pedal. `lanes=snare` also selects rim, ghosts and fill notes. When a step is meant for one voice, select its pitch and a `v=` band.

## Cases the file can put you in

15. No riff track: skip every step that mentions the riff or lock, and say so.
16. A fill in the last bar has no landing bar. Leave the landing out and say so.
17. A fill candidate with no crash after it is still a fill. Repairing its landing is its own single step: one crash and a kick, and only when the request is about fills.
18. A recipe names lanes the kit does not have: translate to the nearest lanes that have notes, and keep the number of voices.
19. A recipe written for bars 1 to 8 of an example is a pattern, not a range. Map every bar number to this file, and check what each mapped bar holds (a fill bar inside a range needs its own treatment).

## Before reporting

20. Check with numbers. Run `show --vel` on the changed bars and find each gesture you are about to describe in the velocities. Do not report what the numbers do not show.
21. Report truthfully in two or three lines: what changed, where, and anything changed outside the named scope. Do not say "not more notes" when notes were added.
