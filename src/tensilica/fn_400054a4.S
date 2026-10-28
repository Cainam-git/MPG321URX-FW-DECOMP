# fn_400054a4: 0x400054a4-0x40005516 (firmware file offset 0x354a4-0x35516), 48 instructions
# Called from: fn_40005574
# Calls: fn_40005424

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400054a4, @function
fn_400054a4:
	entry	a1, 64                  # 400054a4
	s32i.n	a2, a1, 16              # 400054a7
	s32i.n	a3, a1, 20              # 400054a9
	movi.n	a6, 0                   # 400054ab
	l32i.n	a5, a1, 16              # 400054ad
	bne	a5, a6, .L400054b9      # 400054af
	movi.n	a6, 1                   # 400054b2
	s32i.n	a6, a1, 8               # 400054b4
	j	.L40005513              # 400054b6
.L400054b9:
	l32i.n	a10, a1, 16             # 400054b9
	movi.n	a9, 0                   # 400054bb
	s8i	a9, a10, 0              # 400054bd
	movi.n	a8, 0                   # 400054c0
	s32i.n	a8, a1, 0               # 400054c2
	l32i.n	a7, a1, 0               # 400054c4
	bgei	a7, 8, .L40005504       # 400054c6
.L400054c9:
	l32i.n	a11, a1, 20             # 400054c9
	l32i.n	a13, a1, 0              # 400054cb
	slli	a13, a13, 2             # 400054cd
	movi.n	a12, 28                 # 400054d0
	sub	a12, a12, a13           # 400054d2
	ssr	a12                     # 400054d5
	srl	a11, a11                # 400054d8
	extui	a11, a11, 0, 8          # 400054db
	extui	a11, a11, 0, 4          # 400054de
	s8i	a11, a1, 4              # 400054e1
	l8ui	a10, a1, 4              # 400054e4
	call8	fn_40005424             # 400054e7
	s8i	a10, a1, 4              # 400054ea
	l32i.n	a2, a1, 0               # 400054ed
	l32i.n	a15, a1, 16             # 400054ef
	add.n	a15, a15, a2            # 400054f1
	l8ui	a14, a1, 4              # 400054f3
	s8i	a14, a15, 0             # 400054f6
	l32i.n	a13, a1, 0              # 400054f9
	addi.n	a13, a13, 1             # 400054fb
	s32i.n	a13, a1, 0              # 400054fd
	l32i.n	a12, a1, 0              # 400054ff
	blti	a12, 8, .L400054c9      # 40005501
.L40005504:
	l32i.n	a5, a1, 0               # 40005504
	l32i.n	a4, a1, 16              # 40005506
	add.n	a4, a4, a5              # 40005508
	movi.n	a3, 0                   # 4000550a
	s8i	a3, a4, 0               # 4000550c
	movi.n	a2, 0                   # 4000550f
	s32i.n	a2, a1, 8               # 40005511
.L40005513:
	l32i.n	a2, a1, 8               # 40005513
	retw.n                          # 40005515
	.size	fn_400054a4, . - fn_400054a4
