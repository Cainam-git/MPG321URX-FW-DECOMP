#!/usr/bin/env python3
"""Reading aid for one leon2m function: target assembly with debug strings and call targets annotated,
the 0x4008xxxx RAM alias resolved (func_0x4008XXXX is the same code as FUN_a002XXXX), plus its callers.
usage: xref.py <fn> [--no-asm]"""
import json, pathlib, re, struct, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
IMG = (ROOT / "firmware" / "MSI_MPG321URX_V021_7F69.bin").read_bytes()
FS = {f["name"]: f for f in json.loads((ROOT / "symbols/leon2m.functions.json").read_text())["functions"]}
BYADDR = {f["start"]: n for n, f in FS.items()}
SYM = {v["name"]: v for v in json.loads((ROOT / "symbols/leon2m.json").read_text())["functions"].values()}

def string_at(a):
    o = a + 0x108000
    if not (0 <= o < len(IMG)): return None
    e = IMG.find(b"\0", o, o + 200)
    s = IMG[o:e] if e > o else b""
    return s.decode("latin1") if len(s) >= 3 and all(32 <= c < 127 or c in (9, 10, 13, 27) for c in s) else None

def name_of(t):
    if 0x40080000 <= t < 0x40090000: t = t - 0x40080000 + 0xa0020000
    n = BYADDR.get(t, f"0x{t:08x}")
    st = SYM.get(n, {}).get("status")
    return n + (" [matched]" if st == "matched" else "")

def callers(fn):
    tgt = FS[fn]["start"]; alias = tgt - 0xa0020000 + 0x40080000 if 0xa0028000 <= tgt < 0xa0038000 else None
    out = []
    for off in range(0xa8000, 0x2A0000, 4):
        w = struct.unpack_from(">I", IMG, off)[0]
        if w >> 30 != 1: continue
        d = w & 0x3fffffff
        if d & 0x20000000: d -= 0x40000000
        pc = off - 0xa8000 + 0xa0000000; t = (pc + d * 4) & 0xffffffff
        if t == tgt or (alias and t == alias):
            owner = max((s for s in BYADDR if s <= pc), default=None)
            out.append(f"{BYADDR.get(owner, '?')}+0x{pc - owner:x}" if owner else hex(pc))
    return out

def main():
    fn = sys.argv[1]; f = FS[fn]
    print(f"# {fn} 0x{f['start']:08x} size {f['size']}  status {SYM.get(fn, {}).get('status')}")
    print("# callers:", ", ".join(callers(fn)) or "none found (jump table or pointer?)")
    if "--no-asm" in sys.argv: return
    hi = {}; annul = False
    for ln in (ROOT / "asm/leon2m" / f"{fn}.s").read_text().splitlines()[1:]:
        a, rest = ln.split(":", 1); ins = rest[13:].strip(); note = ""
        m = re.match(r"sethi\s+%hi\((0x[0-9a-f]+)\),\s*(%\w+)", ins)
        # a sethi in the delay slot of an annulled branch (b..,a) only runs when the branch is taken: the fall-through
        # code keeps the register's older value, so do not carry the new one forward
        if m and annul: hi.pop(m[2], None); note = "  ; (annulled delay slot: only on the taken branch)"
        elif m: hi[m[2]] = int(m[1], 16)
        annul = bool(re.match(r"b\w*,a\s", ins)) and not re.match(r"ba?,a\s", ins)   # after an unconditional b,a the
        # next instruction is only reached as a branch target, where the sethi does run
        m = re.match(r"(?:or|add)\s+(%\w+),\s*(-?0x[0-9a-f]+|-?\d+),\s*(%\w+)", ins)
        if m and m[1] in hi:
            v = hi[m[1]] + int(m[2], 0); s = string_at(v)
            note = f'  ; 0x{v:x}' + (f' "{s[:70]}"' if s else "")
        m = re.match(r"call\s+(0x[0-9a-f]+)", ins)
        if m: note = "  ; -> " + name_of(int(m[1], 16))
        print(f"{a.strip()}: {ins}{note}")

if __name__ == "__main__": main()
