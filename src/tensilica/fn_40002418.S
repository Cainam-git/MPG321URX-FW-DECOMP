# fn_40002418: 0x40002418-0x400024e2 (firmware file offset 0x32418-0x324e2), 87 instructions
# Called from: fn_400030c8
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40002418, @function
fn_40002418:
	entry	a1, 64                  # 40002418
	s32i.n	a2, a1, 16              # 4000241b
	s32i.n	a3, a1, 20              # 4000241d
	s32i.n	a4, a1, 24              # 4000241f
	movi.n	a11, 0                  # 40002421
	s32i.n	a11, a1, 0              # 40002423
	movi.n	a10, 0                  # 40002425
	s32i.n	a10, a1, 4              # 40002427
	movi.n	a9, 0                   # 40002429
	s32i.n	a9, a1, 0               # 4000242b
	l32r	a8, lit_3ffe1a98        # 4000242d  = data_3ffe2390
	l32i.n	a8, a8, 0               # 40002430
	l32i.n	a7, a1, 0               # 40002432
	bgeu	a7, a8, .L4000245b      # 40002434
.L40002437:
	l32i.n	a13, a1, 0              # 40002437
	l32i.n	a14, a1, 16             # 40002439
	addx4	a13, a13, a14           # 4000243b
	l32i.n	a13, a13, 0             # 4000243e
	movi.n	a12, 0                  # 40002440
	bgeu	a12, a13, .L4000244b    # 40002442
	l32i.n	a15, a1, 4              # 40002445
	addi.n	a15, a15, 1             # 40002447
	s32i.n	a15, a1, 4              # 40002449
.L4000244b:
	l32i.n	a4, a1, 0               # 4000244b
	addi.n	a4, a4, 1               # 4000244d
	s32i.n	a4, a1, 0               # 4000244f
	l32r	a3, lit_3ffe1a98        # 40002451  = data_3ffe2390
	l32i.n	a3, a3, 0               # 40002454
	l32i.n	a2, a1, 0               # 40002456
	bltu	a2, a3, .L40002437      # 40002458
.L4000245b:
	movi.n	a7, 0                   # 4000245b
	s32i.n	a7, a1, 0               # 4000245d
	l32r	a6, lit_3ffe1a98        # 4000245f  = data_3ffe2390
	l32i.n	a6, a6, 0               # 40002462
	l32i.n	a5, a1, 0               # 40002464
	bgeu	a5, a6, .L400024e1      # 40002466
.L40002469:
	l32i.n	a12, a1, 0              # 40002469
	l32i.n	a13, a1, 16             # 4000246b
	addx4	a12, a12, a13           # 4000246d
	movi	a14, 255                # 40002470
	l32r	a15, lit_3ffe1a98       # 40002473  = data_3ffe2390
	l32i.n	a15, a15, 0             # 40002476
	addi.n	a15, a15, -1            # 40002478
	l32i.n	a3, a1, 4               # 4000247a
	l32r	a2, lit_3ffe1a98        # 4000247c  = data_3ffe2390
	l32i.n	a2, a2, 0               # 4000247f
	sub	a2, a2, a3              # 40002481
	l32r	a3, lit_3ffe1a98        # 40002484  = data_3ffe2390
	l32i	a3, a3, 68              # 40002487
	l32i.n	a13, a1, 0              # 4000248a
	l32i.n	a4, a1, 16              # 4000248c
	addx4	a13, a13, a4            # 4000248e
	l32i.n	a13, a13, 0             # 40002491
	mull	a13, a13, a3            # 40002493
	mull	a13, a13, a2            # 40002496
	quou	a13, a13, a15           # 40002499
	quou	a13, a13, a14           # 4000249c
	l32i.n	a11, a1, 0              # 4000249f
	l32i.n	a14, a1, 16             # 400024a1
	addx4	a11, a11, a14           # 400024a3
	l32i.n	a11, a11, 0             # 400024a6
	add.n	a11, a11, a13           # 400024a8
	s32i.n	a11, a12, 0             # 400024aa
	l32i.n	a9, a1, 0               # 400024ac
	l32i.n	a10, a1, 16             # 400024ae
	addx4	a9, a9, a10             # 400024b0
	l32i.n	a9, a9, 0               # 400024b3
	l32i.n	a8, a1, 20              # 400024b5
	bltu	a8, a9, .L400024cd      # 400024b7
	l32i.n	a15, a1, 24             # 400024ba
	l32i.n	a14, a1, 0              # 400024bc
	l32i.n	a2, a1, 16              # 400024be
	addx4	a14, a14, a2            # 400024c0
	l32i.n	a14, a14, 0             # 400024c3
	maxu	a14, a14, a15           # 400024c5
	s32i.n	a14, a1, 8              # 400024c8
	j	.L400024d1              # 400024ca
.L400024cd:
	l32i.n	a2, a1, 20              # 400024cd
	s32i.n	a2, a1, 8               # 400024cf
.L400024d1:
	l32i.n	a5, a1, 0               # 400024d1
	addi.n	a5, a5, 1               # 400024d3
	s32i.n	a5, a1, 0               # 400024d5
	l32r	a4, lit_3ffe1a98        # 400024d7  = data_3ffe2390
	l32i.n	a4, a4, 0               # 400024da
	l32i.n	a3, a1, 0               # 400024dc
	bltu	a3, a4, .L40002469      # 400024de
.L400024e1:
	retw.n                          # 400024e1
	.size	fn_40002418, . - fn_40002418
