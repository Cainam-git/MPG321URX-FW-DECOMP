# fn_400011e4: 0x400011e4-0x40001343 (firmware file offset 0x311e4-0x31343), 145 instructions
# Called from: fn_40001428, fn_400014c0, fn_4000153c, fn_4000165c, fn_400017c0, fn_400035d0
# Addresses loaded: data_3ffe2390
# Other literal values: 0x3ffe3f30, 0x3ffe3eb0, 0x3ffe3ef0, 0x00000fff, 0x3ffe2bf0, 0xe009104c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400011e4, @function
fn_400011e4:
	entry	a1, 96                  # 400011e4
	s32i.n	a2, a1, 48              # 400011e7
	movi.n	a12, 0                  # 400011e9
	s32i.n	a12, a1, 0              # 400011eb
	movi.n	a11, 0                  # 400011ed
	s32i.n	a11, a1, 4              # 400011ef
	movi.n	a10, 0                  # 400011f1
	s32i.n	a10, a1, 8              # 400011f3
	movi.n	a9, 0                   # 400011f5
	s32i.n	a9, a1, 12              # 400011f7
	movi.n	a8, 0                   # 400011f9
	s32i.n	a8, a1, 16              # 400011fb
	movi.n	a7, 0                   # 400011fd
	s32i.n	a7, a1, 20              # 400011ff
	movi.n	a6, 0                   # 40001201
	s32i.n	a6, a1, 24              # 40001203
	movi.n	a5, 0                   # 40001205
	s32i.n	a5, a1, 28              # 40001207
	movi.n	a5, 0                   # 40001209
	l32i.n	a4, a1, 48              # 4000120b
	bne	a4, a5, .L40001230      # 4000120d
	l32r	a14, lit_3ffe1b10       # 40001210  = 0x3ffe3f30
	l32i.n	a14, a14, 0             # 40001213
	movi.n	a13, 59                 # 40001215
	bltu	a13, a14, .L40001229    # 40001217
	l32r	a2, lit_3ffe1b10        # 4000121a  = 0x3ffe3f30
	l32r	a15, lit_3ffe1b10       # 4000121d  = 0x3ffe3f30
	l32i.n	a15, a15, 0             # 40001220
	addi.n	a15, a15, 1             # 40001222
	s32i.n	a15, a2, 0              # 40001224
	j	.L40001342              # 40001226
.L40001229:
	l32r	a3, lit_3ffe1b10        # 40001229  = 0x3ffe3f30
	movi.n	a2, 0                   # 4000122c
	s32i.n	a2, a3, 0               # 4000122e
.L40001230:
	movi.n	a6, 0                   # 40001230
	s32i.n	a6, a1, 12              # 40001232
	l32r	a5, lit_3ffe1a98        # 40001234  = data_3ffe2390
	l32i.n	a5, a5, 0               # 40001237
	l32i.n	a4, a1, 12              # 40001239
	bgeu	a4, a5, .L40001270      # 4000123b
.L4000123e:
	l32i.n	a14, a1, 16             # 4000123e
	l32i.n	a13, a1, 12             # 40001240
	l32r	a15, lit_3ffe1ac0       # 40001242  = 0x3ffe3eb0
	addx2	a13, a13, a15           # 40001245
	l16ui	a13, a13, 0             # 40001248
	add.n	a13, a13, a14           # 4000124b
	s32i.n	a13, a1, 16             # 4000124d
	l32i.n	a11, a1, 20             # 4000124f
	l32i.n	a10, a1, 12             # 40001251
	l32r	a12, lit_3ffe1ac4       # 40001253  = 0x3ffe3ef0
	addx2	a10, a10, a12           # 40001256
	l16ui	a10, a10, 0             # 40001259
	add.n	a10, a10, a11           # 4000125c
	s32i.n	a10, a1, 20             # 4000125e
	l32i.n	a9, a1, 12              # 40001260
	addi.n	a9, a9, 1               # 40001262
	s32i.n	a9, a1, 12              # 40001264
	l32r	a8, lit_3ffe1a98        # 40001266  = data_3ffe2390
	l32i.n	a8, a8, 0               # 40001269
	l32i.n	a7, a1, 12              # 4000126b
	bltu	a7, a8, .L4000123e      # 4000126d
