# How the firmware works: a guided tour

The place to start. This tour follows the firmware of the MPG 321URX from the moment the monitor gets power to the
moment a picture and a menu are on the screen, and points at the functions worth opening on the way.

Every function name links to its source file, which starts with a comment block that says what the function does,
who calls it and what it calls. Numbers that start with `0x` are hexadecimal (base 16). The
[glossary](GLOSSARY.md) explains terms such as *scaler*, *EDID* or *OSD*.

The programs are large but built from simple pieces: loops that run forever, small state machines (a variable that
says "where am I", and code that moves it on step by step), and tables that map a number to a function.

## 1. The chips and their programs

The main chip of the monitor is its [scaler](GLOSSARY.md), the NT68500 (the name is in its own start-up messages).
It takes the picture from the cable, processes it and drives the panel. Inside it sit several processors, each
with its own program. All programs come out of one file, the 2,820,096-byte firmware file in `firmware/`, whose
layout is drawn in the [firmware map](MAP.md#regions).

| Program | Source | Runs on | What it does | Size of its code |
|---|---|---|---|---:|
| Boot loader | `src/8051_bank0` | the 8051, a small 8-bit processor (the helper processor) | Starts first and starts the 8051 main application. | 6,182 bytes |
| 8051 main application | `src/8051_bank1` | the same 8051 | Copies the other programs into place, starts them, watches them, handles standby and power-off, relays serial, EDID and DDC/CI traffic, and writes the flash during an update. | 53,244 bytes |
| Update agent | `src/8051_bank2` | a second 8051 inside the chip's USB controller | Reads USB storage devices and can write the flash from a file, but only when commanded. | 52,590 bytes |
| Main program | `src/leon2m` | the main processor: "Leon2M", a 32-bit LEON2 processor | Everything the user sees: picture path, panel and OLED control, menu, settings, DDC/CI, the PC tool. | 941,056 bytes |
| Input program | `src/leon2s` | the input processor: "Leon2S", a second LEON2 processor | The HDMI and DisplayPort receivers: locking onto a signal, reading its timing, copy protection, HDR data. | 412,360 bytes |
| Tensilica program | `src/tensilica` | the Tensilica processor, an Xtensa core | Zone dimming, made for LED-backlit screens (see [section 7](#7-the-tensilica-program)). | 55,516 bytes |
| Menu fonts and texts | `src/osd` | read by the main program | 15 fonts and 5,744 texts in 29 languages. | 589,152 bytes |

The sizes of the LEON and 8051 programs are those of the [status report](STATUS.md); the other two are from
[the Tensilica program's README](../src/tensilica/README.md) and [Menu fonts and texts](OSD-TEXT.md). The main
program has 3,968 named pieces (functions, plus library routines and the tables of `switch` statements), the input
program 1,702, the three 8051 programs 52, 431 and 285, and the Tensilica program 301 functions.

Each processor has its own memory and address numbers ([address numbering](MAP.md#address-numbering)). The main
program runs straight out of the flash chip; the other programs are copied into memory by the 8051.

Outside the scaler the firmware talks to three more chips that matter for this tour: the flash chip that holds
the firmware file, a small EEPROM chip (a memory that keeps its contents without power) that holds the settings,
and the OLED panel controller. The main program reaches the last two over I2C, a two-wire bus on which each chip
answers to its own address; the panel controller answers to address 0x60.

**Functions to read first**

| Function | Why |
|---|---|
| [startup_boot_main](../src/8051_bank0/startup/startup_boot_main.c) | The very first C code after power-on, short and in plain steps. |
| [sys_main](../src/8051_bank1/sys/sys_main.c) (8051) | The loop that keeps the whole monitor alive: mailbox, watch, standby and wake-up. |
| [startup_main](../src/leon2m/startup/startup_main.c) | The main program in twelve lines: three start-up steps, then four tasks forever. |
| [sys_main_part1](../src/leon2s/sys/sys_main_part1.S) | The start of the input program's main function, kept as assembly in nine pieces. |
| [sys_init_and_run_main_loop](../src/tensilica/sys/sys_init_and_run_main_loop.S) | The Tensilica program's main function. |

## 2. Switching on

The 8051 starts first and everything else follows from it:

1. **Boot loader.** [startup_boot_main](../src/8051_bank0/startup/startup_boot_main.c) prints
   "------STBC Boot Loader -----", reads the ID of the flash chip and reads the partition table at file offset
   0x6000 ([startup_load_partition_table](../src/8051_bank0/startup/startup_load_partition_table.c)). The table
   says where each program lies. The boot loader hands the place of the 8051 main application to the chip's copy
   hardware and starts it. It checks nothing: no checksum, no signature, no second copy.
2. **8051 main application.** [sys_main](../src/8051_bank1/sys/sys_main.c) sets up clocks, serial ports and
   timers and prints "------NT68500 MCU Test program -----". Then
   [startup_load_core_images](../src/8051_bank1/startup/startup_load_core_images.c) loads the other programs:
   - it copies the update agent into the USB controller and starts it
     ([startup_start_usb_agent](../src/8051_bank1/startup/startup_start_usb_agent.c)); from then on both 8051
     programs run side by side;
   - it copies the Tensilica program by DMA, a copy done by the hardware without the processor
     ([startup_load_tensilica_image](../src/8051_bank1/startup/startup_load_tensilica_image.c)); the code does
     this only on chip versions with ID 0x16, 0x17, 0x1E or 0x1F;
   - it copies the input program and the main program's start-up code and start values into memory and releases
     both LEON processors.
3. **Release byte.** [startup_release_leon2m](../src/8051_bank1/startup/startup_release_leon2m.c) writes 1 into
   a shared word. The main program waits for that byte and prints it as "Boot from 01".
4. **Input program.** It sets up its interrupts, serial port and task list, prints
   "NT68500 Leon2S system compiled under Linux" ([startup_init_system](../src/leon2s/startup/startup_init_system.c)),
   powers its receivers on and then sets a ready bit for the main program
   ([ipc_post_ready_flag](../src/leon2s/ipc/ipc_post_ready_flag.c)).
5. **Main program.** [startup_main](../src/leon2m/startup/startup_main.c) runs three steps:
   - it registers ten callbacks, functions that the system layer calls later by slot number;
   - [startup_bring_up_system](../src/leon2m/startup/startup_bring_up_system.c) waits, without a time limit, for
     the 8051's release byte and then for two bits of the input processor ("wait otp ready", "wait sub init").
     Between the waits it checks and loads the stored settings. After them it sets up the picture path and the
     output ([System_Initialize](../src/leon2m/startup/System_Initialize.c), which also starts the dimming
     program) and loads each input's EDID into the 8051 ([startup_load_port_edids](../src/leon2m/startup/startup_load_port_edids.c));
   - [App_CoolInitialize](../src/leon2m/startup/App_CoolInitialize.c) loads the user settings, shows the MSI logo
     when the settings allow it ([ShowLogo](../src/leon2m/osd/ShowLogo.c), which also switches the panel on) and
     applies the settings ([App_Initialize](../src/leon2m/startup/App_Initialize.c)).
6. **Main loop.** From now on the main program repeats four tasks forever: take the news from the other
   processors, run the picture tasks, run the application (keys, menu, timers, DDC/CI), and serve the debug
   command line.

While all this runs, the 8051 keeps watch. It writes a token into a shared byte; the main program copies it on
([ipc_signal_alive](../src/leon2m/ipc/ipc_signal_alive.c)), and the input program copies the main program's copy
once more. When the token has gone all the way round, the 8051 writes the next one. If a round takes longer than
15,000 ticks of the 8051's timer (10,000 for a second ring of the same kind),
[sys_watch_main_core](../src/8051_bank1/sys/sys_watch_main_core.c) prints "###SYSTEM CRASH, RESET###", stops both
LEON processors, runs the power-off sequence and then stops for good. Despite the text, it does not restart
anything. The full sequence with every function is in the [firmware map](MAP.md#start-up-sequence).

**Functions to read first**

| Function | Why |
|---|---|
| [startup_load_partition_table](../src/8051_bank0/startup/startup_load_partition_table.c) | Shows how little the boot loader checks. |
| [startup_load_core_images](../src/8051_bank1/startup/startup_load_core_images.c) | Where every program comes from and where it goes. |
| [startup_bring_up_system](../src/leon2m/startup/startup_bring_up_system.c) | The main program's start-up, with its three waits. |
| [App_CoolInitialize](../src/leon2m/startup/App_CoolInitialize.c) | How the power-on type decides between logo, wake-up and standby. |
| [sys_watch_main_core](../src/8051_bank1/sys/sys_watch_main_core.c) | The token ring that guards the two LEON processors. |

## 3. From the cable to the panel

**Is a cable there?** The port table in the main program describes each input: its port code, its type and the
pin that tells whether a cable is plugged in. [input_is_port_cable_present](../src/leon2m/input/input_is_port_cable_present.c)
reads that pin, and [input_report_present_ports](../src/leon2m/input/input_report_present_ports.c) sends the
list of present inputs to the input processor.

**The input processor locks on.** It numbers its inputs 0 and 1 for HDMI 2.0, 2 and 3 for HDMI 2.1 and 4 and 5
for DisplayPort. On every pass of its main loop [input_run_link_tasks](../src/leon2s/input/input_run_link_tasks.c)
runs one step of a state machine for each of them, for example
[hdmi_tmds_run_link_state](../src/leon2s/hdmi/hdmi_tmds_run_link_state.c). The states are named in the firmware's
own messages: power off, power on, standby, stable, ready. When an input changes,
[ipc_publish_port_status](../src/leon2s/ipc/ipc_publish_port_status.c) posts the news for the main program.

**The main program measures and matches.** It reads that news first thing in every pass
([ipc_ack_port_change_bits](../src/leon2m/ipc/ipc_ack_port_change_bits.c)). For each port,
[input_port_sync_task](../src/leon2m/input/input_port_sync_task.c) waits until the sync of the signal stays the
same for a while ("SYNC_IS_STABLE") and then measures the line rate and the refresh rate with the measuring
hardware of its own input blocks. [input_match_port_mode](../src/leon2m/input/input_match_port_mode.c) compares
the measured timing with a table of known modes and keeps the closest one. Other code reads the result field by
field through [input_api_get_timing_field](../src/leon2m/input/input_api_get_timing_field.c); field 1, for example,
is the refresh rate in tenths of a hertz (600 = 60.0 Hz).

**Channels.** The main program keeps four picture channels: the main picture and up to three further pictures
(for PIP and PBP). [input_channel_bring_up_task](../src/leon2m/input/input_channel_bring_up_task.c) moves a channel
through its states, again named in the firmware: mode search, capture, display, wait to show, wait for the panel,
and "wait for a mode change", the normal state while a picture is shown.
[GlobalModeHandler](../src/leon2m/sys/GlobalModeHandler.c) acts when a channel enters a state: it asks for the
panel to be switched on and decides whether the frame-rate converter, the block whose output timing drives the
panel, is used ("FRC ON" and "FRC OFF" in its messages).

**Choosing the panel mode.** The panel runs in one of three modes, 240, 120 or 60 Hz, each described by one row
of the panel mode table ([panel modes](MAP.md#panel-modes)). When the timing of a channel is known (an
application event, see [section 4](#4-the-menu)), [APPActionDispatcher](../src/leon2m/sys/APPActionDispatcher.c)
calls [SYSAPI_GetPanelParamStruct](../src/leon2m/panel/SYSAPI_GetPanelParamStruct.c), which picks the row:

- In picture mode 0 (one picture) and picture mode 2 it looks at the measured refresh rate: below 62.0 Hz the 60 Hz mode,
  below 122.0 Hz the 120 Hz mode, otherwise the 240 Hz mode. The 2.0 Hz margin shrinks to 0.5 Hz when the
  factory menu switch "PHY CTS AUTO" is on.
- For some ports it uses the line rate instead, divided by 2,348, the lines of the panel's shortest frame:
  up to 69.9 Hz the 60 Hz mode, up to 129.9 Hz the 120 Hz mode, otherwise the 240 Hz mode.
- In the other PIP and PBP modes it always takes the 120 Hz mode.

It only switches when the mode changes. [panel_api_set_active_row](../src/leon2m/panel/panel_api_set_active_row.c)
makes the chosen row the active one and sets the output up again; [FRCConfigPostFRC](../src/leon2m/sys/FRCConfigPostFRC.c)
programs the output clock and timing from it. The two files in `firmware/custom/` change only the limits of
`SYSAPI_GetPanelParamStruct`; the [firmware overview](../firmware/README.md#custom-firmware) explains why, and
the [worked example](EXAMPLE-PANEL-MODE.md) reads the function line by line.

**The OLED panel controller.** The panel has its own controller chip. The main program switches the panel on in
timed steps ([panel_power_sequencer_task](../src/leon2m/panel/panel_power_sequencer_task.c)), tells the controller
the row number of the panel mode ([oled_frc_task](../src/leon2m/oled/oled_frc_task.c): register 0xB2 at address
0x60), and sends it the brightness ([panel_api_set_brightness](../src/leon2m/panel/panel_api_set_brightness.c),
register 0x5E). The OLED care runs ("OFFSENSING" after 4 hours of use, with the panel off) have a state machine of
their own, [oled_power_task](../src/leon2m/oled/oled_power_task.c).

**Functions to read first**

| Function | Why |
|---|---|
| [SYSAPI_GetPanelParamStruct](../src/leon2m/panel/SYSAPI_GetPanelParamStruct.c) | The choice of 240, 120 or 60 Hz, fully commented. |
| [hdmi_tmds_run_link_state](../src/leon2s/hdmi/hdmi_tmds_run_link_state.c) | A small, readable link state machine of the input processor. |
| [input_port_sync_task](../src/leon2m/input/input_port_sync_task.c) | How the main program decides that a signal is stable. |
| [input_channel_bring_up_task](../src/leon2m/input/input_channel_bring_up_task.c) | Every state a picture passes through before it is shown. |
| [FRCConfigPostFRC](../src/leon2m/sys/FRCConfigPostFRC.c) | How a panel mode row becomes an output clock. |
| [oled_frc_task](../src/leon2m/oled/oled_frc_task.c) | How the panel controller learns the mode. |

## 4. The menu

**Keys.** The monitor's control keys are read through two analogue inputs and a few pins
([input_scan_keys](../src/leon2m/input/input_scan_keys.c)). A key code only counts after it has been the same for
50 ticks ([input_read_keys_debounced](../src/leon2m/input/input_read_keys_debounced.c)).
[sys_scan_keys_post_event](../src/leon2m/sys/sys_scan_keys_post_event.c) adds the rules for held keys: repeat after
a delay, long press, keys that are blocked.

**Events.** Keys do not call menu code directly. They become *events*: small numbers in a queue of at most ten
([sys_post_app_event](../src/leon2m/sys/sys_post_app_event.c)). The top two bits of an event say where it comes
from: 0x00 the application (port changes and timers that ran out), 0x40 a key, 0x80 the menu, 0xC0 DDC/CI. On every
pass [sys_pump_app_events](../src/leon2m/sys/sys_pump_app_events.c) collects new events from all four sources and
hands each one to [APPActionDispatcher](../src/leon2m/sys/APPActionDispatcher.c) (power, picture and saving
actions) and to [osd_dispatch_key_event](../src/leon2m/osd/osd_dispatch_key_event.c) (the menu).

**Menu states.** The menu keeps one number that says which screen is open, 0 when the menu is closed. A table
gives, for every menu state, the function for each key. `osd_dispatch_key_event` looks up the state and the key
and runs that function. On the Brightness slider, for example, the right key runs
[osd_increase_brightness](../src/leon2m/osd/osd_increase_brightness.c). It raises the value by 1 (up to 100),
redraws the slider, applies the value ([sys_user_apply_brightness](../src/leon2m/sys/sys_user_apply_brightness.c),
which ends in `panel_api_set_brightness`) and marks the settings as changed.

**Drawing a text.** A text in the firmware is a length byte followed by character codes. The bytes 0xF0 to 0xFE
switch the font. [osd_get_text](../src/leon2m/osd/osd_get_text.c) picks a text from a table; for a translated text
the entry number is item × 29 + language, where the language is byte 8 of the user settings.
[osd_draw_text](../src/leon2m/osd/osd_draw_text.c) adds up the widths of the characters, places the text left,
right or centred, and ORs the picture of each character ([font_get_glyph_column](../src/leon2m/font/font_get_glyph_column.c))
into fresh 24-pixel-wide cells, which go to the menu layer's memory
([osd_ram_write_words24](../src/leon2m/osd/osd_ram_write_words24.c)).

**The texts per language.** All fonts and texts are kept as editable text files in `src/osd/`: one file per font,
one file per language (`src/osd/texts/01_english.txt` and so on), and a file for the texts several languages
share. A text line names the table entry that points at it, then the text in quotes. How the files rebuild the
exact bytes is in [Menu fonts and texts](OSD-TEXT.md).

**Functions to read first**

| Function | Why |
|---|---|
| [sys_pump_app_events](../src/leon2m/sys/sys_pump_app_events.c) | The heart of the application: four producers, four consumers. |
| [sys_scan_keys_post_event](../src/leon2m/sys/sys_scan_keys_post_event.c) | From a pressed key to a key event. |
| [osd_dispatch_key_event](../src/leon2m/osd/osd_dispatch_key_event.c) | The table of menu state × key, and the factory menu's shortcuts. |
| [osd_increase_brightness](../src/leon2m/osd/osd_increase_brightness.c) | A complete menu action in a dozen lines. |
| [osd_draw_text](../src/leon2m/osd/osd_draw_text.c) | How a text with characters of different widths is drawn. |
| [osd_draw_language_list](../src/leon2m/osd/osd_draw_language_list.c) | A simple drawing function: one page of the language list. |

## 5. Settings

The settings live in a few records, fixed-size blocks of bytes in the main program's memory. The
[record fields](RECORDS.md) page names the bytes; [data objects](DATA.md#settings) gives the addresses.

| Record | Size | Holds | Place in the EEPROM |
|---|---:|---|---|
| User settings (`user_settings`) | 0x1FC bytes | Every setting of the on-screen menu; byte 8 is the language, byte 9 the brightness. | offset 0 |
| Factory record (`factory_record`) | 0x1C bytes | Factory menu and factory tool values, the key test. | offset 0x2E0 |
| Saved-mode table | 20 × 16 bytes | The input timings seen last. | offset 0x300 |
| Part record (`part_record`) | 0x30 bytes | Colour entries of the picture modes and related values. | offset 0x440 |
| Device settings (`device_settings`) | 0x50 bytes | Settings of the device rather than the user, such as the on-time counters and "PHY CTS AUTO". | offset 0x470 |

**Where they are stored.** [nvram_write](../src/leon2m/nvram/nvram_write.c) writes the EEPROM in pages of at most
16 bytes and waits after each page, without a time limit, until the chip answers. Its second path, through the
8051 into the flash, is for other storage devices; the one device of FW.021 is the EEPROM.

**When they are loaded.** At start-up [nvram_validate_settings_at_startup](../src/leon2m/nvram/nvram_validate_settings_at_startup.c)
checks the stored header against the defaults in ROM (the read-only part of the firmware file), writes the
defaults when the header is wrong, and loads the part record and the device settings. A little later
[nvram_load_user_settings](../src/leon2m/nvram/nvram_load_user_settings.c) loads the user settings and the factory
record; a record whose first and last marker words differ from the defaults is replaced by the defaults.

**When they are saved.** A change is not written at once. The menu marks the settings as changed; that becomes a
menu event, and `APPActionDispatcher` sets a save request and starts a one-second timer. When the timer runs out,
[sys_run_app_timer_task](../src/leon2m/sys/sys_run_app_timer_task.c) writes the whole user settings record
([SYSAPI_WriteEEPROM](../src/leon2m/nvram/SYSAPI_WriteEEPROM.c)), so changes in quick succession are saved together.

**Factory reset.** [sys_user_factory_reset](../src/leon2m/sys/sys_user_factory_reset.c) copies the defaults over
the user settings and applies every setting again. A few fields survive, among them the input source and the
language. The menu's Reset runs it through
[osd_run_settings_reset](../src/leon2m/osd/osd_run_settings_reset.c); the PC tool and DDC/CI can run it too.

**Functions to read first**

| Function | Why |
|---|---|
| [nvram_validate_settings_at_startup](../src/leon2m/nvram/nvram_validate_settings_at_startup.c) | What happens to bad or empty stored settings. |
| [nvram_load_user_settings](../src/leon2m/nvram/nvram_load_user_settings.c) | Loading with a fall-back to the defaults. |
| [nvram_write](../src/leon2m/nvram/nvram_write.c) | The EEPROM write, page by page. |
| [sys_run_app_timer_task](../src/leon2m/sys/sys_run_app_timer_task.c) | Step 9 is the delayed save; the other steps are worth a look too. |
| [sys_user_factory_reset](../src/leon2m/sys/sys_user_factory_reset.c) | Which settings a reset keeps. |

## 6. How the processors talk to each other

The processors cannot call each other's functions. Instead they share *mailboxes*: agreed places in shared memory
where one side leaves a message and the other picks it up. There are three, called portals in the code:

| Portal | Between | How it works |
|---|---|---|
| 0 | main program and 8051 | One command word (number and three bytes); four slots each way for longer messages, cut into 16-byte pieces. |
| 1 | main program and input program | One command slot of eight words with a marker byte and a checksum; one reply slot; status words the input program keeps up to date. |
| 2 | main program and Tensilica program | One command word (number, sub-code and a 16-bit value) and a block of start-up values. |

The 8051 serves portal 0 once per pass of its loop ([ipc_service_mailbox](../src/8051_bank1/ipc/ipc_service_mailbox.c)).
The input program checks the marker and the checksum of a command ([ipc_poll_command](../src/leon2s/ipc/ipc_poll_command.c))
and carries it out ([ipc_dispatch_command](../src/leon2s/ipc/ipc_dispatch_command.c)). A sender first waits a
short while for the slot to be empty: a slot that is not empty holds a command that has not been taken yet.

Three examples, one per portal:

- **Command 0x07 to the 8051**, sent with [ipc_send_8051_command](../src/leon2m/ipc/ipc_send_8051_command.c) and
  carried out by [ipc_run_command](../src/8051_bank1/ipc/ipc_run_command.c): set a DDC/CI address on some ports and
  switch them on. The update path uses it to open address 0x6E for the PC tool ([section 9](#9-firmware-update)).
- **Command 0x71 to the input program**, sent with [ipc_send_command](../src/leon2m/ipc/ipc_send_command.c) by
  [ipc_get_input_timing](../src/leon2m/ipc/ipc_get_input_timing.c): "read the timing of this input". The reply,
  built by [input_read_port_timing](../src/leon2s/input/input_read_port_timing.c), carries eight 16-bit numbers
  (line length, number of lines, picture size, sync widths).
- **Command 0x21 to the Tensilica program**, sent by
  [ldc_send_panel_size_and_start](../src/leon2m/ldc/ldc_send_panel_size_and_start.c): the panel size goes into the
  start-up block, then the command starts the program's processing.

Messages also flow the other way. The 8051 passes on what it receives for the main program: EDID read-backs, I2C
results, serial bytes, DDC/CI requests from the computer and remote-control pulses. The main program fetches them
([ipc_8051_poll_messages](../src/leon2m/ipc/ipc_8051_poll_messages.c)) and sorts them by type
([ipc_8051_decode_message](../src/leon2m/ipc/ipc_8051_decode_message.c)). The commands between the main processor, the 8051 and
the input processor are listed in [Mailbox commands](MAILBOX.md); those to the Tensilica program and to the update
agent in the [firmware map](MAP.md).

**Functions to read first**

| Function | Why |
|---|---|
| [ipc_send_8051_command](../src/leon2m/ipc/ipc_send_8051_command.c) | The simplest sender: one word, then wait. |
| [ipc_run_command](../src/8051_bank1/ipc/ipc_run_command.c) | The 8051's side: one `switch` over all commands. |
| [ipc_send_command](../src/leon2m/ipc/ipc_send_command.c) | A message with a marker and a checksum. |
| [ipc_dispatch_command](../src/leon2s/ipc/ipc_dispatch_command.c) | The input program's 109 commands, in groups. |
| [ipc_8051_decode_message](../src/leon2m/ipc/ipc_8051_decode_message.c) | Messages from the 8051, sorted by type. |

## 7. The Tensilica program

The Tensilica core runs a zone-dimming program: software for screens whose LED backlight is split into zones that
are dimmed one by one. Its own texts name the parts: "LDC" (the dimming controller), zone segments and how they are
merged, gain tables, LED pulse width ("PDIM") and LED current ("ADIM"). It is kept as assembly source with a
comment above every step that shows the C statement it came from.

**What it computes.** The chip's dimming hardware measures the picture in zones. When the hardware raises its
interrupt, [ldc_irq_handler](../src/tensilica/ldc/ldc_irq_handler.S) counts the event, and the main loop then runs
one processing pass ([ldc_run_pass_on_new_frame](../src/tensilica/ldc/ldc_run_pass_on_new_frame.S) →
[ldc_run_frame_pass](../src/tensilica/ldc/ldc_run_frame_pass.S)): it merges the zone values, runs them through the
current path and the pulse-width path, and writes the results back into the dimming hardware.

**What the main program tells it.** At start-up the main program sends six of the program's 46 commands through
portal 2: the panel size and start (0x21, read by [LDC_LoadPanel](../src/tensilica/ldc/LDC_LoadPanel.S)), the zone
counts (0x2B, [ldc_send_zone_counts](../src/leon2m/ldc/ldc_send_zone_counts.c)), the zone grid (0x2A), two single
values (0x84, 0x97) and a check command (0x40). A pass only runs after that check command has been received.
[ldc_poll_mailbox_command](../src/tensilica/ldc/ldc_poll_mailbox_command.S) reads each command and looks up its
function in a table.

**What it does not do here.** The LED driver chips are only set up by command 0x22, and the main program's sender
for it is never called. The main program never reads the results back either. So the program processes the
dimming hardware's measurements, but it drives no LEDs in this OLED monitor. Whether the hardware itself uses the
results is decided by how the block is wired inside the chip, which the firmware does not show
([what it does](MAP.md#what-it-does)).

**Functions to read first**

| Function | Why |
|---|---|
| [sys_init_and_run_main_loop](../src/tensilica/sys/sys_init_and_run_main_loop.S) | Everything the program sets up, and its short main loop. |
| [ldc_poll_mailbox_command](../src/tensilica/ldc/ldc_poll_mailbox_command.S) | How a command from the main program is read and run. |
| [ldc_run_frame_pass](../src/tensilica/ldc/ldc_run_frame_pass.S) | One pass over the zone values. |
| [LDC_LoadPanel](../src/tensilica/ldc/LDC_LoadPanel.S) | The panel description the program receives. |
| [ldc_send_panel_size_and_start](../src/leon2m/ldc/ldc_send_panel_size_and_start.c) | The main program's side of command 0x21. |

## 8. Control from outside

**DDC/CI from the computer.** A computer can read and change settings over the video cable, using DDC/CI at address
0x6E ([DDC](GLOSSARY.md) is the slow data channel inside the cable). The 8051 receives the request and passes it to
the main program. [ddc_handle_request](../src/leon2m/ddc/ddc_handle_request.c) checks its checksum, drops it when
it is wrong, and hands it on by its command: read a setting ("GetVCP"), change a setting ("SetVCP"), timing,
capabilities, or the factory tool. A setting code selects its case in a `switch`
([the two jump tables](MAP.md#monitor-control-from-the-pc-ddcci)); in the DDC/CI standard, for example, 0x10 is the
brightness and 0x60 the input source.

**The factory tool.** DDC/CI command 0xC0 carries the factory tool's requests
([ddc_tool_dispatch_command](../src/leon2m/ddc/ddc_tool_dispatch_command.c)). They switch factory mode and burn-in
on or off, set colour gains, write the factory record, run a reset and read back stored values.

**MSI's PC tool.** At start-up [uart_cmd_init_ports](../src/leon2m/uart/uart_cmd_init_ports.c) asks the 8051 to
open two of its serial ports at 115,200 baud. The bytes the tool sends arrive through the mailbox, and
[uart_cmd_run_tool_task](../src/leon2m/uart/uart_cmd_run_tool_task.c) collects them into frames. A frame "58" plus a
five-character id asks for a value ([uart_cmd_dispatch_get](../src/leon2m/uart/uart_cmd_dispatch_get.c)); a frame
"5b" plus an id and a value sets one ([uart_cmd_dispatch_set](../src/leon2m/uart/uart_cmd_dispatch_set.c)). The
monitor answers "5600+" when a setting was done and "5600-" when it was refused.

**Debug serial consoles.** Each of the three larger programs has a command line on a debug serial port. The main
program's ([dbg_command_shell](../src/leon2m/dbg/dbg_command_shell.c)) prints "MDBG >>", looks the first word of a
line up in a table of 12 commands and never waits for input. The input program's
([dbg_handle_input_line](../src/leon2s/dbg/dbg_handle_input_line.c)) has named commands too, plus two modes that
read and write single memory words. The Tensilica program greets with "Welcome to User's Command Line Debug".

**Functions to read first**

| Function | Why |
|---|---|
| [ddc_handle_request](../src/leon2m/ddc/ddc_handle_request.c) | The front door for DDC/CI. |
| [ddc_tool_dispatch_command](../src/leon2m/ddc/ddc_tool_dispatch_command.c) | What the factory tool can do. |
| [uart_cmd_run_tool_task](../src/leon2m/uart/uart_cmd_run_tool_task.c) | How a frame of the PC tool is received and answered. |
| [dbg_command_shell](../src/leon2m/dbg/dbg_command_shell.c) | A tiny command line, easy to follow. |
| [dbg_handle_input_line](../src/leon2s/dbg/dbg_handle_input_line.c) | The input program's console with its memory read and write modes. |

## 9. Firmware update

**The path MSI's tool takes.** The update starts as a normal PC tool request. The get command "580040:" is answered
by [UartSetI2CEnable](../src/leon2m/uart/UartSetI2CEnable.c): it sends the brightness as its answer, then has the
8051 close one serial port, switch the internal EDID of input 0 off and open the DDC/CI address 0x6E on that port.
The flash itself is written by the 8051: command 0x29 sends it into
[fwupd_run_flash_loop](../src/8051_bank1/fwupd/fwupd_run_flash_loop.c), a loop that never returns. It takes erase,
write and read commands from a small mailbox; one write command reads the page back and compares a 16-bit sum. No
function of the main program sends the number 0x29 as a fixed value. Once in that loop the 8051 no longer runs its
main loop, and with it the watch of section 2.

**The update agent.** The agent in the USB controller ([sys_main](../src/8051_bank2/sys/sys_main.c) of bank 2)
recognises a USB storage device, mounts its volume and can look for an update file, but it writes only when a
command byte arrives ([fwupd_step_port_state](../src/8051_bank2/fwupd/fwupd_step_port_state.c)). Every sender
found for those commands is in the main program, and the entry functions of this route there, such as
[fwupd_api_start_update](../src/leon2m/fwupd/fwupd_api_start_update.c), are never called in FW.021. Besides the
file name, the agent checks only a 16-bit sum, and only when a `CONFIG.BIN` with the right record is present
([fwupd_verify_file_sum](../src/8051_bank2/fwupd/fwupd_verify_file_sum.c)).

**When an update goes wrong.** Both routes need a main program that reaches its main loop: only the main loop
answers the PC tool and gives the 8051 its commands. The boot loader checks nothing, has no update mode and no
second copy to fall back on. So a firmware whose main program stops before its main loop can no longer be
replaced through MSI's tool; the flash chip then has to be written from outside the monitor. A firmware that only
misbehaves inside the main loop can still be replaced. [Modifying the firmware](MODIFYING.md) turns this into rules,
and the [update path](MAP.md#update-path) lists every step.

**Functions to read first**

| Function | Why |
|---|---|
| [UartSetI2CEnable](../src/leon2m/uart/UartSetI2CEnable.c) | The main program's part of the update path. |
| [fwupd_run_flash_loop](../src/8051_bank1/fwupd/fwupd_run_flash_loop.c) | The loop that writes the flash. |
| [fwupd_step_port_state](../src/8051_bank2/fwupd/fwupd_step_port_state.c) | The update agent's state machine and the commands it waits for. |
| [fwupd_verify_file_sum](../src/8051_bank2/fwupd/fwupd_verify_file_sum.c) | The only check of an update file on USB storage. |

## 10. Where to read next

**Reference pages.** [The documentation index](README.md) lists them all. The ones to reach for first:

| Page | Read it for |
|---|---|
| [A worked example: the panel mode selection](EXAMPLE-PANEL-MODE.md) | One function read from top to bottom, and what the two custom firmware files change. |
| [Firmware map](MAP.md) | The file layout, the full start-up sequence, the update path, the panel modes, DDC/CI and the Tensilica program. |
| [Mailbox commands](MAILBOX.md) | Every command between the processors. |
| [Data objects](DATA.md) and [Record fields](RECORDS.md) | What the main records and tables hold. |
| [Menu fonts and texts](OSD-TEXT.md) | How the menu's fonts and texts are stored and edited. |
| [Modifying the firmware](MODIFYING.md) | What can be changed safely, and how to check a changed file. |
| [Function names](NAMES.md) | How the names were given and how far each one can be trusted. |
| [Glossary](GLOSSARY.md) | The terms in plain words. |

**Index pages.** `docs/names/` holds one page per program, with every function grouped by subject and linked to its
file: [main program](names/leon2m.md), [input program](names/leon2s.md), [boot loader](names/8051_bank0.md),
[8051 main application](names/8051_bank1.md), [update agent](names/8051_bank2.md) and
[Tensilica program](names/tensilica.md). Pages ending in `-data` list the named data, for example
[the main program's data](names/leon2m-data.md).

**Finding a function's file.** Files are named after their function and sorted by subject:
`src/<program>/<subject>/<name>.c` (`.S` for assembly). The subject is usually the first word of the name, so
`osd_draw_text` is in `src/leon2m/osd/osd_draw_text.c`; for names the firmware prints itself, such as
`SYSAPI_GetPanelParamStruct`, the index pages give the folder. Each function also has a label built from an
address, such as `FUN_a00dac38`; `symbols/<program>.files.json` gives the file of every label, and
`symbols/<program>.names.json` its name, a one-line description and the subject. Both 8051 programs have a
`sys_main`, so check the folder.

**Reading a file.** Start with the comment block above the function: what it does, its arguments, who calls it,
and its phases in order. Then read the code with that list beside you.
