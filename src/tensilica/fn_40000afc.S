# fn_40000afc: 0x40000afc-0x40000c68 (firmware file offset 0x30afc-0x30c68), 146 instructions
# Address stored in the words at: 0x4000c844
# Addresses loaded: data_3ffe2390, data_3ffe2760
# Other literal values: 0x3ffe2d70, 0x3ffe3d70

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40000afc, @function
fn_40000afc:
	entry	a1, 0x150               # 40000afc
	s32i	a2, a1, 0x120           # 40000aff
	s32i	a3, a1, 0x124           # 40000b02
	movi.n	a9, 0                   # 40000b05
	s32i.n	a9, a1, 0               # 40000b07
	movi.n	a8, 0                   # 40000b09
	s32i.n	a8, a1, 4               # 40000b0b
	movi.n	a7, 0                   # 40000b0d
	s32i.n	a7, a1, 4               # 40000b0f
	l32r	a6, lit_3ffe1a98        # 40000b11  = data_3ffe2390
	l32i.n	a6, a6, 0               # 40000b14
	l32i.n	a5, a1, 4               # 40000b16
	bgeu	a5, a6, .L40000b46      # 40000b18
.L40000b1b:
	l32i.n	a3, a1, 4               # 40000b1b
	addi	a4, a1, 16              # 40000b1d
	addx4	a3, a3, a4              # 40000b20
	movi.n	a2, 0                   # 40000b23
	s32i.n	a2, a3, 0               # 40000b25
	l32i.n	a14, a1, 4              # 40000b27
	addi	a15, a1, 127            # 40000b29
	addi	a15, a15, 17            # 40000b2c
	addx4	a14, a14, a15           # 40000b2f
	movi.n	a13, 0                  # 40000b32
	s32i.n	a13, a14, 0             # 40000b34
	l32i.n	a12, a1, 4              # 40000b36
	addi.n	a12, a12, 1             # 40000b38
	s32i.n	a12, a1, 4              # 40000b3a
	l32r	a11, lit_3ffe1a98       # 40000b3c  = data_3ffe2390
	l32i.n	a11, a11, 0             # 40000b3f
	l32i.n	a10, a1, 4              # 40000b41
	bltu	a10, a11, .L40000b1b    # 40000b43
.L40000b46:
	movi.n	a7, 0                   # 40000b46
	s32i.n	a7, a1, 0               # 40000b48
	l32r	a6, lit_3ffe1a88        # 40000b4a  = data_3ffe2760
	l32i.n	a6, a6, 0               # 40000b4d
	l32i.n	a5, a1, 0               # 40000b4f
	bgeu	a5, a6, .L40000bbe      # 40000b51
.L40000b54:
	l32i.n	a14, a1, 0              # 40000b54
	l32r	a15, lit_3ffe1a8c       # 40000b56  = 0x3ffe2d70
	addx2	a14, a14, a15           # 40000b59
	l16ui	a14, a14, 0             # 40000b5c
	s32i.n	a14, a1, 4              # 40000b5f
	l32i.n	a12, a1, 4              # 40000b61
	addi	a13, a1, 127            # 40000b63
	addi	a13, a13, 17            # 40000b66
	addx4	a12, a12, a13           # 40000b69
	l32i.n	a13, a1, 4              # 40000b6c
	addi	a14, a1, 127            # 40000b6e
	addi	a14, a14, 17            # 40000b71
	addx4	a13, a13, a14           # 40000b74
	l32i.n	a13, a13, 0             # 40000b77
	l32i.n	a11, a1, 0              # 40000b79
	l32i	a14, a1, 0x120          # 40000b7b
	addx2	a11, a11, a14           # 40000b7e
	l16ui	a11, a11, 0             # 40000b81
	add.n	a11, a11, a13           # 40000b84
	s32i.n	a11, a12, 0             # 40000b86
	movi.n	a9, 0                   # 40000b88
	l32i.n	a8, a1, 0               # 40000b8a
	l32i	a10, a1, 0x120          # 40000b8c
	addx2	a8, a8, a10             # 40000b8f
	l16ui	a8, a8, 0               # 40000b92
	bne	a8, a9, .L40000bae      # 40000b95
	l32i.n	a3, a1, 4               # 40000b98
	addi	a4, a1, 16              # 40000b9a
	addx4	a3, a3, a4              # 40000b9d
	l32i.n	a2, a1, 4               # 40000ba0
	addi	a4, a1, 16              # 40000ba2
	addx4	a2, a2, a4              # 40000ba5
	l32i.n	a2, a2, 0               # 40000ba8
	addi.n	a2, a2, 1               # 40000baa
	s32i.n	a2, a3, 0               # 40000bac
