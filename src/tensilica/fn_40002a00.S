# fn_40002a00: 0x40002a00-0x40002bed (firmware file offset 0x32a00-0x32bed), 203 instructions
# Called from: fn_400030c8
# Calls: fn_40002660
# Addresses loaded: data_3ffe2390
# Other literal values: 0x3ffe3ef0, 0x3ffe3db0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40002a00, @function
fn_40002a00:
	entry	a1, 64                  # 40002a00
	s32i.n	a2, a1, 16              # 40002a03
	s32i.n	a3, a1, 20              # 40002a05
	s32i.n	a4, a1, 24              # 40002a07
	movi.n	a8, 0                   # 40002a09
	s32i.n	a8, a1, 0               # 40002a0b
	l32i.n	a7, a1, 24              # 40002a0d
	beqi	a7, 1, .L40002a15       # 40002a0f
	j	.L40002b7f              # 40002a12
.L40002a15:
	movi.n	a11, 0                  # 40002a15
	s32i.n	a11, a1, 0              # 40002a17
	l32r	a10, lit_3ffe1a98       # 40002a19  = data_3ffe2390
	l32i.n	a10, a10, 0             # 40002a1c
	l32i.n	a9, a1, 0               # 40002a1e
	bltu	a9, a10, .L40002a26     # 40002a20
	j	.L40002b7c              # 40002a23
.L40002a26:
	l32i.n	a13, a1, 0              # 40002a26
	l32r	a14, lit_3ffe1ac4       # 40002a28  = 0x3ffe3ef0
	addx2	a13, a13, a14           # 40002a2b
	l16ui	a13, a13, 0             # 40002a2e
	l32i.n	a12, a1, 0              # 40002a31
	l32i.n	a14, a1, 16             # 40002a33
	addx4	a12, a12, a14           # 40002a35
	l32i.n	a12, a12, 0             # 40002a38
	bgeu	a12, a13, .L40002abc    # 40002a3a
	l32i.n	a10, a1, 0              # 40002a3d
	l32i.n	a11, a1, 16             # 40002a3f
	addx4	a10, a10, a11           # 40002a41
	l32i.n	a10, a10, 0             # 40002a44
	slli	a10, a10, 8             # 40002a46
	l32i.n	a11, a1, 0              # 40002a49
	l32r	a12, lit_3ffe1aac       # 40002a4b  = 0x3ffe3db0
	addx4	a11, a11, a12           # 40002a4e
	l32i.n	a11, a11, 0             # 40002a51
	l32r	a12, lit_3ffe1a98       # 40002a53  = data_3ffe2390
	l32i.n	a12, a12, 48            # 40002a56
	call8	fn_40002660             # 40002a58
	l32i.n	a4, a1, 0               # 40002a5b
	l32r	a5, lit_3ffe1aac        # 40002a5d  = 0x3ffe3db0
	addx4	a4, a4, a5              # 40002a60
	s32i.n	a10, a4, 0              # 40002a63
	l32i.n	a2, a1, 0               # 40002a65
	l32i.n	a3, a1, 20              # 40002a67
	addx4	a2, a2, a3              # 40002a69
	movi	a3, 128                 # 40002a6c
	l32i.n	a15, a1, 0              # 40002a6f
	l32r	a4, lit_3ffe1aac        # 40002a71  = 0x3ffe3db0
	addx4	a15, a15, a4            # 40002a74
	l32i.n	a15, a15, 0             # 40002a77
	add.n	a15, a15, a3            # 40002a79
	srli	a15, a15, 8             # 40002a7b
	s32i.n	a15, a2, 0              # 40002a7e
	l32i.n	a13, a1, 0              # 40002a80
	l32i.n	a14, a1, 20             # 40002a82
	addx4	a13, a13, a14           # 40002a84
	l32i.n	a13, a13, 0             # 40002a87
	l32r	a12, lit_3ffe1a98       # 40002a89  = data_3ffe2390
	l32i.n	a12, a12, 12            # 40002a8c
	bltu	a12, a13, .L40002aa7    # 40002a8e
	l32r	a7, lit_3ffe1a98        # 40002a91  = data_3ffe2390
	l32i.n	a7, a7, 8               # 40002a94
	l32i.n	a6, a1, 0               # 40002a96
	l32i.n	a8, a1, 20              # 40002a98
	addx4	a6, a6, a8              # 40002a9a
	l32i.n	a6, a6, 0               # 40002a9d
	maxu	a6, a6, a7              # 40002a9f
	s32i.n	a6, a1, 4               # 40002aa2
	j	.L40002aae              # 40002aa4
