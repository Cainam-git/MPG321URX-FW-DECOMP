# fn_4000a1f4: 0x4000a1f4-0x4000a2ca (firmware file offset 0x3a1f4-0x3a2ca), 91 instructions
# Called from: fn_40003904, fn_40003a70, fn_40003b98

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a1f4, @function
fn_4000a1f4:
	entry	a1, 80                  # 4000a1f4
	s32i.n	a2, a1, 32              # 4000a1f7
	movi.n	a7, 0                   # 4000a1f9
	s32i.n	a7, a1, 0               # 4000a1fb
	movi.n	a6, 0                   # 4000a1fd
	s32i.n	a6, a1, 4               # 4000a1ff
	movi.n	a5, 0                   # 4000a201
	s32i.n	a5, a1, 8               # 4000a203
	movi.n	a5, 0                   # 4000a205
	l32i.n	a6, a1, 8               # 4000a207
	l32i.n	a4, a1, 32              # 4000a209
	add.n	a4, a4, a6              # 4000a20b
	l8ui	a4, a4, 0               # 4000a20d
	beq	a4, a5, .L4000a227      # 4000a210
.L4000a213:
	l32i.n	a9, a1, 8               # 4000a213
	addi.n	a9, a9, 1               # 4000a215
	s32i.n	a9, a1, 8               # 4000a217
	movi.n	a9, 0                   # 4000a219
	l32i.n	a10, a1, 8              # 4000a21b
	l32i.n	a8, a1, 32              # 4000a21d
	add.n	a8, a8, a10             # 4000a21f
	l8ui	a8, a8, 0               # 4000a221
	bne	a8, a9, .L4000a213      # 4000a224
.L4000a227:
	l32i.n	a12, a1, 8              # 4000a227
	addi.n	a12, a12, -1            # 4000a229
	s32i.n	a12, a1, 12             # 4000a22b
	movi.n	a11, 0                  # 4000a22d
	l32i.n	a10, a1, 12             # 4000a22f
	bge	a10, a11, .L4000a237    # 4000a231
	j	.L4000a2c7              # 4000a234
.L4000a237:
	movi.n	a15, 0                  # 4000a237
	s8i	a15, a1, 16             # 4000a239
	l32i.n	a15, a1, 12             # 4000a23c
	l32i.n	a14, a1, 32             # 4000a23e
	add.n	a14, a14, a15           # 4000a240
	l8ui	a14, a14, 0             # 4000a242
	s32i.n	a14, a1, 20             # 4000a245
	l32i.n	a13, a1, 20             # 4000a247
	bnei	a13, 32, .L4000a24f     # 4000a249
	j	.L4000a2b7              # 4000a24c
.L4000a24f:
	l32i.n	a3, a1, 20              # 4000a24f
	addi	a3, a3, -48             # 4000a251
	movi.n	a2, 9                   # 4000a254
	bltu	a2, a3, .L4000a268      # 4000a256
	l32i.n	a5, a1, 20              # 4000a259
	addi	a5, a5, -48             # 4000a25b
	s32i.n	a5, a1, 20              # 4000a25e
	movi.n	a4, 1                   # 4000a260
	s8i	a4, a1, 16              # 4000a262
	j	.L4000a293              # 4000a265
.L4000a268:
	l32i.n	a6, a1, 20              # 4000a268
	addi	a6, a6, -97             # 4000a26a
	bgeui	a6, 6, .L4000a27f       # 4000a26d
	l32i.n	a8, a1, 20              # 4000a270
	addi	a8, a8, -87             # 4000a272
	s32i.n	a8, a1, 20              # 4000a275
	movi.n	a7, 1                   # 4000a277
	s8i	a7, a1, 16              # 4000a279
	j	.L4000a293              # 4000a27c
.L4000a27f:
	l32i.n	a9, a1, 20              # 4000a27f
	addi	a9, a9, -65             # 4000a281
	bgeui	a9, 6, .L4000a293       # 4000a284
	l32i.n	a11, a1, 20             # 4000a287
	addi	a11, a11, -55           # 4000a289
	s32i.n	a11, a1, 20             # 4000a28c
	movi.n	a10, 1                  # 4000a28e
	s8i	a10, a1, 16             # 4000a290
.L4000a293:
	movi.n	a13, 0                  # 4000a293
	l8ui	a12, a1, 16             # 4000a295
	beq	a12, a13, .L4000a2b4    # 4000a298
	l32i.n	a2, a1, 20              # 4000a29b
	l32i.n	a3, a1, 4               # 4000a29d
	ssl	a3                      # 4000a29f
	sll	a2, a2                  # 4000a2a2
	l32i.n	a15, a1, 0              # 4000a2a5
	add.n	a15, a15, a2            # 4000a2a7
	s32i.n	a15, a1, 0              # 4000a2a9
	l32i.n	a14, a1, 4              # 4000a2ab
	addi.n	a14, a14, 4             # 4000a2ad
	s32i.n	a14, a1, 4              # 4000a2af
	j	.L4000a2b7              # 4000a2b1
.L4000a2b4:
	j	.L4000a2c7              # 4000a2b4
.L4000a2b7:
	l32i.n	a6, a1, 12              # 4000a2b7
	addi.n	a6, a6, -1              # 4000a2b9
	s32i.n	a6, a1, 12              # 4000a2bb
	movi.n	a5, 0                   # 4000a2bd
	l32i.n	a4, a1, 12              # 4000a2bf
	blt	a4, a5, .L4000a2c7      # 4000a2c1
	j	.L4000a237              # 4000a2c4
.L4000a2c7:
	l32i.n	a2, a1, 0               # 4000a2c7
	retw.n                          # 4000a2c9
	.size	fn_4000a1f4, . - fn_4000a1f4
