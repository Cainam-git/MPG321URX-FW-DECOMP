# fn_40006750: 0x40006750-0x40006760 (firmware file offset 0x36750-0x36760), 7 instructions
# Called from: fn_400068c0
# Other literal values: 0xe0080160

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006750, @function
fn_40006750:
	entry	a1, 48                  # 40006750
	s32i.n	a2, a1, 0               # 40006753
	l32r	a5, lit_3ffe1ef8        # 40006755  = 0xe0080160
	l32i.n	a4, a1, 0               # 40006758
	memw                            # 4000675a
	s32i.n	a4, a5, 0               # 4000675d
	retw.n                          # 4000675f
	.size	fn_40006750, . - fn_40006750
