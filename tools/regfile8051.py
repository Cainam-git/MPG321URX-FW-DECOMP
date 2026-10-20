#!/usr/bin/env python3
"""Register-usage file (Keil C51 REGFILE / .ORC) for an 8051 bank, rebuilt from the firmware itself.

The original 8051 code was compiled with Keil's whole-program register optimisation: a caller keeps values in
R1..R7 across a call when the callee is known not to touch them. Single-file compiles without that knowledge spill
to DATA instead and can never match. This tool decodes every function of the bank, collects the R0..R7 registers it
writes (MOV/INC/DEC/XCH/DJNZ on Rn, and direct writes to DATA 0..7 = register bank 0), adds the usage of every
function it calls or jumps to (transitively), and writes symbols/<bank>.orc in C51's REGFILE format:
    "MASK  NAME" per line; mask bit 15 = usage known, 0x2300 = accumulator/DPTR (baseline seen in Keil's own files),
    low byte = registers: bit 0 = R7, bit 1 = R6, ... bit 7 = R0 (worked out by experiment).
Each function is written as NAME and _NAME (Keil prefixes functions that take register parameters).
usage: regfile8051.py <bank> [<bank> ...]"""
import json, pathlib, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
BASE = {"8051_bank0": 0x00000, "8051_bank1": 0x10000, "8051_bank2": 0x20000, "8051_bank3": 0x30000}

# instruction lengths by opcode (standard 8051)
LEN = [1] * 256
for op in list(range(0x01, 0x100, 0x20)) + list(range(0x11, 0x100, 0x20)): LEN[op] = 2        # AJMP / ACALL
for op in (0x02, 0x12, 0x90, 0x43, 0x53, 0x63, 0x75, 0x85, 0xB4, 0xB5, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
           0xB6, 0xB7, 0xD5, 0x10, 0x20, 0x30): LEN[op] = 3
for op in (0x05, 0x15, 0x25, 0x35, 0x45, 0x55, 0x65, 0x95, 0x24, 0x34, 0x44, 0x54, 0x64, 0x94, 0x74, 0xC5, 0xD0, 0xC0,
           0xE5, 0xF5, 0x42, 0x52, 0x62, 0x72, 0x82, 0x92, 0xA0, 0xA2, 0xB0, 0xB2, 0xC2, 0xD2, 0x40, 0x50, 0x60, 0x70,
           0x80, 0x86, 0x87, 0xA6, 0xA7, 0x76, 0x77, 0x26 - 0x26 + 0x26):
    LEN[op] = 2
for op in range(0x78, 0x80): LEN[op] = 2          # MOV Rn,#
for op in range(0xA8, 0xB0): LEN[op] = 2          # MOV Rn,direct
for op in range(0x88, 0x90): LEN[op] = 2          # MOV direct,Rn
for op in range(0xD8, 0xE0): LEN[op] = 2          # DJNZ Rn,rel
LEN[0x26] = LEN[0x27] = 1; LEN[0x76] = LEN[0x77] = 2; LEN[0x83] = LEN[0x93] = 1; LEN[0x73] = 1


def scan(code, start, end):
    """(registers written as R0..R7 bit set, call/jump targets)"""
    regs, targets, pc = set(), set(), start
    while pc < end and pc < len(code):
        op = code[pc]; n = LEN[op]
        if 0x08 <= op <= 0x0F or 0x18 <= op <= 0x1F or 0x78 <= op <= 0x7F or 0xA8 <= op <= 0xAF \
                or 0xF8 <= op <= 0xFF or 0xC8 <= op <= 0xCF or 0xD8 <= op <= 0xDF:
            regs.add(op & 7)
        if op in (0x75, 0xF5, 0xD0, 0x05, 0x15, 0xD5, 0xC5, 0x42, 0x43, 0x52, 0x53, 0x62, 0x63, 0x86, 0x87) or 0x88 <= op <= 0x8F:
            if pc + 1 < len(code) and code[pc + 1] < 8: regs.add(code[pc + 1])
        if op == 0x85 and pc + 2 < len(code) and code[pc + 2] < 8: regs.add(code[pc + 2])   # MOV dst,src: dst is byte 3
        if op in (0x12, 0x02) and pc + 2 < len(code): targets.add((code[pc + 1] << 8) | code[pc + 2])
        if op & 0x1F in (0x01, 0x11): targets.add(((pc + 2) & 0xF800) | ((op & 0xE0) << 3) | code[pc + 1])
        pc += n
    return regs, targets


def build(bank):
    img = (ROOT / "firmware" / "MSI_MPG321URX_V021_7F69.bin").read_bytes()
    code = img[BASE[bank]:BASE[bank] + 0x10000]
    fs = json.loads((ROOT / "symbols" / f"{bank}.functions.json").read_text())["functions"]
    by_start = {f["start"]: f["name"] for f in fs}
    own = {f["name"]: scan(code, f["start"], f["end"]) for f in fs}
    usage = {}
    def use(fn, stack=()):
        if fn in usage: return usage[fn]
        if fn in stack: return set()
        regs = set(own[fn][0])
        for t in own[fn][1]:
            if t in by_start and by_start[t] != fn: regs |= use(by_start[t], stack + (fn,))
        usage[fn] = regs; return regs
    lines = []
    for f in sorted(fs, key=lambda f: f["start"]):
        regs = use(f["name"]); mask = 0xA300 | sum(1 << (7 - r) for r in regs)
        for nm in (f["name"].upper(), "_" + f["name"].upper()): lines.append(f"{mask:04X}  {nm}")
    out = ROOT / "symbols" / f"{bank}.orc"; out.write_text("\n".join(lines) + "\n")
    return out, len(fs)

if __name__ == "__main__":
    for b in sys.argv[1:]: print(*build(b))
