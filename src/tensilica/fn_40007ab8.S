# fn_40007ab8: 0x40007ab8-0x40007c4c (firmware file offset 0x37ab8-0x37c4c), 162 instructions
# Address stored in the words at: 0x4000c794
# Calls: fn_400078a0, fn_4000770c, fn_4000713c, fn_40007348, fn_40007760
# Addresses loaded: data_3ffe2a20, data_3ffe23a4
# Other literal values: 0x3ffe54a0, 0x3ffe2d30, 0x3ffe2d34, 0x3ffe5590, 0x3ffe5500, 0x3ffe3eb0, 0x3ffe54c0,
#                       0x3ffe3ef0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40007ab8, @function
fn_40007ab8:
	entry	a1, 48                  # 40007ab8
	movi.n	a4, 0                   # 40007abb
	s32i.n	a4, a1, 0               # 40007abd
	movi.n	a3, 0                   # 40007abf
	s32i.n	a3, a1, 4               # 40007ac1
	movi.n	a3, 0                   # 40007ac3
	l32r	a2, lit_3ffe20ac        # 40007ac5  = 0x3ffe54a0
	l32i	a2, a2, 236             # 40007ac8
	bne	a2, a3, .L40007ad1      # 40007acb
	j	.L40007c4b              # 40007ace
.L40007ad1:
	l32r	a6, lit_3ffe20e0        # 40007ad1  = 0x3ffe2d30
	l32i.n	a6, a6, 0               # 40007ad4
	l32r	a5, lit_3ffe20f4        # 40007ad6  = data_3ffe2a20
	l32i.n	a5, a5, 0               # 40007ad9
	beq	a5, a6, .L40007af0      # 40007adb
	l32r	a10, lit_3ffe20e0       # 40007ade  = 0x3ffe2d30
	l32i.n	a10, a10, 0             # 40007ae1
	call8	fn_400078a0             # 40007ae3
	l32r	a12, lit_3ffe20f4       # 40007ae6  = data_3ffe2a20
	l32r	a11, lit_3ffe20e0       # 40007ae9  = 0x3ffe2d30
	l32i.n	a11, a11, 0             # 40007aec
	s32i.n	a11, a12, 0             # 40007aee
.L40007af0:
	l32r	a13, lit_3ffe20f8       # 40007af0  = 0x3ffe2d34
	l32i.n	a13, a13, 0             # 40007af3
	l32r	a12, lit_3ffe20fc       # 40007af5  = 0x3ffe5590
	l32i.n	a12, a12, 0             # 40007af8
	beq	a12, a13, .L40007b0f    # 40007afa
	l32r	a10, lit_3ffe20f8       # 40007afd  = 0x3ffe2d34
	l32i.n	a10, a10, 0             # 40007b00
	call8	fn_4000770c             # 40007b02
	l32r	a12, lit_3ffe20fc       # 40007b05  = 0x3ffe5590
	l32r	a11, lit_3ffe20f8       # 40007b08  = 0x3ffe2d34
	l32i.n	a11, a11, 0             # 40007b0b
	s32i.n	a11, a12, 0             # 40007b0d
.L40007b0f:
	l32r	a12, lit_3ffe20f8       # 40007b0f  = 0x3ffe2d34
	l32i.n	a12, a12, 0             # 40007b12
	beqi	a12, 1, .L40007b22      # 40007b14
	l32r	a13, lit_3ffe20f8       # 40007b17  = 0x3ffe2d34
	l32i.n	a13, a13, 0             # 40007b1a
	beqi	a13, 2, .L40007b22      # 40007b1c
	j	.L40007bcf              # 40007b1f
.L40007b22:
	movi.n	a2, 0                   # 40007b22
	s32i.n	a2, a1, 4               # 40007b24
	l32i.n	a15, a1, 4              # 40007b26
	movi.n	a14, 0                  # 40007b28
	bgeu	a14, a15, .L40007b30    # 40007b2a
	j	.L40007bcc              # 40007b2d
