# MPG321URX-FW-DECOMP

A byte-exact decompilation of the firmware of the **MSI MPG 321URX** QD-OLED monitor, version **FW.021**.

The goal is readable source code for every function in the firmware. Compiled with the same tools MSI used, this
source reproduces the original firmware file byte for byte. A function only counts as done when it matches exactly,
so every file in `src/` is a proven reconstruction, not an approximation.

## Inside the monitor

The monitor is driven by a Novatek NT68500 scaler chip. The firmware holds programs for four processors:

| Processor | Responsibilities |
|---|---|
| **Main processor** (LEON2, "Leon2M") | Picture pipeline, panel control and on-screen menu logic. |
| **Input processor** (LEON2, "Leon2S") | Receiving and decoding the HDMI and DisplayPort signals. |
| **Helper processor** (8051) | Booting the system, loading the programs of the other processors, supervising the main processor, power and firmware updates. |
| **Tensilica processor** (Xtensa) | A separate program of about 300 functions that the helper processor loads at start-up. Its own text calls it "NT68500 Tensilica S/W" and mentions LED driver chips; what it does has not been worked out yet. |

## Progress

```
Main processor      [###############-----]   79 %
Input processor     [###############-----]   77 %
Helper processor    [##################--]   92 %
Tensilica processor [###-----------------]   15 %
Overall             [###############-----]   77 %
```

Percentages are by code size. More than 5,800 of roughly 6,300 functions are done, and the helper processor's boot
loader is complete. `tools/rebuild.py` builds the complete firmware image from the matched functions plus the
original bytes for everything else, and the result is identical to the original file. Detailed numbers are in the
[status report](docs/STATUS.md).

## How it works

1. A function is rewritten in C, or in assembly where the original was written in assembly. Routines from the
   toolchains' own libraries are taken unchanged from those libraries.
2. It is compiled with the original toolchains: GCC 3.4.4 for the two LEON processors and Keil C51 for the 8051.
   The compiler of the Tensilica program has not been identified, so that program is not decompiled yet.
3. The result is compared with the original bytes at the exact address the function occupies.
4. Only an identical result is accepted.

Most source files begin with a short description of what the function does. The full method is described in the
[workflow guide](docs/WORKFLOW.md).

## Where to look

| If you want to… | Read |
|---|---|
| See how the firmware file is laid out | [Firmware map](docs/MAP.md) |
| Set up the toolchains and check a function | [Build guide](docs/BUILD.md) |
| Understand the matching method | [Workflow guide](docs/WORKFLOW.md) |
| Learn the source tricks that make GCC and Keil produce identical code | [Matching tricks](docs/MATCHING-TRICKS.md) |
| Change the firmware safely | [Modifying the firmware](docs/MODIFYING.md) |
| Contribute a function | [Contributing](CONTRIBUTING.md) |

## Repository layout

| Folder | Contents |
|---|---|
| `src/` | The reconstructed source code, one file per function (a few 8051 files hold a Keil module of several functions). |
| `firmware/` | The original FW.021 file, older versions for comparison, and two custom versions. |
| `asm/` | The original machine code of each function, as a reference. |
| `symbols/` | Names and status of every function. |
| `decomp/` | Raw output of the Ghidra decompiler, as a reading aid. |
| `tools/` | Scripts that compile, compare, accept and count functions. |
| `docs/` | Documentation. |
