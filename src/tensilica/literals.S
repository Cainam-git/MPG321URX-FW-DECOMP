# Literal words of the program code (read with l32r): 0x4000c768-0x4000d083 (firmware file offset 0x3c768-0x3d083)
# The reset code copies this region to RAM 0x3ffe1a70-0x3ffe238b (section_table); the code uses the
# RAM addresses. Each label lit_XXXXXXXX is the RAM address of the byte that follows it.
# The literal word for each l32r of the program code; the l32r names its word by the
# RAM address (lit_XXXXXXXX). Code addresses are written as labels, RAM addresses of
# copied data as ro_/data_ names.

literals_start:
# used by: startup_zero_bss_and_run_main
lit_3ffe1a70 = . - literals_start + LITERALS_RAM
	.word	0x3ffef000              # 4000c768
lit_3ffe1a74 = . - literals_start + LITERALS_RAM
	.word	0x00040020              # 4000c76c
lit_3ffe1a78 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2bf0              # 4000c770
lit_3ffe1a7c = . - literals_start + LITERALS_RAM
	.word	0x3ffe6448              # 4000c774
# used by: ldc_build_segment_channel_map, ldc_select_led_driver, ldc_init_panel_defaults, LDC_LoadPanel,
#          ldc_post_brightness_status, ldc_cmd_load_panel_and_start, ldc_cmd_set_ldc_mode,
#          ldc_cmd_set_dark_pdim, ldc_cmd_set_user_adim, ldc_cmd_set_peaking, ldc_cmd_set_segment_merge_mode,
#          ldc_cmd_set_adim_bright_percent, ldc_cmd_set_direct_pwm, ldc_cmd_write_as3824_register,
#          ldc_cmd_set_led_current_on, ldc_cmd_enable_input_duty_check, ldc_ramp_level_over_time,
#          ldc_pdim_select_user_or_dark, ldc_post_segment_percent, ldc_print_debug_dump,
#          ldc_follow_mode_and_run_led_driver, ldc_run_frame_pass, ldc_run_pass_on_new_frame,
#          ldc_led_driver_type0_update
lit_3ffe1a80 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2bf0              # 4000c778
# used by: ldc_build_segment_channel_map, ldc_cmd_load_panel_and_start, ldc_print_debug_dump,
#          ldc_hw_set_zone_area_factors, DRV_LDC_SetPanelResolution, ldc_set_zone_count_exponents,
#          DRV_LDC_UpdateSegmentBoundary, DRV_LDC_SetLDCSegment, DRV_LDC_SetDSRegisters, ldc_set_ds_divider,
#          ldc_hw_set_reg168_fields
lit_3ffe1a84 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4450              # 4000c77c
# used by: ldc_build_segment_channel_map, ldc_merge_segments_maximum, ldc_merge_segments_average,
#          ldc_merge_segments_average_no_black, ldc_merge_segments_blend, ldc_check_input_duty_edges,
#          ldc_fill_segment_values, ldc_write_table_and_global_gain, ldc_print_debug_dump,
#          DRV_LDC_SetLDCSegment, ldc_read_segment_values
lit_3ffe1a88 = . - literals_start + LITERALS_RAM
	.word	ldc_segment_count       # 4000c780
# used by: ldc_build_segment_channel_map, ldc_merge_segments_maximum, ldc_merge_segments_average,
#          ldc_merge_segments_average_no_black, ldc_merge_segments_blend, ldc_fill_segment_values
lit_3ffe1a8c = . - literals_start + LITERALS_RAM
	.word	0x3ffe2d70              # 4000c784
# used by: ldc_build_segment_channel_map
lit_3ffe1a90 = . - literals_start + LITERALS_RAM
	.word	0x00000800              # 4000c788
# used by: ldc_build_segment_channel_map, ldc_merge_segments_average, ldc_merge_segments_average_no_black,
#          ldc_merge_segments_blend
lit_3ffe1a94 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3d70              # 4000c78c
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
lit_3ffe1a98 = . - literals_start + LITERALS_RAM
	.word	ldc_dimming_settings    # 4000c790
# used by: ldc_select_led_driver
lit_3ffe1a9c = . - literals_start + LITERALS_RAM
	.word	ldc_as3824_update       # 4000c794
lit_3ffe1aa0 = . - literals_start + LITERALS_RAM
	.word	ldc_led_driver_type2_update # 4000c798
lit_3ffe1aa4 = . - literals_start + LITERALS_RAM
	.word	ldc_led_driver_type0_update # 4000c79c
# used by: ldc_init_panel_defaults
lit_3ffe1aa8 = . - literals_start + LITERALS_RAM
	.word	0xe0091010              # 4000c7a0
# used by: ldc_init_panel_defaults, ldc_adim_smooth_toward_target
lit_3ffe1aac = . - literals_start + LITERALS_RAM
	.word	0x3ffe3db0              # 4000c7a4
# used by: ldc_init_panel_defaults
lit_3ffe1ab0 = . - literals_start + LITERALS_RAM
	.word	0x00020000              # 4000c7a8
# used by: ldc_init_panel_defaults, ldc_pdim_smooth_toward_target
lit_3ffe1ab4 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3e30              # 4000c7ac
# used by: ldc_init_panel_defaults
lit_3ffe1ab8 = . - literals_start + LITERALS_RAM
	.word	0x000fff00              # 4000c7b0
# used by: ldc_init_panel_defaults, ldc_post_brightness_status, ldc_cmd_set_user_pdim,
#          ldc_pdim_smooth_toward_target, ldc_pdim_raise_masked_channels, ldc_pdim_scale_to_4095,
#          DRV_LDC_UpdateSegmentBoundary, LED_AS3824_Init
lit_3ffe1abc = . - literals_start + LITERALS_RAM
	.word	0x00000fff              # 4000c7b4
# used by: ldc_init_panel_defaults, ldc_post_brightness_status, ldc_cmd_set_ldc_mode, ldc_cmd_set_user_pdim,
#          ldc_pdim_smooth_toward_target, ldc_run_pdim_path, ldc_print_debug_dump, ldc_as3824_update,
#          ldc_led_driver_type0_update
lit_3ffe1ac0 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3eb0              # 4000c7b8
# used by: ldc_init_panel_defaults, ldc_post_brightness_status, ldc_cmd_set_ldc_mode, ldc_cmd_set_user_adim,
#          ldc_cmd_set_adim_bright_percent, ldc_adim_smooth_toward_target, ldc_run_adim_path,
#          ldc_print_debug_dump, ldc_run_frame_pass, ldc_as3824_update, ldc_led_driver_type0_update
lit_3ffe1ac4 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3ef0              # 4000c7bc
# used by: ldc_init_panel_defaults, ldc_hw_init
lit_3ffe1ac8 = . - literals_start + LITERALS_RAM
	.word	0x00000870              # 4000c7c0
lit_3ffe1acc = . - literals_start + LITERALS_RAM
	.word	0x00000f00              # 4000c7c4
# used by: ldc_init_panel_defaults, LDC_LoadPanel
lit_3ffe1ad0 = . - literals_start + LITERALS_RAM
	.word	0xe00910a0              # 4000c7c8
lit_3ffe1ad4 = . - literals_start + LITERALS_RAM
	.word	0xe00910a4              # 4000c7cc
lit_3ffe1ad8 = . - literals_start + LITERALS_RAM
	.word	0xe00910a8              # 4000c7d0
lit_3ffe1adc = . - literals_start + LITERALS_RAM
	.word	0xe00910ac              # 4000c7d4
# used by: ldc_init_panel_defaults, ldc_cmd_set_segment_merge_mode
lit_3ffe1ae0 = . - literals_start + LITERALS_RAM
	.word	ldc_merge_segments_maximum # 4000c7d8
# used by: LDC_LoadPanel
lit_3ffe1ae4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0000             # 4000c7dc "Configured seg size is over than tensilica seg buf size!!\n"
lit_3ffe1ae8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe003c             # 4000c7e0 "Leon2M conf LED_col = %d, LED_row = %d\n"
lit_3ffe1aec = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0064             # 4000c7e4 "Tensilica LED_CH_NUM = %d\n"
lit_3ffe1af0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0080             # 4000c7e8 "LDC_LoadPanel Error!!\n"
lit_3ffe1af4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0098             # 4000c7ec "PanelInfo\r\n"
lit_3ffe1af8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe00a4             # 4000c7f0 "Resolution: %d x %d\r\n"
lit_3ffe1afc = . - literals_start + LITERALS_RAM
	.word	ro_3ffe00bc             # 4000c7f4 "DriverDuty: Max %04x Min %04x\r\n"
lit_3ffe1b00 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe00dc             # 4000c7f8 "LEDRowCol: %02d x %02d : %02d\r\n"
lit_3ffe1b04 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe00fc             # 4000c7fc "DriverType: Type %02x Num %02x Seq %02x\r\n"
# used by: LDC_LoadPanel, LED_AS3824_Init, ldc_led_driver_type0_update
lit_3ffe1b08 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2c24              # 4000c800
# used by: LDC_LoadPanel
lit_3ffe1b0c = . - literals_start + LITERALS_RAM
	.word	0xe00910c0              # 4000c804
# used by: ldc_post_brightness_status
lit_3ffe1b10 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f30              # 4000c808
# used by: ldc_post_brightness_status, ldc_ramp_level_over_time
lit_3ffe1b14 = . - literals_start + LITERALS_RAM
	.word	0xe009104c              # 4000c80c
# used by: ldc_cmd_load_panel_and_start, ldc_post_segment_percent
lit_3ffe1b18 = . - literals_start + LITERALS_RAM
	.word	0x00000d70              # 4000c810
lit_3ffe1b1c = . - literals_start + LITERALS_RAM
	.word	0x00001400              # 4000c814
# used by: ldc_cmd_set_ldc_mode, ldc_cmd_set_gain_table1_point, ldc_cmd_load_gain_table, ldc_print_debug_dump
lit_3ffe1b20 = . - literals_start + LITERALS_RAM
	.word	ldc_gain_table_anv1     # 4000c818
# used by: ldc_cmd_set_ldc_mode, ldc_cmd_load_gain_table
lit_3ffe1b24 = . - literals_start + LITERALS_RAM
	.word	ldc_gain_table_flat     # 4000c81c
