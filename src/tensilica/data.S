# Initialised data: 0x4000d088-0x4000d8db (firmware file offset 0x3d088-0x3d8db)
# The reset code copies this region to RAM 0x3ffe2390-0x3ffe2be3 (section_table); the code uses the
# RAM addresses. Each label data_XXXXXXXX is the RAM address of the byte that follows it.

data_start:

# used by: ldc_merge_segments_average, ldc_merge_segments_average_no_black, ldc_merge_segments_blend,
#          ldc_init_panel_defaults, LDC_LoadPanel, ldc_post_brightness_status, ldc_cmd_set_ldc_mode,
#          ldc_cmd_set_user_pdim, ldc_cmd_set_dark_pdim, ldc_cmd_set_user_adim, ldc_cmd_set_user_global_gain,
#          ldc_cmd_set_gain_filter_mode, ldc_cmd_set_value_0x3c, ldc_cmd_set_value_0x3d,
#          ldc_cmd_set_value_0x3e, ldc_cmd_set_value_0x3f, ldc_cmd_set_value_0x5b, ldc_cmd_set_value_0x5c,
#          ldc_cmd_set_peaking, ldc_cmd_set_adim_max, ldc_cmd_set_adim_min, ldc_cmd_set_adim_bright_percent,
#          ldc_cmd_set_adim_level_and_percent, ldc_cmd_set_limit_upper_bound,
#          ldc_cmd_set_zone_peaking_percent, ldc_cmd_enable_input_duty_check, ldc_ramp_level_over_time,
#          ldc_pdim_select_user_or_dark, ldc_adim_map_through_curve, ldc_adim_apply_limit_upper_bound,
#          ldc_adim_apply_zone_peaking, ldc_adim_hold_on_sudden_rise, ldc_pdim_smooth_toward_target,
#          ldc_adim_smooth_toward_target, ldc_smooth_and_apply_global_gain, ldc_adim_raise_masked_channels,
#          ldc_pdim_raise_masked_channels, ldc_pdim_scale_to_4095, ldc_run_adim_path,
#          ldc_write_table_and_global_gain, ldc_print_debug_dump
ldc_dimming_settings = . - data_start + DATA_RAM # data_3ffe2390
	.word	0x00000020, 0x00000006, 0x00000040, 0x000003ff # 4000d088
	.word	0x00000fff              # 4000d098

# used by: ldc_as3824_update
data_3ffe23a4 = . - data_start + DATA_RAM
	.word	0x00000200, 0x00000200  # 4000d09c

# used by: ldc_level_curve_value, ldc_led_driver_type2_update
data_3ffe23ac = . - data_start + DATA_RAM
	.word	0x000003ff, 0x00000400, 0x00000050, 0x00000048 # 4000d0a4
	.word	0x00000028, 0x00000008, 0x0000000a, 0x0000000a # 4000d0b4
	.word	0x00000001, 0x000000ff, 0x00000078, 0x00000400 # 4000d0c4
	.word	0x00000000              # 4000d0d4

# used by: ldc_cmd_set_ldc_mode, ldc_cmd_set_gain_table1_point, ldc_cmd_load_gain_table, ldc_print_debug_dump
ldc_gain_table_anv1 = . - data_start + DATA_RAM # data_3ffe23e0
	.word	0x00000000, 0x00000800  # 4000d0d8

# used by: ldc_print_debug_dump
data_3ffe23e8 = . - data_start + DATA_RAM
	.word	0x00000040, 0x00000651  # 4000d0e0

# used by: ldc_print_debug_dump
data_3ffe23f0 = . - data_start + DATA_RAM
	.word	0x00000080, 0x000004cc  # 4000d0e8

# used by: ldc_print_debug_dump
data_3ffe23f8 = . - data_start + DATA_RAM
	.word	0x000000c8, 0x00000400  # 4000d0f0

# used by: ldc_print_debug_dump
data_3ffe2400 = . - data_start + DATA_RAM
	.word	0x000000ff, 0x00000400, 0x00000000, 0x00000000 # 4000d0f8

# used by: ldc_cmd_set_ldc_mode, ldc_cmd_load_gain_table
ldc_gain_table_flat = . - data_start + DATA_RAM # data_3ffe2410
	.word	0x00000000, 0x00000400, 0x000000ff, 0x00000400 # 4000d108

# used by: ldc_cmd_set_gain_table2_point, ldc_cmd_load_gain_table, ldc_print_debug_dump
ldc_gain_table_anv2 = . - data_start + DATA_RAM # data_3ffe2420
	.word	0x00000000, 0x00000733  # 4000d118

