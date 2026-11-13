#!/bin/bash
# Linked build of a LEON section: inventory -> link view -> symbol addresses -> assembly and library objects ->
# link with every piece at its FW.021 address and comparison with the firmware. usage: tools/link/build.sh [leon2m]
cd "$(dirname "$0")/../.." || exit 1
sec=${1:-leon2m}
python3 -I tools/link/inventory.py "$sec" --jobs 8 | tail -1
python3 -I tools/link/linkview.py "$sec" --jobs 8 | head -1
python3 -I tools/link/symtab.py "$sec" | head -2
python3 -I tools/link/extra.py "$sec" | tail -2
python3 -I tools/link/gen.py "$sec" | tail -6
