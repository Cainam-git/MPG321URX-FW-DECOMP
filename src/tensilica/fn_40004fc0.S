# fn_40004fc0: 0x40004fc0-0x4000504e (firmware file offset 0x34fc0-0x3504e), 58 instructions
# Called from: fn_400058dc
# Calls: fn_40004ea0, fn_40004dfc, fn_400099bc
# Text loaded: " OK.\n\r", "\n\rCommand Not Found!\n\r", "TDBG >>"
# Addresses loaded: ro_3ffe08e8
# Other literal values: 0x3ffe4240, 0x3ffe4270

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004fc0, @function
fn_40004fc0:
	entry	a1, 64                  # 40004fc0
	s32i.n	a2, a1, 16              # 40004fc3
	l32i.n	a10, a1, 16             # 40004fc5
	l32r	a11, lit_3ffe1d70       # 40004fc7  = 0x3ffe4240
	l32r	a12, lit_3ffe1d74       # 40004fca  = 0x3ffe4270
	call8	fn_40004ea0             # 40004fcd
	s32i.n	a10, a1, 0              # 40004fd0
	movi.n	a12, 0                  # 40004fd2
	l32i.n	a11, a1, 0              # 40004fd4
	bne	a11, a12, .L40005045    # 40004fd6
	l32r	a10, lit_3ffe1d74       # 40004fd9  = 0x3ffe4270
	call8	fn_40004dfc             # 40004fdc
	movi.n	a13, 0                  # 40004fdf
	bne	a10, a13, .L40004ff9    # 40004fe1
	l32r	a10, lit_3ffe1d6c       # 40004fe4  = ro_3ffe08e8
	call8	fn_400099bc             # 40004fe7
	l32r	a10, lit_3ffe1d74       # 40004fea  = 0x3ffe4270
	call8	fn_400099bc             # 40004fed
	l32r	a10, lit_3ffe1d78       # 40004ff0  = ro_3ffe08ec " OK.\n\r"
	call8	fn_400099bc             # 40004ff3
	j	.L40004fff              # 40004ff6
.L40004ff9:
	l32r	a10, lit_3ffe1d7c       # 40004ff9  = ro_3ffe08f4 "\n\rCommand Not Found!\n\r"
	call8	fn_400099bc             # 40004ffc
.L40004fff:
	movi.n	a15, 0                  # 40004fff
	s32i.n	a15, a1, 4              # 40005001
	l32i.n	a14, a1, 4              # 40005003
	bgei	a14, 4, .L4000503e      # 40005005
.L40005008:
	movi.n	a4, 0                   # 40005008
	s32i.n	a4, a1, 8               # 4000500a
	l32i.n	a3, a1, 8               # 4000500c
	movi.n	a2, 31                  # 4000500e
	blt	a2, a3, .L40005033      # 40005010
.L40005013:
	l32r	a10, lit_3ffe1d74       # 40005013  = 0x3ffe4270
	l32i.n	a11, a1, 4              # 40005016
	slli	a11, a11, 5             # 40005018
	l32i.n	a9, a1, 8               # 4000501b
	add.n	a9, a9, a11             # 4000501d
	add.n	a9, a9, a10             # 4000501f
	movi.n	a8, 0                   # 40005021
	s8i	a8, a9, 0               # 40005023
	l32i.n	a7, a1, 8               # 40005026
	addi.n	a7, a7, 1               # 40005028
	s32i.n	a7, a1, 8               # 4000502a
	l32i.n	a6, a1, 8               # 4000502c
	movi.n	a5, 31                  # 4000502e
	bge	a5, a6, .L40005013      # 40005030
.L40005033:
	l32i.n	a13, a1, 4              # 40005033
	addi.n	a13, a13, 1             # 40005035
	s32i.n	a13, a1, 4              # 40005037
	l32i.n	a12, a1, 4              # 40005039
	blti	a12, 4, .L40005008      # 4000503b
.L4000503e:
	l32r	a15, lit_3ffe1d70       # 4000503e  = 0x3ffe4240
	movi.n	a14, 0                  # 40005041
	s32i.n	a14, a15, 0             # 40005043
.L40005045:
	l32r	a10, lit_3ffe1d80       # 40005045  = ro_3ffe090c "TDBG >>"
	call8	fn_400099bc             # 40005048
	movi.n	a2, 0                   # 4000504b
	retw.n                          # 4000504d
	.size	fn_40004fc0, . - fn_40004fc0
