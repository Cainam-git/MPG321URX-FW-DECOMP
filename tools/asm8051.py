#!/usr/bin/env python3
"""Assembly-source pass for the 8051 helper chip: routines that were hand-written assembly in the original.

Qualifies (strict, C51 cannot produce it): a routine whose last instruction is not RET/RETI/LJMP/AJMP/SJMP/JMP
and runs straight into the next routine (several entry points into one piece of code: the math and table
helpers), plus the routine it runs into. Keil C51 always ends a function with a return or a jump, so a
fall-through between two functions is assembly by definition. Bytes Ghidra did not disassemble (data) never
qualify. The bytes are decoded with the table below into Keil A51 syntax (internal branch targets as labels,
everything else as numbers), assembled with A51 at the real address (CSEG AT) and judged byte for byte against
the bank. Matches go to src/<bank>/<fn>.a51 with status matched, by "asm".
usage: asm8051.py <bank> [--names a,b] [--import]        check one file: asm8051.py --check <bank> <fn>

Note: the fall-through rule above is NOT enough on its own. Of 139 fall-through routines in the three
banks, most are compiled C that Ghidra cut in two (Keil lets one function jump into another's tail, so the second
half has its own callers); every one of them re-assembles exactly, which proves nothing about the source. The 38
that sit inside Keil library code were filed by tools/keillib.py as library pieces instead. So --import needs
--names: file only routines shown to be hand-written by other evidence; never sweep a whole bank.
"""
import json, os, pathlib, re, subprocess, sys, tempfile
ROOT = pathlib.Path(__file__).resolve().parent.parent
CFG = json.loads((ROOT / "tools" / "config.json").read_text())
A51 = ROOT / CFG["8051"]["keil_bin"] / "A51.EXE"
ENV = dict(os.environ, WINEPREFIX=str(ROOT / CFG["8051"]["wineprefix"]), WINEDEBUG="-all")
ENDS = ("RET", "RETI", "LJMP", "AJMP", "SJMP", "JMP")

def h8(v): return f"0{v:02X}H"
def h16(v): return f"0{v:04X}H"
ARITH = {0x2: "ADD", 0x3: "ADDC", 0x9: "SUBB"}
LOGIC = {0x4: "ORL", 0x5: "ANL", 0x6: "XRL"}

