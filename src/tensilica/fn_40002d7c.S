# fn_40002d7c: 0x40002d7c-0x40002ddd (firmware file offset 0x32d7c-0x32ddd), 41 instructions
# Called from: fn_40003140
# Addresses loaded: data_3ffe2390
# Other literal values: 0x00000ffc, 0x00000fff

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40002d7c, @function
fn_40002d7c:
	entry	a1, 64                  # 40002d7c
	s32i.n	a2, a1, 16              # 40002d7f
	movi.n	a7, 0                   # 40002d81
	s32i.n	a7, a1, 0               # 40002d83
	movi.n	a6, 0                   # 40002d85
	s32i.n	a6, a1, 0               # 40002d87
	l32r	a5, lit_3ffe1a98        # 40002d89  = data_3ffe2390
	l32i.n	a5, a5, 0               # 40002d8c
	l32i.n	a4, a1, 0               # 40002d8e
	bgeu	a4, a5, .L40002ddc      # 40002d90
.L40002d93:
	l32i.n	a14, a1, 0              # 40002d93
	l32i.n	a15, a1, 16             # 40002d95
	addx4	a14, a14, a15           # 40002d97
	l32i.n	a14, a14, 0             # 40002d9a
	l32i.n	a12, a1, 0              # 40002d9c
	l32i.n	a13, a1, 16             # 40002d9e
	addx4	a12, a12, a13           # 40002da0
	l32r	a13, lit_3ffe1bdc       # 40002da3  = 0x00000ffc
	slli	a11, a14, 12            # 40002da6
	sub	a11, a11, a14           # 40002da9
	quou	a11, a11, a13           # 40002dac
	s32i.n	a11, a12, 0             # 40002daf
	l32i.n	a9, a1, 0               # 40002db1
	l32i.n	a10, a1, 16             # 40002db3
	addx4	a9, a9, a10             # 40002db5
	l32i.n	a9, a9, 0               # 40002db8
	l32r	a8, lit_3ffe1abc        # 40002dba  = 0x00000fff
	bgeu	a8, a9, .L40002dcc      # 40002dbd
	l32i.n	a3, a1, 0               # 40002dc0
	l32i.n	a4, a1, 16              # 40002dc2
	addx4	a3, a3, a4              # 40002dc4
	l32r	a2, lit_3ffe1abc        # 40002dc7  = 0x00000fff
	s32i.n	a2, a3, 0               # 40002dca
.L40002dcc:
	l32i.n	a7, a1, 0               # 40002dcc
	addi.n	a7, a7, 1               # 40002dce
	s32i.n	a7, a1, 0               # 40002dd0
	l32r	a6, lit_3ffe1a98        # 40002dd2  = data_3ffe2390
	l32i.n	a6, a6, 0               # 40002dd5
	l32i.n	a5, a1, 0               # 40002dd7
	bltu	a5, a6, .L40002d93      # 40002dd9
.L40002ddc:
	retw.n                          # 40002ddc
	.size	fn_40002d7c, . - fn_40002d7c
