# fn_4000176c: 0x4000176c-0x4000177c (firmware file offset 0x3176c-0x3177c), 7 instructions
# Address stored in the words at: 0x4000d34c
# Calls: fn_40006884

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000176c, @function
fn_4000176c:
	entry	a1, 48                  # 4000176c
	s32i.n	a2, a1, 0               # 4000176f
	s32i.n	a3, a1, 4               # 40001771
	l32i.n	a10, a1, 4              # 40001773
	extui	a10, a10, 0, 8          # 40001775
	call8	fn_40006884             # 40001778
	retw.n                          # 4000177b
	.size	fn_4000176c, . - fn_4000176c