def decode(b, pc):
    """one instruction at b[0..] located at pc -> (length, mnemonic, operand template, targets) or None.
    Branch targets are returned as ('T', addr) in the operand list so the caller can turn them into labels."""
    op = b[0]; hi, lo = op >> 4, op & 0xF
    def d(i): return h8(b[i])
    def rel(i, n): return ("T", (pc + n + (b[i] - 256 if b[i] > 127 else b[i])) & 0xFFFF)
    rn = f"R{op & 7}"; ri = f"@R{op & 1}"
    if lo == 1:   # AJMP / ACALL addr11
        t = ((pc + 2) & 0xF800) | ((op & 0xE0) << 3) | b[1]
        return 2, ("ACALL" if hi & 1 else "AJMP"), [("T", t)]
    if op == 0x00: return 1, "NOP", []
    if op == 0x02: return 3, "LJMP", [("T", (b[1] << 8) | b[2])]
    if op == 0x12: return 3, "LCALL", [("T", (b[1] << 8) | b[2])]
    if op in (0x03, 0x13, 0x23, 0x33): return 1, {0x03: "RR", 0x13: "RRC", 0x23: "RL", 0x33: "RLC"}[op], ["A"]
    if op == 0x22: return 1, "RET", []
    if op == 0x32: return 1, "RETI", []
    if op in (0x10, 0x20, 0x30): return 3, {0x10: "JBC", 0x20: "JB", 0x30: "JNB"}[op], [d(1), rel(2, 3)]
    if op in (0x40, 0x50, 0x60, 0x70, 0x80): return 2, {0x40: "JC", 0x50: "JNC", 0x60: "JZ", 0x70: "JNZ", 0x80: "SJMP"}[op], [rel(1, 2)]
    if hi in (0x0, 0x1) and lo >= 4:   # INC / DEC
        m = "INC" if hi == 0 else "DEC"
        if lo == 4: return 1, m, ["A"]
        if lo == 5: return 2, m, [d(1)]
        return 1, m, [ri if lo < 8 else rn]
    if hi in ARITH and lo >= 4:
        m = ARITH[hi]
        if lo == 4: return 2, m, ["A", "#" + d(1)]
        if lo == 5: return 2, m, ["A", d(1)]
        return 1, m, ["A", ri if lo < 8 else rn]
    if hi in LOGIC and lo >= 2:
        m = LOGIC[hi]
        if lo == 2: return 2, m, [d(1), "A"]
        if lo == 3: return 3, m, [d(1), "#" + d(2)]
        if lo == 4: return 2, m, ["A", "#" + d(1)]
        if lo == 5: return 2, m, ["A", d(1)]
        return 1, m, ["A", ri if lo < 8 else rn]
    if op == 0x72: return 2, "ORL", ["C", d(1)]
    if op == 0x73: return 1, "JMP", ["@A+DPTR"]
    if op == 0x74: return 2, "MOV", ["A", "#" + d(1)]
    if op == 0x75: return 3, "MOV", [d(1), "#" + d(2)]
    if hi == 0x7 and lo >= 6: return 2, "MOV", [ri if lo < 8 else rn, "#" + d(1)]
    if op == 0x82: return 2, "ANL", ["C", d(1)]
    if op == 0x83: return 1, "MOVC", ["A", "@A+PC"]
    if op == 0x84: return 1, "DIV", ["AB"]
    if op == 0x85: return 3, "MOV", [d(2), d(1)]   # encoded source first, destination second
    if hi == 0x8 and lo >= 6: return 2, "MOV", [d(1), ri if lo < 8 else rn]
    if op == 0x90: return 3, "MOV", ["DPTR", "#" + h16((b[1] << 8) | b[2])]
    if op == 0x92: return 2, "MOV", [d(1), "C"]
    if op == 0x93: return 1, "MOVC", ["A", "@A+DPTR"]
    if op == 0xA0: return 2, "ORL", ["C", "/" + d(1)]
    if op == 0xA2: return 2, "MOV", ["C", d(1)]
    if op == 0xA3: return 1, "INC", ["DPTR"]
    if op == 0xA4: return 1, "MUL", ["AB"]
    if op == 0xA5: return None
    if hi == 0xA and lo >= 6: return 2, "MOV", [ri if lo < 8 else rn, d(1)]
    if op == 0xB0: return 2, "ANL", ["C", "/" + d(1)]
    if op == 0xB2: return 2, "CPL", [d(1)]
    if op == 0xB3: return 1, "CPL", ["C"]
    if op == 0xB4: return 3, "CJNE", ["A", "#" + d(1), rel(2, 3)]
    if op == 0xB5: return 3, "CJNE", ["A", d(1), rel(2, 3)]
    if hi == 0xB and lo >= 6: return 3, "CJNE", [ri if lo < 8 else rn, "#" + d(1), rel(2, 3)]
    if op == 0xC0: return 2, "PUSH", [d(1)]
    if op == 0xC2: return 2, "CLR", [d(1)]
    if op == 0xC3: return 1, "CLR", ["C"]
    if op == 0xC4: return 1, "SWAP", ["A"]
    if op == 0xC5: return 2, "XCH", ["A", d(1)]
    if hi == 0xC and lo >= 6: return 1, "XCH", ["A", ri if lo < 8 else rn]
    if op == 0xD0: return 2, "POP", [d(1)]
    if op == 0xD2: return 2, "SETB", [d(1)]
    if op == 0xD3: return 1, "SETB", ["C"]
    if op == 0xD4: return 1, "DA", ["A"]
    if op == 0xD5: return 3, "DJNZ", [d(1), rel(2, 3)]
    if op in (0xD6, 0xD7): return 1, "XCHD", ["A", ri]
    if hi == 0xD and lo >= 8: return 2, "DJNZ", [rn, rel(1, 2)]
    if op == 0xE0: return 1, "MOVX", ["A", "@DPTR"]
    if op in (0xE2, 0xE3): return 1, "MOVX", ["A", ri]
    if op == 0xE4: return 1, "CLR", ["A"]
    if op == 0xE5: return 2, "MOV", ["A", d(1)]
    if hi == 0xE and lo >= 6: return 1, "MOV", ["A", ri if lo < 8 else rn]
    if op == 0xF0: return 1, "MOVX", ["@DPTR", "A"]
    if op in (0xF2, 0xF3): return 1, "MOVX", [ri, "A"]
    if op == 0xF4: return 1, "CPL", ["A"]
    if op == 0xF5: return 2, "MOV", [d(1), "A"]
    if hi == 0xF and lo >= 6: return 1, "MOV", [ri if lo < 8 else rn, "A"]
    return None

