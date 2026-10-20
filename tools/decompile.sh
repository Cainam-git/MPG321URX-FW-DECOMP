#!/usr/bin/env bash
# Regenerate decomp/ from the firmware with Ghidra headless (package: ghidra, /opt/ghidra).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
FW="${1:-$ROOT/firmware/MSI_MPG321URX_V021_7F69.bin}"
GH="${GHIDRA_HOME:-/opt/ghidra}"
PARTS="$ROOT/parts"; PROJ="$ROOT/ghidra_proj"; OUT="$ROOT/decomp"; SCR="$ROOT/tools/ghidra"; SYM="$ROOT/symbols"
mkdir -p "$PARTS" "$PROJ" "$OUT" "$SYM"
python3 -I "$ROOT/tools/split.py" "$FW" "$PARTS"

run() {  # name language base [prescript args...]
  local name=$1 lang=$2 base=$3; shift 3
  local pre=()
  pre=(-preScript Seed.java)
  [ $# -gt 0 ] && pre=(-preScript AddBlocks.java "$@" -preScript Seed.java)
  "$GH/support/analyzeHeadless" "$PROJ" fw -overwrite \
    -import "$PARTS/$name.bin" -processor "$lang" -loader BinaryLoader -loader-baseAddr "$base" \
    -scriptPath "$SCR" "${pre[@]}" \
    -postScript NameFromStrings.java "$SYM/$name.auto.json" \
    -postScript ImportSymbols.java "$SYM/$name.auto.json" "$SYM/$name.json" \
    -postScript SplitFunctions.java "$SYM/$name.splits.json" \
    -postScript ApplySignatures.java "$SYM/$name.sigs.json" \
    -postScript ExportFunctions.java "$SYM/$name.functions.json" \
    -postScript ExportC.java "$OUT/$name.c" "$OUT/$name.lst" \
    -max-cpu "$(nproc)" > "$OUT/$name.log" 2>&1
  echo "done $name -> $OUT/$name.c"
}

run 8051_bank0 8051:BE:16:default CODE:0x0000
run 8051_bank1 8051:BE:16:default CODE:0x0000
run 8051_bank2 8051:BE:16:default CODE:0x0000
run 8051_bank3 8051:BE:16:default CODE:0x0000
run leon2s     sparc:BE:32:default 0xA0060000
run leon2m     sparc:BE:32:default 0xA0028000 "osd:$PARTS/osd_data.bin:0xA0168000" "data:$PARTS/leon2m_data.bin:0xA01D8000"
