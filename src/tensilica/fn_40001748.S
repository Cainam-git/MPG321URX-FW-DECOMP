# fn_40001748: 0x40001748-0x40001755 (firmware file offset 0x31748-0x31755), 6 instructions
# Address stored in the words at: 0x4000d354
# Calls: fn_4000686c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001748, @function
fn_40001748:
	entry	a1, 48                  # 40001748
	s32i.n	a2, a1, 0               # 4000174b
	s32i.n	a3, a1, 4               # 4000174d
	l32i.n	a10, a1, 4              # 4000174f
	call8	fn_4000686c             # 40001751
	retw.n                          # 40001754
	.size	fn_40001748, . - fn_40001748