.L40007b30:
	l32r	a9, lit_3ffe20ac        # 40007b30  = 0x3ffe54a0
	l32i.n	a8, a1, 4               # 40007b33
	addi.n	a8, a8, 1               # 40007b35
	s32i.n	a8, a9, 0               # 40007b37
	l32r	a7, lit_3ffe20ac        # 40007b39  = 0x3ffe54a0
	movi.n	a6, 1                   # 40007b3c
	s32i	a6, a7, 232             # 40007b3e
	movi.n	a5, 0                   # 40007b41
	s32i.n	a5, a1, 0               # 40007b43
	l32r	a4, lit_3ffe20ac        # 40007b45  = 0x3ffe54a0
	l32i.n	a4, a4, 12              # 40007b48
	l32i.n	a3, a1, 0               # 40007b4a
	bgeu	a3, a4, .L40007b9a      # 40007b4c
.L40007b4f:
	l32i.n	a15, a1, 4              # 40007b4f
	slli	a15, a15, 4             # 40007b51
	l32i.n	a14, a1, 0              # 40007b54
	add.n	a14, a14, a15           # 40007b56
	l32i.n	a15, a1, 0              # 40007b58
	l32r	a2, lit_3ffe20e8        # 40007b5a  = 0x3ffe5500
	addx4	a15, a15, a2            # 40007b5d
	l32r	a2, lit_3ffe1ac0        # 40007b60  = 0x3ffe3eb0
	addx2	a14, a14, a2            # 40007b63
	l16ui	a14, a14, 0             # 40007b66
	s32i.n	a14, a15, 0             # 40007b69
	l32i.n	a13, a1, 4              # 40007b6b
	slli	a13, a13, 4             # 40007b6d
	l32i.n	a12, a1, 0              # 40007b70
	add.n	a12, a12, a13           # 40007b72
	l32i.n	a13, a1, 0              # 40007b74
	l32r	a14, lit_3ffe20ec       # 40007b76  = 0x3ffe54c0
	addx4	a13, a13, a14           # 40007b79
	l32r	a14, lit_3ffe1ac4       # 40007b7c  = 0x3ffe3ef0
	addx2	a12, a12, a14           # 40007b7f
	l16ui	a12, a12, 0             # 40007b82
	srli	a12, a12, 2             # 40007b85
	s32i.n	a12, a13, 0             # 40007b88
	l32i.n	a11, a1, 0              # 40007b8a
	addi.n	a11, a11, 1             # 40007b8c
	s32i.n	a11, a1, 0              # 40007b8e
	l32r	a10, lit_3ffe20ac       # 40007b90  = 0x3ffe54a0
	l32i.n	a10, a10, 12            # 40007b93
	l32i.n	a9, a1, 0               # 40007b95
	bltu	a9, a10, .L40007b4f     # 40007b97
.L40007b9a:
	l32r	a10, lit_3ffe20ac       # 40007b9a  = 0x3ffe54a0
	l32i.n	a10, a10, 0             # 40007b9d
	l32r	a11, lit_3ffe20e8       # 40007b9f  = 0x3ffe5500
	l32r	a12, lit_3ffe20ac       # 40007ba2  = 0x3ffe54a0
	l32i	a12, a12, 232           # 40007ba5
	call8	fn_4000713c             # 40007ba8
	l32r	a10, lit_3ffe20ac       # 40007bab  = 0x3ffe54a0
	l32i.n	a10, a10, 0             # 40007bae
	l32r	a11, lit_3ffe20ec       # 40007bb0  = 0x3ffe54c0
	l32r	a12, lit_3ffe20ac       # 40007bb3  = 0x3ffe54a0
	l32i	a12, a12, 232           # 40007bb6
	call8	fn_40007348             # 40007bb9
	l32i.n	a13, a1, 4              # 40007bbc
	addi.n	a13, a13, 1             # 40007bbe
	s32i.n	a13, a1, 4              # 40007bc0
	l32i.n	a12, a1, 4              # 40007bc2
	movi.n	a11, 0                  # 40007bc4
	bltu	a11, a12, .L40007bcc    # 40007bc6
	j	.L40007b30              # 40007bc9
