import sys, subprocess, pathlib, re, difflib
sys.path.insert(0,'tools'); import diff
cpu, fn, src, flags = sys.argv[1:5]
o = pathlib.Path(src).with_suffix('.o')
r = subprocess.run(['toolchains/sparc-elf-3.4.4/bin/sparc-elf-gcc', *flags.split(), '-w', '-c', src, '-o', str(o)], capture_output=True, text=True)
if r.returncode: print(r.stderr[:600]); sys.exit(1)
tn, cn, sm, same, total, score, match = diff.compare(cpu, fn, str(o))
mask=lambda s: re.sub(r'%[gloi][0-7]', '%R', s)
tm, cm = [mask(x) for x in tn], [mask(x) for x in cn]
sm2 = difflib.SequenceMatcher(a=tm, b=cm, autojunk=False)
same2 = sum(b.size for b in sm2.get_matching_blocks())
print(f'{fn}: shape {score:.1f}%  register-blind {100*same2/max(len(tm),len(cm)):.1f}%')
for tag,i1,i2,j1,j2 in sm2.get_opcodes():
    if tag=='equal': continue
    print(f'  @{i1}: FW {tm[i1:i2]}  =>  C {cm[j1:j2]}')
