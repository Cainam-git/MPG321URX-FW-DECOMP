# fn_4000770c: 0x4000770c-0x4000775c (firmware file offset 0x3770c-0x3775c), 29 instructions
# Called from: fn_40007ab8
# Calls: fn_400074b4, fn_400099bc
# Text loaded: "AS3824Buf.HdrMode = 0x%02X \n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000770c, @function
fn_4000770c:
	entry	a1, 48                  # 4000770c
	s32i.n	a2, a1, 0               # 4000770f
	l32i.n	a4, a1, 0               # 40007711
	beqi	a4, 1, .L4000771b       # 40007713
	l32i.n	a5, a1, 0               # 40007716
	bnei	a5, 2, .L4000772f       # 40007718
.L4000771b:
	l32r	a7, lit_3ffe20ac        # 4000771b  = 0x3ffe54a0
	movi.n	a8, 16                  # 4000771e
	l32r	a6, lit_3ffe20ac        # 40007720  = 0x3ffe54a0
	l32i	a6, a6, 164             # 40007723
	or	a6, a6, a8              # 40007726
	s32i	a6, a7, 164             # 40007729
	j	.L40007740              # 4000772c
.L4000772f:
	l32r	a8, lit_3ffe20ac        # 4000772f  = 0x3ffe54a0
	movi.n	a9, -17                 # 40007732
	l32r	a7, lit_3ffe20ac        # 40007734  = 0x3ffe54a0
	l32i	a7, a7, 164             # 40007737
	and	a7, a7, a9              # 4000773a
	s32i	a7, a8, 164             # 4000773d
.L40007740:
	movi	a10, 103                # 40007740
	l32r	a11, lit_3ffe20ac       # 40007743  = 0x3ffe54a0
	l32i	a11, a11, 164           # 40007746
	extui	a11, a11, 0, 8          # 40007749
	call8	fn_400074b4             # 4000774c
	l32r	a10, lit_3ffe20b0       # 4000774f  = ro_3ffe0bf8 "AS3824Buf.HdrMode = 0x%02X \n"
	l32r	a11, lit_3ffe20ac       # 40007752  = 0x3ffe54a0
	l32i	a11, a11, 164           # 40007755
	call8	fn_400099bc             # 40007758
	retw.n                          # 4000775b
	.size	fn_4000770c, . - fn_4000770c
