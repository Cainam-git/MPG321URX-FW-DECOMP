# fn_4000414c: 0x4000414c-0x40004159 (firmware file offset 0x3414c-0x34159), 6 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40003f10

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000414c, @function
fn_4000414c:
	entry	a1, 48                  # 4000414c
	s32i.n	a2, a1, 0               # 4000414f
	l32i.n	a10, a1, 0              # 40004151
	call8	fn_40003f10             # 40004153
	mov.n	a2, a10                 # 40004156
	retw.n                          # 40004158
	.size	fn_4000414c, . - fn_4000414c
