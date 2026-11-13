# ldc_cmd_set_value_0x3d  (fn_4000160c): 0x4000160c-0x4000161b (firmware file offset 0x3160c-0x3161b), 7 instructions
# Name basis: descriptive - command table; one store only
# Address stored in the words at: 0x4000d31c
# Addresses loaded: ldc_dimming_settings
#
# Command 0x3D: stores the value in word +40 of ldc_dimming_settings (cfg); nothing else.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_value_0x3d, @function
ldc_cmd_set_value_0x3d:                 # fn_4000160c
	entry	a1, 48                  # 4000160c
	s32i.n	a2, a1, 0               # 4000160f
	s32i.n	a3, a1, 4               # 40001611
	# cfg[+40] = value
	l32r	a6, lit_3ffe1a98        # 40001613  = ldc_dimming_settings
	l32i.n	a5, a1, 4               # 40001616
	s32i.n	a5, a6, 40              # 40001618
	retw.n                          # 4000161a
	.size	ldc_cmd_set_value_0x3d, . - ldc_cmd_set_value_0x3d
