#!/usr/bin/env python3
"""raw candidate scan inside the code ranges of one 8051 bank.
Finds: MOV DPTR,#imm with the first use of DPTR; generic-pointer immediates (R3 type, R2 high, R1 low);
register-pair immediates R6:R7 / R4:R5 / R2:R3 (memory-specific pointer arguments); JMP @A+DPTR sites;
MOVC A,@A+PC sites; PUSH DPL/DPH; CCASE inline tables.
usage: python3 -I tools/refs/8051/scan.py <bank>  -> work/refs/8051_cand_<bank>.json and a short report"""
import json, pathlib, sys
HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import d51  # noqa: E402

BR = {"SJMP", "AJMP", "LJMP", "JZ", "JNZ", "JC", "JNC", "JB", "JNB", "JBC", "CJNE", "DJNZ", "RET", "RETI", "JMP"}


def tgt(ops):
    for o in ops:
        if isinstance(o, tuple): return o[1]
    return None


def imm(o):
    return int(o[1:-1], 16) if isinstance(o, str) and o.startswith("#") else None


def run(b):
    ins, tabs, probs = d51.sweep(b)
    lib = {v: k for k, v in d51.libs(b).items()}
    hel = json.loads((d51.ROOT / "symbols" / f"8051_bank{b}.helpers.json").read_text())
    for k, v in hel.items(): lib.setdefault(int(k, 16), v["name"])
    # branch targets, so that windows stop at labels
    labels = set()
    for pc, ln, m, ops, f in ins:
        t = tgt(ops)
        if t is not None and m not in ("LCALL", "ACALL"): labels.add(t)
    out = []
    for i, (pc, ln, m, ops, f) in enumerate(ins):
        if m == "MOV" and ops[0] == "DPTR":
            v = imm(ops[1]); use = None; trail = []
            for j in range(i + 1, min(i + 16, len(ins))):
                pj, lj, mj, oj, fj = ins[j]
                if fj != f: use = "end"; break
                trail.append(mj + " " + ",".join(o if isinstance(o, str) else "%04x" % o[1] for o in oj))
                if mj == "MOVX" and ("@DPTR" in oj): use = "movx"; break
                if mj == "MOVC" and oj[1] == "@A+DPTR": use = "movc"; break
                if mj == "JMP": use = "jmp@a+dptr"; break
                if mj in ("LCALL", "ACALL", "LJMP", "AJMP"):
                    t = tgt(oj); use = ("lib:" + lib[t]) if t in lib else ("%s:%04x" % (mj.lower(), t)); break
                if mj == "MOV" and oj[0] == "DPTR": use = "overwritten"; break
                if mj == "PUSH" and oj[0] in ("082H", "083H"): use = "push"; break
                if mj in BR: use = "branch"; break
                if pj in labels and j > i + 1: pass
            out.append(dict(kind="dptr", pc=pc, off=pc + 1, width=2, value=v, func=f, use=use, trail=trail[:6]))
        if m == "MOV" and ops[0] == "R3" and imm(ops[1]) is not None:
            regs = {"R3": (pc + 1, imm(ops[1]))}
            for j in range(i + 1, min(i + 6, len(ins))):
                pj, lj, mj, oj, fj = ins[j]
                if pj in labels or fj != f: break
                if mj == "MOV" and oj[0] in ("R1", "R2") and imm(oj[1]) is not None and oj[0] not in regs:
                    regs[oj[0]] = (pj + 1, imm(oj[1]))
                if len(regs) == 3: break
            if len(regs) == 3:
                out.append(dict(kind="gptr", pc=pc, func=f, type=regs["R3"][1], value=(regs["R2"][1] << 8) | regs["R1"][1],
                                off_type=regs["R3"][0], off_hi=regs["R2"][0], off_lo=regs["R1"][0]))
            else:
                out.append(dict(kind="r3only", pc=pc, func=f, type=regs["R3"][1], regs={k: v for k, v in regs.items()}))
        if m == "MOV" and ops[0] in ("R6", "R4", "R2") and imm(ops[1]) is not None:
            for lo_r in ({"R6": ("R7",), "R4": ("R5",), "R2": ("R3", "R1")}[ops[0]]):
              for j in (i - 1, i + 1):
                if 0 <= j < len(ins):
                    pj, lj, mj, oj, fj = ins[j]
                    if fj == f and mj == "MOV" and oj[0] == lo_r and imm(oj[1]) is not None and not (j > i and pj in labels) and not (j < i and pc in labels):
                        out.append(dict(kind="pair", pc=min(pc, pj), func=f, regs=ops[0] + ":" + lo_r,
                                        value=(imm(ops[1]) << 8) | imm(oj[1]), off_hi=pc + 1, off_lo=pj + 1))
        if m == "JMP": out.append(dict(kind="jmpadptr", pc=pc, func=f))
        if m == "MOVC" and ops[1] == "@A+PC": out.append(dict(kind="movcpc", pc=pc, func=f))
        if m == "PUSH" and ops[0] in ("082H", "083H"): out.append(dict(kind="push", pc=pc, func=f, reg=ops[0]))
    for f, call, t0, ents, doff, dval, end in tabs:
        out.append(dict(kind="ccase", pc=call, func=f, table=t0, end=end,
                        entries=[(o, a, v) for o, a, v in ents], default_off=doff, default=dval))
    return out, probs


if __name__ == "__main__":
    b = int(sys.argv[1])
    out, probs = run(b)
    (d51.ROOT / "work" / "refs" / f"8051_cand_{b}.json").write_text(json.dumps(out, indent=0))
    import collections
    print(collections.Counter(o["kind"] for o in out))
    print(collections.Counter(o.get("use") for o in out if o["kind"] == "dptr"))
