# fn_400041a8: 0x400041a8-0x4000420d (firmware file offset 0x341a8-0x3420d), 44 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0x3ffe4220, 0x3ffe4230

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400041a8, @function
fn_400041a8:
	entry	a1, 64                  # 400041a8
	s32i.n	a2, a1, 16              # 400041ab
	s32i.n	a3, a1, 20              # 400041ad
	l32i.n	a6, a1, 20              # 400041af
	movi.n	a5, 79                  # 400041b1
	bltu	a5, a6, .L400041bd      # 400041b3
	movi.n	a7, 1                   # 400041b6
	s32i.n	a7, a1, 0               # 400041b8
	j	.L4000420a              # 400041ba
.L400041bd:
	movi.n	a9, 0                   # 400041bd
	l32i.n	a8, a1, 16              # 400041bf
	bne	a8, a9, .L400041cb      # 400041c1
	movi.n	a9, 1                   # 400041c4
	s32i.n	a9, a1, 0               # 400041c6
	j	.L4000420a              # 400041c8
.L400041cb:
	l32r	a8, lit_3ffe1d34        # 400041cb  = 0x3ffe4220
	movi.n	a7, 1                   # 400041ce
	s8i	a7, a8, 0               # 400041d0
	l32r	a6, lit_3ffe1d34        # 400041d3  = 0x3ffe4220
	l32r	a5, lit_3ffe1d38        # 400041d6  = 0x3ffe4230
	s32i.n	a5, a6, 4               # 400041d9
	l32r	a4, lit_3ffe1d34        # 400041db  = 0x3ffe4220
	l32i.n	a4, a4, 4               # 400041de
	l32i.n	a3, a1, 16              # 400041e0
	s32i.n	a3, a4, 0               # 400041e2
	l32r	a2, lit_3ffe1d34        # 400041e4  = 0x3ffe4220
	l32i.n	a2, a2, 4               # 400041e7
	l32i.n	a15, a1, 20             # 400041e9
	s32i.n	a15, a2, 4              # 400041eb
	l32r	a14, lit_3ffe1d34       # 400041ed  = 0x3ffe4220
	l32i.n	a14, a14, 4             # 400041f0
	l32i.n	a14, a14, 0             # 400041f2
	movi.n	a13, 0                  # 400041f4
	s32i.n	a13, a14, 0             # 400041f6
	l32r	a12, lit_3ffe1d34       # 400041f8  = 0x3ffe4220
	l32i.n	a12, a12, 4             # 400041fb
	l32i.n	a12, a12, 0             # 400041fd
	l32i.n	a11, a1, 20             # 400041ff
	addi	a11, a11, -8            # 40004201
	s32i.n	a11, a12, 4             # 40004204
	movi.n	a10, 0                  # 40004206
	s32i.n	a10, a1, 0              # 40004208
.L4000420a:
	l32i.n	a2, a1, 0               # 4000420a
	retw.n                          # 4000420c
	.size	fn_400041a8, . - fn_400041a8
