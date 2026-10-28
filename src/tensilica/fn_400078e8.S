# fn_400078e8: 0x400078e8-0x40007910 (firmware file offset 0x378e8-0x37910), 15 instructions
# Called from: fn_40007958, fn_400079b8
# Calls: fn_400074b4, fn_400099bc
# Text loaded: "LED AS3824 Options: 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400078e8, @function
fn_400078e8:
	entry	a1, 48                  # 400078e8
	s32i.n	a2, a1, 0               # 400078eb
	l32r	a13, lit_3ffe20ac       # 400078ed  = 0x3ffe54a0
	l32i.n	a12, a1, 0              # 400078f0
	s32i	a12, a13, 160           # 400078f2
	movi.n	a10, 89                 # 400078f5
	l32r	a11, lit_3ffe20ac       # 400078f7  = 0x3ffe54a0
	l32i	a11, a11, 160           # 400078fa
	extui	a11, a11, 0, 8          # 400078fd
	call8	fn_400074b4             # 40007900
	l32r	a10, lit_3ffe20d8       # 40007903  = ro_3ffe0cf8 "LED AS3824 Options: 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007906  = 0x3ffe54a0
	l32i	a11, a11, 160           # 40007909
	call8	fn_400099bc             # 4000790c
	retw.n                          # 4000790f
	.size	fn_400078e8, . - fn_400078e8
