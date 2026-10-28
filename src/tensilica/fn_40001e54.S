# fn_40001e54: 0x40001e54-0x40001f92 (firmware file offset 0x31e54-0x31f92), 136 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Other literal values: 0xe00831c0, 0xe00831e0, 0xe0091074

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001e54, @function
fn_40001e54:
	entry	a1, 64                  # 40001e54
	movi.n	a7, 0                   # 40001e57
	s32i.n	a7, a1, 0               # 40001e59
	movi.n	a6, 0                   # 40001e5b
	s32i.n	a6, a1, 4               # 40001e5d
	movi.n	a5, 0                   # 40001e5f
	s32i.n	a5, a1, 8               # 40001e61
	movi.n	a4, 0                   # 40001e63
	s32i.n	a4, a1, 12              # 40001e65
	movi.n	a3, 0                   # 40001e67
	s32i.n	a3, a1, 0               # 40001e69
	l32i.n	a2, a1, 0               # 40001e6b
	bgeui	a2, 8, .L40001ee2       # 40001e6d
.L40001e70:
	l32i.n	a11, a1, 0              # 40001e70
	slli	a11, a11, 2             # 40001e72
	memw                            # 40001e75
	l32r	a12, lit_3ffe1b98       # 40001e78  = 0xe00831c0
	add.n	a11, a11, a12           # 40001e7b
	memw                            # 40001e7d
	l32i.n	a11, a11, 0             # 40001e80
	extui	a11, a11, 0, 12         # 40001e82
	s32i.n	a11, a1, 16             # 40001e85
	l32i.n	a10, a1, 0              # 40001e87
	slli	a10, a10, 2             # 40001e89
	memw                            # 40001e8c
	l32r	a11, lit_3ffe1b98       # 40001e8f  = 0xe00831c0
	add.n	a10, a10, a11           # 40001e92
	memw                            # 40001e94
	l32i.n	a10, a10, 0             # 40001e97
	extui	a10, a10, 16, 16        # 40001e99
	extui	a10, a10, 0, 12         # 40001e9c
	s32i.n	a10, a1, 20             # 40001e9f
	l32i.n	a9, a1, 16              # 40001ea1
	l32i.n	a8, a1, 20              # 40001ea3
	bgeu	a8, a9, .L40001eba      # 40001ea5
	l32i.n	a14, a1, 20             # 40001ea8
	l32i.n	a13, a1, 16             # 40001eaa
	sub	a13, a13, a14           # 40001eac
	movi.n	a12, 16                 # 40001eaf
	bgeu	a12, a13, .L40001eba    # 40001eb1
	l32i.n	a15, a1, 4              # 40001eb4
	addi.n	a15, a15, 1             # 40001eb6
	s32i.n	a15, a1, 4              # 40001eb8
.L40001eba:
	l32i.n	a3, a1, 12              # 40001eba
	l32i.n	a2, a1, 16              # 40001ebc
	bgeu	a2, a3, .L40001ed3      # 40001ebe
	l32i.n	a6, a1, 16              # 40001ec1
	l32i.n	a5, a1, 12              # 40001ec3
	sub	a5, a5, a6              # 40001ec5
	movi.n	a4, 16                  # 40001ec8
	bgeu	a4, a5, .L40001ed3      # 40001eca
	l32i.n	a7, a1, 4               # 40001ecd
	addi.n	a7, a7, 1               # 40001ecf
	s32i.n	a7, a1, 4               # 40001ed1
.L40001ed3:
	l32i.n	a10, a1, 20             # 40001ed3
	s32i.n	a10, a1, 12             # 40001ed5
	l32i.n	a9, a1, 0               # 40001ed7
	addi.n	a9, a9, 1               # 40001ed9
	s32i.n	a9, a1, 0               # 40001edb
	l32i.n	a8, a1, 0               # 40001edd
	bltui	a8, 8, .L40001e70       # 40001edf
.L40001ee2:
	movi.n	a12, 0                  # 40001ee2
	s32i.n	a12, a1, 0              # 40001ee4
	l32i.n	a11, a1, 0              # 40001ee6
	bgeui	a11, 8, .L40001f5d      # 40001ee8
