#!/usr/bin/env python3
"""Model of GCC 3.4 local register allocation (local-alloc.c) for one basic block of a -dl dump, against the dump.

Usage: lsim.py <file.lreg> <block> [--mark REG,...] [--swap-uid A,B ...] [--move-uid A,B ...] [--swap-item I,J]
               [--notie REG,...] [--glob REG,...] [--ovr REG:refs|b|d:VALUE ...] [--alloc HARD,...] [--debug REG]
               [--func NAME]
       lsim.py --src <file.c> [--flags "-mcpu=v8 -O3 -g"] <block> [options as above]
       lsim.py <file.lreg> --blocks [--func NAME]

Reads the block's insns from the .lreg dump (gcc -dl), builds the block-local quantities the way local-alloc does
(a pseudo set from a pseudo that dies in the same insn is tied to it, except movsi_lo_sum), gives each quantity the
priority floor(log2(refs)) * refs / (death - birth) and assigns hard registers in priority order (ties: quantity
number), taking the first free register of the allocation order. Per quantity it prints rank, priority, life
(insn positions, two per insn), refs, its pseudos, the hard register GCC chose (';; Register N in M.' lines) and the
simulated one, marked X when they differ. The last line counts agreements.

What-if options (the dump is not changed):
  --swap-uid A,B   swap the insns with uids A and B before the replay (repeatable)
  --move-uid A,B   move the insn with uid A to just before uid B (repeatable)
  --swap-item I,J  swap the I-th and J-th item of the block (0-based)
  --notie REG,...  do not tie these pseudos to a dying source pseudo
  --glob REG,...   treat these pseudos as global (left to global-alloc, not replayed)
  --ovr REG:F:V    override field F of the quantity holding pseudo REG: refs, b (birth) or d (death) (repeatable)
  --alloc H,...    hard-register allocation order (default 1,13,12,11,10,9,8,15,16..23: the SPARC leaf-less order
                   %g1, %o5..%o0, %o7, %l0..%l7)
  --mark REG,...   mark the quantities holding these pseudos with <==
  --debug REG      print the busy intervals of the first eight allocation-order registers when REG's quantity is placed
--func NAME uses only that function's part of the dump (block numbers restart in every function).
--src compiles <file.c> with --flags plus -dl in a temporary directory and reads the dump from there; --blocks lists
the blocks of the dump with their insn counts.
"""
import argparse, glob, math, os, re, subprocess, sys, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import diff

DEFAULT_ALLOC = "1,13,12,11,10,9,8,15,16,17,18,19,20,21,22,23"


def parse_sexp(x):
    x = re.sub(r'\[\d+ [^\]]*\]', '', x); x = re.sub(r'\[flags [^\]]*\]', '', x); x = re.sub(r'<[^>]*>', '', x)
    x = x.replace('[', '(').replace(']', ')')
    toks = re.findall(r'\(|\)|"[^"]*"|[^\s()]+', x)

    def rec(k):
        if toks[k] == '(':
            lst = []; k += 1
            while toks[k] != ')':
                v, k = rec(k); lst.append(v)
            return lst, k + 1
        return toks[k], k + 1
    return rec(0)[0]


def regno(e):
    if isinstance(e, list) and e and e[0].startswith('reg'): return int(e[1])
    if isinstance(e, list) and e and e[0].startswith('subreg') and isinstance(e[1], list) and e[1][0].startswith('reg'):
        return int(e[1][1])
    return None


def uid(x):
    m = re.match(r'\((?:insn|code_label|call_insn|jump_insn|note|barrier) (\d+)', x.strip())
    return m.group(1) if m else None


def blocks(t):
    out = []
    for m in re.finditer(r';; Start of basic block (\d+),', t):
        e = t.index(';; End of basic block %s,' % m.group(1), m.start())
        out.append((int(m.group(1)), len(re.findall(r'^\((?:insn|call_insn|jump_insn) ', t[m.start():e], re.M))))
    return out


def function_part(t, fn):
    parts = re.split(r'^(?=;; Function )', t, flags=re.M)
    for p in parts:
        if re.match(r';; Function %s\b' % re.escape(fn), p): return p
    raise SystemExit("no ';; Function %s' in the dump" % fn)


