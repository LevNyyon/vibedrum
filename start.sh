#!/bin/sh
# vibedrum: build the engine if needed, start the page, open it. Safe to run twice. Stop it with Ctrl+C.
# Run it as: sh start.sh   (in Finder: double click start.command)
cd "$(dirname "$0")" || exit 1
HERE=$(pwd -P)
URL=http://localhost:${VIBEDRUM_PORT:-8790}

# Does anything answer on the port, and is it the page server of THIS folder?
answers() { curl -s -m 3 -o /dev/null "$URL/api/state" 2>/dev/null; }
ours() { curl -s -m 3 "$URL/api/state" 2>/dev/null | grep -qF "\"root\": \"$HERE\""; }

if answers; then
  if ours; then
    echo "vibedrum is already running at $URL"
    open "$URL" 2>/dev/null
    exit 0
  fi
  echo "Something else is using $URL: another program, or another copy of the vibedrum folder."
  echo "Quit that program, or stop the other copy (Ctrl+C in its window), then run this again."
  exit 1
fi

if [ ! -x build/vibedrum ] || [ -n "$(find core cli -type f -newer build/vibedrum)" ]; then
  FW=""
  if [ "$(uname)" = Darwin ]; then
    FW="-framework AudioToolbox -framework CoreFoundation"
    if ! xcode-select -p >/dev/null 2>&1; then
      echo "vibedrum needs Apple's free developer tools. An install window is opening."
      echo "Click Install, wait for it to finish, then run this again."
      xcode-select --install
      exit 1
    fi
  fi
  echo "Building vibedrum (first run only, about half a minute)..."
  mkdir -p build
  clang++ -std=c++17 -O2 -Icore core/vibedrum.cpp cli/main.cpp $FW -o build/vibedrum || exit 1
  ./build/vibedrum selfcheck || exit 1
fi

# Open the page only once our own server answers, so a failed start never opens somebody else's page.
(for _ in 1 2 3 4 5 6 7 8 9 10; do sleep 1; ours && { open "$URL" 2>/dev/null; break; }; done) &
echo "Press Ctrl+C to stop."
exec python3 ui/server.py
