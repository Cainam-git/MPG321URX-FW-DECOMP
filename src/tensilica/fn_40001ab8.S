# fn_40001ab8: 0x40001ab8-0x40001ac7 (firmware file offset 0x31ab8-0x31ac7), 7 instructions
# Address stored in the words at: 0x4000d3dc
# Calls: fn_40006724

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001ab8, @function
fn_40001ab8:
	entry	a1, 48                  # 40001ab8
	s32i.n	a2, a1, 0               # 40001abb
	s32i.n	a3, a1, 4               # 40001abd
	l32i.n	a10, a1, 4              # 40001abf
	l32i.n	a11, a1, 0              # 40001ac1
	call8	fn_40006724             # 40001ac3
	retw.n                          # 40001ac6
	.size	fn_40001ab8, . - fn_40001ab8
