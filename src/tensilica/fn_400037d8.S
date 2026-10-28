# fn_400037d8: 0x400037d8-0x40003810 (firmware file offset 0x337d8-0x33810), 25 instructions
# Called from: fn_4000a3cc
# Addresses loaded: data_3ffe2590
# Other literal values: 0x3ffe3f60

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400037d8, @function
fn_400037d8:
	entry	a1, 48                  # 400037d8
	movi.n	a6, 0                   # 400037db
	s32i.n	a6, a1, 0               # 400037dd
	movi.n	a5, 46                  # 400037df
	s32i.n	a5, a1, 4               # 400037e1
	movi.n	a4, 0                   # 400037e3
	s32i.n	a4, a1, 0               # 400037e5
	l32i.n	a3, a1, 4               # 400037e7
	l32i.n	a2, a1, 0               # 400037e9
	bgeu	a2, a3, .L4000380f      # 400037eb
.L400037ee:
	l32i.n	a11, a1, 0              # 400037ee
	l32r	a12, lit_3ffe1cb4       # 400037f0  = data_3ffe2590
	addx8	a11, a11, a12           # 400037f3
	l32i.n	a11, a11, 0             # 400037f6
	l32r	a12, lit_3ffe1cb8       # 400037f8  = 0x3ffe3f60
	addx4	a11, a11, a12           # 400037fb
	l32i.n	a10, a1, 0              # 400037fe
	s32i.n	a10, a11, 0             # 40003800
	l32i.n	a9, a1, 0               # 40003802
	addi.n	a9, a9, 1               # 40003804
	s32i.n	a9, a1, 0               # 40003806
	l32i.n	a8, a1, 4               # 40003808
	l32i.n	a7, a1, 0               # 4000380a
	bltu	a7, a8, .L400037ee      # 4000380c
.L4000380f:
	retw.n                          # 4000380f
	.size	fn_400037d8, . - fn_400037d8
