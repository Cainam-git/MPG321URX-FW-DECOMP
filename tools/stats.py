#!/usr/bin/env python3
"""Recompute the progress numbers and write them into README.md (progress bars and summary sentence) and
docs/STATUS.md (progress table). Matched = status "matched" in symbols/<section>.json, counted by function name
against the function table symbols/<section>.functions.json.
usage: stats.py [--check]   (--check prints the numbers without writing)"""
import json, pathlib, re, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
ROWS = [("Main processor", "leon2m", "`leon2m`"), ("Input processor", "leon2s", "`leon2s`"),
        ("Helper processor", "8051_bank0", "`8051_bank0` (boot loader)"),
        ("Helper processor", "8051_bank1", "`8051_bank1` (main application)"),
        ("Helper processor", "8051_bank2", "`8051_bank2` (update agent)"),
        ("Helper processor", "8051_bank3", "`8051_bank3` (mostly tables)")]


def section(name):
    funcs = json.loads((ROOT / "symbols" / f"{name}.functions.json").read_text())["functions"]
    sym = json.loads((ROOT / "symbols" / f"{name}.json").read_text())["functions"]
    matched = {v["name"] for v in sym.values() if v.get("status") == "matched"}
    return (sum(f["size"] for f in funcs if f["name"] in matched), sum(f["size"] for f in funcs),
            sum(1 for f in funcs if f["name"] in matched), len(funcs))


def bar(p, width=20):
    n = int(p * width + 1e-9)
    return "[" + "#" * n + "-" * (width - n) + "]"


def main():
    data = {s: section(s) for _, s, _ in ROWS}
    groups = {}
    for label, s, _ in ROWS:
        g = groups.setdefault(label, [0, 0]); g[0] += data[s][0]; g[1] += data[s][1]
    tot = [sum(d[i] for d in data.values()) for i in range(4)]
    lines = [f"{label:<18} {bar(m / t)} {round(100 * m / t):4d} %" for label, (m, t) in groups.items()]
    lines.append(f"{'Overall':<18} {bar(tot[0] / tot[1])} {round(100 * tot[0] / tot[1]):4d} %")
    print("\n".join(lines))
    if "--check" in sys.argv: return

    readme = ROOT / "README.md"; r = readme.read_text()
    r = re.sub(r"(## Progress\n\n```\n).*?(\n```)", lambda m: m[1] + "\n".join(lines) + m[2], r, flags=re.S)
    done = tot[2] // 100 * 100
    r = re.sub(r"More than [\d,]+ of roughly [\d,]+ functions are done",
               f"More than {done:,} of roughly {round(tot[3], -2):,} functions are done", r)
    readme.write_text(r)

    status = ROOT / "docs" / "STATUS.md"; s = status.read_text()
    head = ("| Processor | Section | Matched bytes | Total bytes | Matched | Matched functions | Functions |\n"
            "|---|---|---:|---:|---:|---:|---:|\n")
    rows = "".join(f"| {label} | {sec} | {data[s][0]:,} | {data[s][1]:,} | {100 * data[s][0] / data[s][1]:.1f} % | "
                   f"{data[s][2]:,} | {data[s][3]:,} |\n" for label, s, sec in ROWS)
    rows += (f"| **Total** | | **{tot[0]:,}** | **{tot[1]:,}** | **{100 * tot[0] / tot[1]:.1f} %** | "
             f"**{tot[2]:,}** | **{tot[3]:,}** |\n")
    s = re.sub(r"\| Processor \| Section \|.*?\n(?=\n)", head + rows, s, count=1, flags=re.S)
    status.write_text(s)


if __name__ == "__main__":
    main()
