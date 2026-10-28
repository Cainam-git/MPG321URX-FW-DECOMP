# fn_4000a39c: 0x4000a39c-0x4000a3c3 (firmware file offset 0x3a39c-0x3a3c3), 16 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0x000015ac

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a39c, @function
fn_4000a39c:
	entry	a1, 64                  # 4000a39c
	extui	a2, a2, 0, 8            # 4000a39f
	s8i	a2, a1, 16              # 4000a3a2
	movi.n	a5, 0                   # 4000a3a5
	l8ui	a4, a1, 16              # 4000a3a7
	beq	a4, a5, .L4000a3b4      # 4000a3aa
	movi.n	a5, 79                  # 4000a3ad
	s32i.n	a5, a1, 0               # 4000a3af
	j	.L4000a3b8              # 4000a3b1
.L4000a3b4:
	movi.n	a6, 78                  # 4000a3b4
	s32i.n	a6, a1, 0               # 4000a3b6
.L4000a3b8:
	l32r	a8, lit_3ffe2328        # 4000a3b8  = 0x000015ac
	memw                            # 4000a3bb
	l32i.n	a7, a1, 0               # 4000a3be
	s32i.n	a7, a8, 0               # 4000a3c0
	retw.n                          # 4000a3c2
	.size	fn_4000a39c, . - fn_4000a39c
