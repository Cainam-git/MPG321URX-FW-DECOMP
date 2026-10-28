# fn_40001f94: 0x40001f94-0x400020cd (firmware file offset 0x31f94-0x320cd), 135 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0xe0091040, 0xe0080700, 0x00038400

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001f94, @function
fn_40001f94:
	entry	a1, 80                  # 40001f94
	s32i.n	a2, a1, 32              # 40001f97
	s32i.n	a3, a1, 36              # 40001f99
	movi.n	a7, 0                   # 40001f9b
	s32i.n	a7, a1, 0               # 40001f9d
	l32i.n	a6, a1, 36              # 40001f9f
	l32i.n	a5, a1, 0               # 40001fa1
	bgeu	a5, a6, .L40002009      # 40001fa3
.L40001fa6:
	l32i.n	a9, a1, 0               # 40001fa6
	l32i.n	a10, a1, 32             # 40001fa8
	addx4	a9, a9, a10             # 40001faa
	l32i.n	a9, a9, 0               # 40001fad
	movi	a8, 0x578               # 40001faf
	bgeu	a8, a9, .L40001fd4      # 40001fb2
	movi	a11, 0x190              # 40001fb5
	movi	a13, 0xfffffa88         # 40001fb8
	l32i.n	a12, a1, 0              # 40001fbb
	l32i.n	a14, a1, 32             # 40001fbd
	addx4	a12, a12, a14           # 40001fbf
	l32i.n	a12, a12, 0             # 40001fc2
	add.n	a12, a12, a13           # 40001fc4
	movi.n	a13, 1                  # 40001fc6
	s32i.n	a13, a1, 16             # 40001fc8
	bltu	a11, a12, .L40001fd1    # 40001fca
	movi.n	a15, 0                  # 40001fcd
	s32i.n	a15, a1, 16             # 40001fcf
.L40001fd1:
	j	.L40001ff1              # 40001fd1
.L40001fd4:
	movi	a2, 0x190               # 40001fd4
	l32i.n	a4, a1, 0               # 40001fd7
	l32i.n	a5, a1, 32              # 40001fd9
	addx4	a4, a4, a5              # 40001fdb
	l32i.n	a4, a4, 0               # 40001fde
	movi	a3, 0x578               # 40001fe0
	sub	a3, a3, a4              # 40001fe3
	movi.n	a4, 1                   # 40001fe6
	s32i.n	a4, a1, 16              # 40001fe8
	bltu	a2, a3, .L40001ff1      # 40001fea
	movi.n	a6, 0                   # 40001fed
	s32i.n	a6, a1, 16              # 40001fef
.L40001ff1:
	l32i.n	a7, a1, 16              # 40001ff1
	beqz.n	a7, .L40001ffc          # 40001ff3
	movi.n	a8, 0                   # 40001ff5
	s32i.n	a8, a1, 20              # 40001ff7
	j	.L400020ca              # 40001ff9
.L40001ffc:
	l32i.n	a11, a1, 0              # 40001ffc
	addi.n	a11, a11, 1             # 40001ffe
	s32i.n	a11, a1, 0              # 40002000
	l32i.n	a10, a1, 36             # 40002002
	l32i.n	a9, a1, 0               # 40002004
	bltu	a9, a10, .L40001fa6     # 40002006
.L40002009:
	l32r	a3, lit_3ffe1b80        # 40002009  = 0xe0091040
	memw                            # 4000200c
	l32i.n	a3, a3, 0               # 4000200f
	s32i.n	a3, a1, 4               # 40002011
	l32i.n	a2, a1, 4               # 40002013
	s32i.n	a2, a1, 8               # 40002015
	l32i.n	a15, a1, 8              # 40002017
	extui	a15, a15, 0, 16         # 40002019
	s32i.n	a15, a1, 8              # 4000201c
	l32i.n	a14, a1, 4              # 4000201e
	extui	a14, a14, 16, 16        # 40002020
	s32i.n	a14, a1, 4              # 40002023
	l32i.n	a13, a1, 4              # 40002025
	movi.n	a12, 85                 # 40002027
	bgeu	a12, a13, .L40002041    # 40002029
	movi.n	a4, 8                   # 4000202c
	l32i.n	a5, a1, 4               # 4000202e
	addi	a5, a5, -85             # 40002030
	movi.n	a6, 1                   # 40002033
	s32i.n	a6, a1, 24              # 40002035
	bltu	a4, a5, .L4000203e      # 40002037
	movi.n	a6, 0                   # 4000203a
	s32i.n	a6, a1, 24              # 4000203c