.L40001270:
	l32r	a6, lit_3ffe1a98        # 40001270  = data_3ffe2390
	l32i.n	a6, a6, 0               # 40001273
	l32i.n	a5, a1, 16              # 40001275
	quou	a5, a5, a6              # 40001277
	s32i.n	a5, a1, 24              # 4000127a
	l32r	a4, lit_3ffe1a98        # 4000127c  = data_3ffe2390
	l32i.n	a4, a4, 0               # 4000127f
	l32i.n	a3, a1, 20              # 40001281
	quou	a3, a3, a4              # 40001283
	s32i.n	a3, a1, 28              # 40001286
	l32i.n	a3, a1, 28              # 40001288
	l32r	a2, lit_3ffe1a98        # 4000128a  = data_3ffe2390
	l32i.n	a2, a2, 8               # 4000128d
	bgeu	a2, a3, .L400012be      # 4000128f
	movi.n	a8, 10                  # 40001292
	l32r	a10, lit_3ffe1a98       # 40001294  = data_3ffe2390
	l32i.n	a10, a10, 8             # 40001297
	l32r	a9, lit_3ffe1a98        # 40001299  = data_3ffe2390
	l32i.n	a9, a9, 12              # 4000129c
	sub	a9, a9, a10             # 4000129e
	movi	a10, 0x3e8              # 400012a1
	l32r	a11, lit_3ffe1a98       # 400012a4  = data_3ffe2390
	l32i.n	a11, a11, 8             # 400012a7
	l32i.n	a7, a1, 28              # 400012a9
	sub	a7, a7, a11             # 400012ab
	mull	a7, a7, a10             # 400012ae
	quou	a7, a7, a9              # 400012b1
	addi.n	a7, a7, 5               # 400012b4
	quou	a7, a7, a8              # 400012b6
	s32i.n	a7, a1, 8               # 400012b9
	j	.L400012c2              # 400012bb
.L400012be:
	movi.n	a11, 0                  # 400012be
	s32i.n	a11, a1, 8              # 400012c0
.L400012c2:
	l32i.n	a13, a1, 24             # 400012c2
	movi.n	a12, 0                  # 400012c4
	bgeu	a12, a13, .L400012e3    # 400012c6
	movi.n	a15, 10                 # 400012c9
	l32r	a2, lit_3ffe1abc        # 400012cb  = 0x00000fff
	movi	a3, 0x3e8               # 400012ce
	l32i.n	a14, a1, 24             # 400012d1
	mull	a14, a14, a3            # 400012d3
	quou	a14, a14, a2            # 400012d6
	addi.n	a14, a14, 5             # 400012d9
	quou	a14, a14, a15           # 400012db
	s32i.n	a14, a1, 4              # 400012de
	j	.L400012e7              # 400012e0
.L400012e3:
	movi.n	a4, 0                   # 400012e3
	s32i.n	a4, a1, 4               # 400012e5
.L400012e7:
	movi	a7, 100                 # 400012e7
	l32i.n	a8, a1, 8               # 400012ea
	l32i.n	a6, a1, 4               # 400012ec
	mull	a6, a6, a8              # 400012ee
	addi	a6, a6, 50              # 400012f1
	quou	a6, a6, a7              # 400012f4
	s32i.n	a6, a1, 0               # 400012f7
	l32r	a5, lit_3ffe1a80        # 400012f9  = 0x3ffe2bf0
	l32i	a5, a5, 0x140           # 400012fc
	bltui	a5, 4, .L40001321       # 400012ff
	movi.n	a10, 1                  # 40001302
	l32i.n	a11, a1, 0              # 40001304
	slli	a11, a11, 8             # 40001306
	l32i.n	a12, a1, 8              # 40001309
	slli	a12, a12, 24            # 4000130b
	l32i.n	a9, a1, 4               # 4000130e
	slli	a9, a9, 16              # 40001310
	or	a9, a9, a12             # 40001313
	or	a9, a9, a11             # 40001316
	or	a9, a9, a10             # 40001319
	s32i.n	a9, a1, 32              # 4000131c
	j	.L40001338              # 4000131e
.L40001321:
	l32i.n	a13, a1, 0              # 40001321
	slli	a13, a13, 8             # 40001323
	l32i.n	a14, a1, 8              # 40001326
	slli	a14, a14, 24            # 40001328
	l32i.n	a12, a1, 4              # 4000132b
	slli	a12, a12, 16            # 4000132d
	or	a12, a12, a14           # 40001330
	or	a12, a12, a13           # 40001333
	s32i.n	a12, a1, 32             # 40001336
.L40001338:
	l32r	a15, lit_3ffe1b14       # 40001338  = 0xe009104c
	memw                            # 4000133b
	l32i.n	a14, a1, 32             # 4000133e
	s32i.n	a14, a15, 0             # 40001340
.L40001342:
	retw.n                          # 40001342
	.size	fn_400011e4, . - fn_400011e4
