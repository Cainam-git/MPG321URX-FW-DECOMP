# fn_40006144: 0x40006144-0x4000617d (firmware file offset 0x36144-0x3617d), 25 instructions
# Called from: fn_400068c0
# Addresses loaded: data_3ffe2770

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006144, @function
fn_40006144:
	entry	a1, 48                  # 40006144
	movi.n	a5, 59                  # 40006147
	s32i.n	a5, a1, 0               # 40006149
	movi.n	a4, 0                   # 4000614b
	s32i.n	a4, a1, 4               # 4000614d
	l32i.n	a3, a1, 0               # 4000614f
	l32i.n	a2, a1, 4               # 40006151
	bgeu	a2, a3, .L4000617c      # 40006153
.L40006156:
	l32i.n	a10, a1, 4              # 40006156
	l32r	a11, lit_3ffe1e84       # 40006158  = data_3ffe2770
	addx8	a10, a10, a11           # 4000615b
	l32i.n	a10, a10, 0             # 4000615e
	l32i.n	a9, a1, 4               # 40006160
	l32r	a11, lit_3ffe1e84       # 40006162  = data_3ffe2770
	addx8	a9, a9, a11             # 40006165
	l32i.n	a9, a9, 4               # 40006168
	memw                            # 4000616a
	s32i.n	a9, a10, 0              # 4000616d
	l32i.n	a8, a1, 4               # 4000616f
	addi.n	a8, a8, 1               # 40006171
	s32i.n	a8, a1, 4               # 40006173
	l32i.n	a7, a1, 0               # 40006175
	l32i.n	a6, a1, 4               # 40006177
	bltu	a6, a7, .L40006156      # 40006179
.L4000617c:
	retw.n                          # 4000617c
	.size	fn_40006144, . - fn_40006144
