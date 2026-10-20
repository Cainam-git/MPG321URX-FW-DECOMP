#!/bin/bash
# usage: acc.sh <by> <FUN> <file.c> "<summary>" [flags]   (leon2m)  verify jf+rawcmp, accept, commit
set -e
cd "$(dirname "$0")/../.."
by=$1; f=$2; c=$3; sum=$4; fl=${5:--mcpu=v8 -O3 -g}
r=$(grep -m1 -o '0x[0-9a-f]*-0x[0-9a-f]*' asm/leon2m/$f.s); lo=${r%-*}; hi=${r#*-}
j=$(nice -n 19 python3 -I tools/check/jf.py leon2m $f $c "$fl" 0); echo "jf: $j"
rc=$(nice -n 19 python3 -I tools/check/rawcmp.py $f $c "$fl" ${lo#0x} ${hi#0x} | tail -1); echo "raw: $rc"
case "$j" in "100.00 match=True"*) ;; *) echo "NOT EXACT (jf)"; exit 1;; esac
case "$rc" in *"mismatches 0;"*|*"mismatches 0") ;; *) echo "NOT EXACT (rawcmp)"; exit 1;; esac
grep -q "$f" $c || { echo "fn name missing in file"; exit 1; }
python3 -I tools/handaccept.py leon2m $by $f $c "$sum" | tail -1
git add src/leon2m/$f.c symbols/leon2m.json
git commit -q -m "leon2m $f byte-exact ($by): $sum"
git log --oneline -1
