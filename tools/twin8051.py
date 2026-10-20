#!/usr/bin/env python3
"""Helper-chip shortcuts: (1) twins: an unmatched 8051 function with the same instruction shape as a MATCHED one
gets the matched C with the constants swapped by position, judged byte-exact; (2) templates: one-line shapes
(empty function, tail jump, 4-byte xdata read) get generated C. Everything imported passes diff8051's exact judge.
usage: twin8051.py [--dry]      runs over 8051_bank0..2; prints what it imported
"""
import json, pathlib, re, sys, tempfile, time
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import diff8051
BANKS = ("8051_bank0", "8051_bank1", "8051_bank2")


def listing(bank):
    rows = {}
    for ln in open(ROOT / "decomp" / f"{bank}.lst", errors="replace"):
        m = re.match(r"CODE:CODE:([0-9a-f]{4})\s+([0-9a-f]+)\s+(\S+)\s*(.*)$", ln)
        if m: rows[int(m[1], 16)] = (bytes.fromhex(m[2]), m[3], m[4].strip())
    return rows


def shape_and_consts(L, f):
    seq, consts, a = [], [], f["start"]
    while a < f["end"] and a in L:
        b, mn, ops = L[a]; ops = re.sub(r"=>\S+", "", ops)
        for h in re.findall(r"(?:LAB|FUN|DAT|thunk)\w*?_([0-9a-f]{4})\b|#?0x([0-9a-f]+)", ops):
            consts.append(int(h[0] or h[1], 16))
        seq.append(mn + " " + re.sub(r"#?0x[0-9a-f]+|(?:LAB|FUN|DAT|SFR|thunk)\w*", "N", ops)); a += len(b)
    return "|".join(seq), consts


def swap(src, old, new):
    """Rewrite every constant of the matched C that differs in the twin; the mapping must be one-to-one."""
    pairs = {}
    for o, n in zip(old, new):
        if o != n and pairs.setdefault(o, n) != n: return None
    for o, n in sorted(pairs.items(), key=lambda kv: -kv[0]):
        src = re.sub(r"(?i)\b0x0*%x\b" % o, "0x%04x" % n, src)
        src = re.sub(r"\b(DAT_EXTMEM|FUN_CODE|LAB_CODE|thunk_FUN_CODE)_0*%04x\b" % o, lambda m: f"{m.group(1)}_{n:04x}", src)
        src = re.sub(r"(?<![\w.])%d(?![\w.])" % o, str(n), src) if o > 255 else src
    return src


def template(fn, shape, consts):
    if shape == "RET ": return f"void {fn}(void)\n{{\n}}\n"
    if shape == "LJMP N": return f"extern void FUN_CODE_{consts[0]:04x}(void);\nvoid {fn}(void)\n{{\n    FUN_CODE_{consts[0]:04x}();\n}}\n"
    if shape == "MOV DPTR,#N|MOVX A,@DPTR|MOV R4,A|INC DPTR|MOVX A,@DPTR|MOV R5,A|INC DPTR|MOVX A,@DPTR|MOV R6,A|INC DPTR|MOVX A,@DPTR|MOV R7,A|RET ":
        return f"unsigned long {fn}(void)\n{{\n    return *(volatile unsigned long xdata *)0x{consts[0]:04x};\n}}\n"
    return None


def main():
    dry = "--dry" in sys.argv; got = []
    funcs, shapes, syms = {}, {}, {}
    for b in BANKS:
        L = listing(b); syms[b] = json.loads((ROOT / "symbols" / f"{b}.json").read_text())
        for f in json.loads((ROOT / "symbols" / f"{b}.functions.json").read_text())["functions"]:
            sh, cs = shape_and_consts(L, f); funcs[(b, f["name"])] = (f, sh, cs); shapes.setdefault(sh, []).append((b, f["name"]))
    def matched(b, fn): return any(v.get("name") == fn and v.get("status") == "matched" for v in syms[b]["functions"].values())
    memo_p = ROOT / "work" / "8051-twin-tried.json"; memo = json.loads(memo_p.read_text()) if memo_p.exists() else {}
    def try_import(b, fn, f, src, how):
        import hashlib
        h = hashlib.sha1(src.encode()).hexdigest()
        if memo.get(f"{b}/{fn}") == h: return False   # this exact C already failed the judge
        memo[f"{b}/{fn}"] = h; memo_p.write_text(json.dumps(memo, indent=0))
        with tempfile.TemporaryDirectory() as td:
            p = pathlib.Path(td) / f"{fn}.c"; p.write_text(src)
            r = diff8051.judge(b, fn, str(p))
        if not r.get("match"): return False
        got.append((b, fn, how))
        if dry: return True
        (ROOT / "src" / b / f"{fn}.c").write_text(f"/* {b} {fn} @ 0x{f['start']:04x}  MATCH ({r.get('opts')}, {how})\n * {how}: byte-exact.\n */\n" + src)
        syms[b]["functions"][f"CODE:{f['start']:04x}"] = {"name": fn, "status": "matched", "by": "twin" if how.startswith("twin") else "template",
                                                         "c51opts": r.get("opts"), "comment": how}
        return True
    for (b, fn), (f, sh, cs) in funcs.items():
        if matched(b, fn) or fn.startswith("thunk") or f["end"] - f["start"] < 1: continue
        src = template(fn, sh, cs)
        if src and try_import(b, fn, f, src, "template"): continue
        for b2, fn2 in shapes.get(sh, []):
            if (b2, fn2) == (b, fn) or not matched(b2, fn2): continue
            sp = ROOT / "src" / b2 / f"{fn2}.c"
            if not sp.exists(): continue
            body = re.sub(r"/\*.*?\*/\s*", "", sp.read_text(), count=1, flags=re.S)
            src = swap(body, funcs[(b2, fn2)][2], cs)
            if src is None: continue
            src = re.sub(r"\b%s\b" % re.escape(fn2), fn, src)
            if try_import(b, fn, f, src, f"twin of {b2}/{fn2}"): break
    if not dry and got:
        # re-read each bank file just before writing and add only this run's entries (writing back the copy read
        # at the start would drop accepts made during the run)
        for b in {g[0] for g in got}:
            p = ROOT / "symbols" / f"{b}.json"; cur = json.loads(p.read_text())
            for b2, fn, _ in got:
                if b2 != b: continue
                for k, v in syms[b]["functions"].items():
                    if v.get("name") == fn and cur["functions"].get(k, {}).get("status") != "matched": cur["functions"][k] = v
            p.write_text(json.dumps(cur, indent=2, sort_keys=True))
    print(f"8051 twins/templates: {len(got)} {'would be ' if dry else ''}imported")
    for b, fn, how in got: print(f"  {b} {fn}: {how}")


if __name__ == "__main__": main()
