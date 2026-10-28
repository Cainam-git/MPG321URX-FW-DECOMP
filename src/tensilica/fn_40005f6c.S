# fn_40005f6c: 0x40005f6c-0x40005f8c (firmware file offset 0x35f6c-0x35f8c), 13 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_400090c8
# Addresses loaded: fn_40005e74
# Other literal values: 0x3ffe4438

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005f6c, @function
fn_40005f6c:
	entry	a1, 48                  # 40005f6c
	extui	a6, a2, 0, 8            # 40005f6f
	s8i	a6, a1, 0               # 40005f72
	s32i.n	a3, a1, 4               # 40005f75
	s32i.n	a4, a1, 8               # 40005f77
	l8ui	a10, a1, 0              # 40005f79
	l32i.n	a11, a1, 4              # 40005f7c
	l32r	a12, lit_3ffe1e68       # 40005f7e  = fn_40005e74
	call8	fn_400090c8             # 40005f81
	l32r	a12, lit_3ffe1e60       # 40005f84  = 0x3ffe4438
	l32i.n	a11, a1, 8              # 40005f87
	s32i.n	a11, a12, 12            # 40005f89
	retw.n                          # 40005f8b
	.size	fn_40005f6c, . - fn_40005f6c
