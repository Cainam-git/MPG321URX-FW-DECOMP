# fn_40003f74: 0x40003f74-0x40003f9e (firmware file offset 0x33f74-0x33f9e), 17 instructions
# Called from: fn_40004180

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003f74, @function
fn_40003f74:
	entry	a1, 64                  # 40003f74
	s32i.n	a2, a1, 16              # 40003f77
	movi.n	a7, -4                  # 40003f79
	l32i.n	a6, a1, 16              # 40003f7b
	and	a6, a6, a7              # 40003f7d
	memw                            # 40003f80
	l32i.n	a6, a6, 0               # 40003f83
	s32i.n	a6, a1, 0               # 40003f85
	l32i.n	a5, a1, 16              # 40003f87
	extui	a5, a5, 0, 2            # 40003f89
	l32i.n	a4, a1, 0               # 40003f8c
	slli	a5, a5, 3               # 40003f8e
	ssr	a5                      # 40003f91
	srl	a4, a4                  # 40003f94
	s8i	a4, a1, 4               # 40003f97
	l8ui	a2, a1, 4               # 40003f9a
	retw.n                          # 40003f9d
	.size	fn_40003f74, . - fn_40003f74
