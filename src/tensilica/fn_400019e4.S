# fn_400019e4: 0x400019e4-0x400019ec (firmware file offset 0x319e4-0x319ec), 4 instructions
# Address stored in the words at: 0x4000d3b4

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400019e4, @function
fn_400019e4:
	entry	a1, 48                  # 400019e4
	s32i.n	a2, a1, 0               # 400019e7
	s32i.n	a3, a1, 4               # 400019e9
	retw.n                          # 400019eb
	.size	fn_400019e4, . - fn_400019e4
