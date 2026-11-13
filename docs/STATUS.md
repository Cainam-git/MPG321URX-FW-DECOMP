# Status report

How much of the firmware is rebuilt from source, how that is counted and checked, and what is left.

## Progress

| Processor | Section | Matched bytes | Total bytes | Matched | Matched entries | Entries |
|---|---|---:|---:|---:|---:|---:|
| Main processor | `leon2m` | 941,056 | 941,056 | 100.0 % | 3,968 | 3,968 |
| Input processor | `leon2s` | 412,360 | 412,360 | 100.0 % | 1,702 | 1,702 |
| Helper processor | `8051_bank0` (boot loader) | 6,182 | 6,182 | 100.0 % | 52 | 52 |
| Helper processor | `8051_bank1` (main application) | 53,244 | 53,244 | 100.0 % | 431 | 431 |
| Helper processor | `8051_bank2` (update agent) | 52,590 | 52,590 | 100.0 % | 283 | 283 |
| Tensilica processor | `8051_bank3` (Xtensa program image) | 65,536 | 65,536 | 100.0 % | 307 | 307 |
| **Total** | | **1,530,968** | **1,530,968** | **100.0 %** | **6,743** | **6,743** |

`python3 -I tools/stats.py` recounts and rewrites this table and the progress bars in the README. The helper
processor of the table is the 8051; the section names are those of the tools.

The entries are those of the function tables, which hold more than functions:

| Kind of entry | Entries |
|---|---:|
| Functions written as C | 5,276 |
| Functions and pieces kept as assembly (the trap and interrupt code of the LEON programs, the Tensilica program) | 838 |
| Library routines, taken unchanged from the toolchains' libraries | 272 |
| Jump tables of `switch` statements, built with their function | 245 |
| Pieces that the tables list apart from the function they belong to | 96 |
| Data and fill recorded as such | 8 |
| Start-up templates of the 8051 compiler | 6 |
| Interrupt vectors | 4 |

That is 6,745: two pieces of the update agent are recorded on their own without an entry in its function table.
The Tensilica program is assembly reproduced from the disassembly, not decompiled C, and the 65,536 bytes of its
section include 10,020 bytes of 0xFF fill behind the 55,516-byte program.

## What the rebuilt file consists of

`python3 -I tools/rebuild.py` builds the complete firmware file and compares it with the original. Its report
counts where every byte of the 2,820,096-byte file comes from:

