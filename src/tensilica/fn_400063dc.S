# fn_400063dc: 0x400063dc-0x4000640e (firmware file offset 0x363dc-0x3640e), 20 instructions
# Called from: fn_400013e0, fn_400068c0
# Calls: fn_40003f38
# Other literal values: 0x3ffe4450, 0xe0080000, 0x00ff0000, 0xff000000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400063dc, @function
fn_400063dc:
	entry	a1, 48                  # 400063dc
	s32i.n	a2, a1, 0               # 400063df
	s32i.n	a3, a1, 4               # 400063e1
	l32r	a14, lit_3ffe1a84       # 400063e3  = 0x3ffe4450
	l32i.n	a13, a1, 0              # 400063e6
	s32i.n	a13, a14, 24            # 400063e8
	l32r	a13, lit_3ffe1a84       # 400063ea  = 0x3ffe4450
	l32i.n	a12, a1, 4              # 400063ed
	s32i.n	a12, a13, 28            # 400063ef
	l32r	a10, lit_3ffe1b74       # 400063f1  = 0xe0080000
	l32i.n	a11, a1, 0              # 400063f4
	slli	a11, a11, 16            # 400063f6
	l32r	a12, lit_3ffe1ea4       # 400063f9  = 0x00ff0000
	call8	fn_40003f38             # 400063fc
	l32r	a10, lit_3ffe1b74       # 400063ff  = 0xe0080000
	l32i.n	a11, a1, 4              # 40006402
	slli	a11, a11, 24            # 40006404
	l32r	a12, lit_3ffe1ea8       # 40006407  = 0xff000000
	call8	fn_40003f38             # 4000640a
	retw.n                          # 4000640d
	.size	fn_400063dc, . - fn_400063dc
