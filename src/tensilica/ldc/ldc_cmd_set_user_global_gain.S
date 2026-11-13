# ldc_cmd_set_user_global_gain  (fn_400015d4): 0x400015d4-0x400015e3 (firmware file offset 0x315d4-0x315e3), 7 instructions
# Name basis: proven - field cfg +32 printed as 'UserGlobalGain'
# Address stored in the words at: 0x4000d384
# Addresses loaded: ldc_dimming_settings
#
# Command 0x5A: stores the value as UserGlobalGain (cfg +32, printed as "UserGlobalGain").
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_user_global_gain, @function
ldc_cmd_set_user_global_gain:           # fn_400015d4
	entry	a1, 48                  # 400015d4
	s32i.n	a2, a1, 0               # 400015d7
	s32i.n	a3, a1, 4               # 400015d9
	# cfg.user_global_gain = value
	l32r	a6, lit_3ffe1a98        # 400015db  = ldc_dimming_settings
	l32i.n	a5, a1, 4               # 400015de
	s32i.n	a5, a6, 32              # 400015e0
	retw.n                          # 400015e2
	.size	ldc_cmd_set_user_global_gain, . - ldc_cmd_set_user_global_gain
