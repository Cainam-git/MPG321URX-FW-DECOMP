# Firmware map

How `MSI_MPG321URX_V021_7F69.bin` is laid out, and how its four processors start and work together.

## The file

| Property | Value |
|---|---|
| Size | 2,820,096 bytes (0x2B0800) |
| SHA-256 | `4934abd71dff21492dda3b2dd630f3539ba1d6639de88f2f3684fd03d59f019e` |
| MD5 | `ed43f709aa67b8bc624b799f219e30c8` |
| Scaler chip | Novatek NT68500 (start-up messages "NT68500 Leon2M system compiled under Linux" and "NT68500 Leon2S system compiled under Linux"; a record at 0x207D68 holds "SCALER" and "NT68550") |
| Version string | "FW.021 20260112", at 0x2082E9 |
| Panel | Samsung Display "SDC QMC315AA01_D01", 31.5" QD-OLED |
| EDID | "MPG321UX OLED", product 0x3DD2, 48 variants at 0x118000–0x11EE00, 0x200 apart (one gap, see [regions](#regions)) |
| Encryption or compression | None |
| File name | `MSI_MPG321URX_V021_XXXX.bin`, where `XXXX` is the 16-bit sum of all bytes, in uppercase hexadecimal. The value is not stored inside the file. |

## The four processors

| Processor | Architecture | Responsibilities |
|---|---|---|
| **8051** | 8-bit, Keil C51 | Boot loader, power sequencing, loading the other processors' programs, supervising the two LEON processors, update channel. A second 8051 core in the chip's USB controller runs bank 2. |
| **Main processor** ("Leon2M") | LEON2, SPARC V8 | Picture pipeline, panel and OLED control, frame-rate conversion, on-screen menu logic, update service, USB mode selection. |
| **Input processor** ("Leon2S") | LEON2, SPARC V8 | HDMI and DisplayPort receivers, link training, mode detection. |
| **Tensilica processor** | Xtensa (windowed calls) | Zone dimming ("LDC"): processes the chip's per-zone picture measurements every frame. Made for LED backlights; in this OLED monitor its LED drivers are never switched on. See [the Tensilica program](#the-tensilica-program). |

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
| 0x050000 | 0x80000 | Input-processor program in three parts (0x050000, 0x0A6000, 0x0B0000), copied to RAM by the 8051 | CPU 0xA0060000, 0xA8076000 and 0x9F1B0000 (see [address numbering](#address-numbering)) |
| 0x0D0000 | 0x07B44 | Main-processor start-up code (reset, trap handlers, early C), copied to RAM by the 8051 | CPU 0xA0028000 |
| 0x0D7B44 | 0x144C0 | Unused (0xFF) | |
| 0x0EC000 | 0x06F38 | Main-processor initialised data, copied by the 8051 to the start of the main processor's data RAM | CPU 0xA8024000 |
| 0x0F2F38 | 0x150C8 | Empty (0xFF) | |
| 0x108000 | | Start of the main processor's code window; the code runs directly from flash | CPU 0x00000000 |
| 0x118000 | 0x6F80 | EDID blocks, inside the code window: 48 blocks 0x200 apart, with a gap between 0x11C800 and 0x11D800 | CPU 0x10000 |
| 0x120000 | 0xE6B00 | Main program of the main processor | CPU 0x18000 onward |
| 0x206B00 | ~0x9500 | Main-processor read-only data (debug strings, version) | |
| 0x210000 | 0x001F0 | End of the main-processor read-only data (menu debug messages) | CPU 0x108000 |
| 0x2101F0 | 0x65BF8 | Menu fonts: the character pictures and character widths of 15 fonts (see [menu text](#menu-text)) | CPU 0x1081F0 |
| 0x275DE8 | 0x2A168 | Menu texts in every language with their tables of text addresses (see [menu text](#menu-text)) | CPU 0x16DDE8 |
| 0x29FF50 | 0x106B0 | Constant tables of the main program (among them the panel mode table, the default settings, the port table and the input mode table) | CPU 0x197F50 |
| 0x2A0380 | 3 × 0x58 | Panel mode table (240, 120 and 60 Hz), see [panel modes](#panel-modes) | CPU 0x198380 |
| 0x2B0600 | 0x200 | Trailer: a table of 8-byte values, then 0x05/0x19/0x7D words and 0xFF padding. It is not a checksum. | |

## Address numbering

Each processor sees the flash and its memory at its own addresses. They relate to the file offsets of this map as
follows.

- **Main program of the main processor:** the CPU address is the file offset minus 0x108000. Function names such as
  `FUN_a00dac38` use Ghidra's import base, which is the CPU address plus 0xA0060000. To find a function in the file,
  subtract 0xA0000000 from the number in its name and add 0xA8000.
- **Data labels of the main processor** (`DAT_00198380`, `DAT_a802d9a0`) carry the address the processor itself uses:
  for data in the flash, the CPU address (file offset minus 0x108000); for data in RAM, the RAM address.
- **Start-up code of the main processor:** runs at the address in its name (0xA0028000–0xA002FB43).
- **Data RAM of the main processor:** 0xA8024000–0xA8040000. A DMA job of the 8051 fills the area after the
  initialised data.
- **Input-processor program:** loaded in three parts (three records of the partition table).
  - The first part (file 0x050000, 0x54F60 bytes) runs at 0xA0060000.
  - The second part (file 0x0A6000, 0x27E0 bytes) holds the start values of its data RAM at 0xA8076000; the data RAM
    extends to 0xA807FF94.
  - The third part (file 0x0B0000, 0x1EEC5 bytes) runs at 0x9F1B0000. The 86 calls from the first part into it
    and the calls back land on function starts only at that address, and its 370 jump-table words hold
    0x9F1B…/0x9F1C… values.
  - The function names of the third part (`FUN_a00c…`, `FUN_a00d…`) come from importing the whole block at
    0xA0060000. They are 0xF10000 higher than the addresses that code runs at; the calls, jump tables and address
    constants in the firmware use the real addresses. `tools/exact.py` checks them at that offset.
- **8051 banks 0 to 2:** each imported as an independent 64 KB program starting at CODE 0x0000.
- **Tensilica program:** starts at Xtensa address 0x40000000 (file offset 0x030000).

## Start-up sequence

The 8051 starts first, copies the other programs into place, starts the USB controller and the two LEON
processors, and then watches the two LEON processors for as long as the monitor is on.

The 8051 never switches between banks. Each bank is a complete program that the chip's hardware copies into place.

1. **8051 boot loader** (bank 0, `startup_entry` → `startup_boot_main` (`FUN_CODE_151c`)): reads the flash ID and
   the partition table (`startup_load_partition_table` (`FUN_CODE_0003`)), then has bank 1 copied for the 8051
   itself (copy registers 0xF1D0..0xF1D8) and starts that application.
   - The table is read from file offset 0x6000, or from 0x7000 when the marker byte at 0x7FFF is 0xAA.
   - The boot loader checks nothing: no checksum, no signature and no range check of the table or of the program
     it starts. Its message "Can't find valid partition table!!!" cannot be reached.
   - It has no update mode, no key check and no second copy of the application to fall back on.
2. **8051 application** (bank 1, `sys_main` (`FUN_CODE_3fe7`)):
   - Copies the start-up code and data of the main processor and the input-processor program to RAM
     (`startup_load_core_images` (`FUN_CODE_0b0d`), using the copy function `startup_copy_flash_image` and the fill
     function `startup_dma_fill`).
   - On chip versions with ID 0x16, 0x17, 0x1E or 0x1F, loads the Tensilica program: the boot loader passes its
     partition-table record (flash 0x030000, length 0xD8DC) on, and `startup_load_core_images` hands it to
     `startup_load_tensilica_image`, which starts the flash DMA in `flash_dma_read`.
   - Points the main processor's code window at file offset 0x108000 (phase 7 of `startup_load_core_images`) and
     writes the main processor's fixed set-up registers (`startup_setup_leon2m` (`FUN_CODE_4a85`)).
   - Starts the bank 2 update agent (`startup_start_usb_agent` (`FUN_CODE_96eb`)): it has bank 2 copied into the
     USB controller (registers 0xF166..0xF16F, then the start key "USBONE"). Bank 1 keeps running afterwards, so
     the two programs run side by side.
   - Releases the main processor (`startup_release_leon2m` (`FUN_CODE_c544`)).
   - From then on checks on every loop that both LEON processors are alive (`sys_watch_main_core`
     (`FUN_CODE_7b5a`)): it sends two tokens round, each from the 8051 to the main processor, on to the input
     processor and back. When a round takes longer than 15,000 ticks (10,000 for the second token) it prints
     "###SYSTEM CRASH, RESET###", stops both LEON processors, runs the power-off sequence (`power_off_sequence`
     (`FUN_CODE_7a0b`)) and stays in an endless loop.
3. **Main processor**:
   - Starts at the reset slot of its trap table (`trap_reset_entry` (`FUN_a0028000`)), which jumps to the start-up
     code at 0xA0029000, then runs `startup_main` (`FUN_a00295a4`).
   - Start-up (`startup_bring_up_system` (`FUN_a015266c`)): processor and timers (`startup_init_core`), settings
     (`nvram_validate_settings_at_startup`), clocks, display start-up (`startup_init_display_output`) and the
     input channel reset (`startup_reset_channel_records`).
   - Shows the logo (`App_CoolInitialize` → `ShowLogo`) and enters the main loop (`sys_run_app_main_task`
     (`FUN_a0087430`)).
   - Passes the 8051's two alive tokens on through `ipc_signal_alive` (`FUN_a002ced8`).

## Update path

MSI's PC tool reaches the main processor through the 8051. The main processor then opens the connection for the
tool, and the 8051 enters its flash-writing loop, which writes the new firmware.

1. MSI Gaming Intelligence talks to the 8051, which passes the bytes to the main processor through the mailbox (see
   [Mailbox commands](MAILBOX.md)).
2. The main processor polls the mailbox (`ipc_8051_poll_messages`) and sorts the message
   (`ipc_8051_decode_message`).
3. The command task `uart_cmd_run_tool_task` (`FUN_a00ce348`), called from the main loop's timer function
   `sys_run_app_timer_task`, runs the command switch (`uart_cmd_dispatch_get`); the update command is handled by
   `UartSetI2CEnable` (`FUN_a00bf110`).
4. The main processor sends the 8051 commands (`ipc_run_command` (`FUN_CODE_224f`)): command 7 sets up the I2C
   slave address 0x6E for MSI's tool, and command 0x29 starts the flash loop `fwupd_run_flash_loop`
   (`FUN_CODE_6c34`), which then erases, writes and reads the flash as told through a mailbox at XDATA 0xF250 and
   never returns. No function of the main program sends the number 0x29 as a fixed value.
5. The USB mode pins (GPIO 7.7 and 5.0) are driven by `UsbModeSelectRoutine` (`FUN_a0083ff0`).

This path needs a main program that reaches its main loop: only the main loop answers the tool and gives the 8051 the
commands above.

### The update agent on the USB controller

The bank 2 program (`sys_main` (`FUN_CODE_b5b4`)) contains a second way of writing the flash, from a file on a USB
storage device. It depends on the main program as well, and FW.021 as shipped does not start it.

- **On its own** it only recognises a storage device that is plugged in, mounts its FAT, exFAT or NTFS volume
  (`fwupd_mount_volume`) and, behind a hub, looks for a file `UPDATE*.BIN` (`fwupd_find_update_file`). Then it waits.
- **It writes only on command.** A flash write starts when a command byte arrives in its command registers
  (0xF191 and 0xF193, one per USB port; handled in `fwupd_step_port_state` (`FUN_CODE_6e16`)): 0x11, 0x12, 0x14 or
  0x15 when a file has been found, or 0x16 or 0x17 after command 0x46 has loaded a file into memory. A file or a pin
  alone starts nothing. All of them end in `fwupd_run_isp_write` (`FUN_CODE_a8a3`).
- **How it writes.** After identifying the flash chip it sends I2C packets to slave address 0x6E on a bus it drives
  by hand (pins P1.7 and P1.6). Depending on the command it either erases the flash and writes the file in
  512-byte blocks (`fwupd_write_flash_blocks`), or rewrites header records and hands the file's place in memory to
  the chip's own programming function (`fwupd_svc_send_region`). The firmware does not show which device answers at
  address 0x6E.
- **What it checks.** The file name; and a 16-bit sum of the file's bytes against a record in a second file,
  `CONFIG.BIN`, but only when that file and that record exist (`fwupd_verify_file_sum`). Without them the file is
  taken unchecked. The file size is not checked, and written blocks are not read back. On an exFAT volume the
  search loads and checks at the end of the folder without testing that the update file was found
  (`fwupd_find_update_file`); on FAT it gives up when the file is missing.
- **Who commands it.** Every sender found is in the main program: 0x70 (host or device mode,
  `fwupd_port_send_cmd_0x70`), 0x46, 0x47 and 0x48 (`fwupd_find_and_verify_file`, `fwupd_read_file_name`,
  `fwupd_find_file`), 0x13 and 0x17 (`fwupd_enter_update`, `fwupd_run_progress_loop`). The entry functions of this
  route in the main program (`fwupd_api_start_update`, `fwupd_find_and_verify_file`, `fwupd_find_file`) are not
  called from anywhere in FW.021, directly or through a stored address. No sender was found for 0x11, 0x12, 0x14,
  0x15 and 0x16.

## Panel modes

The panel is driven in one of three modes, each one row of the panel mode table. Inputs up to about 62 Hz use the
60 Hz mode, inputs up to about 122 Hz the 120 Hz mode, and faster inputs the 240 Hz mode.

| Row | Output clock | Horizontal total | Vertical total range | Nominal rate | Display mode |
|---|---|---|---|---|---|
| 0 | 2291 MHz | 4064 | 2348–11764 | 240 Hz | 11 |
| 1 | 2300 MHz | 8160 | 2348–5884 | 120 Hz | 11 |
| 2 | 576 MHz | 4088 | 2348–2944 | 60 Hz | 5 |

- **Choosing the row:** `SYSAPI_GetPanelParamStruct` measures the input refresh rate (in 0.1 Hz units) or line
  rate and picks:
  - Row 2 below `off + 600`, row 1 below `off + 1200`, and row 0 otherwise, where `off` is 20 (2 Hz), or 5
    (0.5 Hz) when the factory menu switch "PHY CTS AUTO" (saved setting 2) is on. That switch is item 24 of the
    factory menu (`osd_factory_increase_value` (`FUN_a008c25c`)), meant for signal compliance tests (CTS); it is
    saved with the other settings.
  - When it uses the line rate instead, it compares `h / 2348` against 699 and 1299.
- **Applying it:** `panel_api_set_active_row` (`FUN_a01483f4`) copies the chosen row to 0xA802E378.
  `panel_transform_row` (`FUN_a0141840`) builds a transformed copy, with the display mode from `DispModeTransform`
  (`FUN_a0151c84`), and re-runs the output set-up (`panel_setup_output_after_row_change` (`FUN_a015373c`) →
  `panel_output_setup_clock` (`FUN_a0106d64`)).
- **Timing:** `FRCConfigPostFRC` (`FUN_a0107e44`) programs the output clock from the row, and `sys_frc_setup_lock`
  (`FUN_a0109bbc`) selects frame-locked or free-running timing.
- **Panel controller:** `oled_frc_task` (`FUN_a01295e4`) and `oled_set_frame_rate_control` (`FUN_a0126704`) send
  the row number to it over I2C (address 0x60, register 0xB2).

## Menu text

The menu's fonts and texts sit in flash at 0x2101F0–0x29FF4F, inside the main processor's code window (partition
entry 5: flash 0x108000, length 0x1A8654). The 8051 does not copy them; the main processor reads them in place.
Their formats, the languages and the editable source in `src/osd/` are described in
[Menu fonts and texts](OSD-TEXT.md).

## Monitor control from the PC (DDC/CI)

A PC can read and change monitor settings over the video cable (DDC/CI, the I2C address 0x6E). The main processor
handles these commands in `ddc_handle_request` (`FUN_a0088724`), in two `switch` statements on the setting code.
The compiler turned them into two jump tables with one target per code; every target lies inside
`ddc_handle_request`:

| Jump table | File offset | Codes with a case of their own |
|---|---|---|
| Read a setting ("GetVCP") | 0x130254 | 02 04 05 06 08 0B 0C 0E 10 12 14 16 18 1A 1E 1F 20 30 3E 52 60 62 6C 6E 70 8D AC AE B2 B6 C0 C6 C8 C9 CA CC D6 DC DF EC F1 F4 FE FF |
| Change a setting ("SetVCP") | 0x12FE58 | 02 04 05 06 08 0C 0E 10 12 14 16 18 1A 1E 20 30 3E 60 62 6C 6E 70 72 8D CA CC D6 DC EC F1 F8 F9 FA FE |

Every other code goes to one shared case. In the VESA MCCS standard, for example, 0x10 is brightness, 0x12
contrast, 0x60 the input source, 0x62 the volume and 0xD6 the power mode.

## The Tensilica program

The last 8051 flash bank (file offset 0x030000) does not contain 8051 code. It holds a complete program for the
chip's Tensilica Xtensa core, 0xD8DC bytes long, followed by empty space (0xFF). No 8051 code calls into it; the
8051 only copies it out as one block at start-up. The parts of the program, its assembly source and how to build it
are described in the [README of `src/tensilica/`](../src/tensilica/README.md).

### What it does

The program is Novatek's local-dimming controller ("LDC") for LED-backlit screens. It prints a banner with
"NVT_Formal_RG20189" and "NT68500 FW Version". Its messages name the parts: zone segments and how they are merged
(maximum, average, average without black, blend), gain tables and limits ("LDC_GainTable", "ZonePeakingPercent",
"UserGlobalGain"), LED pulse width and current ("PDIM", "ADIM"), and AS3824 LED driver chips. It also has a debug
command line on its serial port ("Welcome to User's Command Line Debug").

In this monitor, traced from both sides:

- **Start-up:** the main processor starts it and sends six of its 46 commands (see
  [the commands it receives](#commands-from-the-main-processor)). After that it only sends the power-down handshake
  (slot 0x34, `ldc_power_down_handshake` (`FUN_a01396d8`)).
- **Every frame:** the chip's dimming hardware block raises an interrupt (Xtensa interrupt 9, external line 7;
  `ldc_irq_handler` (`fn_40008ef0`), installed by `ldc_irq_install` (`fn_40008f58`), status register 0xE0080404).
  The main loop (`sys_init_and_run_main_loop` (`fn_4000a3cc`)) then runs one processing pass
  (`ldc_run_pass_on_new_frame` (`fn_40003764`) -> `ldc_run_frame_pass` (`fn_400035d0`)) when the counter in that
  status register has moved, and only after command 0x40 has been received. The pass reads the zone values and
  writes its results back into the same block (0xE0080310 to 0xE0080708 and the table at 0xE0082000).
- **Not used:** the LED driver chips are only set up by command 0x22 (`ldc_cmd_init_led_drivers` (`fn_400013a0`) ->
  `LED_AS3824_Init` (`fn_400079b8`)), and the main processor's sender for it (`ldc_send_init_led_drivers`
  (`FUN_a0139d38`)) has no caller. Its functions that read results back (slots 0x10 and 0x4C) and its senders for the
  other commands have no caller either, and none of their addresses is stored.

So the program processes every frame of the chip's dimming hardware, but it never drives LEDs and the main processor
never reads its results. Whether the dimming hardware itself uses the results to change the picture on this OLED
panel (for example to limit brightness) depends on how the block is wired inside the chip; the firmware does not
show it.

### Commands from the main processor

The main processor sends its commands through mailbox portal 2 (0xB7091000, command slot +0x20). The Tensilica
program reads the slot at 0xE0091020 in `ldc_poll_mailbox_command` (`fn_40003814`) and looks the command up in its
table at 0x4000D288. These six are sent:

| Command | Sent by | Content |
|---|---|---|
| 0x21 | `ldc_send_panel_size_and_start` (`FUN_a0139a30`) (`System_Initialize`, output set-up `panel_setup_output_after_row_change` (`FUN_a015373c`)) | Active panel size; starts the program |
| 0x2B | `ldc_send_zone_counts` (`FUN_a0139c3c`) (`System_Initialize`) | Zone counts as powers of two (5 and 6) |
| 0x2A | `ldc_send_zone_grid_32x16` (`FUN_a0139b90`), `ldc_api_set_zone_grid` (`FUN_a014e050`) (start-up path via `sys_user_apply_startup_settings` (`FUN_a00db054`)) | Zone grid 32 x 16 or 64 x 32, chosen by bits 18-19 of the word at 0xA802D290 + 0xAC |
| 0x84 | `ldc_send_cmd_0x84` (`FUN_a013a8d4`) (`System_Initialize`) | One value, written to 0xE0080168 |
| 0x97 | `ldc_api_set_zone_grid` | One value, written to 0xE0080388 |
| 0x40 | `ldc_send_dpll_init_check` (`FUN_a013a750`) | Check message ("MAILBOX_DPLL INIT DONE") |

## What changes between versions

Comparing the official versions FW.012, FW.016, FW.020 and FW.021 (`firmware/`):

- **The whole 8051 part is identical in all four**, byte for byte: the boot loader, the main application and the
  update agent.
- **The Tensilica program is different in every version.** It is rebuilt for each release.

## Open questions

- **Not worked out:** the meaning of most flag bits in the input channel records (0xA802DF30). Which code sets and
  reads each bit is known.
- **Not answerable from the firmware file:** whether the chip's dimming hardware changes the picture on this OLED
  panel (that depends on the wiring inside the chip), and which compiler built the Tensilica program (the program
  does not name it).
