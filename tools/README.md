# Tools

Run every script from the repository root with `python3 -I`; each one starts with a short usage description.
Settings and toolchain paths are in `config.json`. Temporary output goes to `work/`, which is not stored in git. The
toolchains themselves are described in the [build guide](../docs/BUILD.md).

## Firmware

| Script | Purpose |
|---|---|
| `split.py` | Cuts the firmware into the parts each processor runs (`parts/`). |
| `dump_asm.py` | Writes the target assembly of every function (`asm/<section>/`). |
| `decompile.sh`, `reanalyze8051.sh`, `ghidra/` | Run Ghidra without a user interface: import, naming and export (`decomp/`, `symbols/*.auto.json`). |
| `rebuild.py` | Builds the complete image from every matched function plus the original bytes for the rest, and compares it with the original file. |
| `fwdiff.py` | Compares functions between firmware versions, with addresses masked out. |
| `xref.py`, `lst8051.py`, `extract_func.py` | Reading aids for a single function. |

## Checking and accepting

| Script | Purpose |
|---|---|
| `diff.py`, `exact.py` | Check for the LEON processors: instruction shape first, then exact bytes linked at the real address. |
| `diff8051.py`, `lx51judge.py`, `batch8051.py` | Checks for the 8051 (Keil C51 under Wine), including the LX51 linker variant and batch runs. |
| `strcheck.py` | Confirms that every string literal in a source file exists in the firmware. |
| `handaccept.py`, `accept8051.py`, `accept.py` | Accept a byte-exact, documented source into `src/` and `symbols/`. |
| `check/acc.sh`, `check/acc2s.sh` | Accept a function of the main or input processor in one step: check, raw comparison, accept, commit. |
| `check/jf.py`, `check/rawcmp.py`, `check/rawcmp_l2s.py` | Check with one fixed set of compiler flags, and an independent raw word comparison. |
| `check/shapej.py`, `check/casecmp.py`, `check/jtscan.py`, `check/p2o3*.py` | Register-independent shape comparison, switch-case comparison, jump-table scan, and permutation search with fixed flags. |
| `verify.py`, `relink.py` | Re-check or rebuild every matched function. |
| `xtensa_check.py`, `xtensa_gen.py` | Build the Tensilica program from `src/tensilica/` and compare it with the firmware; regenerate those files from the firmware (this overwrites them). |
| `acctable.py` | Records a LEON jump table (`switchdataD_*`) as matched when the exact check of a matched function proves it entry for entry; with `--gaps` it also adds tables that had no entry in the function table yet. |
| `progress.py` | Counts matched functions and bytes per section. |
| `stats.py` | Updates the progress bars in `README.md` and the table in `docs/STATUS.md`. |

## Mechanical matching

| Script | Purpose |
|---|---|
| `autoc.py`, `auto8051.py` | Clean up Ghidra's C for every function, then compile and check it. |
| `twin.py`, `twin8051.py`, `sibling.py` | Reuse the source of a matched function for functions with the same shape. |
| `libmatch.py`, `libimport.py`, `keillib.py`, `keil_helpers.py` | Find toolchain library functions in the firmware and import them unchanged. |
| `asmgen.py`, `asm8051.py`, `startup8051.py` | Assembly routines and the 8051 start-up code. |
| `permute.py`, `permuter.py`, `permuter2.py`, `permute8051.py`, `basefix.py`, `nearfix.py` | Automatic searches that close near-misses. |
| `near.py`, `piles.py`, `splits.py`, `mergetails.py`, `inlined.py`, `sigs.py` | Sorting near-misses and repairing the function table. |
| `regfile8051.py` | Rebuilds the Keil register files (`symbols/8051_bank*.orc`). |
