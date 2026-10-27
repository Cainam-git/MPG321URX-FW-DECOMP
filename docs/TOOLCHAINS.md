# Toolchains

How the compilers that built the original firmware were identified, and which options they used.

## 8051: Keil C51

- **Evidence:** The Keil runtime routine `?C?CLDPTR` appears byte for byte at 0x0F3F (bank 0), 0x106A4 (bank 1) and
  0x23179 (bank 2). Keil C51 is also the standard compiler in Novatek scaler SDKs.
- **Version:** C51 9.60, evaluation edition, running under Wine. Its limits (2 KB of object code per link, no
  floating point) do not matter when matching one function at a time.
- **Options per file:** `OPTIMIZE(7,SPEED)` or `OPTIMIZE(8,SPEED)`, since a tail jump (`LJMP`) needs level 8, with
  `LARGE` where used.
- **Banks 0 and 1** were built with whole-program register optimisation. The register files are reconstructed from
  the firmware (`tools/regfile8051.py`, written to `symbols/8051_bank*.orc`) and passed to the compiler with
  `REGFILE`.
- **Bank 2** (update agent) uses `OBJECTADVANCED` and, for some modules, the LX51 linker (`tools/lx51judge.py`).

## LEON processors: Gaisler BCC 1.0.52 with GCC 3.4.4

- **Evidence:** The string `BCC_Initial` at 0x1B55C, and hardware multiply and divide instructions, which means the
  code was built for `-mcpu=v8`.
- **Version:** GCC 4.4.2 (BCC 1.0.x) and GCC 7 or later (BCC2) produce different prologues, delay-slot use and
  instruction scheduling. GCC 3.4.4 reproduces the original code.
- **Input processor (Leon2S):** Mostly `-mcpu=v8 -Os -g`, some files with `-msoft-float`, and a few without
  optimisation (`-g` only). With `-g`, GCC 3.4 places a `nop` after a function's final call, exactly as the firmware
  does.
- **Main processor (Leon2M):** The flags vary per file:
  - Mostly `-O2 -g`, and often `-O3`, with or without `-g`.
  - `-msoft-float` for code that uses floating point, since the firmware has no floating-point instructions and
    calls the software routines in libgcc instead. This flag also changes how loops are optimised.
  - Occasionally `-Os -g`, and in a few cases no optimisation at all (`-g` only).

  The flags of every function are recorded in `symbols/leon2m.json`.
- **Libraries:** Library code (libc, libm, libgcc, libnosys and the BCC runtime) is taken directly from the
  toolchain's own archives (`tools/libmatch.py`).

## Tensilica program: not identified yet

- The program stores no compiler name.
- Its code is unoptimised and uses the Xtensa windowed calling convention.
- Its banner contains "NVT_Formal_RG20189". That has the form of a release name of Cadence's own Xtensa tools
  (RG-2018.9), but this is not proven.
- No suitable compiler is installed, so this program is not decompiled yet.

## Comparison tools

Neither decomp.me nor objdiff supports SPARC or the 8051. The checking tools in `tools/` are built around `objdump`
for the LEON processors and an OMF51 object reader for the 8051.
