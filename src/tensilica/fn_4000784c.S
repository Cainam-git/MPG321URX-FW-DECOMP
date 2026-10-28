# fn_4000784c: 0x4000784c-0x40007874 (firmware file offset 0x3784c-0x37874), 16 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_400074b4, fn_400099bc
# Text loaded: "LED AS3824 PWM CTRL: 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000784c, @function
fn_4000784c:
	entry	a1, 48                  # 4000784c
	s32i.n	a2, a1, 0               # 4000784f
	l32r	a13, lit_3ffe20ac       # 40007851  = 0x3ffe54a0
	l32i.n	a12, a1, 0              # 40007854
	extui	a12, a12, 0, 8          # 40007856
	s32i.n	a12, a13, 20            # 40007859
	movi.n	a10, 19                 # 4000785b
	l32r	a11, lit_3ffe20ac       # 4000785d  = 0x3ffe54a0
	l32i.n	a11, a11, 20            # 40007860
	extui	a11, a11, 0, 8          # 40007862
	call8	fn_400074b4             # 40007865
	l32r	a10, lit_3ffe20cc       # 40007868  = ro_3ffe0c90 "LED AS3824 PWM CTRL: 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 4000786b  = 0x3ffe54a0
	l32i.n	a11, a11, 20            # 4000786e
	call8	fn_400099bc             # 40007870
	retw.n                          # 40007873
	.size	fn_4000784c, . - fn_4000784c
