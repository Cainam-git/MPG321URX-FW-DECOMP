# fn_40007e68: 0x40007e68-0x4000800f (firmware file offset 0x37e68-0x3800f), 175 instructions
# Address stored in the words at: 0x4000c798
# Calls: fn_4000aa64, fn_40007d40, fn_40006be8
# Addresses loaded: ro_3ffe0f00, data_3ffe23ac
# Other literal values: 0x3ffe2d34, 0x3ffe4490, 0xe0091038, 0x3ffe2d3c, 0x00000ffc

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40007e68, @function
fn_40007e68:
	entry	a1, 0x450               # 40007e68
	movi.n	a7, 32                  # 40007e6b
	add.n	a7, a1, a7              # 40007e6d
	movi.n	a2, 0                   # 40007e6f
	s32i.n	a2, a1, 4               # 40007e71
	mov.n	a10, a7                 # 40007e73
	l32r	a11, lit_3ffe2150       # 40007e75  = ro_3ffe0f00
	movi	a12, 0x404              # 40007e78
	call8	fn_4000aa64             # 40007e7b
	movi.n	a5, 0                   # 40007e7e
	s32i.n	a5, a1, 8               # 40007e80
	movi.n	a4, 0                   # 40007e82
	s32i.n	a4, a1, 12              # 40007e84
	movi.n	a3, 0                   # 40007e86
	s32i.n	a3, a1, 16              # 40007e88
	call8	fn_40007d40             # 40007e8a
	s32i.n	a10, a1, 8              # 40007e8d
	l32r	a6, lit_3ffe20f8        # 40007e8f  = 0x3ffe2d34
	l32i.n	a6, a6, 0               # 40007e92
	beqi	a6, 4, .L40007eaa       # 40007e94
	l32r	a8, lit_3ffe20f8        # 40007e97  = 0x3ffe2d34
	l32i.n	a8, a8, 0               # 40007e9a
	beqi	a8, 1, .L40007eaa       # 40007e9c
	l32r	a9, lit_3ffe20f8        # 40007e9f  = 0x3ffe2d34
	l32i.n	a9, a9, 0               # 40007ea2
	beqi	a9, 2, .L40007eaa       # 40007ea4
	j	.L40007f9a              # 40007ea7
.L40007eaa:
	movi.n	a12, 0                  # 40007eaa
	s32i.n	a12, a1, 4              # 40007eac
	l32i.n	a11, a1, 4              # 40007eae
	movi.n	a10, 0                  # 40007eb0
	bgeu	a10, a11, .L40007eb8    # 40007eb2
	j	.L40007f97              # 40007eb5
.L40007eb8:
	movi.n	a15, 0                  # 40007eb8
	s32i.n	a15, a1, 20             # 40007eba
	l32i.n	a14, a1, 20             # 40007ebc
	movi	a13, 255                # 40007ebe
	bgeu	a13, a14, .L40007ec7    # 40007ec1
	j	.L40007f7e              # 40007ec4
.L40007ec7:
	l32i.n	a12, a1, 4              # 40007ec7
	slli	a12, a12, 8             # 40007ec9
	l32i.n	a11, a1, 4              # 40007ecc
	add.n	a11, a11, a12           # 40007ece
	l32i.n	a10, a1, 20             # 40007ed0
	add.n	a10, a10, a11           # 40007ed2
	slli	a10, a10, 1             # 40007ed4
	s32i.n	a10, a1, 24             # 40007ed7
	movi	a8, 0x3ff               # 40007ed9
	l32r	a9, lit_3ffe2148        # 40007edc  = data_3ffe23ac
	l32i.n	a9, a9, 0               # 40007edf
	l32i.n	a6, a1, 24              # 40007ee1
	l32r	a10, lit_3ffe1b88       # 40007ee3  = 0x3ffe4490
	addx2	a6, a6, a10             # 40007ee6
	l16ui	a6, a6, 0               # 40007ee9
	mull	a6, a6, a9              # 40007eec
	quou	a6, a6, a8              # 40007eef
	s32i.n	a6, a1, 12              # 40007ef2
	movi	a4, 0x3ff               # 40007ef4
	l32r	a5, lit_3ffe2148        # 40007ef7  = data_3ffe23ac
	l32i.n	a5, a5, 0               # 40007efa
	l32i.n	a3, a1, 24              # 40007efc
	l32r	a6, lit_3ffe1b88        # 40007efe  = 0x3ffe4490
	addx2	a3, a3, a6              # 40007f01
	addi.n	a3, a3, 2               # 40007f04
	l16ui	a3, a3, 0               # 40007f06
	mull	a3, a3, a5              # 40007f09
	quou	a3, a3, a4              # 40007f0c
	s32i.n	a3, a1, 16              # 40007f0f
	movi.n	a3, 0                   # 40007f11
	l32r	a2, lit_3ffe1bd8        # 40007f13  = 0xe0091038
	memw                            # 40007f16
	l32i.n	a2, a2, 0               # 40007f19
	beq	a2, a3, .L40007f38      # 40007f1b
	l32i.n	a14, a1, 12             # 40007f1e
	movi	a13, 99                 # 40007f20
	bltu	a13, a14, .L40007f2b    # 40007f23
	movi	a15, 100                # 40007f26
	s32i.n	a15, a1, 12             # 40007f29
.L40007f2b:
	l32i.n	a3, a1, 16              # 40007f2b
	movi	a2, 99                  # 40007f2d
	bltu	a2, a3, .L40007f38      # 40007f30
	movi	a4, 100                 # 40007f33
	s32i.n	a4, a1, 16              # 40007f36
