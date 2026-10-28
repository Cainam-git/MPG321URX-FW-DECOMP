# fn_400018f0: 0x400018f0-0x40001904 (firmware file offset 0x318f0-0x31904), 9 instructions
# Address stored in the words at: 0x4000d36c
# Calls: fn_40001894
# Addresses loaded: data_3ffe23e0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400018f0, @function
fn_400018f0:
	entry	a1, 48                  # 400018f0
	s32i.n	a2, a1, 0               # 400018f3
	s32i.n	a3, a1, 4               # 400018f5
	l32r	a10, lit_3ffe1b20       # 400018f7  = data_3ffe23e0
	movi.n	a11, 5                  # 400018fa
	l32i.n	a12, a1, 4              # 400018fc
	l32i.n	a13, a1, 0              # 400018fe
	call8	fn_40001894             # 40001900
	retw.n                          # 40001903
	.size	fn_400018f0, . - fn_400018f0
