# fn_4000160c: 0x4000160c-0x4000161b (firmware file offset 0x3160c-0x3161b), 7 instructions
# Address stored in the words at: 0x4000d31c
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000160c, @function
fn_4000160c:
	entry	a1, 48                  # 4000160c
	s32i.n	a2, a1, 0               # 4000160f
	s32i.n	a3, a1, 4               # 40001611
	l32r	a6, lit_3ffe1a98        # 40001613  = data_3ffe2390
	l32i.n	a5, a1, 4               # 40001616
	s32i.n	a5, a6, 40              # 40001618
	retw.n                          # 4000161a
	.size	fn_4000160c, . - fn_4000160c