# used by: ldc_print_debug_dump
data_3ffe2428 = . - data_start + DATA_RAM
	.word	0x00000040, 0x00000600  # 4000d120

# used by: ldc_print_debug_dump
data_3ffe2430 = . - data_start + DATA_RAM
	.word	0x00000080, 0x000004cc  # 4000d128

# used by: ldc_print_debug_dump
data_3ffe2438 = . - data_start + DATA_RAM
	.word	0x000000e0, 0x00000400  # 4000d130

# used by: ldc_print_debug_dump
data_3ffe2440 = . - data_start + DATA_RAM
	.word	0x000000ff, 0x00000400, 0x00000000, 0x00000000 # 4000d138

# used by: ldc_cmd_set_gain_table3_point, ldc_cmd_load_gain_table, ldc_print_debug_dump
ldc_gain_table_anv3 = . - data_start + DATA_RAM # data_3ffe2450
	.word	0x00000000, 0x000008c8  # 4000d148

# used by: ldc_print_debug_dump
data_3ffe2458 = . - data_start + DATA_RAM
	.word	0x00000040, 0x00000651  # 4000d150

# used by: ldc_print_debug_dump
data_3ffe2460 = . - data_start + DATA_RAM
	.word	0x00000080, 0x00000546  # 4000d158

# used by: ldc_print_debug_dump
data_3ffe2468 = . - data_start + DATA_RAM
	.word	0x000000e0, 0x00000400  # 4000d160

# used by: ldc_print_debug_dump
data_3ffe2470 = . - data_start + DATA_RAM
	.word	0x000000ff, 0x00000400, 0x00000000, 0x00000000 # 4000d168

# used by: ldc_adim_map_through_curve
ldc_adim_curve_points = . - data_start + DATA_RAM # data_3ffe2480
	.word	0x00000000, 0x00000000, 0x00000ffc, 0x000003ff # 4000d178

# used by: ldc_filter_grid_3x3
ldc_filter_weights_16_32_64 = . - data_start + DATA_RAM # data_3ffe2490
	.word	0x00000010, 0x00000020, 0x00000010, 0x00000020 # 4000d188
	.word	0x00000040, 0x00000020, 0x00000010, 0x00000020 # 4000d198
	.word	0x00000010, 0x00000000, 0x00000000, 0x00000000 # 4000d1a8

# used by: ldc_filter_grid_3x3
ldc_filter_weights_28_32 = . - data_start + DATA_RAM # data_3ffe24c0
	.word	0x0000001c, 0x0000001c, 0x0000001c, 0x0000001c # 4000d1b8
	.word	0x00000020, 0x0000001c, 0x0000001c, 0x0000001c # 4000d1c8
	.word	0x0000001c, 0x00000000, 0x00000000, 0x00000000 # 4000d1d8
	.word	0x00000c50, 0x00000fff, 0x00000c84, 0x00000fd0 # 4000d1e8
	.word	0x00000cb8, 0x00000f40, 0x00000cf0, 0x00000ef0 # 4000d1f8
	.asciz	"$\r"                   # 4000d208
	.balign	4, 0                    # zero bytes up to the 4-byte boundary
	.word	0x00000e80, 0x00000d5c, 0x00000e22, 0x00000d94 # 4000d20c
	.word	0x00000dc0, 0x00000dd0, 0x00000d40, 0x00000e08 # 4000d21c
	.word	0x00000cbd, 0x00000e44, 0x00000c40, 0x00000e80 # 4000d22c
	.word	0x00000be0, 0x00000ebc, 0x00000b6f, 0x00000f38 # 4000d23c
	.word	0x00000a8b, 0x00000f78, 0x00000a29, 0x00000fbc # 4000d24c
	.word	0x000009b3, 0x00000fff, 0x00000975 # 4000d25c

# used by: ldc_cmd_set_led_current_on
ldc_first_current_on = . - data_start + DATA_RAM # data_3ffe2570
	.word	0x00000001              # 4000d268

# used by: ldc_check_input_duty_edges
ldc_input_duty_flag = . - data_start + DATA_RAM # data_3ffe2574
	.word	0x00000001, 0x00000001, 0x00000001 # 4000d26c

# used by: ldc_smooth_and_apply_global_gain
ldc_kept_global_gain = . - data_start + DATA_RAM # data_3ffe2580
	.word	0x00040000, 0x00000000, 0x00000000, 0x00000000 # 4000d278

