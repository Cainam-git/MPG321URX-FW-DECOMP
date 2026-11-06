#!/usr/bin/env python3
"""Emitted store sequence of one LEON function: compiled code against the firmware.

Usage: stseq.py <cpu> <function> <file.c|file.o> [--flags "-mcpu=v8 -O3 -g"] [--sym NAME|ADDR[:SIZE]] ...
                [--calls] [--stack] [--all]

Lists every store instruction (st, stb, sth, std and the clr forms) in the order of the instruction stream, on both
sides, and prints SAME when the two sequences are equal, else DIFF with the differing rows. Each store is written as
'<width> <address>': the address is resolved from the sethi/or/add constant chain into the base register (firmware
side: concrete values; compiled side: the relocation symbol, read as an address when its name ends in eight hex
digits, plus the addend), with the immediate offset added. A store through a register whose value is not a known
constant is written as '?+<offset>'. Stack stores (%fp/%sp) are left out unless --stack is given.

--sym keeps only stores into the given symbol or address range (SIZE in bytes, default 0x100; repeatable).
--calls adds the calls ('call <target>') to the sequence, so the store/call order is checked as well.
--all prints both full sequences side by side instead of only the differing rows.

A .c file is compiled with --flags into a temporary directory.

Library: sequence(cpu, fn, obj, syms=None, calls=False, stack=False) -> (fw_events, our_events);
same(cpu, fn, obj, ...) -> bool.
"""
import argparse, difflib, os, re, subprocess, sys, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import diff

REG = r'%(?:[goli][0-7]|sp|fp)'
STORE = re.compile(r'^(st|stb|sth|std|clr|clrb|clrh)\s+(?:(' + REG + r'|%g0),\s*)?\[\s*(' + REG + r')\s*(?:([+-])\s*(%lo\([^)]*\)|0x[0-9a-f]+|\d+|' + REG + r'))?\s*\]')
WIDTH = {"st": "w", "clr": "w", "stb": "b", "clrb": "b", "sth": "h", "clrh": "h", "std": "d"}


def sym_addr(name):
    m = re.search(r'([0-9a-f]{8})$', name)
    return int(m.group(1), 16) if m else name


def _value(rel):
    v = sym_addr(rel[1])
    return v + rel[2] if isinstance(v, int) else v


def _step(ins, rel, st):
    """state after one instruction: register -> known constant (int) or symbol name"""
    s = re.match(r'^sethi %hi\((0x[0-9a-f]+|\d+)\), (' + REG + r')$', ins)
    if s:
        st[s.group(2)] = _value(rel) if rel else int(s.group(1), 0); return
    o = re.match(r'^(or|add) (' + REG + r'), (0x[0-9a-f]+|\d+|%lo\([^)]*\)), (' + REG + r')$', ins)
    if o and o.group(2) in st:
        b = st[o.group(2)]
        if rel: st[o.group(4)] = _value(rel)
        elif isinstance(b, int): st[o.group(4)] = (b | int(o.group(3), 0)) if o.group(1) == "or" else b + int(o.group(3), 0)
        else: st[o.group(4)] = b
        return
    mv = re.match(r'^mov (' + REG + r'), (' + REG + r')$', ins)
    if mv and mv.group(1) in st:
        st[mv.group(2)] = _value(rel) if rel else st[mv.group(1)]; return
    if re.match(r'^(save|restore)\b', ins): st.clear(); return
    if STORE.match(ins) or re.match(r'^(cmp|btst|tst|b\w*|fb\w*|nop|ret|retl|jmp|call)\b', ins): return
    d = re.search(r', (' + REG + r')$', ins) or re.match(r'^(?:clr|inc|dec|not|neg) (' + REG + r')$', ins)
    if d: st.pop(d.group(1), None)


CLOBBER = ("%o0", "%o1", "%o2", "%o3", "%o4", "%o5", "%o7", "%g1", "%g2", "%g3", "%g4")


