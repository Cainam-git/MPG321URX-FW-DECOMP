#!/usr/bin/env python3
"""Find unmatched functions where Ghidra glued a second routine onto the end (code after a return
or a tail call that no branch of the function reaches) and record the split addresses in
symbols/<cpu>.splits.json (tracked; applied by ghidra/SplitFunctions.java, also in decompile.sh).
usage: splits.py <cpu>"""

def glued(path):
    rows=[]
    for l in open(path).read().splitlines()[1:]:
        m=re.match(r'^([0-9a-f]+):\s+(?:[0-9a-f]{2} ){4}\s*(.*)$',l)
        if m: rows.append((int(m.group(1),16),m.group(2).split('!')[0].strip()))
    targets={int(t,16) for _,i in rows for t in re.findall(r'^(?:b\w*|fb\w*)(?:,a)?\s+0x([0-9a-f]+)',i)}
    for k in range(len(rows)-2):
        a,i=rows[k]; nxt=rows[k+1][1]
        end = i in ('ret','retl') or (i.startswith('call') and nxt.startswith('restore'))
        if not end: continue
        j=k+2
        while j<len(rows) and rows[j][1]=='nop': j+=1
        if j>=len(rows)-1: continue
        split=rows[j][0]
        if any(t>=split for t in targets): continue      # the function itself jumps there
        return split
    return None
import re, glob, json, sys, pathlib
ROOT = pathlib.Path(__file__).resolve().parent.parent
if __name__=='__main__':
    cpu = sys.argv[1]
    done = {v['name'] for v in json.loads((ROOT / f'symbols/{cpu}.json').read_text())['functions'].values() if v.get('status') == 'matched'}
    starts = {f['name']: f['start'] for f in json.loads((ROOT / f'symbols/{cpu}.functions.json').read_text())['functions']}
    sp = ROOT / f'symbols/{cpu}.splits.json'
    out = json.loads(sp.read_text()) if sp.exists() else {}
    byaddr = {f"{v:08x}": k for k, v in starts.items()}
    pruned = [k for k in out if byaddr.get(k) in done]   # matched since: their range is proven, never split them
    for k in pruned: del out[k]
    if pruned: print(f"{cpu}: dropped {len(pruned)} splits of functions matched since")
    new = 0
    for p in sorted(glob.glob(str(ROOT / f'asm/{cpu}/*.s'))):
        fn = pathlib.Path(p).stem
        if fn in done or fn not in starts: continue
        s = glued(p)
        if s and f"{s:08x}" not in out.values():
            out[f"{starts[fn]:08x}"] = f"{s:08x}"; new += 1
    sp.write_text(json.dumps(out, indent=1, sort_keys=True))
    print(f"{cpu}: {new} new splits, {len(out)} total")
