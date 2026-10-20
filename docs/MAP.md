# Firmware map

How `MSI_MPG321URX_V021_7F69.bin` is laid out, and how its three processors start and work together.

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

## The three processors

| Processor | Architecture | Responsibilities |
|---|---|---|
| **8051** | 8-bit, bank-switched, Keil C51 | Boot loader, power sequencing, starting and supervising the LEON processors, update channel, OSD resources. |
| **Leon2M** (main) | LEON2, SPARC V8 | Picture pipeline, panel and OLED control, frame-rate conversion, on-screen menu logic, update service, USB mode selection. |
| **Leon2S** (input) | LEON2, SPARC V8 | HDMI 2.1 and DisplayPort receiver, link training, mode detection. |

## Regions

| File offset | Length | Contents | Runs at or is loaded to |
|---|---|---|---|
| 0x000000 | 0x06000 | 8051 bank 0: boot loader (reset vector `LJMP 0x13F7`, Keil start-up code) | CODE 0x0000 |
| 0x006000 | 0x02000 | Partition table (0x6000) and slot area (0x7000–0x7FFF), read by the boot loader | |
| 0x008000 | 0x08000 | Empty (0xFF) | |
| 0x010000 | 0x10000 | 8051 bank 1: main application | CODE 0x0000 |
| 0x020000 | 0x10000 | 8051 bank 2: update agent | CODE 0x0000 |
| 0x030000 | 0x10000 | 8051 bank 3: mostly tables; "Nov 10 2025" at 0x3B2C4, FAT/NTFS signatures at 0x2E0AB | CODE 0x0000 |
| 0x040000 | 0x10000 | Empty (0xFF) | |
| 0x050000 | 0x80000 | Leon2S program, copied to RAM by the 8051 | CPU 0xA0060000 |
| 0x0D0000 | 0x07B44 | Leon2M start-up code (reset, trap handlers, early C), copied to RAM by the 8051 | CPU 0xA0028000 |
| 0x0D7B44 | 0x144C0 | Unused (0xFF) | |
| 0x0EC000 | 0x06F38 | Leon2M initialised data, copied by the 8051 to the start of Leon2M data RAM | CPU 0xA8024000 |
| 0x0F2F38 | | Panel timing tables | |
| 0x108000 | | Start of the Leon2M code window; the code runs directly from flash | CPU 0x00000000 |
| 0x118000 | 0x6E00 | EDID table, inside the code window | CPU 0x10000 |
| 0x120000 | 0xE6B00 | Leon2M main program | CPU 0x18000 onward |
| 0x206B00 | ~0x9500 | Leon2M read-only data (debug strings, version) | |
| 0x210000 | 0x70000 | OSD resources: menus, fonts and string tables for more than 20 languages | |
| 0x280000 | 0x30652 | Leon2M data image ("SWVERSION", version block) | |
| 0x2A0380 | 3 × 0x58 | Panel mode table (240, 120 and 60 Hz), see [panel modes](#panel-modes) | CPU 0x198380 |
| 0x2B0600 | 0x200 | Trailer: a table of 8-byte values, then 0x05/0x19/0x7D words and 0xFF padding. It is not a checksum. | |

## Address numbering

- **Leon2M main program:** The CPU address is the file offset minus 0x108000. Function names such as
  `FUN_a00dac38` use Ghidra's import base, which is the CPU address plus 0xA0060000. To find a function in the file,
  subtract 0xA0000000 from the number in its name and add 0xA8000.
- **Leon2M start-up code** runs at the address in its name (0xA0028000–0xA002FB43).
- **Leon2M data RAM** spans 0xA8024000–0xA8040000. The area after the initialised data is filled by a DMA job of the
  8051.
- **Leon2S** runs code from 0xA0060000 and uses data RAM at 0xA8076000–0xA807FF94.
- **8051 banks** are each imported as an independent 64 KB program starting at CODE 0x0000.

## Start-up sequence

1. **8051 boot loader** (bank 0, `FUN_CODE_13f7` → `FUN_CODE_151c`): reads the flash ID and the partition table,
   then starts the bank 1 application.
2. **8051 application** (bank 1, `FUN_CODE_3fe7`):
   - Copies the Leon2M start-up code and data and the Leon2S program to RAM (`FUN_CODE_0b0d`, using the DMA routine
     `FUN_CODE_738c` and the fill routine `FUN_CODE_a8bb`).
   - Points the Leon2M code window at file offset 0x108000 (`FUN_CODE_4a85`).
   - Starts the bank 2 update agent (`FUN_CODE_96eb`) and releases Leon2M (`FUN_CODE_c544`).
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
4. The 8051's update channel (I2C slave 0x6E, `FUN_CODE_6c34`) is opened by a command from Leon2M (`FUN_CODE_224f`).
5. The USB mode pins (GPIO 7.7 and 5.0) are driven by `FUN_a0083ff0`.

## Panel modes

The panel can be driven in three modes. Each is described by one row of the panel mode table:

| Row | Output clock | Horizontal total | Vertical total range | Nominal rate | Display mode |
|---|---|---|---|---|---|
| 0 | 2291 MHz | 4064 | 2348–11764 | 240 Hz | 11 |
| 1 | 2300 MHz | 8160 | 2348–5884 | 120 Hz | 11 |
| 2 | 576 MHz | 4088 | 2348–2944 | 60 Hz | 5 |

- **Choosing the row:** `FUN_a00dac38` measures the input refresh rate (in 0.1 Hz units) or line rate and picks:
  - Row 2 below `off + 600`, row 1 below `off + 1200`, and row 0 otherwise, where `off` is 20, or 5 when saved
    setting 2 is enabled.
  - When it uses the line rate instead, it compares `h / 2348` against 699 and 1299.
- **Applying it:** `FUN_a01483f4` copies the chosen row to 0xA802E378. `FUN_a0141840` builds a transformed copy, with
  the display mode from `FUN_a0151c84`, and re-runs the output set-up (`FUN_a015373c` → `FUN_a0106d64`).
- **Timing:** `FUN_a0107e44` programs the output clock from the row, and `FUN_a0109bbc` selects frame-locked or
  free-running timing.
- **Panel controller:** `FUN_a01295e4` and `FUN_a0126704` send the row number to it over I2C (address 0x60,
  register 0xB2).

## Open questions

- How the 8051 switches between banks 1 and 2 (which special function register selects the bank).
- The meaning of the pointer table at 0x12FFF0 and the table set at 0x0E0000–0x0FFFFF.
- Which processor reads the region 0x210000–0x27FFFF.
- The meaning of most flag bits in the input channel records (0xA802DF30) and of saved setting 2.
