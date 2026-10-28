# fn_400021d0: 0x400021d0-0x40002225 (firmware file offset 0x321d0-0x32225), 37 instructions
# Called from: fn_40003140
# Addresses loaded: data_3ffe2390
# Other literal values: 0x3ffe2bf0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400021d0, @function
fn_400021d0:
	entry	a1, 64                  # 400021d0
	s32i.n	a2, a1, 16              # 400021d3
	s32i.n	a3, a1, 20              # 400021d5
	movi.n	a8, 0                   # 400021d7
	s32i.n	a8, a1, 0               # 400021d9
	movi.n	a7, 0                   # 400021db
	s32i.n	a7, a1, 0               # 400021dd
	l32r	a6, lit_3ffe1a98        # 400021df  = data_3ffe2390
	l32i.n	a6, a6, 0               # 400021e2
	l32i.n	a5, a1, 0               # 400021e4
	bgeu	a5, a6, .L40002224      # 400021e6
.L400021e9:
	l32i.n	a10, a1, 0              # 400021e9
	l32i.n	a11, a1, 16             # 400021eb
	addx4	a10, a10, a11           # 400021ed
	l32i.n	a10, a10, 0             # 400021f0
	movi.n	a9, 9                   # 400021f2
	bgeu	a9, a10, .L40002201     # 400021f4
	l32r	a12, lit_3ffe1a98       # 400021f7  = data_3ffe2390
	l32i.n	a12, a12, 16            # 400021fa
	s32i.n	a12, a1, 4              # 400021fc
	j	.L40002209              # 400021fe
.L40002201:
	l32r	a13, lit_3ffe1a80       # 40002201  = 0x3ffe2bf0
	l32i	a13, a13, 0x14c         # 40002204
	s32i.n	a13, a1, 4              # 40002207
.L40002209:
	l32i.n	a4, a1, 0               # 40002209
	l32i.n	a5, a1, 20              # 4000220b
	addx4	a4, a4, a5              # 4000220d
	l32i.n	a3, a1, 4               # 40002210
	s32i.n	a3, a4, 0               # 40002212
	l32i.n	a2, a1, 0               # 40002214
	addi.n	a2, a2, 1               # 40002216
	s32i.n	a2, a1, 0               # 40002218
	l32r	a15, lit_3ffe1a98       # 4000221a  = data_3ffe2390
	l32i.n	a15, a15, 0             # 4000221d
	l32i.n	a14, a1, 0              # 4000221f
	bltu	a14, a15, .L400021e9    # 40002221
.L40002224:
	retw.n                          # 40002224
	.size	fn_400021d0, . - fn_400021d0
