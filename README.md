# MPG321URX-FW-DECOMP

A byte-exact decompilation of the firmware of the **MSI MPG 321URX** QD-OLED monitor, version **FW.021**: the
programs inside the monitor, turned back from machine code into source code that can be read.

The repository holds source code for every function in the firmware. Compiled with the tools the firmware was
built with, the source reproduces the original program code byte for byte, and `tools/rebuild.py` puts the
complete firmware file together again, identical to the original.

With MSI's firmware the monitor shows a full-screen colour cycle (cycling colours, "color cycling") instead of a
picture for sources at 60.0988 Hz, 60.59 Hz and 120.198 Hz, such as retro consoles and the upscalers made for them.
The repository holds two modified firmware files (custom firmware, CFW) that give a picture
([Firmware overview](firmware/README.md#custom-firmware)).

The project is not affiliated with MSI or Novatek. Read [Modifying the firmware](docs/MODIFYING.md) before
changing anything on a real monitor.

## Where to look

| If you want to… | Read |
|---|---|
| Understand how the monitor's firmware works | [How the firmware works: a guided tour](docs/TOUR.md) |
| Read one function explained from top to bottom | [A worked example: the panel mode selection](docs/EXAMPLE-PANEL-MODE.md) |
| Look up a function by name, or find its file | [Function names](docs/NAMES.md#where-the-names-are) |
| Look up a term | [Glossary](docs/GLOSSARY.md) |
| Set up the toolchains and rebuild the firmware | [Build guide](docs/BUILD.md) |
| Change the firmware safely | [Modifying the firmware](docs/MODIFYING.md) |
| Read or change a menu text or a character of a menu font | [Menu fonts and texts](docs/OSD-TEXT.md) |
| Use or understand the two custom firmware files | [Firmware overview](firmware/README.md#custom-firmware) |
| Find a script | [Tools](tools/README.md) |
| Find any other page | [Documentation index](docs/README.md) |

## Q&A

**Why does my MSI MPG 321URX show cycling colours with a retro console or an upscaler?**\
The source runs slightly faster than 60 Hz or 120 Hz, and MSI's firmware FW.021 picks a panel setting in which
such a signal does not fit. The panel itself can show it.

**Does the MSI MPG 321URX work at 60.0988 Hz, 60.59 Hz or 120.198 Hz (NES, SNES, arcade boards, black frame insertion)?**\
With MSI's FW.021 it shows cycling colours instead of a picture. With the custom firmware of this repository it
shows the picture correctly.

**Is there custom firmware (CFW) for the MSI MPG 321URX?**\
Yes: [FW.021-7E9D](https://github.com/Cainam-git/MPG321URX-FW-DECOMP/releases/tag/FW.021-7E9D), which is MSI's
official FW.021 with one small change. The [firmware overview](firmware/README.md#custom-firmware) says exactly
what it changes.

**Can I go back to MSI's firmware?**\
Yes. Install MSI's official FW.021 with MSI's own tool (Gaming Intelligence), the same way.

**How does the firmware of this monitor work, and can it be changed?**\
[How the firmware works: a guided tour](docs/TOUR.md) explains it, and
[Modifying the firmware](docs/MODIFYING.md) says what can be changed safely.

## Inside the monitor

The monitor is driven by a Novatek NT68500 scaler chip. The firmware holds programs for four processors:

| Processor | Responsibilities |
|---|---|
| **Main processor** (LEON2, "Leon2M") | Picture pipeline, panel control and on-screen menu logic. |
| **Input processor** (LEON2, "Leon2S") | Receiving and decoding the HDMI and DisplayPort signals. |
| **Helper processor** (8051) | Booting the system, loading the programs of the other processors, watching the main and the input processor, power and firmware updates. A second 8051 core in the chip's USB controller runs the update agent. |
| **Tensilica processor** (Xtensa) | Zone dimming for LED backlights. Runs, but drives no LEDs in this OLED monitor. |

## Progress

```
Main processor      [####################]  100 %
Input processor     [####################]  100 %
Helper processor    [####################]  100 %
Tensilica processor [####################]  100 %
Overall             [####################]  100 %
```

Percentages are by code size. All 6,743 entries of the function tables are done: functions, and the jump tables, library routines and
pieces of functions that the tables list beside them. The [status report](docs/STATUS.md) has the numbers, the
definitions behind them and what is left.

## Method

1. A function of the main, input or helper processor is rewritten in C, or in assembly where the original was
   written in assembly. The Tensilica program is rewritten in assembly, because its C compiler is not available.
   Functions from the toolchains' own libraries are taken unchanged from those libraries.
2. It is compiled with the original toolchains: GCC 3.4.4 for the two LEON processors and Keil C51 9.56 for the 8051.
   The Tensilica program is assembled with the free Xtensa assembler.
3. The result is compared with the original bytes at the exact address the function occupies. A source file is
   kept only when its build matches exactly.

The menu's fonts and texts are rebuilt from text files (`src/osd/`, see [Menu fonts and texts](docs/OSD-TEXT.md)).
Everything else in the firmware file (tables, settings, empty space) is copied from the original file. The
[workflow guide](docs/WORKFLOW.md) describes the method in full.

## State of the source

- **Function names.** Every function has a descriptive name and a short description: in the header of its file,
  in the code and in a table ([Function names](docs/NAMES.md)). About a third of the names only describe what
  the function does, because the firmware does not show what for.
- **Data names.** 2,542 records, tables, variables and registers have names. Data whose purpose the code does not
  show keeps its label (`DAT_a802d9a0`), which is an address, not a name.
- **Code.** Every C function is written out in full: its parameters, local variables and constants carry names, record
  fields too where the code shows what they hold (the others carry their offset, `byte_0x110`), and comments say
  what the code does and why. The assembly files are commented instruction by
  instruction. The local variables of the Tensilica program's functions are stack slots, named in the comments.
- **Proof.** The exact build proves the code, not the names and comments. Those were checked against the code
  by reading, and the mistakes found were corrected; a reader should still expect a wrong sentence here and there.
- **Reconstructed statements.** Three functions contain one statement each that had to be reconstructed
  ([status report](docs/STATUS.md#reconstructed-statements)).

## Repository layout

- **`src/`**: the source, one file per function, named after the function and grouped by processor and subject:
  `src/<processor>/<subject>/<name>.c`, for example `src/leon2m/panel/SYSAPI_GetPanelParamStruct.c`. A few 8051
  files hold a Keil module of several functions. `src/tensilica/` holds the Tensilica program as assembly,
  `src/osd/` the menu's fonts and texts as text files.
- **`firmware/`**: the original FW.021 file, older versions for comparison, and two custom versions.
- **`asm/`**: the original machine code as text: one file per function for the two LEON programs, one listing per
  program for the 8051. The checking tools compare against it.
- **`symbols/`**: the function table of each processor, and for every function its status, how it was matched,
  its compiler flags, its name with a one-line description, and the path of its source file. `symbols/defs/`
  holds the list of names each C file uses, which the build puts in front of the file.
- **`tools/`**: scripts that build, compare and verify the source and rebuild the firmware file.
- **`docs/`**: documentation.

## Licence

The tools, the documentation, and the names and comments written for this project are released into the public
domain ([LICENSE](LICENSE)): anyone may use, copy and change them for any purpose. MSI's firmware files and the
program code reconstructed from them are not covered by it.
