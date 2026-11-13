# Function names: Tensilica program (dimming processor)

301 entries from `symbols/tensilica.names.json`, grouped by subject and listed by name; the label of each entry gives its address. [Function names](../NAMES.md) describes how the names were given and what the *basis* column means. A name with a link has a source file of its own, in the folder of its subject (`src/tensilica/<subject>/`); the other entries are jump tables, library members and entry points inside another function's file.

| Basis | Entries |
|---|---:|
| proven | 112 |
| derived | 124 |
| descriptive | 65 |

## Subjects

- [Start-up](#startup) (1)
- [Traps and crash handling](#trap) (4)
- [Interrupts](#irq) (18)
- [Timers and delays](#timer) (25)
- [System control: channels, modes, configuration](#sys) (9)
- [Dimming processor and its hardware block](#ldc) (148)
- [Pins](#gpio) (9)
- [Serial ports](#uart) (16)
- [Register access](#reg) (10)
- [Debug facilities](#dbg) (27)
- [Library routines](#lib) (34)

<a id="startup"></a>
## Start-up

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`startup_zero_bss_and_run_main`](../../src/tensilica/startup/startup_zero_bss_and_run_main.S) | `fn_40000800` | Set stack and PS, zero RAM 0x3FFE2BF0..0x3FFE6447, call the main routine; never returns. | proven |

<a id="trap"></a>
## Traps and crash handling

| Name | Label | What it does | Basis |
|---|---|---|---|
| `trap_alloca_handler` | `fn_40000010` | Exception cause 5: reload the caller's register window through the window underflow code | derived |
| [`trap_break_on_other_cause`](../../src/tensilica/trap/trap_break_on_other_cause.S) | `fn_4000abcc` | Exception causes 0, 2, 3: restore a2/a3, execute BREAK 1,1 and return to EPC1 | derived |
| [`trap_syscall_handler`](../../src/tensilica/trap/trap_syscall_handler.S) | `fn_4000a458` | Exception cause 1: resume 3 bytes on; code 0 runs a call12 window pass and returns 0, else -1 | derived |
| [`trap_syscall_touch_a15`](../../src/tensilica/trap/trap_syscall_touch_a15.S) | `fn_4000a4b8` | Open a window, write a15 to itself and return; holds the -1 exit of trap_syscall_handler | descriptive |

<a id="irq"></a>
## Interrupts

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`irq_block_start_and_wait`](../../src/tensilica/irq/irq_block_start_and_wait.S) | `fn_40008ec4` | Write 1 to 0xE00A1004 and wait until its bit 0 reads 0 | descriptive |
| [`irq_clear`](../../src/tensilica/irq/irq_clear.S) | `fn_4000ab7c` | Write a mask to INTCLEAR to clear pending interrupts | proven |
| [`irq_default_handler`](../../src/tensilica/irq/irq_default_handler.S) | `fn_4000ab5c` | Execute BREAK 1,15: the handler of every interrupt that has none installed | proven |
| [`irq_disable`](../../src/tensilica/irq/irq_disable.S) | `fn_4000a548` | Remove mask bits from the enabled word and write INTENABLE; return the old enabled word | proven |
| [`irq_dispatch_level1`](../../src/tensilica/irq/irq_dispatch_level1.S) | `fn_4000a570` | Exception cause 4: run handlers of pending enabled interrupts, highest bit first | proven |
| [`irq_dispatch_level3`](../../src/tensilica/irq/irq_dispatch_level3.S) | `fn_4000a680` | Run handlers of pending interrupts 9, 10, 11, 21 (lowest bit first); return with rfi 3 | proven |
| [`irq_dispatch_level5`](../../src/tensilica/irq/irq_dispatch_level5.S) | `fn_4000a74c` | Save all registers to 0x3FFE62F0, run the interrupt-13 handler, restore, rfi 5 | proven |
| [`irq_enable`](../../src/tensilica/irq/irq_enable.S) | `fn_4000a524` | Add mask bits to the enabled word and write INTENABLE; return the old enabled word | proven |
| [`irq_install_step_empty`](../../src/tensilica/irq/irq_install_step_empty.S) | `fn_4000ab64` | Do nothing; called after irq_set_handler for interrupts 0, 2, 6 and 9 | descriptive |
| [`irq_install_step_empty_tick`](../../src/tensilica/irq/irq_install_step_empty_tick.S) | `fn_4000ab74` | Do nothing; called after irq_set_handler for interrupt 13 (tick) | descriptive |
| [`irq_install_step_empty_timer1`](../../src/tensilica/irq/irq_install_step_empty_timer1.S) | `fn_4000ab6c` | Do nothing; called after irq_set_handler for interrupt 10 (timer 1) | descriptive |
| [`irq_line_ack`](../../src/tensilica/irq/irq_line_ack.S) | `fn_40008de4` | Pulse a line's +0x30 bit and write 1 << line to 0xE00A1070 | derived |
| [`irq_line_config`](../../src/tensilica/irq/irq_line_config.S) | `fn_40008ce0` | Pulse a line's +0x30 bit and set/clear its bit+16 in the line's 0xE00A10xx word | descriptive |
| [`irq_line_init`](../../src/tensilica/irq/irq_line_init.S) | `fn_40008c60` | Set or clear line bit n in 0xE00A106C, write 0xE00A1070, clear bit in 0xE00A1068 | descriptive |
| [`irq_set_handler`](../../src/tensilica/irq/irq_set_handler.S) | `fn_4000a514` | Install a handler for interrupt n with n as its argument | proven |
| [`irq_set_handler_and_arg`](../../src/tensilica/irq/irq_set_handler_and_arg.S) | `fn_4000a4c8` | Store handler and argument for interrupt n (0..21, level < 7); return previous non-default handler | proven |
| [`irq_sw_handler`](../../src/tensilica/irq/irq_sw_handler.S) | `fn_40008e88` | Interrupt 0 handler: set the SW_IRQ flag and acknowledge line 0 | derived |
| [`irq_sw_install`](../../src/tensilica/irq/irq_sw_install.S) | `fn_40008e9c` | Install irq_sw_handler for interrupt 0, enable it and set up line 0 | derived |

<a id="timer"></a>
## Timers and delays

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`timer_arm_timer0`](../../src/tensilica/timer/timer_arm_timer0.S) | `fn_4000908c` | Store timer 0 mode, period and callback; arm CCOMPARE0 and enable interrupt 6 | derived |
| [`timer_arm_timer1`](../../src/tensilica/timer/timer_arm_timer1.S) | `fn_400090c8` | Store timer 1 mode, period and callback; arm CCOMPARE1 and enable interrupt 10 | derived |
| [`timer_count_tick_timer0`](../../src/tensilica/timer/timer_count_tick_timer0.S) | `fn_40005e44` | Timer 0 callback: count one pending tick | derived |
| [`timer_count_tick_timer1`](../../src/tensilica/timer/timer_count_tick_timer1.S) | `fn_40005e74` | Timer 1 callback: count one pending tick | derived |
| [`timer_read_compare`](../../src/tensilica/timer/timer_read_compare.S) | `fn_4000ac08` | Return CCOMPARE0, 1 or 2 (0 for other numbers) | proven |
| [`timer_read_cycle_count`](../../src/tensilica/timer/timer_read_cycle_count.S) | `fn_4000abdc` | Return CCOUNT | proven |
| [`timer_read_ticks`](../../src/tensilica/timer/timer_read_ticks.S) | `fn_400091a4` | Return the tick count read with interrupts masked | derived |
| [`timer_run_pending_callbacks`](../../src/tensilica/timer/timer_run_pending_callbacks.S) | `fn_40005ea4` | Take one pending tick per timer and call that timer's stored callback | derived |
| [`timer_service_tick`](../../src/tensilica/timer/timer_service_tick.S) | `fn_4000902c` | Interrupt 13 handler: count a tick, call the tick callback, move CCOMPARE2 by 0x6C34 | derived |
| [`timer_service_timer0`](../../src/tensilica/timer/timer_service_timer0.S) | `fn_40008f84` | Interrupt 6 handler: re-arm CCOMPARE0 or stop, call the timer 0 callback | derived |
| [`timer_service_timer1`](../../src/tensilica/timer/timer_service_timer1.S) | `fn_40008fd8` | Interrupt 10 handler: re-arm CCOMPARE1 or stop, call the timer 1 callback | derived |
| [`timer_set_compare0_from_now`](../../src/tensilica/timer/timer_set_compare0_from_now.S) | `fn_4000ab84` | Set CCOMPARE0 = CCOUNT + cycles | proven |
| [`timer_set_compare1_from_now`](../../src/tensilica/timer/timer_set_compare1_from_now.S) | `fn_4000ab94` | Set CCOMPARE1 = CCOUNT + cycles | proven |
| [`timer_set_compare2_from_now`](../../src/tensilica/timer/timer_set_compare2_from_now.S) | `fn_4000aba4` | Set CCOMPARE2 = CCOUNT + cycles; file also holds the level-1 dispatcher exit | proven |
| [`timer_start_counted_timer0`](../../src/tensilica/timer/timer_start_counted_timer0.S) | `fn_40005f2c` | Start timer 0 with the tick counter and store the callback for the dispatcher | derived |
| [`timer_start_counted_timer1`](../../src/tensilica/timer/timer_start_counted_timer1.S) | `fn_40005f6c` | Start timer 1 with the tick counter and store the callback for the dispatcher | derived |
| [`timer_start_expstate_toggle`](../../src/tensilica/timer/timer_start_expstate_toggle.S) | `fn_40005dd8` | Start timer 0 with the EXPSTATE bit 9 toggle callback | derived |
| [`timer_start_tick`](../../src/tensilica/timer/timer_start_tick.S) | `fn_40009104` | Store the tick callback; arm CCOMPARE2 every 0x6C34 cycles and enable interrupt 13 | derived |
| [`timer_start_timer0`](../../src/tensilica/timer/timer_start_timer0.S) | `fn_40005f50` | Start timer 0 (CCOMPARE0) with a callback | derived |
| [`timer_start_timer1`](../../src/tensilica/timer/timer_start_timer1.S) | `fn_40005f90` | Start timer 1 (CCOMPARE1) with a callback | derived |
| [`timer_tick_callback_empty`](../../src/tensilica/timer/timer_tick_callback_empty.S) | `fn_4000a3c4` | Do nothing: the tick callback the main routine gives timer_start_tick | proven |
| [`timer_toggle_expstate_bit9`](../../src/tensilica/timer/timer_toggle_expstate_bit9.S) | `fn_40005cf8` | Timer callback: flip EXPSTATE bit 9 on every call | derived |
| [`timer_toggle_expstate_bit19`](../../src/tensilica/timer/timer_toggle_expstate_bit19.S) | `fn_40005d68` | Flip EXPSTATE bit 19 on every call (unused twin of the bit 9 toggler) | descriptive |
| [`timer_wait_ticks`](../../src/tensilica/timer/timer_wait_ticks.S) | `fn_4000912c` | Wait until the tick count has moved on by n | derived |
| [`timer_write_compare`](../../src/tensilica/timer/timer_write_compare.S) | `fn_4000abe4` | Write a value to CCOMPARE0, 1 or 2 | proven |

<a id="sys"></a>
## System control: channels, modes, configuration

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`sys_empty_after_tlb_write_a`](../../src/tensilica/sys/sys_empty_after_tlb_write_a.S) | `fn_4000ac28` | Do nothing; the first of two empty calls at the end of sys_set_region_attributes | descriptive |
| [`sys_empty_after_tlb_write_b`](../../src/tensilica/sys/sys_empty_after_tlb_write_b.S) | `fn_4000ac30` | Do nothing; the second of two empty calls at the end of sys_set_region_attributes | descriptive |
| [`sys_init_and_run_main_loop`](../../src/tensilica/sys/sys_init_and_run_main_loop.S) | `fn_4000a3cc` | Set up console, interrupts, timers, dimming block; poll mailbox and console until power-down word | proven |
| [`sys_read_region_attributes`](../../src/tensilica/sys/sys_read_region_attributes.S) | `fn_4000a994` | Read RDTLB1 of the eight 512 MB regions and pack their low nibbles into one word | proven |
| [`sys_set_all_regions_attribute_2`](../../src/tensilica/sys/sys_set_all_regions_attribute_2.S) | `fn_4000a10c` | Set the attribute of all eight 512 MB regions to 2; no caller | descriptive |
| [`sys_set_region_attributes`](../../src/tensilica/sys/sys_set_region_attributes.S) | `fn_4000a890` | Set the 4-bit attribute of each 512 MB region a range touches; return 0, -1, -2 or -3 | derived |
| [`sys_write_78_and_set_bit7`](../../src/tensilica/sys/sys_write_78_and_set_bit7.S) | `fn_4000a374` | Write 78 to word 0x15AC and keep bits 0..6 of word 0x14F8 with bit 7 set | descriptive |
| [`sys_write_78_or_79`](../../src/tensilica/sys/sys_write_78_or_79.S) | `fn_4000a39c` | Write 79 (flag set) or 78 (flag 0) to word 0x15AC | descriptive |
| [`sys_write_region_attributes`](../../src/tensilica/sys/sys_write_region_attributes.S) | `fn_4000a9c0` | Write eight attribute nibbles into the instruction and data TLB entries of the 512 MB regions | proven |

<a id="ldc"></a>
## Dimming processor and its hardware block

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`DRV_LDC_Intensity_Gain_Update`](../../src/tensilica/ldc/DRV_LDC_Intensity_Gain_Update.S) | `fn_40006904` | Fill register table 0xE0080C00 from a curve of {x, y} points by linear interpolation | proven |
| [`DRV_LDC_SetDSRegisters`](../../src/tensilica/ldc/DRV_LDC_SetDSRegisters.S) | `fn_400066d4` | Write width / DS divider to 0xE0080040 and the divider to 0xE0080370 | proven |
| [`DRV_LDC_SetLDCSegment`](../../src/tensilica/ldc/DRV_LDC_SetLDCSegment.S) | `fn_4000660c` | Set segment grid columns/rows (clamped 1..64 / 1..32), count, registers and boundaries | proven |
| [`DRV_LDC_SetPanelResolution`](../../src/tensilica/ldc/DRV_LDC_SetPanelResolution.S) | `fn_40006374` | Store panel width and height, write them to 0xE0080004, recompute zone area factors | proven |
| [`DRV_LDC_UpdateSegmentBoundary`](../../src/tensilica/ldc/DRV_LDC_UpdateSegmentBoundary.S) | `fn_40006434` | Write the column and row boundaries of the segment grid into the dimming block | proven |
| [`ldc_adim_apply_limit_upper_bound`](../../src/tensilica/ldc/ldc_adim_apply_limit_upper_bound.S) | `fn_4000233c` | Scale all ADIM values down when their average is above LimitUpperBound * percent / 255 | derived |
| [`ldc_adim_apply_zone_peaking`](../../src/tensilica/ldc/ldc_adim_apply_zone_peaking.S) | `fn_40002418` | Raise ADIM values by ZonePeakingPercent, more when fewer channels are lit | derived |
| [`ldc_adim_hold_on_sudden_rise`](../../src/tensilica/ldc/ldc_adim_hold_on_sudden_rise.S) | `fn_400024e4` | Hold all ADIM at PercentADIM for a time after a sudden rise from a dark average | descriptive |
| [`ldc_adim_map_through_curve`](../../src/tensilica/ldc/ldc_adim_map_through_curve.S) | `fn_40002228` | Map merged channel values to ADIM through the point table and scale by PercentADIM | derived |
| [`ldc_adim_raise_masked_channels`](../../src/tensilica/ldc/ldc_adim_raise_masked_channels.S) | `fn_40002ca0` | Give ADIM 32 to channels at most 31 whose bit is set in mailbox word +0x38 | descriptive |
| [`ldc_adim_smooth_toward_target`](../../src/tensilica/ldc/ldc_adim_smooth_toward_target.S) | `fn_40002a00` | Move each channel's kept ADIM toward the new value by weights +44/+48, limit to ADIM_Min..Max | derived |
| [`ldc_as3824_apply_direct_pwm`](../../src/tensilica/ldc/ldc_as3824_apply_direct_pwm.S) | `fn_40007958` | Switch direct PWM on (CurrCtrl 6, Options 96) or off (CurrCtrl 128 or 132, Options 0) | derived |
| [`ldc_as3824_apply_ldc_mode`](../../src/tensilica/ldc/ldc_as3824_apply_ldc_mode.S) | `fn_4000770c` | Set/clear HdrMode bit 4 for LDC_Mode 1 or 2, write reg 103, print it | derived |
| [`ldc_as3824_print_state`](../../src/tensilica/ldc/ldc_as3824_print_state.S) | `fn_40007c50` | Print all AS3824Buf fields, BDAC/PWM_HT values, LED_Mode and LDC_Mode; no caller | proven |
| [`ldc_as3824_send_dev1_reg_bit7`](../../src/tensilica/ldc/ldc_as3824_send_dev1_reg_bit7.S) | `fn_40007530` | Send frame {0x41, reg\|0x80, 0...} (2 words) via unit 0; no caller | descriptive |
| [`ldc_as3824_set_curr_ctrl`](../../src/tensilica/ldc/ldc_as3824_set_curr_ctrl.S) | `fn_40007878` | Store AS3824Buf.CurrCtrl and write it to AS3824 register 7 | proven |
| [`ldc_as3824_set_current_on`](../../src/tensilica/ldc/ldc_as3824_set_current_on.S) | `fn_400077fc` | Store AS3824Buf.CurrOnOff and write it to AS3824 register 1 | proven |
| [`ldc_as3824_set_dac`](../../src/tensilica/ldc/ldc_as3824_set_dac.S) | `fn_40007760` | Store AS3824Buf.DAC and send it to register 0x0C (value >> 2, value & 3) | derived |
| [`ldc_as3824_set_dacref_bit`](../../src/tensilica/ldc/ldc_as3824_set_dacref_bit.S) | `fn_400078a0` | Set CurrCtrl bit 2 when LED_Mode is 4 or more, else clear it; write AS3824 register 7 | proven |
| [`ldc_as3824_set_direct_pwm_bit`](../../src/tensilica/ldc/ldc_as3824_set_direct_pwm_bit.S) | `fn_40007914` | Set PWM_Ctrl bit 2 when the argument is 1, else clear it; write AS3824 register 19 | proven |
| [`ldc_as3824_set_hdr_bit0_and_init`](../../src/tensilica/ldc/ldc_as3824_set_hdr_bit0_and_init.S) | `fn_400077d4` | Set HdrMode bit 0, write reg 103, then run LED_AS3824_Init; no caller | descriptive |
| [`ldc_as3824_set_hdr_mode`](../../src/tensilica/ldc/ldc_as3824_set_hdr_mode.S) | `fn_40007820` | Store AS3824Buf.HdrMode and write it to AS3824 register 103 | proven |
| [`ldc_as3824_set_options`](../../src/tensilica/ldc/ldc_as3824_set_options.S) | `fn_400078e8` | Store AS3824Buf.Options and write it to AS3824 register 89 | proven |
| [`ldc_as3824_set_pwm_ctrl`](../../src/tensilica/ldc/ldc_as3824_set_pwm_ctrl.S) | `fn_4000784c` | Store AS3824Buf.PWM_Ctrl and write it to AS3824 register 19; no caller | proven |
| [`ldc_as3824_update`](../../src/tensilica/ldc/ldc_as3824_update.S) | `fn_40007ab8` | Driver type 1 routine: send PDIM/ADIM as PWM_HT/BDAC to the AS3824 after init | derived |
| [`ldc_as3824_write_bdac`](../../src/tensilica/ldc/ldc_as3824_write_bdac.S) | `fn_40007348` | Send one AS3824 device's 16 BDAC bytes (reg 0x70, channel order) via unit 0 | derived |
| [`ldc_as3824_write_byte`](../../src/tensilica/ldc/ldc_as3824_write_byte.S) | `fn_400074b4` | Send AS3824 frame {0xC0, reg, value} via unit 0, wait 2 ticks | derived |
| [`ldc_as3824_write_byte_to_device`](../../src/tensilica/ldc/ldc_as3824_write_byte_to_device.S) | `fn_400074ec` | Send AS3824 frame {device\|0x40, reg, value} via unit 0, wait 2 ticks | descriptive |
| [`ldc_as3824_write_bytes`](../../src/tensilica/ldc/ldc_as3824_write_bytes.S) | `fn_400075fc` | Send len bytes to one register: {hdr\|0x40,reg,d0} for len 1, else {hdr,len,reg,data} | descriptive |
| [`ldc_as3824_write_pwm_ht`](../../src/tensilica/ldc/ldc_as3824_write_pwm_ht.S) | `fn_4000713c` | Send one AS3824 device's 16 PWM_HT values (reg 0x37, 16-bit each, channel order) via unit 0 | derived |
| [`ldc_as3824_write_word`](../../src/tensilica/ldc/ldc_as3824_write_word.S) | `fn_4000756c` | Send AS3824 frame {0x80, 2, reg, lo, hi} via unit 0 (16-bit register value) | derived |
| [`ldc_as3824_write_word_to_device`](../../src/tensilica/ldc/ldc_as3824_write_word_to_device.S) | `fn_400075ac` | Send AS3824 frame {header, 2, reg, lo, hi} via unit 0; no caller | descriptive |
| [`ldc_build_command_index`](../../src/tensilica/ldc/ldc_build_command_index.S) | `fn_400037d8` | Fill the command-number to table-position index 0x3FFE3F60 for the 46 commands | proven |
| [`ldc_build_segment_channel_map`](../../src/tensilica/ldc/ldc_build_segment_channel_map.S) | `fn_400008c0` | Map each segment of the segment grid to an LED channel and count segments per channel. | derived |
| [`ldc_calc_percent_adim`](../../src/tensilica/ldc/ldc_calc_percent_adim.S) | `fn_40001188` | Return ADIM_Min plus weight/1023 of the span up to min(ADIM_Max, usUserADIM). | derived |
| [`ldc_check_curve_register_order`](../../src/tensilica/ldc/ldc_check_curve_register_order.S) | `fn_40001e54` | Count steps over 16 in the 12-bit pairs at 0xE00831C0/0xE00831E0; post pass flag (<5) | descriptive |
| [`ldc_check_duty_level_and_pair_sums`](../../src/tensilica/ldc/ldc_check_duty_level_and_pair_sums.S) | `fn_40001b08` | Return 1/0 from tests on a value array, mailbox word 0x40 and pair sums at 0xE0080700 | descriptive |
| [`ldc_check_input_duty_edges`](../../src/tensilica/ldc/ldc_check_input_duty_edges.S) | `fn_40001cb4` | Update and return a flag: set when few Input Duty entries differ from the one 17 later | descriptive |
| [`ldc_check_pure_pattern`](../../src/tensilica/ldc/ldc_check_pure_pattern.S) | `fn_400030b4` | Store the input-duty flag as the pass record's Pure Pattern word, then post the segment percent | derived |
| [`ldc_check_result_words_above_63`](../../src/tensilica/ldc/ldc_check_result_words_above_63.S) | `fn_40001dd8` | Count the 63 block words at 0xE0080700 above 63; post count and pass flag (<=8) to mailbox | descriptive |
| [`ldc_check_values_and_mailbox_ranges`](../../src/tensilica/ldc/ldc_check_values_and_mailbox_ranges.S) | `fn_40001f94` | Check values near 1400, mailbox +0x40 halves near 85/37 and block word 0xE0080700 range | descriptive |
| [`ldc_cmd_dpll_init_check`](../../src/tensilica/ldc/ldc_cmd_dpll_init_check.S) | `fn_400016a4` | Command 0x40: set or clear the DPLL-init flag that gates the per-frame pass, print it | proven |
| [`ldc_cmd_enable_input_duty_check`](../../src/tensilica/ldc/ldc_cmd_enable_input_duty_check.S) | `fn_40001ac8` | Command 0x97: switch the per-frame input duty check on or off, update reg 0xE0080388 | derived |
| [`ldc_cmd_ignore`](../../src/tensilica/ldc/ldc_cmd_ignore.S) | `fn_400037cc` | Do nothing: handler of commands 0x00 and 0x36 | proven |
| [`ldc_cmd_ignore_0x94`](../../src/tensilica/ldc/ldc_cmd_ignore_0x94.S) | `fn_400019e4` | Command 0x94: do nothing | proven |
| [`ldc_cmd_ignore_0x95`](../../src/tensilica/ldc/ldc_cmd_ignore_0x95.S) | `fn_400019f0` | Command 0x95: do nothing | proven |
| [`ldc_cmd_ignore_0x96`](../../src/tensilica/ldc/ldc_cmd_ignore_0x96.S) | `fn_400019fc` | Command 0x96: do nothing | proven |
| [`ldc_cmd_init_led_drivers`](../../src/tensilica/ldc/ldc_cmd_init_led_drivers.S) | `fn_400013a0` | Command 0x22: with value 1 run the LED driver set-up (prints LED_AS3824_Init Done). | derived |
| [`ldc_cmd_load_gain_table`](../../src/tensilica/ldc/ldc_cmd_load_gain_table.S) | `fn_40001938` | Command 0x50: load gain table 1..3 (ANV1..3) or the flat table into the hardware | proven |
| [`ldc_cmd_load_panel_and_start`](../../src/tensilica/ldc/ldc_cmd_load_panel_and_start.S) | `fn_40001344` | Command 0x21: load the panel, set resolution and segments, select driver, rebuild map. | derived |
| [`ldc_cmd_set_adim_bright_percent`](../../src/tensilica/ldc/ldc_cmd_set_adim_bright_percent.S) | `fn_400017c0` | Command 0x35: set ADIM_BrighPercent, recompute PercentADIM, refresh LED ADIM and status | proven |
| [`ldc_cmd_set_adim_level_and_percent`](../../src/tensilica/ldc/ldc_cmd_set_adim_level_and_percent.S) | `fn_40001830` | Command 0x39: set ADIM_BrighPercent and usUserADIM from one packed command | derived |
| [`ldc_cmd_set_adim_max`](../../src/tensilica/ldc/ldc_cmd_set_adim_max.S) | `fn_40001780` | Command 0x33: set ADIM_Max (10 bits) when above ADIM_Min | proven |
| [`ldc_cmd_set_adim_min`](../../src/tensilica/ldc/ldc_cmd_set_adim_min.S) | `fn_400017a0` | Command 0x34: set ADIM_Min (10 bits) when below ADIM_Max | proven |
| [`ldc_cmd_set_dark_pdim`](../../src/tensilica/ldc/ldc_cmd_set_dark_pdim.S) | `fn_40001510` | Command 0x32: store the PDIM for channels with value 9 or less, capped at usUserPDIM. | descriptive |
| [`ldc_cmd_set_direct_pwm`](../../src/tensilica/ldc/ldc_cmd_set_direct_pwm.S) | `fn_40001994` | Command 0x60: switch the LED drivers' direct PWM set-up on or off, by driver type | derived |
| [`ldc_cmd_set_ds_divider`](../../src/tensilica/ldc/ldc_cmd_set_ds_divider.S) | `fn_40001758` | Command 0x46: set the divider used by DRV_LDC_SetDSRegisters and rewrite those registers | derived |
| [`ldc_cmd_set_gain_filter_mode`](../../src/tensilica/ldc/ldc_cmd_set_gain_filter_mode.S) | `fn_400015e4` | Command 0x5D: store GainFilterMode and apply it to register 0xE0080388. | proven |
| [`ldc_cmd_set_gain_table1_point`](../../src/tensilica/ldc/ldc_cmd_set_gain_table1_point.S) | `fn_400018f0` | Command 0x51: change one point of gain table ANV1 | proven |
| [`ldc_cmd_set_gain_table2_point`](../../src/tensilica/ldc/ldc_cmd_set_gain_table2_point.S) | `fn_40001908` | Command 0x52: change one point of gain table ANV2 | proven |
| [`ldc_cmd_set_gain_table3_point`](../../src/tensilica/ldc/ldc_cmd_set_gain_table3_point.S) | `fn_40001920` | Command 0x53: change one point of gain table ANV3 | proven |
| [`ldc_cmd_set_ldc_mode`](../../src/tensilica/ldc/ldc_cmd_set_ldc_mode.S) | `fn_40001428` | Command 0x20: set LDC_Mode, load its gain table and filter mode, refill PDIM/ADIM. | proven |
| [`ldc_cmd_set_led_current_on`](../../src/tensilica/ldc/ldc_cmd_set_led_current_on.S) | `fn_40001a08` | Command 0x38: switch the AS3824 LED current on (0xFFFF, after a wait) or off (0) | derived |
| [`ldc_cmd_set_limit_upper_bound`](../../src/tensilica/ldc/ldc_cmd_set_limit_upper_bound.S) | `fn_40001858` | Command 0x37: set LimitUpperBound, at most 255 | proven |
| [`ldc_cmd_set_peaking`](../../src/tensilica/ldc/ldc_cmd_set_peaking.S) | `fn_4000165c` | Command 0x82: switch peaking off (LED_Mode 3) or on (LED_Mode 6), print it, post brightness | proven |
| [`ldc_cmd_set_reg00c_bit7`](../../src/tensilica/ldc/ldc_cmd_set_reg00c_bit7.S) | `fn_4000176c` | Command 0x43: set or clear bit 7 of byte register 0xE008000C | descriptive |
| [`ldc_cmd_set_reg5a4_bit2`](../../src/tensilica/ldc/ldc_cmd_set_reg5a4_bit2.S) | `fn_40001aa8` | Command 0x83: set bit 2 of register 0xE00805A4 for value 1, else clear it | descriptive |
| [`ldc_cmd_set_reg28c_bits4_6`](../../src/tensilica/ldc/ldc_cmd_set_reg28c_bits4_6.S) | `fn_40001734` | Command 0x42: write value & 7 into bits 4..6 of register 0xE008028C | descriptive |
| [`ldc_cmd_set_reg168`](../../src/tensilica/ldc/ldc_cmd_set_reg168.S) | `fn_40001ab8` | Command 0x84: keep value and sub and write (value << 8) + sub to register 0xE0080168 | derived |
| [`ldc_cmd_set_reg280_bytes`](../../src/tensilica/ldc/ldc_cmd_set_reg280_bytes.S) | `fn_40001404` | Command 0x85: write two bytes of the value to bits 0..15 of register 0xE0080280. | descriptive |
| [`ldc_cmd_set_reg290_high`](../../src/tensilica/ldc/ldc_cmd_set_reg290_high.S) | `fn_40001748` | Command 0x44: write the value into bits 16..31 of register 0xE0080290 | descriptive |
| [`ldc_cmd_set_segment_grid`](../../src/tensilica/ldc/ldc_cmd_set_segment_grid.S) | `fn_400013b4` | Command 0x2A: set segment columns and rows from the value and rebuild the map. | derived |
| [`ldc_cmd_set_segment_merge_mode`](../../src/tensilica/ldc/ldc_cmd_set_segment_merge_mode.S) | `fn_400016d4` | Command 0x41: select the segment merge routine (maximum, average, average no black, blend) | proven |
| [`ldc_cmd_set_user_adim`](../../src/tensilica/ldc/ldc_cmd_set_user_adim.S) | `fn_4000153c` | Command 0x31: set usUserADIM, compute PercentADIM, refill ADIM, post status. | proven |
| [`ldc_cmd_set_user_global_gain`](../../src/tensilica/ldc/ldc_cmd_set_user_global_gain.S) | `fn_400015d4` | Command 0x5A: store UserGlobalGain. | proven |
| [`ldc_cmd_set_user_pdim`](../../src/tensilica/ldc/ldc_cmd_set_user_pdim.S) | `fn_400014c0` | Command 0x30: set usUserPDIM (max 0xFFF) for all channels and post status. | proven |
| [`ldc_cmd_set_value_0x3c`](../../src/tensilica/ldc/ldc_cmd_set_value_0x3c.S) | `fn_400015fc` | Command 0x3C: store the value in word +36 of the dimming settings. | descriptive |
| [`ldc_cmd_set_value_0x3d`](../../src/tensilica/ldc/ldc_cmd_set_value_0x3d.S) | `fn_4000160c` | Command 0x3D: store the value in word +40 of the dimming settings. | descriptive |
| [`ldc_cmd_set_value_0x3e`](../../src/tensilica/ldc/ldc_cmd_set_value_0x3e.S) | `fn_4000161c` | Command 0x3E: store the value in word +44 of the dimming settings. | descriptive |
| [`ldc_cmd_set_value_0x3f`](../../src/tensilica/ldc/ldc_cmd_set_value_0x3f.S) | `fn_4000162c` | Command 0x3F: store the value in word +48 of the dimming settings. | descriptive |
| [`ldc_cmd_set_value_0x5b`](../../src/tensilica/ldc/ldc_cmd_set_value_0x5b.S) | `fn_4000163c` | Command 0x5B: store the value in word +52 of the dimming settings. | descriptive |
| [`ldc_cmd_set_value_0x5c`](../../src/tensilica/ldc/ldc_cmd_set_value_0x5c.S) | `fn_4000164c` | Command 0x5C: store the value in word +56 of the dimming settings. | descriptive |
| [`ldc_cmd_set_zone_counts`](../../src/tensilica/ldc/ldc_cmd_set_zone_counts.S) | `fn_400013e0` | Command 0x2B: store two byte values and write them to register 0xE0080000. | derived |
| [`ldc_cmd_set_zone_peaking_percent`](../../src/tensilica/ldc/ldc_cmd_set_zone_peaking_percent.S) | `fn_40001880` | Command 0x3A: set ZonePeakingPercent | proven |
| [`ldc_cmd_write_as3824_register`](../../src/tensilica/ldc/ldc_cmd_write_as3824_register.S) | `fn_400019c4` | Command 0x61: write one AS3824 register (number = sub-code) when the driver type is 1 | derived |
| [`ldc_cmd_write_register_byte`](../../src/tensilica/ldc/ldc_cmd_write_register_byte.S) | `fn_40001a4c` | Command 0x77: write the sub-code byte at byte offset 'value' in the 0xE0080000 block | derived |
| [`ldc_fill_segment_values`](../../src/tensilica/ldc/ldc_fill_segment_values.S) | `fn_40002de0` | Fill per-segment values from their channel's value (mode 1) or from Input Duty | descriptive |
| [`ldc_filter_grid_3x3`](../../src/tensilica/ldc/ldc_filter_grid_3x3.S) | `fn_40002688` | Filter a rows x cols grid with one of two 3x3 weight tables, borders copied | derived |
| [`ldc_follow_mode_and_run_led_driver`](../../src/tensilica/ldc/ldc_follow_mode_and_run_led_driver.S) | `fn_40003558` | Apply a changed LDC_Mode, then call the panel's LED driver routine after 1 or 2 passes | derived |
| [`ldc_gain_table_set_point`](../../src/tensilica/ldc/ldc_gain_table_set_point.S) | `fn_40001894` | Set the x (inner points only, <=254) or y of one point of a gain table | derived |
| [`ldc_hw_apply_gain_filter_mode`](../../src/tensilica/ldc/ldc_hw_apply_gain_filter_mode.S) | `fn_4000679c` | Copy bits 1 and 2 of GainFilterMode into register 0xE0080388 | derived |
| [`ldc_hw_apply_ldc_mode`](../../src/tensilica/ldc/ldc_hw_apply_ldc_mode.S) | `fn_40005fac` | Set dimming-block control bits (0x310, 0x400, 0x00C, 0x514) for an LDC_Mode value | derived |
| [`ldc_hw_init`](../../src/tensilica/ldc/ldc_hw_init.S) | `fn_400068c0` | Preset segment values, load default registers and set each register group at start-up | derived |
| [`ldc_hw_load_default_registers`](../../src/tensilica/ldc/ldc_hw_load_default_registers.S) | `fn_40006144` | Write the 59 {register, value} pairs of ldc_hw_default_registers into the dimming block | proven |
| [`ldc_hw_set_global_gain_by_maximum`](../../src/tensilica/ldc/ldc_hw_set_global_gain_by_maximum.S) | `fn_40006a58` | Write a global gain to 0xE0080378 that depends on the largest of a list of words | descriptive |
| [`ldc_hw_set_reg00c_bit7`](../../src/tensilica/ldc/ldc_hw_set_reg00c_bit7.S) | `fn_40006884` | Set or clear bit 7 of register 0xE008000C (byte access) | descriptive |
| [`ldc_hw_set_reg5a4_bit2`](../../src/tensilica/ldc/ldc_hw_set_reg5a4_bit2.S) | `fn_40006764` | Set or clear bit 2 of register 0xE00805A4 | descriptive |
| [`ldc_hw_set_reg28c_bits4_6`](../../src/tensilica/ldc/ldc_hw_set_reg28c_bits4_6.S) | `fn_40006854` | Write a 3-bit value to bits 4..6 of register 0xE008028C | descriptive |
| [`ldc_hw_set_reg168_fields`](../../src/tensilica/ldc/ldc_hw_set_reg168_fields.S) | `fn_40006724` | Store two fields and write (a << 8) + b to bits 0..23 of register 0xE0080168 | derived |
| [`ldc_hw_set_reg280_low_bytes`](../../src/tensilica/ldc/ldc_hw_set_reg280_low_bytes.S) | `fn_40006410` | Write two bytes to bits 0..15 of register 0xE0080280 | descriptive |
| [`ldc_hw_set_reg290_high_half`](../../src/tensilica/ldc/ldc_hw_set_reg290_high_half.S) | `fn_4000686c` | Write a 16-bit value to bits 16..31 of register 0xE0080290 | descriptive |
| [`ldc_hw_set_zone_area_factors`](../../src/tensilica/ldc/ldc_hw_set_zone_area_factors.S) | `fn_400061b0` | Compute zone pixel count and its reciprocal factor and shift, write registers 0x134..0x140 | derived |
| [`ldc_hw_write_global_gain`](../../src/tensilica/ldc/ldc_hw_write_global_gain.S) | `fn_400069f0` | Write a 12-bit gain to bits 16..27 of register 0xE0080378 | derived |
| [`ldc_hw_write_global_gain_0x400`](../../src/tensilica/ldc/ldc_hw_write_global_gain_0x400.S) | `fn_400069dc` | Write 0x400 to the global gain field (bits 16..27) of register 0xE0080378 | descriptive |
| [`ldc_hw_write_reg160`](../../src/tensilica/ldc/ldc_hw_write_reg160.S) | `fn_40006750` | Write a value to register 0xE0080160 | descriptive |
| [`ldc_hw_write_result_table`](../../src/tensilica/ldc/ldc_hw_write_result_table.S) | `fn_40006a08` | Copy the result values into the table at 0xE0082000 while bit 7 of 0xE008000C is set | derived |
| [`ldc_init_panel_defaults`](../../src/tensilica/ldc/ldc_init_panel_defaults.S) | `fn_40000e20` | Set default panel record, tables, modes and mailbox panel words at start-up. | derived |
| [`ldc_irq_handler`](../../src/tensilica/ldc/ldc_irq_handler.S) | `fn_40008ef0` | Interrupt 9 handler: flag, ack, read segment values, count status bits 0/1/4 | derived |
| [`ldc_irq_install`](../../src/tensilica/ldc/ldc_irq_install.S) | `fn_40008f58` | Install ldc_irq_handler for interrupt 9, enable it and set up line 7 | derived |
| [`ldc_led_driver_type0_update`](../../src/tensilica/ldc/ldc_led_driver_type0_update.S) | `fn_4000802c` | Pack PDIM/ADIM of 8 or 10 channels into a 9-word frame and send it via unit 0 | derived |
| [`ldc_led_driver_type2_update`](../../src/tensilica/ldc/ldc_led_driver_type2_update.S) | `fn_40007e68` | Driver type 2 routine: 256 words of scaled segment value pairs + curve value via unit 0 | derived |
| [`ldc_level_curve_value`](../../src/tensilica/ldc/ldc_level_curve_value.S) | `fn_40007d40` | Map reg 0xE00802FC bits 16-25 through an 8-point curve, scale, post to mailbox +0x44 | descriptive |
| [`LDC_LoadPanel`](../../src/tensilica/ldc/LDC_LoadPanel.S) | `fn_40000fb4` | Read the panel description from the mailbox, check LED count, print PanelInfo. | proven |
| [`ldc_merge_segments_average`](../../src/tensilica/ldc/ldc_merge_segments_average.S) | `fn_40000a08` | Merge segments into LED channels by their average, minimum 10 when the sum is above 10. | proven |
| [`ldc_merge_segments_average_no_black`](../../src/tensilica/ldc/ldc_merge_segments_average_no_black.S) | `fn_40000afc` | Merge segments into LED channels by the average of the non-zero segments. | proven |
| [`ldc_merge_segments_blend`](../../src/tensilica/ldc/ldc_merge_segments_blend.S) | `fn_40000c6c` | Merge segments into LED channels as half of maximum plus average. | proven |
| [`ldc_merge_segments_maximum`](../../src/tensilica/ldc/ldc_merge_segments_maximum.S) | `fn_400009a0` | Merge segments into LED channels by taking the largest segment value. | proven |
| [`ldc_pdim_raise_masked_channels`](../../src/tensilica/ldc/ldc_pdim_raise_masked_channels.S) | `fn_40002d0c` | Give PDIM 0xFFF to channels at most 15 whose bit is set in mailbox word +0x38 | descriptive |
| [`ldc_pdim_scale_to_4095`](../../src/tensilica/ldc/ldc_pdim_scale_to_4095.S) | `fn_40002d7c` | Scale each channel's PDIM by 4095/4092 and cap at 0xFFF | descriptive |
| [`ldc_pdim_select_user_or_dark`](../../src/tensilica/ldc/ldc_pdim_select_user_or_dark.S) | `fn_400021d0` | Set each channel's PDIM to usUserPDIM when its merged value is above 9, else the dark PDIM | derived |
| [`ldc_pdim_smooth_toward_target`](../../src/tensilica/ldc/ldc_pdim_smooth_toward_target.S) | `fn_40002894` | Move each channel's kept PDIM toward the new value by weights +36/+40, cap at 0xFFF | derived |
| [`ldc_poll_mailbox_command`](../../src/tensilica/ldc/ldc_poll_mailbox_command.S) | `fn_40003814` | Read portal 2 power word and command slot, print and run the command handler | proven |
| [`ldc_post_brightness_status`](../../src/tensilica/ldc/ldc_post_brightness_status.S) | `fn_400011e4` | Post average ADIM and PDIM percentages and their product in mailbox word +0x4C. | derived |
| [`ldc_post_segment_percent`](../../src/tensilica/ldc/ldc_post_segment_percent.S) | `fn_40002e78` | Compute a 0..100 percentage from Input Duty or block words 0x700..0x708, post it at mailbox +0x90 | descriptive |
| [`ldc_preset_segment_values`](../../src/tensilica/ldc/ldc_preset_segment_values.S) | `fn_40006180` | Fill the 2048 16-bit segment values at 0x3ffe4490 with 0xFFC | derived |
| [`ldc_print_debug_dump`](../../src/tensilica/ldc/ldc_print_debug_dump.S) | `fn_40003190` | Print Input Duty, gain tables, settings, LED ADIM/PDIM on mailbox request or every 180 passes | proven |
| [`ldc_ramp_level_over_time`](../../src/tensilica/ldc/ldc_ramp_level_over_time.S) | `fn_400020d0` | Ramp a level between min and max by elapsed ticks; flag the end in settings +60 and mailbox | descriptive |
| [`ldc_read_segment_values`](../../src/tensilica/ldc/ldc_read_segment_values.S) | `fn_40006804` | Copy the segment values from the dimming block at 0xE0083000 into 0x3ffe4490 | derived |
| [`ldc_run_adim_path`](../../src/tensilica/ldc/ldc_run_adim_path.S) | `fn_400030c8` | Run the ADIM chain on the merged channel values and store the LED ADIM array | derived |
| [`ldc_run_frame_pass`](../../src/tensilica/ldc/ldc_run_frame_pass.S) | `fn_400035d0` | Run one processing pass: merge, ADIM/PDIM paths, result table, LED driver, debug print | proven |
| [`ldc_run_pass_on_new_frame`](../../src/tensilica/ldc/ldc_run_pass_on_new_frame.S) | `fn_40003764` | Run a processing pass when the frame interrupt's bit-1 count has moved | derived |
| [`ldc_run_pdim_path`](../../src/tensilica/ldc/ldc_run_pdim_path.S) | `fn_40003140` | Run the PDIM chain on the merged channel values and store the LED PDIM array | derived |
| [`ldc_select_led_driver`](../../src/tensilica/ldc/ldc_select_led_driver.S) | `fn_40000de8` | Store the LED driver routine for driver type 1, 2 or other in the panel record. | derived |
| [`ldc_set_direct_pwm_type0`](../../src/tensilica/ldc/ldc_set_direct_pwm_type0.S) | `fn_400082cc` | Send {0x238007AA,0x55} and set the direct PWM flag (1), or clear the flag | derived |
| [`ldc_set_ds_divider`](../../src/tensilica/ldc/ldc_set_ds_divider.S) | `fn_4000670c` | Store the DS divider (grid +48) and write the DS registers | derived |
| [`ldc_set_zone_count_exponents`](../../src/tensilica/ldc/ldc_set_zone_count_exponents.S) | `fn_400063dc` | Store the two zone-count exponents and write them to bits 16..31 of 0xE0080000 | derived |
| [`ldc_smooth_and_apply_global_gain`](../../src/tensilica/ldc/ldc_smooth_and_apply_global_gain.S) | `fn_40002bf0` | Set ApplyGlobalGain from the gain (optionally smoothed), limit to 16..0xD00, write it | derived |
| [`ldc_test_dump_grid_values`](../../src/tensilica/ldc/ldc_test_dump_grid_values.S) | `fn_40006afc` | Step registers 0x5A0/0x5A4 over 32x64x9 positions and print the values read at 0x5D4 | derived |
| [`ldc_unit_set_length_and_flag`](../../src/tensilica/ldc/ldc_unit_set_length_and_flag.S) | `fn_40006de8` | Write n - 1 to bits 4..13 and a flag to bit 3 of one unit's control register | descriptive |
| [`ldc_unit_set_mode_bits`](../../src/tensilica/ldc/ldc_unit_set_mode_bits.S) | `fn_40006c9c` | Set bits 30..31 of one unit's control register and bit 12 of its word at 0x3ffe5490 | descriptive |
| [`ldc_unit_set_reg38_bit13`](../../src/tensilica/ldc/ldc_unit_set_reg38_bit13.S) | `fn_40006e94` | Write a flag to bit 13 of register +0x38 of one unit (0xC0192000 + k*0x100) | descriptive |
| [`ldc_units_copy_words_and_start`](../../src/tensilica/ldc/ldc_units_copy_words_and_start.S) | `fn_40006be8` | Copy words to buffer 0xC01A0004 and start each selected unit (0xC0197000 + k*0x1000) | descriptive |
| [`ldc_units_init`](../../src/tensilica/ldc/ldc_units_init.S) | `fn_40006f00` | Write start-up values to the four units (0xC0192000/0xC0197000 + k) and the unit words | descriptive |
| [`ldc_units_setup_driver_type2`](../../src/tensilica/ldc/ldc_units_setup_driver_type2.S) | `fn_40008010` | Unit 0: mode bits 2, length 12 flag 1, reg +0x38 bit 13 = 1 (driver type 2) | descriptive |
| [`ldc_write_table_and_global_gain`](../../src/tensilica/ldc/ldc_write_table_and_global_gain.S) | `fn_40003174` | Write a 16-bit table to the result table, then smooth and apply UserGlobalGain | derived |
| [`LED_AS3824_Init`](../../src/tensilica/ldc/LED_AS3824_Init.S) | `fn_400079b8` | Set up the AS3824 registers and AS3824Buf, send BDAC and PWM_HT, mark init done | proven |
| [`LED_AS3824_SetPwmPeriod`](../../src/tensilica/ldc/LED_AS3824_SetPwmPeriod.S) | `fn_400077a4` | Store AS3824Buf.PWM_Period and write it to AS3824 register 20 | proven |
| [`LED_AS3824_Unlock`](../../src/tensilica/ldc/LED_AS3824_Unlock.S) | `fn_40007998` | Write 0xCA (LockUnlock) to AS3824 register 54 | proven |

<a id="gpio"></a>
## Pins

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`gpio_input_read`](../../src/tensilica/gpio/gpio_input_read.S) | `fn_40008c38` | Return bit n of the IMPWIRE input | descriptive |
| [`gpio_input_read_all`](../../src/tensilica/gpio/gpio_input_read_all.S) | `fn_40008c58` | Return the whole IMPWIRE input word | descriptive |
| [`gpio_output_clear`](../../src/tensilica/gpio/gpio_output_clear.S) | `fn_400089e8` | Clear EXPSTATE bit gpio (0..31) | derived |
| [`gpio_output_clear_masked`](../../src/tensilica/gpio/gpio_output_clear_masked.S) | `fn_40008ad8` | Clear EXPSTATE bit n with one masked write | descriptive |
| [`gpio_output_set`](../../src/tensilica/gpio/gpio_output_set.S) | `fn_40008af8` | Set EXPSTATE bit gpio (0..31) | derived |
| [`gpio_output_set_masked`](../../src/tensilica/gpio/gpio_output_set_masked.S) | `fn_40008be8` | Set EXPSTATE bit n with one masked write | descriptive |
| [`gpio_output_toggle`](../../src/tensilica/gpio/gpio_output_toggle.S) | `fn_40008c10` | Invert EXPSTATE bit n | descriptive |
| [`gpio_set_input`](../../src/tensilica/gpio/gpio_set_input.S) | `fn_400086a4` | Run gpio_switch_mux, then clear the pin's bit in the 0x14E0..0x14FC words | proven |
| [`gpio_switch_mux`](../../src/tensilica/gpio/gpio_switch_mux.S) | `fn_40008300` | Hand a GPIO pin to the GPIO function: set its bit, clear its pin-specific mux bit | proven |

<a id="uart"></a>
## Serial ports

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`uart_getchar`](../../src/tensilica/uart/uart_getchar.S) | `fn_400091f4` | Wait for one received byte (uart_wait_read_byte); negative becomes -1 | derived |
| [`uart_init`](../../src/tensilica/uart/uart_init.S) | `fn_40009ca8` | Set up serial block 0xE00A0000 from a settings record, install rx handler on int 2 | derived |
| [`uart_print_tx_test_lines`](../../src/tensilica/uart/uart_print_tx_test_lines.S) | `fn_40009a90` | Print the printf test lines of the serial port test and the expected result | proven |
| [`uart_put_hex_byte`](../../src/tensilica/uart/uart_put_hex_byte.S) | `fn_4000a08c` | Send a byte as 2 upper-case hex digits with the bounded wait | derived |
| [`uart_put_hex_word`](../../src/tensilica/uart/uart_put_hex_word.S) | `fn_4000a010` | Send a 32-bit value as 8 upper-case hex digits with the bounded wait | derived |
| [`uart_putc`](../../src/tensilica/uart/uart_putc.S) | `fn_40009e88` | Wait for bit 5 of 0xE00A0014, write one byte to 0xE00A0000, return it | derived |
| [`uart_putc_timeout`](../../src/tensilica/uart/uart_putc_timeout.S) | `fn_40009fc8` | Wait for bit 5 of 0xE00A0014 at most 0xFFFFF polls, then write one byte | derived |
| [`uart_puts`](../../src/tensilica/uart/uart_puts.S) | `fn_400091d0` | Send a text via uart_send_text; return 0, or -1 for a null text | derived |
| [`uart_rx_irq_handler`](../../src/tensilica/uart/uart_rx_irq_handler.S) | `fn_40009f10` | Interrupt 2 handler: put the received value into the 128-word ring, ack 0xE00A1070 | derived |
| [`uart_rx_ring_get`](../../src/tensilica/uart/uart_rx_ring_get.S) | `fn_40009f70` | Take the oldest byte from the receive ring into *out; return 1, or 0 when empty | derived |
| [`uart_selftest`](../../src/tensilica/uart/uart_selftest.S) | `fn_40005de8` | Run the UART TX/RX test, echo typed characters until 'q', then loop forever | proven |
| [`uart_send_text`](../../src/tensilica/uart/uart_send_text.S) | `fn_40009de8` | Write a text's bytes to 0xE00A0000 while 0xE00A0014 bit 5 is set; CR before LF | derived |
| [`uart_set_baud_divisor`](../../src/tensilica/uart/uart_set_baud_divisor.S) | `fn_40009b50` | Write (48000000>>4)/baud to 0xE00A0000/04 (bit 7 of 0xE00A000C set) and 0xE009101C | derived |
| [`uart_set_line_format`](../../src/tensilica/uart/uart_set_line_format.S) | `fn_40009bc8` | Build 0xE00A000C from settings words +4 (bits 0-1), +8 (bits 3-5), +12 (bit 2) | descriptive |
| [`uart_try_read_byte`](../../src/tensilica/uart/uart_try_read_byte.S) | `fn_40009ec0` | Return 0xE00A0000 when bit 0 of 0xE00A0014 is set, else -1 (no wait) | derived |
| [`uart_wait_read_byte`](../../src/tensilica/uart/uart_wait_read_byte.S) | `fn_40009ee8` | Wait for bit 0 of 0xE00A0014 and return the word at 0xE00A0000 | derived |

<a id="reg"></a>
## Register access

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`reg_read8`](../../src/tensilica/reg/reg_read8.S) | `fn_40003f74` | Return a byte by reading its aligned 32-bit word and shifting | proven |
| [`reg_read8_wrap`](../../src/tensilica/reg/reg_read8_wrap.S) | `fn_40004180` | Return the byte at an address through reg_read8 | derived |
| [`reg_read32`](../../src/tensilica/reg/reg_read32.S) | `fn_40003f10` | Return the 32-bit word at an address (volatile read) | proven |
| [`reg_read32_wrap`](../../src/tensilica/reg/reg_read32_wrap.S) | `fn_4000414c` | Return the word at an address through reg_read32 | derived |
| [`reg_write8`](../../src/tensilica/reg/reg_write8.S) | `fn_40003fa0` | Write a byte by read-modify-write of its aligned 32-bit word | proven |
| [`reg_write8_wrap`](../../src/tensilica/reg/reg_write8_wrap.S) | `fn_40004190` | Write a byte to an address through reg_write8 | derived |
| [`reg_write32`](../../src/tensilica/reg/reg_write32.S) | `fn_40003f24` | Write a 32-bit word to an address (volatile write) | proven |
| [`reg_write32_masked`](../../src/tensilica/reg/reg_write32_masked.S) | `fn_40003f38` | Replace the masked bits of a 32-bit word with the bits of a value | proven |
| [`reg_write32_masked_wrap`](../../src/tensilica/reg/reg_write32_masked_wrap.S) | `fn_4000416c` | Change the masked bits of a word through reg_write32_masked | derived |
| [`reg_write32_wrap`](../../src/tensilica/reg/reg_write32_wrap.S) | `fn_4000415c` | Write a word to an address through reg_write32 | derived |

<a id="dbg"></a>
## Debug facilities

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`dbg_cmd_gpio_test`](../../src/tensilica/dbg/dbg_cmd_gpio_test.S) | `fn_40005cac` | Toggle a GPIO 1000 times through the two gpio_set_output routines, print 'GPIOtest done!!' | proven |
| [`dbg_cmd_help`](../../src/tensilica/dbg/dbg_cmd_help.S) | `fn_40005c3c` | Print the help texts of the debug commands | proven |
| [`dbg_cmd_mdw`](../../src/tensilica/dbg/dbg_cmd_mdw.S) | `fn_40004b08` | Print words from an address as 8-digit hex values, 4 per line (debug command mdw) | proven |
| [`dbg_cmd_mem`](../../src/tensilica/dbg/dbg_cmd_mem.S) | `fn_4000498c` | Print words from an address as a hex and character byte dump (debug command mem) | proven |
| [`dbg_cmd_msg0`](../../src/tensilica/dbg/dbg_cmd_msg0.S) | `fn_40005c9c` | Write 0 to mailbox register 0xE0091084 | derived |
| [`dbg_cmd_msg1`](../../src/tensilica/dbg/dbg_cmd_msg1.S) | `fn_40005c8c` | Write 1 to mailbox register 0xE0091084 | derived |
| [`dbg_cmd_rsa`](../../src/tensilica/dbg/dbg_cmd_rsa.S) | `fn_40005c78` | Write 0x68500DEF to 0xB70910FC | derived |
| [`dbg_cmd_wmem`](../../src/tensilica/dbg/dbg_cmd_wmem.S) | `fn_40004bcc` | Write a word to an aligned address and echo it (debug commands wmem and mww) | proven |
| [`dbg_console_init`](../../src/tensilica/dbg/dbg_console_init.S) | `fn_40005ba8` | Reset the debug command line state and print the 'Command Line Debug' banner | proven |
| [`dbg_console_poll`](../../src/tensilica/dbg/dbg_console_poll.S) | `fn_400058dc` | Feed one received serial character to the debug command line and run the line on Enter | proven |
| [`dbg_find_and_run_command`](../../src/tensilica/dbg/dbg_find_and_run_command.S) | `fn_40004dfc` | Look the first command word up in the debug command table and run its handler | proven |
| [`dbg_init_uart_print_banner`](../../src/tensilica/dbg/dbg_init_uart_print_banner.S) | `fn_40003c94` | Set up the serial port and print the version banner | proven |
| [`dbg_memcmd_cfg`](../../src/tensilica/dbg/dbg_memcmd_cfg.S) | `fn_40003b98` | Console command 'cfg': parse item and value; all cases empty, prints 'val = 0x%08X' | proven |
| [`dbg_memcmd_echo_char`](../../src/tensilica/dbg/dbg_memcmd_echo_char.S) | `fn_400038e8` | Send one character to the serial port while the console flag is set | derived |
| [`dbg_memcmd_md`](../../src/tensilica/dbg/dbg_memcmd_md.S) | `fn_40003b68` | Console command 'md': set the console's echo/verbose flag dbg_memcmd_verbose | derived |
| [`dbg_memcmd_mr`](../../src/tensilica/dbg/dbg_memcmd_mr.S) | `fn_40003904` | Console command 'mr': dump memory as 32/16/8-bit values, 16 bytes per row | proven |
| [`dbg_memcmd_mw`](../../src/tensilica/dbg/dbg_memcmd_mw.S) | `fn_40003a70` | Console command 'mw': write hex values of a given width to memory | proven |
| [`dbg_memcmd_poll_console`](../../src/tensilica/dbg/dbg_memcmd_poll_console.S) | `fn_40003cd0` | Read one console character, edit the line, run the matching mr/mw/md/cfg command | derived |
| [`dbg_parse_star_request`](../../src/tensilica/dbg/dbg_parse_star_request.S) | `fn_4000574c` | Recognise a '*qt/*RD/*WD/*RB/*WB/*CB' request line and store its code and operands | derived |
| [`dbg_parse_word_number`](../../src/tensilica/dbg/dbg_parse_word_number.S) | `fn_40004c14` | Convert a debug command word to a number (0x.. hexadecimal, else decimal) | derived |
| [`dbg_print_sw_value`](../../src/tensilica/dbg/dbg_print_sw_value.S) | `fn_40005c24` | Print 'NT68500 Tensilica S/W : ', a value as 8 hex digits, and '#' | derived |
| [`dbg_printf`](../../src/tensilica/dbg/dbg_printf.S) | `fn_400099bc` | Format a text like printf into a 1024-byte stack buffer and send it to the serial port | proven |
| [`dbg_request_check_char`](../../src/tensilica/dbg/dbg_request_check_char.S) | `fn_40005518` | Return '0' + low 4 bits of the byte sum of two words (check char of '*xx' requests) | derived |
| [`dbg_run_hex_packet`](../../src/tensilica/dbg/dbg_run_hex_packet.S) | `fn_40005050` | Run a '^' hex packet: read, write or masked-write a word, print a 0x83/0x82 reply | derived |
| [`dbg_run_star_request`](../../src/tensilica/dbg/dbg_run_star_request.S) | `fn_40005574` | Run the stored '*xx' request (read/write word, set base) and print its '#..OK!#' reply | derived |
| [`dbg_run_text_command`](../../src/tensilica/dbg/dbg_run_text_command.S) | `fn_40004fc0` | Split a typed line, run its command from the table, print OK or 'Command Not Found!' | proven |
| [`dbg_split_command_words`](../../src/tensilica/dbg/dbg_split_command_words.S) | `fn_40004ea0` | Split a command line into up to four 32-byte word slots, counting the words | derived |

<a id="lib"></a>
## Library routines

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`lib_blend_by_weight_1024`](../../src/tensilica/lib/lib_blend_by_weight_1024.S) | `fn_40002660` | Return the rounded mix (a*w + b*(1024-w) + 512) >> 10 | proven |
| [`lib_compare_bytes`](../../src/tensilica/lib/lib_compare_bytes.S) | `fn_40004710` | Compare count bytes; return 0 if equal, 1 at the first difference | proven |
| [`lib_compare_strings`](../../src/tensilica/lib/lib_compare_strings.S) | `fn_40004788` | Compare two zero-terminated texts; return the difference of the first unequal bytes | proven |
| [`lib_compare_words`](../../src/tensilica/lib/lib_compare_words.S) | `fn_400046c8` | Compare count words; return 0 if equal, 1 at the first difference | proven |
| [`lib_copy_bytes`](../../src/tensilica/lib/lib_copy_bytes.S) | `fn_4000462c` | Copy count bytes | proven |
| [`lib_copy_bytes_word_access`](../../src/tensilica/lib/lib_copy_bytes_word_access.S) | `fn_40004364` | Copy bytes using only aligned word reads and writes | derived |
| [`lib_copy_memory`](../../src/tensilica/lib/lib_copy_memory.S) | `fn_4000aa64` | Copy n bytes from src to dst using word moves (SRC joins for unaligned source); return dst | proven |
| [`lib_copy_next_word`](../../src/tensilica/lib/lib_copy_next_word.S) | `fn_4000a120` | Copy the next space-separated word of a text into dst; return the address after it | derived |
| [`lib_copy_words`](../../src/tensilica/lib/lib_copy_words.S) | `fn_400045f4` | Copy count 32-bit words | proven |
| [`lib_divide_round_up`](../../src/tensilica/lib/lib_divide_round_up.S) | `fn_400047c4` | Divide two unsigned numbers, rounding the quotient up | proven |
| [`lib_fill_bytes`](../../src/tensilica/lib/lib_fill_bytes.S) | `fn_40004694` | Store one byte value into count bytes | proven |
| [`lib_fill_halfwords`](../../src/tensilica/lib/lib_fill_halfwords.S) | `fn_4000087c` | Fill count 16-bit entries with one value, a word at a time. | derived |
| [`lib_fill_words`](../../src/tensilica/lib/lib_fill_words.S) | `fn_40004664` | Store one value into count 32-bit words | proven |
| [`lib_format_hex_word`](../../src/tensilica/lib/lib_format_hex_word.S) | `fn_400054a4` | Write a 32-bit value as eight hex digits and a zero byte | proven |
| [`lib_heap_alloc`](../../src/tensilica/lib/lib_heap_alloc.S) | `fn_40004210` | Take a block of the pool, first fit, size rounded up to 8 | derived |
| [`lib_heap_free`](../../src/tensilica/lib/lib_heap_free.S) | `fn_400042a8` | Return a block to the address-ordered free list, merging touching blocks | derived |
| [`lib_heap_init`](../../src/tensilica/lib/lib_heap_init.S) | `fn_400041a8` | Set up the memory pool and its free list (record 0x3ffe4220, list head 0x3ffe4230) | derived |
| [`lib_hex_digit_value`](../../src/tensilica/lib/lib_hex_digit_value.S) | `fn_400053d0` | Return the value 0-15 of a hex digit character, 0 for any other character | proven |
| [`lib_nibble_to_hex_char`](../../src/tensilica/lib/lib_nibble_to_hex_char.S) | `fn_40005424` | Return the upper-case hex digit character of a value 0-15 | proven |
| [`lib_pack_word_pairs`](../../src/tensilica/lib/lib_pack_word_pairs.S) | `fn_4000082c` | Pack pairs of words into one word as low and high 16-bit halves. | derived |
| [`lib_parse_decimal_text`](../../src/tensilica/lib/lib_parse_decimal_text.S) | `fn_4000a2cc` | Read a text as a decimal number from its last character back; skip spaces, stop at other chars | proven |
| [`lib_parse_hex_digits`](../../src/tensilica/lib/lib_parse_hex_digits.S) | `fn_40005460` | Return the number formed by n hex digit characters | proven |
| [`lib_parse_hex_text`](../../src/tensilica/lib/lib_parse_hex_text.S) | `fn_4000a1f4` | Read a hex number from a text, scanning backwards, skipping spaces | derived |
| [`lib_read_word`](../../src/tensilica/lib/lib_read_word.S) | `fn_4000496c` | Return the 32-bit word at an address | proven |
| [`lib_round_up_to_multiple`](../../src/tensilica/lib/lib_round_up_to_multiple.S) | `fn_40004804` | Round an unsigned number up to a multiple of a step | proven |
| [`lib_sprintf`](../../src/tensilica/lib/lib_sprintf.S) | `fn_40009a4c` | Format a text like sprintf into the caller's buffer through lib_vsprintf; no caller | derived |
| [`lib_string_length`](../../src/tensilica/lib/lib_string_length.S) | `fn_40004758` | Return the length of a zero-terminated text | proven |
| [`lib_swap_byte_order`](../../src/tensilica/lib/lib_swap_byte_order.S) | `fn_40004844` | Return a 32-bit value with its bytes reversed | proven |
| [`lib_swap_byte_order_words`](../../src/tensilica/lib/lib_swap_byte_order_words.S) | `fn_40004884` | Reverse the byte order of each word of an array (length in bytes) | proven |
| [`lib_swap_byte_order_words_volatile`](../../src/tensilica/lib/lib_swap_byte_order_words_volatile.S) | `fn_400048fc` | Reverse the byte order of size/4 words in place with volatile accesses | proven |
| [`lib_unused_return_zero`](../../src/tensilica/lib/lib_unused_return_zero.S) | `fn_40009a34` | Store a2..a7 in stack slots and return 0; no caller | descriptive |
| [`lib_vsprintf`](../../src/tensilica/lib/lib_vsprintf.S) | `fn_40009218` | Format text with %d %u %x %X %c %s %p %P %l*, width 1-9, '0' pad, into buf | derived |
| [`lib_write_bit_field`](../../src/tensilica/lib/lib_write_bit_field.S) | `fn_40003ff8` | Write a value into a bit field at a byte address, using aligned volatile word accesses | descriptive |
| [`lib_write_word`](../../src/tensilica/lib/lib_write_word.S) | `fn_4000497c` | Write a 32-bit word to an address | proven |
