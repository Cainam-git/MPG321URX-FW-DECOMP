# Data names: Tensilica program (dimming processor)

61 entries from `symbols/tensilica.data.json`, in address order (RAM addresses). The labelled ones are renamed in the assembly source by `tools/names/xt_apply.py`; addresses that the code writes as plain numbers have no label, and their names are used only in the comments. The *basis* column has the same meaning as for the function names.

| Basis | Entries |
|---|---:|
| proven | 25 |
| derived | 29 |
| descriptive | 7 |

## Initialised data (data.S)

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `ldc_dimming_settings` | `data_3ffe2390` | Dimming settings: channel count, GainFilterMode, ADIM_Min/Max, usUserPDIM/ADIM, gains. | proven |
| `ldc_gain_table_anv1` | `data_3ffe23e0` | Gain table ANV1: 5 {x, y} word pairs | proven |
| `ldc_gain_table_flat` | `data_3ffe2410` | Gain table of 2 points {0, 0x400}, {0xFF, 0x400}, loaded for table number 0 | derived |
| `ldc_gain_table_anv2` | `data_3ffe2420` | Gain table ANV2: 5 {x, y} word pairs | proven |
| `ldc_gain_table_anv3` | `data_3ffe2450` | Gain table ANV3: 5 {x, y} word pairs | proven |
| `ldc_adim_curve_points` | `data_3ffe2480` | Point table {x, y}[2] = {0,0},{0xFFC,0x3FF} of ldc_adim_map_through_curve | derived |
| `ldc_filter_weights_16_32_64` | `data_3ffe2490` | 3x3 weights 16 32 16 / 32 64 32 / 16 32 16 of ldc_filter_grid_3x3 | derived |
| `ldc_filter_weights_28_32` | `data_3ffe24c0` | 3x3 weights 28 everywhere, 32 in the centre, of ldc_filter_grid_3x3 | derived |
| `ldc_first_current_on` | `data_3ffe2570` | 1 until the first 'current on' of command 0x38 (longer wait the first time) | derived |
| `ldc_input_duty_flag` | `data_3ffe2574` | Flag kept by ldc_check_input_duty_edges (1 at start) | descriptive |
| `ldc_kept_global_gain` | `data_3ffe2580` | Kept global gain (scaled by 256) of ldc_smooth_and_apply_global_gain | derived |
| `ldc_command_table` | `data_3ffe2590` | Mailbox command table: pairs of command code and handler routine. | derived |
| `dbg_memcmd_verbose` | `data_3ffe2700` | Byte flag: echo, prompt and mr row headers of the second console on/off (set by 'md') | derived |
| `dbg_uart_config` | `data_3ffe2704` | Serial port set-up record (first word 115200) passed to uart_init | derived |
| `dbg_memcmd_table` | `data_3ffe2720` | Command table {name, handler} of the second console: mr, mw, md, cfg | proven |
| `dbg_help_texts` | `data_3ffe2740` | NULL-terminated list of the help texts printed by 'help' | proven |
| `ldc_segment_count` | `data_3ffe2760` | Number of segments (columns x rows) of the segment grid. | derived |
| `ldc_dpll_init_done` | `data_3ffe2764` | Flag set by command 0x40; the per-frame pass runs only while it is not 0 | proven |
| `ldc_hw_default_registers` | `data_3ffe2770` | 59 {register address, value} pairs written at start-up | proven |
| `ldc_as3824_last_led_mode` | `data_3ffe2a20` | LED_Mode last handled by ldc_as3824_update (starts at 3) | derived |
| `ldc_level_curve` | `data_3ffe2a30` | 8 {x, y} points (x 0..100, y 0x580..0x140) used by ldc_level_curve_value | descriptive |
| `irq_enable_state` | `data_3ffe2a78` | +0 enabled interrupt bits, +4 allowed bits (INTENABLE = enabled & allowed) | proven |
| `irq_handler_table` | `data_3ffe2a80` | 22 entries {handler, arg}; interrupt n at +8*(21-n); default irq_default_handler with arg n | proven |
| `irq_level5_handler_address` | `data_3ffe2be0` | Word holding irq_dispatch_level5, put back into EXCSAVE5 on every level-5 entry | proven |