.L4000203e:
	j	.L40002055              # 4000203e
.L40002041:
	movi.n	a7, 8                   # 40002041
	l32i.n	a9, a1, 4               # 40002043
	movi.n	a8, 85                  # 40002045
	sub	a8, a8, a9              # 40002047
	movi.n	a9, 1                   # 4000204a
	s32i.n	a9, a1, 24              # 4000204c
	bltu	a7, a8, .L40002055      # 4000204e
	movi.n	a10, 0                  # 40002051
	s32i.n	a10, a1, 24             # 40002053
.L40002055:
	l32i.n	a11, a1, 24             # 40002055
	beqz.n	a11, .L40002060         # 40002057
	movi.n	a12, 0                  # 40002059
	s32i.n	a12, a1, 20             # 4000205b
	j	.L400020ca              # 4000205d
.L40002060:
	l32i.n	a14, a1, 8              # 40002060
	movi.n	a13, 37                 # 40002062
	bgeu	a13, a14, .L4000207c    # 40002064
	movi.n	a15, 8                  # 40002067
	l32i.n	a2, a1, 8               # 40002069
	addi	a2, a2, -37             # 4000206b
	movi.n	a3, 1                   # 4000206e
	s32i.n	a3, a1, 28              # 40002070
	bltu	a15, a2, .L40002079     # 40002072
	movi.n	a3, 0                   # 40002075
	s32i.n	a3, a1, 28              # 40002077
.L40002079:
	j	.L40002090              # 40002079
.L4000207c:
	movi.n	a4, 8                   # 4000207c
	l32i.n	a6, a1, 8               # 4000207e
	movi.n	a5, 37                  # 40002080
	sub	a5, a5, a6              # 40002082
	movi.n	a6, 1                   # 40002085
	s32i.n	a6, a1, 28              # 40002087
	bltu	a4, a5, .L40002090      # 40002089
	movi.n	a7, 0                   # 4000208c
	s32i.n	a7, a1, 28              # 4000208e
.L40002090:
	l32i.n	a8, a1, 28              # 40002090
	beqz.n	a8, .L4000209b          # 40002092
	movi.n	a9, 0                   # 40002094
	s32i.n	a9, a1, 20              # 40002096
	j	.L400020ca              # 40002098
.L4000209b:
	l32r	a14, lit_3ffe1b78       # 4000209b  = 0xe0080700
	memw                            # 4000209e
	l32i.n	a14, a14, 0             # 400020a1
	s32i.n	a14, a1, 12             # 400020a3
	l32r	a12, lit_3ffe1b84       # 400020a5  = 0x00038400
	movi	a13, 0x3e8              # 400020a8
	l32i.n	a11, a1, 12             # 400020ab
	mull	a11, a11, a13           # 400020ad
	quou	a11, a11, a12           # 400020b0
	s32i.n	a11, a1, 12             # 400020b3
	movi.n	a11, 30                 # 400020b5
	l32i.n	a10, a1, 12             # 400020b7
	addi	a10, a10, -48           # 400020b9
	bltu	a10, a11, .L400020c6    # 400020bc
	movi.n	a15, 0                  # 400020bf
	s32i.n	a15, a1, 20             # 400020c1
	j	.L400020ca              # 400020c3
.L400020c6:
	movi.n	a2, 1                   # 400020c6
	s32i.n	a2, a1, 20              # 400020c8
.L400020ca:
	l32i.n	a2, a1, 20              # 400020ca
	retw.n                          # 400020cc
	.size	fn_40001f94, . - fn_40001f94
