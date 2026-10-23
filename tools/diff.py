#!/usr/bin/env python3
"""Compare a compiled object's function with the firmware's target assembly.

Usage: diff.py <cpu> <function> <object.o> [--quiet]

Both sides are objdump'ed and normalised the way asm-differ does: addresses
dropped, branch targets turned into relative labels, calls outside the
function become <extern>, and address fields the linker fills in (sethi %hi /
%lo pairs, relocations) become placeholders. "MATCH" means every instruction
is identical after that. Prints a side-by-side diff and a percentage.
"""
import difflib, json, os, pathlib, re, subprocess, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent

def toolchain(cpu):
    cfg = json.loads((ROOT / "tools" / "config.json").read_text())[cpu]
    return str(ROOT / cfg["toolchain"]) + "/" + cfg["prefix"]

def target(cpu, fn):
    rows = []
    for ln in (ROOT / "asm" / cpu / f"{fn}.s").read_text().splitlines()[1:]:
        a, rest = ln.split(":", 1)
        rest = rest.strip()
        rows.append((int(a, 16), rest[:12].strip(), rest[12:].strip()))
    return rows

def compiled(cpu, obj, fn):
    out = subprocess.run([toolchain(cpu) + "objdump", "-d", "-r", "--no-show-raw-insn", obj],
                         capture_output=True, text=True, check=True).stdout
    rows, inside, relocs = [], False, {}
    for ln in out.splitlines():
        h = re.match(r'^[0-9a-f]+ <(.+)>:$', ln)
        if h:
            inside = h.group(1) == fn
            continue
        if not inside: continue
        r = re.match(r'\s*([0-9a-f]+):\s+R_SPARC_(\w+)\s+(.*)', ln)
        if r:
            relocs[int(r.group(1), 16)] = r.group(2); continue
        m = re.match(r'\s*([0-9a-f]+):\s+(.*)$', ln)
        if m: rows.append((int(m.group(1), 16), "", m.group(2).strip()))
    return rows, relocs

