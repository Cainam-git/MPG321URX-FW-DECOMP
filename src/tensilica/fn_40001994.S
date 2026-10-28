# fn_40001994: 0x40001994-0x400019c1 (firmware file offset 0x31994-0x319c1), 18 instructions
# Address stored in the words at: 0x4000d3a4
# Calls: fn_40007958, fn_400082cc
# Other literal values: 0x3ffe2bf0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001994, @function
fn_40001994:
	entry	a1, 48                  # 40001994
	s32i.n	a2, a1, 0               # 40001997
	s32i.n	a3, a1, 4               # 40001999
	l32r	a5, lit_3ffe1a80        # 4000199b  = 0x3ffe2bf0
	l32i.n	a5, a5, 24              # 4000199e
	bnei	a5, 1, .L400019ae       # 400019a0
	l32i.n	a10, a1, 4              # 400019a3
	extui	a10, a10, 0, 8          # 400019a5
	call8	fn_40007958             # 400019a8
	j	.L400019c0              # 400019ab
.L400019ae:
	movi.n	a12, 0                  # 400019ae
	l32r	a11, lit_3ffe1a80       # 400019b0  = 0x3ffe2bf0
	l32i.n	a11, a11, 24            # 400019b3
	bne	a11, a12, .L400019c0    # 400019b5
	l32i.n	a10, a1, 4              # 400019b8
	extui	a10, a10, 0, 8          # 400019ba
	call8	fn_400082cc             # 400019bd
.L400019c0:
	retw.n                          # 400019c0
	.size	fn_40001994, . - fn_40001994
