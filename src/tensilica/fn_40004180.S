# fn_40004180: 0x40004180-0x4000418d (firmware file offset 0x34180-0x3418d), 6 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40003f74

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004180, @function
fn_40004180:
	entry	a1, 48                  # 40004180
	s32i.n	a2, a1, 0               # 40004183
	l32i.n	a10, a1, 0              # 40004185
	call8	fn_40003f74             # 40004187
	mov.n	a2, a10                 # 4000418a
	retw.n                          # 4000418c
	.size	fn_40004180, . - fn_40004180
