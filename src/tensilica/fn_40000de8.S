# fn_40000de8: 0x40000de8-0x40000e1c (firmware file offset 0x30de8-0x30e1c), 19 instructions
# Called from: fn_40000e20, fn_40001344
# Calls: fn_40008010
# Addresses loaded: fn_40007ab8, fn_40007e68, fn_4000802c
# Other literal values: 0x3ffe2bf0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40000de8, @function
fn_40000de8:
	entry	a1, 48                  # 40000de8
	s32i.n	a2, a1, 0               # 40000deb
	l32i.n	a4, a1, 0               # 40000ded
	bnei	a4, 1, .L40000dfe       # 40000def
	l32r	a6, lit_3ffe1a80        # 40000df2  = 0x3ffe2bf0
	l32r	a5, lit_3ffe1a9c        # 40000df5  = fn_40007ab8
	s32i	a5, a6, 0x13c           # 40000df8
	j	.L40000e1b              # 40000dfb
.L40000dfe:
	l32i.n	a7, a1, 0               # 40000dfe
	bnei	a7, 2, .L40000e12       # 40000e00
	l32r	a9, lit_3ffe1a80        # 40000e03  = 0x3ffe2bf0
	l32r	a8, lit_3ffe1aa0        # 40000e06  = fn_40007e68
	s32i	a8, a9, 0x13c           # 40000e09
	call8	fn_40008010             # 40000e0c
	j	.L40000e1b              # 40000e0f
.L40000e12:
	l32r	a11, lit_3ffe1a80       # 40000e12  = 0x3ffe2bf0
	l32r	a10, lit_3ffe1aa4       # 40000e15  = fn_4000802c
	s32i	a10, a11, 0x13c         # 40000e18
.L40000e1b:
	retw.n                          # 40000e1b
	.size	fn_40000de8, . - fn_40000de8
