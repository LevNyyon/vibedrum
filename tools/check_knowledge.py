#!/usr/bin/env python3
"""Apply every ```vd block of the given markdown files to an empty 8 bar 4/4 song.
Prints each rejected block with the engine's error. Exit 1 if any block is rejected."""
import os, re, subprocess, sys, tempfile

vd = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "build", "vibedrum")
bad = total = 0
with tempfile.TemporaryDirectory() as tmp:
    mid, out = os.path.join(tmp, "empty.mid"), os.path.join(tmp, "out.mid")
    subprocess.run([vd, "new", mid, "--bars", "8"], check=True)
    for path in sys.argv[1:]:
        text = open(path).read()
        for m in re.finditer(r"^```vd\n(.*?)^```", text, re.S | re.M):
            total += 1
            r = subprocess.run([vd, "apply", mid, "-", "-o", out], input=m.group(1), capture_output=True, text=True)
            if r.returncode:
                bad += 1
                print(f"{path}:{text[:m.start()].count(chr(10)) + 2} {r.stderr.strip()}")
print(f"{total} vd blocks, {bad} rejected")
sys.exit(1 if bad else 0)