| Origin | Bytes | Share |
|---|---:|---:|
| Built from the source in `src/` (C, assembly, and the menu's fonts and texts) | 2,057,640 | 73.0 % |
| Functions taken from the toolchains' own libraries | 47,693 | 1.7 % |
| Copied from the original file | 714,763 | 25.3 % |

This table and the progress table count different things: the progress table adds up the sizes of the function-table
entries, this one counts every byte of the file once, by where the rebuild takes it from.

The copied part is what is neither program code nor menu font or text: tables, the EDID blocks, initial
values of variables, the partition table and empty space. It includes 8,001 bytes of address fields inside built
functions (jump-table, literal-pool and library addresses) that the checks take from the firmware.

## Definitions

- **Matched:** The file in `src/<section>/`, built with the compiler flags recorded in `symbols/<section>.json`
  (or, where none are recorded, with one of the section's flag sets in `tools/config.json`),
  reproduces the original bytes at the function's address.
  - For the LEON processors, `tools/diff.py` first compares the instruction shapes. `tools/exact.py` then links the
    object at its real address and requires identical bytes.
  - For the 8051, `tools/diff8051.py` compares the Keil object byte for byte, except for the bytes the linker fills in.
- **Library functions:** Functions recognised byte for byte in the toolchains' own libraries (`tools/libmatch.py`,
  `tools/libimport.py`, `tools/keillib.py`) count as matched. They are recorded as `.lib` entries.
- **Jump tables:** A LEON jump table (`switchdataD_*` entry) counts as matched when the exact check of the matched
  function whose switch uses it proves every entry (`tools/acctable.py`, recorded with `"kind": "jump_table"`):
  the compiled table's targets equal the firmware words at the address the function loads.
- **Function counts:** These come from Ghidra's function table (`symbols/<section>.functions.json`), corrected with
  `tools/splits.py` and `tools/mergetails.py`, and by hand where a function's jump-table case blocks, return tail or
  a second function lay outside or inside its listed range.
- **Byte counts:** The address ranges of the entries in `symbols/<section>.functions.json`.
- **The Tensilica program:** Flash bank 3 (section `8051_bank3`) holds no 8051 code. It holds the program of the
  chip's Tensilica Xtensa core, followed by empty space (see the [firmware map](MAP.md#the-tensilica-program)).
  The 1,205 pieces of it that Ghidra had marked as 8051 functions were all false. The program is kept as assembly
  source in `src/tensilica/` (one file per function), which the free Xtensa assembler builds to the original bytes
  (`tools/xtensa_check.py`, see [toolchains](TOOLCHAINS.md)). Each function and data region has its own entry,
  counted as matched (`"by": "asm"`); the zero fill between functions belongs to the following entry. The empty
  space after the program is recorded as data.
- **Completeness of the function tables:** The tables came from the decompiler, which lists only code that
  something calls or jumps to. The space between the listed functions of the two LEON sections was therefore
  examined separately (`tools/refs/gapfn.py`, see [Stored addresses](REFERENCES.md#code-outside-the-function-table)):
  99 small functions that nothing calls directly were added (most are unused, a few are reached through stored
  addresses), 223 listed functions were extended over the `nop` behind their final call, the ranges of the
  hand-written start-up assembly were corrected so that every code byte lies in an entry, and one unused function
  was added to 8051 bank 1. A scan of everything outside the listed functions for instruction patterns finds no
  further code in the LEON sections.

## Verification

`python3 -I tools/verify.py leon2m leon2s 8051_bank0 8051_bank1 8051_bank2 8051_bank3` rebuilds every matched function and
compares it with the firmware. The entries below are not confirmed by that script; each is checked another way.

| Entry | How it is checked |
|---|---|
| `leon2s FUN_a0083648` | The shape comparison reports a difference because the firmware listing shows the low part of an address as a literal (its high part sits in a branch delay slot); the byte-exact link check (`tools/exact.py`) passes. |
| `leon2s FUN_a00d0d78` | Its switch table holds the addresses the code runs at, which are 0xF10000 below the numbers in the function names (see the [firmware map](MAP.md#address-numbering)); `tools/exact.py` checks every table entry at that shift and the rest of the bytes as usual. |
| Start-up code of 8051 banks 0, 1 and 2 (`FUN_CODE_13f7`, `FUN_CODE_a627`, `FUN_CODE_d426` and their reset jumps) | Rebuilt from Keil's `STARTUP.A51` and `INIT.A51` with `tools/startup8051.py`. |
| `8051_bank0 FUN_CODE_123a`, `FUN_CODE_1249` | Keil entry code generated by the file that calls it (`src/8051_bank0/flash/flash_setup_bus_mode.c`), and checked together with that file. |
| `8051_bank0 FUN_CODE_7400`, `FUN_CODE_7527`, `FUN_CODE_7f9d` | Not code: zero padding inside the slot area, recorded as data. |
| `8051_bank2 FUN_CODE_c395`, `FUN_CODE_c433`, `FUN_CODE_c441` | Not code: bytes inside Keil's `?C_INITSEG` initialisation records (0xC36D..0xC44E), recorded as data. |
| `8051_bank1` interrupt vectors at 0x0003, 0x000B, 0x0013, 0x0023 | The `LJMP` that C51 places for `interrupt n` of a matched interrupt function; `tools/diff8051.py` (`vector`) checks the interrupt number in that function's source and the jump target. |
| `8051_bank2 FUN_CODE_f080` | Not code: 0xFF fill; the apparent jumps to it are the bytes of `MOVX @DPTR,A; SJMP` inside matched functions. Recorded as data. |
| `8051_bank2 FUN_CODE_cee9` | Built with the LX51 linker's code packing and checked with `tools/lx51judge.py`. |

## Known deviations from strict C

- `8051_bank1 FUN_CODE_8c5d`: the bit accumulator `b` is read before it is assigned, exactly as in the firmware,
  which has no store to it before the loop. The loop shifts all eight initial bits out, so the returned value does
  not depend on the initial contents. Initialising it would add two instructions the firmware does not have.

## Reconstructed statements

Three functions of the main processor contain one statement each that the firmware requires but does not show:
without a statement of that kind at that place the function does not build to the original bytes, and the statement
itself leaves no instruction. Each file header states the evidence and what cannot be recovered from the bytes.
The behaviour of the three functions does not depend on these statements.

- `leon2m FUN_a0133384`: the first two records stand in a `while (1) { ...; break; }` block. The same block makes
  this function byte-exact in two other firmware images built from the same SDK. Not recoverable: where the loop
  starts and how it was spelled.
- `leon2m FUN_a0125e60`: one test of the last read value with an empty arm after the two reads. The same test is
  needed by the 247-word build of this function in another firmware of the same SDK. Not recoverable: the compared
  value and what the arm held, if anything.
- `leon2m FUN_a014e26c`: an if / else-if chain of three tests with empty arms in front of the single call. Not
  recoverable: what was tested and what the arms held, if anything.

## Remaining work

The program code is complete, and the source is written out with names and comments. What is left:

- **Data as source.** The menu's fonts and texts are source files (`src/osd/`, see
  [Menu fonts and texts](OSD-TEXT.md)). The rest of the [copied part](#what-the-rebuilt-file-consists-of) of the
  file is not described by source files.
- **Names.** Every function of the two LEON programs, the three 8051 programs and the Tensilica program has a
  descriptive name and a description (see [Function names](NAMES.md)). 2,134 of the 6,739 entries of the names tables describe the
  operation only, because the firmware does not show the purpose. Of the stored data, 2,542 objects have names
  (`symbols/<section>.data.json`); data whose purpose the code does not show keeps its label. The local variables of
  the Tensilica program's functions are stack slots, named in the comments only.
- **Two counts.** The function tables hold 6,743 entries, the names tables 6,739. The function table of the
  Tensilica program has 307 entries: 300 functions and 7 other pieces (vectors, reset code, literals, data,
  read-only data, the section table and the fill behind the program); its names table has 301, the 300 functions
  and one handler inside the vector piece. The names table of the update agent has 285 entries, 2 more than its
  function table: two pieces that the function table does not list on their own.
- **Shared types.** Each source file declares the layout of the records it uses itself, so that it builds on its
  own. The fields of the principal records are listed in [Record fields](RECORDS.md); they are not collected in
  shared header files.
- **A relocatable build.** `tools/rebuild.py` builds every function for the address it has in FW.021. For the two
  LEON processors a [linked build](LINKING.md) exists in which code and data can move. It is proven on the PC only
  (identical when nothing moves, every reference correct when something moves) and has not been run on a monitor.
  The 8051 programs are not linked this way. A build in which code can grow or move needs one linked program per
  processor, with all addresses as symbols; the list of every address the firmware stores outside its
  instructions, which such a build needs, is complete (see [Stored addresses](REFERENCES.md)). Until such a build
  has been tested on hardware, the firmware should only be changed in place (see
  [Modifying the firmware](MODIFYING.md)).
- **The Tensilica program as C.** It is rebuilt from assembly source; C source would need its original compiler,
  which is not available.
