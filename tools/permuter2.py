#!/usr/bin/env python3
"""decomp-permuter (simonlindholm, toolchains/decomp-permuter) driven by this project's judge, for the SPARC cores.

The community permuter rewrites the C at the language level (pycparser AST: temporaries, expression expansion,
statement/declaration reordering, masks, casts, struct refs, ...), far more than tools/permuter.py's regex moves.
It knows nothing about SPARC, so this driver replaces its objdump scorer with diff.compare (shape score) plus the
exact-bytes verdict: penalty 0 = byte-exact, else (100 - shape) * 100. Its own threading/network modes are not used;
one single-threaded search per function, several functions in parallel (--jobs). Matches are filed exactly like
tools/permuter.py (src/<cpu>/<fn>.c, symbols, by "permuter2", commit under the core lock); improved drafts overwrite
work/autoc/<cpu>/<fn>.c so later passes start from them.
usage: permuter2.py <cpu> [--min 90] [--max 99.99] [--budget 120] [--limit N] [--jobs 4] [--names a,b] [--src draft.c --write]
"""
import re, argparse, hashlib, json, os, pathlib, subprocess, sys, tempfile, time
from multiprocessing import Pool
ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools" / "_shims"))          # 'toml' shim (decomp-permuter only reads toml)
sys.path.insert(0, str(ROOT / "toolchains" / "decomp-permuter"))
sys.path.insert(0, str(ROOT / "tools"))
import diff, near, permuter as ours
from src.permuter import Permuter, EvalError
from src.compiler import Compiler
from src.helpers import get_default_randomization_weights
GCC = str(ROOT / "toolchains/sparc-elf-3.4.4/bin/sparc-elf-gcc")
LOG = ROOT / "work" / "permuter.log"   # shared with tools/permuter.py, so one log holds both ("MATCH" lines)


class ByteScorer:
    """decomp-permuter scorer interface: score(o_file) -> (penalty, hash); 0 = done"""
    PENALTY_INF = 10 ** 9

    def __init__(self, cpu, fn): self.cpu, self.fn = cpu, fn

    def score(self, cand_o):
        if not cand_o: return self.PENALTY_INF, ""
        try: tn, cn, sm, same, total, score, match = diff.compare(self.cpu, self.fn, cand_o)
        except BaseException: return self.PENALTY_INF, ""
        h = hashlib.sha256(pathlib.Path(cand_o).read_bytes()).hexdigest()
        return (0 if match else max(1, int(round((100.0 - score) * 100)))), h


def search(cpu, fn, src_path, flags, budget):
    """(start_shape, best_shape, matched, best_source, candidates_tried)"""
    with tempfile.TemporaryDirectory(prefix="p2_") as td:
        td = pathlib.Path(td)
        # pycparser cannot parse __builtin_va_arg(ap, T); hide it as a call __va_arg_T(ap) for the
        # permuter and turn it back just before compiling (compile.sh rewrites a copy of the candidate)
        (td / "compile.sh").write_text('#!/bin/bash\n'
            'sed -E \'s/__va_arg_([A-Za-z_]+)\\(([A-Za-z_][A-Za-z0-9_]*)\\)/__builtin_va_arg(\\2, \\1)/g; s/\\b(unsigned|signed|long)_/\\1 /g\' "$1" > "$1.va.c"\n'
            f'"{GCC}" {flags} -w -c "$1.va.c" -o "$3"; r=$?; rm -f -- "$1.va.c"; exit $r\n'); os.chmod(td / "compile.sh", 0o755)  # delete the copy (otherwise every candidate leaves a file in /tmp)
        source = subprocess.run([GCC, "-E", "-P", "-DPERMUTER", "-D__attribute__(x)=", str(src_path)], capture_output=True, text=True, check=True).stdout
        source = re.sub(r'__builtin_va_arg\s*\(\s*(\w+)\s*,\s*([\w ]+?)\s*\)', lambda m: '__va_arg_' + m.group(2).replace(' ', '_') + '(' + m.group(1) + ')', source)
        if '__va_arg_' in source: source = 'int __va_arg_int(); unsigned int __va_arg_unsigned_int();\n' + source
        compiler = Compiler(str(td / "compile.sh"), show_errors=False, debug_mode=False)
        p = Permuter(str(td), fn, compiler, ByteScorer(cpu, fn), str(src_path), source,
                     randomization_weights=get_default_randomization_weights("base"), force_seed=None, force_rng_seed=None,
                     keep_prob=0.25, need_profiler=False, need_all_sources=False, show_errors=False, best_only=True,
                     better_only=True, score_threshold=None, debug_mode=False, speed=100)
        start = p.base_score; best = start; best_src = p.base_source; n = 0; t0 = time.time()
        for seed in p.seed_iterator():
            if time.time() - t0 > budget or best == 0: break
            r = p.try_eval_candidate(seed); n += 1
            if isinstance(r, EvalError) or r.score is None: continue
            if r.score < best and r.source:
                best, best_src = r.score, r.source; p.record_result(r)
        return 100.0 - start / 100.0, 100.0 - best / 100.0, best == 0, best_src, n