def _states(rows, relocs):
    """forward data flow over the function's control flow (delay slots included); state before every row"""
    n = len(rows); idx = {a: i for i, (a, _) in enumerate(rows)}
    succ = [[] for _ in range(n)]   # edges (from row i, executed rows) -> j: state after i flows into j
    jmp_rows = []
    for i, (a, ins) in enumerate(rows):
        op = ins.split()[0] if ins else ""
        m = re.match(r'^(b\w*|fb\w*)(,a)?\s+(?:0x)?([0-9a-f]+)$', ins)
        uncond = op in ("b", "ba", "b,a", "ba,a")
        if m and int(m.group(3), 16) in idx:
            t = idx[int(m.group(3), 16)]
            if uncond and m.group(2): succ[i].append(t)
            else:
                if i + 1 < n: succ[i + 1].append(t)
            if not uncond:
                if m.group(2) and i + 2 < n: succ[i].append(i + 2)
                if i + 1 < n: succ[i].append(i + 1)
            elif not m.group(2) and i + 1 < n: succ[i].append(i + 1)
            continue
        if i > 0 and (rows[i - 1][1].split() or [""])[0] in ("b", "ba", "ret", "retl", "jmp"):
            if rows[i - 1][1].split()[0] == "jmp": jmp_rows.append(i)
            continue   # delay slot of an unconditional transfer: no fall-through
        if i + 1 < n: succ[i].append(i + 1)
    preds = [[] for _ in range(n)]
    for i, l in enumerate(succ):
        for j in l: preds[j].append(i)
    for i in range(1, n):   # reached only by a computed jump (jump-table case): state after that jmp's delay slot
        js = [j for j in jmp_rows if j < i]
        if not preds[i] and js: succ[js[-1]].append(i); preds[i].append(js[-1])
    out = [None] * n; inn = [None] * n
    work = list(range(n))
    while work:
        i = work.pop(0)
        if preds[i]:
            ps = [out[p] for p in preds[i] if out[p] is not None]
            if not ps and i != 0: continue
            st = dict(ps[0]) if ps else {}
            for q in ps[1:]: st = {k: v for k, v in st.items() if q.get(k) == v}
        else: st = {}
        inn[i] = dict(st)
        a, ins = rows[i]
        _step(ins, relocs.get(a) if relocs is not None else None, st)
        if i > 0 and rows[i - 1][1].startswith("call"):
            for r in CLOBBER: st.pop(r, None)
        if st != out[i]:
            out[i] = st
            for j in succ[i]:
                if j not in work: work.append(j)
    return inn


def _events(rows, relocs, calls, stack, lo, hi):
    """rows: [(addr, insn)]; relocs: {addr: (type, symbol, addend)} or None for the firmware"""
    rows = [(a, re.sub(r'\s*<[^>]*>', '', re.sub(r'\s+', ' ', ins.split('!')[0].strip()))) for a, ins in rows]
    states = _states(rows, relocs)
    out = []
    for (a, ins), val in zip(rows, states):
        val = val or {}
        rel = relocs.get(a) if relocs is not None else None
        c = re.match(r'^call (?:0x)?([0-9a-f]+)', ins)
        if c:
            if calls:
                if rel: tgt = _value(rel)
                else:
                    tgt = int(c.group(1), 16)
                    if relocs is not None or lo <= tgt < hi: tgt = "local+%x" % (tgt - (rows[0][0] if relocs is not None else lo))
                out.append("call " + (("%08x" % tgt) if isinstance(tgt, int) else str(tgt)))
            elif re.match(r'^call (' + REG + ')', ins) and calls: out.append("call indirect")
            continue
        m = STORE.match(ins)
        if not m: continue
        op, base, sign, off = m.group(1), m.group(3), m.group(4), m.group(5)
        if base in ("%fp", "%sp") and not stack: continue
        k = 0; known = base in val; v = val.get(base)
        if rel and rel[0] in ("LO10", "13"):
            v = _value(rel); known = True
            if off and not off.startswith("%") and not isinstance(v, int): k = 0
        elif off and off.startswith("%"): known = False
        elif off: k = int(off, 0) * (-1 if sign == "-" else 1)
        if base in ("%fp", "%sp"): out.append("%s %s%+d" % (WIDTH[op], base, k)); continue
        if known and isinstance(v, int): out.append("%s %08x" % (WIDTH[op], (v + k) & 0xffffffff))
        elif known: out.append("%s %s+%x" % (WIDTH[op], v, k))
        else: out.append("%s ?+%s" % (WIDTH[op], off if off and off.startswith("%") else "%x" % k))
    return out


