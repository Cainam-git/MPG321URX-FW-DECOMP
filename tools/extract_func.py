#!/usr/bin/env python3
"""Print one function's machine-made C from decomp/<cpu>.c.
Usage: extract_func.py <cpu> <function-name-or-address>   (address like a00617b4)
"""
import re, sys, pathlib
ROOT = pathlib.Path(__file__).resolve().parent.parent

def functions(cpu):
    """Yield (name, address_or_None, text) for every function in decomp/<cpu>.c."""
    text = (ROOT / "decomp" / f"{cpu}.c").read_text(errors="replace")
    # Ghidra puts long return types on their own line: join "undefined8\nFUN_x(" into one header line
    text = re.sub(r'^((?!typedef|struct|union|enum|return)[A-Za-z_][\w \*]*)\n(?=[A-Za-z_]\w*\()', r'\1 ', text, flags=re.M)
    # a definition starts at column 0 with a type, a name and '(' and ends at a '}' at column 0
    for m in re.finditer(r'^(?!typedef|struct|union|enum)[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\(([^;{]*)\)\s*\n\s*\{.*?^\}', text, re.S | re.M):
        name = m.group(1)
        addr = re.search(r'(?:FUN_|LAB_)?(?:CODE_)?([0-9a-f]{4,8})$', name)
        yield name, (addr.group(1) if addr else None), m.group(0)

def get(cpu, key):
    for name, addr, body in functions(cpu):
        if name == key or (addr and addr == key.lower()):
            return name, body
    return None, None

if __name__ == "__main__":
    name, body = get(sys.argv[1], sys.argv[2])
    sys.exit("not found") if body is None else print(body)
