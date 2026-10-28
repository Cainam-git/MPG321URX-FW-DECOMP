# fn_400075ac: 0x400075ac-0x400075f9 (firmware file offset 0x375ac-0x375f9), 30 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40006be8, fn_4000912c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400075ac, @function
fn_400075ac:
	entry	a1, 64                  # 400075ac
	extui	a6, a2, 0, 8            # 400075af
	s8i	a6, a1, 16              # 400075b2
	extui	a3, a3, 0, 8            # 400075b5
	s8i	a3, a1, 20              # 400075b8
	s32i.n	a4, a1, 24              # 400075bb
	mov.n	a10, a1                 # 400075bd
	movi	a11, 0x200              # 400075bf
	l32i.n	a12, a1, 24             # 400075c2
	extui	a12, a12, 0, 8          # 400075c4
	slli	a12, a12, 24            # 400075c7
	l8ui	a13, a1, 20             # 400075ca
	slli	a13, a13, 16            # 400075cd
	l8ui	a9, a1, 16              # 400075d0
	or	a9, a9, a13             # 400075d3
	or	a9, a9, a12             # 400075d6
	or	a9, a9, a11             # 400075d9
	s32i.n	a9, a10, 0              # 400075dc
	addi.n	a9, a1, 4               # 400075de
	l32i.n	a8, a1, 24              # 400075e0
	srli	a8, a8, 8               # 400075e2
	extui	a8, a8, 0, 8            # 400075e5
	s32i.n	a8, a9, 0               # 400075e8
	movi.n	a10, 2                  # 400075ea
	mov.n	a11, a1                 # 400075ec
	movi.n	a12, 1                  # 400075ee
	call8	fn_40006be8             # 400075f0
	movi.n	a10, 2                  # 400075f3
	call8	fn_4000912c             # 400075f5
	retw.n                          # 400075f8
	.size	fn_400075ac, . - fn_400075ac