# used by: ldc_build_command_index, ldc_poll_mailbox_command
ldc_command_table = . - data_start + DATA_RAM # data_3ffe2590
	.word	0x00000000              # 4000d288
	.word	ldc_cmd_ignore          # 4000d28c
	.word	0x00000020              # 4000d290
	.word	ldc_cmd_set_ldc_mode    # 4000d294
	.word	0x00000021              # 4000d298
	.word	ldc_cmd_load_panel_and_start # 4000d29c
	.word	0x00000022              # 4000d2a0
	.word	ldc_cmd_init_led_drivers # 4000d2a4
	.word	0x0000002a              # 4000d2a8
	.word	ldc_cmd_set_segment_grid # 4000d2ac
	.word	0x0000002b              # 4000d2b0
	.word	ldc_cmd_set_zone_counts # 4000d2b4
	.word	0x00000038              # 4000d2b8
	.word	ldc_cmd_set_led_current_on # 4000d2bc
	.word	0x00000030              # 4000d2c0
	.word	ldc_cmd_set_user_pdim   # 4000d2c4
	.word	0x00000031              # 4000d2c8
	.word	ldc_cmd_set_user_adim   # 4000d2cc
	.word	0x00000032              # 4000d2d0
	.word	ldc_cmd_set_dark_pdim   # 4000d2d4
	.word	0x00000033              # 4000d2d8
	.word	ldc_cmd_set_adim_max    # 4000d2dc
	.word	0x00000034              # 4000d2e0
	.word	ldc_cmd_set_adim_min    # 4000d2e4
	.word	0x00000035              # 4000d2e8
	.word	ldc_cmd_set_adim_bright_percent # 4000d2ec
	.word	0x00000036              # 4000d2f0
	.word	ldc_cmd_ignore          # 4000d2f4
	.word	0x00000037              # 4000d2f8
	.word	ldc_cmd_set_limit_upper_bound # 4000d2fc
	.word	0x00000039              # 4000d300
	.word	ldc_cmd_set_adim_level_and_percent # 4000d304
	.word	0x0000003a              # 4000d308
	.word	ldc_cmd_set_zone_peaking_percent # 4000d30c
	.word	0x0000003c              # 4000d310
	.word	ldc_cmd_set_value_0x3c  # 4000d314
	.word	0x0000003d              # 4000d318
	.word	ldc_cmd_set_value_0x3d  # 4000d31c
	.word	0x0000003e              # 4000d320
	.word	ldc_cmd_set_value_0x3e  # 4000d324
	.word	0x0000003f              # 4000d328
	.word	ldc_cmd_set_value_0x3f  # 4000d32c
	.word	0x00000040              # 4000d330
	.word	ldc_cmd_dpll_init_check # 4000d334
	.word	0x00000041              # 4000d338
	.word	ldc_cmd_set_segment_merge_mode # 4000d33c
	.word	0x00000042              # 4000d340
	.word	ldc_cmd_set_reg28c_bits4_6 # 4000d344
	.word	0x00000043              # 4000d348
	.word	ldc_cmd_set_reg00c_bit7 # 4000d34c
	.word	0x00000044              # 4000d350
	.word	ldc_cmd_set_reg290_high # 4000d354
	.word	0x00000046              # 4000d358
	.word	ldc_cmd_set_ds_divider  # 4000d35c
	.word	0x00000050              # 4000d360
	.word	ldc_cmd_load_gain_table # 4000d364
	.word	0x00000051              # 4000d368
	.word	ldc_cmd_set_gain_table1_point # 4000d36c
	.word	0x00000052              # 4000d370
	.word	ldc_cmd_set_gain_table2_point # 4000d374
	.word	0x00000053              # 4000d378
	.word	ldc_cmd_set_gain_table3_point # 4000d37c
	.word	0x0000005a              # 4000d380
	.word	ldc_cmd_set_user_global_gain # 4000d384
	.word	0x0000005b              # 4000d388
	.word	ldc_cmd_set_value_0x5b  # 4000d38c
	.word	0x0000005c              # 4000d390
	.word	ldc_cmd_set_value_0x5c  # 4000d394
	.word	0x0000005d              # 4000d398
	.word	ldc_cmd_set_gain_filter_mode # 4000d39c
	.word	0x00000060              # 4000d3a0
	.word	ldc_cmd_set_direct_pwm  # 4000d3a4
	.word	0x00000061              # 4000d3a8
	.word	ldc_cmd_write_as3824_register # 4000d3ac
	.word	0x00000094              # 4000d3b0
	.word	ldc_cmd_ignore_0x94     # 4000d3b4
	.word	0x00000095              # 4000d3b8
	.word	ldc_cmd_ignore_0x95     # 4000d3bc
	.word	0x00000096              # 4000d3c0
	.word	ldc_cmd_ignore_0x96     # 4000d3c4
	.word	0x00000077              # 4000d3c8
	.word	ldc_cmd_write_register_byte # 4000d3cc
	.word	0x00000083              # 4000d3d0
	.word	ldc_cmd_set_reg5a4_bit2 # 4000d3d4
	.word	0x00000084              # 4000d3d8
	.word	ldc_cmd_set_reg168      # 4000d3dc
	.word	0x00000085              # 4000d3e0
	.word	ldc_cmd_set_reg280_bytes # 4000d3e4
	.word	0x00000082              # 4000d3e8
	.word	ldc_cmd_set_peaking     # 4000d3ec
	.word	0x00000097              # 4000d3f0
	.word	ldc_cmd_enable_input_duty_check # 4000d3f4