def simulate(t, blk, a):
    if ';; Start of basic block %s,' % blk not in t: raise SystemExit('no block %s in the dump (--blocks lists them)' % blk)
    start = t.index(';; Start of basic block %s,' % blk); end = t.index(';; End of basic block %s,' % blk, start)
    s = t[start:end]
    actual = {int(x): int(y) for x, y in re.findall(r';; Register (\d+) in (\d+)\.', t)}
    info = {}
    for m in re.finditer(r'^Register (\d+) used (\d+) times across (\d+) insns in block (\d+);(.*)$', t, re.M):
        if m.group(4) == str(blk) and 'dies in' not in m.group(5): info[int(m.group(1))] = int(m.group(2))
    for g in a.glob: info.pop(g, None)
    items = [x for x in re.split(r'\n\n', s) if x.strip() and not x.strip().startswith('(note')
             and not x.strip().startswith(';;')]
    for pr in a.swap_uid:
        x, y = pr.split(',')
        ia = next(i for i, it in enumerate(items) if uid(it) == x); ib = next(i for i, it in enumerate(items) if uid(it) == y)
        items[ia], items[ib] = items[ib], items[ia]
    for pr in a.move_uid:
        x, y = pr.split(',')
        ia = next(i for i, it in enumerate(items) if uid(it) == x); it = items.pop(ia)
        ib = next(i for i, it2 in enumerate(items) if uid(it2) == y); items.insert(ib, it)
    if a.swap_item:
        i, j = map(int, a.swap_item.split(',')); items[i], items[j] = items[j], items[i]
    n = 0; recs = []
    for it in items:
        it = it.strip()
        if not it or it.startswith('(note') or it.startswith(';;'): continue
        n += 1
        if not it.startswith('(insn'): continue
        pat_txt = it[:it.index(' {')]; rest = it[it.index(' {'):]
        body = pat_txt[pat_txt.index('(', 1):]
        try: P = parse_sexp(body)
        except Exception: P = None
        dest = None; ops = []; S = P
        if isinstance(S, list) and S and S[0] == 'parallel': S = S[1][0]
        if isinstance(S, list) and S and S[0] == 'set':
            dest = regno(S[1]); src = S[2]
            if regno(src) is not None: ops = [regno(src)]
            elif isinstance(src, list): ops = [regno(x) for x in src[1:] if regno(x) is not None]
        dead = [int(x) for x in re.findall(r'REG_DEAD \(reg[^ ]* (\d+)', rest)]
        recs.append((n, dest, ops, dead, rest.split('}')[0]))
    qty = {}; Q = []
    for n, dest, ops, dead, name in recs:
        tied = None
        if dest is not None and dest in info and dest not in qty and dest not in a.notie and name not in (' {*movsi_lo_sum',):
            for r in ops:
                if r in dead and r in qty:
                    q = qty[r]; qty[dest] = q; Q[q][2] += info[dest]; Q[q][3].append(dest); tied = r; break
        for r in dead:
            if r in qty and r != tied: Q[qty[r]][1] = 2 * n
        if dest is not None and dest in info and dest not in qty:
            qty[dest] = len(Q); Q.append([2 * n, None, info[dest], [dest]])
    for q in Q:
        if q[1] is None: q[1] = q[0] + 1
    ovr = {}
    for kv in a.ovr:
        r, f, v = kv.split(':'); ovr.setdefault(int(r), []).append((f, int(v)))
    for q in Q:
        for r in q[3]:
            for f, v in ovr.get(r, []):
                q[{"refs": 2, "b": 0, "d": 1}[f]] = v

    def pri(q):
        b, d, refs, regs = q
        return int((math.floor(math.log2(refs)) * refs * 1000 / (d - b)) * 10) if refs > 0 else 0
    order = sorted(range(len(Q)), key=lambda i: (-pri(Q[i]), i))
    alloc = [int(x) for x in a.alloc.split(",")]
    busy, pred, owners = {}, {}, {}
    for i in order:
        b, d, refs, regs = Q[i]
        pick = None
        for h in alloc:
            if all(d2 <= b or d <= b2 for b2, d2 in busy.get(h, [])): pick = h; break
        if a.debug is not None and a.debug in regs:
            for h in alloc[:8]:
                print('  busy', h, [(b2, d2, o) for b2, d2, o in owners.get(h, []) if not (d2 <= b or d <= b2)])
        busy.setdefault(pick, []).append((b, d)); pred[i] = pick; owners.setdefault(pick, []).append((b, d, regs[0]))
    ok = bad = 0; lines = []
    for rank, i in enumerate(order):
        b, d, refs, regs = Q[i]
        hr = sorted({actual.get(r) for r in regs if r in actual})
        good = hr == [pred[i]]
        ok += good; bad += not good
        mark = ' <==' if any(r in a.mark for r in regs) else ''
        lines.append(f'{rank:3d} q{i:3d} pri {pri(Q[i]):6d} life {b:4d}-{d:4d} refs {refs:2d} regs {regs} act {hr} '
                     f'sim {pred[i]}{"" if good else " X"}{mark}')
    return lines, ok, bad


def ints(s): return [int(x) for x in s.split(",") if x] if s else []


def main():
    ap = argparse.ArgumentParser(usage=__doc__.split("\n\n")[1])
    ap.add_argument("args", nargs="*"); ap.add_argument("--src"); ap.add_argument("--flags", default="-mcpu=v8 -O3 -g")
    ap.add_argument("--blocks", action="store_true"); ap.add_argument("--mark", default="")
    ap.add_argument("--swap-uid", action="append", default=[]); ap.add_argument("--move-uid", action="append", default=[])
    ap.add_argument("--swap-item"); ap.add_argument("--notie", default=""); ap.add_argument("--glob", default="")
    ap.add_argument("--ovr", action="append", default=[]); ap.add_argument("--alloc", default=DEFAULT_ALLOC)
    ap.add_argument("--debug", type=int); ap.add_argument("--func")
    a = ap.parse_args()
    a.mark, a.notie, a.glob = ints(a.mark), ints(a.notie), ints(a.glob)
    with tempfile.TemporaryDirectory() as td:
        if a.src:
            c = os.path.join(td, "x.c"); open(c, "w").write(open(a.src).read())
            subprocess.run(["nice", "-n", "10", diff.toolchain("leon2m") + "gcc", *a.flags.split(), "-w", "-dl", "-c",
                            c, "-o", os.path.join(td, "x.o")], cwd=td, check=True)
            lreg = glob.glob(os.path.join(td, "*.lreg"))
            if not lreg: raise SystemExit("no .lreg dump written")
            t = open(lreg[0]).read(); rest = a.args
        else:
            if not a.args: raise SystemExit(__doc__.split("\n\n")[1])
            t = open(a.args[0]).read(); rest = a.args[1:]
    if a.func: t = function_part(t, a.func)
    if a.blocks or not rest:
        for b, ln in blocks(t):
            print("block %s: %d insns" % (b, ln))
        return
    lines, ok, bad = simulate(t, int(rest[0]), a)
    print("\n".join(lines)); print('agree', ok, 'disagree', bad)


if __name__ == "__main__":
    main()
