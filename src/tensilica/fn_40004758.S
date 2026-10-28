# fn_40004758: 0x40004758-0x40004784 (firmware file offset 0x34758-0x34784), 20 instructions
# Called from: fn_40004c14, fn_40004ea0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004758, @function
fn_40004758:
	entry	a1, 64                  # 40004758
	s32i.n	a2, a1, 16              # 4000475b
	movi.n	a5, 0                   # 4000475d
	s32i.n	a5, a1, 0               # 4000475f
	movi.n	a5, 0                   # 40004761
	l32i.n	a4, a1, 16              # 40004763
	l8ui	a4, a4, 0               # 40004765
	beq	a4, a5, .L40004781      # 40004768
.L4000476b:
	l32i.n	a8, a1, 0               # 4000476b
	addi.n	a8, a8, 1               # 4000476d
	s32i.n	a8, a1, 0               # 4000476f
	l32i.n	a7, a1, 16              # 40004771
	addi.n	a7, a7, 1               # 40004773
	s32i.n	a7, a1, 16              # 40004775
	movi.n	a7, 0                   # 40004777
	l32i.n	a6, a1, 16              # 40004779
	l8ui	a6, a6, 0               # 4000477b
	bne	a6, a7, .L4000476b      # 4000477e
.L40004781:
	l32i.n	a2, a1, 0               # 40004781
	retw.n                          # 40004783
	.size	fn_40004758, . - fn_40004758
