# Song structure: the language above the drum layer (pop punk)

Scope: pop punk from the 90s wave to the modern scene and easycore. This file names the lettered sections of the `show` header, gives lengths and phrase structure, lists how the drums move energy at a fixed tempo, how sections are joined, how the drums sit against guitar, bass and vocal, and what a song level request means in edits. Conventions as in the sibling documents: cells are grid=16 indexes 0-15 of a 4/4 bar (beat 1 = cell 0, beat 2 = 4, beat 3 = 8, beat 4 = 12, the "and" of 4 = 14), everything is written for notation A (section 1) at 480 ppq, a written digit d is velocity d x 14 (9 = 127). In the bar blocks a 9 in a snare row is a rimshot backbeat (116-127 on a real file), an 8 in a kick row a main kick (110-124), a 9 in a kick row sits only under a section start, a push or a landing: on a real file keep existing notes with `x`. Pointers: "grooves 5" = grooves.md section 5, "fills" = fills.md, "feel" = dynamics-and-feel.md, "vocabulary" = vocabulary.md, "EP 4" = rule 4 of knowledge/editing-principles.md, which every recipe here obeys. `[n]` = source list at the bottom. "unconfirmed" = working default, no source found. Header readings quoted here were produced with this engine version.

## 1. Tempo, notation and size
The same song is stored two ways (grooves 1, the same table). Decide once per file, on the main verse or chorus, from backbeats per minute (`normal` = bpm / 2, `double` = bpm, `half` = bpm / 4): 75-110 is the fast beat in either notation, 47-75 a mid tempo song, 37-55 under the label `half` a half time part. Never convert a file: write in the notation it has. Everything below is notation A. In a B file halve every bar count, read `double` for `normal` and `normal` for `half`, and convert cells with the last row of the table.

| | notation A (180 bpm, snare on 2 and 4) | notation B (the same music at 90 bpm) |
|---|---|---|
| `# tempo:` | 150-220 | 75-110 |
| verse and chorus on the fast beat | feel `normal`: snare 4 12, eighth keeper on the even cells | feel `double`: snare 2 6 10 14, eighth keeper on all 16 cells |
| half time bridge, chorus tag | `half` | `normal` |
| breakdown at quarter speed (rare) | snare on cell 0 of every second bar: bars alternate `open` and `other` | `half` |
| snare on all four quarters | `normal` | `blast` (8 strong snares, on the even cells) |
| phrase, section | 8 bars, 8 or 16 bars | 4 bars, 4 or 8 bars |
| push | cell 14 | cells 7 and 15 |
| bars per minute (bpm / 4) | 37-55 | 19-28 |
| conversion | two A bars = one B bar | A cell c of the first bar = B cell c/2, of the second bar = B cell 8 + c/2 |

- Tempo conventions: fast songs 150-220 bpm (150-200 in a writing guide [2], song figures in grooves 2), mid tempo songs 94-150 with `normal` in every section (150-165 takes either name, grooves 1), easycore 160-200 with breakdowns felt at 70-100 [17], pack grooves 116-204 [18].
- One tempo per song is the norm: `# tempo: 1:180`. Section contrast comes from feel and keeper, not bpm. Two to four entries are real changes at section starts (one structural map puts the 4 bar unit before the chorus of All the Small Things at about 145 against 150 [7]): keep them. A long list is a tempo map. No op changes tempo: answer "faster" and "slower" for a section with feel or keeper rate (section 5) and say so.
- Size: bars = minutes x bpm / 4. All the Small Things: 2:48 at 150 bpm = 105 bars [6][7]. A header of 100-160 bars in A (50-80 in B) is a whole song. Under about 40 bars the file is a part of one: name what is there, do not expect the full form.

## 2. Forms
- Standard: intro, verse, pre-chorus, chorus, verse 2, pre-chorus, chorus, bridge, last chorus, optional outro [1][2][3]. Short form: intro riff, verse, chorus, verse, chorus, double chorus [2]. Breakdown form: verse, chorus, verse, chorus, breakdown, chorus [2]. Easycore keeps the frame and adds chug riffs, gang vocals and a half time breakdown in the bridge slot [17][22]. Dammit, as a band member describes its arrangement: verse, verse, chorus, verse, chorus, bridge, chorus [5]. All the Small Things by one map: intro, two verses back to back, a 4 bar link (the map calls it a bridge), chorus, instrumental, verse, link, chorus, a 16 bar instrumental, then link and verse material alternating to the end, most units 8 bars [7]. A post chorus is optional and may follow only some choruses [1]. In this style it is usually the intro riff again without the vocal (unconfirmed). The bridge sits after the second chorus [1][4]. The last chorus is often doubled, with gang vocals on top [2], and is usually the loudest and most intense part of the song [23].