.L40002aa7:
	l32r	a8, lit_3ffe1a98        # 40002aa7  = data_3ffe2390
	l32i.n	a8, a8, 12              # 40002aaa
	s32i.n	a8, a1, 4               # 40002aac
.L40002aae:
	l32i.n	a10, a1, 0              # 40002aae
	l32i.n	a11, a1, 20             # 40002ab0
	addx4	a10, a10, a11           # 40002ab2
	l32i.n	a9, a1, 4               # 40002ab5
	s32i.n	a9, a10, 0              # 40002ab7
	j	.L40002b69              # 40002ab9
.L40002abc:
	l32i.n	a13, a1, 0              # 40002abc
	l32i.n	a14, a1, 16             # 40002abe
	addx4	a13, a13, a14           # 40002ac0
	l32i.n	a13, a13, 0             # 40002ac3
	l32i.n	a12, a1, 0              # 40002ac5
	l32r	a14, lit_3ffe1ac4       # 40002ac7  = 0x3ffe3ef0
	addx2	a12, a12, a14           # 40002aca
	l16ui	a12, a12, 0             # 40002acd
	bltu	a12, a13, .L40002ad6    # 40002ad0
	j	.L40002b55              # 40002ad3
.L40002ad6:
	l32i.n	a10, a1, 0              # 40002ad6
	l32i.n	a11, a1, 16             # 40002ad8
	addx4	a10, a10, a11           # 40002ada
	l32i.n	a10, a10, 0             # 40002add
	slli	a10, a10, 8             # 40002adf
	l32i.n	a11, a1, 0              # 40002ae2
	l32r	a12, lit_3ffe1aac       # 40002ae4  = 0x3ffe3db0
	addx4	a11, a11, a12           # 40002ae7
	l32i.n	a11, a11, 0             # 40002aea
	l32r	a12, lit_3ffe1a98       # 40002aec  = data_3ffe2390
	l32i.n	a12, a12, 44            # 40002aef
	call8	fn_40002660             # 40002af1
	l32i.n	a4, a1, 0               # 40002af4
	l32r	a5, lit_3ffe1aac        # 40002af6  = 0x3ffe3db0
	addx4	a4, a4, a5              # 40002af9
	s32i.n	a10, a4, 0              # 40002afc
	l32i.n	a2, a1, 0               # 40002afe
	l32i.n	a3, a1, 20              # 40002b00
	addx4	a2, a2, a3              # 40002b02
	movi	a3, 128                 # 40002b05
	l32i.n	a15, a1, 0              # 40002b08
	l32r	a4, lit_3ffe1aac        # 40002b0a  = 0x3ffe3db0
	addx4	a15, a15, a4            # 40002b0d
	l32i.n	a15, a15, 0             # 40002b10
	add.n	a15, a15, a3            # 40002b12
	srli	a15, a15, 8             # 40002b14
	s32i.n	a15, a2, 0              # 40002b17
	l32i.n	a13, a1, 0              # 40002b19
	l32i.n	a14, a1, 20             # 40002b1b
	addx4	a13, a13, a14           # 40002b1d
	l32i.n	a13, a13, 0             # 40002b20
	l32r	a12, lit_3ffe1a98       # 40002b22  = data_3ffe2390
	l32i.n	a12, a12, 12            # 40002b25
	bltu	a12, a13, .L40002b40    # 40002b27
	l32r	a7, lit_3ffe1a98        # 40002b2a  = data_3ffe2390
	l32i.n	a7, a7, 8               # 40002b2d
	l32i.n	a6, a1, 0               # 40002b2f
	l32i.n	a8, a1, 20              # 40002b31
	addx4	a6, a6, a8              # 40002b33
	l32i.n	a6, a6, 0               # 40002b36
	maxu	a6, a6, a7              # 40002b38
	s32i.n	a6, a1, 8               # 40002b3b
	j	.L40002b47              # 40002b3d
.L40002b40:
	l32r	a8, lit_3ffe1a98        # 40002b40  = data_3ffe2390
	l32i.n	a8, a8, 12              # 40002b43
	s32i.n	a8, a1, 8               # 40002b45
