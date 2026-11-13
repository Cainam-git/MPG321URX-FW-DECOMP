# ldc_cmd_set_value_0x3c  (fn_400015fc): 0x400015fc-0x4000160b (firmware file offset 0x315fc-0x3160b), 7 instructions
# Name basis: descriptive - command table; one store only
# Address stored in the words at: 0x4000d314
# Addresses loaded: ldc_dimming_settings
#
# Command 0x3C: stores the value in word +36 of ldc_dimming_settings (cfg); nothing else.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_value_0x3c, @function
ldc_cmd_set_value_0x3c:                 # fn_400015fc
	entry	a1, 48                  # 400015fc
	s32i.n	a2, a1, 0               # 400015ff
	s32i.n	a3, a1, 4               # 40001601
	# cfg[+36] = value
	l32r	a6, lit_3ffe1a98        # 40001603  = ldc_dimming_settings
	l32i.n	a5, a1, 4               # 40001606
	s32i.n	a5, a6, 36              # 40001608
	retw.n                          # 4000160a
	.size	ldc_cmd_set_value_0x3c, . - ldc_cmd_set_value_0x3c
