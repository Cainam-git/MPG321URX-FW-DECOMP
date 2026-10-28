# fn_40006a58: 0x40006a58-0x40006afa (firmware file offset 0x36a58-0x36afa), 66 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0xe0080378, 0x06800000, 0xff4cccd8, 0x0000a3d7, 0x04000000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006a58, @function
fn_40006a58:
	entry	a1, 80                  # 40006a58
	s32i.n	a2, a1, 32              # 40006a5b
	s32i.n	a3, a1, 36              # 40006a5d
	movi.n	a10, 0                  # 40006a5f
	s32i.n	a10, a1, 0              # 40006a61
	movi.n	a9, 0                   # 40006a63
	s32i.n	a9, a1, 4               # 40006a65
	movi.n	a8, 0                   # 40006a67
	s32i.n	a8, a1, 8               # 40006a69
	movi.n	a7, 0                   # 40006a6b
	s32i.n	a7, a1, 12              # 40006a6d
	l32i.n	a6, a1, 36              # 40006a6f
	l32i.n	a5, a1, 12              # 40006a71
	bgeu	a5, a6, .L40006a9c      # 40006a73
.L40006a76:
	l32i.n	a12, a1, 12             # 40006a76
	l32i.n	a13, a1, 32             # 40006a78
	addx4	a12, a12, a13           # 40006a7a
	l32i.n	a12, a12, 0             # 40006a7d
	l32i.n	a11, a1, 8              # 40006a7f
	bgeu	a11, a12, .L40006a8f    # 40006a81
	l32i.n	a14, a1, 12             # 40006a84
	l32i.n	a15, a1, 32             # 40006a86
	addx4	a14, a14, a15           # 40006a88
	l32i.n	a14, a14, 0             # 40006a8b
	s32i.n	a14, a1, 8              # 40006a8d
.L40006a8f:
	l32i.n	a4, a1, 12              # 40006a8f
	addi.n	a4, a4, 1               # 40006a91
	s32i.n	a4, a1, 12              # 40006a93
	l32i.n	a3, a1, 36              # 40006a95
	l32i.n	a2, a1, 12              # 40006a97
	bltu	a2, a3, .L40006a76      # 40006a99
.L40006a9c:
	l32i.n	a6, a1, 8               # 40006a9c
	movi	a5, 0x117               # 40006a9e
	bltu	a5, a6, .L40006ab2      # 40006aa1
	l32r	a8, lit_3ffe1f20        # 40006aa4  = 0xe0080378
	l32r	a7, lit_3ffe1f2c        # 40006aa7  = 0x06800000
	memw                            # 40006aaa
	s32i.n	a7, a8, 0               # 40006aad
	j	.L40006af9              # 40006aaf
.L40006ab2:
	movi	a11, 0x119              # 40006ab2
	l32i.n	a10, a1, 8              # 40006ab5
	sub	a10, a10, a11           # 40006ab7
	movi	a9, 0x29c               # 40006aba
	bltu	a9, a10, .L40006aee     # 40006abd
	movi	a2, 0x3e8               # 40006ac0
	movi	a3, 0x29e               # 40006ac3
	l32r	a4, lit_3ffe1f30        # 40006ac6  = 0xff4cccd8
	l32r	a5, lit_3ffe1f34        # 40006ac9  = 0x0000a3d7
	l32i.n	a15, a1, 8              # 40006acc
	mull	a15, a15, a5            # 40006ace
	add.n	a15, a15, a4            # 40006ad1
	quou	a15, a15, a3            # 40006ad3
	mull	a15, a15, a2            # 40006ad6
	l32r	a14, lit_3ffe1f2c       # 40006ad9  = 0x06800000
	sub	a14, a14, a15           # 40006adc
	s32i.n	a14, a1, 16             # 40006adf
	l32r	a13, lit_3ffe1f20       # 40006ae1  = 0xe0080378
	l32i.n	a12, a1, 16             # 40006ae4
	memw                            # 40006ae6
	s32i.n	a12, a13, 0             # 40006ae9
	j	.L40006af9              # 40006aeb
.L40006aee:
	l32r	a7, lit_3ffe1f20        # 40006aee  = 0xe0080378
	l32r	a6, lit_3ffe1f24        # 40006af1  = 0x04000000
	memw                            # 40006af4
	s32i.n	a6, a7, 0               # 40006af7
.L40006af9:
	retw.n                          # 40006af9
	.size	fn_40006a58, . - fn_40006a58
