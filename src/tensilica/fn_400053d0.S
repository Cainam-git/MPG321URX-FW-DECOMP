# fn_400053d0: 0x400053d0-0x40005420 (firmware file offset 0x353d0-0x35420), 28 instructions
# Called from: fn_40005460

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400053d0, @function
fn_400053d0:
	entry	a1, 64                  # 400053d0
	extui	a2, a2, 0, 8            # 400053d3
	s8i	a2, a1, 16              # 400053d6
	movi.n	a6, 0                   # 400053d9
	s8i	a6, a1, 0               # 400053db
	l8ui	a5, a1, 16              # 400053de
	addi	a5, a5, -48             # 400053e1
	movi.n	a4, 9                   # 400053e4
	bltu	a4, a5, .L400053f5      # 400053e6
	l8ui	a7, a1, 16              # 400053e9
	addi	a7, a7, -48             # 400053ec
	s8i	a7, a1, 0               # 400053ef
	j	.L4000541c              # 400053f2
.L400053f5:
	l8ui	a8, a1, 16              # 400053f5
	addi	a8, a8, -65             # 400053f8
	bgeui	a8, 6, .L4000540a       # 400053fb
	l8ui	a9, a1, 16              # 400053fe
	addi	a9, a9, -55             # 40005401
	s8i	a9, a1, 0               # 40005404
	j	.L4000541c              # 40005407
.L4000540a:
	l8ui	a10, a1, 16             # 4000540a
	addi	a10, a10, -97           # 4000540d
	bgeui	a10, 6, .L4000541c      # 40005410
	l8ui	a11, a1, 16             # 40005413
	addi	a11, a11, -87           # 40005416
	s8i	a11, a1, 0              # 40005419
.L4000541c:
	l8ui	a2, a1, 0               # 4000541c
	retw.n                          # 4000541f
	.size	fn_400053d0, . - fn_400053d0