# used by: ldc_cmd_set_user_pdim, ldc_cmd_set_user_adim, ldc_cmd_set_adim_bright_percent
lit_3ffe1b28 = . - literals_start + LITERALS_RAM
	.word	0xe0091028              # 4000c820
# used by: ldc_cmd_set_peaking
lit_3ffe1b2c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0128             # 4000c824 "Current Stress Staus = %d (Peaking OFF)\n"
lit_3ffe1b30 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0154             # 4000c828 "Current Stress Staus = %d (Peaking ON)\n"
# used by: ldc_cmd_dpll_init_check, ldc_run_pass_on_new_frame
lit_3ffe1b34 = . - literals_start + LITERALS_RAM
	.word	ldc_dpll_init_done      # 4000c82c
# used by: ldc_cmd_dpll_init_check
lit_3ffe1b38 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe017c             # 4000c830 "MAILBOX_DPLL INIT DONE!!\n"
lit_3ffe1b3c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0198             # 4000c834 "MAILBOX_DPLL NOT INIT!!\n"
# used by: ldc_cmd_set_segment_merge_mode
lit_3ffe1b40 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe01b4             # 4000c838 "Segment Merge Mode: Maximum \n"
lit_3ffe1b44 = . - literals_start + LITERALS_RAM
	.word	ldc_merge_segments_average # 4000c83c
lit_3ffe1b48 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe01d4             # 4000c840 "Segment Merge Mode: Average \n"
lit_3ffe1b4c = . - literals_start + LITERALS_RAM
	.word	ldc_merge_segments_average_no_black # 4000c844
lit_3ffe1b50 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe01f4             # 4000c848 "Segment Merge Mode: Average exclude black  \n"
lit_3ffe1b54 = . - literals_start + LITERALS_RAM
	.word	ldc_merge_segments_blend # 4000c84c
lit_3ffe1b58 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0224             # 4000c850 "Segment Merge Mode: Blend \n"
# used by: ldc_gain_table_set_point
lit_3ffe1b5c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0240             # 4000c854 "Selected entry is out of range of table!\n"
# used by: ldc_cmd_set_gain_table2_point, ldc_cmd_load_gain_table, ldc_print_debug_dump
lit_3ffe1b60 = . - literals_start + LITERALS_RAM
	.word	ldc_gain_table_anv2     # 4000c858
# used by: ldc_cmd_set_gain_table3_point, ldc_cmd_load_gain_table, ldc_print_debug_dump
lit_3ffe1b64 = . - literals_start + LITERALS_RAM
	.word	ldc_gain_table_anv3     # 4000c85c
# used by: ldc_cmd_set_led_current_on
lit_3ffe1b68 = . - literals_start + LITERALS_RAM
	.word	ldc_first_current_on    # 4000c860
lit_3ffe1b6c = . - literals_start + LITERALS_RAM
	.word	0x00001388              # 4000c864
# used by: ldc_cmd_set_led_current_on, dbg_run_star_request, dbg_parse_star_request,
#          ldc_hw_set_zone_area_factors
lit_3ffe1b70 = . - literals_start + LITERALS_RAM
	.word	0x0000ffff              # 4000c868
# used by: ldc_cmd_write_register_byte, ldc_set_zone_count_exponents, DRV_LDC_SetLDCSegment
lit_3ffe1b74 = . - literals_start + LITERALS_RAM
	.word	0xe0080000              # 4000c86c
# used by: ldc_check_duty_level_and_pair_sums, ldc_check_result_words_above_63,
#          ldc_check_values_and_mailbox_ranges, ldc_post_segment_percent
lit_3ffe1b78 = . - literals_start + LITERALS_RAM
	.word	0xe0080700              # 4000c870
# used by: ldc_check_duty_level_and_pair_sums
lit_3ffe1b7c = . - literals_start + LITERALS_RAM
	.word	0x00038270              # 4000c874
# used by: ldc_check_duty_level_and_pair_sums, ldc_check_values_and_mailbox_ranges
lit_3ffe1b80 = . - literals_start + LITERALS_RAM
	.word	0xe0091040              # 4000c878
lit_3ffe1b84 = . - literals_start + LITERALS_RAM
	.word	0x00038400              # 4000c87c
# used by: ldc_check_input_duty_edges, ldc_fill_segment_values, ldc_post_segment_percent,
#          ldc_print_debug_dump, ldc_run_frame_pass, ldc_preset_segment_values, ldc_read_segment_values,
#          ldc_led_driver_type2_update
lit_3ffe1b88 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4490              # 4000c880
# used by: ldc_check_input_duty_edges
lit_3ffe1b8c = . - literals_start + LITERALS_RAM
	.word	ldc_input_duty_flag     # 4000c884
# used by: ldc_check_result_words_above_63
lit_3ffe1b90 = . - literals_start + LITERALS_RAM
	.word	0xe009106c              # 4000c888
lit_3ffe1b94 = . - literals_start + LITERALS_RAM
	.word	0xe0091068              # 4000c88c
# used by: ldc_check_curve_register_order
lit_3ffe1b98 = . - literals_start + LITERALS_RAM
	.word	0xe00831c0              # 4000c890
lit_3ffe1b9c = . - literals_start + LITERALS_RAM
	.word	0xe00831e0              # 4000c894
lit_3ffe1ba0 = . - literals_start + LITERALS_RAM
	.word	0xe0091074              # 4000c898
# used by: ldc_ramp_level_over_time
lit_3ffe1ba4 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f34              # 4000c89c
lit_3ffe1ba8 = . - literals_start + LITERALS_RAM
	.word	0x000112a8              # 4000c8a0
# used by: ldc_adim_map_through_curve
lit_3ffe1bac = . - literals_start + LITERALS_RAM
	.word	ldc_adim_curve_points   # 4000c8a4
# used by: ldc_adim_hold_on_sudden_rise
lit_3ffe1bb0 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f38              # 4000c8a8
lit_3ffe1bb4 = . - literals_start + LITERALS_RAM
	.word	0x0007a120              # 4000c8ac
lit_3ffe1bb8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f3c              # 4000c8b0
lit_3ffe1bbc = . - literals_start + LITERALS_RAM
	.word	0x000088b7              # 4000c8b4
lit_3ffe1bc0 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f40              # 4000c8b8
lit_3ffe1bc4 = . - literals_start + LITERALS_RAM
	.word	0x00000bb8              # 4000c8bc
# used by: ldc_filter_grid_3x3
lit_3ffe1bc8 = . - literals_start + LITERALS_RAM
	.word	ldc_filter_weights_16_32_64 # 4000c8c0
lit_3ffe1bcc = . - literals_start + LITERALS_RAM
	.word	ldc_filter_weights_28_32 # 4000c8c4
# used by: ldc_smooth_and_apply_global_gain
lit_3ffe1bd0 = . - literals_start + LITERALS_RAM
	.word	ldc_kept_global_gain    # 4000c8c8
lit_3ffe1bd4 = . - literals_start + LITERALS_RAM
	.word	0x00000d00              # 4000c8cc
# used by: ldc_adim_raise_masked_channels, ldc_pdim_raise_masked_channels, ldc_led_driver_type2_update
lit_3ffe1bd8 = . - literals_start + LITERALS_RAM
	.word	0xe0091038              # 4000c8d0
# used by: ldc_pdim_scale_to_4095, ldc_preset_segment_values, ldc_led_driver_type2_update
lit_3ffe1bdc = . - literals_start + LITERALS_RAM
	.word	0x00000ffc              # 4000c8d4
# used by: ldc_post_segment_percent
lit_3ffe1be0 = . - literals_start + LITERALS_RAM
	.word	0xe0091094              # 4000c8d8
# used by: ldc_post_segment_percent, DRV_LDC_SetDSRegisters
lit_3ffe1be4 = . - literals_start + LITERALS_RAM
	.word	0xe0080370              # 4000c8dc
# used by: ldc_post_segment_percent
lit_3ffe1be8 = . - literals_start + LITERALS_RAM
	.word	0xe0080704              # 4000c8e0
lit_3ffe1bec = . - literals_start + LITERALS_RAM
	.word	0xe0080708              # 4000c8e4
lit_3ffe1bf0 = . - literals_start + LITERALS_RAM
	.word	0xe0091090              # 4000c8e8
# used by: ldc_print_debug_dump, dbg_cmd_msg1, dbg_cmd_msg0
lit_3ffe1bf4 = . - literals_start + LITERALS_RAM
	.word	0xe0091084              # 4000c8ec
# used by: ldc_print_debug_dump
lit_3ffe1bf8 = . - literals_start + LITERALS_RAM
	.word	0xe0091080              # 4000c8f0
lit_3ffe1bfc = . - literals_start + LITERALS_RAM
	.word	ro_3ffe026c             # 4000c8f4 "Input Duty:\n"
lit_3ffe1c00 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe027c             # 4000c8f8
lit_3ffe1c04 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0280             # 4000c8fc "\t%04X "
lit_3ffe1c08 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0288             # 4000c900
lit_3ffe1c0c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe028c             # 4000c904 "LDC_GainTable_ANV1: \n"
lit_3ffe1c10 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe02a4             # 4000c908 "\t%04d, \t%04d \n"
lit_3ffe1c14 = . - literals_start + LITERALS_RAM
	.word	data_3ffe23e8           # 4000c90c
lit_3ffe1c18 = . - literals_start + LITERALS_RAM
	.word	data_3ffe23f0           # 4000c910
lit_3ffe1c1c = . - literals_start + LITERALS_RAM
	.word	data_3ffe23f8           # 4000c914
lit_3ffe1c20 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe02b4             # 4000c918 "\t%04d, \t%04d \n\n"
lit_3ffe1c24 = . - literals_start + LITERALS_RAM
	.word	data_3ffe2400           # 4000c91c
lit_3ffe1c28 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe02c4             # 4000c920 "LDC_GainTable_ANV2: \n"
lit_3ffe1c2c = . - literals_start + LITERALS_RAM
	.word	data_3ffe2428           # 4000c924
lit_3ffe1c30 = . - literals_start + LITERALS_RAM
	.word	data_3ffe2430           # 4000c928
