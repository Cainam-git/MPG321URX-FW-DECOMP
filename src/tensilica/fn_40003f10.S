# fn_40003f10: 0x40003f10-0x40003f21 (firmware file offset 0x33f10-0x33f21), 8 instructions
# Called from: fn_40002e78, fn_4000414c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003f10, @function
fn_40003f10:
	entry	a1, 64                  # 40003f10
	s32i.n	a2, a1, 16              # 40003f13
	l32i.n	a4, a1, 16              # 40003f15
	memw                            # 40003f17
	l32i.n	a4, a4, 0               # 40003f1a
	s32i.n	a4, a1, 0               # 40003f1c
	l32i.n	a2, a1, 0               # 40003f1e
	retw.n                          # 40003f20
	.size	fn_40003f10, . - fn_40003f10
