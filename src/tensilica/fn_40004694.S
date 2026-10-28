# fn_40004694: 0x40004694-0x400046c6 (firmware file offset 0x34694-0x346c6), 22 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004694, @function
fn_40004694:
	entry	a1, 64                  # 40004694
	s32i.n	a2, a1, 16              # 40004697
	extui	a3, a3, 0, 8            # 40004699
	s8i	a3, a1, 20              # 4000469c
	s32i.n	a4, a1, 24              # 4000469f
	movi.n	a9, 0                   # 400046a1
	s32i.n	a9, a1, 0               # 400046a3
	l32i.n	a8, a1, 24              # 400046a5
	l32i.n	a7, a1, 0               # 400046a7
	bgeu	a7, a8, .L400046c5      # 400046a9
.L400046ac:
	l32i.n	a15, a1, 0              # 400046ac
	l32i.n	a14, a1, 16             # 400046ae
	add.n	a14, a14, a15           # 400046b0
	l8ui	a13, a1, 20             # 400046b2
	s8i	a13, a14, 0             # 400046b5
	l32i.n	a12, a1, 0              # 400046b8
	addi.n	a12, a12, 1             # 400046ba
	s32i.n	a12, a1, 0              # 400046bc
	l32i.n	a11, a1, 24             # 400046be
	l32i.n	a10, a1, 0              # 400046c0
	bltu	a10, a11, .L400046ac    # 400046c2
.L400046c5:
	retw.n                          # 400046c5
	.size	fn_40004694, . - fn_40004694
