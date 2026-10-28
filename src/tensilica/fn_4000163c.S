# fn_4000163c: 0x4000163c-0x4000164b (firmware file offset 0x3163c-0x3164b), 7 instructions
# Address stored in the words at: 0x4000d38c
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000163c, @function
fn_4000163c:
	entry	a1, 48                  # 4000163c
	s32i.n	a2, a1, 0               # 4000163f
	s32i.n	a3, a1, 4               # 40001641
	l32r	a6, lit_3ffe1a98        # 40001643  = data_3ffe2390
	l32i.n	a5, a1, 4               # 40001646
	s32i.n	a5, a6, 52              # 40001648
	retw.n                          # 4000164a
	.size	fn_4000163c, . - fn_4000163c
