#!/bin/bash
# Re-run Ghidra on the 8051 code banks with tools/ghidra/Returning.java (see there); same pipeline as decompile.sh.
# usage: tools/reanalyze8051.sh [bank ...]      default: 8051_bank0 8051_bank1 8051_bank2
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"; GH="${GHIDRA_HOME:-/opt/ghidra}"
PARTS="$ROOT/parts"; PROJ="$ROOT/ghidra_proj"; OUT="$ROOT/decomp"; SCR="$ROOT/tools/ghidra"; SYM="$ROOT/symbols"
for name in "${@:-8051_bank0 8051_bank1 8051_bank2}"; do for name in $name; do
  "$GH/support/analyzeHeadless" "$PROJ" fw -overwrite \
    -import "$PARTS/$name.bin" -processor 8051:BE:16:default -loader BinaryLoader -loader-baseAddr CODE:0x0000 \
    -scriptPath "$SCR" -preScript Returning.java -preScript Seed.java \
    -postScript NameFromStrings.java "$SYM/$name.auto.json" \
    -postScript ImportSymbols.java "$SYM/$name.auto.json" "$SYM/$name.json" \
    -postScript SplitFunctions.java "$SYM/$name.splits.json" \
    -postScript MergeFunctions.java "$SYM/$name.merges.json" \
    -postScript ApplySignatures.java "$SYM/$name.sigs.json" \
    -postScript ExportFunctions.java "$SYM/$name.functions.json" \
    -postScript ExportC.java "$OUT/$name.c" "$OUT/$name.lst" \
    -max-cpu "$(nproc)" > "$OUT/$name.log" 2>&1
  echo "$(date '+%H:%M:%S') done $name: $(python3 -c "import json;print(len(json.load(open('$SYM/$name.functions.json'))['functions']))") functions"
done; done
