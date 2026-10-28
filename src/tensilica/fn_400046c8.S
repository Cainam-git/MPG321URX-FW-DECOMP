# fn_400046c8: 0x400046c8-0x4000470c (firmware file offset 0x346c8-0x3470c), 31 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400046c8, @function
fn_400046c8:
	entry	a1, 64                  # 400046c8
	s32i.n	a2, a1, 16              # 400046cb
	s32i.n	a3, a1, 20              # 400046cd
	s32i.n	a4, a1, 24              # 400046cf
	movi.n	a10, 0                  # 400046d1
	s32i.n	a10, a1, 0              # 400046d3
	movi.n	a9, 0                   # 400046d5
	s32i.n	a9, a1, 4               # 400046d7
	l32i.n	a8, a1, 24              # 400046d9
	l32i.n	a7, a1, 4               # 400046db
	bgeu	a7, a8, .L40004709      # 400046dd
.L400046e0:
	l32i.n	a12, a1, 4              # 400046e0
	l32i.n	a13, a1, 20             # 400046e2
	addx4	a12, a12, a13           # 400046e4
	l32i.n	a12, a12, 0             # 400046e7
	l32i.n	a11, a1, 4              # 400046e9
	l32i.n	a13, a1, 16             # 400046eb
	addx4	a11, a11, a13           # 400046ed
	l32i.n	a11, a11, 0             # 400046f0
	beq	a11, a12, .L400046fc    # 400046f2
	movi.n	a14, 1                  # 400046f5
	s32i.n	a14, a1, 0              # 400046f7
	j	.L40004709              # 400046f9
.L400046fc:
	l32i.n	a3, a1, 4               # 400046fc
	addi.n	a3, a3, 1               # 400046fe
	s32i.n	a3, a1, 4               # 40004700
	l32i.n	a2, a1, 24              # 40004702
	l32i.n	a15, a1, 4              # 40004704
	bltu	a15, a2, .L400046e0     # 40004706
.L40004709:
	l32i.n	a2, a1, 0               # 40004709
	retw.n                          # 4000470b
	.size	fn_400046c8, . - fn_400046c8