REG = r'%[a-z]\d'
def normalise(rows, relocs, lo0_copies=()):
    """relocs: None for the firmware side (addresses are concrete), dict for objects.
    lo0_copies (firmware side): row indices where the compiled object completes an address into another register
    with a %lo of 0 ("or %a, %lo(sym), %b", which objdump prints as "mov %a, %b"); the firmware's "mov" there is
    that completion, not a copy of the %hi part."""
    starts = {a for a, _, _ in rows}
    lo, hi = min(starts, default=0), max(starts, default=0)
    sethi_regs = {}          # reg -> instruction index of the last sethi into it
    completed = set()        # sethi'd regs whose %lo was already added (full address in the register)
    out = []
    at_target = {}           # branch target address -> address-register state when the branch (and its delay slot) ran
    pending = None           # (target, delay-slot index) of the branch just seen
    dead = False             # the previous row ended the straight-line flow (unconditional jump done)
    uncond_next = -1         # index of the delay slot of the last unconditional jump
    jmp_state = None         # address-register state at the last computed jump (switch dispatch)
    for i, (a, _, ins) in enumerate(rows):
        if a in at_target:   # a branch lands here: registers set up before it (e.g. a sethi in its delay slot) still hold
            regs, comp = at_target[a]
            if dead:   # the code just above ends in an unconditional jump: only the branch's state reaches this point
                sethi_regs = dict(regs); completed = set(comp)
            else:
                for r, j in regs.items(): sethi_regs.setdefault(r, j)
                completed |= {r for r in comp if sethi_regs.get(r) == regs.get(r)}
        elif dead and jmp_state is not None:   # unreachable by straight-line flow and no recorded branch: a jump-table
            sethi_regs = dict(jmp_state[0]); completed = set(jmp_state[1])   # case, entered with the state at the "jmp"
        dead = False
        ins = re.sub(r'\s+', ' ', ins.split("!")[0].strip())
        ins = re.sub(r'\s*<[^>]*>', '', ins)
        m = re.match(r'^(call|b\w*|fb\w*|cb\w*)(,a)?\s+(?:0x)?([0-9a-f]+)$', ins)
        if m:
            tgt = int(m.group(3), 16)
            if m.group(1) != "call" and lo <= tgt <= hi: pending = (tgt, i + 1)
            op = m.group(1) + (m.group(2) or "")
            ins = f"{op} L{tgt - a:+d}" if (lo <= tgt <= hi and not (relocs is not None and a in relocs)) else f"{op} <extern>"
        elif relocs is not None and a in relocs:
            t = relocs[a]
            if t == "HI22": ins = re.sub(r'%hi\(0x[0-9a-f]+\)|%hi\(0\)', '%hi(ADDR)', ins)
            elif t in ("LO10", "13"):
                ins = re.sub(r'\[ (' + REG + r') \]', r'[ \1 + %lo(ADDR) ]', ins)
                ins = re.sub(r'^mov (' + REG + r'), (' + REG + r')$', r'or \1, %lo(ADDR), \2', ins)
                ins = re.sub(r', 0\b', ', %lo(ADDR)', ins)
            # a relocated instruction also writes its destination register: drop any older constant-sethi tracking of
            # it, or later field offsets on that register ("ldub [%o2 + 0x14]") get misread as %lo(ADDR)
            d = re.search(r', (' + REG + r')$', ins)
            if d: sethi_regs.pop(d.group(1), None); completed.discard(d.group(1))
        else:
            s = re.match(r'^sethi %hi\((0x[0-9a-f]+)\), (' + REG + ')$', ins)
            if s:
                sethi_regs[s.group(2)] = i; completed.discard(s.group(2))
                ins = f"sethi %hi(ADDR), {s.group(2)}"
            else:
                # an immediate < 0x400 applied to a recently sethi'd register is a %lo()
                for reg, j in list(sethi_regs.items()):
                    if reg in ins:
                        # "or %r, 0, %r" (a %lo that happens to be zero) is printed by objdump as "mov %r, %r"
                        ins = re.sub(r'^mov (' + re.escape(reg) + r'), ' + re.escape(reg) + r'$', r'or \1, %lo(ADDR), \1', ins)
                        if reg not in completed:   # once the address is complete, [reg + n] is a field offset
                            ins = re.sub(r'\[ (' + re.escape(reg) + r') \+ (0x[0-3]?[0-9a-f]{1,2}|\d)\b \]', r'[ \1 + %lo(ADDR) ]', ins)   # objdump prints 0-9 in decimal
                            ins = re.sub(r'\[ (' + re.escape(reg) + r') \]', r'[ \1 + %lo(ADDR) ]', ins)   # a %lo of 0 prints as [ %reg ]
                        ins = re.sub(r'^(or|add|restore) (' + re.escape(reg) + r'), (0x[0-3]?[0-9a-f]{1,2}|\d)\b,', r'\1 \2, %lo(ADDR),', ins)   # restore %i0, %lo(sym), %o0 = tail call passing a symbol address
                # a register overwritten by something other than its %lo use stops tracking
                # any write to the register ends its address role: a load into it ("ldub [%g1+lo], %g1")
                # or the completed address ("or %g1, lo, %g1"); later small immediates on it are plain numbers
                # (completing the address, "or %r, %lo, %r", keeps it: other code paths may complete it again)
                d = re.search(r', (' + REG + r')$', ins) or re.match(r'^clr (' + REG + r')$', ins)   # "clr %r" writes %r too
                if d and d.group(1) in sethi_regs:
                    if re.match(r'^(or|add) (\S+), %lo\(ADDR\), \2$', ins): completed.add(d.group(1))
                    else: del sethi_regs[d.group(1)]; completed.discard(d.group(1))
                cp = re.match(r'^mov (' + REG + r'), (' + REG + r')$', ins)   # a copy of a sethi'd register carries the address on
                if cp and cp.group(1) != cp.group(2) and cp.group(1) in sethi_regs and i in lo0_copies \
                        and cp.group(1) not in completed:   # the object completes the address here with a %lo of 0
                    ins = f"or {cp.group(1)}, %lo(ADDR), {cp.group(2)}"
                    sethi_regs[cp.group(2)] = i; completed.add(cp.group(2))
                elif cp and cp.group(1) != cp.group(2) and cp.group(1) in sethi_regs:
                    sethi_regs[cp.group(2)] = i
                    if cp.group(1) in completed: completed.add(cp.group(2))
                    else: completed.discard(cp.group(2))
        out.append(ins)
        if pending and i == pending[1]:   # state after the delay slot travels with the branch
            at_target.setdefault(pending[0], (dict(sethi_regs), set(completed))); pending = None
        # unconditional control transfer: "b,a"/"ba,a" skip their delay slot (next row is unreachable at once);
        # "b"/"ba"/"ret"/"retl"/"jmp" end the flow after their delay slot
        if re.match(r'^ba?,a ', ins): dead = True
        elif uncond_next == i: dead = True
        if re.match(r'^(ba? |ret|retl|jmp )', ins) or ins in ('ret', 'retl'): uncond_next = i + 1
        if ins.startswith('jmp ') and not re.match(r'^jmp %[io]7', ins): jmp_state = (dict(sethi_regs), set(completed))
    return out

