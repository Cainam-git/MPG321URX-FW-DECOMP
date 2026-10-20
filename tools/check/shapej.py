# Check: register-blind shape compare at one flag set; prints shape score + first shape diffs
import sys, re, difflib, subprocess, tempfile, pathlib
sys.path.insert(0,'tools'); import near, diff
fl = sys.argv[4] if len(sys.argv) > 4 else '-mcpu=v8 -O3 -g'
with tempfile.TemporaryDirectory() as td:
    o = pathlib.Path(td)/'x.o'
    r = subprocess.run([str(near.GCC), *fl.split(), '-w', '-c', sys.argv[3], '-o', str(o)], capture_output=True, text=True)
    if r.returncode: print(r.stderr[-400:]); sys.exit()
    tn, cn = diff.compare(sys.argv[1], sys.argv[2], str(o))[:2]
norm = lambda l: re.sub(r'%[golif][0-7]|%sp|%fp', 'R', l)
a = [norm(x) for x in tn]; b = [norm(x) for x in cn]
sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
print(f"shape {100*sm.ratio():.2f}  len T={len(a)} O={len(b)}")
n = 0
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal': continue
    print(f"  {tag} T[{i1}:{i2}] {a[i1:i2][:6]}  O[{j1}:{j2}] {b[j1:j2][:6]}"); n += 1
    if n > int(sys.argv[5] if len(sys.argv) > 5 else 12): break
