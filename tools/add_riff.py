#!/usr/bin/env python3
"""Add a guitar track to a drum MIDI so the riff row and the lock number have something to show.
The riff follows the kick: every kick is a chug, except every 9th (left out), plus one chug per bar the kick does not play.
Usage: add_riff.py in.mid out.mid"""
import json, os, struct, subprocess, sys

src, dst = sys.argv[1], sys.argv[2]
vd = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "build", "vibedrum")
song = json.loads(subprocess.run([vd, "json", src], capture_output=True, text=True, check=True).stdout)
kick = {p for p, name in song["rows"] if name.startswith("kick")}
ticks = sorted({t for t, _, p, _ in song["notes"] if p in kick})
riff = {t for i, t in enumerate(ticks) if i % 9 != 8}
for start, length, _, _ in song["bars"]:
    extra = start + length // 8 * 3   # the "and" of beat 2 in 4/4
    riff.add(extra)

def var(n):
    out = [n & 0x7F]
    while n >> 7:
        n >>= 7
        out.append(n & 0x7F | 0x80)
    return bytes(reversed(out))

events = sorted([(t, 1, bytes([0x90, 40, 100])) for t in riff] + [(t + 60, 0, bytes([0x80, 40, 0])) for t in riff])
body, now = b"\x00\xff\x03\x06Guitar", 0
for t, _, msg in events:
    body += var(t - now) + msg
    now = t
body += b"\x00\xff\x2f\x00"
data = bytearray(open(src, "rb").read())
assert data[8:10] == b"\x00\x01", "needs a format 1 file"
data[10:12] = struct.pack(">H", struct.unpack(">H", data[10:12])[0] + 1)
open(dst, "wb").write(bytes(data) + b"MTrk" + struct.pack(">I", len(body)) + body)
