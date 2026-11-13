#!/usr/bin/env python3
"""function ranges and a linear sweep of the 8051 banks (read-only use of tools/asm8051.decode).
usage (from repo root): python3 -I tools/refs/8051/d51.py <bank 0|1|2>   -> prints sweep statistics
"""
import json, pathlib, sys
ROOT = pathlib.Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "tools"))
import asm8051, diff8051, srcpath   # noqa: E402  (read-only: decode(), funclist(), SPAN_END)
FW = (ROOT / "firmware" / "MSI_MPG321URX_V021_7F69.bin").read_bytes()


def bank_bytes(b):
    return FW[b * 0x10000:(b + 1) * 0x10000]


def syms(b):
    return json.loads((ROOT / "symbols" / f"8051_bank{b}.json").read_text())["functions"]


def libs(b):
    d = json.loads((ROOT / "symbols" / f"8051_bank{b}.libs.json").read_text())
    out = {k: v for k, v in d.items() if k.startswith("?C?") and isinstance(v, int)}
    # plus the library entries filed as .lib source files (first line: LIBFILE MODULE PUBLIC-or-@seg+off)
    for p in srcpath.files(f"8051_bank{b}", ".lib"):
        t = p.read_text().split("\n", 1)[0].split(); fn = srcpath.label_of(f"8051_bank{b}", p)
        if len(t) >= 3 and not t[2].startswith("@") and fn.startswith("FUN_CODE_"):
            out.setdefault(t[2], int(fn[9:], 16))
    return out


def funcs(b):
    """list of (start, end, name, kind) of CODE ranges; kind 'code' or 'data' (entries recorded as data)"""
    bank = f"8051_bank{b}"
    sj = {v["name"]: v for v in syms(b).values()}
    out = []
    for f in diff8051.funclist(bank):
        end = diff8051.SPAN_END.get((bank, f["name"]), f["end"])
        kind = "data" if sj.get(f["name"], {}).get("by") == "data" else "code"
        out.append((f["start"], end, f["name"], kind))
    return sorted(out)


def coverage(b):
    """per-byte owner name of code ranges (None = outside every code range)"""
    own = [None] * 0x10000
    for s, e, n, k in funcs(b):
        if k != "code": continue
        for x in range(s, min(e, 0x10000)):
            if own[x] is None: own[x] = n
    return own


STARTUP_FN = {0: ("FUN_CODE_13f7",), 1: ("FUN_CODE_a627",), 2: ("FUN_CODE_d426",)}


INLINE = []   # filled by sweep(): (func, call_pc, data_pc, 32-bit value) of ?C?LSTK* inline constants


def sweep(b):
    """linear sweep of every code range. Returns (insns, tables, problems).
    insns: list of (pc, length, mnemonic, ops, func); tables: CCASE inline tables
    [(func, call_pc, table_start, [(entry_off, addr, value)], default_off, default_addr, end)]"""
    bk = bank_bytes(b)
    lb = libs(b)
    ccase = lb.get("?C?CCASE")
    # Keil 'store long constant' routines read 4 inline bytes after the LCALL and return behind them
    inline4 = {v for k, v in lb.items() if "LSTK" in k}
    global INLINE
    INLINE = []
    insns, tables, probs, seen, datab = [], [], [], set(), set()
    # INIT.A51 bit-mask table (read with MOVC A,@A+PC) inside the start-up code: data, not instructions
    st = diff8051.json.loads((ROOT / "symbols" / f"8051_bank{b}.json").read_text())  # noqa
    for s, e, n, k in funcs(b):
        if n in STARTUP_FN.get(b, ()):
            i = bk.find(bytes([1, 2, 4, 8, 16, 32, 64, 128]), s, e)
            if i >= 0: datab.update(range(i, i + 8))
    for s, e, n, k in funcs(b):
        if k != "code": continue
        pc = s
        while pc < e:
            if pc in seen or pc in datab: pc += 1; continue
            r = asm8051.decode(bk[pc:pc + 3], pc)
            if r is None:
                probs.append((n, pc, "undecodable %02x" % bk[pc])); pc += 1; continue
            ln, m, ops = r
            if any(x in seen for x in range(pc, pc + ln)): pc += 1; continue
            insns.append((pc, ln, m, ops, n)); seen.update(range(pc, pc + ln))
            pc += ln
            if m in ("LCALL", "ACALL") and ops[0][1] in inline4:
                INLINE.append((n, pc - ln, pc, int.from_bytes(bk[pc:pc + 4], "big")))
                datab.update(range(pc, pc + 4)); pc += 4; continue
            if m == "LCALL" and ccase is not None and ops[0][1] == ccase:
                t0 = pc; ents = []
                while True:
                    a = (bk[pc] << 8) | bk[pc + 1]
                    if a == 0:
                        d = (bk[pc + 2] << 8) | bk[pc + 3]
                        tables.append((n, t0 - 3, t0, ents, pc + 2, d, pc + 4)); pc += 4
                        datab.update(range(t0, pc)); break
                    ents.append((pc, a, bk[pc + 2])); pc += 3
        if pc != e: probs.append((n, pc, "sweep ends 0x%04x, range end 0x%04x" % (pc, e)))
    return insns, tables, probs


if __name__ == "__main__":
    b = int(sys.argv[1])
    ins, tab, pr = sweep(b)
    print("insns", len(ins), "ccase tables", len(tab), "problems", len(pr))
    for p in pr[:40]: print("  ", p[0], hex(p[1]), p[2])
