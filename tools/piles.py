"""Near-miss piles: group every unmatched draft above a score by the ONE thing that blocks it, so a shared
compiler habit shows up as a pile worth a one-time fix (examples: byte reads through 4-byte globals, function-name
strings as separate objects). Writes work/piles.json (cause -> functions) and prints
one summary line; piles at or above --flag are marked WORTH A LOOK.
usage: piles.py [--min 90] [--flag 10]"""
import argparse, collections, json, pathlib, re, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools")); import near


def cause(score, match, reason, pairs):
    if match: return "match (not yet filed)"
    if reason:
        if reason.startswith("outside name"): return "invented name"
        if reason.startswith("its constant data"): return "string/constant layout"
        if reason.startswith("bytes differ"): return "wrong constant or address"
        if reason.startswith("runs into"): return "Ghidra cut (next function is its tail)"
        if reason.startswith("compile error"): return "does not compile"
        return reason.split(":")[0][:40]
    if not pairs: return f"shape {score:.0f}%"
    a, b = pairs[0]
    ma, mb = (a.split(" ")[0] if a != "-" else "-"), (b.split(" ")[0] if b != "-" else "-")
    if ma == mb: return f"same instruction, different operands ({ma})"
    if mb == "-": return f"firmware has an extra '{ma}'"
    if ma == "-": return f"draft has an extra '{mb}'"
    return f"'{ma}' where the draft has '{mb}'"


def main():
    ap = argparse.ArgumentParser(); ap.add_argument("--min", type=float, default=90); ap.add_argument("--flag", type=int, default=10)
    a = ap.parse_args(); piles = collections.defaultdict(list); n = 0
    for cpu in ("leon2s", "leon2m"):
        cands, sc = near.candidates(cpu, a.min)
        for fn, (s0, origin, src) in cands.items():
            score, match, reason, pairs, flags = near.judge(cpu, fn, src)
            if score < a.min and not match: continue   # recompiled lower than recorded: not a near miss
            piles[cause(score, match, reason, pairs)].append(f"{cpu}/{fn}"); n += 1
    out = {k: sorted(v) for k, v in sorted(piles.items(), key=lambda kv: -len(kv[1]))}
    (ROOT / "work" / "piles.json").write_text(json.dumps(out, indent=1))
    big = [(k, len(v)) for k, v in out.items() if len(v) >= a.flag]
    top = ", ".join(f"{k} ({len(v)})" for k, v in list(out.items())[:4])
    print(f"near misses above {a.min:.0f}%: {n}; " + (f"WORTH A LOOK: " + "; ".join(f"{k} ({c})" for k, c in big) if big else "no pile reaches " + str(a.flag)) + f" | top: {top}")


if __name__ == "__main__": main()
