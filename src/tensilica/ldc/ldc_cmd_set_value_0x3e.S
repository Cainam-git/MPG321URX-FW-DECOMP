# ldc_cmd_set_value_0x3e  (fn_4000161c): 0x4000161c-0x4000162b (firmware file offset 0x3161c-0x3162b), 7 instructions
# Name basis: descriptive - command table; one store only
# Address stored in the words at: 0x4000d324
# Addresses loaded: ldc_dimming_settings
#
# Command 0x3E: stores the value in word +44 of ldc_dimming_settings (cfg); nothing else.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_value_0x3e, @function
ldc_cmd_set_value_0x3e:                 # fn_4000161c
	entry	a1, 48                  # 4000161c
	s32i.n	a2, a1, 0               # 4000161f
	s32i.n	a3, a1, 4               # 40001621
	# cfg[+44] = value
	l32r	a6, lit_3ffe1a98        # 40001623  = ldc_dimming_settings
	l32i.n	a5, a1, 4               # 40001626
	s32i.n	a5, a6, 44              # 40001628
	retw.n                          # 4000162a
	.size	ldc_cmd_set_value_0x3e, . - ldc_cmd_set_value_0x3e
