# fn_40003f24: 0x40003f24-0x40003f35 (firmware file offset 0x33f24-0x33f35), 8 instructions
# Called from: fn_4000415c, fn_40006904, fn_400069dc, fn_400069f0, fn_40006be8, fn_40006c9c, fn_40006f00

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003f24, @function
fn_40003f24:
	entry	a1, 48                  # 40003f24
	s32i.n	a2, a1, 0               # 40003f27
	s32i.n	a3, a1, 4               # 40003f29
	l32i.n	a6, a1, 0               # 40003f2b
	l32i.n	a5, a1, 4               # 40003f2d
	memw                            # 40003f2f
	s32i.n	a5, a6, 0               # 40003f32
	retw.n                          # 40003f34
	.size	fn_40003f24, . - fn_40003f24
