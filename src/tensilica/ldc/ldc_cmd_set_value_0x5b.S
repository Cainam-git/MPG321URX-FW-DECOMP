# ldc_cmd_set_value_0x5b  (fn_4000163c): 0x4000163c-0x4000164b (firmware file offset 0x3163c-0x3164b), 7 instructions
# Name basis: descriptive - command table; one store only
# Address stored in the words at: 0x4000d38c
# Addresses loaded: ldc_dimming_settings
#
# Command 0x5B: stores the value in word +52 of ldc_dimming_settings (cfg); nothing else.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_value_0x5b, @function
ldc_cmd_set_value_0x5b:                 # fn_4000163c
	entry	a1, 48                  # 4000163c
	s32i.n	a2, a1, 0               # 4000163f
	s32i.n	a3, a1, 4               # 40001641
	# cfg[+52] = value
	l32r	a6, lit_3ffe1a98        # 40001643  = ldc_dimming_settings
	l32i.n	a5, a1, 4               # 40001646
	s32i.n	a5, a6, 52              # 40001648
	retw.n                          # 4000164a
	.size	ldc_cmd_set_value_0x5b, . - ldc_cmd_set_value_0x5b
