# fn_400045f4: 0x400045f4-0x40004628 (firmware file offset 0x345f4-0x34628), 24 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400045f4, @function
fn_400045f4:
	entry	a1, 64                  # 400045f4
	s32i.n	a2, a1, 16              # 400045f7
	s32i.n	a3, a1, 20              # 400045f9
	s32i.n	a4, a1, 24              # 400045fb
	movi.n	a9, 0                   # 400045fd
	s32i.n	a9, a1, 0               # 400045ff
	l32i.n	a8, a1, 24              # 40004601
	l32i.n	a7, a1, 0               # 40004603
	bgeu	a7, a8, .L40004627      # 40004605
.L40004608:
	l32i.n	a14, a1, 0              # 40004608
	l32i.n	a15, a1, 16             # 4000460a
	addx4	a14, a14, a15           # 4000460c
	l32i.n	a13, a1, 0              # 4000460f
	l32i.n	a15, a1, 20             # 40004611
	addx4	a13, a13, a15           # 40004613
	l32i.n	a13, a13, 0             # 40004616
	s32i.n	a13, a14, 0             # 40004618
	l32i.n	a12, a1, 0              # 4000461a
	addi.n	a12, a12, 1             # 4000461c
	s32i.n	a12, a1, 0              # 4000461e
	l32i.n	a11, a1, 24             # 40004620
	l32i.n	a10, a1, 0              # 40004622
	bltu	a10, a11, .L40004608    # 40004624
.L40004627:
	retw.n                          # 40004627
	.size	fn_400045f4, . - fn_400045f4
