#!/usr/bin/env python3
"""Rebuild the 8051 boot loader's Keil start-up (src/8051_bank0/startup: STARTUP.A51 configured for IDATALEN 80h,
XDATA 3000h..3FFFh; INIT.A51 unchanged from Keil C51 9.60) with A51 + BL51 + OH51 under Wine, linked as in the
firmware (?C_C51STARTUP at 13F7h, ?STACK at 5Bh, MAIN = 151Ch, ?C_INITSEG = 185Fh), and compare the bytes with the
firmware: CODE 0x0000..0x0002 (reset LJMP) and 0x13F7..0x1490 (start-up + ?C_INIT).
usage: startup8051.py [bank start stack main initseg end]   (defaults: the boot loader, bank 0)
  e.g. startup8051.py 8051_bank2 D426 62 B5B4 C36D D4B2   (update agent: SP = stack - 1)
build() returns the linked bytes for tools/rebuild.py, which takes the settings of each bank from STARTUPS."""
import os, pathlib, shutil, subprocess, sys, tempfile
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools")); import diff8051
KEIL, ENV = diff8051.KEIL, diff8051.ENV
# start-up of each bank that has one: start, stack, main, initseg, end (the reset LJMP at 0x0000 is part of it)
STARTUPS = {"8051_bank0": (0x13F7, 0x5B, 0x151C, 0x185F, 0x1491), "8051_bank2": (0xD426, 0x62, 0xB5B4, 0xC36D, 0xD4B2)}


def run(t, *a):
    r = subprocess.run(["wine", str(KEIL / a[0])] + list(a[1:]), cwd=t, env=ENV, capture_output=True, text=True, timeout=300)
    return r.stdout + r.stderr


def build(bank, START, STACK, MAIN, INITSEG, END):
    """Assemble and link the start-up; returns ({address: byte} of the linked image, the address ranges it is
    compared over, the tool log). The image is empty when the link fails."""
    t = pathlib.Path(tempfile.mkdtemp(prefix="k51s_"))
    for f in ("STARTUP.A51", "INIT.A51"): shutil.copy(ROOT / "src" / bank / "startup" / f, t / f)
    # link-only stand-ins for the C side: MAIN at its firmware address, the init table segment placed at 185Fh
    (t / "STUB.A51").write_text(f"$NOMOD51\nNAME STUB\nPUBLIC MAIN\nMAIN EQU 0{MAIN:04X}H\n?C_INITSEG SEGMENT CODE\nRSEG ?C_INITSEG\nDB 0\nEND\n")
    for f in ("STARTUP.A51", "INIT.A51", "STUB.A51"): run(t, "A51.EXE", f)
    log = run(t, "BL51.EXE", "STARTUP.OBJ,INIT.OBJ,STUB.OBJ", "TO", "OUT", "CODE(" + ",".join(f"{n}(0{v:04X}H)" for v, n in sorted(((START, "?C_C51STARTUP"), (INITSEG, "?C_INITSEG")))) + ")", f"IDATA(?STACK(0{STACK:02X}H))")
    log += run(t, "OH51.EXE", "OUT")
    img = {}
    hexf = next((p for p in t.iterdir() if p.name.upper() == "OUT.HEX"), t / "OUT.HEX")
    if hexf.exists():
        for ln in hexf.read_text().splitlines():
            n, a, ty = int(ln[1:3], 16), int(ln[3:7], 16), int(ln[7:9], 16)
            if ty == 0:
                for i in range(n): img[a + i] = int(ln[9 + 2 * i:11 + 2 * i], 16)
    shutil.rmtree(t, ignore_errors=True)
    return img, ((0x0000, 0x0003), (START, END)), log


def main():
    a = sys.argv[1:] or ["8051_bank0", "13F7", "5B", "151C", "185F", "1491"]
    bank = a[0]
    fw = (ROOT / "parts" / f"{bank}.bin").read_bytes()
    img, ranges, log = build(bank, *(int(x, 16) for x in a[1:]))
    if not img: sys.exit("link failed:\n" + log[-1500:])
    ok = True
    for lo, hi in ranges:
        miss = [hex(a) for a in range(lo, hi) if a not in img]
        diff = [hex(a) for a in range(lo, hi) if a in img and img[a] != fw[a]]
        print(f"0x{lo:04x}..0x{hi - 1:04x}: {hi - lo} bytes, {len(diff)} differ, {len(miss)} not produced  {diff[:6]} {miss[:6]}")
        ok &= not diff and not miss
    print("MATCH" if ok else "no match")


if __name__ == "__main__":
    main()
