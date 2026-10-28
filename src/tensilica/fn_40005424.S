# fn_40005424: 0x40005424-0x4000545f (firmware file offset 0x35424-0x3545f), 21 instructions
# Called from: fn_400054a4

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005424, @function
fn_40005424:
	entry	a1, 64                  # 40005424
	extui	a2, a2, 0, 8            # 40005427
	s8i	a2, a1, 16              # 4000542a
	l8ui	a5, a1, 16              # 4000542d
	movi.n	a4, 9                   # 40005430
	bltu	a4, a5, .L40005441      # 40005432
	l8ui	a6, a1, 16              # 40005435
	addi	a6, a6, 48              # 40005438
	s8i	a6, a1, 0               # 4000543b
	j	.L4000545b              # 4000543e
.L40005441:
	l8ui	a7, a1, 16              # 40005441
	addi	a7, a7, -10             # 40005444
	bgeui	a7, 6, .L40005456       # 40005447
	l8ui	a8, a1, 16              # 4000544a
	addi	a8, a8, 55              # 4000544d
	s8i	a8, a1, 0               # 40005450
	j	.L4000545b              # 40005453
.L40005456:
	movi.n	a9, 48                  # 40005456
	s8i	a9, a1, 0               # 40005458
.L4000545b:
	l8ui	a2, a1, 0               # 4000545b
	retw.n                          # 4000545e
	.size	fn_40005424, . - fn_40005424