.L40000bae:
	l32i.n	a7, a1, 0               # 40000bae
	addi.n	a7, a7, 1               # 40000bb0
	s32i.n	a7, a1, 0               # 40000bb2
	l32r	a6, lit_3ffe1a88        # 40000bb4  = data_3ffe2760
	l32i.n	a6, a6, 0               # 40000bb7
	l32i.n	a5, a1, 0               # 40000bb9
	bltu	a5, a6, .L40000b54      # 40000bbb
.L40000bbe:
	movi.n	a10, 0                  # 40000bbe
	s32i.n	a10, a1, 4              # 40000bc0
	l32r	a9, lit_3ffe1a98        # 40000bc2  = data_3ffe2390
	l32i.n	a9, a9, 0               # 40000bc5
	l32i.n	a8, a1, 4               # 40000bc7
	bltu	a8, a9, .L40000bcf      # 40000bc9
	j	.L40000c67              # 40000bcc
.L40000bcf:
	l32i.n	a12, a1, 4              # 40000bcf
	addi	a13, a1, 16             # 40000bd1
	addx4	a12, a12, a13           # 40000bd4
	l32i.n	a12, a12, 0             # 40000bd7
	l32i.n	a11, a1, 4              # 40000bd9
	l32r	a13, lit_3ffe1a94       # 40000bdb  = 0x3ffe3d70
	addx2	a11, a11, a13           # 40000bde
	l16ui	a11, a11, 0             # 40000be1
	bne	a11, a12, .L40000bef    # 40000be4
	movi.n	a14, 0                  # 40000be7
	s32i	a14, a1, 0x110          # 40000be9
	j	.L40000c1a              # 40000bec
.L40000bef:
	l32i.n	a3, a1, 4               # 40000bef
	addi	a4, a1, 16              # 40000bf1
	addx4	a3, a3, a4              # 40000bf4
	l32i.n	a3, a3, 0               # 40000bf7
	l32i.n	a2, a1, 4               # 40000bf9
	l32r	a4, lit_3ffe1a94        # 40000bfb  = 0x3ffe3d70
	addx2	a2, a2, a4              # 40000bfe
	l16ui	a2, a2, 0               # 40000c01
	sub	a2, a2, a3              # 40000c04
	l32i.n	a15, a1, 4              # 40000c07
	addi	a3, a1, 127             # 40000c09
	addi	a3, a3, 17              # 40000c0c
	addx4	a15, a15, a3            # 40000c0f
	l32i.n	a15, a15, 0             # 40000c12
	quou	a15, a15, a2            # 40000c14
	s32i	a15, a1, 0x110          # 40000c17
.L40000c1a:
	l32i.n	a9, a1, 4               # 40000c1a
	l32i	a10, a1, 0x124          # 40000c1c
	addx4	a9, a9, a10             # 40000c1f
	l32i	a8, a1, 0x110           # 40000c22
	s32i.n	a8, a9, 0               # 40000c25
	l32i.n	a6, a1, 4               # 40000c27
	addi	a7, a1, 127             # 40000c29
	addi	a7, a7, 17              # 40000c2c
	addx4	a6, a6, a7              # 40000c2f
	l32i.n	a6, a6, 0               # 40000c32
	movi.n	a5, 10                  # 40000c34
	bgeu	a5, a6, .L40000c54      # 40000c36
	l32i.n	a12, a1, 4              # 40000c39
	l32i	a13, a1, 0x124          # 40000c3b
	addx4	a12, a12, a13           # 40000c3e
	l32i.n	a12, a12, 0             # 40000c41
	movi.n	a11, 9                  # 40000c43
	bltu	a11, a12, .L40000c54    # 40000c45
	l32i.n	a15, a1, 4              # 40000c48
	l32i	a2, a1, 0x124           # 40000c4a
	addx4	a15, a15, a2            # 40000c4d
	movi.n	a14, 10                 # 40000c50
	s32i.n	a14, a15, 0             # 40000c52
.L40000c54:
	l32i.n	a5, a1, 4               # 40000c54
	addi.n	a5, a5, 1               # 40000c56
	s32i.n	a5, a1, 4               # 40000c58
	l32r	a4, lit_3ffe1a98        # 40000c5a  = data_3ffe2390
	l32i.n	a4, a4, 0               # 40000c5d
	l32i.n	a3, a1, 4               # 40000c5f
	bgeu	a3, a4, .L40000c67      # 40000c61
	j	.L40000bcf              # 40000c64
.L40000c67:
	retw.n                          # 40000c67
	.size	fn_40000afc, . - fn_40000afc
