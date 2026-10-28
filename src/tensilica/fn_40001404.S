# fn_40001404: 0x40001404-0x40001424 (firmware file offset 0x31404-0x31424), 14 instructions
# Address stored in the words at: 0x4000d3e4
# Calls: fn_40006410

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001404, @function
fn_40001404:
	entry	a1, 64                  # 40001404
	s32i.n	a2, a1, 16              # 40001407
	s32i.n	a3, a1, 20              # 40001409
	l32i.n	a6, a1, 20              # 4000140b
	extui	a6, a6, 0, 8            # 4000140d
	s32i.n	a6, a1, 0               # 40001410
	l32i.n	a5, a1, 20              # 40001412
	srli	a5, a5, 8               # 40001414
	extui	a5, a5, 0, 8            # 40001417
	s32i.n	a5, a1, 4               # 4000141a
	l32i.n	a10, a1, 4              # 4000141c
	l32i.n	a11, a1, 0              # 4000141e
	call8	fn_40006410             # 40001420
	retw.n                          # 40001423
	.size	fn_40001404, . - fn_40001404
