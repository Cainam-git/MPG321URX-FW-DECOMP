"""Merge Ghidra's 8-byte 'ret; restore' stubs back into the function before them. gcc 3.4 emits a sibling call
as 'call f; restore' and still lays down the unreachable 'ret; restore' epilogue after it; Ghidra makes that a
function of its own, which (a) counts as a bogus function and (b) makes the byte judge reject the real function
("runs into the next function"). A stub is merged when nothing calls it and it starts exactly where the previous
function ends. Updates symbols/<cpu>.functions.json, symbols/<cpu>.json, asm/<cpu>/*.s and src/<cpu>/*.S.
usage: mergetails.py <cpu> [--apply]"""
import json, pathlib, re, subprocess, sys
ROOT = pathlib.Path(__file__).resolve().parent.parent
cpu = sys.argv[1]; apply = "--apply" in sys.argv
dec = (ROOT / "decomp" / f"{cpu}.c").read_text()
fj = ROOT / "symbols" / f"{cpu}.functions.json"; d = json.loads(fj.read_text()); fs = d["functions"]
by_start = {f["start"]: f for f in fs}; by_end = {f["end"]: f for f in fs}
sp = ROOT / "symbols" / f"{cpu}.json"; sym = json.loads(sp.read_text())
merged = []; skipped = []
for f in sorted(fs, key=lambda x: x["start"]):
    if f["size"] != 8: continue
    s = ROOT / "asm" / cpu / f"{f['name']}.s"
    if not s.exists(): continue
    body = [l for l in s.read_text().split("\n")[1:] if l.strip()]
    if not (len(body) == 2 and " ret" in body[0] and " restore" in body[1]): continue
    if len(re.findall(r"\b" + f["name"] + r"\b", dec)) > 1: skipped.append((f["name"], "has callers")); continue
    prev = by_end.get(f["start"])
    if not prev: skipped.append((f["name"], "no function ends at its start")); continue
    ps = ROOT / "asm" / cpu / f"{prev['name']}.s"
    plines = [l for l in ps.read_text().split("\n")[1:] if l.strip()]
    if not any(" call " in l or " jmp" in l or " b,a " in l or " b " in l for l in plines[-3:]):
        skipped.append((f["name"], f"{prev['name']} does not end in a call/branch")); continue
    merged.append((f, prev))
    if not apply: continue
    prev["end"] = f["end"]; prev["size"] = prev["end"] - prev["start"]
    t = ps.read_text()
    t = re.sub(r"^(# \S+ \S+ 0x[0-9a-f]+-)0x[0-9a-f]+ \((\d+) bytes\)", lambda m: f"{m.group(1)}0x{prev['end']:x} ({prev['size']} bytes)  [{f['name']} = unreachable ret/restore tail, merged]", t, count=1, flags=re.M)
    t = t.rstrip("\n") + "\n" + "\n".join(body) + "\n"; ps.write_text(t); s.unlink()
    sym["functions"].pop(f"ram:{f['start']:08x}", None)
    for ext in (".S", ".c", ".lib"):
        g = ROOT / "src" / cpu / (f["name"] + ext)
        if g.exists(): subprocess.run(["git", "rm", "-q", str(g.relative_to(ROOT))], cwd=ROOT)
    pS = ROOT / "src" / cpu / (prev["name"] + ".S")   # hand-written asm for the previous function: give it its tail
    if pS.exists():
        pS.write_text(pS.read_text().rstrip("\n") + "\n\tret\n\trestore\n")
if apply:
    d["functions"] = [f for f in fs if f["name"] not in {m[0]["name"] for m in merged}]
    fj.write_text(json.dumps(d, indent=1)); sp.write_text(json.dumps(sym, indent=2, sort_keys=True))
print(f"{cpu}: {len(merged)} stubs {'merged' if apply else 'would be merged'}, {len(skipped)} skipped")
for n, why in skipped[:10]: print("  skip", n, why)
was_matched = sum(1 for f, p in merged if any(v.get('name') == f['name'] and v.get('status') == 'matched' for v in json.loads(sp.read_text())['functions'].values()))
prev_matched = sum(1 for f, p in merged if (ROOT / 'src' / cpu / (p['name'] + '.c')).exists() or (ROOT / 'src' / cpu / (p['name'] + '.S')).exists())
print(f"  stubs that were counted as matched: {was_matched}; previous functions already matched: {prev_matched}")