.L40007bcc:
	j	.L40007c4b              # 40007bcc
.L40007bcf:
	movi.n	a2, 0                   # 40007bcf
	s32i.n	a2, a1, 4               # 40007bd1
	l32i.n	a15, a1, 4              # 40007bd3
	movi.n	a14, 0                  # 40007bd5
	bltu	a14, a15, .L40007c4b    # 40007bd7
.L40007bda:
	l32r	a9, lit_3ffe20ac        # 40007bda  = 0x3ffe54a0
	l32i.n	a8, a1, 4               # 40007bdd
	addi.n	a8, a8, 1               # 40007bdf
	s32i.n	a8, a9, 0               # 40007be1
	l32r	a7, lit_3ffe20ac        # 40007be3  = 0x3ffe54a0
	movi.n	a6, 1                   # 40007be6
	s32i	a6, a7, 232             # 40007be8
	movi.n	a5, 0                   # 40007beb
	s32i.n	a5, a1, 0               # 40007bed
	l32r	a4, lit_3ffe20ac        # 40007bef  = 0x3ffe54a0
	l32i.n	a4, a4, 12              # 40007bf2
	l32i.n	a3, a1, 0               # 40007bf4
	bgeu	a3, a4, .L40007c25      # 40007bf6
.L40007bf9:
	l32i.n	a13, a1, 4              # 40007bf9
	slli	a13, a13, 4             # 40007bfb
	l32i.n	a12, a1, 0              # 40007bfe
	add.n	a12, a12, a13           # 40007c00
	l32i.n	a13, a1, 0              # 40007c02
	l32r	a14, lit_3ffe20e8       # 40007c04  = 0x3ffe5500
	addx4	a13, a13, a14           # 40007c07
	l32r	a14, lit_3ffe1ac0       # 40007c0a  = 0x3ffe3eb0
	addx2	a12, a12, a14           # 40007c0d
	l16ui	a12, a12, 0             # 40007c10
	s32i.n	a12, a13, 0             # 40007c13
	l32i.n	a11, a1, 0              # 40007c15
	addi.n	a11, a11, 1             # 40007c17
	s32i.n	a11, a1, 0              # 40007c19
	l32r	a10, lit_3ffe20ac       # 40007c1b  = 0x3ffe54a0
	l32i.n	a10, a10, 12            # 40007c1e
	l32i.n	a9, a1, 0               # 40007c20
	bltu	a9, a10, .L40007bf9     # 40007c22
.L40007c25:
	l32r	a10, lit_3ffe20ac       # 40007c25  = 0x3ffe54a0
	l32i.n	a10, a10, 0             # 40007c28
	l32r	a11, lit_3ffe20e8       # 40007c2a  = 0x3ffe5500
	l32r	a12, lit_3ffe20ac       # 40007c2d  = 0x3ffe54a0
	l32i	a12, a12, 232           # 40007c30
	call8	fn_4000713c             # 40007c33
	l32r	a10, lit_3ffe2100       # 40007c36  = data_3ffe23a4
	l32i.n	a10, a10, 0             # 40007c39
	call8	fn_40007760             # 40007c3b
	l32i.n	a13, a1, 4              # 40007c3e
	addi.n	a13, a13, 1             # 40007c40
	s32i.n	a13, a1, 4              # 40007c42
	l32i.n	a12, a1, 4              # 40007c44
	movi.n	a11, 0                  # 40007c46
	bgeu	a11, a12, .L40007bda    # 40007c48
.L40007c4b:
	retw.n                          # 40007c4b
	.size	fn_40007ab8, . - fn_40007ab8
