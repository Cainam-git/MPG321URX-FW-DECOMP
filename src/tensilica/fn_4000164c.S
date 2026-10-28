# fn_4000164c: 0x4000164c-0x4000165b (firmware file offset 0x3164c-0x3165b), 7 instructions
# Address stored in the words at: 0x4000d394
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000164c, @function
fn_4000164c:
	entry	a1, 48                  # 4000164c
	s32i.n	a2, a1, 0               # 4000164f
	s32i.n	a3, a1, 4               # 40001651
	l32r	a6, lit_3ffe1a98        # 40001653  = data_3ffe2390
	l32i.n	a5, a1, 4               # 40001656
	s32i.n	a5, a6, 56              # 40001658
	retw.n                          # 4000165a
	.size	fn_4000164c, . - fn_4000164c
