# fn_400077fc: 0x400077fc-0x4000781e (firmware file offset 0x377fc-0x3781e), 14 instructions
# Called from: fn_40001a08, fn_400079b8
# Calls: fn_4000756c, fn_400099bc
# Text loaded: "LED AS3824 Current On: 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400077fc, @function
fn_400077fc:
	entry	a1, 48                  # 400077fc
	s32i.n	a2, a1, 0               # 400077ff
	l32r	a13, lit_3ffe20ac       # 40007801  = 0x3ffe54a0
	l32i.n	a12, a1, 0              # 40007804
	s32i.n	a12, a13, 8             # 40007806
	movi.n	a10, 1                  # 40007808
	l32r	a11, lit_3ffe20ac       # 4000780a  = 0x3ffe54a0
	l32i.n	a11, a11, 8             # 4000780d
	call8	fn_4000756c             # 4000780f
	l32r	a10, lit_3ffe20c4       # 40007812  = ro_3ffe0c50 "LED AS3824 Current On: 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007815  = 0x3ffe54a0
	l32i.n	a11, a11, 8             # 40007818
	call8	fn_400099bc             # 4000781a
	retw.n                          # 4000781d
	.size	fn_400077fc, . - fn_400077fc
