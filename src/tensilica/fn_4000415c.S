# fn_4000415c: 0x4000415c-0x4000416b (firmware file offset 0x3415c-0x3416b), 7 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40003f24

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000415c, @function
fn_4000415c:
	entry	a1, 48                  # 4000415c
	s32i.n	a2, a1, 0               # 4000415f
	s32i.n	a3, a1, 4               # 40004161
	l32i.n	a10, a1, 0              # 40004163
	l32i.n	a11, a1, 4              # 40004165
	call8	fn_40003f24             # 40004167
	retw.n                          # 4000416a
	.size	fn_4000415c, . - fn_4000415c
