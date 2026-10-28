# fn_4000416c: 0x4000416c-0x4000417f (firmware file offset 0x3416c-0x3417f), 9 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40003f38

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000416c, @function
fn_4000416c:
	entry	a1, 48                  # 4000416c
	s32i.n	a2, a1, 0               # 4000416f
	s32i.n	a3, a1, 4               # 40004171
	s32i.n	a4, a1, 8               # 40004173
	l32i.n	a10, a1, 0              # 40004175
	l32i.n	a11, a1, 4              # 40004177
	l32i.n	a12, a1, 8              # 40004179
	call8	fn_40003f38             # 4000417b
	retw.n                          # 4000417e
	.size	fn_4000416c, . - fn_4000416c
