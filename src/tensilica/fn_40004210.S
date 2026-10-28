# fn_40004210: 0x40004210-0x400042a6 (firmware file offset 0x34210-0x342a6), 68 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0x3ffe4220

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004210, @function
fn_40004210:
	entry	a1, 80                  # 40004210
	s32i.n	a2, a1, 32              # 40004213
	movi.n	a5, 0                   # 40004215
	l32r	a4, lit_3ffe1d34        # 40004217  = 0x3ffe4220
	l8ui	a4, a4, 0               # 4000421a
	bne	a4, a5, .L40004227      # 4000421d
	movi.n	a5, 0                   # 40004220
	s32i.n	a5, a1, 16              # 40004222
	j	.L400042a3              # 40004224
.L40004227:
	movi.n	a8, -8                  # 40004227
	l32i.n	a7, a1, 32              # 40004229
	addi.n	a7, a7, 7               # 4000422b
	and	a7, a7, a8              # 4000422d
	s32i.n	a7, a1, 0               # 40004230
	l32r	a6, lit_3ffe1d34        # 40004232  = 0x3ffe4220
	l32i.n	a6, a6, 4               # 40004235
	s32i.n	a6, a1, 4               # 40004237
.L40004239:
	l32i.n	a10, a1, 4              # 40004239
	l32i.n	a10, a10, 0             # 4000423b
	s32i.n	a10, a1, 8              # 4000423d
	movi.n	a9, 0                   # 4000423f
	l32i.n	a8, a1, 8               # 40004241
	bne	a8, a9, .L4000424d      # 40004243
	movi.n	a11, 0                  # 40004246
	s32i.n	a11, a1, 16             # 40004248
	j	.L400042a3              # 4000424a
.L4000424d:
	l32i.n	a13, a1, 0              # 4000424d
	l32i.n	a12, a1, 8              # 4000424f
	l32i.n	a12, a12, 4             # 40004251
	bgeu	a12, a13, .L4000425d    # 40004253
	l32i.n	a13, a1, 8              # 40004256
	s32i.n	a13, a1, 4              # 40004258
	j	.L40004239              # 4000425a
.L4000425d:
	l32i.n	a3, a1, 0               # 4000425d
	l32i.n	a2, a1, 8               # 4000425f
	l32i.n	a2, a2, 4               # 40004261
	sub	a2, a2, a3              # 40004263
	s32i.n	a2, a1, 12              # 40004266
	l32i.n	a15, a1, 12             # 40004268
	movi.n	a14, 31                 # 4000426a
	bltu	a14, a15, .L40004280    # 4000426c
	l32i.n	a5, a1, 4               # 4000426f
	l32i.n	a4, a1, 8               # 40004271
	l32i.n	a4, a4, 0               # 40004273
	s32i.n	a4, a5, 0               # 40004275
	l32i.n	a3, a1, 8               # 40004277
	addi.n	a3, a3, 8               # 40004279
	s32i.n	a3, a1, 16              # 4000427b
	j	.L400042a3              # 4000427d
.L40004280:
	l32i.n	a12, a1, 12             # 40004280
	addi	a12, a12, -8            # 40004282
	s32i.n	a12, a1, 12             # 40004285
	l32i.n	a11, a1, 8              # 40004287
	l32i.n	a10, a1, 12             # 40004289
	s32i.n	a10, a11, 4             # 4000428b
	l32i.n	a9, a1, 12              # 4000428d
	l32i.n	a8, a1, 8               # 4000428f
	add.n	a8, a8, a9              # 40004291
	addi.n	a8, a8, 8               # 40004293
	s32i.n	a8, a1, 4               # 40004295
	l32i.n	a7, a1, 4               # 40004297
	l32i.n	a6, a1, 0               # 40004299
	s32i.n	a6, a7, 4               # 4000429b
	l32i.n	a5, a1, 4               # 4000429d
	addi.n	a5, a5, 8               # 4000429f
	s32i.n	a5, a1, 16              # 400042a1
.L400042a3:
	l32i.n	a2, a1, 16              # 400042a3
	retw.n                          # 400042a5
	.size	fn_40004210, . - fn_40004210
