# fn_40001aa8: 0x40001aa8-0x40001ab5 (firmware file offset 0x31aa8-0x31ab5), 6 instructions
# Address stored in the words at: 0x4000d3d4
# Calls: fn_40006764

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001aa8, @function
fn_40001aa8:
	entry	a1, 48                  # 40001aa8
	s32i.n	a2, a1, 0               # 40001aab
	s32i.n	a3, a1, 4               # 40001aad
	l32i.n	a10, a1, 4              # 40001aaf
	call8	fn_40006764             # 40001ab1
	retw.n                          # 40001ab4
	.size	fn_40001aa8, . - fn_40001aa8
