# fn_40001908: 0x40001908-0x4000191c (firmware file offset 0x31908-0x3191c), 9 instructions
# Address stored in the words at: 0x4000d374
# Calls: fn_40001894
# Addresses loaded: data_3ffe2420

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001908, @function
fn_40001908:
	entry	a1, 48                  # 40001908
	s32i.n	a2, a1, 0               # 4000190b
	s32i.n	a3, a1, 4               # 4000190d
	l32r	a10, lit_3ffe1b60       # 4000190f  = data_3ffe2420
	movi.n	a11, 5                  # 40001912
	l32i.n	a12, a1, 4              # 40001914
	l32i.n	a13, a1, 0              # 40001916
	call8	fn_40001894             # 40001918
	retw.n                          # 4000191b
	.size	fn_40001908, . - fn_40001908
