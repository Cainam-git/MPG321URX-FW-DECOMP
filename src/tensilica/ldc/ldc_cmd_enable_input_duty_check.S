# ldc_cmd_enable_input_duty_check  (fn_40001ac8): 0x40001ac8-0x40001b06 (firmware file offset 0x31ac8-0x31b06), 25 instructions
# Name basis: derived - panel +0x154 gates ldc_check_pure_pattern -> ldc_check_input_duty_edges in
#   ldc_run_frame_pass
# Address stored in the words at: 0x4000d3f4
# Calls: ldc_hw_apply_gain_filter_mode
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0x3ffe2bf0
#
# Command 0x97 (sent by ldc_send_input_duty_check and ldc_api_set_zone_grid): sets panel +0x154 to 1 for value 1 and to
# 0 for any other value. While it is 1 the per-frame pass (ldc_run_frame_pass) runs ldc_check_pure_pattern, which calls
# ldc_check_input_duty_edges. Then writes GainFilterMode (cfg +4) to bits 1 and 2 of register 0xE0080388
# through ldc_hw_apply_gain_filter_mode, with bit 2 cleared while panel +0x154 is 1.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_enable_input_duty_check, @function
ldc_cmd_enable_input_duty_check:        # fn_40001ac8
	entry	a1, 48                  # 40001ac8
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 40001acb
	s32i.n	a3, a1, 4               # 40001acd
	# panel.duty_check_on = (value == 1)   (panel +0x154)
	l32r	a7, lit_3ffe1a80        # 40001acf  = 0x3ffe2bf0
	movi.n	a10, 1                  # 40001ad2
	l32i.n	a9, a1, 4               # 40001ad4
	addi.n	a9, a9, -1              # 40001ad6
	movi.n	a8, 1                   # 40001ad8
	movi.n	a6, 0                   # 40001ada
	moveqz	a6, a8, a9              # 40001adc
	s32i	a6, a7, 0x154           # 40001adf
	# if (panel.duty_check_on) ldc_hw_apply_gain_filter_mode(cfg.gain_filter_mode & ~4)
	movi.n	a6, 0                   # 40001ae2
	l32r	a5, lit_3ffe1a80        # 40001ae4  = 0x3ffe2bf0
	l32i	a5, a5, 0x154           # 40001ae7
	beq	a5, a6, .L40001afd      # 40001aea
	movi.n	a11, -5                 # 40001aed
	l32r	a10, lit_3ffe1a98       # 40001aef  = ldc_dimming_settings
	l32i.n	a10, a10, 4             # 40001af2
	and	a10, a10, a11           # 40001af4
	call8	ldc_hw_apply_gain_filter_mode # 40001af7
	j	.L40001b05              # 40001afa
.L40001afd:
	# else ldc_hw_apply_gain_filter_mode(cfg.gain_filter_mode)
	l32r	a10, lit_3ffe1a98       # 40001afd  = ldc_dimming_settings
	l32i.n	a10, a10, 4             # 40001b00
	call8	ldc_hw_apply_gain_filter_mode # 40001b02
.L40001b05:
	retw.n                          # 40001b05
	.size	ldc_cmd_enable_input_duty_check, . - ldc_cmd_enable_input_duty_check
