# fn_40007d40: 0x40007d40-0x40007e64 (firmware file offset 0x37d40-0x37e64), 121 instructions
# Called from: fn_40007e68
# Addresses loaded: data_3ffe2a30, data_3ffe23ac
# Other literal values: 0xe00802fc, 0x3ffe2d34, 0xe0091044

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40007d40, @function
fn_40007d40:
	entry	a1, 64                  # 40007d40
	movi.n	a6, 0                   # 40007d43
	s32i.n	a6, a1, 0               # 40007d45
	movi	a6, 0x3ff               # 40007d47
	movi	a7, 100                 # 40007d4a
	l32r	a5, lit_3ffe2140        # 40007d4d  = 0xe00802fc
	memw                            # 40007d50
	l32i.n	a5, a5, 0               # 40007d53
	extui	a5, a5, 16, 16          # 40007d55
	extui	a5, a5, 0, 10           # 40007d58
	mull	a5, a5, a7              # 40007d5b
	quou	a5, a5, a6              # 40007d5e
	s32i.n	a5, a1, 4               # 40007d61
	movi.n	a4, 8                   # 40007d63
	s32i.n	a4, a1, 8               # 40007d65
	l32r	a3, lit_3ffe2144        # 40007d67  = data_3ffe2a30
	l32i.n	a3, a3, 4               # 40007d6a
	s32i.n	a3, a1, 12              # 40007d6c
	movi.n	a3, 0                   # 40007d6e
	l32r	a2, lit_3ffe20f8        # 40007d70  = 0x3ffe2d34
	l32i.n	a2, a2, 0               # 40007d73
	bne	a2, a3, .L40007d98      # 40007d75
	movi	a8, 0x3ff               # 40007d78
	l32i.n	a9, a1, 8               # 40007d7b
	l32r	a10, lit_3ffe2144       # 40007d7d  = data_3ffe2a30
	addx8	a9, a9, a10             # 40007d80
	addi	a9, a9, -8              # 40007d83
	l32i.n	a9, a9, 4               # 40007d86
	l32r	a7, lit_3ffe2148        # 40007d88  = data_3ffe23ac
	l32i.n	a7, a7, 0               # 40007d8b
	mull	a7, a7, a9              # 40007d8d
	quou	a7, a7, a8              # 40007d90
	s32i.n	a7, a1, 12              # 40007d93
	j	.L40007e57              # 40007d95
.L40007d98:
	movi.n	a13, 0                  # 40007d98
	s32i.n	a13, a1, 0              # 40007d9a
	l32i.n	a12, a1, 8              # 40007d9c
	addi.n	a12, a12, -1            # 40007d9e
	l32i.n	a11, a1, 0              # 40007da0
	bgeu	a11, a12, .L40007df9    # 40007da2
.L40007da5:
	l32i.n	a4, a1, 0               # 40007da5
	l32r	a5, lit_3ffe2144        # 40007da7  = data_3ffe2a30
	addx8	a4, a4, a5              # 40007daa
	l32i.n	a4, a4, 0               # 40007dad
	s32i.n	a4, a1, 16              # 40007daf
	l32i.n	a2, a1, 0               # 40007db1
	l32r	a3, lit_3ffe2144        # 40007db3  = data_3ffe2a30
	addx8	a2, a2, a3              # 40007db6
	addi.n	a2, a2, 8               # 40007db9
	l32i.n	a2, a2, 0               # 40007dbb
	s32i.n	a2, a1, 20              # 40007dbd
	l32i.n	a15, a1, 16             # 40007dbf
	l32i.n	a14, a1, 4              # 40007dc1
	bltu	a14, a15, .L40007dea    # 40007dc3
	l32i.n	a7, a1, 4               # 40007dc6
	l32i.n	a6, a1, 20              # 40007dc8
	bltu	a6, a7, .L40007dea      # 40007dca
	l32i.n	a10, a1, 0              # 40007dcd
	l32r	a11, lit_3ffe2144       # 40007dcf  = data_3ffe2a30
	addx8	a10, a10, a11           # 40007dd2
	l32i.n	a10, a10, 4             # 40007dd5
	s32i.n	a10, a1, 24             # 40007dd7
	l32i.n	a8, a1, 0               # 40007dd9
	l32r	a9, lit_3ffe2144        # 40007ddb  = data_3ffe2a30
	addx8	a8, a8, a9              # 40007dde
	addi.n	a8, a8, 8               # 40007de1
	l32i.n	a8, a8, 4               # 40007de3
	s32i.n	a8, a1, 28              # 40007de5
	j	.L40007df9              # 40007de7
.L40007dea:
	l32i.n	a14, a1, 0              # 40007dea
	addi.n	a14, a14, 1             # 40007dec
	s32i.n	a14, a1, 0              # 40007dee
	l32i.n	a13, a1, 8              # 40007df0
	addi.n	a13, a13, -1            # 40007df2
	l32i.n	a12, a1, 0              # 40007df4
	bltu	a12, a13, .L40007da5    # 40007df6
.L40007df9:
	l32i.n	a2, a1, 28              # 40007df9
	l32i.n	a15, a1, 24             # 40007dfb
	bltu	a15, a2, .L40007e24     # 40007dfd
	l32i.n	a6, a1, 16              # 40007e00
	l32i.n	a5, a1, 20              # 40007e02
	sub	a5, a5, a6              # 40007e04
	l32i.n	a7, a1, 28              # 40007e07
	l32i.n	a6, a1, 24              # 40007e09
	sub	a6, a6, a7              # 40007e0b
	l32i.n	a7, a1, 4               # 40007e0e
	l32i.n	a4, a1, 20              # 40007e10
	sub	a4, a4, a7              # 40007e12
	mull	a4, a4, a6              # 40007e15
	quou	a4, a4, a5              # 40007e18
	l32i.n	a3, a1, 28              # 40007e1b
	add.n	a3, a3, a4              # 40007e1d
	s32i.n	a3, a1, 12              # 40007e1f
	j	.L40007e45              # 40007e21
.L40007e24:
	l32i.n	a10, a1, 16             # 40007e24
	l32i.n	a9, a1, 20              # 40007e26
	sub	a9, a9, a10             # 40007e28
	l32i.n	a11, a1, 24             # 40007e2b
	l32i.n	a10, a1, 28             # 40007e2d
	sub	a10, a10, a11           # 40007e2f
	l32i.n	a11, a1, 16             # 40007e32
	l32i.n	a8, a1, 4               # 40007e34
	sub	a8, a8, a11             # 40007e36
	mull	a8, a8, a10             # 40007e39
	quou	a8, a8, a9              # 40007e3c
	l32i.n	a7, a1, 24              # 40007e3f
	add.n	a7, a7, a8              # 40007e41
	s32i.n	a7, a1, 12              # 40007e43
.L40007e45:
	movi	a12, 0x3ff              # 40007e45
	l32i.n	a13, a1, 12             # 40007e48
	l32r	a11, lit_3ffe2148       # 40007e4a  = data_3ffe23ac
	l32i.n	a11, a11, 0             # 40007e4d
	mull	a11, a11, a13           # 40007e4f
	quou	a11, a11, a12           # 40007e52
	s32i.n	a11, a1, 12             # 40007e55
.L40007e57:
	l32r	a13, lit_3ffe214c       # 40007e57  = 0xe0091044
	l32i.n	a12, a1, 12             # 40007e5a
	memw                            # 40007e5c
	s32i.n	a12, a13, 0             # 40007e5f
	l32i.n	a2, a1, 12              # 40007e61
	retw.n                          # 40007e63
	.size	fn_40007d40, . - fn_40007d40
