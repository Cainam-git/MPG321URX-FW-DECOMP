# Linked build

How the programs of the two LEON processors are built as linked programs in which code and data can move, and how
that build is checked.

`tools/rebuild.py` proves every function on its own: it builds the function for the exact address it has in
FW.021 and gives it the addresses of everything it refers to as fixed numbers. That proves the source, but it
cannot produce a firmware in which a function is longer or a table has moved. In the linked build every function,
every jump table and every piece of data is an input to the GNU linker, every reference between them is a symbol,
and the linker decides the addresses.

## What it covers

- The main processor (`leon2m`): its start-up code, its start values and its code window (EDID blocks, program,
  read-only data, menu fonts and texts, data image), 1,732,816 bytes in total.
- The input processor (`leon2s`): its first program part, its start values and its third program part, 484,869
  bytes in total.

| Kind of piece | Main processor | Input processor | Linked as |
|---|---:|---:|---|
| Functions written in C | 3,404 | 1,389 | The compiler's own output for the function, see [link view](#link-view). |
| Hand-written assembly functions | 262 | 270 | The assembled source file. |
| Toolchain library members | 69 (100 function-table entries) | none | The member taken from the toolchain's archive. |
| Data | everything else | everything else | Generated assembly: the original bytes, with a label at every address something refers to and a symbolic word at every stored address ([stored addresses](REFERENCES.md)). |

Not covered: the 8051 programs, and the Tensilica program (which is already built from relocatable assembly
source).

## The two proofs

1. **Identical when nothing moves.** Linked with every piece at its FW.021 address, and also linked with no fixed
   addresses at all in the code window (every piece follows the one before it), the result is byte-identical to
   the firmware: 0 of 1,732,816 bytes differ for the main processor and 0 of 484,869 for the input processor.
2. **Correct when something moves.** `tools/link/verify_shift.py` checks a link in which pieces have moved against
   the unmoved one, without relying on the linker:
   - every symbol moved exactly as far as the piece it belongs to;
   - the two images differ only inside relocation sites;
   - at every relocation site (62,266 in the main processor, 19,427 in the input processor) the new value is
     re-derived from the old one and the new layout: a call must reach the moved target from the moved site, a
     stored address and the two halves of an address in code must name the moved target.

   For the main processor it passes for a gap of 16 bytes in front of the program, a gap of 4 KB in the middle of
   the program, and for the realistic case: one function in the middle grows by one instruction and everything
   behind it follows on its own. For the input processor it passes for the same realistic case in the first and in
   the third program part.

`tools/link/hidden.py` looks for addresses the link does not know about. It compares every `sethi` instruction
that is not a relocation site with the same instruction in FW.020, FW.016 and FW.012 (through the
[version map](REFERENCES.md#how-the-leon-lists-were-made)). An address that moved between versions would show as a
changed high part. In the main processor, 64 of 12,551 such instructions differ in an older version: 27 are RAM
addresses, 22 are small numbers and 15 are two flag masks that changed value between versions. In the input
processor, 24 of 5,105 differ: 21 RAM addresses and 3 small numbers. None is an address of code or of data in a
program area.

## Limits

- **Not tested on a monitor.** Both proofs are comparisons on the PC. Nothing built this way has been flashed. The
  rules in [Modifying the firmware](MODIFYING.md) apply unchanged.
- **RAM and the start-up areas do not move.** Addresses of RAM are fixed numbers throughout (the source of the main
  processor writes 56 of them as numbers, that of the input processor 29), and so are the code addresses in the two
  trap tables (32 and 28): the start-up code of the main processor, and the trap table with its handlers at the
  start of the input processor's first part, keep their place. Code that is added must not need
  the RAM layout to change. Between MSI's own versions the RAM layout did change.
- **Data keeps its alignment.** The unpinned layout aligns every data piece as it was aligned in FW.021 (8, 4, 2 or
  1 bytes). In a few places the compiler computed the two halves of a RAM address for slightly different offsets,
  which is only valid while the object keeps its alignment; no such case exists for data in the code window.
- **Eight words are undecided** whether they are addresses (see [stored addresses](REFERENCES.md#limits)). They
  would point into the EDID area, which lies in front of the program and does not move when the program grows.
- **The partition table is not updated.** Its record for the code window (file offset 0x6020) holds the length of
  the window. A linked build of another length needs that field corrected.

## Running it

```
tools/link/build.sh leon2m                               # all steps; ends with the comparison of the pinned link (also leon2s)
python3 -I tools/link/gen.py leon2m --seq                # no fixed addresses in the code window
python3 -I tools/link/gen.py leon2m --seq --pad 0xa1d9c 4   # as if the piece at 0xa1d9c had 4 more bytes before it
python3 -I tools/link/verify_shift.py leon2m             # checks the last changed link against the pinned one
python3 -I tools/link/gen.py leon2s --seq --move P3 --pad 0x9f1c00e0 4   # input processor, third program part
python3 -I tools/link/hidden.py leon2m                   # needs the version maps (tools/refs/vmap.py --build)
```

All output goes to `work/link/`. The [tools overview](../tools/README.md#linked-build) lists the script of each
step.

## Link view

The C functions are not recompiled differently for the linked build. `tools/link/linkview.py` takes the assembly
that the compiler writes for each source file with the flags proven for it, and changes only where things live:

- Debug sections are dropped.
- Of the function bodies in a file, only the function the file is named after is kept. Some source files define
  copies of neighbouring functions so that the compiler can inline them; those neighbours are linked from their
  own files.
- Jump tables go into a section of their own. The compiler places all jump tables of a source file in front of the
  file's functions, so in the firmware a table is not always next to its function.
- The file's own texts and constants are not linked from the file. The original link merged identical texts and
  constants of all files into shared pools, so they are kept in the data and each reference gets a symbol for the
  place where the firmware holds that text or constant.
- Names that carry an address (`func_0x…`) are replaced by the name of the function they mean (see
  [stored addresses](REFERENCES.md#addresses-written-as-numbers-in-the-source)).

The library members get the same treatment for their constants and their own data (`tools/link/elfsplit.py`
rewrites the relocations of the archive member, nothing else). `__sprint` (`FUN_a0157a20`) is part of `vfprintf.o`,
not `vfiprintf.o`; both contain the same function.

`tools/link/symtab.py` then establishes the address of every symbol from the firmware itself: at each place where
a function refers to the symbol, the call displacement or address halves in the firmware must agree. For the 4,015
symbols the C functions of the main processor refer to and the 2,719 of the input processor, every reference
agrees.

## Addresses in the source

The source writes code-window addresses as symbols, with one exception:

- **C files.** A code-window address is written as the text itself or as a symbol (`s_<address>` for a text,
  `DAT_<address>` for other data). 79 files passed such addresses as plain numbers before, mostly the address of a
  text handed to a print function; they are still byte-exact.
- **The exception.** `osd_draw_gaming_items` (`FUN_a00ad02c`) is only byte-exact with the number; the link view
  turns that one number into a symbol (`symbols/leon2m.numsym.json`).
- **Assembly.** `src/leon2m/trap/trap_dump_crash_and_halt.S` writes its code-window addresses as symbols, where
  it formed them from numeric halves before (34 high parts with their low parts).
- **Input processor.** One address literal (`DRV_HDMI21_LMS_To_EQ`, the address of a text) is a symbol.
