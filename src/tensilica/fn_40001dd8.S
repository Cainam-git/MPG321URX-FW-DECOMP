# fn_40001dd8: 0x40001dd8-0x40001e52 (firmware file offset 0x31dd8-0x31e52), 53 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0xe0080700, 0xe009106c, 0xe0091068

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001dd8, @function
fn_40001dd8:
	entry	a1, 48                  # 40001dd8
	movi.n	a7, 0                   # 40001ddb
	s32i.n	a7, a1, 0               # 40001ddd
	movi.n	a6, 0                   # 40001ddf
	s32i.n	a6, a1, 4               # 40001de1
	movi.n	a5, 0                   # 40001de3
	s32i.n	a5, a1, 8               # 40001de5
	movi.n	a4, 0                   # 40001de7
	s32i.n	a4, a1, 0               # 40001de9
	l32i.n	a3, a1, 0               # 40001deb
	movi.n	a2, 62                  # 40001ded
	bltu	a2, a3, .L40001e26      # 40001def
.L40001df2:
	l32i.n	a9, a1, 0               # 40001df2
	slli	a9, a9, 2               # 40001df4
	memw                            # 40001df7
	l32r	a10, lit_3ffe1b78       # 40001dfa  = 0xe0080700
	add.n	a9, a9, a10             # 40001dfd
	memw                            # 40001dff
	l32i.n	a9, a9, 0               # 40001e02
	movi.n	a8, 63                  # 40001e04
	bgeu	a8, a9, .L40001e19      # 40001e06
	l32i.n	a12, a1, 8              # 40001e09
	addi.n	a12, a12, 1             # 40001e0b
	s32i.n	a12, a1, 8              # 40001e0d
	l32r	a11, lit_3ffe1b90       # 40001e0f  = 0xe009106c
	l32i.n	a10, a1, 8              # 40001e12
	memw                            # 40001e14
	s32i.n	a10, a11, 0             # 40001e17
.L40001e19:
	l32i.n	a15, a1, 0              # 40001e19
	addi.n	a15, a15, 1             # 40001e1b
	s32i.n	a15, a1, 0              # 40001e1d
	l32i.n	a14, a1, 0              # 40001e1f
	movi.n	a13, 62                 # 40001e21
	bgeu	a13, a14, .L40001df2    # 40001e23
.L40001e26:
	l32i.n	a3, a1, 8               # 40001e26
	movi.n	a2, 8                   # 40001e28
	bltu	a2, a3, .L40001e3e      # 40001e2a
	l32r	a6, lit_3ffe1b94        # 40001e2d  = 0xe0091068
	movi.n	a5, 1                   # 40001e30
	memw                            # 40001e32
	s32i.n	a5, a6, 0               # 40001e35
	movi.n	a4, 1                   # 40001e37
	s32i.n	a4, a1, 12              # 40001e39
	j	.L40001e4f              # 40001e3b
.L40001e3e:
	l32r	a9, lit_3ffe1b94        # 40001e3e  = 0xe0091068
	movi.n	a8, 0                   # 40001e41
	memw                            # 40001e43
	s32i.n	a8, a9, 0               # 40001e46
	movi.n	a7, 0                   # 40001e48
	s32i.n	a7, a1, 12              # 40001e4a
	j	.L40001e4f              # 40001e4c
.L40001e4f:
	l32i.n	a2, a1, 12              # 40001e4f
	retw.n                          # 40001e51
	.size	fn_40001dd8, . - fn_40001dd8
