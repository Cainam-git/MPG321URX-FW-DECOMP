# Tools

One line per script, grouped by task. Run every script from the repository root with `python3 -I`; each one starts
with a short usage description. Settings and toolchain paths are in `config.json`. Temporary output goes to `work/`.
The set-up and the commands are in the [build guide](../docs/BUILD.md).

## Rebuilding and verifying

| Script | Purpose |
|---|---|
| `split.py` | Cuts the firmware file into the parts each processor runs (`parts/`). |
| `rebuild.py` | Builds every function and the menu's fonts and texts, writes the complete firmware file and compares it with the original. |
| `verify.py`, `relink.py` | Build and check every function again, one by one. |
| `xtensa_check.py` | Builds the Tensilica program from `src/tensilica/` and compares it with the firmware. |
| `osd_check.py`, `osd_build.py` | Build the menu fonts and texts from `src/osd/` and compare them with the firmware (see [Menu fonts and texts](../docs/OSD-TEXT.md)). |
| `osd_gen.py` | Writes `src/osd/` from the firmware. |
| `progress.py` | Counts finished functions and bytes per section. |
| `stats.py` | Updates the progress bars in `README.md` and the table in `docs/STATUS.md`. |

## Checking and accepting one function

| Script | Purpose |
|---|---|
| `diff.py`, `exact.py` | Check for the LEON processors: instruction shape first, then exact bytes linked at the real address. |
| `diff8051.py`, `lx51judge.py`, `batch8051.py` | Checks for the 8051 (Keil C51 under Wine), including the variant built with the LX51 linker, and batch runs. |
| `startup8051.py` | Rebuilds the 8051 start-up code from Keil's templates and checks it. |
| `strcheck.py` | Confirms that every string literal in a source file exists in the firmware. |
| `handaccept.py`, `accept8051.py`, `accept.py` | Accept a byte-exact, documented source file into `src/` and `symbols/`. |
| `check/acc.sh`, `check/acc2s.sh` | Accept a function of the main or input processor in one step: check, raw comparison, accept, commit. |
| `check/jf.py`, `check/rawcmp.py`, `check/rawcmp_l2s.py` | Check with one fixed set of compiler flags, and an independent comparison of the raw instruction words. |
| `acctable.py` | Records a LEON jump table (`switchdataD_*`) as matched when the check of the function that uses it proves it entry for entry. |

## Reading the firmware

| Script | Purpose |
|---|---|
| `xref.py` | Prints the target assembly of one main-processor function with its debug strings, call targets and callers. |
| `lst8051.py`, `extract_func.py` | Print Ghidra's listing or C of one function. |
| `fwdiff.py` | Finds a main-processor function of FW.021 in FW.012 and compares the two, with addresses masked out. |
| `decompile.sh`, `reanalyze8051.sh`, `ghidra/` | Run Ghidra without a user interface: import, naming and export (`decomp/`, `symbols/*.auto.json`). |
| `dump_asm.py` | Writes the target assembly of every function (`asm/<section>/`). Only needed after a change to the function table. |

## Finding out why a function does not match

For rewriting a source file, and for other firmware built with the same compilers (see the
[matching guide](../docs/MATCHING-TRICKS.md)).

| Script | Purpose |
|---|---|
| `show.py` | Compiles a LEON source file with every flag set of its section and prints only the lines that differ from the firmware, for the best flag set. |
| `judge2.py` | Prints how close a LEON source file is to the firmware for one flag set, with and without register names. |
| `regions.py` | Compares a LEON source file with the firmware range by range, and shows where its local variables are kept on the stack. |
| `stseq.py` | Compares the order of memory writes between a LEON build and the firmware. |
| `check/shapej.py`, `check/casecmp.py`, `check/jtscan.py` | Comparison without register names, comparison of the branches of a `switch`, and a scan for jump tables. |
| `lsim.py` | A model of how GCC assigns registers within one block of code, for testing what a change in the source would do. |
| `permuter.py`, `permuter2.py`, `permute.py`, `check/p2o3*.py` | Automatic search: try many equivalent ways of writing a nearly exact function and keep the ones that come closer (uses decomp-permuter). |
| `mutsearch.py` | Automatic search over small changes that keep the meaning: order of statements and declarations, variable types, order of `case` blocks. |
| `near.py` | Lists how far a set of drafts is from exact and what kind of difference is left. |