def ghidra_rows(bank):
    rows = {}
    for ln in (ROOT / "decomp" / f"{bank}.lst").read_text(errors="replace").splitlines():
        m = re.match(r"CODE:CODE:([0-9a-f]{4})\s+([0-9a-f]+)\s+(\S+)", ln)
        if m: rows[int(m[1], 16)] = (len(m[2]) // 2, m[3])
    return rows

def candidates(bank):
    """fall-through pairs among routines: (fn, next) where fn does not end in a return/jump"""
    rows = ghidra_rows(bank)
    fs = sorted(json.loads((ROOT / "symbols" / f"{bank}.functions.json").read_text())["functions"], key=lambda f: f["start"])
    starts = {f["start"]: f for f in fs}; out = {}
    for f in fs:
        a, last = f["start"], None
        while a < f["end"] and a in rows: last = rows[a]; a += rows[a][0]
        if a != f["end"] or last is None: continue                    # not fully disassembled: data inside
        if last[1].upper() not in ENDS and f["end"] in starts:
            out[f["name"]] = f; nxt = starts[f["end"]]; out[nxt["name"]] = nxt
    return out, rows

def gen(bank, f, rows):
    """A51 source for one routine, or (None, reason)"""
    img = (ROOT / "parts" / f"{bank}.bin").read_bytes()
    a, ins = f["start"], []
    while a < f["end"]:
        if a not in rows: return None, f"0x{a:04x} not disassembled by Ghidra (data)"
        r = decode(img[a:a + 3] + b"\0\0", a)
        if not r or r[0] != rows[a][0]: return None, f"0x{a:04x} cannot decode {img[a]:02x}"
        ins.append((a,) + r); a += r[0]
    targets = {t[1] for _, _, _, ops in ins for t in ops if isinstance(t, tuple)}
    inside = {x[0] for x in ins}
    body = []
    for a, n, m, ops in ins:
        if a in targets: body.append(f"L_{a:04X}:")
        txt = ",".join((f"L_{o[1]:04X}" if o[1] in inside else h16(o[1])) if isinstance(o, tuple) else o for o in ops)
        body.append(f"\t{m}\t{txt}".rstrip())
    return (f"; {bank} {f['name']} @ 0x{f['start']:04X}  MATCH (Keil A51, asm)\n"
            "; Hand-written assembly in the original: runs straight into the next routine (several entry\n"
            "; points into one piece of code), which Keil C51 never generates. Reproduced from the bytes.\n"
            f"\tCSEG\tAT\t{h16(f['start'])}\n" + "\n".join(body) + "\n\tEND\n"), None

def assemble(src, start, end):
    """None if A51 reproduces exactly the firmware bytes from start to end, else a short reason"""
    with tempfile.TemporaryDirectory() as td:
        (pathlib.Path(td) / "u.a51").write_text(src)
        r = subprocess.run(["wine", str(A51), "u.a51"], cwd=td, env=ENV, capture_output=True, text=True, timeout=300)
        lst = pathlib.Path(td) / "u.LST"
        if " 0 ERROR(S)" not in r.stdout or not lst.exists(): return "A51: " + (r.stdout.strip().splitlines() or ["no output"])[-1]
        code = {}
        for ln in lst.read_text(errors="replace").splitlines():
            m = re.match(r"^([0-9A-F]{4}) ([0-9A-F]{2,6})\s+\d+\s", ln)
            if m:
                for k in range(len(m[2]) // 2): code[int(m[1], 16) + k] = int(m[2][2 * k:2 * k + 2], 16)
    return src_cmp(code, start, end)

BANKIMG = {}
def src_cmp(code, start, end):
    return None if code == {a: BANKIMG["img"][a] for a in range(start, end)} else "bytes differ"

def check(bank, fn):
    """verify.py hook: re-assemble src/<bank>/<fn>.a51 and compare with the bank"""
    f = {x["name"]: x for x in json.loads((ROOT / "symbols" / f"{bank}.functions.json").read_text())["functions"]}[fn]
    BANKIMG["img"] = (ROOT / "parts" / f"{bank}.bin").read_bytes()
    return assemble((ROOT / "src" / bank / f"{fn}.a51").read_text(), f["start"], f["end"])

def main():
    if sys.argv[1] == "--check": print(check(sys.argv[2], sys.argv[3]) or "exact"); return
    bank = sys.argv[1]; do_import = "--import" in sys.argv
    if do_import and "--names" not in sys.argv: sys.exit("--import needs --names (see FINDING in the header)")
    want = set(sys.argv[sys.argv.index("--names") + 1].split(",")) if "--names" in sys.argv else None
    BANKIMG["img"] = (ROOT / "parts" / f"{bank}.bin").read_bytes()
    symp = ROOT / "symbols" / f"{bank}.json"; sym = json.loads(symp.read_text())
    done = {v["name"] for v in sym["functions"].values() if v.get("status") == "matched"}
    cands, rows = candidates(bank)
    n = ok = 0; fails = []
    for fn, f in sorted(cands.items(), key=lambda kv: kv[1]["start"]):
        if fn in done or fn.startswith("thunk") or (want and fn not in want): continue
        n += 1
        src, why = gen(bank, f, rows)
        if not src: fails.append((fn, why)); continue
        why = assemble(src, f["start"], f["end"])
        if why: fails.append((fn, why)); continue
        ok += 1
        if do_import:
            (ROOT / "src" / bank / f"{fn}.a51").write_text(src)
            sym["functions"][f"CODE:{f['start']:04x}"] = {"name": fn, "status": "matched", "by": "asm",
                "comment": "hand-written assembly (runs into the next routine); reproduced from the bytes"}
    if do_import: symp.write_text(json.dumps(sym, indent=2, sort_keys=True))
    print(f"{bank}: {n} fall-through routines, {ok} reproduce exactly" + (" (imported)" if do_import else ""))
    for fn, why in fails[:8]: print("  ", fn, why)

if __name__ == "__main__":
    main()
