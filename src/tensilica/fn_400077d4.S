# fn_400077d4: 0x400077d4-0x400077fb (firmware file offset 0x377d4-0x377fb), 14 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_400074b4, fn_400079b8
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400077d4, @function
fn_400077d4:
	entry	a1, 32                  # 400077d4
	l32r	a13, lit_3ffe20ac       # 400077d7  = 0x3ffe54a0
	movi.n	a14, 1                  # 400077da
	l32r	a12, lit_3ffe20ac       # 400077dc  = 0x3ffe54a0
	l32i	a12, a12, 164           # 400077df
	or	a12, a12, a14           # 400077e2
	s32i	a12, a13, 164           # 400077e5
	movi	a10, 103                # 400077e8
	l32r	a11, lit_3ffe20ac       # 400077eb  = 0x3ffe54a0
	l32i	a11, a11, 164           # 400077ee
	extui	a11, a11, 0, 8          # 400077f1
	call8	fn_400074b4             # 400077f4
	call8	fn_400079b8             # 400077f7
	retw.n                          # 400077fa
	.size	fn_400077d4, . - fn_400077d4