# used by: dbg_memcmd_echo_char, dbg_memcmd_mr, dbg_memcmd_md, dbg_memcmd_poll_console
dbg_memcmd_verbose = . - data_start + DATA_RAM # data_3ffe2700
	.word	0x00000001              # 4000d3f8

# used by: dbg_init_uart_print_banner
dbg_uart_config = . - data_start + DATA_RAM # data_3ffe2704
	.word	0x0001c200, 0x00000003, 0x00000000, 0x00000000 # 4000d3fc
	.word	0x00000004, 0x00000000, 0x00000000 # 4000d40c

# used by: dbg_memcmd_poll_console
dbg_memcmd_table = . - data_start + DATA_RAM # data_3ffe2720
	.word	ro_3ffe04f0             # 4000d418
	.word	dbg_memcmd_mr           # 4000d41c
	.word	ro_3ffe04f4             # 4000d420
	.word	dbg_memcmd_mw           # 4000d424
	.word	ro_3ffe04f8             # 4000d428
	.word	dbg_memcmd_md           # 4000d42c
	.word	ro_3ffe04fc             # 4000d430
	.word	dbg_memcmd_cfg          # 4000d434

# used by: dbg_cmd_help
dbg_help_texts = . - data_start + DATA_RAM # data_3ffe2740
	.word	ro_3ffe07c0             # 4000d438
	.word	ro_3ffe07fc             # 4000d43c
	.word	ro_3ffe0828             # 4000d440
	.word	ro_3ffe0864             # 4000d444
	.word	ro_3ffe0888             # 4000d448
	.word	0x00000000              # 4000d44c

# used by: timer_toggle_expstate_bit9
data_3ffe2758 = . - data_start + DATA_RAM
	.word	0x00000001              # 4000d450

# used by: timer_toggle_expstate_bit19
data_3ffe275c = . - data_start + DATA_RAM
	.word	0x00000001              # 4000d454

# used by: ldc_build_segment_channel_map, ldc_merge_segments_maximum, ldc_merge_segments_average,
#          ldc_merge_segments_average_no_black, ldc_merge_segments_blend, ldc_check_input_duty_edges,
#          ldc_fill_segment_values, ldc_write_table_and_global_gain, ldc_print_debug_dump,
#          DRV_LDC_SetLDCSegment, ldc_read_segment_values
ldc_segment_count = . - data_start + DATA_RAM # data_3ffe2760
	.word	0x00000200              # 4000d458

# used by: ldc_cmd_dpll_init_check, ldc_run_pass_on_new_frame
ldc_dpll_init_done = . - data_start + DATA_RAM # data_3ffe2764
	.word	0x00000001, 0x00000000, 0x00000000 # 4000d45c

