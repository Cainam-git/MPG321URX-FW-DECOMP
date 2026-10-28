# fn_40001758: 0x40001758-0x40001768 (firmware file offset 0x31758-0x31768), 7 instructions
# Address stored in the words at: 0x4000d35c
# Calls: fn_4000670c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001758, @function
fn_40001758:
	entry	a1, 48                  # 40001758
	s32i.n	a2, a1, 0               # 4000175b
	s32i.n	a3, a1, 4               # 4000175d
	l32i.n	a10, a1, 4              # 4000175f
	extui	a10, a10, 0, 8          # 40001761
	call8	fn_4000670c             # 40001764
	retw.n                          # 40001767
	.size	fn_40001758, . - fn_40001758
