# Workflow guide

This project uses *matching decompilation*, the approach known from the Super Mario 64 and Ocarina of Time
decompilations: source code is accepted only when it compiles back to exactly the original bytes. The exact match
proves the source, because a wrong reading of a function does not compile to the same bytes.

This page gives the method and the rules. The commands are in the [build guide](BUILD.md), the scripts in the
[tools overview](../tools/README.md).

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
5. **Accept** the function (`tools/handaccept.py`, `tools/accept8051.py`): the source goes into its file under
   `src/<section>/`, and `symbols/<section>.json` records it as matched, with its compiler flags and how it was
   matched.
6. **Re-verify** the whole set at any time (`tools/verify.py`, `tools/relink.py`).
7. **Rebuild** the complete firmware file and compare it with the original (`tools/rebuild.py`). Every function is
   built the way its check builds it and written at its place in a copy of the firmware; all other bytes stay
   original. The build guide describes [the report](BUILD.md#rebuilding-and-verifying-everything).

Steps 1 to 5 are finished for every function of FW.021. Steps 6 and 7 are the checks to run after any change to the
source.

## How the source was obtained

The `by` field of `symbols/<section>.json` records, per function, how its source was obtained. Whatever the method,
the same check decides: the build must give the original bytes.

| Method | `by` | Description |
|---|---|---|
| Individual work | `hand` | Written and adjusted function by function until the build was exact. Most functions. |
| Mechanical clean-up | `autoc` | Ghidra's C with types, string literals and variable widths corrected automatically (`tools/autoc.py`), accepted when that already built exact. |
| Shape twins | `twin` | The source of a finished function, reused for another function with an identical instruction shape. |
| Libraries | `lib`, `keil-lib` | Toolchain library routines recognised byte for byte and imported unchanged (`tools/libmatch.py`, `tools/libimport.py`, `tools/keillib.py`). |
| Assembly | `asm` | Functions that were written in assembly in the original (trap tables, start-up code, privileged instructions), and the Tensilica program, whose C compiler is not available. |
| Search | `permuter`, `near` | Drafts that were a few instructions away from exact, finished by an automatic search over equivalent ways of writing the same code (`tools/permuter*.py`) or by a mechanical repair. |
| Jump tables | `table` | A switch's table of jump addresses, proven entry for entry by the check of the function that uses it (`tools/acctable.py`). |
| Interrupt vectors | `vector` | The `LJMP` that Keil C51 places for an interrupt function, checked against that function's source (`tools/diff8051.py`). |
| Other | `template`, `data` | Keil start-up templates, and data that the decompiler had mistaken for code. |

## Reading a source file

Every C file starts with a comment that says what the function does, who calls it, the data it uses and the data
layouts it relies on, and any *source form* the byte-exact build depends on: a detail of how the code is written
(the type of a variable, the order of two statements, a helper function) that changes what the compiler produces.
The [matching guide](MATCHING-TRICKS.md) collects the most common of these forms, and the [glossary](GLOSSARY.md)
explains the short terms used in the comments.

Names of the form `FUN_a00dac38` and `DAT_a802d9a0` are Ghidra's automatic labels: the kind of object and its
address. The [firmware map](MAP.md#address-numbering) explains how these addresses relate to positions in the
firmware file. In the LEON and 8051 programs every function also has a descriptive name: the file is named after
it, the name stands at the top of the file's header, and the code uses it (see
[Names in the source](NAMES.md#names-in-the-source)). The part of the header under *Matching notes* describes the
code by labels and addresses.

## Rules the source follows

A change to a file in `src/` keeps to the rules the existing source was written under:

1. **The build stays byte-exact.** A changed function must still give the original bytes at its real address, and
   `python3 -I tools/rebuild.py` must still report a file that is byte-identical to the original.
2. **One file per function**, `src/<section>/<subject>/<name>.c` (or `.S`), starting with the comment described
   under [Reading a source file](#reading-a-source-file). Comments describe the code only.
3. **The source reads as its authors could have written it.** Not used: branch hints, `volatile` on ordinary
   memory, inline assembly (other than a `nop` that the firmware really contains), and names or variables chosen
   only for their effect on the compiler. A statement that leaves no instructions of its own, such as an extra
   `case` label or an empty test, is used only when the function cannot be reproduced without it. The file header
   then says so and gives the evidence, and the function is listed in the
   [status report](STATUS.md#reconstructed-statements) when the firmware does not show how the statement was worded.
4. **Ghidra's labels stay** as the symbols the files share (`FUN_…`, `DAT_…`), because the checking tools link by
   those names. Descriptive names are not typed into the code by hand: they are kept in
   `symbols/<section>.names.json`, and tools write them into the files and name the files after them (see
   [Changing names](NAMES.md#changing-names)).
5. **Changes are recorded through the tools** (`tools/handaccept.py`, `tools/accept8051.py` or
   `tools/check/acc*.sh`), which check the file again and store its status and compiler flags
   in `symbols/<section>.json`.

## Folders

| Folder | Contents |
|---|---|
| `firmware/` | The target file, earlier versions and two custom versions. |
| `asm/<section>/` | Target assembly, one file per function. For the 8051 programs `asm/8051_bank<n>.lst` holds one listing per program. |
| `src/<section>/<subject>/` | Source, one file per function, named after it; a few 8051 files hold a Keil module of several functions, accepted per function. |
| `src/tensilica/` | The Tensilica program as assembly, one file per function plus its data. |
| `symbols/` | Per section: the status, compiler flags and how each function was matched (`<section>.json`), the function table (`<section>.functions.json`), names taken from debug strings (`<section>.auto.json`), the function and data names (`<section>.names.json`, `<section>.data.json`), the path of every source file (`<section>.files.json`); also library matches and Keil register files. |
| `symbols/defs/<section>/` | The side list of names of each C file, which the build puts in front of it. |
| `tools/` | Scripts. |
| `docs/` | Documentation. |

The folders that exist only locally and are not stored in git are listed in the
[build guide](BUILD.md#local-folders).