# used by: ldc_hw_load_default_registers
ldc_hw_default_registers = . - data_start + DATA_RAM # data_3ffe2770
	.word	0xe0080000, 0x05061010, 0xe008000c, 0x00000808 # 4000d468
	.word	0xe0080010, 0x02000100, 0xe0080014, 0x00000300 # 4000d478
	.word	0xe0080024, 0x00800000, 0xe0080040, 0x00780000 # 4000d488
	.word	0xe0080134, 0x80808080, 0xe0080138, 0x00190019 # 4000d498
	.word	0xe008013c, 0x84658465, 0xe0080140, 0x00190019 # 4000d4a8
	.word	0xe0080160, 0x00000000, 0xe0080164, 0x00013001 # 4000d4b8
	.word	0xe0080168, 0x05000000, 0xe0080174, 0x00004001 # 4000d4c8
	.word	0xe0080274, 0x00000000, 0xe0080278, 0x00000000 # 4000d4d8
	.word	0xe0080280, 0x10000101, 0xe0080284, 0x0a142538 # 4000d4e8
	.word	0xe0080288, 0x00000205, 0xe008028c, 0x00400010 # 4000d4f8
	.word	0xe0080290, 0x40400000, 0xe00802c0, 0x00000000 # 4000d508
	.word	0xe00802c4, 0x0fff0fff, 0xe00802c8, 0x01804040 # 4000d518
	.word	0xe00802fc, 0x00000000, 0xe0080314, 0x0ccc0999 # 4000d528
	.word	0xe0080320, 0x0fffff00, 0xe0080324, 0x04000100 # 4000d538
	.word	0xe008032c, 0x00800300, 0xe008033c, 0x00000001 # 4000d548
	.word	0xe0080340, 0x00000000, 0xe0080370, 0x01010420 # 4000d558
	.word	0xe0080388, 0x00000006, 0xe008038c, 0x00000000 # 4000d568
	.word	0xe0080398, 0xfff00001, 0xe00803a0, 0x00000000 # 4000d578
	.word	0xe0080500, 0x000fff00, 0xe0080504, 0x01000100 # 4000d588
	.word	0xe0080508, 0x00000000, 0xe008050c, 0x03c00000 # 4000d598
	.word	0xe0080510, 0x021c0000, 0xe0080514, 0x00010001 # 4000d5a8
	.word	0xe0080518, 0x0fff0fff, 0xe008051c, 0x00000fff # 4000d5b8
	.word	0xe00805a4, 0x00000004, 0xe00805b0, 0x00000000 # 4000d5c8
	.word	0xe00805b4, 0x00000000, 0xe00805b8, 0x00000000 # 4000d5d8
	.word	0xe00805bc, 0x00000000, 0xe00805c0, 0x00000000 # 4000d5e8
	.word	0xe00805d0, 0x00000000, 0xe00805d4, 0x00000000 # 4000d5f8
	.word	0xe0080a04, 0x3fffffff, 0xe0080a14, 0x03ff03ff # 4000d608
	.word	0xe0080a18, 0x04000400, 0xe0080a1c, 0x04000400 # 4000d618
	.word	0xe0080a24, 0x04000400, 0xe0080a2c, 0x00000600 # 4000d628
	.word	0xe008000c, 0x00000809, 0x00000000, 0x00000000 # 4000d638
	.word	0x00000000, 0x00000f00, 0x0000011d, 0x00000f00 # 4000d648
	.word	0x000001bd, 0x00000a80, 0x00000271, 0x00000890 # 4000d658
	.word	0x0000036b, 0x000007c7, 0x000003f3, 0x000006d0 # 4000d668
	.word	0x00000472, 0x00000670, 0x00000649, 0x00000600 # 4000d678
	.word	0x000008e6, 0x00000535, 0x00000b6a, 0x000004b6 # 4000d688
	.word	0x00000ce4, 0x0000046d, 0x00000e8c, 0x0000043b # 4000d698
	.word	0x00000fcc, 0x00000400, 0x00000000, 0x00000000 # 4000d6a8
	.word	0x00000000, 0x00000f00, 0x0000011d, 0x00000f00 # 4000d6b8
	.word	0x000001bd, 0x00000a30, 0x00000267, 0x00000830 # 4000d6c8
	.word	0x000003f3, 0x000006d0, 0x00000472, 0x00000670 # 4000d6d8
	.word	0x00000649, 0x000005eb, 0x000008e6, 0x0000050a # 4000d6e8
	.word	0x00000b6a, 0x000004aa, 0x00000ce4, 0x00000464 # 4000d6f8
	.word	0x00000e8c, 0x00000432, 0x00000fcc, 0x00000400 # 4000d708

# used by: ldc_as3824_update
ldc_as3824_last_led_mode = . - data_start + DATA_RAM # data_3ffe2a20
	.word	0x00000003, 0x00000000, 0x00000000, 0x00000000 # 4000d718

