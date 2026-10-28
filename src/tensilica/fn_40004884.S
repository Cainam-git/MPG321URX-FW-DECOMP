# fn_40004884: 0x40004884-0x400048fb (firmware file offset 0x34884-0x348fb), 53 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0x0000ff00

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004884, @function
fn_40004884:
	entry	a1, 64                  # 40004884
	s32i.n	a2, a1, 16              # 40004887
	s32i.n	a3, a1, 20              # 40004889
	movi.n	a8, 0                   # 4000488b
	s32i.n	a8, a1, 0               # 4000488d
	l32i.n	a7, a1, 0               # 4000488f
	s32i.n	a7, a1, 4               # 40004891
	l32i.n	a6, a1, 20              # 40004893
	l32i.n	a5, a1, 4               # 40004895
	bgeu	a5, a6, .L400048fa      # 40004897
.L4000489a:
	l32i.n	a10, a1, 0              # 4000489a
	l32i.n	a11, a1, 16             # 4000489c
	addx4	a10, a10, a11           # 4000489e
	l32i.n	a10, a10, 0             # 400048a1
	s32i.n	a10, a1, 8              # 400048a3
	l32i.n	a9, a1, 8               # 400048a5
	extui	a9, a9, 24, 8           # 400048a7
	s32i.n	a9, a1, 12              # 400048aa
	l32r	a9, lit_3ffe1d3c        # 400048ac  = 0x0000ff00
	l32i.n	a8, a1, 8               # 400048af
	srli	a8, a8, 8               # 400048b1
	and	a8, a8, a9              # 400048b4
	l32i.n	a7, a1, 12              # 400048b7
	add.n	a7, a7, a8              # 400048b9
	s32i.n	a7, a1, 12              # 400048bb
	l32r	a6, lit_3ffe1d3c        # 400048bd  = 0x0000ff00
	l32i.n	a5, a1, 8               # 400048c0
	and	a5, a5, a6              # 400048c2
	slli	a5, a5, 8               # 400048c5
	l32i.n	a4, a1, 12              # 400048c8
	add.n	a4, a4, a5              # 400048ca
	s32i.n	a4, a1, 12              # 400048cc
	l32i.n	a3, a1, 8               # 400048ce
	extui	a3, a3, 0, 8            # 400048d0
	slli	a3, a3, 24              # 400048d3
	l32i.n	a2, a1, 12              # 400048d6
	add.n	a2, a2, a3              # 400048d8
	s32i.n	a2, a1, 12              # 400048da
	l32i.n	a14, a1, 0              # 400048dc
	l32i.n	a15, a1, 16             # 400048de
	addx4	a14, a14, a15           # 400048e0
	l32i.n	a13, a1, 12             # 400048e3
	s32i.n	a13, a14, 0             # 400048e5
	l32i.n	a12, a1, 4              # 400048e7
	addi.n	a12, a12, 4             # 400048e9
	s32i.n	a12, a1, 4              # 400048eb
	l32i.n	a11, a1, 0              # 400048ed
	addi.n	a11, a11, 1             # 400048ef
	s32i.n	a11, a1, 0              # 400048f1
	l32i.n	a10, a1, 20             # 400048f3
	l32i.n	a9, a1, 4               # 400048f5
	bltu	a9, a10, .L4000489a     # 400048f7
.L400048fa:
	retw.n                          # 400048fa
	.size	fn_40004884, . - fn_40004884