## Names and source files

[Function names](../docs/NAMES.md#changing-names) gives the options of these scripts and the order to run them in.

| Script | Purpose |
|---|---|
| `srcpath.py` | Says where the source file of a label is and which label a file belongs to, and puts a file's side list of names in front of it for the compilers; every script that builds or reads source files goes through it. |
| `names/apply.py` | Writes the function names (`symbols/<section>.names.json`) and data names (`symbols/<section>.data.json`) into the header comments, the code and the side lists of a section's source files. |
| `names/xt_apply.py` | Renames the labels of the Tensilica program in `src/tensilica/` to the names of `symbols/tensilica.names.json` and `symbols/tensilica.data.json`. |
| `names/layout.py`, `names/xt_layout.py` | Name each source file after its function and move it into a folder for its subject. |
| `names/pathrefs.py` | Corrects the comments and pages that mention a source file by its former name. |
| `names/index.py` | Writes the readable index pages `docs/names/<section>.md` (functions) and `docs/names/<section>-data.md` (data). |
| `names/records.py` | Writes `docs/RECORDS.md`: the named fields of the principal records, by offset. |

## Stored addresses and code outside the function table

The method and the results are in [Stored addresses](../docs/REFERENCES.md).

| Script | Purpose |
|---|---|
| `refs/vmap.py`, `refs/vmap_check.py` | Map every position of FW.021 to the same position in the three older versions, and check that map. |
| `refs/scan.py`, `refs/classify.py` | Collect every value in the LEON sections that could be a stored address, and settle each one by evidence (`symbols/<section>.refs.json`). |
| `refs/8051/` | The same for the three 8051 programs, including the partition table (`scan.py`, `refs.py`, `check.py` and their helpers). |
| `refs/srclit.py`, `refs/srcclass.py` | List the addresses that the C and assembly source write as plain numbers (`symbols/<section>.srcaddr.json`). |
| `refs/aliases.py` | Lists the names in the C source that carry an address instead of naming a function (`symbols/<section>.aliases.json`). |
| `refs/gapfn.py` | Examines the space between the listed functions of the LEON sections for code that is in no function-table entry. |

## Linked build

The method, the checks and the commands are in [Linked build](../docs/LINKING.md).

| Script | Purpose |
|---|---|
| `link/build.sh` | Runs all steps for a LEON section and compares the linked program with the firmware. |
| `link/inventory.py` | Builds every function as `rebuild.py` does and records the flags that make it exact, its sections and what it refers to. |
| `link/linkview.py` | Writes the link view of every C function and reads every reference back from the firmware. |
| `link/symtab.py` | Establishes one address per symbol from the firmware, proven at every reference. |
| `link/extra.py`, `link/elfsplit.py` | The same for the assembly functions and the toolchain library members. |
| `link/gen.py` | Generates the data files and the linker script, links (with fixed addresses, without them, or with a piece moved) and compares with the firmware. |
| `link/verify_shift.py`, `link/hidden.py` | Check a link in which something moved, and search for addresses the link does not know about. |

## How the function table and the first sources were made

| Script | Purpose |
|---|---|
| `autoc.py` | Cleans up Ghidra's C for a function, then compiles and checks it. |
| `libmatch.py`, `libimport.py`, `keillib.py`, `keil_helpers.py` | Find toolchain library routines in the firmware and import them unchanged. |
| `asmgen.py`, `asm8051.py` | Produce assembly source for functions that were written in assembly in the original. |
| `splits.py`, `mergetails.py`, `sigs.py` | Repair Ghidra's function table (functions glued together, return stubs split off) and pass function signatures back to Ghidra. |
| `regfile8051.py` | Rebuilds the Keil register files (`symbols/8051_bank*.orc`). |
| `xtensa_gen.py` | Writes `src/tensilica/` from the firmware; running it again overwrites those files, which are edited by hand, and loses their names and comments. |
