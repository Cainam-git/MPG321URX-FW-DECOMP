# fn_40000c6c: 0x40000c6c-0x40000de4 (firmware file offset 0x30c6c-0x30de4), 151 instructions
# Address stored in the words at: 0x4000c84c
# Addresses loaded: data_3ffe2390, data_3ffe2760
# Other literal values: 0x3ffe2d70, 0x3ffe3d70

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40000c6c, @function
fn_40000c6c:
	entry	a1, 0x1c0               # 40000c6c
	s32i	a2, a1, 0x190           # 40000c6f
	s32i	a3, a1, 0x194           # 40000c72
	movi.n	a9, 0                   # 40000c75
	s32i.n	a9, a1, 0               # 40000c77
	movi.n	a8, 0                   # 40000c79
	s32i.n	a8, a1, 4               # 40000c7b
	movi.n	a7, 0                   # 40000c7d
	s32i.n	a7, a1, 4               # 40000c7f
	l32r	a6, lit_3ffe1a98        # 40000c81  = data_3ffe2390
	l32i.n	a6, a6, 0               # 40000c84
	l32i.n	a5, a1, 4               # 40000c86
	bgeu	a5, a6, .L40000cc5      # 40000c88
.L40000c8b:
	l32i.n	a6, a1, 4               # 40000c8b
	addi	a7, a1, 16              # 40000c8d
	addx4	a6, a6, a7              # 40000c90
	movi.n	a5, 0                   # 40000c93
	s32i.n	a5, a6, 0               # 40000c95
	l32i.n	a3, a1, 4               # 40000c97
	addi	a4, a1, 127             # 40000c99
	addi	a4, a4, 17              # 40000c9c
	addx4	a3, a3, a4              # 40000c9f
	movi.n	a2, 0                   # 40000ca2
	s32i.n	a2, a3, 0               # 40000ca4
	l32i.n	a14, a1, 4              # 40000ca6
	addmi	a15, a1, 0x100          # 40000ca8
	addi	a15, a15, 16            # 40000cab
	addx4	a14, a14, a15           # 40000cae
	movi.n	a13, 0                  # 40000cb1
	s32i.n	a13, a14, 0             # 40000cb3
	l32i.n	a12, a1, 4              # 40000cb5
	addi.n	a12, a12, 1             # 40000cb7
	s32i.n	a12, a1, 4              # 40000cb9
	l32r	a11, lit_3ffe1a98       # 40000cbb  = data_3ffe2390
	l32i.n	a11, a11, 0             # 40000cbe
	l32i.n	a10, a1, 4              # 40000cc0
	bltu	a10, a11, .L40000c8b    # 40000cc2
.L40000cc5:
	movi.n	a10, 0                  # 40000cc5
	s32i.n	a10, a1, 0              # 40000cc7
	l32r	a9, lit_3ffe1a88        # 40000cc9  = data_3ffe2760
	l32i.n	a9, a9, 0               # 40000ccc
	l32i.n	a8, a1, 0               # 40000cce
	bgeu	a8, a9, .L40000d44      # 40000cd0
.L40000cd3:
	l32i.n	a3, a1, 0               # 40000cd3
	l32r	a4, lit_3ffe1a8c        # 40000cd5  = 0x3ffe2d70
	addx2	a3, a3, a4              # 40000cd8
	l16ui	a3, a3, 0               # 40000cdb
	s32i.n	a3, a1, 4               # 40000cde
	l32i.n	a15, a1, 4              # 40000ce0
	addi	a2, a1, 16              # 40000ce2
	addx4	a15, a15, a2            # 40000ce5
	l32i.n	a2, a1, 4               # 40000ce8
	addi	a3, a1, 16              # 40000cea
	addx4	a2, a2, a3              # 40000ced
	l32i.n	a2, a2, 0               # 40000cf0
	l32i.n	a14, a1, 0              # 40000cf2
	l32i	a3, a1, 0x190           # 40000cf4
	addx2	a14, a14, a3            # 40000cf7
	l16ui	a14, a14, 0             # 40000cfa
	add.n	a14, a14, a2            # 40000cfd
	s32i.n	a14, a15, 0             # 40000cff
	l32i.n	a12, a1, 0              # 40000d01
	l32i	a13, a1, 0x190          # 40000d03
	addx2	a12, a12, a13           # 40000d06
	l16ui	a12, a12, 0             # 40000d09
	l32i.n	a11, a1, 4              # 40000d0c
	addi	a13, a1, 127            # 40000d0e
	addi	a13, a13, 17            # 40000d11
	addx4	a11, a11, a13           # 40000d14
	l32i.n	a11, a11, 0             # 40000d17
	bgeu	a11, a12, .L40000d34    # 40000d19
	l32i.n	a6, a1, 4               # 40000d1c
	addi	a7, a1, 127             # 40000d1e
	addi	a7, a7, 17              # 40000d21
	addx4	a6, a6, a7              # 40000d24
	l32i.n	a5, a1, 0               # 40000d27
	l32i	a7, a1, 0x190           # 40000d29
	addx2	a5, a5, a7              # 40000d2c
	l16ui	a5, a5, 0               # 40000d2f
	s32i.n	a5, a6, 0               # 40000d32
