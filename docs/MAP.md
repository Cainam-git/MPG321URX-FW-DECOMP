# Firmware map

How `MSI_MPG321URX_V021_7F69.bin` is laid out, and how its four processors start and work together.

## The file

| Property | Value |
|---|---|
| Size | 2,820,096 bytes (0x2B0800) |
| SHA-256 | `4934abd71dff21492dda3b2dd630f3539ba1d6639de88f2f3684fd03d59f019e` |
| MD5 | `ed43f709aa67b8bc624b799f219e30c8` |
| Scaler chip | Novatek NT68500 ("NT68500 Leon2M/Leon2S system compiled under Linux"; the string "SCALER=NT68550" appears at 0x207D68) |
| Version string | "FW.021 20260112", at 0x2082E9 |
| Panel | Samsung Display "SDC QMC315AA01_D01", 31.5" QD-OLED |
| EDID | "MPG321UX OLED", product 0x3DD2, 48 variants at 0x118000–0x11EE00, 0x200 apart |
| Encryption or compression | None |
| File name | `MSI_MPG321URX_V021_XXXX.bin`, where `XXXX` is the 16-bit sum of all bytes, in uppercase hexadecimal. The value is not stored inside the file. |

## The four processors

| Processor | Architecture | Responsibilities |
|---|---|---|
| **8051** | 8-bit, Keil C51 | Boot loader, power sequencing, loading the other processors' programs, supervising Leon2M, update channel. A second 8051 core in the chip's USB controller runs bank 2. |
| **Leon2M** (main) | LEON2, SPARC V8 | Picture pipeline, panel and OLED control, frame-rate conversion, on-screen menu logic, update service, USB mode selection. |
| **Leon2S** (input) | LEON2, SPARC V8 | HDMI 2.1 and DisplayPort receiver, link training, mode detection. |
| **Tensilica core** | Xtensa (windowed calls); kept as assembly source, its compiler is not available | Zone dimming ("LDC"): processes the chip's per-zone picture measurements every frame. Made for LED backlights; in this OLED monitor its LED drivers are never switched on. See [the Tensilica program](#the-tensilica-program). |

## Regions

