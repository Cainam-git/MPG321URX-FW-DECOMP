# fn_400013b4: 0x400013b4-0x400013dd (firmware file offset 0x313b4-0x313dd), 17 instructions
# Address stored in the words at: 0x4000d2ac
# Calls: fn_4000660c, fn_400008c0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400013b4, @function
fn_400013b4:
	entry	a1, 64                  # 400013b4
	s32i.n	a2, a1, 16              # 400013b7
	s32i.n	a3, a1, 20              # 400013b9
	l32i.n	a12, a1, 20             # 400013bb
	extui	a12, a12, 0, 8          # 400013bd
	s32i.n	a12, a1, 0              # 400013c0
	l32i.n	a11, a1, 20             # 400013c2
	srli	a11, a11, 8             # 400013c4
	extui	a11, a11, 0, 8          # 400013c7
	s32i.n	a11, a1, 4              # 400013ca
	l32i.n	a10, a1, 0              # 400013cc
	extui	a10, a10, 0, 8          # 400013ce
	l32i.n	a11, a1, 4              # 400013d1
	extui	a11, a11, 0, 8          # 400013d3
	call8	fn_4000660c             # 400013d6
	call8	fn_400008c0             # 400013d9
	retw.n                          # 400013dc
	.size	fn_400013b4, . - fn_400013b4
