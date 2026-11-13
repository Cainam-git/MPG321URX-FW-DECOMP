# Glossary

The terms of this project, in plain words.

## Hardware

| Term | Meaning |
|---|---|
| **Scaler** | The main chip of a monitor. It receives the HDMI or DisplayPort signal, processes the picture and drives the panel. In this monitor: the Novatek NT68500. |
| **Main processor** | "Leon2M", one of the scaler's two LEON2 processors. It handles the picture pipeline, panel control and on-screen menu logic. Its program is the main program (`leon2m`). |
| **Input processor** | "Leon2S", the other LEON2 processor. It handles the HDMI and DisplayPort inputs. Its program is the input program (`leon2s`). |
| **8051** | A small 8-bit processor inside the scaler, also called the helper processor. Here it boots the system, loads the programs of the other processors, supervises the two LEON processors, and handles power sequencing and firmware updates. A second 8051 core, in the chip's USB controller, runs the update agent. Programmed in C with the Keil C51 compiler. |
| **LEON2 / SPARC** | A 32-bit processor design based on the SPARC V8 architecture. The scaler contains two, the main processor and the input processor. Programmed in C with a GCC-based compiler. |
| **Tensilica / Xtensa** | A configurable 32-bit processor design. The scaler contains one Xtensa core, the Tensilica processor. The 8051 copies its program, the Tensilica program, out of the firmware at start-up. The program runs the chip's zone-dimming loop, made for LED-backlit screens. |
| **DRAM** | The scaler's working memory. Code and data are copied there from the firmware at start-up. |
| **OSD** | On-screen display: the menu that appears when the monitor's button is pressed. |
| **EDID** | A small data block the monitor sends to the computer to describe itself (name, supported resolutions). |
| **DDC** | The low-speed data channel inside an HDMI, DisplayPort or VGA cable, used for EDID and monitor control. |
| **ISP** | In-system programming: writing firmware to the scaler through a cable. |
| **Flashing** | Writing a firmware file into the monitor's flash chip, here with MSI's update tool. |
| **CFW** | Custom firmware: a firmware file that was changed by someone other than the maker. |
| **Upscaler** | A box between an old console and the monitor that turns the console's picture into a modern video signal. Not the scaler chip inside the monitor. |
| **Black frame insertion** | Showing a black frame after every picture frame, for sharper motion. It doubles the refresh rate of the signal. |
| **Flash programmer** | A hardware tool that writes a flash chip directly, connected to the chip on the circuit board. |
| **FRC** | Frame-rate conversion: the stage of the scaler between the timing of the input and the timing of the panel. It runs frame-locked (every panel frame lasts as long as an input frame) or free-running. |
| **Frame lock** | The panel's timing follows the input: every panel frame lasts exactly as long as an input frame. |
| **PIP / PBP** | Picture in picture and picture by picture: the menu's names for showing more than one input at once. |
| **Line rate** | The number of picture lines a signal delivers per second. |

## Firmware file

| Term | Meaning |
|---|---|
| **Firmware** | The program that runs on the scaler. The `.bin` file is a complete copy of it. |
| **Section** | The part of the firmware that one processor runs, as named in the tools: `leon2m`, `leon2s`, `8051_bank0` to `8051_bank3`. |
| **Bank** | A 64 KB block of the firmware file holding one 8051 program. The 8051 addresses 64 KB of program code; here each of banks 0 to 2 is a complete program (boot loader, main application, update agent) that the chip's hardware copies into place, and bank 3 holds the Tensilica program. |
| **Slot area** | File offsets 0x6000–0x7FFF: the partition table at 0x6000 and room for a second one at 0x7000, which the boot loader uses when the byte at 0x7FFF is 0xAA. |

## Method

| Term | Meaning |
|---|---|
| **Decompiler** | A tool, here Ghidra, that turns machine code back into rough, unnamed C. |
| **Matching decompilation** | Writing source code that compiles back to exactly the original bytes, which proves that it is correct. |
| **Byte-exact** | Compiled source that gives exactly the original bytes at the function's real address. Only byte-exact functions count as matched. |
| **Target assembly** | The original machine code of a function, written out as text. The source must reproduce it. |
| **Symbols** | Names, status and descriptions of functions and variables, kept in `symbols/`. |
| **`FUN_…`, `DAT_…`** | Ghidra's automatic labels for a function and a piece of data. The number is an address, in the numbering that [address numbering](MAP.md#address-numbering) explains (a function label of the main program is 0xA0060000 above the address the code runs at; a data label is the address itself); it is not a name with a meaning. `FUN_CODE_…` is a function of an 8051 program, `fn_…` a function of the Tensilica program. |
| **Label** | The automatic name of a function or a piece of data, built from its address (`FUN_…`, `DAT_…`). The checking tools link by labels; the source uses the names. |
| **Side list** | The list of the names one C file uses, with the label behind each name. The build puts it in front of the file ([Function names](NAMES.md#names-in-the-source)). |
| **Flags** | The options a source file is compiled with, such as the optimisation level. They are recorded per function, as the options that reproduce the original bytes. |
| **Reconstructed statement** | A statement that the original source must have had at a certain place, because the function does not build to the original bytes without one, but whose wording the firmware does not show. |
| **Jump table** | A list of addresses the compiler creates for a `switch` statement. |
| **Routine** | Another word for function. The comments in the source files use it. |
| **Library routine** | Ready-made code that comes with a compiler, for example for division or for copying memory. It is taken unchanged from the compiler's own files. |

## Source file headers

| Term | Meaning |
|---|---|
| **Matching notes** | The block at the top of a source file that lists what the exact build depends on: compiler options and ways of writing the code. It can be skipped when reading for understanding. |
| **Source form** | A detail of how a function is written (the type of a variable, the order of two statements, a small helper function) that changes what the compiler produces. File headers name the forms the byte-exact build depends on. |
| **Aids** | Source forms that are not plain C or that leave no instructions of their own. "Aids: none" or "No aids" means the file needs none. |
| **fw** | Short for "the firmware", meaning the original bytes. |
