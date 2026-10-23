# Build guide

## Toolchains

The toolchains are not stored in git. They live in a `toolchains/` folder inside the repository, at the paths that
`tools/config.json` and the scripts expect.

| Purpose | Toolchain | Location |
|---|---|---|
| Compiling for the LEON processors | Gaisler BCC 1.0.52 with GCC 3.4.4 | `toolchains/sparc-elf-3.4.4/` |
| Disassembly for `tools/fwdiff.py` | Gaisler BCC 1.0.52 with GCC 4.4.2 | `toolchains/sparc-elf-4.4.2/` |
| Compiling for the 8051 | Keil C51 9.60 evaluation edition, running under Wine | `toolchains/keil-prefix/` (a Wine prefix) |
| Permutation search | decomp-permuter | `toolchains/decomp-permuter/` |
| Compiler internals (optional) | GCC 3.4.4 source code | `toolchains/gcc-3.4.4-src/` |
| Decompiler | Ghidra 12 | `/opt/ghidra`, or set `GHIDRA_HOME` |

Besides these, the scripts only need Python 3 (without extra packages) and, for the 8051, Wine. The setup below was
tested with Python 3.14, Wine 11.20 and Ghidra 12.1.2. Run all scripts from the repository root with `python3 -I`.

## Setting up a new machine

1. **Download the files** listed under [downloads](#downloads), and check their SHA-256 checksums.
2. **Unpack the two Gaisler toolchains** into `toolchains/`. Each archive contains its own folder:

   ```
   tar -xjf sparc-elf-3.4.4-1.0.52.tar.bz2 -C toolchains/
   tar -xjf sparc-elf-4.4.2-1.0.52.tar.bz2 -C toolchains/
   ```

3. **Install Keil C51 into its own Wine prefix.** The installer runs silently and installs to
   `toolchains/keil-prefix/drive_c/Keil_v5/`. Disabling `winemenubuilder` keeps Wine from adding Keil to the desktop
   menu and from registering file associations:

   ```
   export WINEPREFIX="$PWD/toolchains/keil-prefix" WINEDEBUG=-all WINEDLLOVERRIDES="winemenubuilder.exe=d"
   wineboot -i
   wine C51V961.exe /S
   ```

4. **Get decomp-permuter**, at the commit used here:

   ```
   git clone https://github.com/simonlindholm/decomp-permuter toolchains/decomp-permuter
   git -C toolchains/decomp-permuter checkout 8556c81d80d1c1af98a858c8f4dc951357f29139
   ```

5. **Optionally unpack the GCC 3.4.4 source** into `toolchains/gcc-3.4.4-src/`, for reading the compiler's internals.
6. **Install Ghidra** (on Arch Linux: `pacman -S ghidra`). It is only needed to regenerate `decomp/`.
7. **Split the firmware** into the parts each processor runs. The checking tools read them from `parts/`:

   ```
   python3 -I tools/split.py firmware/MSI_MPG321URX_V021_7F69.bin parts
   ```

8. **Check the setup** by running `python3 -I tools/verify.py 8051_bank0 leon2s`. Every function should verify,
   apart from the entries listed in the [status report](STATUS.md#verification).

## Downloads

| File | Source | Size (bytes) | SHA-256 |
|---|---|---:|---|
| `sparc-elf-3.4.4-1.0.52.tar.bz2` | [download.gaisler.com/anonftp/bcc/bin/linux](https://download.gaisler.com/anonftp/bcc/bin/linux/) | 62,204,306 | `0e864c0e1f4cf0b3816f56132635dbcc6e78a68db80d664be1a87bfe93d210a5` |
| `sparc-elf-4.4.2-1.0.52.tar.bz2` | [download.gaisler.com/anonftp/bcc/bin/linux](https://download.gaisler.com/anonftp/bcc/bin/linux/) | 52,473,470 | `9e2cbb787d3cc4cf30c8aa730ed50eace70caae7d784a4e66b22b001ff4d5765` |
| `C51V961.exe` | [Keil C51 evaluation](https://www.keil.com/demo/eval/c51.htm) (free, after a registration form) | 109,869,064 | `f23f2f5a5eda77d710ed8cf50ff44a04f35260afefe082b352ac08c059b63379` |
| `gcc-3.4.4.tar.bz2` | [ftp.gnu.org/gnu/gcc/gcc-3.4.4](https://ftp.gnu.org/gnu/gcc/gcc-3.4.4/) | 27,565,872 | `3444179840638cb8664e8e53604900c4521d29d57785a5091202ee4937d8d0fd` |

Keil may offer a newer installer than `C51V961.exe`. A different compiler version can produce different code, so
check that the 8051 functions still verify before relying on it.

## Regenerating local folders

```
python3 -I tools/split.py firmware/MSI_MPG321URX_V021_7F69.bin parts   # Per-processor parts
./tools/decompile.sh                                                     # Ghidra project, decomp/, symbols/*.auto.json
python3 -I tools/dump_asm.py leon2m                                      # Target assembly (already committed;
python3 -I tools/dump_asm.py leon2s                                      # only needed after function-table changes)
```

## Checking and accepting a function

```
python3 -I tools/diff.py leon2m FUN_a00dac38 build/x.o          # LEON: shape, then exact bytes at the real address
python3 -I tools/diff8051.py 8051_bank1 FUN_CODE_7b5a src.c     # 8051
python3 -I tools/handaccept.py leon2m hand FUN_a00dac38 src.c "One-line description"
python3 -I tools/accept8051.py 8051_bank1 hand FUN_CODE_7b5a src.c "One-line description"
tools/check/acc.sh  hand FUN_a00dac38 src.c "One-line description" [flags]   # Main processor: check, compare, accept, commit
tools/check/acc2s.sh hand FUN_a0060000 src.c "One-line description" [flags]  # Input processor: the same
```

`handaccept.py` and `accept8051.py` refuse any source that is not byte-exact or has no descriptive comment.

## Verifying everything

```
python3 -I tools/verify.py leon2m leon2s 8051_bank0 8051_bank1 8051_bank2
python3 -I tools/relink.py leon2m leon2s --jobs 8
python3 -I tools/progress.py
python3 -I tools/rebuild.py                    # The complete image, compared with the original file
```

A few entries are checked by other tools than `verify.py`, for example the 8051 start-up code by
`tools/startup8051.py`. The [status report](STATUS.md#verification) lists them all.

`tools/rebuild.py` builds every matched function, including those entries, and writes it at its place in a copy of
the firmware; all other bytes stay original. It writes `build/MSI_MPG321URX_V021_rebuilt.bin` (or the path given as
its first argument) and a report next to it (`.txt`), and exits with 1 unless the image is byte-identical to
`firmware/MSI_MPG321URX_V021_7F69.bin` and every function was built exact. The report gives, per section:

- **source:** bytes built from C and assembly;
- **library:** bytes of toolchain library routines (`.lib` entries);
- **original:** bytes taken from the firmware, including (**fields**) the address fields inside built functions that
  a check takes from the firmware (jump-table and literal-pool addresses, library fixups);
- **differ:** bytes of the rebuilt image that are not the original's, each listed with its address and function.

It also lists functions that are exact only with flags that `symbols/<section>.json` does not record. Options:
`--jobs N` (parallel builds, default 4; Keil runs at most 2 at a time) and `--sections leon2m ...` (build only these
sections; the others stay original). The whole firmware takes about a minute.
