"""Near-miss triage: every unmatched function whose best mechanical draft (work/autoc) scored >= MIN,
recompiled with the core's flag sets and judged by shape (diff.compare) and bytes (exact). Prints one line per
function with the differing instruction pairs and the byte-judge reason, plus a tally of the causes, and keeps
the per-function record in work/near/<cpu>/<fn>.json (source path, flags, score, reason, diff pairs).
Usage: near.py [--min 95] [--cpu leon2s|leon2m] [--names a,b]"""
import argparse, collections, json, pathlib, re, subprocess, sys, tempfile
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools")); import diff, autoc
GCC = ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-gcc"


def candidates(cpu, lo):
    sym = json.loads((ROOT / "symbols" / f"{cpu}.json").read_text())["functions"]
    matched = {v["name"] for v in sym.values() if v.get("status") == "matched"}
    sc = json.loads((ROOT / "work/autoc" / f"{cpu}.scores.json").read_text())
    best = {}
    for n, v in sc.items():
        src = ROOT / "work/autoc" / cpu / f"{n}.c"
        if n in matched and src.exists(): continue
        if src.exists() and v.get("score", -1) > best.get(n, (0,))[0]: best[n] = (v["score"], "autoc", src)
    return {n: b for n, b in best.items() if b[0] >= lo}, sc


def judge(cpu, fn, src):
    """(score, match, reason, pairs, flags, obj) for the best flag set"""
    best = None
    with tempfile.TemporaryDirectory() as td:
        for flags in autoc.flag_sets(cpu):
            o = pathlib.Path(td) / "x.o"
            r = subprocess.run([str(GCC), *flags.split(), "-w", "-c", str(src), "-o", str(o)], capture_output=True, text=True)
            if r.returncode:
                rec = (-1.0, False, "compile error: " + (r.stderr.strip().splitlines() or [""])[-1][:160], [], flags)
                if best is None: best = rec
                continue
            try: tn, cn, sm, same, total, score, match = diff.compare(cpu, fn, str(o))
            except BaseException as e: rec = (-1.0, False, f"judge error: {e}"[:160], [], flags); continue
            pairs = []
            for tag, i1, i2, j1, j2 in sm.get_opcodes():
                if tag == "equal": continue
                a, b = tn[i1:i2], cn[j1:j2]
                for k in range(max(len(a), len(b))): pairs.append((a[k] if k < len(a) else "-", b[k] if k < len(b) else "-"))
            rec = (score, match, diff.last_reason if match or score >= 99 else None, pairs, flags)
            if match: return rec
            if best is None or rec[0] > best[0]: best = rec
    return best


def main():
    ap = argparse.ArgumentParser(); ap.add_argument("--min", type=float, default=95); ap.add_argument("--cpu", default="")
    ap.add_argument("--names", default=""); a = ap.parse_args()
    want = set(a.names.split(",")) if a.names else None
    tally = collections.Counter(); n_all = 0
    for cpu in ([a.cpu] if a.cpu else ["leon2s", "leon2m"]):
        cands, sc = candidates(cpu, a.min)
        outd = ROOT / "work/near" / cpu; outd.mkdir(parents=True, exist_ok=True)
        for fn, (s0, origin, src) in sorted(cands.items(), key=lambda kv: -kv[1][0]):
            if want and fn not in want: continue
            score, match, reason, pairs, flags = judge(cpu, fn, src)
            n_all += 1
            key = reason.split(":")[0][:40] if reason else ("MATCH" if match else "shape:" + ";".join(f"{p[0].split(' ')[0]}>{p[1].split(' ')[0]}" for p in pairs[:3]))
            tally[key] += 1
            (outd / f"{fn}.json").write_text(json.dumps({"src": str(src), "origin": origin, "flags": flags, "score": score, "match": match,
                                                         "reason": reason, "pairs": pairs, "size": sc.get(fn, {}).get("size")}, indent=1))
            print(f"{cpu} {fn} {sc.get(fn, {}).get('size', '?')}B {origin} {score:.1f} {'MATCH' if match else ''} "
                  + (f"[{reason[:90]}]" if reason else "") + " " + " | ".join(f"{p[0]} => {p[1]}" for p in pairs[:4]))
    print(f"\n{n_all} functions; causes:")
    for k, v in tally.most_common(): print(f"  {v:3d}  {k}")


if __name__ == "__main__": main()
