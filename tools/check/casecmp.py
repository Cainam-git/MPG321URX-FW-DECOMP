# Check: compare each switch case body of FUN_a008454c with the firmware's, via both jump tables (layout-blind).
# usage: casecmp.py file.c [flags] [case,case,...]
import sys, re, struct, subprocess, tempfile, pathlib
sys.path.insert(0, 'tools'); import near, exact
src = sys.argv[1]; fl = sys.argv[2] if len(sys.argv) > 2 else '-mcpu=v8 -O3 -g'
want = {int(x) for x in sys.argv[3].split(',')} if len(sys.argv) > 3 else None
FN, LO, HI, TAB, N = 'FUN_a008454c', 0xa008454c, 0xa0085984, 0xA0080204, 63
fw = open('firmware/MSI_MPG321URX_V021_7F69.bin', 'rb').read()
fwt = [struct.unpack('>I', fw[TAB - 0x9FF58000 + 4*i:TAB - 0x9FF58000 + 4*i + 4])[0] + 0xA0060000 for i in range(N)]
def dis(blob, vma):
    p = pathlib.Path(tempfile.mktemp()); p.write_bytes(blob)
    out = subprocess.run([exact.tool('objdump'), '-D', '-b', 'binary', '-m', 'sparc', '-EB', f'--adjust-vma={vma:#x}', str(p)], capture_output=True, text=True).stdout
    rows = []
    for l in out.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\s+(?:[0-9a-f]{2} ){4}\s*(.*)$', l)
        if m: rows.append((int(m[1], 16), m[2].split('!')[0].strip()))
    return rows
norm = lambda s: re.sub(r'\[ R \+ 0x[0-9a-f]{3,} \]', '[ R ]', re.sub(r'%hi\([^)]*\)', '%hi(X)', re.sub(r'0x[0-9a-f]{5,}', 'ADDR', re.sub(r'%[golif][0-7]|%sp|%fp', 'R', s))))
def bodies(starts, rows, hi):
    order = sorted(set(starts)); res = {}
    for i, n in enumerate(starts):
        a = n; b = next((x for x in order if x > a), hi)
        res[i] = [norm(t) for addr, t in rows if a <= addr < b]
    return res
T = bodies(fwt, dis(fw[LO - 0x9FF58000:HI - 0x9FF58000], LO), HI)
with tempfile.TemporaryDirectory() as td:
    o = pathlib.Path(td) / 'x.o'
    subprocess.run([str(near.GCC), *fl.split(), '-w', '-c', src, '-o', str(o)], check=True)
    b = pathlib.Path(td) / 't.bin'; subprocess.run([exact.tool('objcopy'), '-O', 'binary', '-j', '.text', str(o), str(b)], check=True)
    code = b.read_bytes()
    nm = subprocess.run([exact.tool('nm'), str(o)], capture_output=True, text=True).stdout
    off = int(re.search(r'^([0-9a-f]+) T ' + FN + '$', nm, re.M)[1], 16)
    rel = subprocess.run([exact.tool('readelf'), '-rW', str(o)], capture_output=True, text=True).stdout
    ent = []
    sect = None
    for l in rel.splitlines():
        h = re.search(r"Relocation section '\.rela(\S+)'", l)
        if h: sect = h[1]; continue
        r = re.search(r'([0-9a-f]{8})\s+[0-9a-f]{8}\s+R_SPARC_32\s+[0-9a-f]+\s+\+?\.text\s*\+\s*([0-9a-f]+)', l)
        if r: ent.append((int(r[1], 16), int(r[2], 16)))
    ent.sort()
    # group consecutive relocated words into tables; pick the table of N entries whose bodies fit the target best
    tabs, cur = [], []
    for k, (o_, t_) in enumerate(ent):
        if cur and o_ != cur[-1][0] + 4: tabs.append(cur); cur = []
        cur.append((o_, t_))
    if cur: tabs.append(cur)
    rows_o = dis(code[off:], LO); hi_o = LO + len(code) - off
    import difflib as _d
    best = None
    for tb in tabs:
        if len(tb) != N: continue
        cand = bodies([t - off + LO for _, t in tb], rows_o, hi_o)
        sc = sum(_d.SequenceMatcher(None, T[c], cand.get(c, []), autojunk=False).ratio() for c in range(N))
        if best is None or sc > best[0]: best = (sc, cand)
    O = best[1] if best else {}
import difflib
bad = 0
for c in range(N):
    if want and c not in want: continue
    if fwt[c] == fwt[0] and c != 0: continue
    t, ob = T[c], O.get(c, [])
    if t != ob:
        bad += 1
        sm = difflib.SequenceMatcher(None, t, ob, autojunk=False)
        print(f'case {c}: target {len(t)} ours {len(ob)} ratio {sm.ratio():.2f}')
        for tag, i1, i2, j1, j2 in sm.get_opcodes():
            if tag != 'equal': print(f'   {tag} T{t[i1:i2][:4]} O{ob[j1:j2][:4]}')
print('cases differing (register-blind):', bad)