.L40007f38:
	l32r	a6, lit_3ffe2154        # 40007f38  = 0x3ffe2d3c
	l32i.n	a6, a6, 0               # 40007f3b
	l32i.n	a5, a1, 12              # 40007f3d
	bgeu	a5, a6, .L40007f49      # 40007f3f
	l32r	a8, lit_3ffe2154        # 40007f42  = 0x3ffe2d3c
	l32i.n	a8, a8, 0               # 40007f45
	s32i.n	a8, a1, 12              # 40007f47
.L40007f49:
	l32r	a10, lit_3ffe2154       # 40007f49  = 0x3ffe2d3c
	l32i.n	a10, a10, 0             # 40007f4c
	l32i.n	a9, a1, 16              # 40007f4e
	bgeu	a9, a10, .L40007f5a     # 40007f50
	l32r	a11, lit_3ffe2154       # 40007f53  = 0x3ffe2d3c
	l32i.n	a11, a11, 0             # 40007f56
	s32i.n	a11, a1, 16             # 40007f58
.L40007f5a:
	l32i.n	a2, a1, 20              # 40007f5a
	mov.n	a3, a7                  # 40007f5c
	addx4	a2, a2, a3              # 40007f5e
	l32i.n	a3, a1, 16              # 40007f61
	slli	a3, a3, 16              # 40007f63
	l32i.n	a15, a1, 12             # 40007f66
	or	a15, a15, a3            # 40007f68
	s32i.n	a15, a2, 0              # 40007f6b
	l32i.n	a14, a1, 20             # 40007f6d
	addi.n	a14, a14, 1             # 40007f6f
	s32i.n	a14, a1, 20             # 40007f71
	l32i.n	a13, a1, 20             # 40007f73
	movi	a12, 255                # 40007f75
	bltu	a12, a13, .L40007f7e    # 40007f78
	j	.L40007ec7              # 40007f7b
.L40007f7e:
	addmi	a9, a7, 0x400           # 40007f7e
	mov.n	a9, a9                  # 40007f81
	l32i.n	a8, a1, 8               # 40007f83
	s32i.n	a8, a9, 0               # 40007f85
	l32i.n	a6, a1, 4               # 40007f87
	addi.n	a6, a6, 1               # 40007f89
	s32i.n	a6, a1, 4               # 40007f8b
	l32i.n	a5, a1, 4               # 40007f8d
	movi.n	a4, 0                   # 40007f8f
	bltu	a4, a5, .L40007f97      # 40007f91
	j	.L40007eb8              # 40007f94
.L40007f97:
	j	.L40008004              # 40007f97
.L40007f9a:
	movi.n	a12, 0                  # 40007f9a
	s32i.n	a12, a1, 4              # 40007f9c
	l32i.n	a11, a1, 4              # 40007f9e
	movi.n	a10, 0                  # 40007fa0
	bltu	a10, a11, .L40008004    # 40007fa2
.L40007fa5:
	movi.n	a15, 0                  # 40007fa5
	s32i.n	a15, a1, 20             # 40007fa7
	l32i.n	a14, a1, 20             # 40007fa9
	movi	a13, 255                # 40007fab
	bltu	a13, a14, .L40007fee    # 40007fae
.L40007fb1:
	l32i.n	a13, a1, 4              # 40007fb1
	slli	a13, a13, 8             # 40007fb3
	l32i.n	a12, a1, 4              # 40007fb6
	add.n	a12, a12, a13           # 40007fb8
	l32i.n	a11, a1, 20             # 40007fba
	add.n	a11, a11, a12           # 40007fbc
	slli	a11, a11, 1             # 40007fbe
	s32i.n	a11, a1, 24             # 40007fc1
	l32r	a10, lit_3ffe1bdc       # 40007fc3  = 0x00000ffc
	s32i.n	a10, a1, 12             # 40007fc6
	l32r	a9, lit_3ffe1bdc        # 40007fc8  = 0x00000ffc
	s32i.n	a9, a1, 16              # 40007fcb
	l32i.n	a6, a1, 20              # 40007fcd
	mov.n	a8, a7                  # 40007fcf
	addx4	a6, a6, a8              # 40007fd1
	l32i.n	a8, a1, 16              # 40007fd4
	slli	a8, a8, 16              # 40007fd6
	l32i.n	a5, a1, 12              # 40007fd9
	or	a5, a5, a8              # 40007fdb
	s32i.n	a5, a6, 0               # 40007fde
	l32i.n	a4, a1, 20              # 40007fe0
	addi.n	a4, a4, 1               # 40007fe2
	s32i.n	a4, a1, 20              # 40007fe4
	l32i.n	a3, a1, 20              # 40007fe6
	movi	a2, 255                 # 40007fe8
	bgeu	a2, a3, .L40007fb1      # 40007feb
.L40007fee:
	addmi	a4, a7, 0x400           # 40007fee
	mov.n	a4, a4                  # 40007ff1
	l32i.n	a3, a1, 8               # 40007ff3
	s32i.n	a3, a4, 0               # 40007ff5
	l32i.n	a2, a1, 4               # 40007ff7
	addi.n	a2, a2, 1               # 40007ff9
	s32i.n	a2, a1, 4               # 40007ffb
	l32i.n	a15, a1, 4              # 40007ffd
	movi.n	a14, 0                  # 40007fff
	bgeu	a14, a15, .L40007fa5    # 40008001
.L40008004:
	movi	a10, 0x101              # 40008004
	mov.n	a11, a7                 # 40008007
	movi.n	a12, 1                  # 40008009
	call8	fn_40006be8             # 4000800b
	retw.n                          # 4000800e
	.size	fn_40007e68, . - fn_40007e68
