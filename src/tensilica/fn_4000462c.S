# fn_4000462c: 0x4000462c-0x40004660 (firmware file offset 0x3462c-0x34660), 24 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000462c, @function
fn_4000462c:
	entry	a1, 64                  # 4000462c
	s32i.n	a2, a1, 16              # 4000462f
	s32i.n	a3, a1, 20              # 40004631
	s32i.n	a4, a1, 24              # 40004633
	movi.n	a9, 0                   # 40004635
	s32i.n	a9, a1, 0               # 40004637
	l32i.n	a8, a1, 24              # 40004639
	l32i.n	a7, a1, 0               # 4000463b
	bgeu	a7, a8, .L4000465f      # 4000463d
.L40004640:
	l32i.n	a15, a1, 0              # 40004640
	l32i.n	a14, a1, 16             # 40004642
	add.n	a14, a14, a15           # 40004644
	l32i.n	a15, a1, 0              # 40004646
	l32i.n	a13, a1, 20             # 40004648
	add.n	a13, a13, a15           # 4000464a
	l8ui	a13, a13, 0             # 4000464c
	s8i	a13, a14, 0             # 4000464f
	l32i.n	a12, a1, 0              # 40004652
	addi.n	a12, a12, 1             # 40004654
	s32i.n	a12, a1, 0              # 40004656
	l32i.n	a11, a1, 24             # 40004658
	l32i.n	a10, a1, 0              # 4000465a
	bltu	a10, a11, .L40004640    # 4000465c
.L4000465f:
	retw.n                          # 4000465f
	.size	fn_4000462c, . - fn_4000462c
