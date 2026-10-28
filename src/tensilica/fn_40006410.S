# fn_40006410: 0x40006410-0x40006431 (firmware file offset 0x36410-0x36431), 13 instructions
# Called from: fn_40001404
# Calls: fn_40003f38
# Other literal values: 0xe0080280, 0x0000ff00

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006410, @function
fn_40006410:
	entry	a1, 48                  # 40006410
	s32i.n	a2, a1, 0               # 40006413
	s32i.n	a3, a1, 4               # 40006415
	l32r	a10, lit_3ffe1eac       # 40006417  = 0xe0080280
	l32i.n	a11, a1, 4              # 4000641a
	movi	a12, 255                # 4000641c
	call8	fn_40003f38             # 4000641f
	l32r	a10, lit_3ffe1eac       # 40006422  = 0xe0080280
	l32i.n	a11, a1, 0              # 40006425
	slli	a11, a11, 8             # 40006427
	l32r	a12, lit_3ffe1d3c       # 4000642a  = 0x0000ff00
	call8	fn_40003f38             # 4000642d
	retw.n                          # 40006430
	.size	fn_40006410, . - fn_40006410
