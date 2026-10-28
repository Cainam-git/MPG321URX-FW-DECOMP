# fn_40005cf8: 0x40005cf8-0x40005d67 (firmware file offset 0x35cf8-0x35d67), 46 instructions
# Address stored in the words at: 0x4000cb34
# Addresses loaded: data_3ffe2758
# Other literal values: 0x3ffe4430
# Special registers: ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005cf8, @function
fn_40005cf8:
	entry	a1, 64                  # 40005cf8
	rsil	a2, 15                  # 40005cfb
	s32i.n	a2, a1, 16              # 40005cfe
	l32i.n	a4, a1, 16              # 40005d00
	s32i.n	a4, a1, 0               # 40005d02
	l32i.n	a3, a1, 0               # 40005d04
	s32i.n	a3, a1, 4               # 40005d06
	l32i.n	a6, a1, 4               # 40005d08
	s32i.n	a6, a1, 8               # 40005d0a
	movi.n	a6, 0                   # 40005d0c
	l32r	a5, lit_3ffe1e2c        # 40005d0e  = data_3ffe2758
	l32i.n	a5, a5, 0               # 40005d11
	beq	a5, a6, .L40005d34      # 40005d13
	l32r	a9, lit_3ffe1e2c        # 40005d16  = data_3ffe2758
	movi.n	a8, 0                   # 40005d19
	s32i.n	a8, a9, 0               # 40005d1b
	rur.expstate	a7              # 40005d1d
	bbci	a7, 19, .L40005d2d      # 40005d20
	l32r	a11, lit_3ffe1e30       # 40005d23  = 0x3ffe4430
	movi.n	a10, 1                  # 40005d26
	s32i.n	a10, a11, 0             # 40005d28
	j	.L40005d34              # 40005d2a
.L40005d2d:
	l32r	a13, lit_3ffe1e30       # 40005d2d  = 0x3ffe4430
	movi.n	a12, 0                  # 40005d30
	s32i.n	a12, a13, 0             # 40005d32
.L40005d34:
	movi.n	a15, 0                  # 40005d34
	l32r	a14, lit_3ffe1e30       # 40005d36  = 0x3ffe4430
	l32i.n	a14, a14, 0             # 40005d39
	beq	a14, a15, .L40005d44    # 40005d3b
	clrb_expstate	9               # 40005d3e
	j	.L40005d47              # 40005d41
.L40005d44:
	setb_expstate	9               # 40005d44
.L40005d47:
	l32r	a2, lit_3ffe1e30        # 40005d47  = 0x3ffe4430
	movi.n	a5, 0                   # 40005d4a
	l32r	a4, lit_3ffe1e30        # 40005d4c  = 0x3ffe4430
	l32i.n	a4, a4, 0               # 40005d4f
	movi.n	a3, 1                   # 40005d51
	movi.n	a15, 0                  # 40005d53
	moveqz	a15, a3, a4             # 40005d55
	s32i.n	a15, a2, 0              # 40005d58
	l32i.n	a7, a1, 8               # 40005d5a
	s32i.n	a7, a1, 12              # 40005d5c
	l32i.n	a6, a1, 12              # 40005d5e
	wsr.ps	a6                      # 40005d60
	rsync                           # 40005d63
	retw.n                          # 40005d66
	.size	fn_40005cf8, . - fn_40005cf8