.L40000d34:
	l32i.n	a10, a1, 0              # 40000d34
	addi.n	a10, a10, 1             # 40000d36
	s32i.n	a10, a1, 0              # 40000d38
	l32r	a9, lit_3ffe1a88        # 40000d3a  = data_3ffe2760
	l32i.n	a9, a9, 0               # 40000d3d
	l32i.n	a8, a1, 0               # 40000d3f
	bltu	a8, a9, .L40000cd3      # 40000d41
.L40000d44:
	movi.n	a13, 0                  # 40000d44
	s32i.n	a13, a1, 4              # 40000d46
	l32r	a12, lit_3ffe1a98       # 40000d48  = data_3ffe2390
	l32i.n	a12, a12, 0             # 40000d4b
	l32i.n	a11, a1, 4              # 40000d4d
	bltu	a11, a12, .L40000d55    # 40000d4f
	j	.L40000de3              # 40000d52
.L40000d55:
	l32i.n	a7, a1, 4               # 40000d55
	addmi	a8, a1, 0x100           # 40000d57
	addi	a8, a8, 16              # 40000d5a
	addx4	a7, a7, a8              # 40000d5d
	l32i.n	a8, a1, 4               # 40000d60
	l32r	a9, lit_3ffe1a94        # 40000d62  = 0x3ffe3d70
	addx2	a8, a8, a9              # 40000d65
	l16ui	a8, a8, 0               # 40000d68
	l32i.n	a6, a1, 4               # 40000d6b
	addi	a9, a1, 16              # 40000d6d
	addx4	a6, a6, a9              # 40000d70
	l32i.n	a6, a6, 0               # 40000d73
	quou	a6, a6, a8              # 40000d75
	s32i.n	a6, a7, 0               # 40000d78
	l32i.n	a4, a1, 4               # 40000d7a
	addmi	a5, a1, 0x100           # 40000d7c
	addi	a5, a5, 16              # 40000d7f
	addx4	a4, a4, a5              # 40000d82
	l32i.n	a4, a4, 0               # 40000d85
	l32i.n	a3, a1, 4               # 40000d87
	addi	a5, a1, 127             # 40000d89
	addi	a5, a5, 17              # 40000d8c
	addx4	a3, a3, a5              # 40000d8f
	l32i.n	a3, a3, 0               # 40000d92
	add.n	a3, a3, a4              # 40000d94
	l32i.n	a4, a1, 4               # 40000d96
	l32i	a5, a1, 0x194           # 40000d98
	addx4	a4, a4, a5              # 40000d9b
	slli	a3, a3, 7               # 40000d9e
	srli	a3, a3, 8               # 40000da1
	s32i.n	a3, a4, 0               # 40000da4
	l32i.n	a15, a1, 4              # 40000da6
	addi	a2, a1, 16              # 40000da8
	addx4	a15, a15, a2            # 40000dab
	l32i.n	a15, a15, 0             # 40000dae
	movi.n	a14, 10                 # 40000db0
	bgeu	a14, a15, .L40000dd0    # 40000db2
	l32i.n	a10, a1, 4              # 40000db5
	l32i	a11, a1, 0x194          # 40000db7
	addx4	a10, a10, a11           # 40000dba
	l32i.n	a10, a10, 0             # 40000dbd
	movi.n	a9, 9                   # 40000dbf
	bltu	a9, a10, .L40000dd0     # 40000dc1
	l32i.n	a13, a1, 4              # 40000dc4
	l32i	a14, a1, 0x194          # 40000dc6
	addx4	a13, a13, a14           # 40000dc9
	movi.n	a12, 10                 # 40000dcc
	s32i.n	a12, a13, 0             # 40000dce
.L40000dd0:
	l32i.n	a3, a1, 4               # 40000dd0
	addi.n	a3, a3, 1               # 40000dd2
	s32i.n	a3, a1, 4               # 40000dd4
	l32r	a2, lit_3ffe1a98        # 40000dd6  = data_3ffe2390
	l32i.n	a2, a2, 0               # 40000dd9
	l32i.n	a15, a1, 4              # 40000ddb
	bgeu	a15, a2, .L40000de3     # 40000ddd
	j	.L40000d55              # 40000de0
.L40000de3:
	retw.n                          # 40000de3
	.size	fn_40000c6c, . - fn_40000c6c
