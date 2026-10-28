# fn_400048fc: 0x400048fc-0x4000496a (firmware file offset 0x348fc-0x3496a), 47 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0x0000ff00

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400048fc, @function
fn_400048fc:
	entry	a1, 64                  # 400048fc
	s32i.n	a2, a1, 16              # 400048ff
	s32i.n	a3, a1, 20              # 40004901
	l32i.n	a9, a1, 20              # 40004903
	srli	a9, a9, 2               # 40004905
	s32i.n	a9, a1, 0               # 40004908
	l32i.n	a8, a1, 16              # 4000490a
	s32i.n	a8, a1, 4               # 4000490c
	movi.n	a7, 0                   # 4000490e
	s32i.n	a7, a1, 8               # 40004910
	l32i.n	a6, a1, 0               # 40004912
	l32i.n	a5, a1, 8               # 40004914
	bgeu	a5, a6, .L40004969      # 40004916
.L40004919:
	l32i.n	a4, a1, 4               # 40004919
	memw                            # 4000491b
	l32i.n	a4, a4, 0               # 4000491e
	s32i.n	a4, a1, 12              # 40004920
	l32i.n	a3, a1, 12              # 40004922
	slli	a3, a3, 24              # 40004924
	l32r	a5, lit_3ffe1d3c        # 40004927  = 0x0000ff00
	l32i.n	a4, a1, 12              # 4000492a
	and	a4, a4, a5              # 4000492c
	slli	a4, a4, 8               # 4000492f
	l32i.n	a5, a1, 12              # 40004932
	extui	a5, a5, 24, 8           # 40004934
	l32r	a6, lit_3ffe1d3c        # 40004937  = 0x0000ff00
	l32i.n	a2, a1, 12              # 4000493a
	srli	a2, a2, 8               # 4000493c
	and	a2, a2, a6              # 4000493f
	or	a2, a2, a5              # 40004942
	or	a2, a2, a4              # 40004945
	or	a2, a2, a3              # 40004948
	s32i.n	a2, a1, 12              # 4000494b
	l32i.n	a15, a1, 4              # 4000494d
	l32i.n	a14, a1, 12             # 4000494f
	memw                            # 40004951
	s32i.n	a14, a15, 0             # 40004954
	l32i.n	a13, a1, 4              # 40004956
	addi.n	a13, a13, 4             # 40004958
	s32i.n	a13, a1, 4              # 4000495a
	l32i.n	a12, a1, 8              # 4000495c
	addi.n	a12, a12, 1             # 4000495e
	s32i.n	a12, a1, 8              # 40004960
	l32i.n	a11, a1, 0              # 40004962
	l32i.n	a10, a1, 8              # 40004964
	bltu	a10, a11, .L40004919    # 40004966
.L40004969:
	retw.n                          # 40004969
	.size	fn_400048fc, . - fn_400048fc
