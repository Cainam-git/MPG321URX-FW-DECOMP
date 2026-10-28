# fn_40007820: 0x40007820-0x40007849 (firmware file offset 0x37820-0x37849), 15 instructions
# Called from: fn_400079b8
# Calls: fn_400074b4, fn_400099bc
# Text loaded: "LED AS3824 HDR Mode: 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40007820, @function
fn_40007820:
	entry	a1, 48                  # 40007820
	s32i.n	a2, a1, 0               # 40007823
	l32r	a13, lit_3ffe20ac       # 40007825  = 0x3ffe54a0
	l32i.n	a12, a1, 0              # 40007828
	s32i	a12, a13, 164           # 4000782a
	movi	a10, 103                # 4000782d
	l32r	a11, lit_3ffe20ac       # 40007830  = 0x3ffe54a0
	l32i	a11, a11, 164           # 40007833
	extui	a11, a11, 0, 8          # 40007836
	call8	fn_400074b4             # 40007839
	l32r	a10, lit_3ffe20c8       # 4000783c  = ro_3ffe0c70 "LED AS3824 HDR Mode: 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 4000783f  = 0x3ffe54a0
	l32i	a11, a11, 164           # 40007842
	call8	fn_400099bc             # 40007845
	retw.n                          # 40007848
	.size	fn_40007820, . - fn_40007820
