# Build guide

How to set up the original toolchains, rebuild the firmware file from the source and check single functions. The
method behind the commands is in the [workflow guide](WORKFLOW.md).

Run all scripts from the repository root with `python3 -I`.

## Toolchains

The toolchains live in a `toolchains/` folder inside the repository, at the paths that `tools/config.json` and the
scripts expect.

| Purpose | Toolchain | Location |
|---|---|---|
| Compiling for the LEON processors | Gaisler BCC 1.0.52 with GCC 3.4.4 | `toolchains/sparc-elf-3.4.4/` |
| Disassembly for `tools/fwdiff.py` | Gaisler BCC 1.0.52 with GCC 4.4.2 | `toolchains/sparc-elf-4.4.2/` |
| Compiling for the 8051 | Keil C51 9.56 evaluation edition, running under Wine | `toolchains/keil-prefix/drive_c/K956/` (in a Wine prefix) |
| Assembling the Tensilica program | Espressif xtensa-esp32-elf GCC 8.4.0 esp-2020r3 (binutils 2.31.1) | `toolchains/xtensa-esp32-elf/` |
| Automatic search (optional, only for `tools/permuter*.py`) | decomp-permuter | `toolchains/decomp-permuter/` |
| Compiler internals (optional) | GCC 3.4.4 source code | `toolchains/gcc-3.4.4-src/` |
| Decompiler (optional) | Ghidra 12 | `/opt/ghidra`, or set `GHIDRA_HOME` |

Besides these, the scripts need Linux on x86-64, Python 3 (without extra packages), `git`, `tar`, `7z` and, for the
8051, Wine. The evaluation edition of Keil C51 limits what its linker links, not what its compiler compiles: the
checks read the compiler's object files without linking them, and the one check that links (`tools/lx51judge.py`)
links a single function inside a 2 KB page. The set-up below was
tested on Linux with Python 3.14, Wine 11.20 and Ghidra 12.1.2.

## Setting up a new machine

