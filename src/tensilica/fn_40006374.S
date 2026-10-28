# fn_40006374: 0x40006374-0x400063d8 (firmware file offset 0x36374-0x363d8), 38 instructions
# Called from: fn_40001344, fn_400068c0
# Calls: fn_400099bc, fn_40003f38, fn_400061b0
# Text loaded: "DRV_LDC_SetPanelResolution,%u,%u\r\n"
# Other literal values: 0x3ffe4450, 0xe0080004, 0x0000ff00, 0x00ff0000, 0xff000000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006374, @function
fn_40006374:
	entry	a1, 48                  # 40006374
	s32i.n	a2, a1, 0               # 40006377
	s32i.n	a3, a1, 4               # 40006379
	l32r	a10, lit_3ffe1e9c       # 4000637b  = ro_3ffe0ab4 "DRV_LDC_SetPanelResolution,%u,%u\r\n"
	l32i.n	a11, a1, 0              # 4000637e
	l32i.n	a12, a1, 4              # 40006380
	call8	fn_400099bc             # 40006382
	l32r	a14, lit_3ffe1a84       # 40006385  = 0x3ffe4450
	l32i.n	a13, a1, 0              # 40006388
	s32i.n	a13, a14, 16            # 4000638a
	l32r	a13, lit_3ffe1a84       # 4000638c  = 0x3ffe4450
	l32i.n	a12, a1, 4              # 4000638f
	s32i.n	a12, a13, 20            # 40006391
	l32r	a10, lit_3ffe1ea0       # 40006393  = 0xe0080004
	l32i.n	a11, a1, 0              # 40006396
	extui	a11, a11, 0, 8          # 40006398
	movi	a12, 255                # 4000639b
	call8	fn_40003f38             # 4000639e
	l32r	a10, lit_3ffe1ea0       # 400063a1  = 0xe0080004
	movi	a12, 0xffffff00         # 400063a4
	l32i.n	a11, a1, 0              # 400063a7
	and	a11, a11, a12           # 400063a9
	l32r	a12, lit_3ffe1d3c       # 400063ac  = 0x0000ff00
	call8	fn_40003f38             # 400063af
	l32r	a10, lit_3ffe1ea0       # 400063b2  = 0xe0080004
	l32i.n	a11, a1, 4              # 400063b5
	extui	a11, a11, 0, 8          # 400063b7
	slli	a11, a11, 16            # 400063ba
	l32r	a12, lit_3ffe1ea4       # 400063bd  = 0x00ff0000
	call8	fn_40003f38             # 400063c0
	l32r	a10, lit_3ffe1ea0       # 400063c3  = 0xe0080004
	l32i.n	a11, a1, 4              # 400063c6
	srli	a11, a11, 8             # 400063c8
	slli	a11, a11, 24            # 400063cb
	l32r	a12, lit_3ffe1ea8       # 400063ce  = 0xff000000
	call8	fn_40003f38             # 400063d1
	call8	fn_400061b0             # 400063d4
	retw.n                          # 400063d7
	.size	fn_40006374, . - fn_40006374
