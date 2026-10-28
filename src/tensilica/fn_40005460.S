# fn_40005460: 0x40005460-0x400054a1 (firmware file offset 0x35460-0x354a1), 29 instructions
# Called from: fn_4000574c
# Calls: fn_400053d0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005460, @function
fn_40005460:
	entry	a1, 64                  # 40005460
	s32i.n	a2, a1, 16              # 40005463
	s32i.n	a3, a1, 20              # 40005465
	movi.n	a8, 0                   # 40005467
	s32i.n	a8, a1, 0               # 40005469
	movi.n	a7, 0                   # 4000546b
	s32i.n	a7, a1, 4               # 4000546d
	l32i.n	a6, a1, 20              # 4000546f
	l32i.n	a5, a1, 4               # 40005471
	bge	a5, a6, .L4000549e      # 40005473
.L40005476:
	l32i.n	a11, a1, 4              # 40005476
	l32i.n	a10, a1, 16             # 40005478
	add.n	a10, a10, a11           # 4000547a
	l8ui	a10, a10, 0             # 4000547c
	call8	fn_400053d0             # 4000547f
	s8i	a10, a1, 8              # 40005482
	l32i.n	a15, a1, 0              # 40005485
	slli	a15, a15, 4             # 40005487
	l8ui	a14, a1, 8              # 4000548a
	add.n	a14, a14, a15           # 4000548d
	s32i.n	a14, a1, 0              # 4000548f
	l32i.n	a13, a1, 4              # 40005491
	addi.n	a13, a13, 1             # 40005493
	s32i.n	a13, a1, 4              # 40005495
	l32i.n	a12, a1, 20             # 40005497
	l32i.n	a11, a1, 4              # 40005499
	blt	a11, a12, .L40005476    # 4000549b
.L4000549e:
	l32i.n	a2, a1, 0               # 4000549e
	retw.n                          # 400054a0
	.size	fn_40005460, . - fn_40005460
