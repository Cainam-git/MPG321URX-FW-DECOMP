# fn_4000082c: 0x4000082c-0x40000879 (firmware file offset 0x3082c-0x30879), 34 instructions
# Called from: fn_400008c0, fn_400030c8, fn_40003140, fn_400035d0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000082c, @function
fn_4000082c:
	entry	a1, 64                  # 4000082c
	s32i.n	a2, a1, 16              # 4000082f
	s32i.n	a3, a1, 20              # 40000831
	s32i.n	a4, a1, 24              # 40000833
	movi.n	a9, 0                   # 40000835
	s32i.n	a9, a1, 0               # 40000837
	l32i.n	a8, a1, 24              # 40000839
	srli	a8, a8, 1               # 4000083b
	l32i.n	a7, a1, 0               # 4000083e
	bgeu	a7, a8, .L40000878      # 40000840
.L40000843:
	l32i.n	a3, a1, 0               # 40000843
	l32i.n	a4, a1, 20              # 40000845
	addx4	a3, a3, a4              # 40000847
	s32i.n	a3, a1, 4               # 4000084a
	l32i.n	a14, a1, 4              # 4000084c
	l32i.n	a15, a1, 0              # 4000084e
	l32i.n	a2, a1, 16              # 40000850
	addx8	a15, a15, a2            # 40000852
	l32i.n	a15, a15, 4             # 40000855
	slli	a15, a15, 16            # 40000857
	l32i.n	a13, a1, 0              # 4000085a
	l32i.n	a2, a1, 16              # 4000085c
	addx8	a13, a13, a2            # 4000085e
	l32i.n	a13, a13, 0             # 40000861
	or	a13, a13, a15           # 40000863
	s32i.n	a13, a14, 0             # 40000866
	l32i.n	a12, a1, 0              # 40000868
	addi.n	a12, a12, 1             # 4000086a
	s32i.n	a12, a1, 0              # 4000086c
	l32i.n	a11, a1, 24             # 4000086e
	srli	a11, a11, 1             # 40000870
	l32i.n	a10, a1, 0              # 40000873
	bltu	a10, a11, .L40000843    # 40000875
.L40000878:
	retw.n                          # 40000878
	.size	fn_4000082c, . - fn_4000082c
