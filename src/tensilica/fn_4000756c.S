# fn_4000756c: 0x4000756c-0x400075ab (firmware file offset 0x3756c-0x375ab), 26 instructions
# Called from: fn_400077a4, fn_400077fc
# Calls: fn_40006be8, fn_4000912c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000756c, @function
fn_4000756c:
	entry	a1, 64                  # 4000756c
	extui	a4, a2, 0, 8            # 4000756f
	s8i	a4, a1, 16              # 40007572
	s32i.n	a3, a1, 20              # 40007575
	mov.n	a8, a1                  # 40007577
	movi	a9, 0x280               # 40007579
	l32i.n	a10, a1, 20             # 4000757c
	extui	a10, a10, 0, 8          # 4000757e
	slli	a10, a10, 24            # 40007581
	l8ui	a7, a1, 16              # 40007584
	slli	a7, a7, 16              # 40007587
	add.n	a7, a7, a10             # 4000758a
	add.n	a7, a7, a9              # 4000758c
	s32i.n	a7, a8, 0               # 4000758e
	addi.n	a7, a1, 4               # 40007590
	l32i.n	a6, a1, 20              # 40007592
	srli	a6, a6, 8               # 40007594
	extui	a6, a6, 0, 8            # 40007597
	s32i.n	a6, a7, 0               # 4000759a
	movi.n	a10, 2                  # 4000759c
	mov.n	a11, a1                 # 4000759e
	movi.n	a12, 1                  # 400075a0
	call8	fn_40006be8             # 400075a2
	movi.n	a10, 2                  # 400075a5
	call8	fn_4000912c             # 400075a7
	retw.n                          # 400075aa
	.size	fn_4000756c, . - fn_4000756c
