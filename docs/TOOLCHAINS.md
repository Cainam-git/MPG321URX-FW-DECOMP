# Toolchains

The compilers that built the original firmware, the evidence for each, and the options they were run with. The
[build guide](BUILD.md) tells where to get them and how to set them up.

## 8051: Keil C51

- **Evidence:** The Keil runtime function `?C?CLDPTR` appears byte for byte at 0x0F3F (bank 0), 0x106A4 (bank 1) and
  0x23179 (bank 2). Keil C51 is also the standard compiler in Novatek scaler SDKs.
- **Version:** C51 9.56, evaluation edition, running under Wine. It reproduces every 8051 function. The other
  releases produce different code for some of them; the matching guide lists
  [what each release does differently](MATCHING-TRICKS.md#keil-c51-releases). The limits of the evaluation edition
  (2 KB of object code per link, no floating point) do not matter when matching one function at a time.
- **Options per file:** `OPTIMIZE(7,SPEED)` or `OPTIMIZE(8,SPEED)`, since a tail jump (`LJMP`) needs level 8, with
  `LARGE` where used.
- **Banks 0 and 1** were built with whole-program register optimisation. The register files are reconstructed from
  the firmware (`tools/regfile8051.py`, written to `symbols/8051_bank*.orc`) and passed to the compiler with
  `REGFILE`.
- **Bank 2** (update agent) uses `OBJECTADVANCED` and, for some modules, the LX51 linker (`tools/lx51judge.py`).

## LEON processors: Gaisler BCC 1.0.52 with GCC 3.4.4

- **Evidence:** The 100 library routines of the main program are byte-identical to members of the libraries that
  come with BCC 1.0.52 (`.lib` entries in `src/leon2m/lib/`), and the C functions compile to the original bytes
  with its GCC 3.4.4. The code uses hardware multiply and divide instructions, so it was built for `-mcpu=v8`.
- **Version:** GCC 3.4.4 reproduces the original code. GCC 4.4.2 (BCC 1.0.x) and GCC 7 or later (BCC2) produce
  different prologues, delay-slot use and instruction scheduling.
- **Input processor (`leon2s`):** Mostly `-mcpu=v8 -Os -g`; a few files with `-msoft-float` or without `-g`, and one
  without optimisation (`-mcpu=v8 -g`). With `-g`, GCC 3.4 places a `nop` after a function's final call, exactly as
  the firmware does.
- **Flags** are recorded as the ones that reproduce the bytes. Where more than one set does, the recorded set is
  not proven to be the one MSI used.
- **Main processor (`leon2m`):** The flags vary per file:
  - `-O3 -g` for about 60 % of the C functions. About a third have no flags of their own on record: they build
    exact with the section's default, `-O2 -g`, or with one of the other sets listed in `tools/config.json`, which
    the tools try in order. A few use `-O3` or `-O2` without `-g`.
  - `-msoft-float` for code that uses floating point, since the firmware has no floating-point instructions and
    calls the software functions in libgcc instead. This flag also changes how loops are optimised.
  - Occasionally `-Os -g`, and in a few cases no optimisation at all (`-g` only).

  Flags that differ from the default are recorded per function in `symbols/leon2m.json`.
- **Libraries:** Library code (libc, libm, libgcc, libnosys and the BCC runtime) is taken directly from the
  toolchain's own archives (`tools/libmatch.py`).

## Tensilica program: assembly source, Espressif Xtensa binutils

- **Original compiler:** not available to this project. The program stores no compiler name; its code is
  unoptimised and uses the Xtensa windowed calling convention. Its banner contains "NVT_Formal_RG20189", which has
  the form of a release name of Cadence's own Xtensa tools (RG-2018.9), but this is not proven.
- **Not GCC:** the free GCC for Xtensa (Espressif GCC 8.4.0) is not the compiler that built it. At `-O0` GCC sets
  up a frame pointer (`mov.n a7, a1`) in every function, and none of the program's functions has one.
- **Source:** the program is kept as assembly source in `src/tensilica/`. The free GNU binutils for Xtensa assemble
  it to the same bytes as the firmware (see [src/tensilica/README.md](../src/tensilica/README.md)).
- **Binutils:** from Espressif's `xtensa-esp32-elf` toolchain, GCC 8.4.0 release esp-2020r3 (binutils 2.31.1). Only
  `as`, `ld`, `objcopy` and `nm` are used. They are built for the ESP32's core configuration; every instruction of
  the program assembles to its original bytes with it, but a few configuration-specific mnemonics (`read_impwire`)
  are the ESP32 configuration's names.
- **Options:** `as --no-transform` (keeps every instruction exactly as written), `ld -Ttext=0x40000000 --no-relax`,
  `objcopy -O binary -j .text`.

## Comparison tools

The checking tools in `tools/` are built around `objdump` for the LEON processors and an OMF51 object reader for
the 8051.
