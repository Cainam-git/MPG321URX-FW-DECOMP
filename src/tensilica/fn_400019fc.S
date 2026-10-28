# fn_400019fc: 0x400019fc-0x40001a04 (firmware file offset 0x319fc-0x31a04), 4 instructions
# Address stored in the words at: 0x4000d3c4

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400019fc, @function
fn_400019fc:
	entry	a1, 48                  # 400019fc
	s32i.n	a2, a1, 0               # 400019ff
	s32i.n	a3, a1, 4               # 40001a01
	retw.n                          # 40001a03
	.size	fn_400019fc, . - fn_400019fc
