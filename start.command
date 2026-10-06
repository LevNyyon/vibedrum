#!/bin/sh
# Double click this in Finder: it opens Terminal and runs start.sh (Finder opens .sh files in a text editor instead).
cd "$(dirname "$0")" && exec sh start.sh
