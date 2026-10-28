# fn_400015e4: 0x400015e4-0x400015fb (firmware file offset 0x315e4-0x315fb), 10 instructions
# Address stored in the words at: 0x4000d39c
# Calls: fn_4000679c
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400015e4, @function
fn_400015e4:
	entry	a1, 48                  # 400015e4
	s32i.n	a2, a1, 0               # 400015e7
	s32i.n	a3, a1, 4               # 400015e9
	l32r	a12, lit_3ffe1a98       # 400015eb  = data_3ffe2390
	l32i.n	a11, a1, 4              # 400015ee
	s32i.n	a11, a12, 4             # 400015f0
	l32r	a10, lit_3ffe1a98       # 400015f2  = data_3ffe2390
	l32i.n	a10, a10, 4             # 400015f5
	call8	fn_4000679c             # 400015f7
	retw.n                          # 400015fa
	.size	fn_400015e4, . - fn_400015e4
