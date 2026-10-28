# fn_400082cc: 0x400082cc-0x400082fe (firmware file offset 0x382cc-0x382fe), 22 instructions
# Called from: fn_40001994
# Calls: fn_40006be8
# Other literal values: 0x238007aa, 0x3ffe5594

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400082cc, @function
fn_400082cc:
	entry	a1, 96                  # 400082cc
	s32i.n	a2, a1, 48              # 400082cf
	l32i.n	a4, a1, 48              # 400082d1
	bnei	a4, 1, .L400082f6       # 400082d3
	mov.n	a8, a1                  # 400082d6
	l32r	a7, lit_3ffe21c0        # 400082d8  = 0x238007aa
	s32i.n	a7, a8, 0               # 400082db
	addi.n	a6, a1, 4               # 400082dd
	movi.n	a5, 85                  # 400082df
	s32i.n	a5, a6, 0               # 400082e1
	movi.n	a10, 2                  # 400082e3
	mov.n	a11, a1                 # 400082e5
	movi.n	a12, 1                  # 400082e7
	call8	fn_40006be8             # 400082e9
	l32r	a10, lit_3ffe2158       # 400082ec  = 0x3ffe5594
	movi.n	a9, 1                   # 400082ef
	s32i.n	a9, a10, 0              # 400082f1
	j	.L400082fd              # 400082f3
.L400082f6:
	l32r	a12, lit_3ffe2158       # 400082f6  = 0x3ffe5594
	movi.n	a11, 0                  # 400082f9
	s32i.n	a11, a12, 0             # 400082fb
.L400082fd:
	retw.n                          # 400082fd
	.size	fn_400082cc, . - fn_400082cc
