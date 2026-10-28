# fn_40004804: 0x40004804-0x40004842 (firmware file offset 0x34804-0x34842), 27 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004804, @function
fn_40004804:
	entry	a1, 64                  # 40004804
	s32i.n	a2, a1, 16              # 40004807
	s32i.n	a3, a1, 20              # 40004809
	movi.n	a6, 0                   # 4000480b
	l32i.n	a5, a1, 20              # 4000480d
	bne	a5, a6, .L40004819      # 4000480f
	l32i.n	a6, a1, 16              # 40004812
	s32i.n	a6, a1, 0               # 40004814
	j	.L4000483f              # 40004816
.L40004819:
	movi.n	a8, 0                   # 40004819
	l32i.n	a9, a1, 20              # 4000481b
	l32i.n	a7, a1, 16              # 4000481d
	remu	a7, a7, a9              # 4000481f
	bne	a7, a8, .L4000482c      # 40004822
	l32i.n	a10, a1, 16             # 40004825
	s32i.n	a10, a1, 0              # 40004827
	j	.L4000483f              # 40004829
.L4000482c:
	l32i.n	a13, a1, 20             # 4000482c
	l32i.n	a12, a1, 16             # 4000482e
	quou	a12, a12, a13           # 40004830
	addi.n	a12, a12, 1             # 40004833
	l32i.n	a11, a1, 20             # 40004835
	mull	a11, a11, a12           # 40004837
	s32i.n	a11, a1, 0              # 4000483a
	j	.L4000483f              # 4000483c
.L4000483f:
	l32i.n	a2, a1, 0               # 4000483f
	retw.n                          # 40004841
	.size	fn_40004804, . - fn_40004804
