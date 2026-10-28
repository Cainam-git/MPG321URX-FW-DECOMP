# fn_40007878: 0x40007878-0x4000789d (firmware file offset 0x37878-0x3789d), 15 instructions
# Called from: fn_40007958, fn_400079b8
# Calls: fn_400074b4, fn_400099bc
# Text loaded: "LED AS3824 CURR CTRL: 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40007878, @function
fn_40007878:
	entry	a1, 48                  # 40007878
	s32i.n	a2, a1, 0               # 4000787b
	l32r	a13, lit_3ffe20ac       # 4000787d  = 0x3ffe54a0
	l32i.n	a12, a1, 0              # 40007880
	s32i.n	a12, a13, 16            # 40007882
	movi.n	a10, 7                  # 40007884
	l32r	a11, lit_3ffe20ac       # 40007886  = 0x3ffe54a0
	l32i.n	a11, a11, 16            # 40007889
	extui	a11, a11, 0, 8          # 4000788b
	call8	fn_400074b4             # 4000788e
	l32r	a10, lit_3ffe20d0       # 40007891  = ro_3ffe0cb0 "LED AS3824 CURR CTRL: 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007894  = 0x3ffe54a0
	l32i.n	a11, a11, 16            # 40007897
	call8	fn_400099bc             # 40007899
	retw.n                          # 4000789c
	.size	fn_40007878, . - fn_40007878
