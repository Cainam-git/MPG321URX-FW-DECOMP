# fn_40004710: 0x40004710-0x40004754 (firmware file offset 0x34710-0x34754), 31 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004710, @function
fn_40004710:
	entry	a1, 64                  # 40004710
	s32i.n	a2, a1, 16              # 40004713
	s32i.n	a3, a1, 20              # 40004715
	s32i.n	a4, a1, 24              # 40004717
	movi.n	a10, 0                  # 40004719
	s32i.n	a10, a1, 0              # 4000471b
	movi.n	a9, 0                   # 4000471d
	s32i.n	a9, a1, 4               # 4000471f
	l32i.n	a8, a1, 24              # 40004721
	l32i.n	a7, a1, 4               # 40004723
	bgeu	a7, a8, .L40004751      # 40004725
.L40004728:
	l32i.n	a13, a1, 4              # 40004728
	l32i.n	a12, a1, 20             # 4000472a
	add.n	a12, a12, a13           # 4000472c
	l8ui	a12, a12, 0             # 4000472e
	l32i.n	a13, a1, 4              # 40004731
	l32i.n	a11, a1, 16             # 40004733
	add.n	a11, a11, a13           # 40004735
	l8ui	a11, a11, 0             # 40004737
	beq	a11, a12, .L40004744    # 4000473a
	movi.n	a13, 1                  # 4000473d
	s32i.n	a13, a1, 0              # 4000473f
	j	.L40004751              # 40004741
.L40004744:
	l32i.n	a2, a1, 4               # 40004744
	addi.n	a2, a2, 1               # 40004746
	s32i.n	a2, a1, 4               # 40004748
	l32i.n	a15, a1, 24             # 4000474a
	l32i.n	a14, a1, 4              # 4000474c
	bltu	a14, a15, .L40004728    # 4000474e
.L40004751:
	l32i.n	a2, a1, 0               # 40004751
	retw.n                          # 40004753
	.size	fn_40004710, . - fn_40004710
