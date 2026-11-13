#!/usr/bin/env python3
"""Decode the Keil ?C_INITSEG records of one bank (format: src/8051_bank0/startup/INIT.A51, XBANK = 0).
usage: python3 -I tools/refs/8051/initseg.py <bank>"""
import pathlib, sys
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import d51  # noqa: E402

START = {0: 0x185F, 1: 0x708C, 2: 0xC36D}
TYPES = {0: "IDATA", 1: "XDATA", 2: "PDATA", 3: "BIT"}


def decode(b):
    bk = d51.bank_bytes(b)
    p = START[b]; recs = []
    while True:
        info = bk[p]
        if info == 0:
            return recs, p   # p = terminator offset
        at = p; p += 1
        typ = info >> 6
        if info & 0x20:
            hi = info & 0x1F; lo = bk[p]; p += 1; n = hi * 256 + lo
        else:
            n = info & 0x1F
            if n == 0: n = 256
        if typ == 3:   # BIT: n bytes, each one bit address (low 7 bits) + value (bit 7)
            recs.append(dict(at=at, type="BIT", addr_off=None, addr=None, n=n, data_off=p, data=bk[p:p + n])); p += n
            continue
        if typ == 1:
            aoff, aw = p, 2; addr = (bk[p] << 8) | bk[p + 1]; p += 2
        else:
            aoff, aw = p, 1; addr = bk[p]; p += 1
        recs.append(dict(at=at, type=TYPES[typ], addr_off=aoff, addr_w=aw, addr=addr, n=n, data_off=p, data=bk[p:p + n]))
        p += n


if __name__ == "__main__":
    b = int(sys.argv[1])
    recs, end = decode(b)
    for r in recs:
        print("rec@%04x %-5s addr@%s=%s n=%3d data@%04x %s" % (
            r["at"], r["type"], "%04x" % r["addr_off"] if r["addr_off"] is not None else "-",
            "%04x" % r["addr"] if r["addr"] is not None else "-", r["n"], r["data_off"], r["data"][:24].hex()))
    print("terminator at %04x, %d records" % (end, len(recs)))
