# fn_4000162c: 0x4000162c-0x4000163b (firmware file offset 0x3162c-0x3163b), 7 instructions
# Address stored in the words at: 0x4000d32c
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000162c, @function
fn_4000162c:
	entry	a1, 48                  # 4000162c
	s32i.n	a2, a1, 0               # 4000162f
	s32i.n	a3, a1, 4               # 40001631
	l32r	a6, lit_3ffe1a98        # 40001633  = data_3ffe2390
	l32i.n	a5, a1, 4               # 40001636
	s32i.n	a5, a6, 48              # 40001638
	retw.n                          # 4000163a
	.size	fn_4000162c, . - fn_4000162c
