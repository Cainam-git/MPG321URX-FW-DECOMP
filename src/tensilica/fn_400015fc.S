# fn_400015fc: 0x400015fc-0x4000160b (firmware file offset 0x315fc-0x3160b), 7 instructions
# Address stored in the words at: 0x4000d314
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400015fc, @function
fn_400015fc:
	entry	a1, 48                  # 400015fc
	s32i.n	a2, a1, 0               # 400015ff
	s32i.n	a3, a1, 4               # 40001601
	l32r	a6, lit_3ffe1a98        # 40001603  = data_3ffe2390
	l32i.n	a5, a1, 4               # 40001606
	s32i.n	a5, a6, 36              # 40001608
	retw.n                          # 4000160a
	.size	fn_400015fc, . - fn_400015fc
