# fn_40007760: 0x40007760-0x400077a3 (firmware file offset 0x37760-0x377a3), 29 instructions
# Called from: fn_400079b8, fn_40007ab8
# Calls: fn_40006be8, fn_4000912c
# Addresses loaded: ro_3ffe0c18
# Other literal values: 0x3ffe54a0, 0x000c0280

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40007760, @function
fn_40007760:
	entry	a1, 64                  # 40007760
	s32i.n	a2, a1, 16              # 40007763
	l32r	a7, lit_3ffe20b4        # 40007765  = ro_3ffe0c18
	l32i.n	a8, a7, 4               # 40007768
	s32i.n	a8, a1, 4               # 4000776a
	l32i.n	a7, a7, 0               # 4000776c
	s32i.n	a7, a1, 0               # 4000776e
	l32r	a7, lit_3ffe20ac        # 40007770  = 0x3ffe54a0
	l32i.n	a6, a1, 16              # 40007773
	s32i.n	a6, a7, 28              # 40007775
	mov.n	a6, a1                  # 40007777
	l32r	a7, lit_3ffe20b8        # 40007779  = 0x000c0280
	l32i.n	a5, a1, 16              # 4000777c
	srli	a5, a5, 2               # 4000777e
	extui	a5, a5, 0, 8            # 40007781
	slli	a5, a5, 24              # 40007784
	add.n	a5, a5, a7              # 40007787
	s32i.n	a5, a6, 0               # 40007789
	addi.n	a5, a1, 4               # 4000778b
	l32i.n	a4, a1, 16              # 4000778d
	extui	a4, a4, 0, 2            # 4000778f
	s32i.n	a4, a5, 0               # 40007792
	movi.n	a10, 2                  # 40007794
	mov.n	a11, a1                 # 40007796
	movi.n	a12, 1                  # 40007798
	call8	fn_40006be8             # 4000779a
	movi.n	a10, 2                  # 4000779d
	call8	fn_4000912c             # 4000779f
	retw.n                          # 400077a2
	.size	fn_40007760, . - fn_40007760
