#!/bin/sh
# vibedrum: build the engine if needed, start the page, open it. Safe to run twice. Stop it with Ctrl+C.
# Run it as: sh start.sh
cd "$(dirname "$0")" || exit 1
URL=http://localhost:8790

if curl -fs "$URL/api/state" >/dev/null 2>&1; then
  echo "vibedrum is already running at $URL"
  open "$URL" 2>/dev/null
  exit 0
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

(sleep 1; open "$URL" 2>/dev/null) &
echo "Press Ctrl+C to stop."
exec python3 ui/server.py