lit_3ffe1c34 = . - literals_start + LITERALS_RAM
	.word	data_3ffe2438           # 4000c92c
lit_3ffe1c38 = . - literals_start + LITERALS_RAM
	.word	data_3ffe2440           # 4000c930
lit_3ffe1c3c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe02dc             # 4000c934 "LDC_GainTable_ANV3: \n"
lit_3ffe1c40 = . - literals_start + LITERALS_RAM
	.word	data_3ffe2458           # 4000c938
lit_3ffe1c44 = . - literals_start + LITERALS_RAM
	.word	data_3ffe2460           # 4000c93c
lit_3ffe1c48 = . - literals_start + LITERALS_RAM
	.word	data_3ffe2468           # 4000c940
lit_3ffe1c4c = . - literals_start + LITERALS_RAM
	.word	data_3ffe2470           # 4000c944
lit_3ffe1c50 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe02f4             # 4000c948 "LED_Mode = \t%04X\n"
lit_3ffe1c54 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0308             # 4000c94c "LDC_Mode = \t%04X\n"
lit_3ffe1c58 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe031c             # 4000c950 "usUserPDIM = \t%04X\n"
lit_3ffe1c5c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0330             # 4000c954 "usUserADIM = \t%04X\n"
lit_3ffe1c60 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0344             # 4000c958 "ADIM_Max = \t%04X\n"
lit_3ffe1c64 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0358             # 4000c95c "ADIM_Min = \t%04X\n"
lit_3ffe1c68 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe036c             # 4000c960 "ADIM_BrighPercent = \t%04X\n"
lit_3ffe1c6c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0388             # 4000c964 "PercentADIM = \t%04X\n"
lit_3ffe1c70 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe03a0             # 4000c968 "LimitUpperBound = \t%04X\n"
lit_3ffe1c74 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe03bc             # 4000c96c "ZonePeakingPercent = \t%04X\n"
lit_3ffe1c78 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe03d8             # 4000c970 "UserGlobalGain = \t%04X\n"
lit_3ffe1c7c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe03f0             # 4000c974 "ApplyGlobalGain = \t%04X\n"
lit_3ffe1c80 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe040c             # 4000c978 "GainFilterMode = \t%04X\n"
lit_3ffe1c84 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f44              # 4000c97c
lit_3ffe1c88 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0424             # 4000c980 "Input Duty:"
lit_3ffe1c8c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0430             # 4000c984 "\n  %02d. "
lit_3ffe1c90 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe043c             # 4000c988 "Merged Segment:"
lit_3ffe1c94 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe044c             # 4000c98c "LED ADIM:"
lit_3ffe1c98 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0458             # 4000c990 "LED PDIM:"
lit_3ffe1c9c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0464             # 4000c994 "Pure Pattern: %d\n"
lit_3ffe1ca0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0478             # 4000c998 "ApplyGlobalGain: 0x%04X\n"
# used by: ldc_follow_mode_and_run_led_driver
lit_3ffe1ca4 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f48              # 4000c99c
lit_3ffe1ca8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f4c              # 4000c9a0
lit_3ffe1cac = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f50              # 4000c9a4
# used by: ldc_run_frame_pass
lit_3ffe1cb0 = . - literals_start + LITERALS_RAM
	.word	ldc_pass_record_init    # 4000c9a8
# used by: ldc_build_command_index, ldc_poll_mailbox_command
lit_3ffe1cb4 = . - literals_start + LITERALS_RAM
	.word	ldc_command_table       # 4000c9ac
lit_3ffe1cb8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f60              # 4000c9b0
# used by: ldc_poll_mailbox_command
lit_3ffe1cbc = . - literals_start + LITERALS_RAM
	.word	0xe0091034              # 4000c9b4
lit_3ffe1cc0 = . - literals_start + LITERALS_RAM
	.word	0xe0091030              # 4000c9b8
lit_3ffe1cc4 = . - literals_start + LITERALS_RAM
	.word	0xaa550001              # 4000c9bc
lit_3ffe1cc8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe04b4             # 4000c9c0 "POWER_UP\r\n"
lit_3ffe1ccc = . - literals_start + LITERALS_RAM
	.word	0x55aa0002              # 4000c9c4
lit_3ffe1cd0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe04c0             # 4000c9c8 "POWER_DOWN\r\n"
lit_3ffe1cd4 = . - literals_start + LITERALS_RAM
	.word	0xe0091020              # 4000c9cc
lit_3ffe1cd8 = . - literals_start + LITERALS_RAM
	.word	0xe0091024              # 4000c9d0
lit_3ffe1cdc = . - literals_start + LITERALS_RAM
	.word	ro_3ffe04d0             # 4000c9d4 "MailBox Cmd: %02X %02X %04X \n"
# used by: dbg_memcmd_echo_char, dbg_memcmd_mr, dbg_memcmd_md, dbg_memcmd_poll_console
lit_3ffe1ce0 = . - literals_start + LITERALS_RAM
	.word	dbg_memcmd_verbose      # 4000c9d8
# used by: dbg_memcmd_mr
lit_3ffe1ce4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0500             # 4000c9dc "%08X:   "
lit_3ffe1ce8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe050c             # 4000c9e0 " %08X"
lit_3ffe1cec = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0514             # 4000c9e4 " %04X"
lit_3ffe1cf0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe051c             # 4000c9e8 " %02X"
lit_3ffe1cf4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0524             # 4000c9ec
# used by: dbg_memcmd_cfg
lit_3ffe1cf8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0528             # 4000c9f0 "val = 0x%08X\n"
# used by: dbg_init_uart_print_banner
lit_3ffe1cfc = . - literals_start + LITERALS_RAM
	.word	dbg_uart_config         # 4000c9f4
lit_3ffe1d00 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0538             # 4000c9f8 "\n-----------------------------------------\n"
lit_3ffe1d04 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0564             # 4000c9fc "Core %s\n"
lit_3ffe1d08 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0570             # 4000ca00 "NVT_Formal_RG20189"
lit_3ffe1d0c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0584             # 4000ca04 "NT68500 FW Version: %d.%d.%d (customer id = %d)\n"
lit_3ffe1d10 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe05b8             # 4000ca08 "Built time: %s %s\n"
lit_3ffe1d14 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe05cc             # 4000ca0c "Nov 10 2025"
lit_3ffe1d18 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe05d8             # 4000ca10 "09:47:58"
lit_3ffe1d1c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe05e4             # 4000ca14 "--------------------------------------------\n"
# used by: dbg_memcmd_poll_console
lit_3ffe1d20 = . - literals_start + LITERALS_RAM
	.word	0x3ffe41c0              # 4000ca18
lit_3ffe1d24 = . - literals_start + LITERALS_RAM
	.word	0x3ffe41d0              # 4000ca1c
lit_3ffe1d28 = . - literals_start + LITERALS_RAM
	.word	dbg_memcmd_table        # 4000ca20
lit_3ffe1d2c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0614             # 4000ca24 "Please enter the command: "
lit_3ffe1d30 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4210              # 4000ca28
# used by: lib_heap_init, lib_heap_alloc, lib_heap_free
lit_3ffe1d34 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4220              # 4000ca2c
# used by: lib_heap_init
lit_3ffe1d38 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4230              # 4000ca30
# used by: lib_swap_byte_order, lib_swap_byte_order_words, lib_swap_byte_order_words_volatile,
#          DRV_LDC_SetPanelResolution, ldc_hw_set_reg280_low_bytes, DRV_LDC_SetLDCSegment
lit_3ffe1d3c = . - literals_start + LITERALS_RAM
	.word	0x0000ff00              # 4000ca34
# used by: dbg_cmd_mem, dbg_cmd_mdw
lit_3ffe1d40 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08a0             # 4000ca38 " : "
# used by: dbg_cmd_mem
lit_3ffe1d44 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08a4             # 4000ca3c "            "
# used by: dbg_cmd_mem, dbg_cmd_mdw
lit_3ffe1d48 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08b4             # 4000ca40
# used by: dbg_cmd_mem
lit_3ffe1d4c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08b8             # 4000ca44
lit_3ffe1d50 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08bc             # 4000ca48
# used by: dbg_cmd_mem, dbg_cmd_mdw, dbg_cmd_wmem, dbg_console_poll
lit_3ffe1d54 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08be             # 4000ca4c
# used by: dbg_cmd_mdw
lit_3ffe1d58 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08c0             # 4000ca50 "         "
# used by: dbg_cmd_wmem
lit_3ffe1d5c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08cc             # 4000ca54 "\n ["
lit_3ffe1d60 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08d0             # 4000ca58 "] : "
lit_3ffe1d64 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08d8             # 4000ca5c "Address Fail\n"
# used by: dbg_find_and_run_command
lit_3ffe1d68 = . - literals_start + LITERALS_RAM
	.word	dbg_command_table       # 4000ca60 "mem"
# used by: dbg_find_and_run_command, dbg_run_text_command
lit_3ffe1d6c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08e8             # 4000ca64
# used by: dbg_run_text_command, dbg_run_star_request, dbg_parse_star_request, dbg_console_poll,
#          dbg_console_init
lit_3ffe1d70 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4240              # 4000ca68
# used by: dbg_run_text_command, dbg_console_init
lit_3ffe1d74 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4270              # 4000ca6c
# used by: dbg_run_text_command
lit_3ffe1d78 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08ec             # 4000ca70 " OK.\n\r"
lit_3ffe1d7c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe08f4             # 4000ca74 "\n\rCommand Not Found!\n\r"
lit_3ffe1d80 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe090c             # 4000ca78 "TDBG >>"
# used by: dbg_run_hex_packet, dbg_console_poll
lit_3ffe1d84 = . - literals_start + LITERALS_RAM
	.word	0x3ffe42f0              # 4000ca7c
# used by: dbg_run_hex_packet
lit_3ffe1d88 = . - literals_start + LITERALS_RAM
	.word	0x3ffe43f0              # 4000ca80
lit_3ffe1d8c = . - literals_start + LITERALS_RAM
	.word	0x3ffe43f9              # 4000ca84
lit_3ffe1d90 = . - literals_start + LITERALS_RAM
	.word	0x3ffe43fa              # 4000ca88
