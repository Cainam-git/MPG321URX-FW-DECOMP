# Small-chip variant of tools/check/rawcmp.py (parts/leon2s.bin at 0xA0060000); prints every mismatch.
# Independent check: compile C, compare the function's raw words with the firmware over [lo, hi),
# masking only relocated fields (call disp30, sethi imm22, simm13 of the paired %lo). Prints mismatches.
import sys, subprocess, tempfile, pathlib, re, struct
sys.path.insert(0, 'tools'); import near
fn, src, fl, lo, hi = sys.argv[1], sys.argv[2], sys.argv[3], int(sys.argv[4], 16), int(sys.argv[5], 16)
fw = open('parts/leon2s.bin', 'rb').read()  # Small chip image, base 0xA0060000
tgt = fw[lo - 0xA0060000: hi - 0xA0060000]
with tempfile.TemporaryDirectory() as td:
    o = pathlib.Path(td) / 'x.o'
    subprocess.run([str(near.GCC), *fl.split(), '-w', '-c', src, '-o', str(o)], check=True)
    od = str(near.GCC).replace('gcc', 'objdump')
    dis = subprocess.run([od, '-d', '-r', str(o)], capture_output=True, text=True).stdout
    oc = str(near.GCC).replace('gcc', 'objcopy')
    b = pathlib.Path(td) / 'x.bin'
    subprocess.run([oc, '-O', 'binary', '-j', '.text', str(o), str(b)], check=True)
    code = b.read_bytes()
# function offset in .text
m = re.search(r'^([0-9a-f]+) <%s>:' % fn, dis, re.M); start = int(m.group(1), 16)
relocs = {int(x, 16) for x in re.findall(r'^\s+([0-9a-f]+): R_SPARC', dis, re.M)}
n = len(tgt) // 4; bad = 0
for i in range(n):
    off = start + 4 * i
    if off + 4 > len(code): print('compiled code too short at word', i); bad += 1; break
    a = struct.unpack('>I', tgt[4*i:4*i+4])[0]; c = struct.unpack('>I', code[off:off+4])[0]
    if off in relocs:
        if a >> 30 == 1: mask = 0xC0000000
        elif (a >> 22) & 7 == 4 and a >> 30 == 0: mask = 0xFFC00000
        else: mask = 0xFFFFE000
        if (a & mask) != (c & mask): bad += 1; print(f'{lo+4*i:08x} reloc-word differs {a:08x} {c:08x}')
    elif a != c:
        bad += 1
        if True: print(f'{lo+4*i:08x} differs fw {a:08x} ours {c:08x}')
nxt = code[start + len(tgt): start + len(tgt) + 4]
print(f'words {n}, mismatches {bad}; compiled function continues after range: {nxt.hex() or "(end)"}')
