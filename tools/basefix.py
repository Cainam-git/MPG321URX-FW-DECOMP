#!/usr/bin/env python3
"""Base addresses held in a register (evidence-based version of permuter.py's S10): when the firmware does
'sethi %hi(X), %oN; or %oN, lo, %lM  ! 0xBASE' the original kept a struct/global base in a local pointer declared ONCE
as a constant-cast integer: `volatile unsigned char *pb_ = (volatile unsigned char *)0xBASE;` and accessed the nearby
globals as offsets from it (gcc 3.4.4 keeps the base in %l only for a constant-cast integer address, tested).
1. work/<cpu>-bases.json = {fn: [bases]} for every unmatched function (a hint for hand work).
2. For each such function with a draft: rewrite the scalar globals within 4 KB above each base as offsets from pbN_,
   judge, keep the draft when it scores higher, file it when byte-exact (by "basefix").
usage: basefix.py <cpu> [--dry]
"""
import json, pathlib, re, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import near, permuter as ours
RE_BASE = re.compile(r"\bor\s+%[lo]\d, (?:0x[0-9a-f]+|%lo\([^)]*\)), %l\d\s*!\s*(?:0x)?([0-9a-f]{8})")


def bases_of(cpu, fn):
    p = ROOT / "asm" / cpu / f"{fn}.s"
    return sorted({int(m.group(1), 16) for m in RE_BASE.finditer(p.read_text())}) if p.exists() else []


def rewrite(src, bases):
    """scalar globals within [base, base + 0x1000) -> (*(volatile T *)(pbN_ + off)); None when nothing applies"""
    scal = {}
    for m in re.finditer(r"^(?:extern\s+)?((?:(?:const|volatile|unsigned|signed)\s+)*(?:char|short|int|long))\s+_?DAT_([0-9a-fA-F]{8})\s*;", src, re.M):
        scal[int(m.group(2), 16)] = (m.group(1).replace("volatile ", ""), m.group(2))
    m = re.search(r"^[A-Za-z_][\w ]*?\s*\**\s*\w+\s*\([^)]*\)\s*\{", src, re.M)
    if not m: return None
    hdr, body = src[:m.end()], src[m.end():]; decls = ""; n = 0; hit = False
    for base in bases:
        n += 1; used = False
        for a, (t, hx) in scal.items():
            if base <= a < base + 0x1000 and re.search(r"\b_?DAT_" + hx + r"\b", body):
                body = re.sub(r"\b_?DAT_" + hx + r"\b", f"(*(volatile {t} *)(pb{n}_ + {a - base}))", body); used = True
        if used: decls += f"    volatile unsigned char *pb{n}_ = (volatile unsigned char *)0x{base:08X};\n"; hit = True
    if not hit: return None
    i = body.find("\n") + 1
    return hdr + body[:i] + decls + body[i:]


def main():
    cpu = sys.argv[1]; dry = "--dry" in sys.argv
    sym = json.loads((ROOT / "symbols" / f"{cpu}.json").read_text())["functions"]; byname = {v["name"]: v for v in sym.values()}
    scp = ROOT / "work" / "autoc" / f"{cpu}.scores.json"; scores = json.loads(scp.read_text())
    allb = {}
    for p in (ROOT / "asm" / cpu).glob("*.s"):
        if byname.get(p.stem, {}).get("status") == "matched": continue
        b = bases_of(cpu, p.stem)
        if b: allb[p.stem] = [f"{x:08x}" for x in b]
    (ROOT / "work" / f"{cpu}-bases.json").write_text(json.dumps(allb, indent=0))
    memo_p = ROOT / "work" / f"{cpu}-basefix-tried.json"; memo = json.loads(memo_p.read_text()) if memo_p.exists() else {}
    cands, _ = near.candidates(cpu, 30)
    tried = better = filed = 0
    for fn, (s0, origin, src_path) in cands.items():
        if fn not in allb: continue
        src = pathlib.Path(src_path).read_text(); h = str(hash(src) & 0xffffffff)
        if memo.get(fn) == h: continue
        memo[fn] = h
        new = rewrite(src, [int(x, 16) for x in allb[fn]])
        if not new: continue
        tried += 1
        out = ROOT / "work" / "basefix" / cpu / f"{fn}.c"; out.parent.mkdir(parents=True, exist_ok=True); out.write_text(new)
        score, match, reason, pairs, flags = near.judge(cpu, fn, out)
        cur = (scores.get(fn) or {}).get("score", -1) or -1
        if match:
            filed += 1
            if not dry: ours.file_match(cpu, fn, new, flags, [f"base 0x{allb[fn][0]} kept in a register: pointer local (basefix)"]); scores.setdefault(fn, {})["score"] = 100.0
        elif score > max(cur, s0) + 0.05:
            better += 1
            if not dry: (ROOT / "work" / "autoc" / cpu / f"{fn}.c").write_text(new); scores.setdefault(fn, {})["score"] = score
    memo_p.write_text(json.dumps(memo, indent=0))
    if not dry: scp.write_text(json.dumps(scores, indent=1))
    print(f"{cpu} basefix: {len(allb)} unmatched functions keep a base in a register; {tried} drafts rewritten, {better} better, {filed} now match" + (" (dry)" if dry else ""))


if __name__ == "__main__": main()
