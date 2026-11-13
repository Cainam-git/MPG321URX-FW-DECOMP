# ldc_cmd_set_value_0x3f  (fn_4000162c): 0x4000162c-0x4000163b (firmware file offset 0x3162c-0x3163b), 7 instructions
# Name basis: descriptive - command table; one store only
# Address stored in the words at: 0x4000d32c
# Addresses loaded: ldc_dimming_settings
#
# Command 0x3F: stores the value in word +48 of ldc_dimming_settings (cfg); nothing else.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_value_0x3f, @function
ldc_cmd_set_value_0x3f:                 # fn_4000162c
	entry	a1, 48                  # 4000162c
	s32i.n	a2, a1, 0               # 4000162f
	s32i.n	a3, a1, 4               # 40001631
	# cfg[+48] = value
	l32r	a6, lit_3ffe1a98        # 40001633  = ldc_dimming_settings
	l32i.n	a5, a1, 4               # 40001636
	s32i.n	a5, a6, 48              # 40001638
	retw.n                          # 4000163a
	.size	ldc_cmd_set_value_0x3f, . - ldc_cmd_set_value_0x3f