def _compiled(cpu, obj, fn):
    out = subprocess.run([diff.toolchain(cpu) + "objdump", "-d", "-r", "--no-show-raw-insn", str(obj)],
                         capture_output=True, text=True, check=True).stdout
    rows, relocs, inside = [], {}, False
    for ln in out.splitlines():
        h = re.match(r'^[0-9a-f]+ <(.+)>:$', ln)
        if h: inside = h.group(1) == fn; continue
        if not inside: continue
        r = re.match(r'\s*([0-9a-f]+):\s+R_SPARC_(\w+)\s+(\S+?)(?:\+0x([0-9a-f]+))?$', ln.rstrip())
        if r: relocs[int(r.group(1), 16)] = (r.group(2), r.group(3), int(r.group(4) or "0", 16)); continue
        m = re.match(r'\s*([0-9a-f]+):\s+(.*)$', ln)
        if m: rows.append((int(m.group(1), 16), m.group(2)))
    return rows, relocs


def _keep(ev, syms):
    if not syms: return ev
    out = []
    for e in ev:
        a = e.split()[1]
        if e.startswith("call ") or (re.fullmatch(r'[0-9a-f]{8}', a) and any(lo <= int(a, 16) < hi for lo, hi in syms)):
            out.append(e)
    return out


def parse_sym(s):
    nm, _, sz = s.partition(":")
    a = sym_addr(nm) if not nm.startswith("0x") else int(nm, 16)
    if not isinstance(a, int): raise SystemExit("--sym needs an address or a name ending in eight hex digits: " + s)
    return a, a + int(sz or "0x100", 0)


def sequence(cpu, fn, obj, syms=None, calls=False, stack=False):
    t = diff.target(cpu, fn)
    lo, hi = t[0][0], t[-1][0] + 4
    fw = _events([(a, ins) for a, _, ins in t], None, calls, stack, lo, hi)
    rows, relocs = _compiled(cpu, obj, fn)
    ours = _events(rows, relocs, calls, stack, 0, 0)
    return _keep(fw, syms), _keep(ours, syms)


def same(cpu, fn, obj, syms=None, calls=False, stack=False):
    a, b = sequence(cpu, fn, obj, syms, calls, stack)
    return a == b


def main():
    ap = argparse.ArgumentParser(usage=__doc__.split("\n\n")[1])
    ap.add_argument("cpu"); ap.add_argument("fn"); ap.add_argument("file")
    ap.add_argument("--flags", default="-mcpu=v8 -O3 -g"); ap.add_argument("--sym", action="append")
    ap.add_argument("--calls", action="store_true"); ap.add_argument("--stack", action="store_true")
    ap.add_argument("--all", action="store_true")
    a = ap.parse_args()
    syms = [parse_sym(s) for s in a.sym or []]
    with tempfile.TemporaryDirectory() as td:
        obj = a.file
        if a.file.endswith(".c"):
            obj = os.path.join(td, "s.o")
            if subprocess.run(["nice", "-n", "10", diff.toolchain(a.cpu) + "gcc", *a.flags.split(), "-w", "-c", a.file,
                               "-o", obj]).returncode: raise SystemExit("compile error")
        fw, ours = sequence(a.cpu, a.fn, obj, syms, a.calls, a.stack)
    sm = difflib.SequenceMatcher(a=fw, b=ours, autojunk=False)
    print("%-28s | %s" % ("FW (%d)" % len(fw), "OURS (%d)" % len(ours)))
    ndiff = 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal" and not a.all:
            print("  ... %d equal" % (i2 - i1)); continue
        for k in range(max(i2 - i1, j2 - j1)):
            l = fw[i1 + k] if i1 + k < i2 else ""
            r = ours[j1 + k] if j1 + k < j2 else ""
            if tag != "equal": ndiff += 1
            print("%s%-27s | %s" % (" " if tag == "equal" else "*", l, r))
    print("store sequence", "SAME" if fw == ours else "DIFF (%d rows)" % ndiff)


if __name__ == "__main__":
    main()
