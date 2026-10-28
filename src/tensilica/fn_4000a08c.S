# fn_4000a08c: 0x4000a08c-0x4000a109 (firmware file offset 0x3a08c-0x3a109), 50 instructions
# Called from: fn_4000498c
# Text loaded: "0123456789ABCDEF\nGot power down command..\n"
# Other literal values: 0xe00a0014, 0x000ffffe, 0xe00a0000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a08c, @function
fn_4000a08c:
	entry	a1, 64                  # 4000a08c
	extui	a2, a2, 0, 8            # 4000a08f
	s8i	a2, a1, 16              # 4000a092
	movi.n	a5, 0                   # 4000a095
	s32i.n	a5, a1, 0               # 4000a097
	l32i.n	a4, a1, 0               # 4000a099
	bgei	a4, 2, .L4000a108       # 4000a09b
.L4000a09e:
	l32i.n	a10, a1, 0              # 4000a09e
	slli	a10, a10, 2             # 4000a0a0
	movi.n	a9, 4                   # 4000a0a3
	sub	a9, a9, a10             # 4000a0a5
	s32i.n	a9, a1, 4               # 4000a0a8
	l32r	a9, lit_3ffe2324        # 4000a0aa  = ro_3ffe19b0 "0123456789ABCDEF\nGot power down command..\n"
	l8ui	a8, a1, 16              # 4000a0ad
	l32i.n	a10, a1, 4              # 4000a0b0
	ssr	a10                     # 4000a0b2
	sra	a8, a8                  # 4000a0b5
	extui	a8, a8, 0, 4            # 4000a0b8
	add.n	a8, a8, a9              # 4000a0bb
	l8ui	a8, a8, 0               # 4000a0bd
	s8i	a8, a1, 8               # 4000a0c0
	movi.n	a7, 0                   # 4000a0c3
	s32i.n	a7, a1, 12              # 4000a0c5
	l32r	a6, lit_3ffe2318        # 4000a0c7  = 0xe00a0014
	memw                            # 4000a0ca
	l32i.n	a6, a6, 0               # 4000a0cd
	bbsi	a6, 5, .L4000a0f2       # 4000a0cf
.L4000a0d2:
	l32i.n	a13, a1, 12             # 4000a0d2
	addi.n	a13, a13, 1             # 4000a0d4
	s32i.n	a13, a1, 12             # 4000a0d6
	l32i.n	a12, a1, 12             # 4000a0d8
	l32r	a11, lit_3ffe2320       # 4000a0da  = 0x000ffffe
	bltu	a11, a12, .L4000a0f2    # 4000a0dd
	movi.n	a15, 0                  # 4000a0e0
	movi.n	a2, 32                  # 4000a0e2
	l32r	a14, lit_3ffe2318       # 4000a0e4  = 0xe00a0014
	memw                            # 4000a0e7
	l32i.n	a14, a14, 0             # 4000a0ea
	and	a14, a14, a2            # 4000a0ec
	beq	a14, a15, .L4000a0d2    # 4000a0ef
.L4000a0f2:
	l32r	a4, lit_3ffe2300        # 4000a0f2  = 0xe00a0000
	l8ui	a3, a1, 8               # 4000a0f5
	memw                            # 4000a0f8
	s32i.n	a3, a4, 0               # 4000a0fb
	l32i.n	a2, a1, 0               # 4000a0fd
	addi.n	a2, a2, 1               # 4000a0ff
	s32i.n	a2, a1, 0               # 4000a101
	l32i.n	a15, a1, 0              # 4000a103
	blti	a15, 2, .L4000a09e      # 4000a105
.L4000a108:
	retw.n                          # 4000a108
	.size	fn_4000a08c, . - fn_4000a08c
