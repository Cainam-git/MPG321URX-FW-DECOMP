# ldc_cmd_set_value_0x5c  (fn_4000164c): 0x4000164c-0x4000165b (firmware file offset 0x3164c-0x3165b), 7 instructions
# Name basis: descriptive - command table; one store only
# Address stored in the words at: 0x4000d394
# Addresses loaded: ldc_dimming_settings
#
# Command 0x5C: stores the value in word +56 of ldc_dimming_settings (cfg); nothing else.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_value_0x5c, @function
ldc_cmd_set_value_0x5c:                 # fn_4000164c
	entry	a1, 48                  # 4000164c
	s32i.n	a2, a1, 0               # 4000164f
	s32i.n	a3, a1, 4               # 40001651
	# cfg[+56] = value
	l32r	a6, lit_3ffe1a98        # 40001653  = ldc_dimming_settings
	l32i.n	a5, a1, 4               # 40001656
	s32i.n	a5, a6, 56              # 40001658
	retw.n                          # 4000165a
	.size	ldc_cmd_set_value_0x5c, . - ldc_cmd_set_value_0x5c