last_reason = None   # why the last shape match was not byte-exact (for feedback)


def compare(cpu, fn, obj):
    t = target(cpu, fn); c, relocs = compiled(cpu, obj, fn)
    if not c: raise SystemExit(f"function {fn} not found in {obj}")
    cn = normalise(c, relocs)
    # rows where the object completes an address into another register with a %lo of 0 ("mov %a, %b" + LO10)
    lo0 = {i for i, (a, _, ins) in enumerate(c) if relocs.get(a) in ("LO10", "13")
           and re.match(r'^mov\s+(' + REG + r'),\s*(' + REG + r')', ins.split("!")[0].strip())
           and len(set(re.findall(REG, ins.split("!")[0]))) == 2}
    tn = normalise(t, None, lo0)
    # Ghidra often ends a function before its trailing padding nop; if the compiled code has
    # extra trailing nops and the firmware has exactly those nops right after, they belong to it
    extra = len(cn) - len(tn)
    if t and 0 < extra <= 2 and all(x == "nop" for x in cn[-extra:]):
        img = (ROOT / "parts" / f"{cpu}.bin").read_bytes()
        off = t[-1][0] + 4 - {"leon2s": 0xA0060000, "leon2m": 0xA0028000}[cpu]
        if img[off:off + 4 * extra] == b"\x01\x00\x00\x00" * extra:
            tn = tn + ["nop"] * extra
    elif t and 0 < extra <= 4 and not (relocs and any(r[0] in relocs for r in c[-extra:])):
        # Ghidra also cuts functions short before a final ret/restore that only a branch reaches:
        # when the firmware bytes right after the cut are exactly the compiled tail, they belong to it
        img = (ROOT / "parts" / f"{cpu}.bin").read_bytes()
        off = t[-1][0] + 4 - {"leon2s": 0xA0060000, "leon2m": 0xA0028000}[cpu]
        enc = {"ret": "81c7e008", "retl": "81c3e008", "restore": "81e80000", "nop": "01000000"}   # compiled rows carry no bytes
        tail = bytes.fromhex("".join(enc.get(x, "zz") for x in cn[-extra:])) if all(x in enc for x in cn[-extra:]) else b""
        if len(tail) == 4 * extra and img[off:off + 4 * extra] == tail:
            tn = tn + cn[-extra:]
    sm = difflib.SequenceMatcher(a=tn, b=cn, autojunk=False)
    same = sum(b.size for b in sm.get_matching_blocks())
    total = max(len(tn), len(cn))
    score, match = 100.0 * same / total, tn == cn
    global last_reason
    last_reason = None
    if match:   # shapes are equal: now the real bytes at the real address must be too (tools/exact.py)
        import exact
        last_reason = exact.exact(cpu, fn, obj)
        if last_reason: score, match = 99.0, False
    elif score >= 90 and len(tn) == len(cn):   # the shape normaliser misses some address forms ([%i0 + 0x1fd] with a
        import exact                           # far-away sethi): the exact byte comparison decides
        if exact.exact(cpu, fn, obj) is None: score, match, last_reason = 100.0, True, None
    return tn, cn, sm, same, total, score, match

def render(fn, cpu, tn, cn, sm, same, total, score, match):
    w = 44
    lines = [f"{'TARGET (' + cpu + ')':<{w}} | COMPILED"]
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        for k in range(max(i2 - i1, j2 - j1)):
            l = tn[i1 + k] if i1 + k < i2 else ""
            r = cn[j1 + k] if j1 + k < j2 else ""
            lines.append(f"{' ' if tag == 'equal' else '*'}{l:<{w-1}} | {r}")
    lines.append(f"\n{fn}: {same}/{total} instructions, {score:.1f}%  " + ("MATCH" if match else "no match"))
    return "\n".join(lines)

if __name__ == "__main__":
    cpu, fn, obj = sys.argv[1], sys.argv[2], sys.argv[3]
    res = compare(cpu, fn, obj)
    txt = render(fn, cpu, *res)
    print(txt.splitlines()[-1] if "--quiet" in sys.argv else txt)
