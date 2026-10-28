# fn_40004788: 0x40004788-0x400047c3 (firmware file offset 0x34788-0x347c3), 27 instructions
# Called from: fn_40004dfc, fn_400058dc

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004788, @function
fn_40004788:
	entry	a1, 64                  # 40004788
	s32i.n	a2, a1, 16              # 4000478b
	s32i.n	a3, a1, 20              # 4000478d
.L4000478f:
	l32i.n	a12, a1, 16             # 4000478f
	l8ui	a12, a12, 0             # 40004791
	s32i.n	a12, a1, 0              # 40004794
	l32i.n	a11, a1, 16             # 40004796
	addi.n	a11, a11, 1             # 40004798
	s32i.n	a11, a1, 16             # 4000479a
	l32i.n	a10, a1, 20             # 4000479c
	l8ui	a10, a10, 0             # 4000479e
	s32i.n	a10, a1, 4              # 400047a1
	l32i.n	a9, a1, 20              # 400047a3
	addi.n	a9, a9, 1               # 400047a5
	s32i.n	a9, a1, 20              # 400047a7
	l32i.n	a8, a1, 4               # 400047a9
	l32i.n	a7, a1, 0               # 400047ab
	sub	a7, a7, a8              # 400047ad
	s32i.n	a7, a1, 8               # 400047b0
	movi.n	a6, 0                   # 400047b2
	l32i.n	a5, a1, 8               # 400047b4
	bne	a5, a6, .L400047c0      # 400047b6
	movi.n	a14, 0                  # 400047b9
	l32i.n	a13, a1, 0              # 400047bb
	bne	a13, a14, .L4000478f    # 400047bd
.L400047c0:
	l32i.n	a2, a1, 8               # 400047c0
	retw.n                          # 400047c2
	.size	fn_40004788, . - fn_40004788