1. **Download the files** listed under [downloads](#downloads), and check their SHA-256 checksums.
2. **Unpack the two Gaisler toolchains and the Xtensa toolchain** into `toolchains/`. Each archive contains its own
   folder:

   ```
   tar -xjf sparc-elf-3.4.4-1.0.52.tar.bz2 -C toolchains/
   tar -xjf sparc-elf-4.4.2-1.0.52.tar.bz2 -C toolchains/
   tar -xzf xtensa-esp32-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz -C toolchains/
   ```

3. **Unpack Keil C51 9.56 into its own Wine prefix.** The installer is not run; 7-Zip extracts it, and a
   `TOOLS.INI` tells the compiler where it lives. Disabling `winemenubuilder` keeps Wine from adding entries to the
   desktop menu:

   ```
   export WINEPREFIX="$PWD/toolchains/keil-prefix" WINEDEBUG=-all WINEDLLOVERRIDES="winemenubuilder.exe=d"
   wineboot -i
   7z x -o"$WINEPREFIX/drive_c/K956" c51v956.exe
   printf '[C51]\r\nPATH="C:\\K956\\C51"\r\nVERSION=V956\r\n' > "$WINEPREFIX/drive_c/K956/TOOLS.INI"
   ```

4. **Optionally get decomp-permuter**, at the commit used here. Only the search scripts need it:

   ```
   git clone https://github.com/simonlindholm/decomp-permuter toolchains/decomp-permuter
   git -C toolchains/decomp-permuter checkout 8556c81d80d1c1af98a858c8f4dc951357f29139
   ```

5. **Optionally unpack the GCC 3.4.4 source** into `toolchains/gcc-3.4.4-src/`, for reading the compiler's internals.
6. **Install Ghidra** (on Arch Linux: `pacman -S ghidra`). Only making the decompiler's raw output again needs it
   (`decomp/`, see [local folders](#local-folders)).
7. **Split the firmware** into the parts each processor runs. The checking tools read them from `parts/`:

   ```
   python3 -I tools/split.py firmware/MSI_MPG321URX_V021_7F69.bin parts
   ```

8. **Check the set-up** by running `python3 -I tools/verify.py 8051_bank0 leon2s`. Every function should verify,
   apart from the entries listed in the [status report](STATUS.md#verification).

## Downloads

| File | Source | Size (bytes) | SHA-256 |
|---|---|---:|---|
| `sparc-elf-3.4.4-1.0.52.tar.bz2` | [download.gaisler.com/anonftp/bcc/bin/linux](https://download.gaisler.com/anonftp/bcc/bin/linux/) | 62,204,306 | `0e864c0e1f4cf0b3816f56132635dbcc6e78a68db80d664be1a87bfe93d210a5` |
| `sparc-elf-4.4.2-1.0.52.tar.bz2` | [download.gaisler.com/anonftp/bcc/bin/linux](https://download.gaisler.com/anonftp/bcc/bin/linux/) | 52,473,470 | `9e2cbb787d3cc4cf30c8aa730ed50eace70caae7d784a4e66b22b001ff4d5765` |
| `c51v956.exe` | [Keil C51 evaluation, release 9.56](https://www.keil.com/files/eval/c51v956.exe) (free) | 104,217,336 | `b991e4924ee6577a2e0f9e590546d59add411fa75da3bd23080816bb183b74c4` |
| `xtensa-esp32-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz` | [github.com/espressif/crosstool-NG, release esp-2020r3](https://github.com/espressif/crosstool-NG/releases/tag/esp-2020r3) | 85,731,226 | `674080a12f9c5ebe5a3a5ce51c6deaeffe6dfb06d6416233df86f25b574e9279` |
| `gcc-3.4.4.tar.bz2` | [ftp.gnu.org/gnu/gcc/gcc-3.4.4](https://ftp.gnu.org/gnu/gcc/gcc-3.4.4/) | 27,565,872 | `3444179840638cb8664e8e53604900c4521d29d57785a5091202ee4937d8d0fd` |

Use release 9.56 exactly. Other releases produce different code for some 8051 functions (see
[toolchains](TOOLCHAINS.md)).

## Rebuilding and verifying everything

```
python3 -I tools/verify.py leon2m leon2s 8051_bank0 8051_bank1 8051_bank2 8051_bank3
python3 -I tools/relink.py leon2m leon2s --jobs 8
python3 -I tools/progress.py
python3 -I tools/rebuild.py                    # The complete image, compared with the original file
```

`tools/rebuild.py` alone answers whether the source builds the firmware byte for byte. Its last lines then read:

```
6089 built entries, 6089 exact; 8 entries recorded as data (kept original); 0 overlap conflicts
build/MSI_MPG321URX_V021_rebuilt.bin: 2,820,096 bytes, file name sum 7F69, BYTE-IDENTICAL to the original; 35 s
```

The count is of things built, not of functions: the whole Tensilica program and the menu area are one entry each,
and a jump table is built with its function.

A few entries are checked by other tools than `verify.py`, for example the 8051 start-up code by
`tools/startup8051.py`. The [status report](STATUS.md#verification) lists them all.

`tools/rebuild.py` builds every function, including those entries, and writes it at its place in a copy of
the firmware; all other bytes (the data) stay original. It writes `build/MSI_MPG321URX_V021_rebuilt.bin` (or the
path given as its first argument) and a report next to it (`.txt`), and exits with 1 unless the image is
byte-identical to `firmware/MSI_MPG321URX_V021_7F69.bin` and every function was built exact. The whole firmware
takes less than a minute. The report gives, per section:

- **source:** bytes built from C and assembly;
- **library:** bytes of toolchain library routines (`.lib` entries);
- **original:** bytes taken from the firmware, including (**fields**) the address fields inside built functions that
  a check takes from the firmware (jump-table and literal-pool addresses, library fixups);
- **differ:** bytes of the rebuilt image that are not the original's, each listed with its address and function.

It also lists functions that are exact only with flags that `symbols/<section>.json` does not record.

| Option | Effect |
|---|---|
| `--jobs N` | Parallel builds, default 4; Keil runs at most 2 at a time. |
| `--sections leon2m ...` | Build only these sections; the others stay original. |

## Checking and accepting a function

To check a file after changing it, and to record the changed file:

```
python3 -I tools/diff.py leon2m FUN_a00dac38 build/x.o          # LEON: shape, then exact bytes at the real address
python3 -I tools/diff8051.py 8051_bank1 FUN_CODE_7b5a src.c     # 8051
python3 -I tools/handaccept.py leon2m hand FUN_a00dac38 src.c "One-line description"
python3 -I tools/accept8051.py 8051_bank1 hand FUN_CODE_7b5a src.c "One-line description"
tools/check/acc.sh hand FUN_a00dac38 src.c "One-line description" [flags]   # Main processor: check, compare, accept, commit
tools/check/acc2s.sh hand FUN_a0060000 src.c "One-line description" [flags]  # Input processor: the same
```

`handaccept.py` and `accept8051.py` refuse any source that is not byte-exact or has no descriptive comment. A draft
outside `src/` gets the side list of the label in its file name, or of the function it is checked as.

## Compiling one file by hand

`python3 -I tools/srcpath.py leon2m FUN_a00dac38` prints the path of the function's source file
(`src/leon2m/panel/SYSAPI_GetPanelParamStruct.c`) together with the file's side list of names. The compiler needs the
side list in front of the file:

```
toolchains/sparc-elf-3.4.4/bin/sparc-elf-gcc -mcpu=v8 -O3 -g -include symbols/defs/leon2m/FUN_a00dac38.h \
    -w -c src/leon2m/panel/SYSAPI_GetPanelParamStruct.c -o build/x.o
```

[Names in the source](NAMES.md#names-in-the-source) explains the side lists and how the scripts pass them to Keil
C51; [File names and folders](NAMES.md#file-names-and-folders) explains where the files are.

## Checking the Tensilica program

To build the program from `src/tensilica/` and compare it with the firmware:

```
python3 -I tools/xtensa_check.py
```

It assembles `src/tensilica/tensilica.S` (which includes the other files in address order), links it at 0x40000000
and compares the result with file offset 0x30000-0x3D8DB (flash bank 3). It prints every differing byte with its
address and symbol and exits with status 0 only when the build is identical. The files in `src/tensilica/` are the
master copy: `tools/xtensa_gen.py` can regenerate them from the firmware, but it overwrites them.

## Local folders

These folders are not stored in git:

| Folder | Contents |
|---|---|
| `toolchains/` | The toolchains (set-up steps 2 to 5). |
| `parts/` | The parts each processor runs (set-up step 7). |
| `ghidra_proj/`, `decomp/` | The Ghidra project and the raw output of the decompiler, which `tools/decompile.sh` makes again. |
| `build/` | The rebuilt firmware file and its report. |
| `work/` | Scratch space. |

To make `decomp/` and the target assembly again:

```
./tools/decompile.sh                    # Ghidra project, decomp/, symbols/*.auto.json
python3 -I tools/dump_asm.py leon2m     # Target assembly (already committed;
python3 -I tools/dump_asm.py leon2s     # only needed after function-table changes)
```
