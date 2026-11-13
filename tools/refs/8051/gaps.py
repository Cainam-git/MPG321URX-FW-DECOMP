#!/usr/bin/env python3
"""list the non-function regions of one bank, split into fill / strings / other bytes.
usage: python3 -I tools/refs/8051/gaps.py <bank> [--raw]"""
import pathlib, sys
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import d51  # noqa: E402

PR = set(range(0x20, 0x7F)) | {0x0D, 0x0A, 0x09}


def regions(b):
    own = d51.coverage(b)
    out = []; s = None
    for x in range(0x10000 + 1):
        if x < 0x10000 and own[x] is None:
            if s is None: s = x
        elif s is not None:
            out.append((s, x)); s = None
    return out


def pieces(bk, s, e):
    """split [s,e) into ('ff'|'zero'|'str'|'bytes', start, end)"""
    out = []; x = s
    while x < e:
        c = bk[x]
        if c in (0xFF, 0x00):
            y = x
            while y < e and bk[y] == c: y += 1
            if y - x >= 4 or c == 0xFF:
                out.append(("ff" if c == 0xFF else "zero", x, y)); x = y; continue
        if c in PR:
            y = x
            while y < e and bk[y] in PR: y += 1
            if y < e and bk[y] == 0 and y - x >= 2:
                out.append(("str", x, y + 1)); x = y + 1; continue
        y = x + 1
        while y < e and not (bk[y] in PR or bk[y] in (0xFF,)) : y += 1
        if out and out[-1][0] == "bytes" and out[-1][2] == x: out[-1] = ("bytes", out[-1][1], y)
        else: out.append(("bytes", x, y))
        x = y
    return out


if __name__ == "__main__":
    b = int(sys.argv[1]); bk = d51.bank_bytes(b)
    for s, e in regions(b):
        print("REGION %04x-%04x (%d)" % (s, e, e - s))
        for k, x, y in pieces(bk, s, e):
            if k == "str": print("   %04x str  %r" % (x, bk[x:y - 1].decode("latin1")))
            elif k in ("ff", "zero"): print("   %04x %-4s x%d" % (x, k, y - x))
            else: print("   %04x hex  %s" % (x, bk[x:y].hex(" ")))
