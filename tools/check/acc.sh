#!/bin/bash
# usage: acc.sh <by> <FUN> <file.c> "<summary>" [flags]   (leon2m)  verify jf+rawcmp, accept, commit
set -e
cd "$(dirname "$0")/../.."
by=$1; f=$2; c=$3; sum=$4; fl=${5:--mcpu=v8 -O3 -g}
# an already matched function is only re-accepted on purpose (REACCEPT=1, e.g. a source correction)
if [ -z "$REACCEPT" ] && python3 -I -c "import json,sys; d=json.load(open('symbols/leon2m.json'))['functions']; sys.exit(0 if any(v.get('name')==sys.argv[1] and v.get('status')=='matched' for v in d.values()) else 1)" "$f"; then
  echo "ALREADY MATCHED: $f (set REACCEPT=1 only for a deliberate source correction)"; exit 1; fi
r=$(grep -m1 -o '0x[0-9a-f]*-0x[0-9a-f]*' asm/leon2m/$f.s); lo=${r%-*}; hi=${r#*-}
j=$(nice -n 19 python3 -I tools/check/jf.py leon2m $f $c "$fl" 0); echo "jf: $j"
rc=$(nice -n 19 python3 -I tools/check/rawcmp.py $f $c "$fl" ${lo#0x} ${hi#0x} | tail -1); echo "raw: $rc"
case "$j" in "100.00 match=True"*) ;; *) echo "NOT EXACT (jf)"; exit 1;; esac
case "$rc" in *"mismatches 0;"*|*"mismatches 0") ;; *) echo "NOT EXACT (rawcmp)"; exit 1;; esac
grep -q "$f" $c || { echo "fn name missing in file"; exit 1; }
python3 -I tools/handaccept.py leon2m $by $f $c "$sum" | tail -1
p=$(python3 -I tools/srcpath.py leon2m $f | head -n 1)   # the source file of $f (tools/srcpath.py)
git add $p symbols/leon2m.json
git commit -q -m "leon2m $f byte-exact ($by): $sum" -- $p symbols/leon2m.json
git log --oneline -1
