# fn_400074ec: 0x400074ec-0x4000752f (firmware file offset 0x374ec-0x3752f), 25 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40006be8, fn_4000912c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400074ec, @function
fn_400074ec:
	entry	a1, 64                  # 400074ec
	extui	a7, a2, 0, 8            # 400074ef
	s8i	a7, a1, 16              # 400074f2
	extui	a5, a3, 0, 8            # 400074f5
	s8i	a5, a1, 20              # 400074f8
	extui	a2, a4, 0, 8            # 400074fb
	s8i	a2, a1, 24              # 400074fe
	l8ui	a10, a1, 24             # 40007501
	slli	a10, a10, 16            # 40007504
	l8ui	a11, a1, 20             # 40007507
	slli	a11, a11, 8             # 4000750a
	movi.n	a12, 64                 # 4000750d
	l8ui	a9, a1, 16              # 4000750f
	or	a9, a9, a12             # 40007512
	extui	a9, a9, 0, 8            # 40007515
	or	a9, a9, a11             # 40007518
	or	a9, a9, a10             # 4000751b
	s32i.n	a9, a1, 0               # 4000751e
	movi.n	a10, 1                  # 40007520
	mov.n	a11, a1                 # 40007522
	movi.n	a12, 1                  # 40007524
	call8	fn_40006be8             # 40007526
	movi.n	a10, 2                  # 40007529
	call8	fn_4000912c             # 4000752b
	retw.n                          # 4000752e
	.size	fn_400074ec, . - fn_400074ec