def run_one(args):
    cpu, fn, src_path, budget, write = args
    try:
        s0, m0, reason, pairs, flags = near.judge(cpu, fn, pathlib.Path(src_path))   # best flag set for this draft
        if s0 < 0: return cpu, fn, None, f"{fn}: draft does not compile ({reason})", write, None, None
        t0 = time.time(); start, best, matched, best_src, n = search(cpu, fn, src_path, flags, budget)
        line = f"p2 {fn}: {start:.1f} -> {best:.1f}{' MATCH' if matched else ''} ({n} candidates, {time.time() - t0:.0f}s)"
        return cpu, fn, (start, best, matched, best_src, flags), line, write, None, None
    except Exception as e:
        return cpu, fn, None, f"p2 {fn}: error {str(e)[:120]}", write, None, None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("cpu"); ap.add_argument("--names", default=""); ap.add_argument("--src", default="")
    ap.add_argument("--min", type=float, default=90); ap.add_argument("--max", type=float, default=99.99)
    ap.add_argument("--budget", type=int, default=120); ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--jobs", type=int, default=4); ap.add_argument("--write", action="store_true")
    a = ap.parse_args(); want = set(a.names.split(",")) if a.names else None
    scp = ROOT / "work" / "autoc" / f"{a.cpu}.scores.json"; scores = json.loads(scp.read_text())
    sym = json.loads((ROOT / "symbols" / f"{a.cpu}.json").read_text())["functions"]
    done = {v["name"] for v in sym.values() if v.get("status") == "matched"}
    if a.src:
        todo = [(a.cpu, a.names, a.src, a.budget, a.write)]
    else:
        todo = []
        for fn, v in scores.items():
            p = ROOT / "work" / "autoc" / a.cpu / f"{fn}.c"
            if not (a.min <= v.get("score", -1) <= a.max and fn not in done and (not want or fn in want) and p.exists()): continue
            if not want and v.get("permuter2") == hashlib.sha1(p.read_bytes()).hexdigest() and v.get("permuter2_budget", 0) >= a.budget: continue
            todo.append((a.cpu, fn, str(p), a.budget, True))
        if a.limit: todo = sorted(todo, key=lambda t: -scores[t[1]].get("score", -1))[:a.limit]
    with Pool(max(1, min(a.jobs, len(todo) or 1))) as pool:
        res = list(pool.imap_unordered(run_one, todo, chunksize=1))
    import fcntl
    lockf = open(ROOT / "work" / f"lock-{a.cpu}", "w"); fcntl.flock(lockf, fcntl.LOCK_EX)   # searches ran unlocked; writes under the core lock
    up = matched = 0
    with LOG.open("a") as lg:
        for cpu, fn, r, line, write, _, _ in res:
            print(line); lg.write(time.strftime("%F %T ") + cpu + " " + line + "\n")
            if not write or r is None: continue
            start, best, ok, best_src, flags = r
            if not a.src:
                scores.setdefault(fn, {})["permuter2"] = hashlib.sha1(pathlib.Path(ROOT / "work" / "autoc" / cpu / f"{fn}.c").read_bytes()).hexdigest()
                scores[fn]["permuter2_budget"] = a.budget
            if ok:
                ours.file_match(cpu, fn, best_src, flags, ["decomp-permuter (AST mutations), judged by exact bytes"]); matched += 1
                scores.setdefault(fn, {})["score"] = 100.0
            elif best > start + 0.05 and a.src:
                # a run on a given (hand) draft: random AST mutations may change the meaning, so the improvement is
                # kept beside the draft for a drift check instead of replacing what later passes start from
                (ROOT / "work" / "hand" / cpu / f"{fn}.p2best.c").write_text(best_src); up += 1
            elif best > start + 0.05:
                (ROOT / "work" / "autoc" / cpu / f"{fn}.c").write_text(best_src); scores.setdefault(fn, {})["score"] = best; up += 1
    if any(r[4] for r in res) and not a.src: scp.write_text(json.dumps(scores, indent=1))
    fcntl.flock(lockf, fcntl.LOCK_UN); lockf.close()
    print(f"{len(res)} tried, {up} improved, {matched} now match")


if __name__ == "__main__": main()