.L40001eeb:
	l32i.n	a2, a1, 0               # 40001eeb
	slli	a2, a2, 2               # 40001eed
	memw                            # 40001ef0
	l32r	a3, lit_3ffe1b9c        # 40001ef3  = 0xe00831e0
	add.n	a2, a2, a3              # 40001ef6
	memw                            # 40001ef8
	l32i.n	a2, a2, 0               # 40001efb
	extui	a2, a2, 0, 12           # 40001efd
	s32i.n	a2, a1, 16              # 40001f00
	l32i.n	a15, a1, 0              # 40001f02
	slli	a15, a15, 2             # 40001f04
	memw                            # 40001f07
	l32r	a2, lit_3ffe1b9c        # 40001f0a  = 0xe00831e0
	add.n	a15, a15, a2            # 40001f0d
	memw                            # 40001f0f
	l32i.n	a15, a15, 0             # 40001f12
	extui	a15, a15, 16, 16        # 40001f14
	extui	a15, a15, 0, 12         # 40001f17
	s32i.n	a15, a1, 20             # 40001f1a
	l32i.n	a14, a1, 20             # 40001f1c
	l32i.n	a13, a1, 16             # 40001f1e
	bgeu	a13, a14, .L40001f35    # 40001f20
	l32i.n	a5, a1, 16              # 40001f23
	l32i.n	a4, a1, 20              # 40001f25
	sub	a4, a4, a5              # 40001f27
	movi.n	a3, 16                  # 40001f2a
	bgeu	a3, a4, .L40001f35      # 40001f2c
	l32i.n	a6, a1, 4               # 40001f2f
	addi.n	a6, a6, 1               # 40001f31
	s32i.n	a6, a1, 4               # 40001f33
.L40001f35:
	l32i.n	a8, a1, 16              # 40001f35
	l32i.n	a7, a1, 12              # 40001f37
	bgeu	a7, a8, .L40001f4e      # 40001f39
	l32i.n	a11, a1, 12             # 40001f3c
	l32i.n	a10, a1, 16             # 40001f3e
	sub	a10, a10, a11           # 40001f40
	movi.n	a9, 16                  # 40001f43
	bgeu	a9, a10, .L40001f4e     # 40001f45
	l32i.n	a12, a1, 4              # 40001f48
	addi.n	a12, a12, 1             # 40001f4a
	s32i.n	a12, a1, 4              # 40001f4c
.L40001f4e:
	l32i.n	a15, a1, 20             # 40001f4e
	s32i.n	a15, a1, 12             # 40001f50
	l32i.n	a14, a1, 0              # 40001f52
	addi.n	a14, a14, 1             # 40001f54
	s32i.n	a14, a1, 0              # 40001f56
	l32i.n	a13, a1, 0              # 40001f58
	bltui	a13, 8, .L40001eeb      # 40001f5a
.L40001f5d:
	l32i.n	a2, a1, 4               # 40001f5d
	bgeui	a2, 5, .L40001f66       # 40001f5f
	movi.n	a3, 1                   # 40001f62
	s32i.n	a3, a1, 8               # 40001f64
.L40001f66:
	movi.n	a5, 0                   # 40001f66
	l32i.n	a4, a1, 8               # 40001f68
	beq	a4, a5, .L40001f7e      # 40001f6a
	l32r	a8, lit_3ffe1ba0        # 40001f6d  = 0xe0091074
	movi.n	a7, 1                   # 40001f70
	memw                            # 40001f72
	s32i.n	a7, a8, 0               # 40001f75
	movi.n	a6, 1                   # 40001f77
	s32i.n	a6, a1, 24              # 40001f79
	j	.L40001f8f              # 40001f7b
.L40001f7e:
	l32r	a11, lit_3ffe1ba0       # 40001f7e  = 0xe0091074
	movi.n	a10, 0                  # 40001f81
	memw                            # 40001f83
	s32i.n	a10, a11, 0             # 40001f86
	movi.n	a9, 0                   # 40001f88
	s32i.n	a9, a1, 24              # 40001f8a
	j	.L40001f8f              # 40001f8c
.L40001f8f:
	l32i.n	a2, a1, 24              # 40001f8f
	retw.n                          # 40001f91
	.size	fn_40001e54, . - fn_40001e54
