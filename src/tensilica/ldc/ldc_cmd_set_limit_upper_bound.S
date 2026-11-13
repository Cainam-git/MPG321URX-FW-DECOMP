# ldc_cmd_set_limit_upper_bound  (fn_40001858): 0x40001858-0x4000187f (firmware file offset 0x31858-0x3187f), 15 instructions
# Name basis: proven - cfg +64 printed as 'LimitUpperBound'
# Address stored in the words at: 0x4000d2fc
# Addresses loaded: ldc_dimming_settings
#
# Command 0x37: stores the value as LimitUpperBound (cfg +64), limited to 255.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_limit_upper_bound, @function
ldc_cmd_set_limit_upper_bound:          # fn_40001858
	entry	a1, 48                  # 40001858
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 4000185b
	s32i.n	a3, a1, 4               # 4000185d
	# if (value <= 254)
	l32i.n	a6, a1, 4               # 4000185f
	movi	a5, 254                 # 40001861
	bltu	a5, a6, .L40001875      # 40001864
	# cfg.limit_upper_bound = value & 0xFF
	l32r	a8, lit_3ffe1a98        # 40001867  = ldc_dimming_settings
	l32i.n	a7, a1, 4               # 4000186a
	extui	a7, a7, 0, 8            # 4000186c
	s32i	a7, a8, 64              # 4000186f
	j	.L4000187e              # 40001872
.L40001875:
	# else cfg.limit_upper_bound = 255
	l32r	a9, lit_3ffe1a98        # 40001875  = ldc_dimming_settings
	movi	a8, 255                 # 40001878
	s32i	a8, a9, 64              # 4000187b
.L4000187e:
	retw.n                          # 4000187e
	.size	ldc_cmd_set_limit_upper_bound, . - ldc_cmd_set_limit_upper_bound