lit_3ffe1d94 = . - literals_start + LITERALS_RAM
	.word	0x3ffe43f1              # 4000ca8c
lit_3ffe1d98 = . - literals_start + LITERALS_RAM
	.word	0x3ffe43f2              # 4000ca90
# used by: dbg_run_star_request
lit_3ffe1d9c = . - literals_start + LITERALS_RAM
	.word	0x3ffe4411              # 4000ca94
lit_3ffe1da0 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4410              # 4000ca98
lit_3ffe1da4 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4419              # 4000ca9c
lit_3ffe1da8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe441a              # 4000caa0
lit_3ffe1dac = . - literals_start + LITERALS_RAM
	.word	0x3ffe441b              # 4000caa4
lit_3ffe1db0 = . - literals_start + LITERALS_RAM
	.word	0x3ffe441c              # 4000caa8
lit_3ffe1db4 = . - literals_start + LITERALS_RAM
	.word	0x3ffe441d              # 4000caac
lit_3ffe1db8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe441e              # 4000cab0
lit_3ffe1dbc = . - literals_start + LITERALS_RAM
	.word	0x3ffe441f              # 4000cab4
lit_3ffe1dc0 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4420              # 4000cab8
lit_3ffe1dc4 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4412              # 4000cabc
lit_3ffe1dc8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4413              # 4000cac0
lit_3ffe1dcc = . - literals_start + LITERALS_RAM
	.word	0x3ffe4414              # 4000cac4
lit_3ffe1dd0 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4415              # 4000cac8
lit_3ffe1dd4 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4416              # 4000cacc
lit_3ffe1dd8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4424              # 4000cad0
lit_3ffe1ddc = . - literals_start + LITERALS_RAM
	.word	0x3ffe4425              # 4000cad4
lit_3ffe1de0 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4426              # 4000cad8
lit_3ffe1de4 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4427              # 4000cadc
lit_3ffe1de8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4417              # 4000cae0
lit_3ffe1dec = . - literals_start + LITERALS_RAM
	.word	0x3ffe4418              # 4000cae4
# used by: dbg_parse_star_request, ldc_unit_set_mode_bits
lit_3ffe1df0 = . - literals_start + LITERALS_RAM
	.word	0x00001000              # 4000cae8
# used by: dbg_console_poll
lit_3ffe1df4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0914             # 4000caec
lit_3ffe1df8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0918             # 4000caf0 "\n\rDBG >>"
lit_3ffe1dfc = . - literals_start + LITERALS_RAM
	.word	ro_3ffe07a0             # 4000caf4 "*CB00000"
lit_3ffe1e00 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe07b0             # 4000caf8 "{#UTIL#}"
# used by: dbg_console_init
lit_3ffe1e04 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0924             # 4000cafc "\n---------------------------------------------"
lit_3ffe1e08 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0954             # 4000cb00 "\n    Welcome to User's Command Line Debug"
lit_3ffe1e0c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0980             # 4000cb04 "\n---------------------------------------------\n"
# used by: dbg_print_sw_value
lit_3ffe1e10 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe09b0             # 4000cb08 "NT68500 Tensilica S/W : "
lit_3ffe1e14 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe09cc             # 4000cb0c
# used by: dbg_cmd_help
lit_3ffe1e18 = . - literals_start + LITERALS_RAM
	.word	dbg_help_texts          # 4000cb10
lit_3ffe1e1c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe09d0             # 4000cb14 "\n%s"
# used by: dbg_cmd_rsa
lit_3ffe1e20 = . - literals_start + LITERALS_RAM
	.word	0xb70910fc              # 4000cb18
lit_3ffe1e24 = . - literals_start + LITERALS_RAM
	.word	0x68500def              # 4000cb1c
# used by: dbg_cmd_gpio_test
lit_3ffe1e28 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe09d4             # 4000cb20 "GPIOtest done!!"
# used by: timer_toggle_expstate_bit9
lit_3ffe1e2c = . - literals_start + LITERALS_RAM
	.word	data_3ffe2758           # 4000cb24
lit_3ffe1e30 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4430              # 4000cb28
# used by: timer_toggle_expstate_bit19
lit_3ffe1e34 = . - literals_start + LITERALS_RAM
	.word	data_3ffe275c           # 4000cb2c
lit_3ffe1e38 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4434              # 4000cb30
# used by: timer_start_expstate_toggle
lit_3ffe1e3c = . - literals_start + LITERALS_RAM
	.word	timer_toggle_expstate_bit9 # 4000cb34
# used by: uart_selftest
lit_3ffe1e40 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe09e4             # 4000cb38 "*** UART TX Test Start ***\n"
lit_3ffe1e44 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0a00             # 4000cb3c "*** UART TX Test End ***\n\n"
lit_3ffe1e48 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0a1c             # 4000cb40 "*** UART RX Test Start ***\n"
lit_3ffe1e4c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0a38             # 4000cb44 "Please input a character ('q' to exit):\n"
lit_3ffe1e50 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0a64             # 4000cb48 "User input: \\n\n"
lit_3ffe1e54 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0a74             # 4000cb4c "User input: %c\n"
lit_3ffe1e58 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0a84             # 4000cb50 "*** UART RX Test End ***\n\n"
lit_3ffe1e5c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0aa0             # 4000cb54 "UART test done!\n"
# used by: timer_count_tick_timer0, timer_count_tick_timer1, timer_run_pending_callbacks,
#          timer_start_counted_timer0, timer_start_counted_timer1
lit_3ffe1e60 = . - literals_start + LITERALS_RAM
	.word	0x3ffe4438              # 4000cb58
# used by: timer_start_counted_timer0
lit_3ffe1e64 = . - literals_start + LITERALS_RAM
	.word	timer_count_tick_timer0 # 4000cb5c
# used by: timer_start_counted_timer1
lit_3ffe1e68 = . - literals_start + LITERALS_RAM
	.word	timer_count_tick_timer1 # 4000cb60
# used by: ldc_hw_apply_ldc_mode
lit_3ffe1e6c = . - literals_start + LITERALS_RAM
	.word	0xe0080310              # 4000cb64
lit_3ffe1e70 = . - literals_start + LITERALS_RAM
	.word	0xe0080400              # 4000cb68
# used by: ldc_hw_apply_ldc_mode, DRV_LDC_SetLDCSegment, ldc_hw_set_reg00c_bit7, ldc_hw_write_result_table
lit_3ffe1e74 = . - literals_start + LITERALS_RAM
	.word	0xe008000c              # 4000cb6c
# used by: ldc_hw_apply_ldc_mode
lit_3ffe1e78 = . - literals_start + LITERALS_RAM
	.word	0xe0080514              # 4000cb70
lit_3ffe1e7c = . - literals_start + LITERALS_RAM
	.word	0xfffefffe              # 4000cb74
lit_3ffe1e80 = . - literals_start + LITERALS_RAM
	.word	0x00010001              # 4000cb78
# used by: ldc_hw_load_default_registers
lit_3ffe1e84 = . - literals_start + LITERALS_RAM
	.word	ldc_hw_default_registers # 4000cb7c
# used by: ldc_hw_set_zone_area_factors
lit_3ffe1e88 = . - literals_start + LITERALS_RAM
	.word	0x00000a00              # 4000cb80
lit_3ffe1e8c = . - literals_start + LITERALS_RAM
	.word	0xe0080134              # 4000cb84
lit_3ffe1e90 = . - literals_start + LITERALS_RAM
	.word	0xe0080138              # 4000cb88
lit_3ffe1e94 = . - literals_start + LITERALS_RAM
	.word	0xe008013c              # 4000cb8c
lit_3ffe1e98 = . - literals_start + LITERALS_RAM
	.word	0xe0080140              # 4000cb90
# used by: DRV_LDC_SetPanelResolution
lit_3ffe1e9c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0ab4             # 4000cb94 "DRV_LDC_SetPanelResolution,%u,%u\r\n"
lit_3ffe1ea0 = . - literals_start + LITERALS_RAM
	.word	0xe0080004              # 4000cb98
# used by: DRV_LDC_SetPanelResolution, ldc_set_zone_count_exponents, DRV_LDC_SetLDCSegment
lit_3ffe1ea4 = . - literals_start + LITERALS_RAM
	.word	0x00ff0000              # 4000cb9c
lit_3ffe1ea8 = . - literals_start + LITERALS_RAM
	.word	0xff000000              # 4000cba0
# used by: ldc_hw_set_reg280_low_bytes, DRV_LDC_SetLDCSegment
lit_3ffe1eac = . - literals_start + LITERALS_RAM
	.word	0xe0080280              # 4000cba4
# used by: DRV_LDC_UpdateSegmentBoundary
lit_3ffe1eb0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0ad8             # 4000cba8 "DRV_LDC_UpdateSegmentBoundary\r\n"
lit_3ffe1eb4 = . - literals_start + LITERALS_RAM
	.word	0x1fff0000              # 4000cbac
lit_3ffe1eb8 = . - literals_start + LITERALS_RAM
	.word	0x00001fff              # 4000cbb0
lit_3ffe1ebc = . - literals_start + LITERALS_RAM
	.word	0xe0080900              # 4000cbb4
lit_3ffe1ec0 = . - literals_start + LITERALS_RAM
	.word	0xe0080800              # 4000cbb8
lit_3ffe1ec4 = . - literals_start + LITERALS_RAM
	.word	0xe0080980              # 4000cbbc
lit_3ffe1ec8 = . - literals_start + LITERALS_RAM
	.word	0x1fff1fff              # 4000cbc0
lit_3ffe1ecc = . - literals_start + LITERALS_RAM
	.word	0xe0080880              # 4000cbc4
lit_3ffe1ed0 = . - literals_start + LITERALS_RAM
	.word	0x0fff0000              # 4000cbc8
lit_3ffe1ed4 = . - literals_start + LITERALS_RAM
	.word	0xe0080940              # 4000cbcc
lit_3ffe1ed8 = . - literals_start + LITERALS_RAM
	.word	0xe0080680              # 4000cbd0
lit_3ffe1edc = . - literals_start + LITERALS_RAM
	.word	0x0fff0fff              # 4000cbd4