## 3. Section signatures
- Header line: `#   B 5-16 hh normal 3.3 106 38%` = name, bars, keeper, feel, kick/bar, vel (mean velocity of every drum note in the range), lock (only with a riff track, read as in grooves 4). vel is weak evidence in this style: on a played file every full kit section reads 104-116 (tight hat verse about 107, ride chorus about 106, crash chorus about 113, half time about 111, kick only about 114), so a difference under 8 means nothing. 120 or more is a programmed section near the ceiling (section 10, Direction). Under 100 means taps or ghosts (a marching snare bridge reads 75-90) or a build. Read keeper and feel first, then the rows.
- A letter is one keeper plus one feel, not a song function (vocabulary 1). In this style: a pre-chorus on the verse's hat is a slice of the verse letter. Tight and sloshy hat both print `hh`: look for a 46 row on the even cells. A guitar alone intro and a stripped first half of a last chorus with no drum notes both print `none empty 0 0` and share a letter. Kick only prints `none open` and a hat with no snare `hh open` from 3 bars on: a 2 bar drop stays inside the letter before it. A floor tom verse prints `none normal`. Inside a hat or ride section, two bars of snare on all four quarters under crash quarters print `crash1 normal`, as their own letter or joined to a crash chorus that follows. A one bar build or stop gets no letter. Markers win over all of this.
- The verse stays tight and minimal under the vocal, the chorus opens up with bigger crashes [13][3]. A verse to chorus change can be as small as hat to ride (Basket Case [9], Tre Cool's habit [12]).

| section | bars (A) | keeper | feel | kick/bar | vel, lock | grid tells |
|---|---|---|---|---|---|---|
| intro | 4, 8 or 16, riff intro [2] | none while the guitar plays alone [5][6][7], then the chorus keeper | `empty`, then as the chorus | 0, then 2-5 | 0, then as the chorus. Lock 12-40% under a lead | `# bars 1-4 empty` over a `# riff` row with onsets, then a pickup fill or crash + kick at 9. Or chorus rows from bar 1 under a lead (12-16 riff onsets per bar: ignore lock) |
| verse | 8 or 16, multiples of 4 [4] | hh with only a 42 row: tight eighths [9][10]. Or none: tom5 on the even cells [10][12] | `normal` | 2-4 | 104-110, 25-50% | the lowest rung of the song. Crash only on cell 0 of bars 1 and 5, fill only in bar 8, at most a pickup in bar 4. `# riff` on all 8 even cells (palm muted eighths [2]). Verse 2 is the same letter returning with one difference (section 8), often at half the length (unconfirmed) |
| pre-chorus | 4 or 8 [4] | verse keeper, hh with a 46 row, or ride | `normal`. Its last bar may read `blast` or `other` | 4 (four on the floor), or falling to 0-1 (down pre-chorus [14]) | 106-112, 25-50% | the bars before a chorus start. One or two of: hat opens, kick on 0 4 8 12 (grooves P5 bar 1), snare on 0 4 8 12 in its last 1-2 bars, a build, a stop or an empty bar at its end (block in section 6) [2][4][19] |
| chorus | 8 or 16 [4] | hh with a 46 row on the even cells, ride, or crash1 [8][9][12] | `normal`. `half` for a half time chorus (unconfirmed how common) | 2-5 | 106-116, 25-50%, 75-100% over held chords | crash1 + kick at 9 on its first cell (or on the push before it), a crash on cell 0 every 2 or 4 bars, plain snare row, no ghosts, the same rows on every return |
| chorus tag | last 2-8 bars of a chorus | chorus keeper or crash1 | `half`, or `normal` with snare on 0 4 8 12 | 2-4 | as chorus | Misery Business: half time 8 bars into the chorus, then snare on every quarter [8] |
| post chorus riff | 4 or 8 | chorus keeper | as chorus | as chorus | as chorus, lock 12-40% under a lead | rows equal the intro. No vocal: fills may follow the lead (grooves 2 row 3) |
| bridge | 8 [4] or 16 | crash1 or ride on quarters, or none | `half` [22]. Or `open` (kick only, tom groove), `empty`, or a marching snare [8], whose feel is read from its accents alone (`blast`, `other` or `normal`) | 0-5 | 108-114, 75-90 for a marching snare | a letter that occurs once, after chorus 2. Often two halves: 4-8 bars dropped, then 4-8 bars that rise |
| breakdown (easycore) | 8 or 16 | china or crash1 on quarters | `half` | 5-10 | 112-116, 85%+ | kick = riff chug with holes of 3+ cells, snare on cell 8, no ghosts [16][17], often a silent beat before it (unconfirmed) |
| build | 1, 2 or 4 | none, or `hh` when a 44 row keeps time | `normal` (quarters), `blast` (eighths, sixteenths) | 4 | 90-100, rising left to right | end of a pre-chorus or bridge. Snare (+ tom5) hits per beat 1, 2, 4, digits rising from 5 to a top one digit under the landing |
| last chorus | 16-24: the chorus twice [2] | chorus letter, one rung up | `normal` | 2-5 | as chorus | two cymbals on its entry, the most crashes of the song. It may open stripped: 4-8 bars `none empty` or `none open`, then the full chorus (section 5) |
| outro | 4-8, or 1 bar | last chorus or intro keeper | as its source | as its source | as its source | final bar: crash + kick (+ snare) on cell 0, then every row `-`. Or stabs on `# riff` onsets, or snare on 0 4 8 12 for 2-4 bars |
```vd
# verse, 2 of 8 bars: tight hat 112/84 under palm muted eighths, crash only on the section start, kick on 1 and 3 plus one riff accent that moves in bar 2. fill only in bar 8
bar 1 grid=16
crash1 49  |9--- ---- ---- ----|
hh 42      |--6- 8-6- 8-6- 8-6-|
snare 38   |---- 9--- ---- 9---|
kick 36    |9--- ---- 8-8- ----|
bar 2 grid=16
hh 42      |8-6- 8-6- 8-6- 8-6-|
snare 38   |---- 9--- ---- 9---|
kick 36    |8--- --8- 8--- ----|
```
```vd
# chorus, first of 8 bars: crash1 + kick at 127 open it, then ridden crash quarters written 98 and 112 (88-112 on a real file, feel 2: the wash stays under the section start), plain backbeat, kick on the chord rhythm. in bars 2-8 the crash row and the kick row start on 8. up to about 175 bpm the top form is crash eighths in two levels |9-7- 8-7- 8-7- 8-7-| (feel 5). one rung lower: hh_open eighths with a crash on the first cell only
bar 1 grid=16
crash1 49  |9--- 7--- 8--- 7---|
snare 38   |---- 9--- ---- 9---|
kick 36    |9--- --8- 8-8- ----|
```
```vd
# bar 1: half time bridge. one backbeat on beat 3, crash quarters, kick on 1 plus riff accents and off beat 3 (reads crash1 half). bar 2: its dropped form, kick only (reads none open from 3 bars on). bar 3: first bar of an easycore breakdown, china quarters, kick = the riff chug with its rests, double pedal (reads china half, kick/bar 8)
bar 1 grid=16
crash1 49  |9--- 7--- 8--- 7---|
snare 38   |---- ---- 9--- ----|
kick 36    |9--- --8- ---- 8-8-|
bar 2 grid=16
kick 36    |8--- --8- ---- 8-8-|
bar 3 grid=16
# riff     |x-xx --x- --xx -xx-|
china 52   |9--- 8--- 8--- 8---|
snare 38   |---- ---- 9--- ----|
kick 36    |9-88 --8- --88 -88-|
```

## 4. Phrase structure
- Sizes in A: chord cycle 2 or 4 bars, phrase 4 or 8, section 8 or 16 (halve all three in B). A verse is two 4 bar vocal lines or one 8 bar unit: the vocal rests in bar 8 and, less, in bar 4, which is why fills live there (fills 4). A quarter bar fill is small enough to sit under a vocal [11].
- The phrase marker is a crash + kick on cell 0. Punk drummers put crash accents on the arrival points of the riff and of the form [15], Tre Cool on chord changes and momentum shifts [12]. Rank (EP 6, feel 6): section start 122-127, two cymbals allowed. Bar 5 of an 8 bar section and bar 9 of a 16 bar one: one crash at 112-118, on the other crash pitch when `# lanes` has two. Every 2 bars only for more energy. The keeper hit on a crash cell is deleted: the same hand plays the crash.
- Measuring phrase length: (a) bars between crashes on cell 0, (b) `# bar 5 = bar 1` means a 4 bar cycle, (c) the `# fills:` list at bars 8, 16, 24 means 8 bar phrases, (d) the `# riff` row repeating its first bar. A pushed phrase start has its crash + kick on cell 14 of the bar before and an empty cell 0 (grooves 5). Count the phrase from the bar line, not from the crash.
- Odd lengths are real (which ones a given band uses is unconfirmed): 9 bars = 8 + a one bar break, 10 = 8 + a 2 bar build or tag, 12 = 8 + 4, 6 = 4 + a 2 bar extension. Do not pad or cut them. The marker crash then sits on the first cell after the extra bars.
- Phrase ends by rank (EP 5): bar 4 takes nothing, a bark on cell 14 or a two note pickup. Bar 8 inside a section takes a 1-2 beat fill. The last bar of a section takes the 2 beat to 2 bar fill, a build or a stop (fills 4 slot table).

## 5. Energy without a tempo change
Kick and backbeat stay loud in every section (feel 2). Energy moves through which lane keeps time, the feel, how much of the kit plays and how often a crash marks time. Levers, low to high:

| lever | low to high | op | basis |
|---|---|---|---|
| keeper ladder | rung 1 tight hat (42 eighths 112/84), 2 sloshy hat (46 eighths 112/98), 3 ride (51 eighths, bell 53 quarters), 4 crash quarters (49 at 88-112), 5 crash eighths (written new only up to about 175 bpm, feel 5). China quarters only in a breakdown | `remap SEL lanes=42 to=hh_open` from bar 1 of the section, then its shape (section 10, grooves 3, feel 5) | hat verse and ride chorus [9][12], closed verse and bigger chorus [13]. Rungs 2 and 3 count as one step in every recipe: one rung up from either is the crash (grooves 3) |
| floor tom ride | tom5 43 on the even cells in place of the hat: same rate, darker, below rung 1. Prints keeper none | `remap SEL lanes=42 to=tom5`, only when `# lanes` has that tom (EP 8) | verses, intros, bridges [10][12] |
| keeper rate | quarters, eighths. Sixteenths only two handed under about 180 bpm (grooves 7) | the four `delete` lines of grooves 7 | eighths against quarters as a variation [19] |
| feel | `half` (snare cell 8), `normal` (4 12), `double` (2 6 10 14 with kick on 0 4 8 12) | snare row of one bar, then `copy ... lanes=snare`, fill bars out of `to=` | half time moves the backbeat to beat 3 and sounds half as fast, double time puts it on the "and"s [21] |
| kit size | no drums (`empty`), kick only (`open`), kick + hat with no snare, floor tom groove, full kit | `delete SEL lanes=...` by named lane | layers added across the opening sections, drums removed for a drop [14][19] |
| snare count per bar | 1 (`half`), 2, 4 (all quarters, still `normal`), 8 and 16 (a build, `blast`) | bar blocks | Misery Business ends its chorus on snare quarters and builds on the snare [8] |
| kick | row of 2-3 cells, four on the floor (0 4 8 12), chug with double pedal (easycore only) | bar block + `copy ... lanes=kick` | grooves 2 rows 3 and 6. Not a lever where the kick follows `# riff`, or where the file has no riff track (EP 21) |
| crash markers | section start only, every 4 bars, every 2 bars | bar blocks, crash1 and crash2 alternating | [12][15] |

- Half time is not "quieter": it is wider and heavier at the same level, used for a bridge, a breakdown or a chorus tag [8][22]. Pop songs put it in bridges, final choruses and drops [14]. Real double time on top of the fast beat is a 2-4 bar burst (unconfirmed how common). In a mid tempo file at 94-110 bpm a `double` section is the fast punk beat arriving, written as in notation B. From about 125 bpm it is hardcore speed (grooves 1). Moving the snare needs a feel word from him (vocabulary 3 and 4).
- Drop to kick only or to no drums: 2-8 bars with the hand rows empty. Places: first half of a bridge, a down pre-chorus (Still Into You drops to vocal and palm muted guitar there [4], 15% of the songs with a pre-chorus in one pop corpus [14]), the last bar before a chorus [2][19], the start of a last chorus. Thinning the chorus before the final one makes the ending seem larger [19].
- Stripped first half of a last chorus: its first 4 or 8 bars have no drums, or crash + kick on cell 0 and then kick only, the full kit returns on bar 5 or 9 through a fill, a one bar build or a pickup, on the highest rung of the song. In the header: a `none empty` or `none open` range followed by the chorus letter. Guides describe the device for rock and pop in general [19][22]: band by band it is unconfirmed. Recognise it, and write it only on his word (section 10).
- Arc by rung (0 = no keeper, T = floor tom): intro 0 or the chorus rung. Verse 1: 1 or T. Pre-chorus: verse + 1. Chorus: 2-4. Post chorus: chorus rung. Verse 2: 1 or T. Bridge: `half` on 3-4, or 0. Last chorus: chorus + 1, or its first half at 0. Rules that hold after any edit (vocabulary 4 item 7): one keeper per section, changed on its bar 1 (the one exception: a verse that starts on the floor tom and gets its hat later, section 8), the chorus at least one rung above the verse, the last chorus not below the first. Two neighbours at the top rung cancel: lowering the first is outside the named section, so offer it (EP 7).

## 6. Transitions
| device | grid | where | notes |
|---|---|---|---|
| fill | fills 4 and 8: bar 8 slot `beats=3-5`, keeper cleared in the span, crash + kick on the next cell 0 | every phrase end | a fill, a guitar lead or silence all serve as the join [3]. Sometimes the right fill is none [13] |
| push | crash + kick at 9 on cell 14 as a section entrance (inside a section one crash at digit 8), next cell 0 empty in crash, kick and keeper | where `# riff` has x on 14 and none on the next 0 | grooves 5. A fill before it ends on cell 13 |
| band stop | crash + kick (+ snare) on cell 0, or on the last `# riff` onset, then every drum row `-` to the bar line | last 1-4 beats before a chorus, a last chorus or a breakdown | not in `# fills:`. One silent beat, then the full speed chorus [22]. The crash rings through the gap: the map has no choke |
| one bar break | the last bar of the section before the chorus has no groove: a stab, an empty bar (`# bar N empty`), or kick only | before a chorus [2], often making a 9 bar section | resting a whole bar, out on beat 1 and back on beat 1, is a fill [11] |
| snare build | 1 bar: snare + tom5 eighths in beats 1-2, snare sixteenths in beats 3-4. 2 bars: fills 5 figure 5. Rising from 70 to a top 10 or more under the landing (EP 6), kick on the quarters, keeper out | end of a pre-chorus, end of a bridge into the last chorus | Misery Business builds with snare sixteenths out of its bridge [8]. All the Small Things bridge: snare with the foot hat on quarters, sixteenths in its last 4 bars [8]. Prints `blast` |
| snare on all quarters | snare on 0 4 8 12 with hat or crash quarters, kick on the "and"s or on the quarters | last 1-2 bars of a pre-chorus, last 2-4 bars of a chorus (the tag of section 10) or of the song | grooves P8. Crash quarters under it only when the next section does not ride the crash: a keeper cymbal never arrives before its section (EP 6) |
| guitar alone, then band in | bars 1-4 or 1-8 empty under a `# riff` row, pickup in the last 1-2 beats, crash + kick at 9 on the entry | intro, start of a bridge, start of a last chorus | Dammit opens on its guitar riff [5]. All the Small Things: guitars, then bass and drums part way through the intro [7] |
| feel switch | snare leaves 4 and 12 for 8 on the bar line, crash + kick on that cell 0 | into a bridge or breakdown, out of it into the last chorus | section 5 |

```vd
# the last 2 bars of a 4 bar pre-chorus and the chorus landing (bars 1-2: the hat opens to hh_open eighths 112/98 over four on the floor, grooves P5 bar 1). bar 3: snare on all four quarters in unison with half open hat quarters that lean on 2 and 4, kick on the "and"s (reads normal). bar 4: one bar build. the foot closes the hat and keeps time, snare + floor tom eighths 70 to 98, snare sixteenths that lean on the beat cells, the floor tom back under the last hit: its top is 112, a digit under the landing (EP 6), on the strong hand and the low drum (EP 9). kick on the quarters, the last sixteenth free so both hands reach the cymbals (reads blast). bar 5: two cymbals + kick because a section starts, then the chorus rows
bar 3 grid=16
hh_open 46  |7--- 8--- 7--- 8---|
snare 38    |8--- 9--- 8--- 9---|
kick 36     |--8- --8- --8- --8-|
bar 4 grid=16
hh_pedal 44 |6--- 5--- 5--- 5---|
snare 38    |5-6- 6-7- 7676 878-|
tom5 43     |5-6- 6-7- ---- --8-|
kick 36     |8--- 8--- 8--- 8---|
bar 5 grid=16
crash1 49   |9--- 7--- 8--- 7---|
crash2 57   |9--- ---- ---- ----|
snare 38    |---- 9--- ---- 9---|
kick 36     |9--- --8- 8-8- ----|
```
```vd
# guitar alone, then band in. bars 1-3 hold no drum notes, bar 4 answers the guitar with a 2 beat pickup: flat flam on 3, snare on its "and", two snares on 4, then the floor tom alone on the "and" of 4 as its top (112, one digit under the entry), kick on 3 and 4. bar 5 enters on crash1 + kick at 127 with the chorus keeper. the header reads bars 1-4 as none plus empty
bar 4 grid=16
snare 38   |---- ---- 7-6- 76--|
tom5 43    |---- ---- 7--- --8-|
kick 36    |---- ---- 8--- 8---|
bar 5 grid=16
crash1 49  |9--- ---- ---- ----|
hh_open 46 |--7- 8-7- 8-7- 8-7-|
snare 38   |---- 9--- ---- 9---|
kick 36    |9--- --8- 8-8- ----|
```

## 7. Drums against the other parts
- No riff track: no `# riff` row and no lock. Skip every step that reads them and say so, and count every groove kick as locked: do not move it (EP 21). A file with a guitar or bass track prints `# riff: track N` in the header: `--riff N` picks another one.
- Palm muted verse: the guitar plays muted eighths and opens to full strums in the chorus [2]. `# riff` shows the same 8 onsets either way, the mute is invisible. Under it: rung 1 or the floor tom, kick on cells 0 and 8 plus one accent, lock 25-50%, no sloshy hat (grooves 9 item 9, unconfirmed). When the guitar opens, the hat opens: the keeper change sits on that bar 1.
- Kick and bass guitar: the bass plays root eighths with the guitar rhythm, the kick marks their accents, not every note. American Idiot: the kick follows the rhythm of bass and guitar [10]. Basket Case: the kick is locked to the rhythm guitar [9]. With the bass as riff track (`--riff N`) read lock the same way (grooves 4). A verse carried by bass and drums alone keeps the kick on cells 0 and 8 plus the bass accents (unconfirmed).
- Room for the vocal: the vocal is not in the grid. Assume it in verse, pre-chorus and chorus. There: one keeper, one kick row per 2-4 bars, no crash inside the phrase except the markers of section 4, fills only at phrase ends and short [11][13], Barker devices only on request (grooves 6). Intro, post chorus riff and the instrumental half of a bridge have no vocal: the bigger fills and the fills that follow a guitar lead go there.
- Chord changes: a change that is an arrival (cell 0 of bars 1 and 5, a `# riff` onset after 2+ empty cells) takes crash + kick at 112-118, the section start 122-127. A change pulled to cell 14 is a push, to cell 6 an early beat 3 (grooves 5). Not every change gets a crash: under strummed eighths the markers of section 4 are enough.
- Gang vocal hits: group shouts on the quarters or on a short figure, in a bridge or a final chorus [2][17]. The drums go to unison with them: snare on all four quarters, or four on the floor under the plain backbeat, or one crash + kick (+ snare) per shout with the rows empty between. In the grid they show only as isolated `# riff` onsets or not at all: without a riff row, place them only where he names the cells.
- Unison stabs: `# riff` has 1-4 isolated onsets in the bar. Each gets crash + kick (+ snare) at 8-9, the last one strongest, crash1 and crash2 alternating when under a bar apart, every other row empty (fills 5 figure 9). Homorhythmic accents with the guitars are the punctuation of punk forms [15]. lock reads 75-100% there. A stab without a kick is the fault (grooves 4).

## 8. Verse two habits
Verse 2 is the verse letter returning. It keeps the kick row, the backbeat and a rung below the chorus. One difference, the first of this list that fits (EP 1). Guides ask for a change of instrument, keeper or kick pattern on the repeat [20], or layers held back early and added later [14][23]. Which habit a given band prefers is unconfirmed.
1. Keeper lane side step below the chorus rung: floor tom ride in its first half, or in verse 1 with the hat arriving later, hat to ride only when the chorus is on the crash.
2. Stripped start: its first 2-4 bars without the snare (kick + hat, reads `open` from 3 bars on) or without drums, full verse beat back on bar 5 under one crash at 112-118.
3. One more event per 2 bars: a bark on cell 14 of bars 2 and 6, one more kick on a `# riff` accent (Barker adds kick notes across a phrase, feel 6), a splash + kick in place of the bar 5 crash.
4. Another fill: no two fills of a section cell identical (fills 4), and the bar 4 pickup differs from verse 1.
5. Half the length of verse 1 (no op removes bars: recognise it, never create it). Only on a feel word: its first half in half time.

## 9. Section recogniser
Match the header fields first, then two or more grid features. The right column is inferred usage (unconfirmed). In a B file read `double` for `normal` and `normal` for `half`.

| header fields and grid features | section | words he uses |
|---|---|---|
| `none empty 0 0` from bar 1, `# bars 1-N empty`, `# riff` row has onsets | intro, guitar alone | "the intro", "before the drums come in", "the guitar bit at the start" |
| first or post chorus position, rows equal the chorus letter, 12-16 riff onsets per bar, no vocal | intro riff, post chorus riff | "the riff", "the lead part", "the intro riff", "after the chorus" |
| `hh normal`, kick/bar 2-4, only a 42 row, riff on all even cells, lock 25-50%, lowest rung, returns after chorus 1 | verse | "the verse", "under the vocals", "the palm muted part", "the quiet part" |
| `none normal`, tom5 on the even cells in most bars, snare on 4 and 12. The header lists these bars as fills: they are not (fills 3) | floor tom verse (also intro or bridge) | "the tom part", "the tom beat", "the jungle beat" |
| 4 or 8 bars before a chorus start, a 46 row appears, kick on 0 4 8 12, snare on 0 4 8 12 or a `blast` bar at its end | pre-chorus | "the pre", "the lift", "the part before the chorus", "the build" |
| `hh` with a 46 row on even cells, `ride`, or `crash1`, feel `normal`, crash + kick at 9 on its first cell, crash on cell 0 every 2-4 bars, returns 2-3 times | chorus | "the chorus", "the hook", "the big part", "the singalong" |
| feel `half` for 4-8 bars on the chorus keeper right after chorus bars, or snare on 0 4 8 12 | chorus tag | "the end of the chorus", "the half time bit", "the tag" |
| feel `half`, crash1 or ride quarters, kick/bar 2-5, occurs once after chorus 2 | half time bridge | "the bridge", "the middle eight", "the slow part", loosely "the breakdown" |
| feel `half`, china or crash1 quarters, kick/bar 5-10 with adjacent kick cells and holes of 3+, lock 85%+ | easycore breakdown | "the breakdown", "the heavy part", "the mosh part", "the chugs", "the drop" |
| keeper none or `hh` from a 44 row (it can then share the verse letter), snare on most cells with 4-6 between the 9s, taps under 60, vel under 100 | marching snare bridge | "the snare part", "the march", "the drumline bit" |
| `none open`, kick only, 3-8 bars. Or 2 kick only bars inside another letter | dropped half of a bridge, down pre-chorus | "the drop", "where it's just bass and kick", "the quiet bit" |
| `none empty` or `none open` for 2-8 bars in the last third, then the chorus letter | stripped first half of the last chorus | "the quiet chorus", "where everything drops out", "the breakdown chorus" |
| 1-2 bars, no keeper, snare hits per beat 1 then 2 then 4, digits rising, flagged `blast` or as a whole bar fill | build | "the build", "the snare roll", "the drum roll", "the ramp" |
| one bar: crash + kick on cell 0, then every row `-`, `# riff` empty there. Or `# bar N empty` | stop, one bar break | "the stop", "the break", "the pause", "where the band cuts out" |
| chorus letter, last occurrence, 12-24 bars, two cymbals on its entry, crash every 2 bars | last chorus | "the last chorus", "the final chorus", "the double chorus", "the outro chorus" |
| last section, final bar crash + kick on cell 0 then rests, or 2-4 bars of snare on 0 4 8 12 | outro | "the ending", "the outro", "the last hit" |
| feel `double` at 150+ bpm for 2-4 bars | double time burst | "the fast part", "the hardcore part" |

## 10. Song level requests as edits
Rules for every recipe below. "Fills 6" = fills.md section 6, which owns the fill rules: the lines here are what a section recipe needs of them.
- Levers by impact (EP 1, 2). A request for more on a section takes, in this order: (1) width: the keeper one rung up from the section's bar 1 (section 5), while it rides below the crash. (2) The entrance: crash + kick at full on its first cell, a second cymbal with them when the keeper already is the crash, and the fill before it rising to 10 under it (to 127 with air before the biggest entrance of the song). (3) Weight in its second half: snare on all four quarters into its closing fill (the tag), a kick under that fill. (4) Its fills brought up to the section by rank. The default is the two or three of these that have room in this file, in one script, and the report names the next one as an offer. A lever whose ops would change nothing is skipped and never reported as done.
- Direction (EP 3, 4). Bigger, biggest, build: no note in scope ends quieter, a flat part is shaped by raising its strong notes, and `ramp scale=A-B` over notes that exist has A at 1 or above. Ceiling: `# lanes` shows keeper, kick and backbeat at min = max = 127 (it is song wide: confirm the section with `show --vel`). Then levers 2 to 4 are the answer and the report says that the groove itself was at the top. Turning the "and"s of a ridden crash down 20 (feel 5, ceiling row: never the beats, the kick or the backbeat) comes only on his word after that. `diff` lists it as quieter: report it as contrast. Breathe and drop down are the mirror: notes come out, strokes do not just go soft, nothing in scope gets louder.
- Read before writing (EP 20): `show --vel` of the section, the bar before it and the bar after it. Note what sits on its cell 0 and on the cell before that, the kick cells of each bar, where its phrases start (section 4), and for each fill the span, the cell it opens on, its drums in order, pairs or alternation, the kick under it and what it lands on. The `# input` lines of a worked answer are such a reading, and every cell, level and bar of its script follows from them. Another file gives other cells: write your rows from its `show`. Never keep a block and swap the bar numbers, never treat two fills with one line.
- Scope (EP 7). "The chorus" is every occurrence, each read on its own bars. The bar before the section and the cell 0 after it are setup and landing: allowed, and named in the report. Nothing else outside it moves: a flaw there is named, not fixed.
- Fills (EP 5, 8, 9, 10, fills 4 and 6). Drums, order and note count stay. (a) No note ends under its old value. (b) The top sits on the last note, on the lowest drum of the fill, by rank: a fill into a new section, or in the last bar of the file, 10 under an entrance at 127: 117. A phrase end fill or a pickup that lands inside the section: 107 at most, and a pickup that lands on a digit 8 crash keeps its level. 127 only in a fill that ends with air: the last sixteenth cell of the bar, or more, empty in every hand row and in the kick row. (c) One rise per fill: `ramp SPAN lanes=... scale=A-B`, B = top / its level, A = 1 for a pickup and just over 1 for a longer fill. In a figure that alternates two drums the lower drum then goes 8 over its neighbours: it is the heavy voice, not the weak hand. The lean of fills 6 comes on top when he asks about the fills. (d) A fill that opens on a backbeat cell (beat 2 or 4 in `normal`, beat 3 in `half`): a real backbeat there (116 or more) is never lowered. A note there at fill level comes up to the section's backbeats only when the fill ends on 127 with air, so `diff` still shows last = peak. In every other fill it is the first stroke of the rise. (e) A fill of 2 beats or more with no kick under it gets `x` in the kick row on its beats, with a riff track on the `# riff` onsets inside the span, never three adjacent sixteenth kicks (grooves 7).
- Two cymbals (EP 6, 15): only on the first cell of a section: crash2 57, a china or a second crash with crash1. None of them has notes in `# lanes`: crash2 is a new lane, written on that cell only, say so (EP 24). Both hands travel, so the sixteenth before that cell holds no hand note: a fill that runs to the bar line gives up its last note when that drum still sounds earlier in the fill (else the fill stays whole and the entrance stays on one crash). That gap is the air of rule b.
- Ops (EP 16 to 19): notes first (bar blocks, `remap`, `delete`), then level, then gestures (`accent`, `ramp scale=`, `vel add=`). One voice = its pitch: `lanes=42`, `lanes=49`, backbeats `lanes=38 v=100-127`, ghosts `lanes=38 v=1-59`. No `humanize` in these recipes: two bars differ by design (phrase, kick, fill), never by spread.
- Cases (EP 21 to 24). No riff track: skip every step that reads `# riff` and say so, the groove kick rows stay as they are. A fill in the last bar of the file has no landing: it ends the song on its top (117), say so. A recipe lane with no notes in `# lanes`: the nearest lane that has notes, same number of voices (no floor tom: the lowest tom, no tom: the snare alone).
- Check (the acceptance tests of editing-principles.md) with `vibedrum diff ORIGINAL RESULT` and `show RESULT --vel` on the changed bars. `# sections`: the scope at the same or a higher vel or with more notes (less: fewer notes or a lower vel). `# lanes`: 0 in the last column (less: no note louder). `# fills`: last within 5 of peak for every fill touched, 10 or more between ranks, no two sequences alike. Every entrance and landing in scope 10 or more over the note before it, or after air. No `# bar N = bar M` between two bars of one occurrence when the script shaped either of them. A return may equal the first occurrence, and groove bars the script never touched fold as before: his loop, named in one line. `# bars changed`: the scope plus the bars the report names. A failed line means another script from the same starting file.
- Report: two or three lines read off the diff: what got louder, what was added or removed with counts, what changed outside the named section, what was skipped and why. Never "bigger" for a change the diff shows as quieter.

**"Make the chorus bigger."** Keeper below the crash: (1) width, by `remap` from its bar 1, the row then shaped by raising only: hat to sloshy hat with `remap SEL lanes=42 to=hh_open` and `accent SEL lanes=46 grid=16 pattern=9--- mix=0.5` (a flat 98 becomes 112 on the beats, the "and"s stay, grooves 3), a sloshy hat or a ride to the ridden crash with the script of feel 5. (2) Its second phrase starts under one crash + kick a digit under the entrance, keeper hit off that cell, and answers the first with more: its "and"s that carry a kick go 16 up (feel 5). (3) Its fills by the fills rule, the first note of a fill not under the keeper note before it (EP 14). Keeper already the crash (the ceiling case below): two cymbals on each entrance, the fill before each rising to 117 on its new last note (set up, outside the section: reported). Then the tag: snare on all four quarters from the 2 bars before the bar of its closing fill up to that fill (no closing fill: its last 2 bars), never more than its second half, the added notes two digits under the backbeats in the first bar and one digit under after it. When a second crash has notes in `# lanes`, its second half starts on it: one crash in place of the keeper hit, never a stack. Then its fills. Offers after that: the crash "and"s 20 down for contrast, the verse one rung down, a build or a stop before it (below).
```vd
# said back: chorus = bars 5-8. crash, kick and backbeats are flat at 127, so the groove cannot rise. bigger = crash2 joins crash1 + kick on its first hit and the fill before it rises to 117 and leaves the last sixteenth free (bar 4, outside the chorus), its second half starts on crash2 and drives on snare quarters, its fills come up by rank: the pickup to 107, the closing fill to 117 with a kick on its beats and the floor tom on top. 1 note goes, nothing gets quieter
# input: 180 bpm, notation A, no riff track. verse 1-4, chorus 5-8 on crash1 quarters, crash2 has notes (bar 1)
#   bar 4 fill 3-5 at 98 runs to the bar line: snare 8-11, tom5 12-15. bar 5 cell 0 = crash1 + kick at 127
#   bar 6 pickup 4-5 at 98: snare 12-13, tom2 14-15. it opens on the backbeat cell and lands on bar 7 cell 0 (crash1 + kick at 127)
#   bar 8 fill 3-5 at 98: snare on 8, 10, 12, 14, tom5 between on 9, 11, 13, 15, no kick under it. a new section follows on crash + kick at 127
# notes. entrance: tom5 on cell 15 comes out (tom5 still sounds on 12-14) so both hands reach the two cymbals
bar 4 grid=16
tom5 43    |---- ---- ---- xxx-|
bar 5 grid=16
crash2 57  |9--- ---- ---- ----|
# second half = bars 7-8: bar 7 starts on crash2 alone, snare quarters at 98 in bar 7 and at 112 in bar 8 up to its fill, kick on beats 3 and 4 under that fill
remap bars=7 beats=1-1.25 lanes=49 to=crash2
bar 7 grid=16
snare 38   |7--- x--- 7--- x---|
bar 8 grid=16
snare 38   |8--- x--- x-x- x-x-|
kick 36    |x--- --x- x--- x---|
# rises. bar 4 (set up): 98 to 117 on its new last note. bar 6 pickup: its backbeat cell stays the first stroke (it cannot end on 127), top 107. bar 8: top 117, tom5 8 over the snare: 102 111 104 113 106 115 108 117
ramp bars=4 beats=3-5 lanes=38,43 scale=1-1.19
ramp bars=6 beats=4-5 lanes=38,48 scale=1-1.09
ramp bars=8 beats=3-5 lanes=38,43 scale=1.04-1.11
vel bars=8 beats=3-5 lanes=43 add=8
```
**"Make the last chorus the biggest."** Scope: the last occurrence and the bar before it. It ends above every other chorus and never below the first. (1) Width: when the other choruses ride below the crash, this one rides the crash from its first bar (feel 5). (2) The biggest entrance of the song: two cymbals + kick, and the fill or build before it becomes the biggest fill of the song: it ends with air on its top at 127 (the two cymbal rule takes its last sixteenth, the top sits on the eighth cell before it), the lowest tom with notes and a kick under that top, its backbeat cell at full, a kick on its beats. (3) Its ending: the tag, and its closing fill by rank. Default: all three, at the ceiling 2 and 3. Only on his word ("drop out first", "a quiet first half"): the stripped first half of section 5. It removes notes, so it is never the default of a request for more.
```vd
# said back: last chorus = bars 5-8, the same rows as the other choruses and flat at 127: no rung and no level left. biggest = its entrance and its ending. the build in bar 4 gets its backbeat at full and a kick on beats 3 and 4, and rises to a 127 flam with the floor tom and a kick on the "and" of 4, the last sixteenth stays free, then crash1 + crash2 + kick. bars 7-8 drive on snare quarters and the last fill rises from 102 to 117 with a kick on its beats. 1 note of the build goes, nothing gets quieter
# input: 180 bpm, notation A, no riff track. bridge 1-4 in half time (backbeat cell 8), last chorus 5-8 on crash1 quarters, bar 5 cell 0 = crash1 + kick, no second crash in `# lanes`: crash2 is a new lane
#   bar 4: build on beats 3-5, eight snare sixteenths flat at 98 to the bar line. it opens on the backbeat cell 8. kick only on 0 and 6. tom5 has notes (bar 8)
#   bar 8 = last bar of the file: fill 3-5 at 98 in pairs (snare 8-9, tom2 10-11, tom5 12-15), no kick under it, cell 8 is no backbeat cell in this feel
# notes. entrance: the snare on cell 15 comes out, cell 8 to 9 (the build will end on 127), tom5 and kick under its last hit on cell 14, kick on beats 3 and 4
bar 4 grid=16
snare 38   |---- ---- 9xxx xxx-|
tom5 43    |---- ---- ---- --x-|
kick 36    |x--- --x- x--- x-x-|
bar 5 grid=16
crash2 57  |9--- ---- ---- ----|
# ending: the tag from bar 7, kick on the beats of the last fill
bar 7 grid=16
snare 38   |7--- x--- 7--- x---|
bar 8 grid=16
snare 38   |8--- x--- xx-- ----|
kick 36    |x--- --x- x--- x---|
# rises. the build from the note after its backbeat: 104 to 127. the last fill: last bar of the file, so 117 on the last tom5
ramp bars=4 beats=3.25-5 lanes=38,43 scale=1.06-1.3
ramp bars=8 beats=3-5 lanes=38,tom scale=1.04-1.19
```
**"The verse should breathe."** A request for less (vocabulary "more space"). (1) The keeper one step down: an open hat closes (`remap SEL lanes=46 to=hh`), a closed hat on eighths thins to quarters with the four `delete` lines below (a bar with a bark or a push on cell 14 stays out of the last one). (2) What clutters the phrase goes: ghosts (`delete SEL lanes=38 v=1-59`, fill bars left out), barks, splash and bell rows, a crash inside the phrase (the section start stays), and a pickup inside the phrase thins to its first note and the "and" after it. (3) What is left of the keeper is shaped downward over the phrase: it relaxes from bar 1 to the bar before the lift (`ramp ... scale=1-0.82`, or only down to 100 / their level when the backbeat quarters are shoulders of 100 or more: they stay shoulders, EP 13), the last bar before the closing fill and the fill bar keep his level as the lift, and the quarters that do not fall with the backbeat sit 16 under those that do. Default: all three. The kick stays. With a riff track, kicks with no riff x under them (cells 0 and 8 excepted) go only on "more". On his word: floor tom ride, the first 4 bars without snare, half time.
```vd
# said back: verse = bars 1-8. breathe = the ghosts go, the hat thins from eighths to quarters, the quarters relax from 112 to about 101 over bars 1-6 and come back for the lift in bar 7, the ones with the kick sit 16 under the ones with the backbeat. kick, backbeats, the bar 8 fill and the bar 1 crash stay. nothing gets louder
# input: feel normal, so the backbeat quarters are beats 2 and 4 and the others beats 1 and 3 (kick on cells 0, 8, 10 in every bar). hh 42 eighths at 112/84, ghosts at 42 on cells 7 and 15 of bars 1-7, no pickup in bar 4, fill 8:3-5: the lift is bars 7-8 and bar 8 stays out of the ghost delete. no riff track
delete bars=1-7 lanes=38 v=1-59
delete bars=1-8 beats=1.5-2 lanes=42
delete bars=1-8 beats=2.5-3 lanes=42
delete bars=1-8 beats=3.5-4 lanes=42
delete bars=1-8 beats=4.5-5 lanes=42
# the quarters left are shoulders at 112: 0.9 keeps the backbeat ones at 100 or more
ramp bars=1-6 lanes=42 scale=1-0.9
vel bars=1-8 beats=1-1.25 lanes=42 add=-16
vel bars=1-8 beats=3-3.25 lanes=42 add=-16
```
**"Build into the chorus."** A request for more, on the last bar before each chorus. (1) A bar that is plain groove or ends in a fill becomes a one bar build: keeper row cleared, snare + the lowest tom with notes once on beat 1 and twice on beat 2, snare sixteenths from beat 3, existing backbeats and fill notes kept with `x`, `x` in the kick row on every quarter. New notes sit at or under the level of the tail (digits 6 and 7 under a tail at 98), never under the ghost wall of 60 (EP 13). (2) The tail rises to its top 10 under the entrance: `ramp ... scale=1-B`, B = (entrance - 10) / its level. (3) A build that is already there is shaped, not rewritten: a kick on its beats, the tom under its eighths, the rise. The build into the last chorus is the bigger one: it ends with air on 127 as in the recipe above (last sixteenth out, backbeat cell at full, tom and kick under the top). Default: all of it. On "long": 2 bars, the first one on snare quarters (bar 3 of the section 6 block, fills 5 figure 5). Above about 210 bpm sixteenths become eighths (fills 4). A stop that is already there stays silent. Afterwards the header reads the bar as a whole bar fill or as `blast`: expected.
```vd
# said back: the bar before the chorus (bar 4) becomes a one bar build. hat out, snare + tom2 once on beat 1 and twice on beat 2 (the backbeat stays), snare sixteenths on beat 3, then the fill that was there, kick on every quarter. it rises from 98 to 117 on the last tom2, 10 under the chorus crash. nothing gets quieter
# input: 180 bpm, notation A. chorus from bar 5 on crash1 + kick at 127, no air. bar 4: hat eighths on beats 1-3, backbeat on cell 4, kick on 0, 6, 8, fill 4-5 at 98 (snare 12-13, tom2 14-15). tom2 is the lowest tom with notes
bar 4 grid=16
hh 42      |---- ---- ---- ----|
snare 38   |6--- x-7- 7777 xx--|
tom2 48    |6--- 7-7- ---- --xx|
kick 36    |x--- x-x- x--- x---|
ramp bars=4 beats=3-5 lanes=38,48 scale=1-1.19
```
**"The bridge should drop down."** A request for less: the feel halves or the kit thins, strokes do not go soft. (1) Bridge reads `normal`: half time, the worked answer "make the bridge half time" of vocabulary 7. (2) Bridge already `half`: its first half (4 bars at most, never the bar that holds its fill or build) goes to kick only: keeper and snare out by pitch, the opening crash + kick ring. The groove returns under one crash a digit below the section start, in place of the keeper hit on that cell: the one note added, said in the report. A crash keeper has that hit already: spare its first hit with `beats=1.25-5` in the delete of bar 1. (3) On his word: no drums for 2-4 bars (riff kicks go: count them), or the keeper down inside `half` (crash quarters to ride bell or half open hat quarters). Offer after it: the build of the recipe above in its last bar. A 2 bar drop prints inside the letter before it, 3 bars or more as `none open`: expected. Kick only bars fold in `show` when his kick row repeats: that loop is his, say so.
```vd
# said back: bridge = bars 1-8, already half time, so dropping down = its first 4 bars go to kick only under the ringing first crash, and the groove returns on bar 5 under one crash at 112. kick row and the bar 8 fill untouched. 20 notes go, 1 is added, nothing gets louder
# input: feel half (snare on cell 8), keeper hh_open quarters at 98, crash1 + kick at 127 on bar 1 cell 0 with no hat on that cell, kick on 0, 6, 12, fill 8:3-5 into the last chorus: the first half is bars 1-4. no riff track: the kicks stay
delete bars=1-4 lanes=46,38
delete bars=5 beats=1-1.25 lanes=46
bar 5 grid=16
crash1 49  |8--- ---- ---- ----|
```
**"Make the second verse different from the first."** Not more and not less: kick row and backbeat stay, the level stays about where it was, one thing changes in the hands: the first habit of section 8 that fits. Floor tom only when `# lanes` has that tom (EP 8), otherwise habit 2 or 3. After the `remap` a flat row gets its beats raised (`accent SEL lanes=43 grid=16 pattern=9--- mix=0.5`), a row with two levels its tips (`vel SEL lanes=43 v=60-99 add=14`): toms sit at 112/98. Never the chorus keeper, never a rung above the chorus. The header then lists those bars as fill candidates: expected (fills 3). Bars that were equal before the side step are equal after it: his loop, say so.
```vd
# said back: verse 2 = bars 5-8, a repeat of verse 1. different = its first 2 bars ride the floor tom instead of the hat (same eighths, same hand), the hat returns on bar 7 under one crash a digit below the section start. kick, backbeats and verse 1 untouched
# input: hh 42 eighths at 112/84, show printed "# bar 5 = bar 1", crash1 + kick at 127 on bar 5 cell 0, a kick on bar 7 cell 0, tom5 notes in `# lanes` (the bar 4 pickup). the last tom of bar 6 ends at 98, so the crash at 112 stands 14 over it
remap bars=5-6 lanes=42 to=tom5
vel bars=5-6 lanes=43 v=60-99 add=14
delete bars=7 beats=1-1.25 lanes=42
bar 7 grid=16
crash1 49  |8--- ---- ---- ----|
```
**"Add a stop before the chorus."** Air is the lever. Scope: the last bar before every chorus, the one before the last chorus the longest. One crash + kick stab on cell 0 (crash at 8, on a crash the next section does not ride when the kit has two), every other row of the bar `-` up to the pickup, then the chorus crash. A bar that holds a fill keeps it whole as the pickup, and the fill rises to 10 under the entrance. Before the last chorus the fill is cut from the front to its last beat. A plain bar gets a two note pickup, `snare 38 |---- ---- ---- 7-8-|`: the groove has stopped, so the note on beat 4 is a pickup note, not a backbeat. `# riff` has an x on cell 14 and none on the next cell 0: the stop ends on the push, crash + snare + kick on cell 14 and the next cell 0 cleared (grooves 5). `# riff` strumming through the bar, or no riff track: it is a drums only drop out, say so, and count the kicks that went. On "more": the whole bar silent, or stabs on 1, 2 and 3 (fills 5).
```vd
# said back: a stop in the bar before the chorus (bar 4): one crash + kick stab on beat 1, silence, then the fill that was there as the pickup, rising from 98 to 117 on the floor tom, 10 under the chorus crash. the hats, the backbeat on 2 and 2 kicks of bar 4 go. no riff track, so this is a drums only drop out
# input: chorus from bar 5 on hh_open with crash1 + kick at 127. bar 4: hat eighths on beats 1-2, backbeat on cell 4, kick on 0, 6, 8, fill 3-5 at 98 (snare 8 and 10, tom1 12-13, tom5 14-15), cell 8 is no backbeat cell
bar 4 grid=16
crash1 49  |8--- ---- ---- ----|
hh 42      |---- ---- ---- ----|
snare 38   |---- ---- x-x- ----|
kick 36    |x--- ---- ---- ----|
ramp bars=4 beats=3-5 lanes=38,tom scale=1-1.19
```

## Sources
Unconfirmed (working defaults of this document): section lengths other than those cited, chord cycle and odd section lengths, the post chorus as the intro riff, verse 2 at half length, the half time chorus, how common the stripped last chorus and real double time are in these bands, the arc by rung, the vel ranges (read from the canonical bars with this engine), the user words of section 9, which verse 2 habit a band prefers, the tag as a default lever at the ceiling, and every velocity and scale number of section 10 (tops 107, 117 and 127, the lean of 16, the relax to 0.82, the scales): chosen to pass the acceptance tests of editing-principles.md, each worked script checked with `diff` and `show --vel` on a file built from its `# input` lines. No usable source was found for the arrangement habits of Sum 41, The Offspring, Yellowcard, Fall Out Boy, All Time Low, Simple Plan, Good Charlotte, The Story So Far, Neck Deep, State Champs, The Wonder Years, Knuckle Puck or Four Year Strong song by song: nothing here is attributed to them. Not retrievable (truncated or blocked): MusicRadar (Rian Dawson, Alex Shelnutt, Anatomy of an arrangement), Point Blank. Engine behaviour was read from `core/vibedrum.cpp` and checked on test songs: recheck it if the engine changes.
1. Wikipedia, Song structure. https://en.wikipedia.org/wiki/Song_structure
2. Lyric Assistant, How to Write Pop Punk Songs. https://lyricassistant.com/how-to-write-pop-punk-songs/
3. Riffhard, How to Write Pop Punk Guitar. https://www.riffhard.com/how-to-write-pop-punk-guitar/
4. Composer Code, Song Structure. https://composercode.com/song-structure/
5. Wikipedia, Dammit. https://en.wikipedia.org/wiki/Dammit
6. Wikipedia, All the Small Things. https://en.wikipedia.org/wiki/All_the_Small_Things
7. Blake Grosskreutz, All The Small Things structural map. https://blakegrosskreutz.wordpress.com/2016/05/12/blink-182-all-the-small-things-structural-map/
8. Melodics, All The Small Things and Misery Business on drums, search excerpts only (bridge and chorus descriptions). https://melodics.com/learn-to-play/all-the-small-things-by-blink-182-on-drums and https://melodics.com/learn-to-play/misery-business-by-paramore-on-drums
9. The Drum Ninja, Basket Case and All the Small Things transcriptions. https://thedrumninja.com/basket-case-drum-transcription-by-greenday/ and https://thedrumninja.com/all-the-small-things-drum-transcription/
10. Drumeo, A Drummer's Guide To Punk. https://www.drumeo.com/beat/a-drummers-guide-to-punk/
11. Drumeo, common rock drum fills. https://www.drumeo.com/beat/common-rock-drum-fills/
12. Drumhead Authority, Tre Cool. https://drumheadauthority.com/articles/tre-cool/
13. Drummerworld, Song Structure as a Drummer. https://www.drummerworld.com/articles/news/song-structure-for-drummers/
14. Geary, Formal Functions of Drum Patterns in Post-Millennial Pop Songs, Music Theory Online 30.2 (100 song pop corpus, not pop punk). https://mtosmt.org/issues/mto.24.30.2/mto.24.30.2.geary.html
15. Pearson, Extreme Hardcore Punk and the Analytical Challenges of Rhythm, Riffs, and Timbre, Music Theory Online 25.1. https://mtosmt.org/issues/mto.19.25.1/mto.19.25.1.pearson.html
16. Wikipedia, Breakdown (music). https://en.wikipedia.org/wiki/Breakdown_(music)
17. Melodigging, Easycore. https://www.melodigging.com/genre/easycore
18. Toontrack, Pop Punk MIDI. https://www.toontrack.com/product/pop-punk-midi/
19. Passive Promotion, The Death of the Bridge. https://passivepromotion.com/the-death-of-the-bridge/
20. Home Recording forum, How to make second verse and chorus different than the first. https://homerecording.com/bbs/threads/how-to-make-second-verse-and-chorus-different-than-the-first.382760/
21. Wikipedia, Half-time (music). https://en.wikipedia.org/wiki/Half-time_(music)
22. Search excerpts only, pages blocked: https://eathealthy365.com/your-ultimate-guide-to-writing-an-authentic-pop-punk-song/ (half time bridge, one silent beat before the chorus), https://tvtropes.org/pmwiki/pmwiki.php/Main/SubduedSection (instruments dropping out under the last chorus), https://www.iamtunedup.com/relevant-discoveries-the-easycore-edition/ (easycore formula)
23. Ashbea Music, The Art of Arranging Pop and Rock Songs. https://www.ashbeamusic.com/blog/the-art-of-arranging-pop-and-rock-songs-a-guide-for-musicians
