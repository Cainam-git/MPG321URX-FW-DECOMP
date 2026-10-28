# fn_40007530: 0x40007530-0x40007569 (firmware file offset 0x37530-0x37569), 23 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40006be8, fn_4000912c
# Addresses loaded: ro_3ffe0bf0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40007530, @function
fn_40007530:
	entry	a1, 64                  # 40007530
	extui	a2, a2, 0, 8            # 40007533
	s8i	a2, a1, 16              # 40007536
	l32r	a5, lit_3ffe20a8        # 40007539  = ro_3ffe0bf0
	l32i.n	a6, a5, 4               # 4000753c
	s32i.n	a6, a1, 4               # 4000753e
	l32i.n	a5, a5, 0               # 40007540
	s32i.n	a5, a1, 0               # 40007542
	mov.n	a5, a1                  # 40007544
	movi	a6, 128                 # 40007546
	l8ui	a4, a1, 16              # 40007549
	or	a4, a4, a6              # 4000754c
	extui	a4, a4, 0, 8            # 4000754f
	slli	a4, a4, 8               # 40007552
	addi	a4, a4, 65              # 40007555
	s32i.n	a4, a5, 0               # 40007558
	movi.n	a10, 2                  # 4000755a
	mov.n	a11, a1                 # 4000755c
	movi.n	a12, 1                  # 4000755e
	call8	fn_40006be8             # 40007560
	movi.n	a10, 2                  # 40007563
	call8	fn_4000912c             # 40007565
	retw.n                          # 40007568
	.size	fn_40007530, . - fn_40007530