| File offset | Length | Contents | Runs at or is loaded to |
|---|---|---|---|
| 0x000000 | 0x06000 | 8051 bank 0: boot loader (reset vector `LJMP 0x13F7`, Keil start-up code) | CODE 0x0000 |
| 0x006000 | 0x02000 | Partition table (0x6000) and slot area (0x7000–0x7FFF), read by the boot loader | |
| 0x008000 | 0x08000 | Empty (0xFF) | |
| 0x010000 | 0x10000 | 8051 bank 1: main application | CODE 0x0000 |
| 0x020000 | 0x10000 | 8051 bank 2: update agent, run by the USB controller's 8051 core; contains a FAT disk boot sector ("MSDOS5.0", volume "UPDATE") at 0x2E0AB | CODE 0x0000 |
| 0x030000 | 0x0D8DC | Tensilica program (see [the Tensilica program](#the-tensilica-program)); built "Nov 10 2025" (string at 0x3B2C4) | Xtensa 0x40000000 |
| 0x03D8DC | 0x02724 | Empty (0xFF) | |
| 0x040000 | 0x10000 | Empty (0xFF) | |
| 0x050000 | 0x80000 | Leon2S program, copied to RAM by the 8051 | CPU 0xA0060000 |
| 0x0D0000 | 0x07B44 | Leon2M start-up code (reset, trap handlers, early C), copied to RAM by the 8051 | CPU 0xA0028000 |
| 0x0D7B44 | 0x144C0 | Unused (0xFF) | |
| 0x0EC000 | 0x06F38 | Leon2M initialised data, copied by the 8051 to the start of Leon2M data RAM | CPU 0xA8024000 |
| 0x0F2F38 | 0x150C8 | Empty (0xFF) | |
| 0x108000 | | Start of the Leon2M code window; the code runs directly from flash | CPU 0x00000000 |
| 0x118000 | 0x6E00 | EDID table, inside the code window | CPU 0x10000 |
| 0x120000 | 0xE6B00 | Leon2M main program | CPU 0x18000 onward |
| 0x206B00 | ~0x9500 | Leon2M read-only data (debug strings, version) | |
| 0x210000 | 0x001F0 | End of the Leon2M read-only data (menu debug messages) | CPU 0x108000 |
| 0x2101F0 | 0x65BF8 | Menu fonts: the character pictures and character widths of 15 fonts (see [menu text](#menu-text)) | CPU 0x1081F0 |
| 0x275DE8 | 0x0A218 | Menu texts in every language, found through tables of text addresses | CPU 0x16DDE8 |
| 0x280000 | 0x30652 | Leon2M data image ("SWVERSION", version block) | |
| 0x2A0380 | 3 × 0x58 | Panel mode table (240, 120 and 60 Hz), see [panel modes](#panel-modes) | CPU 0x198380 |
| 0x2B0600 | 0x200 | Trailer: a table of 8-byte values, then 0x05/0x19/0x7D words and 0xFF padding. It is not a checksum. | |

## What changes between versions

Comparing the official versions FW.012, FW.016, FW.020 and FW.021 (`firmware/`):

- **The whole 8051 part is identical in all four**, byte for byte: the boot loader, the main application and the
  update agent. It was built once and has been copied into every release unchanged since.
- **The Tensilica program is different in every version.** It is rebuilt for each release; the copy in FW.021 is
  dated "Nov 10 2025".

## Address numbering

- **Leon2M main program:** The CPU address is the file offset minus 0x108000. Function names such as
  `FUN_a00dac38` use Ghidra's import base, which is the CPU address plus 0xA0060000. To find a function in the file,
  subtract 0xA0000000 from the number in its name and add 0xA8000.
- **Leon2M start-up code** runs at the address in its name (0xA0028000–0xA002FB43).
- **Leon2M data RAM** spans 0xA8024000–0xA8040000. The area after the initialised data is filled by a DMA job of the
  8051.
- **Leon2S** runs code from 0xA0060000 and uses data RAM at 0xA8076000–0xA807FF94. Part of its program was linked
  0xF10000 above the address it runs at, so some calls, switch tables and string addresses in it point 0xF10000
  higher than the code they refer to. `tools/exact.py` checks those addresses at that offset.
- **8051 banks 0 to 2** are each imported as an independent 64 KB program starting at CODE 0x0000.
- **The Tensilica program** starts at Xtensa address 0x40000000 (file offset 0x030000).

## Start-up sequence

1. **8051 boot loader** (bank 0, `FUN_CODE_13f7` → `FUN_CODE_151c`): reads the flash ID and the partition table,
   then starts the bank 1 application.
2. **8051 application** (bank 1, `FUN_CODE_3fe7`):
   - Copies the Leon2M start-up code and data and the Leon2S program to RAM (`FUN_CODE_0b0d`, using the DMA routine
     `FUN_CODE_738c` and the fill routine `FUN_CODE_a8bb`).
   - Loads the Tensilica program: the boot loader passes its partition-table record (flash 0x030000, length
     0xD8DC) on, and `FUN_CODE_0b0d` hands it to `FUN_CODE_c43e`, which starts the flash DMA in `FUN_CODE_8d60`.
   - Points the Leon2M code window at file offset 0x108000 (`FUN_CODE_4a85`).
   - Starts the bank 2 update agent (`FUN_CODE_96eb`) and releases Leon2M (`FUN_CODE_c544`).
   - The banks are never switched. Each one is a whole program linked at CODE 0x0000 and copied by hardware: the
     boot loader starts bank 1 with the copy block at 0xF1D0..0xF1D8, and bank 1 loads bank 2 into the chip's USB
     controller with the copy block at 0xF166..0xF16F (flash 0x020000, length 0xE552, then the key "USBONE" at
     0xF1E5). Bank 1 keeps running after that, so bank 2 runs on that second controller, not in place of bank 1.
   - From then on checks on every loop that Leon2M is alive (`FUN_CODE_7b5a`). After 15,000 ticks without a sign of
     life it prints "###SYSTEM CRASH, RESET###", stops both LEON processors and runs the power-off sequence
     (`FUN_CODE_7a0b`).
3. **Leon2M**:
   - Runs reset (`FUN_a0028ff0`), then main (`FUN_a00295a4`).
   - Start-up (`FUN_a015266c`): processor and timers, data RAM check (`FUN_a00de7c4`), settings
     (`FUN_a0153c74`), clocks, display start-up (`FUN_a0141964`) and the input channel reset (`FUN_a013c944`).
   - Shows the logo (`FUN_a0087020` → `FUN_a008ef48`, ShowLogo) and enters the main loop (`FUN_a0087430`).
   - Signals that it is alive to the 8051 through `FUN_a002ced8`.

## Update path

1. MSI Gaming Intelligence talks to the 8051, which passes commands to Leon2M through a mailbox.
2. Leon2M polls the mailbox (`FUN_a0134de0`) and decodes the message (`FUN_a013497c`).
3. The command task `FUN_a00ce348`, called from the main loop's timer routine `FUN_a0085984`, runs the command
   switch (`FUN_a00bfcc4`); the update command is handled by `FUN_a00bf110`.
4. Leon2M sends the 8051 commands (`FUN_CODE_224f`): command 7 sets up the I2C slave address 0x6E for MSI's tool,
   and command 0x29 starts the flash loop `FUN_CODE_6c34`, which then writes the flash as told through a mailbox at
   XDATA 0xF250.
5. The USB mode pins (GPIO 7.7 and 5.0) are driven by `FUN_a0083ff0`.

## Panel modes

The panel can be driven in three modes. Each is described by one row of the panel mode table:

| Row | Output clock | Horizontal total | Vertical total range | Nominal rate | Display mode |
|---|---|---|---|---|---|
| 0 | 2291 MHz | 4064 | 2348–11764 | 240 Hz | 11 |
| 1 | 2300 MHz | 8160 | 2348–5884 | 120 Hz | 11 |
| 2 | 576 MHz | 4088 | 2348–2944 | 60 Hz | 5 |

- **Choosing the row:** `FUN_a00dac38` measures the input refresh rate (in 0.1 Hz units) or line rate and picks:
  - Row 2 below `off + 600`, row 1 below `off + 1200`, and row 0 otherwise, where `off` is 20 (2 Hz), or 5
    (0.5 Hz) when the factory menu switch "PHY CTS AUTO" (saved setting 2) is on. That switch is item 24 of the
    factory menu (`FUN_a008c25c`), meant for signal compliance tests (CTS); it is saved with the other settings.
  - When it uses the line rate instead, it compares `h / 2348` against 699 and 1299.
- **Applying it:** `FUN_a01483f4` copies the chosen row to 0xA802E378. `FUN_a0141840` builds a transformed copy, with
  the display mode from `FUN_a0151c84`, and re-runs the output set-up (`FUN_a015373c` → `FUN_a0106d64`).
- **Timing:** `FUN_a0107e44` programs the output clock from the row, and `FUN_a0109bbc` selects frame-locked or
  free-running timing.
- **Panel controller:** `FUN_a01295e4` and `FUN_a0126704` send the row number to it over I2C (address 0x60,
  register 0xB2).

## Menu text

The menu's fonts and texts sit in flash at 0x2101F0–0x27FFFF. The 8051 does not copy them anywhere: they are part of
the Leon2M code window (partition entry 5: flash 0x108000, length 0x1A8654), and Leon2M reads them in place.

- **Texts:** each message has a table with one text address per language (for example the panel protection message
  "After 1 mins, panel protection ..." at 0x275DE8). `FUN_a00a3844` picks the entry for the current language.
- **Fonts:** a text can switch font with a byte from 0xF0 to 0xFE. The text drawing routine `FUN_a00a31a4` reads
  those bytes, and `FUN_a00a2eec` fetches the character picture from the table of the chosen font (one lookup
  routine per table at 0xa00a285c–0xa00a2e74). Byte tables with values such as 7, 13 and 19 hold the character
  widths.

## Monitor control from the PC (DDC/CI)

A PC can read and change monitor settings over the video cable (DDC/CI, the I2C address 0x6E). Leon2M handles these
commands in `FUN_a0088724`, which picks the routine for each setting code from two tables with one routine address
per code:

| Table | File offset | Used for |
|---|---|---|
| Read a setting ("GetVCP") | 0x130254 | Codes with their own routine: 02 04 05 06 08 0B 0C 0E 10 12 14 16 18 1A 1E 1F 20 30 3E 52 60 62 6C 6E 70 8D AC AE B2 B6 C0 C6 C8 C9 CA CC D6 DC DF EC F1 F4 FE FF |
| Change a setting ("SetVCP") | 0x12FE58 | Codes with their own routine: 02 04 05 06 08 0C 0E 10 12 14 16 18 1A 1E 20 30 3E 60 62 6C 6E 70 72 8D CA CC D6 DC EC F1 F8 F9 FA FE |

Every other code goes to one shared routine. In the VESA MCCS standard, for example, 0x10 is brightness, 0x12
contrast, 0x60 the input source, 0x62 the volume and 0xD6 the power mode.

## The Tensilica program

The last 8051 flash bank (file offset 0x030000) does not contain 8051 code. It holds a complete program for the
chip's Tensilica Xtensa core, 0xD8DC bytes long, followed by empty space (0xFF). No 8051 code calls into it; the
8051 only copies it out as one block at start-up.

| File offset | Contents |
|---|---|
| 0x030000–0x0303FF | Exception and interrupt vectors |
| 0x030400–0x03053F | Reset code |
| 0x030800–0x03AC37 | Program code: about 300 functions |
| 0x03AC38–0x03ACF7 | Table of the sections that the reset code copies to the core's RAM |
| 0x03ACF8–0x03C767 | Read-only data: text messages, switch tables |
| 0x03C768–0x03D083 | Constants used by the code |
| 0x03D088–0x03D8DB | Initialised variables |

### What it does

The program is Novatek's local-dimming controller ("LDC") for LED-backlit screens. Its messages name the parts:
zone segments and how they are merged (maximum, average, average without black, blend), gain tables and limits
("LDC_GainTable", "ZonePeakingPercent", "UserGlobalGain"), LED pulse width and current ("PDIM", "ADIM"), and AS3824
LED driver chips. It also has a debug command line on its serial port ("Welcome to User's Command Line Debug").

In this monitor, traced from both sides:

- **Start-up:** the main processor starts it and sends six of its 46 commands, through mailbox portal 2 (0xB7091000,
  command slot +0x20; the Tensilica program reads it at 0xE0091020 in `fn_40003814` and looks it up in its table at
  0x4000D288):

  | Command | Sent by | Content |
  |---|---|---|
  | 0x21 | `FUN_a0139a30` (`System_Initialize`, output set-up `FUN_a015373c`) | Active panel size; starts the program |
  | 0x2B | `FUN_a0139c3c` (`System_Initialize`) | Zone counts as powers of two (5 and 6) |
  | 0x2A | `FUN_a0139b90`, `FUN_a014e050` (start-up path via `FUN_a00db054`) | Zone grid 32 x 16 or 64 x 32, chosen by bits 18-19 of the word at 0xA802D290 + 0xAC |
  | 0x84 | `FUN_a013a8d4` (`System_Initialize`) | One value, written to 0xE0080168 |
  | 0x97 | `FUN_a014e050` | One value, written to 0xE0080388 |
  | 0x40 | `FUN_a013a750` | Check message ("MAILBOX_DPLL INIT DONE") |

  After that it only sends the power-down handshake (slot 0x34, `FUN_a01396d8`).
- **Every frame:** the chip's dimming hardware block raises interrupt 7 (`fn_40008ef0`, installed by `fn_40008f58`,
  status register 0xE0080404). The main loop (`fn_4000a3cc`) then runs one processing pass (`fn_40003764` ->
  `fn_400035d0`), which reads the zone values and writes its results back into the same block (0xE0080310 to
  0xE0080708 and the table at 0xE0082000).
- **Not used:** the LED driver chips are only set up by command 0x22 (`fn_400013a0` -> `fn_400079b8`), and the main
  processor's sender for it (`FUN_a0139d38`) has no caller. Its routines that read results back (slots 0x10 and
  0x4C) and its senders for the other commands have no caller either, and none of their addresses is stored.

So the program processes every frame of the chip's dimming hardware, but it never drives LEDs and the main processor
never reads its results. Whether the dimming hardware itself uses the results to change the picture on this OLED
panel (for example to limit brightness) depends on how the block is wired inside the chip; the firmware does not
show it.

The program prints a banner with "NVT_Formal_RG20189" and "NT68500 FW Version", and its messages mention LED driver
chips (AS3824, "LDC"). No compiler name is stored in it. The code is unoptimised; it is not the output of GCC (see
[toolchains](TOOLCHAINS.md)). The source in `src/tensilica/` is assembly that rebuilds it byte for byte.

## Open questions

- The meaning of most flag bits in the input channel records (0xA802DF30). Which code sets and reads each bit is
  known; what each one stands for is part of naming the Leon2M functions.
- Whether the chip's dimming hardware changes the picture on this OLED panel, and which compiler built the
  Tensilica program.
