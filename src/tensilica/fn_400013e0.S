# fn_400013e0: 0x400013e0-0x40001403 (firmware file offset 0x313e0-0x31403), 15 instructions
# Address stored in the words at: 0x4000d2b4
# Calls: fn_400063dc, fn_400061b0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400013e0, @function
fn_400013e0:
	entry	a1, 64                  # 400013e0
	s32i.n	a2, a1, 16              # 400013e3
	s32i.n	a3, a1, 20              # 400013e5
	l32i.n	a6, a1, 20              # 400013e7
	extui	a6, a6, 0, 8            # 400013e9
	s32i.n	a6, a1, 0               # 400013ec
	l32i.n	a5, a1, 20              # 400013ee
	srli	a5, a5, 8               # 400013f0
	extui	a5, a5, 0, 8            # 400013f3
	s32i.n	a5, a1, 4               # 400013f6
	l32i.n	a10, a1, 0              # 400013f8
	l32i.n	a11, a1, 4              # 400013fa
	call8	fn_400063dc             # 400013fc
	call8	fn_400061b0             # 400013ff
	retw.n                          # 40001402
	.size	fn_400013e0, . - fn_400013e0