# used by: DRV_LDC_SetLDCSegment
lit_3ffe1ee0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0af8             # 4000cbd8 "DRV_LDC_SetLDCSegment\r\n"
# used by: DRV_LDC_SetDSRegisters
lit_3ffe1ee4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0b10             # 4000cbdc "DRV_LDC_SetDSRegisters\r\n"
lit_3ffe1ee8 = . - literals_start + LITERALS_RAM
	.word	0xe0080040              # 4000cbe0
# used by: DRV_LDC_SetDSRegisters, ldc_hw_set_reg290_high_half
lit_3ffe1eec = . - literals_start + LITERALS_RAM
	.word	0xffff0000              # 4000cbe4
# used by: ldc_hw_set_reg168_fields
lit_3ffe1ef0 = . - literals_start + LITERALS_RAM
	.word	0xe0080168              # 4000cbe8
lit_3ffe1ef4 = . - literals_start + LITERALS_RAM
	.word	0x00ffffff              # 4000cbec
# used by: ldc_hw_write_reg160
lit_3ffe1ef8 = . - literals_start + LITERALS_RAM
	.word	0xe0080160              # 4000cbf0
# used by: ldc_hw_set_reg5a4_bit2, ldc_test_dump_grid_values
lit_3ffe1efc = . - literals_start + LITERALS_RAM
	.word	0xe00805a4              # 4000cbf4
# used by: ldc_hw_apply_gain_filter_mode
lit_3ffe1f00 = . - literals_start + LITERALS_RAM
	.word	0xe0080388              # 4000cbf8
# used by: ldc_read_segment_values
lit_3ffe1f04 = . - literals_start + LITERALS_RAM
	.word	0xe0083000              # 4000cbfc
# used by: ldc_hw_set_reg28c_bits4_6
lit_3ffe1f08 = . - literals_start + LITERALS_RAM
	.word	0xe008028c              # 4000cc00
# used by: ldc_hw_set_reg290_high_half
lit_3ffe1f0c = . - literals_start + LITERALS_RAM
	.word	0xe0080290              # 4000cc04
# used by: ldc_hw_init
lit_3ffe1f10 = . - literals_start + LITERALS_RAM
	.word	0x08802000              # 4000cc08
# used by: DRV_LDC_Intensity_Gain_Update
lit_3ffe1f14 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0b2c             # 4000cc0c "DRV_LDC_Intensity_Gain_Update\n"
lit_3ffe1f18 = . - literals_start + LITERALS_RAM
	.word	0xe0080c00              # 4000cc10
lit_3ffe1f1c = . - literals_start + LITERALS_RAM
	.word	0xe0080ffc              # 4000cc14
# used by: ldc_hw_write_global_gain_0x400, ldc_hw_write_global_gain, ldc_hw_set_global_gain_by_maximum
lit_3ffe1f20 = . - literals_start + LITERALS_RAM
	.word	0xe0080378              # 4000cc18
# used by: ldc_hw_write_global_gain_0x400, ldc_hw_set_global_gain_by_maximum
lit_3ffe1f24 = . - literals_start + LITERALS_RAM
	.word	0x04000000              # 4000cc1c
# used by: ldc_hw_write_result_table
lit_3ffe1f28 = . - literals_start + LITERALS_RAM
	.word	0xe0082000              # 4000cc20
# used by: ldc_hw_set_global_gain_by_maximum
lit_3ffe1f2c = . - literals_start + LITERALS_RAM
	.word	0x06800000              # 4000cc24
lit_3ffe1f30 = . - literals_start + LITERALS_RAM
	.word	0xff4cccd8              # 4000cc28
lit_3ffe1f34 = . - literals_start + LITERALS_RAM
	.word	0x0000a3d7              # 4000cc2c
# used by: ldc_test_dump_grid_values
lit_3ffe1f38 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0b4c             # 4000cc30 "LDC test function\r\n"
lit_3ffe1f3c = . - literals_start + LITERALS_RAM
	.word	0xe00805a0              # 4000cc34
lit_3ffe1f40 = . - literals_start + LITERALS_RAM
	.word	0xe00805d4              # 4000cc38
lit_3ffe1f44 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0b60             # 4000cc3c "i = %d, %lX, %lX, %lX, %lX, %lX, %lX, %lX, %lX, %lX\r\n"
# used by: ldc_units_copy_words_and_start
lit_3ffe1f48 = . - literals_start + LITERALS_RAM
	.word	0xc01a0004              # 4000cc40
# used by: ldc_units_copy_words_and_start, ldc_units_init
lit_3ffe1f4c = . - literals_start + LITERALS_RAM
	.word	0xc01a0000              # 4000cc44
# used by: ldc_units_copy_words_and_start
lit_3ffe1f50 = . - literals_start + LITERALS_RAM
	.word	0x84000000              # 4000cc48
# used by: ldc_units_copy_words_and_start, ldc_units_init
lit_3ffe1f54 = . - literals_start + LITERALS_RAM
	.word	0xc0197040              # 4000cc4c
# used by: ldc_units_copy_words_and_start
lit_3ffe1f58 = . - literals_start + LITERALS_RAM
	.word	0xc019700c              # 4000cc50
# used by: ldc_units_copy_words_and_start, ldc_units_init
lit_3ffe1f5c = . - literals_start + LITERALS_RAM
	.word	0xc0198040              # 4000cc54
# used by: ldc_units_copy_words_and_start
lit_3ffe1f60 = . - literals_start + LITERALS_RAM
	.word	0xc019800c              # 4000cc58
# used by: ldc_units_copy_words_and_start, ldc_units_init
lit_3ffe1f64 = . - literals_start + LITERALS_RAM
	.word	0xc0199040              # 4000cc5c
# used by: ldc_units_copy_words_and_start
lit_3ffe1f68 = . - literals_start + LITERALS_RAM
	.word	0xc019900c              # 4000cc60
# used by: ldc_units_copy_words_and_start, ldc_units_init
lit_3ffe1f6c = . - literals_start + LITERALS_RAM
	.word	0xc019a040              # 4000cc64
# used by: ldc_units_copy_words_and_start
lit_3ffe1f70 = . - literals_start + LITERALS_RAM
	.word	0xc019a00c              # 4000cc68
# used by: ldc_unit_set_mode_bits, ldc_unit_set_length_and_flag, ldc_units_init
lit_3ffe1f74 = . - literals_start + LITERALS_RAM
	.word	0xc0192000              # 4000cc6c
# used by: ldc_unit_set_mode_bits, irq_dispatch_level1, irq_dispatch_level3
lit_3ffe1f78 = . - literals_start + LITERALS_RAM
	.word	0xc0000000              # 4000cc70
# used by: ldc_unit_set_mode_bits, ldc_units_init
lit_3ffe1f7c = . - literals_start + LITERALS_RAM
	.word	0x3ffe5490              # 4000cc74
# used by: ldc_unit_set_mode_bits
lit_3ffe1f80 = . - literals_start + LITERALS_RAM
	.word	0xffffefff              # 4000cc78
# used by: ldc_unit_set_mode_bits, ldc_units_init
lit_3ffe1f84 = . - literals_start + LITERALS_RAM
	.word	0xc0197000              # 4000cc7c
# used by: ldc_unit_set_mode_bits, ldc_unit_set_length_and_flag, ldc_units_init
lit_3ffe1f88 = . - literals_start + LITERALS_RAM
	.word	0xc0192100              # 4000cc80
# used by: ldc_unit_set_mode_bits, ldc_units_init
lit_3ffe1f8c = . - literals_start + LITERALS_RAM
	.word	0xc0198000              # 4000cc84
# used by: ldc_unit_set_mode_bits, ldc_unit_set_length_and_flag, ldc_units_init
lit_3ffe1f90 = . - literals_start + LITERALS_RAM
	.word	0xc0192200              # 4000cc88
# used by: ldc_unit_set_mode_bits, ldc_units_init
lit_3ffe1f94 = . - literals_start + LITERALS_RAM
	.word	0xc0199000              # 4000cc8c
# used by: ldc_unit_set_mode_bits, ldc_unit_set_length_and_flag, ldc_units_init
lit_3ffe1f98 = . - literals_start + LITERALS_RAM
	.word	0xc0192300              # 4000cc90
# used by: ldc_unit_set_mode_bits, ldc_units_init
lit_3ffe1f9c = . - literals_start + LITERALS_RAM
	.word	0xc019a000              # 4000cc94
# used by: ldc_unit_set_length_and_flag
lit_3ffe1fa0 = . - literals_start + LITERALS_RAM
	.word	0x00003ff0              # 4000cc98
# used by: ldc_unit_set_reg38_bit13, ldc_units_init
lit_3ffe1fa4 = . - literals_start + LITERALS_RAM
	.word	0xc0192038              # 4000cc9c
# used by: ldc_unit_set_reg38_bit13, timer_start_tick, irq_dispatch_level5
lit_3ffe1fa8 = . - literals_start + LITERALS_RAM
	.word	0x00002000              # 4000cca0
# used by: ldc_unit_set_reg38_bit13, ldc_units_init
lit_3ffe1fac = . - literals_start + LITERALS_RAM
	.word	0xc0192138              # 4000cca4
lit_3ffe1fb0 = . - literals_start + LITERALS_RAM
	.word	0xc0192238              # 4000cca8
lit_3ffe1fb4 = . - literals_start + LITERALS_RAM
	.word	0xc0192338              # 4000ccac
# used by: ldc_units_init
lit_3ffe1fb8 = . - literals_start + LITERALS_RAM
	.word	0x02000002              # 4000ccb0
lit_3ffe1fbc = . - literals_start + LITERALS_RAM
	.word	0xc019200c              # 4000ccb4
lit_3ffe1fc0 = . - literals_start + LITERALS_RAM
	.word	0xc019203c              # 4000ccb8
lit_3ffe1fc4 = . - literals_start + LITERALS_RAM
	.word	0xc0192030              # 4000ccbc
lit_3ffe1fc8 = . - literals_start + LITERALS_RAM
	.word	0xc019210c              # 4000ccc0
lit_3ffe1fcc = . - literals_start + LITERALS_RAM
	.word	0xc019213c              # 4000ccc4
lit_3ffe1fd0 = . - literals_start + LITERALS_RAM
	.word	0xc0192130              # 4000ccc8
