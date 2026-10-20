#!/usr/bin/env python3
"""Find Keil C51 run-time library helpers in an 8051 bank by byte fingerprint and
write symbols/<bank>.helpers.json. The list explains wrappers in C terms: a wrapper such as
`MOV DPTR,#X ; LJMP ?C?LSTXDATA` is just `*(unsigned long xdata *)X = v;`.
Usage: keil_helpers.py <bank>"""
import json, pathlib, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
FP = [  # (name, bytes, meaning in C terms)
 ("?C?CLDPTR",   "bb0106898 28a83e022".replace(" ",""), "load a char through a generic pointer in R3:R2:R1 (`*p` where p has no memory-space keyword)"),
 ("?C?CLDOPTR",  "bb010ce58229f582e5833af583e022", "load a char through a generic pointer plus offset in A (`p[i]`)"),
 ("?C?CSTPTR",   "bb0106898 28a83f022".replace(" ",""), "store a char through a generic pointer (`*p = c`)"),
 ("?C?CSTOPTR",  "f8bb010de58229f582e5833af583", "store a char through a generic pointer plus offset (`p[i] = c`)"),
 ("?C?LSTXDATA", "ecf0a3edf0a3eef0a3eff022", "store the unsigned long in R4..R7 to xdata at DPTR (`*(unsigned long xdata *)DPTR = v`)"),
 ("?C?LLDXDATA", "e0fca3e0fda3e0fea3e0ff22", "load an unsigned long from xdata at DPTR into R4..R7 (`v = *(unsigned long xdata *)DPTR`)"),
 ("?C?ILDPTR",   "bb010a89828a83e0f5f0a3e022", "load an int through a generic pointer"),
 ("?C?ISTPTR",   "bb010a89828a83e5f0f0a3eff022", "store an int through a generic pointer"),
 ("?C?LMUL",     "a882a983ac05ad04ae06af07", "32-bit multiply helper (long * long)"),
 ("?C?IMUL",     "a882a983ac05ad04", "16-bit multiply helper (int * int)"),
]
def main(bank):
    b = (ROOT / "parts" / f"{bank}.bin").read_bytes()
    found = {}
    for name, hx, meaning in FP:
        pat = bytes.fromhex(hx); i = b.find(pat)
        while i >= 0:
            if f"{i:04x}" not in found: found[f"{i:04x}"] = {"name": name, "meaning": meaning}
            i = b.find(pat, i + 1)
    out = ROOT / "symbols" / f"{bank}.helpers.json"; out.write_text(json.dumps(found, indent=2, sort_keys=True))
    print(bank, {k: v["name"] for k, v in sorted(found.items())})
if __name__ == "__main__": main(sys.argv[1])
