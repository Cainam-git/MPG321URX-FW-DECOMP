# fn_400077a4: 0x400077a4-0x400077d1 (firmware file offset 0x377a4-0x377d1), 19 instructions
# Called from: fn_400079b8
# Calls: fn_4000756c, fn_400099bc
# Text loaded: "LED_AS3824_SetPwmPeriod = 0x%X \n"
# Addresses loaded: ro_3ffe0c48
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400077a4, @function
fn_400077a4:
	entry	a1, 64                  # 400077a4
	s32i.n	a2, a1, 16              # 400077a7
	l32r	a13, lit_3ffe20bc       # 400077a9  = ro_3ffe0c48
	l32i.n	a14, a13, 4             # 400077ac
	s32i.n	a14, a1, 4              # 400077ae
	l32i.n	a13, a13, 0             # 400077b0
	s32i.n	a13, a1, 0              # 400077b2
	l32r	a13, lit_3ffe20ac       # 400077b4  = 0x3ffe54a0
	l32i.n	a12, a1, 16             # 400077b7
	s32i.n	a12, a13, 24            # 400077b9
	movi.n	a10, 20                 # 400077bb
	l32r	a11, lit_3ffe20ac       # 400077bd  = 0x3ffe54a0
	l32i.n	a11, a11, 24            # 400077c0
	call8	fn_4000756c             # 400077c2
	l32r	a10, lit_3ffe20c0       # 400077c5  = ro_3ffe0c20 "LED_AS3824_SetPwmPeriod = 0x%X \n"
	l32r	a11, lit_3ffe20ac       # 400077c8  = 0x3ffe54a0
	l32i.n	a11, a11, 24            # 400077cb
	call8	fn_400099bc             # 400077cd
	retw.n                          # 400077d0
	.size	fn_400077a4, . - fn_400077a4
