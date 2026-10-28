# Glossary

| Term | Meaning |
|---|---|
| **Scaler** | The main chip of a monitor. It receives the HDMI or DisplayPort signal, processes the picture and drives the panel. In this monitor: the Novatek NT68500. |
| **Firmware** | The program that runs on the scaler. The `.bin` file is a complete copy of it. |
| **8051** | A small 8-bit processor inside the scaler. Here it boots the system, loads the programs of the other processors, supervises the main LEON processor, and handles power sequencing and firmware updates. A second 8051 core, in the chip's USB controller, runs the update agent. Programmed in C with the Keil C51 compiler. |
| **LEON2 / SPARC** | A 32-bit processor design based on the SPARC V8 architecture. The scaler contains two: "Leon2M" handles the picture pipeline, panel control and on-screen menu logic; "Leon2S" handles the HDMI 2.1 and DisplayPort inputs. Programmed in C with a GCC-based compiler. |
| **Tensilica / Xtensa** | A configurable 32-bit processor design. The scaler contains one Xtensa core with its own program, which the 8051 copies out of the firmware at start-up. The program runs the chip's zone-dimming loop, made for LED-backlit screens. |
| **Bank** | The 8051 can only address 64 KB of program code at a time, so its code is split into banks that it switches between. |
| **DRAM** | The scaler's working memory. Code and data are copied there from the firmware at start-up. |
| **OSD** | On-screen display: the menu that appears when the monitor's button is pressed. |
| **EDID** | A small data block the monitor sends to the computer to describe itself (name, supported resolutions). |
| **DDC** | The low-speed data channel inside an HDMI, DisplayPort or VGA cable, used for EDID and monitor control. |
| **ISP** | In-system programming: writing firmware to the scaler through a cable. |
| **Decompiler** | A tool, here Ghidra, that turns machine code back into rough, unnamed C. |
| **Matching decompilation** | Writing source code that compiles back to exactly the original bytes, which proves that it is correct. |
| **Target assembly** | The original machine code of a function, written out as text. The source must reproduce it. |
| **Symbols** | Names, status and descriptions of functions and variables, kept in `symbols/`. |
