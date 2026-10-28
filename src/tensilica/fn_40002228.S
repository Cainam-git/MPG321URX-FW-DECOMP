# fn_40002228: 0x40002228-0x4000233b (firmware file offset 0x32228-0x3233b), 118 instructions
# Called from: fn_400030c8
# Addresses loaded: data_3ffe2390, data_3ffe2480

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40002228, @function
fn_40002228:
	entry	a1, 80                  # 40002228
	s32i.n	a2, a1, 32              # 4000222b
	s32i.n	a3, a1, 36              # 4000222d
	s32i.n	a4, a1, 40              # 4000222f
	movi.n	a12, 0                  # 40002231
	s32i.n	a12, a1, 0              # 40002233
	movi.n	a11, 0                  # 40002235
	s32i.n	a11, a1, 4              # 40002237
	movi.n	a10, 2                  # 40002239
	s32i.n	a10, a1, 8              # 4000223b
	movi.n	a9, 0                   # 4000223d
	s32i.n	a9, a1, 0               # 4000223f
	l32r	a8, lit_3ffe1a98        # 40002241  = data_3ffe2390
	l32i.n	a8, a8, 0               # 40002244
	l32i.n	a7, a1, 0               # 40002246
	bltu	a7, a8, .L4000224e      # 40002248
	j	.L4000233a              # 4000224b
.L4000224e:
	movi.n	a15, 0                  # 4000224e
	s32i.n	a15, a1, 4              # 40002250
	l32i.n	a14, a1, 8              # 40002252
	addi.n	a14, a14, -1            # 40002254
	l32i.n	a13, a1, 4              # 40002256
	bgeu	a13, a14, .L400022d1    # 40002258
.L4000225b:
	l32i.n	a3, a1, 4               # 4000225b
	l32r	a4, lit_3ffe1bac        # 4000225d  = data_3ffe2480
	addx8	a3, a3, a4              # 40002260
	l32i.n	a3, a3, 0               # 40002263
	l32i.n	a2, a1, 0               # 40002265
	l32i.n	a4, a1, 32              # 40002267
	addx4	a2, a2, a4              # 40002269
	l32i.n	a2, a2, 0               # 4000226c
	bltu	a2, a3, .L400022c2      # 4000226e
	l32i.n	a6, a1, 0               # 40002271
	l32i.n	a7, a1, 32              # 40002273
	addx4	a6, a6, a7              # 40002275
	l32i.n	a6, a6, 0               # 40002278
	l32i.n	a5, a1, 4               # 4000227a
	l32r	a7, lit_3ffe1bac        # 4000227c  = data_3ffe2480
	addx8	a5, a5, a7              # 4000227f
	addi.n	a5, a5, 8               # 40002282
	l32i.n	a5, a5, 0               # 40002284
	bltu	a5, a6, .L400022c2      # 40002286
	l32i.n	a14, a1, 4              # 40002289
	l32r	a15, lit_3ffe1bac       # 4000228b  = data_3ffe2480
	addx8	a14, a14, a15           # 4000228e
	l32i.n	a14, a14, 0             # 40002291
	s32i.n	a14, a1, 12             # 40002293
	l32i.n	a12, a1, 4              # 40002295
	l32r	a13, lit_3ffe1bac       # 40002297  = data_3ffe2480
	addx8	a12, a12, a13           # 4000229a
	addi.n	a12, a12, 8             # 4000229d
	l32i.n	a12, a12, 0             # 4000229f
	s32i.n	a12, a1, 16             # 400022a1
	l32i.n	a10, a1, 4              # 400022a3
	l32r	a11, lit_3ffe1bac       # 400022a5  = data_3ffe2480
	addx8	a10, a10, a11           # 400022a8
	addi.n	a10, a10, 4             # 400022ab
	l32i.n	a10, a10, 0             # 400022ad
	s32i.n	a10, a1, 20             # 400022af
	l32i.n	a8, a1, 4               # 400022b1
	l32r	a9, lit_3ffe1bac        # 400022b3  = data_3ffe2480
	addx8	a8, a8, a9              # 400022b6
	addi.n	a8, a8, 12              # 400022b9
	l32i.n	a8, a8, 0               # 400022bb
	s32i.n	a8, a1, 24              # 400022bd
	j	.L400022d1              # 400022bf
.L400022c2:
	l32i.n	a4, a1, 4               # 400022c2
	addi.n	a4, a4, 1               # 400022c4
	s32i.n	a4, a1, 4               # 400022c6
	l32i.n	a3, a1, 8               # 400022c8
	addi.n	a3, a3, -1              # 400022ca
	l32i.n	a2, a1, 4               # 400022cc
	bltu	a2, a3, .L4000225b      # 400022ce
.L400022d1:
	l32i.n	a12, a1, 0              # 400022d1
	l32i.n	a13, a1, 36             # 400022d3
	addx4	a12, a12, a13           # 400022d5
	l32i.n	a15, a1, 12             # 400022d8
	l32i.n	a14, a1, 16             # 400022da
	sub	a14, a14, a15           # 400022dc
	l32i.n	a2, a1, 20              # 400022df
	l32i.n	a15, a1, 24             # 400022e1
	sub	a15, a15, a2            # 400022e3
	l32i.n	a2, a1, 12              # 400022e6
	l32i.n	a13, a1, 0              # 400022e8
	l32i.n	a3, a1, 32              # 400022ea
	addx4	a13, a13, a3            # 400022ec
	l32i.n	a13, a13, 0             # 400022ef
	sub	a13, a13, a2            # 400022f1
	mull	a13, a13, a15           # 400022f4
	quou	a13, a13, a14           # 400022f7
	l32i.n	a11, a1, 20             # 400022fa
	add.n	a11, a11, a13           # 400022fc
	s32i.n	a11, a12, 0             # 400022fe
	l32i.n	a9, a1, 0               # 40002300
	l32i.n	a10, a1, 36             # 40002302
	addx4	a9, a9, a10             # 40002304
	l32i.n	a10, a1, 8              # 40002307
	l32r	a11, lit_3ffe1bac       # 40002309  = data_3ffe2480
	addx8	a10, a10, a11           # 4000230c
	addi	a10, a10, -4            # 4000230f
	l32i.n	a10, a10, 0             # 40002312
	l32i.n	a11, a1, 40             # 40002314
	l32i.n	a8, a1, 0               # 40002316
	l32i.n	a12, a1, 36             # 40002318
	addx4	a8, a8, a12             # 4000231a
	l32i.n	a8, a8, 0               # 4000231d
	mull	a8, a8, a11             # 4000231f
	quou	a8, a8, a10             # 40002322
	s32i.n	a8, a9, 0               # 40002325
	l32i.n	a7, a1, 0               # 40002327
	addi.n	a7, a7, 1               # 40002329
	s32i.n	a7, a1, 0               # 4000232b
	l32r	a6, lit_3ffe1a98        # 4000232d  = data_3ffe2390
	l32i.n	a6, a6, 0               # 40002330
	l32i.n	a5, a1, 0               # 40002332
	bgeu	a5, a6, .L4000233a      # 40002334
	j	.L4000224e              # 40002337
.L4000233a:
	retw.n                          # 4000233a
	.size	fn_40002228, . - fn_40002228