.L40002b47:
	l32i.n	a10, a1, 0              # 40002b47
	l32i.n	a11, a1, 20             # 40002b49
	addx4	a10, a10, a11           # 40002b4b
	l32i.n	a9, a1, 8               # 40002b4e
	s32i.n	a9, a10, 0              # 40002b50
	j	.L40002b69              # 40002b52
.L40002b55:
	l32i.n	a13, a1, 0              # 40002b55
	l32i.n	a14, a1, 20             # 40002b57
	addx4	a13, a13, a14           # 40002b59
	l32i.n	a12, a1, 0              # 40002b5c
	l32r	a14, lit_3ffe1ac4       # 40002b5e  = 0x3ffe3ef0
	addx2	a12, a12, a14           # 40002b61
	l16ui	a12, a12, 0             # 40002b64
	s32i.n	a12, a13, 0             # 40002b67
.L40002b69:
	l32i.n	a3, a1, 0               # 40002b69
	addi.n	a3, a3, 1               # 40002b6b
	s32i.n	a3, a1, 0               # 40002b6d
	l32r	a2, lit_3ffe1a98        # 40002b6f  = data_3ffe2390
	l32i.n	a2, a2, 0               # 40002b72
	l32i.n	a15, a1, 0              # 40002b74
	bgeu	a15, a2, .L40002b7c     # 40002b76
	j	.L40002a26              # 40002b79
.L40002b7c:
	j	.L40002bec              # 40002b7c
.L40002b7f:
	movi.n	a6, 0                   # 40002b7f
	s32i.n	a6, a1, 0               # 40002b81
	l32r	a5, lit_3ffe1a98        # 40002b83  = data_3ffe2390
	l32i.n	a5, a5, 0               # 40002b86
	l32i.n	a4, a1, 0               # 40002b88
	bgeu	a4, a5, .L40002bec      # 40002b8a
.L40002b8d:
	l32i.n	a11, a1, 0              # 40002b8d
	l32r	a12, lit_3ffe1aac       # 40002b8f  = 0x3ffe3db0
	addx4	a11, a11, a12           # 40002b92
	l32i.n	a10, a1, 0              # 40002b95
	l32i.n	a12, a1, 16             # 40002b97
	addx4	a10, a10, a12           # 40002b99
	l32i.n	a10, a10, 0             # 40002b9c
	slli	a10, a10, 8             # 40002b9e
	s32i.n	a10, a11, 0             # 40002ba1
	l32i.n	a8, a1, 0               # 40002ba3
	l32i.n	a9, a1, 16              # 40002ba5
	addx4	a8, a8, a9              # 40002ba7
	l32i.n	a8, a8, 0               # 40002baa
	l32r	a7, lit_3ffe1a98        # 40002bac  = data_3ffe2390
	l32i.n	a7, a7, 12              # 40002baf
	bltu	a7, a8, .L40002bca      # 40002bb1
	l32r	a14, lit_3ffe1a98       # 40002bb4  = data_3ffe2390
	l32i.n	a14, a14, 8             # 40002bb7
	l32i.n	a13, a1, 0              # 40002bb9
	l32i.n	a15, a1, 16             # 40002bbb
	addx4	a13, a13, a15           # 40002bbd
	l32i.n	a13, a13, 0             # 40002bc0
	maxu	a13, a13, a14           # 40002bc2
	s32i.n	a13, a1, 12             # 40002bc5
	j	.L40002bd1              # 40002bc7
.L40002bca:
	l32r	a15, lit_3ffe1a98       # 40002bca  = data_3ffe2390
	l32i.n	a15, a15, 12            # 40002bcd
	s32i.n	a15, a1, 12             # 40002bcf
.L40002bd1:
	l32i.n	a6, a1, 0               # 40002bd1
	l32i.n	a7, a1, 20              # 40002bd3
	addx4	a6, a6, a7              # 40002bd5
	l32i.n	a5, a1, 12              # 40002bd8
	s32i.n	a5, a6, 0               # 40002bda
	l32i.n	a4, a1, 0               # 40002bdc
	addi.n	a4, a4, 1               # 40002bde
	s32i.n	a4, a1, 0               # 40002be0
	l32r	a3, lit_3ffe1a98        # 40002be2  = data_3ffe2390
	l32i.n	a3, a3, 0               # 40002be5
	l32i.n	a2, a1, 0               # 40002be7
	bltu	a2, a3, .L40002b8d      # 40002be9
.L40002bec:
	retw.n                          # 40002bec
	.size	fn_40002a00, . - fn_40002a00
