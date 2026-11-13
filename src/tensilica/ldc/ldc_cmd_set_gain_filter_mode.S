# ldc_cmd_set_gain_filter_mode  (fn_400015e4): 0x400015e4-0x400015fb (firmware file offset 0x315e4-0x315fb), 10 instructions
# Name basis: proven - field cfg +4 printed as 'GainFilterMode'
# Address stored in the words at: 0x4000d39c
# Calls: ldc_hw_apply_gain_filter_mode
# Addresses loaded: ldc_dimming_settings
#
# Command 0x5D: stores the value as GainFilterMode (cfg +4, printed as "GainFilterMode") and applies it with
# ldc_hw_apply_gain_filter_mode (bits 1 and 2 of the value set or clear bits 1 and 2 of register 0xE0080388).
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_gain_filter_mode, @function
ldc_cmd_set_gain_filter_mode:           # fn_400015e4
	entry	a1, 48                  # 400015e4
	s32i.n	a2, a1, 0               # 400015e7
	s32i.n	a3, a1, 4               # 400015e9
	# cfg.gain_filter_mode = value
	l32r	a12, lit_3ffe1a98       # 400015eb  = ldc_dimming_settings
	l32i.n	a11, a1, 4              # 400015ee
	s32i.n	a11, a12, 4             # 400015f0
	# ldc_hw_apply_gain_filter_mode(cfg.gain_filter_mode)
	l32r	a10, lit_3ffe1a98       # 400015f2  = ldc_dimming_settings
	l32i.n	a10, a10, 4             # 400015f5
	call8	ldc_hw_apply_gain_filter_mode # 400015f7
	retw.n                          # 400015fa
	.size	ldc_cmd_set_gain_filter_mode, . - ldc_cmd_set_gain_filter_mode
