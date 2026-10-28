# fn_40005f2c: 0x40005f2c-0x40005f4c (firmware file offset 0x35f2c-0x35f4c), 13 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_4000908c
# Addresses loaded: fn_40005e44
# Other literal values: 0x3ffe4438

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005f2c, @function
fn_40005f2c:
	entry	a1, 48                  # 40005f2c
	extui	a6, a2, 0, 8            # 40005f2f
	s8i	a6, a1, 0               # 40005f32
	s32i.n	a3, a1, 4               # 40005f35
	s32i.n	a4, a1, 8               # 40005f37
	l8ui	a10, a1, 0              # 40005f39
	l32i.n	a11, a1, 4              # 40005f3c
	l32r	a12, lit_3ffe1e64       # 40005f3e  = fn_40005e44
	call8	fn_4000908c             # 40005f41
	l32r	a12, lit_3ffe1e60       # 40005f44  = 0x3ffe4438
	l32i.n	a11, a1, 8              # 40005f47
	s32i.n	a11, a12, 8             # 40005f49
	retw.n                          # 40005f4b
	.size	fn_40005f2c, . - fn_40005f2c
