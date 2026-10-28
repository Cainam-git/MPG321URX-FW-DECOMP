# fn_40009fc8: 0x40009fc8-0x4000a00c (firmware file offset 0x39fc8-0x3a00c), 27 instructions
# Called from: fn_4000498c, fn_400058dc
# Other literal values: 0xe00a0014, 0x000ffffe, 0xe00a0000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40009fc8, @function
fn_40009fc8:
	entry	a1, 64                  # 40009fc8
	extui	a2, a2, 0, 8            # 40009fcb
	s8i	a2, a1, 16              # 40009fce
	movi.n	a5, 0                   # 40009fd1
	s32i.n	a5, a1, 0               # 40009fd3
	l32r	a4, lit_3ffe2318        # 40009fd5  = 0xe00a0014
	memw                            # 40009fd8
	l32i.n	a4, a4, 0               # 40009fdb
	bbsi	a4, 5, .L4000a000       # 40009fdd
.L40009fe0:
	l32i.n	a8, a1, 0               # 40009fe0
	addi.n	a8, a8, 1               # 40009fe2
	s32i.n	a8, a1, 0               # 40009fe4
	l32i.n	a7, a1, 0               # 40009fe6
	l32r	a6, lit_3ffe2320        # 40009fe8  = 0x000ffffe
	bltu	a6, a7, .L4000a000      # 40009feb
	movi.n	a10, 0                  # 40009fee
	movi.n	a11, 32                 # 40009ff0
	l32r	a9, lit_3ffe2318        # 40009ff2  = 0xe00a0014
	memw                            # 40009ff5
	l32i.n	a9, a9, 0               # 40009ff8
	and	a9, a9, a11             # 40009ffa
	beq	a9, a10, .L40009fe0     # 40009ffd
.L4000a000:
	l32r	a11, lit_3ffe2300       # 4000a000  = 0xe00a0000
	l8ui	a10, a1, 16             # 4000a003
	memw                            # 4000a006
	s32i.n	a10, a11, 0             # 4000a009
	retw.n                          # 4000a00b
	.size	fn_40009fc8, . - fn_40009fc8
