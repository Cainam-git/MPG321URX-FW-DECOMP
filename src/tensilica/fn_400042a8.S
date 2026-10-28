# fn_400042a8: 0x400042a8-0x40004360 (firmware file offset 0x342a8-0x34360), 83 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0x3ffe4220

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400042a8, @function
fn_400042a8:
	entry	a1, 64                  # 400042a8
	s32i.n	a2, a1, 16              # 400042ab
	movi.n	a5, 0                   # 400042ad
	l32r	a4, lit_3ffe1d34        # 400042af  = 0x3ffe4220
	l8ui	a4, a4, 0               # 400042b2
	bne	a4, a5, .L400042bb      # 400042b5
	j	.L4000435f              # 400042b8
.L400042bb:
	movi.n	a6, 0                   # 400042bb
	l32i.n	a5, a1, 16              # 400042bd
	beq	a5, a6, .L400042ce      # 400042bf
	movi.n	a7, 0                   # 400042c2
	l32r	a6, lit_3ffe1d34        # 400042c4  = 0x3ffe4220
	l32i.n	a6, a6, 4               # 400042c7
	l32i.n	a6, a6, 4               # 400042c9
	bne	a6, a7, .L400042d1      # 400042cb
.L400042ce:
	j	.L4000435f              # 400042ce
.L400042d1:
	l32i.n	a8, a1, 16              # 400042d1
	addi	a8, a8, -8              # 400042d3
	s32i.n	a8, a1, 0               # 400042d6
	l32r	a7, lit_3ffe1d34        # 400042d8  = 0x3ffe4220
	l32i.n	a7, a7, 4               # 400042db
	s32i.n	a7, a1, 4               # 400042dd
.L400042df:
	l32i.n	a11, a1, 4              # 400042df
	l32i.n	a11, a11, 0             # 400042e1
	s32i.n	a11, a1, 8              # 400042e3
	movi.n	a10, 0                  # 400042e5
	l32i.n	a9, a1, 8               # 400042e7
	beq	a9, a10, .L400042fa     # 400042e9
	l32i.n	a13, a1, 8              # 400042ec
	l32i.n	a12, a1, 16             # 400042ee
	bltu	a12, a13, .L400042fa    # 400042f0
	l32i.n	a13, a1, 8              # 400042f3
	s32i.n	a13, a1, 4              # 400042f5
	j	.L400042df              # 400042f7
.L400042fa:
	movi.n	a15, 0                  # 400042fa
	l32i.n	a14, a1, 8              # 400042fc
	beq	a14, a15, .L40004329    # 400042fe
	l32i.n	a4, a1, 0               # 40004301
	l32i.n	a4, a4, 4               # 40004303
	l32i.n	a3, a1, 16              # 40004305
	add.n	a3, a3, a4              # 40004307
	l32i.n	a2, a1, 8               # 40004309
	bne	a2, a3, .L40004329      # 4000430b
	l32i.n	a7, a1, 0               # 4000430e
	l32i.n	a8, a1, 0               # 40004310
	l32i.n	a8, a8, 4               # 40004312
	l32i.n	a6, a1, 8               # 40004314
	l32i.n	a6, a6, 4               # 40004316
	add.n	a6, a6, a8              # 40004318
	addi.n	a6, a6, 8               # 4000431a
	s32i.n	a6, a7, 4               # 4000431c
	l32i.n	a6, a1, 0               # 4000431e
	l32i.n	a5, a1, 8               # 40004320
	l32i.n	a5, a5, 0               # 40004322
	s32i.n	a5, a6, 0               # 40004324
	j	.L4000432f              # 40004326
.L40004329:
	l32i.n	a10, a1, 0              # 40004329
	l32i.n	a9, a1, 8               # 4000432b
	s32i.n	a9, a10, 0              # 4000432d
.L4000432f:
	l32i.n	a13, a1, 4              # 4000432f
	l32i.n	a13, a13, 4             # 40004331
	l32i.n	a12, a1, 4              # 40004333
	add.n	a12, a12, a13           # 40004335
	addi.n	a12, a12, 8             # 40004337
	l32i.n	a11, a1, 0              # 40004339
	bne	a11, a12, .L40004359    # 4000433b
	l32i.n	a2, a1, 4               # 4000433e
	l32i.n	a3, a1, 0               # 40004340
	l32i.n	a3, a3, 4               # 40004342
	l32i.n	a15, a1, 4              # 40004344
	l32i.n	a15, a15, 4             # 40004346
	add.n	a15, a15, a3            # 40004348
	addi.n	a15, a15, 8             # 4000434a
	s32i.n	a15, a2, 4              # 4000434c
	l32i.n	a15, a1, 4              # 4000434e
	l32i.n	a14, a1, 0              # 40004350
	l32i.n	a14, a14, 0             # 40004352
	s32i.n	a14, a15, 0             # 40004354
	j	.L4000435f              # 40004356
.L40004359:
	l32i.n	a5, a1, 4               # 40004359
	l32i.n	a4, a1, 0               # 4000435b
	s32i.n	a4, a5, 0               # 4000435d
.L4000435f:
	retw.n                          # 4000435f
	.size	fn_400042a8, . - fn_400042a8
