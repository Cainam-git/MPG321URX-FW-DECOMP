# fn_4000670c: 0x4000670c-0x40006722 (firmware file offset 0x3670c-0x36722), 9 instructions
# Called from: fn_40001344, fn_40001758, fn_400068c0
# Calls: fn_400066d4
# Other literal values: 0x3ffe4450

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000670c, @function
fn_4000670c:
	entry	a1, 48                  # 4000670c
	s32i.n	a2, a1, 0               # 4000670f
	l32r	a5, lit_3ffe1a84        # 40006711  = 0x3ffe4450
	l32i.n	a4, a1, 0               # 40006714
	sext	a4, a4, 7               # 40006716
	extui	a4, a4, 0, 8            # 40006719
	s32i.n	a4, a5, 48              # 4000671c
	call8	fn_400066d4             # 4000671e
	retw.n                          # 40006721
	.size	fn_4000670c, . - fn_4000670c
