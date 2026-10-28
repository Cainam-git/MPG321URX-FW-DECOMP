# Workflow guide

This project uses *matching decompilation*, the approach known from the Super Mario 64 and Ocarina of Time
decompilations: source code is accepted only when it compiles back to exactly the original bytes.

## The steps

1. **Split** the firmware into the parts each processor runs (`tools/split.py`, see the [firmware map](MAP.md)).
2. **Dump** the machine code of every function as text, the *target assembly* (`tools/dump_asm.py`, written to
   `asm/<section>/<function>.s`).
3. **Write source** for one function at a time: C, or assembly where the original was written in assembly. It is
   built with the original toolchain and compiler flags.
4. **Check** the result:
   - LEON processors: `tools/diff.py` compares the instruction shapes with addresses masked out. `tools/exact.py`
     then links the object at the function's real address and requires identical bytes.
   - 8051: `tools/diff8051.py` compares the Keil object byte for byte, except for the bytes the linker fills in.
   - Tensilica program: `tools/xtensa_check.py` assembles the whole program and compares it byte for byte.
5. **Accept** the function: the source goes into `src/<section>/`, and `symbols/<section>.json` records it as matched,
   with its compiler flags and a one-line description (`tools/handaccept.py`, `tools/accept8051.py`).
6. **Re-verify** the whole matched set at any time (`tools/verify.py`, `tools/relink.py`).
7. **Rebuild** the complete image from source plus the remaining original bytes, and compare it with the original
   file (`tools/rebuild.py`):
   - Every matched function is built the way its check builds it and written at its place in a copy of the firmware.
     All other bytes stay original, as do the address fields that a check takes from the firmware instead of the
     build (jump-table, literal-pool and library addresses).
   - The script writes the image to `build/`, reports per section how many bytes come from source, from toolchain
     libraries and from the original file, and lists every byte that differs, with its function.

## Where first drafts come from

Each matched function records how its source was obtained in the `by` field of `symbols/<section>.json`.

| Method | `by` | Description |
|---|---|---|
| Mechanical clean-up | `autoc` | Ghidra's C with types, string literals and variable widths corrected automatically (`tools/autoc.py`, `tools/auto8051.py`). |
| Shape twins | `twin` | The source of a matched function, reused for another function with an identical instruction shape (`tools/twin.py`, `tools/twin8051.py`). |
| Libraries | `lib`, `keil-lib` | Toolchain library routines recognised byte for byte and imported unchanged (`tools/libmatch.py`, `tools/libimport.py`, `tools/keillib.py`). |
| Assembly | `asm` | Routines that were written in assembly in the original (trap tables, start-up code, privileged instructions), and the Tensilica program, whose C compiler is not available. |
| Search | `permuter`, `near` | Near-misses closed by automatic source permutation (`tools/permuter*.py`) or mechanical repair (`tools/nearfix.py`). |
| Individual work | `hand` | Written and tuned function by function. |
| Jump tables | `table` | A switch's table of jump addresses, proven entry for entry by the check of the function that uses it (`tools/acctable.py`). |
| Other | `template`, `data` | Keil start-up templates, and data that was mistaken for code. |

Most source files begin with a comment describing what the function does, who calls it, the data it uses, and any
source form the byte-exact build depends on. The [matching tricks](MATCHING-TRICKS.md) collect the most common of
these forms.

## Folders

| Folder | Contents |
|---|---|
| `firmware/` | The target image and earlier versions. |
| `asm/<section>/` | Target assembly, one file per function. |
| `src/<section>/` | Matched source, one file per function; a few 8051 files hold a Keil module of several functions, accepted per function. |
| `src/tensilica/` | The Tensilica program as assembly, one file per function plus its data. |
| `symbols/` | Names, status, flags and descriptions (`<section>.json`), function tables (`<section>.functions.json`), names taken from debug strings (`<section>.auto.json`), library matches and Keil register files. |
| `decomp/` | Ghidra output, as a reading aid. |
| `tools/` | Scripts. |
| `docs/` | Documentation. |

Some folders exist only locally and are not stored in git: `toolchains/`, `parts/`, `ghidra_proj/`, `build/`,
`work/` (scratch space) and the large Ghidra listing `decomp/leon2m.lst`.
