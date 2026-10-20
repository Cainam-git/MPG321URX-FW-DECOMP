#!/bin/bash
# usage: acc2s.sh <by> <FUN> <file.c> "<summary>"   (leon2s, -mcpu=v8 -Os -g) verify jf + rawcmp_l2s over the asm header range, accept, commit
cd "$(dirname "$0")/../.." || exit 1
by=$1; f=$2; c=$3; s=$4; fl='-mcpu=v8 -Os -g'
rng=$(head -n 1 asm/leon2s/$f.s | grep -o '0xa0[0-9a-f]*-0x[0-9a-f]*'); lo=${rng%-*}; hi=${rng#*-}
j=$(nice -n 19 python3 -I tools/check/jf.py leon2s $f $c "$fl" 0); echo "jf: $j"
rc=$(nice -n 19 python3 -I tools/check/rawcmp_l2s.py $f $c "$fl" ${lo#0x} ${hi#0x} | tail -1); echo "raw: $rc"
case "$j" in "100.00 match=True"*) ;; *) echo "NOT EXACT (jf)"; exit 1;; esac
case "$rc" in *"mismatches 0;"*|*"mismatches 0") ;; *) echo "NOT EXACT (rawcmp)"; exit 1;; esac
nice -n 19 python3 -I tools/handaccept.py leon2s $by $f $c "$s" || exit 1
git add src/leon2s/$f.c symbols/leon2s.json && git commit -qm "leon2s $f byte-exact ($by): $s" && git log --oneline -1