lit_3ffe1fd4 = . - literals_start + LITERALS_RAM
	.word	0xc019220c              # 4000cccc
lit_3ffe1fd8 = . - literals_start + LITERALS_RAM
	.word	0xc019223c              # 4000ccd0
lit_3ffe1fdc = . - literals_start + LITERALS_RAM
	.word	0xc0192230              # 4000ccd4
lit_3ffe1fe0 = . - literals_start + LITERALS_RAM
	.word	0xc019230c              # 4000ccd8
lit_3ffe1fe4 = . - literals_start + LITERALS_RAM
	.word	0xc019233c              # 4000ccdc
lit_3ffe1fe8 = . - literals_start + LITERALS_RAM
	.word	0xc0192330              # 4000cce0
lit_3ffe1fec = . - literals_start + LITERALS_RAM
	.word	0xc0193008              # 4000cce4
lit_3ffe1ff0 = . - literals_start + LITERALS_RAM
	.word	0xc0193010              # 4000cce8
lit_3ffe1ff4 = . - literals_start + LITERALS_RAM
	.word	0xc0193014              # 4000ccec
lit_3ffe1ff8 = . - literals_start + LITERALS_RAM
	.word	0xc0193018              # 4000ccf0
lit_3ffe1ffc = . - literals_start + LITERALS_RAM
	.word	0xc019301c              # 4000ccf4
lit_3ffe2000 = . - literals_start + LITERALS_RAM
	.word	0xc0193020              # 4000ccf8
lit_3ffe2004 = . - literals_start + LITERALS_RAM
	.word	0xc0197080              # 4000ccfc
lit_3ffe2008 = . - literals_start + LITERALS_RAM
	.word	0xc0197084              # 4000cd00
lit_3ffe200c = . - literals_start + LITERALS_RAM
	.word	0xc0197088              # 4000cd04
lit_3ffe2010 = . - literals_start + LITERALS_RAM
	.word	0xc019708c              # 4000cd08
lit_3ffe2014 = . - literals_start + LITERALS_RAM
	.word	0x00010000              # 4000cd0c
lit_3ffe2018 = . - literals_start + LITERALS_RAM
	.word	0xc0198080              # 4000cd10
lit_3ffe201c = . - literals_start + LITERALS_RAM
	.word	0xc01a1000              # 4000cd14
lit_3ffe2020 = . - literals_start + LITERALS_RAM
	.word	0xc0198084              # 4000cd18
lit_3ffe2024 = . - literals_start + LITERALS_RAM
	.word	0xc0198088              # 4000cd1c
lit_3ffe2028 = . - literals_start + LITERALS_RAM
	.word	0xc019808c              # 4000cd20
lit_3ffe202c = . - literals_start + LITERALS_RAM
	.word	0xc0199080              # 4000cd24
lit_3ffe2030 = . - literals_start + LITERALS_RAM
	.word	0xc01a2000              # 4000cd28
lit_3ffe2034 = . - literals_start + LITERALS_RAM
	.word	0xc0199084              # 4000cd2c
lit_3ffe2038 = . - literals_start + LITERALS_RAM
	.word	0xc0199088              # 4000cd30
lit_3ffe203c = . - literals_start + LITERALS_RAM
	.word	0xc019908c              # 4000cd34
lit_3ffe2040 = . - literals_start + LITERALS_RAM
	.word	0xc019a080              # 4000cd38
lit_3ffe2044 = . - literals_start + LITERALS_RAM
	.word	0xc01a3000              # 4000cd3c
lit_3ffe2048 = . - literals_start + LITERALS_RAM
	.word	0xc019a084              # 4000cd40
lit_3ffe204c = . - literals_start + LITERALS_RAM
	.word	0xc019a088              # 4000cd44
lit_3ffe2050 = . - literals_start + LITERALS_RAM
	.word	0xc019a08c              # 4000cd48
lit_3ffe2054 = . - literals_start + LITERALS_RAM
	.word	0x01010013              # 4000cd4c
# used by: ldc_as3824_write_pwm_ht
lit_3ffe2058 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0ba0             # 4000cd50
# used by: ldc_as3824_write_pwm_ht, ldc_as3824_write_bdac, LED_AS3824_Init
lit_3ffe205c = . - literals_start + LITERALS_RAM
	.word	0x3ffe5548              # 4000cd54
# used by: ldc_as3824_write_pwm_ht
lit_3ffe2060 = . - literals_start + LITERALS_RAM
	.word	0x00372000              # 4000cd58
# used by: ldc_as3824_write_pwm_ht, ldc_as3824_write_bdac
lit_3ffe2064 = . - literals_start + LITERALS_RAM
	.word	0x3ffe554c              # 4000cd5c
lit_3ffe2068 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5550              # 4000cd60
lit_3ffe206c = . - literals_start + LITERALS_RAM
	.word	0x3ffe5554              # 4000cd64
lit_3ffe2070 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5558              # 4000cd68
lit_3ffe2074 = . - literals_start + LITERALS_RAM
	.word	0x3ffe555c              # 4000cd6c
lit_3ffe2078 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5560              # 4000cd70
lit_3ffe207c = . - literals_start + LITERALS_RAM
	.word	0x3ffe5564              # 4000cd74
lit_3ffe2080 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5568              # 4000cd78
lit_3ffe2084 = . - literals_start + LITERALS_RAM
	.word	0x3ffe556c              # 4000cd7c
lit_3ffe2088 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5570              # 4000cd80
lit_3ffe208c = . - literals_start + LITERALS_RAM
	.word	0x3ffe5574              # 4000cd84
lit_3ffe2090 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5578              # 4000cd88
lit_3ffe2094 = . - literals_start + LITERALS_RAM
	.word	0x3ffe557c              # 4000cd8c
lit_3ffe2098 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5580              # 4000cd90
lit_3ffe209c = . - literals_start + LITERALS_RAM
	.word	0x3ffe5584              # 4000cd94
# used by: ldc_as3824_write_bdac
lit_3ffe20a0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0bd0             # 4000cd98
lit_3ffe20a4 = . - literals_start + LITERALS_RAM
	.word	0x00701000              # 4000cd9c
# used by: ldc_as3824_send_dev1_reg_bit7
lit_3ffe20a8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0bf0             # 4000cda0
# used by: ldc_as3824_apply_ldc_mode, ldc_as3824_set_dac, LED_AS3824_SetPwmPeriod,
#          ldc_as3824_set_hdr_bit0_and_init, ldc_as3824_set_current_on, ldc_as3824_set_hdr_mode,
#          ldc_as3824_set_pwm_ctrl, ldc_as3824_set_curr_ctrl, ldc_as3824_set_dacref_bit,
#          ldc_as3824_set_options, ldc_as3824_set_direct_pwm_bit, LED_AS3824_Unlock, LED_AS3824_Init,
#          ldc_as3824_update, ldc_as3824_print_state
lit_3ffe20ac = . - literals_start + LITERALS_RAM
	.word	0x3ffe54a0              # 4000cda4
# used by: ldc_as3824_apply_ldc_mode
lit_3ffe20b0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0bf8             # 4000cda8 "AS3824Buf.HdrMode = 0x%02X \n"
# used by: ldc_as3824_set_dac
lit_3ffe20b4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0c18             # 4000cdac
lit_3ffe20b8 = . - literals_start + LITERALS_RAM
	.word	0x000c0280              # 4000cdb0
# used by: LED_AS3824_SetPwmPeriod
lit_3ffe20bc = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0c48             # 4000cdb4
lit_3ffe20c0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0c20             # 4000cdb8 "LED_AS3824_SetPwmPeriod = 0x%X \n"
# used by: ldc_as3824_set_current_on
lit_3ffe20c4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0c50             # 4000cdbc "LED AS3824 Current On: 0x%04X\n"
# used by: ldc_as3824_set_hdr_mode
lit_3ffe20c8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0c70             # 4000cdc0 "LED AS3824 HDR Mode: 0x%04X\n"
# used by: ldc_as3824_set_pwm_ctrl
lit_3ffe20cc = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0c90             # 4000cdc4 "LED AS3824 PWM CTRL: 0x%04X\n"
# used by: ldc_as3824_set_curr_ctrl
lit_3ffe20d0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0cb0             # 4000cdc8 "LED AS3824 CURR CTRL: 0x%04X\n"
# used by: ldc_as3824_set_dacref_bit
lit_3ffe20d4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0cd0             # 4000cdcc "LED AS3824 CURR CTRL(DACref): 0x%04X\n"
# used by: ldc_as3824_set_options
lit_3ffe20d8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0cf8             # 4000cdd0 "LED AS3824 Options: 0x%04X\n"
# used by: ldc_as3824_set_direct_pwm_bit
lit_3ffe20dc = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0d14             # 4000cdd4 "LED AS3824 Direct PWM: 0x%04X\n"
# used by: ldc_as3824_apply_direct_pwm, ldc_as3824_update, ldc_as3824_print_state, ldc_led_driver_type0_update
lit_3ffe20e0 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2d30              # 4000cdd8
# used by: LED_AS3824_Unlock
lit_3ffe20e4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0d34             # 4000cddc "LED_AS3824_Unlock\n"
# used by: LED_AS3824_Init, ldc_as3824_update, ldc_as3824_print_state
lit_3ffe20e8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5500              # 4000cde0
lit_3ffe20ec = . - literals_start + LITERALS_RAM
	.word	0x3ffe54c0              # 4000cde4
# used by: LED_AS3824_Init
lit_3ffe20f0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0d48             # 4000cde8 "LED_AS3824_Init Done!! \n"
# used by: ldc_as3824_update
lit_3ffe20f4 = . - literals_start + LITERALS_RAM
	.word	ldc_as3824_last_led_mode # 4000cdec
# used by: ldc_as3824_update, ldc_as3824_print_state, ldc_level_curve_value, ldc_led_driver_type2_update
lit_3ffe20f8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2d34              # 4000cdf0
# used by: ldc_as3824_update
lit_3ffe20fc = . - literals_start + LITERALS_RAM
	.word	0x3ffe5590              # 4000cdf4
lit_3ffe2100 = . - literals_start + LITERALS_RAM
	.word	data_3ffe23a4           # 4000cdf8
