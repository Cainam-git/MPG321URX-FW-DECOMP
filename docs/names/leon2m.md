# Function names: Main processor (leon2m)

3,968 entries from `symbols/leon2m.names.json`, grouped by subject and listed by name; the label of each entry gives its address. [Function names](../NAMES.md) describes how the names were given and what the *basis* column means. A name with a link has a source file of its own, in the folder of its subject (`src/leon2m/<subject>/`); the other entries are jump tables, library members and entry points inside another function's file.

| Basis | Entries |
|---|---:|
| proven | 1,252 |
| derived | 1,363 |
| descriptive | 1,353 |

## Subjects

- [Start-up](#startup) (33)
- [Traps and crash handling](#trap) (261)
- [Interrupts](#irq) (120)
- [Timers and delays](#timer) (20)
- [System control: channels, modes, configuration](#sys) (575)
- [Video inputs: detection, measurement, routing](#input) (363)
- [HDMI](#hdmi) (32)
- [DisplayPort](#dp) (4)
- [EDID](#edid) (26)
- [DDC/CI and the service tool](#ddc) (81)
- [Panel: timing, output, power, PWM](#panel) (245)
- [OLED panel care](#oled) (72)
- [Picture: colour, gamma, windows](#pq) (282)
- [HDR](#hdr) (1)
- [On-screen menu](#osd) (774)
- [Menu fonts](#font) (46)
- [Sound](#audio) (25)
- [Dimming processor and its hardware block](#ldc) (73)
- [Messages between the processors](#ipc) (186)
- [Saved settings](#nvram) (47)
- [Flash memory](#flash) (2)
- [Firmware update](#fwupd) (25)
- [Power states](#power) (18)
- [Pins](#gpio) (91)
- [I2C](#i2c) (16)
- [Serial ports](#uart) (289)
- [USB](#usb) (1)
- [Register access](#reg) (54)
- [Debug facilities](#dbg) (44)
- [Library routines](#lib) (162)

<a id="startup"></a>
## Start-up

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`App_CoolInitialize`](../../src/leon2m/startup/App_CoolInitialize.c) | `FUN_a0087020` | Initialise the application state, show the logo and prepare the main loop (start-up step 3) | proven |
| [`App_Initialize`](../../src/leon2m/startup/App_Initialize.c) | `FUN_a0086ae8` | Switch the power pins on in the order for the power-on type and initialise the modules. | proven |
| [`startup_bring_up_system`](../../src/leon2m/startup/startup_bring_up_system.c) | `FUN_a015266c` | Run the second start-up step: wait for OTP and the input processor, then initialise the system. | proven |
| [`startup_check_data_ram_config`](../../src/leon2m/startup/startup_check_data_ram_config.c) | `FUN_a00de70c` | Check that the data memory window of the processor matches the program's layout. | proven |
| [`startup_init_8051_i2c_ports`](../../src/leon2m/startup/startup_init_8051_i2c_ports.c) | `FUN_a01243dc` | Have the 8051 switch the DDC/CI slave on for ports 0, 2, 4, 6 and off for ports 1, 3, 5, 7. | derived |
| [`startup_init_block_5a80`](../../src/leon2m/startup/startup_init_block_5a80.c) | `FUN_a01141fc` | Write the start values and two constant tables of the block at 0xCF015A80. | descriptive |
| [`startup_init_clock_blocks`](../../src/leon2m/startup/startup_init_clock_blocks.c) | `FUN_a0118400` | Set up the three identical clock blocks. | derived |
| [`startup_init_clocks`](../../src/leon2m/startup/startup_init_clocks.c) | `FUN_a0102680` | Set two fixed clock values and their enable bits. | derived |
| [`startup_init_converter_sources`](../../src/leon2m/startup/startup_init_converter_sources.c) | `FUN_a00fd558` | Reset the converter's source fields, switch the V-by-One receiver off and print a message. | derived |
| [`startup_init_core`](../../src/leon2m/startup/startup_init_core.c) | `FUN_a00de7c4` | Set up the processor core, the debug serial port and the timers, and print the banner. | proven |
| [`startup_init_display_clocks`](../../src/leon2m/startup/startup_init_display_clocks.c) | `FUN_a0112db0` | Set up the display clocks, reset the blocks and load the ROM settings. | derived |
| [`startup_init_display_output`](../../src/leon2m/startup/startup_init_display_output.c) | `FUN_a0141964` | Build the working panel timing row and set up the output at power-on. | derived |
| [`startup_init_eeprom_layout`](../../src/leon2m/startup/startup_init_eeprom_layout.c) | `FUN_a01400e0` | Build the layout of the storage areas from the ROM tables. | derived |
| [`startup_init_input_blocks`](../../src/leon2m/startup/startup_init_input_blocks.c) | `FUN_a00f87dc` | Clear the per-block offsets and write the start values of all eight input capture blocks. | descriptive |
| [`startup_init_input_ports`](../../src/leon2m/startup/startup_init_input_ports.c) | `FUN_a012b7b8` | Send the link settings of the input ports and set up their pins. | derived |
| [`startup_init_level_generator`](../../src/leon2m/startup/startup_init_level_generator.c) | `FUN_a0129b44` | Load the table and start values of the level generator block. | descriptive |
| [`startup_init_output_layers`](../../src/leon2m/startup/startup_init_output_layers.c) | `FUN_a010b610` | Run the start sequence of the two output halves. | derived |
| [`startup_init_path_blocks`](../../src/leon2m/startup/startup_init_path_blocks.c) | `FUN_a01423dc` | Initialise both signal path blocks and their selector. | derived |
| [`startup_init_pins`](../../src/leon2m/startup/startup_init_pins.c) | `FUN_a0124448` | Set up the pins from the boot byte of the 8051 and the port table. | proven |
| [`startup_load_block8_config`](../../src/leon2m/startup/startup_load_block8_config.c) | `FUN_a01410a4` | Load the start configuration of picture block 8. | descriptive |
| [`startup_load_default_panel_row`](../../src/leon2m/startup/startup_load_default_panel_row.c) | `FUN_a0124180` | Copy the ROM default panel timing row into the active row. | proven |
| [`startup_load_default_records`](../../src/leon2m/startup/startup_load_default_records.c) | `FUN_a0142380` | Load the default part record, settings record and panel timing row. | proven |
| [`startup_load_port_edids`](../../src/leon2m/startup/startup_load_port_edids.c) | `FUN_a012c188` | Load the EDID of each port whose EDID flag is 1 into the 8051; switch the other internal EDIDs off. | proven |
| [`startup_main`](../../src/leon2m/startup/startup_main.c) | `FUN_a00295a4` | Run the three start-up steps, then the main loop tasks forever. | proven |
| [`startup_register_app_callbacks`](../../src/leon2m/startup/startup_register_app_callbacks.c) | `FUN_a008796c` | Register the ten application callbacks with the system layer. | proven |
| [`startup_reset_channel_records`](../../src/leon2m/startup/startup_reset_channel_records.c) | `FUN_a013c944` | Reset the four channel records. | proven |
| [`startup_reset_input_table`](../../src/leon2m/startup/startup_reset_input_table.c) | `FUN_a0141b60` | Reset the seven-entry input table. | derived |
| [`startup_reset_output_blocks`](../../src/leon2m/startup/startup_reset_output_blocks.c) | `FUN_a01073b8` | Write the fixed start values of seven output block registers. | descriptive |
| [`startup_reset_port_table`](../../src/leon2m/startup/startup_reset_port_table.c) | `FUN_a01427d4` | Reset the eight-entry port table. | derived |
| [`startup_return_one`](../../src/leon2m/startup/startup_return_one.c) | `FUN_a01423a0` | Return 1. | descriptive |
| [`startup_select_default_port`](../../src/leon2m/startup/startup_select_default_port.c) | `FUN_a012fc04` | Give channel 0 the port with code 0x61. | derived |
| [`System_Initialize`](../../src/leon2m/startup/System_Initialize.c) | `FUN_a015209c` | Initialise clocks, port records, the output configuration and frame-rate conversion. | proven |
| `System_Initialize_jump_table` | `switchdataD_a01511a0` | Jump table 1 of the switch statements in System_Initialize. | proven |

<a id="trap"></a>
## Traps and crash handling

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`trap_data_access_exception_entry`](../../src/leon2m/trap/trap_data_access_exception_entry.S) | `FUN_a0028090` | Trap table slot 0x09 (data access exception): reads %psr and %tbr and jumps to the handler at 0xa0029460. | proven |
| [`trap_division_by_zero_entry`](../../src/leon2m/trap/trap_division_by_zero_entry.S) | `FUN_a00282a0` | Trap table slot 0x2a (division by zero): reads %psr and %tbr and jumps to the handler at 0xa0029460. | proven |
| [`trap_dump_crash_and_halt`](../../src/leon2m/trap/trap_dump_crash_and_halt.S) | `FUN_a002d5ac` | Print the crash report (PC, trap type, registers, stack, code) and halt. | proven |
| [`trap_enter_halt_loop`](../../src/leon2m/trap/trap_enter_halt_loop.S) | `FUN_a0029060` | Raise the interrupt level to 15, enable traps and call the endless loop. | derived |
| [`trap_fp_disabled_unhandled`](../../src/leon2m/trap/trap_fp_disabled_unhandled.S) | `FUN_a0028040` | Trap table slot 0x04 (fp disabled): not handled, raises a software trap. | proven |
| [`trap_fp_exception_entry`](../../src/leon2m/trap/trap_fp_exception_entry.S) | `FUN_a0028080` | Trap table slot 0x08 (fp exception): reads %psr and %tbr and jumps to the handler at 0xa0029210. | proven |
| [`trap_halt_forever`](../../src/leon2m/trap/trap_halt_forever.c) | `FUN_a002a878` | Loop forever (halt) | proven |
| [`trap_handle_faults`](../../src/leon2m/trap/trap_handle_faults.S) | `FUN_a00291c4` | Handle processor faults: window traps, skipped traps, watchpoint, store error, fatal dump. | proven |
| [`trap_illegal_instruction_entry`](../../src/leon2m/trap/trap_illegal_instruction_entry.S) | `FUN_a0028020` | Trap table slot 0x02 (illegal instruction): reads %psr and %tbr and jumps to the handler at 0xa0029460. | proven |
| [`trap_instruction_access_exception_unhandled`](../../src/leon2m/trap/trap_instruction_access_exception_unhandled.S) | `FUN_a0028010` | Trap table slot 0x01 (instruction access exception): not handled, raises a software trap. | proven |
| [`trap_interrupt_level_1_entry`](../../src/leon2m/trap/trap_interrupt_level_1_entry.S) | `FUN_a0028110` | Trap table slot 0x11 (interrupt level 1): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_2_entry`](../../src/leon2m/trap/trap_interrupt_level_2_entry.S) | `FUN_a0028120` | Trap table slot 0x12 (interrupt level 2): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_3_entry`](../../src/leon2m/trap/trap_interrupt_level_3_entry.S) | `FUN_a0028130` | Trap table slot 0x13 (interrupt level 3): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_4_entry`](../../src/leon2m/trap/trap_interrupt_level_4_entry.S) | `FUN_a0028140` | Trap table slot 0x14 (interrupt level 4): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_5_entry`](../../src/leon2m/trap/trap_interrupt_level_5_entry.S) | `FUN_a0028150` | Trap table slot 0x15 (interrupt level 5): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_6_entry`](../../src/leon2m/trap/trap_interrupt_level_6_entry.S) | `FUN_a0028160` | Trap table slot 0x16 (interrupt level 6): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_7_entry`](../../src/leon2m/trap/trap_interrupt_level_7_entry.S) | `FUN_a0028170` | Trap table slot 0x17 (interrupt level 7): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_8_entry`](../../src/leon2m/trap/trap_interrupt_level_8_entry.S) | `FUN_a0028180` | Trap table slot 0x18 (interrupt level 8): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_9_entry`](../../src/leon2m/trap/trap_interrupt_level_9_entry.S) | `FUN_a0028190` | Trap table slot 0x19 (interrupt level 9): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_10_entry`](../../src/leon2m/trap/trap_interrupt_level_10_entry.S) | `FUN_a00281a0` | Trap table slot 0x1a (interrupt level 10): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_11_entry`](../../src/leon2m/trap/trap_interrupt_level_11_entry.S) | `FUN_a00281b0` | Trap table slot 0x1b (interrupt level 11): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_12_entry`](../../src/leon2m/trap/trap_interrupt_level_12_entry.S) | `FUN_a00281c0` | Trap table slot 0x1c (interrupt level 12): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_13_entry`](../../src/leon2m/trap/trap_interrupt_level_13_entry.S) | `FUN_a00281d0` | Trap table slot 0x1d (interrupt level 13): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_14_entry`](../../src/leon2m/trap/trap_interrupt_level_14_entry.S) | `FUN_a00281e0` | Trap table slot 0x1e (interrupt level 14): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_interrupt_level_15_entry`](../../src/leon2m/trap/trap_interrupt_level_15_entry.S) | `FUN_a00281f0` | Trap table slot 0x1f (interrupt level 15): reads %psr and %tbr and jumps to the handler at 0xa00290ec. | proven |
| [`trap_privileged_instruction_entry`](../../src/leon2m/trap/trap_privileged_instruction_entry.S) | `FUN_a0028030` | Trap table slot 0x03 (privileged instruction): reads %psr and %tbr and jumps to the handler at 0xa0029460. | proven |
| [`trap_reset_entry`](../../src/leon2m/trap/trap_reset_entry.S) | `FUN_a0028000` | Trap table slot 0x00 (reset): jumps to the handler at 0xa0029000. | proven |
| [`trap_return_from_ta1`](../../src/leon2m/trap/trap_return_from_ta1.S) | `FUN_a0028810` | Return from software trap 'ta 1' to the instruction after it. | proven |
| [`trap_save_return_pc`](../../src/leon2m/trap/trap_save_return_pc.S) | `FUN_a0029054` | Copy the trapped PC/nPC to %l5/%l6 and fall into the halt path that follows. | descriptive |
| [`trap_software_trap_0_entry`](../../src/leon2m/trap/trap_software_trap_0_entry.S) | `FUN_a0028800` | Trap table slot 0x80 (software trap 0): reads %psr and %tbr and jumps to the handler at 0xa0029388. | proven |
| [`trap_software_trap_2_entry`](../../src/leon2m/trap/trap_software_trap_2_entry.S) | `FUN_a0028820` | Trap table slot 0x82 (software trap 2): reads %psr and %tbr and jumps to the handler at 0xa0029460. | proven |
| [`trap_software_trap_3_entry`](../../src/leon2m/trap/trap_software_trap_3_entry.S) | `FUN_a0028830` | Trap table slot 0x83 (software trap 3): reads %psr and %tbr and jumps to the handler at 0xa0029328. | proven |
| [`trap_software_trap_4_entry`](../../src/leon2m/trap/trap_software_trap_4_entry.S) | `FUN_a0028840` | Trap table slot 0x84 (software trap 4): reads %psr and %tbr and jumps to the handler at 0xa0029210. | proven |
| [`trap_software_trap_5_unhandled`](../../src/leon2m/trap/trap_software_trap_5_unhandled.S) | `FUN_a0028850` | Trap table slot 0x85 (software trap 5): not handled, raises a software trap. | proven |
| [`trap_software_trap_6_unhandled`](../../src/leon2m/trap/trap_software_trap_6_unhandled.S) | `FUN_a0028860` | Trap table slot 0x86 (software trap 6): not handled, raises a software trap. | proven |
| [`trap_software_trap_7_unhandled`](../../src/leon2m/trap/trap_software_trap_7_unhandled.S) | `FUN_a0028870` | Trap table slot 0x87 (software trap 7): not handled, raises a software trap. | proven |
| [`trap_software_trap_8_unhandled`](../../src/leon2m/trap/trap_software_trap_8_unhandled.S) | `FUN_a0028880` | Trap table slot 0x88 (software trap 8): not handled, raises a software trap. | proven |
| [`trap_software_trap_9_unhandled`](../../src/leon2m/trap/trap_software_trap_9_unhandled.S) | `FUN_a0028890` | Trap table slot 0x89 (software trap 9): not handled, raises a software trap. | proven |
| [`trap_software_trap_10_unhandled`](../../src/leon2m/trap/trap_software_trap_10_unhandled.S) | `FUN_a00288a0` | Trap table slot 0x8a (software trap 10): not handled, raises a software trap. | proven |
| [`trap_software_trap_11_unhandled`](../../src/leon2m/trap/trap_software_trap_11_unhandled.S) | `FUN_a00288b0` | Trap table slot 0x8b (software trap 11): not handled, raises a software trap. | proven |
| [`trap_software_trap_12_unhandled`](../../src/leon2m/trap/trap_software_trap_12_unhandled.S) | `FUN_a00288c0` | Trap table slot 0x8c (software trap 12): not handled, raises a software trap. | proven |
| [`trap_software_trap_13_unhandled`](../../src/leon2m/trap/trap_software_trap_13_unhandled.S) | `FUN_a00288d0` | Trap table slot 0x8d (software trap 13): not handled, raises a software trap. | proven |
| [`trap_software_trap_14_unhandled`](../../src/leon2m/trap/trap_software_trap_14_unhandled.S) | `FUN_a00288e0` | Trap table slot 0x8e (software trap 14): not handled, raises a software trap. | proven |
| [`trap_software_trap_15_unhandled`](../../src/leon2m/trap/trap_software_trap_15_unhandled.S) | `FUN_a00288f0` | Trap table slot 0x8f (software trap 15): not handled, raises a software trap. | proven |
| [`trap_software_trap_16_unhandled`](../../src/leon2m/trap/trap_software_trap_16_unhandled.S) | `FUN_a0028900` | Trap table slot 0x90 (software trap 16): not handled, raises a software trap. | proven |
| [`trap_software_trap_17_unhandled`](../../src/leon2m/trap/trap_software_trap_17_unhandled.S) | `FUN_a0028910` | Trap table slot 0x91 (software trap 17): not handled, raises a software trap. | proven |
| [`trap_software_trap_18_unhandled`](../../src/leon2m/trap/trap_software_trap_18_unhandled.S) | `FUN_a0028920` | Trap table slot 0x92 (software trap 18): not handled, raises a software trap. | proven |
| [`trap_software_trap_19_unhandled`](../../src/leon2m/trap/trap_software_trap_19_unhandled.S) | `FUN_a0028930` | Trap table slot 0x93 (software trap 19): not handled, raises a software trap. | proven |
| [`trap_software_trap_20_unhandled`](../../src/leon2m/trap/trap_software_trap_20_unhandled.S) | `FUN_a0028940` | Trap table slot 0x94 (software trap 20): not handled, raises a software trap. | proven |
| [`trap_software_trap_21_unhandled`](../../src/leon2m/trap/trap_software_trap_21_unhandled.S) | `FUN_a0028950` | Trap table slot 0x95 (software trap 21): not handled, raises a software trap. | proven |
| [`trap_software_trap_22_unhandled`](../../src/leon2m/trap/trap_software_trap_22_unhandled.S) | `FUN_a0028960` | Trap table slot 0x96 (software trap 22): not handled, raises a software trap. | proven |
| [`trap_software_trap_23_unhandled`](../../src/leon2m/trap/trap_software_trap_23_unhandled.S) | `FUN_a0028970` | Trap table slot 0x97 (software trap 23): not handled, raises a software trap. | proven |
| [`trap_software_trap_24_unhandled`](../../src/leon2m/trap/trap_software_trap_24_unhandled.S) | `FUN_a0028980` | Trap table slot 0x98 (software trap 24): not handled, raises a software trap. | proven |
| [`trap_software_trap_25_unhandled`](../../src/leon2m/trap/trap_software_trap_25_unhandled.S) | `FUN_a0028990` | Trap table slot 0x99 (software trap 25): not handled, raises a software trap. | proven |
| [`trap_software_trap_26_unhandled`](../../src/leon2m/trap/trap_software_trap_26_unhandled.S) | `FUN_a00289a0` | Trap table slot 0x9a (software trap 26): not handled, raises a software trap. | proven |
| [`trap_software_trap_27_unhandled`](../../src/leon2m/trap/trap_software_trap_27_unhandled.S) | `FUN_a00289b0` | Trap table slot 0x9b (software trap 27): not handled, raises a software trap. | proven |
| [`trap_software_trap_28_unhandled`](../../src/leon2m/trap/trap_software_trap_28_unhandled.S) | `FUN_a00289c0` | Trap table slot 0x9c (software trap 28): not handled, raises a software trap. | proven |
| [`trap_software_trap_29_unhandled`](../../src/leon2m/trap/trap_software_trap_29_unhandled.S) | `FUN_a00289d0` | Trap table slot 0x9d (software trap 29): not handled, raises a software trap. | proven |
| [`trap_software_trap_30_unhandled`](../../src/leon2m/trap/trap_software_trap_30_unhandled.S) | `FUN_a00289e0` | Trap table slot 0x9e (software trap 30): not handled, raises a software trap. | proven |
| [`trap_software_trap_31_unhandled`](../../src/leon2m/trap/trap_software_trap_31_unhandled.S) | `FUN_a00289f0` | Trap table slot 0x9f (software trap 31): not handled, raises a software trap. | proven |
| [`trap_software_trap_32_unhandled`](../../src/leon2m/trap/trap_software_trap_32_unhandled.S) | `FUN_a0028a00` | Trap table slot 0xa0 (software trap 32): not handled, raises a software trap. | proven |
| [`trap_software_trap_33_unhandled`](../../src/leon2m/trap/trap_software_trap_33_unhandled.S) | `FUN_a0028a10` | Trap table slot 0xa1 (software trap 33): not handled, raises a software trap. | proven |
| [`trap_software_trap_34_unhandled`](../../src/leon2m/trap/trap_software_trap_34_unhandled.S) | `FUN_a0028a20` | Trap table slot 0xa2 (software trap 34): not handled, raises a software trap. | proven |
| [`trap_software_trap_35_unhandled`](../../src/leon2m/trap/trap_software_trap_35_unhandled.S) | `FUN_a0028a30` | Trap table slot 0xa3 (software trap 35): not handled, raises a software trap. | proven |
| [`trap_software_trap_36_unhandled`](../../src/leon2m/trap/trap_software_trap_36_unhandled.S) | `FUN_a0028a40` | Trap table slot 0xa4 (software trap 36): not handled, raises a software trap. | proven |
| [`trap_software_trap_37_unhandled`](../../src/leon2m/trap/trap_software_trap_37_unhandled.S) | `FUN_a0028a50` | Trap table slot 0xa5 (software trap 37): not handled, raises a software trap. | proven |
| [`trap_software_trap_38_unhandled`](../../src/leon2m/trap/trap_software_trap_38_unhandled.S) | `FUN_a0028a60` | Trap table slot 0xa6 (software trap 38): not handled, raises a software trap. | proven |
| [`trap_software_trap_39_unhandled`](../../src/leon2m/trap/trap_software_trap_39_unhandled.S) | `FUN_a0028a70` | Trap table slot 0xa7 (software trap 39): not handled, raises a software trap. | proven |
| [`trap_software_trap_40_unhandled`](../../src/leon2m/trap/trap_software_trap_40_unhandled.S) | `FUN_a0028a80` | Trap table slot 0xa8 (software trap 40): not handled, raises a software trap. | proven |
| [`trap_software_trap_41_unhandled`](../../src/leon2m/trap/trap_software_trap_41_unhandled.S) | `FUN_a0028a90` | Trap table slot 0xa9 (software trap 41): not handled, raises a software trap. | proven |
| [`trap_software_trap_42_unhandled`](../../src/leon2m/trap/trap_software_trap_42_unhandled.S) | `FUN_a0028aa0` | Trap table slot 0xaa (software trap 42): not handled, raises a software trap. | proven |
| [`trap_software_trap_43_unhandled`](../../src/leon2m/trap/trap_software_trap_43_unhandled.S) | `FUN_a0028ab0` | Trap table slot 0xab (software trap 43): not handled, raises a software trap. | proven |
| [`trap_software_trap_44_unhandled`](../../src/leon2m/trap/trap_software_trap_44_unhandled.S) | `FUN_a0028ac0` | Trap table slot 0xac (software trap 44): not handled, raises a software trap. | proven |
| [`trap_software_trap_45_unhandled`](../../src/leon2m/trap/trap_software_trap_45_unhandled.S) | `FUN_a0028ad0` | Trap table slot 0xad (software trap 45): not handled, raises a software trap. | proven |
| [`trap_software_trap_46_unhandled`](../../src/leon2m/trap/trap_software_trap_46_unhandled.S) | `FUN_a0028ae0` | Trap table slot 0xae (software trap 46): not handled, raises a software trap. | proven |
| [`trap_software_trap_47_unhandled`](../../src/leon2m/trap/trap_software_trap_47_unhandled.S) | `FUN_a0028af0` | Trap table slot 0xaf (software trap 47): not handled, raises a software trap. | proven |
| [`trap_software_trap_48_unhandled`](../../src/leon2m/trap/trap_software_trap_48_unhandled.S) | `FUN_a0028b00` | Trap table slot 0xb0 (software trap 48): not handled, raises a software trap. | proven |
| [`trap_software_trap_49_unhandled`](../../src/leon2m/trap/trap_software_trap_49_unhandled.S) | `FUN_a0028b10` | Trap table slot 0xb1 (software trap 49): not handled, raises a software trap. | proven |
| [`trap_software_trap_50_unhandled`](../../src/leon2m/trap/trap_software_trap_50_unhandled.S) | `FUN_a0028b20` | Trap table slot 0xb2 (software trap 50): not handled, raises a software trap. | proven |
| [`trap_software_trap_51_unhandled`](../../src/leon2m/trap/trap_software_trap_51_unhandled.S) | `FUN_a0028b30` | Trap table slot 0xb3 (software trap 51): not handled, raises a software trap. | proven |
| [`trap_software_trap_52_unhandled`](../../src/leon2m/trap/trap_software_trap_52_unhandled.S) | `FUN_a0028b40` | Trap table slot 0xb4 (software trap 52): not handled, raises a software trap. | proven |
| [`trap_software_trap_53_unhandled`](../../src/leon2m/trap/trap_software_trap_53_unhandled.S) | `FUN_a0028b50` | Trap table slot 0xb5 (software trap 53): not handled, raises a software trap. | proven |
| [`trap_software_trap_54_unhandled`](../../src/leon2m/trap/trap_software_trap_54_unhandled.S) | `FUN_a0028b60` | Trap table slot 0xb6 (software trap 54): not handled, raises a software trap. | proven |
| [`trap_software_trap_55_unhandled`](../../src/leon2m/trap/trap_software_trap_55_unhandled.S) | `FUN_a0028b70` | Trap table slot 0xb7 (software trap 55): not handled, raises a software trap. | proven |
| [`trap_software_trap_56_unhandled`](../../src/leon2m/trap/trap_software_trap_56_unhandled.S) | `FUN_a0028b80` | Trap table slot 0xb8 (software trap 56): not handled, raises a software trap. | proven |
| [`trap_software_trap_57_unhandled`](../../src/leon2m/trap/trap_software_trap_57_unhandled.S) | `FUN_a0028b90` | Trap table slot 0xb9 (software trap 57): not handled, raises a software trap. | proven |
| [`trap_software_trap_58_unhandled`](../../src/leon2m/trap/trap_software_trap_58_unhandled.S) | `FUN_a0028ba0` | Trap table slot 0xba (software trap 58): not handled, raises a software trap. | proven |
| [`trap_software_trap_59_unhandled`](../../src/leon2m/trap/trap_software_trap_59_unhandled.S) | `FUN_a0028bb0` | Trap table slot 0xbb (software trap 59): not handled, raises a software trap. | proven |
| [`trap_software_trap_60_unhandled`](../../src/leon2m/trap/trap_software_trap_60_unhandled.S) | `FUN_a0028bc0` | Trap table slot 0xbc (software trap 60): not handled, raises a software trap. | proven |
| [`trap_software_trap_61_unhandled`](../../src/leon2m/trap/trap_software_trap_61_unhandled.S) | `FUN_a0028bd0` | Trap table slot 0xbd (software trap 61): not handled, raises a software trap. | proven |
| [`trap_software_trap_62_unhandled`](../../src/leon2m/trap/trap_software_trap_62_unhandled.S) | `FUN_a0028be0` | Trap table slot 0xbe (software trap 62): not handled, raises a software trap. | proven |
| [`trap_software_trap_63_unhandled`](../../src/leon2m/trap/trap_software_trap_63_unhandled.S) | `FUN_a0028bf0` | Trap table slot 0xbf (software trap 63): not handled, raises a software trap. | proven |
| [`trap_software_trap_64_unhandled`](../../src/leon2m/trap/trap_software_trap_64_unhandled.S) | `FUN_a0028c00` | Trap table slot 0xc0 (software trap 64): not handled, raises a software trap. | proven |
| [`trap_software_trap_65_unhandled`](../../src/leon2m/trap/trap_software_trap_65_unhandled.S) | `FUN_a0028c10` | Trap table slot 0xc1 (software trap 65): not handled, raises a software trap. | proven |
| [`trap_software_trap_66_unhandled`](../../src/leon2m/trap/trap_software_trap_66_unhandled.S) | `FUN_a0028c20` | Trap table slot 0xc2 (software trap 66): not handled, raises a software trap. | proven |
| [`trap_software_trap_67_unhandled`](../../src/leon2m/trap/trap_software_trap_67_unhandled.S) | `FUN_a0028c30` | Trap table slot 0xc3 (software trap 67): not handled, raises a software trap. | proven |
| [`trap_software_trap_68_unhandled`](../../src/leon2m/trap/trap_software_trap_68_unhandled.S) | `FUN_a0028c40` | Trap table slot 0xc4 (software trap 68): not handled, raises a software trap. | proven |
| [`trap_software_trap_69_unhandled`](../../src/leon2m/trap/trap_software_trap_69_unhandled.S) | `FUN_a0028c50` | Trap table slot 0xc5 (software trap 69): not handled, raises a software trap. | proven |
| [`trap_software_trap_70_unhandled`](../../src/leon2m/trap/trap_software_trap_70_unhandled.S) | `FUN_a0028c60` | Trap table slot 0xc6 (software trap 70): not handled, raises a software trap. | proven |
| [`trap_software_trap_71_unhandled`](../../src/leon2m/trap/trap_software_trap_71_unhandled.S) | `FUN_a0028c70` | Trap table slot 0xc7 (software trap 71): not handled, raises a software trap. | proven |
| [`trap_software_trap_72_unhandled`](../../src/leon2m/trap/trap_software_trap_72_unhandled.S) | `FUN_a0028c80` | Trap table slot 0xc8 (software trap 72): not handled, raises a software trap. | proven |
| [`trap_software_trap_73_unhandled`](../../src/leon2m/trap/trap_software_trap_73_unhandled.S) | `FUN_a0028c90` | Trap table slot 0xc9 (software trap 73): not handled, raises a software trap. | proven |
| [`trap_software_trap_74_unhandled`](../../src/leon2m/trap/trap_software_trap_74_unhandled.S) | `FUN_a0028ca0` | Trap table slot 0xca (software trap 74): not handled, raises a software trap. | proven |
| [`trap_software_trap_75_unhandled`](../../src/leon2m/trap/trap_software_trap_75_unhandled.S) | `FUN_a0028cb0` | Trap table slot 0xcb (software trap 75): not handled, raises a software trap. | proven |
| [`trap_software_trap_76_unhandled`](../../src/leon2m/trap/trap_software_trap_76_unhandled.S) | `FUN_a0028cc0` | Trap table slot 0xcc (software trap 76): not handled, raises a software trap. | proven |
| [`trap_software_trap_77_unhandled`](../../src/leon2m/trap/trap_software_trap_77_unhandled.S) | `FUN_a0028cd0` | Trap table slot 0xcd (software trap 77): not handled, raises a software trap. | proven |
| [`trap_software_trap_78_unhandled`](../../src/leon2m/trap/trap_software_trap_78_unhandled.S) | `FUN_a0028ce0` | Trap table slot 0xce (software trap 78): not handled, raises a software trap. | proven |
| [`trap_software_trap_79_unhandled`](../../src/leon2m/trap/trap_software_trap_79_unhandled.S) | `FUN_a0028cf0` | Trap table slot 0xcf (software trap 79): not handled, raises a software trap. | proven |
| [`trap_software_trap_80_unhandled`](../../src/leon2m/trap/trap_software_trap_80_unhandled.S) | `FUN_a0028d00` | Trap table slot 0xd0 (software trap 80): not handled, raises a software trap. | proven |
| [`trap_software_trap_81_unhandled`](../../src/leon2m/trap/trap_software_trap_81_unhandled.S) | `FUN_a0028d10` | Trap table slot 0xd1 (software trap 81): not handled, raises a software trap. | proven |
| [`trap_software_trap_82_unhandled`](../../src/leon2m/trap/trap_software_trap_82_unhandled.S) | `FUN_a0028d20` | Trap table slot 0xd2 (software trap 82): not handled, raises a software trap. | proven |
| [`trap_software_trap_83_unhandled`](../../src/leon2m/trap/trap_software_trap_83_unhandled.S) | `FUN_a0028d30` | Trap table slot 0xd3 (software trap 83): not handled, raises a software trap. | proven |
| [`trap_software_trap_84_unhandled`](../../src/leon2m/trap/trap_software_trap_84_unhandled.S) | `FUN_a0028d40` | Trap table slot 0xd4 (software trap 84): not handled, raises a software trap. | proven |
| [`trap_software_trap_85_unhandled`](../../src/leon2m/trap/trap_software_trap_85_unhandled.S) | `FUN_a0028d50` | Trap table slot 0xd5 (software trap 85): not handled, raises a software trap. | proven |
| [`trap_software_trap_86_unhandled`](../../src/leon2m/trap/trap_software_trap_86_unhandled.S) | `FUN_a0028d60` | Trap table slot 0xd6 (software trap 86): not handled, raises a software trap. | proven |
| [`trap_software_trap_87_unhandled`](../../src/leon2m/trap/trap_software_trap_87_unhandled.S) | `FUN_a0028d70` | Trap table slot 0xd7 (software trap 87): not handled, raises a software trap. | proven |
| [`trap_software_trap_88_unhandled`](../../src/leon2m/trap/trap_software_trap_88_unhandled.S) | `FUN_a0028d80` | Trap table slot 0xd8 (software trap 88): not handled, raises a software trap. | proven |
| [`trap_software_trap_89_unhandled`](../../src/leon2m/trap/trap_software_trap_89_unhandled.S) | `FUN_a0028d90` | Trap table slot 0xd9 (software trap 89): not handled, raises a software trap. | proven |
| [`trap_software_trap_90_unhandled`](../../src/leon2m/trap/trap_software_trap_90_unhandled.S) | `FUN_a0028da0` | Trap table slot 0xda (software trap 90): not handled, raises a software trap. | proven |
| [`trap_software_trap_91_unhandled`](../../src/leon2m/trap/trap_software_trap_91_unhandled.S) | `FUN_a0028db0` | Trap table slot 0xdb (software trap 91): not handled, raises a software trap. | proven |
| [`trap_software_trap_92_unhandled`](../../src/leon2m/trap/trap_software_trap_92_unhandled.S) | `FUN_a0028dc0` | Trap table slot 0xdc (software trap 92): not handled, raises a software trap. | proven |
| [`trap_software_trap_93_unhandled`](../../src/leon2m/trap/trap_software_trap_93_unhandled.S) | `FUN_a0028dd0` | Trap table slot 0xdd (software trap 93): not handled, raises a software trap. | proven |
| [`trap_software_trap_94_unhandled`](../../src/leon2m/trap/trap_software_trap_94_unhandled.S) | `FUN_a0028de0` | Trap table slot 0xde (software trap 94): not handled, raises a software trap. | proven |
| [`trap_software_trap_95_unhandled`](../../src/leon2m/trap/trap_software_trap_95_unhandled.S) | `FUN_a0028df0` | Trap table slot 0xdf (software trap 95): not handled, raises a software trap. | proven |
| [`trap_software_trap_96_unhandled`](../../src/leon2m/trap/trap_software_trap_96_unhandled.S) | `FUN_a0028e00` | Trap table slot 0xe0 (software trap 96): not handled, raises a software trap. | proven |
| [`trap_software_trap_97_unhandled`](../../src/leon2m/trap/trap_software_trap_97_unhandled.S) | `FUN_a0028e10` | Trap table slot 0xe1 (software trap 97): not handled, raises a software trap. | proven |
| [`trap_software_trap_98_unhandled`](../../src/leon2m/trap/trap_software_trap_98_unhandled.S) | `FUN_a0028e20` | Trap table slot 0xe2 (software trap 98): not handled, raises a software trap. | proven |
| [`trap_software_trap_99_unhandled`](../../src/leon2m/trap/trap_software_trap_99_unhandled.S) | `FUN_a0028e30` | Trap table slot 0xe3 (software trap 99): not handled, raises a software trap. | proven |
| [`trap_software_trap_100_unhandled`](../../src/leon2m/trap/trap_software_trap_100_unhandled.S) | `FUN_a0028e40` | Trap table slot 0xe4 (software trap 100): not handled, raises a software trap. | proven |
| [`trap_software_trap_101_unhandled`](../../src/leon2m/trap/trap_software_trap_101_unhandled.S) | `FUN_a0028e50` | Trap table slot 0xe5 (software trap 101): not handled, raises a software trap. | proven |
| [`trap_software_trap_102_unhandled`](../../src/leon2m/trap/trap_software_trap_102_unhandled.S) | `FUN_a0028e60` | Trap table slot 0xe6 (software trap 102): not handled, raises a software trap. | proven |
| [`trap_software_trap_103_unhandled`](../../src/leon2m/trap/trap_software_trap_103_unhandled.S) | `FUN_a0028e70` | Trap table slot 0xe7 (software trap 103): not handled, raises a software trap. | proven |
| [`trap_software_trap_104_unhandled`](../../src/leon2m/trap/trap_software_trap_104_unhandled.S) | `FUN_a0028e80` | Trap table slot 0xe8 (software trap 104): not handled, raises a software trap. | proven |
| [`trap_software_trap_105_unhandled`](../../src/leon2m/trap/trap_software_trap_105_unhandled.S) | `FUN_a0028e90` | Trap table slot 0xe9 (software trap 105): not handled, raises a software trap. | proven |
| [`trap_software_trap_106_unhandled`](../../src/leon2m/trap/trap_software_trap_106_unhandled.S) | `FUN_a0028ea0` | Trap table slot 0xea (software trap 106): not handled, raises a software trap. | proven |
| [`trap_software_trap_107_unhandled`](../../src/leon2m/trap/trap_software_trap_107_unhandled.S) | `FUN_a0028eb0` | Trap table slot 0xeb (software trap 107): not handled, raises a software trap. | proven |
| [`trap_software_trap_108_unhandled`](../../src/leon2m/trap/trap_software_trap_108_unhandled.S) | `FUN_a0028ec0` | Trap table slot 0xec (software trap 108): not handled, raises a software trap. | proven |
| [`trap_software_trap_109_unhandled`](../../src/leon2m/trap/trap_software_trap_109_unhandled.S) | `FUN_a0028ed0` | Trap table slot 0xed (software trap 109): not handled, raises a software trap. | proven |
| [`trap_software_trap_110_unhandled`](../../src/leon2m/trap/trap_software_trap_110_unhandled.S) | `FUN_a0028ee0` | Trap table slot 0xee (software trap 110): not handled, raises a software trap. | proven |
| [`trap_software_trap_111_unhandled`](../../src/leon2m/trap/trap_software_trap_111_unhandled.S) | `FUN_a0028ef0` | Trap table slot 0xef (software trap 111): not handled, raises a software trap. | proven |
| [`trap_software_trap_112_unhandled`](../../src/leon2m/trap/trap_software_trap_112_unhandled.S) | `FUN_a0028f00` | Trap table slot 0xf0 (software trap 112): not handled, raises a software trap. | proven |
| [`trap_software_trap_113_unhandled`](../../src/leon2m/trap/trap_software_trap_113_unhandled.S) | `FUN_a0028f10` | Trap table slot 0xf1 (software trap 113): not handled, raises a software trap. | proven |
| [`trap_software_trap_114_unhandled`](../../src/leon2m/trap/trap_software_trap_114_unhandled.S) | `FUN_a0028f20` | Trap table slot 0xf2 (software trap 114): not handled, raises a software trap. | proven |
| [`trap_software_trap_115_unhandled`](../../src/leon2m/trap/trap_software_trap_115_unhandled.S) | `FUN_a0028f30` | Trap table slot 0xf3 (software trap 115): not handled, raises a software trap. | proven |
| [`trap_software_trap_116_unhandled`](../../src/leon2m/trap/trap_software_trap_116_unhandled.S) | `FUN_a0028f40` | Trap table slot 0xf4 (software trap 116): not handled, raises a software trap. | proven |
| [`trap_software_trap_117_unhandled`](../../src/leon2m/trap/trap_software_trap_117_unhandled.S) | `FUN_a0028f50` | Trap table slot 0xf5 (software trap 117): not handled, raises a software trap. | proven |
| [`trap_software_trap_118_unhandled`](../../src/leon2m/trap/trap_software_trap_118_unhandled.S) | `FUN_a0028f60` | Trap table slot 0xf6 (software trap 118): not handled, raises a software trap. | proven |
| [`trap_software_trap_119_unhandled`](../../src/leon2m/trap/trap_software_trap_119_unhandled.S) | `FUN_a0028f70` | Trap table slot 0xf7 (software trap 119): not handled, raises a software trap. | proven |
| [`trap_software_trap_120_unhandled`](../../src/leon2m/trap/trap_software_trap_120_unhandled.S) | `FUN_a0028f80` | Trap table slot 0xf8 (software trap 120): not handled, raises a software trap. | proven |
| [`trap_software_trap_121_unhandled`](../../src/leon2m/trap/trap_software_trap_121_unhandled.S) | `FUN_a0028f90` | Trap table slot 0xf9 (software trap 121): not handled, raises a software trap. | proven |
| [`trap_software_trap_122_unhandled`](../../src/leon2m/trap/trap_software_trap_122_unhandled.S) | `FUN_a0028fa0` | Trap table slot 0xfa (software trap 122): not handled, raises a software trap. | proven |
| [`trap_software_trap_123_unhandled`](../../src/leon2m/trap/trap_software_trap_123_unhandled.S) | `FUN_a0028fb0` | Trap table slot 0xfb (software trap 123): not handled, raises a software trap. | proven |
| [`trap_software_trap_124_unhandled`](../../src/leon2m/trap/trap_software_trap_124_unhandled.S) | `FUN_a0028fc0` | Trap table slot 0xfc (software trap 124): not handled, raises a software trap. | proven |
| [`trap_software_trap_125_unhandled`](../../src/leon2m/trap/trap_software_trap_125_unhandled.S) | `FUN_a0028fd0` | Trap table slot 0xfd (software trap 125): not handled, raises a software trap. | proven |
| [`trap_software_trap_126_unhandled`](../../src/leon2m/trap/trap_software_trap_126_unhandled.S) | `FUN_a0028fe0` | Trap table slot 0xfe (software trap 126): not handled, raises a software trap. | proven |
| [`trap_software_trap_127_unhandled`](../../src/leon2m/trap/trap_software_trap_127_unhandled.S) | `FUN_a0028ff0` | Trap table slot 0xff (software trap 127): not handled, raises a software trap. | proven |
| [`trap_tag_overflow_unhandled`](../../src/leon2m/trap/trap_tag_overflow_unhandled.S) | `FUN_a00280a0` | Trap table slot 0x0a (tag overflow): not handled, raises a software trap. | proven |
| [`trap_type_0b_entry`](../../src/leon2m/trap/trap_type_0b_entry.S) | `FUN_a00280b0` | Trap table slot 0x0b (type 0b): reads %psr and %tbr and jumps to the handler at 0xa0029220. | proven |
| [`trap_type_0c_unhandled`](../../src/leon2m/trap/trap_type_0c_unhandled.S) | `FUN_a00280c0` | Trap table slot 0x0c (type 0c): not handled, raises a software trap. | proven |
| [`trap_type_0d_unhandled`](../../src/leon2m/trap/trap_type_0d_unhandled.S) | `FUN_a00280d0` | Trap table slot 0x0d (type 0d): not handled, raises a software trap. | proven |
| [`trap_type_0e_unhandled`](../../src/leon2m/trap/trap_type_0e_unhandled.S) | `FUN_a00280e0` | Trap table slot 0x0e (type 0e): not handled, raises a software trap. | proven |
| [`trap_type_0f_unhandled`](../../src/leon2m/trap/trap_type_0f_unhandled.S) | `FUN_a00280f0` | Trap table slot 0x0f (type 0f): not handled, raises a software trap. | proven |
| [`trap_type_2b_entry`](../../src/leon2m/trap/trap_type_2b_entry.S) | `FUN_a00282b0` | Trap table slot 0x2b (type 2b): reads %psr and %tbr and jumps to the handler at 0xa0029244. | proven |
| [`trap_type_2c_unhandled`](../../src/leon2m/trap/trap_type_2c_unhandled.S) | `FUN_a00282c0` | Trap table slot 0x2c (type 2c): not handled, raises a software trap. | proven |
| [`trap_type_2d_unhandled`](../../src/leon2m/trap/trap_type_2d_unhandled.S) | `FUN_a00282d0` | Trap table slot 0x2d (type 2d): not handled, raises a software trap. | proven |
| [`trap_type_2e_unhandled`](../../src/leon2m/trap/trap_type_2e_unhandled.S) | `FUN_a00282e0` | Trap table slot 0x2e (type 2e): not handled, raises a software trap. | proven |
| [`trap_type_2f_unhandled`](../../src/leon2m/trap/trap_type_2f_unhandled.S) | `FUN_a00282f0` | Trap table slot 0x2f (type 2f): not handled, raises a software trap. | proven |
| [`trap_type_3a_unhandled`](../../src/leon2m/trap/trap_type_3a_unhandled.S) | `FUN_a00283a0` | Trap table slot 0x3a (type 3a): not handled, raises a software trap. | proven |
| [`trap_type_3b_unhandled`](../../src/leon2m/trap/trap_type_3b_unhandled.S) | `FUN_a00283b0` | Trap table slot 0x3b (type 3b): not handled, raises a software trap. | proven |
| [`trap_type_3c_unhandled`](../../src/leon2m/trap/trap_type_3c_unhandled.S) | `FUN_a00283c0` | Trap table slot 0x3c (type 3c): not handled, raises a software trap. | proven |
| [`trap_type_3d_unhandled`](../../src/leon2m/trap/trap_type_3d_unhandled.S) | `FUN_a00283d0` | Trap table slot 0x3d (type 3d): not handled, raises a software trap. | proven |
| [`trap_type_3e_unhandled`](../../src/leon2m/trap/trap_type_3e_unhandled.S) | `FUN_a00283e0` | Trap table slot 0x3e (type 3e): not handled, raises a software trap. | proven |
| [`trap_type_3f_unhandled`](../../src/leon2m/trap/trap_type_3f_unhandled.S) | `FUN_a00283f0` | Trap table slot 0x3f (type 3f): not handled, raises a software trap. | proven |
| [`trap_type_4a_unhandled`](../../src/leon2m/trap/trap_type_4a_unhandled.S) | `FUN_a00284a0` | Trap table slot 0x4a (type 4a): not handled, raises a software trap. | proven |
| [`trap_type_4b_unhandled`](../../src/leon2m/trap/trap_type_4b_unhandled.S) | `FUN_a00284b0` | Trap table slot 0x4b (type 4b): not handled, raises a software trap. | proven |
| [`trap_type_4c_unhandled`](../../src/leon2m/trap/trap_type_4c_unhandled.S) | `FUN_a00284c0` | Trap table slot 0x4c (type 4c): not handled, raises a software trap. | proven |
| [`trap_type_4d_unhandled`](../../src/leon2m/trap/trap_type_4d_unhandled.S) | `FUN_a00284d0` | Trap table slot 0x4d (type 4d): not handled, raises a software trap. | proven |
| [`trap_type_4e_unhandled`](../../src/leon2m/trap/trap_type_4e_unhandled.S) | `FUN_a00284e0` | Trap table slot 0x4e (type 4e): not handled, raises a software trap. | proven |
| [`trap_type_4f_unhandled`](../../src/leon2m/trap/trap_type_4f_unhandled.S) | `FUN_a00284f0` | Trap table slot 0x4f (type 4f): not handled, raises a software trap. | proven |
| [`trap_type_5a_unhandled`](../../src/leon2m/trap/trap_type_5a_unhandled.S) | `FUN_a00285a0` | Trap table slot 0x5a (type 5a): not handled, raises a software trap. | proven |
| [`trap_type_5b_unhandled`](../../src/leon2m/trap/trap_type_5b_unhandled.S) | `FUN_a00285b0` | Trap table slot 0x5b (type 5b): not handled, raises a software trap. | proven |
| [`trap_type_5c_unhandled`](../../src/leon2m/trap/trap_type_5c_unhandled.S) | `FUN_a00285c0` | Trap table slot 0x5c (type 5c): not handled, raises a software trap. | proven |
| [`trap_type_5d_unhandled`](../../src/leon2m/trap/trap_type_5d_unhandled.S) | `FUN_a00285d0` | Trap table slot 0x5d (type 5d): not handled, raises a software trap. | proven |
| [`trap_type_5e_unhandled`](../../src/leon2m/trap/trap_type_5e_unhandled.S) | `FUN_a00285e0` | Trap table slot 0x5e (type 5e): not handled, raises a software trap. | proven |
| [`trap_type_5f_unhandled`](../../src/leon2m/trap/trap_type_5f_unhandled.S) | `FUN_a00285f0` | Trap table slot 0x5f (type 5f): not handled, raises a software trap. | proven |
| [`trap_type_6a_unhandled`](../../src/leon2m/trap/trap_type_6a_unhandled.S) | `FUN_a00286a0` | Trap table slot 0x6a (type 6a): not handled, raises a software trap. | proven |
| [`trap_type_6b_unhandled`](../../src/leon2m/trap/trap_type_6b_unhandled.S) | `FUN_a00286b0` | Trap table slot 0x6b (type 6b): not handled, raises a software trap. | proven |
| [`trap_type_6c_unhandled`](../../src/leon2m/trap/trap_type_6c_unhandled.S) | `FUN_a00286c0` | Trap table slot 0x6c (type 6c): not handled, raises a software trap. | proven |
| [`trap_type_6d_unhandled`](../../src/leon2m/trap/trap_type_6d_unhandled.S) | `FUN_a00286d0` | Trap table slot 0x6d (type 6d): not handled, raises a software trap. | proven |
| [`trap_type_6e_unhandled`](../../src/leon2m/trap/trap_type_6e_unhandled.S) | `FUN_a00286e0` | Trap table slot 0x6e (type 6e): not handled, raises a software trap. | proven |
| [`trap_type_6f_unhandled`](../../src/leon2m/trap/trap_type_6f_unhandled.S) | `FUN_a00286f0` | Trap table slot 0x6f (type 6f): not handled, raises a software trap. | proven |
| [`trap_type_7a_unhandled`](../../src/leon2m/trap/trap_type_7a_unhandled.S) | `FUN_a00287a0` | Trap table slot 0x7a (type 7a): not handled, raises a software trap. | proven |
| [`trap_type_7b_unhandled`](../../src/leon2m/trap/trap_type_7b_unhandled.S) | `FUN_a00287b0` | Trap table slot 0x7b (type 7b): not handled, raises a software trap. | proven |
| [`trap_type_7c_unhandled`](../../src/leon2m/trap/trap_type_7c_unhandled.S) | `FUN_a00287c0` | Trap table slot 0x7c (type 7c): not handled, raises a software trap. | proven |
| [`trap_type_7d_unhandled`](../../src/leon2m/trap/trap_type_7d_unhandled.S) | `FUN_a00287d0` | Trap table slot 0x7d (type 7d): not handled, raises a software trap. | proven |
| [`trap_type_7e_unhandled`](../../src/leon2m/trap/trap_type_7e_unhandled.S) | `FUN_a00287e0` | Trap table slot 0x7e (type 7e): not handled, raises a software trap. | proven |
| [`trap_type_7f_unhandled`](../../src/leon2m/trap/trap_type_7f_unhandled.S) | `FUN_a00287f0` | Trap table slot 0x7f (type 7f): not handled, raises a software trap. | proven |
| [`trap_type_10_unhandled`](../../src/leon2m/trap/trap_type_10_unhandled.S) | `FUN_a0028100` | Trap table slot 0x10 (type 10): not handled, raises a software trap. | proven |
| [`trap_type_20_unhandled`](../../src/leon2m/trap/trap_type_20_unhandled.S) | `FUN_a0028200` | Trap table slot 0x20 (type 20): not handled, raises a software trap. | proven |
| [`trap_type_21_unhandled`](../../src/leon2m/trap/trap_type_21_unhandled.S) | `FUN_a0028210` | Trap table slot 0x21 (type 21): not handled, raises a software trap. | proven |
| [`trap_type_22_unhandled`](../../src/leon2m/trap/trap_type_22_unhandled.S) | `FUN_a0028220` | Trap table slot 0x22 (type 22): not handled, raises a software trap. | proven |
| [`trap_type_23_unhandled`](../../src/leon2m/trap/trap_type_23_unhandled.S) | `FUN_a0028230` | Trap table slot 0x23 (type 23): not handled, raises a software trap. | proven |
| [`trap_type_24_unhandled`](../../src/leon2m/trap/trap_type_24_unhandled.S) | `FUN_a0028240` | Trap table slot 0x24 (type 24): not handled, raises a software trap. | proven |
| [`trap_type_25_unhandled`](../../src/leon2m/trap/trap_type_25_unhandled.S) | `FUN_a0028250` | Trap table slot 0x25 (type 25): not handled, raises a software trap. | proven |
| [`trap_type_26_unhandled`](../../src/leon2m/trap/trap_type_26_unhandled.S) | `FUN_a0028260` | Trap table slot 0x26 (type 26): not handled, raises a software trap. | proven |
| [`trap_type_27_unhandled`](../../src/leon2m/trap/trap_type_27_unhandled.S) | `FUN_a0028270` | Trap table slot 0x27 (type 27): not handled, raises a software trap. | proven |
| [`trap_type_28_unhandled`](../../src/leon2m/trap/trap_type_28_unhandled.S) | `FUN_a0028280` | Trap table slot 0x28 (type 28): not handled, raises a software trap. | proven |
| [`trap_type_29_unhandled`](../../src/leon2m/trap/trap_type_29_unhandled.S) | `FUN_a0028290` | Trap table slot 0x29 (type 29): not handled, raises a software trap. | proven |
| [`trap_type_30_unhandled`](../../src/leon2m/trap/trap_type_30_unhandled.S) | `FUN_a0028300` | Trap table slot 0x30 (type 30): not handled, raises a software trap. | proven |
| [`trap_type_31_unhandled`](../../src/leon2m/trap/trap_type_31_unhandled.S) | `FUN_a0028310` | Trap table slot 0x31 (type 31): not handled, raises a software trap. | proven |
| [`trap_type_32_unhandled`](../../src/leon2m/trap/trap_type_32_unhandled.S) | `FUN_a0028320` | Trap table slot 0x32 (type 32): not handled, raises a software trap. | proven |
| [`trap_type_33_unhandled`](../../src/leon2m/trap/trap_type_33_unhandled.S) | `FUN_a0028330` | Trap table slot 0x33 (type 33): not handled, raises a software trap. | proven |
| [`trap_type_34_unhandled`](../../src/leon2m/trap/trap_type_34_unhandled.S) | `FUN_a0028340` | Trap table slot 0x34 (type 34): not handled, raises a software trap. | proven |
| [`trap_type_35_unhandled`](../../src/leon2m/trap/trap_type_35_unhandled.S) | `FUN_a0028350` | Trap table slot 0x35 (type 35): not handled, raises a software trap. | proven |
| [`trap_type_36_unhandled`](../../src/leon2m/trap/trap_type_36_unhandled.S) | `FUN_a0028360` | Trap table slot 0x36 (type 36): not handled, raises a software trap. | proven |
| [`trap_type_37_unhandled`](../../src/leon2m/trap/trap_type_37_unhandled.S) | `FUN_a0028370` | Trap table slot 0x37 (type 37): not handled, raises a software trap. | proven |
| [`trap_type_38_unhandled`](../../src/leon2m/trap/trap_type_38_unhandled.S) | `FUN_a0028380` | Trap table slot 0x38 (type 38): not handled, raises a software trap. | proven |
| [`trap_type_39_unhandled`](../../src/leon2m/trap/trap_type_39_unhandled.S) | `FUN_a0028390` | Trap table slot 0x39 (type 39): not handled, raises a software trap. | proven |
| [`trap_type_40_unhandled`](../../src/leon2m/trap/trap_type_40_unhandled.S) | `FUN_a0028400` | Trap table slot 0x40 (type 40): not handled, raises a software trap. | proven |
| [`trap_type_41_unhandled`](../../src/leon2m/trap/trap_type_41_unhandled.S) | `FUN_a0028410` | Trap table slot 0x41 (type 41): not handled, raises a software trap. | proven |
| [`trap_type_42_unhandled`](../../src/leon2m/trap/trap_type_42_unhandled.S) | `FUN_a0028420` | Trap table slot 0x42 (type 42): not handled, raises a software trap. | proven |
| [`trap_type_43_unhandled`](../../src/leon2m/trap/trap_type_43_unhandled.S) | `FUN_a0028430` | Trap table slot 0x43 (type 43): not handled, raises a software trap. | proven |
| [`trap_type_44_unhandled`](../../src/leon2m/trap/trap_type_44_unhandled.S) | `FUN_a0028440` | Trap table slot 0x44 (type 44): not handled, raises a software trap. | proven |
| [`trap_type_45_unhandled`](../../src/leon2m/trap/trap_type_45_unhandled.S) | `FUN_a0028450` | Trap table slot 0x45 (type 45): not handled, raises a software trap. | proven |
| [`trap_type_46_unhandled`](../../src/leon2m/trap/trap_type_46_unhandled.S) | `FUN_a0028460` | Trap table slot 0x46 (type 46): not handled, raises a software trap. | proven |
| [`trap_type_47_unhandled`](../../src/leon2m/trap/trap_type_47_unhandled.S) | `FUN_a0028470` | Trap table slot 0x47 (type 47): not handled, raises a software trap. | proven |
| [`trap_type_48_unhandled`](../../src/leon2m/trap/trap_type_48_unhandled.S) | `FUN_a0028480` | Trap table slot 0x48 (type 48): not handled, raises a software trap. | proven |
| [`trap_type_49_unhandled`](../../src/leon2m/trap/trap_type_49_unhandled.S) | `FUN_a0028490` | Trap table slot 0x49 (type 49): not handled, raises a software trap. | proven |
| [`trap_type_50_unhandled`](../../src/leon2m/trap/trap_type_50_unhandled.S) | `FUN_a0028500` | Trap table slot 0x50 (type 50): not handled, raises a software trap. | proven |
| [`trap_type_51_unhandled`](../../src/leon2m/trap/trap_type_51_unhandled.S) | `FUN_a0028510` | Trap table slot 0x51 (type 51): not handled, raises a software trap. | proven |
| [`trap_type_52_unhandled`](../../src/leon2m/trap/trap_type_52_unhandled.S) | `FUN_a0028520` | Trap table slot 0x52 (type 52): not handled, raises a software trap. | proven |
| [`trap_type_53_unhandled`](../../src/leon2m/trap/trap_type_53_unhandled.S) | `FUN_a0028530` | Trap table slot 0x53 (type 53): not handled, raises a software trap. | proven |
| [`trap_type_54_unhandled`](../../src/leon2m/trap/trap_type_54_unhandled.S) | `FUN_a0028540` | Trap table slot 0x54 (type 54): not handled, raises a software trap. | proven |
| [`trap_type_55_unhandled`](../../src/leon2m/trap/trap_type_55_unhandled.S) | `FUN_a0028550` | Trap table slot 0x55 (type 55): not handled, raises a software trap. | proven |
| [`trap_type_56_unhandled`](../../src/leon2m/trap/trap_type_56_unhandled.S) | `FUN_a0028560` | Trap table slot 0x56 (type 56): not handled, raises a software trap. | proven |
| [`trap_type_57_unhandled`](../../src/leon2m/trap/trap_type_57_unhandled.S) | `FUN_a0028570` | Trap table slot 0x57 (type 57): not handled, raises a software trap. | proven |
| [`trap_type_58_unhandled`](../../src/leon2m/trap/trap_type_58_unhandled.S) | `FUN_a0028580` | Trap table slot 0x58 (type 58): not handled, raises a software trap. | proven |
| [`trap_type_59_unhandled`](../../src/leon2m/trap/trap_type_59_unhandled.S) | `FUN_a0028590` | Trap table slot 0x59 (type 59): not handled, raises a software trap. | proven |
| [`trap_type_60_unhandled`](../../src/leon2m/trap/trap_type_60_unhandled.S) | `FUN_a0028600` | Trap table slot 0x60 (type 60): not handled, raises a software trap. | proven |
| [`trap_type_61_unhandled`](../../src/leon2m/trap/trap_type_61_unhandled.S) | `FUN_a0028610` | Trap table slot 0x61 (type 61): not handled, raises a software trap. | proven |
| [`trap_type_62_unhandled`](../../src/leon2m/trap/trap_type_62_unhandled.S) | `FUN_a0028620` | Trap table slot 0x62 (type 62): not handled, raises a software trap. | proven |
| [`trap_type_63_unhandled`](../../src/leon2m/trap/trap_type_63_unhandled.S) | `FUN_a0028630` | Trap table slot 0x63 (type 63): not handled, raises a software trap. | proven |
| [`trap_type_64_unhandled`](../../src/leon2m/trap/trap_type_64_unhandled.S) | `FUN_a0028640` | Trap table slot 0x64 (type 64): not handled, raises a software trap. | proven |
| [`trap_type_65_unhandled`](../../src/leon2m/trap/trap_type_65_unhandled.S) | `FUN_a0028650` | Trap table slot 0x65 (type 65): not handled, raises a software trap. | proven |
| [`trap_type_66_unhandled`](../../src/leon2m/trap/trap_type_66_unhandled.S) | `FUN_a0028660` | Trap table slot 0x66 (type 66): not handled, raises a software trap. | proven |
| [`trap_type_67_unhandled`](../../src/leon2m/trap/trap_type_67_unhandled.S) | `FUN_a0028670` | Trap table slot 0x67 (type 67): not handled, raises a software trap. | proven |
| [`trap_type_68_unhandled`](../../src/leon2m/trap/trap_type_68_unhandled.S) | `FUN_a0028680` | Trap table slot 0x68 (type 68): not handled, raises a software trap. | proven |
| [`trap_type_69_unhandled`](../../src/leon2m/trap/trap_type_69_unhandled.S) | `FUN_a0028690` | Trap table slot 0x69 (type 69): not handled, raises a software trap. | proven |
| [`trap_type_70_unhandled`](../../src/leon2m/trap/trap_type_70_unhandled.S) | `FUN_a0028700` | Trap table slot 0x70 (type 70): not handled, raises a software trap. | proven |
| [`trap_type_71_unhandled`](../../src/leon2m/trap/trap_type_71_unhandled.S) | `FUN_a0028710` | Trap table slot 0x71 (type 71): not handled, raises a software trap. | proven |
| [`trap_type_72_unhandled`](../../src/leon2m/trap/trap_type_72_unhandled.S) | `FUN_a0028720` | Trap table slot 0x72 (type 72): not handled, raises a software trap. | proven |
| [`trap_type_73_unhandled`](../../src/leon2m/trap/trap_type_73_unhandled.S) | `FUN_a0028730` | Trap table slot 0x73 (type 73): not handled, raises a software trap. | proven |
| [`trap_type_74_unhandled`](../../src/leon2m/trap/trap_type_74_unhandled.S) | `FUN_a0028740` | Trap table slot 0x74 (type 74): not handled, raises a software trap. | proven |
| [`trap_type_75_unhandled`](../../src/leon2m/trap/trap_type_75_unhandled.S) | `FUN_a0028750` | Trap table slot 0x75 (type 75): not handled, raises a software trap. | proven |
| [`trap_type_76_unhandled`](../../src/leon2m/trap/trap_type_76_unhandled.S) | `FUN_a0028760` | Trap table slot 0x76 (type 76): not handled, raises a software trap. | proven |
| [`trap_type_77_unhandled`](../../src/leon2m/trap/trap_type_77_unhandled.S) | `FUN_a0028770` | Trap table slot 0x77 (type 77): not handled, raises a software trap. | proven |
| [`trap_type_78_unhandled`](../../src/leon2m/trap/trap_type_78_unhandled.S) | `FUN_a0028780` | Trap table slot 0x78 (type 78): not handled, raises a software trap. | proven |
| [`trap_type_79_unhandled`](../../src/leon2m/trap/trap_type_79_unhandled.S) | `FUN_a0028790` | Trap table slot 0x79 (type 79): not handled, raises a software trap. | proven |
| [`trap_unaligned_address_entry`](../../src/leon2m/trap/trap_unaligned_address_entry.S) | `FUN_a0028070` | Trap table slot 0x07 (unaligned address): reads %psr and %tbr and jumps to the handler at 0xa0029460. | proven |
| [`trap_window_overflow_entry`](../../src/leon2m/trap/trap_window_overflow_entry.S) | `FUN_a0028050` | Trap table slot 0x05 (window overflow): reads %psr and %tbr and jumps to the handler at 0xa0029278. | proven |
| [`trap_window_underflow_entry`](../../src/leon2m/trap/trap_window_underflow_entry.S) | `FUN_a0028060` | Trap table slot 0x06 (window underflow): reads %psr and %tbr and jumps to the handler at 0xa00292d0. | proven |

<a id="irq"></a>
## Interrupts

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`irq_dispatch`](../../src/leon2m/irq/irq_dispatch.S) | `FUN_a0029128` | Save the globals, call the level handler from table 0xA8027B50 and restore. | proven |
| [`irq_empty_handler`](../../src/leon2m/irq/irq_empty_handler.c) | `FUN_a00295e4` | Return at once (its address stands in the word right after the interrupt level table). | derived |
| [`irq_empty_handler_copy`](../../src/leon2m/irq/irq_empty_handler_copy.c) | `FUN_a0029818` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy2`](../../src/leon2m/irq/irq_empty_handler_copy2.c) | `FUN_a002c4a8` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy3`](../../src/leon2m/irq/irq_empty_handler_copy3.c) | `FUN_a002c4b0` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy4`](../../src/leon2m/irq/irq_empty_handler_copy4.c) | `FUN_a002c4b8` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy5`](../../src/leon2m/irq/irq_empty_handler_copy5.c) | `FUN_a002c4c0` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy6`](../../src/leon2m/irq/irq_empty_handler_copy6.c) | `FUN_a002c4c8` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy7`](../../src/leon2m/irq/irq_empty_handler_copy7.c) | `FUN_a009108c` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy8`](../../src/leon2m/irq/irq_empty_handler_copy8.c) | `FUN_a009a018` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy9`](../../src/leon2m/irq/irq_empty_handler_copy9.c) | `FUN_a00ba9d0` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy10`](../../src/leon2m/irq/irq_empty_handler_copy10.c) | `FUN_a00baee8` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy11`](../../src/leon2m/irq/irq_empty_handler_copy11.c) | `FUN_a00baef0` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy12`](../../src/leon2m/irq/irq_empty_handler_copy12.c) | `FUN_a00bb44c` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy13`](../../src/leon2m/irq/irq_empty_handler_copy13.c) | `FUN_a00bb520` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy14`](../../src/leon2m/irq/irq_empty_handler_copy14.c) | `FUN_a00bf2c8` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy15`](../../src/leon2m/irq/irq_empty_handler_copy15.c) | `FUN_a00d5ea4` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy16`](../../src/leon2m/irq/irq_empty_handler_copy16.c) | `FUN_a00d5f9c` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy17`](../../src/leon2m/irq/irq_empty_handler_copy17.c) | `FUN_a00da848` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy18`](../../src/leon2m/irq/irq_empty_handler_copy18.c) | `FUN_a00da850` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy19`](../../src/leon2m/irq/irq_empty_handler_copy19.c) | `FUN_a00da858` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy20`](../../src/leon2m/irq/irq_empty_handler_copy20.c) | `FUN_a00da860` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy21`](../../src/leon2m/irq/irq_empty_handler_copy21.c) | `FUN_a00da868` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy22`](../../src/leon2m/irq/irq_empty_handler_copy22.c) | `FUN_a00ddac4` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy23`](../../src/leon2m/irq/irq_empty_handler_copy23.c) | `FUN_a00ddacc` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy24`](../../src/leon2m/irq/irq_empty_handler_copy24.c) | `FUN_a00ddad4` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy25`](../../src/leon2m/irq/irq_empty_handler_copy25.c) | `FUN_a00ddadc` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy26`](../../src/leon2m/irq/irq_empty_handler_copy26.c) | `FUN_a00e0ca8` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy27`](../../src/leon2m/irq/irq_empty_handler_copy27.c) | `FUN_a00e0cb0` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy28`](../../src/leon2m/irq/irq_empty_handler_copy28.c) | `FUN_a00e0d08` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy29`](../../src/leon2m/irq/irq_empty_handler_copy29.c) | `FUN_a00e0d10` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy30`](../../src/leon2m/irq/irq_empty_handler_copy30.c) | `FUN_a00e724c` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy31`](../../src/leon2m/irq/irq_empty_handler_copy31.c) | `FUN_a00ed528` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy32`](../../src/leon2m/irq/irq_empty_handler_copy32.c) | `FUN_a00fe444` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy33`](../../src/leon2m/irq/irq_empty_handler_copy33.c) | `FUN_a0101860` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy34`](../../src/leon2m/irq/irq_empty_handler_copy34.c) | `FUN_a0101d94` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy35`](../../src/leon2m/irq/irq_empty_handler_copy35.c) | `FUN_a0103254` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy36`](../../src/leon2m/irq/irq_empty_handler_copy36.c) | `FUN_a0105af0` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy37`](../../src/leon2m/irq/irq_empty_handler_copy37.c) | `FUN_a0108e4c` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy38`](../../src/leon2m/irq/irq_empty_handler_copy38.c) | `FUN_a010983c` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy39`](../../src/leon2m/irq/irq_empty_handler_copy39.c) | `FUN_a010a854` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy40`](../../src/leon2m/irq/irq_empty_handler_copy40.c) | `FUN_a010adb8` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy41`](../../src/leon2m/irq/irq_empty_handler_copy41.c) | `FUN_a011d740` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy42`](../../src/leon2m/irq/irq_empty_handler_copy42.c) | `FUN_a0121eb8` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy43`](../../src/leon2m/irq/irq_empty_handler_copy43.c) | `FUN_a0121ec0` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy44`](../../src/leon2m/irq/irq_empty_handler_copy44.c) | `FUN_a0121ec8` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy45`](../../src/leon2m/irq/irq_empty_handler_copy45.c) | `FUN_a0125908` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy46`](../../src/leon2m/irq/irq_empty_handler_copy46.c) | `FUN_a0125910` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy47`](../../src/leon2m/irq/irq_empty_handler_copy47.c) | `FUN_a0125c44` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy48`](../../src/leon2m/irq/irq_empty_handler_copy48.c) | `FUN_a0125c4c` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy49`](../../src/leon2m/irq/irq_empty_handler_copy49.c) | `FUN_a0125c6c` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy50`](../../src/leon2m/irq/irq_empty_handler_copy50.c) | `FUN_a0125c7c` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy51`](../../src/leon2m/irq/irq_empty_handler_copy51.c) | `FUN_a0125c94` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy52`](../../src/leon2m/irq/irq_empty_handler_copy52.c) | `FUN_a0125c9c` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy53`](../../src/leon2m/irq/irq_empty_handler_copy53.c) | `FUN_a0125ca4` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy54`](../../src/leon2m/irq/irq_empty_handler_copy54.c) | `FUN_a0125cac` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy55`](../../src/leon2m/irq/irq_empty_handler_copy55.c) | `FUN_a0126310` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy56`](../../src/leon2m/irq/irq_empty_handler_copy56.c) | `FUN_a012bc00` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy57`](../../src/leon2m/irq/irq_empty_handler_copy57.c) | `FUN_a012c100` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy58`](../../src/leon2m/irq/irq_empty_handler_copy58.c) | `FUN_a012c108` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy59`](../../src/leon2m/irq/irq_empty_handler_copy59.c) | `FUN_a012c130` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy60`](../../src/leon2m/irq/irq_empty_handler_copy60.c) | `FUN_a0131510` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy61`](../../src/leon2m/irq/irq_empty_handler_copy61.c) | `FUN_a0132768` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy62`](../../src/leon2m/irq/irq_empty_handler_copy62.c) | `FUN_a0132a28` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy63`](../../src/leon2m/irq/irq_empty_handler_copy63.c) | `FUN_a0133cf4` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy64`](../../src/leon2m/irq/irq_empty_handler_copy64.c) | `FUN_a0133cfc` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy65`](../../src/leon2m/irq/irq_empty_handler_copy65.c) | `FUN_a0138554` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy66`](../../src/leon2m/irq/irq_empty_handler_copy66.c) | `FUN_a013d008` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy67`](../../src/leon2m/irq/irq_empty_handler_copy67.c) | `FUN_a013d010` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy68`](../../src/leon2m/irq/irq_empty_handler_copy68.c) | `FUN_a0145644` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy69`](../../src/leon2m/irq/irq_empty_handler_copy69.c) | `FUN_a01478a8` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy70`](../../src/leon2m/irq/irq_empty_handler_copy70.c) | `FUN_a0147a90` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy71`](../../src/leon2m/irq/irq_empty_handler_copy71.c) | `FUN_a0147a98` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy72`](../../src/leon2m/irq/irq_empty_handler_copy72.c) | `FUN_a0148350` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy73`](../../src/leon2m/irq/irq_empty_handler_copy73.c) | `FUN_a0149be8` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy74`](../../src/leon2m/irq/irq_empty_handler_copy74.c) | `FUN_a014a818` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy75`](../../src/leon2m/irq/irq_empty_handler_copy75.c) | `FUN_a014b960` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy76`](../../src/leon2m/irq/irq_empty_handler_copy76.c) | `FUN_a014b970` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy77`](../../src/leon2m/irq/irq_empty_handler_copy77.c) | `FUN_a014b978` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy78`](../../src/leon2m/irq/irq_empty_handler_copy78.c) | `FUN_a014dd20` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy79`](../../src/leon2m/irq/irq_empty_handler_copy79.c) | `FUN_a014dd28` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy80`](../../src/leon2m/irq/irq_empty_handler_copy80.c) | `FUN_a014dd30` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy81`](../../src/leon2m/irq/irq_empty_handler_copy81.c) | `FUN_a014dd38` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy82`](../../src/leon2m/irq/irq_empty_handler_copy82.c) | `FUN_a014dd40` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy83`](../../src/leon2m/irq/irq_empty_handler_copy83.c) | `FUN_a014dd48` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy84`](../../src/leon2m/irq/irq_empty_handler_copy84.c) | `FUN_a014dd50` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy85`](../../src/leon2m/irq/irq_empty_handler_copy85.c) | `FUN_a014dd60` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy86`](../../src/leon2m/irq/irq_empty_handler_copy86.c) | `FUN_a014dd68` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy87`](../../src/leon2m/irq/irq_empty_handler_copy87.c) | `FUN_a014dd70` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy88`](../../src/leon2m/irq/irq_empty_handler_copy88.c) | `FUN_a014dd78` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy89`](../../src/leon2m/irq/irq_empty_handler_copy89.c) | `FUN_a014dd80` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy90`](../../src/leon2m/irq/irq_empty_handler_copy90.c) | `FUN_a014dd88` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy91`](../../src/leon2m/irq/irq_empty_handler_copy91.c) | `FUN_a014dd90` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_empty_handler_copy92`](../../src/leon2m/irq/irq_empty_handler_copy92.c) | `FUN_a0154574` | Return at once: an empty routine, identical in code to irq_empty_handler. | descriptive |
| [`irq_entry`](../../src/leon2m/irq/irq_entry.S) | `FUN_a00290e4` | Save the interrupted PC/nPC at level 15 with traps on, then enter the dispatcher. | proven |
| [`irq_init_controller`](../../src/leon2m/irq/irq_init_controller.c) | `FUN_a0029858` | Reset both interrupt controllers, enable levels 1..14, unmask level-1 and level-4 sources. | derived |
| [`irq_mask_sources`](../../src/leon2m/irq/irq_mask_sources.c) | `FUN_a0029968` | Mask the given sources of interrupt level n. | derived |
| [`irq_raise_software_irq_bit0`](../../src/leon2m/irq/irq_raise_software_irq_bit0.c) | `FUN_a00de970` | Raise software interrupt bit 0 for the other side. | descriptive |
| [`irq_raise_software_irq_bit2`](../../src/leon2m/irq/irq_raise_software_irq_bit2.c) | `FUN_a00deb64` | Write 4 (bit 2) to the software interrupt register 0x9F120024. | descriptive |
| [`irq_raise_software_irq_bit3`](../../src/leon2m/irq/irq_raise_software_irq_bit3.c) | `FUN_a00deb80` | Write 8 (bit 3) to the software interrupt register 0x9F120024. | descriptive |
| [`irq_service_level1`](../../src/leon2m/irq/irq_service_level1.c) | `FUN_a0029994` | Run and acknowledge the registered handlers of pending level-1 interrupt sources. | proven |
| [`irq_service_level2`](../../src/leon2m/irq/irq_service_level2.c) | `FUN_a0029aac` | Run and acknowledge the registered handlers of pending level-2 interrupt sources. | proven |
| [`irq_service_level3`](../../src/leon2m/irq/irq_service_level3.c) | `FUN_a0029bc4` | Run and acknowledge the registered handlers of pending level-3 interrupt sources. | proven |
| [`irq_service_level4`](../../src/leon2m/irq/irq_service_level4.c) | `FUN_a0029cdc` | Run and acknowledge the registered handlers of pending level-4 interrupt sources. | proven |
| [`irq_service_level5`](../../src/leon2m/irq/irq_service_level5.c) | `FUN_a0029df4` | Run and acknowledge the registered handlers of pending level-5 interrupt sources. | proven |
| [`irq_service_level6`](../../src/leon2m/irq/irq_service_level6.c) | `FUN_a0029f14` | Run and acknowledge the registered handlers of pending level-6 interrupt sources. | proven |
| [`irq_service_level7`](../../src/leon2m/irq/irq_service_level7.c) | `FUN_a002a02c` | Run and acknowledge the registered handlers of pending level-7 interrupt sources. | proven |
| [`irq_service_level8`](../../src/leon2m/irq/irq_service_level8.c) | `FUN_a002a144` | Run and acknowledge the registered handlers of pending level-8 interrupt sources. | proven |
| [`irq_service_level9`](../../src/leon2m/irq/irq_service_level9.c) | `FUN_a002a25c` | Run and acknowledge the registered handlers of pending level-9 interrupt sources. | proven |
| [`irq_service_level10`](../../src/leon2m/irq/irq_service_level10.c) | `FUN_a002a344` | Run and acknowledge the registered handlers of pending level-10 interrupt sources. | proven |
| [`irq_service_level11`](../../src/leon2m/irq/irq_service_level11.c) | `FUN_a002a45c` | Acknowledge interrupt level 11 (no source handlers) | proven |
| [`irq_service_level12`](../../src/leon2m/irq/irq_service_level12.c) | `FUN_a002a4c4` | Run and acknowledge the registered handlers of pending level-12 interrupt sources. | proven |
| [`irq_service_level13`](../../src/leon2m/irq/irq_service_level13.c) | `FUN_a002a614` | Run and acknowledge the registered handlers of pending level-13 interrupt sources. | proven |
| [`irq_service_level14`](../../src/leon2m/irq/irq_service_level14.c) | `FUN_a002a734` | Run and acknowledge the registered handlers of pending level-14 interrupt sources. | proven |
| [`irq_service_level15`](../../src/leon2m/irq/irq_service_level15.c) | `FUN_a002a84c` | Acknowledge interrupt level 15 (no source handlers) | proven |
| [`irq_set_level4_only`](../../src/leon2m/irq/irq_set_level4_only.c) | `FUN_a002992c` | Enable only interrupt level 4 when on, otherwise disable all levels. | derived |
| [`irq_set_level12_source_mode`](../../src/leon2m/irq/irq_set_level12_source_mode.c) | `FUN_a002a5e4` | OR ((b & 0xFF) << a) << 16 into the level-12 mask register. | descriptive |
| [`irq_set_source_handler`](../../src/leon2m/irq/irq_set_source_handler.c) | `FUN_a002a880` | Register handler v for the lowest source bit in mask of interrupt level i. | proven |
| [`irq_unmask_sources`](../../src/leon2m/irq/irq_unmask_sources.c) | `FUN_a0029820` | Unmask the given sources of interrupt level n and clear their pending bits. | derived |
| [`irq_write_control_value`](../../src/leon2m/irq/irq_write_control_value.c) | `FUN_a00de98c` | Write 0x1000 to core register 0x9F120008. | descriptive |

<a id="timer"></a>
## Timers and delays

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`timer_api_get_ticks16`](../../src/leon2m/timer/timer_api_get_ticks16.c) | `FUN_a0147724` | Return the current 16-bit tick count. | proven |
| [`timer_api_sleep_ticks`](../../src/leon2m/timer/timer_api_sleep_ticks.c) | `FUN_a01437dc` | Wait for a number of ticks. | proven |
| [`timer_api_ticks_since`](../../src/leon2m/timer/timer_api_ticks_since.c) | `FUN_a0147740` | Return the ticks passed since an earlier tick count. | proven |
| [`timer_clear_flag`](../../src/leon2m/timer/timer_clear_flag.c) | `FUN_a00dedbc` | Clear the timer flag byte. | descriptive |
| [`timer_delay_nop_rounds`](../../src/leon2m/timer/timer_delay_nop_rounds.c) | `FUN_a002d23c` | Busy-wait n rounds of 200 nop instructions. | proven |
| [`timer_get_elapsed_fine`](../../src/leon2m/timer/timer_get_elapsed_fine.c) | `FUN_a00dec90` | Return the time passed since a tick count, in fine units. | derived |
| [`timer_get_flag`](../../src/leon2m/timer/timer_get_flag.c) | `FUN_a00dedb0` | Return the timer flag byte. | descriptive |
| [`timer_get_tick_count`](../../src/leon2m/timer/timer_get_tick_count.c) | `FUN_a002cfac` | Return the 32-bit tick counter. | proven |
| [`timer_get_ticks16`](../../src/leon2m/timer/timer_get_ticks16.c) | `FUN_a002d588` | Return the low 16 bits of the tick counter. | proven |
| [`timer_init`](../../src/leon2m/timer/timer_init.c) | `FUN_a00deb9c` | Start the timers and register their interrupt handlers. | proven |
| [`timer_isr_hook1`](../../src/leon2m/timer/timer_isr_hook1.c) | `FUN_a002d10c` | Call timer hook 1 (word 0xA802B0D4) with 1 when set. | descriptive |
| [`timer_isr_hook3`](../../src/leon2m/timer/timer_isr_hook3.c) | `FUN_a002d148` | Call timer hook 3 (word 0xA802B0DC) with 3 when set. | descriptive |
| [`timer_isr_hook4`](../../src/leon2m/timer/timer_isr_hook4.c) | `FUN_a002d174` | Call timer hook 4 (word 0xA802B0E0) with 4 when set. | derived |
| [`timer_raise_128_tick_flag`](../../src/leon2m/timer/timer_raise_128_tick_flag.c) | `FUN_a002d138` | Set the flag byte timer_tick_isr raises every 128 ticks when enabled. | descriptive |
| [`timer_set_slot_value`](../../src/leon2m/timer/timer_set_slot_value.c) | `FUN_a00ded78` | Store a value in a slot of the timer record when the record is active. | descriptive |
| [`timer_sleep_ticks`](../../src/leon2m/timer/timer_sleep_ticks.c) | `FUN_a002d1a0` | Wait n + 1 timer ticks; warn once when the tick interrupt seems stopped. | proven |
| [`timer_start_second_timer`](../../src/leon2m/timer/timer_start_second_timer.c) | `FUN_a00decf4` | Store two values and program the second timer. | descriptive |
| [`timer_tick_isr`](../../src/leon2m/timer/timer_tick_isr.c) | `FUN_a002cfb8` | Count one timer tick: sleep countdown, 5/50/500-tick flags, tick counter, hook. | proven |
| [`timer_ticks_since`](../../src/leon2m/timer/timer_ticks_since.c) | `FUN_a002d594` | Return the ticks elapsed since the 16-bit time stamp t0. | proven |
| [`timer_wait_frames`](../../src/leon2m/timer/timer_wait_frames.c) | `FUN_a0121bcc` | Wait for up to ten frame periods at a given refresh rate. | proven |

<a id="sys"></a>
## System control: channels, modes, configuration

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`APP_ConfigDispSize`](../../src/leon2m/sys/APP_ConfigDispSize.c) | `FUN_a00d6054` | Compute the display window of a channel for the current mode, aspect and layout. | proven |
| `APP_ConfigDispSize_jump_table` | `switchdataD_a00d3a64` | Jump table 1 of the switch statements in APP_ConfigDispSize. | proven |
| `APP_ConfigDispSize_jump_table2` | `switchdataD_a00d3a78` | Jump table 2 of the switch statements in APP_ConfigDispSize. | proven |
| `APP_ConfigDispSize_jump_table3` | `switchdataD_a00d3a98` | Jump table 3 of the switch statements in APP_ConfigDispSize. | proven |
| [`APPActionDispatcher`](../../src/leon2m/sys/APPActionDispatcher.c) | `FUN_a008454c` | Map an application, key, menu or DDC/CI event to its action and run it. | proven |
| `APPActionDispatcher_jump_table` | `switchdataD_a0080204` | Jump table 1 of the switch statements in APPActionDispatcher. | proven |
| [`APPBeforeDisplay_TriggerBySystem`](../../src/leon2m/sys/APPBeforeDisplay_TriggerBySystem.c) | `FUN_a0080af0` | Refresh the game/pro mode state before the picture is shown. | proven |
| [`FRC_SetMainBypassMode`](../../src/leon2m/sys/FRC_SetMainBypassMode.c) | `FUN_a01095bc` | Switch the bypass of the frame-rate converter for the main picture on or off. | proven |
| [`FRCConfigPostFRC`](../../src/leon2m/sys/FRCConfigPostFRC.c) | `FUN_a0107e44` | Configure the output clock and timing behind the frame-rate converter. | proven |
| [`GlobalModeHandler`](../../src/leon2m/sys/GlobalModeHandler.c) | `FUN_a0131518` | Run the main state machine that decides what each channel shows and when. | proven |
| [`GMDHEnableFRC`](../../src/leon2m/sys/GMDHEnableFRC.c) | `FUN_a012fcf4` | Switch the frame-rate converter channels on as the picture-in-picture mode says. | proven |
| `GMDHEnableFRC_jump_table` | `switchdataD_a012f18c` | Jump table 1 of the switch statements in GMDHEnableFRC. | proven |
| `GMDHEnableFRC_jump_table2` | `switchdataD_a012f1ac` | Jump table 2 of the switch statements in GMDHEnableFRC. | proven |
| [`IsAnyACRAvailable`](../../src/leon2m/sys/IsAnyACRAvailable.c) | `FUN_a014eb14` | Return the first free ACR unit (1 or 3), or 4 when both are taken. | proven |
| [`mwb_from_phy`](../../src/leon2m/sys/mwb_from_phy.c) | `FUN_a00e09b8` | Copy a register byte of a memory interface into the masked bits of a memory word. | proven |
| [`SetFRCCHRW`](../../src/leon2m/sys/SetFRCCHRW.c) | `FUN_a01086fc` | Program the converter's read and write windows for a channel. | proven |
| [`sys_api_center_channel_window`](../../src/leon2m/sys/sys_api_center_channel_window.c) | `FUN_a0148aec` | Centre the window of the block that a channel is mapped to. | descriptive |
| [`sys_api_clear_all_channels_flag25`](../../src/leon2m/sys/sys_api_clear_all_channels_flag25.c) | `FUN_a0143da8` | Clear flag bit 25 in all four channel records. | descriptive |
| [`sys_api_config`](../../src/leon2m/sys/sys_api_config.c) | `FUN_a014c7bc` | Apply one system configuration command (0..32) with its arguments. | proven |
| `sys_api_config_jump_table` | `switchdataD_a0143590` | Jump table 1 of the switch statements in sys_api_config. | proven |
| `sys_api_config_jump_table2` | `switchdataD_a01435a4` | Jump table 2 of the switch statements in sys_api_config. | proven |
| [`sys_api_copy_channel_position_fields`](../../src/leon2m/sys/sys_api_copy_channel_position_fields.c) | `FUN_a0145508` | Copy halfwords +0x28/+0x2A/+0x2C to +0x0E/+0x1E/+0x20 in the records of running channels. | descriptive |
| [`sys_api_disable_selected_path`](../../src/leon2m/sys/sys_api_disable_selected_path.c) | `FUN_a010a83c` | Switch the selected path off. | descriptive |
| [`sys_api_enable_channel_port`](../../src/leon2m/sys/sys_api_enable_channel_port.c) | `FUN_a014dd98` | Mark the port of a channel as enabled or disabled and switch it. | derived |
| [`sys_api_enable_selected_path`](../../src/leon2m/sys/sys_api_enable_selected_path.c) | `FUN_a010a824` | Switch the selected path on. | descriptive |
| [`sys_api_get_byte_d990`](../../src/leon2m/sys/sys_api_get_byte_d990.c) | `FUN_a0143fe4` | Return the byte at 0xA802D990. | descriptive |
| [`sys_api_get_channel_block_flag2`](../../src/leon2m/sys/sys_api_get_channel_block_flag2.c) | `FUN_a0148c94` | Return flag bit 2 of the register block that a channel is mapped to. | descriptive |
| [`sys_api_get_channel_flag28`](../../src/leon2m/sys/sys_api_get_channel_flag28.c) | `FUN_a0143f0c` | Return flag bit 28 of a channel's flag word. | descriptive |
| [`sys_api_get_channel_flag29`](../../src/leon2m/sys/sys_api_get_channel_flag29.c) | `FUN_a0143e70` | Return flag bit 29 of a channel's flag word. | descriptive |
| [`sys_api_get_channel_flags_14_15`](../../src/leon2m/sys/sys_api_get_channel_flags_14_15.c) | `FUN_a0143d14` | Return the 2-bit field at bits 14-15 of a channel's flag word. | descriptive |
| [`sys_api_get_channel_port_flag`](../../src/leon2m/sys/sys_api_get_channel_port_flag.c) | `FUN_a0148540` | Return the bit of the port mask at 0xA802CBD4 for the port of a channel. | descriptive |
| [`sys_api_get_channel_port_flag6`](../../src/leon2m/sys/sys_api_get_channel_port_flag6.c) | `FUN_a01438dc` | Return flag bit 6 of the port record that a channel is mapped to. | descriptive |
| [`sys_api_get_channel_port_flag8`](../../src/leon2m/sys/sys_api_get_channel_port_flag8.c) | `FUN_a014d3d4` | Return flag bit 8 of the port record that a channel is mapped to. | descriptive |
| [`sys_api_get_channel_port_flag9`](../../src/leon2m/sys/sys_api_get_channel_port_flag9.c) | `FUN_a014bd70` | Return flag bit 9 of the port record that a channel is mapped to. | descriptive |
| [`sys_api_get_channel_port_flag11`](../../src/leon2m/sys/sys_api_get_channel_port_flag11.c) | `FUN_a014d544` | Return bit 11 of the status halfword of the port record that a channel is mapped to. | descriptive |
| [`sys_api_get_channel_port_flag_alt`](../../src/leon2m/sys/sys_api_get_channel_port_flag_alt.c) | `FUN_a01485e0` | Return the bit of the port mask at 0xA802CBD3 for the port of a channel. | descriptive |
| [`sys_api_get_channel_port_state`](../../src/leon2m/sys/sys_api_get_channel_port_state.c) | `FUN_a01476e4` | Return a 0/1 state of the port a channel is mapped to. | descriptive |
| [`sys_api_get_channel_state_code`](../../src/leon2m/sys/sys_api_get_channel_state_code.c) | `FUN_a0143c14` | Return the state of a channel as a code for the application layer. | derived |
| `sys_api_get_channel_state_code_jump_table` | `switchdataD_a0143074` | Jump table 1 of the switch statements in sys_api_get_channel_state_code. | proven |
| [`sys_api_get_channel_sync_mode`](../../src/leon2m/sys/sys_api_get_channel_sync_mode.c) | `FUN_a0147bb0` | Return the sync mode 1..5 of the port a channel is mapped to, or 6. | descriptive |
| `sys_api_get_channel_sync_mode_jump_table` | `switchdataD_a0143438` | Jump table 1 of the switch statements in sys_api_get_channel_sync_mode. | proven |
| [`sys_api_get_event_code`](../../src/leon2m/sys/sys_api_get_event_code.c) | `FUN_a0143fb8` | Return the stored event code. | descriptive |
| [`sys_api_get_table_byte`](../../src/leon2m/sys/sys_api_get_table_byte.c) | `FUN_a014883c` | Return the first byte of an entry of the two-byte table at 0x1A6DB2. | descriptive |
| [`sys_api_get_three_status_words`](../../src/leon2m/sys/sys_api_get_three_status_words.c) | `FUN_a0148c84` | Fetch the three stored status words into the caller's variables. | descriptive |
| [`sys_api_is_channel_port_state4`](../../src/leon2m/sys/sys_api_is_channel_port_state4.c) | `FUN_a0143db8` | Return whether the port of a channel is in state 4. | descriptive |
| [`sys_api_is_event_pending`](../../src/leon2m/sys/sys_api_is_event_pending.c) | `FUN_a0143fa8` | Return the pending flag of the stored event. | descriptive |
| [`sys_api_is_frc_active_unlocked`](../../src/leon2m/sys/sys_api_is_frc_active_unlocked.c) | `FUN_a014d504` | Return whether frame-rate conversion is running and neither bypass nor lock mode is set. | derived |
| [`sys_api_is_pip_mode_above_4`](../../src/leon2m/sys/sys_api_is_pip_mode_above_4.c) | `FUN_a0148854` | Return whether the picture-in-picture mode (device settings byte +7) is above 4. | derived |
| [`sys_api_latch_status_state`](../../src/leon2m/sys/sys_api_latch_status_state.c) | `FUN_a0147c80` | Derive a 0..2 state from the status bits and latch it. | descriptive |
| [`sys_api_mark_channel_port`](../../src/leon2m/sys/sys_api_mark_channel_port.c) | `FUN_a014de48` | Mark the port of a channel as enabled or disabled without switching it. | derived |
| [`sys_api_rebuild_channel_window`](../../src/leon2m/sys/sys_api_rebuild_channel_window.c) | `FUN_a0149e8c` | Restart a channel and set up its output window again, with its source briefly off. | derived |
| [`sys_api_reset_memory_interfaces`](../../src/leon2m/sys/sys_api_reset_memory_interfaces.c) | `FUN_a011552c` | Run the register sequence of the three memory interfaces. | descriptive |
| [`sys_api_restart_channel`](../../src/leon2m/sys/sys_api_restart_channel.c) | `FUN_a014a060` | Restart a channel at level 3. | descriptive |
| [`sys_api_restart_channel_at_level`](../../src/leon2m/sys/sys_api_restart_channel_at_level.c) | `FUN_a0148268` | Restart a channel at the given level 0..3. | derived |
| [`sys_api_restart_secondary_channel`](../../src/leon2m/sys/sys_api_restart_secondary_channel.c) | `FUN_a014b900` | Restart channel 2 or 3 when its enable value is 1. | descriptive |
| [`sys_api_return_5`](../../src/leon2m/sys/sys_api_return_5.c) | `FUN_a0144684` | Return the constant 5. | descriptive |
| [`sys_api_return_6`](../../src/leon2m/sys/sys_api_return_6.c) | `FUN_a0144484` | Return the constant 6. | descriptive |
| [`sys_api_return_6_copy`](../../src/leon2m/sys/sys_api_return_6_copy.c) | `FUN_a01547b4` | Return the constant 6. | descriptive |
| [`sys_api_return_ff`](../../src/leon2m/sys/sys_api_return_ff.c) | `FUN_a0147a80` | Return 0xFF. | descriptive |
| [`sys_api_return_ff_copy`](../../src/leon2m/sys/sys_api_return_ff_copy.c) | `FUN_a0147a88` | Return 0xFF. | descriptive |
| [`sys_api_sample_channel_block`](../../src/leon2m/sys/sys_api_sample_channel_block.c) | `FUN_a0148bc4` | Run the sample accumulation for the block that a channel is mapped to. | descriptive |
| [`sys_api_select_channel_source`](../../src/leon2m/sys/sys_api_select_channel_source.c) | `FUN_a0149978` | Set the source of a channel, update its port records and note the time of the change. | derived |
| [`sys_api_set_all_channels_flag25`](../../src/leon2m/sys/sys_api_set_all_channels_flag25.c) | `FUN_a0143d98` | Set flag bit 25 in all four channel records. | descriptive |
| [`sys_api_set_block0_reg54_mode`](../../src/leon2m/sys/sys_api_set_block0_reg54_mode.c) | `FUN_a014e0a4` | Write mode 2, 1 or 0 to register 0x54 of register block 0. | descriptive |
| [`sys_api_set_block_route_first`](../../src/leon2m/sys/sys_api_set_block_route_first.c) | `FUN_a0132770` | Select route 1, 2 or 3 of the first block for a value 0, 1 or 2/4. | descriptive |
| [`sys_api_set_block_route_second`](../../src/leon2m/sys/sys_api_set_block_route_second.c) | `FUN_a01327e0` | Select route 1, 2 or 3 of the second block for a value 0, 1 or 2/4. | descriptive |
| [`sys_api_set_block_selector`](../../src/leon2m/sys/sys_api_set_block_selector.c) | `FUN_a0132850` | Forward a selector 0..3 to the block routine. | descriptive |
| [`sys_api_set_channel_position_field`](../../src/leon2m/sys/sys_api_set_channel_position_field.c) | `FUN_a0145808` | Store one position value of a channel and apply it. | descriptive |
| [`sys_api_set_channel_scaling_mode`](../../src/leon2m/sys/sys_api_set_channel_scaling_mode.c) | `FUN_a0149064` | Store the mode 0..4 of channel 0 or 1 and apply it. | descriptive |
| `sys_api_set_channel_scaling_mode_jump_table` | `switchdataD_a01434a0` | Jump table 1 of the switch statements in sys_api_set_channel_scaling_mode. | proven |
| [`sys_api_set_channel_source_enable`](../../src/leon2m/sys/sys_api_set_channel_source_enable.c) | `FUN_a014d474` | Set or clear the enable bit of the source class that a channel uses. | descriptive |
| [`sys_api_set_channel_timeout`](../../src/leon2m/sys/sys_api_set_channel_timeout.c) | `FUN_a014a8d4` | Set flag bit 16 and a 16-bit time value for one channel or for all four. | descriptive |
| [`sys_api_set_config_bit19`](../../src/leon2m/sys/sys_api_set_config_bit19.c) | `FUN_a014aa7c` | Store configuration bit 19. | descriptive |
| [`sys_api_set_config_bit21`](../../src/leon2m/sys/sys_api_set_config_bit21.c) | `FUN_a014a7f4` | Store configuration bit 21. | descriptive |
| [`sys_api_set_config_bit25_restart_all`](../../src/leon2m/sys/sys_api_set_config_bit25_restart_all.c) | `FUN_a0148ef4` | Store configuration bit 25 and restart all four channels. | descriptive |
| [`sys_api_set_config_bit31`](../../src/leon2m/sys/sys_api_set_config_bit31.c) | `FUN_a0148d98` | Store configuration bit 31 (0 if device settings bit 27 is set), mirror it inverted to channel 0. | descriptive |
| [`sys_api_set_config_field_restart_all`](../../src/leon2m/sys/sys_api_set_config_field_restart_all.c) | `FUN_a0148fc0` | Store a configuration field and restart all four channels at level 2. | descriptive |
| [`sys_api_set_config_mask_and_value`](../../src/leon2m/sys/sys_api_set_config_mask_and_value.c) | `FUN_a014a860` | Set bits of configuration byte +0x34, store a 16-bit value at +0x36 and print the byte. | descriptive |
| [`sys_api_set_entry_actions_all_channels`](../../src/leon2m/sys/sys_api_set_entry_actions_all_channels.c) | `FUN_a0145354` | Store whether the state entry actions run for every channel (1) or only channel 0 (0). | derived |
| [`sys_api_set_event_code`](../../src/leon2m/sys/sys_api_set_event_code.c) | `FUN_a0143fc4` | Store an event code and clear its pending flag. | descriptive |
| [`sys_api_set_flag_e403`](../../src/leon2m/sys/sys_api_set_flag_e403.c) | `FUN_a014a820` | Store 0 or 1 in the flag byte at stSysConfig +0x33. | descriptive |
| [`sys_api_set_output_mode`](../../src/leon2m/sys/sys_api_set_output_mode.c) | `FUN_a0148f4c` | Store the output mode byte and reconfigure the output timing when it changes. | descriptive |
| [`sys_api_set_panel_power_all_channels`](../../src/leon2m/sys/sys_api_set_panel_power_all_channels.c) | `FUN_a0145348` | Store whether every channel (1) or only channel 0 (0) drives the panel power. | derived |
| [`sys_api_set_port0_value_and_stamp`](../../src/leon2m/sys/sys_api_set_port0_value_and_stamp.c) | `FUN_a0148358` | Store a 16-bit value for port 0 and note the time. | descriptive |
| [`sys_api_set_pwm7_duty`](../../src/leon2m/sys/sys_api_set_pwm7_duty.c) | `FUN_a0148d34` | Write a duty value to PWM channel 7 for selector 0..2. | descriptive |
| [`sys_api_set_secondary_channel_enable`](../../src/leon2m/sys/sys_api_set_secondary_channel_enable.c) | `FUN_a014b844` | Store the enable value of channel 2 or 3 and restart that channel. | descriptive |
| [`sys_api_stop_channel`](../../src/leon2m/sys/sys_api_stop_channel.c) | `FUN_a0149fb8` | Restart a channel at level 2 and switch its source enable off. | descriptive |
| [`sys_api_update_channel_window_size`](../../src/leon2m/sys/sys_api_update_channel_window_size.c) | `FUN_a0149f44` | Recompute the window size of a channel. | descriptive |
| [`sys_app_generate_events`](../../src/leon2m/sys/sys_app_generate_events.c) | `FUN_a0080c10` | Turn port state changes and expired timers into application events. | proven |
| `sys_app_generate_events_jump_table` | `switchdataD_a00801c0` | Jump table 1 of the switch statements in sys_app_generate_events. | proven |
| [`sys_app_ticks_since`](../../src/leon2m/sys/sys_app_ticks_since.c) | `FUN_a0086ac8` | Return the milliseconds elapsed since t0. | derived |
| [`sys_app_timer_read`](../../src/leon2m/sys/sys_app_timer_read.c) | `FUN_a0086a3c` | Age all 23 application timers and return the time left on timer id. | proven |
| [`sys_app_timer_start`](../../src/leon2m/sys/sys_app_timer_start.c) | `FUN_a00869b0` | Age all 23 application timers, then start timer id with ms. | proven |
| [`sys_apply_pip_layout`](../../src/leon2m/sys/sys_apply_pip_layout.c) | `FUN_a0130438` | Switch the four channels on or off as the picture-in-picture mode requires. | derived |
| [`sys_apply_pip_layout_and_windows`](../../src/leon2m/sys/sys_apply_pip_layout_and_windows.c) | `FUN_a013129c` | Apply the picture-in-picture layout and set up the windows of all four channels. | derived |
| `sys_apply_pip_layout_jump_table` | `switchdataD_a012f1cc` | Jump table 1 of the switch statements in sys_apply_pip_layout. | proven |
| [`sys_call_app_callback`](../../src/leon2m/sys/sys_call_app_callback.c) | `FUN_a002f984` | Call application callback k (0, 1 or 5) from table 0xA802CC1C when set. | proven |
| [`sys_call_empty_hook`](../../src/leon2m/sys/sys_call_empty_hook.c) | `FUN_a0132a14` | Call a routine that is empty in this firmware. | descriptive |
| [`sys_call_frc_callbacks`](../../src/leon2m/sys/sys_call_frc_callbacks.c) | `FUN_a013d0ec` | Call the two registered callbacks for case 0, or clear the two FRC mode bits. | descriptive |
| [`sys_call_startup_hook_if_marker`](../../src/leon2m/sys/sys_call_startup_hook_if_marker.c) | `FUN_a0152f7c` | Call a start-up routine when the marker read back is 0x55. | descriptive |
| [`sys_channel0_apply_timing_block`](../../src/leon2m/sys/sys_channel0_apply_timing_block.c) | `FUN_a013c040` | Apply the timing block of channel 0 to the output stage. | descriptive |
| [`sys_channel_apply_output_timing`](../../src/leon2m/sys/sys_channel_apply_output_timing.c) | `FUN_a013c144` | Apply the output timing of a channel, including the low-resolution path. | derived |
| [`sys_channel_apply_scaler_route`](../../src/leon2m/sys/sys_channel_apply_scaler_route.c) | `FUN_a013bd00` | Choose the scaling route of a channel from its size fields. | descriptive |
| [`sys_channel_apply_scaler_route_auto`](../../src/leon2m/sys/sys_channel_apply_scaler_route_auto.c) | `FUN_a013beb0` | Derive the size flag and choose the scaling route of a channel. | descriptive |
| [`sys_channel_apply_scaler_route_for`](../../src/leon2m/sys/sys_channel_apply_scaler_route_for.c) | `FUN_a013bdb8` | Choose the scaling route of the port given as second parameter from its own size fields. | descriptive |
| [`sys_channel_clamp_position`](../../src/leon2m/sys/sys_channel_clamp_position.c) | `FUN_a013bc5c` | Limit the position fields of a channel to half and double of its sizes. | descriptive |
| [`sys_channel_derive_default_window`](../../src/leon2m/sys/sys_channel_derive_default_window.c) | `FUN_a013bbb8` | Derive the default window fields of a channel from its measured sizes. | descriptive |
| [`sys_channel_fill_size_fields`](../../src/leon2m/sys/sys_channel_fill_size_fields.c) | `FUN_a013bfa8` | Fill halfwords +0x12..+0x2C of a port's channel record from its port record and input block. | descriptive |
| [`sys_channels_idle_task`](../../src/leon2m/sys/sys_channels_idle_task.c) | `FUN_a012f7a8` | Step the port code of each enabled channel in port state 2 or 5, by group and time limit. | descriptive |
| [`sys_check_channel_index`](../../src/leon2m/sys/sys_check_channel_index.c) | `FUN_a01436b4` | Return a channel number 0..3 unchanged, else 0xFF. | derived |
| [`sys_clear_all_channels_flag25`](../../src/leon2m/sys/sys_clear_all_channels_flag25.c) | `FUN_a013cfc4` | Clear flag bit 25 in all four channel records. | descriptive |
| [`sys_clear_factory_mode_flag`](../../src/leon2m/sys/sys_clear_factory_mode_flag.c) | `FUN_a00cea44` | Clear the factory mode flag and switch all input signals off. | derived |
| [`sys_clear_three_clock_bits`](../../src/leon2m/sys/sys_clear_three_clock_bits.c) | `FUN_a01183c0` | Clear bit 0 of three block registers. | descriptive |
| [`sys_cmd_frame8_get_char`](../../src/leon2m/sys/sys_cmd_frame8_get_char.c) | `FUN_a015463c` | Return character b of row a of the 8-byte command frame table. | derived |
| [`sys_cmd_frame11_get_byte`](../../src/leon2m/sys/sys_cmd_frame11_get_byte.c) | `FUN_a015468c` | Return byte b of row a of the 11-byte command frame table. | derived |
| [`sys_cmd_frame26_get_byte`](../../src/leon2m/sys/sys_cmd_frame26_get_byte.c) | `FUN_a01546ec` | Return byte b of row a of the 26-byte command frame table. | derived |
| [`sys_cmd_frame42_get_byte`](../../src/leon2m/sys/sys_cmd_frame42_get_byte.c) | `FUN_a0154750` | Return byte b of row a of the 42-byte command frame table. | derived |
| [`sys_compute_temperature_from_adc_15`](../../src/leon2m/sys/sys_compute_temperature_from_adc_15.c) | `FUN_a00da65c` | Compute a temperature value with a fixed formula from ADC channel 15, which always reads 0xFF. | descriptive |
| [`sys_config_set_defaults`](../../src/leon2m/sys/sys_config_set_defaults.c) | `FUN_a0151358` | Set every field of the system configuration record (stSysConfig) to its default. | derived |
| [`sys_copy_row_byte_to_record`](../../src/leon2m/sys/sys_copy_row_byte_to_record.c) | `FUN_a012bae0` | Store a byte of the active panel timing row in byte 0x15 of a record. | descriptive |
| [`sys_core_read_reg_032c`](../../src/leon2m/sys/sys_core_read_reg_032c.c) | `FUN_a00de9c0` | Read core register 0x9F02032C. | descriptive |
| [`sys_core_read_reg_0324`](../../src/leon2m/sys/sys_core_read_reg_0324.c) | `FUN_a00de9e0` | Read core register 0x9F020324. | descriptive |
| [`sys_core_read_reg_0328`](../../src/leon2m/sys/sys_core_read_reg_0328.c) | `FUN_a00de9a8` | Read core register 0x9F020328. | descriptive |
| [`sys_core_restart_unit_0320`](../../src/leon2m/sys/sys_core_restart_unit_0320.c) | `FUN_a00de6a8` | Write 0, wait a tick and write 5 to core register 0x9F020320. | descriptive |
| [`sys_core_setup_unit_0320`](../../src/leon2m/sys/sys_core_setup_unit_0320.c) | `FUN_a00de6d4` | Start the unit at core register 0x9F020320 and register its interrupt handler. | descriptive |
| [`sys_ddr_add_qs_gate_sel`](../../src/leon2m/sys/sys_ddr_add_qs_gate_sel.c) | `FUN_a00e5428` | Add one step to the strobe gate selection of a data byte. | proven |
| [`sys_ddr_add_qsen_wrap_delay`](../../src/leon2m/sys/sys_ddr_add_qsen_wrap_delay.c) | `FUN_a00e52e8` | Add a step to the strobe-enable wrap delay of a data byte, with range check. | proven |
| [`sys_ddr_adjust_reg_d5`](../../src/leon2m/sys/sys_ddr_adjust_reg_d5.c) | `FUN_a00e2288` | Add a step to register 0xD5 of a memory interface and update register 0xD6. | descriptive |
| [`sys_ddr_calibrate_drivers`](../../src/leon2m/sys/sys_ddr_calibrate_drivers.c) | `FUN_a00e3bdc` | Run training step 3 (DUTY): the calibration unit duty_idx selects, then update three registers. | derived |
| [`sys_ddr_calibrate_unit_first`](../../src/leon2m/sys/sys_ddr_calibrate_unit_first.c) | `FUN_a00e312c` | Run the setting search with the routines of the first calibration unit. | derived |
| [`sys_ddr_calibrate_unit_second`](../../src/leon2m/sys/sys_ddr_calibrate_unit_second.c) | `FUN_a00e317c` | Run the setting search with the routines of the second calibration unit. | derived |
| [`sys_ddr_calibrate_unit_third`](../../src/leon2m/sys/sys_ddr_calibrate_unit_third.c) | `FUN_a00e31cc` | Run the setting search with the routines of the third calibration unit. | derived |
| [`sys_ddr_check_arguments`](../../src/leon2m/sys/sys_ddr_check_arguments.c) | `FUN_a00dfc50` | Check the interface number, its version and the memory type in one go. | proven |
| `sys_ddr_check_arguments_jump_table` | `switchdataD_a00df768` | Jump table 1 of the switch statements in sys_ddr_check_arguments. | proven |
| `sys_ddr_check_arguments_jump_table2` | `switchdataD_a00df79c` | Jump table 2 of the switch statements in sys_ddr_check_arguments. | proven |
| `sys_ddr_check_arguments_jump_table3` | `switchdataD_a00df7d0` | Jump table 3 of the switch statements in sys_ddr_check_arguments. | proven |
| [`sys_ddr_check_gate_fields`](../../src/leon2m/sys/sys_ddr_check_gate_fields.c) | `FUN_a00e4f8c` | Check the gate fields of a memory interface: DDR4 against a 64-bit pattern, others five fields. | descriptive |
| [`sys_ddr_check_generation`](../../src/leon2m/sys/sys_ddr_check_generation.c) | `FUN_a00dfb30` | Check that the memory type is DDR3 or DDR4. | proven |
| `sys_ddr_check_generation_jump_table` | `switchdataD_a00df734` | Jump table 1 of the switch statements in sys_ddr_check_generation. | proven |
| [`sys_ddr_check_phy_byte`](../../src/leon2m/sys/sys_ddr_check_phy_byte.c) | `FUN_a00e47f8` | Configure the memory interface registers of one data byte and check them. | proven |
| `sys_ddr_check_phy_byte_jump_table` | `switchdataD_a00e47dc` | Jump table 1 of the switch statements in sys_ddr_check_phy_byte. | proven |
| [`sys_ddr_check_phy_id`](../../src/leon2m/sys/sys_ddr_check_phy_id.c) | `FUN_a00df8f4` | Check that a memory interface number is valid. | proven |
| `sys_ddr_check_phy_id_jump_table` | `switchdataD_a00df6cc` | Jump table 1 of the switch statements in sys_ddr_check_phy_id. | proven |
| [`sys_ddr_check_phy_reg`](../../src/leon2m/sys/sys_ddr_check_phy_reg.c) | `FUN_a00e0788` | Poll a register of a memory interface until it shows the expected value. | proven |
| [`sys_ddr_check_phy_reg_or_fail`](../../src/leon2m/sys/sys_ddr_check_phy_reg_or_fail.c) | `FUN_a00e0888` | Poll a register of a memory interface for the expected value and report a failure. | proven |
| [`sys_ddr_check_phy_version`](../../src/leon2m/sys/sys_ddr_check_phy_version.c) | `FUN_a00dfa10` | Check that the memory interface version is supported. | proven |
| `sys_ddr_check_phy_version_jump_table` | `switchdataD_a00df700` | Jump table 1 of the switch statements in sys_ddr_check_phy_version. | proven |
| [`sys_ddr_controller_read`](../../src/leon2m/sys/sys_ddr_controller_read.c) | `FUN_a00e0268` | Read a register of memory controller 0, 1 or 2. | proven |
| [`sys_ddr_controller_write`](../../src/leon2m/sys/sys_ddr_controller_write.c) | `FUN_a00e02a0` | Write a register of memory controller 0, 1 or 2. | proven |
| [`sys_ddr_controller_write_reg194`](../../src/leon2m/sys/sys_ddr_controller_write_reg194.c) | `FUN_a00e0078` | Write 0x10000 to register 0x194 of a memory controller. | descriptive |
| [`sys_ddr_delay`](../../src/leon2m/sys/sys_ddr_delay.c) | `FUN_a00dffa4` | Wait for a number of delay units. | derived |
| [`sys_ddr_delay_short`](../../src/leon2m/sys/sys_ddr_delay_short.c) | `FUN_a00dff94` | Wait in the long delay loop, with the caller's argument (1) as the number of rounds. | descriptive |
| [`sys_ddr_delay_tens`](../../src/leon2m/sys/sys_ddr_delay_tens.c) | `FUN_a00e222c` | Wait for ten times the given number of delay units. | descriptive |
| [`sys_ddr_dump_phy_reg`](../../src/leon2m/sys/sys_ddr_dump_phy_reg.c) | `FUN_a00e0bf0` | Read a memory interface register and print it with the interface's name. | derived |
| [`sys_ddr_find_read_eye`](../../src/leon2m/sys/sys_ddr_find_read_eye.c) | `FUN_a00e8e6c` | Find both edges of the passing read delay window with self-test steps and set the middle. | proven |
| [`sys_ddr_find_write_window_lower_edge`](../../src/leon2m/sys/sys_ddr_find_write_window_lower_edge.c) | `FUN_a00eba64` | Find the lower edge of the passing write delay window of a data byte with read self-tests. | derived |
| [`sys_ddr_get_bist_result`](../../src/leon2m/sys/sys_ddr_get_bist_result.c) | `FUN_a00e40f4` | Check the self-test status registers and return the result 0..3. | proven |
| [`sys_ddr_get_controller_base`](../../src/leon2m/sys/sys_ddr_get_controller_base.c) | `FUN_a00e0234` | Return the base address of memory controller 0, 1 or 2. | proven |
| [`sys_ddr_get_step`](../../src/leon2m/sys/sys_ddr_get_step.c) | `FUN_a00dffcc` | Return the current training step. | derived |
| [`sys_ddr_identity`](../../src/leon2m/sys/sys_ddr_identity.c) | `FUN_a00e02e4` | Return the argument unchanged. | descriptive |
| [`sys_ddr_init`](../../src/leon2m/sys/sys_ddr_init.c) | `FUN_a00e1fc8` | Choose the old or the new memory script by a pin and run it. | proven |
| [`sys_ddr_init_select_script`](../../src/leon2m/sys/sys_ddr_init_select_script.c) | `FUN_a00e1f50` | Choose the old or the new memory script by a pin and run it (first copy). | proven |
| [`sys_ddr_map_all_to_4`](../../src/leon2m/sys/sys_ddr_map_all_to_4.c) | `FUN_a00e0e28` | Return 4 for the value 0xFF, other values unchanged. | descriptive |
| [`sys_ddr_measure_pll`](../../src/leon2m/sys/sys_ddr_measure_pll.c) | `FUN_a00df5dc` | Select a measurement and return the clock value of a memory interface. | descriptive |
| [`sys_ddr_measure_read_eye_at`](../../src/leon2m/sys/sys_ddr_measure_read_eye_at.c) | `FUN_a00e9b34` | Set three fields and measure the read window at that setting. | derived |
| [`sys_ddr_measure_write_eye`](../../src/leon2m/sys/sys_ddr_measure_write_eye.c) | `FUN_a00edc70` | Measure the write window with six fields saved and restored. | derived |
| [`sys_ddr_move_qs_gate`](../../src/leon2m/sys/sys_ddr_move_qs_gate.c) | `FUN_a00e55ec` | Move the strobe gate of a data byte by a signed number of steps. | derived |
| [`sys_ddr_phy_adjust_field`](../../src/leon2m/sys/sys_ddr_phy_adjust_field.c) | `FUN_a00e0134` | Add or subtract a step in a register field of a memory interface, with a limit check. | proven |
| [`sys_ddr_phy_clear_reg0_bit0`](../../src/leon2m/sys/sys_ddr_phy_clear_reg0_bit0.c) | `FUN_a00e005c` | Clear bit 0 of register 0 of a memory interface. | descriptive |
| [`sys_ddr_phy_read`](../../src/leon2m/sys/sys_ddr_phy_read.c) | `FUN_a00e02ec` | Read a register of a memory interface. | proven |
| [`sys_ddr_phy_read_8_registers`](../../src/leon2m/sys/sys_ddr_phy_read_8_registers.c) | `FUN_a00e0b00` | Read 8 registers in a row of page 3 of a memory interface and return them as one 64-bit value. | descriptive |
| [`sys_ddr_phy_read_field`](../../src/leon2m/sys/sys_ddr_phy_read_field.c) | `FUN_a00e0754` | Read a bit field of a register of a memory interface. | proven |
| [`sys_ddr_phy_read_masked`](../../src/leon2m/sys/sys_ddr_phy_read_masked.c) | `FUN_a00e0514` | Read a register of a memory interface and return it masked. | proven |
| [`sys_ddr_phy_set_bits`](../../src/leon2m/sys/sys_ddr_phy_set_bits.c) | `FUN_a00e0740` | Set the masked bits of a register of a memory interface. | proven |
| [`sys_ddr_phy_set_reg0_bit0`](../../src/leon2m/sys/sys_ddr_phy_set_reg0_bit0.c) | `FUN_a00e0040` | Set bit 0 of register 0 of a memory interface. | descriptive |
| [`sys_ddr_phy_update_bits`](../../src/leon2m/sys/sys_ddr_phy_update_bits.c) | `FUN_a00e05d8` | Replace the masked bits of a register of a memory interface. | proven |
| [`sys_ddr_phy_write`](../../src/leon2m/sys/sys_ddr_phy_write.c) | `FUN_a00e03b0` | Write a register of a memory interface. | proven |
| [`sys_ddr_phy_write_field`](../../src/leon2m/sys/sys_ddr_phy_write_field.c) | `FUN_a00e0774` | Write a bit field of a register of a memory interface. | proven |
| [`sys_ddr_print_error_prefix`](../../src/leon2m/sys/sys_ddr_print_error_prefix.c) | `FUN_a00e0bc0` | Print the prefix 'ddr_err: ' in front of an error message. | proven |
| [`sys_ddr_print_fatal_prefix`](../../src/leon2m/sys/sys_ddr_print_fatal_prefix.c) | `FUN_a00e0bd8` | Print the prefix '[FATAL] ddr_fatal: ' in front of an error message. | proven |
| [`sys_ddr_print_info_prefix`](../../src/leon2m/sys/sys_ddr_print_info_prefix.c) | `FUN_a00e0ba8` | Print the prefix 'ddr: ' in front of an information message. | derived |
| [`sys_ddr_print_step`](../../src/leon2m/sys/sys_ddr_print_step.c) | `FUN_a00df80c` | Print the name of the current training step with the interface and data byte. | proven |
| `sys_ddr_print_step_jump_table` | `switchdataD_a00df698` | Jump table 1 of the switch statements in sys_ddr_print_step. | proven |
| [`sys_ddr_read_reg1b_word`](../../src/leon2m/sys/sys_ddr_read_reg1b_word.c) | `FUN_a00e4030` | Read the 16-bit value of registers 0x1B / 0x1C of a memory interface. | descriptive |
| [`sys_ddr_read_reg17_word`](../../src/leon2m/sys/sys_ddr_read_reg17_word.c) | `FUN_a00e3ff4` | Read the 16-bit value of registers 0x17 / 0x18 of a memory interface. | descriptive |
| [`sys_ddr_reg_page_of`](../../src/leon2m/sys/sys_ddr_reg_page_of.c) | `FUN_a00e02d8` | Return the page number of a register number. | derived |
| [`sys_ddr_reset_fifos`](../../src/leon2m/sys/sys_ddr_reset_fifos.c) | `FUN_a00e0090` | Pulse the reset bits of a memory interface's registers 0x2CE and 0x2CD. | derived |
| [`sys_ddr_return_minus_one`](../../src/leon2m/sys/sys_ddr_return_minus_one.c) | `FUN_a00eecc8` | Return -1. | descriptive |
| [`sys_ddr_run_bist_read`](../../src/leon2m/sys/sys_ddr_run_bist_read.c) | `FUN_a00e4278` | Run the memory self-test for a read step; result 3 repeats the attempt, any other is returned. | derived |
| [`sys_ddr_run_bist_write`](../../src/leon2m/sys/sys_ddr_run_bist_write.c) | `FUN_a00e4538` | Run the memory self-test for a write step. | derived |
| [`sys_ddr_run_cal_first`](../../src/leon2m/sys/sys_ddr_run_cal_first.c) | `FUN_a00e2c3c` | Trigger a measurement of the first calibration unit and return its result. | derived |
| [`sys_ddr_run_cal_second`](../../src/leon2m/sys/sys_ddr_run_cal_second.c) | `FUN_a00e2cac` | Trigger a measurement of the second calibration unit and return its result. | derived |
| [`sys_ddr_run_cal_third`](../../src/leon2m/sys/sys_ddr_run_cal_third.c) | `FUN_a00e2d1c` | Trigger a measurement of the third calibration unit and return its result. | derived |
| [`sys_ddr_run_script`](../../src/leon2m/sys/sys_ddr_run_script.c) | `FUN_a00e0e44` | Run the memory training script: one command byte after the other. | proven |
| `sys_ddr_run_script_jump_table` | `switchdataD_a00e0d30` | Jump table 1 of the switch statements in sys_ddr_run_script. | proven |
| [`sys_ddr_search_cal_setting`](../../src/leon2m/sys/sys_ddr_search_cal_setting.c) | `FUN_a00e2d8c` | Step a calibration setting through its range; mode 0 picks the best one by its measured sums. | derived |
| [`sys_ddr_search_qs_gate_late`](../../src/leon2m/sys/sys_ddr_search_qs_gate_late.c) | `FUN_a00e57b4` | Step the strobe-enable delay until the 'late' flag clears. | proven |
| [`sys_ddr_send_mode_register`](../../src/leon2m/sys/sys_ddr_send_mode_register.c) | `FUN_a00e406c` | Send a mode register command to the memory chips. | derived |
| [`sys_ddr_set_adj_table_fields_first`](../../src/leon2m/sys/sys_ddr_set_adj_table_fields_first.c) | `FUN_a00e2714` | Write three table fields of the first calibration unit at entry n_adj (0..9). | derived |
| [`sys_ddr_set_adj_table_fields_second`](../../src/leon2m/sys/sys_ddr_set_adj_table_fields_second.c) | `FUN_a00e285c` | Write three table fields of the second calibration unit at entry n_adj (0..9). | derived |
| [`sys_ddr_set_adj_table_fields_third`](../../src/leon2m/sys/sys_ddr_set_adj_table_fields_third.c) | `FUN_a00e29a4` | Write three table fields of the third calibration unit at entry n_adj (0..9). | derived |
| [`sys_ddr_set_mode_register_fields`](../../src/leon2m/sys/sys_ddr_set_mode_register_fields.c) | `FUN_a00e3f6c` | Write the fields of a mode register command. | descriptive |
| [`sys_ddr_set_n_adj_det_first`](../../src/leon2m/sys/sys_ddr_set_n_adj_det_first.c) | `FUN_a00e2588` | Write the N_adj and N_det values (0..9) of the first calibration unit. | proven |
| [`sys_ddr_set_n_adj_det_second`](../../src/leon2m/sys/sys_ddr_set_n_adj_det_second.c) | `FUN_a00e260c` | Write the N_adj and N_det values (0..9) of the second calibration unit. | proven |
| [`sys_ddr_set_n_adj_det_third`](../../src/leon2m/sys/sys_ddr_set_n_adj_det_third.c) | `FUN_a00e2690` | Write the N_adj and N_det values (0..9) of the third calibration unit. | proven |
| [`sys_ddr_set_param0`](../../src/leon2m/sys/sys_ddr_set_param0.c) | `FUN_a00e0cd8` | Store the first training parameter and mark it as set explicitly. | descriptive |
| [`sys_ddr_set_param0_default`](../../src/leon2m/sys/sys_ddr_set_param0_default.c) | `FUN_a00e0c68` | Store the first training parameter unless it was set explicitly. | descriptive |
| [`sys_ddr_set_param1`](../../src/leon2m/sys/sys_ddr_set_param1.c) | `FUN_a00e0cf0` | Store the second training parameter and mark it as set explicitly. | descriptive |
| [`sys_ddr_set_param1_default`](../../src/leon2m/sys/sys_ddr_set_param1_default.c) | `FUN_a00e0c88` | Store the second training parameter unless it was set explicitly. | descriptive |
| [`sys_ddr_set_param2`](../../src/leon2m/sys/sys_ddr_set_param2.c) | `FUN_a00e0d18` | Store the third training parameter and mark it as set explicitly. | descriptive |
| [`sys_ddr_set_param2_default`](../../src/leon2m/sys/sys_ddr_set_param2_default.c) | `FUN_a00e0cb8` | Store the third training parameter unless it was set explicitly. | descriptive |
| [`sys_ddr_set_pll`](../../src/leon2m/sys/sys_ddr_set_pll.c) | `FUN_a00dffd8` | Check the interface number and write its clock value. | derived |
| [`sys_ddr_set_pll_value`](../../src/leon2m/sys/sys_ddr_set_pll_value.c) | `FUN_a00df648` | Write a clock value to the three clock registers of a memory interface. | descriptive |
| [`sys_ddr_set_read_dq_bit`](../../src/leon2m/sys/sys_ddr_set_read_dq_bit.c) | `FUN_a00e7dc8` | Write the read deskew control bit of one data line. | derived |
| [`sys_ddr_set_step`](../../src/leon2m/sys/sys_ddr_set_step.c) | `FUN_a00dffb4` | Record the current training step, interface and data byte for the error messages. | proven |
| [`sys_ddr_set_vref`](../../src/leon2m/sys/sys_ddr_set_vref.c) | `FUN_a00ee964` | Set the reference voltage through mode register 6. | proven |
| [`sys_ddr_set_write_delay_center`](../../src/leon2m/sys/sys_ddr_set_write_delay_center.c) | `FUN_a00ec340` | Write the centre of the write delay window into the fields of a data byte. | descriptive |
| [`sys_ddr_set_write_delay_fields`](../../src/leon2m/sys/sys_ddr_set_write_delay_fields.c) | `FUN_a00eb708` | Write the write delay fields of a data byte from a stored value and a step. | descriptive |
| [`sys_ddr_set_write_dq_bit`](../../src/leon2m/sys/sys_ddr_set_write_dq_bit.c) | `FUN_a00ea25c` | Write the write deskew control bit of one data line. | derived |
| [`sys_ddr_set_write_level_fields`](../../src/leon2m/sys/sys_ddr_set_write_level_fields.c) | `FUN_a00ed530` | Write a write-levelling step into the fields of a data byte. | descriptive |
| [`sys_ddr_setup_phy`](../../src/leon2m/sys/sys_ddr_setup_phy.c) | `FUN_a00eecd0` | Write the start register values of one memory interface. | derived |
| [`sys_ddr_speed_to_tccd_index`](../../src/leon2m/sys/sys_ddr_speed_to_tccd_index.c) | `FUN_a00ee188` | Convert a DDR speed to its tCCD_L index 0..3. | proven |
| [`sys_ddr_train_and_set_vref`](../../src/leon2m/sys/sys_ddr_train_and_set_vref.c) | `FUN_a00eec44` | Train the reference voltage and apply it. | derived |
| [`sys_ddr_train_clk_tree`](../../src/leon2m/sys/sys_ddr_train_clk_tree.c) | `FUN_a00e2340` | Run training step 1 (CLK_TREE): step register 0xD5 until status bits 0x80 and 0x40 are right. | proven |
| [`sys_ddr_train_qs_gate`](../../src/leon2m/sys/sys_ddr_train_qs_gate.c) | `FUN_a00e7254` | Run the strobe gate training for one data byte (0..3), saving and restoring nine registers. | proven |
| [`sys_ddr_train_qs_gate_byte`](../../src/leon2m/sys/sys_ddr_train_qs_gate_byte.c) | `FUN_a00e5fc8` | Train the strobe gate of one data byte. | proven |
| [`sys_ddr_train_read_deskew`](../../src/leon2m/sys/sys_ddr_train_read_deskew.c) | `FUN_a00e7eb0` | Train the read deskew of one data byte: align its eight data lines. | derived |
| [`sys_ddr_train_read_eye`](../../src/leon2m/sys/sys_ddr_train_read_eye.c) | `FUN_a00e9c80` | Train the read window of a data byte in two passes and write the midpoints. | proven |
| [`sys_ddr_train_read_eye_all`](../../src/leon2m/sys/sys_ddr_train_read_eye_all.c) | `FUN_a00ea1f0` | Run the read window training for a number of data bytes. | derived |
| [`sys_ddr_train_vref`](../../src/leon2m/sys/sys_ddr_train_vref.c) | `FUN_a00ee1e8` | Narrow the reference voltage index range and write the centre of the shared write delay window. | derived |
| [`sys_ddr_train_write_deskew`](../../src/leon2m/sys/sys_ddr_train_write_deskew.c) | `FUN_a00ea878` | Train the write deskew of one data byte: align its eight data lines. | proven |
| [`sys_ddr_train_write_eye`](../../src/leon2m/sys/sys_ddr_train_write_eye.c) | `FUN_a00ec6b8` | Train the write window of a data byte. | derived |
| [`sys_ddr_train_write_leveling`](../../src/leon2m/sys/sys_ddr_train_write_leveling.c) | `FUN_a00ed70c` | Run the write levelling of one data byte of a memory interface. | proven |
| [`sys_ddr_update_phy_bits_multi`](../../src/leon2m/sys/sys_ddr_update_phy_bits_multi.c) | `FUN_a00e20dc` | Replace masked bits of a register of one memory interface, or of all three. | derived |
| [`sys_ddr_wait_cal_idle_first`](../../src/leon2m/sys/sys_ddr_wait_cal_idle_first.c) | `FUN_a00e2aec` | Start the first calibration unit and wait until its status reads idle six times in a row. | derived |
| [`sys_ddr_wait_cal_idle_second`](../../src/leon2m/sys/sys_ddr_wait_cal_idle_second.c) | `FUN_a00e2b5c` | Start the second calibration unit and wait until its status reads idle six times in a row. | derived |
| [`sys_ddr_wait_cal_idle_third`](../../src/leon2m/sys/sys_ddr_wait_cal_idle_third.c) | `FUN_a00e2bcc` | Start the third calibration unit and wait until its status reads idle six times in a row. | derived |
| [`sys_ddr_write_all_controllers`](../../src/leon2m/sys/sys_ddr_write_all_controllers.c) | `FUN_a00e2258` | Write a register of all three memory controllers. | derived |
| [`sys_ddr_write_deskew_coarse`](../../src/leon2m/sys/sys_ddr_write_deskew_coarse.c) | `FUN_a00ea308` | Run the coarse passes of the write deskew of one data byte. | proven |
| [`sys_ddr_write_deskew_fine`](../../src/leon2m/sys/sys_ddr_write_deskew_fine.c) | `FUN_a00ea638` | Run the fail-mask passes of the write deskew of one data byte. | proven |
| [`sys_ddr_write_phy_reg_multi`](../../src/leon2m/sys/sys_ddr_write_phy_reg_multi.c) | `FUN_a00e2040` | Write a register of one memory interface, or of all three. | derived |
| [`sys_ddr_zq_calibrate_first`](../../src/leon2m/sys/sys_ddr_zq_calibrate_first.c) | `FUN_a00e321c` | Run the register sequence and the setting search of the first calibration unit. | descriptive |
| [`sys_ddr_zq_calibrate_second`](../../src/leon2m/sys/sys_ddr_zq_calibrate_second.c) | `FUN_a00e3524` | Run the register sequence and the setting search of the second calibration unit. | descriptive |
| [`sys_ddr_zq_calibrate_third`](../../src/leon2m/sys/sys_ddr_zq_calibrate_third.c) | `FUN_a00e3880` | Run the register sequence and the setting search of the third calibration unit. | descriptive |
| [`sys_delay_loop_long`](../../src/leon2m/sys/sys_delay_loop_long.c) | `FUN_a00de578` | Wait in a loop of n times 64,000 passes. | derived |
| [`sys_delay_loop_medium`](../../src/leon2m/sys/sys_delay_loop_medium.c) | `FUN_a00de5c0` | Wait in a loop of n times 40,000 idle instructions. | derived |
| [`sys_delay_loop_short`](../../src/leon2m/sys/sys_delay_loop_short.c) | `FUN_a00de53c` | Wait in a loop of n times 64 passes. | derived |
| [`sys_enable_channel_port`](../../src/leon2m/sys/sys_enable_channel_port.c) | `FUN_a01312d4` | Switch the port of a channel on or off and set its clock when switching on. | derived |
| [`sys_enable_unit_6a80`](../../src/leon2m/sys/sys_enable_unit_6a80.c) | `FUN_a010795c` | Switch the unit at 0xCF016A80 on or off. | descriptive |
| [`sys_enable_unit_6800_n0`](../../src/leon2m/sys/sys_enable_unit_6800_n0.c) | `FUN_a010765c` | Switch unit 0 of the five units at 0xCF016800 on or off. | descriptive |
| [`sys_enable_unit_6800_n1`](../../src/leon2m/sys/sys_enable_unit_6800_n1.c) | `FUN_a01076bc` | Switch unit 1 of the five units at 0xCF016800 on or off. | descriptive |
| [`sys_enable_unit_6800_n2`](../../src/leon2m/sys/sys_enable_unit_6800_n2.c) | `FUN_a010771c` | Switch unit 2 of the five units at 0xCF016800 on or off. | descriptive |
| [`sys_enable_unit_6800_n3`](../../src/leon2m/sys/sys_enable_unit_6800_n3.c) | `FUN_a010777c` | Switch unit 3 of the five units at 0xCF016800 on or off. | descriptive |
| [`sys_enable_unit_6800_n4`](../../src/leon2m/sys/sys_enable_unit_6800_n4.c) | `FUN_a01077dc` | Switch unit 4 of the five units at 0xCF016800 on or off. | descriptive |
| [`sys_enable_unit_7400_n0`](../../src/leon2m/sys/sys_enable_unit_7400_n0.c) | `FUN_a010783c` | Switch unit 0 of the four units at 0xCF017400 on or off. | descriptive |
| [`sys_enable_unit_7400_n1`](../../src/leon2m/sys/sys_enable_unit_7400_n1.c) | `FUN_a0107884` | Switch unit 1 of the four units at 0xCF017400 on or off. | descriptive |
| [`sys_enable_unit_7400_n2`](../../src/leon2m/sys/sys_enable_unit_7400_n2.c) | `FUN_a01078cc` | Switch unit 2 of the four units at 0xCF017400 on or off. | descriptive |
| [`sys_enable_unit_7400_n3`](../../src/leon2m/sys/sys_enable_unit_7400_n3.c) | `FUN_a0107914` | Switch unit 3 of the four units at 0xCF017400 on or off. | descriptive |
| [`sys_enable_unit_e9e8`](../../src/leon2m/sys/sys_enable_unit_e9e8.c) | `FUN_a0107554` | Switch the unit at 0xCF00E9E8 on or off (first form). | descriptive |
| [`sys_enable_unit_e9e8_with_bit4`](../../src/leon2m/sys/sys_enable_unit_e9e8_with_bit4.c) | `FUN_a01075f8` | Switch the unit at 0xCF00E9E8 on with bit 4 of 0xCF00EAC8, or off. | descriptive |
| [`sys_end_logo_restore_picture`](../../src/leon2m/sys/sys_end_logo_restore_picture.c) | `FUN_a008f354` | Close the logo screen and re-apply the picture settings and layout. | derived |
| [`sys_fill_output_size_record`](../../src/leon2m/sys/sys_fill_output_size_record.c) | `FUN_a012b9a8` | Fill four size values of a record from the output blocks and derive four more from them. | descriptive |
| [`sys_find_channel_by_path`](../../src/leon2m/sys/sys_find_channel_by_path.c) | `FUN_a013ce10` | Return the channel record whose path field equals an id. | descriptive |
| [`sys_find_channel_by_port`](../../src/leon2m/sys/sys_find_channel_by_port.c) | `FUN_a013cd4c` | Return the channel record whose port field equals an id. | derived |
| [`sys_find_channel_of_port`](../../src/leon2m/sys/sys_find_channel_of_port.c) | `FUN_a013b86c` | Return the index of the first channel whose port field equals the given port, or 0xFF. | derived |
| [`sys_frc_apply_bit_groups`](../../src/leon2m/sys/sys_frc_apply_bit_groups.c) | `FUN_a01118cc` | Clear and set the register bit groups of the frame-rate converter for a setting. | descriptive |
| `sys_frc_apply_bit_groups_jump_table` | `switchdataD_a01117e0` | Jump table 1 of the switch statements in sys_frc_apply_bit_groups. | proven |
| [`sys_frc_clear_reg_d8c`](../../src/leon2m/sys/sys_frc_clear_reg_d8c.c) | `FUN_a0112fcc` | Write 0 to register 0xCF011D8C. | descriptive |
| [`sys_frc_derive_output_sizes`](../../src/leon2m/sys/sys_frc_derive_output_sizes.c) | `FUN_a0109844` | Derive the converter's output size registers from its input size registers. | descriptive |
| [`sys_frc_disable_channel4`](../../src/leon2m/sys/sys_frc_disable_channel4.c) | `FUN_a0108544` | Clear bit 4 in three converter registers and write the restart value. | descriptive |
| [`sys_frc_disable_channels`](../../src/leon2m/sys/sys_frc_disable_channels.c) | `FUN_a0113064` | Switch one converter channel off, or every enabled channel when given 0xFF. | descriptive |
| [`sys_frc_divide_by_ratio`](../../src/leon2m/sys/sys_frc_divide_by_ratio.c) | `FUN_a01085a4` | Replace a value by value / (ratio + 1) + 1 when channel is 0 and bit 4 of 0xCF011A00 is set. | descriptive |
| [`sys_frc_enable_channels`](../../src/leon2m/sys/sys_frc_enable_channels.c) | `FUN_a0113138` | Switch the frame-rate converter channels of a mask on. | descriptive |
| [`sys_frc_get_channel_enables`](../../src/leon2m/sys/sys_frc_get_channel_enables.c) | `FUN_a0112fb8` | Return the channel enable bits of the frame-rate converter. | descriptive |
| [`sys_frc_get_enable_bit4`](../../src/leon2m/sys/sys_frc_get_enable_bit4.c) | `FUN_a010a874` | Return bit 4 of the converter's first enable register. | descriptive |
| [`sys_frc_get_output_active_height`](../../src/leon2m/sys/sys_frc_get_output_active_height.c) | `FUN_a010a8f0` | Read the converter's output timing value, scaled by chip revision. | derived |
| [`sys_frc_get_output_active_width`](../../src/leon2m/sys/sys_frc_get_output_active_width.c) | `FUN_a010a494` | Read the converter's output timing value from the active register pair. | derived |
| [`sys_frc_get_output_frame_length`](../../src/leon2m/sys/sys_frc_get_output_frame_length.c) | `FUN_a010a9e8` | Return the frame length of the converter's output timing. | derived |
| [`sys_frc_get_output_line_length`](../../src/leon2m/sys/sys_frc_get_output_line_length.c) | `FUN_a010a884` | Return the line length of the converter's output timing. | derived |
| [`sys_frc_init_control_number_fields`](../../src/leon2m/sys/sys_frc_init_control_number_fields.c) | `FUN_a0108f70` | Write n into bits 4-5 of FRC control register n (0..3) and clear bits 0-2 of registers 1..3. | descriptive |
| [`sys_frc_is_active`](../../src/leon2m/sys/sys_frc_is_active.c) | `FUN_a0108e54` | Return whether the frame-rate converter is active. | derived |
| [`sys_frc_is_channel_enabled`](../../src/leon2m/sys/sys_frc_is_channel_enabled.c) | `FUN_a0109598` | Return whether a converter channel is enabled. | derived |
| [`sys_frc_is_running`](../../src/leon2m/sys/sys_frc_is_running.c) | `FUN_a010a864` | Return whether the frame-rate converter is switched on. | derived |
| [`sys_frc_load_rom_settings`](../../src/leon2m/sys/sys_frc_load_rom_settings.c) | `FUN_a0112b2c` | Load the ROM settings selected by the two stored indexes into the frame-rate converter. | descriptive |
| [`sys_frc_set_active`](../../src/leon2m/sys/sys_frc_set_active.c) | `FUN_a0109110` | Switch the frame-rate converter's active bit on or off. | derived |
| [`sys_frc_set_channel_bit_triple`](../../src/leon2m/sys/sys_frc_set_channel_bit_triple.c) | `FUN_a01084a8` | Set or clear a converter channel's bit in three registers. | descriptive |
| [`sys_frc_set_channel_enable`](../../src/leon2m/sys/sys_frc_set_channel_enable.c) | `FUN_a0109554` | Set or clear the enable bit of a converter channel. | derived |
| [`sys_frc_set_channel_enable_bit`](../../src/leon2m/sys/sys_frc_set_channel_enable_bit.c) | `FUN_a0113020` | Set or clear one channel enable bit of the frame-rate converter. | descriptive |
| [`sys_frc_set_config_index`](../../src/leon2m/sys/sys_frc_set_config_index.c) | `FUN_a01118c0` | Store the first index that selects the frame-rate converter's ROM settings. | descriptive |
| [`sys_frc_set_d08_value`](../../src/leon2m/sys/sys_frc_set_d08_value.c) | `FUN_a0109b70` | Write a 16-bit value to 0xCF011D08 and split it over 0xCF011EC4 and 0xCF011EC0. | descriptive |
| [`sys_frc_set_dc0_bit`](../../src/leon2m/sys/sys_frc_set_dc0_bit.c) | `FUN_a0109ad0` | Set or clear one bit of converter register 0xCF011DC0. | descriptive |
| [`sys_frc_set_dc4_bit`](../../src/leon2m/sys/sys_frc_set_dc4_bit.c) | `FUN_a0109b14` | Set or clear one bit of converter register 0xCF011DC4. | descriptive |
| [`sys_frc_set_dc8_bit`](../../src/leon2m/sys/sys_frc_set_dc8_bit.c) | `FUN_a010ace4` | Set or clear one bit of converter register 0xCF011DC8. | descriptive |
| [`sys_frc_set_input_enable_bit`](../../src/leon2m/sys/sys_frc_set_input_enable_bit.c) | `FUN_a0109514` | Set or clear one bit of the converter's first enable register. | descriptive |
| [`sys_frc_set_input_enable_bit_copy`](../../src/leon2m/sys/sys_frc_set_input_enable_bit_copy.c) | `FUN_a0112fe0` | Set or clear one bit of the converter's first enable register. | descriptive |
| [`sys_frc_set_lock_mode`](../../src/leon2m/sys/sys_frc_set_lock_mode.c) | `FUN_a01085f8` | Set the lock mode bits of a converter channel. | derived |
| [`sys_frc_set_port_size_first`](../../src/leon2m/sys/sys_frc_set_port_size_first.c) | `FUN_a0109148` | Write a size pair of a converter port (first register pair). | descriptive |
| [`sys_frc_set_port_size_second`](../../src/leon2m/sys/sys_frc_set_port_size_second.c) | `FUN_a0109278` | Write a size pair of a converter port (second register pair). | descriptive |
| [`sys_frc_set_six_bit_field`](../../src/leon2m/sys/sys_frc_set_six_bit_field.c) | `FUN_a010ad28` | Write a 6-bit field of one of the registers 0xCF011DCC..0xCF011DD8. | descriptive |
| [`sys_frc_set_size_pair`](../../src/leon2m/sys/sys_frc_set_size_pair.c) | `FUN_a01099fc` | Write a size pair of converter channel 0..3. | descriptive |
| [`sys_frc_set_source_bit`](../../src/leon2m/sys/sys_frc_set_source_bit.c) | `FUN_a01093a8` | Set or clear one source bit of the frame-rate converter and update its idle bit. | descriptive |
| [`sys_frc_set_source_class_enable`](../../src/leon2m/sys/sys_frc_set_source_class_enable.c) | `FUN_a0109474` | Set or clear the enable bit of source class 1, 2 or 3. | derived |
| [`sys_frc_set_source_field_hi`](../../src/leon2m/sys/sys_frc_set_source_field_hi.c) | `FUN_a0108e70` | Write the 2-bit field at bits 4-5 of a converter source register. | descriptive |
| [`sys_frc_set_source_field_lo`](../../src/leon2m/sys/sys_frc_set_source_field_lo.c) | `FUN_a0108eec` | Write the 3-bit field at bits 0-2 of a converter source register. | descriptive |
| [`sys_frc_setup_lock`](../../src/leon2m/sys/sys_frc_setup_lock.c) | `FUN_a0109bbc` | Set the frame-rate converter up for locked or free-running output. | proven |
| [`sys_frc_switch_mode`](../../src/leon2m/sys/sys_frc_switch_mode.c) | `FUN_a01131d4` | Switch the frame-rate converter to another mode and reload its settings. | derived |
| [`sys_frc_wait_channel_frame`](../../src/leon2m/sys/sys_frc_wait_channel_frame.c) | `FUN_a010abd4` | Wait for one frame pulse of a converter channel, with time limits. | descriptive |
| [`sys_frc_wait_frame`](../../src/leon2m/sys/sys_frc_wait_frame.c) | `FUN_a010ac68` | Wait for one frame pulse of the converter, with time limits. | descriptive |
| [`sys_frc_write_cc4_a0`](../../src/leon2m/sys/sys_frc_write_cc4_a0.c) | `FUN_a0109b58` | Write 0xA0 to converter register 0xCF011CC4. | descriptive |
| [`sys_frc_write_mode_values`](../../src/leon2m/sys/sys_frc_write_mode_values.c) | `FUN_a01136a0` | Write one of two fixed value sets to the frame-rate converter registers. | descriptive |
| [`sys_frc_write_setting_values`](../../src/leon2m/sys/sys_frc_write_setting_values.c) | `FUN_a01129e4` | Write up to three values to the registers of the selected group (0..5, 0xA, 0xB, 0x13). | descriptive |
| `sys_frc_write_setting_values_jump_table` | `switchdataD_a0111834` | Jump table 1 of the switch statements in sys_frc_write_setting_values. | proven |
| [`sys_get_active_port_code`](../../src/leon2m/sys/sys_get_active_port_code.c) | `FUN_a012fc20` | Return the port code (port record byte +0xA) of the active channel's port, or 0xFF. | derived |
| [`sys_get_app_flag42_bit4`](../../src/leon2m/sys/sys_get_app_flag42_bit4.c) | `FUN_a0082c20` | Return bit 4 of the application flag halfword 0xA802AF42. | descriptive |
| [`sys_get_app_flag42_bit5`](../../src/leon2m/sys/sys_get_app_flag42_bit5.c) | `FUN_a0083c20` | Return bit 5 of the application flag halfword 0xA802AF42. | descriptive |
| [`sys_get_app_flag42_bit14`](../../src/leon2m/sys/sys_get_app_flag42_bit14.c) | `FUN_a0082c38` | Return bit 14 of the application flag halfword 0xA802AF42. | descriptive |
| [`sys_get_app_flag_bit3`](../../src/leon2m/sys/sys_get_app_flag_bit3.c) | `FUN_a0080bc0` | Return bit 3 of the application flag byte 0xA802AF41. | descriptive |
| [`sys_get_block_5a00_byte`](../../src/leon2m/sys/sys_get_block_5a00_byte.c) | `FUN_a011440c` | Return the low byte of register 0xCF015A00. | descriptive |
| [`sys_get_channel0_flag_bit19`](../../src/leon2m/sys/sys_get_channel0_flag_bit19.c) | `FUN_a014e010` | Return bit 19 of the flag word at +0x70 of channel record 0. | descriptive |
| [`sys_get_channel_flags_14_15`](../../src/leon2m/sys/sys_get_channel_flags_14_15.c) | `FUN_a013cea0` | Return the 2-bit field at bits 14-15 of a channel's flag word. | descriptive |
| [`sys_get_channel_port`](../../src/leon2m/sys/sys_get_channel_port.c) | `FUN_a012f3b4` | Return the port field of a channel. | derived |
| [`sys_get_channel_signal_code`](../../src/leon2m/sys/sys_get_channel_signal_code.c) | `FUN_a012fc70` | Return the signal code of a channel's input block; code 0xB1 gives another channel's port code. | descriptive |
| [`sys_get_channel_source_class`](../../src/leon2m/sys/sys_get_channel_source_class.c) | `FUN_a013cda8` | Return the port field of a channel when it is 1, 2 or 3, else 0. | descriptive |
| [`sys_get_channel_state`](../../src/leon2m/sys/sys_get_channel_state.c) | `FUN_a013ce6c` | Return the state field of a channel. | derived |
| [`sys_get_chip_model_code`](../../src/leon2m/sys/sys_get_chip_model_code.c) | `FUN_a011d0a8` | Return a code 1..7 for the chip model, or 0. | descriptive |
| [`sys_get_chip_revision`](../../src/leon2m/sys/sys_get_chip_revision.c) | `FUN_a011cf88` | Return the chip revision code 0x80..0x84. | derived |
| [`sys_get_const_0x1429`](../../src/leon2m/sys/sys_get_const_0x1429.c) | `FUN_a0124208` | Return the constant 0x1429. | descriptive |
| [`sys_get_const_0x1429_copy`](../../src/leon2m/sys/sys_get_const_0x1429_copy.c) | `FUN_a0124214` | Return the constant 0x1429. | descriptive |
| [`sys_get_logo_hold`](../../src/leon2m/sys/sys_get_logo_hold.c) | `FUN_a008453c` | Return bit 0 of 0xA802AF41 (logo shown, events held) | derived |
| [`sys_get_path_selector`](../../src/leon2m/sys/sys_get_path_selector.c) | `FUN_a0114360` | Return the 2-bit path selector. | descriptive |
| [`sys_get_pip_channel_count`](../../src/leon2m/sys/sys_get_pip_channel_count.c) | `FUN_a012f3ec` | Return the number of pictures shown in the current picture-in-picture mode. | descriptive |
| `sys_get_pip_channel_count_jump_table` | `switchdataD_a012f14c` | Jump table 1 of the switch statements in sys_get_pip_channel_count. | proven |
| [`sys_get_port_holdoff_count`](../../src/leon2m/sys/sys_get_port_holdoff_count.c) | `FUN_a014e7bc` | Return the hold-off counter of a port. | descriptive |
| [`sys_get_region_address`](../../src/leon2m/sys/sys_get_region_address.c) | `FUN_a002e46c` | Return the address of memory region k (0..0x14), or for 0x15..0x18 an address read from registers. | descriptive |
| `sys_get_region_address_jump_table` | `switchdataD_a002e408` | Jump table 1 of the switch statements in sys_get_region_address. | proven |
| [`sys_get_stack_pointer`](../../src/leon2m/sys/sys_get_stack_pointer.c) | `FUN_a00de9d8` | Return the current stack pointer. | proven |
| [`sys_get_status_byte`](../../src/leon2m/sys/sys_get_status_byte.c) | `FUN_a0152f70` | Return the status byte at 0xA802CF90. | descriptive |
| [`sys_get_three_status_words`](../../src/leon2m/sys/sys_get_three_status_words.c) | `FUN_a00f9500` | Fetch the three stored result words into the caller's variables. | descriptive |
| [`sys_init_enable_output_blocks`](../../src/leon2m/sys/sys_init_enable_output_blocks.c) | `FUN_a015202c` | Run the output-block reset and enable the twelve sub-blocks. | descriptive |
| [`sys_init_picture_blocks`](../../src/leon2m/sys/sys_init_picture_blocks.c) | `FUN_a0150da4` | Run the picture-block initialisers and set the two mode bits in 0xA802A4B8. | descriptive |
| [`sys_is_channel_value_below_default`](../../src/leon2m/sys/sys_is_channel_value_below_default.c) | `FUN_a013d198` | Return whether a channel value is below the default of the ROM row. | descriptive |
| [`sys_is_logo_hold`](../../src/leon2m/sys/sys_is_logo_hold.c) | `FUN_a0082c4c` | Return bit 0 of 0xA802AF41 (logo shown, events held) | derived |
| [`sys_is_mode_4_to_6`](../../src/leon2m/sys/sys_is_mode_4_to_6.c) | `FUN_a00837e4` | Return 1 when mode byte 0xA802D434 is 4, 5 or 6. | descriptive |
| [`sys_is_pip_mode_above_4`](../../src/leon2m/sys/sys_is_pip_mode_above_4.c) | `FUN_a013d178` | Return whether the picture-in-picture mode byte is above 4. | descriptive |
| [`sys_is_pip_mode_active`](../../src/leon2m/sys/sys_is_pip_mode_active.c) | `FUN_a013d670` | Return whether a picture-in-picture mode is set. | derived |
| [`sys_is_value_in_pip_limit`](../../src/leon2m/sys/sys_is_value_in_pip_limit.c) | `FUN_a013cecc` | Return whether a value is inside the limit for the current picture-in-picture mode. | descriptive |
| `sys_is_value_in_pip_limit_jump_table` | `switchdataD_a013c89c` | Jump table 1 of the switch statements in sys_is_value_in_pip_limit. | proven |
| [`sys_latch_status_state`](../../src/leon2m/sys/sys_latch_status_state.c) | `FUN_a011337c` | Derive a 0..2 state from the status bits and latch it one-hot. | descriptive |
| `sys_latch_status_state_jump_table` | `switchdataD_a0111884` | Jump table 1 of the switch statements in sys_latch_status_state. | proven |
| [`sys_latch_unit_event_ch0`](../../src/leon2m/sys/sys_latch_unit_event_ch0.c) | `FUN_a002ef0c` | Run the ROM step if its checks pass; clear two unit 0 registers, call the hook, mark event bit 0. | descriptive |
| [`sys_latch_unit_event_ch1`](../../src/leon2m/sys/sys_latch_unit_event_ch1.c) | `FUN_a002efd4` | Clear the two unit 1 registers at 0xCF006F30/34, set control bit 1 and mark event bit 1. | descriptive |
| [`sys_latch_unit_event_ch2`](../../src/leon2m/sys/sys_latch_unit_event_ch2.c) | `FUN_a002f010` | Clear the two unit 2 registers at 0xCF007330/34, set control bit 2 and mark event bit 2. | descriptive |
| [`sys_latch_unit_event_ch3`](../../src/leon2m/sys/sys_latch_unit_event_ch3.c) | `FUN_a002f04c` | Clear the two unit 3 registers at 0xCF007730/34, set control bit 3 and mark event bit 3. | descriptive |
| [`sys_latch_unit_event_ch4`](../../src/leon2m/sys/sys_latch_unit_event_ch4.c) | `FUN_a002f088` | Clear the two unit 4 registers at 0xCF007B30/34 and mark event bit 4. | descriptive |
| [`sys_latch_unit_event_ch6`](../../src/leon2m/sys/sys_latch_unit_event_ch6.c) | `FUN_a002f0b4` | Clear the two unit 6 registers at 0xCF008330/34 and mark event bit 6. | descriptive |
| [`sys_latch_unit_event_ch7`](../../src/leon2m/sys/sys_latch_unit_event_ch7.c) | `FUN_a002f0e0` | Clear the two unit 7 registers at 0xCF008730/34 and mark event bit 7. | descriptive |
| [`sys_led_bar_get_flag10`](../../src/leon2m/sys/sys_led_bar_get_flag10.c) | `FUN_a00daad4` | Return flag bit 10 of the LED light bar state. | descriptive |
| [`sys_led_bar_get_status_code`](../../src/leon2m/sys/sys_led_bar_get_status_code.c) | `FUN_a00da870` | Work out the status code 1..10 that the LED light bar shows. | derived |
| [`sys_led_bar_send_mode_command`](../../src/leon2m/sys/sys_led_bar_send_mode_command.c) | `FUN_a00da9e4` | Send the mode command with one digit to the LED light bar controller. | derived |
| [`sys_led_bar_send_query`](../../src/leon2m/sys/sys_led_bar_send_query.c) | `FUN_a00daa7c` | Send the fixed query command to the LED light bar controller. | derived |
| [`sys_main_loop_periodic_task`](../../src/leon2m/sys/sys_main_loop_periodic_task.c) | `FUN_a0153018` | Run one pass of the main program's periodic work: input and picture tasks, counters, alive signal. | proven |
| [`sys_map_channel_to_path_block`](../../src/leon2m/sys/sys_map_channel_to_path_block.c) | `FUN_a01423b0` | Return 0 for channel 0, 1 for channel 1 and 3 otherwise. | descriptive |
| [`sys_map_port_signal_code`](../../src/leon2m/sys/sys_map_port_signal_code.c) | `FUN_a013143c` | Translate a port's signal code through the source code table into two port bytes. | descriptive |
| [`sys_mem_port_enable`](../../src/leon2m/sys/sys_mem_port_enable.c) | `FUN_a0115644` | Switch the memory port on or off. | derived |
| [`sys_mem_port_read_blocks`](../../src/leon2m/sys/sys_mem_port_read_blocks.c) | `FUN_a011403c` | Read a number of 32-byte blocks through the memory port into a buffer. | derived |
| [`sys_mem_port_read_rgb_sums`](../../src/leon2m/sys/sys_mem_port_read_rgb_sums.c) | `FUN_a01139c8` | Read twelve blocks through the memory port and store the average of every eight value triples. | descriptive |
| [`sys_mem_port_read_word_blocks`](../../src/leon2m/sys/sys_mem_port_read_word_blocks.c) | `FUN_a0113cd8` | Read a number of 8-word blocks through the memory port. | derived |
| [`sys_mem_port_write_blocks`](../../src/leon2m/sys/sys_mem_port_write_blocks.c) | `FUN_a0113eb4` | Write a number of 32-byte blocks through the memory port. | derived |
| [`sys_mem_port_write_word_blocks`](../../src/leon2m/sys/sys_mem_port_write_word_blocks.c) | `FUN_a01138fc` | Write a number of 32-byte blocks from a word array through the memory port. | descriptive |
| [`sys_mode_apply_converter_setup`](../../src/leon2m/sys/sys_mode_apply_converter_setup.c) | `FUN_a015149c` | Apply the converter configuration selected by the system configuration fields to units 0..3. | descriptive |
| [`sys_mode_enter_state_c`](../../src/leon2m/sys/sys_mode_enter_state_c.c) | `FUN_a0151818` | Run the entry actions of channel state 0xC for the given channel when it is on port 0. | derived |
| [`sys_mode_notify_channel0_port`](../../src/leon2m/sys/sys_mode_notify_channel0_port.c) | `FUN_a01517f4` | Pass the port number of channel 0 to sys_map_port_signal_code, with selector 0. | descriptive |
| [`sys_mode_reset_vx1_if_link_type_1`](../../src/leon2m/sys/sys_mode_reset_vx1_if_link_type_1.c) | `FUN_a0151674` | Call ResetVx1 when bits 20..22 of the active panel row's first word equal 1. | derived |
| [`sys_mode_restart_channel`](../../src/leon2m/sys/sys_mode_restart_channel.c) | `FUN_a01518c8` | Run the entry actions of global mode handler state 5: reset and restart a channel. | derived |
| [`sys_mode_set_pwm7_and_continue`](../../src/leon2m/sys/sys_mode_set_pwm7_and_continue.c) | `FUN_a01519b4` | Set PWM port 7 to 0x3C0 and continue with the next mode step. | descriptive |
| [`sys_output_record1_add_flags_2001`](../../src/leon2m/sys/sys_output_record1_add_flags_2001.c) | `FUN_a012c090` | Add the flag bits 0x2001 to output record 1 and report them. | descriptive |
| [`sys_output_record_add_flags`](../../src/leon2m/sys/sys_output_record_add_flags.c) | `FUN_a012bb94` | Add flag bits to an output record and report them to the input processor. | descriptive |
| [`sys_output_record_clear_flags`](../../src/leon2m/sys/sys_output_record_clear_flags.c) | `FUN_a012baf0` | Clear the 16-bit flags of an output record. | descriptive |
| [`sys_output_record_set_flag`](../../src/leon2m/sys/sys_output_record_set_flag.c) | `FUN_a012be4c` | Store one flag of an output record and optionally report it to the input processor. | descriptive |
| [`sys_output_record_set_flag30`](../../src/leon2m/sys/sys_output_record_set_flag30.c) | `FUN_a012bb38` | Write flag bit 30 of output record 0, or clear it for another record. | descriptive |
| [`sys_output_record_set_flag31`](../../src/leon2m/sys/sys_output_record_set_flag31.c) | `FUN_a012c004` | Store flag bit 31 of an output record and report it when it changed. | descriptive |
| `sys_output_record_set_flag_jump_table` | `switchdataD_a012b8c0` | Jump table 1 of the switch statements in sys_output_record_set_flag. | proven |
| [`sys_output_record_set_word14`](../../src/leon2m/sys/sys_output_record_set_word14.c) | `FUN_a012bb14` | Store a word in an output record. | descriptive |
| [`sys_path_block_enable`](../../src/leon2m/sys/sys_path_block_enable.c) | `FUN_a011f1c8` | Switch a signal path block on or off. | descriptive |
| [`sys_path_block_fetch_readout`](../../src/leon2m/sys/sys_path_block_fetch_readout.c) | `FUN_a012043c` | Fetch the read-out words of a signal path block when it has finished. | descriptive |
| [`sys_path_block_init`](../../src/leon2m/sys/sys_path_block_init.c) | `FUN_a011eadc` | Load the start values of both signal path blocks from the ROM tables. | descriptive |
| [`sys_path_block_is_enabled`](../../src/leon2m/sys/sys_path_block_is_enabled.c) | `FUN_a01207ac` | Return whether a signal path block is switched on. | descriptive |
| [`sys_path_block_set_coefficients`](../../src/leon2m/sys/sys_path_block_set_coefficients.c) | `FUN_a011f6a4` | Write two coefficient records to a signal path block, or to both. | descriptive |
| [`sys_path_block_set_line_sizes`](../../src/leon2m/sys/sys_path_block_set_line_sizes.c) | `FUN_a01200f8` | Write two 16-bit sizes to registers 0x42..0x45 of a signal path block. | descriptive |
| [`sys_path_block_set_record`](../../src/leon2m/sys/sys_path_block_set_record.c) | `FUN_a011f364` | Write a mode record to registers 4..8 of a signal path block, or of both. | descriptive |
| [`sys_path_block_set_reg1a`](../../src/leon2m/sys/sys_path_block_set_reg1a.c) | `FUN_a0120678` | Write an on/off value to register 0x1A of a signal path block, or of both. | descriptive |
| [`sys_path_block_set_reg24`](../../src/leon2m/sys/sys_path_block_set_reg24.c) | `FUN_a011fd84` | Program register 0x24 and the 12-bit value behind it of a signal path block. | descriptive |
| [`sys_path_block_set_reg36`](../../src/leon2m/sys/sys_path_block_set_reg36.c) | `FUN_a011fbd8` | Write a 12-bit value with flag 0x4000 to registers 0x36/0x37 of a signal path block. | descriptive |
| [`sys_path_block_set_reg48_bit5`](../../src/leon2m/sys/sys_path_block_set_reg48_bit5.c) | `FUN_a011fcac` | Write bit 5 of register 0x48 of a signal path block. | descriptive |
| [`sys_path_block_set_width`](../../src/leon2m/sys/sys_path_block_set_width.c) | `FUN_a011ff28` | Write a 16-bit width to a signal path block, and a quarter of it to a second pair. | descriptive |
| [`sys_path_block_start_readout`](../../src/leon2m/sys/sys_path_block_start_readout.c) | `FUN_a01202c0` | Program the read-out register of a signal path block and start it. | descriptive |
| [`sys_path_get_mux_field`](../../src/leon2m/sys/sys_path_get_mux_field.c) | `FUN_a0120638` | Return the 2-bit selector of register 0xCF0116D8 as 2, 3 or 1. | descriptive |
| [`sys_path_set_mux_field`](../../src/leon2m/sys/sys_path_set_mux_field.c) | `FUN_a01205c0` | Write the 2-bit selector 1..3 in register 0xCF0116D8. | descriptive |
| [`sys_poll_events_stub`](../../src/leon2m/sys/sys_poll_events_stub.c) | `FUN_a008e7a8` | Do nothing (empty application event source) | descriptive |
| [`sys_poll_events_stub_copy`](../../src/leon2m/sys/sys_poll_events_stub_copy.c) | `FUN_a00d8b30` | Do nothing (empty application event source) | descriptive |
| [`sys_poll_events_stub_copy2`](../../src/leon2m/sys/sys_poll_events_stub_copy2.c) | `FUN_a00dd8ac` | Do nothing (empty application event source) | descriptive |
| [`sys_poll_events_stub_copy3`](../../src/leon2m/sys/sys_poll_events_stub_copy3.c) | `FUN_a0101858` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy4`](../../src/leon2m/sys/sys_poll_events_stub_copy4.c) | `FUN_a0101e68` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy5`](../../src/leon2m/sys/sys_poll_events_stub_copy5.c) | `FUN_a0107ba4` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy6`](../../src/leon2m/sys/sys_poll_events_stub_copy6.c) | `FUN_a0121f20` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy7`](../../src/leon2m/sys/sys_poll_events_stub_copy7.c) | `FUN_a0125a24` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy8`](../../src/leon2m/sys/sys_poll_events_stub_copy8.c) | `FUN_a0125bbc` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy9`](../../src/leon2m/sys/sys_poll_events_stub_copy9.c) | `FUN_a0125c34` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy10`](../../src/leon2m/sys/sys_poll_events_stub_copy10.c) | `FUN_a0125c3c` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy11`](../../src/leon2m/sys/sys_poll_events_stub_copy11.c) | `FUN_a0125c74` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy12`](../../src/leon2m/sys/sys_poll_events_stub_copy12.c) | `FUN_a0125c84` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy13`](../../src/leon2m/sys/sys_poll_events_stub_copy13.c) | `FUN_a0125c8c` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy14`](../../src/leon2m/sys/sys_poll_events_stub_copy14.c) | `FUN_a012ad64` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy15`](../../src/leon2m/sys/sys_poll_events_stub_copy15.c) | `FUN_a012b9a0` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy16`](../../src/leon2m/sys/sys_poll_events_stub_copy16.c) | `FUN_a012f12c` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy17`](../../src/leon2m/sys/sys_poll_events_stub_copy17.c) | `FUN_a013855c` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy18`](../../src/leon2m/sys/sys_poll_events_stub_copy18.c) | `FUN_a01437f4` | Do nothing (empty application event source) | descriptive |
| [`sys_poll_events_stub_copy19`](../../src/leon2m/sys/sys_poll_events_stub_copy19.c) | `FUN_a01437fc` | Do nothing (empty application event source) | descriptive |
| [`sys_poll_events_stub_copy20`](../../src/leon2m/sys/sys_poll_events_stub_copy20.c) | `FUN_a014771c` | Do nothing (empty application event source) | descriptive |
| [`sys_poll_events_stub_copy21`](../../src/leon2m/sys/sys_poll_events_stub_copy21.c) | `FUN_a014b968` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy22`](../../src/leon2m/sys/sys_poll_events_stub_copy22.c) | `FUN_a0151494` | Do nothing (empty routine). | descriptive |
| [`sys_poll_events_stub_copy23`](../../src/leon2m/sys/sys_poll_events_stub_copy23.c) | `FUN_a01544cc` | Do nothing (empty routine). | descriptive |
| [`sys_poll_port_flag5_holdoff`](../../src/leon2m/sys/sys_poll_port_flag5_holdoff.c) | `FUN_a014e768` | Return status bit 5 of a port record and keep the port's hold-off counter up to date. | descriptive |
| [`sys_post_app_event`](../../src/leon2m/sys/sys_post_app_event.c) | `FUN_a008a184` | Append an event to the application event queue (at most 10) | proven |
| [`sys_program_block_f500`](../../src/leon2m/sys/sys_program_block_f500.c) | `FUN_a0109654` | Program the register block at 0xCF00F500 or 0xCF00F580 with fixed values and one word. | descriptive |
| [`sys_publish_chip_status_code`](../../src/leon2m/sys/sys_publish_chip_status_code.c) | `FUN_a01544d4` | Set status 3 for chip revision class 8 with model code 3, else 0, and write it to a register. | descriptive |
| [`sys_pump_app_events`](../../src/leon2m/sys/sys_pump_app_events.c) | `FUN_a008a210` | Collect events from all producers and dispatch up to 10 of them. | proven |
| [`sys_read_id_area`](../../src/leon2m/sys/sys_read_id_area.c) | `FUN_a011ce80` | Copy one of the five small identification fields into a buffer. | descriptive |
| `sys_read_id_area_jump_table` | `switchdataD_a011ce6c` | Jump table 1 of the switch statements in sys_read_id_area. | proven |
| [`sys_read_id_record_byte`](../../src/leon2m/sys/sys_read_id_record_byte.c) | `FUN_a0115584` | Read the six-byte identification record, check it and return one of its bytes. | derived |
| [`sys_read_paged_reg_76`](../../src/leon2m/sys/sys_read_paged_reg_76.c) | `FUN_a0122e24` | Read register reg of group 0x76 through the indirect registers, with the given page selected. | descriptive |
| [`sys_read_startup_key`](../../src/leon2m/sys/sys_read_startup_key.c) | `FUN_a008e650` | Read the front keys at start-up, log them for the key test and set the start-up key option. | derived |
| [`sys_refresh_status_and_signal_alive`](../../src/leon2m/sys/sys_refresh_status_and_signal_alive.c) | `FUN_a0154580` | Refresh the input status codes when requested, then signal the 8051 that the main processor is alive. | derived |
| [`sys_register_callback`](../../src/leon2m/sys/sys_register_callback.c) | `FUN_a0143700` | Store a callback in one of the fifteen slots of the callback table. | proven |
| `sys_register_callback_jump_table` | `switchdataD_a0142ffc` | Jump table 1 of the switch statements in sys_register_callback. | proven |
| [`sys_release_logo_hold`](../../src/leon2m/sys/sys_release_logo_hold.c) | `FUN_a0082acc` | Finish the logo phase: restore the picture, unblock all keys, clear the hold flag and flag 25. | derived |
| [`sys_report_output_timing`](../../src/leon2m/sys/sys_report_output_timing.c) | `FUN_a012bc08` | Build the output timing record of a channel and report it to the input processor. | derived |
| [`sys_request_with_zero_byte`](../../src/leon2m/sys/sys_request_with_zero_byte.c) | `FUN_a0152010` | Send a request with a zero byte and return the argument unchanged. | descriptive |
| [`sys_reset_memory_interfaces`](../../src/leon2m/sys/sys_reset_memory_interfaces.c) | `FUN_a0114650` | Clear and set the fixed register sequence of the three memory interfaces. | descriptive |
| [`sys_restart_channel`](../../src/leon2m/sys/sys_restart_channel.c) | `FUN_a012f1ec` | Set a channel back to an earlier state so that it is brought up again. | derived |
| [`sys_return_4`](../../src/leon2m/sys/sys_return_4.c) | `FUN_a012c110` | Return the constant 4. | descriptive |
| [`sys_return_constant_9`](../../src/leon2m/sys/sys_return_constant_9.c) | `FUN_a01547c8` | Return the constant 9. | descriptive |
| [`sys_return_one`](../../src/leon2m/sys/sys_return_one.c) | `FUN_a0110f44` | Return 1. | descriptive |
| [`sys_return_one_copy`](../../src/leon2m/sys/sys_return_one_copy.c) | `FUN_a0124eac` | Return 1. | descriptive |
| [`sys_return_one_copy2`](../../src/leon2m/sys/sys_return_one_copy2.c) | `FUN_a0147c40` | Return 1. | descriptive |
| [`sys_return_one_copy3`](../../src/leon2m/sys/sys_return_one_copy3.c) | `FUN_a0148804` | Return 1. | descriptive |
| [`sys_return_one_copy4`](../../src/leon2m/sys/sys_return_one_copy4.c) | `FUN_a014880c` | Return 1. | descriptive |
| [`sys_return_one_copy5`](../../src/leon2m/sys/sys_return_one_copy5.c) | `FUN_a0148814` | Return 1. | descriptive |
| [`sys_return_zero`](../../src/leon2m/sys/sys_return_zero.c) | `FUN_a0110f4c` | Return 0. | descriptive |
| [`sys_return_zero_copy`](../../src/leon2m/sys/sys_return_zero_copy.c) | `FUN_a0110f54` | Return 0. | descriptive |
| [`sys_return_zero_copy2`](../../src/leon2m/sys/sys_return_zero_copy2.c) | `FUN_a011898c` | Return 0. | descriptive |
| [`sys_return_zero_copy3`](../../src/leon2m/sys/sys_return_zero_copy3.c) | `FUN_a012b394` | Return 0. | descriptive |
| [`sys_return_zero_copy4`](../../src/leon2m/sys/sys_return_zero_copy4.c) | `FUN_a01423a8` | Return 0. | descriptive |
| [`sys_return_zero_copy5`](../../src/leon2m/sys/sys_return_zero_copy5.c) | `FUN_a015e7d8` | Return 0. | descriptive |
| [`sys_run_app_main_task`](../../src/leon2m/sys/sys_run_app_main_task.c) | `FUN_a0087430` | Run one application step: event pump, periodic OSD task, timer task and DDC/CI request task. | proven |
| [`sys_run_app_timer_task`](../../src/leon2m/sys/sys_run_app_timer_task.c) | `FUN_a0085984` | Run the timed application checks: OLED errors, fake sleep, power saving, USB, PIP. | proven |
| `sys_run_app_timer_task_jump_table` | `switchdataD_a0080300` | Jump table 1 of the switch statements in sys_run_app_timer_task. | proven |
| [`sys_scan_keys_post_event`](../../src/leon2m/sys/sys_scan_keys_post_event.c) | `FUN_a008e7b0` | Read the front keys, apply repeat, long-press and block rules, and post the key event. | proven |
| [`sys_service_ports_by_mask`](../../src/leon2m/sys/sys_service_ports_by_mask.c) | `FUN_a01519d8` | Run the service calls for the port group selected by sel (4, 8, 0x10 or 0x20). | descriptive |
| [`sys_set_all_channels_flag25`](../../src/leon2m/sys/sys_set_all_channels_flag25.c) | `FUN_a013cf84` | Set flag bit 25 in all four channel records. | descriptive |
| [`sys_set_app_flag44_bit2`](../../src/leon2m/sys/sys_set_app_flag44_bit2.c) | `FUN_a0082c0c` | Set bit 2 of the application flag byte 0xA802AF44. | descriptive |
| [`sys_set_app_flag_bit3`](../../src/leon2m/sys/sys_set_app_flag_bit3.c) | `FUN_a0080bd8` | Set bit 3 of the application flag byte 0xA802AF41 when v is 1, else clear it. | descriptive |
| [`sys_set_block_5b50_size`](../../src/leon2m/sys/sys_set_block_5b50_size.c) | `FUN_a0114420` | Write a width rounded up to 8 and half a height to the block at 0xCF015B50. | descriptive |
| [`sys_set_c940_bit1_and_notify`](../../src/leon2m/sys/sys_set_c940_bit1_and_notify.c) | `FUN_a014e7e0` | Set or clear bit 1 of register 0xCF03C940, then write the follow-up register. | descriptive |
| [`sys_set_c940_bit2_and_notify`](../../src/leon2m/sys/sys_set_c940_bit2_and_notify.c) | `FUN_a014e82c` | Set or clear bit 2 of register 0xCF03C940, then write the follow-up register. | descriptive |
| [`sys_set_channel_enable`](../../src/leon2m/sys/sys_set_channel_enable.c) | `FUN_a01302e0` | Switch a channel on or off. | derived |
| [`sys_set_channel_flag17`](../../src/leon2m/sys/sys_set_channel_flag17.c) | `FUN_a01302a4` | Write flag bit 17 of a channel record. | descriptive |
| [`sys_set_channel_path_mode`](../../src/leon2m/sys/sys_set_channel_path_mode.c) | `FUN_a0142418` | Apply mode 0..4 to the signal path block of path 0 or 1, or switch the block off. | descriptive |
| [`sys_set_channel_port`](../../src/leon2m/sys/sys_set_channel_port.c) | `FUN_a012f43c` | Set the port code of a channel's port, re-select the channel's source and note the code's class. | derived |
| `sys_set_channel_port_jump_table` | `switchdataD_a012f16c` | Jump table 1 of the switch statements in sys_set_channel_port. | proven |
| [`sys_set_channel_source`](../../src/leon2m/sys/sys_set_channel_source.c) | `FUN_a013d018` | Store the source and its receiver index in a channel record. | derived |
| [`sys_set_channel_window_size`](../../src/leon2m/sys/sys_set_channel_window_size.c) | `FUN_a013d684` | Compute the window size of a channel from its timing and program it. | derived |
| [`sys_set_ef80_block`](../../src/leon2m/sys/sys_set_ef80_block.c) | `FUN_a014e8ec` | Write two 16-bit values as low and high bytes to block 0xCF00EF80 and switch it on, or switch it off. | descriptive |
| [`sys_set_factory_mode_flag`](../../src/leon2m/sys/sys_set_factory_mode_flag.c) | `FUN_a00cea18` | Set the factory mode flag and switch all input signals on. | derived |
| [`sys_set_five_block_bits`](../../src/leon2m/sys/sys_set_five_block_bits.c) | `FUN_a0122d5c` | Set one bit each in five block control registers. | descriptive |
| [`sys_set_hook_c9e0`](../../src/leon2m/sys/sys_set_hook_c9e0.c) | `FUN_a0121eac` | Store the hook pointer at 0xA802C9E0. | descriptive |
| [`sys_set_key_blocked`](../../src/leon2m/sys/sys_set_key_blocked.c) | `FUN_a008ee6c` | Block or unblock one key, or all keys with id 0xFF. | derived |
| [`sys_set_key_long_press`](../../src/leon2m/sys/sys_set_key_long_press.c) | `FUN_a008ed00` | Make one key (or all with 0xFF) act only after being held for the long-press time. | derived |
| [`sys_set_key_long_press_alt`](../../src/leon2m/sys/sys_set_key_long_press_alt.c) | `FUN_a008edb8` | Give one key a second event code that it sends when held long. | derived |
| [`sys_set_key_long_press_time`](../../src/leon2m/sys/sys_set_key_long_press_time.c) | `FUN_a008ef3c` | Set the hold time that counts as a long key press. | derived |
| [`sys_set_key_modes_for_menu`](../../src/leon2m/sys/sys_set_key_modes_for_menu.c) | `FUN_a0091094` | Set the key repeat and long-press rules for the current menu state. | derived |
| [`sys_set_key_repeat`](../../src/leon2m/sys/sys_set_key_repeat.c) | `FUN_a008ec48` | Turn auto-repeat on or off for one key, or for all keys with id 0xFF. | derived |
| [`sys_set_key_repeat_delay`](../../src/leon2m/sys/sys_set_key_repeat_delay.c) | `FUN_a008ef24` | Set the hold time before a repeating key repeats for the first time. | derived |
| [`sys_set_key_repeat_interval`](../../src/leon2m/sys/sys_set_key_repeat_interval.c) | `FUN_a008ef30` | Set the time between repeats of a held key. | derived |
| [`sys_set_mode_byte_c9f8`](../../src/leon2m/sys/sys_set_mode_byte_c9f8.c) | `FUN_a01243bc` | Store the mode byte at 0xA802C9F8. | descriptive |
| [`sys_set_mode_byte_c9f9`](../../src/leon2m/sys/sys_set_mode_byte_c9f9.c) | `FUN_a01243b0` | Store the mode byte at 0xA802C9F9. | descriptive |
| [`sys_set_path_selector`](../../src/leon2m/sys/sys_set_path_selector.c) | `FUN_a011433c` | Write the 2-bit path selector. | descriptive |
| [`sys_set_reg1360_bit`](../../src/leon2m/sys/sys_set_reg1360_bit.c) | `FUN_a0101e24` | Set or clear one bit of register 0xCF011360. | descriptive |
| [`sys_set_reg3428_bit0_guarded`](../../src/leon2m/sys/sys_set_reg3428_bit0_guarded.c) | `FUN_a0113810` | Set or clear bit 0 of register 0xCF013428 inside the guard sequence. | descriptive |
| [`sys_set_selected_path_enable`](../../src/leon2m/sys/sys_set_selected_path_enable.c) | `FUN_a0114374` | Switch the selected path on or off, or clear a block bit for another path. | descriptive |
| [`sys_set_state_bit10_and_apply`](../../src/leon2m/sys/sys_set_state_bit10_and_apply.c) | `FUN_a0083b14` | Set bit 10 of the app state word; with PIP/PBP off make channel 0's port the source of channel 1. | descriptive |
| [`sys_set_three_clock_bits`](../../src/leon2m/sys/sys_set_three_clock_bits.c) | `FUN_a0118380` | Set bit 0 of three block registers. | descriptive |
| [`sys_set_unit_ea00_bit0`](../../src/leon2m/sys/sys_set_unit_ea00_bit0.c) | `FUN_a01075a8` | Clear bit 4 of 0xCF00EAC8 and write bit 0 of 0xCF00EA00. | descriptive |
| [`sys_setup_channel_window`](../../src/leon2m/sys/sys_setup_channel_window.c) | `FUN_a013d918` | Set up the output window of a channel. | derived |
| [`sys_setup_low_resolution_path`](../../src/leon2m/sys/sys_setup_low_resolution_path.c) | `FUN_a0142518` | Set the line width and padding of the path used for low-resolution and interlaced signals. | derived |
| [`sys_shut_down_blocks`](../../src/leon2m/sys/sys_shut_down_blocks.c) | `FUN_a011d194` | Run the shut-down sequence of the picture blocks and switch the PWM outputs off. | derived |
| [`sys_store_request_byte`](../../src/leon2m/sys/sys_store_request_byte.c) | `FUN_a01111e4` | Store a byte from the caller's buffer. | descriptive |
| [`sys_touch_row_and_return`](../../src/leon2m/sys/sys_touch_row_and_return.c) | `FUN_a012c118` | Call the active-row routine and return the argument. | descriptive |
| [`sys_user_apply_adaptive_sync_setting`](../../src/leon2m/sys/sys_user_apply_adaptive_sync_setting.c) | `FUN_a00da184` | Apply the Adaptive-Sync switch: reload the EDID, restart both channels, set DSC support from it. | derived |
| [`sys_user_apply_auto_level`](../../src/leon2m/sys/sys_user_apply_auto_level.c) | `FUN_a00d8ffc` | Switch the automatic level control as the setting says; re-apply the brightness when it is off. | descriptive |
| [`sys_user_apply_brightness`](../../src/leon2m/sys/sys_user_apply_brightness.c) | `FUN_a00d8cd4` | Apply the brightness setting for the current mode, picture state and input. | derived |
| [`sys_user_apply_byte_2b_slot5`](../../src/leon2m/sys/sys_user_apply_byte_2b_slot5.c) | `FUN_a00d5b10` | Pass settings byte +0x2B to a routine that is empty in this firmware. | descriptive |
| [`sys_user_apply_byte_2c_slot6`](../../src/leon2m/sys/sys_user_apply_byte_2c_slot6.c) | `FUN_a00d5b2c` | Pass settings byte +0x2C to a routine that is empty in this firmware. | descriptive |
| [`sys_user_apply_byte_2d_slot5`](../../src/leon2m/sys/sys_user_apply_byte_2d_slot5.c) | `FUN_a00d5b48` | Pass settings byte +0x2D to a routine that is empty in this firmware. | descriptive |
| [`sys_user_apply_byte_2e_slot6`](../../src/leon2m/sys/sys_user_apply_byte_2e_slot6.c) | `FUN_a00d5b64` | Pass settings byte +0x2E to a routine that is empty in this firmware. | descriptive |
| [`sys_user_apply_byte_27_slot5`](../../src/leon2m/sys/sys_user_apply_byte_27_slot5.c) | `FUN_a00d5ca0` | Pass settings byte +0x27 to a routine that is empty in this firmware. | descriptive |
| [`sys_user_apply_byte_28_slot6`](../../src/leon2m/sys/sys_user_apply_byte_28_slot6.c) | `FUN_a00d5cbc` | Pass settings byte +0x28 to a routine that is empty in this firmware. | descriptive |
| [`sys_user_apply_channel0_scaling_mode`](../../src/leon2m/sys/sys_user_apply_channel0_scaling_mode.c) | `FUN_a00d58f8` | Apply the scaling mode setting to channel 0. | descriptive |
| [`sys_user_apply_channel1_scaling_mode`](../../src/leon2m/sys/sys_user_apply_channel1_scaling_mode.c) | `FUN_a00d58d8` | Apply the scaling mode setting to channel 1. | descriptive |
| [`sys_user_apply_channel2_enable`](../../src/leon2m/sys/sys_user_apply_channel2_enable.c) | `FUN_a00d5b80` | Apply the enable setting of channel 2. | descriptive |
| [`sys_user_apply_channel3_enable`](../../src/leon2m/sys/sys_user_apply_channel3_enable.c) | `FUN_a00d5b9c` | Apply the enable setting of channel 3. | descriptive |
| [`sys_user_apply_config_bit25`](../../src/leon2m/sys/sys_user_apply_config_bit25.c) | `FUN_a00d5e84` | Apply settings bit 30 to configuration bit 25 and restart all channels. | descriptive |
| [`sys_user_apply_config_bit31`](../../src/leon2m/sys/sys_user_apply_config_bit31.c) | `FUN_a00d5918` | Apply settings bit 9 to configuration bit 31. | descriptive |
| [`sys_user_apply_config_field`](../../src/leon2m/sys/sys_user_apply_config_field.c) | `FUN_a00d5e0c` | Apply a 4-bit settings field and restart all channels. | descriptive |
| [`sys_user_apply_dimming_mode`](../../src/leon2m/sys/sys_user_apply_dimming_mode.c) | `FUN_a00d9120` | Send the dimming mode for the current state and re-apply the picture table. | descriptive |
| [`sys_user_apply_input_link_settings`](../../src/leon2m/sys/sys_user_apply_input_link_settings.c) | `FUN_a00d9fdc` | Apply the per-input link settings and the EDID for a selector. | derived |
| [`sys_user_apply_mode_byte`](../../src/leon2m/sys/sys_user_apply_mode_byte.c) | `FUN_a00db174` | Store the mode byte from settings bit 30. | descriptive |
| [`sys_user_apply_output_mode`](../../src/leon2m/sys/sys_user_apply_output_mode.c) | `FUN_a00d5da4` | Apply the output mode setting. | descriptive |
| [`sys_user_apply_pip_sources`](../../src/leon2m/sys/sys_user_apply_pip_sources.c) | `FUN_a00d5938` | Select the source of extra picture 1, 2 or 3 from settings bytes +0x20 to +0x22. | derived |
| [`sys_user_apply_second_picture_enable`](../../src/leon2m/sys/sys_user_apply_second_picture_enable.c) | `FUN_a00d5eac` | Switch the second picture's source and port on or off as the settings say. | derived |
| [`sys_user_apply_source_slot4`](../../src/leon2m/sys/sys_user_apply_source_slot4.c) | `FUN_a00d59d4` | Select the source of slot 4 from the settings. | descriptive |
| [`sys_user_apply_source_slot5`](../../src/leon2m/sys/sys_user_apply_source_slot5.c) | `FUN_a00d59f0` | Select the source of slot 5 from the settings. | descriptive |
| [`sys_user_apply_source_slot6`](../../src/leon2m/sys/sys_user_apply_source_slot6.c) | `FUN_a00d5a0c` | Select the source of slot 6 from the settings. | descriptive |
| [`sys_user_apply_startup_settings`](../../src/leon2m/sys/sys_user_apply_startup_settings.c) | `FUN_a00db054` | Run the set-up calls that apply the stored settings after power-on. | derived |
| [`sys_user_apply_table_record_slot5`](../../src/leon2m/sys/sys_user_apply_table_record_slot5.c) | `FUN_a00d5a28` | Pass the record chosen by a settings byte to the slot 5 routine. | descriptive |
| [`sys_user_apply_table_record_slot6`](../../src/leon2m/sys/sys_user_apply_table_record_slot6.c) | `FUN_a00d5a9c` | Pass the record chosen by a settings byte to the slot 6 routine. | descriptive |
| [`sys_user_apply_window_channel1`](../../src/leon2m/sys/sys_user_apply_window_channel1.c) | `FUN_a00d79b0` | Compute the window of channel 1, hand it over and restart the channel. | derived |
| [`sys_user_clear_second_picture_request`](../../src/leon2m/sys/sys_user_clear_second_picture_request.c) | `FUN_a00d5f3c` | Clear a pending second-picture request and switch that picture off when it is not in use. | descriptive |
| [`sys_user_factory_reset`](../../src/leon2m/sys/sys_user_factory_reset.c) | `FUN_a00dc3dc` | Reload all user settings from their defaults and apply every one of them. | proven |
| [`sys_user_get_picture_state`](../../src/leon2m/sys/sys_user_get_picture_state.c) | `FUN_a00d7d48` | Return a code for the current picture state. | descriptive |
| [`sys_user_get_table_pair`](../../src/leon2m/sys/sys_user_get_table_pair.c) | `FUN_a00d80d8` | Fetch two 16-bit values of a record of the table at 0x1984C8. | descriptive |
| [`sys_user_is_special_picture_state`](../../src/leon2m/sys/sys_user_is_special_picture_state.c) | `FUN_a00d7b60` | Return 1 when the status field is 2 or port flag 9 of channel 0 is set. | descriptive |
| [`sys_user_map_mode_1_2`](../../src/leon2m/sys/sys_user_map_mode_1_2.c) | `FUN_a00d493c` | Map 1 to 0, 2 to 1 and other values to 5. | descriptive |
| [`sys_user_map_setting_to_float`](../../src/leon2m/sys/sys_user_map_setting_to_float.c) | `FUN_a00d3d30` | Map a setting byte to an output value in floating point. | descriptive |
| [`sys_user_rebuild_window_channel1`](../../src/leon2m/sys/sys_user_rebuild_window_channel1.c) | `FUN_a00d7b20` | Compute the window of channel 1, hand it over and rebuild it. | derived |
| [`sys_user_rebuild_window_channel2`](../../src/leon2m/sys/sys_user_rebuild_window_channel2.c) | `FUN_a00d7a30` | Compute the window of channel 2, hand it over and rebuild it. | derived |
| [`sys_user_reset_display_path`](../../src/leon2m/sys/sys_user_reset_display_path.c) | `FUN_a00d9238` | Mute, switch the panel off when showing, select the input source and restart channels 0 and 1. | derived |
| [`sys_user_reset_settings_keep_source`](../../src/leon2m/sys/sys_user_reset_settings_keep_source.c) | `FUN_a00dc2dc` | Put the whole user settings record back to its defaults, keeping the input source, and re-apply. | derived |
| [`sys_user_resize_window_channel1`](../../src/leon2m/sys/sys_user_resize_window_channel1.c) | `FUN_a00d7a70` | Compute the window of channel 1 and update it, with its source briefly off when asked. | derived |
| [`sys_user_resize_window_channel2`](../../src/leon2m/sys/sys_user_resize_window_channel2.c) | `FUN_a00d79f0` | Compute the window of channel 2, hand it over and update its size. | derived |
| [`sys_user_restart_channel0`](../../src/leon2m/sys/sys_user_restart_channel0.c) | `FUN_a00d4910` | Restart channel 0 at level 1. | descriptive |
| [`sys_user_restart_channel0_copy`](../../src/leon2m/sys/sys_user_restart_channel0_copy.c) | `FUN_a00d5d8c` | Restart channel 0 at level 1. | descriptive |
| [`sys_user_restart_channel2_by_table`](../../src/leon2m/sys/sys_user_restart_channel2_by_table.c) | `FUN_a00d5bb8` | Copy a table record chosen by settings byte +0x46 and restart channel 2 if its enable value is 1. | descriptive |
| [`sys_user_restart_channel3_by_table`](../../src/leon2m/sys/sys_user_restart_channel3_by_table.c) | `FUN_a00d5c2c` | Copy a table record chosen by a settings byte and restart channel 3 if its enable value is 1. | descriptive |
| [`sys_user_save_mode_slot`](../../src/leon2m/sys/sys_user_save_mode_slot.c) | `FUN_a00d4998` | Copy the current picture settings into the slot of a picture mode. | derived |
| `sys_user_save_mode_slot_jump_table` | `switchdataD_a00d3a30` | Jump table 1 of the switch statements in sys_user_save_mode_slot. | proven |
| [`sys_user_select_mode_setting`](../../src/leon2m/sys/sys_user_select_mode_setting.c) | `FUN_a00d8100` | Select the settings field that belongs to an item number in the current picture mode. | derived |
| `sys_user_select_mode_setting_jump_table` | `switchdataD_a00d3ad8` | Jump table 1 of the switch statements in sys_user_select_mode_setting. | proven |
| [`sys_user_swap_pip_sources`](../../src/leon2m/sys/sys_user_swap_pip_sources.c) | `FUN_a00d934c` | Swap the sources of the main and the second picture. | derived |
| [`sys_vcp_clamp_field_14`](../../src/leon2m/sys/sys_vcp_clamp_field_14.c) | `FUN_a00d40c8` | Limit position field 0x14 of a channel to 63 and write it back. | descriptive |
| [`sys_vcp_clamp_field_f`](../../src/leon2m/sys/sys_vcp_clamp_field_f.c) | `FUN_a00d444c` | Limit field 0x0F of a channel to field 0x12 and write it back. | descriptive |
| [`sys_vcp_get_field_4_percent`](../../src/leon2m/sys/sys_vcp_get_field_4_percent.c) | `FUN_a00d4250` | Return position field 4 of the active channel as a percentage. | descriptive |
| [`sys_vcp_get_field_15`](../../src/leon2m/sys/sys_vcp_get_field_15.c) | `FUN_a00d4164` | Return the low byte of timing field 0x15 of the channel input_api_find_channel_not_sync_mode5 gives. | descriptive |
| [`sys_vcp_get_field_b_percent`](../../src/leon2m/sys/sys_vcp_get_field_b_percent.c) | `FUN_a00d43b4` | Return position field 0x0B of the active channel as a percentage of its range. | descriptive |
| [`sys_vcp_reset_positions`](../../src/leon2m/sys/sys_vcp_reset_positions.c) | `FUN_a00d5748` | Reset the channel positions and write the four position fields back. | descriptive |
| [`sys_vcp_return_ff`](../../src/leon2m/sys/sys_vcp_return_ff.c) | `FUN_a00d4558` | Return 0xFF. | descriptive |
| [`sys_vcp_rewrite_field_4`](../../src/leon2m/sys/sys_vcp_rewrite_field_4.c) | `FUN_a00d4188` | Write position field 4 of a channel back unchanged. | descriptive |
| [`sys_vcp_rewrite_field_b`](../../src/leon2m/sys/sys_vcp_rewrite_field_b.c) | `FUN_a00d42e0` | Write position field 0x0B of a channel back unchanged. | descriptive |
| [`sys_vcp_set_field_4_percent`](../../src/leon2m/sys/sys_vcp_set_field_4_percent.c) | `FUN_a00d41b4` | Set position field 4 of the active channel from a percentage. | descriptive |
| [`sys_vcp_set_field_14_percent`](../../src/leon2m/sys/sys_vcp_set_field_14_percent.c) | `FUN_a00d4108` | Set position field 0x14 of the active channel from a percentage. | descriptive |
| [`sys_vcp_set_field_b_percent`](../../src/leon2m/sys/sys_vcp_set_field_b_percent.c) | `FUN_a00d430c` | Set position field 0x0B of the active channel from a percentage between its limits. | descriptive |
| [`sys_vcp_set_field_f_percent`](../../src/leon2m/sys/sys_vcp_set_field_f_percent.c) | `FUN_a00d44bc` | Set a further position field of the active channel from a percentage. | descriptive |
| [`sys_write_c374_value6`](../../src/leon2m/sys/sys_write_c374_value6.c) | `FUN_a011d1fc` | Write 6 to register 0xCF03C374. | descriptive |
| [`sys_write_paged_reg_76`](../../src/leon2m/sys/sys_write_paged_reg_76.c) | `FUN_a0122dbc` | Write a paged register 0x7600 + n with the page register saved and restored. | descriptive |
| [`sys_write_reg_b708_by_flag`](../../src/leon2m/sys/sys_write_reg_b708_by_flag.c) | `FUN_a0110f5c` | Write one of two values to a register by a flag. | descriptive |
| [`sys_write_reg_sequence_1814`](../../src/leon2m/sys/sys_write_reg_sequence_1814.c) | `FUN_a01234b8` | Clear register 0xCF011814 and write four values through the shared write sequence. | descriptive |
| [`sys_write_status_register`](../../src/leon2m/sys/sys_write_status_register.c) | `FUN_a01004cc` | Write the status byte to the status register. | descriptive |
| [`SYSAPI_ConfigSystemPIPMode`](../../src/leon2m/sys/SYSAPI_ConfigSystemPIPMode.c) | `FUN_a0149bf0` | Set the picture-in-picture / picture-by-picture mode and reconfigure the channels. | proven |
| `SYSAPI_ConfigSystemPIPMode_jump_table` | `switchdataD_a01434b4` | Jump table 1 of the switch statements in SYSAPI_ConfigSystemPIPMode. | proven |
| [`SYSAPI_ConfigSystemPostFRCLockMode`](../../src/leon2m/sys/SYSAPI_ConfigSystemPostFRCLockMode.c) | `FUN_a0148e34` | Switch the lock mode of the frame-rate converter output on or off. | proven |
| [`SYSAPI_ConfigSystemPostFRCMainBypass`](../../src/leon2m/sys/SYSAPI_ConfigSystemPostFRCMainBypass.c) | `FUN_a0148eb4` | Switch the bypass of the frame-rate converter for the main picture on or off. | proven |
| [`SysTasksBeforeDisplay_byChannel`](../../src/leon2m/sys/SysTasksBeforeDisplay_byChannel.c) | `FUN_a01516b0` | Run the per-channel tasks that precede showing the picture and enable frame-rate conversion. | proven |
| [`UserSetAuroraLEDBarBrightness`](../../src/leon2m/sys/UserSetAuroraLEDBarBrightness.c) | `FUN_a00da754` | Send the brightness of the LED light bar to its controller. | proven |
| [`UserSetPIPMode`](../../src/leon2m/sys/UserSetPIPMode.c) | `FUN_a00da254` | Apply the picture-in-picture / picture-by-picture mode the user chose. | proven |
| `UserSetPIPMode_jump_table` | `switchdataD_a00d3b7c` | Jump table 1 of the switch statements in UserSetPIPMode. | proven |

<a id="input"></a>
## Video inputs: detection, measurement, routing

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`input_adc_auto_adjust`](../../src/leon2m/input/input_adc_auto_adjust.c) | `FUN_a00f446c` | Run the three-stage automatic adjustment of the analogue input stage. | descriptive |
| [`input_adc_auto_color`](../../src/leon2m/input/input_adc_auto_color.c) | `FUN_a00f59c4` | Run the automatic level and offset calibration in one of two sequences chosen by mode. | descriptive |
| [`input_adc_calibrate_internal`](../../src/leon2m/input/input_adc_calibrate_internal.c) | `FUN_a00f557c` | Calibrate the analogue input stage against the internal reference. | descriptive |
| [`input_adc_calibrate_levels`](../../src/leon2m/input/input_adc_calibrate_levels.c) | `FUN_a00f4e60` | Sample the three level values until ten stable readings and store their averages. | descriptive |
| [`input_adc_calibrate_offsets`](../../src/leon2m/input/input_adc_calibrate_offsets.c) | `FUN_a00f51b4` | Sample the three offset values until ten stable readings and store their averages. | descriptive |
| [`input_adc_configure`](../../src/leon2m/input/input_adc_configure.c) | `FUN_a00f32d8` | Run the on or off register sequence of the analogue input stage and keep its record. | descriptive |
| [`input_adc_get_level0`](../../src/leon2m/input/input_adc_get_level0.c) | `FUN_a00f3988` | Return the first of the three level bytes that the calibration routines save and restore. | descriptive |
| [`input_adc_get_level1`](../../src/leon2m/input/input_adc_get_level1.c) | `FUN_a00f3974` | Return the second of the three level bytes that the calibration routines save and restore. | descriptive |
| [`input_adc_get_level2`](../../src/leon2m/input/input_adc_get_level2.c) | `FUN_a00f3960` | Return the third of the three level bytes that the calibration routines save and restore. | descriptive |
| [`input_adc_get_line_width`](../../src/leon2m/input/input_adc_get_line_width.c) | `FUN_a00f3528` | Return the 16-bit width value from the hook or from its register pair. | descriptive |
| [`input_adc_get_offset0`](../../src/leon2m/input/input_adc_get_offset0.c) | `FUN_a00f39c0` | Return the first of the three offset bytes that the calibration routines save and restore. | descriptive |
| [`input_adc_get_offset1`](../../src/leon2m/input/input_adc_get_offset1.c) | `FUN_a00f39ac` | Return the second of the three offset bytes that the calibration routines save and restore. | descriptive |
| [`input_adc_get_offset2`](../../src/leon2m/input/input_adc_get_offset2.c) | `FUN_a00f3998` | Return the third of the three offset bytes that the calibration routines save and restore. | descriptive |
| [`input_adc_get_phase`](../../src/leon2m/input/input_adc_get_phase.c) | `FUN_a00f3580` | Return the sampling position from the hook or from its register. | descriptive |
| [`input_adc_power_down`](../../src/leon2m/input/input_adc_power_down.c) | `FUN_a00f328c` | Write the power-down values of the analogue input stage. | descriptive |
| [`input_adc_search_gain`](../../src/leon2m/input/input_adc_search_gain.c) | `FUN_a00f3c18` | Search the gain setting with up to five probes per step and check the result. | descriptive |
| [`input_adc_search_phase`](../../src/leon2m/input/input_adc_search_phase.c) | `FUN_a00f3f64` | Step a sampling position through its range and find where the readings are smallest and largest. | descriptive |
| [`input_adc_select_reference`](../../src/leon2m/input/input_adc_select_reference.c) | `FUN_a00f31bc` | Select the reference of the analogue input stage by a selector. | descriptive |
| [`input_adc_set_bandwidth`](../../src/leon2m/input/input_adc_set_bandwidth.c) | `FUN_a00f35d0` | Write a 3-bit setting to three registers of the analogue input stage. | descriptive |
| [`input_adc_set_capture_offsets`](../../src/leon2m/input/input_adc_set_capture_offsets.c) | `FUN_a00f3a30` | Compute two limited capture offsets from the block's registers and apply them. | descriptive |
| [`input_adc_set_hook0`](../../src/leon2m/input/input_adc_set_hook0.c) | `FUN_a00f39d4` | Store entry 0 of the calibration's four-entry hook record. | descriptive |
| [`input_adc_set_hook1`](../../src/leon2m/input/input_adc_set_hook1.c) | `FUN_a00f39e0` | Store entry 1 of the calibration's four-entry hook record. | descriptive |
| [`input_adc_set_hook2`](../../src/leon2m/input/input_adc_set_hook2.c) | `FUN_a00f39ec` | Store entry 2 of the calibration's four-entry hook record. | descriptive |
| [`input_adc_set_hook3`](../../src/leon2m/input/input_adc_set_hook3.c) | `FUN_a00f39f8` | Store entry 3 of the calibration's four-entry hook record. | descriptive |
| [`input_adc_set_hooks`](../../src/leon2m/input/input_adc_set_hooks.c) | `FUN_a00f3a04` | Store the four function pointers of the calibration's hook record. | descriptive |
| [`input_adc_set_level0`](../../src/leon2m/input/input_adc_set_level0.c) | `FUN_a00f3904` | Write the first level value of the analogue input stage. | descriptive |
| [`input_adc_set_level1`](../../src/leon2m/input/input_adc_set_level1.c) | `FUN_a00f38ec` | Write the second level value of the analogue input stage. | descriptive |
| [`input_adc_set_level2`](../../src/leon2m/input/input_adc_set_level2.c) | `FUN_a00f38d4` | Write the third level value of the analogue input stage. | descriptive |
| [`input_adc_set_line_width`](../../src/leon2m/input/input_adc_set_line_width.c) | `FUN_a00f36b8` | Write the 16-bit width value and select the matching range. | descriptive |
| [`input_adc_set_offset0`](../../src/leon2m/input/input_adc_set_offset0.c) | `FUN_a00f3948` | Write the first offset value of the analogue input stage. | descriptive |
| [`input_adc_set_offset1`](../../src/leon2m/input/input_adc_set_offset1.c) | `FUN_a00f3930` | Write the second offset value of the analogue input stage. | descriptive |
| [`input_adc_set_offset2`](../../src/leon2m/input/input_adc_set_offset2.c) | `FUN_a00f3918` | Write the third offset value of the analogue input stage. | descriptive |
| [`input_adc_set_phase`](../../src/leon2m/input/input_adc_set_phase.c) | `FUN_a00f37d0` | Write the sampling position and pass it to the hook. | descriptive |
| [`input_adc_step_width_to_target`](../../src/leon2m/input/input_adc_step_width_to_target.c) | `FUN_a00f42b8` | Step a 16-bit width value towards a target in steps of 4, applying each step. | descriptive |
| [`input_adc_wait_clock_stable`](../../src/leon2m/input/input_adc_wait_clock_stable.c) | `FUN_a00f381c` | Wait until the measured clock value stays near its target for 30 ticks, at most 299 ticks. | descriptive |
| [`input_adc_write_fixed_setup`](../../src/leon2m/input/input_adc_write_fixed_setup.c) | `FUN_a00f3194` | Write two fixed values of the analogue input stage. | descriptive |
| [`input_any_port_status`](../../src/leon2m/input/input_any_port_status.c) | `FUN_a0129a24` | Return whether any of the four bits of the first port status word is set. | descriptive |
| [`input_any_port_status_second`](../../src/leon2m/input/input_any_port_status_second.c) | `FUN_a0129ab8` | Return whether any of the four bits of the second port status word is set. | descriptive |
| [`input_api_any_port_status`](../../src/leon2m/input/input_api_any_port_status.c) | `FUN_a0144114` | Return whether any bit of the first port status word is set. | descriptive |
| [`input_api_any_port_status_second`](../../src/leon2m/input/input_api_any_port_status_second.c) | `FUN_a0144268` | Return whether any bit of the second port status word is set. | descriptive |
| [`input_api_count_port_status_bits`](../../src/leon2m/input/input_api_count_port_status_bits.c) | `FUN_a014412c` | Return how many of the four bits of the first port status word are set. | descriptive |
| [`input_api_count_port_status_bits_second`](../../src/leon2m/input/input_api_count_port_status_bits_second.c) | `FUN_a0144280` | Return how many of the four bits of the second port status word are set. | descriptive |
| [`input_api_find_channel_not_sync_mode5`](../../src/leon2m/input/input_api_find_channel_not_sync_mode5.c) | `FUN_a0144414` | Return the first channel whose port does not have sync mode 5, or 0xFF. | descriptive |
| [`input_api_get_block_selector`](../../src/leon2m/input/input_api_get_block_selector.c) | `FUN_a0142fe4` | Return the 2-bit selector of an input block, or 0xFF. | descriptive |
| [`input_api_get_channel_format_code`](../../src/leon2m/input/input_api_get_channel_format_code.c) | `FUN_a01448fc` | Return the colour format code 0..0x27 of a channel's port, raised by 2 in twelve cases. | derived |
| `input_api_get_channel_format_code_jump_table` | `switchdataD_a01430a8` | Jump table 1 of the switch statements in input_api_get_channel_format_code. | proven |
| [`input_api_get_channel_port_byte5`](../../src/leon2m/input/input_api_get_channel_port_byte5.c) | `FUN_a01447bc` | Return byte 5 of the port entry of the input that a channel shows. | descriptive |
| [`input_api_get_channel_port_code`](../../src/leon2m/input/input_api_get_channel_port_code.c) | `FUN_a014448c` | Return the port code of the input that a channel shows. | derived |
| [`input_api_get_channel_status_bit`](../../src/leon2m/input/input_api_get_channel_status_bit.c) | `FUN_a0143ff0` | Return the bit of the first port status word for the port of a channel. | descriptive |
| [`input_api_get_channel_status_bit_second`](../../src/leon2m/input/input_api_get_channel_status_bit_second.c) | `FUN_a0144144` | Return the bit of the second port status word for the port of a channel. | descriptive |
| [`input_api_get_port_status_bit`](../../src/leon2m/input/input_api_get_port_status_bit.c) | `FUN_a01440ac` | Return the bit of the first port status word for a port code. | descriptive |
| [`input_api_get_port_status_bit_second`](../../src/leon2m/input/input_api_get_port_status_bit_second.c) | `FUN_a0144200` | Return the bit of the second port status word for a port code. | descriptive |
| [`input_api_get_source_class5_code`](../../src/leon2m/input/input_api_get_source_class5_code.c) | `FUN_a0143bc4` | Return 2 when the port entry of a source has class 5, else 0. | descriptive |
| [`input_api_get_timing_field`](../../src/leon2m/input/input_api_get_timing_field.c) | `FUN_a0145660` | Return one field of a channel's measured input timing. | derived |
| `input_api_get_timing_field_jump_table` | `switchdataD_a0143148` | Jump table 1 of the switch statements in input_api_get_timing_field. | proven |
| [`input_api_is_channel_port_flagged`](../../src/leon2m/input/input_api_is_channel_port_flagged.c) | `FUN_a014505c` | Return whether the port entry of a channel has its flag bit 7 set. | descriptive |
| [`input_api_is_channel_sync_mode5`](../../src/leon2m/input/input_api_is_channel_sync_mode5.c) | `FUN_a0144298` | Return whether the port of a channel has sync mode 5. | descriptive |
| [`input_api_is_channel_sync_mode_2to4`](../../src/leon2m/input/input_api_is_channel_sync_mode_2to4.c) | `FUN_a0144350` | Return whether the port of a channel has sync mode 2, 3 or 4. | descriptive |
| [`input_api_lookup_source_id_swapped`](../../src/leon2m/input/input_api_lookup_source_id_swapped.c) | `FUN_a01446e0` | Return the source id stored for a setting value in the five-entry table, swapping ids 4 and 6. | descriptive |
| [`input_api_lookup_source_key`](../../src/leon2m/input/input_api_lookup_source_key.c) | `FUN_a0144768` | Return the key stored for a value in the five-entry table at 0x1A6DA3. | descriptive |
| [`input_api_lookup_source_value`](../../src/leon2m/input/input_api_lookup_source_value.c) | `FUN_a014468c` | Return the value stored for a key in the five-entry table at 0x1A6DA3. | descriptive |
| [`input_api_menu_index_to_port_code`](../../src/leon2m/input/input_api_menu_index_to_port_code.c) | `FUN_a014464c` | Translate a menu index to the code of its input port. | descriptive |
| [`input_api_menu_index_to_source_id`](../../src/leon2m/input/input_api_menu_index_to_source_id.c) | `FUN_a014459c` | Translate a menu index 0..3 to its source id (5, 6, 0xC, 0xD) through the four-pair table. | derived |
| [`input_api_power_on_dp_port`](../../src/leon2m/input/input_api_power_on_dp_port.c) | `FUN_a014deec` | Switch on the ports of a source with code 0x71 or 0x81 and send its number as a DP receiver setting. | derived |
| [`input_api_query_channel_link_state`](../../src/leon2m/input/input_api_query_channel_link_state.c) | `FUN_a014489c` | Ask the other side for a link value when the channel's block reports code 0xB1, else 8. | descriptive |
| [`input_api_select_ports`](../../src/leon2m/input/input_api_select_ports.c) | `FUN_a01439d8` | Map the selected sources to ports and switch those ports on. | derived |
| `input_api_select_ports_jump_table` | `switchdataD_a014303c` | Jump table 1 of the switch statements in input_api_select_ports. | proven |
| `input_api_select_ports_jump_table2` | `switchdataD_a0143054` | Jump table 2 of the switch statements in input_api_select_ports. | proven |
| [`input_api_set_block_selector`](../../src/leon2m/input/input_api_set_block_selector.c) | `FUN_a0142fcc` | Write the 2-bit selector of an input block. | descriptive |
| [`input_api_set_capture_window`](../../src/leon2m/input/input_api_set_capture_window.c) | `FUN_a0149b8c` | Hand a capture window (eight 16-bit values) to a channel. | derived |
| [`input_api_set_channel_link_option`](../../src/leon2m/input/input_api_set_channel_link_option.c) | `FUN_a014931c` | Store an option per channel and send it for channels fed by port code 0x71. | descriptive |
| [`input_api_set_device_option_bit25`](../../src/leon2m/input/input_api_set_device_option_bit25.c) | `FUN_a0149018` | Wake the input ports, store device option bit 25 and save the settings record. | descriptive |
| [`input_api_set_link_option_enable`](../../src/leon2m/input/input_api_set_link_option_enable.c) | `FUN_a0149588` | Store configuration bit 23 and send each channel's link option, or 0 when it is off. | descriptive |
| [`input_api_set_port0_option_bit24`](../../src/leon2m/input/input_api_set_port0_option_bit24.c) | `FUN_a014a0d8` | Store configuration bit 24, switch on input port entry 2 and send the bit as link byte 3 of port 0. | descriptive |
| [`input_api_set_port_field_second`](../../src/leon2m/input/input_api_set_port_field_second.c) | `FUN_a014a4d8` | Store a per-port link setting (second field) and save the settings record. | descriptive |
| [`input_api_set_port_field_third`](../../src/leon2m/input/input_api_set_port_field_third.c) | `FUN_a014a588` | Store a per-port link setting (third field) and save the settings record. | descriptive |
| [`input_api_set_port_flag_row7`](../../src/leon2m/input/input_api_set_port_flag_row7.c) | `FUN_a014a654` | Store a per-port on/off setting (row byte 7) and save the settings record. | descriptive |
| [`input_api_set_port_option_bit20`](../../src/leon2m/input/input_api_set_port_option_bit20.c) | `FUN_a014df68` | Store option bit 20 and send it for the port of a source (codes 0x71/0x81). | descriptive |
| [`input_api_set_port_signal`](../../src/leon2m/input/input_api_set_port_signal.c) | `FUN_a014b4b4` | Switch the signal of all seven input slots on or off (source 0xFE); any other source sends nothing. | descriptive |
| [`input_api_set_port_version_field`](../../src/leon2m/input/input_api_set_port_version_field.c) | `FUN_a014a428` | Store a per-port link setting (first field) and save the settings record. | descriptive |
| [`input_api_source_id_to_menu_index`](../../src/leon2m/input/input_api_source_id_to_menu_index.c) | `FUN_a01445fc` | Translate a source id (5, 6, 0xC, 0xD) to its menu index 0..3 through the four-pair table. | derived |
| [`input_api_source_to_port_code`](../../src/leon2m/input/input_api_source_to_port_code.c) | `FUN_a0144574` | Convert a source id to the code of its input port. | derived |
| [`input_apply_8051_port_flags`](../../src/leon2m/input/input_apply_8051_port_flags.c) | `FUN_a002fae0` | For each of the 4 port records whose mask matches the 8051 port flags, set its channel control bit. | descriptive |
| [`input_assert_port_control_pin`](../../src/leon2m/input/input_assert_port_control_pin.c) | `FUN_a0124df8` | Drive the control pin of an input to its active level. | derived |
| [`input_block0_clear_regad_set_regaf`](../../src/leon2m/input/input_block0_clear_regad_set_regaf.c) | `FUN_a010b36c` | Clear bit 0 of register 0xAD and set bit 7 of register 0xAF of input block 0. | descriptive |
| [`input_block0_get_regad_bit0`](../../src/leon2m/input/input_block0_get_regad_bit0.c) | `FUN_a010b330` | Return bit 0 of register 0xAD of input block 0. | descriptive |
| [`input_block0_set_regad_bit0`](../../src/leon2m/input/input_block0_set_regad_bit0.c) | `FUN_a010b34c` | Set bit 0 of register 0xAD of input block 0. | descriptive |
| [`input_block0_set_regaf_bit7`](../../src/leon2m/input/input_block0_set_regaf_bit7.c) | `FUN_a010b39c` | Set bit 7 of register 0xAF of input block 0. | descriptive |
| [`input_block0_toggle_pre_frc`](../../src/leon2m/input/input_block0_toggle_pre_frc.c) | `FUN_a00f9880` | Toggle the pre-converter bit of input block 0 with a short wait in between. | proven |
| [`input_block_accumulate_samples`](../../src/leon2m/input/input_block_accumulate_samples.c) | `FUN_a00f9528` | Accumulate weighted samples of an input block into three averages. | descriptive |
| [`input_block_calc_rates`](../../src/leon2m/input/input_block_calc_rates.c) | `FUN_a0105af8` | Compute line and frame rate values of an input block as floating-point numbers. | descriptive |
| [`input_block_center_window`](../../src/leon2m/input/input_block_center_window.c) | `FUN_a00f93a0` | Compute centred offsets from the capture registers and write them. | derived |
| [`input_block_check_reg10_and_9`](../../src/leon2m/input/input_block_check_reg10_and_9.c) | `FUN_a01235b4` | Return a yes/no result from registers 0x10 and 9 of an input block. | descriptive |
| [`input_block_check_signal`](../../src/leon2m/input/input_block_check_signal.c) | `FUN_a01215e8` | Run the register checks that decide whether the signal of a block can be matched. | descriptive |
| [`input_block_clear_change_pending`](../../src/leon2m/input/input_block_clear_change_pending.c) | `FUN_a0121388` | Clear the pending change flag of a block. | derived |
| [`input_block_clear_flags_1c_1d`](../../src/leon2m/input/input_block_clear_flags_1c_1d.c) | `FUN_a0121d1c` | Write the clear masks to registers 0x1C and 0x1D of an input block. | descriptive |
| [`input_block_clear_flags_1e_1f`](../../src/leon2m/input/input_block_clear_flags_1e_1f.c) | `FUN_a0121cf4` | Write the clear masks to registers 0x1E and 0x1F of an input block. | descriptive |
| [`input_block_clear_reg5c_bit0`](../../src/leon2m/input/input_block_clear_reg5c_bit0.c) | `FUN_a00f911c` | Clear bit 0 of register 0x5C of an input block. | descriptive |
| [`input_block_clear_reg6_bit6`](../../src/leon2m/input/input_block_clear_reg6_bit6.c) | `FUN_a00f8f14` | Clear bit 6 of register 6 of an input block. | descriptive |
| [`input_block_compare_two_measurements`](../../src/leon2m/input/input_block_compare_two_measurements.c) | `FUN_a00f8f78` | Take two measurements on the capture block of a port and return whether they agree. | descriptive |
| [`input_block_detect_sync_mode`](../../src/leon2m/input/input_block_detect_sync_mode.c) | `FUN_a0120de4` | Work out the sync mode 1..5 of the signal on an input block. | derived |
| [`input_block_detect_sync_mode_auto`](../../src/leon2m/input/input_block_detect_sync_mode_auto.c) | `FUN_a01211ac` | Work out the sync mode of an input block using its own signal code. | derived |
| [`input_block_disable_scaler`](../../src/leon2m/input/input_block_disable_scaler.c) | `FUN_a00f8918` | Switch the scaling bit of an input block off. | descriptive |
| [`input_block_enable`](../../src/leon2m/input/input_block_enable.c) | `FUN_a0120998` | Switch an input block on or off. | derived |
| [`input_block_enable_pre_pattern`](../../src/leon2m/input/input_block_enable_pre_pattern.c) | `FUN_a00f913c` | Switch the built-in test pattern of an input block on or off. | proven |
| [`input_block_enable_scaler_ratio`](../../src/leon2m/input/input_block_enable_scaler_ratio.c) | `FUN_a00f88e8` | Write a ratio to register 0x99 of an input block and switch its scaling bit on. | descriptive |
| [`input_block_get_capture_hstart`](../../src/leon2m/input/input_block_get_capture_hstart.c) | `FUN_a00f8dd4` | Return the 12-bit horizontal start of an input block. | derived |
| [`input_block_get_capture_reg12`](../../src/leon2m/input/input_block_get_capture_reg12.c) | `FUN_a00f88ac` | Return 16-bit register 0x12 of an input block's capture unit. | descriptive |
| [`input_block_get_capture_vstart`](../../src/leon2m/input/input_block_get_capture_vstart.c) | `FUN_a00f8df0` | Return the 11-bit vertical start of an input block. | derived |
| [`input_block_get_config_word`](../../src/leon2m/input/input_block_get_config_word.c) | `FUN_a01215c8` | Return the first word of an input block's configuration. | descriptive |
| [`input_block_get_pixel_repeat`](../../src/leon2m/input/input_block_get_pixel_repeat.c) | `FUN_a0120bf4` | Return the factor 1, 2, 4 or 8 selected by the low bits of register 0x11. | descriptive |
| [`input_block_get_reg0c_11bit`](../../src/leon2m/input/input_block_get_reg0c_11bit.c) | `FUN_a00f88cc` | Return the 11-bit value of register 0x0C of an input block. | descriptive |
| [`input_block_get_reg6_bit6`](../../src/leon2m/input/input_block_get_reg6_bit6.c) | `FUN_a00f8f34` | Return bit 6 of register 6 of an input block's capture registers. | descriptive |
| [`input_block_get_reg8c_bit7`](../../src/leon2m/input/input_block_get_reg8c_bit7.c) | `FUN_a00f92d4` | Return bit 7 of register 0x8C of an input block. | descriptive |
| [`input_block_get_reg10_low4`](../../src/leon2m/input/input_block_get_reg10_low4.c) | `FUN_a0123574` | Return the low four bits of register 0x10 of an input block. | descriptive |
| [`input_block_get_selector`](../../src/leon2m/input/input_block_get_selector.c) | `FUN_a0100434` | Return the 2-bit selector of an input block, or 0xFF. | descriptive |
| [`input_block_get_signal_code`](../../src/leon2m/input/input_block_get_signal_code.c) | `FUN_a00fd820` | Return the signal code of an input block. | derived |
| `input_block_get_signal_code_jump_table` | `switchdataD_a00fd4d0` | Jump table 1 of the switch statements in input_block_get_signal_code. | proven |
| [`input_block_get_status_bit2`](../../src/leon2m/input/input_block_get_status_bit2.c) | `FUN_a0121258` | Return status bit 2 of an input block. | descriptive |
| [`input_block_handle_mode_change`](../../src/leon2m/input/input_block_handle_mode_change.c) | `FUN_a01213a4` | Re-detect the sync mode of a block after a change and reprogram it. | proven |
| [`input_block_is_change_pending`](../../src/leon2m/input/input_block_is_change_pending.c) | `FUN_a0121374` | Return whether a block has a pending change flag. | derived |
| [`input_block_is_interlaced`](../../src/leon2m/input/input_block_is_interlaced.c) | `FUN_a01211d4` | Return the interlace flag of the signal on an input block. | descriptive |
| [`input_block_is_regcc_zero`](../../src/leon2m/input/input_block_is_regcc_zero.c) | `FUN_a0123590` | Return whether register 0xCC of an input block reads 0. | descriptive |
| [`input_block_measure_active_area`](../../src/leon2m/input/input_block_measure_active_area.c) | `FUN_a00f40e4` | Start a measurement on an input block, wait for it and store the measured values. | derived |
| [`input_block_measure_hfreq`](../../src/leon2m/input/input_block_measure_hfreq.c) | `FUN_a0120a18` | Measure the horizontal frequency of the signal on an input block. | proven |
| [`input_block_measure_pixel_clock`](../../src/leon2m/input/input_block_measure_pixel_clock.c) | `FUN_a0120c90` | Compute the timing value of an input block that the output clock is derived from. | derived |
| [`input_block_measure_vfreq`](../../src/leon2m/input/input_block_measure_vfreq.c) | `FUN_a0120b38` | Measure the vertical frequency of the signal on an input block. | proven |
| [`input_block_power`](../../src/leon2m/input/input_block_power.c) | `FUN_a0121714` | Switch the receiver block of one input port on or off. | derived |
| [`input_block_pulse_reg2f_bit7`](../../src/leon2m/input/input_block_pulse_reg2f_bit7.c) | `FUN_a00f9910` | Set and then clear bit 7 of register 0x2F of an input block. | descriptive |
| [`input_block_read_13bit_count`](../../src/leon2m/input/input_block_read_13bit_count.c) | `FUN_a00f9354` | Return the 13-bit value held in registers 0xAC and 0x9E of an input block. | descriptive |
| [`input_block_read_reg4c_word`](../../src/leon2m/input/input_block_read_reg4c_word.c) | `FUN_a0123244` | Return the 16-bit value of registers 0x4C/0x4D of an input block, times 8. | descriptive |
| [`input_block_read_reg8f_word`](../../src/leon2m/input/input_block_read_reg8f_word.c) | `FUN_a00f9334` | Return the 16-bit register 0x8F of an input block. | descriptive |
| [`input_block_read_reg22`](../../src/leon2m/input/input_block_read_reg22.c) | `FUN_a0120c58` | Read register 0x22 of an input block. | descriptive |
| [`input_block_read_reg23`](../../src/leon2m/input/input_block_read_reg23.c) | `FUN_a0120c74` | Read register 0x23 of an input block. | descriptive |
| [`input_block_read_reg40_word`](../../src/leon2m/input/input_block_read_reg40_word.c) | `FUN_a01231e4` | Return the 16-bit value of registers 0x40/0x41 of an input block. | descriptive |
| [`input_block_read_reg43`](../../src/leon2m/input/input_block_read_reg43.c) | `FUN_a00f6340` | Read register 0x43 of an input block. | descriptive |
| [`input_block_read_reg44`](../../src/leon2m/input/input_block_read_reg44.c) | `FUN_a00f635c` | Read register 0x44 of an input block. | descriptive |
| [`input_block_read_reg44_word`](../../src/leon2m/input/input_block_read_reg44_word.c) | `FUN_a01232a4` | Return the 16-bit value of registers 0x44/0x45 of an input block. | descriptive |
| [`input_block_read_reg45`](../../src/leon2m/input/input_block_read_reg45.c) | `FUN_a00f6378` | Read register 0x45 of an input block. | descriptive |
| [`input_block_read_reg48_word`](../../src/leon2m/input/input_block_read_reg48_word.c) | `FUN_a0123184` | Return the 16-bit value of registers 0x48/0x49 of an input block, times 8. | descriptive |
| [`input_block_read_reg95_word`](../../src/leon2m/input/input_block_read_reg95_word.c) | `FUN_a00f92f4` | Return the 16-bit register 0x95 of an input block. | descriptive |
| [`input_block_read_reg97_word`](../../src/leon2m/input/input_block_read_reg97_word.c) | `FUN_a00f9314` | Return the 16-bit register 0x97 of an input block. | descriptive |
| [`input_block_reset_window_regs`](../../src/leon2m/input/input_block_reset_window_regs.c) | `FUN_a0121e3c` | Reset an input block's window registers when the low nibble of its capture register 4 is above 1. | descriptive |
| [`input_block_restart_statistics`](../../src/leon2m/input/input_block_restart_statistics.c) | `FUN_a00f62ac` | Restart the statistics measurement of an input block. | descriptive |
| [`input_block_set_capture_reg0e`](../../src/leon2m/input/input_block_set_capture_reg0e.c) | `FUN_a00f8e44` | Write register 0x0E of an input block's capture unit: the stored block offset plus the value. | descriptive |
| [`input_block_set_capture_reg12`](../../src/leon2m/input/input_block_set_capture_reg12.c) | `FUN_a00f8e0c` | Write 16-bit register 0x12 of an input block's capture unit. | descriptive |
| [`input_block_set_capture_start`](../../src/leon2m/input/input_block_set_capture_start.c) | `FUN_a00f8938` | Write the horizontal start (made even) and the vertical start of an input block. | descriptive |
| [`input_block_set_change_pending`](../../src/leon2m/input/input_block_set_change_pending.c) | `FUN_a01216f8` | Set the pending change flag of a block. | derived |
| [`input_block_set_config`](../../src/leon2m/input/input_block_set_config.c) | `FUN_a01207f4` | Store the 12-byte configuration of an input block. | derived |
| [`input_block_set_offset`](../../src/leon2m/input/input_block_set_offset.c) | `FUN_a00f8e2c` | Store the per-block offset. | descriptive |
| [`input_block_set_reg3_bit2`](../../src/leon2m/input/input_block_set_reg3_bit2.c) | `FUN_a0123304` | Set or clear bit 2 of register 3 of an input block. | descriptive |
| [`input_block_set_reg5_mode`](../../src/leon2m/input/input_block_set_reg5_mode.c) | `FUN_a00fe820` | Switch register 5 of input block 6 or 7 between its two modes. | descriptive |
| [`input_block_set_reg5c_bit0`](../../src/leon2m/input/input_block_set_reg5c_bit0.c) | `FUN_a00f90fc` | Set bit 0 of register 0x5C of an input block. | descriptive |
| [`input_block_set_reg5c_bit2`](../../src/leon2m/input/input_block_set_reg5c_bit2.c) | `FUN_a00f8f58` | Write bit 2 of register 0x5C of an input block. | descriptive |
| [`input_block_set_reg6_bit6`](../../src/leon2m/input/input_block_set_reg6_bit6.c) | `FUN_a00f8ef4` | Set bit 6 of register 6 of an input block. | descriptive |
| [`input_block_set_reg9c_bit2`](../../src/leon2m/input/input_block_set_reg9c_bit2.c) | `FUN_a0123344` | Set or clear bit 2 of register 0x9C of an input block. | descriptive |
| [`input_block_set_reg40_bit0`](../../src/leon2m/input/input_block_set_reg40_bit0.c) | `FUN_a0121b50` | Set or clear bit 0 of register 0x40 of an input block. | descriptive |
| [`input_block_set_reg40_field`](../../src/leon2m/input/input_block_set_reg40_field.c) | `FUN_a0121b98` | Write register 0x40 of an input block as (old bit 0) \| value << 1; all other bits end up 0. | descriptive |
| [`input_block_set_reg41_quarter`](../../src/leon2m/input/input_block_set_reg41_quarter.c) | `FUN_a00f8cc4` | Write a quarter of a value to register 0x41 of an input block. | descriptive |
| [`input_block_set_regab_bit2`](../../src/leon2m/input/input_block_set_regab_bit2.c) | `FUN_a0100468` | Set or clear bit 2 of register 0xAB of an input block for codes 0xE1 and 0xE2. | descriptive |
| [`input_block_set_selector`](../../src/leon2m/input/input_block_set_selector.c) | `FUN_a01003b4` | Write the 2-bit selector of an input block when the block is active. | descriptive |
| [`input_block_set_size_pair`](../../src/leon2m/input/input_block_set_size_pair.c) | `FUN_a00f8ce4` | Write two 16-bit sizes into registers 0x60..0x6C of a block, optionally halved and swapped. | descriptive |
| `input_block_set_size_pair_jump_table` | `switchdataD_a00f87bc` | Jump table 1 of the switch statements in input_block_set_size_pair. | proven |
| [`input_block_set_sync_source`](../../src/leon2m/input/input_block_set_sync_source.c) | `FUN_a012127c` | Select the sync source bits of an input block. | descriptive |
| [`input_block_set_sync_thresholds`](../../src/leon2m/input/input_block_set_sync_thresholds.c) | `FUN_a0120848` | Write the two threshold fields of an input block. | descriptive |
| [`input_block_setup_capture`](../../src/leon2m/input/input_block_setup_capture.c) | `FUN_a00f896c` | Set an input block up for its signal type and capture size. | derived |
| [`input_block_setup_capture_quarter`](../../src/leon2m/input/input_block_setup_capture_quarter.c) | `FUN_a00f8a98` | Set an input block up with sizes in units of 4, retrying on block 1 until it is stable. | derived |
| [`input_block_wait_measure_cycle`](../../src/leon2m/input/input_block_wait_measure_cycle.c) | `FUN_a0121c6c` | Wait until the busy bit of an input block has been set and cleared again. | derived |
| [`input_block_write_reg1a`](../../src/leon2m/input/input_block_write_reg1a.c) | `FUN_a012082c` | Write register 0x1A of an input block. | descriptive |
| [`input_block_write_reg9d`](../../src/leon2m/input/input_block_write_reg9d.c) | `FUN_a00f98f4` | Write register 0x9D of an input block. | descriptive |
| [`input_blocks_init`](../../src/leon2m/input/input_blocks_init.c) | `FUN_a01218c8` | Set up block 8 and the eight input blocks and register their interrupt handler. | proven |
| [`input_bring_up_check_free_run`](../../src/leon2m/input/input_bring_up_check_free_run.c) | `FUN_a00f04f8` | Run the free-run calibration check of a port. | proven |
| [`input_bring_up_clear_counters`](../../src/leon2m/input/input_bring_up_clear_counters.c) | `FUN_a00f1150` | Clear the bring-up counters of port pair 2/6 or 3/7. | descriptive |
| [`input_bring_up_get_done_flag`](../../src/leon2m/input/input_bring_up_get_done_flag.c) | `FUN_a00f1100` | Return the bring-up done flag of ports 2 / 6 or ports 3 / 7; 0 for any other port. | derived |
| [`input_bring_up_lock_port`](../../src/leon2m/input/input_bring_up_lock_port.c) | `FUN_a00f0b58` | Bring a port's clock up with retries, then start the free-run check. | proven |
| [`input_bring_up_select_port`](../../src/leon2m/input/input_bring_up_select_port.c) | `FUN_a00ef048` | Select a port for bring-up and set its registers up. | derived |
| `input_bring_up_select_port_jump_table` | `switchdataD_a00eef5c` | Jump table 1 of the switch statements in input_bring_up_select_port. | proven |
| [`input_bring_up_set_pixel_clock`](../../src/leon2m/input/input_bring_up_set_pixel_clock.c) | `FUN_a00ef1b0` | Compute the pixel clock for the incoming timing and program it. | proven |
| [`input_bring_up_step_reg51`](../../src/leon2m/input/input_bring_up_step_reg51.c) | `FUN_a00f0380` | Step register 0x51 of a picture block up or down by flag bits. | descriptive |
| [`input_capture_read8`](../../src/leon2m/input/input_capture_read8.c) | `FUN_a00f1a90` | Read an 8-bit register of an input capture block. | proven |
| [`input_capture_read16`](../../src/leon2m/input/input_capture_read16.c) | `FUN_a00f1ce4` | Read a 16-bit register pair of an input capture block. | proven |
| [`input_capture_update_bits`](../../src/leon2m/input/input_capture_update_bits.c) | `FUN_a00f1b5c` | Set or clear bits of a register of one input capture block, or of all eight. | proven |
| [`input_capture_write8`](../../src/leon2m/input/input_capture_write8.c) | `FUN_a00f1ad4` | Write an 8-bit register of one input capture block, or of all eight. | proven |
| [`input_capture_write16`](../../src/leon2m/input/input_capture_write16.c) | `FUN_a00f1d48` | Write a 16-bit register pair of one input capture block, or of all eight. | proven |
| [`input_channel_bring_up_task`](../../src/leon2m/input/input_channel_bring_up_task.c) | `FUN_a013dc6c` | Run the state machine that brings a channel up when its input gets a signal. | proven |
| `input_channel_bring_up_task_jump_table` | `switchdataD_a013c8bc` | Jump table 1 of the switch statements in input_channel_bring_up_task. | proven |
| `input_channel_bring_up_task_jump_table2` | `switchdataD_a013c8dc` | Jump table 2 of the switch statements in input_channel_bring_up_task. | proven |
| [`input_check_ch1_size_order`](../../src/leon2m/input/input_check_ch1_size_order.c) | `FUN_a00844f8` | Return 1 when channel 1's port code is 0x0D and its first measured size is not above the second. | descriptive |
| [`input_count_port_status_bits`](../../src/leon2m/input/input_count_port_status_bits.c) | `FUN_a0129a5c` | Return how many of the four bits of the first port status word are set. | descriptive |
| [`input_count_port_status_bits_second`](../../src/leon2m/input/input_count_port_status_bits_second.c) | `FUN_a0129af0` | Return how many of the four bits of the second port status word are set. | descriptive |
| [`input_csc_is_format_group_0`](../../src/leon2m/input/input_csc_is_format_group_0.c) | `FUN_a010128c` | Return whether a colour format code is 0 or 1. | descriptive |
| [`input_csc_is_format_group_1`](../../src/leon2m/input/input_csc_is_format_group_1.c) | `FUN_a01011c0` | Return whether a colour format code belongs to the second group. | descriptive |
| [`input_csc_is_format_group_2`](../../src/leon2m/input/input_csc_is_format_group_2.c) | `FUN_a01010f4` | Return whether a colour format code belongs to the third group. | descriptive |
| [`input_csc_is_format_group_3`](../../src/leon2m/input/input_csc_is_format_group_3.c) | `FUN_a0101028` | Return whether a colour format code belongs to the fourth group. | descriptive |
| [`input_csc_map_format_code`](../../src/leon2m/input/input_csc_map_format_code.c) | `FUN_a0100990` | Map the stored format byte through a table of 42 cases. | descriptive |
| `input_csc_map_format_code_jump_table` | `switchdataD_a0100584` | Jump table 1 of the switch statements in input_csc_map_format_code. | proven |
| [`input_csc_set_format_code`](../../src/leon2m/input/input_csc_set_format_code.c) | `FUN_a0100e6c` | Set the colour format code from a selector and a signal code. | descriptive |
| [`input_csc_set_option_byte`](../../src/leon2m/input/input_csc_set_option_byte.c) | `FUN_a01006d8` | Store an option byte of the colour format handling. | descriptive |
| [`input_csc_setup`](../../src/leon2m/input/input_csc_setup.c) | `FUN_a01012a8` | Work out the colour format of a port and program the conversion for it. | derived |
| [`input_csc_setup_with_selector`](../../src/leon2m/input/input_csc_setup_with_selector.c) | `FUN_a01016a4` | Store the selector and run the colour format set-up. | derived |
| [`input_csc_write_mode_regs`](../../src/leon2m/input/input_csc_write_mode_regs.c) | `FUN_a0100a40` | Write block registers 0x19 and 0x1A for the current colour format. | descriptive |
| `input_csc_write_mode_regs_jump_table` | `switchdataD_a010062c` | Jump table 1 of the switch statements in input_csc_write_mode_regs. | proven |
| [`input_csc_write_range_values`](../../src/leon2m/input/input_csc_write_range_values.c) | `FUN_a01006e4` | Write the value record for the current colour format to a block. | descriptive |
| `input_csc_write_range_values_jump_table` | `switchdataD_a01004e4` | Jump table 1 of the switch statements in input_csc_write_range_values. | proven |
| [`input_enable_four_port_items`](../../src/leon2m/input/input_enable_four_port_items.c) | `FUN_a0083adc` | Enable the port items 5, 6, 12 and 13 through the port item setter. | descriptive |
| [`input_entry_index_to_port_code`](../../src/leon2m/input/input_entry_index_to_port_code.c) | `FUN_a01421c4` | Convert a port entry index to its port code. | derived |
| `input_entry_index_to_port_code_jump_table` | `switchdataD_a0141af4` | Jump table 1 of the switch statements in input_entry_index_to_port_code. | proven |
| [`input_fill_port_timing`](../../src/leon2m/input/input_fill_port_timing.c) | `FUN_a014285c` | Fill a port's timing record from the measurement hardware. | derived |
| [`input_find_mode_row_by_id`](../../src/leon2m/input/input_find_mode_row_by_id.c) | `FUN_a013ffb0` | Return the index of the mode-table row with a given id. | derived |
| [`input_find_next_mode_row`](../../src/leon2m/input/input_find_next_mode_row.c) | `FUN_a013faa0` | Return the next mode-table row of the same group as the port's current mode. | descriptive |
| [`input_find_port_entry_by_bus_id`](../../src/leon2m/input/input_find_port_entry_by_bus_id.c) | `FUN_a0142218` | Return the index of the port entry with the given bus id. | derived |
| [`input_find_slot_by_port_code`](../../src/leon2m/input/input_find_slot_by_port_code.c) | `FUN_a014e478` | Return the index 0..7 of the input slot whose port code matches, or 8. | descriptive |
| [`input_find_source_code_index`](../../src/leon2m/input/input_find_source_code_index.c) | `FUN_a012f2dc` | Return the index of a code in the four-entry source code table. | descriptive |
| [`input_format_read8`](../../src/leon2m/input/input_format_read8.c) | `FUN_a00f1e0c` | Read an 8-bit register of an input format block. | derived |
| [`input_format_write8`](../../src/leon2m/input/input_format_write8.c) | `FUN_a00f1e50` | Write an 8-bit register of one input format block, or of all eight. | derived |
| [`input_format_write16`](../../src/leon2m/input/input_format_write16.c) | `FUN_a00f1ed8` | Write a 16-bit register pair of one input format block, or of all eight. | derived |
| [`input_get_channel_block_selector`](../../src/leon2m/input/input_get_channel_block_selector.c) | `FUN_a013291c` | Return the 2-bit selector of the input block that a channel uses. | descriptive |
| [`input_get_const_375`](../../src/leon2m/input/input_get_const_375.c) | `FUN_a00f9390` | Return the constant 375. | descriptive |
| [`input_get_const_500`](../../src/leon2m/input/input_get_const_500.c) | `FUN_a00f9398` | Return the constant 500. | descriptive |
| [`input_get_internal_path1_source`](../../src/leon2m/input/input_get_internal_path1_source.c) | `FUN_a00fe184` | Return the source 1..3 selected for internal signal path 1. | derived |
| [`input_get_internal_path2_source`](../../src/leon2m/input/input_get_internal_path2_source.c) | `FUN_a00fe3ec` | Return the source 1..3 selected for internal signal path 2. | derived |
| [`input_get_key_table_entry`](../../src/leon2m/input/input_get_key_table_entry.c) | `FUN_a012629c` | Fetch the key table entry for the lowest set bit of a mask that is the constant 1: always entry 0. | descriptive |
| [`input_get_mode_row_field_a`](../../src/leon2m/input/input_get_mode_row_field_a.c) | `FUN_a0140034` | Return the 16-bit field at +0x0A of a mode-table row. | descriptive |
| [`input_get_port_bus_id`](../../src/leon2m/input/input_get_port_bus_id.c) | `FUN_a014af84` | Return the bus id of the input port that belongs to a source code. | descriptive |
| [`input_get_port_changed_flag`](../../src/leon2m/input/input_get_port_changed_flag.c) | `FUN_a012b3f0` | Return the changed flag of a port. | descriptive |
| [`input_get_port_class`](../../src/leon2m/input/input_get_port_class.c) | `FUN_a0141ce0` | Return the class field of the port entry for a port code. | descriptive |
| [`input_get_port_entry_byte5`](../../src/leon2m/input/input_get_port_entry_byte5.c) | `FUN_a0141e74` | Return byte 5 of the port entry for a port code. | descriptive |
| [`input_get_port_entry_field_e`](../../src/leon2m/input/input_get_port_entry_field_e.c) | `FUN_a0141e0c` | Return the 16-bit field at +0x0E of the port entry for a port code. | descriptive |
| [`input_get_port_entry_word_e`](../../src/leon2m/input/input_get_port_entry_word_e.c) | `FUN_a012b370` | Return the 16-bit field at +0x0E of a port entry. | descriptive |
| [`input_get_port_link_byte3`](../../src/leon2m/input/input_get_port_link_byte3.c) | `FUN_a012b354` | Return byte 3 of a port's link row. | descriptive |
| [`input_get_port_mask_bit`](../../src/leon2m/input/input_get_port_mask_bit.c) | `FUN_a0140098` | Return the bit of a port in the port mask at 0xA802CBD4. | descriptive |
| [`input_get_port_mask_bit_alt`](../../src/leon2m/input/input_get_port_mask_bit_alt.c) | `FUN_a01400bc` | Return the bit of a port in the port mask at 0xA802CBD3. | descriptive |
| [`input_get_port_status_bit`](../../src/leon2m/input/input_get_port_status_bit.c) | `FUN_a0129a10` | Return one bit of the first port status word. | descriptive |
| [`input_get_port_status_bit_second`](../../src/leon2m/input/input_get_port_status_bit_second.c) | `FUN_a0129aa4` | Return one bit of the second port status word. | descriptive |
| [`input_get_port_status_word`](../../src/leon2m/input/input_get_port_status_word.c) | `FUN_a0129b38` | Return the first port status word. | descriptive |
| [`input_get_port_sync_mode`](../../src/leon2m/input/input_get_port_sync_mode.c) | `FUN_a0142e8c` | Return byte +9 of a port record: the sync mode (1 = none recognised, 2..5) of the port. | derived |
| [`input_get_route_selector`](../../src/leon2m/input/input_get_route_selector.c) | `FUN_a00fe7d8` | Return the 2-bit route selector, or 3 when the route is off. | descriptive |
| [`input_get_routed_port_pair`](../../src/leon2m/input/input_get_routed_port_pair.c) | `FUN_a00fe6c8` | Return which pair of port codes the routing bits select. | descriptive |
| [`input_init_port_link_row`](../../src/leon2m/input/input_init_port_link_row.c) | `FUN_a012b458` | Fill a port's link row from the saved settings and send it to the input processor. | derived |
| [`input_is_mode_id_listed`](../../src/leon2m/input/input_is_mode_id_listed.c) | `FUN_a013b92c` | Return whether a port's mode id is one of fourteen listed values. | descriptive |
| [`input_is_port_cable_present`](../../src/leon2m/input/input_is_port_cable_present.c) | `FUN_a0124bf4` | Return whether a cable is detected on an input. | derived |
| [`input_is_port_code_scalable`](../../src/leon2m/input/input_is_port_code_scalable.c) | `FUN_a0121d4c` | Return 0 when a port's signal code is one of thirteen listed codes, else 1. | descriptive |
| [`input_is_port_control_pin_active`](../../src/leon2m/input/input_is_port_control_pin_active.c) | `FUN_a0124e44` | Return whether the control pin of an input reads its active level. | derived |
| [`input_is_port_detect_pin_active`](../../src/leon2m/input/input_is_port_detect_pin_active.c) | `FUN_a0124d24` | Return whether the detect pin of an input reads its active level. | derived |
| [`input_is_port_used`](../../src/leon2m/input/input_is_port_used.c) | `FUN_a0080320` | Return 1 when port c (0..3) is in use for the current port layout byte. | derived |
| [`input_is_receiver_index_0_or_1`](../../src/leon2m/input/input_is_receiver_index_0_or_1.c) | `FUN_a01422f4` | Return whether a value is 0 or 1. | descriptive |
| [`input_is_receiver_index_2_or_3`](../../src/leon2m/input/input_is_receiver_index_2_or_3.c) | `FUN_a0142360` | Return whether a value is 2 or 3. | descriptive |
| [`input_is_refresh_rate_high`](../../src/leon2m/input/input_is_refresh_rate_high.c) | `FUN_a013bb50` | Return 1 when the refresh rate in a port's channel record passes its limit (300.0 or 245.1 Hz). | derived |
| [`input_is_sample_rate_too_high`](../../src/leon2m/input/input_is_sample_rate_too_high.c) | `FUN_a00f4434` | Return whether the line rate times a value exceeds 2,050,000. | descriptive |
| [`input_is_timing_out_of_range`](../../src/leon2m/input/input_is_timing_out_of_range.c) | `FUN_a013ba14` | Return 1 when a port's line rate or refresh rate is outside the accepted range. | derived |
| [`input_is_timing_supported`](../../src/leon2m/input/input_is_timing_supported.c) | `FUN_a0105d58` | Look a width, height and rate up in the table of supported timings and print the result. | proven |
| [`input_load_block_source_registers`](../../src/leon2m/input/input_load_block_source_registers.c) | `FUN_a00fd9a0` | Load the block registers for an input class from the ROM register table. | derived |
| [`input_load_mode_row`](../../src/leon2m/input/input_load_mode_row.c) | `FUN_a013f284` | Copy a row of the ROM mode table into a port's timing record. | derived |
| [`input_load_port_template`](../../src/leon2m/input/input_load_port_template.c) | `FUN_a0136d20` | Copy the port template received from the input processor into a port entry. | derived |
| [`input_map_mode_4_to_5`](../../src/leon2m/input/input_map_mode_4_to_5.c) | `FUN_a0121ed0` | Map the values 1, 2, 3, 4 to 1, 2, 3, 5. | descriptive |
| [`input_match_port_mode`](../../src/leon2m/input/input_match_port_mode.c) | `FUN_a013f370` | Match a port's measured timing against the known modes and store the result. | derived |
| [`input_measure_picture_size`](../../src/leon2m/input/input_measure_picture_size.c) | `FUN_a014e4b8` | Measure the incoming picture and report whether its two size results reach 300 and 200. | derived |
| [`input_measure_read8`](../../src/leon2m/input/input_measure_read8.c) | `FUN_a00f1f9c` | Read an 8-bit register of an input measurement block. | proven |
| [`input_measure_read16`](../../src/leon2m/input/input_measure_read16.c) | `FUN_a00f21f0` | Read a 16-bit register pair of an input measurement block. | proven |
| [`input_measure_update_bits`](../../src/leon2m/input/input_measure_update_bits.c) | `FUN_a00f2068` | Set or clear bits of a register of an input measurement block. | proven |
| [`input_measure_write8`](../../src/leon2m/input/input_measure_write8.c) | `FUN_a00f1fe0` | Write an 8-bit register of one input measurement block, or of all eight. | proven |
| [`input_mode_list_has_entry`](../../src/leon2m/input/input_mode_list_has_entry.c) | `FUN_a013f224` | Return whether the short mode list holds an entry {0xC, k}. | descriptive |
| [`input_next_source_code_same_group`](../../src/leon2m/input/input_next_source_code_same_group.c) | `FUN_a012f31c` | Return the next entry of the source code table that belongs to the same group. | descriptive |
| [`input_pack_four_2bit_fields`](../../src/leon2m/input/input_pack_four_2bit_fields.c) | `FUN_a012ad80` | Pack four 2-bit values into one byte. | descriptive |
| [`input_pack_four_flags`](../../src/leon2m/input/input_pack_four_flags.c) | `FUN_a012adac` | Pack four flags into the low four bits of a byte. | descriptive |
| [`input_port_code_to_receiver_index`](../../src/leon2m/input/input_port_code_to_receiver_index.c) | `FUN_a014226c` | Convert a port code to the index of its receiver. | descriptive |
| [`input_port_entry_get_flag_bit6`](../../src/leon2m/input/input_port_entry_get_flag_bit6.c) | `FUN_a0142140` | Return flag bit 6 of the first halfword of a port entry. | descriptive |
| [`input_port_entry_get_flag_bit6_hi`](../../src/leon2m/input/input_port_entry_get_flag_bit6_hi.c) | `FUN_a01420e4` | Return flag bit 6 of the second halfword of a port entry. | descriptive |
| [`input_port_entry_get_flag_bit7`](../../src/leon2m/input/input_port_entry_get_flag_bit7.c) | `FUN_a014230c` | Return flag bit 7 of the second halfword of port entry 0 or 1. | descriptive |
| [`input_port_entry_is_class5`](../../src/leon2m/input/input_port_entry_is_class5.c) | `FUN_a0142110` | Return whether the class field of a port entry is 5. | descriptive |
| [`input_port_get_status_bit7`](../../src/leon2m/input/input_port_get_status_bit7.c) | `FUN_a013f204` | Return status bit 7 of a port record. | descriptive |
| [`input_port_get_status_bit8`](../../src/leon2m/input/input_port_get_status_bit8.c) | `FUN_a0140078` | Return status bit 8 of a port record. | descriptive |
| [`input_port_get_status_bit9`](../../src/leon2m/input/input_port_get_status_bit9.c) | `FUN_a0140058` | Return status bit 9 of a port record. | descriptive |
| [`input_port_get_status_bit10`](../../src/leon2m/input/input_port_get_status_bit10.c) | `FUN_a013f1e4` | Return status bit 10 of a port record. | descriptive |
| [`input_port_id_to_entry_index`](../../src/leon2m/input/input_port_id_to_entry_index.c) | `FUN_a0142168` | Convert a port id to its index in the port entry table. | derived |
| [`input_port_is_av_muted`](../../src/leon2m/input/input_port_is_av_muted.c) | `FUN_a0132964` | Return the AV mute flag (bit 6) of the port entry behind an input's signal code 0x51 or 0x61. | derived |
| [`input_port_list_append`](../../src/leon2m/input/input_port_list_append.c) | `FUN_a0152a20` | Append one 3-byte port record to the list unless it is already present. | descriptive |
| [`input_port_list_build`](../../src/leon2m/input/input_port_list_build.c) | `FUN_a0152e28` | Build the port record list for the current configuration and return its size. | descriptive |
| `input_port_list_build_jump_table` | `switchdataD_a015126c` | Jump table 1 of the switch statements in input_port_list_build. | proven |
| [`input_port_sync_task`](../../src/leon2m/input/input_port_sync_task.c) | `FUN_a0142910` | Run the per-port sync state machine and update the port status. | proven |
| [`input_port_table_find_code`](../../src/leon2m/input/input_port_table_find_code.c) | `FUN_a0125198` | Return the index of the input with a given port code. | derived |
| [`input_port_table_find_flagged_type2`](../../src/leon2m/input/input_port_table_find_flagged_type2.c) | `FUN_a01250c4` | Return the first type 2 input whose flag bit 0x400 is set in the port table. | descriptive |
| [`input_port_table_get_bus_id`](../../src/leon2m/input/input_port_table_get_bus_id.c) | `FUN_a0125124` | Return the bus id of an input's entry in the port table. | derived |
| [`input_port_table_get_byte11`](../../src/leon2m/input/input_port_table_get_byte11.c) | `FUN_a01252c4` | Return byte +0x11 of an input's entry in the port table. | descriptive |
| [`input_port_table_get_code`](../../src/leon2m/input/input_port_table_get_code.c) | `FUN_a0125140` | Return the port code of an input index. | derived |
| [`input_port_table_get_control_mask`](../../src/leon2m/input/input_port_table_get_control_mask.c) | `FUN_a0125334` | Return the pin mask of the control pin of an input's entry in the port table. | descriptive |
| [`input_port_table_get_control_port`](../../src/leon2m/input/input_port_table_get_control_port.c) | `FUN_a0125318` | Return the GPIO port of the control pin of an input's entry in the port table. | descriptive |
| [`input_port_table_get_detect_level`](../../src/leon2m/input/input_port_table_get_detect_level.c) | `FUN_a0125628` | Return the active level of the detect pin of an input's entry in the port table. | descriptive |
| [`input_port_table_get_detect_mask`](../../src/leon2m/input/input_port_table_get_detect_mask.c) | `FUN_a01252fc` | Return the pin mask of the detect pin of an input's entry in the port table. | descriptive |
| [`input_port_table_get_detect_mask_alt`](../../src/leon2m/input/input_port_table_get_detect_mask_alt.c) | `FUN_a012560c` | Return the pin mask of the detect pin of an input's entry in the port table. | descriptive |
| [`input_port_table_get_detect_port`](../../src/leon2m/input/input_port_table_get_detect_port.c) | `FUN_a01252e0` | Return the GPIO port of the detect pin of an input's entry in the port table. | descriptive |
| [`input_port_table_get_detect_port_alt`](../../src/leon2m/input/input_port_table_get_detect_port_alt.c) | `FUN_a01255f0` | Return the GPIO port of the detect pin of an input's entry in the port table. | descriptive |
| [`input_port_table_get_link_bytes`](../../src/leon2m/input/input_port_table_get_link_bytes.c) | `FUN_a0124b88` | Copy bytes +0x12..+0x15 of an input's port table entry to a buffer. | descriptive |
| [`input_port_table_get_type`](../../src/leon2m/input/input_port_table_get_type.c) | `FUN_a01250a8` | Return the type byte of an input's entry in the port table. | descriptive |
| [`input_port_table_get_type1_byte12`](../../src/leon2m/input/input_port_table_get_type1_byte12.c) | `FUN_a0125264` | Return byte +0x12 of a type 1 input's entry, else 0x0F. | descriptive |
| [`input_port_table_get_type2_byte12`](../../src/leon2m/input/input_port_table_get_type2_byte12.c) | `FUN_a0125294` | Return byte +0x12 of a type 2 input's entry, else a default. | descriptive |
| [`input_port_timer_start`](../../src/leon2m/input/input_port_timer_start.c) | `FUN_a013b754` | Update the nine port timers and start one of them with a time value. | proven |
| [`input_port_timers_update`](../../src/leon2m/input/input_port_timers_update.c) | `FUN_a013b7e0` | Count the nine port timers down by the ticks that have passed. | proven |
| [`input_power_on_ports_by_mask`](../../src/leon2m/input/input_power_on_ports_by_mask.c) | `FUN_a0151aa4` | Switch on the input ports selected by a mask and start their timers. | derived |
| [`input_query_port_timing`](../../src/leon2m/input/input_query_port_timing.c) | `FUN_a013dbcc` | Fetch the 16-byte measured timing report of the input behind a block (signal codes 0x51..0x81). | derived |
| [`input_read_keys_debounced`](../../src/leon2m/input/input_read_keys_debounced.c) | `FUN_a012621c` | Scan the keys until the same code has been seen for 50 ticks and return it. | proven |
| [`input_rearm_port_event`](../../src/leon2m/input/input_rearm_port_event.c) | `FUN_a00808ac` | Reset the last-state byte of port n (4 = all) and optionally force its pending event. | derived |
| [`input_refresh_port_entries`](../../src/leon2m/input/input_refresh_port_entries.c) | `FUN_a002f550` | Reload the four port entries from the Leon2S templates and fix their type and HDCP bits. | derived |
| [`input_release_port_control_pin`](../../src/leon2m/input/input_release_port_control_pin.c) | `FUN_a0124da4` | Drive the control pin of an input to its inactive level. | derived |
| [`input_report_present_ports`](../../src/leon2m/input/input_report_present_ports.c) | `FUN_a01298d8` | Build the mask of inputs that are present and report it to the input processor. | derived |
| [`input_reroute_shared_block`](../../src/leon2m/input/input_reroute_shared_block.c) | `FUN_a00fde94` | Move the shared route to another free input block when it points at a given block. | descriptive |
| [`input_resend_link_bytes_on_pin_change`](../../src/leon2m/input/input_resend_link_bytes_on_pin_change.c) | `FUN_a0124244` | When GPIO port 2 bit 0 or bit 3 changed, write link row bytes 8, 0xA, 0xB of port 0 or 1 again. | descriptive |
| [`input_scan_keys`](../../src/leon2m/input/input_scan_keys.c) | `FUN_a0125e60` | Scan the control keys once and return the key code. | proven |
| [`input_select_block_source`](../../src/leon2m/input/input_select_block_source.c) | `FUN_a00fd594` | Set a picture block's mode code and route bits for a source class. | derived |
| [`input_select_mode_row_by_id`](../../src/leon2m/input/input_select_mode_row_by_id.c) | `FUN_a013fe2c` | Switch a port to the mode-table row with a given id and store it. | descriptive |
| [`input_select_next_mode_row`](../../src/leon2m/input/input_select_next_mode_row.c) | `FUN_a013fbe8` | Switch a port to the next mode-table row of the same group and store it. | descriptive |
| [`input_set_all_ports_class_1`](../../src/leon2m/input/input_set_all_ports_class_1.c) | `FUN_a0141c98` | Set the class field of all seven port entries to 1. | descriptive |
| [`input_set_bring_up_limits`](../../src/leon2m/input/input_set_bring_up_limits.c) | `FUN_a00ef034` | Store two limit values of the bring-up code. | descriptive |
| [`input_set_bring_up_port`](../../src/leon2m/input/input_set_bring_up_port.c) | `FUN_a00eef7c` | Store the port that is being brought up and set its hardware select bit. | descriptive |
| `input_set_bring_up_port_jump_table` | `switchdataD_a00eef3c` | Jump table 1 of the switch statements in input_set_bring_up_port. | proven |
| [`input_set_channel_block_selector`](../../src/leon2m/input/input_set_channel_block_selector.c) | `FUN_a01328d4` | Write the 2-bit selector of the input block that a channel uses. | descriptive |
| [`input_set_main_ports_class_2`](../../src/leon2m/input/input_set_main_ports_class_2.c) | `FUN_a0141b10` | Set the class field of the four main port entries to 2. | descriptive |
| [`input_set_main_ports_class_6`](../../src/leon2m/input/input_set_main_ports_class_6.c) | `FUN_a0141c48` | Set the class field of the four main port entries to 6. | descriptive |
| [`input_set_pending_source`](../../src/leon2m/input/input_set_pending_source.c) | `FUN_a00fd980` | Store a non-zero source code as pending. | descriptive |
| [`input_set_pin_config_byte0`](../../src/leon2m/input/input_set_pin_config_byte0.c) | `FUN_a0107a14` | Store pin configuration byte 0. | descriptive |
| [`input_set_pin_config_byte2`](../../src/leon2m/input/input_set_pin_config_byte2.c) | `FUN_a0107a08` | Store pin configuration byte 2. | descriptive |
| [`input_set_pin_config_bytes`](../../src/leon2m/input/input_set_pin_config_bytes.c) | `FUN_a01079c0` | Store the five pin configuration bytes. | descriptive |
| [`input_set_pin_config_bytes_3_4`](../../src/leon2m/input/input_set_pin_config_bytes_3_4.c) | `FUN_a01079f4` | Store pin configuration bytes 3 and 4. | descriptive |
| [`input_set_port0_value`](../../src/leon2m/input/input_set_port0_value.c) | `FUN_a0142e80` | Store a 16-bit value in port record 0. | descriptive |
| [`input_set_port_class`](../../src/leon2m/input/input_set_port_class.c) | `FUN_a0141d50` | Store the class field of the port entry for a port code. | descriptive |
| [`input_set_port_link_byte3`](../../src/leon2m/input/input_set_port_link_byte3.c) | `FUN_a012b328` | Store byte 3 of a port's link row and send it. | descriptive |
| [`input_set_port_link_field_first`](../../src/leon2m/input/input_set_port_link_field_first.c) | `FUN_a012add8` | Store a port's first link setting in the settings and its link row, and send the row. | descriptive |
| [`input_set_port_link_field_second`](../../src/leon2m/input/input_set_port_link_field_second.c) | `FUN_a012b078` | Store a port's second link setting in the settings and its link row, and send the row. | descriptive |
| [`input_set_port_link_field_third`](../../src/leon2m/input/input_set_port_link_field_third.c) | `FUN_a012af40` | Store a port's third link setting in the settings and its link row, and send the row. | descriptive |
| [`input_set_port_link_flag_row7`](../../src/leon2m/input/input_set_port_link_flag_row7.c) | `FUN_a012b164` | Store a port's on/off link flag (row byte 7) and send the row. | descriptive |
| [`input_set_port_link_tail_bytes`](../../src/leon2m/input/input_set_port_link_tail_bytes.c) | `FUN_a012b418` | Store three bytes of a port's link row and send them. | descriptive |
| [`input_set_port_mode`](../../src/leon2m/input/input_set_port_mode.c) | `FUN_a0142ed0` | Set the mode byte of a port record and reprogram the receiver when it changes. | descriptive |
| [`input_set_port_pending_bit`](../../src/leon2m/input/input_set_port_pending_bit.c) | `FUN_a012b39c` | Set a port's pending bit, or clear it and mark the port as changed. | descriptive |
| [`input_set_port_pin_function`](../../src/leon2m/input/input_set_port_pin_function.c) | `FUN_a0107a20` | Switch the pin of input 0 or 1, or of both (argument 2), to function 9 or back to 0. | descriptive |
| [`input_set_route_selector`](../../src/leon2m/input/input_set_route_selector.c) | `FUN_a00fe718` | Write the 2-bit route selector, or switch the route off. | descriptive |
| [`input_set_shared_route`](../../src/leon2m/input/input_set_shared_route.c) | `FUN_a00fdf44` | Point the shared route at an input block 0..7, or clear it. | descriptive |
| [`input_setup_converter_port`](../../src/leon2m/input/input_setup_converter_port.c) | `FUN_a0104a34` | Set the converter port bits for a channel from its input registers. | descriptive |
| [`input_setup_route_for_source`](../../src/leon2m/input/input_setup_route_for_source.c) | `FUN_a00fe4a4` | Set the routing registers for a source of class 0x51, 0x61, 0x71 or 0x81. | derived |
| [`input_slot_get_port_code`](../../src/leon2m/input/input_slot_get_port_code.c) | `FUN_a0125230` | Return the port code of the input in a given slot. | descriptive |
| [`input_slot_get_table_byte8`](../../src/leon2m/input/input_slot_get_table_byte8.c) | `FUN_a01254f8` | Return byte +8 of the port table entry of a slot. | descriptive |
| [`input_slot_get_table_byte9`](../../src/leon2m/input/input_slot_get_table_byte9.c) | `FUN_a0125530` | Return byte +9 of the port table entry of a slot. | descriptive |
| [`input_slot_get_table_byte10`](../../src/leon2m/input/input_slot_get_table_byte10.c) | `FUN_a0125568` | Return byte +0x0A of the port table entry of a slot. | descriptive |
| [`input_stamp_port_time`](../../src/leon2m/input/input_stamp_port_time.c) | `FUN_a0142ea8` | Store the current tick count in a port record. | derived |
| [`input_store_capture_window`](../../src/leon2m/input/input_store_capture_window.c) | `FUN_a013d1b4` | Store a capture window in a channel record after limiting it. | derived |
| [`input_unit_read8`](../../src/leon2m/input/input_unit_read8.c) | `FUN_a00f2e30` | Read an 8-bit register of a receiver unit. | derived |
| [`input_unit_setup_by_mode`](../../src/leon2m/input/input_unit_setup_by_mode.c) | `FUN_a0122e80` | Print 'Vx1RxLink_Initial' and write one of two start-up register lists of a receiver unit. | derived |
| [`input_unit_update_bits`](../../src/leon2m/input/input_unit_update_bits.c) | `FUN_a00f2ca8` | Set or clear bits of a register of one receiver unit, or of both. | derived |
| [`input_unit_write8`](../../src/leon2m/input/input_unit_write8.c) | `FUN_a00f2c20` | Write an 8-bit register of one receiver unit, or of both. | derived |
| [`input_update_present_ports_alt`](../../src/leon2m/input/input_update_present_ports_alt.c) | `FUN_a0129980` | Rebuild the second present-ports mask from the detect pins of the port entries. | descriptive |
| [`input_used_ports_in_state4`](../../src/leon2m/input/input_used_ports_in_state4.c) | `FUN_a0090f30` | Return 1 when every used input port is in application state 4. | descriptive |
| [`input_used_ports_settled`](../../src/leon2m/input/input_used_ports_settled.c) | `FUN_a00803a4` | Return 1 when no used port reports a state code above 4. | derived |
| [`input_user_apply_channel0_link_option`](../../src/leon2m/input/input_user_apply_channel0_link_option.c) | `FUN_a00d5fe4` | Apply the link option setting of channel 0. | descriptive |
| [`input_user_apply_channel1_link_option`](../../src/leon2m/input/input_user_apply_channel1_link_option.c) | `FUN_a00d6000` | Apply the link option setting of channel 1. | descriptive |
| [`input_user_apply_channel2_link_option`](../../src/leon2m/input/input_user_apply_channel2_link_option.c) | `FUN_a00d601c` | Apply the link option setting of channel 2. | descriptive |
| [`input_user_apply_channel3_link_option`](../../src/leon2m/input/input_user_apply_channel3_link_option.c) | `FUN_a00d6038` | Apply the link option setting of channel 3. | descriptive |
| [`input_user_apply_link_option_enable`](../../src/leon2m/input/input_user_apply_link_option_enable.c) | `FUN_a00d5fc4` | Apply settings bit 28 to the link option enable. | descriptive |
| [`input_user_apply_port0_option`](../../src/leon2m/input/input_user_apply_port0_option.c) | `FUN_a00d5fa4` | Apply settings bit 29 to the option of input port 0. | descriptive |
| [`input_user_apply_port_version`](../../src/leon2m/input/input_user_apply_port_version.c) | `FUN_a00d80b0` | Apply the port version setting to both inputs of the pair. | descriptive |
| [`input_user_get_rounded_refresh_rate`](../../src/leon2m/input/input_user_get_rounded_refresh_rate.c) | `FUN_a00d8b38` | Return the incoming refresh rate rounded, snapped to 120, 144, 180 or 240 when close. | proven |
| [`input_user_has_rate_mode`](../../src/leon2m/input/input_user_has_rate_mode.c) | `FUN_a00d8bd8` | Return 1 when pq_select_rate_mode gives a mode other than 0 for channel 0's refresh rate. | derived |
| [`input_user_is_active_port_in_range`](../../src/leon2m/input/input_user_is_active_port_in_range.c) | `FUN_a00d8034` | Return whether the active port code lies between 0x0B and 0x0F. | descriptive |
| [`Set_INTERNAL_1_INPUT_Path`](../../src/leon2m/input/Set_INTERNAL_1_INPUT_Path.c) | `FUN_a00fdf74` | Select the source of internal signal path 1. | proven |
| [`Set_INTERNAL_2_INPUT_Path`](../../src/leon2m/input/Set_INTERNAL_2_INPUT_Path.c) | `FUN_a00fe1dc` | Select the source of internal signal path 2. | proven |

<a id="hdmi"></a>
## HDMI

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`APPCECGetSourceType`](../../src/leon2m/hdmi/APPCECGetSourceType.c) | `FUN_a0083d80` | Identify the connected console from its CEC vendor ID or name. | proven |
| [`hdmi_cec_api_copy_message`](../../src/leon2m/hdmi/hdmi_cec_api_copy_message.c) | `FUN_a0147780` | Copy the five stored CEC message bytes to a buffer. | descriptive |
| [`hdmi_cec_api_get_command`](../../src/leon2m/hdmi/hdmi_cec_api_get_command.c) | `FUN_a0147790` | Run the CEC receive step and return the received command 0..7. | derived |
| `hdmi_cec_api_get_command_jump_table` | `switchdataD_a01433d8` | Jump table 1 of the switch statements in hdmi_cec_api_get_command. | proven |
| [`hdmi_cec_api_get_message_word`](../../src/leon2m/hdmi/hdmi_cec_api_get_message_word.c) | `FUN_a0147770` | Return the four stored CEC message bytes as one word. | descriptive |
| [`hdmi_cec_api_get_sender`](../../src/leon2m/hdmi/hdmi_cec_api_get_sender.c) | `FUN_a0147814` | Return the stored byte that accompanies the last CEC command. | descriptive |
| [`hdmi_cec_api_reset`](../../src/leon2m/hdmi/hdmi_cec_api_reset.c) | `FUN_a0147760` | Clear the CEC control register. | derived |
| [`hdmi_cec_api_send_action`](../../src/leon2m/hdmi/hdmi_cec_api_send_action.c) | `FUN_a014782c` | Send one of six CEC actions (1, 2, 3, 5, 6, 7); other action numbers do nothing. | derived |
| `hdmi_cec_api_send_action_jump_table` | `switchdataD_a01433f8` | Jump table 1 of the switch statements in hdmi_cec_api_send_action. | proven |
| [`hdmi_cec_clear_receive_flag`](../../src/leon2m/hdmi/hdmi_cec_clear_receive_flag.c) | `FUN_a00fc318` | Acknowledge the CEC receive flag and clear the stored state. | descriptive |
| [`hdmi_cec_copy_message`](../../src/leon2m/hdmi/hdmi_cec_copy_message.c) | `FUN_a00fce0c` | Copy the five stored CEC message bytes to a buffer. | descriptive |
| [`hdmi_cec_get_message_word`](../../src/leon2m/hdmi/hdmi_cec_get_message_word.c) | `FUN_a00fcdd8` | Return the four stored CEC message bytes as one word. | descriptive |
| [`hdmi_cec_get_operand`](../../src/leon2m/hdmi/hdmi_cec_get_operand.c) | `FUN_a00fca40` | Return the stored operand of the last CEC command. | descriptive |
| [`hdmi_cec_get_sender`](../../src/leon2m/hdmi/hdmi_cec_get_sender.c) | `FUN_a00fca34` | Return the stored byte that accompanies the last CEC command. | descriptive |
| [`hdmi_cec_init`](../../src/leon2m/hdmi/hdmi_cec_init.c) | `FUN_a00fc200` | Set up the CEC block and give one pin, chosen by the parameter, the CEC function. | derived |
| [`hdmi_cec_match_console_name`](../../src/leon2m/hdmi/hdmi_cec_match_console_name.c) | `FUN_a0083c88` | Return 0, 1 or 2 when the CEC source name is "Play", "Nint" or "XBOX", else 0xFF. | derived |
| [`hdmi_cec_name_is_play`](../../src/leon2m/hdmi/hdmi_cec_name_is_play.c) | `FUN_a0083c34` | Return 1 when the stored CEC source name starts with "Play". | derived |
| [`hdmi_cec_receive_and_reply`](../../src/leon2m/hdmi/hdmi_cec_receive_and_reply.c) | `FUN_a00fc334` | Receive a CEC message, answer it and return the command it carried. | derived |
| [`hdmi_cec_request_osd_name`](../../src/leon2m/hdmi/hdmi_cec_request_osd_name.c) | `FUN_a00fd298` | Clear the stored OSD name answer and send CEC message 0x46 (give OSD name). | derived |
| [`hdmi_cec_request_vendor_id`](../../src/leon2m/hdmi/hdmi_cec_request_vendor_id.c) | `FUN_a00fce40` | Clear the stored vendor id answer and send CEC message 0x8C (give device vendor id). | derived |
| [`hdmi_cec_reset`](../../src/leon2m/hdmi/hdmi_cec_reset.c) | `FUN_a00fc2fc` | Clear the CEC control register. | derived |
| [`hdmi_cec_send_message_first`](../../src/leon2m/hdmi/hdmi_cec_send_message_first.c) | `FUN_a00fca4c` | Send the first of three fixed CEC messages and wait for it to go out. | descriptive |
| [`hdmi_cec_send_message_second`](../../src/leon2m/hdmi/hdmi_cec_send_message_second.c) | `FUN_a00fcb1c` | Send the second of three fixed CEC messages and wait for it to go out. | descriptive |
| [`hdmi_cec_send_message_third`](../../src/leon2m/hdmi/hdmi_cec_send_message_third.c) | `FUN_a00fcbec` | Send the third of three fixed CEC messages and wait for it to go out. | descriptive |
| [`hdmi_cec_send_table_message`](../../src/leon2m/hdmi/hdmi_cec_send_table_message.c) | `FUN_a00fccbc` | Send CEC message 0x32 with the three bytes of a table entry. | derived |
| [`hdmi_cec_send_user_control`](../../src/leon2m/hdmi/hdmi_cec_send_user_control.c) | `FUN_a00fd074` | Send CEC message 0x44 with one operand. | derived |
| [`hdmi_cec_set_clock_divider`](../../src/leon2m/hdmi/hdmi_cec_set_clock_divider.c) | `FUN_a00fc1cc` | Write the CEC clock divider for the current clock setting. | descriptive |
| [`hdmi_cec_set_send_hook`](../../src/leon2m/hdmi/hdmi_cec_set_send_hook.c) | `FUN_a00fc30c` | Store the hook that is called when a CEC message is sent. | descriptive |
| [`hdmi_mute_port_until_hdcp22_auth`](../../src/leon2m/hdmi/hdmi_mute_port_until_hdcp22_auth.c) | `FUN_a0141f98` | Keep a class 5 port muted while its HDCP 2.2 authentication is checked. | derived |
| [`hdmi_update_port_hdcp_flags`](../../src/leon2m/hdmi/hdmi_update_port_hdcp_flags.c) | `FUN_a0141edc` | Copy three state bits of a class 5 port into its port entry. | descriptive |
| [`hdmi_user_send_cec_action4`](../../src/leon2m/hdmi/hdmi_user_send_cec_action4.c) | `FUN_a00d4888` | Ask for CEC action 4 when HDMI CEC is on and PIP/PBP is off; action 4 has no case, nothing is sent. | derived |
| [`UserGetCECSourceMode`](../../src/leon2m/hdmi/UserGetCECSourceMode.c) | `FUN_a00da4b8` | Store the CEC source kind and load Pro and Game mode from saved copy 1 (CEC mode on) or copy 2. | proven |

<a id="dp"></a>
## DisplayPort

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`dp_api_set_dsc_support`](../../src/leon2m/dp/dp_api_set_dsc_support.c) | `FUN_a014a768` | Store whether DSC is enabled for the DisplayPort input of a source and save the setting. | derived |
| [`dp_get_port_dsc_support`](../../src/leon2m/dp/dp_get_port_dsc_support.c) | `FUN_a012b22c` | Return the DSC flag of a DisplayPort input from device settings byte +0x32. | derived |
| [`dp_set_port_dsc_support`](../../src/leon2m/dp/dp_set_port_dsc_support.c) | `FUN_a012b260` | Store whether DSC is enabled for a DisplayPort input and send the port's link row. | derived |
| [`SYSAPI_GetSystemDPDSCSupport`](../../src/leon2m/dp/SYSAPI_GetSystemDPDSCSupport.c) | `FUN_a014a6e0` | Return whether DSC is enabled for the DisplayPort input of a source. | proven |

<a id="edid"></a>
## EDID

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`edid_api_enable_internal_edid`](../../src/leon2m/edid/edid_api_enable_internal_edid.c) | `FUN_a014b65c` | Switch the internal EDID of an input port on or off. | proven |
| [`edid_api_read_port_edid`](../../src/leon2m/edid/edid_api_read_port_edid.c) | `FUN_a014b0c4` | Read the whole EDID of the input port that belongs to a source. | derived |
| [`edid_api_read_port_edid_range`](../../src/leon2m/edid/edid_api_read_port_edid_range.c) | `FUN_a014b1c8` | Read part of the EDID of the input port that belongs to a source. | derived |
| [`edid_api_set_port_flag`](../../src/leon2m/edid/edid_api_set_port_flag.c) | `FUN_a014b750` | Set or clear the per-port flag bit that accompanies the internal EDID. | descriptive |
| [`edid_api_write_port_edid`](../../src/leon2m/edid/edid_api_write_port_edid.c) | `FUN_a014b280` | Write an EDID, or the built-in default, to the input port that belongs to a source. | derived |
| [`edid_api_write_port_edid_bytes`](../../src/leon2m/edid/edid_api_write_port_edid_bytes.c) | `FUN_a014b360` | Write given bytes at an address into the EDID memory of the input port that belongs to a source. | derived |
| [`edid_copy_stored_block`](../../src/leon2m/edid/edid_copy_stored_block.c) | `FUN_a00ce9c0` | Copy 16 bytes of one stored EDID record. | derived |
| [`edid_enable_internal_edid`](../../src/leon2m/edid/edid_enable_internal_edid.c) | `FUN_a01253bc` | Switch the internal EDID of a port on or off and remember the choice. | proven |
| [`edid_get_bus_table_byte0`](../../src/leon2m/edid/edid_get_bus_table_byte0.c) | `FUN_a0124f64` | Return byte 0 of an entry of the four-byte EDID bus table. | descriptive |
| [`edid_get_bus_table_byte1`](../../src/leon2m/edid/edid_get_bus_table_byte1.c) | `FUN_a0124f7c` | Return byte 1 of an entry of the four-byte EDID bus table. | descriptive |
| [`edid_get_bus_table_byte2`](../../src/leon2m/edid/edid_get_bus_table_byte2.c) | `FUN_a0124f98` | Return byte 2 of an entry of the four-byte EDID bus table. | descriptive |
| [`edid_get_bus_table_byte3`](../../src/leon2m/edid/edid_get_bus_table_byte3.c) | `FUN_a0124fb4` | Return byte 3 of an entry of the four-byte EDID bus table. | descriptive |
| [`edid_get_port_flag`](../../src/leon2m/edid/edid_get_port_flag.c) | `FUN_a012536c` | Return the per-port flag that accompanies the internal EDID. | descriptive |
| [`edid_get_port_memory_base`](../../src/leon2m/edid/edid_get_port_memory_base.c) | `FUN_a0125380` | Return the base address of an input's EDID memory. | derived |
| [`edid_get_port_memory_size`](../../src/leon2m/edid/edid_get_port_memory_size.c) | `FUN_a01255a0` | Return the size of an input's EDID memory. | derived |
| [`edid_get_port_size`](../../src/leon2m/edid/edid_get_port_size.c) | `FUN_a012c16c` | Return the stored EDID size of a port in bytes. | derived |
| [`edid_is_internal_edid_enabled`](../../src/leon2m/edid/edid_is_internal_edid_enabled.c) | `FUN_a0125350` | Return whether the internal EDID of a port is switched on. | derived |
| [`edid_patch_serial_and_checksum`](../../src/leon2m/edid/edid_patch_serial_and_checksum.c) | `FUN_a012ccf0` | Copy ten identification bytes into an EDID block and recompute its checksum. | derived |
| [`edid_read_port_edid`](../../src/leon2m/edid/edid_read_port_edid.c) | `FUN_a012c320` | Read the EDID memory of an input port, in full or a given range. | derived |
| [`edid_set_port_flag`](../../src/leon2m/edid/edid_set_port_flag.c) | `FUN_a01254b8` | Set or clear the per-port flag that accompanies the internal EDID. | descriptive |
| [`edid_set_port_internal_edid`](../../src/leon2m/edid/edid_set_port_internal_edid.c) | `FUN_a012cd68` | Switch the internal EDID of one port on or off as its stored flag says. | derived |
| [`edid_set_port_size_code`](../../src/leon2m/edid/edid_set_port_size_code.c) | `FUN_a012c138` | Store the EDID size code of a port. | descriptive |
| [`edid_write_port_edid`](../../src/leon2m/edid/edid_write_port_edid.c) | `FUN_a012c80c` | Write an EDID, or the built-in default for the port's variant, to an input port. | derived |
| [`LoadCustomerEDIDData`](../../src/leon2m/edid/LoadCustomerEDIDData.c) | `FUN_a00ce958` | Load one of the stored EDID records into an input port. | proven |
| [`UserSwitchEDID`](../../src/leon2m/edid/UserSwitchEDID.c) | `FUN_a00d99f8` | Choose the EDID variant that fits the user's settings and load it into the inputs. | proven |
| `UserSwitchEDID_jump_table` | `switchdataD_a00d3b44` | Jump table 1 of the switch statements in UserSwitchEDID. | proven |

<a id="ddc"></a>
## DDC/CI and the service tool

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`ddc_answer_maker_vcp_get`](../../src/leon2m/ddc/ddc_answer_maker_vcp_get.c) | `FUN_a00cf2d4` | Fill the reply to a DDC/CI 'Get VCP Feature' request for the maker code 0xFE (sub-code in byte 4). | derived |
| `ddc_answer_maker_vcp_get_jump_table` | `switchdataD_a00ceb24` | Jump table 1 of the switch statements in ddc_answer_maker_vcp_get. | proven |
| [`ddc_api_get_request_state`](../../src/leon2m/ddc/ddc_api_get_request_state.c) | `FUN_a0148680` | Return the state byte of the received DDC/CI request. | derived |
| [`ddc_api_queue_reply`](../../src/leon2m/ddc/ddc_api_queue_reply.c) | `FUN_a01486a8` | Queue the bytes of a DDC/CI reply for the 8051 to send. | derived |
| [`ddc_api_set_port_slave_address`](../../src/leon2m/ddc/ddc_api_set_port_slave_address.c) | `FUN_a014b01c` | Store a DDC/CI slave address for the port of a source and have the 8051 switch that slave on. | derived |
| [`ddc_api_take_request`](../../src/leon2m/ddc/ddc_api_take_request.c) | `FUN_a0148698` | Copy the received DDC/CI request out and mark the record free. | derived |
| [`ddc_apply_maker_vcp_set`](../../src/leon2m/ddc/ddc_apply_maker_vcp_set.c) | `FUN_a00cfacc` | Carry out a DDC/CI 'Set VCP Feature' request for the maker code 0xFE and fill its reply. | derived |
| `ddc_apply_maker_vcp_set_jump_table` | `switchdataD_a00ceb74` | Jump table 1 of the switch statements in ddc_apply_maker_vcp_set. | proven |
| `ddc_apply_maker_vcp_set_jump_table2` | `switchdataD_a00cec0c` | Jump table 2 of the switch statements in ddc_apply_maker_vcp_set. | proven |
| [`ddc_build_crc_reply`](../../src/leon2m/ddc/ddc_build_crc_reply.c) | `FUN_a00cfa68` | Fill a DDC/CI reply with the CRC-16 of four request bytes. | descriptive |
| [`ddc_build_fixed_status_reply`](../../src/leon2m/ddc/ddc_build_fixed_status_reply.c) | `FUN_a00cfa14` | Fill a fixed DDC/CI reply carrying the value 0x36F. | descriptive |
| [`ddc_build_vcp_reply`](../../src/leon2m/ddc/ddc_build_vcp_reply.c) | `FUN_a00cead4` | Fill a DDC/CI VCP feature reply for maker code 0xFE with four given value bytes. | derived |
| [`ddc_combine_status_flags`](../../src/leon2m/ddc/ddc_combine_status_flags.c) | `FUN_a00cf23c` | Return the OR of the flag halfwords of the three status entries. | descriptive |
| [`ddc_find_status_entry`](../../src/leon2m/ddc/ddc_find_status_entry.c) | `FUN_a00cf1ec` | Return the value byte of the status entry whose key byte matches. | descriptive |
| [`ddc_get_edid_write_limit`](../../src/leon2m/ddc/ddc_get_edid_write_limit.c) | `FUN_a00cf288` | Return the byte limit of an EDID write block sent over DDC/CI. | descriptive |
| [`ddc_get_port_slave_address`](../../src/leon2m/ddc/ddc_get_port_slave_address.c) | `FUN_a01243c8` | Return the stored DDC/CI slave address of a port. | derived |
| [`ddc_get_request_state`](../../src/leon2m/ddc/ddc_get_request_state.c) | `FUN_a0133ad8` | Return the state byte of the received DDC/CI request. | derived |
| [`ddc_handle_request`](../../src/leon2m/ddc/ddc_handle_request.c) | `FUN_a0088724` | Decode and answer one DDC/CI request (GetVCP, SetVCP, capabilities, timing) | proven |
| [`ddc_map_color_preset`](../../src/leon2m/ddc/ddc_map_color_preset.c) | `FUN_a00cf194` | Map a DDC/CI colour preset code to the colour temperature setting value. | derived |
| [`ddc_post_pending_event`](../../src/leon2m/ddc/ddc_post_pending_event.c) | `FUN_a008a09c` | Post the first pending DDC/CI event flag as event 0xC0..0xC6. | proven |
| [`ddc_queue_reply`](../../src/leon2m/ddc/ddc_queue_reply.c) | `FUN_a0133b54` | Queue the bytes of a DDC/CI reply for the 8051 to send. | derived |
| [`ddc_raise_event0`](../../src/leon2m/ddc/ddc_raise_event0.c) | `FUN_a0089f10` | Set pending DDC/CI event flag 0. | proven |
| [`ddc_raise_event1`](../../src/leon2m/ddc/ddc_raise_event1.c) | `FUN_a0089f4c` | Set pending DDC/CI event flag 1. | proven |
| [`ddc_raise_event2`](../../src/leon2m/ddc/ddc_raise_event2.c) | `FUN_a0089f38` | Set pending DDC/CI event flag 2. | proven |
| [`ddc_raise_event3`](../../src/leon2m/ddc/ddc_raise_event3.c) | `FUN_a0089f24` | Set pending DDC/CI event flag 3. | proven |
| [`ddc_return_two`](../../src/leon2m/ddc/ddc_return_two.c) | `FUN_a00cf280` | Return 2. | descriptive |
| [`ddc_return_two_copy`](../../src/leon2m/ddc/ddc_return_two_copy.c) | `FUN_a00df804` | Return 2. | descriptive |
| [`ddc_run_request_task`](../../src/leon2m/ddc/ddc_run_request_task.c) | `FUN_a008a174` | Run the DDC/CI request handler. | proven |
| [`ddc_send_vcp_e6_reply`](../../src/leon2m/ddc/ddc_send_vcp_e6_reply.c) | `FUN_a0089f6c` | Send a VCP reply for code 0xE6 carrying settings bit 7 of +0xA8. | derived |
| [`ddc_set_checksum_byte`](../../src/leon2m/ddc/ddc_set_checksum_byte.c) | `FUN_a0089f60` | Store v in the DDC/CI checksum byte. | derived |
| [`ddc_set_port_slave_address`](../../src/leon2m/ddc/ddc_set_port_slave_address.c) | `FUN_a01255dc` | Store the DDC/CI slave address of a port. | derived |
| [`ddc_take_event0`](../../src/leon2m/ddc/ddc_take_event0.c) | `FUN_a0088654` | Return and clear pending DDC/CI event flag 0. | proven |
| [`ddc_take_event1`](../../src/leon2m/ddc/ddc_take_event1.c) | `FUN_a008866c` | Return and clear pending DDC/CI event flag 1. | proven |
| [`ddc_take_event2`](../../src/leon2m/ddc/ddc_take_event2.c) | `FUN_a00886a4` | Return and clear pending DDC/CI event flag 2. | proven |
| [`ddc_take_event3`](../../src/leon2m/ddc/ddc_take_event3.c) | `FUN_a0088688` | Return and clear pending DDC/CI event flag 3. | proven |
| [`ddc_take_event4`](../../src/leon2m/ddc/ddc_take_event4.c) | `FUN_a00886c0` | Return and clear pending DDC/CI event flag 4. | proven |
| [`ddc_take_event5`](../../src/leon2m/ddc/ddc_take_event5.c) | `FUN_a00886dc` | Return and clear pending DDC/CI event flag 5. | proven |
| [`ddc_take_event6`](../../src/leon2m/ddc/ddc_take_event6.c) | `FUN_a00886f8` | Return and clear pending DDC/CI event flag 6. | proven |
| [`ddc_take_request`](../../src/leon2m/ddc/ddc_take_request.c) | `FUN_a0133ae4` | Copy the received DDC/CI request out and mark the record free. | derived |
| [`ddc_tool_answer_read_request`](../../src/leon2m/ddc/ddc_tool_answer_read_request.c) | `FUN_a00d3650` | Answer a factory tool table read: 16 bytes of a stored EDID record, or an error result. | derived |
| `ddc_tool_answer_read_request_jump_table` | `switchdataD_a00cf0f4` | Jump table 1 of the switch statements in ddc_tool_answer_read_request. | proven |
| `ddc_tool_answer_read_request_jump_table2` | `switchdataD_a00cf110` | Jump table 2 of the switch statements in ddc_tool_answer_read_request. | proven |
| `ddc_tool_answer_read_request_jump_table3` | `switchdataD_a00cf144` | Jump table 3 of the switch statements in ddc_tool_answer_read_request. | proven |
| `ddc_tool_answer_read_request_jump_table4` | `switchdataD_a00cf178` | Jump table 4 of the switch statements in ddc_tool_answer_read_request. | proven |
| [`ddc_tool_build_reply`](../../src/leon2m/ddc/ddc_tool_build_reply.c) | `FUN_a00d1220` | Fill the rest of a factory tool reply for a result code or an answer kind and store its checksum. | derived |
| [`ddc_tool_build_reply_header`](../../src/leon2m/ddc/ddc_tool_build_reply_header.c) | `FUN_a00d0e48` | Fill the header of a factory tool reply from its request. | descriptive |
| `ddc_tool_build_reply_jump_table` | `switchdataD_a00cec3c` | Jump table 1 of the switch statements in ddc_tool_build_reply. | proven |
| [`ddc_tool_calc_checksum`](../../src/leon2m/ddc/ddc_tool_calc_checksum.c) | `FUN_a00d0f68` | Return the XOR checksum of a factory tool message. | derived |
| [`ddc_tool_clear_factory_counters`](../../src/leon2m/ddc/ddc_tool_clear_factory_counters.c) | `FUN_a00d2994` | Tool command: clear a byte and a 16-bit counter of the factory record and save it. | descriptive |
| [`ddc_tool_copy_color_temp_gains`](../../src/leon2m/ddc/ddc_tool_copy_color_temp_gains.c) | `FUN_a00d23b8` | Copy one three-byte colour row of the part record to another and save the part record. | derived |
| [`ddc_tool_dispatch_command`](../../src/leon2m/ddc/ddc_tool_dispatch_command.c) | `FUN_a00d2a98` | Carry out a factory tool command and send its answer. | proven |
| `ddc_tool_dispatch_command_jump_table` | `switchdataD_a00ced30` | Jump table 1 of the switch statements in ddc_tool_dispatch_command. | proven |
| `ddc_tool_dispatch_command_jump_table2` | `switchdataD_a00cedb0` | Jump table 2 of the switch statements in ddc_tool_dispatch_command. | proven |
| [`ddc_tool_enter_factory_mode`](../../src/leon2m/ddc/ddc_tool_enter_factory_mode.c) | `FUN_a00d28d4` | Tool command: switch factory mode and burn-in on, save and verify. | derived |
| [`ddc_tool_fill_reply_0x97`](../../src/leon2m/ddc/ddc_tool_fill_reply_0x97.c) | `FUN_a00d0fa0` | Fill the factory tool reply to command 0x97. | descriptive |
| [`ddc_tool_reply_color_temp_gains`](../../src/leon2m/ddc/ddc_tool_reply_color_temp_gains.c) | `FUN_a00d0fe8` | Fill the factory tool reply with the gains of the current colour temperature. | derived |
| [`ddc_tool_reply_factory_record`](../../src/leon2m/ddc/ddc_tool_reply_factory_record.c) | `FUN_a00d1110` | Fill the factory tool reply with 13 bytes of the factory record. | derived |
| [`ddc_tool_reply_factory_status`](../../src/leon2m/ddc/ddc_tool_reply_factory_status.c) | `FUN_a00d1184` | Fill the factory tool reply with the factory mode or burn-in state. | derived |
| [`ddc_tool_reply_key_test`](../../src/leon2m/ddc/ddc_tool_reply_key_test.c) | `FUN_a00d10b4` | Fill the factory tool reply with the front key test result. | derived |
| [`ddc_tool_run_factory_reset`](../../src/leon2m/ddc/ddc_tool_run_factory_reset.c) | `FUN_a00d1b48` | Reset the user settings to their defaults and save the user settings and the factory record. | derived |
| [`ddc_tool_select_input`](../../src/leon2m/ddc/ddc_tool_select_input.c) | `FUN_a00d1d34` | Switch to the input the factory tool names. | derived |
| [`ddc_tool_set_brightness`](../../src/leon2m/ddc/ddc_tool_set_brightness.c) | `FUN_a00d1ed8` | Set the brightness the factory tool sends (at most 100) | proven |
| [`ddc_tool_set_brightness_preset`](../../src/leon2m/ddc/ddc_tool_set_brightness_preset.c) | `FUN_a00d27ac` | Tool command: set brightness preset 0..2, switch to Game Mode 1, apply and save. | derived |
| [`ddc_tool_set_burn_in`](../../src/leon2m/ddc/ddc_tool_set_burn_in.c) | `FUN_a00d1ce4` | Switch the burn-in test on or off as the factory tool asks and save it. | proven |
| [`ddc_tool_set_color_temp_gain`](../../src/leon2m/ddc/ddc_tool_set_color_temp_gain.c) | `FUN_a00d1f58` | Set one colour gain of the current colour temperature from the factory tool. | proven |
| [`ddc_tool_set_color_temperature`](../../src/leon2m/ddc/ddc_tool_set_color_temperature.c) | `FUN_a00d1e3c` | Select the colour temperature the factory tool names and save it. | derived |
| [`ddc_tool_set_contrast`](../../src/leon2m/ddc/ddc_tool_set_contrast.c) | `FUN_a00d1f20` | Set the contrast the factory tool sends (at most 100) | proven |
| [`ddc_tool_set_factory_flag_14`](../../src/leon2m/ddc/ddc_tool_set_factory_flag_14.c) | `FUN_a00d2884` | Tool command: store a 0/1 flag in the factory record and save it. | descriptive |
| [`ddc_tool_set_factory_mode`](../../src/leon2m/ddc/ddc_tool_set_factory_mode.c) | `FUN_a00d1ad4` | Switch factory mode on or off as the factory tool asks and save it. | derived |
| [`ddc_tool_set_fill_or_inspection`](../../src/leon2m/ddc/ddc_tool_set_fill_or_inspection.c) | `FUN_a00d25f4` | Tool command: show a fill colour or select the panel's inspection mode and pattern. | derived |
| [`ddc_tool_set_inverted_flag`](../../src/leon2m/ddc/ddc_tool_set_inverted_flag.c) | `FUN_a00d1e08` | Store the inverse of a factory tool on/off value in a flag byte. | descriptive |
| [`ddc_tool_set_language`](../../src/leon2m/ddc/ddc_tool_set_language.c) | `FUN_a00d20a4` | Set the menu language the factory tool names and save it. | derived |
| `ddc_tool_set_language_jump_table` | `switchdataD_a00cecb0` | Jump table 1 of the switch statements in ddc_tool_set_language. | proven |
| [`ddc_tool_set_level_percent`](../../src/leon2m/ddc/ddc_tool_set_level_percent.c) | `FUN_a00d2384` | Store the level the factory tool sends in settings byte +0x10 and apply it. | derived |
| [`ddc_tool_set_pip_test_mode`](../../src/leon2m/ddc/ddc_tool_set_pip_test_mode.c) | `FUN_a00d253c` | Tool command: switch a picture-in-picture test layout on or off. | descriptive |
| [`ddc_tool_set_power`](../../src/leon2m/ddc/ddc_tool_set_power.c) | `FUN_a00d1a34` | Switch the monitor on or off as the factory tool asks. | derived |
| [`ddc_tool_set_read_address`](../../src/leon2m/ddc/ddc_tool_set_read_address.c) | `FUN_a00d2974` | Tool command: store the two address bytes for the next table read. | descriptive |
| [`ddc_tool_set_rgb_led`](../../src/leon2m/ddc/ddc_tool_set_rgb_led.c) | `FUN_a00d24e0` | Switch the RGB LED on or off as the factory tool asks and save it. | derived |
| [`ddc_tool_set_setting_bit7`](../../src/leon2m/ddc/ddc_tool_set_setting_bit7.c) | `FUN_a00d2a28` | Tool command: write bit 7 of the settings word at +0x1EC and apply it when it changed. | descriptive |
| [`ddc_tool_set_setting_bit9`](../../src/leon2m/ddc/ddc_tool_set_setting_bit9.c) | `FUN_a00d29c0` | Tool command: write settings bit 9 and apply it when it changed. | descriptive |
| [`ddc_tool_write_factory_record`](../../src/leon2m/ddc/ddc_tool_write_factory_record.c) | `FUN_a00d2334` | Store 13 bytes from the factory tool in the factory record and save it. | proven |

<a id="panel"></a>
## Panel: timing, output, power, PWM

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`APPBlurFree_AfterMute`](../../src/leon2m/panel/APPBlurFree_AfterMute.c) | `FUN_a00875ec` | Switch blur reduction off after the picture was muted and apply the brightness as for off. | proven |
| [`ConfigScalerPWM`](../../src/leon2m/panel/ConfigScalerPWM.c) | `FUN_a011d748` | Set a PWM channel's clock source, prescaler and divider for a frequency and route it to a pin. | proven |
| `ConfigScalerPWM_jump_table` | `switchdataD_a011d214` | Jump table 1 of the switch statements in ConfigScalerPWM. | proven |
| `ConfigScalerPWM_jump_table2` | `switchdataD_a011d294` | Jump table 2 of the switch statements in ConfigScalerPWM. | proven |
| `ConfigScalerPWM_jump_table3` | `switchdataD_a011d304` | Jump table 3 of the switch statements in ConfigScalerPWM. | proven |
| [`Disp_Init`](../../src/leon2m/panel/Disp_Init.c) | `FUN_a0151db4` | Set up the initial output configuration. | proven |
| `Disp_Init_jump_table` | `switchdataD_a01510d4` | Jump table 1 of the switch statements in Disp_Init. | proven |
| [`DispModeTransform`](../../src/leon2m/panel/DispModeTransform.c) | `FUN_a0151c84` | Derive the display mode from a panel mode row. | proven |
| `DispModeTransform_jump_table` | `switchdataD_a0151008` | Jump table 1 of the switch statements in DispModeTransform. | proven |
| [`drv_PanelLimitation`](../../src/leon2m/panel/drv_PanelLimitation.c) | `FUN_a01070b4` | Compare the current timing with the panel's limits and warn when it is outside. | proven |
| [`panel_api_check_limitation`](../../src/leon2m/panel/panel_api_check_limitation.c) | `FUN_a014e8d8` | Run the panel limit check (drv_PanelLimitation). | derived |
| [`panel_api_copy_active_row`](../../src/leon2m/panel/panel_api_copy_active_row.c) | `FUN_a01483b8` | Copy the active panel timing row (0x58 bytes) to a buffer. | derived |
| [`panel_api_get_active_size`](../../src/leon2m/panel/panel_api_get_active_size.c) | `FUN_a014837c` | Return the first or second 16-bit size field of the active panel timing row. | derived |
| [`panel_api_get_brightness_level`](../../src/leon2m/panel/panel_api_get_brightness_level.c) | `FUN_a014be10` | Return the panel brightness value computed from the stored brightness setting. | derived |
| [`panel_api_reapply_nominal_rate`](../../src/leon2m/panel/panel_api_reapply_nominal_rate.c) | `FUN_a0148500` | Apply the nominal refresh rate of the active row again. | derived |
| [`panel_api_set_active_row`](../../src/leon2m/panel/panel_api_set_active_row.c) | `FUN_a01483f4` | Make a panel timing row the active one and optionally apply it to the output. | proven |
| [`panel_api_set_blurfree_mode`](../../src/leon2m/panel/panel_api_set_blurfree_mode.c) | `FUN_a014bc58` | Store the blur-reduction mode and switch the feature off, to GEN1 or to GEN2. | proven |
| [`panel_api_set_brightness`](../../src/leon2m/panel/panel_api_set_brightness.c) | `FUN_a014bf64` | Store the brightness setting, convert it to the panel value and send it to the panel. | proven |
| [`panel_api_set_pwm_duty_channel_ff`](../../src/leon2m/panel/panel_api_set_pwm_duty_channel_ff.c) | `FUN_a014382c` | Call panel_pwm_set_duty with channel 0xFF, which has no case for it and writes nothing. | descriptive |
| [`panel_api_store_blurfree_mode`](../../src/leon2m/panel/panel_api_store_blurfree_mode.c) | `FUN_a014bce4` | Store the blur-reduction mode without applying it. | derived |
| [`panel_blurfree_apply_channel_delays`](../../src/leon2m/panel/panel_blurfree_apply_channel_delays.c) | `FUN_a014faa8` | Write the stored delay of each PWM channel to the hardware, then the reference delay. | derived |
| [`panel_blurfree_apply_mode_second_port`](../../src/leon2m/panel/panel_blurfree_apply_mode_second_port.c) | `FUN_a014fb84` | Program the second PWM port for blur-reduction mode 1, otherwise clear its control. | derived |
| [`panel_blurfree_apply_user_mode`](../../src/leon2m/panel/panel_blurfree_apply_user_mode.c) | `FUN_a008767c` | Choose the blur reduction mode (off, 1 or 2) from the settings and set up its PWM parameters. | derived |
| [`panel_blurfree_configure`](../../src/leon2m/panel/panel_blurfree_configure.c) | `FUN_a01502c4` | Validate the blur-reduction PWM parameters and store the derived period, duty and delay. | proven |
| [`panel_blurfree_enable_channels`](../../src/leon2m/panel/panel_blurfree_enable_channels.c) | `FUN_a014fd34` | Switch every PWM channel selected by the channel mask on or off. | derived |
| [`panel_blurfree_off`](../../src/leon2m/panel/panel_blurfree_off.c) | `FUN_a0150230` | Switch blur reduction off. | proven |
| [`panel_blurfree_periodic_task`](../../src/leon2m/panel/panel_blurfree_periodic_task.c) | `FUN_a0150248` | Run the blur-reduction countdown while PWM channels are active. | derived |
| [`panel_blurfree_set_channel_delays`](../../src/leon2m/panel/panel_blurfree_set_channel_delays.c) | `FUN_a014f8a0` | Store a delay value for every PWM channel selected by a mask. | derived |
| [`panel_blurfree_set_channel_duty`](../../src/leon2m/panel/panel_blurfree_set_channel_duty.c) | `FUN_a014f998` | Write a duty value to every PWM channel selected by the second channel mask. | derived |
| [`panel_blurfree_set_channel_mask`](../../src/leon2m/panel/panel_blurfree_set_channel_mask.c) | `FUN_a014f980` | Store the mask of PWM channels used for blur reduction. | derived |
| [`panel_blurfree_set_channel_output_mode`](../../src/leon2m/panel/panel_blurfree_set_channel_output_mode.c) | `FUN_a014fbf0` | Set the output mode of every PWM channel selected by the channel mask. | descriptive |
| [`panel_blurfree_set_cycle_length`](../../src/leon2m/panel/panel_blurfree_set_cycle_length.c) | `FUN_a014f92c` | Store the cycle length of the first PWM signal. | derived |
| [`panel_blurfree_set_duty_offset`](../../src/leon2m/panel/panel_blurfree_set_duty_offset.c) | `FUN_a014f95c` | Store the duty offset. | derived |
| [`panel_blurfree_set_first_pwm_freq`](../../src/leon2m/panel/panel_blurfree_set_first_pwm_freq.c) | `FUN_a014f894` | Store the frequency of the first PWM signal. | derived |
| [`panel_blurfree_set_mode`](../../src/leon2m/panel/panel_blurfree_set_mode.c) | `FUN_a0150120` | Switch blur reduction off, or on in GEN1 or GEN2 mode, and program the PWM port. | proven |
| [`panel_blurfree_set_on_time`](../../src/leon2m/panel/panel_blurfree_set_on_time.c) | `FUN_a014f888` | Store the on-time of the first PWM signal. | derived |
| [`panel_blurfree_set_parameter`](../../src/leon2m/panel/panel_blurfree_set_parameter.c) | `FUN_a014bac4` | Store one blur-reduction parameter selected by its number 0..18. | proven |
| `panel_blurfree_set_parameter_jump_table` | `switchdataD_a01434e8` | Jump table 1 of the switch statements in panel_blurfree_set_parameter. | proven |
| [`panel_blurfree_set_pin_functions`](../../src/leon2m/panel/panel_blurfree_set_pin_functions.c) | `FUN_a0150768` | Set the pin function (10 or 0) of each pin whose bit is set in either blur-reduction channel mask. | derived |
| [`panel_blurfree_set_pwm_freq_ch16`](../../src/leon2m/panel/panel_blurfree_set_pwm_freq_ch16.c) | `FUN_a014fa84` | Set the PWM frequency of channel 0x10. | derived |
| [`panel_blurfree_set_reference_delay`](../../src/leon2m/panel/panel_blurfree_set_reference_delay.c) | `FUN_a014f938` | Store the reference delay. | descriptive |
| [`panel_blurfree_set_reversed_mode`](../../src/leon2m/panel/panel_blurfree_set_reversed_mode.c) | `FUN_a014f98c` | Store the flag that panel_blurfree_configure sets to 1 in its reversed case. | derived |
| [`panel_blurfree_set_second_channel_mask`](../../src/leon2m/panel/panel_blurfree_set_second_channel_mask.c) | `FUN_a014f974` | Store the second mask of PWM channels. | derived |
| [`panel_blurfree_set_second_port`](../../src/leon2m/panel/panel_blurfree_set_second_port.c) | `FUN_a014f968` | Store the port of the second PWM signal. | derived |
| [`panel_blurfree_set_second_pwm_freq`](../../src/leon2m/panel/panel_blurfree_set_second_pwm_freq.c) | `FUN_a014f950` | Store the frequency of the second PWM signal as given to ConfigScalerPWM. | derived |
| [`panel_blurfree_set_task_threshold`](../../src/leon2m/panel/panel_blurfree_set_task_threshold.c) | `FUN_a014f944` | Store the threshold the periodic blur-reduction task compares against. | derived |
| [`panel_calc_clock_percent`](../../src/leon2m/panel/panel_calc_clock_percent.c) | `FUN_a01083fc` | Compute a pixel clock as a percentage of 2407 MHz, plus 1. | descriptive |
| [`panel_calc_output_pixel_clock`](../../src/leon2m/panel/panel_calc_output_pixel_clock.c) | `FUN_a010325c` | Compute the output pixel clock for a channel and program it. | proven |
| [`panel_channel_layer_set_gains`](../../src/leon2m/panel/panel_channel_layer_set_gains.c) | `FUN_a010d244` | Store three percentages of a channel layer and write them as 10-bit values (100 gives 1023). | descriptive |
| [`panel_channel_layer_set_offsets`](../../src/leon2m/panel/panel_channel_layer_set_offsets.c) | `FUN_a010d530` | Store three percentages of a channel layer and write them as signed 8-bit values (50 gives 0). | descriptive |
| [`panel_channel_layer_setup_window`](../../src/leon2m/panel/panel_channel_layer_setup_window.c) | `FUN_a01107b8` | Set up a channel layer's window across both output halves, split at the middle of the panel. | derived |
| [`panel_correct_clock_first_step`](../../src/leon2m/panel/panel_correct_clock_first_step.c) | `FUN_a0104380` | Correct the output clock from measured counts (first step). | derived |
| [`panel_correct_clock_second_step`](../../src/leon2m/panel/panel_correct_clock_second_step.c) | `FUN_a01045a0` | Measure the output and correct the clock (second step). | derived |
| [`panel_cycle_burnin_colour`](../../src/leon2m/panel/panel_cycle_burnin_colour.c) | `FUN_a0082b00` | Show the next of nine full-screen test colours of the burn-in cycle. | proven |
| [`panel_get_active_row`](../../src/leon2m/panel/panel_get_active_row.c) | `FUN_a01241fc` | Return the address of the active panel timing row. | derived |
| [`panel_get_output_flag`](../../src/leon2m/panel/panel_get_output_flag.c) | `FUN_a0105c78` | Return the output driver's flag byte. | descriptive |
| [`panel_get_pll_frequency_mhz`](../../src/leon2m/panel/panel_get_pll_frequency_mhz.c) | `FUN_a0102fd0` | Compute a clock generator's frequency in MHz from its programmed value and post-divider; print it. | derived |
| `panel_get_pll_frequency_mhz_jump_table` | `switchdataD_a0101d24` | Jump table 1 of the switch statements in panel_get_pll_frequency_mhz. | proven |
| [`panel_get_power_state`](../../src/leon2m/panel/panel_get_power_state.c) | `FUN_a0141ae8` | Return the state of the panel power sequencer. | derived |
| [`panel_is_link_ready`](../../src/leon2m/panel/panel_is_link_ready.c) | `FUN_a012498c` | Return whether the panel link reports ready. | derived |
| [`panel_is_power_off`](../../src/leon2m/panel/panel_is_power_off.c) | `FUN_a0141ad0` | Return whether the panel power sequencer is in the off state. | derived |
| [`panel_is_power_on_done`](../../src/leon2m/panel/panel_is_power_on_done.c) | `FUN_a0141a98` | Return whether the panel power sequencer has finished switching on. | derived |
| [`panel_is_vdd_detected`](../../src/leon2m/panel/panel_is_vdd_detected.c) | `FUN_a0124914` | Return whether the panel supply voltage is detected. | proven |
| [`panel_layer4_clear_half_width_bit`](../../src/leon2m/panel/panel_layer4_clear_half_width_bit.c) | `FUN_a010f864` | Clear bit 0 of a fourth-layer context's flags and bit 20 or 21 of word 0 of both register sets. | descriptive |
| [`panel_layer4_disable`](../../src/leon2m/panel/panel_layer4_disable.c) | `FUN_a010d89c` | Switch the fourth layer off in both output halves. | descriptive |
| [`panel_layer4_enable`](../../src/leon2m/panel/panel_layer4_enable.c) | `FUN_a010d874` | Switch the fourth layer on in both output halves. | descriptive |
| [`panel_layer4_get_word0_bit0`](../../src/leon2m/panel/panel_layer4_get_word0_bit0.c) | `FUN_a0110084` | Return bit 0 of word 0 of the fourth layer's first register set. | descriptive |
| [`panel_layer4_hide`](../../src/leon2m/panel/panel_layer4_hide.c) | `FUN_a010f724` | Mark the fourth layer as hidden and write its position words back. | descriptive |
| [`panel_layer4_read_block_word`](../../src/leon2m/panel/panel_layer4_read_block_word.c) | `FUN_a010daf8` | Read a word of the fourth layer's register block. | descriptive |
| [`panel_layer4_read_half_block_word`](../../src/leon2m/panel/panel_layer4_read_half_block_word.c) | `FUN_a010db74` | Read a word of the fourth layer's register block in one output half. | descriptive |
| [`panel_layer4_refresh_buffer_address`](../../src/leon2m/panel/panel_layer4_refresh_buffer_address.c) | `FUN_a01101a8` | Recompute the two buffer address words (base >> 5) of the fourth layer and write them. | descriptive |
| [`panel_layer4_set_alpha_byte`](../../src/leon2m/panel/panel_layer4_set_alpha_byte.c) | `FUN_a010c54c` | Store a byte of the fourth layer and write it to block word 5. | descriptive |
| [`panel_layer4_set_buffer`](../../src/leon2m/panel/panel_layer4_set_buffer.c) | `FUN_a010dc8c` | Store the buffer parameters of the fourth layer and program them. | descriptive |
| [`panel_layer4_set_color_key`](../../src/leon2m/panel/panel_layer4_set_color_key.c) | `FUN_a010e0f4` | Store a selector and two values of the fourth layer and write its control bits. | descriptive |
| `panel_layer4_set_color_key_jump_table` | `switchdataD_a010b41c` | Jump table 1 of the switch statements in panel_layer4_set_color_key. | proven |
| `panel_layer4_set_color_key_jump_table2` | `switchdataD_a010b430` | Jump table 2 of the switch statements in panel_layer4_set_color_key. | proven |
| [`panel_layer4_set_format`](../../src/leon2m/panel/panel_layer4_set_format.c) | `FUN_a010d914` | Set the pixel format of the fourth layer. | derived |
| `panel_layer4_set_format_jump_table` | `switchdataD_a010b3f8` | Jump table 1 of the switch statements in panel_layer4_set_format. | proven |
| [`panel_layer4_set_gains`](../../src/leon2m/panel/panel_layer4_set_gains.c) | `FUN_a010e624` | Store three percentages of the fourth layer and write them as 10-bit values (100 gives 1023). | descriptive |
| [`panel_layer4_set_half_width`](../../src/leon2m/panel/panel_layer4_set_half_width.c) | `FUN_a010f7a4` | Write half the row width to word 6 or 7 of both fourth-layer register sets and set bit 20 or 21. | descriptive |
| [`panel_layer4_set_mode_word`](../../src/leon2m/panel/panel_layer4_set_mode_word.c) | `FUN_a010d8c4` | Write one of two mode words of the fourth layer. | descriptive |
| [`panel_layer4_set_offsets`](../../src/leon2m/panel/panel_layer4_set_offsets.c) | `FUN_a010e8ec` | Store three percentages of the fourth layer and write them as signed 8-bit values (50 gives 0). | descriptive |
| [`panel_layer4_set_output_size`](../../src/leon2m/panel/panel_layer4_set_output_size.c) | `FUN_a010de54` | Program the panel size of one half's part of the fourth layer, with its scaling ratios. | derived |
| [`panel_layer4_set_position`](../../src/leon2m/panel/panel_layer4_set_position.c) | `FUN_a010f65c` | Write the two position words of the fourth layer with a line offset. | descriptive |
| [`panel_layer4_set_window_position`](../../src/leon2m/panel/panel_layer4_set_window_position.c) | `FUN_a010dbc4` | Set the window position of the fourth layer. | derived |
| [`panel_layer4_set_word9_bit24`](../../src/leon2m/panel/panel_layer4_set_word9_bit24.c) | `FUN_a010e448` | Set or clear bit 24 of word 9 of the fourth layer's register blocks. | descriptive |
| [`panel_layer4_setup_window`](../../src/leon2m/panel/panel_layer4_setup_window.c) | `FUN_a0110318` | Set up the fourth layer's window across both output halves, split at the middle of the panel. | derived |
| [`panel_layer4_switch_bits`](../../src/leon2m/panel/panel_layer4_switch_bits.c) | `FUN_a010fda4` | Clear one control bit of the fourth layer and set its counterpart. | descriptive |
| [`panel_layer4_update_enable_bits`](../../src/leon2m/panel/panel_layer4_update_enable_bits.c) | `FUN_a010fe50` | Set or clear the fourth layer's bits in both halves, depending on where it lies. | descriptive |
| [`panel_layer4_write_block_word`](../../src/leon2m/panel/panel_layer4_write_block_word.c) | `FUN_a010c4a0` | Write a word of the fourth layer's register blocks. | descriptive |
| [`panel_layer4_write_half_block_word`](../../src/leon2m/panel/panel_layer4_write_half_block_word.c) | `FUN_a010db2c` | Write a word of the fourth layer's register block in one output half. | descriptive |
| [`panel_layer_clear_word0_bit0_or_bit4`](../../src/leon2m/panel/panel_layer_clear_word0_bit0_or_bit4.c) | `FUN_a010f50c` | Clear bit 0 (argument 0) or bit 4 (otherwise) of block word 0 of a channel layer, or of all three. | descriptive |
| [`panel_layer_clear_word1_bit14`](../../src/leon2m/panel/panel_layer_clear_word1_bit14.c) | `FUN_a010ef64` | Clear bit 14 of word 1 in the register blocks of one layer, or of all three. | descriptive |
| [`panel_layer_hide`](../../src/leon2m/panel/panel_layer_hide.c) | `FUN_a010ed50` | Mark a layer as hidden and write its two position words back. | descriptive |
| [`panel_layer_is_status_set`](../../src/leon2m/panel/panel_layer_is_status_set.c) | `FUN_a010b96c` | Return whether a layer's status bit is set in either output half. | descriptive |
| [`panel_layer_read_alt_block_word`](../../src/leon2m/panel/panel_layer_read_alt_block_word.c) | `FUN_a010b4fc` | Read a word of the second register block set of a layer. | descriptive |
| [`panel_layer_read_block_word`](../../src/leon2m/panel/panel_layer_read_block_word.c) | `FUN_a010b5dc` | Read a word of the register block of a layer. | descriptive |
| [`panel_layer_read_half_block_word`](../../src/leon2m/panel/panel_layer_read_half_block_word.c) | `FUN_a010bea4` | Read a word of a layer's register block in one output half. | descriptive |
| [`panel_layer_refresh_buffer_address`](../../src/leon2m/panel/panel_layer_refresh_buffer_address.c) | `FUN_a01100a4` | Recompute the two buffer address words (base >> 5) of a channel layer and write them. | descriptive |
| [`panel_layer_set_alpha_byte`](../../src/leon2m/panel/panel_layer_set_alpha_byte.c) | `FUN_a010c390` | Store a byte of a layer and write it to bits 16..23 of block word 4. | descriptive |
| [`panel_layer_set_buffer`](../../src/leon2m/panel/panel_layer_set_buffer.c) | `FUN_a010baf4` | Store the buffer parameters of a channel layer and program them. | descriptive |
| [`panel_layer_set_color_key`](../../src/leon2m/panel/panel_layer_set_color_key.c) | `FUN_a010c61c` | Store a selector and two values of a channel layer and write its control words. | descriptive |
| `panel_layer_set_color_key_jump_table` | `switchdataD_a010b3e4` | Jump table 1 of the switch statements in panel_layer_set_color_key. | proven |
| [`panel_layer_set_ctrl_bit8_clear_bit1`](../../src/leon2m/panel/panel_layer_set_ctrl_bit8_clear_bit1.c) | `FUN_a010fc74` | For channel 0..2: set bit 8 + channel, clear bit 1 + channel of layer control word 1, both halves. | descriptive |
| [`panel_layer_set_field_2c`](../../src/leon2m/panel/panel_layer_set_field_2c.c) | `FUN_a010ec70` | Write a 3-bit field of register 0x2C of both halves. | descriptive |
| [`panel_layer_set_field_2c_clear_bit0`](../../src/leon2m/panel/panel_layer_set_field_2c_clear_bit0.c) | `FUN_a010d838` | Clear bit 0 and put a value in bits 16..18 of register 0x2C; write the result to both halves. | descriptive |
| [`panel_layer_set_format`](../../src/leon2m/panel/panel_layer_set_format.c) | `FUN_a010c194` | Set the pixel format of a channel layer in both output halves. | derived |
| `panel_layer_set_format_jump_table` | `switchdataD_a010b3bc` | Jump table 1 of the switch statements in panel_layer_set_format. | proven |
| [`panel_layer_set_half_width`](../../src/leon2m/panel/panel_layer_set_half_width.c) | `FUN_a010edbc` | Program half of the panel width into the channel register blocks of both halves. | descriptive |
| [`panel_layer_set_output_size`](../../src/leon2m/panel/panel_layer_set_output_size.c) | `FUN_a010bee4` | Store one half's output width and the window lines of a channel layer; program size and scaling. | derived |
| [`panel_layer_set_slot_values`](../../src/leon2m/panel/panel_layer_set_slot_values.c) | `FUN_a010f064` | Write two packed values into one of two slots of a channel's second-set blocks in both halves. | descriptive |
| [`panel_layer_set_stream_mode`](../../src/leon2m/panel/panel_layer_set_stream_mode.c) | `FUN_a010ebd0` | Write the mode word chosen by two selectors to the stream registers of both halves. | descriptive |
| [`panel_layer_set_update_strobe_enabled`](../../src/leon2m/panel/panel_layer_set_update_strobe_enabled.c) | `FUN_a010b444` | Store the byte that switches the layer update request and its wait on or off. | derived |
| [`panel_layer_set_window_position`](../../src/leon2m/panel/panel_layer_set_window_position.c) | `FUN_a010bdcc` | Set the window position of a channel layer. | derived |
| [`panel_layer_set_word3d_bit24`](../../src/leon2m/panel/panel_layer_set_word3d_bit24.c) | `FUN_a010d068` | Set or clear bit 24 of word 0x3D of a channel layer's register blocks. | descriptive |
| [`panel_layer_show_with_flag`](../../src/leon2m/panel/panel_layer_show_with_flag.c) | `FUN_a010eca8` | Mark one of the three layers as shown and write its two position words with a flag. | descriptive |
| [`panel_layer_stream_data`](../../src/leon2m/panel/panel_layer_stream_data.c) | `FUN_a0110d64` | Stream a block of data words into the stream register of both halves. | descriptive |
| [`panel_layer_strobe_update`](../../src/leon2m/panel/panel_layer_strobe_update.c) | `FUN_a011023c` | Trigger the update of a layer and wait until the hardware has taken it. | derived |
| [`panel_layer_update_enable_bits`](../../src/leon2m/panel/panel_layer_update_enable_bits.c) | `FUN_a010f8fc` | Set or clear a channel layer's enable bits in both halves, depending on where it lies. | descriptive |
| [`panel_layer_write_alt_block_word`](../../src/leon2m/panel/panel_layer_write_alt_block_word.c) | `FUN_a010b450` | Write a word of the second register block set of one layer, or of all three. | descriptive |
| [`panel_layer_write_block_word`](../../src/leon2m/panel/panel_layer_write_block_word.c) | `FUN_a010b530` | Write a word of the register blocks of one layer, or of all three. | descriptive |
| [`panel_layer_write_half_block_word`](../../src/leon2m/panel/panel_layer_write_half_block_word.c) | `FUN_a010baac` | Write a word of a layer's register block in one output half. | descriptive |
| [`panel_layers_are_enabled`](../../src/leon2m/panel/panel_layers_are_enabled.c) | `FUN_a010b948` | Return whether the layer stage is switched on. | descriptive |
| [`panel_layers_disable`](../../src/leon2m/panel/panel_layers_disable.c) | `FUN_a010b918` | Switch the layer stage of both output halves off. | descriptive |
| [`panel_layers_enable`](../../src/leon2m/panel/panel_layers_enable.c) | `FUN_a010b8e8` | Switch the layer stage of both output halves on. | descriptive |
| [`panel_level_gen_clear_10c_bit0`](../../src/leon2m/panel/panel_level_gen_clear_10c_bit0.c) | `FUN_a0101aa0` | Clear bit 0 of register 0xCF01610C. | descriptive |
| [`panel_level_gen_clear_ctrl_bit0`](../../src/leon2m/panel/panel_level_gen_clear_ctrl_bit0.c) | `FUN_a01016e8` | Clear bit 0 of the level generator's first control register. | descriptive |
| [`panel_level_gen_clear_ctrl_bit3`](../../src/leon2m/panel/panel_level_gen_clear_ctrl_bit3.c) | `FUN_a01019e4` | Clear bit 3 of the level generator's first control register. | descriptive |
| [`panel_level_gen_enable`](../../src/leon2m/panel/panel_level_gen_enable.c) | `FUN_a0129bfc` | Switch the level generator on. | descriptive |
| [`panel_level_gen_get_min_level`](../../src/leon2m/panel/panel_level_gen_get_min_level.c) | `FUN_a0101cb4` | Return the low byte of level generator register 0xCF0160C8. | descriptive |
| [`panel_level_gen_get_reg_e0`](../../src/leon2m/panel/panel_level_gen_get_reg_e0.c) | `FUN_a0101a00` | Return the low byte of register 0xCF0160E0. | descriptive |
| [`panel_level_gen_get_reg_e4`](../../src/leon2m/panel/panel_level_gen_get_reg_e4.c) | `FUN_a0101a14` | Return the low byte of register 0xCF0160E4. | descriptive |
| [`panel_level_gen_is_ready`](../../src/leon2m/panel/panel_level_gen_is_ready.c) | `FUN_a0101b78` | Return whether the level generator reports ready. | descriptive |
| [`panel_level_gen_load_table`](../../src/leon2m/panel/panel_level_gen_load_table.c) | `FUN_a0101704` | Load the 128-byte table of the level generator. | derived |
| [`panel_level_gen_ramp_next`](../../src/leon2m/panel/panel_level_gen_ramp_next.c) | `FUN_a0101bb0` | Advance the level generator's ramp value by one, with an optional reset first. | descriptive |
| [`panel_level_gen_ramp_step`](../../src/leon2m/panel/panel_level_gen_ramp_step.c) | `FUN_a0129c10` | Advance the level generator's ramp by one step and switch the generator on when it ends. | descriptive |
| [`panel_level_gen_set_bit6`](../../src/leon2m/panel/panel_level_gen_set_bit6.c) | `FUN_a0101b20` | Write bit 6 of the level generator's control register. | descriptive |
| [`panel_level_gen_set_cc_bit5`](../../src/leon2m/panel/panel_level_gen_set_cc_bit5.c) | `FUN_a01018b0` | Set or clear bit 5 of register 0xCF0160CC. | descriptive |
| [`panel_level_gen_set_ctrl_bit0`](../../src/leon2m/panel/panel_level_gen_set_ctrl_bit0.c) | `FUN_a01016cc` | Set bit 0 of the level generator's first control register. | descriptive |
| [`panel_level_gen_set_ctrl_bit1`](../../src/leon2m/panel/panel_level_gen_set_ctrl_bit1.c) | `FUN_a01018e8` | Set bit 1 of the level generator's first control register. | descriptive |
| [`panel_level_gen_set_ctrl_high_bits`](../../src/leon2m/panel/panel_level_gen_set_ctrl_high_bits.c) | `FUN_a0101950` | Put a 4-bit value in bits 4..7 of the level generator's first control register, then set bit 3. | descriptive |
| [`panel_level_gen_set_d8_low4`](../../src/leon2m/panel/panel_level_gen_set_d8_low4.c) | `FUN_a010192c` | Write the low four bits of register 0xCF0160D8. | descriptive |
| [`panel_level_gen_set_enable`](../../src/leon2m/panel/panel_level_gen_set_enable.c) | `FUN_a0101c64` | Switch the level generator on or off. | descriptive |
| [`panel_level_gen_set_f4_bit4`](../../src/leon2m/panel/panel_level_gen_set_f4_bit4.c) | `FUN_a01019b4` | Write bit 4 of register 0xCF0160F4. | descriptive |
| [`panel_level_gen_set_f4_lower_field`](../../src/leon2m/panel/panel_level_gen_set_f4_lower_field.c) | `FUN_a0101a70` | Write the 3-bit field at bits 1-3 of register 0xCF0160F4. | descriptive |
| [`panel_level_gen_set_f4_upper_field`](../../src/leon2m/panel/panel_level_gen_set_f4_upper_field.c) | `FUN_a0101984` | Write the 2-bit field at bits 5-6 of register 0xCF0160F4. | descriptive |
| [`panel_level_gen_set_fields_10c`](../../src/leon2m/panel/panel_level_gen_set_fields_10c.c) | `FUN_a0101abc` | Write two fields of the level generator's register 0xCF01610C. | descriptive |
| [`panel_level_gen_set_frequency`](../../src/leon2m/panel/panel_level_gen_set_frequency.c) | `FUN_a010178c` | Program the level generator's divider for a frequency. | derived |
| [`panel_level_gen_set_level_pair`](../../src/leon2m/panel/panel_level_gen_set_level_pair.c) | `FUN_a0101a28` | Write the minimum level byte to 0xCF0160C8 and the level byte to 0xCF0160DC. | descriptive |
| [`panel_level_gen_set_min_level`](../../src/leon2m/panel/panel_level_gen_set_min_level.c) | `FUN_a0101c9c` | Write the low byte of level generator register 0xCF0160C8. | descriptive |
| [`panel_level_gen_set_reg_0c4`](../../src/leon2m/panel/panel_level_gen_set_reg_0c4.c) | `FUN_a0101884` | Write two 4-bit fields of register 0xCF0160C4. | descriptive |
| [`panel_level_gen_set_reg_104`](../../src/leon2m/panel/panel_level_gen_set_reg_104.c) | `FUN_a0101868` | Write two 4-bit fields of register 0xCF016104. | descriptive |
| [`panel_level_gen_set_reg_108`](../../src/leon2m/panel/panel_level_gen_set_reg_108.c) | `FUN_a0101a4c` | Write two 4-bit fields of register 0xCF016108. | descriptive |
| [`panel_level_gen_set_reg_110`](../../src/leon2m/panel/panel_level_gen_set_reg_110.c) | `FUN_a0101af0` | Write the level generator's register 0xCF016110. | descriptive |
| [`panel_level_gen_set_reg_110_copy`](../../src/leon2m/panel/panel_level_gen_set_reg_110_copy.c) | `FUN_a0101b48` | Write the level generator's register 0xCF016110. | descriptive |
| [`panel_level_gen_set_reg_114`](../../src/leon2m/panel/panel_level_gen_set_reg_114.c) | `FUN_a0101b08` | Write the level generator's register 0xCF016114. | descriptive |
| [`panel_level_gen_set_reg_114_copy`](../../src/leon2m/panel/panel_level_gen_set_reg_114_copy.c) | `FUN_a0101b60` | Write the level generator's register 0xCF016114. | descriptive |
| [`panel_level_gen_set_target`](../../src/leon2m/panel/panel_level_gen_set_target.c) | `FUN_a0129edc` | Compute the generator's target level from a record and set the generator up for it. | descriptive |
| [`panel_level_gen_step_to_target`](../../src/leon2m/panel/panel_level_gen_step_to_target.c) | `FUN_a0129c64` | Step the generator level towards its target and select the matching table entry. | descriptive |
| [`panel_level_gen_stop_ramp`](../../src/leon2m/panel/panel_level_gen_stop_ramp.c) | `FUN_a0101904` | Clear bit 6 of the control register and write 0xFF to register 0xCF016114. | descriptive |
| [`panel_output_apply_timing`](../../src/leon2m/panel/panel_output_apply_timing.c) | `FUN_a01023f4` | Program the output timing block from the active panel timing row. | proven |
| [`panel_output_get_source_select`](../../src/leon2m/panel/panel_output_get_source_select.c) | `FUN_a0106228` | Return 1, 2, 3 or 4 for the first set bit (0, 1, 2 or 4) of the output stage's source select. | descriptive |
| [`panel_output_pulse_rate_update`](../../src/leon2m/panel/panel_output_pulse_rate_update.c) | `FUN_a010b6e4` | Set bits 10 and 14 of register 0xF0 of both output halves, wait for two sync pulses, clear them. | descriptive |
| [`panel_output_restart_sequence`](../../src/leon2m/panel/panel_output_restart_sequence.c) | `FUN_a010b77c` | Run the restart bit sequence of the output halves. | descriptive |
| [`panel_output_set_clock_bits`](../../src/leon2m/panel/panel_output_set_clock_bits.c) | `FUN_a010b884` | Set clock bits of the output stage by a selector. | descriptive |
| [`panel_output_set_source_select`](../../src/leon2m/panel/panel_output_set_source_select.c) | `FUN_a01061c0` | Write the source select value 0, 1, 2, 4 or 0x10 of the output stage. | descriptive |
| `panel_output_set_source_select_jump_table` | `switchdataD_a0101d80` | Jump table 1 of the switch statements in panel_output_set_source_select. | proven |
| [`panel_output_set_window_mode`](../../src/leon2m/panel/panel_output_set_window_mode.c) | `FUN_a0106294` | Write 9 or 0 to the output window mode register. | descriptive |
| [`panel_output_setup_block4`](../../src/leon2m/panel/panel_output_setup_block4.c) | `FUN_a01062e0` | Set up output block 4 from the working panel timing row. | derived |
| [`panel_output_setup_channel_timing`](../../src/leon2m/panel/panel_output_setup_channel_timing.c) | `FUN_a01038c0` | Set up the display output timing for one channel. | proven |
| [`panel_output_setup_clock`](../../src/leon2m/panel/panel_output_setup_clock.c) | `FUN_a0106d64` | Set up the output path's configuration and clock modulation registers. | derived |
| [`panel_output_setup_for_display_mode`](../../src/leon2m/panel/panel_output_setup_for_display_mode.c) | `FUN_a0101e9c` | Program the output registers that depend on the display mode. | derived |
| `panel_output_setup_for_display_mode_jump_table` | `switchdataD_a0101cc8` | Jump table 1 of the switch statements in panel_output_setup_for_display_mode. | proven |
| [`panel_output_setup_path`](../../src/leon2m/panel/panel_output_setup_path.c) | `FUN_a0105150` | Set up the output path's configuration record and clock modulation. | derived |
| [`panel_power_off`](../../src/leon2m/panel/panel_power_off.c) | `FUN_a0124874` | Switch the panel power pin off. | proven |
| [`panel_power_sequencer_task`](../../src/leon2m/panel/panel_power_sequencer_task.c) | `FUN_a01413d0` | Run the panel power sequencer: switch the supplies and signals in timed steps. | proven |
| `panel_power_sequencer_task_jump_table` | `switchdataD_a0141290` | Jump table 1 of the switch statements in panel_power_sequencer_task. | proven |
| [`panel_pwm_clear_control`](../../src/leon2m/panel/panel_pwm_clear_control.c) | `FUN_a011e148` | Clear the enable and the two low control bits of a PWM channel. | descriptive |
| `panel_pwm_clear_control_jump_table` | `switchdataD_a011d470` | Jump table 1 of the switch statements in panel_pwm_clear_control. | proven |
| [`panel_pwm_enable`](../../src/leon2m/panel/panel_pwm_enable.c) | `FUN_a011e028` | Switch a PWM channel on or off; other channel numbers switch the six main ones. | derived |
| [`panel_pwm_enable_channel`](../../src/leon2m/panel/panel_pwm_enable_channel.c) | `FUN_a011e8fc` | Switch a grouped PWM channel 0x10..0x17 on or off. | derived |
| `panel_pwm_enable_channel_jump_table` | `switchdataD_a011d630` | Jump table 1 of the switch statements in panel_pwm_enable_channel. | proven |
| `panel_pwm_enable_channel_jump_table2` | `switchdataD_a011d650` | Jump table 2 of the switch statements in panel_pwm_enable_channel. | proven |
| `panel_pwm_enable_jump_table` | `switchdataD_a011d3f0` | Jump table 1 of the switch statements in panel_pwm_enable. | proven |
| [`panel_pwm_get_ch5_value`](../../src/leon2m/panel/panel_pwm_get_ch5_value.c) | `FUN_a011e630` | Return the 10-bit value of the register pair +4 / +8 of PWM channel 5. | descriptive |
| [`panel_pwm_init_group`](../../src/leon2m/panel/panel_pwm_init_group.c) | `FUN_a011e6dc` | Write the fixed start values of the grouped PWM channels. | derived |
| [`panel_pwm_set_ch5_value`](../../src/leon2m/panel/panel_pwm_set_ch5_value.c) | `FUN_a011e5fc` | Write a 10-bit value to the register pair +4 / +8 of PWM channel 5. | descriptive |
| [`panel_pwm_set_channel_delay`](../../src/leon2m/panel/panel_pwm_set_channel_delay.c) | `FUN_a011e4c8` | Write the delay byte of a PWM channel 16..24, or of all nine. | derived |
| `panel_pwm_set_channel_delay_jump_table` | `switchdataD_a011d60c` | Jump table 1 of the switch statements in panel_pwm_set_channel_delay. | proven |
| [`panel_pwm_set_channel_output_mode`](../../src/leon2m/panel/panel_pwm_set_channel_output_mode.c) | `FUN_a011e794` | Write the 2-bit output mode of a grouped PWM channel 0x10..0x17. | descriptive |
| [`panel_pwm_set_clock_fields`](../../src/leon2m/panel/panel_pwm_set_clock_fields.c) | `FUN_a011d670` | Write two 2-bit clock fields of a PWM channel. | descriptive |
| [`panel_pwm_set_control_bit3`](../../src/leon2m/panel/panel_pwm_set_control_bit3.c) | `FUN_a011e438` | Write control bit 3 of one of the six main PWM channels. | descriptive |
| `panel_pwm_set_control_bit3_jump_table` | `switchdataD_a011d5f0` | Jump table 1 of the switch statements in panel_pwm_set_control_bit3. | proven |
| [`panel_pwm_set_control_bit6`](../../src/leon2m/panel/panel_pwm_set_control_bit6.c) | `FUN_a011e388` | Write control bit 6 of a PWM channel. | descriptive |
| `panel_pwm_set_control_bit6_jump_table` | `switchdataD_a011d570` | Jump table 1 of the switch statements in panel_pwm_set_control_bit6. | proven |
| [`panel_pwm_set_duty`](../../src/leon2m/panel/panel_pwm_set_duty.c) | `FUN_a011dd9c` | Write the 10-bit duty value of a PWM channel. | derived |
| `panel_pwm_set_duty_jump_table` | `switchdataD_a011d384` | Jump table 1 of the switch statements in panel_pwm_set_duty. | proven |
| [`panel_pwm_set_group_sync_mode`](../../src/leon2m/panel/panel_pwm_set_group_sync_mode.c) | `FUN_a011e690` | Wait for a frame, then set the 2-bit mode at the top of register 0xCF016404. | descriptive |
| [`panel_pwm_set_group_value`](../../src/leon2m/panel/panel_pwm_set_group_value.c) | `FUN_a011e65c` | Write a 10-bit value to the register pair 0xCF016404/0xCF016408. | descriptive |
| [`panel_pwm_set_mode_field`](../../src/leon2m/panel/panel_pwm_set_mode_field.c) | `FUN_a011e220` | Write the mode of a PWM channel: a 2-bit field, or one bit plus a shared 2-bit group field. | descriptive |
| `panel_pwm_set_mode_field_jump_table` | `switchdataD_a011d4f0` | Jump table 1 of the switch statements in panel_pwm_set_mode_field. | proven |
| [`panel_request_power`](../../src/leon2m/panel/panel_request_power.c) | `FUN_a01412b8` | Ask the panel power sequencer to switch the panel on or off. | proven |
| [`panel_set_clock_from_row`](../../src/leon2m/panel/panel_set_clock_from_row.c) | `FUN_a0102f6c` | Program the display clocks from the clock field of the working panel timing row. | derived |
| [`panel_set_pll_frequency`](../../src/leon2m/panel/panel_set_pll_frequency.c) | `FUN_a01026e8` | Program one of the display clock generators for a frequency. | proven |
| `panel_set_pll_frequency_jump_table` | `switchdataD_a0101d10` | Jump table 1 of the switch statements in panel_set_pll_frequency. | proven |
| [`panel_set_working_row`](../../src/leon2m/panel/panel_set_working_row.c) | `FUN_a0105c0c` | Store the working copy of the panel timing row. | proven |
| [`panel_setup_output_after_row_change`](../../src/leon2m/panel/panel_setup_output_after_row_change.c) | `FUN_a015373c` | Set up the output path again after the panel mode row changed. | proven |
| `panel_setup_output_after_row_change_jump_table` | `switchdataD_a015128c` | Jump table 1 of the switch statements in panel_setup_output_after_row_change. | proven |
| [`panel_spread_configure`](../../src/leon2m/panel/panel_spread_configure.c) | `FUN_a0104f48` | Configure the clock modulation, or switch it off. | derived |
| [`panel_spread_disable`](../../src/leon2m/panel/panel_spread_disable.c) | `FUN_a0101e70` | Clear the enable bit of the two clock modulation blocks. | descriptive |
| [`panel_spread_set_enable_from_row`](../../src/leon2m/panel/panel_spread_set_enable_from_row.c) | `FUN_a0104cb0` | Switch the clock modulation on or off as the working panel timing row says. | descriptive |
| [`panel_spread_set_field_hi`](../../src/leon2m/panel/panel_spread_set_field_hi.c) | `FUN_a0104e80` | Write bits 5..7 of the clock modulation control byte. | descriptive |
| [`panel_spread_set_field_lo`](../../src/leon2m/panel/panel_spread_set_field_lo.c) | `FUN_a0104e50` | Write bits 1..4 of the clock modulation control byte. | descriptive |
| [`panel_spread_set_fields`](../../src/leon2m/panel/panel_spread_set_fields.c) | `FUN_a0104eb0` | Write both fields of the clock modulation control byte and its enable bit. | descriptive |
| [`panel_spread_set_rate_and_depth`](../../src/leon2m/panel/panel_spread_set_rate_and_depth.c) | `FUN_a0104d18` | Program the rate and depth of the clock modulation. | derived |
| [`panel_transform_row`](../../src/leon2m/panel/panel_transform_row.c) | `FUN_a0141840` | Build the working copy of a panel timing row and hand it to the output set-up. | derived |
| [`panel_user_map_brightness_knee`](../../src/leon2m/panel/panel_user_map_brightness_knee.c) | `FUN_a00d3e28` | Map a brightness setting through a two-segment line with a stored knee. | descriptive |
| [`panel_user_map_brightness_knee_879`](../../src/leon2m/panel/panel_user_map_brightness_knee_879.c) | `FUN_a00d3ee0` | Map a brightness setting through the two-segment line with the knee 879. | descriptive |
| [`panel_user_map_brightness_knee_auto`](../../src/leon2m/panel/panel_user_map_brightness_knee_auto.c) | `FUN_a00d3f80` | Map a brightness setting through the two-segment line with the knee 272 or 879. | descriptive |
| [`panel_user_rescale_brightness`](../../src/leon2m/panel/panel_user_rescale_brightness.c) | `FUN_a00d3dbc` | Rescale a brightness value around its base 0x7E under two setting flags. | descriptive |
| [`panel_user_set_output_on`](../../src/leon2m/panel/panel_user_set_output_on.c) | `FUN_a00d91fc` | Switch the picture output on, or switch the panel off in the proper order. | derived |
| [`panel_user_set_pwm7_percent`](../../src/leon2m/panel/panel_user_set_pwm7_percent.c) | `FUN_a00da714` | Set PWM channel 7 to a percentage. | descriptive |
| [`panel_vx1_is_locked`](../../src/leon2m/panel/panel_vx1_is_locked.c) | `FUN_a0122d40` | Return whether the V-by-One status register reads 4. | derived |
| [`panel_vx1_measure_lane_clock`](../../src/leon2m/panel/panel_vx1_measure_lane_clock.c) | `FUN_a0105a94` | Measure the clock that sets the V-by-One lane speed. | derived |
| [`panel_vx1_set_group_level`](../../src/leon2m/panel/panel_vx1_set_group_level.c) | `FUN_a0122634` | Set the level of one or all of the four lane groups. | descriptive |
| [`panel_vx1_set_group_table_value`](../../src/leon2m/panel/panel_vx1_set_group_table_value.c) | `FUN_a01112c0` | Write an entry of a 13-byte table to one or all of the four lane groups. | descriptive |
| [`panel_vx1_set_group_value`](../../src/leon2m/panel/panel_vx1_set_group_value.c) | `FUN_a0122480` | Write a value to one or all of the four lane groups. | descriptive |
| [`panel_vx1_set_two_params`](../../src/leon2m/panel/panel_vx1_set_two_params.c) | `FUN_a0122cd8` | Store two V-by-One parameters after range checks. | descriptive |
| [`panel_vx1_setup_lanes`](../../src/leon2m/panel/panel_vx1_setup_lanes.c) | `FUN_a01227f0` | Set up the lanes of the V-by-One link. | proven |
| `panel_vx1_setup_lanes_jump_table` | `switchdataD_a0121f40` | Jump table 1 of the switch statements in panel_vx1_setup_lanes. | proven |
| [`panel_vx1_setup_transmitter`](../../src/leon2m/panel/panel_vx1_setup_transmitter.c) | `FUN_a0121f58` | Set up the V-by-One transmitter blocks for the display mode. | derived |
| [`panel_vx1_start_transmitter`](../../src/leon2m/panel/panel_vx1_start_transmitter.c) | `FUN_a011149c` | Run the start-up sequence of the V-by-One transmitter. | proven |
| [`panel_vx1_write_fixed_setup`](../../src/leon2m/panel/panel_vx1_write_fixed_setup.c) | `FUN_a01223b0` | Write the fixed set-up values of the V-by-One output stage. | derived |
| [`panel_vx1_write_fixed_setup_alt`](../../src/leon2m/panel/panel_vx1_write_fixed_setup_alt.c) | `FUN_a01111f4` | Write the second set of fixed set-up values of the V-by-One output stage. | derived |
| [`panel_vx1_write_lane_config`](../../src/leon2m/panel/panel_vx1_write_lane_config.c) | `FUN_a01222c8` | Write the lane configuration registers from two bytes of the working panel timing row. | descriptive |
| `panel_vx1_write_lane_config_jump_table` | `switchdataD_a0121f28` | Jump table 1 of the switch statements in panel_vx1_write_lane_config. | proven |
| [`panel_vx1_write_test_sequence`](../../src/leon2m/panel/panel_vx1_write_test_sequence.c) | `FUN_a0122250` | Write a register sequence to the V-by-One block and shift a walking bit through it. | descriptive |
| [`panel_wait_sync_pulse`](../../src/leon2m/panel/panel_wait_sync_pulse.c) | `FUN_a002e2a4` | Wait for one pulse of status bit 0xCF00EE1C.7 (polarity from 0xCF00ED58.4), 100-tick limit. | derived |
| [`PanelPowerOn`](../../src/leon2m/panel/PanelPowerOn.c) | `FUN_a0124850` | Print the message and switch the panel power pin on. | proven |
| [`ResetVx1`](../../src/leon2m/panel/ResetVx1.c) | `FUN_a0122d0c` | Reset the V-by-One link with a one-millisecond pulse. | proven |
| [`SetBrightness`](../../src/leon2m/panel/SetBrightness.c) | `FUN_a0143804` | Print the brightness value and write it to the panel. | proven |
| [`SetBrightness_copy`](../../src/leon2m/panel/SetBrightness_copy.c) | `FUN_a0145eb8` | Print the brightness value and write it to the panel. | proven |
| [`SetPSMMixMode`](../../src/leon2m/panel/SetPSMMixMode.c) | `FUN_a014fe78` | Switch the PSM mix mode on or off and program the PWM channels for it. | proven |
| [`SYSAPI_GetPanelParamStruct`](../../src/leon2m/panel/SYSAPI_GetPanelParamStruct.c) | `FUN_a00dac38` | Choose the panel timing row that fits the incoming refresh rate and make it active. | proven |
| [`SYSAPI_PanelOnOffControl`](../../src/leon2m/panel/SYSAPI_PanelOnOffControl.c) | `FUN_a014512c` | Switch the panel on or off through the power sequencer, optionally waiting until it is done. | proven |

<a id="oled"></a>
## OLED panel care

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`oled_choose_recover_mode`](../../src/leon2m/oled/oled_choose_recover_mode.c) | `FUN_a0127b24` | Decide whether an off sensing run must start while the OLED power machine idles: 2 or 0. | derived |
| [`oled_controller_disable`](../../src/leon2m/oled/oled_controller_disable.c) | `FUN_a01248ac` | Switch the enable pin of the OLED panel controller off. | derived |
| [`oled_controller_enable`](../../src/leon2m/oled/oled_controller_enable.c) | `FUN_a0124890` | Switch the enable pin of the OLED panel controller on. | derived |
| [`oled_flag_registers_read`](../../src/leon2m/oled/oled_flag_registers_read.c) | `FUN_a00fe47c` | Read the 16-bit flag value kept in registers 0xCF009BB4 / 0xCF009BB8. | descriptive |
| [`oled_flag_registers_write`](../../src/leon2m/oled/oled_flag_registers_write.c) | `FUN_a00fe44c` | Write the 16-bit flag value kept in registers 0xCF009BB4 / 0xCF009BB8. | descriptive |
| [`oled_frc_apply_default_row`](../../src/leon2m/oled/oled_frc_apply_default_row.c) | `FUN_a0129810` | Make ROM row 1 the active panel timing row when the converter runs and no row was sent. | descriptive |
| [`oled_frc_get_row`](../../src/leon2m/oled/oled_frc_get_row.c) | `FUN_a01295c4` | Return the refresh-rate row index that is sent to the panel. | derived |
| [`oled_frc_request_send`](../../src/leon2m/oled/oled_frc_request_send.c) | `FUN_a01295d0` | Request that the chosen refresh-rate row is sent to the panel. | derived |
| [`oled_frc_reset`](../../src/leon2m/oled/oled_frc_reset.c) | `FUN_a0129598` | Reset the state of the OLED refresh-rate row handler. | derived |
| [`oled_frc_set_row`](../../src/leon2m/oled/oled_frc_set_row.c) | `FUN_a01295b8` | Store the refresh-rate row index that is sent to the panel. | derived |
| [`oled_frc_task`](../../src/leon2m/oled/oled_frc_task.c) | `FUN_a01295e4` | Send the refresh-rate row index to the OLED panel controller and resend it on request. | proven |
| [`oled_get_care_table_byte`](../../src/leon2m/oled/oled_get_care_table_byte.c) | `FUN_a0127a08` | Return a byte of the four-entry care table, the last one for index 0xFF. | descriptive |
| [`oled_get_care_table_count`](../../src/leon2m/oled/oled_get_care_table_count.c) | `FUN_a0127a00` | Return 4, the number of care table entries. | derived |
| [`oled_get_frame_rate_control`](../../src/leon2m/oled/oled_get_frame_rate_control.c) | `FUN_a0126878` | Read the refresh-rate row index back from the OLED panel controller. | proven |
| [`oled_get_lum_gain`](../../src/leon2m/oled/oled_get_lum_gain.c) | `FUN_a01264e8` | Read the luminance gain back from the OLED panel controller. | proven |
| [`oled_get_lum_mode`](../../src/leon2m/oled/oled_get_lum_mode.c) | `FUN_a01266b0` | Read the luminance mode back from the OLED panel controller. | derived |
| [`oled_get_protect_step_code`](../../src/leon2m/oled/oled_get_protect_step_code.c) | `FUN_a00b1654` | Return the panel protect step code (0x1E, 0x32, 0x37) that applies now. | descriptive |
| [`oled_is_controller_enabled`](../../src/leon2m/oled/oled_is_controller_enabled.c) | `FUN_a01248c8` | Return whether the OLED panel controller is enabled. | derived |
| [`oled_is_off_sensing_due`](../../src/leon2m/oled/oled_is_off_sensing_due.c) | `FUN_a0127a34` | Return whether enough use time has passed for the panel's off-state sensing. | derived |
| [`oled_power_get_elapsed_ticks`](../../src/leon2m/oled/oled_power_get_elapsed_ticks.c) | `FUN_a012798c` | Return the ticks passed since the state machine's time stamp. | derived |
| [`oled_power_get_field_0c`](../../src/leon2m/oled/oled_power_get_field_0c.c) | `FUN_a0127968` | Return field +0x0C of the OLED power state record. | descriptive |
| [`oled_power_get_field_0e`](../../src/leon2m/oled/oled_power_get_field_0e.c) | `FUN_a0127974` | Return field +0x0E of the OLED power state record. | descriptive |
| [`oled_power_get_field_0f`](../../src/leon2m/oled/oled_power_get_field_0f.c) | `FUN_a0127920` | Return field +0x0F of the OLED power state record. | descriptive |
| [`oled_power_get_field_10`](../../src/leon2m/oled/oled_power_get_field_10.c) | `FUN_a01279ac` | Return field +0x10 of the OLED power state record. | descriptive |
| [`oled_power_get_field_11`](../../src/leon2m/oled/oled_power_get_field_11.c) | `FUN_a01279c4` | Return field +0x11 of the OLED power state record. | descriptive |
| [`oled_power_get_field_12`](../../src/leon2m/oled/oled_power_get_field_12.c) | `FUN_a01279dc` | Return field +0x12 of the OLED power state record. | descriptive |
| [`oled_power_get_field_13`](../../src/leon2m/oled/oled_power_get_field_13.c) | `FUN_a01279f4` | Return field +0x13 of the OLED power state record. | descriptive |
| [`oled_power_get_state`](../../src/leon2m/oled/oled_power_get_state.c) | `FUN_a012792c` | Return the state of the OLED power state machine. | derived |
| [`oled_power_get_step`](../../src/leon2m/oled/oled_power_get_step.c) | `FUN_a0127944` | Return the step inside the current state of the OLED power state machine. | derived |
| [`oled_power_reset_state`](../../src/leon2m/oled/oled_power_reset_state.c) | `FUN_a0127898` | Clear the state record of the OLED power state machine. | derived |
| [`oled_power_set_field_0a`](../../src/leon2m/oled/oled_power_set_field_0a.c) | `FUN_a01278fc` | Store field +0x0A of the OLED power state record. | descriptive |
| [`oled_power_set_field_0b`](../../src/leon2m/oled/oled_power_set_field_0b.c) | `FUN_a0127908` | Store field +0x0B of the OLED power state record. | descriptive |
| [`oled_power_set_field_0c`](../../src/leon2m/oled/oled_power_set_field_0c.c) | `FUN_a012795c` | Store field +0x0C of the OLED power state record. | descriptive |
| [`oled_power_set_field_0d`](../../src/leon2m/oled/oled_power_set_field_0d.c) | `FUN_a01278f0` | Store field +0x0D of the OLED power state record. | descriptive |
| [`oled_power_set_field_0e`](../../src/leon2m/oled/oled_power_set_field_0e.c) | `FUN_a0127980` | Store field +0x0E of the OLED power state record. | descriptive |
| [`oled_power_set_field_0f`](../../src/leon2m/oled/oled_power_set_field_0f.c) | `FUN_a0127914` | Store field +0x0F of the OLED power state record. | descriptive |
| [`oled_power_set_field_09`](../../src/leon2m/oled/oled_power_set_field_09.c) | `FUN_a01278e4` | Store field +0x09 of the OLED power state record. | descriptive |
| [`oled_power_set_field_11`](../../src/leon2m/oled/oled_power_set_field_11.c) | `FUN_a01279b8` | Store field +0x11 of the OLED power state record. | descriptive |
| [`oled_power_set_field_12`](../../src/leon2m/oled/oled_power_set_field_12.c) | `FUN_a01279d0` | Store field +0x12 of the OLED power state record. | descriptive |
| [`oled_power_set_field_13`](../../src/leon2m/oled/oled_power_set_field_13.c) | `FUN_a01279e8` | Store field +0x13 of the OLED power state record. | descriptive |
| [`oled_power_set_state`](../../src/leon2m/oled/oled_power_set_state.c) | `FUN_a0127938` | Store the state of the OLED power state machine. | derived |
| [`oled_power_set_step`](../../src/leon2m/oled/oled_power_set_step.c) | `FUN_a0127950` | Store the step inside the current state of the OLED power state machine. | derived |
| [`oled_power_task`](../../src/leon2m/oled/oled_power_task.c) | `FUN_a0127c78` | Run the OLED power and care state machine. | proven |
| `oled_power_task_jump_table` | `switchdataD_a0126318` | Jump table 1 of the switch statements in oled_power_task. | proven |
| `oled_power_task_jump_table2` | `switchdataD_a012632c` | Jump table 2 of the switch statements in oled_power_task. | proven |
| `oled_power_task_jump_table3` | `switchdataD_a012634c` | Jump table 3 of the switch statements in oled_power_task. | proven |
| [`oled_read_reg_10`](../../src/leon2m/oled/oled_read_reg_10.c) | `FUN_a01269f8` | Read register 0x10 of the OLED panel controller. | descriptive |
| [`oled_read_reg_d0`](../../src/leon2m/oled/oled_read_reg_d0.c) | `FUN_a01269a4` | Read register 0xD0 of the OLED panel controller. | descriptive |
| [`oled_request_sensing_in_factory_burn_in`](../../src/leon2m/oled/oled_request_sensing_in_factory_burn_in.c) | `FUN_a0127ab8` | In factory mode with Burn In on and device setting 17 at 1: request a sensing run and return 1. | derived |
| [`oled_set_el_sensing`](../../src/leon2m/oled/oled_set_el_sensing.c) | `FUN_a0126938` | Start or stop the panel's EL sensing. | proven |
| [`oled_set_frame_rate_control`](../../src/leon2m/oled/oled_set_frame_rate_control.c) | `FUN_a0126704` | Write the refresh-rate row index to the OLED panel controller and verify it. | proven |
| [`oled_set_inspection_mode`](../../src/leon2m/oled/oled_set_inspection_mode.c) | `FUN_a01275b0` | Write the inspection mode setting to the OLED panel controller and verify it. | proven |
| [`oled_set_inspection_pattern`](../../src/leon2m/oled/oled_set_inspection_pattern.c) | `FUN_a0127724` | Write the inspection pattern setting to the OLED panel controller and verify it. | proven |
| [`oled_set_lpc`](../../src/leon2m/oled/oled_set_lpc.c) | `FUN_a0126dcc` | Write the LPC setting to the OLED panel controller and verify it. | proven |
| [`oled_set_lum_gain`](../../src/leon2m/oled/oled_set_lum_gain.c) | `FUN_a0126360` | Write the luminance gain to the OLED panel controller and verify it. | proven |
| [`oled_set_lum_mode`](../../src/leon2m/oled/oled_set_lum_mode.c) | `FUN_a012653c` | Write the luminance mode to the OLED panel controller and verify it. | proven |
| [`oled_set_multi_logo`](../../src/leon2m/oled/oled_set_multi_logo.c) | `FUN_a012743c` | Write the multi-logo detection setting to the OLED panel controller and verify it. | proven |
| [`oled_set_off_sensing`](../../src/leon2m/oled/oled_set_off_sensing.c) | `FUN_a01268cc` | Start or stop the panel's off-state sensing. | proven |
| [`oled_set_pillar_box`](../../src/leon2m/oled/oled_set_pillar_box.c) | `FUN_a0127154` | Write the pillar box setting to the OLED panel controller and verify it. | proven |
| [`oled_set_pixel_shift_on_off`](../../src/leon2m/oled/oled_set_pixel_shift_on_off.c) | `FUN_a0126ae4` | Switch the panel's pixel shift on or off and verify it. | proven |
| [`oled_set_pixel_shift_speed`](../../src/leon2m/oled/oled_set_pixel_shift_speed.c) | `FUN_a0126c58` | Write the pixel shift speed setting to the OLED panel controller and verify it. | proven |
| [`oled_set_screen_saver_range`](../../src/leon2m/oled/oled_set_screen_saver_range.c) | `FUN_a0126f4c` | Write the screen saver range setting to the OLED panel controller and verify it. | proven |
| [`oled_set_task_bar`](../../src/leon2m/oled/oled_set_task_bar.c) | `FUN_a01272c8` | Write the task bar detection setting to the OLED panel controller and verify it. | proven |
| [`oled_user_apply_multi_logo`](../../src/leon2m/oled/oled_user_apply_multi_logo.c) | `FUN_a00dac00` | Apply the multi-logo detection setting, or 0 when the function is off. | proven |
| [`oled_user_apply_pillar_box`](../../src/leon2m/oled/oled_user_apply_pillar_box.c) | `FUN_a00dab90` | Apply the pillar box setting, or 0 when the function is off. | proven |
| [`oled_user_apply_pixel_shift`](../../src/leon2m/oled/oled_user_apply_pixel_shift.c) | `FUN_a00daae8` | Apply the pixel shift on/off setting. | proven |
| [`oled_user_apply_pixel_shift_speed`](../../src/leon2m/oled/oled_user_apply_pixel_shift_speed.c) | `FUN_a00dab08` | Apply the pixel shift speed setting. | proven |
| [`oled_user_apply_screen_saver_range`](../../src/leon2m/oled/oled_user_apply_screen_saver_range.c) | `FUN_a00dab20` | Apply the screen saver range setting. | proven |
| [`oled_user_apply_task_bar`](../../src/leon2m/oled/oled_user_apply_task_bar.c) | `FUN_a00dabc8` | Apply the task bar detection setting, or 0 when the function is off. | proven |
| [`oled_user_get_temperature`](../../src/leon2m/oled/oled_user_get_temperature.c) | `FUN_a00dab30` | Return the panel temperature. | proven |
| [`oled_user_request_panel_refresh`](../../src/leon2m/oled/oled_user_request_panel_refresh.c) | `FUN_a00dab4c` | Request the panel protect run when the chosen button of its prompt is Execute (0). | derived |
| [`OLEDIIC_getTempSensing`](../../src/leon2m/oled/OLEDIIC_getTempSensing.c) | `FUN_a0126a4c` | Read the panel temperature from the OLED panel controller. | proven |

<a id="pq"></a>
## Picture: colour, gamma, windows

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`APPGetFRCMode`](../../src/leon2m/pq/APPGetFRCMode.c) | `FUN_a008380c` | Choose the frame-rate conversion mode 0..3 for channel 0 from the input rate. | proven |
| [`drv_Set3DDEISC`](../../src/leon2m/pq/drv_Set3DDEISC.c) | `FUN_a0105e60` | Find the table row for a width, height and rate and program picture block 5 with it. | proven |
| [`FGA_Init`](../../src/leon2m/pq/FGA_Init.c) | `FUN_a012cfac` | Write the default calibration tables to storage when the stored marker is missing. | proven |
| [`pq_ace_configure`](../../src/leon2m/pq/pq_ace_configure.c) | `FUN_a00f7894` | Write the ACE configuration bits and print them. | proven |
| [`pq_ace_disable_for_window`](../../src/leon2m/pq/pq_ace_disable_for_window.c) | `FUN_a00f6408` | Switch ACE off for the selected picture window. | descriptive |
| [`pq_ace_enable_for_window`](../../src/leon2m/pq/pq_ace_enable_for_window.c) | `FUN_a00f6c38` | Switch ACE on for the selected picture window. | descriptive |
| [`pq_ace_init`](../../src/leon2m/pq/pq_ace_init.c) | `FUN_a00f793c` | Initialise the four ACE selector blocks with their default tables. | proven |
| [`pq_ace_load_table_first`](../../src/leon2m/pq/pq_ace_load_table_first.c) | `FUN_a00f7534` | Set the ACE control bits and stream a 16-bit table to the block (first form). | descriptive |
| [`pq_ace_load_table_second`](../../src/leon2m/pq/pq_ace_load_table_second.c) | `FUN_a00f7608` | Set the ACE control bits and stream a 16-bit table to the block (second form). | descriptive |
| [`pq_ace_read_histogram`](../../src/leon2m/pq/pq_ace_read_histogram.c) | `FUN_a00f76dc` | Read the measured sums of the ACE block when start is 0 and no measurement is pending. | derived |
| [`pq_ace_write_curve`](../../src/leon2m/pq/pq_ace_write_curve.c) | `FUN_a00f7434` | Write a curve of 16-bit points to the ACE block, or the default curve. | derived |
| [`pq_ace_write_reg_d8`](../../src/leon2m/pq/pq_ace_write_reg_d8.c) | `FUN_a00f6cdc` | Write register 0xCF00EED8 of the ACE block. | descriptive |
| [`pq_add_channel_offset_a`](../../src/leon2m/pq/pq_add_channel_offset_a.c) | `FUN_a0150e80` | Add the signed per-channel offset (first set) to a value, stopping at 0 below and at 0xFF above. | derived |
| [`pq_add_channel_offset_b`](../../src/leon2m/pq/pq_add_channel_offset_b.c) | `FUN_a0150f44` | Add the signed per-channel offset (second set) to a value, stopping at 0 below and at 0xFF above. | derived |
| [`pq_adjust_value_mode7`](../../src/leon2m/pq/pq_adjust_value_mode7.c) | `FUN_a0083be0` | Rescale *p when settings bit 11 is set and mode byte +0x181 is 7. | descriptive |
| [`pq_api_config_ace`](../../src/leon2m/pq/pq_api_config_ace.c) | `FUN_a014737c` | Configure ACE for the picture window of a channel. | proven |
| [`pq_api_enable_channel_window`](../../src/leon2m/pq/pq_api_enable_channel_window.c) | `FUN_a0146ef4` | Switch the picture window of a channel on or off. | derived |
| [`pq_api_enable_color_matrix`](../../src/leon2m/pq/pq_api_enable_color_matrix.c) | `FUN_a0145ee8` | Switch the colour matrix on for the picture window of a channel, or off. | descriptive |
| [`pq_api_enable_preset_curves`](../../src/leon2m/pq/pq_api_enable_preset_curves.c) | `FUN_a014e19c` | Switch both preset-curve stages on or off. | derived |
| [`pq_api_enable_primary_gamma_lut`](../../src/leon2m/pq/pq_api_enable_primary_gamma_lut.c) | `FUN_a014e144` | Switch the primary gamma look-up table on, or off followed by a 20-tick delay. | derived |
| [`pq_api_enable_secondary_gamma_lut`](../../src/leon2m/pq/pq_api_enable_secondary_gamma_lut.c) | `FUN_a014e170` | Switch the secondary gamma look-up table on, or off followed by a 20-tick delay. | descriptive |
| [`pq_api_enable_window`](../../src/leon2m/pq/pq_api_enable_window.c) | `FUN_a0146fdc` | Switch picture window 0..3 on or off. | derived |
| [`pq_api_get_channel_window`](../../src/leon2m/pq/pq_api_get_channel_window.c) | `FUN_a0147064` | Return the picture window index stored for a channel. | derived |
| [`pq_api_get_mode_color_value`](../../src/leon2m/pq/pq_api_get_mode_color_value.c) | `FUN_a0145920` | Return one colour value of the picture modes. | derived |
| `pq_api_get_mode_color_value_jump_table` | `switchdataD_a01431a8` | Jump table 1 of the switch statements in pq_api_get_mode_color_value. | proven |
| [`pq_api_get_zone_average_table`](../../src/leon2m/pq/pq_api_get_zone_average_table.c) | `FUN_a014aa48` | Return the red (0), green (1) or blue (2) table of the 16 x 16 zone averages. | derived |
| [`pq_api_is_primary_gamma_lut_enabled`](../../src/leon2m/pq/pq_api_is_primary_gamma_lut_enabled.c) | `FUN_a014e2f0` | Return whether the primary gamma look-up table is switched on. | derived |
| [`pq_api_is_secondary_gamma_lut_enabled`](../../src/leon2m/pq/pq_api_is_secondary_gamma_lut_enabled.c) | `FUN_a014e308` | Return whether the secondary gamma look-up table is switched on. | descriptive |
| [`pq_api_load_ace_table`](../../src/leon2m/pq/pq_api_load_ace_table.c) | `FUN_a01474b0` | Select the picture window of a channel and write an ACE curve to it. | descriptive |
| [`pq_api_load_level_table`](../../src/leon2m/pq/pq_api_load_level_table.c) | `FUN_a0147560` | Load the first 24-entry level table for the picture window of a channel. | descriptive |
| [`pq_api_load_level_table_second`](../../src/leon2m/pq/pq_api_load_level_table_second.c) | `FUN_a0147610` | Load the second 24-entry level table for the picture window of a channel. | descriptive |
| [`pq_api_load_preset_curves`](../../src/leon2m/pq/pq_api_load_preset_curves.c) | `FUN_a014e1d0` | Switch both curve stages off, wait, and load preset curve 0..4 into both. | derived |
| `pq_api_load_preset_curves_jump_table` | `switchdataD_a01436a0` | Jump table 1 of the switch statements in pq_api_load_preset_curves. | proven |
| [`pq_api_load_profile_table`](../../src/leon2m/pq/pq_api_load_profile_table.c) | `FUN_a014dc18` | Load the built-in 1024-entry profile table into the picture hardware. | proven |
| [`pq_api_read_color_matrix`](../../src/leon2m/pq/pq_api_read_color_matrix.c) | `FUN_a01476d0` | Read the three rows of the colour matrix back from the hardware. | derived |
| [`pq_api_return_ff`](../../src/leon2m/pq/pq_api_return_ff.c) | `FUN_a014705c` | Return 0xFF. | descriptive |
| [`pq_api_set_auto_level_mode`](../../src/leon2m/pq/pq_api_set_auto_level_mode.c) | `FUN_a01492b8` | Store the mode byte and start the automatic level stepping when it is 1. | descriptive |
| [`pq_api_set_channel_offset_first`](../../src/leon2m/pq/pq_api_set_channel_offset_first.c) | `FUN_a014a210` | Store the per-channel offset of the first set for red, green or blue. | derived |
| [`pq_api_set_channel_offset_second`](../../src/leon2m/pq/pq_api_set_channel_offset_second.c) | `FUN_a014a258` | Store the per-channel offset of the second set for red, green or blue. | derived |
| [`pq_api_set_channel_window`](../../src/leon2m/pq/pq_api_set_channel_window.c) | `FUN_a01470fc` | Store the picture window index for a channel. | derived |
| [`pq_api_set_color_gain`](../../src/leon2m/pq/pq_api_set_color_gain.c) | `FUN_a014bcf0` | Store the colour gain and rebuild the colour matrix with it. | derived |
| [`pq_api_set_color_matrix_option`](../../src/leon2m/pq/pq_api_set_color_matrix_option.c) | `FUN_a0145fac` | Switch the second option of the colour matrix on or off. | descriptive |
| [`pq_api_set_color_matrix_param`](../../src/leon2m/pq/pq_api_set_color_matrix_param.c) | `FUN_a014929c` | Store a colour parameter and rebuild the colour matrix. | descriptive |
| [`pq_api_set_color_matrix_values`](../../src/leon2m/pq/pq_api_set_color_matrix_values.c) | `FUN_a01476c0` | Program the colour matrix with a set of 12 values and the two stored option bits. | descriptive |
| [`pq_api_set_color_triple`](../../src/leon2m/pq/pq_api_set_color_triple.c) | `FUN_a0145fc0` | Store three colour values and rebuild the colour matrix. | descriptive |
| [`pq_api_set_fga_byte`](../../src/leon2m/pq/pq_api_set_fga_byte.c) | `FUN_a0149228` | Store one byte in the device record field at +0x37. | descriptive |
| [`pq_api_set_fga_selector`](../../src/leon2m/pq/pq_api_set_fga_selector.c) | `FUN_a0149178` | Store the selector for index 0x30, otherwise report an unknown index. | derived |
| [`pq_api_set_fga_word`](../../src/leon2m/pq/pq_api_set_fga_word.c) | `FUN_a0149210` | Store a 16-bit value in bits 8..23 of the device settings word at +0x34 (bytes +0x35 and +0x36). | descriptive |
| [`pq_api_set_fill_color`](../../src/leon2m/pq/pq_api_set_fill_color.c) | `FUN_a0145fe8` | Set the fill colour of a port and switch the colour-fill path. | derived |
| [`pq_api_set_gamma_and_reapply`](../../src/leon2m/pq/pq_api_set_gamma_and_reapply.c) | `FUN_a014c794` | Store the gamma selection, load that gamma and apply the picture mode again. | derived |
| [`pq_api_set_gamma_lut_options`](../../src/leon2m/pq/pq_api_set_gamma_lut_options.c) | `FUN_a014e0d4` | Set the two option bits of the gamma look-up table from a value 0..3. | descriptive |
| [`pq_api_set_mode_color_value`](../../src/leon2m/pq/pq_api_set_mode_color_value.c) | `FUN_a014ce84` | Store one colour value of a picture mode and re-apply the mode if it is active. | derived |
| `pq_api_set_mode_color_value_jump_table` | `switchdataD_a0143628` | Jump table 1 of the switch statements in pq_api_set_mode_color_value. | proven |
| [`pq_api_set_picture_mode`](../../src/leon2m/pq/pq_api_set_picture_mode.c) | `FUN_a014c778` | Store the picture mode and apply it. | derived |
| [`pq_api_set_response_level`](../../src/leon2m/pq/pq_api_set_response_level.c) | `FUN_a014913c` | Store the level byte and apply it; level 5 only switches the function off. | descriptive |
| [`pq_api_set_rgb_gain`](../../src/leon2m/pq/pq_api_set_rgb_gain.c) | `FUN_a014a11c` | Store the gain 0..100 of the red, green or blue channel and apply it. | derived |
| [`pq_api_set_rgb_offset`](../../src/leon2m/pq/pq_api_set_rgb_offset.c) | `FUN_a014a2a0` | Store the offset 0..100 of the red, green or blue channel and apply it. | derived |
| [`pq_api_set_two_bit_option`](../../src/leon2m/pq/pq_api_set_two_bit_option.c) | `FUN_a01492f0` | Store an option 0..3 and write it to both 2-bit fields of the control byte. | descriptive |
| [`pq_api_set_window_item`](../../src/leon2m/pq/pq_api_set_window_item.c) | `FUN_a01471a0` | Select the picture window of a channel and set one of sixteen picture items. | derived |
| `pq_api_set_window_item_jump_table` | `switchdataD_a0143380` | Jump table 1 of the switch statements in pq_api_set_window_item. | proven |
| `pq_api_set_window_item_jump_table2` | `switchdataD_a0143398` | Jump table 2 of the switch statements in pq_api_set_window_item. | proven |
| [`pq_api_set_window_rect`](../../src/leon2m/pq/pq_api_set_window_rect.c) | `FUN_a0146e2c` | Select the picture window of a channel and write its four 16-bit coordinates. | derived |
| [`pq_api_store_color_row`](../../src/leon2m/pq/pq_api_store_color_row.c) | `FUN_a014923c` | Copy an 18-byte colour row into the selected slot and save it. | descriptive |
| [`pq_api_store_preset_index`](../../src/leon2m/pq/pq_api_store_preset_index.c) | `FUN_a0149130` | Store the preset index used for the preset table look-ups. | descriptive |
| [`pq_api_write_gamma_lut`](../../src/leon2m/pq/pq_api_write_gamma_lut.c) | `FUN_a014e26c` | Write a block of gamma table data to one colour channel, or to all three. | derived |
| [`pq_apply_frc_lock_mode`](../../src/leon2m/pq/pq_apply_frc_lock_mode.c) | `FUN_a0083aa0` | Pass bit 0 of APPGetFRCMode() to SYSAPI_ConfigSystemPostFRCLockMode. | proven |
| [`pq_apply_frc_main_bypass`](../../src/leon2m/pq/pq_apply_frc_main_bypass.c) | `FUN_a0083abc` | Pass bit 1 of APPGetFRCMode() to SYSAPI_ConfigSystemPostFRCMainBypass. | proven |
| [`pq_apply_picture_mode`](../../src/leon2m/pq/pq_apply_picture_mode.c) | `FUN_a014c118` | Select the curve and colour set-up for a picture mode and apply it. | derived |
| `pq_apply_picture_mode_jump_table` | `switchdataD_a0143534` | Jump table 1 of the switch statements in pq_apply_picture_mode. | proven |
| [`pq_apply_response_level`](../../src/leon2m/pq/pq_apply_response_level.c) | `FUN_a014110c` | Load the table set for a level and restart the block when the level changed. | descriptive |
| [`pq_apply_settings_by_mask`](../../src/leon2m/pq/pq_apply_settings_by_mask.c) | `FUN_a00874c8` | Write value v to setting ids 4..11 for each bit set in bits. | derived |
| [`pq_apply_table_entry_both_channels`](../../src/leon2m/pq/pq_apply_table_entry_both_channels.c) | `FUN_a0087d5c` | Apply entry n (0..3) of the 0x44-byte ROM records to channels 1 and 0. | descriptive |
| [`pq_auto_level_apply_brightness`](../../src/leon2m/pq/pq_auto_level_apply_brightness.c) | `FUN_a012a700` | Scale a level to the panel range, let the hook adjust it and send it as brightness. | derived |
| [`pq_auto_level_bin_difference`](../../src/leon2m/pq/pq_auto_level_bin_difference.c) | `FUN_a012a128` | Return how far one of the 16 measured values is from its stored reference. | descriptive |
| [`pq_auto_level_has_scene_changed`](../../src/leon2m/pq/pq_auto_level_has_scene_changed.c) | `FUN_a012a228` | Report whether enough of the 16 measured values moved away from the reference. | descriptive |
| [`pq_auto_level_set_weights`](../../src/leon2m/pq/pq_auto_level_set_weights.c) | `FUN_a012a1a0` | Set the 16 weights, or the default 0x3A, and store their sum. | descriptive |
| [`pq_auto_level_store_reference`](../../src/leon2m/pq/pq_auto_level_store_reference.c) | `FUN_a012a164` | Store the 16 measured values as the new reference. | descriptive |
| [`pq_auto_level_task`](../../src/leon2m/pq/pq_auto_level_task.c) | `FUN_a012a774` | Measure the picture and step the brightness level towards the computed target. | derived |
| [`pq_auto_level_update_curve`](../../src/leon2m/pq/pq_auto_level_update_curve.c) | `FUN_a012a2f0` | Rescale the 16-point curve from the measured values and step the applied curve towards it. | descriptive |
| [`pq_average_zone_color`](../../src/leon2m/pq/pq_average_zone_color.c) | `FUN_a00b9f30` | Average the red, green and blue zone statistics over a rectangle of zones. | derived |
| [`pq_block0_set_blank_mode`](../../src/leon2m/pq/pq_block0_set_blank_mode.c) | `FUN_a0105d04` | Write the blanking mode of picture block 0. | derived |
| [`pq_block5_copy_htotal_readback`](../../src/leon2m/pq/pq_block5_copy_htotal_readback.c) | `FUN_a0105d20` | Copy the 16-bit register 0x82 of picture block 5 into its registers 0x5E and 0x79. | descriptive |
| [`pq_block8_clear_ff0_bit7`](../../src/leon2m/pq/pq_block8_clear_ff0_bit7.c) | `FUN_a0118ad4` | Clear bit 7 of register 0xCF012FF0. | descriptive |
| [`pq_block8_count_reg50_step`](../../src/leon2m/pq/pq_block8_count_reg50_step.c) | `FUN_a0118994` | Count calls that find bit 0 of a block's register 0x50 set; past 50 write 0x40 or 0 to 0xCF012F00. | descriptive |
| [`pq_block8_load_tables`](../../src/leon2m/pq/pq_block8_load_tables.c) | `FUN_a0118be4` | Remember two table pointers and write the two byte tables to picture block 8. | descriptive |
| [`pq_block8_set_ff0_bit7`](../../src/leon2m/pq/pq_block8_set_ff0_bit7.c) | `FUN_a0118af0` | Set bit 7 of register 0xCF012FF0. | descriptive |
| [`pq_block8_set_mode`](../../src/leon2m/pq/pq_block8_set_mode.c) | `FUN_a0118628` | Set the mode fields of picture block 8 for a mode 1..4. | descriptive |
| [`pq_block8_set_three_enables`](../../src/leon2m/pq/pq_block8_set_three_enables.c) | `FUN_a0118b9c` | Switch three enable registers of picture block 8 on or off. | descriptive |
| [`pq_block8_set_timing`](../../src/leon2m/pq/pq_block8_set_timing.c) | `FUN_a01186e0` | Program the timing of picture block 8 from the working panel timing row. | descriptive |
| [`pq_block8_setup_ff0`](../../src/leon2m/pq/pq_block8_setup_ff0.c) | `FUN_a0118b0c` | Program registers 0xCF012FF0..FF8 from a size field of the working panel timing row. | descriptive |
| [`pq_block8_start`](../../src/leon2m/pq/pq_block8_start.c) | `FUN_a01185d4` | Start picture block 8 again after a short wait. | descriptive |
| [`pq_block8_stop`](../../src/leon2m/pq/pq_block8_stop.c) | `FUN_a011855c` | Stop picture block 8 before its settings are changed. | descriptive |
| [`pq_block_blank`](../../src/leon2m/pq/pq_block_blank.c) | `FUN_a0106ba8` | Blank a picture block and switch its output path off. | derived |
| [`pq_block_blank_with_color`](../../src/leon2m/pq/pq_block_blank_with_color.c) | `FUN_a0106bfc` | Blank a picture block with a given value and re-apply the output timing. | derived |
| [`pq_block_is_blanked`](../../src/leon2m/pq/pq_block_is_blanked.c) | `FUN_a0104c34` | Return whether a picture block is in a blanking mode. | derived |
| [`pq_block_read8`](../../src/leon2m/pq/pq_block_read8.c) | `FUN_a00f2254` | Read an 8-bit register of a picture block. | proven |
| [`pq_block_read16`](../../src/leon2m/pq/pq_block_read16.c) | `FUN_a00f25f8` | Read a 16-bit register pair of a picture block. | proven |
| [`pq_block_read16_stable`](../../src/leon2m/pq/pq_block_read16_stable.c) | `FUN_a00f2708` | Read a 16-bit register pair of a picture block until two reads agree. | proven |
| [`pq_block_read24`](../../src/leon2m/pq/pq_block_read24.c) | `FUN_a00f295c` | Read a 24-bit register triple of a picture block. | derived |
| [`pq_block_read24_stable`](../../src/leon2m/pq/pq_block_read24_stable.c) | `FUN_a00f29d4` | Read a 24-bit register triple of a picture block until two reads agree. | proven |
| [`pq_block_read_reg5b_word`](../../src/leon2m/pq/pq_block_read_reg5b_word.c) | `FUN_a0105ce4` | Read the 16-bit register 0x5B of a picture block. | descriptive |
| [`pq_block_read_reg5b_word_copy`](../../src/leon2m/pq/pq_block_read_reg5b_word_copy.c) | `FUN_a0106900` | Read the 16-bit register 0x5B of a picture block. | descriptive |
| [`pq_block_read_reg5e_word`](../../src/leon2m/pq/pq_block_read_reg5e_word.c) | `FUN_a0105cc4` | Read the 16-bit register 0x5E of a picture block. | descriptive |
| [`pq_block_read_reg5e_word_copy`](../../src/leon2m/pq/pq_block_read_reg5e_word_copy.c) | `FUN_a01068e0` | Read the 16-bit register 0x5E of a picture block. | descriptive |
| [`pq_block_read_reg6f_word`](../../src/leon2m/pq/pq_block_read_reg6f_word.c) | `FUN_a01068a0` | Read the 16-bit register 0x6F of a picture block. | descriptive |
| [`pq_block_read_reg62_word`](../../src/leon2m/pq/pq_block_read_reg62_word.c) | `FUN_a01068c0` | Read the 16-bit register 0x62 of a picture block. | descriptive |
| [`pq_block_read_reg64_word`](../../src/leon2m/pq/pq_block_read_reg64_word.c) | `FUN_a0105ca4` | Read the 16-bit register 0x64 of a picture block. | descriptive |
| [`pq_block_read_reg64_word_copy`](../../src/leon2m/pq/pq_block_read_reg64_word_copy.c) | `FUN_a0106274` | Read the 16-bit register 0x64 of a picture block. | descriptive |
| [`pq_block_read_reg66_word`](../../src/leon2m/pq/pq_block_read_reg66_word.c) | `FUN_a0106880` | Read the 16-bit register 0x66 of a picture block. | descriptive |
| [`pq_block_read_reg68_word`](../../src/leon2m/pq/pq_block_read_reg68_word.c) | `FUN_a0105c84` | Read the 16-bit register 0x68 of a picture block. | descriptive |
| [`pq_block_read_reg68_word_copy`](../../src/leon2m/pq/pq_block_read_reg68_word_copy.c) | `FUN_a01062c0` | Read the 16-bit register 0x68 of a picture block. | descriptive |
| [`pq_block_read_reg73_word`](../../src/leon2m/pq/pq_block_read_reg73_word.c) | `FUN_a0106860` | Read the 16-bit register 0x73 of a picture block. | descriptive |
| [`pq_block_read_reg89_pair_average`](../../src/leon2m/pq/pq_block_read_reg89_pair_average.c) | `FUN_a01042c8` | Read register 0x89 of a picture block in pairs one frame apart; return the average of the last pair. | descriptive |
| [`pq_block_set_blank_color`](../../src/leon2m/pq/pq_block_set_blank_color.c) | `FUN_a0103808` | Write the three blanking colour values of a picture block. | derived |
| [`pq_block_set_clock_ratio`](../../src/leon2m/pq/pq_block_set_clock_ratio.c) | `FUN_a0105790` | Compute a 16-bit ratio for a channel's block and write it. | descriptive |
| [`pq_block_set_fill_color`](../../src/leon2m/pq/pq_block_set_fill_color.c) | `FUN_a0118a80` | Write the three fill colour values of a picture block. | derived |
| [`pq_block_set_four_regs`](../../src/leon2m/pq/pq_block_set_four_regs.c) | `FUN_a0105a3c` | Write four 16-bit registers of a picture block. | descriptive |
| [`pq_block_set_mode1_and_value`](../../src/leon2m/pq/pq_block_set_mode1_and_value.c) | `FUN_a0104b2c` | Set a picture block to mode 1 and write a value to its unit register. | descriptive |
| `pq_block_set_mode1_and_value_jump_table` | `switchdataD_a0101d5c` | Jump table 1 of the switch statements in pq_block_set_mode1_and_value. | proven |
| [`pq_block_set_output_path`](../../src/leon2m/pq/pq_block_set_output_path.c) | `FUN_a0106920` | Switch the output path of a picture block on or off. | derived |
| [`pq_block_set_regs_d0_d1`](../../src/leon2m/pq/pq_block_set_regs_d0_d1.c) | `FUN_a0106d3c` | Write registers 0xD0 and 0xD1 of a picture block. | descriptive |
| [`pq_block_set_sharpness_field`](../../src/leon2m/pq/pq_block_set_sharpness_field.c) | `FUN_a00f6834` | Write a 4-bit value and an on/off flag into register 0x20 of a picture block. | descriptive |
| [`pq_block_set_window_regs`](../../src/leon2m/pq/pq_block_set_window_regs.c) | `FUN_a0105910` | Write six window values of a picture block and raise two limits when needed. | descriptive |
| [`pq_block_show`](../../src/leon2m/pq/pq_block_show.c) | `FUN_a0106b08` | Switch a picture block's output on, wait three sync pulses and switch the colour-fill path off. | derived |
| [`pq_block_update_bits`](../../src/leon2m/pq/pq_block_update_bits.c) | `FUN_a00f232c` | Set or clear bits of a register of one picture block, or of all eight. | proven |
| [`pq_block_write8`](../../src/leon2m/pq/pq_block_write8.c) | `FUN_a00f2298` | Write an 8-bit register of one picture block, or of all eight. | proven |
| [`pq_block_write16`](../../src/leon2m/pq/pq_block_write16.c) | `FUN_a00f2488` | Write a 16-bit register pair of one picture block, or of all eight. | proven |
| [`pq_clear_block8_bit1`](../../src/leon2m/pq/pq_clear_block8_bit1.c) | `FUN_a0119114` | Clear bit 1 of register 0xCF012F74 when the chip revision is above 0x83. | descriptive |
| [`pq_color_matrix_clear_bit0`](../../src/leon2m/pq/pq_color_matrix_clear_bit0.c) | `FUN_a00f6c6c` | Clear bit 0 of the colour matrix control register 0xCF00E984. | descriptive |
| [`pq_color_matrix_clear_option_bit`](../../src/leon2m/pq/pq_color_matrix_clear_option_bit.c) | `FUN_a00f6ca4` | Clear the second option bit of the colour matrix. | descriptive |
| [`pq_color_matrix_read`](../../src/leon2m/pq/pq_color_matrix_read.c) | `FUN_a00f72cc` | Read the rows of the colour matrix back from the hardware. | proven |
| [`pq_color_matrix_rebuild`](../../src/leon2m/pq/pq_color_matrix_rebuild.c) | `FUN_a013ae00` | Build the three rows of the colour matrix from the stored settings and program them. | proven |
| [`pq_color_matrix_set_bit0`](../../src/leon2m/pq/pq_color_matrix_set_bit0.c) | `FUN_a00f6c88` | Set bit 0 of the colour matrix control register 0xCF00E984. | descriptive |
| [`pq_color_matrix_set_blue_gain`](../../src/leon2m/pq/pq_color_matrix_set_blue_gain.c) | `FUN_a013b46c` | Store the third gain value and rebuild the colour matrix. | derived |
| [`pq_color_matrix_set_blue_offset`](../../src/leon2m/pq/pq_color_matrix_set_blue_offset.c) | `FUN_a013b544` | Store the third offset value and program the offsets. | derived |
| [`pq_color_matrix_set_enable_flag`](../../src/leon2m/pq/pq_color_matrix_set_enable_flag.c) | `FUN_a013b6e4` | Store the on/off flag of the colour matrix. | descriptive |
| [`pq_color_matrix_set_gains`](../../src/leon2m/pq/pq_color_matrix_set_gains.c) | `FUN_a013b4a4` | Store the three gain values and rebuild the colour matrix. | derived |
| [`pq_color_matrix_set_green_gain`](../../src/leon2m/pq/pq_color_matrix_set_green_gain.c) | `FUN_a013b44c` | Store the second gain value and rebuild the colour matrix. | derived |
| [`pq_color_matrix_set_green_offset`](../../src/leon2m/pq/pq_color_matrix_set_green_offset.c) | `FUN_a013b5a0` | Store the second offset value and program the offsets. | derived |
| [`pq_color_matrix_set_offsets`](../../src/leon2m/pq/pq_color_matrix_set_offsets.c) | `FUN_a013b4e8` | Store the three offset values and program them. | derived |
| [`pq_color_matrix_set_option`](../../src/leon2m/pq/pq_color_matrix_set_option.c) | `FUN_a013b710` | Store the second option flag of the colour matrix and switch its hardware bit. | descriptive |
| [`pq_color_matrix_set_option_bit`](../../src/leon2m/pq/pq_color_matrix_set_option_bit.c) | `FUN_a00f6cc0` | Set the second option bit of the colour matrix. | descriptive |
| [`pq_color_matrix_set_param_first`](../../src/leon2m/pq/pq_color_matrix_set_param_first.c) | `FUN_a013b6c4` | Store the first (signed) matrix parameter and rebuild the colour matrix. | descriptive |
| [`pq_color_matrix_set_param_second`](../../src/leon2m/pq/pq_color_matrix_set_param_second.c) | `FUN_a013b684` | Store the second matrix parameter and rebuild the colour matrix. | descriptive |
| [`pq_color_matrix_set_param_third`](../../src/leon2m/pq/pq_color_matrix_set_param_third.c) | `FUN_a013b6a4` | Store the third matrix parameter and rebuild the colour matrix. | descriptive |
| [`pq_color_matrix_set_red_gain`](../../src/leon2m/pq/pq_color_matrix_set_red_gain.c) | `FUN_a013b42c` | Store the first gain value and rebuild the colour matrix. | derived |
| [`pq_color_matrix_set_red_offset`](../../src/leon2m/pq/pq_color_matrix_set_red_offset.c) | `FUN_a013b5fc` | Store the first offset value and program the offsets. | derived |
| [`pq_color_matrix_set_scale`](../../src/leon2m/pq/pq_color_matrix_set_scale.c) | `FUN_a013adf4` | Store the scale that the colour matrix is built with. | descriptive |
| [`pq_color_matrix_set_values`](../../src/leon2m/pq/pq_color_matrix_set_values.c) | `FUN_a013b658` | Program the colour matrix with a set of 12 values and the two stored option bits. | descriptive |
| [`pq_color_matrix_store_gains`](../../src/leon2m/pq/pq_color_matrix_store_gains.c) | `FUN_a013b48c` | Store the three gain values without rebuilding. | derived |
| [`pq_color_matrix_store_offsets`](../../src/leon2m/pq/pq_color_matrix_store_offsets.c) | `FUN_a013b4d0` | Store the three offset values without applying them. | derived |
| [`pq_color_matrix_write`](../../src/leon2m/pq/pq_color_matrix_write.c) | `FUN_a00f6fe4` | Write the rows of the colour matrix to the hardware. | proven |
| [`pq_detect_ch1_input_change`](../../src/leon2m/pq/pq_detect_ch1_input_change.c) | `FUN_a0084330` | Detect a change of channel 1's measured input size and refresh its window. | derived |
| [`pq_enable_block8_path`](../../src/leon2m/pq/pq_enable_block8_path.c) | `FUN_a01190b0` | Switch the block-8 path on when the chip revision is above 0x83. | descriptive |
| [`pq_fga_expand_gamma_blocks`](../../src/leon2m/pq/pq_fga_expand_gamma_blocks.c) | `FUN_a012e004` | Decode three stored 32-byte blocks into full gamma tables and load them. | derived |
| [`pq_fga_expand_gamma_blocks_scaled`](../../src/leon2m/pq/pq_fga_expand_gamma_blocks_scaled.c) | `FUN_a012e2ac` | Decode three stored 32-byte blocks into scaled gamma tables and load them. | derived |
| [`pq_fga_get_color_mask`](../../src/leon2m/pq/pq_fga_get_color_mask.c) | `FUN_a012e840` | Return the mask of colour entries that exist (0x92). | derived |
| [`pq_fga_get_const_7`](../../src/leon2m/pq/pq_fga_get_const_7.c) | `FUN_a012e848` | Return the constant 7. | descriptive |
| [`pq_fga_get_status`](../../src/leon2m/pq/pq_fga_get_status.c) | `FUN_a012e82c` | Return the FGA status byte. | descriptive |
| [`pq_fga_get_table_mask`](../../src/leon2m/pq/pq_fga_get_table_mask.c) | `FUN_a012e838` | Return the mask of gamma tables that exist (0x508). | derived |
| [`pq_fga_handle_command`](../../src/leon2m/pq/pq_fga_handle_command.c) | `FUN_a012d554` | Carry out one calibration command received over DDC/CI. | derived |
| `pq_fga_handle_command_jump_table` | `switchdataD_a012ce24` | Jump table 1 of the switch statements in pq_fga_handle_command. | proven |
| [`pq_fga_load_color_matrix_row`](../../src/leon2m/pq/pq_fga_load_color_matrix_row.c) | `FUN_a012e6c0` | Read a stored 18-byte row and program it as the colour matrix. | derived |
| [`pq_fga_load_gamma_from_storage`](../../src/leon2m/pq/pq_fga_load_gamma_from_storage.c) | `FUN_a012e3ec` | Read one stored gamma block set and load it into the gamma tables. | derived |
| [`pq_fga_lookup_key_first`](../../src/leon2m/pq/pq_fga_lookup_key_first.c) | `FUN_a012cf1c` | Return the value for a key from the first FGA key table. | descriptive |
| [`pq_fga_lookup_key_second`](../../src/leon2m/pq/pq_fga_lookup_key_second.c) | `FUN_a012cf64` | Return the value for a key from the second FGA key table. | descriptive |
| [`pq_fga_read_color_entry`](../../src/leon2m/pq/pq_fga_read_color_entry.c) | `FUN_a012e550` | Read one stored 3-byte colour entry and report whether it is valid. | derived |
| [`pq_fga_set_byte`](../../src/leon2m/pq/pq_fga_set_byte.c) | `FUN_a012cf10` | Store an FGA byte in the device settings. | descriptive |
| [`pq_fga_set_selector`](../../src/leon2m/pq/pq_fga_set_selector.c) | `FUN_a012ced8` | Store the FGA selector byte. | descriptive |
| [`pq_fga_set_word`](../../src/leon2m/pq/pq_fga_set_word.c) | `FUN_a012cee4` | Store a 16-bit FGA value in the device settings. | descriptive |
| [`pq_fga_store_color_row`](../../src/leon2m/pq/pq_fga_store_color_row.c) | `FUN_a012e928` | Copy an 18-byte colour row into a slot of the stored block and save it. | derived |
| `pq_fga_store_color_row_jump_table` | `switchdataD_a012cebc` | Jump table 1 of the switch statements in pq_fga_store_color_row. | proven |
| [`pq_gamma_disable_first_curve_stage`](../../src/leon2m/pq/pq_gamma_disable_first_curve_stage.c) | `FUN_a010afc8` | Switch the first preset-curve stage off. | derived |
| [`pq_gamma_disable_primary_lut`](../../src/leon2m/pq/pq_gamma_disable_primary_lut.c) | `FUN_a010ae70` | Switch the primary gamma look-up table off. | derived |
| [`pq_gamma_disable_second_curve_stage`](../../src/leon2m/pq/pq_gamma_disable_second_curve_stage.c) | `FUN_a010b198` | Switch the second preset-curve stage off. | derived |
| [`pq_gamma_disable_secondary_lut`](../../src/leon2m/pq/pq_gamma_disable_secondary_lut.c) | `FUN_a010af50` | Switch the secondary gamma look-up table off. | derived |
| [`pq_gamma_enable_first_curve_stage`](../../src/leon2m/pq/pq_gamma_enable_first_curve_stage.c) | `FUN_a010afac` | Switch the first preset-curve stage on. | derived |
| [`pq_gamma_enable_primary_lut`](../../src/leon2m/pq/pq_gamma_enable_primary_lut.c) | `FUN_a010ae54` | Switch the primary gamma look-up table on. | derived |
| [`pq_gamma_enable_second_curve_stage`](../../src/leon2m/pq/pq_gamma_enable_second_curve_stage.c) | `FUN_a010b17c` | Switch the second preset-curve stage on. | derived |
| [`pq_gamma_enable_secondary_lut`](../../src/leon2m/pq/pq_gamma_enable_secondary_lut.c) | `FUN_a010af34` | Switch the secondary gamma look-up table on. | derived |
| [`pq_gamma_is_first_curve_stage_enabled`](../../src/leon2m/pq/pq_gamma_is_first_curve_stage_enabled.c) | `FUN_a010af98` | Return whether the first preset-curve stage is switched on. | derived |
| [`pq_gamma_is_primary_lut_enabled`](../../src/leon2m/pq/pq_gamma_is_primary_lut_enabled.c) | `FUN_a010ae38` | Return whether the primary gamma look-up table is switched on. | derived |
| [`pq_gamma_is_second_curve_stage_enabled`](../../src/leon2m/pq/pq_gamma_is_second_curve_stage_enabled.c) | `FUN_a010b160` | Return whether the second preset-curve stage is switched on. | derived |
| [`pq_gamma_is_secondary_lut_enabled`](../../src/leon2m/pq/pq_gamma_is_secondary_lut_enabled.c) | `FUN_a010af18` | Return whether the secondary gamma look-up table is switched on. | derived |
| [`pq_gamma_load_first_curve_preset0`](../../src/leon2m/pq/pq_gamma_load_first_curve_preset0.c) | `FUN_a010b030` | Load preset 0 (or a given table) into the first preset-curve stage. | derived |
| [`pq_gamma_load_first_curve_preset1`](../../src/leon2m/pq/pq_gamma_load_first_curve_preset1.c) | `FUN_a010b07c` | Load preset 1 (or a given table) into the first preset-curve stage. | derived |
| [`pq_gamma_load_first_curve_preset2`](../../src/leon2m/pq/pq_gamma_load_first_curve_preset2.c) | `FUN_a010afe4` | Load preset 2 (or a given table) into the first preset-curve stage. | derived |
| [`pq_gamma_load_first_curve_preset3`](../../src/leon2m/pq/pq_gamma_load_first_curve_preset3.c) | `FUN_a010b0c8` | Load preset 3 (or a given table) into the first preset-curve stage. | derived |
| [`pq_gamma_load_first_curve_preset4`](../../src/leon2m/pq/pq_gamma_load_first_curve_preset4.c) | `FUN_a010b114` | Load preset 4 (or a given table) into the first preset-curve stage. | derived |
| [`pq_gamma_load_second_curve_preset0`](../../src/leon2m/pq/pq_gamma_load_second_curve_preset0.c) | `FUN_a010b200` | Load preset 0 (or a given table) into the second preset-curve stage. | derived |
| [`pq_gamma_load_second_curve_preset1`](../../src/leon2m/pq/pq_gamma_load_second_curve_preset1.c) | `FUN_a010b24c` | Load preset 1 (or a given table) into the second preset-curve stage. | derived |
| [`pq_gamma_load_second_curve_preset2`](../../src/leon2m/pq/pq_gamma_load_second_curve_preset2.c) | `FUN_a010b1b4` | Load preset 2 (or a given table) into the second preset-curve stage. | derived |
| [`pq_gamma_load_second_curve_preset3`](../../src/leon2m/pq/pq_gamma_load_second_curve_preset3.c) | `FUN_a010b298` | Load preset 3 (or a given table) into the second preset-curve stage. | derived |
| [`pq_gamma_load_second_curve_preset4`](../../src/leon2m/pq/pq_gamma_load_second_curve_preset4.c) | `FUN_a010b2e4` | Load preset 4 (or a given table) into the second preset-curve stage. | derived |
| [`pq_gamma_set_lut_options`](../../src/leon2m/pq/pq_gamma_set_lut_options.c) | `FUN_a010adc0` | Set the two option bits of the gamma look-up tables. | descriptive |
| [`pq_gamma_write_primary_lut`](../../src/leon2m/pq/pq_gamma_write_primary_lut.c) | `FUN_a010ae8c` | Write a block of the primary gamma table of one colour channel. | derived |
| [`pq_gamma_write_secondary_lut`](../../src/leon2m/pq/pq_gamma_write_secondary_lut.c) | `FUN_a010af6c` | Write a 64-byte block of the secondary gamma table of one colour channel. | derived |
| [`pq_get_block8_table_byte`](../../src/leon2m/pq/pq_get_block8_table_byte.c) | `FUN_a01411c8` | Return the first byte of the block-8 table entry for a preset. | descriptive |
| [`pq_get_block8_table_byte_alt`](../../src/leon2m/pq/pq_get_block8_table_byte_alt.c) | `FUN_a01411f8` | Return the second byte of the block-8 table entry for a preset. | descriptive |
| [`pq_get_block8_variant`](../../src/leon2m/pq/pq_get_block8_variant.c) | `FUN_a011909c` | Return the 4-bit variant field of register 0xCF012FDC. | descriptive |
| [`pq_get_preset_table_byte`](../../src/leon2m/pq/pq_get_preset_table_byte.c) | `FUN_a014bcac` | Return the table byte for the current preset (first table). | descriptive |
| [`pq_get_preset_table_byte_alt`](../../src/leon2m/pq/pq_get_preset_table_byte_alt.c) | `FUN_a014bcc8` | Return the table byte for the current preset (second table). | descriptive |
| [`pq_get_selected_window`](../../src/leon2m/pq/pq_get_selected_window.c) | `FUN_a00f6cf4` | Return the picture window that is currently selected. | proven |
| [`pq_is_fga_bit4_set`](../../src/leon2m/pq/pq_is_fga_bit4_set.c) | `FUN_a012f134` | Return bit 4 of a value as 0 or 1. | descriptive |
| [`pq_load_block8_config`](../../src/leon2m/pq/pq_load_block8_config.c) | `FUN_a0118e04` | Store the 16-byte configuration record and load the register tables it selects. | descriptive |
| [`pq_load_block8_tables`](../../src/leon2m/pq/pq_load_block8_tables.c) | `FUN_a014118c` | Load the pair of ROM tables with a given index into picture block 8. | descriptive |
| [`pq_load_fga_color_entries`](../../src/leon2m/pq/pq_load_fga_color_entries.c) | `FUN_a014e320` | Copy three stored FGA colour entries (columns 0x02, 0x10, 0x80) to part record +6, +9 and +0x12. | derived |
| [`pq_load_gamma`](../../src/leon2m/pq/pq_load_gamma.c) | `FUN_a012eeb0` | Load the gamma table set with a given number. | proven |
| [`pq_load_gamma_curve_interpolated`](../../src/leon2m/pq/pq_load_gamma_curve_interpolated.c) | `FUN_a012ec24` | Unpack a curve of 10-bit points, interpolate between them and load it as a gamma table. | derived |
| `pq_load_gamma_jump_table` | `switchdataD_a012eba4` | Jump table 1 of the switch statements in pq_load_gamma. | proven |
| [`pq_load_profile_table`](../../src/leon2m/pq/pq_load_profile_table.c) | `FUN_a0110fb4` | Load the built-in 1024-entry profile table into the picture hardware. | proven |
| [`pq_match_ch1_timing_table`](../../src/leon2m/pq/pq_match_ch1_timing_table.c) | `FUN_a0082ec4` | Match channel 1's input size against a 12-entry table and return four window values. | descriptive |
| [`pq_mode_to_color_row_bit`](../../src/leon2m/pq/pq_mode_to_color_row_bit.c) | `FUN_a012e8c0` | Convert a picture mode 0x10..0x16 to a single-bit byte that selects a stored colour row; else 1. | descriptive |
| `pq_mode_to_color_row_bit_jump_table` | `switchdataD_a012cea0` | Jump table 1 of the switch statements in pq_mode_to_color_row_bit. | proven |
| [`pq_pivot_enable`](../../src/leon2m/pq/pq_pivot_enable.c) | `FUN_a010a2cc` | Switch picture rotation on (mode 1 or 2) or off. | proven |
| [`pq_pivot_is_enabled`](../../src/leon2m/pq/pq_pivot_is_enabled.c) | `FUN_a010a2b0` | Return whether picture rotation is switched on. | derived |
| [`pq_pivot_set_bit4_pattern`](../../src/leon2m/pq/pq_pivot_set_bit4_pattern.c) | `FUN_a010a3a8` | Set or clear bit 4 of the three pivot channel registers in a pattern chosen by the channel. | descriptive |
| [`pq_pivot_setup_timing`](../../src/leon2m/pq/pq_pivot_setup_timing.c) | `FUN_a010a558` | Program the rotation block's timing registers from the working panel timing row. | descriptive |
| [`pq_pivot_update_counter`](../../src/leon2m/pq/pq_pivot_update_counter.c) | `FUN_a010a4d0` | Copy a quarter of a 16-bit counter into the rotation block. | descriptive |
| [`pq_port_read8`](../../src/leon2m/pq/pq_port_read8.c) | `FUN_a00f2b48` | Read an 8-bit register of one of the four port blocks. | derived |
| [`pq_port_set_reg10_bit0`](../../src/leon2m/pq/pq_port_set_reg10_bit0.c) | `FUN_a0118a28` | Set or clear bit 0 of register 0x10 of a port block. | descriptive |
| [`pq_port_write8`](../../src/leon2m/pq/pq_port_write8.c) | `FUN_a00f2b8c` | Write an 8-bit register of one port block, or of all four. | derived |
| [`pq_read_zone_color_averages`](../../src/leon2m/pq/pq_read_zone_color_averages.c) | `FUN_a0150df8` | Read 16 rows of 16 colour averages through the memory port into the three zone average tables. | derived |
| [`pq_select_rate_mode`](../../src/leon2m/pq/pq_select_rate_mode.c) | `FUN_a0087458` | Return 2 (refresh rate 84..279 Hz) or 3 (Adaptive-Sync on) for a settled input, else 0. | derived |
| [`pq_select_window`](../../src/leon2m/pq/pq_select_window.c) | `FUN_a00f63bc` | Select the picture window that the following picture settings apply to. | proven |
| [`pq_set_block8_table_value`](../../src/leon2m/pq/pq_set_block8_table_value.c) | `FUN_a014122c` | Store a value in a block-8 table entry and load the tables again. | descriptive |
| [`pq_set_block_e9f8_mode`](../../src/leon2m/pq/pq_set_block_e9f8_mode.c) | `FUN_a010740c` | Write the mode values of the block at 0xCF00E9F8 and its twin for a selector. | descriptive |
| [`pq_set_color_fill_enable`](../../src/leon2m/pq/pq_set_color_fill_enable.c) | `FUN_a010385c` | Switch the colour-fill path on or off. | derived |
| [`pq_set_color_matrix_preset`](../../src/leon2m/pq/pq_set_color_matrix_preset.c) | `FUN_a0150b8c` | Select one of five 3x4 coefficient tables and program it. | derived |
| [`pq_set_port_fill_color`](../../src/leon2m/pq/pq_set_port_fill_color.c) | `FUN_a010aae8` | Write the three fill colour bytes of a port. | derived |
| [`pq_set_scaled_level_table`](../../src/leon2m/pq/pq_set_scaled_level_table.c) | `FUN_a0150a98` | Scale a level by 48/255 and pass a four-entry table to the picture block. | descriptive |
| [`pq_set_three_entry_table`](../../src/leon2m/pq/pq_set_three_entry_table.c) | `FUN_a0150b08` | Fill three entries of the table chosen by sel and pass it to the picture block. | descriptive |
| [`pq_update_input_window`](../../src/leon2m/pq/pq_update_input_window.c) | `FUN_a00830f4` | Recompute and store a channel's input crop window (video wall, margins, Optix Scope, PBP match). | derived |
| [`pq_user_apply_blue_offset`](../../src/leon2m/pq/pq_user_apply_blue_offset.c) | `FUN_a00d46f8` | Limit the blue offset to 100 and apply it. | derived |
| [`pq_user_apply_color_gain`](../../src/leon2m/pq/pq_user_apply_color_gain.c) | `FUN_a00d7de0` | Apply the colour gain setting, limited to 100. | derived |
| [`pq_user_apply_color_matrix_param`](../../src/leon2m/pq/pq_user_apply_color_matrix_param.c) | `FUN_a00d4660` | Limit settings byte +0x0B to 100 and apply it to the colour matrix. | descriptive |
| [`pq_user_apply_color_settings`](../../src/leon2m/pq/pq_user_apply_color_settings.c) | `FUN_a00d9764` | Limit and apply the colour temperature and the three custom colour values. | derived |
| `pq_user_apply_color_settings_jump_table` | `switchdataD_a00d3b1c` | Jump table 1 of the switch statements in pq_user_apply_color_settings. | proven |
| [`pq_user_apply_color_temperature`](../../src/leon2m/pq/pq_user_apply_color_temperature.c) | `FUN_a00d94fc` | Apply the three colour values of the chosen colour temperature. | derived |
| `pq_user_apply_color_temperature_jump_table` | `switchdataD_a00d3afc` | Jump table 1 of the switch statements in pq_user_apply_color_temperature. | proven |
| [`pq_user_apply_custom_green`](../../src/leon2m/pq/pq_user_apply_custom_green.c) | `FUN_a00d462c` | Limit the custom green value to 100 and apply it. | derived |
| [`pq_user_apply_custom_red`](../../src/leon2m/pq/pq_user_apply_custom_red.c) | `FUN_a00d45f8` | Limit the custom red value to 100 and apply it. | derived |
| [`pq_user_apply_gamma`](../../src/leon2m/pq/pq_user_apply_gamma.c) | `FUN_a00d7bc0` | Apply the gamma setting, or the gamma that the current picture state requires. | derived |
| `pq_user_apply_gamma_jump_table` | `switchdataD_a00d3ac0` | Jump table 1 of the switch statements in pq_user_apply_gamma. | proven |
| [`pq_user_apply_green_offset`](../../src/leon2m/pq/pq_user_apply_green_offset.c) | `FUN_a00d46c4` | Limit the green offset to 100 and apply it. | derived |
| [`pq_user_apply_mode_colors`](../../src/leon2m/pq/pq_user_apply_mode_colors.c) | `FUN_a00d4560` | Re-apply the first six colour values of the picture modes. | derived |
| [`pq_user_apply_red_offset`](../../src/leon2m/pq/pq_user_apply_red_offset.c) | `FUN_a00d4690` | Limit the red offset to 100 and apply it. | derived |
| [`pq_user_apply_sharpness`](../../src/leon2m/pq/pq_user_apply_sharpness.c) | `FUN_a00d4084` | Apply the sharpness setting 0..5. | derived |
| [`pq_user_apply_theme_mode`](../../src/leon2m/pq/pq_user_apply_theme_mode.c) | `FUN_a00d58b0` | Apply the theme mode setting, limited to 4. | derived |
| [`pq_user_reset_response_level`](../../src/leon2m/pq/pq_user_reset_response_level.c) | `FUN_a00d8c1c` | Switch the response level off and back to the stored value. | descriptive |
| [`pq_user_set_custom_blue`](../../src/leon2m/pq/pq_user_set_custom_blue.c) | `FUN_a00d972c` | Limit the custom blue value to 100, apply it and re-apply the colour temperature. | derived |
| [`pq_user_update_input_window`](../../src/leon2m/pq/pq_user_update_input_window.c) | `FUN_a00d4928` | Update the input window of channel 0. | descriptive |
| [`pq_videowall_h_position`](../../src/leon2m/pq/pq_videowall_h_position.c) | `FUN_a0082c5c` | Compute the horizontal crop start and width of this monitor's video-wall tile. | proven |
| [`pq_videowall_v_position`](../../src/leon2m/pq/pq_videowall_v_position.c) | `FUN_a0082dc4` | Compute the vertical crop start and height of this monitor's video-wall tile. | proven |
| [`pq_window_clear_ee40_bits`](../../src/leon2m/pq/pq_window_clear_ee40_bits.c) | `FUN_a00f6ab4` | Clear bit 6 or 7 of register 0xCF00EE40 or 0xCF00EE68 by a selector. | descriptive |
| `pq_window_clear_ee40_bits_jump_table` | `switchdataD_a00f63a8` | Jump table 1 of the switch statements in pq_window_clear_ee40_bits. | proven |
| [`pq_window_disable`](../../src/leon2m/pq/pq_window_disable.c) | `FUN_a00f67d0` | Switch picture window 0..3 off. | derived |
| [`pq_window_disable_stages`](../../src/leon2m/pq/pq_window_disable_stages.c) | `FUN_a00f66a4` | Switch off the picture stages named by a mask. | derived |
| [`pq_window_enable`](../../src/leon2m/pq/pq_window_enable.c) | `FUN_a00f6898` | Switch picture window 0..3 on. | derived |
| [`pq_window_enable_stages`](../../src/leon2m/pq/pq_window_enable_stages.c) | `FUN_a00f6b34` | Switch on the picture stages named by a mask. | derived |
| [`pq_window_set_ee_registers`](../../src/leon2m/pq/pq_window_set_ee_registers.c) | `FUN_a00f6940` | Write one of several register sets at 0xCF00EE2x / 0xCF00EE6x and three bytes behind them. | descriptive |
| `pq_window_set_ee_registers_jump_table` | `switchdataD_a00f6394` | Jump table 1 of the switch statements in pq_window_set_ee_registers. | proven |
| [`pq_window_set_ef40_bit0`](../../src/leon2m/pq/pq_window_set_ef40_bit0.c) | `FUN_a00f6fac` | Write bit 0 of register 0xCF00EF40 when the chip revision is above 0x83. | descriptive |
| [`pq_window_set_item0`](../../src/leon2m/pq/pq_window_set_item0.c) | `FUN_a00f6d80` | Write picture item 0 of the selected picture window. | descriptive |
| [`pq_window_set_item1`](../../src/leon2m/pq/pq_window_set_item1.c) | `FUN_a00f6dd8` | Write picture item 1 of the selected picture window. | descriptive |
| [`pq_window_set_item2`](../../src/leon2m/pq/pq_window_set_item2.c) | `FUN_a00f6e30` | Write picture item 2 of the selected picture window. | descriptive |
| [`pq_window_set_item3`](../../src/leon2m/pq/pq_window_set_item3.c) | `FUN_a00f6e88` | Write picture item 3 of the selected picture window. | descriptive |
| [`pq_window_set_item4`](../../src/leon2m/pq/pq_window_set_item4.c) | `FUN_a00f6ecc` | Write picture item 4 of the selected picture window. | descriptive |
| [`pq_window_set_item5`](../../src/leon2m/pq/pq_window_set_item5.c) | `FUN_a00f6f10` | Write picture item 5 of the selected picture window. | descriptive |
| [`pq_window_set_item6`](../../src/leon2m/pq/pq_window_set_item6.c) | `FUN_a00f6f54` | Write picture item 6 of the selected picture window. | descriptive |
| [`pq_window_set_item7`](../../src/leon2m/pq/pq_window_set_item7.c) | `FUN_a00f6f7c` | Write picture item 7 of the selected picture window. | descriptive |
| [`pq_window_set_item8`](../../src/leon2m/pq/pq_window_set_item8.c) | `FUN_a00f6f94` | Write picture item 8 of the selected picture window. | descriptive |
| [`pq_window_set_item_hook`](../../src/leon2m/pq/pq_window_set_item_hook.c) | `FUN_a00f87b0` | Store the hook that receives the picture window items. | descriptive |
| [`pq_window_set_rect`](../../src/leon2m/pq/pq_window_set_rect.c) | `FUN_a00f6d00` | Write the four coordinates of the selected picture window. | derived |
| [`pq_window_write_coordinates`](../../src/leon2m/pq/pq_window_write_coordinates.c) | `FUN_a0101d9c` | Write four 13-bit window coordinates after clearing the control register. | descriptive |
| [`pq_window_write_level_table`](../../src/leon2m/pq/pq_window_write_level_table.c) | `FUN_a00f643c` | Write the first 24-entry level table of the selected window, or zeros. | descriptive |
| [`pq_window_write_level_table_second`](../../src/leon2m/pq/pq_window_write_level_table_second.c) | `FUN_a00f6508` | Write the second 24-entry level table of the selected window, or the neutral value 0x80. | descriptive |
| [`pq_window_write_level_table_third`](../../src/leon2m/pq/pq_window_write_level_table_third.c) | `FUN_a00f65d8` | Write a 17-entry level table of the selected window, or the neutral value 0x80. | descriptive |
| [`SetThemeMode`](../../src/leon2m/pq/SetThemeMode.c) | `FUN_a0087a14` | Apply the picture theme preset mode to one or both channels. | proven |
| [`UserSetGameMode`](../../src/leon2m/pq/UserSetGameMode.c) | `FUN_a00dbcf0` | Apply the picture mode of the Gaming menu. | proven |
| `UserSetGameMode_jump_table` | `switchdataD_a00d3b9c` | Jump table 1 of the switch statements in UserSetGameMode. | proven |
| [`UserSetProMode`](../../src/leon2m/pq/UserSetProMode.c) | `FUN_a00db738` | Apply the picture mode of the Professional menu. | proven |

<a id="hdr"></a>
## HDR

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`hdr_api_set_port_enable`](../../src/leon2m/hdr/hdr_api_set_port_enable.c) | `FUN_a014b980` | Switch the HDR handling on or off for one input port, or for all. | derived |

<a id="osd"></a>
## On-screen menu

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`osd_accept_alarm_clock_location`](../../src/leon2m/osd/osd_accept_alarm_clock_location.c) | `FUN_a0094ed8` | Keep the highlighted corner for the alarm clock display and go back (OK) | derived |
| [`osd_accept_alarm_clock_off`](../../src/leon2m/osd/osd_accept_alarm_clock_off.c) | `FUN_a0093754` | Leave the Alarm Clock list on OK at the OFF entry: redraw the marks and go back. | derived |
| [`osd_accept_alarm_clock_quick_menu`](../../src/leon2m/osd/osd_accept_alarm_clock_quick_menu.c) | `FUN_a0097498` | Start the alarm timer highlighted in the quick menu and close it. | derived |
| [`osd_accept_alarm_time`](../../src/leon2m/osd/osd_accept_alarm_time.c) | `FUN_a00939b0` | Select the edited alarm timer, store its time and go back to the Alarm Clock item. | derived |
| [`osd_accept_boundary_detection`](../../src/leon2m/osd/osd_accept_boundary_detection.c) | `FUN_a00a2600` | Switch Boundary Detection off or on as highlighted, or open its level slider (OK) | derived |
| `osd_accept_boundary_detection_jump_table` | `switchdataD_a0090d60` | Jump table 1 of the switch statements in osd_accept_boundary_detection. | proven |
| `osd_accept_boundary_detection_jump_table2` | `switchdataD_a0090e48` | Jump table 2 of the switch statements in osd_accept_boundary_detection. | proven |
| [`osd_accept_color_temp`](../../src/leon2m/osd/osd_accept_color_temp.c) | `FUN_a00964fc` | Keep the highlighted colour temperature (Cool, Normal, Warm) and go back (OK) | derived |
| [`osd_accept_crosshair_color`](../../src/leon2m/osd/osd_accept_crosshair_color.c) | `FUN_a00956a0` | Keep the highlighted crosshair colour and go back (OK) | derived |
| [`osd_accept_crosshair_icon`](../../src/leon2m/osd/osd_accept_crosshair_icon.c) | `FUN_a0095984` | Keep the chosen crosshair icon and go back to the crosshair settings (OK) | derived |
| [`osd_accept_display_hdr`](../../src/leon2m/osd/osd_accept_display_hdr.c) | `FUN_a0096ce4` | Keep the highlighted DisplayHDR mode and apply it if it changed (OK) | derived |
| [`osd_accept_game_mode`](../../src/leon2m/osd/osd_accept_game_mode.c) | `FUN_a00932a8` | Keep the highlighted game mode, switch to Game (not Pro) mode and go back (OK key) | derived |
| [`osd_accept_image_enhancement`](../../src/leon2m/osd/osd_accept_image_enhancement.c) | `FUN_a0096230` | Leave the Image Enhancement list on OK: move highlight and mark and go back. | derived |
| [`osd_accept_input_quick_menu`](../../src/leon2m/osd/osd_accept_input_quick_menu.c) | `FUN_a0097190` | Switch to the input highlighted in the input quick menu and close it. | derived |
| [`osd_accept_kvm`](../../src/leon2m/osd/osd_accept_kvm.c) | `FUN_a0099524` | Keep the highlighted KVM choice, apply it and go back (OK) | derived |
| [`osd_accept_language`](../../src/leon2m/osd/osd_accept_language.c) | `FUN_a0098a74` | Keep the highlighted menu language and go back (OK) | derived |
| [`osd_accept_multi_logo_detection`](../../src/leon2m/osd/osd_accept_multi_logo_detection.c) | `FUN_a00a20d0` | Switch Multi Logo Detection off or on as highlighted, or open its level slider (OK) | derived |
| `osd_accept_multi_logo_detection_jump_table` | `switchdataD_a00909c0` | Jump table 1 of the switch statements in osd_accept_multi_logo_detection. | proven |
| `osd_accept_multi_logo_detection_jump_table2` | `switchdataD_a0090aa8` | Jump table 2 of the switch statements in osd_accept_multi_logo_detection. | proven |
| [`osd_accept_navi_key_function`](../../src/leon2m/osd/osd_accept_navi_key_function.c) | `FUN_a00984f0` | Keep the highlighted function for the edited Navi Key direction and go back (OK) | derived |
| [`osd_accept_night_vision`](../../src/leon2m/osd/osd_accept_night_vision.c) | `FUN_a0095b58` | Leave the Night Vision list on OK: move highlight and mark, go back, save the picture slot. | derived |
| [`osd_accept_optix_scope`](../../src/leon2m/osd/osd_accept_optix_scope.c) | `FUN_a0099864` | Apply the highlighted Optix Scope OFF or ON and go back (OK) | derived |
| [`osd_accept_panel_protect_prompt`](../../src/leon2m/osd/osd_accept_panel_protect_prompt.c) | `FUN_a00b2d04` | Run the chosen panel protect button: Execute, Cancel, Later or More Info. | derived |
| [`osd_accept_pbp_custom_split`](../../src/leon2m/osd/osd_accept_pbp_custom_split.c) | `FUN_a00a10c8` | Store the custom PBP split, switch PBP to it and close the editor (OK) | derived |
| [`osd_accept_pbp_source`](../../src/leon2m/osd/osd_accept_pbp_source.c) | `FUN_a00951a8` | Store the highlighted input for PBP Source 1 or 2, then go back or switch the input (OK) | derived |
| [`osd_accept_pip_location`](../../src/leon2m/osd/osd_accept_pip_location.c) | `FUN_a0094fc4` | Keep the highlighted PIP window corner and go back to the PIP settings (OK) | derived |
| [`osd_accept_pip_pbp_quick_menu`](../../src/leon2m/osd/osd_accept_pip_pbp_quick_menu.c) | `FUN_a00972cc` | Apply the PIP/PBP layout highlighted in the quick menu and close it. | derived |
| [`osd_accept_pip_size`](../../src/leon2m/osd/osd_accept_pip_size.c) | `FUN_a00953d4` | Keep the highlighted PIP window size and go back to the PIP settings (OK) | derived |
| [`osd_accept_pip_source`](../../src/leon2m/osd/osd_accept_pip_source.c) | `FUN_a00950a8` | Keep the highlighted PIP source and go back to the PIP settings (OK) | derived |
| [`osd_accept_pixel_shift_speed`](../../src/leon2m/osd/osd_accept_pixel_shift_speed.c) | `FUN_a009a1ec` | Keep the highlighted Pixel Shift speed and go back to the item (OK) | derived |
| [`osd_accept_pixel_shift_switch`](../../src/leon2m/osd/osd_accept_pixel_shift_switch.c) | `FUN_a0099e44` | Switch Pixel Shift off or on as highlighted and go back (OK) | derived |
| [`osd_accept_power_button`](../../src/leon2m/osd/osd_accept_power_button.c) | `FUN_a00990e4` | Keep the highlighted Power Button behaviour and go back (OK) | derived |
| [`osd_accept_pro_mode`](../../src/leon2m/osd/osd_accept_pro_mode.c) | `FUN_a0095e54` | Leave the Pro Mode list on OK: move the marks, set the Pro (not Game) flag and go back. | derived |
| [`osd_accept_protect_notice`](../../src/leon2m/osd/osd_accept_protect_notice.c) | `FUN_a009a0d4` | Keep the highlighted Protect Notice choice (Auto, Usage 24 hrs) and go back (OK) | derived |
| [`osd_accept_refresh_rate_display`](../../src/leon2m/osd/osd_accept_refresh_rate_display.c) | `FUN_a0093534` | Keep the chosen Refresh Rate on/off setting and go back (OK key) | derived |
| [`osd_accept_refresh_rate_location`](../../src/leon2m/osd/osd_accept_refresh_rate_location.c) | `FUN_a0094df0` | Keep the highlighted corner for the refresh rate display and go back (OK) | derived |
| [`osd_accept_rgb_led`](../../src/leon2m/osd/osd_accept_rgb_led.c) | `FUN_a0098f28` | Switch the RGB LED off or on as highlighted and go back (OK) | derived |
| [`osd_accept_scope_ratio`](../../src/leon2m/osd/osd_accept_scope_ratio.c) | `FUN_a00955a0` | Keep the highlighted Optix Scope ratio and go back (OK) | derived |
| [`osd_accept_scope_size`](../../src/leon2m/osd/osd_accept_scope_size.c) | `FUN_a00954a0` | Keep the highlighted Optix Scope size and go back (OK) | derived |
| [`osd_accept_screen_size`](../../src/leon2m/osd/osd_accept_screen_size.c) | `FUN_a0096b54` | Store the highlighted screen size, close the menu and apply it (OK) | derived |
| [`osd_accept_static_screen`](../../src/leon2m/osd/osd_accept_static_screen.c) | `FUN_a0099f20` | Switch Static Screen Detection off or on as highlighted and go back (OK) | derived |
| [`osd_accept_static_screen_reduce_level`](../../src/leon2m/osd/osd_accept_static_screen_reduce_level.c) | `FUN_a009a424` | Keep the chosen 'Reducing Level', apply it and go back (OK) | derived |
| [`osd_accept_static_screen_start_time`](../../src/leon2m/osd/osd_accept_static_screen_start_time.c) | `FUN_a009a324` | Keep the chosen 'Starting in' time, apply it and go back (OK) | derived |
| [`osd_accept_static_screen_time_required`](../../src/leon2m/osd/osd_accept_static_screen_time_required.c) | `FUN_a009a554` | Keep the chosen 'Time required', apply it and go back (OK) | derived |
| [`osd_accept_taskbar_detection`](../../src/leon2m/osd/osd_accept_taskbar_detection.c) | `FUN_a00a23a4` | Switch Taskbar Detection off or on as highlighted, or open its level slider (OK) | derived |
| `osd_accept_taskbar_detection_jump_table` | `switchdataD_a0090b90` | Jump table 1 of the switch statements in osd_accept_taskbar_detection. | proven |
| `osd_accept_taskbar_detection_jump_table2` | `switchdataD_a0090c78` | Jump table 2 of the switch statements in osd_accept_taskbar_detection. | proven |
| [`osd_api_cell_count_plus_one`](../../src/leon2m/osd/osd_api_cell_count_plus_one.c) | `FUN_a0146194` | Return columns times rows plus one. | descriptive |
| [`osd_api_clear_glyph_write_count`](../../src/leon2m/osd/osd_api_clear_glyph_write_count.c) | `FUN_a0146be8` | Set the glyph write count of the given menu layer back to 0. | derived |
| [`osd_api_configure_window_reg30`](../../src/leon2m/osd/osd_api_configure_window_reg30.c) | `FUN_a014692c` | Select window 0..7 of a menu layer and program register group 0x30. | descriptive |
| `osd_api_configure_window_reg30_jump_table` | `switchdataD_a0143320` | Jump table 1 of the switch statements in osd_api_configure_window_reg30. | proven |
| [`osd_api_enable`](../../src/leon2m/osd/osd_api_enable.c) | `FUN_a0146dc0` | Switch a menu layer on or off. | derived |
| [`osd_api_fill_cell_bytes`](../../src/leon2m/osd/osd_api_fill_cell_bytes.c) | `FUN_a0146b20` | Fill a number of cells in one of the two byte planes with one value. | derived |
| [`osd_api_fill_cells`](../../src/leon2m/osd/osd_api_fill_cells.c) | `FUN_a0146a80` | Fill a number of cells from a cell position with one 16-bit value. | derived |
| [`osd_api_get_cell_height_code`](../../src/leon2m/osd/osd_api_get_cell_height_code.c) | `FUN_a014633c` | Return the stored cell code of a menu layer (first table). | descriptive |
| [`osd_api_get_cell_width_code`](../../src/leon2m/osd/osd_api_get_cell_width_code.c) | `FUN_a0146324` | Return the stored cell code of a menu layer (second table). | descriptive |
| [`osd_api_get_columns`](../../src/leon2m/osd/osd_api_get_columns.c) | `FUN_a0146164` | Return the number of columns of a menu layer. | derived |
| [`osd_api_get_const_0x18`](../../src/leon2m/osd/osd_api_get_const_0x18.c) | `FUN_a0146e24` | Return the constant 0x18. | descriptive |
| [`osd_api_get_memory_size`](../../src/leon2m/osd/osd_api_get_memory_size.c) | `FUN_a014611c` | Return 0x14000 for menu layer 0 and 0x6000 for the other. | descriptive |
| [`osd_api_get_rows`](../../src/leon2m/osd/osd_api_get_rows.c) | `FUN_a014617c` | Return the number of rows of a menu layer. | derived |
| [`osd_api_get_text_mode`](../../src/leon2m/osd/osd_api_get_text_mode.c) | `FUN_a0146bb4` | Return the text drawing mode of a menu layer as 1, 2 or 0. | descriptive |
| [`osd_api_is_enabled`](../../src/leon2m/osd/osd_api_is_enabled.c) | `FUN_a0146dfc` | Return whether a menu layer is switched on. | derived |
| [`osd_api_ram_put_data`](../../src/leon2m/osd/osd_api_ram_put_data.c) | `FUN_a014648c` | Send a byte, a byte and a word, or a word as data to the memory port. | derived |
| [`osd_api_ram_seek`](../../src/leon2m/osd/osd_api_ram_seek.c) | `FUN_a01463f8` | Start a memory access at an address with one of the four commands. | derived |
| [`osd_api_reset_layer`](../../src/leon2m/osd/osd_api_reset_layer.c) | `FUN_a0146108` | Reset a menu layer. | descriptive |
| [`osd_api_set_blend_level`](../../src/leon2m/osd/osd_api_set_blend_level.c) | `FUN_a0146570` | Set the level in the first level field of a menu layer. | descriptive |
| [`osd_api_set_cell_size_mode`](../../src/leon2m/osd/osd_api_set_cell_size_mode.c) | `FUN_a0146298` | Select one of five character cell modes for a menu layer. | descriptive |
| `osd_api_set_cell_size_mode_jump_table` | `switchdataD_a01432c8` | Jump table 1 of the switch statements in osd_api_set_cell_size_mode. | proven |
| [`osd_api_set_glyph_write_address`](../../src/leon2m/osd/osd_api_set_glyph_write_address.c) | `FUN_a0146b50` | Store the memory address at which the next glyph data of a menu layer is written. | derived |
| [`osd_api_set_layer_byte_pair`](../../src/leon2m/osd/osd_api_set_layer_byte_pair.c) | `FUN_a0146354` | Store two bytes for a menu layer. | descriptive |
| [`osd_api_set_level_all_windows`](../../src/leon2m/osd/osd_api_set_level_all_windows.c) | `FUN_a014a388` | Apply a level 0..5 to both menu layers and to their eight windows. | descriptive |
| [`osd_api_set_origin_and_size`](../../src/leon2m/osd/osd_api_set_origin_and_size.c) | `FUN_a014654c` | Write the origin and the size in cells of a menu layer. | derived |
| [`osd_api_set_position`](../../src/leon2m/osd/osd_api_set_position.c) | `FUN_a0146518` | Place a menu layer on the screen for the active panel size. | derived |
| [`osd_api_set_reg8e_params`](../../src/leon2m/osd/osd_api_set_reg8e_params.c) | `FUN_a01465a0` | Program the parameter registers 0x8E/0x8F of a menu layer. | descriptive |
| [`osd_api_set_reg90_level`](../../src/leon2m/osd/osd_api_set_reg90_level.c) | `FUN_a0146588` | Set the level byte of register group 0x90 of a menu layer. | descriptive |
| [`osd_api_set_reg_c8_ranges`](../../src/leon2m/osd/osd_api_set_reg_c8_ranges.c) | `FUN_a0146648` | Program two pairs of limits in registers 0xC8..0xDB of a menu layer. | descriptive |
| [`osd_api_set_size_in_cells`](../../src/leon2m/osd/osd_api_set_size_in_cells.c) | `FUN_a014613c` | Store the number of columns and rows of a menu layer. | derived |
| [`osd_api_set_text_mode`](../../src/leon2m/osd/osd_api_set_text_mode.c) | `FUN_a0146b6c` | Store the text drawing mode 1, 2 or 0 of a menu layer. | descriptive |
| [`osd_api_set_window_blend_level`](../../src/leon2m/osd/osd_api_set_window_blend_level.c) | `FUN_a01469e0` | Select window 0..7 of a menu layer and set its level. | descriptive |
| `osd_api_set_window_blend_level_jump_table` | `switchdataD_a0143340` | Jump table 1 of the switch statements in osd_api_set_window_blend_level. | proven |
| [`osd_api_set_window_effect`](../../src/leon2m/osd/osd_api_set_window_effect.c) | `FUN_a014667c` | Build a five-byte effect record for a window of a menu layer and apply it. | descriptive |
| `osd_api_set_window_effect_jump_table` | `switchdataD_a01432dc` | Jump table 1 of the switch statements in osd_api_set_window_effect. | proven |
| [`osd_api_set_window_enable`](../../src/leon2m/osd/osd_api_set_window_enable.c) | `FUN_a0146c40` | Switch one window of a menu layer on or off, or all eight. | derived |
| `osd_api_set_window_enable_jump_table` | `switchdataD_a0143360` | Jump table 1 of the switch statements in osd_api_set_window_enable. | proven |
| [`osd_api_set_window_rect`](../../src/leon2m/osd/osd_api_set_window_rect.c) | `FUN_a0146870` | Select window 0..7 of a menu layer and write its rectangle. | derived |
| `osd_api_set_window_rect_jump_table` | `switchdataD_a0143300` | Jump table 1 of the switch statements in osd_api_set_window_rect. | proven |
| [`osd_api_write_block`](../../src/leon2m/osd/osd_api_write_block.c) | `FUN_a01461a8` | Send a block of bytes to a menu layer's memory. | derived |
| [`osd_api_write_cell_bytes`](../../src/leon2m/osd/osd_api_write_cell_bytes.c) | `FUN_a0146af4` | Write a run of bytes to one of the two byte planes at a cell position. | derived |
| [`osd_api_write_cells`](../../src/leon2m/osd/osd_api_write_cells.c) | `FUN_a0146acc` | Write a row of 16-bit cell values at a cell position. | derived |
| [`osd_api_write_index_run`](../../src/leon2m/osd/osd_api_write_index_run.c) | `FUN_a0146c14` | Write a run of rising byte values into a menu layer's memory. | descriptive |
| [`osd_api_write_packed_block`](../../src/leon2m/osd/osd_api_write_packed_block.c) | `FUN_a01461dc` | Send a plain or run-length packed block to a menu layer's memory. | derived |
| [`osd_api_write_reg24_group`](../../src/leon2m/osd/osd_api_write_reg24_group.c) | `FUN_a0146370` | Write a 24-bit value to register group 0..3 of a menu layer. | derived |
| [`osd_api_write_reg_cc`](../../src/leon2m/osd/osd_api_write_reg_cc.c) | `FUN_a0146ab0` | Write a 16-bit value to registers 0xCC/0xCD of a menu layer. | descriptive |
| [`osd_api_write_words24`](../../src/leon2m/osd/osd_api_write_words24.c) | `FUN_a0146c00` | Send 24-bit entries to a menu layer's memory. | derived |
| [`osd_apply_choice_on_timeout`](../../src/leon2m/osd/osd_apply_choice_on_timeout.c) | `FUN_a00db1ac` | Apply the choice of the open menu screen when the menu time-out ends, as OK would on that screen. | derived |
| [`osd_apply_input_change`](../../src/leon2m/osd/osd_apply_input_change.c) | `FUN_a00b8804` | Restart the display path for a new input, mark settings changed and close the menu. | derived |
| [`osd_apply_optix_scope`](../../src/leon2m/osd/osd_apply_optix_scope.c) | `FUN_a0099658` | Switch Optix Scope on or off from the menu state, turning off features it excludes. | derived |
| [`osd_apply_pip_pbp_mode`](../../src/leon2m/osd/osd_apply_pip_pbp_mode.c) | `FUN_a0097508` | Store the highlighted PIP/PBP layout and switch off the features it excludes. | derived |
| [`osd_apply_screen_size`](../../src/leon2m/osd/osd_apply_screen_size.c) | `FUN_a0096858` | Switch the menu layer off, turn off features the new screen size excludes, apply the layout. | derived |
| [`osd_calc_factory_ssc_ratio`](../../src/leon2m/osd/osd_calc_factory_ssc_ratio.c) | `FUN_a008b58c` | Return the spread-spectrum ratio value in hundredths of a percent from the two SSC bytes. | descriptive |
| [`osd_call_hide_menu`](../../src/leon2m/osd/osd_call_hide_menu.c) | `FUN_a00a7adc` | Hide the menu layer. | derived |
| [`osd_cancel_alarm_clock_choice`](../../src/leon2m/osd/osd_cancel_alarm_clock_choice.c) | `FUN_a0093808` | Restore the alarm clock choice saved on entry and go back (left key) | derived |
| [`osd_cancel_alarm_clock_location`](../../src/leon2m/osd/osd_cancel_alarm_clock_location.c) | `FUN_a0094f58` | Restore the alarm clock location saved on entry and go back (left) | derived |
| [`osd_cancel_color_temp`](../../src/leon2m/osd/osd_cancel_color_temp.c) | `FUN_a0096598` | Restore the colour temperature saved on entry, re-apply it and go back (left) | derived |
| [`osd_cancel_crosshair_color`](../../src/leon2m/osd/osd_cancel_crosshair_color.c) | `FUN_a0095704` | Restore the crosshair colour saved on entry and go back (left) | derived |
| [`osd_cancel_crosshair_icon`](../../src/leon2m/osd/osd_cancel_crosshair_icon.c) | `FUN_a0095a20` | Restore the crosshair icon saved on entry and go back (left) | derived |
| [`osd_cancel_display_hdr`](../../src/leon2m/osd/osd_cancel_display_hdr.c) | `FUN_a0096e14` | Restore the DisplayHDR mode saved on entry and go back (left) | derived |
| [`osd_cancel_game_mode`](../../src/leon2m/osd/osd_cancel_game_mode.c) | `FUN_a0093334` | Restore the mode saved on entry, re-apply it if it changed, and go back (left key) | derived |
| [`osd_cancel_image_enhancement`](../../src/leon2m/osd/osd_cancel_image_enhancement.c) | `FUN_a00962ac` | Restore the Image Enhancement level saved on entry, re-apply it and go back. | derived |
| [`osd_cancel_kvm`](../../src/leon2m/osd/osd_cancel_kvm.c) | `FUN_a0099598` | Restore the KVM choice saved on entry and go back (left) | derived |
| [`osd_cancel_language`](../../src/leon2m/osd/osd_cancel_language.c) | `FUN_a0098c08` | Restore the menu language saved on entry, redraw if it changed, and go back (left) | derived |
| [`osd_cancel_navi_key_function`](../../src/leon2m/osd/osd_cancel_navi_key_function.c) | `FUN_a0098618` | Restore the Navi Key function saved on entry and go back (left) | derived |
| [`osd_cancel_night_vision`](../../src/leon2m/osd/osd_cancel_night_vision.c) | `FUN_a0095d5c` | Restore the Night Vision level saved on entry and go back (left) | derived |
| [`osd_cancel_pbp_source`](../../src/leon2m/osd/osd_cancel_pbp_source.c) | `FUN_a009530c` | Restore the PBP source saved on entry, re-apply it if changed, and go back (left) | derived |
| [`osd_cancel_pip_location`](../../src/leon2m/osd/osd_cancel_pip_location.c) | `FUN_a0095020` | Restore the PIP window location saved on entry and go back (left) | derived |
| [`osd_cancel_pip_size`](../../src/leon2m/osd/osd_cancel_pip_size.c) | `FUN_a0095430` | Restore the PIP size saved on entry, re-apply it if changed, and go back (left) | derived |
| [`osd_cancel_pip_source`](../../src/leon2m/osd/osd_cancel_pip_source.c) | `FUN_a0095134` | Restore the PIP source saved on entry, re-apply it if changed, and go back (left) | derived |
| [`osd_cancel_pixel_shift_speed`](../../src/leon2m/osd/osd_cancel_pixel_shift_speed.c) | `FUN_a009a270` | Restore the Pixel Shift speed saved on entry and go back (left) | derived |
| [`osd_cancel_power_button`](../../src/leon2m/osd/osd_cancel_power_button.c) | `FUN_a0099168` | Leave the Power Button list with the saved behaviour and go back (left) | derived |
| [`osd_cancel_pro_mode`](../../src/leon2m/osd/osd_cancel_pro_mode.c) | `FUN_a0095fb0` | Restore the mode saved on entry, re-apply it if it changed, and go back (left) | derived |
| [`osd_cancel_refresh_rate_display`](../../src/leon2m/osd/osd_cancel_refresh_rate_display.c) | `FUN_a00935e8` | Restore the Refresh Rate on/off setting saved on entry and go back (left key) | derived |
| [`osd_cancel_refresh_rate_location`](../../src/leon2m/osd/osd_cancel_refresh_rate_location.c) | `FUN_a0094e70` | Restore the refresh rate display location saved on entry and go back (left) | derived |
| [`osd_cancel_rgb_brightness`](../../src/leon2m/osd/osd_cancel_rgb_brightness.c) | `FUN_a0099bb4` | Restore the RGB Brightness saved on entry, send it to the light bar and go back. | derived |
| [`osd_cancel_scope_ratio`](../../src/leon2m/osd/osd_cancel_scope_ratio.c) | `FUN_a0095610` | Restore the Optix Scope ratio saved on entry, re-apply it if changed, and go back. | derived |
| [`osd_cancel_scope_size`](../../src/leon2m/osd/osd_cancel_scope_size.c) | `FUN_a0095510` | Restore the Optix Scope size saved on entry, re-apply it if changed, and go back. | derived |
| [`osd_cancel_screen_size`](../../src/leon2m/osd/osd_cancel_screen_size.c) | `FUN_a0096bd8` | Restore the screen size saved on entry, re-apply it if changed, and go back. | derived |
| [`osd_cancel_static_screen_reduce_level`](../../src/leon2m/osd/osd_cancel_static_screen_reduce_level.c) | `FUN_a009a480` | Restore the 'Reducing Level' saved on entry and go back. | descriptive |
| [`osd_cancel_static_screen_start_time`](../../src/leon2m/osd/osd_cancel_static_screen_start_time.c) | `FUN_a009a37c` | Restore the 'Starting in' time saved on entry and go back (left) | derived |
| [`osd_cancel_static_screen_time_required`](../../src/leon2m/osd/osd_cancel_static_screen_time_required.c) | `FUN_a009a5ac` | Restore the 'Time required' value saved on entry and go back (left) | derived |
| [`osd_check_event_action`](../../src/leon2m/osd/osd_check_event_action.c) | `FUN_a008a034` | Flag a menu event whose action number is 3 or lower. | derived |
| [`osd_check_panel_protect_prompt`](../../src/leon2m/osd/osd_check_panel_protect_prompt.c) | `FUN_a009f184` | Show the OLED panel protect prompt (Execute, Cancel, Later) when it is due. | derived |
| [`osd_clear_choice_column`](../../src/leon2m/osd/osd_clear_choice_column.c) | `FUN_a00a8c88` | Clear the choice column (rows 5..0x14) and its highlight windows. | derived |
| [`osd_clear_choice_highlight`](../../src/leon2m/osd/osd_clear_choice_highlight.c) | `FUN_a00a93bc` | Remove the highlight of a choice row. | derived |
| [`osd_clear_crosshair_icon_highlight`](../../src/leon2m/osd/osd_clear_crosshair_icon_highlight.c) | `FUN_a00a9cc8` | Remove the highlight of a Smart Crosshair icon row. | descriptive |
| [`osd_clear_item_column`](../../src/leon2m/osd/osd_clear_item_column.c) | `FUN_a00a7d70` | Clear the item column rows 6..0x15. | descriptive |
| [`osd_clear_item_highlight`](../../src/leon2m/osd/osd_clear_item_highlight.c) | `FUN_a00a8ee8` | Draw an item row back in normal colours. | derived |
| [`osd_clear_menu_rows`](../../src/leon2m/osd/osd_clear_menu_rows.c) | `FUN_a00a7ce8` | Clear the menu rows 5..20 and hide their highlight windows. | descriptive |
| [`osd_clear_menu_state_and_hide`](../../src/leon2m/osd/osd_clear_menu_state_and_hide.c) | `FUN_a0091294` | Clear the menu state and hide the menu window. | proven |
| [`osd_clear_pip_pbp_marks`](../../src/leon2m/osd/osd_clear_pip_pbp_marks.c) | `FUN_a00976a8` | Clear the PIP/PBP list marks of the saved and the current layout, highlight the parent item. | descriptive |
| [`osd_clear_quick_menu_rows`](../../src/leon2m/osd/osd_clear_quick_menu_rows.c) | `FUN_a00a7c88` | Clear the text rows 4..11 of a quick menu. | descriptive |
| [`osd_clear_reg0_bit7`](../../src/leon2m/osd/osd_clear_reg0_bit7.c) | `FUN_a0119578` | Clear bit 7 of the first register of a menu layer. | descriptive |
| [`osd_clear_signal_message`](../../src/leon2m/osd/osd_clear_signal_message.c) | `FUN_a00b83e4` | Blank and switch off the signal message window. | derived |
| [`osd_clear_tab_column`](../../src/leon2m/osd/osd_clear_tab_column.c) | `FUN_a00ab080` | Clear the tab column rows 5..0x15. | derived |
| [`osd_clear_tab_highlight`](../../src/leon2m/osd/osd_clear_tab_highlight.c) | `FUN_a00a7e00` | Draw a tab row of the left column back in normal colours. | derived |
| [`osd_close_boundary_level_slider`](../../src/leon2m/osd/osd_close_boundary_level_slider.c) | `FUN_a00a27a4` | Keep the Boundary Detection level, apply it and close the slider (OK) | derived |
| [`osd_close_brightness_slider`](../../src/leon2m/osd/osd_close_brightness_slider.c) | `FUN_a0096374` | Close the Brightness slider, store the value and go back to the item (OK) | derived |
| [`osd_close_change_notice`](../../src/leon2m/osd/osd_close_change_notice.c) | `FUN_a009b59c` | Close the mode change notice and continue to the Game, Pro or Navi Key page. | descriptive |
| [`osd_close_contrast_slider`](../../src/leon2m/osd/osd_close_contrast_slider.c) | `FUN_a00963e8` | Close the Contrast slider, store the value and go back to the item (OK) | derived |
| [`osd_close_custom_color_gains`](../../src/leon2m/osd/osd_close_custom_color_gains.c) | `FUN_a009665c` | Leave the R/G/B gain editor and return to Customization (OK on the B row) | derived |
| [`osd_close_factory_info_page`](../../src/leon2m/osd/osd_close_factory_info_page.c) | `FUN_a008b330` | Close the menu when a factory information page (state 0x113 or 0x114) is open. | derived |
| [`osd_close_menu`](../../src/leon2m/osd/osd_close_menu.c) | `FUN_a0090fd8` | Close the on-screen menu and clear the menu state. | derived |
| [`osd_close_menu_and_panel_off`](../../src/leon2m/osd/osd_close_menu_and_panel_off.c) | `FUN_a009e780` | Close the quick menu or message and switch the panel off unless channel 0 is in state 10. | derived |
| [`osd_close_multi_logo_level_slider`](../../src/leon2m/osd/osd_close_multi_logo_level_slider.c) | `FUN_a00a2264` | Keep the Multi Logo Detection level, apply it and close the slider (OK) | derived |
| [`osd_close_pip_custom_position`](../../src/leon2m/osd/osd_close_pip_custom_position.c) | `FUN_a0093b74` | Leave the free PIP positioning and return to the location list (OK key) | derived |
| [`osd_close_position_editor`](../../src/leon2m/osd/osd_close_position_editor.c) | `FUN_a0094438` | Leave the position editor and return to the item that opened it (OK key) | derived |
| [`osd_close_rgb_brightness_slider`](../../src/leon2m/osd/osd_close_rgb_brightness_slider.c) | `FUN_a0099b60` | Close the RGB Brightness slider keeping the value (OK) | derived |
| [`osd_close_sharpness_slider`](../../src/leon2m/osd/osd_close_sharpness_slider.c) | `FUN_a009645c` | Close the Sharpness slider, store the value and go back to the item (OK) | derived |
| [`osd_close_taskbar_level_slider`](../../src/leon2m/osd/osd_close_taskbar_level_slider.c) | `FUN_a00a2548` | Keep the Taskbar Detection level, apply it and close the slider (OK) | derived |
| [`osd_close_timeout_slider`](../../src/leon2m/osd/osd_close_timeout_slider.c) | `FUN_a0098e28` | Close the OSD Time out slider and go back to the item (OK) | derived |
| [`osd_close_transparency_slider`](../../src/leon2m/osd/osd_close_transparency_slider.c) | `FUN_a0098d98` | Close the Transparency slider and go back to the item (OK) | derived |
| [`osd_commit_pip_pbp_layout`](../../src/leon2m/osd/osd_commit_pip_pbp_layout.c) | `FUN_a00976f8` | Close the menu and rebuild the picture when the PIP/PBP layout changed. | derived |
| [`osd_configure_reg30_group`](../../src/leon2m/osd/osd_configure_reg30_group.c) | `FUN_a011a9e4` | Program register 0x30 and one of the two parameter triples behind it. | descriptive |
| [`osd_confirm_settings_reset`](../../src/leon2m/osd/osd_confirm_settings_reset.c) | `FUN_a0099ac0` | Reset all user settings to their defaults (Yes in the Reset question) | proven |
| [`osd_decrease_alarm_minutes_tens`](../../src/leon2m/osd/osd_decrease_alarm_minutes_tens.c) | `FUN_a009e1ec` | Step the alarm timer's minutes tens digit down by one (up key) | derived |
| [`osd_decrease_alarm_minutes_units`](../../src/leon2m/osd/osd_decrease_alarm_minutes_units.c) | `FUN_a009e21c` | Step the alarm timer's minutes units digit down by one (up key) | derived |
| [`osd_decrease_alarm_seconds_tens`](../../src/leon2m/osd/osd_decrease_alarm_seconds_tens.c) | `FUN_a009e24c` | Step the alarm timer's seconds tens digit down by one (up key) | derived |
| [`osd_decrease_alarm_seconds_units`](../../src/leon2m/osd/osd_decrease_alarm_seconds_units.c) | `FUN_a009e27c` | Step the alarm timer's seconds units digit down by one (up key) | derived |
| [`osd_decrease_blue_gain`](../../src/leon2m/osd/osd_decrease_blue_gain.c) | `FUN_a00abad0` | Lower the blue gain by 1 (left key) and apply it. | derived |
| [`osd_decrease_brightness`](../../src/leon2m/osd/osd_decrease_brightness.c) | `FUN_a00a429c` | Lower Brightness by 1 on its slider (left key) and apply it. | derived |
| [`osd_decrease_contrast`](../../src/leon2m/osd/osd_decrease_contrast.c) | `FUN_a00a4348` | Lower Contrast by 1 on its slider (left key) and apply it. | derived |
| [`osd_decrease_detection_level`](../../src/leon2m/osd/osd_decrease_detection_level.c) | `FUN_a00a1eec` | Lower the detection level on the slider one step (left key) | derived |
| `osd_decrease_detection_level_jump_table` | `switchdataD_a0090538` | Jump table 1 of the switch statements in osd_decrease_detection_level. | proven |
| `osd_decrease_detection_level_jump_table2` | `switchdataD_a0090620` | Jump table 2 of the switch statements in osd_decrease_detection_level. | proven |
| `osd_decrease_detection_level_jump_table3` | `switchdataD_a0090708` | Jump table 3 of the switch statements in osd_decrease_detection_level. | proven |
| `osd_decrease_detection_level_jump_table4` | `switchdataD_a00907f0` | Jump table 4 of the switch statements in osd_decrease_detection_level. | proven |
| `osd_decrease_detection_level_jump_table5` | `switchdataD_a00908d8` | Jump table 5 of the switch statements in osd_decrease_detection_level. | proven |
| [`osd_decrease_green_gain`](../../src/leon2m/osd/osd_decrease_green_gain.c) | `FUN_a00abd00` | Lower the green gain by 1 (left key) and apply it. | derived |
| [`osd_decrease_osd_timeout`](../../src/leon2m/osd/osd_decrease_osd_timeout.c) | `FUN_a00a454c` | Lower OSD Time out by 5 on its slider (left key) and apply it. | derived |
| [`osd_decrease_quick_brightness`](../../src/leon2m/osd/osd_decrease_quick_brightness.c) | `FUN_a00a49b8` | Lower Brightness by 1 in the Brightness quick menu (left key) | derived |
| [`osd_decrease_red_gain`](../../src/leon2m/osd/osd_decrease_red_gain.c) | `FUN_a00abf30` | Lower the red gain by 1 (left key) and apply it. | derived |
| [`osd_decrease_rgb_brightness`](../../src/leon2m/osd/osd_decrease_rgb_brightness.c) | `FUN_a009e348` | Lower the RGB LED brightness one step (0..4) and send it to the LED bar. | proven |
| [`osd_decrease_sharpness`](../../src/leon2m/osd/osd_decrease_sharpness.c) | `FUN_a00a43f4` | Lower Sharpness by 1 on its slider (left key) and apply it. | derived |
| [`osd_decrease_static_screen_reduce_level`](../../src/leon2m/osd/osd_decrease_static_screen_reduce_level.c) | `FUN_a009e65c` | Lower the Static Screen 'Reducing Level' one step (min 0) and redraw. | derived |
| [`osd_decrease_transparency`](../../src/leon2m/osd/osd_decrease_transparency.c) | `FUN_a00a44a0` | Lower menu Transparency by 1 on its slider (left key) and apply it. | derived |
| [`osd_disable_window`](../../src/leon2m/osd/osd_disable_window.c) | `FUN_a011a378` | Switch off one of the eight windows of a menu layer, or all of them. | derived |
| `osd_disable_window_jump_table` | `switchdataD_a011917c` | Jump table 1 of the switch statements in osd_disable_window. | proven |
| [`osd_dismiss_signal_message`](../../src/leon2m/osd/osd_dismiss_signal_message.c) | `FUN_a009e2ac` | Remove the No Signal message and leave the menu closed (left key) | derived |
| [`osd_dispatch_key_event`](../../src/leon2m/osd/osd_dispatch_key_event.c) | `FUN_a009eb38` | Run the menu action for one key or menu event in the current menu state. | proven |
| [`osd_draw_adaptive_sync_status`](../../src/leon2m/osd/osd_draw_adaptive_sync_status.c) | `FUN_a00acef4` | Draw the two top status lines for Adaptive-Sync: the item name and OFF or ON. | derived |
| [`osd_draw_adaptive_sync_switch`](../../src/leon2m/osd/osd_draw_adaptive_sync_switch.c) | `FUN_a00b69d0` | Draw the Adaptive-Sync switch of the Gaming page. | derived |
| [`osd_draw_adjust_key_guide`](../../src/leon2m/osd/osd_draw_adjust_key_guide.c) | `FUN_a00ab4bc` | Draw the three-row key guide icons used beside adjustable values. | descriptive |
| [`osd_draw_ai_vision_switch`](../../src/leon2m/osd/osd_draw_ai_vision_switch.c) | `FUN_a00b6994` | Draw the AI Vision switch of the Gaming page; OFF while the picture state code is not 0. | derived |
| [`osd_draw_alarm_clock_choices`](../../src/leon2m/osd/osd_draw_alarm_clock_choices.c) | `FUN_a00ac388` | Draw the Alarm Clock choices: OFF, the four timers (mm : ss) and Location. | proven |
| [`osd_draw_alarm_clock_quick_menu`](../../src/leon2m/osd/osd_draw_alarm_clock_quick_menu.c) | `FUN_a00b89c4` | Draw one page of the Alarm Clock quick menu: OFF and timers 1 to 3, or timer 4 alone. | derived |
| [`osd_draw_alarm_digit_cursor`](../../src/leon2m/osd/osd_draw_alarm_digit_cursor.c) | `FUN_a00b6514` | Place the cursor window on the alarm time digit being edited. | derived |
| [`osd_draw_alarm_time_editor`](../../src/leon2m/osd/osd_draw_alarm_time_editor.c) | `FUN_a00b6290` | Draw the alarm timer being edited as mm:ss digits. | derived |
| [`osd_draw_auto_scan_switch`](../../src/leon2m/osd/osd_draw_auto_scan_switch.c) | `FUN_a00b3b5c` | Draw the Input Source auto scan switch and its key guide. | derived |
| [`osd_draw_blue_gain`](../../src/leon2m/osd/osd_draw_blue_gain.c) | `FUN_a00aba34` | Draw the blue gain slider of the custom colour page. | derived |
| [`osd_draw_brightness_slider`](../../src/leon2m/osd/osd_draw_brightness_slider.c) | `FUN_a00b7054` | Draw the Brightness slider with its value and key guide. | proven |
| [`osd_draw_cell_run`](../../src/leon2m/osd/osd_draw_cell_run.c) | `FUN_a00b32e4` | Write a run of n glyph cells across or down, with the same or rising glyphs. | derived |
| [`osd_draw_change_notice_text`](../../src/leon2m/osd/osd_draw_change_notice_text.c) | `FUN_a00b05d8` | Draw the 'Confirm Change !' notice text with its Yes and No buttons. | proven |
| [`osd_draw_choice_mark`](../../src/leon2m/osd/osd_draw_choice_mark.c) | `FUN_a00a813c` | Draw or clear the mark of the stored choice in a list. | derived |
| [`osd_draw_choice_notes`](../../src/leon2m/osd/osd_draw_choice_notes.c) | `FUN_a00aee44` | Draw the notes under a choice list (conflicting functions, notices) | descriptive |
| [`osd_draw_color_gain_labels`](../../src/leon2m/osd/osd_draw_color_gain_labels.c) | `FUN_a00b72cc` | Draw the R, G and B labels of the custom colour gains. | proven |
| [`osd_draw_color_gain_row`](../../src/leon2m/osd/osd_draw_color_gain_row.c) | `FUN_a00ab96c` | Draw the red, green or blue gain row of the custom colour page. | derived |
| [`osd_draw_color_temp_choices`](../../src/leon2m/osd/osd_draw_color_temp_choices.c) | `FUN_a00a8570` | Draw the Color Temperature choices and mark the current one. | proven |
| [`osd_draw_contrast_slider`](../../src/leon2m/osd/osd_draw_contrast_slider.c) | `FUN_a00b6f20` | Draw the Contrast slider with its value and key guide. | proven |
| [`osd_draw_crosshair_color_choices`](../../src/leon2m/osd/osd_draw_crosshair_color_choices.c) | `FUN_a00b3ac8` | Draw the Smart Crosshair colour choices: White, Red, Auto. | proven |
| [`osd_draw_crosshair_icon_page`](../../src/leon2m/osd/osd_draw_crosshair_icon_page.c) | `FUN_a00ab0e0` | Draw the Smart Crosshair icon choices. | derived |
| [`osd_draw_crosshair_items`](../../src/leon2m/osd/osd_draw_crosshair_items.c) | `FUN_a00a82c4` | Draw the Smart Crosshair items: Icon, Color, Position, Reset. | proven |
| [`osd_draw_crosshair_quick_menu`](../../src/leon2m/osd/osd_draw_crosshair_quick_menu.c) | `FUN_a00adaf4` | Draw the Smart Crosshair quick menu list. | derived |
| [`osd_draw_custom_color_page`](../../src/leon2m/osd/osd_draw_custom_color_page.c) | `FUN_a00b7474` | Draw the custom colour page with the red, green and blue gain bars. | derived |
| [`osd_draw_default_key_guide`](../../src/leon2m/osd/osd_draw_default_key_guide.c) | `FUN_a00aa4c0` | Draw the default key guide (icons and texts) | derived |
| [`osd_draw_detection_level_slider`](../../src/leon2m/osd/osd_draw_detection_level_slider.c) | `FUN_a00b7e68` | Draw a logo/taskbar/boundary detection level slider with its number. | proven |
| [`osd_draw_dialog_frame`](../../src/leon2m/osd/osd_draw_dialog_frame.c) | `FUN_a00b0a90` | Draw the frame of a dialog box and highlight its current button. | derived |
| [`osd_draw_display_hdr_choices`](../../src/leon2m/osd/osd_draw_display_hdr_choices.c) | `FUN_a00a8654` | Draw the DisplayHDR choices. | proven |
| [`osd_draw_dsc_switch`](../../src/leon2m/osd/osd_draw_dsc_switch.c) | `FUN_a00b6b68` | Draw the DSC switch of the Gaming page. | derived |
| [`osd_draw_factory_aux0_hours`](../../src/leon2m/osd/osd_draw_factory_aux0_hours.c) | `FUN_a008e520` | Draw factory record halfword +0x12 (the hours count) as five digits. | derived |
| [`osd_draw_factory_aux0_minutes`](../../src/leon2m/osd/osd_draw_factory_aux0_minutes.c) | `FUN_a008e5b8` | Draw factory record byte +0x11 (the minutes count) as two digits. | descriptive |
| [`osd_draw_factory_field_value`](../../src/leon2m/osd/osd_draw_factory_field_value.c) | `FUN_a008a778` | Draw the stored value 0xA802AFBA in factory menu field 0x16. | descriptive |
| [`osd_draw_factory_info_page`](../../src/leon2m/osd/osd_draw_factory_info_page.c) | `FUN_a008ce90` | Draw the factory information page: model, firmware version, serial, panel, on-time. | proven |
| [`osd_draw_factory_menu`](../../src/leon2m/osd/osd_draw_factory_menu.c) | `FUN_a008d2f8` | Draw the whole factory service menu with all item labels and values. | proven |
| [`osd_draw_factory_number`](../../src/leon2m/osd/osd_draw_factory_number.c) | `FUN_a008a568` | Draw a number as 1 or 3 digits in factory menu field id. | derived |
| [`osd_draw_factory_phy_cts_auto`](../../src/leon2m/osd/osd_draw_factory_phy_cts_auto.c) | `FUN_a008ac90` | Draw ON or OFF for the factory menu item "PHY CTS AUTO" (saved setting 2) | proven |
| [`osd_draw_factory_sensing_test`](../../src/leon2m/osd/osd_draw_factory_sensing_test.c) | `FUN_a008ac00` | Draw ON or OFF for the factory menu item "Sensing Test" (saved setting 0x10) | derived |
| [`osd_draw_factory_ssc_freq`](../../src/leon2m/osd/osd_draw_factory_ssc_freq.c) | `FUN_a008b380` | Draw the selected spread-spectrum clock frequency (kHz/MHz) in the factory menu. | derived |
| [`osd_draw_factory_ssc_ratio`](../../src/leon2m/osd/osd_draw_factory_ssc_ratio.c) | `FUN_a008b5e0` | Draw the spread-spectrum ratio (x.xx %) and its register value in the factory menu. | derived |
| [`osd_draw_frame_highlight`](../../src/leon2m/osd/osd_draw_frame_highlight.c) | `FUN_a00ad5a4` | Draw the plain or selected frame of a three-row block: quick menu row or dialog button. | derived |
| [`osd_draw_game_mode_choices`](../../src/leon2m/osd/osd_draw_game_mode_choices.c) | `FUN_a00b617c` | Draw the game mode choices and mark the current one. | proven |
| [`osd_draw_game_mode_quick_menu`](../../src/leon2m/osd/osd_draw_game_mode_quick_menu.c) | `FUN_a00b8ca8` | Draw one page of the Game Mode quick menu and highlight the current mode when it is on that page. | proven |
| [`osd_draw_gaming_item_state`](../../src/leon2m/osd/osd_draw_gaming_item_state.c) | `FUN_a00aa0e8` | Draw the switch state of a Gaming item and set the key guide. | derived |
| [`osd_draw_gaming_items`](../../src/leon2m/osd/osd_draw_gaming_items.c) | `FUN_a00ad02c` | Draw the Gaming items (Game Mode .. DSC) and their states. | proven |
| [`osd_draw_gi_items`](../../src/leon2m/osd/osd_draw_gi_items.c) | `FUN_a00aaaac` | Draw the G.I. items: KVM, Smart Crosshair, Optix Scope. | proven |
| [`osd_draw_green_gain`](../../src/leon2m/osd/osd_draw_green_gain.c) | `FUN_a00abc64` | Draw the green gain slider of the custom colour page. | derived |
| [`osd_draw_hdmi_cec_switch`](../../src/leon2m/osd/osd_draw_hdmi_cec_switch.c) | `FUN_a00b7980` | Draw the HDMI CEC switch, shown off while PIP/PBP is on. | proven |
| [`osd_draw_hdr_icon`](../../src/leon2m/osd/osd_draw_hdr_icon.c) | `FUN_a00b8668` | Draw the small HDR icon window. | derived |
| [`osd_draw_image_enhancement_choices`](../../src/leon2m/osd/osd_draw_image_enhancement_choices.c) | `FUN_a00b6e1c` | Draw the Image Enhancement choices and mark the current level. | proven |
| [`osd_draw_image_items`](../../src/leon2m/osd/osd_draw_image_items.c) | `FUN_a00aabf0` | Draw the Image items: Brightness, Contrast, Sharpness, Color Temperature, ... | proven |
| [`osd_draw_info_box`](../../src/leon2m/osd/osd_draw_info_box.c) | `FUN_a00a5908` | Draw the information box frame and, in mode 1, the input details inside it. | derived |
| [`osd_draw_info_box_values`](../../src/leon2m/osd/osd_draw_info_box_values.c) | `FUN_a00b9750` | Draw the Info. On Screen box: input, resolutions, rate, mode, HDR and bit depth. | proven |
| [`osd_draw_info_on_screen_switch`](../../src/leon2m/osd/osd_draw_info_on_screen_switch.c) | `FUN_a00b7944` | Draw the Info. On Screen switch of the Settings page. | proven |
| [`osd_draw_input_choices`](../../src/leon2m/osd/osd_draw_input_choices.c) | `FUN_a00b621c` | Draw the four input names as a choice list. | proven |
| [`osd_draw_input_info_banner`](../../src/leon2m/osd/osd_draw_input_info_banner.c) | `FUN_a00b848c` | Draw the input info banner, or the HDR icon, after a new input is found. | derived |
| [`osd_draw_input_item_state`](../../src/leon2m/osd/osd_draw_input_item_state.c) | `FUN_a00aa01c` | Draw the switch state of the Input Source auto item and set the key guide. | descriptive |
| [`osd_draw_input_quick_menu`](../../src/leon2m/osd/osd_draw_input_quick_menu.c) | `FUN_a00b5d10` | Draw the input quick menu with the input names and the current one. | derived |
| [`osd_draw_input_source_items`](../../src/leon2m/osd/osd_draw_input_source_items.c) | `FUN_a00b3ba0` | Draw the Input Source items (the inputs) and the auto scan switch. | proven |
| [`osd_draw_item_choices`](../../src/leon2m/osd/osd_draw_item_choices.c) | `FUN_a00af44c` | Draw the choice column of the highlighted item and mark its current value. | derived |
| `osd_draw_item_choices_jump_table` | `switchdataD_a00a4154` | Jump table 1 of the switch statements in osd_draw_item_choices. | proven |
| [`osd_draw_item_row_state`](../../src/leon2m/osd/osd_draw_item_row_state.c) | `FUN_a00aacb4` | Redraw an item row in normal or greyed colours by whether it can be selected. | derived |
| [`osd_draw_key_guide`](../../src/leon2m/osd/osd_draw_key_guide.c) | `FUN_a00a9468` | Draw the key guide icons at the right edge for a menu level. | derived |
| [`osd_draw_key_guide_text`](../../src/leon2m/osd/osd_draw_key_guide_text.c) | `FUN_a00b344c` | Draw one key guide text in the key guide column. | derived |
| [`osd_draw_kvm_choices`](../../src/leon2m/osd/osd_draw_kvm_choices.c) | `FUN_a00b7a44` | Draw the KVM choices (Auto, Upstream, Type C) and mark the current one. | proven |
| [`osd_draw_language_list`](../../src/leon2m/osd/osd_draw_language_list.c) | `FUN_a00a87cc` | Draw the visible page of seven menu languages. | proven |
| [`osd_draw_low_blue_light_switch`](../../src/leon2m/osd/osd_draw_low_blue_light_switch.c) | `FUN_a00b6d58` | Draw the Low Blue Light switch, shown off while HDR is active. | proven |
| [`osd_draw_main_menu_frame`](../../src/leon2m/osd/osd_draw_main_menu_frame.c) | `FUN_a00b5378` | Set up the main menu layer and draw its frame, tabs and header. | derived |
| [`osd_draw_menu_header`](../../src/leon2m/osd/osd_draw_menu_header.c) | `FUN_a00a550c` | Draw the fixed frame cells of the main menu's top rows. | descriptive |
| [`osd_draw_message_frame`](../../src/leon2m/osd/osd_draw_message_frame.c) | `FUN_a00a5714` | Draw the frame of a message box around a cell position. | descriptive |
| [`osd_draw_mode_status_header`](../../src/leon2m/osd/osd_draw_mode_status_header.c) | `FUN_a00acc40` | Draw the top status lines: HDR on/off and the current game or Pro mode. | derived |
| [`osd_draw_navi_key_function_choices`](../../src/leon2m/osd/osd_draw_navi_key_function_choices.c) | `FUN_a00b7b8c` | Draw one page of the functions a Navi key direction can start. | proven |
| [`osd_draw_navi_key_items`](../../src/leon2m/osd/osd_draw_navi_key_items.c) | `FUN_a00a8230` | Draw the Navi Key items: Up, Down, Left, Right. | proven |
| [`osd_draw_navi_quick_menu`](../../src/leon2m/osd/osd_draw_navi_quick_menu.c) | `FUN_a00b8e7c` | Draw the quick menu of the function assigned to a Navi key. | derived |
| [`osd_draw_night_vision_choices`](../../src/leon2m/osd/osd_draw_night_vision_choices.c) | `FUN_a00a835c` | Draw the Night Vision choices and mark the current one. | proven |
| [`osd_draw_night_vision_quick_menu`](../../src/leon2m/osd/osd_draw_night_vision_quick_menu.c) | `FUN_a00ad970` | Draw the Night Vision quick menu list. | proven |
| [`osd_draw_no_signal_message`](../../src/leon2m/osd/osd_draw_no_signal_message.c) | `FUN_a00b8774` | Show the 'No Signal' message on a black screen. | proven |
| [`osd_draw_no_signal_with_input`](../../src/leon2m/osd/osd_draw_no_signal_with_input.c) | `FUN_a00b867c` | Show the input name with 'No Signal' and keep the panel on. | proven |
| [`osd_draw_number_2digits`](../../src/leon2m/osd/osd_draw_number_2digits.c) | `FUN_a008cc28` | Draw a number as two digits at a menu text position. | derived |
| [`osd_draw_number_5digits`](../../src/leon2m/osd/osd_draw_number_5digits.c) | `FUN_a008cd58` | Draw a number as five digits at a menu text position. | derived |
| [`osd_draw_oled_care_choices`](../../src/leon2m/osd/osd_draw_oled_care_choices.c) | `FUN_a00ac718` | Draw the choice list of an OLED Care setting and highlight the current one. | derived |
| `osd_draw_oled_care_choices_jump_table` | `switchdataD_a00a413c` | Jump table 1 of the switch statements in osd_draw_oled_care_choices. | proven |
| [`osd_draw_oled_care_items`](../../src/leon2m/osd/osd_draw_oled_care_items.c) | `FUN_a00aa83c` | Draw the MSI OLED Care items on the current page. | proven |
| [`osd_draw_on_time_hours`](../../src/leon2m/osd/osd_draw_on_time_hours.c) | `FUN_a008cdf0` | Draw the five-digit hours part of the monitor on-time counter. | derived |
| [`osd_draw_on_time_minutes`](../../src/leon2m/osd/osd_draw_on_time_minutes.c) | `FUN_a008ccc0` | Draw the two-digit minutes part of the monitor on-time counter. | derived |
| [`osd_draw_optix_scope_items`](../../src/leon2m/osd/osd_draw_optix_scope_items.c) | `FUN_a00b7ae4` | Draw the Optix Scope sub-items (Scope Size, Scope Ratio) and the on/off choice. | proven |
| [`osd_draw_out_of_range_message`](../../src/leon2m/osd/osd_draw_out_of_range_message.c) | `FUN_a00b87d4` | Show the 'Out Of Range!' message on a black screen. | proven |
| [`osd_draw_overlay_position_preview`](../../src/leon2m/osd/osd_draw_overlay_position_preview.c) | `FUN_a00a6b98` | Draw the overlay being positioned (crosshair, refresh rate or alarm timer) | derived |
| [`osd_draw_panel_ctrl_value`](../../src/leon2m/osd/osd_draw_panel_ctrl_value.c) | `FUN_a008abe0` | Draw the panel controller's register value in factory menu field 0x15. | derived |
| [`osd_draw_panel_protect_dialog`](../../src/leon2m/osd/osd_draw_panel_protect_dialog.c) | `FUN_a00b1ba4` | Draw the panel protect dialog page with its explanation rows and buttons. | derived |
| [`osd_draw_panel_protect_prompt`](../../src/leon2m/osd/osd_draw_panel_protect_prompt.c) | `FUN_a00b1700` | Draw the OLED panel protect prompt with its text and buttons. | derived |
| [`osd_draw_pbp_items`](../../src/leon2m/osd/osd_draw_pbp_items.c) | `FUN_a00a9abc` | Draw the PBP items: mode, sources, display and audio switch, and mark the mode. | proven |
| [`osd_draw_pip_items`](../../src/leon2m/osd/osd_draw_pip_items.c) | `FUN_a00a86e8` | Draw the PIP items: Source, PIP Size, Location, Display Switch, Audio Switch. | proven |
| [`osd_draw_pip_location_choices`](../../src/leon2m/osd/osd_draw_pip_location_choices.c) | `FUN_a00ab340` | Draw the PIP Location choices (four corners and Customize) | proven |
| [`osd_draw_pip_location_choices_copy`](../../src/leon2m/osd/osd_draw_pip_location_choices_copy.c) | `FUN_a00b3070` | Draw the five location choices (four corners and Customize) of the Alarm Clock Location list. | proven |
| [`osd_draw_pip_location_choices_copy2`](../../src/leon2m/osd/osd_draw_pip_location_choices_copy2.c) | `FUN_a00b3108` | Draw the five location choices (four corners and Customize) of the Refresh Rate Location list. | proven |
| [`osd_draw_pip_pbp_items`](../../src/leon2m/osd/osd_draw_pip_pbp_items.c) | `FUN_a00b3c80` | Draw the PIP/PBP items: OFF, PIP, PBP. | proven |
| [`osd_draw_pip_size_choices`](../../src/leon2m/osd/osd_draw_pip_size_choices.c) | `FUN_a00ab2a8` | Draw the PIP Size choices: Small, Medium, Large. | proven |
| [`osd_draw_power_button_choices`](../../src/leon2m/osd/osd_draw_power_button_choices.c) | `FUN_a00b789c` | Draw the Power Button choices (OFF, Standby) and mark the current one. | proven |
| [`osd_draw_power_led_switch`](../../src/leon2m/osd/osd_draw_power_led_switch.c) | `FUN_a00b7a08` | Draw the Power LED switch of the Settings page. | proven |
| [`osd_draw_pro_mode_choices`](../../src/leon2m/osd/osd_draw_pro_mode_choices.c) | `FUN_a00b6bec` | Draw the Professional mode list and grey out modes not usable now. | proven |
| [`osd_draw_professional_item_state`](../../src/leon2m/osd/osd_draw_professional_item_state.c) | `FUN_a00aa258` | Draw the switch state of a Professional item and set the key guide. | derived |
| [`osd_draw_professional_items`](../../src/leon2m/osd/osd_draw_professional_items.c) | `FUN_a00aa9d8` | Draw the Professional items: Pro Mode, Low Blue Light, Image Enhancement. | proven |
| [`osd_draw_quick_menu_frame`](../../src/leon2m/osd/osd_draw_quick_menu_frame.c) | `FUN_a00a788c` | Draw the frame and arrow cells of a quick menu by its kind. | descriptive |
| [`osd_draw_quick_menu_mark`](../../src/leon2m/osd/osd_draw_quick_menu_mark.c) | `FUN_a00b3614` | Draw or clear the current-value mark in a quick menu row. | descriptive |
| [`osd_draw_quick_switch`](../../src/leon2m/osd/osd_draw_quick_switch.c) | `FUN_a00a4a30` | Draw the OFF/ON switch of a quick menu in the given position. | descriptive |
| [`osd_draw_red_gain`](../../src/leon2m/osd/osd_draw_red_gain.c) | `FUN_a00abe94` | Draw the red gain slider of the custom colour page. | derived |
| [`osd_draw_refresh_rate_choices`](../../src/leon2m/osd/osd_draw_refresh_rate_choices.c) | `FUN_a00a8440` | Draw the Refresh Rate choices (OFF, ON, Location) and mark the current one. | derived |
| [`osd_draw_refresh_rate_counter`](../../src/leon2m/osd/osd_draw_refresh_rate_counter.c) | `FUN_a00b88e0` | Draw the current refresh rate as 'nnn HZ' in the overlay box. | proven |
| [`osd_draw_reset_confirm_choices`](../../src/leon2m/osd/osd_draw_reset_confirm_choices.c) | `FUN_a00a89e4` | Draw the Yes and No choices of the Reset question. | proven |
| [`osd_draw_response_time_choices`](../../src/leon2m/osd/osd_draw_response_time_choices.c) | `FUN_a00ab3d8` | Draw the Normal, Fast, Fastest choices and mark the current one. | descriptive |
| [`osd_draw_rgb_brightness_levels`](../../src/leon2m/osd/osd_draw_rgb_brightness_levels.c) | `FUN_a00ac0c4` | Draw the five RGB Brightness level texts. | derived |
| [`osd_draw_rgb_led_choices`](../../src/leon2m/osd/osd_draw_rgb_led_choices.c) | `FUN_a00b77b4` | Draw the RGB LED choices and mark the current one. | derived |
| [`osd_draw_scope_ratio_choices`](../../src/leon2m/osd/osd_draw_scope_ratio_choices.c) | `FUN_a00b3238` | Draw the Optix Scope zoom ratio choices. | derived |
| [`osd_draw_scope_size_choices`](../../src/leon2m/osd/osd_draw_scope_size_choices.c) | `FUN_a00b31a0` | Draw the Optix Scope size choices: Small, Medium, Large. | proven |
| [`osd_draw_screen_size_choices`](../../src/leon2m/osd/osd_draw_screen_size_choices.c) | `FUN_a00aaf48` | Draw the Screen Size choices and mark the current one. | proven |
| [`osd_draw_settings_item_state`](../../src/leon2m/osd/osd_draw_settings_item_state.c) | `FUN_a00aa33c` | Draw the switch state of a Settings item (rows 5..8) and set the key guide. | derived |
| [`osd_draw_settings_items`](../../src/leon2m/osd/osd_draw_settings_items.c) | `FUN_a00ad1c0` | Draw the Settings items (Language .. Reset) and their states. | proven |
| [`osd_draw_sharpness_slider`](../../src/leon2m/osd/osd_draw_sharpness_slider.c) | `FUN_a00b7188` | Draw the Sharpness slider with its value and key guide. | proven |
| [`osd_draw_signal_info_header`](../../src/leon2m/osd/osd_draw_signal_info_header.c) | `FUN_a00b3860` | Draw the menu header: input, resolution, refresh rate, firmware and model. | proven |
| [`osd_draw_signal_message`](../../src/leon2m/osd/osd_draw_signal_message.c) | `FUN_a00b7f9c` | Draw one signal message window (no signal, out of range, input banner, HDR icon) | proven |
| `osd_draw_signal_message_jump_table` | `switchdataD_a00b32ac` | Jump table 1 of the switch statements in osd_draw_signal_message. | proven |
| [`osd_draw_slider_bar`](../../src/leon2m/osd/osd_draw_slider_bar.c) | `FUN_a00a45c0` | Draw a value bar of cells: full cells, one partial cell, then empty cells. | derived |
| [`osd_draw_slider_label_row`](../../src/leon2m/osd/osd_draw_slider_label_row.c) | `FUN_a00b60cc` | Draw the label cells of a slider row in active or normal colours. | descriptive |
| [`osd_draw_static_screen_level_slider`](../../src/leon2m/osd/osd_draw_static_screen_level_slider.c) | `FUN_a00b7d14` | Draw the Static Screen Detection reduce-level slider. | proven |
| [`osd_draw_tab_icons`](../../src/leon2m/osd/osd_draw_tab_icons.c) | `FUN_a00a7aec` | Draw the tab icons of the left column (tabs 0..6, or 7..8 on the second page) | derived |
| `osd_draw_tab_icons_jump_table` | `switchdataD_a00a3854` | Jump table 1 of the switch statements in osd_draw_tab_icons. | proven |
| [`osd_draw_tab_names`](../../src/leon2m/osd/osd_draw_tab_names.c) | `FUN_a00b3d14` | Draw the tab names of the left column (first or second page) | proven |
| [`osd_draw_tab_page`](../../src/leon2m/osd/osd_draw_tab_page.c) | `FUN_a00b0034` | Draw the item list and first choices of a main menu tab. | proven |
| `osd_draw_tab_page_jump_table` | `switchdataD_a00a41fc` | Jump table 1 of the switch statements in osd_draw_tab_page. | proven |
| [`osd_draw_tab_row_frame`](../../src/leon2m/osd/osd_draw_tab_row_frame.c) | `FUN_a00a8bc0` | Draw the frame cells around a tab row. | descriptive |
| [`osd_draw_text`](../../src/leon2m/osd/osd_draw_text.c) | `FUN_a00a31a4` | Draw a menu text (length byte, characters, font codes) at a cell position. | proven |
| [`osd_draw_three_digit_number`](../../src/leon2m/osd/osd_draw_three_digit_number.c) | `FUN_a00b6ec8` | Draw a number as three digits at a menu position. | derived |
| [`osd_draw_timeout_slider`](../../src/leon2m/osd/osd_draw_timeout_slider.c) | `FUN_a00b7674` | Draw the OSD Time out slider with its value and key guide. | proven |
| [`osd_draw_toggle_switch`](../../src/leon2m/osd/osd_draw_toggle_switch.c) | `FUN_a00a9f30` | Draw the OFF/ON switch of a Settings item in normal colours. | derived |
| [`osd_draw_toggle_switch_selected`](../../src/leon2m/osd/osd_draw_toggle_switch_selected.c) | `FUN_a00a5420` | Draw the OFF/ON switch of a Settings item in selected colours. | derived |
| [`osd_draw_transparency_slider`](../../src/leon2m/osd/osd_draw_transparency_slider.c) | `FUN_a00b7530` | Draw the menu Transparency slider with its value and key guide. | proven |
| [`osd_draw_type_c_pd_charge_switch`](../../src/leon2m/osd/osd_draw_type_c_pd_charge_switch.c) | `FUN_a00b79d0` | Draw the Type C PD Charge switch of the Settings page. | proven |
| [`osd_draw_value_number`](../../src/leon2m/osd/osd_draw_value_number.c) | `FUN_a00b3708` | Draw a value as up to three digits at a cell position. | derived |
| [`osd_draw_value_slider`](../../src/leon2m/osd/osd_draw_value_slider.c) | `FUN_a00ab5f0` | Draw a value slider: bar cells for the value and its number. | derived |
| [`osd_enable`](../../src/leon2m/osd/osd_enable.c) | `FUN_a011cca0` | Switch a menu layer on or off. | derived |
| [`osd_enable_window`](../../src/leon2m/osd/osd_enable_window.c) | `FUN_a011a1b0` | Switch on one of the eight windows of a menu layer. | derived |
| `osd_enable_window_jump_table` | `switchdataD_a011915c` | Jump table 1 of the switch statements in osd_enable_window. | proven |
| [`osd_enter_alarm_clock_choices`](../../src/leon2m/osd/osd_enter_alarm_clock_choices.c) | `FUN_a0093694` | Open the Alarm Clock choices (Location, Off, four timers) on the current setting. | derived |
| [`osd_enter_color_temp_choices`](../../src/leon2m/osd/osd_enter_color_temp_choices.c) | `FUN_a0096494` | Open the Color Temperature list on the current setting. | derived |
| [`osd_enter_crosshair_settings`](../../src/leon2m/osd/osd_enter_crosshair_settings.c) | `FUN_a0095930` | Open the Smart Crosshair settings (Icon, Color, Position, Reset) | derived |
| [`osd_enter_detection_choices`](../../src/leon2m/osd/osd_enter_detection_choices.c) | `FUN_a00a13d8` | Open the OFF/ON/level choice of the highlighted OLED Care detection item. | derived |
| [`osd_enter_display_hdr_choices`](../../src/leon2m/osd/osd_enter_display_hdr_choices.c) | `FUN_a0096c80` | Open the DisplayHDR list on the current setting. | derived |
| [`osd_enter_game_mode_choices`](../../src/leon2m/osd/osd_enter_game_mode_choices.c) | `FUN_a00a03e8` | Switch to Game mode and open the game mode list (OK/right on 'Game Mode') | derived |
| [`osd_enter_gaming_items`](../../src/leon2m/osd/osd_enter_gaming_items.c) | `FUN_a00918f4` | Enter the Gaming tab's list (Game Mode .. DSC) at its first enabled item. | proven |
| [`osd_enter_gi_items`](../../src/leon2m/osd/osd_enter_gi_items.c) | `FUN_a0091668` | Enter the G.I. tab's list (KVM, Smart Crosshair, Optix Scope) at its first enabled item. | proven |
| [`osd_enter_image_enhancement_choices`](../../src/leon2m/osd/osd_enter_image_enhancement_choices.c) | `FUN_a00961d4` | Open the Image Enhancement levels on the current setting. | derived |
| [`osd_enter_image_items`](../../src/leon2m/osd/osd_enter_image_items.c) | `FUN_a0091f58` | Enter the Image tab's list at its first enabled item (OK or right key) | proven |
| [`osd_enter_input_source_items`](../../src/leon2m/osd/osd_enter_input_source_items.c) | `FUN_a009221c` | Enter the Input Source list with the current input highlighted (OK or right key) | proven |
| [`osd_enter_kvm_choices`](../../src/leon2m/osd/osd_enter_kvm_choices.c) | `FUN_a00994b8` | Open the KVM list (Auto, Upstream, Type C) on the current setting. | derived |
| [`osd_enter_language_choices`](../../src/leon2m/osd/osd_enter_language_choices.c) | `FUN_a00989c8` | Open the Language list on the current language. | derived |
| [`osd_enter_navi_down_choices`](../../src/leon2m/osd/osd_enter_navi_down_choices.c) | `FUN_a0098794` | Open the function list of the Navi Key direction being edited (OK / right on the Down item). | derived |
| [`osd_enter_navi_key_items`](../../src/leon2m/osd/osd_enter_navi_key_items.c) | `FUN_a0092908` | Enter the Navi Key tab's list at its first enabled item (OK or right key) | proven |
| [`osd_enter_navi_left_choices`](../../src/leon2m/osd/osd_enter_navi_left_choices.c) | `FUN_a0098850` | Open the function list of the Navi Key direction being edited (OK / right on the Left item). | derived |
| [`osd_enter_navi_right_choices`](../../src/leon2m/osd/osd_enter_navi_right_choices.c) | `FUN_a009890c` | Open the function list of the Navi Key direction being edited (OK / right on the Right item). | derived |
| [`osd_enter_navi_up_choices`](../../src/leon2m/osd/osd_enter_navi_up_choices.c) | `FUN_a0098434` | Open the function list of the Navi Key direction being edited (OK / right on the Up item). | derived |
| [`osd_enter_night_vision_choices`](../../src/leon2m/osd/osd_enter_night_vision_choices.c) | `FUN_a0095afc` | Open the Night Vision levels on the current setting. | derived |
| [`osd_enter_oled_care_items`](../../src/leon2m/osd/osd_enter_oled_care_items.c) | `FUN_a0092ea8` | Enter the MSI OLED Care tab's list at its first enabled item (OK or right key) | proven |
| [`osd_enter_optix_scope_choices`](../../src/leon2m/osd/osd_enter_optix_scope_choices.c) | `FUN_a00995f0` | Open the Optix Scope list (Scope Size, Scope Ratio, OFF, ON) on the current setting. | derived |
| [`osd_enter_pbp_settings`](../../src/leon2m/osd/osd_enter_pbp_settings.c) | `FUN_a00979ec` | Switch to PBP and open its settings list on the current PBP mode. | derived |
| [`osd_enter_pbp_source1_choices`](../../src/leon2m/osd/osd_enter_pbp_source1_choices.c) | `FUN_a0098280` | Open the input list for PBP Source 1 on the current main input. | derived |
| [`osd_enter_pbp_source2_choices`](../../src/leon2m/osd/osd_enter_pbp_source2_choices.c) | `FUN_a00982f0` | Open the input list for PBP Source 2 on the current second input. | derived |
| [`osd_enter_pip_location_choices`](../../src/leon2m/osd/osd_enter_pip_location_choices.c) | `FUN_a0097c54` | Open the PIP Location list (four corners, Customize) on the current one. | derived |
| [`osd_enter_pip_pbp_items`](../../src/leon2m/osd/osd_enter_pip_pbp_items.c) | `FUN_a0092524` | Enter the PIP/PBP list with the current layout highlighted (OK or right key) | proven |
| [`osd_enter_pip_settings`](../../src/leon2m/osd/osd_enter_pip_settings.c) | `FUN_a00978c8` | Switch to PIP and open its settings list (Source, Size, Location, ...) | derived |
| [`osd_enter_pip_size_choices`](../../src/leon2m/osd/osd_enter_pip_size_choices.c) | `FUN_a0097bec` | Open the PIP Size list (Small, Medium, Large) on the current size. | derived |
| [`osd_enter_pip_source_choices`](../../src/leon2m/osd/osd_enter_pip_source_choices.c) | `FUN_a0097b7c` | Open the PIP Source list on the current sub-window input. | derived |
| [`osd_enter_pixel_shift_choices`](../../src/leon2m/osd/osd_enter_pixel_shift_choices.c) | `FUN_a0099c0c` | Open the Pixel Shift speed list (Slow, Normal, Fast) on the current setting. | derived |
| [`osd_enter_power_button_choices`](../../src/leon2m/osd/osd_enter_power_button_choices.c) | `FUN_a009906c` | Open the Power Button list (OFF, Standby) on the current setting. | derived |
| [`osd_enter_pro_mode_choices`](../../src/leon2m/osd/osd_enter_pro_mode_choices.c) | `FUN_a00a01fc` | Switch to Pro mode and open the Pro mode list (OK/right on 'Pro Mode') | derived |
| [`osd_enter_professional_items`](../../src/leon2m/osd/osd_enter_professional_items.c) | `FUN_a0091cc0` | Enter the Professional tab's list at its first enabled item (OK or right key) | proven |
| [`osd_enter_protect_notice_choices`](../../src/leon2m/osd/osd_enter_protect_notice_choices.c) | `FUN_a009a020` | Open the Protect Notice choices (Auto, Usage 24 hrs) on the current setting. | derived |
| [`osd_enter_refresh_rate_choices`](../../src/leon2m/osd/osd_enter_refresh_rate_choices.c) | `FUN_a0093464` | Open the Refresh Rate choices (On/Off, Location) on the current setting. | derived |
| [`osd_enter_rgb_led_choices`](../../src/leon2m/osd/osd_enter_rgb_led_choices.c) | `FUN_a0098e6c` | Open the RGB LED list (OFF, ON, RGB Brightness) on the current setting. | derived |
| [`osd_enter_scope_ratio_choices`](../../src/leon2m/osd/osd_enter_scope_ratio_choices.c) | `FUN_a0099a34` | Open the Optix Scope ratio list on the current ratio. | derived |
| [`osd_enter_scope_size_choices`](../../src/leon2m/osd/osd_enter_scope_size_choices.c) | `FUN_a00999ec` | Open the Optix Scope size list on the current size. | derived |
| [`osd_enter_screen_size_choices`](../../src/leon2m/osd/osd_enter_screen_size_choices.c) | `FUN_a00967f0` | Open the Screen Size list on the current setting. | derived |
| [`osd_enter_settings_items`](../../src/leon2m/osd/osd_enter_settings_items.c) | `FUN_a0092b18` | Enter the Settings tab's list at its first enabled item (OK or right key) | proven |
| [`osd_enter_static_screen_choices`](../../src/leon2m/osd/osd_enter_static_screen_choices.c) | `FUN_a0099cfc` | Open the Static Screen Detection choices on the current setting. | derived |
| [`osd_factory_activate_item`](../../src/leon2m/osd/osd_factory_activate_item.c) | `FUN_a008e270` | Run the selected factory menu item: Reset, Exit or start editing its value. | derived |
| [`osd_factory_close_menu`](../../src/leon2m/osd/osd_factory_close_menu.c) | `FUN_a009e820` | Close the factory menu and hide the menu layer (left key) | derived |
| [`osd_factory_cursor_down`](../../src/leon2m/osd/osd_factory_cursor_down.c) | `FUN_a008a878` | Move the factory menu highlight to the next item (wraps) | derived |
| [`osd_factory_cursor_up`](../../src/leon2m/osd/osd_factory_cursor_up.c) | `FUN_a008a794` | Move the factory menu highlight to the previous item (wraps) | derived |
| [`osd_factory_decrease_value`](../../src/leon2m/osd/osd_factory_decrease_value.c) | `FUN_a008b83c` | Lower or toggle the value of the selected factory menu item and redraw it. | proven |
| `osd_factory_decrease_value_jump_table` | `switchdataD_a008a35c` | Jump table 1 of the switch statements in osd_factory_decrease_value. | proven |
| [`osd_factory_edit_key_down`](../../src/leon2m/osd/osd_factory_edit_key_down.c) | `FUN_a009eac0` | Raise or toggle the edited factory menu value (down key) | proven |
| [`osd_factory_edit_key_up`](../../src/leon2m/osd/osd_factory_edit_key_up.c) | `FUN_a009eadc` | Lower or toggle the edited factory menu value (up key) | proven |
| [`osd_factory_enter_item_edit`](../../src/leon2m/osd/osd_factory_enter_item_edit.c) | `FUN_a009ea88` | Run or start editing the highlighted factory menu item (OK/right) | proven |
| [`osd_factory_increase_value`](../../src/leon2m/osd/osd_factory_increase_value.c) | `FUN_a008c25c` | Raise or toggle the value of the selected factory menu item and redraw it. | proven |
| `osd_factory_increase_value_jump_table` | `switchdataD_a008a3c8` | Jump table 1 of the switch statements in osd_factory_increase_value. | proven |
| [`osd_factory_leave_item_edit`](../../src/leon2m/osd/osd_factory_leave_item_edit.c) | `FUN_a009eaa4` | Finish editing a factory menu value and return to the item list. | derived |
| [`osd_factory_menu_key_down`](../../src/leon2m/osd/osd_factory_menu_key_down.c) | `FUN_a009ea5c` | Move the factory menu highlight to the next item (down key) | proven |
| [`osd_factory_menu_key_up`](../../src/leon2m/osd/osd_factory_menu_key_up.c) | `FUN_a009ea40` | Move the factory menu highlight to the previous item (up key) | proven |
| [`osd_factory_open_menu`](../../src/leon2m/osd/osd_factory_open_menu.c) | `FUN_a009ea24` | Open the factory service menu. | derived |
| [`osd_factory_select_item`](../../src/leon2m/osd/osd_factory_select_item.c) | `FUN_a008a95c` | Move the factory menu highlight to the item's value and toggle item 0x14's switch. | descriptive |
| [`osd_factory_set_edit_state`](../../src/leon2m/osd/osd_factory_set_edit_state.c) | `FUN_a009ea78` | Set the menu state to factory item editing (0x112) | descriptive |
| [`osd_factory_show_keys_passed`](../../src/leon2m/osd/osd_factory_show_keys_passed.c) | `FUN_a008b2bc` | Show "All Key Pass" in the factory key test. | proven |
| [`osd_factory_show_pressed_key`](../../src/leon2m/osd/osd_factory_show_pressed_key.c) | `FUN_a008ad20` | Show the number of the front key just pressed and log it for the factory key test. | derived |
| `osd_factory_show_pressed_key_jump_table` | `switchdataD_a008a2d8` | Jump table 1 of the switch statements in osd_factory_show_pressed_key. | proven |
| [`osd_factory_update_key_test`](../../src/leon2m/osd/osd_factory_update_key_test.c) | `FUN_a009eaf8` | Show the front key just pressed in the factory key test and note when all passed. | derived |
| [`osd_flip_low_blue_light_setting`](../../src/leon2m/osd/osd_flip_low_blue_light_setting.c) | `FUN_a00b6d94` | Flip the Low Blue Light setting, redraw its switch and save the mode slot. | proven |
| [`osd_get_cell_height`](../../src/leon2m/osd/osd_get_cell_height.c) | `FUN_a01198b4` | Return the character cell height of a menu layer in lines. | derived |
| [`osd_get_cell_width`](../../src/leon2m/osd/osd_get_cell_width.c) | `FUN_a01198a0` | Return the character cell width of a menu layer in pixels. | derived |
| [`osd_get_columns`](../../src/leon2m/osd/osd_get_columns.c) | `FUN_a011966c` | Return the number of character columns of a menu layer. | derived |
| [`osd_get_crosshair_zone_range`](../../src/leon2m/osd/osd_get_crosshair_zone_range.c) | `FUN_a00ba068` | Work out which picture zones lie around the crosshair position. | derived |
| [`osd_get_detection_field`](../../src/leon2m/osd/osd_get_detection_field.c) | `FUN_a00a14bc` | Return one field of the open detection setting: switch, level, row, minimum or maximum. | derived |
| `osd_get_detection_field_jump_table` | `switchdataD_a008f3e8` | Jump table 1 of the switch statements in osd_get_detection_field. | proven |
| `osd_get_detection_field_jump_table2` | `switchdataD_a008f400` | Jump table 2 of the switch statements in osd_get_detection_field. | proven |
| [`osd_get_last_text_width`](../../src/leon2m/osd/osd_get_last_text_width.c) | `FUN_a00a3838` | Return the pixel width of the text drawn last. | derived |
| [`osd_get_menu_state`](../../src/leon2m/osd/osd_get_menu_state.c) | `FUN_a0090fcc` | Return the current menu state. | derived |
| [`osd_get_oled_care_text`](../../src/leon2m/osd/osd_get_oled_care_text.c) | `FUN_a00ac138` | Return the text of row i for an OLED Care choice list. | derived |
| [`osd_get_rows`](../../src/leon2m/osd/osd_get_rows.c) | `FUN_a0119684` | Return the number of character rows of a menu layer. | derived |
| [`osd_get_state_highlight_kind`](../../src/leon2m/osd/osd_get_state_highlight_kind.c) | `FUN_a00a8a78` | Return the key guide kind (0, 1 or 2) of the current menu state for a choice row. | descriptive |
| `osd_get_state_highlight_kind_jump_table` | `switchdataD_a00a3878` | Jump table 1 of the switch statements in osd_get_state_highlight_kind. | proven |
| [`osd_get_text`](../../src/leon2m/osd/osd_get_text.c) | `FUN_a00a3844` | Return the text pointer at an index of a menu text table. | derived |
| [`osd_get_text_mode`](../../src/leon2m/osd/osd_get_text_mode.c) | `FUN_a011b384` | Return the text drawing mode of a menu layer. | descriptive |
| [`osd_hide_menu`](../../src/leon2m/osd/osd_hide_menu.c) | `FUN_a00b5080` | Hide the menu layer, all its windows and layer 1, and clear bit 15 of app state halfword +0x3E. | proven |
| [`osd_highlight_choice_row`](../../src/leon2m/osd/osd_highlight_choice_row.c) | `FUN_a00a9650` | Highlight a choice row in the choice column and update the key guide. | derived |
| `osd_highlight_choice_row_jump_table` | `switchdataD_a00a3b64` | Jump table 1 of the switch statements in osd_highlight_choice_row. | proven |
| `osd_highlight_choice_row_jump_table2` | `switchdataD_a00a3e50` | Jump table 2 of the switch statements in osd_highlight_choice_row. | proven |
| [`osd_highlight_crosshair_icon`](../../src/leon2m/osd/osd_highlight_crosshair_icon.c) | `FUN_a00a9dac` | Highlight a Smart Crosshair icon row. | descriptive |
| [`osd_highlight_dialog_button`](../../src/leon2m/osd/osd_highlight_dialog_button.c) | `FUN_a00b0710` | Highlight the selected button of a dialog and unmark the others. | derived |
| [`osd_highlight_item_row`](../../src/leon2m/osd/osd_highlight_item_row.c) | `FUN_a00a900c` | Highlight an item row in the item column. | derived |
| [`osd_highlight_quick_menu_row`](../../src/leon2m/osd/osd_highlight_quick_menu_row.c) | `FUN_a00ad86c` | Highlight a row of a quick menu list. | derived |
| [`osd_highlight_tab`](../../src/leon2m/osd/osd_highlight_tab.c) | `FUN_a00b4144` | Highlight a tab of the left column and show the tab key guide. | derived |
| [`osd_ignore_panel_info_select`](../../src/leon2m/osd/osd_ignore_panel_info_select.c) | `FUN_a0099d6c` | Do nothing when OK or right is pressed on OLED Panel Info. | derived |
| [`osd_ignore_panel_info_select_copy`](../../src/leon2m/osd/osd_ignore_panel_info_select_copy.c) | `FUN_a0099e3c` | Do nothing when OK or right is pressed on OLED Panel Info. | derived |
| [`osd_ignore_panel_info_select_copy2`](../../src/leon2m/osd/osd_ignore_panel_info_select_copy2.c) | `FUN_a00b6ec0` | Do nothing when OK or right is pressed on OLED Panel Info. | derived |
| [`osd_ignore_panel_info_select_copy3`](../../src/leon2m/osd/osd_ignore_panel_info_select_copy3.c) | `FUN_a00bc90c` | Do nothing when OK or right is pressed on OLED Panel Info. | derived |
| [`osd_ignore_panel_info_select_copy4`](../../src/leon2m/osd/osd_ignore_panel_info_select_copy4.c) | `FUN_a00bc954` | Do nothing when OK or right is pressed on OLED Panel Info. | derived |
| [`osd_ignore_panel_info_select_copy5`](../../src/leon2m/osd/osd_ignore_panel_info_select_copy5.c) | `FUN_a00bdeb8` | Do nothing when OK or right is pressed on OLED Panel Info. | derived |
| [`osd_ignore_panel_info_select_copy6`](../../src/leon2m/osd/osd_ignore_panel_info_select_copy6.c) | `FUN_a00da840` | Do nothing when OK or right is pressed on OLED Panel Info. | derived |
| [`osd_ignore_panel_info_select_copy7`](../../src/leon2m/osd/osd_ignore_panel_info_select_copy7.c) | `FUN_a0121d44` | Do nothing when OK or right is pressed on OLED Panel Info. | derived |
| [`osd_ignore_panel_info_select_copy8`](../../src/leon2m/osd/osd_ignore_panel_info_select_copy8.c) | `FUN_a0145ee0` | Do nothing when OK or right is pressed on OLED Panel Info. | derived |
| [`osd_ignore_panel_info_select_copy9`](../../src/leon2m/osd/osd_ignore_panel_info_select_copy9.c) | `FUN_a0148374` | Do nothing when OK or right is pressed on OLED Panel Info. | derived |
| [`osd_increase_alarm_minutes_tens`](../../src/leon2m/osd/osd_increase_alarm_minutes_tens.c) | `FUN_a009e204` | Step the alarm timer's minutes tens digit up by one (down key) | derived |
| [`osd_increase_alarm_minutes_units`](../../src/leon2m/osd/osd_increase_alarm_minutes_units.c) | `FUN_a009e234` | Step the alarm timer's minutes units digit up by one (down key) | derived |
| [`osd_increase_alarm_seconds_tens`](../../src/leon2m/osd/osd_increase_alarm_seconds_tens.c) | `FUN_a009e264` | Step the alarm timer's seconds tens digit up by one (down key) | derived |
| [`osd_increase_alarm_seconds_units`](../../src/leon2m/osd/osd_increase_alarm_seconds_units.c) | `FUN_a009e294` | Step the alarm timer's seconds units digit up by one (down key) | derived |
| [`osd_increase_blue_gain`](../../src/leon2m/osd/osd_increase_blue_gain.c) | `FUN_a00abb98` | Raise the blue gain by 1 (right key) and apply it. | derived |
| [`osd_increase_brightness`](../../src/leon2m/osd/osd_increase_brightness.c) | `FUN_a00a4244` | Raise Brightness by 1 on its slider (right key) and apply it. | derived |
| [`osd_increase_contrast`](../../src/leon2m/osd/osd_increase_contrast.c) | `FUN_a00a42f0` | Raise Contrast by 1 on its slider (right key) and apply it. | derived |
| [`osd_increase_detection_level`](../../src/leon2m/osd/osd_increase_detection_level.c) | `FUN_a00a1cf0` | Raise the detection level on the slider one step (right key) | derived |
| `osd_increase_detection_level_jump_table` | `switchdataD_a00900b0` | Jump table 1 of the switch statements in osd_increase_detection_level. | proven |
| `osd_increase_detection_level_jump_table2` | `switchdataD_a0090198` | Jump table 2 of the switch statements in osd_increase_detection_level. | proven |
| `osd_increase_detection_level_jump_table3` | `switchdataD_a0090280` | Jump table 3 of the switch statements in osd_increase_detection_level. | proven |
| `osd_increase_detection_level_jump_table4` | `switchdataD_a0090368` | Jump table 4 of the switch statements in osd_increase_detection_level. | proven |
| `osd_increase_detection_level_jump_table5` | `switchdataD_a0090450` | Jump table 5 of the switch statements in osd_increase_detection_level. | proven |
| [`osd_increase_green_gain`](../../src/leon2m/osd/osd_increase_green_gain.c) | `FUN_a00abdc8` | Raise the green gain by 1 (right key) and apply it. | derived |
| [`osd_increase_osd_timeout`](../../src/leon2m/osd/osd_increase_osd_timeout.c) | `FUN_a00a44f4` | Raise OSD Time out by 5 on its slider (right key) and apply it. | derived |
| [`osd_increase_quick_brightness`](../../src/leon2m/osd/osd_increase_quick_brightness.c) | `FUN_a00a493c` | Raise Brightness by 1 in the Brightness quick menu (right key) | derived |
| [`osd_increase_red_gain`](../../src/leon2m/osd/osd_increase_red_gain.c) | `FUN_a00abff8` | Raise the red gain by 1 (right key) and apply it. | derived |
| [`osd_increase_rgb_brightness`](../../src/leon2m/osd/osd_increase_rgb_brightness.c) | `FUN_a009e2cc` | Raise the RGB LED brightness one step (0..4) and send it to the LED bar. | proven |
| [`osd_increase_sharpness`](../../src/leon2m/osd/osd_increase_sharpness.c) | `FUN_a00a439c` | Raise Sharpness by 1 on its slider (right key) and apply it. | derived |
| [`osd_increase_static_screen_reduce_level`](../../src/leon2m/osd/osd_increase_static_screen_reduce_level.c) | `FUN_a009e624` | Raise the Static Screen 'Reducing Level' one step (max 6) and redraw. | derived |
| [`osd_increase_transparency`](../../src/leon2m/osd/osd_increase_transparency.c) | `FUN_a00a4448` | Raise menu Transparency by 1 on its slider (right key) and apply it. | derived |
| [`osd_is_choice_enabled`](../../src/leon2m/osd/osd_is_choice_enabled.c) | `FUN_a00aad30` | Return 1 when a choice of the open list can be selected. | derived |
| [`osd_is_enabled`](../../src/leon2m/osd/osd_is_enabled.c) | `FUN_a011996c` | Return whether a menu layer is switched on. | derived |
| [`osd_is_item_enabled`](../../src/leon2m/osd/osd_is_item_enabled.c) | `FUN_a00aa520` | Return 1 when an item of the open tab can be selected. | derived |
| [`osd_is_tab_enabled`](../../src/leon2m/osd/osd_is_tab_enabled.c) | `FUN_a00aa4e0` | Return 1 when a menu tab can be entered (PIP/PBP needs SDR and no lock) | derived |
| [`osd_is_third_level_state`](../../src/leon2m/osd/osd_is_third_level_state.c) | `FUN_a00a8ae0` | Return 1 when a menu state is one of the states with a third-level list. | descriptive |
| [`osd_leave_crosshair_settings`](../../src/leon2m/osd/osd_leave_crosshair_settings.c) | `FUN_a00958c4` | Leave the Smart Crosshair settings and return to the G.I. list (left key) | derived |
| [`osd_leave_detection_choices`](../../src/leon2m/osd/osd_leave_detection_choices.c) | `FUN_a00a192c` | Leave the detection choices and return to the OLED Care item (left key) | derived |
| `osd_leave_detection_choices_jump_table` | `switchdataD_a008fa58` | Jump table 1 of the switch statements in osd_leave_detection_choices. | proven |
| `osd_leave_detection_choices_jump_table2` | `switchdataD_a008fb40` | Jump table 2 of the switch statements in osd_leave_detection_choices. | proven |
| [`osd_leave_gaming_items`](../../src/leon2m/osd/osd_leave_gaming_items.c) | `FUN_a00919b4` | Leave the Gaming item list and return the highlight to its tab (left key) | proven |
| [`osd_leave_gi_items`](../../src/leon2m/osd/osd_leave_gi_items.c) | `FUN_a0091710` | Leave the G.I. item list and return the highlight to the tab column. | proven |
| [`osd_leave_image_items`](../../src/leon2m/osd/osd_leave_image_items.c) | `FUN_a0092044` | Leave the Image item list and return the highlight to its tab (left key) | proven |
| [`osd_leave_input_source_items`](../../src/leon2m/osd/osd_leave_input_source_items.c) | `FUN_a00922f0` | Leave the Input Source list and return the highlight to its tab (left key) | proven |
| [`osd_leave_navi_key_items`](../../src/leon2m/osd/osd_leave_navi_key_items.c) | `FUN_a0092998` | Leave the Navi Key item list and return the highlight to its tab (left key) | proven |
| [`osd_leave_oled_care_items`](../../src/leon2m/osd/osd_leave_oled_care_items.c) | `FUN_a0092f2c` | Leave the MSI OLED Care item list and return the highlight to its tab (left key) | proven |
| [`osd_leave_optix_scope_choices`](../../src/leon2m/osd/osd_leave_optix_scope_choices.c) | `FUN_a0099970` | Leave the Optix Scope list and return to the G.I. item (left) | derived |
| [`osd_leave_pbp_settings`](../../src/leon2m/osd/osd_leave_pbp_settings.c) | `FUN_a0097ad0` | Restore the PBP mode saved on entry if changed and return to the PIP/PBP list. | derived |
| [`osd_leave_pip_pbp_items`](../../src/leon2m/osd/osd_leave_pip_pbp_items.c) | `FUN_a0092648` | Leave the PIP/PBP list and return the highlight to its tab (left key) | proven |
| [`osd_leave_pip_settings`](../../src/leon2m/osd/osd_leave_pip_settings.c) | `FUN_a0097988` | Leave the PIP settings list and return to the PIP/PBP list (left) | derived |
| [`osd_leave_pixel_shift_switch`](../../src/leon2m/osd/osd_leave_pixel_shift_switch.c) | `FUN_a0099d74` | Leave the Pixel Shift on/off list and return to the item (left) | derived |
| [`osd_leave_professional_items`](../../src/leon2m/osd/osd_leave_professional_items.c) | `FUN_a0091d74` | Leave the Professional item list and return the highlight to its tab (left key) | proven |
| [`osd_leave_protect_notice_choices`](../../src/leon2m/osd/osd_leave_protect_notice_choices.c) | `FUN_a009a078` | Leave the Protect Notice choices and return to the item (left) | derived |
| [`osd_leave_reset_confirm`](../../src/leon2m/osd/osd_leave_reset_confirm.c) | `FUN_a0099ad0` | Leave the Reset question without resetting and return to the item. | proven |
| [`osd_leave_rgb_led_choices`](../../src/leon2m/osd/osd_leave_rgb_led_choices.c) | `FUN_a009901c` | Leave the RGB LED list and return to the item (left) | derived |
| [`osd_leave_settings_items`](../../src/leon2m/osd/osd_leave_settings_items.c) | `FUN_a0092bb4` | Leave the Settings item list and return the highlight to its tab (left key) | proven |
| [`osd_leave_static_screen_choices`](../../src/leon2m/osd/osd_leave_static_screen_choices.c) | `FUN_a0099dd8` | Leave the Static Screen Detection list and return to the item (left) | derived |
| [`osd_load_layer_lookup_tables`](../../src/leon2m/osd/osd_load_layer_lookup_tables.c) | `FUN_a00a2bdc` | Load the start-up lookup table block into both menu layers. | descriptive |
| [`osd_mark_settings_changed`](../../src/leon2m/osd/osd_mark_settings_changed.c) | `FUN_a00b88b8` | Request that the changed settings are saved. | proven |
| [`osd_mark_settings_changed_copy`](../../src/leon2m/osd/osd_mark_settings_changed_copy.c) | `FUN_a00b88cc` | Request that the changed settings are saved. | proven |
| [`osd_move_cursor_blue_to_green`](../../src/leon2m/osd/osd_move_cursor_blue_to_green.c) | `FUN_a00967b8` | Move the gain editor cursor from the B row to the G row. | derived |
| [`osd_move_cursor_green_to_blue`](../../src/leon2m/osd/osd_move_cursor_green_to_blue.c) | `FUN_a009673c` | Move the gain editor cursor from the G row to the B row. | derived |
| [`osd_move_cursor_green_to_red`](../../src/leon2m/osd/osd_move_cursor_green_to_red.c) | `FUN_a0096780` | Move the gain editor cursor from the G row to the R row. | derived |
| [`osd_move_cursor_red_to_green`](../../src/leon2m/osd/osd_move_cursor_red_to_green.c) | `FUN_a0096704` | Move the gain editor cursor from the R row to the G row. | derived |
| [`osd_move_overlay_down`](../../src/leon2m/osd/osd_move_overlay_down.c) | `FUN_a0094988` | Move the edited indicator down in the position editor. | derived |
| [`osd_move_overlay_left`](../../src/leon2m/osd/osd_move_overlay_left.c) | `FUN_a00945a8` | Move the edited indicator left in the position editor. | derived |
| [`osd_move_overlay_right`](../../src/leon2m/osd/osd_move_overlay_right.c) | `FUN_a0094b6c` | Move the edited indicator right in the position editor. | derived |
| [`osd_move_overlay_up`](../../src/leon2m/osd/osd_move_overlay_up.c) | `FUN_a009478c` | Move the edited indicator up in the position editor. | derived |
| [`osd_move_pip_window_down`](../../src/leon2m/osd/osd_move_pip_window_down.c) | `FUN_a0094108` | Move the custom PIP window down, in bigger steps while the key is held. | derived |
| [`osd_move_pip_window_left`](../../src/leon2m/osd/osd_move_pip_window_left.c) | `FUN_a0093bac` | Move the custom PIP window left by a step of 8. | derived |
| [`osd_move_pip_window_right`](../../src/leon2m/osd/osd_move_pip_window_right.c) | `FUN_a0093d30` | Move the custom PIP window right by a step of 8. | derived |
| [`osd_move_pip_window_up`](../../src/leon2m/osd/osd_move_pip_window_up.c) | `FUN_a0093f90` | Move the custom PIP window up by a step of 8. | derived |
| [`osd_open_alarm_clock_location`](../../src/leon2m/osd/osd_open_alarm_clock_location.c) | `FUN_a00936fc` | Open the screen-position list for the alarm clock display. | derived |
| [`osd_open_alarm_clock_position`](../../src/leon2m/osd/osd_open_alarm_clock_position.c) | `FUN_a00943ec` | Open the free position editor for the alarm clock display. | derived |
| [`osd_open_alarm_time_editor`](../../src/leon2m/osd/osd_open_alarm_time_editor.c) | `FUN_a0093884` | Open the minutes:seconds editor for the highlighted alarm timer. | derived |
| [`osd_open_brightness_slider`](../../src/leon2m/osd/osd_open_brightness_slider.c) | `FUN_a0096338` | Open the Brightness slider (OK or right key) | derived |
| [`osd_open_change_notice`](../../src/leon2m/osd/osd_open_change_notice.c) | `FUN_a00a01b8` | Show the mode change notice (menu state 0x116) | derived |
| [`osd_open_contrast_slider`](../../src/leon2m/osd/osd_open_contrast_slider.c) | `FUN_a00963ac` | Open the Contrast slider (OK or right key) | derived |
| [`osd_open_crosshair_color`](../../src/leon2m/osd/osd_open_crosshair_color.c) | `FUN_a00957e8` | Open the crosshair colour list (White, Red, Auto) on the current colour. | derived |
| [`osd_open_crosshair_icon`](../../src/leon2m/osd/osd_open_crosshair_icon.c) | `FUN_a0095778` | Open the crosshair icon picker on the current icon. | derived |
| [`osd_open_crosshair_position`](../../src/leon2m/osd/osd_open_crosshair_position.c) | `FUN_a0094368` | Open the free position editor for the Smart Crosshair. | derived |
| [`osd_open_custom_color_gains`](../../src/leon2m/osd/osd_open_custom_color_gains.c) | `FUN_a0096610` | Open the R/G/B gain editor of the Customization colour temperature. | derived |
| [`osd_open_detection_level_slider`](../../src/leon2m/osd/osd_open_detection_level_slider.c) | `FUN_a00a231c` | Open the level slider when the level row is highlighted (right key) | derived |
| [`osd_open_dialog_layer`](../../src/leon2m/osd/osd_open_dialog_layer.c) | `FUN_a00b0ef8` | Set up the overlay layer as a 40 x 11 dialog and draw its frame. | descriptive |
| [`osd_open_factory_info_page`](../../src/leon2m/osd/osd_open_factory_info_page.c) | `FUN_a008d2e0` | Draw the factory information page and set the menu state to 0x113. | proven |
| [`osd_open_input_quick_menu`](../../src/leon2m/osd/osd_open_input_quick_menu.c) | `FUN_a0091648` | Open the input quick menu (state 0xFE) and show the menu layer. | derived |
| [`osd_open_main_menu`](../../src/leon2m/osd/osd_open_main_menu.c) | `FUN_a00911a0` | Open the main menu with the first entry highlighted. | proven |
| [`osd_open_menu_state_0x106`](../../src/leon2m/osd/osd_open_menu_state_0x106.c) | `FUN_a0090fac` | Set menu state 0x106 and draw its window. | descriptive |
| [`osd_open_panel_protect_dialog`](../../src/leon2m/osd/osd_open_panel_protect_dialog.c) | `FUN_a0099c64` | Open the Panel Protect question (Execute, Cancel, Later, More Info) | derived |
| [`osd_open_pbp_custom_split`](../../src/leon2m/osd/osd_open_pbp_custom_split.c) | `FUN_a009811c` | Switch PBP to the custom split and open its editor. | proven |
| [`osd_open_pip_custom_position`](../../src/leon2m/osd/osd_open_pip_custom_position.c) | `FUN_a0093b04` | Open the free positioning of the PIP window (Customize location) | derived |
| [`osd_open_pixel_shift_speed`](../../src/leon2m/osd/osd_open_pixel_shift_speed.c) | `FUN_a009a198` | Open the Pixel Shift speed list (Slow, Normal, Fast) from the on/off list. | derived |
| [`osd_open_refresh_rate_location`](../../src/leon2m/osd/osd_open_refresh_rate_location.c) | `FUN_a00934dc` | Open the screen-position list for the refresh rate display. | derived |
| [`osd_open_refresh_rate_position`](../../src/leon2m/osd/osd_open_refresh_rate_position.c) | `FUN_a00943a4` | Open the free position editor for the refresh rate display. | derived |
| [`osd_open_reset_confirm`](../../src/leon2m/osd/osd_open_reset_confirm.c) | `FUN_a0099a7c` | Ask for confirmation of the settings Reset with 'No' highlighted. | derived |
| [`osd_open_rgb_brightness_slider`](../../src/leon2m/osd/osd_open_rgb_brightness_slider.c) | `FUN_a0099b18` | Open the RGB Brightness slider of the light bar. | derived |
| [`osd_open_sharpness_slider`](../../src/leon2m/osd/osd_open_sharpness_slider.c) | `FUN_a0096420` | Open the Sharpness slider (OK or right key) | derived |
| [`osd_open_static_screen_reduce_level`](../../src/leon2m/osd/osd_open_static_screen_reduce_level.c) | `FUN_a009a3cc` | Open the Static Screen Detection 'Reducing Level' choice with its notice. | derived |
| [`osd_open_static_screen_start_time`](../../src/leon2m/osd/osd_open_static_screen_start_time.c) | `FUN_a009a2d0` | Open the Static Screen Detection 'Starting in' time choice (state 0xF4) | derived |
| [`osd_open_static_screen_time_required`](../../src/leon2m/osd/osd_open_static_screen_time_required.c) | `FUN_a009a500` | Open the Static Screen Detection 'Time required' choice. | derived |
| [`osd_open_timeout_slider`](../../src/leon2m/osd/osd_open_timeout_slider.c) | `FUN_a0098ddc` | Open the OSD Time out slider (OK or right key) | derived |
| [`osd_open_transparency_slider`](../../src/leon2m/osd/osd_open_transparency_slider.c) | `FUN_a0098d4c` | Open the menu Transparency slider (OK or right key) | derived |
| [`osd_quick_switch_info_on_screen_off`](../../src/leon2m/osd/osd_quick_switch_info_on_screen_off.c) | `FUN_a00a4e08` | Turn Info. On Screen off in its quick menu (left key) | derived |
| [`osd_quick_switch_info_on_screen_on`](../../src/leon2m/osd/osd_quick_switch_info_on_screen_on.c) | `FUN_a00a4f68` | Turn Info. On Screen on in its quick menu (right key) | derived |
| [`osd_quick_switch_optix_scope_off`](../../src/leon2m/osd/osd_quick_switch_optix_scope_off.c) | `FUN_a00a50c4` | Turn Optix Scope off in its quick menu (left key) | derived |
| [`osd_quick_switch_optix_scope_on`](../../src/leon2m/osd/osd_quick_switch_optix_scope_on.c) | `FUN_a00a5218` | Turn Optix Scope on in its quick menu (right key) | derived |
| [`osd_quick_switch_refresh_rate_off`](../../src/leon2m/osd/osd_quick_switch_refresh_rate_off.c) | `FUN_a00a4b4c` | Turn the Refresh Rate display off in its quick menu (left key) | derived |
| [`osd_quick_switch_refresh_rate_on`](../../src/leon2m/osd/osd_quick_switch_refresh_rate_on.c) | `FUN_a00a4cac` | Turn the Refresh Rate display on in its quick menu (right key) | derived |
| [`osd_ram_fill_cell_bytes`](../../src/leon2m/osd/osd_ram_fill_cell_bytes.c) | `FUN_a011c1ac` | Fill a number of cells in one of the two byte planes with one value. | derived |
| [`osd_ram_fill_cells`](../../src/leon2m/osd/osd_ram_fill_cells.c) | `FUN_a011bed8` | Fill a number of cells from a cell position with one 16-bit value. | derived |
| [`osd_ram_port_delay`](../../src/leon2m/osd/osd_ram_port_delay.c) | `FUN_a011b3cc` | Wait for 160 idle instructions between two memory port writes. | derived |
| [`osd_ram_port_read_data`](../../src/leon2m/osd/osd_ram_port_read_data.c) | `FUN_a011cd80` | Read one data byte from the memory port of a menu layer. | derived |
| [`osd_ram_port_write_command`](../../src/leon2m/osd/osd_ram_port_write_command.c) | `FUN_a011b4b0` | Write a command byte to the memory port of a menu layer and wait. | derived |
| [`osd_ram_port_write_data`](../../src/leon2m/osd/osd_ram_port_write_data.c) | `FUN_a011b3e8` | Write one data byte to the memory port of a menu layer and wait. | derived |
| [`osd_ram_port_write_triple`](../../src/leon2m/osd/osd_ram_port_write_triple.c) | `FUN_a011b428` | Write three bytes to one of the two memory port register triples and wait. | descriptive |
| [`osd_ram_put_byte_and_word`](../../src/leon2m/osd/osd_ram_put_byte_and_word.c) | `FUN_a011c998` | Send one byte and one 16-bit value as data to the memory port. | derived |
| [`osd_ram_put_word`](../../src/leon2m/osd/osd_ram_put_word.c) | `FUN_a011ca58` | Send one 16-bit value as data to the memory port. | derived |
| [`osd_ram_seek_cmd_0x40`](../../src/leon2m/osd/osd_ram_seek_cmd_0x40.c) | `FUN_a011c8e4` | Start a memory access with command 0x40 at a 16-bit address. | derived |
| [`osd_ram_seek_cmd_0x70`](../../src/leon2m/osd/osd_ram_seek_cmd_0x70.c) | `FUN_a011c830` | Start a memory access with command 0x70 at a 16-bit address. | derived |
| [`osd_ram_seek_cmd_0x80`](../../src/leon2m/osd/osd_ram_seek_cmd_0x80.c) | `FUN_a011c77c` | Start a memory access with command 0x80 at a 16-bit address. | derived |
| [`osd_ram_seek_cmd_0x90`](../../src/leon2m/osd/osd_ram_seek_cmd_0x90.c) | `FUN_a011c6c8` | Start a memory access with command 0x90 at a 16-bit address. | derived |
| [`osd_ram_write_block`](../../src/leon2m/osd/osd_ram_write_block.c) | `FUN_a011b4f0` | Send a block of bytes to a menu layer's memory with command 0xD0. | derived |
| [`osd_ram_write_cell_byte`](../../src/leon2m/osd/osd_ram_write_cell_byte.c) | `FUN_a011c050` | Write one byte to a cell position in one of the two byte planes of a menu layer. | derived |
| [`osd_ram_write_cell_bytes`](../../src/leon2m/osd/osd_ram_write_cell_bytes.c) | `FUN_a011c338` | Write a run of bytes from a buffer to one of the two byte planes at a cell position. | derived |
| [`osd_ram_write_cells`](../../src/leon2m/osd/osd_ram_write_cells.c) | `FUN_a011bd60` | Write a row of 16-bit cell values at a cell position of a menu layer. | derived |
| [`osd_ram_write_index_run`](../../src/leon2m/osd/osd_ram_write_index_run.c) | `FUN_a011b648` | Write a run of rising byte values, padded with zeros, into a menu layer's memory. | descriptive |
| [`osd_ram_write_packed_block`](../../src/leon2m/osd/osd_ram_write_packed_block.c) | `FUN_a011c4cc` | Send a block to a menu layer's memory, plain or with runs of 0x00/0xFF expanded. | derived |
| [`osd_ram_write_words24`](../../src/leon2m/osd/osd_ram_write_words24.c) | `FUN_a011bac0` | Send 24-bit entries to a menu layer's memory with command 0xA0. | derived |
| [`osd_redraw_page_after_notice`](../../src/leon2m/osd/osd_redraw_page_after_notice.c) | `FUN_a00b1004` | Redraw the main menu on the Game Mode, Pro Mode or Panel Protect page after a notice or prompt. | derived |
| `osd_redraw_page_after_notice_jump_table` | `switchdataD_a00a4220` | Jump table 1 of the switch statements in osd_redraw_page_after_notice. | proven |
| [`osd_redraw_settings_page`](../../src/leon2m/osd/osd_redraw_settings_page.c) | `FUN_a00ad460` | Redraw the Settings page after the menu language changed. | derived |
| [`osd_reset_crosshair_position`](../../src/leon2m/osd/osd_reset_crosshair_position.c) | `FUN_a009584c` | Store the reset position of the crosshair (0x750, 0x402) and return to the G.I. list. | proven |
| [`osd_reset_layer`](../../src/leon2m/osd/osd_reset_layer.c) | `FUN_a01195ac` | Reset a menu layer: clear bit 7 of its first register, wait for a frame and restart it. | descriptive |
| [`osd_round_down_to_cell`](../../src/leon2m/osd/osd_round_down_to_cell.c) | `FUN_a01192d0` | Round a size down to a multiple of 36 when the layer's cells are 24 pixels wide, else of 9. | descriptive |
| [`osd_round_up_to_cell`](../../src/leon2m/osd/osd_round_up_to_cell.c) | `FUN_a011926c` | Round a size up to a multiple of 36 when the layer's cells are 24 pixels wide, else of 9. | descriptive |
| [`osd_run_navi_key_down`](../../src/leon2m/osd/osd_run_navi_key_down.c) | `FUN_a00a09f8` | Open the quick menu set for the Navi Key down direction (menu closed) | derived |
| [`osd_run_navi_key_left`](../../src/leon2m/osd/osd_run_navi_key_left.c) | `FUN_a00a0780` | Open the quick menu set for the Navi Key left direction (menu closed) | derived |
| [`osd_run_navi_key_right`](../../src/leon2m/osd/osd_run_navi_key_right.c) | `FUN_a00a0508` | Open the quick menu set for the Navi Key right direction (menu closed) | derived |
| [`osd_run_navi_key_up`](../../src/leon2m/osd/osd_run_navi_key_up.c) | `FUN_a00a0c70` | Open the quick menu set for the Navi Key up direction (menu closed) | derived |
| [`osd_run_periodic_task`](../../src/leon2m/osd/osd_run_periodic_task.c) | `FUN_a009f42c` | Run the menu timers: message time-outs, alarm countdown, overlays and panel prompts. | derived |
| [`osd_run_settings_reset`](../../src/leon2m/osd/osd_run_settings_reset.c) | `FUN_a00b8848` | Close the menu and reset all user settings to their defaults. | proven |
| [`osd_run_task_post_redraw_event`](../../src/leon2m/osd/osd_run_task_post_redraw_event.c) | `FUN_a00a012c` | Run the menu timers, then post the first pending menu redraw request as an event. | derived |
| [`osd_select_alarm_minutes_tens`](../../src/leon2m/osd/osd_select_alarm_minutes_tens.c) | `FUN_a0093910` | Put the alarm time cursor on the tens digit of the minutes. | derived |
| [`osd_select_alarm_minutes_units`](../../src/leon2m/osd/osd_select_alarm_minutes_units.c) | `FUN_a0093938` | Put the alarm time cursor on the units digit of the minutes. | derived |
| [`osd_select_alarm_seconds_tens`](../../src/leon2m/osd/osd_select_alarm_seconds_tens.c) | `FUN_a0093960` | Put the alarm time cursor on the tens digit of the seconds. | derived |
| [`osd_select_alarm_seconds_units`](../../src/leon2m/osd/osd_select_alarm_seconds_units.c) | `FUN_a0093988` | Put the alarm time cursor on the units digit of the seconds. | derived |
| [`osd_select_input_dp`](../../src/leon2m/osd/osd_select_input_dp.c) | `FUN_a0096fe8` | Switch to the DP input and close the menu, or go back if it is already active. | proven |
| [`osd_select_input_hdmi1`](../../src/leon2m/osd/osd_select_input_hdmi1.c) | `FUN_a0096e9c` | Switch to the HDMI 1 input and close the menu, or go back if it is already active. | proven |
| [`osd_select_input_hdmi2`](../../src/leon2m/osd/osd_select_input_hdmi2.c) | `FUN_a0096f40` | Switch to the HDMI 2 input and close the menu, or go back if it is already active. | proven |
| [`osd_select_input_type_c`](../../src/leon2m/osd/osd_select_input_type_c.c) | `FUN_a0097090` | Switch to the Type C input and close the menu, or go back if it is already active. | proven |
| [`osd_select_next_alarm_clock_choice`](../../src/leon2m/osd/osd_select_next_alarm_clock_choice.c) | `FUN_a009ab58` | Move to the next allowed Alarm Clock choice (down key) and store it. | derived |
| [`osd_select_next_alarm_clock_location`](../../src/leon2m/osd/osd_select_next_alarm_clock_location.c) | `FUN_a009b37c` | Move to the next allowed alarm clock location (down key) and store it. | derived |
| [`osd_select_next_color_temp`](../../src/leon2m/osd/osd_select_next_color_temp.c) | `FUN_a009c8ec` | Move to the next allowed colour temperature (down key) and preview it. | derived |
| [`osd_select_next_crosshair_color`](../../src/leon2m/osd/osd_select_next_crosshair_color.c) | `FUN_a009b4e8` | Move to the next allowed crosshair colour (down key) | derived |
| [`osd_select_next_crosshair_icon`](../../src/leon2m/osd/osd_select_next_crosshair_icon.c) | `FUN_a009b8e0` | Show the next crosshair icon (down key) | derived |
| [`osd_select_next_crosshair_item`](../../src/leon2m/osd/osd_select_next_crosshair_item.c) | `FUN_a009bf48` | Move to the next allowed Smart Crosshair item (down key) | derived |
| [`osd_select_next_detection_choice`](../../src/leon2m/osd/osd_select_next_detection_choice.c) | `FUN_a00a177c` | Move to the next detection choice row (down key) | derived |
| `osd_select_next_detection_choice_jump_table` | `switchdataD_a008f7a0` | Jump table 1 of the switch statements in osd_select_next_detection_choice. | proven |
| `osd_select_next_detection_choice_jump_table2` | `switchdataD_a008f888` | Jump table 2 of the switch statements in osd_select_next_detection_choice. | proven |
| `osd_select_next_detection_choice_jump_table3` | `switchdataD_a008f970` | Jump table 3 of the switch statements in osd_select_next_detection_choice. | proven |
| [`osd_select_next_display_hdr`](../../src/leon2m/osd/osd_select_next_display_hdr.c) | `FUN_a009c75c` | Move to the next allowed DisplayHDR mode (down key) and store it. | derived |
| [`osd_select_next_game_mode`](../../src/leon2m/osd/osd_select_next_game_mode.c) | `FUN_a009a6c0` | Move to the next allowed game mode (down key) and preview it. | derived |
| [`osd_select_next_gaming_item`](../../src/leon2m/osd/osd_select_next_gaming_item.c) | `FUN_a0091b94` | Move the highlight to the next enabled Gaming item (down key) | proven |
| [`osd_select_next_gi_item`](../../src/leon2m/osd/osd_select_next_gi_item.c) | `FUN_a009183c` | Move the highlight to the next enabled item of the G.I. tab. | proven |
| [`osd_select_next_image_enhancement`](../../src/leon2m/osd/osd_select_next_image_enhancement.c) | `FUN_a009c590` | Move to the next allowed Image Enhancement level (down key) and preview it. | derived |
| [`osd_select_next_image_item`](../../src/leon2m/osd/osd_select_next_image_item.c) | `FUN_a0092188` | Move the highlight to the next enabled Image item (down key) | proven |
| [`osd_select_next_input_source_item`](../../src/leon2m/osd/osd_select_next_input_source_item.c) | `FUN_a0092444` | Move the highlight to the next selectable input (down key) | proven |
| [`osd_select_next_kvm`](../../src/leon2m/osd/osd_select_next_kvm.c) | `FUN_a009db20` | Move to the next allowed KVM choice (Auto, Upstream, Type C) (down key) | derived |
| [`osd_select_next_language`](../../src/leon2m/osd/osd_select_next_language.c) | `FUN_a009d4e8` | Move to the next allowed menu language (down key) | derived |
| [`osd_select_next_navi_key_function`](../../src/leon2m/osd/osd_select_next_navi_key_function.c) | `FUN_a009cfd4` | Move to the next allowed Navi Key function (down key) | derived |
| [`osd_select_next_navi_key_item`](../../src/leon2m/osd/osd_select_next_navi_key_item.c) | `FUN_a0092a80` | Move the highlight to the next enabled Navi Key item (down key) | proven |
| [`osd_select_next_night_vision`](../../src/leon2m/osd/osd_select_next_night_vision.c) | `FUN_a0095c94` | Highlight and apply the next allowed Night Vision level (down key) | derived |
| [`osd_select_next_oled_care_item`](../../src/leon2m/osd/osd_select_next_oled_care_item.c) | `FUN_a0093144` | Move the highlight to the next enabled MSI OLED Care item (down key) | proven |
| [`osd_select_next_optix_scope_item`](../../src/leon2m/osd/osd_select_next_optix_scope_item.c) | `FUN_a009dc84` | Move to the next allowed Optix Scope row (Scope Size, Scope Ratio, OFF, ON) (down key) | derived |
| [`osd_select_next_pbp_item`](../../src/leon2m/osd/osd_select_next_pbp_item.c) | `FUN_a009ccc0` | Move to the next allowed PBP settings item (down key) | derived |
| [`osd_select_next_pbp_source`](../../src/leon2m/osd/osd_select_next_pbp_source.c) | `FUN_a009aec8` | Move to the next allowed PBP source input (down key) | derived |
| [`osd_select_next_pip_item`](../../src/leon2m/osd/osd_select_next_pip_item.c) | `FUN_a009cb8c` | Move to the next allowed PIP settings item (down key) | derived |
| [`osd_select_next_pip_location`](../../src/leon2m/osd/osd_select_next_pip_location.c) | `FUN_a009bdcc` | Move to the next allowed PIP window location (down key) and apply it. | derived |
| [`osd_select_next_pip_pbp_item`](../../src/leon2m/osd/osd_select_next_pip_pbp_item.c) | `FUN_a00927e8` | Move the highlight to the next enabled PIP/PBP layout (down key) | proven |
| [`osd_select_next_pip_size`](../../src/leon2m/osd/osd_select_next_pip_size.c) | `FUN_a009b070` | Move to the next allowed PIP size (down key) and apply it. | derived |
| [`osd_select_next_pip_source`](../../src/leon2m/osd/osd_select_next_pip_source.c) | `FUN_a009ad40` | Move to the next allowed PIP source input (down key) | derived |
| [`osd_select_next_pixel_shift_item`](../../src/leon2m/osd/osd_select_next_pixel_shift_item.c) | `FUN_a009deb0` | Move to the next allowed Pixel Shift row (OFF, ON, speed) (down key) | derived |
| [`osd_select_next_pixel_shift_speed`](../../src/leon2m/osd/osd_select_next_pixel_shift_speed.c) | `FUN_a009e3c8` | Move to the next Pixel Shift speed (down key) and store it. | derived |
| [`osd_select_next_pro_mode`](../../src/leon2m/osd/osd_select_next_pro_mode.c) | `FUN_a009c22c` | Move to the next allowed Pro mode (down key) and preview it. | derived |
| [`osd_select_next_professional_item`](../../src/leon2m/osd/osd_select_next_professional_item.c) | `FUN_a0091ea0` | Move the highlight to the next enabled Professional item (down key) | proven |
| [`osd_select_next_protect_prompt_button`](../../src/leon2m/osd/osd_select_next_protect_prompt_button.c) | `FUN_a00b27fc` | Move to the next button of the panel protect prompt (right key) | derived |
| [`osd_select_next_quick_alarm_clock`](../../src/leon2m/osd/osd_select_next_quick_alarm_clock.c) | `FUN_a00ae39c` | Move to the next row of the alarm clock quick menu (down key) | derived |
| [`osd_select_next_quick_crosshair`](../../src/leon2m/osd/osd_select_next_quick_crosshair.c) | `FUN_a00aeb98` | Move to the next row of the crosshair quick menu (down key) and show it. | derived |
| [`osd_select_next_quick_game_mode`](../../src/leon2m/osd/osd_select_next_quick_game_mode.c) | `FUN_a00ae638` | Move to the next row of the game mode quick menu (down key) and apply it. | derived |
| [`osd_select_next_quick_input`](../../src/leon2m/osd/osd_select_next_quick_input.c) | `FUN_a00ae8e0` | Move to the next row of the input quick menu (down key) | derived |
| [`osd_select_next_quick_kvm`](../../src/leon2m/osd/osd_select_next_quick_kvm.c) | `FUN_a00adc98` | Move to the next row of the KVM quick menu (down key) | derived |
| [`osd_select_next_quick_night_vision`](../../src/leon2m/osd/osd_select_next_quick_night_vision.c) | `FUN_a00adec0` | Move to the next row of the night vision quick menu (down key) and apply it. | derived |
| [`osd_select_next_quick_pip_pbp`](../../src/leon2m/osd/osd_select_next_quick_pip_pbp.c) | `FUN_a00ae174` | Move to the next row of the PIP/PBP quick menu (down key) | derived |
| [`osd_select_next_refresh_rate_choice`](../../src/leon2m/osd/osd_select_next_refresh_rate_choice.c) | `FUN_a009a8dc` | Move to the next allowed Refresh Rate choice (down key) and apply on/off. | derived |
| [`osd_select_next_refresh_rate_location`](../../src/leon2m/osd/osd_select_next_refresh_rate_location.c) | `FUN_a009b20c` | Move to the next allowed refresh rate display location (down key) and store it. | derived |
| [`osd_select_next_rgb_led_item`](../../src/leon2m/osd/osd_select_next_rgb_led_item.c) | `FUN_a009d848` | Move to the next allowed RGB LED row (OFF, ON, RGB Brightness) (down key) | derived |
| [`osd_select_next_scope_ratio`](../../src/leon2m/osd/osd_select_next_scope_ratio.c) | `FUN_a009bbe4` | Move to the next allowed Optix Scope ratio (down key) and apply it. | derived |
| [`osd_select_next_scope_size`](../../src/leon2m/osd/osd_select_next_scope_size.c) | `FUN_a009ba34` | Move to the next allowed Optix Scope size (down key) and apply it. | derived |
| [`osd_select_next_screen_size`](../../src/leon2m/osd/osd_select_next_screen_size.c) | `FUN_a009ca54` | Move to the next allowed screen size (down key) | derived |
| [`osd_select_next_settings_item`](../../src/leon2m/osd/osd_select_next_settings_item.c) | `FUN_a0092d80` | Move the highlight to the next enabled Settings item (down key) | proven |
| [`osd_select_next_static_screen_item`](../../src/leon2m/osd/osd_select_next_static_screen_item.c) | `FUN_a009e00c` | Move to the next allowed Static Screen Detection row (down key) | derived |
| [`osd_select_next_static_screen_start_time`](../../src/leon2m/osd/osd_select_next_static_screen_start_time.c) | `FUN_a009e538` | Move to the next 'Starting in' time (down key) and store it. | derived |
| [`osd_select_next_static_screen_time_required`](../../src/leon2m/osd/osd_select_next_static_screen_time_required.c) | `FUN_a009e694` | Move to the next 'Time required' choice (down key) and store it. | derived |
| [`osd_select_next_tab`](../../src/leon2m/osd/osd_select_next_tab.c) | `FUN_a009145c` | Move the main menu highlight to the next enabled tab (down key) | proven |
| [`osd_select_pbp_mode1`](../../src/leon2m/osd/osd_select_pbp_mode1.c) | `FUN_a0097dec` | Switch PBP to Mode 1 and return to the PIP/PBP list (OK) | derived |
| [`osd_select_pbp_mode2`](../../src/leon2m/osd/osd_select_pbp_mode2.c) | `FUN_a0097f48` | Switch PBP to Mode 2 and return to the PIP/PBP list (OK) | derived |
| [`osd_select_pip_pbp_off`](../../src/leon2m/osd/osd_select_pip_pbp_off.c) | `FUN_a0097814` | Switch PIP/PBP off and return to the PIP/PBP tab (OK on OFF) | derived |
| [`osd_select_prev_alarm_clock_choice`](../../src/leon2m/osd/osd_select_prev_alarm_clock_choice.c) | `FUN_a009aa34` | Move to the previous allowed Alarm Clock choice (up key) and store it. | derived |
| [`osd_select_prev_alarm_clock_location`](../../src/leon2m/osd/osd_select_prev_alarm_clock_location.c) | `FUN_a009b2c4` | Move to the previous allowed alarm clock location (up key) and store it. | derived |
| [`osd_select_prev_color_temp`](../../src/leon2m/osd/osd_select_prev_color_temp.c) | `FUN_a009c83c` | Move to the previous allowed colour temperature (up key) and preview it. | derived |
| [`osd_select_prev_crosshair_color`](../../src/leon2m/osd/osd_select_prev_crosshair_color.c) | `FUN_a009b434` | Move to the previous allowed crosshair colour (up key) | derived |
| [`osd_select_prev_crosshair_icon`](../../src/leon2m/osd/osd_select_prev_crosshair_icon.c) | `FUN_a009b864` | Show the previous crosshair icon (up key) | derived |
| [`osd_select_prev_crosshair_item`](../../src/leon2m/osd/osd_select_prev_crosshair_item.c) | `FUN_a009bedc` | Move to the previous allowed Smart Crosshair item (up key) | derived |
| [`osd_select_prev_detection_choice`](../../src/leon2m/osd/osd_select_prev_detection_choice.c) | `FUN_a00a15d0` | Move to the previous detection choice row (up key) | derived |
| `osd_select_prev_detection_choice_jump_table` | `switchdataD_a008f4e8` | Jump table 1 of the switch statements in osd_select_prev_detection_choice. | proven |
| `osd_select_prev_detection_choice_jump_table2` | `switchdataD_a008f5d0` | Jump table 2 of the switch statements in osd_select_prev_detection_choice. | proven |
| `osd_select_prev_detection_choice_jump_table3` | `switchdataD_a008f6b8` | Jump table 3 of the switch statements in osd_select_prev_detection_choice. | proven |
| [`osd_select_prev_display_hdr`](../../src/leon2m/osd/osd_select_prev_display_hdr.c) | `FUN_a009c67c` | Move to the previous allowed DisplayHDR mode (up key) and store it. | derived |
| [`osd_select_prev_game_mode`](../../src/leon2m/osd/osd_select_prev_game_mode.c) | `FUN_a009a5fc` | Move to the previous allowed game mode (up key) and preview it. | derived |
| [`osd_select_prev_gaming_item`](../../src/leon2m/osd/osd_select_prev_gaming_item.c) | `FUN_a0091a68` | Move the highlight to the previous enabled Gaming item (up key) | proven |
| [`osd_select_prev_gi_item`](../../src/leon2m/osd/osd_select_prev_gi_item.c) | `FUN_a0091784` | Move the highlight to the previous enabled item of the G.I. tab. | proven |
| [`osd_select_prev_image_enhancement`](../../src/leon2m/osd/osd_select_prev_image_enhancement.c) | `FUN_a009c4a4` | Move to the previous allowed Image Enhancement level (up key) and preview it. | derived |
| [`osd_select_prev_image_item`](../../src/leon2m/osd/osd_select_prev_image_item.c) | `FUN_a00920f4` | Move the highlight to the previous enabled Image item (up key) | proven |
| [`osd_select_prev_input_source_item`](../../src/leon2m/osd/osd_select_prev_input_source_item.c) | `FUN_a0092364` | Move the highlight to the previous selectable input (up key) | proven |
| [`osd_select_prev_kvm`](../../src/leon2m/osd/osd_select_prev_kvm.c) | `FUN_a009da6c` | Move to the previous allowed KVM choice (Auto, Upstream, Type C) (up key) | derived |
| [`osd_select_prev_language`](../../src/leon2m/osd/osd_select_prev_language.c) | `FUN_a009d234` | Move to the previous allowed menu language (up key) | derived |
| [`osd_select_prev_navi_key_function`](../../src/leon2m/osd/osd_select_prev_navi_key_function.c) | `FUN_a009cd74` | Move to the previous allowed Navi Key function (up key) | derived |
| [`osd_select_prev_navi_key_item`](../../src/leon2m/osd/osd_select_prev_navi_key_item.c) | `FUN_a00929e8` | Move the highlight to the previous enabled Navi Key item (up key) | proven |
| [`osd_select_prev_night_vision`](../../src/leon2m/osd/osd_select_prev_night_vision.c) | `FUN_a0095bcc` | Highlight and apply the previous allowed Night Vision level (up key) | derived |
| [`osd_select_prev_oled_care_item`](../../src/leon2m/osd/osd_select_prev_oled_care_item.c) | `FUN_a0092fd4` | Move the highlight to the previous enabled MSI OLED Care item (up key) | proven |
| [`osd_select_prev_optix_scope_item`](../../src/leon2m/osd/osd_select_prev_optix_scope_item.c) | `FUN_a009dbd4` | Move to the previous allowed Optix Scope row (Scope Size, Scope Ratio, OFF, ON) (up key) | derived |
| [`osd_select_prev_pbp_item`](../../src/leon2m/osd/osd_select_prev_pbp_item.c) | `FUN_a009cc0c` | Move to the previous allowed PBP settings item (up key) | derived |
| [`osd_select_prev_pbp_source`](../../src/leon2m/osd/osd_select_prev_pbp_source.c) | `FUN_a009ae04` | Move to the previous allowed PBP source input (up key) | derived |
| [`osd_select_prev_pip_item`](../../src/leon2m/osd/osd_select_prev_pip_item.c) | `FUN_a009cb0c` | Move to the previous allowed PIP settings item (up key) | derived |
| [`osd_select_prev_pip_location`](../../src/leon2m/osd/osd_select_prev_pip_location.c) | `FUN_a009bcbc` | Move to the previous allowed PIP window location (up key) and apply it. | derived |
| [`osd_select_prev_pip_pbp_item`](../../src/leon2m/osd/osd_select_prev_pip_pbp_item.c) | `FUN_a00926c8` | Move the highlight to the previous enabled PIP/PBP layout (up key) | proven |
| [`osd_select_prev_pip_size`](../../src/leon2m/osd/osd_select_prev_pip_size.c) | `FUN_a009af8c` | Move to the previous allowed PIP size (up key) and apply it. | derived |
| [`osd_select_prev_pip_source`](../../src/leon2m/osd/osd_select_prev_pip_source.c) | `FUN_a009ac7c` | Move to the previous allowed PIP source input (up key) | derived |
| [`osd_select_prev_pixel_shift_item`](../../src/leon2m/osd/osd_select_prev_pixel_shift_item.c) | `FUN_a009de04` | Move to the previous allowed Pixel Shift row (OFF, ON, speed) (up key) | derived |
| [`osd_select_prev_pixel_shift_speed`](../../src/leon2m/osd/osd_select_prev_pixel_shift_speed.c) | `FUN_a009e480` | Move to the previous Pixel Shift speed (up key) and store it. | derived |
| [`osd_select_prev_pro_mode`](../../src/leon2m/osd/osd_select_prev_pro_mode.c) | `FUN_a009bfb4` | Move to the previous allowed Pro mode (up key) and preview it. | derived |
| [`osd_select_prev_professional_item`](../../src/leon2m/osd/osd_select_prev_professional_item.c) | `FUN_a0091de8` | Move the highlight to the previous enabled Professional item (up key) | proven |
| [`osd_select_prev_protect_prompt_button`](../../src/leon2m/osd/osd_select_prev_protect_prompt_button.c) | `FUN_a00b2a1c` | Move to the previous button of the panel protect prompt (left key) | derived |
| [`osd_select_prev_quick_alarm_clock`](../../src/leon2m/osd/osd_select_prev_quick_alarm_clock.c) | `FUN_a00ae4f0` | Move to the previous row of the alarm clock quick menu (up key) | derived |
| [`osd_select_prev_quick_crosshair`](../../src/leon2m/osd/osd_select_prev_quick_crosshair.c) | `FUN_a00aecec` | Move to the previous row of the crosshair quick menu (up key) and show it. | derived |
| [`osd_select_prev_quick_game_mode`](../../src/leon2m/osd/osd_select_prev_quick_game_mode.c) | `FUN_a00ae790` | Move to the previous row of the game mode quick menu (up key) and apply it. | derived |
| [`osd_select_prev_quick_input`](../../src/leon2m/osd/osd_select_prev_quick_input.c) | `FUN_a00aea3c` | Move to the previous row of the input quick menu (up key) | derived |
| [`osd_select_prev_quick_kvm`](../../src/leon2m/osd/osd_select_prev_quick_kvm.c) | `FUN_a00addac` | Move to the previous row of the KVM quick menu (up key) | derived |
| [`osd_select_prev_quick_night_vision`](../../src/leon2m/osd/osd_select_prev_quick_night_vision.c) | `FUN_a00ae020` | Move to the previous row of the night vision quick menu (up key) and apply it. | derived |
| [`osd_select_prev_quick_pip_pbp`](../../src/leon2m/osd/osd_select_prev_quick_pip_pbp.c) | `FUN_a00ae288` | Move to the previous row of the PIP/PBP quick menu (up key) | derived |
| [`osd_select_prev_refresh_rate_choice`](../../src/leon2m/osd/osd_select_prev_refresh_rate_choice.c) | `FUN_a009a784` | Move to the previous allowed Refresh Rate choice (up key) and apply on/off. | derived |
| [`osd_select_prev_refresh_rate_location`](../../src/leon2m/osd/osd_select_prev_refresh_rate_location.c) | `FUN_a009b154` | Move to the previous allowed refresh rate display location (up key) and store it. | derived |
| [`osd_select_prev_rgb_led_item`](../../src/leon2m/osd/osd_select_prev_rgb_led_item.c) | `FUN_a009d79c` | Move to the previous allowed RGB LED row (OFF, ON, RGB Brightness) (up key) | derived |
| [`osd_select_prev_scope_ratio`](../../src/leon2m/osd/osd_select_prev_scope_ratio.c) | `FUN_a009bb0c` | Move to the previous allowed Optix Scope ratio (up key) and apply it. | derived |
| [`osd_select_prev_scope_size`](../../src/leon2m/osd/osd_select_prev_scope_size.c) | `FUN_a009b95c` | Move to the previous allowed Optix Scope size (up key) and apply it. | derived |
| [`osd_select_prev_screen_size`](../../src/leon2m/osd/osd_select_prev_screen_size.c) | `FUN_a009c99c` | Move to the previous allowed screen size (up key) | derived |
| [`osd_select_prev_settings_item`](../../src/leon2m/osd/osd_select_prev_settings_item.c) | `FUN_a0092c58` | Move the highlight to the previous enabled Settings item (up key) | proven |
| [`osd_select_prev_static_screen_item`](../../src/leon2m/osd/osd_select_prev_static_screen_item.c) | `FUN_a009df5c` | Move to the previous allowed Static Screen Detection row (up key) | derived |
| [`osd_select_prev_static_screen_start_time`](../../src/leon2m/osd/osd_select_prev_static_screen_start_time.c) | `FUN_a009e5ac` | Move to the previous 'Starting in' time (up key) and store it. | derived |
| [`osd_select_prev_static_screen_time_required`](../../src/leon2m/osd/osd_select_prev_static_screen_time_required.c) | `FUN_a009e708` | Move to the previous 'Time required' choice (up key) and store it. | derived |
| [`osd_select_prev_tab`](../../src/leon2m/osd/osd_select_prev_tab.c) | `FUN_a00912ac` | Move the main menu highlight to the previous enabled tab (up key) | proven |
| [`osd_select_window`](../../src/leon2m/osd/osd_select_window.c) | `FUN_a002e6e4` | Select which of the eight windows of a menu layer the next window writes go to. | derived |
| [`osd_set_blend_level`](../../src/leon2m/osd/osd_set_blend_level.c) | `FUN_a011acac` | Set the 0..8 level in the first level field and its two enable bits. | descriptive |
| [`osd_set_blend_level_second`](../../src/leon2m/osd/osd_set_blend_level_second.c) | `FUN_a011adc8` | Set the 0..8 level in the second level field and its enable bit in register 0xCF. | descriptive |
| [`osd_set_cell_size_mode`](../../src/leon2m/osd/osd_set_cell_size_mode.c) | `FUN_a0119698` | Select one of five character cell modes for a menu layer. | descriptive |
| `osd_set_cell_size_mode_jump_table` | `switchdataD_a0119148` | Jump table 1 of the switch statements in osd_set_cell_size_mode. | proven |
| [`osd_set_columns`](../../src/leon2m/osd/osd_set_columns.c) | `FUN_a0119640` | Store the number of character columns of a menu layer. | derived |
| [`osd_set_effect_record`](../../src/leon2m/osd/osd_set_effect_record.c) | `FUN_a011a574` | Copy a five-byte effect record into the registers of a menu layer. | descriptive |
| [`osd_set_event_flag`](../../src/leon2m/osd/osd_set_event_flag.c) | `FUN_a0088714` | Set byte 0xA8024028 to 2. | descriptive |
| [`osd_set_glyph_write_address`](../../src/leon2m/osd/osd_set_glyph_write_address.c) | `FUN_a011b3a0` | Store the memory address at which the next glyph data of a menu layer is written. | derived |
| [`osd_set_glyph_write_count`](../../src/leon2m/osd/osd_set_glyph_write_count.c) | `FUN_a011b3b8` | Store the count of glyph entries written to a menu layer so far. | derived |
| [`osd_set_highlight_window`](../../src/leon2m/osd/osd_set_highlight_window.c) | `FUN_a00b3ed0` | Place the highlight window over a menu area, or switch it off. | derived |
| [`osd_set_layer_byte_pair`](../../src/leon2m/osd/osd_set_layer_byte_pair.c) | `FUN_a011a554` | Store two bytes for a menu layer. | descriptive |
| [`osd_set_layer_window_oriented`](../../src/leon2m/osd/osd_set_layer_window_oriented.c) | `FUN_a002e960` | Program window registers 3..10 of a menu layer after turning the corners by the layer's orientation. | descriptive |
| [`osd_set_layout`](../../src/leon2m/osd/osd_set_layout.c) | `FUN_a00b50d8` | Configure the menu layer for a layout and load its glyphs. | derived |
| [`osd_set_menu_state`](../../src/leon2m/osd/osd_set_menu_state.c) | `FUN_a0090fa0` | Set the current menu state (page or item code) | derived |
| [`osd_set_mode_bits`](../../src/leon2m/osd/osd_set_mode_bits.c) | `FUN_a011cae0` | Set the 3-bit mode field of a menu layer to one of four values. | descriptive |
| [`osd_set_option_field`](../../src/leon2m/osd/osd_set_option_field.c) | `FUN_a01198c8` | Store a 2-bit option in the first or second field of the option byte. | descriptive |
| [`osd_set_origin_and_size`](../../src/leon2m/osd/osd_set_origin_and_size.c) | `FUN_a011a060` | Write the origin and the size in cells of a menu layer, then wait for a frame. | derived |
| [`osd_set_pbp_mode_from_state`](../../src/leon2m/osd/osd_set_pbp_mode_from_state.c) | `FUN_a0097d3c` | Set the PBP mode to 0 or 1 from the menu state and rebuild the picture if it changed. | descriptive |
| [`osd_set_position`](../../src/leon2m/osd/osd_set_position.c) | `FUN_a01199ac` | Place a menu layer on the screen from percentage values and its size in cells. | derived |
| [`osd_set_reg8e_params`](../../src/leon2m/osd/osd_set_reg8e_params.c) | `FUN_a011aee4` | Program the two parameter registers 0x8E/0x8F and a 2-bit field of register 0xCF. | descriptive |
| [`osd_set_reg30_bits`](../../src/leon2m/osd/osd_set_reg30_bits.c) | `FUN_a011a974` | Set or clear the control bits of register 0x30 of a menu layer. | descriptive |
| [`osd_set_reg90_level`](../../src/leon2m/osd/osd_set_reg90_level.c) | `FUN_a011abcc` | Set the level byte of register group 0x90, or switch the group off for level 0. | descriptive |
| [`osd_set_reg_c8_ranges`](../../src/leon2m/osd/osd_set_reg_c8_ranges.c) | `FUN_a011b034` | Program two pairs of 10-bit limits in registers 0xC8..0xCB and 0xD8..0xDB. | descriptive |
| [`osd_set_rega0_fields`](../../src/leon2m/osd/osd_set_rega0_fields.c) | `FUN_a011cdb8` | Program the two fields of register 0xA0 of a menu layer, or clear its enable bit. | descriptive |
| [`osd_set_rega5_bit3`](../../src/leon2m/osd/osd_set_rega5_bit3.c) | `FUN_a011cd10` | Set or clear bit 3 of register 0xA5 of a menu layer. | descriptive |
| [`osd_set_rows`](../../src/leon2m/osd/osd_set_rows.c) | `FUN_a0119658` | Store the number of character rows of a menu layer. | derived |
| [`osd_set_seconds_countdown`](../../src/leon2m/osd/osd_set_seconds_countdown.c) | `FUN_a0090f94` | Set the menu's one-second countdown. | derived |
| [`osd_set_text_field_width`](../../src/leon2m/osd/osd_set_text_field_width.c) | `FUN_a00a3198` | Store the text field width used by the text drawer. | descriptive |
| [`osd_set_text_mode`](../../src/leon2m/osd/osd_set_text_mode.c) | `FUN_a011b36c` | Store the text drawing mode of a menu layer. | descriptive |
| [`osd_set_window_blend_level`](../../src/leon2m/osd/osd_set_window_blend_level.c) | `FUN_a011a848` | Set the 0..8 level in the second level field and its enable bit in register 0xAA. | descriptive |
| [`osd_set_window_rect`](../../src/leon2m/osd/osd_set_window_rect.c) | `FUN_a002ed14` | Write the rectangle of the selected window of a menu layer (registers 3..10 of its block). | derived |
| [`osd_set_window_rect_wait`](../../src/leon2m/osd/osd_set_window_rect_wait.c) | `FUN_a002e764` | Write the rectangle of the selected window of a menu layer and wait for a frame. | derived |
| [`osd_setup_layer_window`](../../src/leon2m/osd/osd_setup_layer_window.c) | `FUN_a00b52f8` | Reset the menu layer and set its size in cells, position and background. | derived |
| [`osd_setup_window_full`](../../src/leon2m/osd/osd_setup_window_full.c) | `FUN_a008a4a8` | Run the full menu window set-up sequence, including tables, and wait three sync pulses. | descriptive |
| [`osd_setup_window_short`](../../src/leon2m/osd/osd_setup_window_short.c) | `FUN_a008a434` | Run the short menu window set-up sequence and wait three sync pulses. | descriptive |
| [`osd_show_change_notice`](../../src/leon2m/osd/osd_show_change_notice.c) | `FUN_a00b0f48` | Draw the whole change notice dialog and show it. | derived |
| [`osd_show_detection_level_slider`](../../src/leon2m/osd/osd_show_detection_level_slider.c) | `FUN_a00a1a68` | Open the level slider of the open detection setting. | derived |
| `osd_show_detection_level_slider_jump_table` | `switchdataD_a008fc28` | Jump table 1 of the switch statements in osd_show_detection_level_slider. | proven |
| `osd_show_detection_level_slider_jump_table2` | `switchdataD_a008fd10` | Jump table 2 of the switch statements in osd_show_detection_level_slider. | proven |
| `osd_show_detection_level_slider_jump_table3` | `switchdataD_a008fdf8` | Jump table 3 of the switch statements in osd_show_detection_level_slider. | proven |
| `osd_show_detection_level_slider_jump_table4` | `switchdataD_a008fee0` | Jump table 4 of the switch statements in osd_show_detection_level_slider. | proven |
| `osd_show_detection_level_slider_jump_table5` | `switchdataD_a008ffc8` | Jump table 5 of the switch statements in osd_show_detection_level_slider. | proven |
| [`osd_show_input_info_message`](../../src/leon2m/osd/osd_show_input_info_message.c) | `FUN_a009e894` | Show the input information banner (input name, console, HDR) after a signal change. | derived |
| [`osd_show_logo_on_power_on`](../../src/leon2m/osd/osd_show_logo_on_power_on.c) | `FUN_a0081e0c` | Show the start-up logo when armed, block all keys except 0x40 and start a 3-second timer. | derived |
| [`osd_show_menu_layer`](../../src/leon2m/osd/osd_show_menu_layer.c) | `FUN_a00a45a8` | Switch the main menu layer on. | derived |
| [`osd_show_no_signal_message`](../../src/leon2m/osd/osd_show_no_signal_message.c) | `FUN_a009e9a8` | Show the plain 'No Signal' message. | derived |
| [`osd_show_no_signal_with_input`](../../src/leon2m/osd/osd_show_no_signal_with_input.c) | `FUN_a009e91c` | Show the input name with 'No Signal' when the active input has no signal. | derived |
| [`osd_show_out_of_range`](../../src/leon2m/osd/osd_show_out_of_range.c) | `FUN_a009ea08` | Show the 'Out Of Range!' message for an unsupported input timing. | proven |
| [`osd_show_screen_overlays`](../../src/leon2m/osd/osd_show_screen_overlays.c) | `FUN_a00a5e68` | Draw or refresh the overlays: crosshair, alarm timer, refresh rate counter. | derived |
| [`osd_step_alarm_digit`](../../src/leon2m/osd/osd_step_alarm_digit.c) | `FUN_a00b65e4` | Step one digit of the edited alarm time up or down and redraw it. | proven |
| [`osd_step_pro_mode_index`](../../src/leon2m/osd/osd_step_pro_mode_index.c) | `FUN_a00b6b88` | Step a Pro mode list index (0..7) up or down with wrap-around. | derived |
| [`osd_swap_pip_inputs`](../../src/leon2m/osd/osd_swap_pip_inputs.c) | `FUN_a0097cb4` | Swap the main and sub-window inputs (Display Switch) | derived |
| [`osd_swap_pip_inputs_copy`](../../src/leon2m/osd/osd_swap_pip_inputs_copy.c) | `FUN_a0098364` | Swap the main and sub-window inputs (Display Switch) | derived |
| [`osd_switch_adaptive_sync`](../../src/leon2m/osd/osd_switch_adaptive_sync.c) | `FUN_a00b69f4` | Toggle Adaptive-Sync, apply it and redraw its switch. | derived |
| [`osd_switch_change_notice_choice`](../../src/leon2m/osd/osd_switch_change_notice_choice.c) | `FUN_a00b0fc0` | Move the highlight between Yes and No in the change notice. | derived |
| [`osd_switch_power_button_choice`](../../src/leon2m/osd/osd_switch_power_button_choice.c) | `FUN_a009d8f4` | Move the highlight to the other Power Button choice and store it. | derived |
| [`osd_switch_power_button_choice_copy`](../../src/leon2m/osd/osd_switch_power_button_choice_copy.c) | `FUN_a009d9b0` | Move the highlight to the other Power Button choice and store it. | derived |
| [`osd_switch_protect_notice_choice`](../../src/leon2m/osd/osd_switch_protect_notice_choice.c) | `FUN_a009e0bc` | Move the highlight between the two Protect Notice choices. | derived |
| [`osd_switch_protect_notice_choice_copy`](../../src/leon2m/osd/osd_switch_protect_notice_choice_copy.c) | `FUN_a009e154` | Move the highlight between the two Protect Notice choices. | derived |
| [`osd_switch_reset_confirm_choice`](../../src/leon2m/osd/osd_switch_reset_confirm_choice.c) | `FUN_a009dd34` | Move the highlight between Yes and No in the Reset question. | derived |
| [`osd_switch_reset_confirm_choice_copy`](../../src/leon2m/osd/osd_switch_reset_confirm_choice_copy.c) | `FUN_a009dd9c` | Move the highlight between Yes and No in the Reset question. | derived |
| [`osd_take_request_bit0`](../../src/leon2m/osd/osd_take_request_bit0.c) | `FUN_a00b5030` | Return and clear request bit 0 of 0xA802B08E. | descriptive |
| [`osd_take_request_bit2`](../../src/leon2m/osd/osd_take_request_bit2.c) | `FUN_a00b5064` | Return and clear request bit 2 of 0xA802B08E. | descriptive |
| [`osd_take_request_bit3`](../../src/leon2m/osd/osd_take_request_bit3.c) | `FUN_a00b5048` | Return and clear request bit 3 of 0xA802B08E. | descriptive |
| [`osd_take_settings_changed`](../../src/leon2m/osd/osd_take_settings_changed.c) | `FUN_a00b5014` | Return and clear the settings-changed request (bit 1 of 0xA802B08E) | derived |
| [`osd_toggle_adaptive_sync`](../../src/leon2m/osd/osd_toggle_adaptive_sync.c) | `FUN_a0095acc` | Switch Adaptive-Sync on or off and redraw the item (OK key) | proven |
| [`osd_toggle_ai_vision`](../../src/leon2m/osd/osd_toggle_ai_vision.c) | `FUN_a0099440` | Switch AI Vision on or off and redraw the item. | proven |
| [`osd_toggle_auto_scan`](../../src/leon2m/osd/osd_toggle_auto_scan.c) | `FUN_a0097138` | Switch automatic input scanning on or off. | proven |
| [`osd_toggle_dsc`](../../src/leon2m/osd/osd_toggle_dsc.c) | `FUN_a0095dd8` | Switch DSC (display stream compression) support on or off. | proven |
| [`osd_toggle_hdmi_cec`](../../src/leon2m/osd/osd_toggle_hdmi_cec.c) | `FUN_a0099244` | Switch HDMI CEC on or off and restart the input channels. | proven |
| [`osd_toggle_info_on_screen`](../../src/leon2m/osd/osd_toggle_info_on_screen.c) | `FUN_a00991ec` | Switch Info. On Screen on or off and redraw the item. | proven |
| [`osd_toggle_low_blue_light`](../../src/leon2m/osd/osd_toggle_low_blue_light.c) | `FUN_a00961a4` | Switch Low Blue Light on or off and re-apply the colours. | proven |
| [`osd_toggle_pbp_audio_source`](../../src/leon2m/osd/osd_toggle_pbp_audio_source.c) | `FUN_a0098374` | Switch the sound between the two PBP inputs and return to the PIP/PBP list. | derived |
| [`osd_toggle_pip_audio_source`](../../src/leon2m/osd/osd_toggle_pip_audio_source.c) | `FUN_a0097cc4` | Switch the sound between the main and sub-window input (Audio Switch) | derived |
| [`osd_toggle_power_led`](../../src/leon2m/osd/osd_toggle_power_led.c) | `FUN_a00993a8` | Switch the Power LED on or off and apply it. | proven |
| [`osd_toggle_protect_prompt_option`](../../src/leon2m/osd/osd_toggle_protect_prompt_option.c) | `FUN_a00b2c18` | Move the highlight to the other button of the panel protect prompt and redraw both buttons. | descriptive |
| [`osd_toggle_type_c_pd_charge`](../../src/leon2m/osd/osd_toggle_type_c_pd_charge.c) | `FUN_a009934c` | Switch Type C PD Charge on or off and apply it. | proven |
| [`osd_update_crosshair_color`](../../src/leon2m/osd/osd_update_crosshair_color.c) | `FUN_a00ba184` | Recolour the crosshair, picking a contrasting colour in automatic mode. | derived |
| [`osd_update_header_refresh_rate`](../../src/leon2m/osd/osd_update_header_refresh_rate.c) | `FUN_a00b37a4` | Redraw the 'n Hz' refresh rate field in the menu header. | derived |
| [`osd_update_key_guide`](../../src/leon2m/osd/osd_update_key_guide.c) | `FUN_a00b34d4` | Redraw the two key guide texts that changed. | derived |
| [`osd_update_reg_bits`](../../src/leon2m/osd/osd_update_reg_bits.c) | `FUN_a01191fc` | Set or clear bits of one register of menu layer 0 or 1. | derived |
| [`osd_user_apply_menu_option`](../../src/leon2m/osd/osd_user_apply_menu_option.c) | `FUN_a00d47c8` | Apply settings byte +6 as a 2-bit option, with the menu layers switched off meanwhile. | descriptive |
| [`osd_user_apply_menu_position`](../../src/leon2m/osd/osd_user_apply_menu_position.c) | `FUN_a00d472c` | Apply the menu position settings. | derived |
| [`osd_user_apply_menu_timeout`](../../src/leon2m/osd/osd_user_apply_menu_timeout.c) | `FUN_a00d47b0` | Apply the menu time-out setting. | derived |
| [`osd_user_apply_transparency`](../../src/leon2m/osd/osd_user_apply_transparency.c) | `FUN_a00d4780` | Apply the menu transparency setting 0..5. | derived |
| [`osd_write_columns_register`](../../src/leon2m/osd/osd_write_columns_register.c) | `FUN_a0119910` | Write a 16-bit value to the two column-count registers of a menu layer. | descriptive |
| [`osd_write_reg16`](../../src/leon2m/osd/osd_write_reg16.c) | `FUN_a011919c` | Write a 16-bit value to a register pair of menu layer 0 or 1. | derived |
| [`osd_write_reg24_group`](../../src/leon2m/osd/osd_write_reg24_group.c) | `FUN_a011932c` | Write a 24-bit value to one of three register groups of a menu layer, chosen by four group codes. | derived |
| [`osd_write_reg_cc`](../../src/leon2m/osd/osd_write_reg_cc.c) | `FUN_a011cc44` | Write a 16-bit value to registers 0xCC/0xCD of a menu layer. | descriptive |
| [`OSDCloseWhenSyncDet`](../../src/leon2m/osd/OSDCloseWhenSyncDet.c) | `FUN_a0091034` | Close the no-signal message (state 0x10D) once an input signal is found. | proven |
| [`OSDPBPAdjustD`](../../src/leon2m/osd/OSDPBPAdjustD.c) | `FUN_a00a0f6c` | Raise the custom PBP split by 8 lines, not above the limit 0x870, and redraw (down key) | proven |
| [`OSDPBPAdjustL`](../../src/leon2m/osd/OSDPBPAdjustL.c) | `FUN_a00a0ff0` | Move the custom PBP split left one step of 8 and redraw (left key) | proven |
| [`OSDPBPAdjustR`](../../src/leon2m/osd/OSDPBPAdjustR.c) | `FUN_a00a105c` | Move the custom PBP split right one step of 8 and redraw (right key) | proven |
| [`OSDPBPAdjustU`](../../src/leon2m/osd/OSDPBPAdjustU.c) | `FUN_a00a0ee8` | Lower the custom PBP split by 8 lines, not below the limit 0x870, and redraw (up key) | proven |
| [`ShowLogo`](../../src/leon2m/osd/ShowLogo.c) | `FUN_a008ef48` | Draw the MSI power-on logo and switch the panel on. | proven |

<a id="font"></a>
## Menu fonts

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`font_get_glyph_column`](../../src/leon2m/font/font_get_glyph_column.c) | `FUN_a00a2eec` | Return a glyph bitmap column from the table of the given menu font code. | derived |
| [`font_get_glyph_column_code_f0`](../../src/leon2m/font/font_get_glyph_column_code_f0.c) | `FUN_a00a2c04` | Return a glyph bitmap column from the table of menu font 0xF0. | derived |
| [`font_get_glyph_column_code_f1`](../../src/leon2m/font/font_get_glyph_column_code_f1.c) | `FUN_a00a2cc4` | Return a glyph bitmap column from the table of menu font 0xF1. | derived |
| [`font_get_glyph_column_code_f2`](../../src/leon2m/font/font_get_glyph_column_code_f2.c) | `FUN_a00a2d24` | Return a glyph bitmap column from the table of menu font 0xF2. | derived |
| [`font_get_glyph_column_code_f3`](../../src/leon2m/font/font_get_glyph_column_code_f3.c) | `FUN_a00a2d54` | Return a glyph bitmap column from the table of menu font 0xF3. | derived |
| [`font_get_glyph_column_code_f4`](../../src/leon2m/font/font_get_glyph_column_code_f4.c) | `FUN_a00a2db4` | Return a glyph bitmap column from the table of menu font 0xF4. | derived |
| [`font_get_glyph_column_code_f5`](../../src/leon2m/font/font_get_glyph_column_code_f5.c) | `FUN_a00a2e14` | Return a glyph bitmap column from the table of menu font 0xF5. | derived |
| [`font_get_glyph_column_code_f6`](../../src/leon2m/font/font_get_glyph_column_code_f6.c) | `FUN_a00a2c64` | Return a glyph bitmap column from the table of menu font 0xF6. | derived |
| [`font_get_glyph_column_code_f7`](../../src/leon2m/font/font_get_glyph_column_code_f7.c) | `FUN_a00a2e44` | Return a glyph bitmap column from the table of menu font 0xF7. | derived |
| [`font_get_glyph_column_code_f8`](../../src/leon2m/font/font_get_glyph_column_code_f8.c) | `FUN_a00a2c34` | Return a glyph bitmap column from the table of menu font 0xF8. | derived |
| [`font_get_glyph_column_code_f9`](../../src/leon2m/font/font_get_glyph_column_code_f9.c) | `FUN_a00a288c` | Return a glyph bitmap column from the table of menu font 0xF9. | derived |
| [`font_get_glyph_column_code_fa`](../../src/leon2m/font/font_get_glyph_column_code_fa.c) | `FUN_a00a285c` | Return a glyph bitmap column from the table of menu font 0xFA. | derived |
| [`font_get_glyph_column_code_fb`](../../src/leon2m/font/font_get_glyph_column_code_fb.c) | `FUN_a00a2de4` | Return a glyph bitmap column from the table of menu font 0xFB. | derived |
| [`font_get_glyph_column_code_fc`](../../src/leon2m/font/font_get_glyph_column_code_fc.c) | `FUN_a00a2d84` | Return a glyph bitmap column from the table of menu font 0xFC. | derived |
| [`font_get_glyph_column_code_fd`](../../src/leon2m/font/font_get_glyph_column_code_fd.c) | `FUN_a00a2c94` | Return a glyph bitmap column from the table of menu font 0xFD. | derived |
| [`font_get_glyph_column_code_fe`](../../src/leon2m/font/font_get_glyph_column_code_fe.c) | `FUN_a00a2cf4` | Return a glyph bitmap column from the table of menu font 0xFE. | derived |
| `font_get_glyph_column_jump_table` | `switchdataD_a00a2e74` | Jump table 1 of the switch statements in font_get_glyph_column. | proven |
| [`font_get_glyph_width`](../../src/leon2m/font/font_get_glyph_width.c) | `FUN_a00a3024` | Return the width of a character in the given menu font. | derived |
| [`font_get_glyph_width_code_f0`](../../src/leon2m/font/font_get_glyph_width_code_f0.c) | `FUN_a00a2c1c` | Return a glyph width from the table of menu font 0xF0. | derived |
| [`font_get_glyph_width_code_f1`](../../src/leon2m/font/font_get_glyph_width_code_f1.c) | `FUN_a00a2cdc` | Return a glyph width from the table of menu font 0xF1. | derived |
| [`font_get_glyph_width_code_f2`](../../src/leon2m/font/font_get_glyph_width_code_f2.c) | `FUN_a00a2d3c` | Return a glyph width from the table of menu font 0xF2. | derived |
| [`font_get_glyph_width_code_f3`](../../src/leon2m/font/font_get_glyph_width_code_f3.c) | `FUN_a00a2d6c` | Return a glyph width from the table of menu font 0xF3. | derived |
| [`font_get_glyph_width_code_f4`](../../src/leon2m/font/font_get_glyph_width_code_f4.c) | `FUN_a00a2dcc` | Return a glyph width from the table of menu font 0xF4. | derived |
| [`font_get_glyph_width_code_f5`](../../src/leon2m/font/font_get_glyph_width_code_f5.c) | `FUN_a00a2e2c` | Return a glyph width from the table of menu font 0xF5. | derived |
| [`font_get_glyph_width_code_f6`](../../src/leon2m/font/font_get_glyph_width_code_f6.c) | `FUN_a00a2c7c` | Return a glyph width from the table of menu font 0xF6. | derived |
| [`font_get_glyph_width_code_f7`](../../src/leon2m/font/font_get_glyph_width_code_f7.c) | `FUN_a00a2e5c` | Return a glyph width from the table of menu font 0xF7. | derived |
| [`font_get_glyph_width_code_f8`](../../src/leon2m/font/font_get_glyph_width_code_f8.c) | `FUN_a00a2c4c` | Return a glyph width from the table of menu font 0xF8. | derived |
| [`font_get_glyph_width_code_f9`](../../src/leon2m/font/font_get_glyph_width_code_f9.c) | `FUN_a00a28a4` | Return a glyph width from the table of menu font 0xF9. | derived |
| [`font_get_glyph_width_code_fa`](../../src/leon2m/font/font_get_glyph_width_code_fa.c) | `FUN_a00a2874` | Return a glyph width from the table of menu font 0xFA. | derived |
| [`font_get_glyph_width_code_fb`](../../src/leon2m/font/font_get_glyph_width_code_fb.c) | `FUN_a00a2dfc` | Return a glyph width from the table of menu font 0xFB. | derived |
| [`font_get_glyph_width_code_fc`](../../src/leon2m/font/font_get_glyph_width_code_fc.c) | `FUN_a00a2d9c` | Return a glyph width from the table of menu font 0xFC. | derived |
| [`font_get_glyph_width_code_fd`](../../src/leon2m/font/font_get_glyph_width_code_fd.c) | `FUN_a00a2cac` | Return a glyph width from the table of menu font 0xFD. | derived |
| [`font_get_glyph_width_code_fe`](../../src/leon2m/font/font_get_glyph_width_code_fe.c) | `FUN_a00a2d0c` | Return a glyph width from the table of menu font 0xFE. | derived |
| `font_get_glyph_width_jump_table` | `switchdataD_a00a2eb0` | Jump table 1 of the switch statements in font_get_glyph_width. | proven |
| [`font_load_crosshair_icon1`](../../src/leon2m/font/font_load_crosshair_icon1.c) | `FUN_a00a2b1c` | Load the glyphs of Smart Crosshair icon 1 into menu layer 1. | derived |
| [`font_load_crosshair_icon2`](../../src/leon2m/font/font_load_crosshair_icon2.c) | `FUN_a00a2b3c` | Load the glyphs of Smart Crosshair icon 2 into menu layer 1. | derived |
| [`font_load_crosshair_icon3`](../../src/leon2m/font/font_load_crosshair_icon3.c) | `FUN_a00a2b5c` | Load the glyphs of Smart Crosshair icon 3 into menu layer 1. | derived |
| [`font_load_crosshair_icon4`](../../src/leon2m/font/font_load_crosshair_icon4.c) | `FUN_a00a2b7c` | Load the glyphs of Smart Crosshair icon 4 into menu layer 1. | derived |
| [`font_load_crosshair_icon5`](../../src/leon2m/font/font_load_crosshair_icon5.c) | `FUN_a00a2b9c` | Load the glyphs of Smart Crosshair icon 5 into menu layer 1. | derived |
| [`font_load_crosshair_icon6`](../../src/leon2m/font/font_load_crosshair_icon6.c) | `FUN_a00a2bbc` | Load the glyphs of Smart Crosshair icon 6 into menu layer 1. | derived |
| [`font_load_crosshair_page_icons`](../../src/leon2m/font/font_load_crosshair_page_icons.c) | `FUN_a00a2afc` | Load the icon glyph block shown on the Smart Crosshair page. | descriptive |
| [`font_load_layout0_glyphs`](../../src/leon2m/font/font_load_layout0_glyphs.c) | `FUN_a00a28bc` | Load the glyph blocks used by menu layer layout 0 (60 x 23 cells) | derived |
| [`font_load_layout2_glyphs`](../../src/leon2m/font/font_load_layout2_glyphs.c) | `FUN_a00a2928` | Load the glyph blocks used by menu layer layout 2 (22 x 17 cells) | derived |
| [`font_load_layout3_glyphs`](../../src/leon2m/font/font_load_layout3_glyphs.c) | `FUN_a00a29a8` | Load the glyph blocks used by menu layer layout 3 (full width x 61 cells) | derived |
| [`font_load_layout4_glyphs`](../../src/leon2m/font/font_load_layout4_glyphs.c) | `FUN_a00a2adc` | Load the glyph blocks used by menu layer layout 4 (8 x 3 cells) | derived |
| [`font_load_layout5_glyphs`](../../src/leon2m/font/font_load_layout5_glyphs.c) | `FUN_a00a2a38` | Load the glyph blocks used by menu layer layout 5 (56 x 27 cells) | derived |

<a id="audio"></a>
## Sound

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`audio_api_route_source`](../../src/leon2m/audio/audio_api_route_source.c) | `FUN_a01478b0` | Translate a setting through a table and route that sound source. | derived |
| `audio_api_route_source_jump_table` | `switchdataD_a0143418` | Jump table 1 of the switch statements in audio_api_route_source. | proven |
| [`audio_api_set_level`](../../src/leon2m/audio/audio_api_set_level.c) | `FUN_a014398c` | Convert a 10-bit value to an audio level and send it to the input processor. | derived |
| [`audio_api_set_level_percent`](../../src/leon2m/audio/audio_api_set_level_percent.c) | `FUN_a0147a14` | Convert a percentage to an audio level and send it to the input processor. | derived |
| [`audio_api_set_mute`](../../src/leon2m/audio/audio_api_set_mute.c) | `FUN_a01479ec` | Mute or unmute the sound. | derived |
| [`audio_init_config`](../../src/leon2m/audio/audio_init_config.c) | `FUN_a014f6f4` | Build the audio configuration, switch the sound pins and send it to the input processor. | derived |
| [`audio_mute_outputs`](../../src/leon2m/audio/audio_mute_outputs.c) | `FUN_a0124f44` | Mute the sound: drive the mute pin high and tell the input processor. | derived |
| [`audio_select_output_pins`](../../src/leon2m/audio/audio_select_output_pins.c) | `FUN_a014f620` | Switch the five pins of pin group 0 or 1 to their sound function. | descriptive |
| [`audio_unit_assign_unit`](../../src/leon2m/audio/audio_unit_assign_unit.c) | `FUN_a014ebf8` | Give an id a free unit, or take over the oldest one, and update the order queue. | derived |
| [`audio_unit_find_unit`](../../src/leon2m/audio/audio_unit_find_unit.c) | `FUN_a014ead0` | Return which of the four units an id holds, or 4 when it holds none. | derived |
| [`audio_unit_get_owner_slot_mask`](../../src/leon2m/audio/audio_unit_get_owner_slot_mask.c) | `FUN_a014e974` | Return a 9-bit mask of the slots that belong to an owner. | descriptive |
| [`audio_unit_get_slot_owner`](../../src/leon2m/audio/audio_unit_get_slot_owner.c) | `FUN_a014e960` | Return the owner stored in one of the nine slots. | descriptive |
| [`audio_unit_is_unassigned`](../../src/leon2m/audio/audio_unit_is_unassigned.c) | `FUN_a014f32c` | Return whether an id holds no unit. | derived |
| [`audio_unit_queue_append`](../../src/leon2m/audio/audio_unit_queue_append.c) | `FUN_a014ea54` | Put an id into the first free place of the order queue. | derived |
| [`audio_unit_queue_remove`](../../src/leon2m/audio/audio_unit_queue_remove.c) | `FUN_a014e9d8` | Remove an id from the four-entry order queue and close the gap. | derived |
| [`audio_unit_queue_rotate`](../../src/leon2m/audio/audio_unit_queue_rotate.c) | `FUN_a014eaa8` | Push an id at the back of the order queue and return the id that drops out at the front. | derived |
| [`audio_unit_release_unused_units`](../../src/leon2m/audio/audio_unit_release_unused_units.c) | `FUN_a014f208` | Free every unit whose id no longer appears in the slot table. | derived |
| [`audio_unit_request_unit`](../../src/leon2m/audio/audio_unit_request_unit.c) | `FUN_a014f3d8` | Make sure an id has a unit, assigning one if needed, and announce the assignment. | derived |
| [`audio_unit_send_owner_slots`](../../src/leon2m/audio/audio_unit_send_owner_slots.c) | `FUN_a014eba4` | Send one command for every slot that belongs to an owner. | descriptive |
| [`audio_unit_send_unit_value`](../../src/leon2m/audio/audio_unit_send_unit_value.c) | `FUN_a014f374` | Send a 16-bit value for the unit an id holds, if it holds one. | descriptive |
| [`audio_unmute_outputs`](../../src/leon2m/audio/audio_unmute_outputs.c) | `FUN_a0124f24` | Unmute the sound: drive the mute pin low and tell the input processor. | derived |
| [`audio_user_apply_level`](../../src/leon2m/audio/audio_user_apply_level.c) | `FUN_a00d4970` | Apply the audio level setting, limited to 100. | derived |
| [`audio_user_apply_mute`](../../src/leon2m/audio/audio_user_apply_mute.c) | `FUN_a00d48cc` | Apply the mute setting. | derived |
| [`audio_user_toggle_source`](../../src/leon2m/audio/audio_user_toggle_source.c) | `FUN_a00d93c8` | Toggle which picture's sound is played and route it. | derived |
| [`audio_user_update_routing`](../../src/leon2m/audio/audio_user_update_routing.c) | `FUN_a00d5cd8` | Work out the sound source for the active input and route it. | derived |

<a id="ldc"></a>
## Dimming processor and its hardware block

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`ldc_api_send_cmd_0x31_sub0`](../../src/leon2m/ldc/ldc_api_send_cmd_0x31_sub0.c) | `FUN_a0143860` | Send dimming command 0x31, variant 0, with a 16-bit value. | descriptive |
| [`ldc_api_send_cmd_0x31_sub1`](../../src/leon2m/ldc/ldc_api_send_cmd_0x31_sub1.c) | `FUN_a0143848` | Send dimming command 0x31, variant 1, with a 16-bit value. | descriptive |
| [`ldc_api_send_cmd_0x33`](../../src/leon2m/ldc/ldc_api_send_cmd_0x33.c) | `FUN_a0143878` | Send dimming command 0x33 with a 16-bit value. | descriptive |
| [`ldc_api_send_cmd_0x34`](../../src/leon2m/ldc/ldc_api_send_cmd_0x34.c) | `FUN_a0143890` | Send dimming command 0x34 with a 16-bit value. | descriptive |
| [`ldc_api_send_cmd_0x39`](../../src/leon2m/ldc/ldc_api_send_cmd_0x39.c) | `FUN_a01438a8` | Send dimming command 0x39 with two 16-bit values. | descriptive |
| [`ldc_api_set_dimming_mode`](../../src/leon2m/ldc/ldc_api_set_dimming_mode.c) | `FUN_a014bd0c` | Send the mode 0..3 to the dimming processor, with a follow-up command for modes 1 and 2. | descriptive |
| [`ldc_api_set_direct_pwm`](../../src/leon2m/ldc/ldc_api_set_direct_pwm.c) | `FUN_a014dbf4` | Switch direct PWM of the dimming processor on for argument 1, off for every other value. | derived |
| [`ldc_api_set_mode_byte`](../../src/leon2m/ldc/ldc_api_set_mode_byte.c) | `FUN_a01438c8` | Send a mode byte to the dimming processor when it has changed. | descriptive |
| [`ldc_api_set_zone_grid`](../../src/leon2m/ldc/ldc_api_set_zone_grid.c) | `FUN_a014e050` | Select the 64 x 32 or the 32 x 16 zone grid and send the related mode values. | derived |
| [`ldc_get_reply_byte0`](../../src/leon2m/ldc/ldc_get_reply_byte0.c) | `FUN_a013a884` | Return the top byte of the dimming processor's reply word. | descriptive |
| [`ldc_get_reply_byte1`](../../src/leon2m/ldc/ldc_get_reply_byte1.c) | `FUN_a013a85c` | Return the second byte of the dimming processor's reply word. | descriptive |
| [`ldc_get_reply_byte2`](../../src/leon2m/ldc/ldc_get_reply_byte2.c) | `FUN_a013a824` | Return the third byte of the dimming processor's reply word. | descriptive |
| [`ldc_get_status_word`](../../src/leon2m/ldc/ldc_get_status_word.c) | `FUN_a013a8ac` | Return the status word of the dimming processor's mailbox. | descriptive |
| [`ldc_hw_access_register`](../../src/leon2m/ldc/ldc_hw_access_register.c) | `FUN_a00fb434` | Read, write or set up a register of the grid block selected by an id. | derived |
| `ldc_hw_access_register_jump_table` | `switchdataD_a00f9940` | Jump table 1 of the switch statements in ldc_hw_access_register. | proven |
| [`ldc_hw_api_pulse_reset`](../../src/leon2m/ldc/ldc_hw_api_pulse_reset.c) | `FUN_a014e7d0` | Pulse the reset bit of the grid block for five ticks. | descriptive |
| [`ldc_hw_api_set_enable_mode`](../../src/leon2m/ldc/ldc_hw_api_set_enable_mode.c) | `FUN_a014e878` | Set the grid block's enable and bit 31 of its register 0x200 for mode 0, 1 or 2. | descriptive |
| [`ldc_hw_command`](../../src/leon2m/ldc/ldc_hw_command.c) | `FUN_a00fbdcc` | Run one of the grid block's commands: init, suspend, timing or strength. | derived |
| [`ldc_hw_copy_table_rows`](../../src/leon2m/ldc/ldc_hw_copy_table_rows.c) | `FUN_a00f9d78` | Copy 20 table entries into rows 12..15 of the working table for the current mode. | descriptive |
| [`ldc_hw_enable_with_irq`](../../src/leon2m/ldc/ldc_hw_enable_with_irq.c) | `FUN_a00fbf5c` | Switch the grid block on or off together with its interrupt source. | derived |
| [`ldc_hw_fill_grid_table`](../../src/leon2m/ldc/ldc_hw_fill_grid_table.c) | `FUN_a00f9f10` | Fill the 16 x 17 table for the current mode from 20 values. | descriptive |
| [`ldc_hw_init`](../../src/leon2m/ldc/ldc_hw_init.c) | `FUN_a00fb9ec` | Load both curves and write the fixed start values of the grid block. | descriptive |
| [`ldc_hw_latch_level_field`](../../src/leon2m/ldc/ldc_hw_latch_level_field.c) | `FUN_a00fa560` | Copy a 10-bit register field and flag a change of its top two bits. | descriptive |
| [`ldc_hw_load_curve_first`](../../src/leon2m/ldc/ldc_hw_load_curve_first.c) | `FUN_a00f9a00` | Copy the first 17-point curve into its 12-bit register fields. | descriptive |
| [`ldc_hw_load_curve_second`](../../src/leon2m/ldc/ldc_hw_load_curve_second.c) | `FUN_a00f9bbc` | Copy the second 17-point curve into its 12-bit register fields. | descriptive |
| [`ldc_hw_pulse_reset`](../../src/leon2m/ldc/ldc_hw_pulse_reset.c) | `FUN_a00fc1a0` | Set bit 29 of the grid block's control register, wait timer_sleep_ticks(5), restore the old value. | descriptive |
| [`ldc_hw_run_mode3_pass`](../../src/leon2m/ldc/ldc_hw_run_mode3_pass.c) | `FUN_a00fa814` | Run one pass of mode 3: write the arrays and tables, read the cells, compute 3 x 3 sums. | derived |
| [`ldc_hw_set_mode`](../../src/leon2m/ldc/ldc_hw_set_mode.c) | `FUN_a00f99a0` | Switch the grid block on or off and write its 4-bit mode. | descriptive |
| [`ldc_hw_set_reg200_bit31_inverted`](../../src/leon2m/ldc/ldc_hw_set_reg200_bit31_inverted.c) | `FUN_a00fc15c` | Clear bit 31 of register 0xD0040200 when the argument is 1 and set it for every other value. | descriptive |
| [`ldc_hw_set_strength`](../../src/leon2m/ldc/ldc_hw_set_strength.c) | `FUN_a00fbc80` | Set the strength values of the grid block for a mode. | descriptive |
| [`ldc_hw_set_timing`](../../src/leon2m/ldc/ldc_hw_set_timing.c) | `FUN_a00fbaf8` | Store a mode and write the timing values of the grid block. | descriptive |
| [`ldc_hw_setup_for_panel_size`](../../src/leon2m/ldc/ldc_hw_setup_for_panel_size.c) | `FUN_a00fc044` | Set the grid block up for the size of the active panel timing row. | derived |
| [`ldc_hw_start`](../../src/leon2m/ldc/ldc_hw_start.c) | `FUN_a00fbfd4` | Initialise the grid block, set its strength and switch it on with its interrupt. | derived |
| [`ldc_hw_suspend_or_resume`](../../src/leon2m/ldc/ldc_hw_suspend_or_resume.c) | `FUN_a00fbaa4` | Save and clear the block's enable bit, or restore it. | descriptive |
| [`ldc_hw_update_arrays`](../../src/leon2m/ldc/ldc_hw_update_arrays.c) | `FUN_a00fa6b4` | Store the level field of 0xD0040014; when its top bits changed, refill the arrays and write one out. | descriptive |
| [`ldc_hw_update_arrays_if_changed`](../../src/leon2m/ldc/ldc_hw_update_arrays_if_changed.c) | `FUN_a00fa5b4` | Refill three arrays and write them out when the change flag is set. | descriptive |
| [`ldc_is_reply_byte_set`](../../src/leon2m/ldc/ldc_is_reply_byte_set.c) | `FUN_a013a7f4` | Return whether the low byte of the dimming processor's reply word is non-zero. | descriptive |
| [`ldc_power_down_handshake`](../../src/leon2m/ldc/ldc_power_down_handshake.c) | `FUN_a01396d8` | Run the power-down handshake with the dimming processor. | proven |
| [`ldc_report_menu_layer_change`](../../src/leon2m/ldc/ldc_report_menu_layer_change.c) | `FUN_a0152fac` | Tell the dimming processor whether menu layer 0 or 1 is switched on, when that changes. | derived |
| [`ldc_send_adim_bright_percent`](../../src/leon2m/ldc/ldc_send_adim_bright_percent.c) | `FUN_a0139604` | Send dimming command 0x35 (ADIM_BrighPercent) with a value, only when the value has changed. | derived |
| [`ldc_send_adim_level_and_percent`](../../src/leon2m/ldc/ldc_send_adim_level_and_percent.c) | `FUN_a013a0d4` | Send dimming command 0x39: ADIM_BrighPercent and usUserADIM packed into 24 bits. | derived |
| [`ldc_send_adim_max`](../../src/leon2m/ldc/ldc_send_adim_max.c) | `FUN_a0139f7c` | Send dimming command 0x33 (ADIM_Max) with a 16-bit value. | derived |
| [`ldc_send_adim_min`](../../src/leon2m/ldc/ldc_send_adim_min.c) | `FUN_a013a028` | Send dimming command 0x34 (ADIM_Min) with a 16-bit value. | derived |
| [`ldc_send_cmd_0x3c`](../../src/leon2m/ldc/ldc_send_cmd_0x3c.c) | `FUN_a013a1a4` | Send dimming command 0x3C with a 16-bit value. | descriptive |
| [`ldc_send_cmd_0x3d`](../../src/leon2m/ldc/ldc_send_cmd_0x3d.c) | `FUN_a013a250` | Send dimming command 0x3D with a 16-bit value. | descriptive |
| [`ldc_send_cmd_0x3e`](../../src/leon2m/ldc/ldc_send_cmd_0x3e.c) | `FUN_a013a2fc` | Send dimming command 0x3E with a 16-bit value. | descriptive |
| [`ldc_send_cmd_0x3f`](../../src/leon2m/ldc/ldc_send_cmd_0x3f.c) | `FUN_a013a3a8` | Send dimming command 0x3F with a 16-bit value. | descriptive |
| [`ldc_send_cmd_0x42`](../../src/leon2m/ldc/ldc_send_cmd_0x42.c) | `FUN_a013aa38` | Send dimming command 0x42 with a one-byte value. | descriptive |
| [`ldc_send_cmd_0x84`](../../src/leon2m/ldc/ldc_send_cmd_0x84.c) | `FUN_a013a8d4` | Send dimming command 0x84 with a 16-bit value and a byte. | derived |
| [`ldc_send_command`](../../src/leon2m/ldc/ldc_send_command.c) | `FUN_a01393f0` | Send a dimming command with a sub-code and a 16-bit value. | derived |
| [`ldc_send_direct_pwm`](../../src/leon2m/ldc/ldc_send_direct_pwm.c) | `FUN_a01398bc` | Send dimming command 0x60 with a one-byte value: 1 switches direct PWM on, any other value off. | derived |
| [`ldc_send_dpll_init_check`](../../src/leon2m/ldc/ldc_send_dpll_init_check.c) | `FUN_a013a750` | Send the check command that the dimming processor answers with its init-done message. | proven |
| [`ldc_send_gain_table1_point`](../../src/leon2m/ldc/ldc_send_gain_table1_point.c) | `FUN_a013a500` | Send dimming command 0x51 with a sub-code byte and a 16-bit value (one point of gain table 1). | derived |
| [`ldc_send_gain_table2_point`](../../src/leon2m/ldc/ldc_send_gain_table2_point.c) | `FUN_a013a5b8` | Send dimming command 0x52 with a byte and a 16-bit value (one point of gain table 2). | derived |
| [`ldc_send_gain_table3_point`](../../src/leon2m/ldc/ldc_send_gain_table3_point.c) | `FUN_a013a670` | Send dimming command 0x53 with a sub-code byte and a 16-bit value (one point of gain table 3). | derived |
| [`ldc_send_init_led_drivers`](../../src/leon2m/ldc/ldc_send_init_led_drivers.c) | `FUN_a0139d38` | Send dimming command 0x22 with the value 1: the dimming program sets up the LED drivers. | derived |
| [`ldc_send_input_duty_check`](../../src/leon2m/ldc/ldc_send_input_duty_check.c) | `FUN_a013a98c` | Send dimming command 0x97 with a 16-bit value: switch the per-frame input duty check on or off. | derived |
| [`ldc_send_ldc_mode`](../../src/leon2m/ldc/ldc_send_ldc_mode.c) | `FUN_a0139968` | Send dimming command 0x20 (set LDC_Mode) with a mode value, only when the value has changed. | derived |
| [`ldc_send_led_current_on`](../../src/leon2m/ldc/ldc_send_led_current_on.c) | `FUN_a01394a8` | Send dimming command 0x38 with an on/off bit: switch the LED current on or off. | derived |
| [`ldc_send_led_driver_register`](../../src/leon2m/ldc/ldc_send_led_driver_register.c) | `FUN_a013aae4` | Send dimming command 0x61 with two byte values, which write one register of the LED driver. | derived |
| [`ldc_send_load_gain_table`](../../src/leon2m/ldc/ldc_send_load_gain_table.c) | `FUN_a013a454` | Send dimming command 0x50 with a value: load gain table 1..3 or the flat table. | derived |
| [`ldc_send_panel_size_and_start`](../../src/leon2m/ldc/ldc_send_panel_size_and_start.c) | `FUN_a0139a30` | Send the active panel size to the dimming processor and start its program. | proven |
| [`ldc_send_peaking`](../../src/leon2m/ldc/ldc_send_peaking.c) | `FUN_a01397f4` | Send dimming command 0x82 (peaking off or on) with a mode byte, only when the byte has changed. | derived |
| [`ldc_send_user_adim_sub0`](../../src/leon2m/ldc/ldc_send_user_adim_sub0.c) | `FUN_a0139ed0` | Send dimming command 0x31 (usUserADIM) variant 0, with a 16-bit value. | derived |
| [`ldc_send_user_adim_sub1`](../../src/leon2m/ldc/ldc_send_user_adim_sub1.c) | `FUN_a0139558` | Send dimming command 0x31 (usUserADIM) variant 1, with a 16-bit value. | derived |
| [`ldc_send_user_pdim`](../../src/leon2m/ldc/ldc_send_user_pdim.c) | `FUN_a0139ddc` | Send dimming command 0x30 (usUserPDIM): a 10-bit level scaled to 12 bits, when it has changed. | derived |
| [`ldc_send_zone_counts`](../../src/leon2m/ldc/ldc_send_zone_counts.c) | `FUN_a0139c3c` | Send the two zone counts as powers of two to the dimming processor. | proven |
| [`ldc_send_zone_grid_32x16`](../../src/leon2m/ldc/ldc_send_zone_grid_32x16.c) | `FUN_a0139b90` | Send the 32 x 16 zone grid to the dimming processor. | proven |
| [`ldc_set_direct_pwm_off`](../../src/leon2m/ldc/ldc_set_direct_pwm_off.c) | `FUN_a0132a40` | Switch direct PWM of the dimming processor off for argument 1 and on for argument 0 (command 0x60). | derived |
| [`ldc_user_apply_grid_enable`](../../src/leon2m/ldc/ldc_user_apply_grid_enable.c) | `FUN_a00db690` | Switch the grid block for the current state and re-apply the dimming mode. | descriptive |
| [`ldc_user_send_cmd_0x61`](../../src/leon2m/ldc/ldc_user_send_cmd_0x61.c) | `FUN_a00db678` | Send dimming command 0x61 with selector 7 and a value. | descriptive |
| [`ldc_user_set_dimming_mode`](../../src/leon2m/ldc/ldc_user_set_dimming_mode.c) | `FUN_a00d8064` | Send the dimming mode 0..3. | descriptive |
| [`ldc_write_status_word`](../../src/leon2m/ldc/ldc_write_status_word.c) | `FUN_a013a728` | Write the word at offset 0x38 of the dimming processor's mailbox, which it reads as a channel mask. | derived |

<a id="ipc"></a>
## Messages between the processors

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`ipc_8051_advance_tx_slot`](../../src/leon2m/ipc/ipc_8051_advance_tx_slot.c) | `FUN_a0134684` | Move the outgoing slot index on by one, wrapping after 3. | derived |
| [`ipc_8051_build_fixed_wake_table`](../../src/leon2m/ipc/ipc_8051_build_fixed_wake_table.c) | `FUN_a0133238` | Fill the second wake-up table with its four fixed entries. | derived |
| [`ipc_8051_build_power_cut_table`](../../src/leon2m/ipc/ipc_8051_build_power_cut_table.c) | `FUN_a0133384` | Fill the 18-byte power-cut table that is sent to the 8051. | derived |
| [`ipc_8051_build_wake_table`](../../src/leon2m/ipc/ipc_8051_build_wake_table.c) | `FUN_a0132e1c` | Fill the table of wake-up sources that is sent to the 8051 before standby. | derived |
| `ipc_8051_build_wake_table_jump_table` | `switchdataD_a0132ac0` | Jump table 1 of the switch statements in ipc_8051_build_wake_table. | proven |
| `ipc_8051_build_wake_table_jump_table2` | `switchdataD_a0132b0c` | Jump table 2 of the switch statements in ipc_8051_build_wake_table. | proven |
| [`ipc_8051_clear_ddc_access_flags`](../../src/leon2m/ipc/ipc_8051_clear_ddc_access_flags.c) | `FUN_a013408c` | Tell the 8051 to clear the DDC access flags in the mailbox (command 0x20). | derived |
| [`ipc_8051_clear_word`](../../src/leon2m/ipc/ipc_8051_clear_word.c) | `FUN_a013480c` | Write a zero word to an offset of the 8051 mailbox. | derived |
| [`ipc_8051_close_uart_ports`](../../src/leon2m/ipc/ipc_8051_close_uart_ports.c) | `FUN_a0133f24` | Tell the 8051 to close the given serial ports (command 0x06). | derived |
| [`ipc_8051_decode_message`](../../src/leon2m/ipc/ipc_8051_decode_message.c) | `FUN_a013497c` | Sort a message from the 8051 into the EDID, I2C, UART or infrared buffer. | proven |
| `ipc_8051_decode_message_jump_table` | `switchdataD_a0132b74` | Jump table 1 of the switch statements in ipc_8051_decode_message. | proven |
| [`ipc_8051_disable_capture_irqs`](../../src/leon2m/ipc/ipc_8051_disable_capture_irqs.c) | `FUN_a0133ec8` | Tell the 8051 to disable all capture-interrupt sources (command 0x0A). | derived |
| [`ipc_8051_disable_ddc_slave`](../../src/leon2m/ipc/ipc_8051_disable_ddc_slave.c) | `FUN_a0133e58` | Tell the 8051 to switch the DDC/CI slave of the given ports off (command 0x08). | derived |
| [`ipc_8051_disable_internal_edid`](../../src/leon2m/ipc/ipc_8051_disable_internal_edid.c) | `FUN_a0133f84` | Tell the 8051 to switch the internal EDID of a port off. | derived |
| [`ipc_8051_enable_ddc_slave`](../../src/leon2m/ipc/ipc_8051_enable_ddc_slave.c) | `FUN_a0133e7c` | Tell the 8051 the DDC/CI slave address of the given ports and switch it on (command 0x07). | derived |
| [`ipc_8051_enable_internal_edid`](../../src/leon2m/ipc/ipc_8051_enable_internal_edid.c) | `FUN_a0133fbc` | Tell the 8051 to switch the internal EDID of a port on. | proven |
| [`ipc_8051_find_filled_rx_slot`](../../src/leon2m/ipc/ipc_8051_find_filled_rx_slot.c) | `FUN_a01346ac` | Find a filled slot among the four incoming slots of the 8051 mailbox. | derived |
| [`ipc_8051_find_free_tx_slot`](../../src/leon2m/ipc/ipc_8051_find_free_tx_slot.c) | `FUN_a013453c` | Find a free slot among the four outgoing slots of the 8051 mailbox. | derived |
| [`ipc_8051_flash_erase_sector`](../../src/leon2m/ipc/ipc_8051_flash_erase_sector.c) | `FUN_a0134464` | Ask the 8051 to erase the flash sector at an address. | derived |
| [`ipc_8051_flash_program_row`](../../src/leon2m/ipc/ipc_8051_flash_program_row.c) | `FUN_a0134428` | Ask the 8051 to program a flash-backed storage row at an address. | derived |
| [`ipc_8051_flash_write_bytes`](../../src/leon2m/ipc/ipc_8051_flash_write_bytes.c) | `FUN_a01344f4` | Have the 8051 program some bytes of its flash buffer at the job address (commands 0x14, 0x15). | derived |
| [`ipc_8051_get_boot_source`](../../src/leon2m/ipc/ipc_8051_get_boot_source.c) | `FUN_a0133564` | Return the boot source byte reported by the 8051. | derived |
| [`ipc_8051_get_status_byte`](../../src/leon2m/ipc/ipc_8051_get_status_byte.c) | `FUN_a0133cbc` | Return byte n (0..3) of the 8051 status word, portal word 0x0C of the 8051 mailbox. | descriptive |
| [`ipc_8051_get_status_byte0`](../../src/leon2m/ipc/ipc_8051_get_status_byte0.c) | `FUN_a01334ec` | Return the low byte of the 8051 status word. | descriptive |
| [`ipc_8051_get_status_byte1`](../../src/leon2m/ipc/ipc_8051_get_status_byte1.c) | `FUN_a0133514` | Return the second byte of the 8051 status word. | descriptive |
| [`ipc_8051_get_status_byte2`](../../src/leon2m/ipc/ipc_8051_get_status_byte2.c) | `FUN_a013353c` | Return the third byte of the 8051 status word. | descriptive |
| [`ipc_8051_load_dp_tx_hdcp_data`](../../src/leon2m/ipc/ipc_8051_load_dp_tx_hdcp_data.c) | `FUN_a0133dec` | Tell the 8051 to load the copy-protection data of the DisplayPort output (command 0x21). | derived |
| [`ipc_8051_notify_power_off`](../../src/leon2m/ipc/ipc_8051_notify_power_off.c) | `FUN_a0133e10` | Send 8051 command 0x17 and never return (send mode 3 loops forever after the send). | derived |
| [`ipc_8051_notify_power_saving`](../../src/leon2m/ipc/ipc_8051_notify_power_saving.c) | `FUN_a0133e34` | Send 8051 command 0x16 and never return (send mode 3 loops forever after the send). | derived |
| [`ipc_8051_open_uart_ports`](../../src/leon2m/ipc/ipc_8051_open_uart_ports.c) | `FUN_a0133f48` | Tell the 8051 to open the given serial ports with a line format and a baud rate (command 0x05). | derived |
| [`ipc_8051_poll_messages`](../../src/leon2m/ipc/ipc_8051_poll_messages.c) | `FUN_a0134de0` | Check the incoming slots of the 8051 mailbox and decode a message that has arrived. | proven |
| [`ipc_8051_queue_buffer_chunks`](../../src/leon2m/ipc/ipc_8051_queue_buffer_chunks.c) | `FUN_a013358c` | Queue two bytes and a buffer for the 8051 in 16-byte chunks without waiting. | descriptive |
| [`ipc_8051_read_port_memory`](../../src/leon2m/ipc/ipc_8051_read_port_memory.c) | `FUN_a013562c` | Ask the 8051 for a block of a port's memory and wait for the bytes. | derived |
| [`ipc_8051_read_word_b4`](../../src/leon2m/ipc/ipc_8051_read_word_b4.c) | `FUN_a01344cc` | Read the word at offset 0xB4 of the 8051 mailbox. | descriptive |
| [`ipc_8051_release_dp_aux`](../../src/leon2m/ipc/ipc_8051_release_dp_aux.c) | `FUN_a0133d04` | Tell the 8051 to hand the DisplayPort receivers back (command 0x2B). | proven |
| [`ipc_8051_request_and_wait`](../../src/leon2m/ipc/ipc_8051_request_and_wait.c) | `FUN_a0135344` | Queue a request with two bytes for the 8051 and service the mailbox until the answer is in. | derived |
| [`ipc_8051_send_buffer_chunks`](../../src/leon2m/ipc/ipc_8051_send_buffer_chunks.c) | `FUN_a0135ae8` | Queue two bytes and a buffer for the 8051 in 16-byte chunks. | descriptive |
| [`ipc_8051_send_power_cut_table`](../../src/leon2m/ipc/ipc_8051_send_power_cut_table.c) | `FUN_a0136384` | Queue the 18-byte power-cut table for the 8051 (message type 10). | derived |
| [`ipc_8051_send_storage_block`](../../src/leon2m/ipc/ipc_8051_send_storage_block.c) | `FUN_a013588c` | Queue a block for the 8051's flash data buffer (message type 7, 16-byte pieces) at a byte offset. | derived |
| [`ipc_8051_send_usb_c_info`](../../src/leon2m/ipc/ipc_8051_send_usb_c_info.c) | `FUN_a0136054` | Queue the ten-byte description of the USB-C port for the 8051 (message type 0x0B). | derived |
| [`ipc_8051_send_wake_key_table`](../../src/leon2m/ipc/ipc_8051_send_wake_key_table.c) | `FUN_a0136600` | Queue the 60-byte table of standby keys and wake-up pins for the 8051 (message type 8). | derived |
| [`ipc_8051_send_wake_port_table`](../../src/leon2m/ipc/ipc_8051_send_wake_port_table.c) | `FUN_a0135dc0` | Queue the table of wake-up ports for the 8051 (message type 9). | derived |
| [`ipc_8051_service`](../../src/leon2m/ipc/ipc_8051_service.c) | `FUN_a0136d08` | Flush the outgoing queue and poll the incoming slots once. | derived |
| [`ipc_8051_set_capture_irq_mask`](../../src/leon2m/ipc/ipc_8051_set_capture_irq_mask.c) | `FUN_a0133eec` | Tell the 8051 which capture-interrupt sources are enabled (command 0x09). | derived |
| [`ipc_8051_set_cec_registers`](../../src/leon2m/ipc/ipc_8051_set_cec_registers.c) | `FUN_a0133ea4` | Have the 8051 write two registers of the CEC controller (command 0x24). | derived |
| [`ipc_8051_set_edid_slave_bit6`](../../src/leon2m/ipc/ipc_8051_set_edid_slave_bit6.c) | `FUN_a01340b0` | Have the 8051 set or clear bit 6 of a port's EDID slave control register (command 0x1F). | derived |
| [`ipc_8051_set_flash_window_extend`](../../src/leon2m/ipc/ipc_8051_set_flash_window_extend.c) | `FUN_a01344a0` | Tell the 8051 the 24-bit extension of its flash window (command 0x26). | proven |
| [`ipc_8051_set_indicator`](../../src/leon2m/ipc/ipc_8051_set_indicator.c) | `FUN_a01341dc` | Have the 8051 toggle the masked pins of one GPIO port (commands 0x19, 0x1A, 0x18); print the values. | proven |
| `ipc_8051_set_indicator_jump_table` | `switchdataD_a0132b2c` | Jump table 1 of the switch statements in ipc_8051_set_indicator. | proven |
| [`ipc_8051_set_option_byte`](../../src/leon2m/ipc/ipc_8051_set_option_byte.c) | `FUN_a0133da0` | Store a byte in one of six option bytes of the 8051 (command 0x23). | descriptive |
| [`ipc_8051_set_option_flag`](../../src/leon2m/ipc/ipc_8051_set_option_flag.c) | `FUN_a0133d78` | Set or clear one of two flag bits in the 8051's byte 0xCAB2 (command 0x28). | descriptive |
| [`ipc_8051_set_pin_p14`](../../src/leon2m/ipc/ipc_8051_set_pin_p14.c) | `FUN_a0134140` | Have the 8051 drive its pin P1.4 high or low (command 0x1D). | proven |
| [`ipc_8051_set_pin_p15`](../../src/leon2m/ipc/ipc_8051_set_pin_p15.c) | `FUN_a01340fc` | Have the 8051 drive its pin P1.5 high or low (command 0x1E). | proven |
| [`ipc_8051_start_handshake`](../../src/leon2m/ipc/ipc_8051_start_handshake.c) | `FUN_a0134068` | Send 8051 command 0x27, which holds the 8051 in a handshake on mailbox word 0xB8. | derived |
| [`ipc_8051_start_port_sequence`](../../src/leon2m/ipc/ipc_8051_start_port_sequence.c) | `FUN_a0133d4c` | Give the 8051 a port pair and start its timed port sequence (command 0x25). | descriptive |
| [`ipc_8051_switch_control_bit`](../../src/leon2m/ipc/ipc_8051_switch_control_bit.c) | `FUN_a0133dc8` | Have the 8051 switch bit 3 of one of two control registers (command 0x22). | descriptive |
| [`ipc_8051_take_over_dp_aux`](../../src/leon2m/ipc/ipc_8051_take_over_dp_aux.c) | `FUN_a0133d28` | Tell the 8051 to answer the DisplayPort AUX requests itself (command 0x2A). | proven |
| [`ipc_8051_take_rx_block`](../../src/leon2m/ipc/ipc_8051_take_rx_block.c) | `FUN_a0132cd4` | Copy the block received from the 8051 to the caller's buffer when its ready flag is set. | derived |
| [`ipc_8051_take_rx_block2`](../../src/leon2m/ipc/ipc_8051_take_rx_block2.c) | `FUN_a0132b8c` | Copy the second block received from the 8051 to the caller's buffer when its ready flag is set. | derived |
| [`ipc_8051_tx_queue_flush`](../../src/leon2m/ipc/ipc_8051_tx_queue_flush.c) | `FUN_a01350dc` | Move queued messages into free outgoing slots of the 8051 mailbox. | proven |
| [`ipc_8051_tx_queue_free_bytes`](../../src/leon2m/ipc/ipc_8051_tx_queue_free_bytes.c) | `FUN_a0132bfc` | Return the free room of the outgoing queue in bytes. | derived |
| [`ipc_8051_tx_queue_pop`](../../src/leon2m/ipc/ipc_8051_tx_queue_pop.c) | `FUN_a0135004` | Take the next queued message out of the outgoing queue. | derived |
| [`ipc_8051_wait_tx_queue`](../../src/leon2m/ipc/ipc_8051_wait_tx_queue.c) | `FUN_a01356fc` | Flush the 8051 send queue until it has room (mode 1), is empty (2) or the mailbox is empty too (3). | derived |
| [`ipc_8051_write_port_memory`](../../src/leon2m/ipc/ipc_8051_write_port_memory.c) | `FUN_a0136a10` | Queue a block for the 8051's 2 KB EDID RAM in 16-byte pieces (message type 1), from a RAM offset. | derived |
| [`ipc_ack_port_change_bits`](../../src/leon2m/ipc/ipc_ack_port_change_bits.c) | `FUN_a01387a4` | Ask the input processor to acknowledge the port change bits. | derived |
| [`ipc_api_clear_audio_level_steps`](../../src/leon2m/ipc/ipc_api_clear_audio_level_steps.c) | `FUN_a014e758` | Ask the input processor to clear the audio level step registers. | derived |
| [`ipc_api_enable_port_ddc_slaves`](../../src/leon2m/ipc/ipc_api_enable_port_ddc_slaves.c) | `FUN_a01486c4` | Switch the 8051's DDC/CI slaves of the ports in mask 0x55 on or off (8051 commands 0x07 and 0x08). | derived |
| [`ipc_api_get_status_field`](../../src/leon2m/ipc/ipc_api_get_status_field.c) | `FUN_a014ba68` | Return the 2-bit status field of the input processor's mailbox word 0 as 0..3. | descriptive |
| [`ipc_api_open_or_close_uart_ports`](../../src/leon2m/ipc/ipc_api_open_or_close_uart_ports.c) | `FUN_a0148794` | Have the 8051 open the serial ports of a mask (command 0x05: line format, baud rate) or close them. | derived |
| [`ipc_api_send_8051_cmd_0x22`](../../src/leon2m/ipc/ipc_api_send_8051_cmd_0x22.c) | `FUN_a0147c48` | Send command 0x22 with one value to the 8051. | descriptive |
| [`ipc_api_set_dp_rx_reg40_bits`](../../src/leon2m/ipc/ipc_api_set_dp_rx_reg40_bits.c) | `FUN_a012b404` | Ask the input processor to set bits 6-7 of DisplayPort receiver register 0x40 and run the follow-up. | derived |
| [`ipc_api_set_dp_rx_reg44_bits`](../../src/leon2m/ipc/ipc_api_set_dp_rx_reg44_bits.c) | `FUN_a012b86c` | Ask the input processor to write DisplayPort receiver register bits from a value. | derived |
| [`ipc_api_set_dp_rx_reg252_bits`](../../src/leon2m/ipc/ipc_api_set_dp_rx_reg252_bits.c) | `FUN_a012b8a8` | Ask the input processor to write bits 5-7 of DisplayPort receiver register 0x252. | derived |
| [`ipc_api_set_dp_rx_setting_11f`](../../src/leon2m/ipc/ipc_api_set_dp_rx_setting_11f.c) | `FUN_a012b884` | Ask the input processor to store a DisplayPort receiver setting byte and set the port up again. | derived |
| [`ipc_api_set_hdr_enable`](../../src/leon2m/ipc/ipc_api_set_hdr_enable.c) | `FUN_a014e03c` | Ask the input processor to switch the HDR curve service on or off. | derived |
| [`ipc_api_set_hdr_peak_luminance`](../../src/leon2m/ipc/ipc_api_set_hdr_peak_luminance.c) | `FUN_a014e024` | Ask the input processor to store the panel's peak luminance for the HDR handling. | derived |
| [`ipc_api_signal_alive`](../../src/leon2m/ipc/ipc_api_signal_alive.c) | `FUN_a014dd10` | Send the alive signal. | proven |
| [`ipc_apply_port_enable_mask`](../../src/leon2m/ipc/ipc_apply_port_enable_mask.c) | `FUN_a01382b0` | Ask the input processor to apply the port enable mask. | derived |
| [`ipc_check_hdcp_stored_keys`](../../src/leon2m/ipc/ipc_check_hdcp_stored_keys.c) | `FUN_a013851c` | Ask the input processor to check the stored copy-protection keys. | derived |
| [`ipc_clear_8051_flags2_bit`](../../src/leon2m/ipc/ipc_clear_8051_flags2_bit.c) | `FUN_a002c22c` | Clear bit 'bit' of the shared 8051 byte at XDATA 0xF225. | descriptive |
| [`ipc_clear_8051_handshake_pair`](../../src/leon2m/ipc/ipc_clear_8051_handshake_pair.c) | `FUN_a002cf78` | On chip code 0xE0, clear the shared bytes F212 and F211. | descriptive |
| [`ipc_clear_audio_level_steps`](../../src/leon2m/ipc/ipc_clear_audio_level_steps.c) | `FUN_a013adcc` | Ask the input processor to clear the audio level step registers. | derived |
| [`ipc_clear_hdmi_tx_request_bit14`](../../src/leon2m/ipc/ipc_clear_hdmi_tx_request_bit14.c) | `FUN_a0137fa0` | Ask the input processor to clear flag bit 14 of an HDMI output's request and mark it pending. | descriptive |
| [`ipc_clear_port_change_bits`](../../src/leon2m/ipc/ipc_clear_port_change_bits.c) | `FUN_a013730c` | Ask the input processor to clear the given port change bits of its state word (command 0x81). | derived |
| [`ipc_configure_audio`](../../src/leon2m/ipc/ipc_configure_audio.c) | `FUN_a0138564` | Ask the input processor to store the 3-byte audio configuration and initialise the audio block. | derived |
| [`ipc_configure_dsc_encoder`](../../src/leon2m/ipc/ipc_configure_dsc_encoder.c) | `FUN_a0138c50` | Ask the input processor to configure the picture compression encoder. | derived |
| [`ipc_copy_words_bytewise`](../../src/leon2m/ipc/ipc_copy_words_bytewise.c) | `FUN_a0134834` | Copy a buffer in groups of four bytes, storing each byte on its own. | descriptive |
| [`ipc_dbg_get_receiver_block`](../../src/leon2m/ipc/ipc_dbg_get_receiver_block.c) | `FUN_a013782c` | Ask the input processor to read 28 bytes of a receiver block (debug). | derived |
| [`ipc_enable_hdmi_phy_input`](../../src/leon2m/ipc/ipc_enable_hdmi_phy_input.c) | `FUN_a01378f0` | Ask the input processor to enable or disable the input of one HDMI receiver. | derived |
| [`ipc_get_dp_rx_clock_value`](../../src/leon2m/ipc/ipc_get_dp_rx_clock_value.c) | `FUN_a01381f0` | Ask the input processor to read the 24-bit clock value of a DisplayPort input. | derived |
| [`ipc_get_dp_rx_register`](../../src/leon2m/ipc/ipc_get_dp_rx_register.c) | `FUN_a01384e4` | Ask the input processor to read one DisplayPort receiver register. | derived |
| [`ipc_get_hdmi21_status_byte`](../../src/leon2m/ipc/ipc_get_hdmi21_status_byte.c) | `FUN_a01391a8` | Ask the input processor to read a status byte of an HDMI 2.1 input. | derived |
| [`ipc_get_hdmi_port_status`](../../src/leon2m/ipc/ipc_get_hdmi_port_status.c) | `FUN_a01384ac` | Ask the input processor to read a status bit of an HDMI port. | derived |
| [`ipc_get_hdmi_tx_registers`](../../src/leon2m/ipc/ipc_get_hdmi_tx_registers.c) | `FUN_a0137fcc` | Ask the input processor to read eight registers of an HDMI output. | derived |
| [`ipc_get_input_setting_byte`](../../src/leon2m/ipc/ipc_get_input_setting_byte.c) | `FUN_a013923c` | Ask the input processor to read a setting byte of an input. | derived |
| [`ipc_get_input_status_byte`](../../src/leon2m/ipc/ipc_get_input_status_byte.c) | `FUN_a0139114` | Ask the input processor to read a status byte of an input. | derived |
| [`ipc_get_input_timing`](../../src/leon2m/ipc/ipc_get_input_timing.c) | `FUN_a0139040` | Ask the input processor to read the measured timing of one input port. | derived |
| [`ipc_get_status_field`](../../src/leon2m/ipc/ipc_get_status_field.c) | `FUN_a0138e5c` | Read the 2-bit status field from mailbox portal 1. | descriptive |
| [`ipc_handshake_8051_bytes`](../../src/leon2m/ipc/ipc_handshake_8051_bytes.c) | `FUN_a002fa34` | Write 0xDD to shared byte 2, wait for 0xAA in byte 3, then clear the bytes (0x88 on timeout) | derived |
| [`ipc_input_cpu_get_ready_bit`](../../src/leon2m/ipc/ipc_input_cpu_get_ready_bit.c) | `FUN_a0136fc4` | Return the ready bit of the input processor's status word. | derived |
| [`ipc_input_cpu_get_state_bit24`](../../src/leon2m/ipc/ipc_input_cpu_get_state_bit24.c) | `FUN_a0136ff0` | Return state bit 24 of the input processor (its OSD unzip busy flag). | derived |
| [`ipc_input_cpu_get_state_bit26`](../../src/leon2m/ipc/ipc_input_cpu_get_state_bit26.c) | `FUN_a013701c` | Return state bit 26 of the input processor. | descriptive |
| [`ipc_input_cpu_get_state_bit27`](../../src/leon2m/ipc/ipc_input_cpu_get_state_bit27.c) | `FUN_a013704c` | Return state bit 27 of the input processor. | descriptive |
| [`ipc_input_cpu_get_state_bit28`](../../src/leon2m/ipc/ipc_input_cpu_get_state_bit28.c) | `FUN_a013707c` | Return state bit 28 of the input processor. | descriptive |
| [`ipc_input_cpu_get_state_bit29`](../../src/leon2m/ipc/ipc_input_cpu_get_state_bit29.c) | `FUN_a01370ac` | Return state bit 29 of the input processor. | descriptive |
| [`ipc_input_cpu_get_state_field`](../../src/leon2m/ipc/ipc_input_cpu_get_state_field.c) | `FUN_a0137724` | Return the 2-bit field at bits 6-7 of the input processor's state word. | descriptive |
| [`ipc_input_cpu_get_state_low_byte`](../../src/leon2m/ipc/ipc_input_cpu_get_state_low_byte.c) | `FUN_a0137754` | Return the low byte of the input processor's state word. | descriptive |
| [`ipc_input_cpu_test_port_mask`](../../src/leon2m/ipc/ipc_input_cpu_test_port_mask.c) | `FUN_a01377a4` | Return whether a port mask overlaps bits 8-15 of the input processor's state word. | descriptive |
| [`ipc_input_cpu_test_port_mask_alt`](../../src/leon2m/ipc/ipc_input_cpu_test_port_mask_alt.c) | `FUN_a01377e8` | Return whether a port mask overlaps bits 8-15 of the word at offset 0xCC. | descriptive |
| [`ipc_input_cpu_test_state_mask`](../../src/leon2m/ipc/ipc_input_cpu_test_state_mask.c) | `FUN_a01376ec` | Return whether any of the given bits is set in the input processor's state word. | descriptive |
| [`ipc_input_cpu_write_flags_word`](../../src/leon2m/ipc/ipc_input_cpu_write_flags_word.c) | `FUN_a0136f4c` | Build a flags word from a 16-bit value and write it to the input processor. | descriptive |
| [`ipc_input_cpu_write_port_nibbles`](../../src/leon2m/ipc/ipc_input_cpu_write_port_nibbles.c) | `FUN_a0136e9c` | Pack eight 4-bit port values into one word and write it to the input processor. | descriptive |
| [`ipc_input_cpu_write_port_nibbles_copy`](../../src/leon2m/ipc/ipc_input_cpu_write_port_nibbles_copy.c) | `FUN_a0138ae8` | Pack eight 4-bit port values into one word and write it to the input processor. | descriptive |
| [`ipc_ir_rx_buffer_take`](../../src/leon2m/ipc/ipc_ir_rx_buffer_take.c) | `FUN_a01348a0` | Take up to n bytes from the infrared message buffer and close the gap. | derived |
| [`ipc_is_dp_rx_condition_pending`](../../src/leon2m/ipc/ipc_is_dp_rx_condition_pending.c) | `FUN_a01393bc` | Ask the input processor to report whether a DisplayPort receiver port has a pending condition. | derived |
| [`ipc_is_dp_tx_link_active`](../../src/leon2m/ipc/ipc_is_dp_tx_link_active.c) | `FUN_a013808c` | Ask the input processor to report whether a DisplayPort output link is active. | derived |
| [`ipc_load_dp_rx_clock_registers`](../../src/leon2m/ipc/ipc_load_dp_rx_clock_registers.c) | `FUN_a0137c4c` | Ask the input processor to clear a DisplayPort receiver bit and load its clock registers. | derived |
| [`ipc_mailbox_read`](../../src/leon2m/ipc/ipc_mailbox_read.c) | `FUN_a002c4d0` | Copy count words from mailbox portal 0 (8051), 1 (Leon2S) or 2 (Tensilica) into buf. | proven |
| [`ipc_mailbox_write`](../../src/leon2m/ipc/ipc_mailbox_write.c) | `FUN_a002c5f8` | Copy count words from buf into mailbox portal 0 (8051), 1 (Leon2S) or 2 (Tensilica) | proven |
| [`ipc_map_index_to_code_0x11`](../../src/leon2m/ipc/ipc_map_index_to_code_0x11.c) | `FUN_a0132d44` | Convert an index 1..13 to a code 0x11..0x1D. | descriptive |
| `ipc_map_index_to_code_0x11_jump_table` | `switchdataD_a0132a74` | Jump table 1 of the switch statements in ipc_map_index_to_code_0x11. | proven |
| [`ipc_pack_bytes_to_words`](../../src/leon2m/ipc/ipc_pack_bytes_to_words.c) | `FUN_a0132c54` | Pack a byte buffer into big-endian words. | derived |
| [`ipc_pack_flag_and_bit_index`](../../src/leon2m/ipc/ipc_pack_flag_and_bit_index.c) | `FUN_a0132dd8` | Pack a flag and the index of the highest set bit of a mask into one byte. | descriptive |
| [`ipc_ping`](../../src/leon2m/ipc/ipc_ping.c) | `FUN_a0137bb0` | Ask the input processor to answer with 1. | derived |
| [`ipc_power_down`](../../src/leon2m/ipc/ipc_power_down.c) | `FUN_a01386e4` | Ask the input processor to power the receivers down (mode 0) and stop the input processor. | derived |
| [`ipc_power_down_for_saving`](../../src/leon2m/ipc/ipc_power_down_for_saving.c) | `FUN_a0138718` | Ask the input processor to power the receivers down (mode 1) and stop the input processor. | derived |
| [`ipc_print_timing_change_notice`](../../src/leon2m/ipc/ipc_print_timing_change_notice.c) | `FUN_a0138fb8` | Ask the input processor to print a timing change notice (debug). | derived |
| [`ipc_read_8051_byte`](../../src/leon2m/ipc/ipc_read_8051_byte.c) | `FUN_a002c194` | Return shared 8051 byte ch (XDATA 0xF200 + ch - 1, ch 1..4), else 0. | derived |
| [`ipc_read_8051_flags2`](../../src/leon2m/ipc/ipc_read_8051_flags2.c) | `FUN_a002c218` | Return the shared 8051 byte at XDATA 0xF225. | descriptive |
| [`ipc_read_8051_port_flags`](../../src/leon2m/ipc/ipc_read_8051_port_flags.c) | `FUN_a002c204` | Return the shared 8051 byte at XDATA 0xF224. | descriptive |
| [`ipc_reload_hdr_tone_curve`](../../src/leon2m/ipc/ipc_reload_hdr_tone_curve.c) | `FUN_a0138f04` | Ask the input processor to reload the HDR tone curve table. | derived |
| [`ipc_request_8051_ack`](../../src/leon2m/ipc/ipc_request_8051_ack.c) | `FUN_a002f388` | Write 1 to 8051 mailbox word 0xB8 and wait until the 8051 answers 2. | descriptive |
| [`ipc_request_hdr_reload`](../../src/leon2m/ipc/ipc_request_hdr_reload.c) | `FUN_a0138eb4` | Ask the input processor to mark the HDR settings as changed. | derived |
| [`ipc_restart_hdmi_port`](../../src/leon2m/ipc/ipc_restart_hdmi_port.c) | `FUN_a0137920` | Ask the input processor to restart one of the two HDMI 2.1 inputs (channel 0 or 1). | derived |
| [`ipc_route_audio_source`](../../src/leon2m/ipc/ipc_route_audio_source.c) | `FUN_a013863c` | Ask the input processor to route an audio source to an output through an audio unit. | derived |
| [`ipc_select_hdr_source`](../../src/leon2m/ipc/ipc_select_hdr_source.c) | `FUN_a0138bf8` | Ask the input processor to select the source that the HDR service follows. | derived |
| [`ipc_send_8051_command`](../../src/leon2m/ipc/ipc_send_8051_command.c) | `FUN_a002f3f4` | Send command cmd with three argument bytes to the 8051 through mailbox portal 0. | proven |
| [`ipc_send_command`](../../src/leon2m/ipc/ipc_send_command.c) | `FUN_a01370dc` | Send a checksummed command with up to 28 data bytes to the input processor. | proven |
| [`ipc_send_command_nop_wait`](../../src/leon2m/ipc/ipc_send_command_nop_wait.c) | `FUN_a013ab9c` | Send a checksummed command through mailbox portal 1, pausing with a nop loop, not the tick timer. | derived |
| [`ipc_send_dsc_dec_command`](../../src/leon2m/ipc/ipc_send_dsc_dec_command.c) | `FUN_a0137d6c` | Send a command byte for the DSC decoder state machine of the input processor (command 0x74). | derived |
| [`ipc_set_audio_level`](../../src/leon2m/ipc/ipc_set_audio_level.c) | `FUN_a01386ac` | Ask the input processor to set a 16-bit audio level (0x8000 = neutral). | derived |
| [`ipc_set_audio_mute`](../../src/leon2m/ipc/ipc_set_audio_mute.c) | `FUN_a0138610` | Ask the input processor to mute or unmute the audio outputs. | derived |
| [`ipc_set_audio_unit_frequency`](../../src/leon2m/ipc/ipc_set_audio_unit_frequency.c) | `FUN_a0138674` | Ask the input processor to program the frequency word of one audio unit. | derived |
| [`ipc_set_command_flags`](../../src/leon2m/ipc/ipc_set_command_flags.c) | `FUN_a0138284` | Ask the input processor to set the command flags. | derived |
| [`ipc_set_dp_mst`](../../src/leon2m/ipc/ipc_set_dp_mst.c) | `FUN_a0137aec` | Ask the input processor to switch DisplayPort multi-stream on or off for a port. | derived |
| [`ipc_set_dp_mst_logical_number`](../../src/leon2m/ipc/ipc_set_dp_mst_logical_number.c) | `FUN_a0137d40` | Ask the input processor to set the DisplayPort multi-stream logical number. | derived |
| [`ipc_set_dp_rx_capabilities`](../../src/leon2m/ipc/ipc_set_dp_rx_capabilities.c) | `FUN_a0137be8` | Ask the input processor to store two mode bytes and rewrite the port's capability registers. | derived |
| [`ipc_set_dp_rx_config`](../../src/leon2m/ipc/ipc_set_dp_rx_config.c) | `FUN_a013797c` | Send the full DisplayPort receiver configuration of a port to the input processor. | derived |
| [`ipc_set_dp_rx_lane_options`](../../src/leon2m/ipc/ipc_set_dp_rx_lane_options.c) | `FUN_a0137d08` | Send three DisplayPort receiver option bytes and the lane and enable bits of a port. | derived |
| [`ipc_set_dp_rx_mode`](../../src/leon2m/ipc/ipc_set_dp_rx_mode.c) | `FUN_a0137a68` | Ask the input processor to store the DisplayPort receiver mode bytes of a port. | derived |
| [`ipc_set_dp_rx_option`](../../src/leon2m/ipc/ipc_set_dp_rx_option.c) | `FUN_a0137c1c` | Ask the input processor to store a DisplayPort receiver option byte and reprogram the port. | derived |
| [`ipc_set_dp_rx_port_flag`](../../src/leon2m/ipc/ipc_set_dp_rx_port_flag.c) | `FUN_a01392d0` | Ask the input processor to set a flag of a DisplayPort receiver port. | derived |
| [`ipc_set_dp_rx_reg40_bits`](../../src/leon2m/ipc/ipc_set_dp_rx_reg40_bits.c) | `FUN_a0137cdc` | Ask the input processor to set bits 6-7 of DisplayPort receiver register 0x40 and run the follow-up. | derived |
| [`ipc_set_dp_rx_reg44_bits`](../../src/leon2m/ipc/ipc_set_dp_rx_reg44_bits.c) | `FUN_a0137cac` | Ask the input processor to write DisplayPort receiver register bits from a value. | derived |
| [`ipc_set_dp_rx_reg252_bits`](../../src/leon2m/ipc/ipc_set_dp_rx_reg252_bits.c) | `FUN_a0138bc8` | Ask the input processor to write bits 5-7 of DisplayPort receiver register 0x252. | derived |
| [`ipc_set_dp_rx_setting_11f`](../../src/leon2m/ipc/ipc_set_dp_rx_setting_11f.c) | `FUN_a0138b98` | Ask the input processor to store a DisplayPort receiver setting byte and set the port up again. | derived |
| [`ipc_set_dp_tx_drive_levels`](../../src/leon2m/ipc/ipc_set_dp_tx_drive_levels.c) | `FUN_a013844c` | Send the base swing and pre-emphasis bytes of the four lanes of a DP output to the input processor. | derived |
| [`ipc_set_dp_tx_reg7d_bit4`](../../src/leon2m/ipc/ipc_set_dp_tx_reg7d_bit4.c) | `FUN_a0138180` | Ask the input processor to set or clear a control bit of a DisplayPort output. | derived |
| [`ipc_set_dp_tx_reg11_mode`](../../src/leon2m/ipc/ipc_set_dp_tx_reg11_mode.c) | `FUN_a0138110` | Ask the input processor to set the mode register 0x11 of a DisplayPort output. | derived |
| [`ipc_set_dp_tx_timing`](../../src/leon2m/ipc/ipc_set_dp_tx_timing.c) | `FUN_a013832c` | Ask the input processor to store the video timing for the DisplayPort outputs and program it. | derived |
| [`ipc_set_dsc_encoder_parameters`](../../src/leon2m/ipc/ipc_set_dsc_encoder_parameters.c) | `FUN_a01392f8` | Ask the input processor to store the picture compression parameters. | derived |
| [`ipc_set_edp_hpd_enable`](../../src/leon2m/ipc/ipc_set_edp_hpd_enable.c) | `FUN_a01381c4` | Send the eDP hotplug-enable byte to the input processor. | derived |
| [`ipc_set_hdcp_rx_port_option`](../../src/leon2m/ipc/ipc_set_hdcp_rx_port_option.c) | `FUN_a0137de0` | Ask the input processor to set a copy-protection option of an input. | derived |
| [`ipc_set_hdcp_tx_dp_bypass`](../../src/leon2m/ipc/ipc_set_hdcp_tx_dp_bypass.c) | `FUN_a01380c4` | Ask the input processor to clear or set the copy-protection bypass bit of DisplayPort output 0. | derived |
| [`ipc_set_hdmi21_port_mask`](../../src/leon2m/ipc/ipc_set_hdmi21_port_mask.c) | `FUN_a0137b5c` | Ask the input processor to apply a mask to the HDMI 2.1 port records. | derived |
| [`ipc_set_hdmi_phy_option_byte`](../../src/leon2m/ipc/ipc_set_hdmi_phy_option_byte.c) | `FUN_a0137b1c` | Ask the input processor to store an option byte of one HDMI receiver. | derived |
| [`ipc_set_hdmi_tx_reg0d_bit2`](../../src/leon2m/ipc/ipc_set_hdmi_tx_reg0d_bit2.c) | `FUN_a013805c` | Ask the input processor to set or clear a control bit of an HDMI output. | derived |
| [`ipc_set_hdmi_tx_request`](../../src/leon2m/ipc/ipc_set_hdmi_tx_request.c) | `FUN_a0137e10` | Ask the input processor to store a full HDMI output request (source, clock, format). | derived |
| [`ipc_set_hdmi_tx_request_bytes`](../../src/leon2m/ipc/ipc_set_hdmi_tx_request_bytes.c) | `FUN_a0137d98` | Ask the input processor to store four HDMI output request bytes. | derived |
| [`ipc_set_hdr_enable`](../../src/leon2m/ipc/ipc_set_hdr_enable.c) | `FUN_a0138e8c` | Ask the input processor to switch the HDR curve service on or off. | derived |
| [`ipc_set_hdr_mode_byte`](../../src/leon2m/ipc/ipc_set_hdr_mode_byte.c) | `FUN_a0138edc` | Ask the input processor to store an HDR mode byte. | derived |
| [`ipc_set_hdr_option_byte`](../../src/leon2m/ipc/ipc_set_hdr_option_byte.c) | `FUN_a0138f2c` | Ask the input processor to store an HDR option byte. | derived |
| [`ipc_set_hdr_peak_luminance`](../../src/leon2m/ipc/ipc_set_hdr_peak_luminance.c) | `FUN_a0138e28` | Ask the input processor to store the panel's peak luminance for the HDR handling. | derived |
| [`ipc_set_hdr_source_enable`](../../src/leon2m/ipc/ipc_set_hdr_source_enable.c) | `FUN_a0138c20` | Ask the input processor to switch the HDR handling of a source on or off. | derived |
| [`ipc_set_input_port_type`](../../src/leon2m/ipc/ipc_set_input_port_type.c) | `FUN_a0137864` | Ask the input processor to set the type of one input port. | derived |
| [`ipc_set_port_option_mask`](../../src/leon2m/ipc/ipc_set_port_option_mask.c) | `FUN_a01382e4` | Ask the input processor to set the port option mask. | derived |
| [`ipc_set_status_byte_88dd`](../../src/leon2m/ipc/ipc_set_status_byte_88dd.c) | `FUN_a013777c` | Ask the input processor to store a status byte. | derived |
| [`ipc_signal_alive`](../../src/leon2m/ipc/ipc_signal_alive.c) | `FUN_a002ced8` | Copy the 8051 alive counters F204 -> F208 and F240 -> F244. | proven |
| [`ipc_take_8051_handshake_pair`](../../src/leon2m/ipc/ipc_take_8051_handshake_pair.c) | `FUN_a002cf04` | On chip code 0xE0, set the shared bytes F211 and F212 to 1, waiting while they read 2. | descriptive |
| [`ipc_wait_command_slot_free`](../../src/leon2m/ipc/ipc_wait_command_slot_free.c) | `FUN_a0137644` | Wait until the input processor's command slot is free; at most 100 rounds if the argument is set. | derived |
| [`ipc_wait_input_cpu_power_down`](../../src/leon2m/ipc/ipc_wait_input_cpu_power_down.c) | `FUN_a013874c` | Wait until the input processor reports that it has powered down. | proven |
| [`ipc_wait_reply`](../../src/leon2m/ipc/ipc_wait_reply.c) | `FUN_a0137344` | Wait for the input processor's reply to the last command. | proven |
| [`ipc_write_8051_byte`](../../src/leon2m/ipc/ipc_write_8051_byte.c) | `FUN_a002c11c` | Write v to shared 8051 byte ch (XDATA 0xF200 + ch - 1, ch 1..4) | derived |
| [`MailBox_LoadFE2P`](../../src/leon2m/ipc/MailBox_LoadFE2P.c) | `FUN_a0134394` | Ask the 8051 to load a flash-backed storage row at an address. | proven |
| [`MailBox_SetWakeUpTimer`](../../src/leon2m/ipc/MailBox_SetWakeUpTimer.c) | `FUN_a0134184` | Tell the 8051 the wake-up timer value. | proven |
| [`MailBoxSub_SetDPTXBrilliantMode`](../../src/leon2m/ipc/MailBoxSub_SetDPTXBrilliantMode.c) | `FUN_a0138148` | Ask the input processor to start the pacing update of one DP output. | proven |

<a id="nvram"></a>
## Saved settings

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`nvram_api_clear_mode_table`](../../src/leon2m/nvram/nvram_api_clear_mode_table.c) | `FUN_a01454c4` | Clear the saved-mode table, or the table and both records. | derived |
| [`nvram_api_read_fga_byte`](../../src/leon2m/nvram/nvram_api_read_fga_byte.c) | `FUN_a0149268` | Read one byte of the FGA block in the EEPROM. | derived |
| [`nvram_api_read_fga_word`](../../src/leon2m/nvram/nvram_api_read_fga_word.c) | `FUN_a0149280` | Read one 16-bit value of the FGA block in the EEPROM. | derived |
| [`nvram_api_restore_factory_records`](../../src/leon2m/nvram/nvram_api_restore_factory_records.c) | `FUN_a014564c` | Write the ROM default records to the EEPROM. | derived |
| [`nvram_api_set_device_field3`](../../src/leon2m/nvram/nvram_api_set_device_field3.c) | `FUN_a01452d0` | Store two values in the 16-bit field at +3 of the device settings and save them. | descriptive |
| [`nvram_api_store_by_selector`](../../src/leon2m/nvram/nvram_api_store_by_selector.c) | `FUN_a0145360` | Store what the argument selects: 0 part record, 1 device settings, 2 one channel's mode row. | derived |
| [`nvram_api_write_fga_byte`](../../src/leon2m/nvram/nvram_api_write_fga_byte.c) | `FUN_a0149254` | Write one byte of the FGA block in the EEPROM. | derived |
| [`nvram_clear_mode_table`](../../src/leon2m/nvram/nvram_clear_mode_table.c) | `FUN_a01539b8` | Fill the saved-mode table (EEPROM 0x300..0x43F) with the 16-byte blank pattern. | derived |
| [`nvram_clear_mode_table_and_records`](../../src/leon2m/nvram/nvram_clear_mode_table_and_records.c) | `FUN_a0153a5c` | Fill EEPROM 0x300..0x4BF (mode table and both records) with the blank pattern. | derived |
| [`nvram_erase_area`](../../src/leon2m/nvram/nvram_erase_area.c) | `FUN_a0140500` | Erase the flash sector of a flash-backed storage area. | derived |
| [`nvram_flash_advance_row`](../../src/leon2m/nvram/nvram_flash_advance_row.c) | `FUN_a01405d0` | Move a flash-backed storage area on to its next row and write it there. | derived |
| [`nvram_flash_prepare_write`](../../src/leon2m/nvram/nvram_flash_prepare_write.c) | `FUN_a0140b78` | Prepare the row of a flash-backed area for a write at a given offset. | descriptive |
| [`nvram_flush_pending_now`](../../src/leon2m/nvram/nvram_flush_pending_now.c) | `FUN_a0140a0c` | Write the pending flash-backed data at once. | derived |
| [`nvram_flush_pending_task`](../../src/leon2m/nvram/nvram_flush_pending_task.c) | `FUN_a0140ab4` | Write the pending flash-backed data once it has waited for more than 1000 ticks. | derived |
| [`nvram_get_blank_value`](../../src/leon2m/nvram/nvram_get_blank_value.c) | `FUN_a012ce18` | Return 0xFFFF, the value of an unwritten storage cell. | descriptive |
| [`nvram_get_device_option_bit25`](../../src/leon2m/nvram/nvram_get_device_option_bit25.c) | `FUN_a012ad6c` | Return option bit 25 of the device settings. | descriptive |
| [`nvram_get_device_setting`](../../src/leon2m/nvram/nvram_get_device_setting.c) | `FUN_a0145af8` | Return one of the eighteen fields of the device settings record. | proven |
| `nvram_get_device_setting_jump_table` | `switchdataD_a0143238` | Jump table 1 of the switch statements in nvram_get_device_setting. | proven |
| [`nvram_is_device_usable`](../../src/leon2m/nvram/nvram_is_device_usable.c) | `FUN_a0140304` | Return whether a storage device can be used. | derived |
| [`nvram_load_default_part_record`](../../src/leon2m/nvram/nvram_load_default_part_record.c) | `FUN_a015440c` | Copy the 0x30-byte ROM default part record to its RAM copy at 0xA802E1F0. | proven |
| [`nvram_load_default_settings_record`](../../src/leon2m/nvram/nvram_load_default_settings_record.c) | `FUN_a0154458` | Copy the 0x50-byte ROM default settings record to its RAM copy at 0xA802E1A0. | proven |
| [`nvram_load_saved_mode_row`](../../src/leon2m/nvram/nvram_load_saved_mode_row.c) | `FUN_a01541ec` | Find the saved EEPROM row for the current timing and restore it into the mode record. | derived |
| [`nvram_load_user_settings`](../../src/leon2m/nvram/nvram_load_user_settings.c) | `FUN_a00d3bb4` | Read the user settings and the factory record from the EEPROM; write defaults if blank. | proven |
| [`nvram_read`](../../src/leon2m/nvram/nvram_read.c) | `FUN_a0140360` | Read a block from a storage device: EEPROM over I2C, or the flash window. | proven |
| [`nvram_read_fga_byte`](../../src/leon2m/nvram/nvram_read_fga_byte.c) | `FUN_a012eb4c` | Read one byte of the FGA block in the EEPROM. | derived |
| [`nvram_read_fga_word`](../../src/leon2m/nvram/nvram_read_fga_word.c) | `FUN_a012e850` | Read one 16-bit value of the FGA block in the EEPROM. | derived |
| [`nvram_read_part_record`](../../src/leon2m/nvram/nvram_read_part_record.c) | `FUN_a0153c54` | Read the 0x30-byte settings part record (EEPROM offset 0x440) into a buffer. | derived |
| [`nvram_read_settings_record`](../../src/leon2m/nvram/nvram_read_settings_record.c) | `FUN_a0153b00` | Read the 0x50-byte settings record (EEPROM offset 0x470) into a buffer. | derived |
| [`nvram_restore_factory_records`](../../src/leon2m/nvram/nvram_restore_factory_records.c) | `FUN_a0153b20` | Write the ROM default records to the EEPROM, fully or only five fields of the settings record. | derived |
| [`nvram_set_device_setting`](../../src/leon2m/nvram/nvram_set_device_setting.c) | `FUN_a0145c5c` | Store one of the eighteen fields of the device settings record. | proven |
| `nvram_set_device_setting_jump_table` | `switchdataD_a0143280` | Jump table 1 of the switch statements in nvram_set_device_setting. | proven |
| [`nvram_set_settings_field`](../../src/leon2m/nvram/nvram_set_settings_field.c) | `FUN_a014b3fc` | Copy one field into the settings record and save the record. | derived |
| `nvram_set_settings_field_jump_table` | `switchdataD_a01434d4` | Jump table 1 of the switch statements in nvram_set_settings_field. | proven |
| [`nvram_store_mode_row`](../../src/leon2m/nvram/nvram_store_mode_row.c) | `FUN_a01542c4` | Store the mode record in the 20-row EEPROM table at 0x300, reusing or adding a row for the timing. | derived |
| [`nvram_validate_settings_at_startup`](../../src/leon2m/nvram/nvram_validate_settings_at_startup.c) | `FUN_a0153c74` | Check the saved settings at start-up; write the ROM defaults or blank the saved-mode table if bad. | proven |
| [`nvram_write`](../../src/leon2m/nvram/nvram_write.c) | `FUN_a0140e74` | Write a block to a storage device, page by page, waiting until the chip is ready. | proven |
| [`nvram_write_default_user_settings`](../../src/leon2m/nvram/nvram_write_default_user_settings.c) | `FUN_a00d57e8` | Write the default user settings and the default factory record to the EEPROM. | proven |
| [`nvram_write_fga_byte`](../../src/leon2m/nvram/nvram_write_fga_byte.c) | `FUN_a012d4f8` | Write one byte of the FGA block in the EEPROM. | derived |
| [`nvram_write_part_record`](../../src/leon2m/nvram/nvram_write_part_record.c) | `FUN_a0153994` | Write the 0x30-byte part record to EEPROM offset 0x440. | derived |
| [`nvram_write_settings_record`](../../src/leon2m/nvram/nvram_write_settings_record.c) | `FUN_a0153970` | Write the 0x50-byte settings record to EEPROM offset 0x470. | derived |
| [`SYSAPI_EraseUSRFlashType2`](../../src/leon2m/nvram/SYSAPI_EraseUSRFlashType2.c) | `FUN_a014ad90` | Erase the type 2 user data area. | proven |
| [`SYSAPI_LoadUSRFlashType1`](../../src/leon2m/nvram/SYSAPI_LoadUSRFlashType1.c) | `FUN_a014aaa0` | Read a block of type 1 user data from storage after checking that it fits. | proven |
| [`SYSAPI_LoadUSRFlashType2`](../../src/leon2m/nvram/SYSAPI_LoadUSRFlashType2.c) | `FUN_a014ac28` | Read a block of type 2 user data from storage after checking that it fits. | proven |
| [`SYSAPI_ReadEEPROM`](../../src/leon2m/nvram/SYSAPI_ReadEEPROM.c) | `FUN_a014ae1c` | Read a block from the settings EEPROM after checking that it fits. | proven |
| [`SYSAPI_SaveUSRFlashType1`](../../src/leon2m/nvram/SYSAPI_SaveUSRFlashType1.c) | `FUN_a014ab74` | Write a block of type 1 user data to storage after checking that it fits. | proven |
| [`SYSAPI_SaveUSRFlashType2`](../../src/leon2m/nvram/SYSAPI_SaveUSRFlashType2.c) | `FUN_a014acdc` | Write a block of type 2 user data to storage after checking that it fits. | proven |
| [`SYSAPI_WriteEEPROM`](../../src/leon2m/nvram/SYSAPI_WriteEEPROM.c) | `FUN_a014aed0` | Write a block to the settings EEPROM after checking that it fits. | proven |

<a id="flash"></a>
## Flash memory

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`flash_write_protect_off`](../../src/leon2m/flash/flash_write_protect_off.c) | `FUN_a0124ed0` | Switch the flash write protection off. | derived |
| [`flash_write_protect_on`](../../src/leon2m/flash/flash_write_protect_on.c) | `FUN_a0124eb4` | Switch the flash write protection on. | derived |

<a id="fwupd"></a>
## Firmware update

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`fwupd_api_run_port_sequence`](../../src/leon2m/fwupd/fwupd_api_run_port_sequence.c) | `FUN_a0147c5c` | Run the register sequence of the update port and wait for it to finish. | descriptive |
| [`fwupd_api_send_port_command`](../../src/leon2m/fwupd/fwupd_api_send_port_command.c) | `FUN_a0147c6c` | Send a command to the update port and switch the two output blocks. | descriptive |
| [`fwupd_api_start_update`](../../src/leon2m/fwupd/fwupd_api_start_update.c) | `FUN_a0148230` | Set the progress hook, switch flash write protection off and start the update in mode 0. | derived |
| [`fwupd_api_start_update_mode5`](../../src/leon2m/fwupd/fwupd_api_start_update_mode5.c) | `FUN_a0148254` | Start the update in mode 5. | descriptive |
| [`fwupd_api_wait_port_ready`](../../src/leon2m/fwupd/fwupd_api_wait_port_ready.c) | `FUN_a0147c94` | Wait, with a time limit, until one of the two update ports reports ready. | descriptive |
| [`fwupd_enter_update`](../../src/leon2m/fwupd/fwupd_enter_update.c) | `FUN_a0123cf0` | Enter the firmware update: mode 0 runs the progress loop, mode 5 prepares the port first. | derived |
| [`fwupd_find_and_verify_file`](../../src/leon2m/fwupd/fwupd_find_and_verify_file.c) | `FUN_a0147fb4` | Look for a named file on the update port and verify its checksum. | derived |
| [`fwupd_find_file`](../../src/leon2m/fwupd/fwupd_find_file.c) | `FUN_a0148120` | Look for a named file on the update port. | derived |
| [`fwupd_get_active_port`](../../src/leon2m/fwupd/fwupd_get_active_port.c) | `FUN_a0124168` | Return which update port answered. | derived |
| [`fwupd_get_file_name_buffer`](../../src/leon2m/fwupd/fwupd_get_file_name_buffer.c) | `FUN_a0124174` | Return the buffer that holds the file name read from the update port. | derived |
| [`fwupd_get_file_name_length`](../../src/leon2m/fwupd/fwupd_get_file_name_length.c) | `FUN_a0147cac` | Return the length of a file name, at most 44. | derived |
| [`fwupd_get_progress_percent`](../../src/leon2m/fwupd/fwupd_get_progress_percent.c) | `FUN_a002f10c` | Return the transfer progress in percent (0..100) | derived |
| [`fwupd_hex_digit_value`](../../src/leon2m/fwupd/fwupd_hex_digit_value.c) | `FUN_a0123c4c` | Convert a hexadecimal digit character to its value. | proven |
| [`fwupd_is_file_name_match`](../../src/leon2m/fwupd/fwupd_is_file_name_match.c) | `FUN_a0123c80` | Compare a name with the file name read from the update port. | proven |
| [`fwupd_parse_name_checksum`](../../src/leon2m/fwupd/fwupd_parse_name_checksum.c) | `FUN_a0147d0c` | Read the four checksum digits that end a file name. | derived |
| [`fwupd_port_reset_control`](../../src/leon2m/fwupd/fwupd_port_reset_control.c) | `FUN_a0123654` | Set bit 0 and then clear bit 1 of the update port's control register. | descriptive |
| [`fwupd_port_run_sequence`](../../src/leon2m/fwupd/fwupd_port_run_sequence.c) | `FUN_a0123744` | Run the start sequence of the update port and wait for it to finish. | descriptive |
| [`fwupd_port_send_cmd_0x31`](../../src/leon2m/fwupd/fwupd_port_send_cmd_0x31.c) | `FUN_a012367c` | Write a 32-bit value to the update port and start command 0x31. | descriptive |
| [`fwupd_port_send_cmd_0x70`](../../src/leon2m/fwupd/fwupd_port_send_cmd_0x70.c) | `FUN_a01236e8` | Write the mode to the update port, start command 0x70, then write 7 or 0xF to two registers. | descriptive |
| [`fwupd_port_wait_ready`](../../src/leon2m/fwupd/fwupd_port_wait_ready.c) | `FUN_a0123840` | Wait, with a time limit, until one of the two update ports reports ready. | derived |
| [`fwupd_query_progress_percent`](../../src/leon2m/fwupd/fwupd_query_progress_percent.c) | `FUN_a002f96c` | Return fwupd_get_progress_percent() as an int. | derived |
| [`fwupd_read_file_name`](../../src/leon2m/fwupd/fwupd_read_file_name.c) | `FUN_a01238e8` | Read the name of the offered file from the update port and print it. | derived |
| [`fwupd_run_progress_loop`](../../src/leon2m/fwupd/fwupd_run_progress_loop.c) | `FUN_a002f118` | Mask all interrupts, wait for the 8051 transfer to start, then report its progress forever. | derived |
| [`fwupd_set_progress_hook`](../../src/leon2m/fwupd/fwupd_set_progress_hook.c) | `FUN_a0123648` | Store the routine that the update progress loop calls on every percent change. | derived |
| [`fwupd_verify_file_checksum`](../../src/leon2m/fwupd/fwupd_verify_file_checksum.c) | `FUN_a0147d70` | Compare the checksum in a file's name with the sum of its data. | proven |

<a id="power"></a>
## Power states

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`APPOnSystemAfterNvramInit`](../../src/leon2m/power/APPOnSystemAfterNvramInit.c) | `FUN_a0083b60` | Print the power-on type; set two GPIO port 4 pins unless type 4, or type 3 woken by the power key. | proven |
| [`APPSetPowerOff`](../../src/leon2m/power/APPSetPowerOff.c) | `FUN_a0080490` | Run the power-off sequence: off sensing, pin sequence and panel off. | proven |
| [`power_api_get_wake_up_port`](../../src/leon2m/power/power_api_get_wake_up_port.c) | `FUN_a0148974` | Return the input port that woke the monitor, or 0xFF. | derived |
| [`power_api_is_woken_by_power_key`](../../src/leon2m/power/power_api_is_woken_by_power_key.c) | `FUN_a0148a24` | Return whether the power key woke the monitor, and prepare two output pins if so. | proven |
| [`power_core_sleep_sequence`](../../src/leon2m/power/power_core_sleep_sequence.c) | `FUN_a00de65c` | Write the two core registers that precede power saving or power off. | derived |
| [`power_core_sleep_sequence_alt`](../../src/leon2m/power/power_core_sleep_sequence_alt.c) | `FUN_a00de604` | Write two core registers with short waits in between. | descriptive |
| [`power_enter_app_state`](../../src/leon2m/power/power_enter_app_state.c) | `FUN_a0081ea8` | Enter application power state 0..5 (on/off, power on, power saving) | proven |
| `power_enter_app_state_jump_table` | `switchdataD_a00801ec` | Jump table 1 of the switch statements in power_enter_app_state. | proven |
| [`power_escape_fake_sleep`](../../src/leon2m/power/power_escape_fake_sleep.c) | `FUN_a0080978` | Leave the suspend and fake-sleep states and restore the power and LED outputs. | proven |
| [`power_prepare_standby_pins`](../../src/leon2m/power/power_prepare_standby_pins.c) | `FUN_a0124fd0` | Enable the 8051 DDC slave (address 0xA8) for two port masks, drive two pins low, set eight to input. | derived |
| [`power_read_wake_status`](../../src/leon2m/power/power_read_wake_status.c) | `FUN_a00de9f8` | Read one of the sixteen wake-up status registers. | derived |
| `power_read_wake_status_jump_table` | `switchdataD_a00de4fc` | Jump table 1 of the switch statements in power_read_wake_status. | proven |
| [`SYSAPI_GetPowerOnType`](../../src/leon2m/power/SYSAPI_GetPowerOnType.c) | `FUN_a0148868` | Return why the monitor started (power-on type). | proven |
| `SYSAPI_GetPowerOnType_jump_table` | `switchdataD_a0143450` | Jump table 1 of the switch statements in SYSAPI_GetPowerOnType. | proven |
| [`SYSAPI_PowerOff`](../../src/leon2m/power/SYSAPI_PowerOff.c) | `FUN_a002f8d8` | Shut the system down: stop the units, interrupts and outputs in order. | proven |
| [`SYSAPI_PowerSaving`](../../src/leon2m/power/SYSAPI_PowerSaving.c) | `FUN_a01451fc` | Put the monitor into power saving: panel off, outputs and blocks shut down. | proven |
| [`SYSAPI_SetPowerStatus`](../../src/leon2m/power/SYSAPI_SetPowerStatus.c) | `FUN_a0148aa8` | Store the power status bit and save the settings record. | proven |
| [`Vx1RxPowerOff`](../../src/leon2m/power/Vx1RxPowerOff.c) | `FUN_a0123384` | Switch the V-by-One receiver off. | proven |

<a id="gpio"></a>
## Pins

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`gpio_api_set_pin_function`](../../src/leon2m/gpio/gpio_api_set_pin_function.c) | `FUN_a014dc74` | Switch one of four fixed pins to its special function or back. | descriptive |
| [`gpio_get_port2_bit0_as_flag2`](../../src/leon2m/gpio/gpio_get_port2_bit0_as_flag2.c) | `FUN_a0124220` | Return 2 when pin 0 of GPIO port 2 reads high, else 0. | descriptive |
| [`gpio_get_port_8051_address`](../../src/leon2m/gpio/gpio_get_port_8051_address.c) | `FUN_a00de444` | Return the 8051 address 0xF000..0xF303 of GPIO port 1..17. | descriptive |
| `gpio_get_port_8051_address_jump_table` | `switchdataD_a00ddd70` | Jump table 1 of the switch statements in gpio_get_port_8051_address. | proven |
| [`gpio_init_adc_and_pin_groups`](../../src/leon2m/gpio/gpio_init_adc_and_pin_groups.c) | `FUN_a00dd904` | Set up the analogue key measurement and the two pin group registers. | descriptive |
| [`gpio_is_aux_bit0_high`](../../src/leon2m/gpio/gpio_is_aux_bit0_high.c) | `FUN_a0124a40` | Read pin 0 of GPIO port number 0xFF; gpio_read_pin answers 0 for that port, so the result is 0. | descriptive |
| [`gpio_is_aux_bit0_high_copy`](../../src/leon2m/gpio/gpio_is_aux_bit0_high_copy.c) | `FUN_a0125b6c` | Read pin 0 of GPIO port number 0xFF; gpio_read_pin answers 0 for that port, so the result is 0. | descriptive |
| [`gpio_is_port2_bit0_high`](../../src/leon2m/gpio/gpio_is_port2_bit0_high.c) | `FUN_a0125b94` | Return whether pin 0 of GPIO port 2 reads high. | descriptive |
| [`gpio_is_port2_bit2_high`](../../src/leon2m/gpio/gpio_is_port2_bit2_high.c) | `FUN_a0125ae4` | Return whether pin 2 of GPIO port 2 reads high. | descriptive |
| [`gpio_is_port2_bit3_high`](../../src/leon2m/gpio/gpio_is_port2_bit3_high.c) | `FUN_a0125b44` | Return whether pin 3 of GPIO port 2 reads high. | descriptive |
| [`gpio_is_port7_bit3_high`](../../src/leon2m/gpio/gpio_is_port7_bit3_high.c) | `FUN_a0125a60` | Return whether pin 3 of GPIO port 7 reads high. | descriptive |
| [`gpio_is_port9_bit4_high`](../../src/leon2m/gpio/gpio_is_port9_bit4_high.c) | `FUN_a012493c` | Return whether pin 4 of GPIO port 9 reads high. | descriptive |
| [`gpio_is_port10_bit2_high`](../../src/leon2m/gpio/gpio_is_port10_bit2_high.c) | `FUN_a0124964` | Return whether pin 2 of GPIO port 10 reads high. | descriptive |
| [`gpio_is_port11_bit1_low`](../../src/leon2m/gpio/gpio_is_port11_bit1_low.c) | `FUN_a0125a88` | Return whether pin 1 of GPIO port 11 reads low. | descriptive |
| [`gpio_is_port13_bit4_high`](../../src/leon2m/gpio/gpio_is_port13_bit4_high.c) | `FUN_a0125e38` | Return whether pin 4 of GPIO port 13 reads high. | descriptive |
| [`gpio_is_port13_bit5_high`](../../src/leon2m/gpio/gpio_is_port13_bit5_high.c) | `FUN_a0124828` | Return whether pin 5 of GPIO port 13 reads high. | descriptive |
| [`gpio_is_port13_bit7_low`](../../src/leon2m/gpio/gpio_is_port13_bit7_low.c) | `FUN_a01248f0` | Return whether pin 7 of GPIO port 13 reads low. | descriptive |
| [`gpio_map_index_to_8051_address`](../../src/leon2m/gpio/gpio_map_index_to_8051_address.c) | `FUN_a00ddbe0` | Convert an index 1..8 to an 8051 register address. | descriptive |
| `gpio_map_index_to_8051_address_jump_table` | `switchdataD_a00dd8e0` | Jump table 1 of the switch statements in gpio_map_index_to_8051_address. | proven |
| [`gpio_pulse_port7_bit7`](../../src/leon2m/gpio/gpio_pulse_port7_bit7.c) | `FUN_a01259f4` | Write pin 7 of GPIO port 7 high, wait 201 ticks, then write it low. | descriptive |
| [`gpio_read_adc_channel`](../../src/leon2m/gpio/gpio_read_adc_channel.c) | `FUN_a00ddae4` | Read one of the ten analogue measurement channels. | derived |
| [`gpio_read_adc_channel_15`](../../src/leon2m/gpio/gpio_read_adc_channel_15.c) | `FUN_a0125c54` | Ask gpio_read_adc_channel for channel 0x0F, which it does not serve: the result is always 0xFF. | descriptive |
| `gpio_read_adc_channel_jump_table` | `switchdataD_a00dd8b4` | Jump table 1 of the switch statements in gpio_read_adc_channel. | proven |
| [`gpio_read_pin`](../../src/leon2m/gpio/gpio_read_pin.c) | `FUN_a002cd38` | Return 1 when any pin of mask on GPIO port 1..17 reads high. | proven |
| `gpio_read_pin_jump_table` | `switchdataD_a002c824` | Jump table 1 of the switch statements in gpio_read_pin. | proven |
| [`gpio_read_port_data`](../../src/leon2m/gpio/gpio_read_port_data.c) | `FUN_a00ddf24` | Read the data byte of one of the 17 GPIO ports. | derived |
| `gpio_read_port_data_jump_table` | `switchdataD_a00ddc98` | Jump table 1 of the switch statements in gpio_read_port_data. | proven |
| [`gpio_select_pwm_group_pins`](../../src/leon2m/gpio/gpio_select_pwm_group_pins.c) | `FUN_a0111088` | Switch the pins of the selected PWM groups to function 8. | descriptive |
| [`gpio_set_aux_bit0_high`](../../src/leon2m/gpio/gpio_set_aux_bit0_high.c) | `FUN_a01249ec` | Ask for pin 0 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit0_high_copy`](../../src/leon2m/gpio/gpio_set_aux_bit0_high_copy.c) | `FUN_a0125e00` | Ask for pin 0 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit0_low`](../../src/leon2m/gpio/gpio_set_aux_bit0_low.c) | `FUN_a0124a08` | Ask for pin 0 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit0_low_copy`](../../src/leon2m/gpio/gpio_set_aux_bit0_low_copy.c) | `FUN_a0124a24` | Ask for pin 0 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit0_low_copy2`](../../src/leon2m/gpio/gpio_set_aux_bit0_low_copy2.c) | `FUN_a0125e1c` | Ask for pin 0 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit1_high`](../../src/leon2m/gpio/gpio_set_aux_bit1_high.c) | `FUN_a0125bfc` | Ask for pin 1 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit1_low`](../../src/leon2m/gpio/gpio_set_aux_bit1_low.c) | `FUN_a0125c18` | Ask for pin 1 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit1_mode0`](../../src/leon2m/gpio/gpio_set_aux_bit1_mode0.c) | `FUN_a0125b0c` | Pass level 0x00 for pin 1 of GPIO port number 0xFF; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit1_mode_ff`](../../src/leon2m/gpio/gpio_set_aux_bit1_mode_ff.c) | `FUN_a0125b28` | Pass level 0xFF for pin 1 of GPIO port number 0xFF; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit2_high`](../../src/leon2m/gpio/gpio_set_aux_bit2_high.c) | `FUN_a0125d58` | Ask for pin 2 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit2_high_copy`](../../src/leon2m/gpio/gpio_set_aux_bit2_high_copy.c) | `FUN_a0124eec` | Ask for pin 2 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit2_low`](../../src/leon2m/gpio/gpio_set_aux_bit2_low.c) | `FUN_a0125d74` | Ask for pin 2 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit2_low_copy`](../../src/leon2m/gpio/gpio_set_aux_bit2_low_copy.c) | `FUN_a0124f08` | Ask for pin 2 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit3_pattern`](../../src/leon2m/gpio/gpio_set_aux_bit3_pattern.c) | `FUN_a0125cb4` | Ask for two writes to pin 3 of GPIO port number 0xFF by mode 0..3; no pin changes (ports 1..17). | descriptive |
| [`gpio_set_aux_bit5_high`](../../src/leon2m/gpio/gpio_set_aux_bit5_high.c) | `FUN_a0125bc4` | Ask for pin 5 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit5_low`](../../src/leon2m/gpio/gpio_set_aux_bit5_low.c) | `FUN_a0125be0` | Ask for pin 5 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit6_high`](../../src/leon2m/gpio/gpio_set_aux_bit6_high.c) | `FUN_a0125918` | Ask for pin 6 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit6_low`](../../src/leon2m/gpio/gpio_set_aux_bit6_low.c) | `FUN_a0125934` | Ask for pin 6 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit7_high`](../../src/leon2m/gpio/gpio_set_aux_bit7_high.c) | `FUN_a0125d90` | Ask for pin 7 of GPIO port number 0xFF to go high; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_aux_bit7_low`](../../src/leon2m/gpio/gpio_set_aux_bit7_low.c) | `FUN_a0125dac` | Ask for pin 7 of GPIO port number 0xFF to go low; no pin changes (gpio_write_pin: ports 1..17). | descriptive |
| [`gpio_set_drive_field`](../../src/leon2m/gpio/gpio_set_drive_field.c) | `FUN_a010031c` | Write a 3-bit field of one of two pin drive registers. | descriptive |
| [`gpio_set_pin_function`](../../src/leon2m/gpio/gpio_set_pin_function.c) | `FUN_a00fe880` | Set the function of one pin of a pin group. | proven |
| `gpio_set_pin_function_jump_table` | `switchdataD_a00fd510` | Jump table 1 of the switch statements in gpio_set_pin_function. | proven |
| [`gpio_set_pin_input`](../../src/leon2m/gpio/gpio_set_pin_input.c) | `FUN_a002cb30` | Release the pins of mask on GPIO port 1..17 (on = 1) or drive them (on = 0) | proven |
| `gpio_set_pin_input_jump_table` | `switchdataD_a002c794` | Jump table 1 of the switch statements in gpio_set_pin_input. | proven |
| `gpio_set_pin_input_jump_table2` | `switchdataD_a002c7dc` | Jump table 2 of the switch statements in gpio_set_pin_input. | proven |
| [`gpio_set_port2_bit2_high`](../../src/leon2m/gpio/gpio_set_port2_bit2_high.c) | `FUN_a0125aac` | Drive pin 2 of GPIO port 2 high. | descriptive |
| [`gpio_set_port2_bit2_low`](../../src/leon2m/gpio/gpio_set_port2_bit2_low.c) | `FUN_a0125ac8` | Drive pin 2 of GPIO port 2 low. | descriptive |
| [`gpio_set_port4_bit4_high_if_allowed`](../../src/leon2m/gpio/gpio_set_port4_bit4_high_if_allowed.c) | `FUN_a0124af8` | Drive pin 4 of GPIO port 4 high when the mode byte or the OLED power state allows it. | descriptive |
| [`gpio_set_port4_bit4_low_if_allowed`](../../src/leon2m/gpio/gpio_set_port4_bit4_low_if_allowed.c) | `FUN_a0124b40` | Drive pin 4 of GPIO port 4 low when the mode byte or the OLED power state allows it. | descriptive |
| [`gpio_set_port4_bit7_high_if_allowed`](../../src/leon2m/gpio/gpio_set_port4_bit7_high_if_allowed.c) | `FUN_a0124a68` | Drive pin 7 of GPIO port 4 high when the mode byte or the OLED power state allows it. | descriptive |
| [`gpio_set_port4_bit7_low_if_allowed`](../../src/leon2m/gpio/gpio_set_port4_bit7_low_if_allowed.c) | `FUN_a0124ab0` | Drive pin 7 of GPIO port 4 low when the mode byte or the OLED power state allows it. | descriptive |
| [`gpio_set_port5_bit0`](../../src/leon2m/gpio/gpio_set_port5_bit0.c) | `FUN_a0125a2c` | Drive pin 0 of GPIO port 5 high for a non-zero argument, else low. | descriptive |
| [`gpio_set_port5_bit7_high`](../../src/leon2m/gpio/gpio_set_port5_bit7_high.c) | `FUN_a0125988` | Drive pin 7 of GPIO port 5 high. | descriptive |
| [`gpio_set_port5_bit7_low`](../../src/leon2m/gpio/gpio_set_port5_bit7_low.c) | `FUN_a01259a4` | Drive pin 7 of GPIO port 5 low. | descriptive |
| [`gpio_set_port6_bit2_high`](../../src/leon2m/gpio/gpio_set_port6_bit2_high.c) | `FUN_a012587c` | Drive pin 2 of GPIO port 6 high. | descriptive |
| [`gpio_set_port6_bit2_high_copy`](../../src/leon2m/gpio/gpio_set_port6_bit2_high_copy.c) | `FUN_a0125898` | Drive pin 2 of GPIO port 6 high (second copy). | descriptive |
| [`gpio_set_port6_bit2_low`](../../src/leon2m/gpio/gpio_set_port6_bit2_low.c) | `FUN_a01258b4` | Drive pin 2 of GPIO port 6 low. | descriptive |
| [`gpio_set_port7_bit1_high`](../../src/leon2m/gpio/gpio_set_port7_bit1_high.c) | `FUN_a01258d0` | Drive pin 1 of GPIO port 7 high. | descriptive |
| [`gpio_set_port7_bit1_low`](../../src/leon2m/gpio/gpio_set_port7_bit1_low.c) | `FUN_a01258ec` | Drive pin 1 of GPIO port 7 low. | descriptive |
| [`gpio_set_port7_bit2_high`](../../src/leon2m/gpio/gpio_set_port7_bit2_high.c) | `FUN_a0125950` | Drive pin 2 of GPIO port 7 high. | descriptive |
| [`gpio_set_port7_bit2_low`](../../src/leon2m/gpio/gpio_set_port7_bit2_low.c) | `FUN_a012596c` | Drive pin 2 of GPIO port 7 low. | descriptive |
| [`gpio_set_port7_bit7_inverted`](../../src/leon2m/gpio/gpio_set_port7_bit7_inverted.c) | `FUN_a01259c0` | Drive pin 7 of GPIO port 7 low for a non-zero argument, else release it high. | descriptive |
| [`gpio_set_port12_bit0_high`](../../src/leon2m/gpio/gpio_set_port12_bit0_high.c) | `FUN_a0125dc8` | Drive pin 0 of GPIO port 12 high. | descriptive |
| [`gpio_set_port12_bit0_low`](../../src/leon2m/gpio/gpio_set_port12_bit0_low.c) | `FUN_a0125de4` | Drive pin 0 of GPIO port 12 low. | descriptive |
| [`gpio_set_port13_bit6_high`](../../src/leon2m/gpio/gpio_set_port13_bit6_high.c) | `FUN_a01249b4` | Drive pin 6 of GPIO port 13 high. | descriptive |
| [`gpio_set_port13_bit6_low`](../../src/leon2m/gpio/gpio_set_port13_bit6_low.c) | `FUN_a01249d0` | Drive pin 6 of GPIO port 13 low. | descriptive |
| [`gpio_set_pwm_group_divider`](../../src/leon2m/gpio/gpio_set_pwm_group_divider.c) | `FUN_a0111028` | Enable the PWM group and program its divider. | descriptive |
| [`gpio_setup_pin`](../../src/leon2m/gpio/gpio_setup_pin.c) | `FUN_a0107bac` | Set up the function and direction of one pin. | derived |
| [`gpio_setup_pwm_group_pins`](../../src/leon2m/gpio/gpio_setup_pwm_group_pins.c) | `FUN_a014dc28` | Program the PWM divider and switch the pins of the selected groups to it. | descriptive |
| [`gpio_user_set_led_by_state`](../../src/leon2m/gpio/gpio_user_set_led_by_state.c) | `FUN_a00d99a8` | Call one of two empty routines, chosen by the OLED power state, its step and settings bit 5. | descriptive |
| [`gpio_user_set_port2_bit2`](../../src/leon2m/gpio/gpio_user_set_port2_bit2.c) | `FUN_a00d9978` | Drive pin 2 of GPIO port 2 as settings bit 6 says. | descriptive |
| [`gpio_user_set_port7_bit1`](../../src/leon2m/gpio/gpio_user_set_port7_bit1.c) | `FUN_a00db12c` | Drive pin 1 of GPIO port 7 by a settings bit and an override. | descriptive |
| [`gpio_write_adc_fixed_setup`](../../src/leon2m/gpio/gpio_write_adc_fixed_setup.c) | `FUN_a00dda4c` | Write the fixed values of the analogue measurement block. | descriptive |
| [`gpio_write_pin`](../../src/leon2m/gpio/gpio_write_pin.c) | `FUN_a002c86c` | Drive the pins of mask on GPIO port 1..17 to level. | proven |
| `gpio_write_pin_jump_table` | `switchdataD_a002c704` | Jump table 1 of the switch statements in gpio_write_pin. | proven |
| `gpio_write_pin_jump_table2` | `switchdataD_a002c74c` | Jump table 2 of the switch statements in gpio_write_pin. | proven |
| [`gpio_write_port_config_pair`](../../src/leon2m/gpio/gpio_write_port_config_pair.c) | `FUN_a00de1fc` | Write two configuration bytes of one of the 17 GPIO ports. | descriptive |
| `gpio_write_port_config_pair_jump_table` | `switchdataD_a00ddd28` | Jump table 1 of the switch statements in gpio_write_port_config_pair. | proven |
| [`gpio_write_port_data`](../../src/leon2m/gpio/gpio_write_port_data.c) | `FUN_a00dddb8` | Write the data byte of one of the 17 GPIO ports. | derived |
| `gpio_write_port_data_jump_table` | `switchdataD_a00ddc50` | Jump table 1 of the switch statements in gpio_write_port_data. | proven |
| [`gpio_write_port_direction`](../../src/leon2m/gpio/gpio_write_port_direction.c) | `FUN_a00de088` | Write the direction byte of one of the 17 GPIO ports. | descriptive |
| `gpio_write_port_direction_jump_table` | `switchdataD_a00ddce0` | Jump table 1 of the switch statements in gpio_write_port_direction. | proven |

<a id="i2c"></a>
## I2C

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`i2c_api_read_block`](../../src/leon2m/i2c/i2c_api_read_block.c) | `FUN_a0147ae8` | Read a block from a device on the software I2C bus. | derived |
| [`i2c_api_write_block`](../../src/leon2m/i2c/i2c_api_write_block.c) | `FUN_a0147aa0` | Write a block to a device on the software I2C bus. | derived |
| [`i2c_api_write_read`](../../src/leon2m/i2c/i2c_api_write_read.c) | `FUN_a0147b70` | Write, then read, in one transfer with a device on the software I2C bus. | derived |
| [`i2c_api_write_two_buffers`](../../src/leon2m/i2c/i2c_api_write_two_buffers.c) | `FUN_a0147b28` | Write two buffers in one transfer to a device on the software I2C bus. | derived |
| [`i2c_bus0_read_block`](../../src/leon2m/i2c/i2c_bus0_read_block.c) | `FUN_a01256d0` | Read a block from a device on software I2C bus 0. | derived |
| [`i2c_bus0_write_block`](../../src/leon2m/i2c/i2c_bus0_write_block.c) | `FUN_a0125644` | Write a block to a device on software I2C bus 0. | derived |
| [`i2c_bus0_write_read`](../../src/leon2m/i2c/i2c_bus0_write_read.c) | `FUN_a01257f0` | Write, then read, in one transfer with a device on software I2C bus 0. | derived |
| [`i2c_bus0_write_two_buffers`](../../src/leon2m/i2c/i2c_bus0_write_two_buffers.c) | `FUN_a0125754` | Write two buffers in one transfer to a device on software I2C bus 0. | derived |
| [`i2c_gpio_probe_device`](../../src/leon2m/i2c/i2c_gpio_probe_device.c) | `FUN_a002be7c` | Return 1 when device dev acknowledges its address on the software I2C bus. | proven |
| [`i2c_gpio_read_block`](../../src/leon2m/i2c/i2c_gpio_read_block.c) | `FUN_a002bb28` | Read len bytes at addr of an I2C device (e.g. the settings EEPROM) over software I2C. | proven |
| [`i2c_gpio_read_byte`](../../src/leon2m/i2c/i2c_gpio_read_byte.c) | `FUN_a002ae4c` | Read one byte over software I2C and answer ACK, or NACK when last is set. | proven |
| [`i2c_gpio_send_byte`](../../src/leon2m/i2c/i2c_gpio_send_byte.c) | `FUN_a002ab04` | Send one byte MSB first over software I2C and return whether the receiver acknowledged. | proven |
| [`i2c_gpio_start`](../../src/leon2m/i2c/i2c_gpio_start.c) | `FUN_a002a910` | Send a software-I2C START, clocking the bus free when SDA is stuck low. | proven |
| [`i2c_gpio_write_block`](../../src/leon2m/i2c/i2c_gpio_write_block.c) | `FUN_a002b3e4` | Write len bytes at addr of an I2C device (e.g. the settings EEPROM) over software I2C. | proven |
| [`i2c_gpio_write_read`](../../src/leon2m/i2c/i2c_gpio_write_read.c) | `FUN_a002b758` | Write wbuf, then read rlen bytes into rbuf over software I2C. | proven |
| [`i2c_gpio_write_two_buffers`](../../src/leon2m/i2c/i2c_gpio_write_two_buffers.c) | `FUN_a002b058` | Write the device byte, then buf1 and buf2 over software I2C with retries. | proven |

<a id="uart"></a>
## Serial ports

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`uart_api_read_rx_ring`](../../src/leon2m/uart/uart_api_read_rx_ring.c) | `FUN_a01487cc` | Read received bytes of a serial port from its ring buffer. | derived |
| [`uart_api_send_bytes`](../../src/leon2m/uart/uart_api_send_bytes.c) | `FUN_a01487e8` | Queue bytes for sending on one of the 8051's serial ports. | derived |
| [`uart_cmd_accept_code440`](../../src/leon2m/uart/uart_cmd_accept_code440.c) | `FUN_a00c0ff4` | Acknowledge command 5b00440 when its value is 0 or 1, storing nothing. | descriptive |
| [`uart_cmd_adjust_pbp_split`](../../src/leon2m/uart/uart_cmd_adjust_pbp_split.c) | `FUN_a00c9980` | Accept, open or move the PBP custom split on a PC tool command. | derived |
| [`uart_cmd_answer_panel_protect`](../../src/leon2m/uart/uart_cmd_answer_panel_protect.c) | `FUN_a00caf0c` | Answer the OLED Panel Protect prompt on behalf of the user (PC tool command) | derived |
| [`uart_cmd_build_checksum_error_reply`](../../src/leon2m/uart/uart_cmd_build_checksum_error_reply.c) | `FUN_a00bac04` | Put the '5600' + 0xEE reply (data check failed) into the reply frame. | derived |
| [`uart_cmd_build_get_reply`](../../src/leon2m/uart/uart_cmd_build_get_reply.c) | `FUN_a00bac3c` | Fill the reply frame header for a get command from its command row. | proven |
| [`uart_cmd_build_get_reply_copy`](../../src/leon2m/uart/uart_cmd_build_get_reply_copy.c) | `FUN_a00bacc4` | Fill the reply frame header for a get command from its command row. | proven |
| [`uart_cmd_build_ok_reply`](../../src/leon2m/uart/uart_cmd_build_ok_reply.c) | `FUN_a00baa6c` | Put the '5600+' acknowledge into a port's transmit buffer. | proven |
| [`uart_cmd_build_ok_reply_port2`](../../src/leon2m/uart/uart_cmd_build_ok_reply_port2.c) | `FUN_a00bb4e8` | Put the '5600+' acknowledge into the port 2 reply frame. | derived |
| [`uart_cmd_check_data_block`](../../src/leon2m/uart/uart_cmd_check_data_block.c) | `FUN_a00cbe9c` | Check the byte sum of a 12-byte data block from the PC tool and acknowledge it. | descriptive |
| [`uart_cmd_clear_rx`](../../src/leon2m/uart/uart_cmd_clear_rx.c) | `FUN_a00ba950` | Clear the receive state and receive record of a tool command port. | derived |
| [`uart_cmd_clear_rx_port2`](../../src/leon2m/uart/uart_cmd_clear_rx_port2.c) | `FUN_a00bb414` | Clear the receive state byte and the whole receive record of command port 2. | derived |
| [`uart_cmd_dispatch_get`](../../src/leon2m/uart/uart_cmd_dispatch_get.c) | `FUN_a00bfcc4` | Answer a get command from the PC tool by its command row. | proven |
| `uart_cmd_dispatch_get_jump_table` | `switchdataD_a00ba428` | Jump table 1 of the switch statements in uart_cmd_dispatch_get. | proven |
| [`uart_cmd_dispatch_set`](../../src/leon2m/uart/uart_cmd_dispatch_set.c) | `FUN_a00ccf34` | Carry out a set command from the PC tool by its command row. | proven |
| `uart_cmd_dispatch_set_jump_table` | `switchdataD_a00ba654` | Jump table 1 of the switch statements in uart_cmd_dispatch_set. | proven |
| [`uart_cmd_enable_port_signals`](../../src/leon2m/uart/uart_cmd_enable_port_signals.c) | `FUN_a00cbe2c` | Switch the signal of all input ports on and acknowledge the PC tool. | descriptive |
| [`uart_cmd_enable_port_signals_copy`](../../src/leon2m/uart/uart_cmd_enable_port_signals_copy.c) | `FUN_a00cbe64` | Switch the signal of all input ports on and acknowledge the PC tool. | descriptive |
| [`uart_cmd_find_get_command`](../../src/leon2m/uart/uart_cmd_find_get_command.c) | `FUN_a00bb1c4` | Return the get command row whose id matches the received frame. | derived |
| [`uart_cmd_find_get_command_port2`](../../src/leon2m/uart/uart_cmd_find_get_command_port2.c) | `FUN_a00bb86c` | Return the get command row matching the frame received on port 2. | derived |
| [`uart_cmd_find_set_command`](../../src/leon2m/uart/uart_cmd_find_set_command.c) | `FUN_a00bb260` | Return the set command row whose id matches the received frame. | derived |
| [`uart_cmd_find_set_command_port2`](../../src/leon2m/uart/uart_cmd_find_set_command_port2.c) | `FUN_a00bb908` | Return the set command row matching the frame received on port 2. | derived |
| [`uart_cmd_flush_rx_port2`](../../src/leon2m/uart/uart_cmd_flush_rx_port2.c) | `FUN_a00bb528` | Clear the receive record of command port 2 and report success. | derived |
| [`uart_cmd_get_adaptive_sync`](../../src/leon2m/uart/uart_cmd_get_adaptive_sync.c) | `FUN_a00bce2c` | Report the Adaptive-Sync switch to the PC tool. | derived |
| [`uart_cmd_get_ai_vision`](../../src/leon2m/uart/uart_cmd_get_ai_vision.c) | `FUN_a00be2f0` | Report the AI Vision switch to the PC tool. | proven |
| [`uart_cmd_get_alarm_clock`](../../src/leon2m/uart/uart_cmd_get_alarm_clock.c) | `FUN_a00bcc64` | Report the Alarm Clock timer choice to the PC tool. | proven |
| [`uart_cmd_get_alarm_clock_location`](../../src/leon2m/uart/uart_cmd_get_alarm_clock_location.c) | `FUN_a00bcd54` | Report the Alarm Clock location to the PC tool. | proven |
| [`uart_cmd_get_alarm_slot`](../../src/leon2m/uart/uart_cmd_get_alarm_slot.c) | `FUN_a00bccac` | Report the selected alarm clock timer slot to the PC tool. | derived |
| [`uart_cmd_get_alarm_slot_time`](../../src/leon2m/uart/uart_cmd_get_alarm_slot_time.c) | `FUN_a00bccf4` | Report the time of the selected alarm clock timer to the PC tool. | derived |
| [`uart_cmd_get_auto_level`](../../src/leon2m/uart/uart_cmd_get_auto_level.c) | `FUN_a00bcb80` | Report the automatic level setting to the PC tool. | derived |
| [`uart_cmd_get_blue_gain`](../../src/leon2m/uart/uart_cmd_get_blue_gain.c) | `FUN_a00bc6f0` | Report the custom blue gain to the PC tool. | proven |
| [`uart_cmd_get_blur_free`](../../src/leon2m/uart/uart_cmd_get_blur_free.c) | `FUN_a00bcb38` | Report the blur reduction mode to the PC tool. | derived |
| [`uart_cmd_get_boundary_detection`](../../src/leon2m/uart/uart_cmd_get_boundary_detection.c) | `FUN_a00be744` | Report the Boundary Detection switch to the PC tool. | proven |
| [`uart_cmd_get_boundary_level`](../../src/leon2m/uart/uart_cmd_get_boundary_level.c) | `FUN_a00be78c` | Report the Boundary Detection level to the PC tool. | proven |
| [`uart_cmd_get_brightness`](../../src/leon2m/uart/uart_cmd_get_brightness.c) | `FUN_a00bbda0` | Report the Brightness to the PC tool. | proven |
| [`uart_cmd_get_byte_0x18`](../../src/leon2m/uart/uart_cmd_get_byte_0x18.c) | `FUN_a00bf2d0` | Report the settings byte +0x18 to the PC tool. | descriptive |
| [`uart_cmd_get_byte_0x140`](../../src/leon2m/uart/uart_cmd_get_byte_0x140.c) | `FUN_a00bcaa8` | Report the settings byte +0x140 to the PC tool. | descriptive |
| [`uart_cmd_get_byte_0x177`](../../src/leon2m/uart/uart_cmd_get_byte_0x177.c) | `FUN_a00be1c0` | Report the settings byte +0x177 to the PC tool. | descriptive |
| [`uart_cmd_get_color_gains`](../../src/leon2m/uart/uart_cmd_get_color_gains.c) | `FUN_a00bc86c` | Report the custom red, green and blue gains to the PC tool. | proven |
| [`uart_cmd_get_color_temperature`](../../src/leon2m/uart/uart_cmd_get_color_temperature.c) | `FUN_a00bc3b0` | Report the Color Temperature to the PC tool. | proven |
| [`uart_cmd_get_color_values`](../../src/leon2m/uart/uart_cmd_get_color_values.c) | `FUN_a00bfb28` | Report the picture mode colour values to the PC tool with a checksum. | derived |
| [`uart_cmd_get_contrast`](../../src/leon2m/uart/uart_cmd_get_contrast.c) | `FUN_a00bbf1c` | Report the Contrast to the PC tool. | proven |
| [`uart_cmd_get_crosshair_color`](../../src/leon2m/uart/uart_cmd_get_crosshair_color.c) | `FUN_a00bcde4` | Report the Smart Crosshair colour to the PC tool. | proven |
| [`uart_cmd_get_crosshair_icon`](../../src/leon2m/uart/uart_cmd_get_crosshair_icon.c) | `FUN_a00bcd9c` | Report the Smart Crosshair icon to the PC tool. | proven |
| [`uart_cmd_get_display_hdr`](../../src/leon2m/uart/uart_cmd_get_display_hdr.c) | `FUN_a00be250` | Report the DisplayHDR setting to the PC tool. | proven |
| [`uart_cmd_get_dsc`](../../src/leon2m/uart/uart_cmd_get_dsc.c) | `FUN_a00be340` | Report the DSC switch to the PC tool. | proven |
| [`uart_cmd_get_firmware_version`](../../src/leon2m/uart/uart_cmd_get_firmware_version.c) | `FUN_a00bc214` | Report the firmware version to the PC tool. | proven |
| [`uart_cmd_get_fixed_code`](../../src/leon2m/uart/uart_cmd_get_fixed_code.c) | `FUN_a00bdb48` | Report the fixed code '00' + 0x9F for command 5800140 to the PC tool. | descriptive |
| [`uart_cmd_get_fixed_one`](../../src/leon2m/uart/uart_cmd_get_fixed_one.c) | `FUN_a00bc914` | Report the fixed value 001 for command 5800415 to the PC tool. | descriptive |
| [`uart_cmd_get_fixed_status`](../../src/leon2m/uart/uart_cmd_get_fixed_status.c) | `FUN_a00bdec0` | Send the fixed reply frame '5b00\00011' for command 580\ to the PC tool. | descriptive |
| [`uart_cmd_get_game_mode`](../../src/leon2m/uart/uart_cmd_get_game_mode.c) | `FUN_a00bc95c` | Report the Game Mode to the PC tool. | proven |
| [`uart_cmd_get_green_gain`](../../src/leon2m/uart/uart_cmd_get_green_gain.c) | `FUN_a00bc574` | Report the custom green gain to the PC tool. | proven |
| [`uart_cmd_get_hdmi_cec`](../../src/leon2m/uart/uart_cmd_get_hdmi_cec.c) | `FUN_a00be140` | Report the HDMI CEC switch to the PC tool. | proven |
| [`uart_cmd_get_hdr_state`](../../src/leon2m/uart/uart_cmd_get_hdr_state.c) | `FUN_a00bf6b0` | Report the HDR state to the PC tool. | derived |
| [`uart_cmd_get_hundreds_digit`](../../src/leon2m/uart/uart_cmd_get_hundreds_digit.c) | `FUN_a00c0adc` | Return the hundreds digit of the value in a received set command. | derived |
| [`uart_cmd_get_image_enhancement`](../../src/leon2m/uart/uart_cmd_get_image_enhancement.c) | `FUN_a00bd294` | Report the Image Enhancement level to the PC tool. | proven |
| [`uart_cmd_get_info_on_screen`](../../src/leon2m/uart/uart_cmd_get_info_on_screen.c) | `FUN_a00be0f0` | Report the Info. On Screen switch to the PC tool. | proven |
| [`uart_cmd_get_input_source`](../../src/leon2m/uart/uart_cmd_get_input_source.c) | `FUN_a00bef90` | Report the Input Source to the PC tool. | proven |
| [`uart_cmd_get_kvm`](../../src/leon2m/uart/uart_cmd_get_kvm.c) | `FUN_a00be208` | Report the KVM setting to the PC tool. | proven |
| [`uart_cmd_get_language`](../../src/leon2m/uart/uart_cmd_get_language.c) | `FUN_a00bc8c4` | Report the menu Language to the PC tool. | proven |
| [`uart_cmd_get_low_blue_light`](../../src/leon2m/uart/uart_cmd_get_low_blue_light.c) | `FUN_a00bd244` | Report the Low Blue Light switch to the PC tool. | proven |
| [`uart_cmd_get_multi_logo_detection`](../../src/leon2m/uart/uart_cmd_get_multi_logo_detection.c) | `FUN_a00be624` | Report the Multi Logo Detection switch to the PC tool. | proven |
| [`uart_cmd_get_multi_logo_level`](../../src/leon2m/uart/uart_cmd_get_multi_logo_level.c) | `FUN_a00be66c` | Report the Multi Logo Detection level to the PC tool. | proven |
| [`uart_cmd_get_navi_key_down`](../../src/leon2m/uart/uart_cmd_get_navi_key_down.c) | `FUN_a00bd520` | Report the Navi Key down function to the PC tool. | proven |
| [`uart_cmd_get_navi_key_left`](../../src/leon2m/uart/uart_cmd_get_navi_key_left.c) | `FUN_a00bd59c` | Report the Navi Key left function to the PC tool. | proven |
| [`uart_cmd_get_navi_key_right`](../../src/leon2m/uart/uart_cmd_get_navi_key_right.c) | `FUN_a00bd6e4` | Report the Navi Key right function to the PC tool. | proven |
| [`uart_cmd_get_navi_key_up`](../../src/leon2m/uart/uart_cmd_get_navi_key_up.c) | `FUN_a00bd4a4` | Report the Navi Key up function to the PC tool. | proven |
| [`uart_cmd_get_night_vision`](../../src/leon2m/uart/uart_cmd_get_night_vision.c) | `FUN_a00bdd48` | Report the Night Vision level to the PC tool. | proven |
| [`uart_cmd_get_optix_scope`](../../src/leon2m/uart/uart_cmd_get_optix_scope.c) | `FUN_a00bdd90` | Report the Optix Scope switch to the PC tool. | proven |
| [`uart_cmd_get_osd_timeout`](../../src/leon2m/uart/uart_cmd_get_osd_timeout.c) | `FUN_a00bd328` | Report the OSD Time out to the PC tool. | proven |
| [`uart_cmd_get_panel_name`](../../src/leon2m/uart/uart_cmd_get_panel_name.c) | `FUN_a00bc258` | Report the panel name to the PC tool. | proven |
| [`uart_cmd_get_panel_protect_answer`](../../src/leon2m/uart/uart_cmd_get_panel_protect_answer.c) | `FUN_a00be5e8` | Report the Panel Protect prompt answer (always 000) to the PC tool. | derived |
| [`uart_cmd_get_panel_protect_bit30`](../../src/leon2m/uart/uart_cmd_get_panel_protect_bit30.c) | `FUN_a00be470` | Report the Panel Protect request bit 30 to the PC tool. | descriptive |
| [`uart_cmd_get_panel_protect_run`](../../src/leon2m/uart/uart_cmd_get_panel_protect_run.c) | `FUN_a00be424` | Report the Panel Protect run request to the PC tool. | derived |
| [`uart_cmd_get_pbp_mode`](../../src/leon2m/uart/uart_cmd_get_pbp_mode.c) | `FUN_a00bdcb0` | Report the PBP layout to the PC tool. | proven |
| [`uart_cmd_get_pbp_source1`](../../src/leon2m/uart/uart_cmd_get_pbp_source1.c) | `FUN_a00bed38` | Report the first PBP source to the PC tool. | derived |
| [`uart_cmd_get_pbp_source2`](../../src/leon2m/uart/uart_cmd_get_pbp_source2.c) | `FUN_a00bec0c` | Report the second PBP source to the PC tool. | derived |
| [`uart_cmd_get_picture_mode`](../../src/leon2m/uart/uart_cmd_get_picture_mode.c) | `FUN_a00bd760` | Report the picture mode (game or professional mode) to the PC tool. | derived |
| `uart_cmd_get_picture_mode_jump_table` | `switchdataD_a00ba408` | Jump table 1 of the switch statements in uart_cmd_get_picture_mode. | proven |
| [`uart_cmd_get_pip_location`](../../src/leon2m/uart/uart_cmd_get_pip_location.c) | `FUN_a00bdc60` | Report the PIP location to the PC tool. | proven |
| [`uart_cmd_get_pip_pbp_mode`](../../src/leon2m/uart/uart_cmd_get_pip_pbp_mode.c) | `FUN_a00bdbcc` | Report the PIP/PBP mode to the PC tool. | proven |
| [`uart_cmd_get_pip_size`](../../src/leon2m/uart/uart_cmd_get_pip_size.c) | `FUN_a00bdc14` | Report the PIP size to the PC tool. | derived |
| [`uart_cmd_get_pip_source`](../../src/leon2m/uart/uart_cmd_get_pip_source.c) | `FUN_a00bee64` | Report the PIP source to the PC tool. | derived |
| [`uart_cmd_get_pixel_shift`](../../src/leon2m/uart/uart_cmd_get_pixel_shift.c) | `FUN_a00be3dc` | Report the Pixel Shift speed to the PC tool. | proven |
| [`uart_cmd_get_port_status_flag`](../../src/leon2m/uart/uart_cmd_get_port_status_flag.c) | `FUN_a00bf3f8` | Report the input port status flag to the PC tool. | descriptive |
| [`uart_cmd_get_power_button`](../../src/leon2m/uart/uart_cmd_get_power_button.c) | `FUN_a00be0a0` | Report the Power Button setting to the PC tool. | proven |
| [`uart_cmd_get_power_led`](../../src/leon2m/uart/uart_cmd_get_power_led.c) | `FUN_a00be38c` | Report the Power LED switch to the PC tool. | proven |
| [`uart_cmd_get_power_state`](../../src/leon2m/uart/uart_cmd_get_power_state.c) | `FUN_a00be9a8` | Report the power state to the PC tool. | descriptive |
| [`uart_cmd_get_pro_mode`](../../src/leon2m/uart/uart_cmd_get_pro_mode.c) | `FUN_a00bd070` | Report the Professional mode to the PC tool. | proven |
| `uart_cmd_get_pro_mode_jump_table` | `switchdataD_a00ba3e8` | Jump table 1 of the switch statements in uart_cmd_get_pro_mode. | proven |
| [`uart_cmd_get_protect_notice`](../../src/leon2m/uart/uart_cmd_get_protect_notice.c) | `FUN_a00be7d4` | Report the Protect Notice setting to the PC tool. | proven |
| [`uart_cmd_get_red_gain`](../../src/leon2m/uart/uart_cmd_get_red_gain.c) | `FUN_a00bc3f8` | Report the custom red gain to the PC tool. | proven |
| [`uart_cmd_get_refresh_rate`](../../src/leon2m/uart/uart_cmd_get_refresh_rate.c) | `FUN_a00bf538` | Report the current refresh rate to the PC tool. | proven |
| [`uart_cmd_get_refresh_rate_display`](../../src/leon2m/uart/uart_cmd_get_refresh_rate_display.c) | `FUN_a00bcbcc` | Report the Refresh Rate display switch to the PC tool. | proven |
| [`uart_cmd_get_refresh_rate_location`](../../src/leon2m/uart/uart_cmd_get_refresh_rate_location.c) | `FUN_a00bcc1c` | Report the Refresh Rate display location to the PC tool. | proven |
| [`uart_cmd_get_resolution_code`](../../src/leon2m/uart/uart_cmd_get_resolution_code.c) | `FUN_a00bf7dc` | Report the input resolution code to the PC tool. | derived |
| [`uart_cmd_get_response_time`](../../src/leon2m/uart/uart_cmd_get_response_time.c) | `FUN_a00bcaf0` | Report the response time level to the PC tool. | derived |
| [`uart_cmd_get_rgb_brightness`](../../src/leon2m/uart/uart_cmd_get_rgb_brightness.c) | `FUN_a00be81c` | Report the RGB LED brightness to the PC tool. | proven |
| [`uart_cmd_get_rgb_led`](../../src/leon2m/uart/uart_cmd_get_rgb_led.c) | `FUN_a00bdcf8` | Report the RGB LED switch to the PC tool. | derived |
| [`uart_cmd_get_rx_byte`](../../src/leon2m/uart/uart_cmd_get_rx_byte.c) | `FUN_a00bab30` | Return one byte of a port's receive record. | derived |
| [`uart_cmd_get_scope_ratio`](../../src/leon2m/uart/uart_cmd_get_scope_ratio.c) | `FUN_a00bde20` | Report the Optix Scope ratio to the PC tool. | proven |
| [`uart_cmd_get_scope_size`](../../src/leon2m/uart/uart_cmd_get_scope_size.c) | `FUN_a00bddd8` | Report the Optix Scope size to the PC tool. | proven |
| [`uart_cmd_get_screen_size`](../../src/leon2m/uart/uart_cmd_get_screen_size.c) | `FUN_a00bcecc` | Report the Screen Size to the PC tool. | proven |
| [`uart_cmd_get_second_source`](../../src/leon2m/uart/uart_cmd_get_second_source.c) | `FUN_a00beae0` | Report the second picture source to the PC tool. | derived |
| [`uart_cmd_get_serial_number`](../../src/leon2m/uart/uart_cmd_get_serial_number.c) | `FUN_a00bd9d8` | Report the serial number from the factory record to the PC tool in a 21-byte frame. | proven |
| [`uart_cmd_get_serial_number_with_sum`](../../src/leon2m/uart/uart_cmd_get_serial_number_with_sum.c) | `FUN_a00bdf28` | Report the serial number from the factory record and the 8-bit sum of its characters to the PC tool. | proven |
| [`uart_cmd_get_setting_bit9`](../../src/leon2m/uart/uart_cmd_get_setting_bit9.c) | `FUN_a00bde68` | Report the settings bit 9 to the PC tool. | descriptive |
| [`uart_cmd_get_setting_bit13`](../../src/leon2m/uart/uart_cmd_get_setting_bit13.c) | `FUN_a00bce7c` | Report the settings bit 13 of +0xA8 to the PC tool. | descriptive |
| [`uart_cmd_get_setting_bit17`](../../src/leon2m/uart/uart_cmd_get_setting_bit17.c) | `FUN_a00bd988` | Report the settings bit 17 of +0xAC to the PC tool. | descriptive |
| [`uart_cmd_get_sharpness`](../../src/leon2m/uart/uart_cmd_get_sharpness.c) | `FUN_a00bc098` | Report the Sharpness to the PC tool. | proven |
| [`uart_cmd_get_static_screen_detection`](../../src/leon2m/uart/uart_cmd_get_static_screen_detection.c) | `FUN_a00be4c0` | Report the Static Screen Detection switch to the PC tool. | proven |
| [`uart_cmd_get_static_screen_reduce_level`](../../src/leon2m/uart/uart_cmd_get_static_screen_reduce_level.c) | `FUN_a00be558` | Report the Static Screen Detection reduce level to the PC tool. | proven |
| [`uart_cmd_get_static_screen_start_time`](../../src/leon2m/uart/uart_cmd_get_static_screen_start_time.c) | `FUN_a00be510` | Report the Static Screen Detection start time to the PC tool. | proven |
| [`uart_cmd_get_static_screen_time_required`](../../src/leon2m/uart/uart_cmd_get_static_screen_time_required.c) | `FUN_a00be5a0` | Report the Static Screen Detection time required to the PC tool. | proven |
| [`uart_cmd_get_taskbar_detection`](../../src/leon2m/uart/uart_cmd_get_taskbar_detection.c) | `FUN_a00be6b4` | Report the Taskbar Detection switch to the PC tool. | proven |
| [`uart_cmd_get_taskbar_level`](../../src/leon2m/uart/uart_cmd_get_taskbar_level.c) | `FUN_a00be6fc` | Report the Taskbar Detection level to the PC tool. | proven |
| [`uart_cmd_get_tens_digit`](../../src/leon2m/uart/uart_cmd_get_tens_digit.c) | `FUN_a00c0b34` | Return the tens digit of the value in a received set command. | derived |
| [`uart_cmd_get_transparency`](../../src/leon2m/uart/uart_cmd_get_transparency.c) | `FUN_a00bd2e0` | Report the menu Transparency to the PC tool. | proven |
| [`uart_cmd_get_type_c_pd_charge`](../../src/leon2m/uart/uart_cmd_get_type_c_pd_charge.c) | `FUN_a00be2a0` | Report the Type C PD Charge switch to the PC tool. | proven |
| [`uart_cmd_get_units_digit`](../../src/leon2m/uart/uart_cmd_get_units_digit.c) | `FUN_a00c0b8c` | Return the units digit of the value in a received set command. | derived |
| [`uart_cmd_get_version_code`](../../src/leon2m/uart/uart_cmd_get_version_code.c) | `FUN_a00bdb88` | Report the fixed version text 'V23' for command 5800150 to the PC tool. | descriptive |
| [`uart_cmd_init_ports`](../../src/leon2m/uart/uart_cmd_init_ports.c) | `FUN_a00ba8bc` | Clear the tool command buffers and open two 8051 serial ports at 115200 baud. | derived |
| [`uart_cmd_parse_value`](../../src/leon2m/uart/uart_cmd_parse_value.c) | `FUN_a00bae38` | Read the three ASCII digits of a received set command as a number. | derived |
| [`uart_cmd_poll_port2`](../../src/leon2m/uart/uart_cmd_poll_port2.c) | `FUN_a00bbabc` | Receive commands on port 2, answer unknown or bad ones and log set commands. | proven |
| [`uart_cmd_put_alarm_time_digits`](../../src/leon2m/uart/uart_cmd_put_alarm_time_digits.c) | `FUN_a00badf8` | Write the time of one alarm clock timer as digits into the reply frame. | descriptive |
| [`uart_cmd_put_color_gain_digits`](../../src/leon2m/uart/uart_cmd_put_color_gain_digits.c) | `FUN_a00badc0` | Write the red, green and blue gain bytes as digits into the reply frame. | descriptive |
| [`uart_cmd_put_value_digits`](../../src/leon2m/uart/uart_cmd_put_value_digits.c) | `FUN_a00bad4c` | Write a value as three ASCII decimal digits into the reply frame. | derived |
| [`uart_cmd_read_frame`](../../src/leon2m/uart/uart_cmd_read_frame.c) | `FUN_a00baef8` | Collect received bytes of a port into its record and classify the frame. | derived |
| [`uart_cmd_read_frame_port2`](../../src/leon2m/uart/uart_cmd_read_frame_port2.c) | `FUN_a00bb560` | Collect received bytes of port 2 and classify the frame. | derived |
| [`uart_cmd_reset_crosshair_position`](../../src/leon2m/uart/uart_cmd_reset_crosshair_position.c) | `FUN_a00c1188` | Store the Smart Crosshair reset position (0x750, 0x402) on a PC tool command and acknowledge it. | proven |
| [`uart_cmd_reset_settings`](../../src/leon2m/uart/uart_cmd_reset_settings.c) | `FUN_a00ccef4` | Reset all user settings to their defaults on a PC tool command. | proven |
| [`uart_cmd_return_zero`](../../src/leon2m/uart/uart_cmd_return_zero.c) | `FUN_a00c0be4` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy`](../../src/leon2m/uart/uart_cmd_return_zero_copy.c) | `FUN_a00c0bec` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy2`](../../src/leon2m/uart/uart_cmd_return_zero_copy2.c) | `FUN_a00c0bf4` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy3`](../../src/leon2m/uart/uart_cmd_return_zero_copy3.c) | `FUN_a00c0bfc` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy4`](../../src/leon2m/uart/uart_cmd_return_zero_copy4.c) | `FUN_a00c0c04` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy5`](../../src/leon2m/uart/uart_cmd_return_zero_copy5.c) | `FUN_a00c0c0c` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy6`](../../src/leon2m/uart/uart_cmd_return_zero_copy6.c) | `FUN_a00c0c14` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy7`](../../src/leon2m/uart/uart_cmd_return_zero_copy7.c) | `FUN_a00c0c1c` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy8`](../../src/leon2m/uart/uart_cmd_return_zero_copy8.c) | `FUN_a00c0c24` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy9`](../../src/leon2m/uart/uart_cmd_return_zero_copy9.c) | `FUN_a00c0c2c` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy10`](../../src/leon2m/uart/uart_cmd_return_zero_copy10.c) | `FUN_a00c0c34` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy11`](../../src/leon2m/uart/uart_cmd_return_zero_copy11.c) | `FUN_a00c0c3c` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy12`](../../src/leon2m/uart/uart_cmd_return_zero_copy12.c) | `FUN_a00c0c44` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy13`](../../src/leon2m/uart/uart_cmd_return_zero_copy13.c) | `FUN_a00c0c4c` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy14`](../../src/leon2m/uart/uart_cmd_return_zero_copy14.c) | `FUN_a00c0c54` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy15`](../../src/leon2m/uart/uart_cmd_return_zero_copy15.c) | `FUN_a00c0c5c` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy16`](../../src/leon2m/uart/uart_cmd_return_zero_copy16.c) | `FUN_a00c0c64` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy17`](../../src/leon2m/uart/uart_cmd_return_zero_copy17.c) | `FUN_a00c0c6c` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy18`](../../src/leon2m/uart/uart_cmd_return_zero_copy18.c) | `FUN_a00c0cf8` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy19`](../../src/leon2m/uart/uart_cmd_return_zero_copy19.c) | `FUN_a00c0d00` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy20`](../../src/leon2m/uart/uart_cmd_return_zero_copy20.c) | `FUN_a00c0d08` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy21`](../../src/leon2m/uart/uart_cmd_return_zero_copy21.c) | `FUN_a00d24d8` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy22`](../../src/leon2m/uart/uart_cmd_return_zero_copy22.c) | `FUN_a00deda0` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy23`](../../src/leon2m/uart/uart_cmd_return_zero_copy23.c) | `FUN_a00deda8` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy24`](../../src/leon2m/uart/uart_cmd_return_zero_copy24.c) | `FUN_a00fbf54` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy25`](../../src/leon2m/uart/uart_cmd_return_zero_copy25.c) | `FUN_a0107b9c` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy26`](../../src/leon2m/uart/uart_cmd_return_zero_copy26.c) | `FUN_a010a85c` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy27`](../../src/leon2m/uart/uart_cmd_return_zero_copy27.c) | `FUN_a0124ea4` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy28`](../../src/leon2m/uart/uart_cmd_return_zero_copy28.c) | `FUN_a0125364` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy29`](../../src/leon2m/uart/uart_cmd_return_zero_copy29.c) | `FUN_a012c088` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy30`](../../src/leon2m/uart/uart_cmd_return_zero_copy30.c) | `FUN_a012c0f8` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy31`](../../src/leon2m/uart/uart_cmd_return_zero_copy31.c) | `FUN_a0132a30` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy32`](../../src/leon2m/uart/uart_cmd_return_zero_copy32.c) | `FUN_a0132a38` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy33`](../../src/leon2m/uart/uart_cmd_return_zero_copy33.c) | `FUN_a01397ec` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy34`](../../src/leon2m/uart/uart_cmd_return_zero_copy34.c) | `FUN_a013c894` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy35`](../../src/leon2m/uart/uart_cmd_return_zero_copy35.c) | `FUN_a0147c38` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy36`](../../src/leon2m/uart/uart_cmd_return_zero_copy36.c) | `FUN_a014881c` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy37`](../../src/leon2m/uart/uart_cmd_return_zero_copy37.c) | `FUN_a0148824` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy38`](../../src/leon2m/uart/uart_cmd_return_zero_copy38.c) | `FUN_a014882c` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy39`](../../src/leon2m/uart/uart_cmd_return_zero_copy39.c) | `FUN_a0148834` | Return 0. | descriptive |
| [`uart_cmd_return_zero_copy40`](../../src/leon2m/uart/uart_cmd_return_zero_copy40.c) | `FUN_a014dd58` | Return 0. | descriptive |
| [`uart_cmd_run_tool_task`](../../src/leon2m/uart/uart_cmd_run_tool_task.c) | `FUN_a00ce348` | Receive one command from MSI's PC tool on port 4 and carry it out. | proven |
| [`uart_cmd_send_error_reply`](../../src/leon2m/uart/uart_cmd_send_error_reply.c) | `FUN_a00baa20` | Send the '5600-' reply (command refused) on a command port. | derived |
| [`uart_cmd_send_error_reply_port2`](../../src/leon2m/uart/uart_cmd_send_error_reply_port2.c) | `FUN_a00bb49c` | Send the '5600-' reply (command refused) from the port 2 reply frame on the given port. | derived |
| [`uart_cmd_send_reply_frame`](../../src/leon2m/uart/uart_cmd_send_reply_frame.c) | `FUN_a00babe4` | Send the shared reply frame on a command port. | derived |
| [`uart_cmd_send_tx_buffer`](../../src/leon2m/uart/uart_cmd_send_tx_buffer.c) | `FUN_a00bab80` | Send the first bytes of a port's transmit buffer. | derived |
| [`uart_cmd_send_unsupported_reply`](../../src/leon2m/uart/uart_cmd_send_unsupported_reply.c) | `FUN_a00ba9d8` | Send the '56006' reply (command not supported) on a command port. | derived |
| [`uart_cmd_send_unsupported_reply_port2`](../../src/leon2m/uart/uart_cmd_send_unsupported_reply_port2.c) | `FUN_a00bb454` | Send the '56006' reply (command not supported) from the port 2 reply frame on the given port. | derived |
| [`uart_cmd_set_adaptive_sync`](../../src/leon2m/uart/uart_cmd_set_adaptive_sync.c) | `FUN_a00c4430` | Set the Adaptive-Sync switch from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_ai_vision`](../../src/leon2m/uart/uart_cmd_set_ai_vision.c) | `FUN_a00c9e9c` | Set the AI Vision switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_alarm_clock`](../../src/leon2m/uart/uart_cmd_set_alarm_clock.c) | `FUN_a00c2f08` | Set the Alarm Clock timer choice from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_alarm_clock_custom_position`](../../src/leon2m/uart/uart_cmd_set_alarm_clock_custom_position.c) | `FUN_a00c2180` | Set the custom Alarm Clock position from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_alarm_clock_location`](../../src/leon2m/uart/uart_cmd_set_alarm_clock_location.c) | `FUN_a00c29d8` | Set the Alarm Clock location from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_alarm_presets`](../../src/leon2m/uart/uart_cmd_set_alarm_presets.c) | `FUN_a00c49b8` | Set the four alarm clock timer times and the chosen timer from a PC tool command. | proven |
| [`uart_cmd_set_alarm_slot`](../../src/leon2m/uart/uart_cmd_set_alarm_slot.c) | `FUN_a00c0c74` | Set the selected alarm clock timer slot from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_alarm_slot_time`](../../src/leon2m/uart/uart_cmd_set_alarm_slot_time.c) | `FUN_a00c2bd8` | Set the time of the selected alarm clock timer from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_auto_level`](../../src/leon2m/uart/uart_cmd_set_auto_level.c) | `FUN_a00c1adc` | Set the automatic level setting from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_blue_gain`](../../src/leon2m/uart/uart_cmd_set_blue_gain.c) | `FUN_a00ccc20` | Set the custom blue gain from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_blur_free`](../../src/leon2m/uart/uart_cmd_set_blur_free.c) | `FUN_a00c4144` | Set the blur reduction mode from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_boundary_detection`](../../src/leon2m/uart/uart_cmd_set_boundary_detection.c) | `FUN_a00cb9d4` | Set the Boundary Detection switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_boundary_level`](../../src/leon2m/uart/uart_cmd_set_boundary_level.c) | `FUN_a00cb7f4` | Set the Boundary Detection level from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_brightness`](../../src/leon2m/uart/uart_cmd_set_brightness.c) | `FUN_a00c6424` | Set the Brightness from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_byte_0x140`](../../src/leon2m/uart/uart_cmd_set_byte_0x140.c) | `FUN_a00c3a30` | Set the settings byte +0x140 from a PC tool command and acknowledge it. | descriptive |
| [`uart_cmd_set_byte_0x177`](../../src/leon2m/uart/uart_cmd_set_byte_0x177.c) | `FUN_a00c122c` | Set the settings byte +0x177 from a PC tool command and acknowledge it. | descriptive |
| [`uart_cmd_set_color_gains`](../../src/leon2m/uart/uart_cmd_set_color_gains.c) | `FUN_a00c573c` | Set the custom red, green and blue gains from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_color_temperature`](../../src/leon2m/uart/uart_cmd_set_color_temperature.c) | `FUN_a00c5a00` | Set the Color Temperature from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_contrast`](../../src/leon2m/uart/uart_cmd_set_contrast.c) | `FUN_a00c6690` | Set the Contrast from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_crosshair_color`](../../src/leon2m/uart/uart_cmd_set_crosshair_color.c) | `FUN_a00c3380` | Set the Smart Crosshair colour from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_crosshair_icon`](../../src/leon2m/uart/uart_cmd_set_crosshair_icon.c) | `FUN_a00c35d0` | Set the Smart Crosshair icon from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_crosshair_position`](../../src/leon2m/uart/uart_cmd_set_crosshair_position.c) | `FUN_a00c25ac` | Set the Smart Crosshair position from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_display_hdr`](../../src/leon2m/uart/uart_cmd_set_display_hdr.c) | `FUN_a00c9be0` | Set the DisplayHDR setting from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_dsc`](../../src/leon2m/uart/uart_cmd_set_dsc.c) | `FUN_a00c9f44` | Set the DSC switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_game_mode`](../../src/leon2m/uart/uart_cmd_set_game_mode.c) | `FUN_a00c3820` | Set the Game Mode from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_green_gain`](../../src/leon2m/uart/uart_cmd_set_green_gain.c) | `FUN_a00cc9c0` | Set the custom green gain from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_hdmi_cec`](../../src/leon2m/uart/uart_cmd_set_hdmi_cec.c) | `FUN_a00c7818` | Set the HDMI CEC switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_image_enhancement`](../../src/leon2m/uart/uart_cmd_set_image_enhancement.c) | `FUN_a00c5e40` | Set the Image Enhancement level from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_info_on_screen`](../../src/leon2m/uart/uart_cmd_set_info_on_screen.c) | `FUN_a00c12b4` | Set the Info. On Screen switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_input_source`](../../src/leon2m/uart/uart_cmd_set_input_source.c) | `FUN_a00c18cc` | Set the Input Source from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_kvm`](../../src/leon2m/uart/uart_cmd_set_kvm.c) | `FUN_a00c1100` | Set the KVM setting from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_language`](../../src/leon2m/uart/uart_cmd_set_language.c) | `FUN_a00cce80` | Set the menu Language from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_low_blue_light`](../../src/leon2m/uart/uart_cmd_set_low_blue_light.c) | `FUN_a00c5c18` | Set the Low Blue Light switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_multi_logo_detection`](../../src/leon2m/uart/uart_cmd_set_multi_logo_detection.c) | `FUN_a00cb3a8` | Set the Multi Logo Detection switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_multi_logo_level`](../../src/leon2m/uart/uart_cmd_set_multi_logo_level.c) | `FUN_a00cb1c8` | Set the Multi Logo Detection level from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_navi_key_down`](../../src/leon2m/uart/uart_cmd_set_navi_key_down.c) | `FUN_a00c16b0` | Set the Navi Key down function from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_navi_key_left`](../../src/leon2m/uart/uart_cmd_set_navi_key_left.c) | `FUN_a00c165c` | Set the Navi Key left function from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_navi_key_right`](../../src/leon2m/uart/uart_cmd_set_navi_key_right.c) | `FUN_a00c1608` | Set the Navi Key right function from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_navi_key_up`](../../src/leon2m/uart/uart_cmd_set_navi_key_up.c) | `FUN_a00c1704` | Set the Navi Key up function from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_night_vision`](../../src/leon2m/uart/uart_cmd_set_night_vision.c) | `FUN_a00c95a4` | Set the Night Vision level from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_optix_scope`](../../src/leon2m/uart/uart_cmd_set_optix_scope.c) | `FUN_a00c46d4` | Set the Optix Scope switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_osd_timeout`](../../src/leon2m/uart/uart_cmd_set_osd_timeout.c) | `FUN_a00c17e8` | Set the OSD Time out from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_panel_protect_byte_0x1e5`](../../src/leon2m/uart/uart_cmd_set_panel_protect_byte_0x1e5.c) | `FUN_a00ca410` | Store 1 in settings byte +0x1E5 for value 1 of a PC tool command and acknowledge it. | descriptive |
| [`uart_cmd_set_pbp_mode`](../../src/leon2m/uart/uart_cmd_set_pbp_mode.c) | `FUN_a00c3f54` | Set the PBP layout from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_pbp_source1`](../../src/leon2m/uart/uart_cmd_set_pbp_source1.c) | `FUN_a00c1400` | Set the first PBP source from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_pbp_source2`](../../src/leon2m/uart/uart_cmd_set_pbp_source2.c) | `FUN_a00c8410` | Set the second PBP source from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_picture_settings`](../../src/leon2m/uart/uart_cmd_set_picture_settings.c) | `FUN_a00c68d8` | Set several picture settings from one PC tool command. | proven |
| [`uart_cmd_set_pip_location`](../../src/leon2m/uart/uart_cmd_set_pip_location.c) | `FUN_a00c91dc` | Set the PIP location from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_pip_pbp_mode`](../../src/leon2m/uart/uart_cmd_set_pip_pbp_mode.c) | `FUN_a00c7a5c` | Set the PIP/PBP mode from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_pip_pbp_settings`](../../src/leon2m/uart/uart_cmd_set_pip_pbp_settings.c) | `FUN_a00c7e3c` | Set the PIP/PBP mode with its sources, size, location and layout from one command. | proven |
| [`uart_cmd_set_pip_position`](../../src/leon2m/uart/uart_cmd_set_pip_position.c) | `FUN_a00c8c38` | Set the PIP window position from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_pip_size`](../../src/leon2m/uart/uart_cmd_set_pip_size.c) | `FUN_a00c8a44` | Set the PIP size from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_pip_source`](../../src/leon2m/uart/uart_cmd_set_pip_source.c) | `FUN_a00c8614` | Set the PIP source (settings byte +0x20) from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_pixel_shift`](../../src/leon2m/uart/uart_cmd_set_pixel_shift.c) | `FUN_a00ca380` | Set the Pixel Shift speed from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_power_button`](../../src/leon2m/uart/uart_cmd_set_power_button.c) | `FUN_a00c135c` | Set the Power Button setting from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_power_flag`](../../src/leon2m/uart/uart_cmd_set_power_flag.c) | `FUN_a00c0db4` | Set the power request flag when the given state is 0 or 4. | descriptive |
| [`uart_cmd_set_power_led`](../../src/leon2m/uart/uart_cmd_set_power_led.c) | `FUN_a00ca158` | Set the Power LED switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_power_state`](../../src/leon2m/uart/uart_cmd_set_power_state.c) | `FUN_a00c0de0` | Take a power on/off request from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_pro_mode`](../../src/leon2m/uart/uart_cmd_set_pro_mode.c) | `FUN_a00c5478` | Set the Professional mode from a PC tool command and acknowledge it. | derived |
| `uart_cmd_set_pro_mode_jump_table` | `switchdataD_a00ba634` | Jump table 1 of the switch statements in uart_cmd_set_pro_mode. | proven |
| [`uart_cmd_set_protect_notice`](../../src/leon2m/uart/uart_cmd_set_protect_notice.c) | `FUN_a00c1078` | Set the Protect Notice setting from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_red_gain`](../../src/leon2m/uart/uart_cmd_set_red_gain.c) | `FUN_a00cc760` | Set the custom red gain from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_refresh_rate_custom_position`](../../src/leon2m/uart/uart_cmd_set_refresh_rate_custom_position.c) | `FUN_a00c1d54` | Set the custom Refresh Rate position from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_refresh_rate_display`](../../src/leon2m/uart/uart_cmd_set_refresh_rate_display.c) | `FUN_a00c0d10` | Set the Refresh Rate display switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_refresh_rate_location`](../../src/leon2m/uart/uart_cmd_set_refresh_rate_location.c) | `FUN_a00c3180` | Set the Refresh Rate display location from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_response_time`](../../src/leon2m/uart/uart_cmd_set_response_time.c) | `FUN_a00c3c14` | Set the response time level from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_rgb_brightness`](../../src/leon2m/uart/uart_cmd_set_rgb_brightness.c) | `FUN_a00cbbb0` | Set the RGB LED brightness from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_rgb_led`](../../src/leon2m/uart/uart_cmd_set_rgb_led.c) | `FUN_a00c9500` | Set the RGB LED switch from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_scope_ratio`](../../src/leon2m/uart/uart_cmd_set_scope_ratio.c) | `FUN_a00c3e3c` | Set the Optix Scope ratio from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_scope_size`](../../src/leon2m/uart/uart_cmd_set_scope_size.c) | `FUN_a00c3ec8` | Set the Optix Scope size from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_screen_size`](../../src/leon2m/uart/uart_cmd_set_screen_size.c) | `FUN_a00c4ec4` | Set the Screen Size from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_screen_size_checked`](../../src/leon2m/uart/uart_cmd_set_screen_size_checked.c) | `FUN_a00ce5dc` | Set the Screen Size from a two-digit PC tool command after checking conflicts. | derived |
| [`uart_cmd_set_second_source`](../../src/leon2m/uart/uart_cmd_set_second_source.c) | `FUN_a00c8818` | Set the second picture source from a PC tool command and acknowledge it. | derived |
| [`uart_cmd_set_setting_bit9`](../../src/leon2m/uart/uart_cmd_set_setting_bit9.c) | `FUN_a00c9788` | Set the settings bit 9 from a PC tool command and acknowledge it. | descriptive |
| [`uart_cmd_set_setting_bit17`](../../src/leon2m/uart/uart_cmd_set_setting_bit17.c) | `FUN_a00c6228` | Set the settings bit 17 of +0xAC from a PC tool command and acknowledge it. | descriptive |
| [`uart_cmd_set_sharpness`](../../src/leon2m/uart/uart_cmd_set_sharpness.c) | `FUN_a00c762c` | Set the Sharpness from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_static_screen_detection`](../../src/leon2m/uart/uart_cmd_set_static_screen_detection.c) | `FUN_a00cae64` | Set the Static Screen Detection switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_static_screen_reduce_level`](../../src/leon2m/uart/uart_cmd_set_static_screen_reduce_level.c) | `FUN_a00cabf8` | Set the Static Screen Detection reduce level from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_static_screen_settings`](../../src/leon2m/uart/uart_cmd_set_static_screen_settings.c) | `FUN_a00ca878` | Set all Static Screen Detection settings from one PC tool command. | proven |
| [`uart_cmd_set_static_screen_start_time`](../../src/leon2m/uart/uart_cmd_set_static_screen_start_time.c) | `FUN_a00cadd4` | Set the Static Screen Detection start time from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_static_screen_time_required`](../../src/leon2m/uart/uart_cmd_set_static_screen_time_required.c) | `FUN_a00cab68` | Set the Static Screen Detection time required from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_taskbar_detection`](../../src/leon2m/uart/uart_cmd_set_taskbar_detection.c) | `FUN_a00cb618` | Set the Taskbar Detection switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_taskbar_level`](../../src/leon2m/uart/uart_cmd_set_taskbar_level.c) | `FUN_a00cb438` | Set the Taskbar Detection level from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_transparency`](../../src/leon2m/uart/uart_cmd_set_transparency.c) | `FUN_a00c604c` | Set the menu Transparency from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_set_type_c_pd_charge`](../../src/leon2m/uart/uart_cmd_set_type_c_pd_charge.c) | `FUN_a00c9df4` | Set the Type C PD Charge switch from a PC tool command and acknowledge it. | proven |
| [`uart_cmd_start_panel_protect`](../../src/leon2m/uart/uart_cmd_start_panel_protect.c) | `FUN_a00ca644` | Start the OLED panel protect run on a PC tool command. | derived |
| [`uart_cmd_swap_pip_sources`](../../src/leon2m/uart/uart_cmd_swap_pip_sources.c) | `FUN_a00c93e0` | Swap the two PIP/PBP sources on a PC tool command. | derived |
| [`uart_cmd_toggle_setting_bit14`](../../src/leon2m/uart/uart_cmd_toggle_setting_bit14.c) | `FUN_a00c9470` | Toggle settings bit 14 of +0xA8 on a PC tool command. | descriptive |
| [`uart_cmd_write_factory_record`](../../src/leon2m/uart/uart_cmd_write_factory_record.c) | `FUN_a00cc140` | Store a factory record block from the PC tool after checking its byte sum. | derived |
| [`uart_find_port_with_data`](../../src/leon2m/uart/uart_find_port_with_data.c) | `FUN_a0133a10` | Return a serial port 1..4 that has received data waiting. | derived |
| [`uart_get_char_blocking`](../../src/leon2m/uart/uart_get_char_blocking.c) | `FUN_a00df420` | Wait without a limit for a character from the debug serial port and return it. | derived |
| [`uart_get_char_timeout`](../../src/leon2m/uart/uart_get_char_timeout.c) | `FUN_a00df384` | Wait up to 1000 polls for a character from the debug serial port and return it. | proven |
| [`uart_init`](../../src/leon2m/uart/uart_init.c) | `FUN_a00dedc8` | Set up the debug serial port from a clock value and install its receive interrupt handler. | proven |
| [`uart_is_rx_ready`](../../src/leon2m/uart/uart_is_rx_ready.c) | `FUN_a00df368` | Return whether the debug serial port has received a character. | proven |
| [`uart_put_char`](../../src/leon2m/uart/uart_put_char.c) | `FUN_a00deef0` | Send one character to the debug serial port. | proven |
| [`uart_put_char_blocking`](../../src/leon2m/uart/uart_put_char_blocking.c) | `FUN_a00df4d4` | Send one character to the debug serial port, waiting without a limit. | proven |
| [`uart_put_char_crlf`](../../src/leon2m/uart/uart_put_char_crlf.c) | `FUN_a00df3d0` | Send one character to the debug serial port, a carriage return first for a line feed. | proven |
| [`uart_put_hex8`](../../src/leon2m/uart/uart_put_hex8.c) | `FUN_a00df0f4` | Send an 8-bit value as two hexadecimal digits to the debug serial port. | proven |
| [`uart_put_hex16`](../../src/leon2m/uart/uart_put_hex16.c) | `FUN_a00df074` | Send a 16-bit value as four hexadecimal digits to the debug serial port. | proven |
| [`uart_put_hex32`](../../src/leon2m/uart/uart_put_hex32.c) | `FUN_a00deffc` | Send a 32-bit value as eight hexadecimal digits to the debug serial port. | proven |
| [`uart_put_string`](../../src/leon2m/uart/uart_put_string.c) | `FUN_a00def40` | Send a text to the debug serial port, character by character. | proven |
| [`uart_put_string_blocking`](../../src/leon2m/uart/uart_put_string_blocking.c) | `FUN_a00df450` | Send a text to the debug serial port, waiting without a limit. | derived |
| [`uart_put_string_crlf`](../../src/leon2m/uart/uart_put_string_crlf.c) | `FUN_a00df278` | Send a text to the debug serial port, adding a carriage return after each line feed. | proven |
| [`uart_read_rx_ring`](../../src/leon2m/uart/uart_read_rx_ring.c) | `FUN_a0133950` | Read received bytes of serial port 0..4 from its ring buffer. | proven |
| [`uart_rx_buffer_get`](../../src/leon2m/uart/uart_rx_buffer_get.c) | `FUN_a00deea4` | Take one character from the receive buffer of the debug serial port. | proven |
| [`uart_rx_isr`](../../src/leon2m/uart/uart_rx_isr.c) | `FUN_a002e238` | Move one received UART byte into the 128-byte receive ring. | proven |
| [`uart_send_bytes`](../../src/leon2m/uart/uart_send_bytes.c) | `FUN_a01337e8` | Queue bytes for sending on one of the 8051's serial ports. | derived |
| [`uart_try_get_char`](../../src/leon2m/uart/uart_try_get_char.c) | `FUN_a00dee6c` | Fetch a character from the debug serial port if one has arrived. | proven |
| [`UartSetI2CEnable`](../../src/leon2m/uart/UartSetI2CEnable.c) | `FUN_a00bf110` | Answer command 580040: and open the I2C path MSI's PC tool uses (slave 0x6E) | proven |

<a id="usb"></a>
## USB

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`UsbModeSelectRoutine`](../../src/leon2m/usb/UsbModeSelectRoutine.c) | `FUN_a0083ff0` | Pick the USB upstream port from the cable-sense inputs and the KVM setting; track the hub condition. | proven |

<a id="reg"></a>
## Register access

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`reg_blockset5_read8`](../../src/leon2m/reg/reg_blockset5_read8.c) | `FUN_a00f11ac` | Read an 8-bit register of a block of the fifth block set. | descriptive |
| [`reg_blockset5_read16`](../../src/leon2m/reg/reg_blockset5_read16.c) | `FUN_a00f14e4` | Read a 16-bit register pair of a block of the fifth block set. | descriptive |
| [`reg_blockset5_read16_stable`](../../src/leon2m/reg/reg_blockset5_read16_stable.c) | `FUN_a00f154c` | Read a 16-bit register pair of the fifth block set until two reads agree. | descriptive |
| [`reg_blockset5_update_bits`](../../src/leon2m/reg/reg_blockset5_update_bits.c) | `FUN_a00f1374` | Set or clear bits of a register of a block of the fifth block set. | descriptive |
| [`reg_blockset5_write8`](../../src/leon2m/reg/reg_blockset5_write8.c) | `FUN_a00f11f4` | Write an 8-bit register of a block of the fifth block set. | descriptive |
| [`reg_blockset5_write16`](../../src/leon2m/reg/reg_blockset5_write16.c) | `FUN_a00f1298` | Write a 16-bit register pair of a block of the fifth block set. | descriptive |
| [`reg_blockset6_read8`](../../src/leon2m/reg/reg_blockset6_read8.c) | `FUN_a00f1690` | Read an 8-bit register of a block of the sixth block set. | descriptive |
| [`reg_blockset6_update_bits`](../../src/leon2m/reg/reg_blockset6_update_bits.c) | `FUN_a00f176c` | Set or clear bits of a register of a block of the sixth block set. | descriptive |
| [`reg_blockset6_write8`](../../src/leon2m/reg/reg_blockset6_write8.c) | `FUN_a00f16d8` | Write an 8-bit register of a block of the sixth block set. | descriptive |
| [`reg_blockset6_write16`](../../src/leon2m/reg/reg_blockset6_write16.c) | `FUN_a00f18d4` | Write a 16-bit register pair of a block of the sixth block set. | descriptive |
| [`reg_blockset7_read8`](../../src/leon2m/reg/reg_blockset7_read8.c) | `FUN_a00f19a4` | Read an 8-bit register of a block of the seventh block set. | descriptive |
| [`reg_blockset7_update_bits`](../../src/leon2m/reg/reg_blockset7_update_bits.c) | `FUN_a00f1a18` | Set or clear bits of a register of a block of the seventh block set. | descriptive |
| [`reg_blockset7_write8`](../../src/leon2m/reg/reg_blockset7_write8.c) | `FUN_a00f19dc` | Write an 8-bit register of a block of the seventh block set. | descriptive |
| [`reg_read8`](../../src/leon2m/reg/reg_read8.c) | `FUN_a002c2d4` | Return byte register r (word 0xCF000000 + 4r) | descriptive |
| [`reg_read8_offset`](../../src/leon2m/reg/reg_read8_offset.c) | `FUN_a002c2f0` | Return byte register r + k (word 0xCF000000 + 4(r + k)) | descriptive |
| [`reg_read16_bytes`](../../src/leon2m/reg/reg_read16_bytes.c) | `FUN_a00f3078` | Read a 16-bit value from two byte registers. | proven |
| [`reg_read16_pair`](../../src/leon2m/reg/reg_read16_pair.c) | `FUN_a002c364` | Return byte registers r (high) and r + 1 (low) as a halfword. | descriptive |
| [`reg_read16_pair_offset`](../../src/leon2m/reg/reg_read16_pair_offset.c) | `FUN_a002c390` | Return byte registers r + k (high) and r + k + 1 (low) as a halfword. | descriptive |
| [`reg_read24_bytes`](../../src/leon2m/reg/reg_read24_bytes.c) | `FUN_a00f30a8` | Read a 24-bit value from three byte registers. | proven |
| [`reg_read32`](../../src/leon2m/reg/reg_read32.c) | `FUN_a002c250` | Return the 32-bit word at addr. | proven |
| [`reg_read32_bytes`](../../src/leon2m/reg/reg_read32_bytes.c) | `FUN_a00f3164` | Read a 32-bit value from four byte registers. | proven |
| [`reg_read32_copy`](../../src/leon2m/reg/reg_read32_copy.c) | `FUN_a00e021c` | Return the 32-bit word at addr. | proven |
| [`reg_read_bit_range_at`](../../src/leon2m/reg/reg_read_bit_range_at.c) | `FUN_a00e21fc` | Return the bits lo..hi of the word at an address. | derived |
| [`reg_read_block_byte`](../../src/leon2m/reg/reg_read_block_byte.c) | `FUN_a002e658` | Return byte register reg of register block blk (0 or 1) | descriptive |
| [`reg_read_byte_in_word`](../../src/leon2m/reg/reg_read_byte_in_word.c) | `FUN_a002c284` | Return byte number (a & 3), counted from the low end, of the aligned word that holds address a. | descriptive |
| [`reg_read_field_at`](../../src/leon2m/reg/reg_read_field_at.c) | `FUN_a00df540` | Return the bit field between two bit positions of the word at an address. | derived |
| [`reg_read_masked_at`](../../src/leon2m/reg/reg_read_masked_at.c) | `FUN_a00df504` | Return the masked value of the word at an address. | derived |
| [`reg_read_masked_shifted_at`](../../src/leon2m/reg/reg_read_masked_shifted_at.c) | `FUN_a00e21e0` | Return the masked and shifted value of the word at an address. | derived |
| [`reg_read_word_at`](../../src/leon2m/reg/reg_read_word_at.c) | `FUN_a00f9988` | Return the word at an address. | derived |
| [`reg_set_channel_ctrl_bit`](../../src/leon2m/reg/reg_set_channel_ctrl_bit.c) | `FUN_a002e3c4` | Set or clear bit n of register 0xCF011FC0. | descriptive |
| [`reg_table_port_delay`](../../src/leon2m/reg/reg_table_port_delay.c) | `FUN_a00f2e74` | Wait for 32 idle instructions between two table port writes. | derived |
| [`reg_table_port_write`](../../src/leon2m/reg/reg_table_port_write.c) | `FUN_a00f2e98` | Write a block of bytes to one of the chip's internal tables through the table port. | proven |
| [`reg_table_port_write_second`](../../src/leon2m/reg/reg_table_port_write_second.c) | `FUN_a00f2f88` | Write a block of bytes through the table port's second data register. | derived |
| [`reg_update_bits_at`](../../src/leon2m/reg/reg_update_bits_at.c) | `FUN_a00df51c` | Replace the masked bits of the word at an address. | derived |
| [`reg_update_bits_at_copy`](../../src/leon2m/reg/reg_update_bits_at_copy.c) | `FUN_a00e2180` | Replace the masked bits of the word at an address. | derived |
| [`reg_write8`](../../src/leon2m/reg/reg_write8.c) | `FUN_a002c318` | Write byte v to register r (word 0xCF000000 + 4r) | descriptive |
| [`reg_write8_masked`](../../src/leon2m/reg/reg_write8_masked.c) | `FUN_a002c42c` | Clear mask and OR in v in byte register r. | descriptive |
| [`reg_write8_masked_offset`](../../src/leon2m/reg/reg_write8_masked_offset.c) | `FUN_a002c464` | Clear mask and OR in v in byte register r + k. | descriptive |
| [`reg_write8_offset`](../../src/leon2m/reg/reg_write8_offset.c) | `FUN_a002c338` | Write byte v to register r + k (word 0xCF000000 + 4(r + k)) | descriptive |
| [`reg_write16_bytes`](../../src/leon2m/reg/reg_write16_bytes.c) | `FUN_a00f308c` | Write a 16-bit value to two byte registers. | proven |
| [`reg_write16_pair`](../../src/leon2m/reg/reg_write16_pair.c) | `FUN_a002c3c8` | Write halfword v to byte registers r (low byte) and r + 1 (high byte) | descriptive |
| [`reg_write16_pair_offset`](../../src/leon2m/reg/reg_write16_pair_offset.c) | `FUN_a002c3f4` | Write halfword v to byte registers r + k (low) and r + k + 1 (high) | descriptive |
| [`reg_write24_bytes`](../../src/leon2m/reg/reg_write24_bytes.c) | `FUN_a00f30c8` | Write a 24-bit value to three byte registers. | proven |
| [`reg_write24_bytes_settle`](../../src/leon2m/reg/reg_write24_bytes_settle.c) | `FUN_a00f30f0` | Write a 24-bit value to three byte registers and wait for it to settle. | proven |
| [`reg_write32`](../../src/leon2m/reg/reg_write32.c) | `FUN_a002c25c` | Store a 32-bit value at addr. | proven |
| [`reg_write32_bytes`](../../src/leon2m/reg/reg_write32_bytes.c) | `FUN_a00f3134` | Write a 32-bit value to four byte registers. | proven |
| [`reg_write32_copy`](../../src/leon2m/reg/reg_write32_copy.c) | `FUN_a00e0228` | Store a 32-bit value at addr. | proven |
| [`reg_write32_masked`](../../src/leon2m/reg/reg_write32_masked.c) | `FUN_a002c268` | Replace the bits of mask in the word at p with those of v. | proven |
| [`reg_write_bit_range_at`](../../src/leon2m/reg/reg_write_bit_range_at.c) | `FUN_a00e21a4` | Write a value into the bits lo..hi of the word at an address. | derived |
| [`reg_write_block_byte`](../../src/leon2m/reg/reg_write_block_byte.c) | `FUN_a002e69c` | Write val to byte register reg of register block blk (0 or 1) | derived |
| [`reg_write_byte_in_word`](../../src/leon2m/reg/reg_write_byte_in_word.c) | `FUN_a002c2a0` | Replace byte number (a & 3), counted from the low end, of the aligned word that holds address a. | descriptive |
| [`reg_write_field_at`](../../src/leon2m/reg/reg_write_field_at.c) | `FUN_a00df588` | Write a value into the bit field between two bit positions of the word at an address. | derived |
| [`reg_write_word_at`](../../src/leon2m/reg/reg_write_word_at.c) | `FUN_a00f9994` | Store a word at an address. | derived |
| [`reg_write_word_at_alt`](../../src/leon2m/reg/reg_write_word_at_alt.c) | `FUN_a00e2248` | Store a word at an address. | derived |

<a id="dbg"></a>
## Debug facilities

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`dbg_command_shell`](../../src/leon2m/dbg/dbg_command_shell.c) | `FUN_a00dcec4` | Run the debug command line: read a line, find the command and carry it out. | proven |
| [`dbg_ddr_advance_test_state`](../../src/leon2m/dbg/dbg_ddr_advance_test_state.c) | `FUN_a01181d4` | Move the stress test on to its next step. | derived |
| [`dbg_ddr_configure_stress`](../../src/leon2m/dbg/dbg_ddr_configure_stress.c) | `FUN_a00dd814` | Switch the memory stress test on or off and store its parameter. | derived |
| [`dbg_ddr_get_result_first`](../../src/leon2m/dbg/dbg_ddr_get_result_first.c) | `FUN_a011818c` | Return the first stored result byte of the stress test. | descriptive |
| [`dbg_ddr_get_result_second`](../../src/leon2m/dbg/dbg_ddr_get_result_second.c) | `FUN_a0118174` | Return the second stored result byte of the stress test. | descriptive |
| [`dbg_ddr_get_stress_param`](../../src/leon2m/dbg/dbg_ddr_get_stress_param.c) | `FUN_a00dd7fc` | Return the parameter of the memory stress test. | derived |
| [`dbg_ddr_get_test_state_byte`](../../src/leon2m/dbg/dbg_ddr_get_test_state_byte.c) | `FUN_a01182cc` | Return one byte of the stress test's state record. | derived |
| [`dbg_ddr_is_stress_enabled`](../../src/leon2m/dbg/dbg_ddr_is_stress_enabled.c) | `FUN_a00dd7f0` | Return whether the memory stress test is switched on. | proven |
| [`dbg_ddr_phy_adjust_regs`](../../src/leon2m/dbg/dbg_ddr_phy_adjust_regs.c) | `FUN_a0116914` | Adjust three registers of a memory interface with waits in between. | descriptive |
| [`dbg_ddr_phy_get_delay_c6_c7`](../../src/leon2m/dbg/dbg_ddr_phy_get_delay_c6_c7.c) | `FUN_a0115684` | Return one of the four delay nibbles in registers 0xC6/0xC7 of a memory interface. | derived |
| [`dbg_ddr_phy_get_delay_c8_c9`](../../src/leon2m/dbg/dbg_ddr_phy_get_delay_c8_c9.c) | `FUN_a011579c` | Return one of the delay values in registers 0xC8/0xC9 of a memory interface. | derived |
| [`dbg_ddr_phy_get_reg_161`](../../src/leon2m/dbg/dbg_ddr_phy_get_reg_161.c) | `FUN_a01166d8` | Return one of the registers 0x161..0x164 of a memory interface. | descriptive |
| [`dbg_ddr_phy_read_reg`](../../src/leon2m/dbg/dbg_ddr_phy_read_reg.c) | `FUN_a0114570` | Read one register of a memory interface's paged register block. | derived |
| [`dbg_ddr_phy_set_delay_c6_c7`](../../src/leon2m/dbg/dbg_ddr_phy_set_delay_c6_c7.c) | `FUN_a01158b4` | Write one of the four delay nibbles in registers 0xC6/0xC7 of a memory interface. | derived |
| [`dbg_ddr_phy_set_delay_c8_c9`](../../src/leon2m/dbg/dbg_ddr_phy_set_delay_c8_c9.c) | `FUN_a0115a44` | Write one of the delay values in registers 0xC8/0xC9 of a memory interface. | derived |
| [`dbg_ddr_phy_set_reg_161`](../../src/leon2m/dbg/dbg_ddr_phy_set_reg_161.c) | `FUN_a01167ec` | Write one of the registers 0x161..0x164 of a memory interface. | descriptive |
| [`dbg_ddr_phy_write_reg`](../../src/leon2m/dbg/dbg_ddr_phy_write_reg.c) | `FUN_a0114498` | Write one register of a memory interface's paged register block. | derived |
| [`dbg_ddr_reset_test_state`](../../src/leon2m/dbg/dbg_ddr_reset_test_state.c) | `FUN_a01181a4` | Reset the state record of the stress test. | derived |
| [`dbg_ddr_run_test_step`](../../src/leon2m/dbg/dbg_ddr_run_test_step.c) | `FUN_a0117f48` | Run one measurement of the memory stress test on a memory interface. | proven |
| [`dbg_ddr_set_result_first`](../../src/leon2m/dbg/dbg_ddr_set_result_first.c) | `FUN_a0118198` | Store the first result byte of the stress test. | descriptive |
| [`dbg_ddr_set_result_second`](../../src/leon2m/dbg/dbg_ddr_set_result_second.c) | `FUN_a0118180` | Store the second result byte of the stress test. | descriptive |
| [`dbg_ddr_set_stress_enabled`](../../src/leon2m/dbg/dbg_ddr_set_stress_enabled.c) | `FUN_a00dd808` | Switch the memory stress test on or off. | proven |
| [`dbg_ddr_set_test_state_byte`](../../src/leon2m/dbg/dbg_ddr_set_test_state_byte.c) | `FUN_a0118324` | Store one byte of the stress test's state record. | derived |
| [`dbg_ddr_stress_task`](../../src/leon2m/dbg/dbg_ddr_stress_task.c) | `FUN_a014d5f4` | Run one step of the memory stress test and print its result table. | proven |
| [`dbg_ddr_test_delay_offset`](../../src/leon2m/dbg/dbg_ddr_test_delay_offset.c) | `FUN_a0115bd4` | Shift the delay settings of a memory interface by an offset and measure the result. | derived |
| [`dbg_ddr_test_second_setting`](../../src/leon2m/dbg/dbg_ddr_test_second_setting.c) | `FUN_a0116ff4` | Change a second memory interface setting, measure the result and restore it. | derived |
| [`dbg_dump_memory_bytes`](../../src/leon2m/dbg/dbg_dump_memory_bytes.c) | `FUN_a00dd250` | Print memory as lines of address, bytes and characters. | proven |
| [`dbg_dump_memory_words`](../../src/leon2m/dbg/dbg_dump_memory_words.c) | `FUN_a00dd43c` | Print memory as lines of address and four words. | proven |
| [`dbg_get_dithering_off_flag`](../../src/leon2m/dbg/dbg_get_dithering_off_flag.c) | `FUN_a00dd6bc` | Return the flag that dbg_switch_dithering sets while dithering is off. | derived |
| [`dbg_get_dithering_off_mode2_flag`](../../src/leon2m/dbg/dbg_get_dithering_off_mode2_flag.c) | `FUN_a00dd6b0` | Return the flag that dbg_switch_dithering sets when it switched dithering off with mode 2. | derived |
| [`dbg_is_print_enabled`](../../src/leon2m/dbg/dbg_is_print_enabled.c) | `FUN_a00dd614` | Return whether a class of debug messages is switched on. | proven |
| [`dbg_parse_number`](../../src/leon2m/dbg/dbg_parse_number.c) | `FUN_a00dcd38` | Convert a text to a number, hexadecimal with 0x or decimal. | proven |
| [`dbg_print_help_list`](../../src/leon2m/dbg/dbg_print_help_list.c) | `FUN_a00dd660` | Print every line of the debug command list. | derived |
| [`dbg_print_stack_overflow`](../../src/leon2m/dbg/dbg_print_stack_overflow.c) | `FUN_a002cea8` | Print the stack pointer overflow report with the two stack check registers. | proven |
| [`dbg_print_stack_usage`](../../src/leon2m/dbg/dbg_print_stack_usage.c) | `FUN_a00dd540` | Print the highest, lowest and current stack position and whether it is in range. | proven |
| [`dbg_printf`](../../src/leon2m/dbg/dbg_printf.c) | `FUN_a00df170` | Format a message and send it to the debug serial port. | proven |
| [`dbg_send_ldc_command`](../../src/leon2m/dbg/dbg_send_ldc_command.c) | `FUN_a00dd628` | Send a command to the dimming processor and print it. | proven |
| [`dbg_send_timing_change_notice`](../../src/leon2m/dbg/dbg_send_timing_change_notice.c) | `FUN_a00dd5b8` | Print three values and send them to the input processor as a timing change notice. | proven |
| [`dbg_set_print_mask_bits`](../../src/leon2m/dbg/dbg_set_print_mask_bits.c) | `FUN_a00dd5e0` | Set or clear bits of the debug print mask. | derived |
| [`dbg_strcmp`](../../src/leon2m/dbg/dbg_strcmp.c) | `FUN_a00dd868` | Compare two texts. | proven |
| [`dbg_strlen`](../../src/leon2m/dbg/dbg_strlen.c) | `FUN_a00dd83c` | Return the length of a text. | proven |
| [`dbg_switch_dithering`](../../src/leon2m/dbg/dbg_switch_dithering.c) | `FUN_a00dd6c8` | Switch the twelve dithering units off (mode 1 or 2) or on; print 'Dithering disabled' / 'enabled'. | proven |
| [`dbg_test_register_write`](../../src/leon2m/dbg/dbg_test_register_write.c) | `FUN_a011553c` | Write a test value to register 0xCF022800 and print it before and after. | descriptive |
| [`dbg_write_memory_word`](../../src/leon2m/dbg/dbg_write_memory_word.c) | `FUN_a00dd3d4` | Store a word at an address and print it. | proven |

<a id="lib"></a>
## Library routines

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`.udiv`](../../src/leon2m/lib/udiv_a0156a6c.lib) | `FUN_a0156a6c` | Toolchain library routine .udiv (libgcc.a:_divsi3.o). | proven |
| [`.umul`](../../src/leon2m/lib/umul_a01575f4.lib) | `FUN_a01575f4` | Toolchain library routine .umul (libgcc.a:_mulsi3.o). | proven |
| [`.urem`](../../src/leon2m/lib/urem_a015e4c4.lib) | `FUN_a015e4c4` | Toolchain library routine .urem (libgcc.a:_modsi3.o). | proven |
| [`__adddf3`](../../src/leon2m/lib/__adddf3.lib) | `FUN_a01560ac` | Toolchain library routine __adddf3 (libgcc.a:_addsub_df.o). | proven |
| [`__addsf3`](../../src/leon2m/lib/__addsf3.lib) | `FUN_a015578c` | Toolchain library routine __addsf3 (libgcc.a:_addsub_sf.o). | proven |
| [`__ashldi3`](../../src/leon2m/lib/__ashldi3.lib) | `FUN_a0155104` | Toolchain library routine __ashldi3 (libgcc.a:_ashldi3.o). | proven |
| [`__divdf3`](../../src/leon2m/lib/__divdf3.lib) | `FUN_a01564b0` | Toolchain library routine __divdf3 (libgcc.a:_div_df.o). | proven |
| [`__divsf3`](../../src/leon2m/lib/__divsf3.lib) | `FUN_a0155a18` | Toolchain library routine __divsf3 (libgcc.a:_div_sf.o). | proven |
| [`__eqdf2`](../../src/leon2m/lib/__eqdf2.lib) | `FUN_a01566b0` | Toolchain library routine __eqdf2 (libgcc.a:_eq_df.o). | proven |
| [`__errno`](../../src/leon2m/lib/__errno.c) | `FUN_a01576dc` | Return the address of the current errno variable. | proven |
| [`__extendsfdf2`](../../src/leon2m/lib/__extendsfdf2.lib) | `FUN_a0155d90` | Toolchain library routine __extendsfdf2 (libgcc.a:_sf_to_df.o). | proven |
| [`__fixdfsi`](../../src/leon2m/lib/__fixdfsi.lib) | `FUN_a0156944` | Toolchain library routine __fixdfsi (libgcc.a:_df_to_si.o). | proven |
| [`__fixsfsi`](../../src/leon2m/lib/__fixsfsi.lib) | `FUN_a0155cec` | Toolchain library routine __fixsfsi (libgcc.a:_sf_to_si.o). | proven |
| [`__fixunsdfsi`](../../src/leon2m/lib/__fixunsdfsi.lib) | `FUN_a0155160` | Toolchain library routine __fixunsdfsi (libgcc.a:_fixunsdfsi.o). | proven |
| [`__fixunssfsi`](../../src/leon2m/lib/__fixunssfsi.lib) | `FUN_a01551bc` | Toolchain library routine __fixunssfsi (libgcc.a:_fixunssfsi.o). | proven |
| [`__floatsidf`](../../src/leon2m/lib/__floatsidf.lib) | `FUN_a0156840` | Toolchain library routine __floatsidf (libgcc.a:_si_to_df.o). | proven |
| [`__floatsisf`](../../src/leon2m/lib/__floatsisf.lib) | `FUN_a0155c40` | Toolchain library routine __floatsisf (libgcc.a:_si_to_sf.o). | proven |
| [`__fp_lock`](../../src/leon2m/lib/__fp_lock.c) | `FUN_a015b738` | Lock one stream unless it is a string stream; always return 0. | proven |
| [`__fp_lock_all`](../../src/leon2m/lib/__fp_lock_all.c) | `FUN_a015b780` | Take the stream-list lock and lock every open stream. | proven |
| [`__fp_unlock`](../../src/leon2m/lib/__fp_unlock.c) | `FUN_a015b75c` | Unlock one stream unless it is a string stream; always return 0. | proven |
| [`__fp_unlock_all`](../../src/leon2m/lib/__fp_unlock_all.c) | `FUN_a015b7a0` | Unlock every open stream and release the stream-list lock. | proven |
| [`__fpcmp_parts_d`](../../src/leon2m/lib/__fpcmp_parts_d.lib) | `FUN_a0157480` | Toolchain library routine __fpcmp_parts_d (libgcc.a:_fpcmp_parts_df.o). | proven |
| [`__fpcmp_parts_f`](../../src/leon2m/lib/__fpcmp_parts_f.lib) | `FUN_a015700c` | Toolchain library routine __fpcmp_parts_f (libgcc.a:_fpcmp_parts_sf.o). | proven |
| [`__gedf2`](../../src/leon2m/lib/__gedf2.lib) | `FUN_a01567dc` | Toolchain library routine __gedf2 (libgcc.a:_ge_df.o). | proven |
| [`__gesf2`](../../src/leon2m/lib/__gesf2.lib) | `FUN_a0155bdc` | Toolchain library routine __gesf2 (libgcc.a:_ge_sf.o). | proven |
| [`__gtdf2`](../../src/leon2m/lib/__gtdf2.lib) | `FUN_a0156778` | Toolchain library routine __gtdf2 (libgcc.a:_gt_df.o). | proven |
| [`__gtsf2`](../../src/leon2m/lib/__gtsf2.lib) | `FUN_a0155b78` | Toolchain library routine __gtsf2 (libgcc.a:_gt_sf.o). | proven |
| [`__ieee754_log`](../../src/leon2m/lib/__ieee754_log.lib) | `FUN_a0154ae8` | Toolchain library routine __ieee754_log (libm.a:e_log.o). | proven |
| [`__locale_charset`](../../src/leon2m/lib/__locale_charset.c) | `FUN_a015c1a8` | Return the character-set name pointer stored at 0xA802AAA8. | proven |
| [`__lshrdi3`](../../src/leon2m/lib/__lshrdi3.lib) | `FUN_a01550a8` | Toolchain library routine __lshrdi3 (libgcc.a:_lshrdi3.o). | proven |
| [`__ltdf2`](../../src/leon2m/lib/__ltdf2.c) | `FUN_a015e774` | Compare two double values for less-than (software floating point). | proven |
| [`__make_dp`](../../src/leon2m/lib/__make_dp.lib) | `FUN_a01569e0` | Toolchain library routine __make_dp (libgcc.a:_make_df.o). | proven |
| [`__make_fp`](../../src/leon2m/lib/__make_fp.lib) | `FUN_a0157130` | Toolchain library routine __make_fp (libgcc.a:_make_sf.o). | proven |
| [`__malloc_lock`](../../src/leon2m/lib/__malloc_lock.c) | `FUN_a015cc54` | Take the heap lock. | proven |
| [`__malloc_unlock`](../../src/leon2m/lib/__malloc_unlock.c) | `FUN_a015cc6c` | Release the heap lock. | proven |
| [`__mcmp`](../../src/leon2m/lib/__mcmp.lib) | `FUN_a015d4c4` | Toolchain library routine __mcmp (libc.a:mprec.o). | proven |
| [`__mdiff`](../../src/leon2m/lib/__mdiff.lib) | `FUN_a015d52c` | Toolchain library routine __mdiff (libc.a:mprec.o). | proven |
| [`__muldf3`](../../src/leon2m/lib/__muldf3.lib) | `FUN_a0156158` | Toolchain library routine __muldf3 (libgcc.a:_mul_df.o). | proven |
| [`__muldi3`](../../src/leon2m/lib/__muldi3.lib) | `FUN_a0156d1c` | Toolchain library routine __muldi3 (libgcc.a:_muldi3.o). | proven |
| [`__mulsf3`](../../src/leon2m/lib/__mulsf3.lib) | `FUN_a0155830` | Toolchain library routine __mulsf3 (libgcc.a:_mul_sf.o). | proven |
| [`__nedf2`](../../src/leon2m/lib/__nedf2.lib) | `FUN_a0156714` | Toolchain library routine __nedf2 (libgcc.a:_ne_df.o). | proven |
| [`__pack_d`](../../src/leon2m/lib/__pack_d.lib) | `FUN_a015714c` | Toolchain library routine __pack_d (libgcc.a:_pack_df.o). | proven |
| [`__pack_f`](../../src/leon2m/lib/__pack_f.lib) | `FUN_a0156dec` | Toolchain library routine __pack_f (libgcc.a:_pack_sf.o). | proven |
| [`__sclose`](../../src/leon2m/lib/__sclose.lib) | `FUN_a015e05c` | Toolchain library routine __sclose (libc.a:stdio.o). | proven |
| [`__sfmoreglue`](../../src/leon2m/lib/__sfmoreglue.lib) | `FUN_a015b4f8` | Toolchain library routine __sfmoreglue (libc.a:findfp.o). | proven |
| [`__sfp`](../../src/leon2m/lib/__sfp.lib) | `FUN_a015b624` | Toolchain library routine __sfp (libc.a:findfp.o). | proven |
| [`__sfp_lock_acquire`](../../src/leon2m/lib/__sfp_lock_acquire.c) | `FUN_a015b5f4` | Take the lock that protects the list of streams. | proven |
| [`__sfp_lock_release`](../../src/leon2m/lib/__sfp_lock_release.c) | `FUN_a015b60c` | Release the lock that protects the list of streams. | proven |
| [`__sfvwrite`](../../src/leon2m/lib/__sfvwrite.lib) | `FUN_a015bb44` | Toolchain library routine __sfvwrite (libc.a:fvwrite.o). | proven |
| [`__sinit`](../../src/leon2m/lib/__sinit.c) | `FUN_a015b558` | Initialise the standard I/O state of a reentrancy structure. | proven |
| [`__smakebuf`](../../src/leon2m/lib/__smakebuf.lib) | `FUN_a015c1fc` | Toolchain library routine __smakebuf (libc.a:makebuf.o). | proven |
| [`__sprint`](../../src/leon2m/lib/__sprint.lib) | `FUN_a0157a20` | Toolchain library routine __sprint (libc.a:vfprintf.o). | proven |
| [`__sread`](../../src/leon2m/lib/__sread.c) | `FUN_a015df44` | Read from the file behind a stream. | proven |
| [`__sseek`](../../src/leon2m/lib/__sseek.c) | `FUN_a015e008` | Move the file position of a stream. | proven |
| [`__st_pthread_mutex_destroy`](../../src/leon2m/lib/__st_pthread_mutex_destroy.c) | `FUN_a015e9d8` | Call the optional mutex-destroy hook; return 0 when none is installed. | proven |
| [`__st_pthread_mutex_init`](../../src/leon2m/lib/__st_pthread_mutex_init.c) | `FUN_a015e9a4` | Call the optional mutex-init hook; return 0 when none is installed. | proven |
| [`__st_pthread_mutex_lock`](../../src/leon2m/lib/__st_pthread_mutex_lock.c) | `FUN_a015ea08` | Call the optional mutex-lock hook; return 0 when none is installed. | proven |
| [`__st_pthread_mutex_trylock`](../../src/leon2m/lib/__st_pthread_mutex_trylock.c) | `FUN_a015ea38` | Call the optional mutex-trylock hook; return 0 when none is installed. | derived |
| [`__st_pthread_mutex_unlock`](../../src/leon2m/lib/__st_pthread_mutex_unlock.c) | `FUN_a015ea68` | Call the optional mutex-unlock hook; return 0 when none is installed. | proven |
| [`__st_pthread_mutexattr_destroy`](../../src/leon2m/lib/__st_pthread_mutexattr_destroy.c) | `FUN_a015eac8` | Call the optional mutex-attribute-destroy hook; return 0 when none is installed. | proven |
| [`__st_pthread_mutexattr_init`](../../src/leon2m/lib/__st_pthread_mutexattr_init.c) | `FUN_a015ea98` | Call the optional mutex-attribute-init hook; return 0 when none is installed. | proven |
| [`__st_pthread_mutexattr_settype`](../../src/leon2m/lib/__st_pthread_mutexattr_settype.c) | `FUN_a015eaf8` | Call the optional mutex-attribute-settype hook; return 0 when none is installed. | proven |
| [`__subdf3`](../../src/leon2m/lib/__subdf3.lib) | `FUN_a01560fc` | Toolchain library routine __subdf3 (libgcc.a:_addsub_df.o). | proven |
| [`__subsf3`](../../src/leon2m/lib/__subsf3.lib) | `FUN_a01557d8` | Toolchain library routine __subsf3 (libgcc.a:_addsub_sf.o). | proven |
| [`__swrite`](../../src/leon2m/lib/__swrite.lib) | `FUN_a015df90` | Toolchain library routine __swrite (libc.a:stdio.o). | proven |
| [`__swsetup`](../../src/leon2m/lib/__swsetup.lib) | `FUN_a0159cf0` | Toolchain library routine __swsetup (libc.a:wsetup.o). | proven |
| [`__truncdfsf2`](../../src/leon2m/lib/__truncdfsf2.lib) | `FUN_a0156a0c` | Toolchain library routine __truncdfsf2 (libgcc.a:_df_to_sf.o). | proven |
| [`__udivdi3`](../../src/leon2m/lib/__udivdi3.lib) | `FUN_a0155208` | Toolchain library routine __udivdi3 (libgcc.a:_udivdi3.o). | proven |
| [`__unpack_d`](../../src/leon2m/lib/__unpack_d.lib) | `FUN_a015734c` | Toolchain library routine __unpack_d (libgcc.a:_unpack_df.o). | proven |
| [`__unpack_f`](../../src/leon2m/lib/__unpack_f.lib) | `FUN_a0156f34` | Toolchain library routine __unpack_f (libgcc.a:_unpack_sf.o). | proven |
| [`_b2d`](../../src/leon2m/lib/_b2d.lib) | `FUN_a015d700` | Toolchain library routine _b2d (libc.a:mprec.o). | proven |
| [`_Balloc`](../../src/leon2m/lib/_Balloc.lib) | `FUN_a015cc84` | Toolchain library routine _Balloc (libc.a:mprec.o). | proven |
| [`_Bfree`](../../src/leon2m/lib/_Bfree.c) | `FUN_a015cd28` | Return a big-number buffer to the free list (number formatting). | proven |
| [`_calloc_r`](../../src/leon2m/lib/_calloc_r.lib) | `FUN_a015e174` | Toolchain library routine _calloc_r (libc.a:callocr.o). | proven |
| [`_cleanup`](../../src/leon2m/lib/_cleanup.c) | `FUN_a015b5dc` | Flush and close all open streams of the global reentrancy structure. | proven |
| [`_cleanup_r`](../../src/leon2m/lib/_cleanup_r.c) | `FUN_a015b5c4` | Flush and close all open streams of a reentrancy structure. | proven |
| [`_close_r`](../../src/leon2m/lib/_close_r.c) | `FUN_a015e224` | Close a file descriptor (reentrant wrapper). | proven |
| [`_d2b`](../../src/leon2m/lib/_d2b.lib) | `FUN_a015d7f0` | Toolchain library routine _d2b (libc.a:mprec.o). | proven |
| [`_dtoa_r`](../../src/leon2m/lib/_dtoa_r.lib) | `FUN_a015a038` | Toolchain library routine _dtoa_r (libc.a:dtoa.o). | proven |
| `_dtoa_r_jump_table` | `switchdataD_a0159e28` | Jump table 1 of the switch statements in _dtoa_r. | proven |
| [`_fclose_r`](../../src/leon2m/lib/_fclose_r.lib) | `FUN_a015e25c` | Toolchain library routine _fclose_r (libc.a:fclose.o). | proven |
| [`_fpadd_parts`](../../src/leon2m/lib/_fpadd_parts.lib) | `FUN_a015555c` | Toolchain library routine _fpadd_parts (libgcc.a:_addsub_sf.o). | proven |
| [`_fpadd_parts_copy2`](../../src/leon2m/lib/_fpadd_parts_copy2.lib) | `FUN_a0155de0` | Toolchain library routine _fpadd_parts (libgcc.a:_addsub_df.o). | proven |
| [`_free_r`](../../src/leon2m/lib/_free_r.lib) | `FUN_a015b8c0` | Toolchain library routine _free_r (libc.a:freer.o). | proven |
| [`_fstat`](../../src/leon2m/lib/_fstat.c) | `FUN_a015e7e0` | Report every file as a character device: set st_mode to 0x2000 and return 0. | proven |
| [`_fstat_r`](../../src/leon2m/lib/_fstat_r.c) | `FUN_a015e408` | Get the status of a file descriptor (reentrant wrapper). | proven |
| [`_fwalk`](../../src/leon2m/lib/_fwalk.lib) | `FUN_a015bf7c` | Toolchain library routine _fwalk (libc.a:fwalk.o). | proven |
| [`_fwalk_reent`](../../src/leon2m/lib/_fwalk_reent.lib) | `FUN_a015c058` | Toolchain library routine _fwalk_reent (libc.a:fwalk.o). | proven |
| [`_hi0bits`](../../src/leon2m/lib/_hi0bits.lib) | `FUN_a015cef8` | Toolchain library routine _hi0bits (libc.a:mprec.o). | proven |
| [`_i2b`](../../src/leon2m/lib/_i2b.c) | `FUN_a015d048` | Make a big number from an integer (number formatting). | proven |
| [`_lo0bits`](../../src/leon2m/lib/_lo0bits.lib) | `FUN_a015cf78` | Toolchain library routine _lo0bits (libc.a:mprec.o). | proven |
| [`_localeconv_r`](../../src/leon2m/lib/_localeconv_r.c) | `FUN_a015c1b4` | Return the address of the static locale conventions record. | proven |
| [`_lseek`](../../src/leon2m/lib/_lseek.c) | `FUN_a015e7fc` | Fail every seek: set errno to 29 (ESPIPE) and return -1. | proven |
| [`_lseek_r`](../../src/leon2m/lib/_lseek_r.c) | `FUN_a015e444` | Move the position of a file descriptor (reentrant wrapper). | proven |
| [`_lshift`](../../src/leon2m/lib/_lshift.lib) | `FUN_a015d3b0` | Toolchain library routine _lshift (libc.a:mprec.o). | proven |
| [`_malloc_r`](../../src/leon2m/lib/_malloc_r.lib) | `FUN_a015c35c` | Toolchain library routine _malloc_r (libc.a:mallocr.o). | proven |
| [`_malloc_trim_r`](../../src/leon2m/lib/_malloc_trim_r.lib) | `FUN_a015b7c4` | Toolchain library routine _malloc_trim_r (libc.a:freer.o). | proven |
| [`_mprec_log10`](../../src/leon2m/lib/_mprec_log10.lib) | `FUN_a015d994` | Toolchain library routine _mprec_log10 (libc.a:mprec.o). | proven |
| [`_multadd`](../../src/leon2m/lib/_multadd.lib) | `FUN_a015cd54` | Toolchain library routine _multadd (libc.a:mprec.o). | proven |
| [`_multiply`](../../src/leon2m/lib/_multiply.lib) | `FUN_a015d06c` | Toolchain library routine _multiply (libc.a:mprec.o). | proven |
| [`_pow5mult`](../../src/leon2m/lib/_pow5mult.lib) | `FUN_a015d288` | Toolchain library routine _pow5mult (libc.a:mprec.o). | proven |
| [`_ratio`](../../src/leon2m/lib/_ratio.lib) | `FUN_a015d918` | Toolchain library routine _ratio (libc.a:mprec.o). | proven |
| [`_read_r`](../../src/leon2m/lib/_read_r.c) | `FUN_a015e484` | Read from a file descriptor (reentrant wrapper). | proven |
| [`_realloc_r`](../../src/leon2m/lib/_realloc_r.lib) | `FUN_a015d9e4` | Toolchain library routine _realloc_r (libc.a:reallocr.o). | proven |
| [`_s2b`](../../src/leon2m/lib/_s2b.lib) | `FUN_a015ce30` | Toolchain library routine _s2b (libc.a:mprec.o). | proven |
| [`_sbrk_r`](../../src/leon2m/lib/_sbrk_r.c) | `FUN_a015df0c` | Grow the heap by a number of bytes (reentrant wrapper). | proven |
| [`_setlocale_r`](../../src/leon2m/lib/_setlocale_r.c) | `FUN_a015c138` | Accept only the C locale; store category and locale name in the reentrancy structure. | proven |
| [`_sprintf_r`](../../src/leon2m/lib/_sprintf_r.lib) | `FUN_a0157798` | Toolchain library routine _sprintf_r (libc.a:sprintf.o). | proven |
| [`_ulp`](../../src/leon2m/lib/_ulp.lib) | `FUN_a015d690` | Toolchain library routine _ulp (libc.a:mprec.o). | proven |
| [`_vfprintf_r`](../../src/leon2m/lib/_vfprintf_r.lib) | `FUN_a0157a60` | Toolchain library routine _vfprintf_r (libc.a:vfprintf.o). | proven |
| `_vfprintf_r_jump_table` | `switchdataD_a01578bc` | Jump table 1 of the switch statements in _vfprintf_r. | proven |
| [`_vsnprintf_r`](../../src/leon2m/lib/_vsnprintf_r.lib) | `FUN_a0159658` | Toolchain library routine _vsnprintf_r (libc.a:vsnprintf.o). | proven |
| [`_wcrtomb_r`](../../src/leon2m/lib/_wcrtomb_r.lib) | `FUN_a01596b8` | Toolchain library routine _wcrtomb_r (libc.a:wcrtomb.o). | proven |
| [`_wcsrtombs_r`](../../src/leon2m/lib/_wcsrtombs_r.lib) | `FUN_a0159734` | Toolchain library routine _wcsrtombs_r (libc.a:wcsrtombs.o). | proven |
| [`_wctomb_r`](../../src/leon2m/lib/_wctomb_r.lib) | `FUN_a0159870` | Toolchain library routine _wctomb_r (libc.a:wctomb_r.o). | proven |
| [`_write_r`](../../src/leon2m/lib/_write_r.c) | `FUN_a015e134` | Write to a file descriptor (reentrant wrapper). | proven |
| [`ceil`](../../src/leon2m/lib/ceil.lib) | `FUN_a01547dc` | Toolchain library routine ceil (libm.a:s_ceil.o). | proven |
| [`fclose`](../../src/leon2m/lib/fclose.lib) | `FUN_a015e3ec` | Toolchain library routine fclose (libc.a:fclose.o). | proven |
| [`fflush`](../../src/leon2m/lib/fflush.lib) | `FUN_a015b300` | Toolchain library routine fflush (libc.a:fflush.o). | proven |
| [`inbyte`](../../src/leon2m/lib/inbyte.lib) | `FUN_a015e970` | Toolchain library routine inbyte (libleonbare.a:io.o). | proven |
| [`isatty`](../../src/leon2m/lib/isatty.c) | `FUN_a015e7f4` | Tell whether a file descriptor is a terminal. | proven |
| [`isinf`](../../src/leon2m/lib/isinf.lib) | `FUN_a015ded4` | Toolchain library routine isinf (libc.a:s_isinf.o). | proven |
| [`isnan`](../../src/leon2m/lib/isnan.lib) | `FUN_a0155074` | Toolchain library routine isnan (libc.a:s_isnan.o). | proven |
| [`lib_byte_chain_add_0x0e`](../../src/leon2m/lib/lib_byte_chain_add_0x0e.c) | `FUN_a0029604` | Return lib_byte_chain_add_0x21(c) + 0x0E as a byte. | descriptive |
| [`lib_byte_chain_add_0x21`](../../src/leon2m/lib/lib_byte_chain_add_0x21.c) | `FUN_a00295f4` | Return c + 0x21 as a byte. | descriptive |
| [`lib_byte_chain_halve`](../../src/leon2m/lib/lib_byte_chain_halve.c) | `FUN_a002961c` | Return lib_byte_chain_add_0x0e(c) shifted right by one. | descriptive |
| [`lib_byte_chain_identity`](../../src/leon2m/lib/lib_byte_chain_identity.c) | `FUN_a00295ec` | Return the byte argument unchanged. | descriptive |
| [`lib_byte_chain_offset_0x0b`](../../src/leon2m/lib/lib_byte_chain_offset_0x0b.c) | `FUN_a0029660` | Return lib_byte_chain_triple(c + 0x0B) as a byte. | descriptive |
| [`lib_byte_chain_offset_0x1e`](../../src/leon2m/lib/lib_byte_chain_offset_0x1e.c) | `FUN_a00296b8` | Return lib_byte_chain_triple(c + 0x1E) as a byte. | descriptive |
| [`lib_byte_chain_offset_0x2d`](../../src/leon2m/lib/lib_byte_chain_offset_0x2d.c) | `FUN_a0029710` | Return lib_byte_chain_triple(c + 0x2D) as a byte. | descriptive |
| [`lib_byte_chain_offset_0x3c`](../../src/leon2m/lib/lib_byte_chain_offset_0x3c.c) | `FUN_a0029794` | Return lib_byte_chain_triple(c + 0x3C) as a byte. | descriptive |
| [`lib_byte_chain_offset_0x3f`](../../src/leon2m/lib/lib_byte_chain_offset_0x3f.c) | `FUN_a00297c0` | Return lib_byte_chain_triple(c + 0x3F) as a byte. | descriptive |
| [`lib_byte_chain_offset_0x15`](../../src/leon2m/lib/lib_byte_chain_offset_0x15.c) | `FUN_a002968c` | Return lib_byte_chain_triple(c + 0x15) as a byte. | descriptive |
| [`lib_byte_chain_offset_0x26`](../../src/leon2m/lib/lib_byte_chain_offset_0x26.c) | `FUN_a00296e4` | Return lib_byte_chain_triple(c + 0x26) as a byte. | descriptive |
| [`lib_byte_chain_offset_0x33`](../../src/leon2m/lib/lib_byte_chain_offset_0x33.c) | `FUN_a002973c` | Return lib_byte_chain_triple(c + 0x33) as a byte. | descriptive |
| [`lib_byte_chain_offset_0x38`](../../src/leon2m/lib/lib_byte_chain_offset_0x38.c) | `FUN_a0029768` | Return lib_byte_chain_triple(c + 0x38) as a byte. | descriptive |
| [`lib_byte_chain_offset_0x41`](../../src/leon2m/lib/lib_byte_chain_offset_0x41.c) | `FUN_a00297ec` | Return lib_byte_chain_triple(c + 0x41) as a byte. | descriptive |
| [`lib_byte_chain_triple`](../../src/leon2m/lib/lib_byte_chain_triple.c) | `FUN_a0029638` | Return lib_byte_chain_halve(c) * 3 as a byte. | descriptive |
| [`lib_crc16_ccitt_update`](../../src/leon2m/lib/lib_crc16_ccitt_update.c) | `FUN_a00cea70` | Add one byte to a CRC-16 (polynomial 0x1021, MSB first) | proven |
| [`lib_extract_bits`](../../src/leon2m/lib/lib_extract_bits.c) | `FUN_a00f99e8` | Return the bits from position lo to hi of a value. | derived |
| [`lib_rgb_to_hue`](../../src/leon2m/lib/lib_rgb_to_hue.c) | `FUN_a00b9c68` | Return the hue angle (0..359) of an RGB colour, or 0xFFFF for grey. | proven |
| [`localeconv`](../../src/leon2m/lib/localeconv.c) | `FUN_a015c1e4` | Return the numeric formatting conventions of the C locale. | proven |
| [`log`](../../src/leon2m/lib/log.lib) | `FUN_a0154980` | Toolchain library routine log (libm.a:w_log.o). | proven |
| [`matherr`](../../src/leon2m/lib/matherr.c) | `FUN_a01550a0` | Report a maths library error; the default handler returns 0. | proven |
| [`memchr`](../../src/leon2m/lib/memchr.lib) | `FUN_a015ca50` | Toolchain library routine memchr (libc.a:memchr.o). | proven |
| [`memcpy`](../../src/leon2m/lib/memcpy.c) | `FUN_a013c910` | Copy n bytes from src to dst. | proven |
| [`memmove`](../../src/leon2m/lib/memmove.lib) | `FUN_a015cb28` | Toolchain library routine memmove (libc.a:memmove.o). | proven |
| [`memset`](../../src/leon2m/lib/memset.lib) | `FUN_a01576e8` | Toolchain library routine memset (libc.a:memset.o). | proven |
| [`outbyte`](../../src/leon2m/lib/outbyte.lib) | `FUN_a015e928` | Toolchain library routine outbyte (libleonbare.a:io.o). | proven |
| [`quorem`](../../src/leon2m/lib/quorem.lib) | `FUN_a0159e40` | Toolchain library routine quorem (libc.a:dtoa.o). | proven |
| [`read`](../../src/leon2m/lib/read.lib) | `FUN_a015e818` | Toolchain library routine read (libleonbare.a:read.o). | proven |
| [`sbrk`](../../src/leon2m/lib/sbrk.lib) | `FUN_a015e880` | Toolchain library routine sbrk (libnosys.a:sbrk.o). | proven |
| [`setlocale`](../../src/leon2m/lib/setlocale.c) | `FUN_a015c1c0` | Set the locale through _setlocale_r with the global reentrancy structure. | proven |
| [`sprintf`](../../src/leon2m/lib/sprintf.lib) | `FUN_a01577f4` | Toolchain library routine sprintf (libc.a:sprintf.o). | proven |
| [`std`](../../src/leon2m/lib/std.lib) | `FUN_a015b468` | Toolchain library routine std (libc.a:findfp.o). | proven |
| [`strcmp`](../../src/leon2m/lib/strcmp.lib) | `FUN_a015e078` | Toolchain library routine strcmp (libc.a:strcmp.o). | proven |
| [`strlen`](../../src/leon2m/lib/strlen.lib) | `FUN_a0157858` | Toolchain library routine strlen (libc.a:strlen.o). | proven |
| [`vfprintf`](../../src/leon2m/lib/vfprintf.lib) | `FUN_a01595c8` | Toolchain library routine vfprintf (libc.a:vfprintf.o). | proven |
| [`vsnprintf`](../../src/leon2m/lib/vsnprintf.lib) | `FUN_a01595f4` | Toolchain library routine vsnprintf (libc.a:vsnprintf.o). | proven |
| [`wcrtomb`](../../src/leon2m/lib/wcrtomb.lib) | `FUN_a0159708` | Toolchain library routine wcrtomb (libc.a:wcrtomb.o). | proven |
| [`wcsrtombs`](../../src/leon2m/lib/wcsrtombs.c) | `FUN_a0159840` | Convert a wide-character string to multibyte using the global reentrancy structure. | proven |
| [`write`](../../src/leon2m/lib/write.lib) | `FUN_a015e8b0` | Toolchain library routine write (libleonbare.a:write.o). | proven |