## RAM without initial values (plain addresses in the code)

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `ldc_adim_kept_values` | `0x3ffe3db0` | Kept ADIM per channel (u32[32], scaled by 256) of ldc_adim_smooth_toward_target | derived |
| `ldc_pdim_kept_values` | `0x3ffe3e30` | Kept PDIM per channel (u32[32], scaled by 256) of ldc_pdim_smooth_toward_target | derived |
| `ldc_ramp_kept_level` | `0x3ffe3f34` | Level kept by ldc_ramp_level_over_time | descriptive |
| `ldc_adim_hold_start` | `0x3ffe3f38` | Tick count when the ADIM hold started | descriptive |
| `ldc_adim_hold_active` | `0x3ffe3f3c` | ADIM hold flag of ldc_adim_hold_on_sudden_rise | descriptive |
| `ldc_adim_previous_average` | `0x3ffe3f40` | Previous average of the merged channel values | descriptive |
| `ldc_debug_dump_call_count` | `0x3ffe3f44` | Call counter of ldc_print_debug_dump (periodic print every 180) | proven |
| `ldc_kept_ldc_mode` | `0x3ffe3f48` | Last LDC_Mode applied by ldc_follow_mode_and_run_led_driver | proven |
| `ldc_led_driver_wait_count` | `0x3ffe3f4c` | Passes counted since the last LDC_Mode change | proven |
| `ldc_led_driver_wait_length` | `0x3ffe3f50` | Passes to wait after a mode change before the LED driver runs (1 or 2) | proven |
| `ldc_command_index` | `0x3ffe3f60` | Word per command number: position in ldc_command_table | proven |
| `dbg_memcmd_line_state` | `0x3ffe41c0` | Second console line state: +0 length, +1 line complete | proven |
| `dbg_memcmd_line` | `0x3ffe41d0` | Second console line buffer (64 characters + end at 0x3FFE4210) | proven |
| `lib_heap_state` | `0x3ffe4220` | Heap record: +0 u8 ready, +4 pointer to the free-list head | derived |
| `lib_heap_list_head` | `0x3ffe4230` | Free-list head {+0 first free block, +4 pool size} | derived |
| `dbg_console_state` | `0x3ffe4240` | Console record: word count, *xx request, hex mode, line length, request mode | derived |
| `timer_tick_state` | `0x3ffe4438` | Pending tick counts and callbacks of timers 0 and 1 | derived |
| `ldc_segment_grid` | `0x3ffe4450` | Grid record: +0 columns, +4 rows, +16/+20 panel width/height, +24/+28 zone exponents, +48 DS divider | derived |
| `ldc_segment_values` | `0x3ffe4490` | u16[2048] segment values read from 0xE0083000 every interrupt | derived |
| `ldc_unit_words` | `0x3ffe5490` | u32[4] per-unit words written to 0xC0197000 + k*0x1000 (bit 12 set by ldc_unit_set_mode_bits) | descriptive |
| `AS3824Buf` | `0x3ffe54a0` | AS3824 register mirror: DevAddr..HdrMode, BDAC[16], PWM_HT[16], order[16], init_done | proven |
| `ldc_as3824_last_ldc_mode` | `0x3ffe5590` | LDC_Mode last handled by ldc_as3824_update | derived |
| `ldc_direct_pwm_on` | `0x3ffe5594` | 1 while direct PWM is on for driver type 0; ldc_led_driver_type0_update then sends nothing | derived |
| `timer_state` | `0x3ffe5598` | t0 {one_shot u8,period,callback} +0, t1 +12, tick_count +24, tick_callback +28, tick_wraps +32 | derived |
| `lib_vsprintf_digits` | `0x3ffe5690` | lib_vsprintf digit stack, one digit per word; width end = this + width*4 | derived |
| `lib_vsprintf_staging` | `0x3ffe59b0` | lib_vsprintf output staging, one character per 32-bit word | derived |
| `uart_rx_state` | `0x3ffe5cd0` | +0 copy of 0xE00A0008 value, +4 ring[128] words, +0x204 head, +0x208 tail | derived |
| `irq_sw_pending` | `0x3ffe5edc` | Set by irq_sw_handler; main loop prints 'SW_IRQ!!' and clears it | derived |
| `ldc_irq_pending` | `0x3ffe5ee0` | Set by ldc_irq_handler; main loop runs ldc_run_pass_on_new_frame and clears it | derived |
| `irq_level5_save_area` | `0x3ffe62f0` | Save area and stack of the level-5 dispatcher: special registers, then registers 0..31 at +52 | proven |

## Read-only data (rodata.S)

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `ldc_pass_record_init` | `ro_3ffe0494` | 32 zero bytes copied into the pass record at the start of each pass | proven |
| `dbg_command_table` | `ro_3ffe0630` | Debug command table {name[32], handler}: mem wmem mdw mww gpio help rsa msg1 msg0 | proven |
| `lib_decimal_digit_texts` | `ro_3ffe15d0` | Texts '0'..'9', two bytes each, used by lib_vsprintf for decimal digits | derived |
| `lib_vsprintf_conv_table` | `ro_3ffe1630` | Switch table of lib_vsprintf, index conversion character - 'P' (41 entries) | proven |
| `trap_exception_cause_table` | `ro_3ffe19fc` | Handler per EXCCAUSE 0..5 read by the user exception vector (cause 6+ uses entry 0) | proven |
| `sys_region_attribute_rank` | `ro_3ffe1a20` | Signed byte per attribute 0..15: rank used to keep the higher attribute (flag 0x100) | derived |
| `irq_level_of_interrupt` | `ro_3ffe1a30` | Byte per interrupt 0..21: its level (1,2,3,4,5,7); handlers refused for 7 and above | proven |
