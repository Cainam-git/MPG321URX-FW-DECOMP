# fn_40001920: 0x40001920-0x40001934 (firmware file offset 0x31920-0x31934), 9 instructions
# Address stored in the words at: 0x4000d37c
# Calls: fn_40001894
# Addresses loaded: data_3ffe2450

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001920, @function
fn_40001920:
	entry	a1, 48                  # 40001920
	s32i.n	a2, a1, 0               # 40001923
	s32i.n	a3, a1, 4               # 40001925
	l32r	a10, lit_3ffe1b64       # 40001927  = data_3ffe2450
	movi.n	a11, 5                  # 4000192a
	l32i.n	a12, a1, 4              # 4000192c
	l32i.n	a13, a1, 0              # 4000192e
	call8	fn_40001894             # 40001930
	retw.n                          # 40001933
	.size	fn_40001920, . - fn_40001920