# used by: ldc_as3824_print_state
lit_3ffe2104 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0d64             # 4000cdfc "AS3824Buf.DevAddr = 0x%04X\n"
lit_3ffe2108 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0d80             # 4000ce00 "AS3824Buf.LockUnlock = 0x%04X\n"
lit_3ffe210c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0da0             # 4000ce04 "AS3824Buf.CurrOnOff = 0x%04X\n"
lit_3ffe2110 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0dc0             # 4000ce08 "AS3824Buf.CurrOnNum = 0x%04X\n"
lit_3ffe2114 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0de0             # 4000ce0c "AS3824Buf.CurrCtrl = 0x%04X\n"
lit_3ffe2118 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0e00             # 4000ce10 "AS3824Buf.PWM_Ctrl = 0x%04X\n"
lit_3ffe211c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0e20             # 4000ce14 "AS3824Buf.PWM_Period = 0x%04X\n"
lit_3ffe2120 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0e40             # 4000ce18 "AS3824Buf.DAC = 0x%04X\n"
lit_3ffe2124 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0e58             # 4000ce1c "AS3824Buf.Options = 0x%04X\n"
lit_3ffe2128 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0e74             # 4000ce20 "AS3824Buf.HdrMode = 0x%04X\n"
lit_3ffe212c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0e90             # 4000ce24 "AS3824Buf.BDAC[%02d] = 0x%04X\n"
lit_3ffe2130 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0eb0             # 4000ce28
lit_3ffe2134 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0eb4             # 4000ce2c "AS3824Buf.PWM_HT[%02d] = 0x%04X\n"
lit_3ffe2138 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0ed8             # 4000ce30 "LED_Mode = 0x%04X\n"
lit_3ffe213c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0eec             # 4000ce34 "LDC_Mode = 0x%04X\n"
# used by: ldc_level_curve_value
lit_3ffe2140 = . - literals_start + LITERALS_RAM
	.word	0xe00802fc              # 4000ce38
lit_3ffe2144 = . - literals_start + LITERALS_RAM
	.word	ldc_level_curve         # 4000ce3c
# used by: ldc_level_curve_value, ldc_led_driver_type2_update
lit_3ffe2148 = . - literals_start + LITERALS_RAM
	.word	data_3ffe23ac           # 4000ce40
# used by: ldc_level_curve_value
lit_3ffe214c = . - literals_start + LITERALS_RAM
	.word	0xe0091044              # 4000ce44
# used by: ldc_led_driver_type2_update
lit_3ffe2150 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe0f00             # 4000ce48
lit_3ffe2154 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2d3c              # 4000ce4c
# used by: ldc_led_driver_type0_update, ldc_set_direct_pwm_type0
lit_3ffe2158 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5594              # 4000ce50
# used by: ldc_led_driver_type0_update
lit_3ffe215c = . - literals_start + LITERALS_RAM
	.word	0x3ffe2c28              # 4000ce54
lit_3ffe2160 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2c2c              # 4000ce58
lit_3ffe2164 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2c30              # 4000ce5c
lit_3ffe2168 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2c34              # 4000ce60
lit_3ffe216c = . - literals_start + LITERALS_RAM
	.word	0x3ffe2c38              # 4000ce64
lit_3ffe2170 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2c3c              # 4000ce68
lit_3ffe2174 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2c40              # 4000ce6c
lit_3ffe2178 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3eb8              # 4000ce70
lit_3ffe217c = . - literals_start + LITERALS_RAM
	.word	0x3ffe3eb4              # 4000ce74
lit_3ffe2180 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3eb6              # 4000ce78
lit_3ffe2184 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3eb2              # 4000ce7c
lit_3ffe2188 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3ec0              # 4000ce80
lit_3ffe218c = . - literals_start + LITERALS_RAM
	.word	0x3ffe3ec2              # 4000ce84
lit_3ffe2190 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3ebc              # 4000ce88
lit_3ffe2194 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3ebe              # 4000ce8c
lit_3ffe2198 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3ef6              # 4000ce90
lit_3ffe219c = . - literals_start + LITERALS_RAM
	.word	0x3ffe3ef8              # 4000ce94
lit_3ffe21a0 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3eba              # 4000ce98
lit_3ffe21a4 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f02              # 4000ce9c
lit_3ffe21a8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3ef4              # 4000cea0
lit_3ffe21ac = . - literals_start + LITERALS_RAM
	.word	0x3ffe3ef2              # 4000cea4
lit_3ffe21b0 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3efa              # 4000cea8
lit_3ffe21b4 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3efc              # 4000ceac
lit_3ffe21b8 = . - literals_start + LITERALS_RAM
	.word	0x3ffe3f00              # 4000ceb0
lit_3ffe21bc = . - literals_start + LITERALS_RAM
	.word	0x3ffe3efe              # 4000ceb4
# used by: ldc_set_direct_pwm_type0
lit_3ffe21c0 = . - literals_start + LITERALS_RAM
	.word	0x238007aa              # 4000ceb8
# used by: gpio_switch_mux
lit_3ffe21c4 = . - literals_start + LITERALS_RAM
	.word	0x00001638              # 4000cebc
lit_3ffe21c8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1350             # 4000cec0
lit_3ffe21cc = . - literals_start + LITERALS_RAM
	.word	0x000015c0              # 4000cec4
lit_3ffe21d0 = . - literals_start + LITERALS_RAM
	.word	0x000015dc              # 4000cec8
lit_3ffe21d4 = . - literals_start + LITERALS_RAM
	.word	0x000015d8              # 4000cecc
lit_3ffe21d8 = . - literals_start + LITERALS_RAM
	.word	0x000015e0              # 4000ced0
lit_3ffe21dc = . - literals_start + LITERALS_RAM
	.word	0x000015d4              # 4000ced4
lit_3ffe21e0 = . - literals_start + LITERALS_RAM
	.word	0x000015cc              # 4000ced8
lit_3ffe21e4 = . - literals_start + LITERALS_RAM
	.word	0x000015c8              # 4000cedc
lit_3ffe21e8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1310             # 4000cee0 "[ERR] gpio_switch_mux: gpio index out of range (%bu)\n"
# used by: gpio_set_input
lit_3ffe21ec = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1410             # 4000cee4
lit_3ffe21f0 = . - literals_start + LITERALS_RAM
	.word	0x000014e0              # 4000cee8
lit_3ffe21f4 = . - literals_start + LITERALS_RAM
	.word	0x000014f4              # 4000ceec
# used by: gpio_set_input, sys_write_78_and_set_bit7
lit_3ffe21f8 = . - literals_start + LITERALS_RAM
	.word	0x000014f8              # 4000cef0
# used by: gpio_set_input
lit_3ffe21fc = . - literals_start + LITERALS_RAM
	.word	0x000014f0              # 4000cef4
lit_3ffe2200 = . - literals_start + LITERALS_RAM
	.word	0x000014e8              # 4000cef8
lit_3ffe2204 = . - literals_start + LITERALS_RAM
	.word	0x000014e4              # 4000cefc
lit_3ffe2208 = . - literals_start + LITERALS_RAM
	.word	0x000014fc              # 4000cf00
lit_3ffe220c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe13d0             # 4000cf04 "[ERR] gpio_set_input: gpio index out of range (%bu)\n"
# used by: gpio_output_clear
lit_3ffe2210 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe14d0             # 4000cf08
# used by: gpio_output_clear, gpio_output_set
lit_3ffe2214 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1490             # 4000cf0c "[ERR] gpio_set_output: gpio index out of range (%bu)\n"
# used by: gpio_output_set
lit_3ffe2218 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1550             # 4000cf10
# used by: irq_line_init, uart_init
lit_3ffe221c = . - literals_start + LITERALS_RAM
	.word	0xe00a106c              # 4000cf14
# used by: irq_line_init, irq_line_ack, uart_init, uart_rx_irq_handler
lit_3ffe2220 = . - literals_start + LITERALS_RAM
	.word	0xe00a1070              # 4000cf18
# used by: irq_line_init, uart_init
lit_3ffe2224 = . - literals_start + LITERALS_RAM
	.word	0xe00a1068              # 4000cf1c
# used by: irq_line_config, irq_line_ack
lit_3ffe2228 = . - literals_start + LITERALS_RAM
	.word	0xe00a1008              # 4000cf20
lit_3ffe222c = . - literals_start + LITERALS_RAM
	.word	0xe00a1020              # 4000cf24
lit_3ffe2230 = . - literals_start + LITERALS_RAM
	.word	0xe00a1024              # 4000cf28
# used by: irq_sw_handler, sys_init_and_run_main_loop
lit_3ffe2234 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5edc              # 4000cf2c
# used by: irq_sw_install
lit_3ffe2238 = . - literals_start + LITERALS_RAM
	.word	irq_sw_handler          # 4000cf30
# used by: irq_block_start_and_wait
lit_3ffe223c = . - literals_start + LITERALS_RAM
	.word	0xe00a1004              # 4000cf34
# used by: ldc_irq_handler
lit_3ffe2240 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5ee0              # 4000cf38
lit_3ffe2244 = . - literals_start + LITERALS_RAM
	.word	0xe0080404              # 4000cf3c
lit_3ffe2248 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2d50              # 4000cf40
lit_3ffe224c = . - literals_start + LITERALS_RAM
	.word	0x3ffe2d58              # 4000cf44
lit_3ffe2250 = . - literals_start + LITERALS_RAM
	.word	0x3ffe2d60              # 4000cf48
# used by: ldc_irq_install
lit_3ffe2254 = . - literals_start + LITERALS_RAM
	.word	ldc_irq_handler         # 4000cf4c
# used by: timer_service_timer0, timer_service_timer1, timer_service_tick, timer_arm_timer0,
#          timer_arm_timer1, timer_start_tick, timer_wait_ticks, timer_read_ticks
lit_3ffe2258 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5598              # 4000cf50
# used by: timer_service_tick, timer_start_tick
lit_3ffe225c = . - literals_start + LITERALS_RAM
	.word	0x00006c34              # 4000cf54
# used by: timer_arm_timer0
lit_3ffe2260 = . - literals_start + LITERALS_RAM
	.word	timer_service_timer0    # 4000cf58
