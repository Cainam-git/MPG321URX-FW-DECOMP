# fn_400015d4: 0x400015d4-0x400015e3 (firmware file offset 0x315d4-0x315e3), 7 instructions
# Address stored in the words at: 0x4000d384
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400015d4, @function
fn_400015d4:
	entry	a1, 48                  # 400015d4
	s32i.n	a2, a1, 0               # 400015d7
	s32i.n	a3, a1, 4               # 400015d9
	l32r	a6, lit_3ffe1a98        # 400015db  = data_3ffe2390
	l32i.n	a5, a1, 4               # 400015de
	s32i.n	a5, a6, 32              # 400015e0
	retw.n                          # 400015e2
	.size	fn_400015d4, . - fn_400015d4
