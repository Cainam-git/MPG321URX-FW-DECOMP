# fn_40003f38: 0x40003f38-0x40003f70 (firmware file offset 0x33f38-0x33f70), 25 instructions
# Called from: fn_4000416c, fn_40006374, fn_400063dc, fn_40006410, fn_40006434, fn_4000660c, fn_400066d4,
#              fn_40006724, fn_40006854, fn_4000686c, fn_40006c9c, fn_40006de8, fn_40006e94

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003f38, @function
fn_40003f38:
	entry	a1, 64                  # 40003f38
	s32i.n	a2, a1, 16              # 40003f3b
	s32i.n	a3, a1, 20              # 40003f3d
	s32i.n	a4, a1, 24              # 40003f3f
	l32i.n	a14, a1, 24             # 40003f41
	l32i.n	a13, a1, 20             # 40003f43
	and	a13, a13, a14           # 40003f45
	s32i.n	a13, a1, 20             # 40003f48
	l32i.n	a12, a1, 16             # 40003f4a
	memw                            # 40003f4c
	l32i.n	a12, a12, 0             # 40003f4f
	s32i.n	a12, a1, 0              # 40003f51
	movi.n	a12, -1                 # 40003f53
	l32i.n	a11, a1, 24             # 40003f55
	xor	a11, a11, a12           # 40003f57
	l32i.n	a10, a1, 0              # 40003f5a
	and	a10, a10, a11           # 40003f5c
	l32i.n	a9, a1, 20              # 40003f5f
	or	a9, a9, a10             # 40003f61
	s32i.n	a9, a1, 0               # 40003f64
	l32i.n	a8, a1, 16              # 40003f66
	l32i.n	a7, a1, 0               # 40003f68
	memw                            # 40003f6a
	s32i.n	a7, a8, 0               # 40003f6d
	retw.n                          # 40003f6f
	.size	fn_40003f38, . - fn_40003f38
