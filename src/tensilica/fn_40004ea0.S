# fn_40004ea0: 0x40004ea0-0x40004fbe (firmware file offset 0x34ea0-0x34fbe), 123 instructions
# Called from: fn_40004fc0
# Calls: fn_40004758

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004ea0, @function
fn_40004ea0:
	entry	a1, 80                  # 40004ea0
	s32i.n	a2, a1, 32              # 40004ea3
	s32i.n	a3, a1, 36              # 40004ea5
	s32i.n	a4, a1, 40              # 40004ea7
	l32i.n	a10, a1, 32             # 40004ea9
	call8	fn_40004758             # 40004eab
	s32i.n	a10, a1, 0              # 40004eae
	movi.n	a12, 0                  # 40004eb0
	l32i.n	a11, a1, 0              # 40004eb2
	bne	a11, a12, .L40004ebe    # 40004eb4
	movi.n	a13, -1                 # 40004eb7
	s32i.n	a13, a1, 28             # 40004eb9
	j	.L40004fbb              # 40004ebb
.L40004ebe:
	movi.n	a4, -1                  # 40004ebe
	s32i.n	a4, a1, 4               # 40004ec0
	movi.n	a3, 0                   # 40004ec2
	s32i.n	a3, a1, 8               # 40004ec4
	movi.n	a2, 0                   # 40004ec6
	s32i.n	a2, a1, 12              # 40004ec8
	l32i.n	a15, a1, 0              # 40004eca
	l32i.n	a14, a1, 12             # 40004ecc
	blt	a14, a15, .L40004ed4    # 40004ece
	j	.L40004f9a              # 40004ed1
.L40004ed4:
	l32i.n	a9, a1, 12              # 40004ed4
	l32i.n	a8, a1, 32              # 40004ed6
	add.n	a8, a8, a9              # 40004ed8
	l8ui	a8, a8, 0               # 40004eda
	s8i	a8, a1, 16              # 40004edd
	l8ui	a7, a1, 16              # 40004ee0
	s32i.n	a7, a1, 20              # 40004ee3
	movi.n	a6, 0                   # 40004ee5
	l32i.n	a5, a1, 20              # 40004ee7
	beq	a5, a6, .L40004f02      # 40004ee9
	l32i.n	a9, a1, 20              # 40004eec
	beqi	a9, 32, .L40004f02      # 40004eee
	movi.n	a11, 44                 # 40004ef1
	l32i.n	a10, a1, 20             # 40004ef3
	beq	a10, a11, .L40004f02    # 40004ef5
	movi.n	a13, 9                  # 40004ef8
	l32i.n	a12, a1, 20             # 40004efa
	beq	a12, a13, .L40004f02    # 40004efc
	j	.L40004f28              # 40004eff
.L40004f02:
	movi.n	a15, 0                  # 40004f02
	l32i.n	a14, a1, 8              # 40004f04
	beq	a14, a15, .L40004f25    # 40004f06
	movi.n	a5, 0                   # 40004f09
	s32i.n	a5, a1, 8               # 40004f0b
	l32i.n	a4, a1, 36              # 40004f0d
	l32i.n	a3, a1, 36              # 40004f0f
	l32i.n	a3, a3, 0               # 40004f11
	addi.n	a3, a3, 1               # 40004f13
	s32i.n	a3, a4, 0               # 40004f15
	l32i.n	a2, a1, 36              # 40004f17
	l32i.n	a2, a2, 0               # 40004f19
	bltui	a2, 4, .L40004f25       # 40004f1b
	movi.n	a6, 1                   # 40004f1e
	s32i.n	a6, a1, 4               # 40004f20
	j	.L40004f8a              # 40004f22
.L40004f25:
	j	.L40004f8a              # 40004f25
.L40004f28:
	l32i.n	a5, a1, 36              # 40004f28
	l32i.n	a5, a5, 0               # 40004f2a
	slli	a5, a5, 5               # 40004f2c
	movi	a6, 252                 # 40004f2f
	l32i.n	a4, a1, 8               # 40004f32
	and	a4, a4, a6              # 40004f34
	add.n	a4, a4, a5              # 40004f37
	l32i.n	a5, a1, 40              # 40004f39
	addx4	a4, a4, a5              # 40004f3b
	s32i.n	a4, a1, 24              # 40004f3e
	l32i.n	a3, a1, 8               # 40004f40
	extui	a3, a3, 0, 2            # 40004f42
	l32i.n	a14, a1, 24             # 40004f45
	movi.n	a2, -1                  # 40004f47
	movi	a15, 255                # 40004f49
	slli	a3, a3, 3               # 40004f4c
	ssl	a3                      # 40004f4f
	sll	a15, a15                # 40004f52
	xor	a15, a15, a2            # 40004f55
	l32i.n	a13, a1, 24             # 40004f58
	l32i.n	a13, a13, 0             # 40004f5a
	and	a13, a13, a15           # 40004f5c
	s32i.n	a13, a14, 0             # 40004f5f
	l32i.n	a12, a1, 8              # 40004f61
	extui	a12, a12, 0, 2          # 40004f63
	l32i.n	a10, a1, 24             # 40004f66
	l8ui	a11, a1, 16             # 40004f68
	slli	a12, a12, 3             # 40004f6b
	ssl	a12                     # 40004f6e
	sll	a11, a11                # 40004f71
	l32i.n	a9, a1, 24              # 40004f74
	l32i.n	a9, a9, 0               # 40004f76
	or	a9, a9, a11             # 40004f78
	s32i.n	a9, a10, 0              # 40004f7b
	l32i.n	a8, a1, 8               # 40004f7d
	addi.n	a8, a8, 1               # 40004f7f
	s32i.n	a8, a1, 8               # 40004f81
	movi.n	a7, 0                   # 40004f83
	s32i.n	a7, a1, 4               # 40004f85
	j	.L40004f8a              # 40004f87
.L40004f8a:
	l32i.n	a8, a1, 12              # 40004f8a
	addi.n	a8, a8, 1               # 40004f8c
	s32i.n	a8, a1, 12              # 40004f8e
	l32i.n	a7, a1, 0               # 40004f90
	l32i.n	a6, a1, 12              # 40004f92
	bge	a6, a7, .L40004f9a      # 40004f94
	j	.L40004ed4              # 40004f97
.L40004f9a:
	movi.n	a10, 0                  # 40004f9a
	l32i.n	a9, a1, 4               # 40004f9c
	bne	a9, a10, .L40004fae     # 40004f9e
	l32i.n	a12, a1, 36             # 40004fa1
	l32i.n	a11, a1, 36             # 40004fa3
	l32i.n	a11, a11, 0             # 40004fa5
	addi.n	a11, a11, 1             # 40004fa7
	s32i.n	a11, a12, 0             # 40004fa9
	j	.L40004fb7              # 40004fab
.L40004fae:
	l32i.n	a13, a1, 4              # 40004fae
	bnei	a13, 1, .L40004fb7      # 40004fb0
	movi.n	a14, 0                  # 40004fb3
	s32i.n	a14, a1, 4              # 40004fb5
.L40004fb7:
	l32i.n	a15, a1, 4              # 40004fb7
	s32i.n	a15, a1, 28             # 40004fb9
.L40004fbb:
	l32i.n	a2, a1, 28              # 40004fbb
	retw.n                          # 40004fbd
	.size	fn_40004ea0, . - fn_40004ea0
