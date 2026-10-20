# Check: find leon2m functions whose jump-table targets fall outside their asm range (bad split)
import re, glob, struct, sys
fw = open('firmware/MSI_MPG321URX_V021_7F69.bin', 'rb').read()
def word(a): o = a - 0x9FF58000; return struct.unpack('>I', fw[o:o+4])[0] if 0 <= o < len(fw) - 4 else None
want = set(sys.argv[1:])
for f in sorted(glob.glob('asm/leon2m/*.s')):
    n = f.split('/')[-1][:-2]
    if want and n not in want: continue
    t = open(f).read().splitlines(); h = re.match(r'# \S+ \S+ 0x([0-9a-f]+)-0x([0-9a-f]+)', t[0])
    if not h: continue
    lo, hi = int(h[1], 16), int(h[2], 16)
    for i, l in enumerate(t):
        if re.search(r'\sjmp\s+%', l):
            ctx = '\n'.join(t[max(0, i-6):i])
            m = re.search(r'! 0x([0-9a-f]+)', ctx)
            if not m: continue
            tb = int(m.group(1), 16)
            fa = tb + 0xA0060000 if tb < 0x200000 else tb   # code runs at listing - 0xA0060000
            cm = re.findall(r'cmp\s+%\w+,\s*(0x[0-9a-f]+|\d+)', '\n'.join(t[max(0, i-12):i]))
            if not cm: continue
            cnt = int(cm[-1], 0) + 1
            out = []
            for k in range(cnt):
                w = word(fa + 4 * k)
                if w is None: break
                tgt = w + 0xA0060000 if w < 0x200000 else w
                if not (0xA0028000 <= tgt < 0xA0170000): break
                if not (lo <= tgt < hi): out.append(hex(tgt))
            if out: print(n, hex(lo), hex(hi), 'table', hex(fa), 'outside:', sorted(set(out))[:6])
