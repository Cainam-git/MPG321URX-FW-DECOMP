# fn_400019f0: 0x400019f0-0x400019f8 (firmware file offset 0x319f0-0x319f8), 4 instructions
# Address stored in the words at: 0x4000d3bc

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400019f0, @function
fn_400019f0:
	entry	a1, 48                  # 400019f0
	s32i.n	a2, a1, 0               # 400019f3
	s32i.n	a3, a1, 4               # 400019f5
	retw.n                          # 400019f7
	.size	fn_400019f0, . - fn_400019f0