# used by: ldc_level_curve_value, irq_dispatch_level1
ldc_level_curve = . - data_start + DATA_RAM # data_3ffe2a30
	.word	0x00000000, 0x00000580, 0x00000036, 0x00000580 # 4000d728
	.word	0x0000003b, 0x000004a8, 0x00000046, 0x00000368 # 4000d738
	.word	0x00000050, 0x0000027c, 0x0000005b, 0x000001bc # 4000d748
	.word	0x00000061, 0x00000140, 0x00000064, 0x00000140 # 4000d758

# used by: reset_40000400, word at 0x4000042c
data_3ffe2a70 = . - data_start + DATA_RAM
	.word	0x00000000, 0x00000000  # 4000d768

# used by: irq_enable, irq_disable, irq_dispatch_level1
irq_enable_state = . - data_start + DATA_RAM # data_3ffe2a78
	.word	0x00000000, 0xffffffff  # 4000d770

# used by: irq_set_handler_and_arg, irq_dispatch_level3, irq_dispatch_level5
irq_handler_table = . - data_start + DATA_RAM # data_3ffe2a80
	.word	irq_default_handler     # 4000d778
	.word	0x00000015              # 4000d77c
	.word	irq_default_handler     # 4000d780
	.word	0x00000014              # 4000d784
	.word	irq_default_handler     # 4000d788
	.word	0x00000013              # 4000d78c
	.word	irq_default_handler     # 4000d790
	.word	0x00000012              # 4000d794
	.word	irq_default_handler     # 4000d798
	.word	0x00000011              # 4000d79c
	.word	irq_default_handler     # 4000d7a0
	.word	0x00000010              # 4000d7a4
	.word	irq_default_handler     # 4000d7a8
	.word	0x0000000f              # 4000d7ac
	.word	irq_default_handler     # 4000d7b0
	.word	0x0000000e              # 4000d7b4
	.word	irq_default_handler     # 4000d7b8
	.word	0x0000000d              # 4000d7bc
	.word	irq_default_handler     # 4000d7c0
	.word	0x0000000c              # 4000d7c4
	.word	irq_default_handler     # 4000d7c8
	.word	0x0000000b              # 4000d7cc
	.word	irq_default_handler     # 4000d7d0
	.word	0x0000000a              # 4000d7d4
	.word	irq_default_handler     # 4000d7d8
	.word	0x00000009              # 4000d7dc
	.word	irq_default_handler     # 4000d7e0
	.word	0x00000008              # 4000d7e4
	.word	irq_default_handler     # 4000d7e8
	.word	0x00000007              # 4000d7ec
	.word	irq_default_handler     # 4000d7f0
	.word	0x00000006              # 4000d7f4
	.word	irq_default_handler     # 4000d7f8
	.word	0x00000005              # 4000d7fc
	.word	irq_default_handler     # 4000d800
	.word	0x00000004              # 4000d804
	.word	irq_default_handler     # 4000d808
	.word	0x00000003              # 4000d80c
	.word	irq_default_handler     # 4000d810
	.word	0x00000002              # 4000d814
	.word	irq_default_handler     # 4000d818
	.word	0x00000001              # 4000d81c
	.word	irq_default_handler     # 4000d820
	.word	0x00000000, 0xffe07f00, 0x00200000, 0xffe07f00 # 4000d824
	.word	0x00100000, 0xfff07f00, 0x00080000, 0xfff87f00 # 4000d834
	.word	0x00040000, 0xfffc7f00, 0x00020000, 0xfffe7f00 # 4000d844
	.word	0x00010000, 0xffff7f00, 0x00008000, 0xffffff00 # 4000d854
	.word	0x00004000, 0xffffff00, 0x00002000, 0xffffff00 # 4000d864
	.word	0x00001000, 0xffffff00, 0x00000800, 0xffffff00 # 4000d874
	.word	0x00000400, 0xffffff00, 0x00000200, 0xffffff00 # 4000d884
	.word	0x00000100, 0xffffff00, 0x00000080, 0xffffff80 # 4000d894
	.word	0x00000040, 0xffffffc0, 0x00000020, 0xffffffe0 # 4000d8a4
	.word	0x00000010, 0xfffffff0, 0x00000008, 0xfffffff8 # 4000d8b4
	.word	0x00000004, 0xfffffffc, 0x00000002, 0xfffffffe # 4000d8c4
	.word	0x00000001              # 4000d8d4

# used by: irq_dispatch_level5, reset_40000400, word at 0x40000434
irq_level5_handler_address = . - data_start + DATA_RAM # data_3ffe2be0
	.word	0x00000000              # 4000d8d8
data_end:
image_end:
