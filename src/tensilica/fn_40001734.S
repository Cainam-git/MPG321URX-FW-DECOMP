# fn_40001734: 0x40001734-0x40001744 (firmware file offset 0x31734-0x31744), 7 instructions
# Address stored in the words at: 0x4000d344
# Calls: fn_40006854

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001734, @function
fn_40001734:
	entry	a1, 48                  # 40001734
	s32i.n	a2, a1, 0               # 40001737
	s32i.n	a3, a1, 4               # 40001739
	l32i.n	a10, a1, 4              # 4000173b
	extui	a10, a10, 0, 8          # 4000173d
	call8	fn_40006854             # 40001740
	retw.n                          # 40001743
	.size	fn_40001734, . - fn_40001734