# used by: timer_arm_timer1
lit_3ffe2264 = . - literals_start + LITERALS_RAM
	.word	timer_service_timer1    # 4000cf5c
# used by: timer_start_tick
lit_3ffe2268 = . - literals_start + LITERALS_RAM
	.word	timer_service_tick      # 4000cf60
# used by: lib_vsprintf
lit_3ffe226c = . - literals_start + LITERALS_RAM
	.word	0x3ffe55c0              # 4000cf64
lit_3ffe2270 = . - literals_start + LITERALS_RAM
	.word	0x3ffe5690              # 4000cf68
lit_3ffe2274 = . - literals_start + LITERALS_RAM
	.word	0x3ffe59b0              # 4000cf6c
lit_3ffe2278 = . - literals_start + LITERALS_RAM
	.word	0x3ffe55d0              # 4000cf70
lit_3ffe227c = . - literals_start + LITERALS_RAM
	.word	lib_vsprintf_conv_table # 4000cf74
lit_3ffe2280 = . - literals_start + LITERALS_RAM
	.word	lib_decimal_digit_texts # 4000cf78
lit_3ffe2284 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe15f0             # 4000cf7c "0123456789abcdef"
lit_3ffe2288 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1610             # 4000cf80 "0123456789ABCDEF"
# used by: dbg_printf
lit_3ffe228c = . - literals_start + LITERALS_RAM
	.word	0x00000400              # 4000cf84
lit_3ffe2290 = . - literals_start + LITERALS_RAM
	.word	0x00000404              # 4000cf88
lit_3ffe2294 = . - literals_start + LITERALS_RAM
	.word	0x00000408              # 4000cf8c
lit_3ffe2298 = . - literals_start + LITERALS_RAM
	.word	0x0000040c              # 4000cf90
lit_3ffe229c = . - literals_start + LITERALS_RAM
	.word	0x00000410              # 4000cf94
lit_3ffe22a0 = . - literals_start + LITERALS_RAM
	.word	0x00000414              # 4000cf98
lit_3ffe22a4 = . - literals_start + LITERALS_RAM
	.word	0x00000420              # 4000cf9c
# used by: lib_sprintf
lit_3ffe22a8 = . - literals_start + LITERALS_RAM
	.word	0x00000030              # 4000cfa0
lit_3ffe22ac = . - literals_start + LITERALS_RAM
	.word	0x00000010              # 4000cfa4
# used by: uart_print_tx_test_lines
lit_3ffe22b0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe16e0             # 4000cfa8 "Hello world!"
lit_3ffe22b4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe16f0             # 4000cfac "%s\n"
lit_3ffe22b8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe16f4             # 4000cfb0 "printf test\n"
lit_3ffe22bc = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1704             # 4000cfb4 "%p is null pointer\n"
lit_3ffe22c0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1718             # 4000cfb8 "%d = 5\n"
lit_3ffe22c4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1720             # 4000cfbc "%d = - max int\n"
lit_3ffe22c8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1730             # 4000cfc0 "%ld = - max long\n"
lit_3ffe22cc = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1744             # 4000cfc4 "char %c = 'a'\n"
lit_3ffe22d0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1754             # 4000cfc8 "hex %x = ff\n"
lit_3ffe22d4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1764             # 4000cfcc "hex %02x = 00\n"
lit_3ffe22d8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe1774             # 4000cfd0 "int: signed %d = unsigned %u = hex %x\n"
lit_3ffe22dc = . - literals_start + LITERALS_RAM
	.word	ro_3ffe179c             # 4000cfd4 "long: signed %ld = unsigned %lu = hex %lx\n"
lit_3ffe22e0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe17c8             # 4000cfd8 "%d %s(s)%"
lit_3ffe22e4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe17d4             # 4000cfdc "message"
lit_3ffe22e8 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe17dc             # 4000cfe0
lit_3ffe22ec = . - literals_start + LITERALS_RAM
	.word	ro_3ffe17e0             # 4000cfe4 "%d %s(s) with %%\n"
lit_3ffe22f0 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe17f4             # 4000cfe8 "TEST result should be \n"
lit_3ffe22f4 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe180c             # 4000cfec
# used by: uart_set_baud_divisor
lit_3ffe22f8 = . - literals_start + LITERALS_RAM
	.word	0x000f4240              # 4000cff0
# used by: uart_set_baud_divisor, uart_set_line_format
lit_3ffe22fc = . - literals_start + LITERALS_RAM
	.word	0xe00a000c              # 4000cff4
# used by: uart_set_baud_divisor, uart_send_text, uart_putc, uart_try_read_byte, uart_wait_read_byte,
#          uart_rx_irq_handler, uart_putc_timeout, uart_put_hex_word, uart_put_hex_byte
lit_3ffe2300 = . - literals_start + LITERALS_RAM
	.word	0xe00a0000              # 4000cff8
# used by: uart_set_baud_divisor, uart_init
lit_3ffe2304 = . - literals_start + LITERALS_RAM
	.word	0xe00a0004              # 4000cffc
# used by: uart_set_baud_divisor
lit_3ffe2308 = . - literals_start + LITERALS_RAM
	.word	0xe009101c              # 4000d000
# used by: uart_init, uart_rx_irq_handler, uart_rx_ring_get
lit_3ffe230c = . - literals_start + LITERALS_RAM
	.word	0x3ffe5cd0              # 4000d004
# used by: uart_init
lit_3ffe2310 = . - literals_start + LITERALS_RAM
	.word	0xe00a0008              # 4000d008
lit_3ffe2314 = . - literals_start + LITERALS_RAM
	.word	uart_rx_irq_handler     # 4000d00c
# used by: uart_send_text, uart_putc, uart_try_read_byte, uart_wait_read_byte, uart_rx_irq_handler,
#          uart_putc_timeout, uart_put_hex_word, uart_put_hex_byte
lit_3ffe2318 = . - literals_start + LITERALS_RAM
	.word	0xe00a0014              # 4000d010
# used by: uart_rx_irq_handler, uart_rx_ring_get
lit_3ffe231c = . - literals_start + LITERALS_RAM
	.word	0x3ffe5cd4              # 4000d014
# used by: uart_putc_timeout, uart_put_hex_word, uart_put_hex_byte
lit_3ffe2320 = . - literals_start + LITERALS_RAM
	.word	0x000ffffe              # 4000d018
# used by: uart_put_hex_word, uart_put_hex_byte
lit_3ffe2324 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe19b0             # 4000d01c "0123456789ABCDEF\nGot power down command..\n"
# used by: sys_write_78_and_set_bit7, sys_write_78_or_79
lit_3ffe2328 = . - literals_start + LITERALS_RAM
	.word	0x000015ac              # 4000d020
# used by: sys_init_and_run_main_loop
lit_3ffe232c = . - literals_start + LITERALS_RAM
	.word	timer_tick_callback_empty # 4000d024
lit_3ffe2330 = . - literals_start + LITERALS_RAM
	.word	0x11223344              # 4000d028
lit_3ffe2334 = . - literals_start + LITERALS_RAM
	.word	0xe0091000              # 4000d02c
lit_3ffe2338 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe19c0             # 4000d030 "\nGot power down command..\n"
lit_3ffe233c = . - literals_start + LITERALS_RAM
	.word	ro_3ffe19dc             # 4000d034 "Enter to Idle loop"
lit_3ffe2340 = . - literals_start + LITERALS_RAM
	.word	ro_3ffe19f0             # 4000d038 "SW_IRQ!!\n"
# used by: trap_syscall_handler, irq_dispatch_level1, irq_dispatch_level3
lit_3ffe2344 = . - literals_start + LITERALS_RAM
	.word	0x00050023              # 4000d03c
# used by: trap_syscall_handler
lit_3ffe2348 = . - literals_start + LITERALS_RAM
	.word	0x80000007              # 4000d040
# used by: irq_set_handler_and_arg
lit_3ffe234c = . - literals_start + LITERALS_RAM
	.word	irq_level_of_interrupt  # 4000d044
# used by: irq_set_handler_and_arg, irq_dispatch_level3, irq_dispatch_level5
lit_3ffe2350 = . - literals_start + LITERALS_RAM
	.word	irq_handler_table       # 4000d048
# used by: irq_set_handler_and_arg
lit_3ffe2354 = . - literals_start + LITERALS_RAM
	.word	irq_default_handler     # 4000d04c
# used by: irq_enable, irq_disable, irq_dispatch_level1
lit_3ffe2358 = . - literals_start + LITERALS_RAM
	.word	irq_enable_state        # 4000d050
# used by: irq_dispatch_level1
lit_3ffe235c = . - literals_start + LITERALS_RAM
	.word	0x80000000              # 4000d054
lit_3ffe2360 = . - literals_start + LITERALS_RAM
	.word	ldc_level_curve         # 4000d058
lit_3ffe2364 = . - literals_start + LITERALS_RAM
	.word	.L4000abb4              # 4000d05c
# used by: irq_dispatch_level3
lit_3ffe2368 = . - literals_start + LITERALS_RAM
	.word	0x00200e00              # 4000d060
lit_3ffe236c = . - literals_start + LITERALS_RAM
	.word	.L4000a742              # 4000d064
# used by: irq_dispatch_level5
lit_3ffe2370 = . - literals_start + LITERALS_RAM
	.word	0x3ffe62f0              # 4000d068
lit_3ffe2374 = . - literals_start + LITERALS_RAM
	.word	irq_level5_handler_address # 4000d06c
lit_3ffe2378 = . - literals_start + LITERALS_RAM
	.word	0x00050025              # 4000d070
# used by: sys_set_region_attributes
lit_3ffe237c = . - literals_start + LITERALS_RAM
	.word	0x1fffffff              # 4000d074
lit_3ffe2380 = . - literals_start + LITERALS_RAM
	.word	sys_region_attribute_rank # 4000d078
# used by: sys_read_region_attributes, sys_write_region_attributes
lit_3ffe2384 = . - literals_start + LITERALS_RAM
	.word	0xe0000000              # 4000d07c
# used by: sys_write_region_attributes
lit_3ffe2388 = . - literals_start + LITERALS_RAM
	.word	.L4000a9f4              # 4000d080
literals_end:

	.space	4, 0                    # 4 zero bytes, 0x4000d084-0x4000d087
