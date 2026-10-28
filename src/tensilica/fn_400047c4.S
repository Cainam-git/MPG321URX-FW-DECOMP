# fn_400047c4: 0x400047c4-0x40004802 (firmware file offset 0x347c4-0x34802), 27 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400047c4, @function
fn_400047c4:
	entry	a1, 64                  # 400047c4
	s32i.n	a2, a1, 16              # 400047c7
	s32i.n	a3, a1, 20              # 400047c9
	movi.n	a6, 0                   # 400047cb
	l32i.n	a5, a1, 20              # 400047cd
	bne	a5, a6, .L400047d9      # 400047cf
	l32i.n	a6, a1, 16              # 400047d2
	s32i.n	a6, a1, 0               # 400047d4
	j	.L400047ff              # 400047d6
.L400047d9:
	movi.n	a8, 0                   # 400047d9
	l32i.n	a9, a1, 20              # 400047db
	l32i.n	a7, a1, 16              # 400047dd
	remu	a7, a7, a9              # 400047df
	bne	a7, a8, .L400047f1      # 400047e2
	l32i.n	a11, a1, 20             # 400047e5
	l32i.n	a10, a1, 16             # 400047e7
	quou	a10, a10, a11           # 400047e9
	s32i.n	a10, a1, 0              # 400047ec
	j	.L400047ff              # 400047ee
.L400047f1:
	l32i.n	a13, a1, 20             # 400047f1
	l32i.n	a12, a1, 16             # 400047f3
	quou	a12, a12, a13           # 400047f5
	addi.n	a12, a12, 1             # 400047f8
	s32i.n	a12, a1, 0              # 400047fa
	j	.L400047ff              # 400047fc
.L400047ff:
	l32i.n	a2, a1, 0               # 400047ff
	retw.n                          # 40004801
	.size	fn_400047c4, . - fn_400047c4
