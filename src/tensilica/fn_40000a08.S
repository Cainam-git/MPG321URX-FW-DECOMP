# fn_40000a08: 0x40000a08-0x40000afa (firmware file offset 0x30a08-0x30afa), 100 instructions
# Address stored in the words at: 0x4000c83c
# Addresses loaded: data_3ffe2390, data_3ffe2760
# Other literal values: 0x3ffe2d70, 0x3ffe3d70

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40000a08, @function
fn_40000a08:
	entry	a1, 192                 # 40000a08
	s32i	a2, a1, 144             # 40000a0b
	s32i	a3, a1, 148             # 40000a0e
	movi.n	a9, 0                   # 40000a11
	s32i.n	a9, a1, 0               # 40000a13
	movi.n	a8, 0                   # 40000a15
	s32i.n	a8, a1, 4               # 40000a17
	movi.n	a7, 0                   # 40000a19
	s32i.n	a7, a1, 4               # 40000a1b
	l32r	a6, lit_3ffe1a98        # 40000a1d  = data_3ffe2390
	l32i.n	a6, a6, 0               # 40000a20
	l32i.n	a5, a1, 4               # 40000a22
	bgeu	a5, a6, .L40000a43      # 40000a24
.L40000a27:
	l32i.n	a14, a1, 4              # 40000a27
	addi	a15, a1, 16             # 40000a29
	addx4	a14, a14, a15           # 40000a2c
	movi.n	a13, 0                  # 40000a2f
	s32i.n	a13, a14, 0             # 40000a31
	l32i.n	a12, a1, 4              # 40000a33
	addi.n	a12, a12, 1             # 40000a35
	s32i.n	a12, a1, 4              # 40000a37
	l32r	a11, lit_3ffe1a98       # 40000a39  = data_3ffe2390
	l32i.n	a11, a11, 0             # 40000a3c
	l32i.n	a10, a1, 4              # 40000a3e
	bltu	a10, a11, .L40000a27    # 40000a40
.L40000a43:
	movi.n	a4, 0                   # 40000a43
	s32i.n	a4, a1, 0               # 40000a45
	l32r	a3, lit_3ffe1a88        # 40000a47  = data_3ffe2760
	l32i.n	a3, a3, 0               # 40000a4a
	l32i.n	a2, a1, 0               # 40000a4c
	bgeu	a2, a3, .L40000a8f      # 40000a4e
.L40000a51:
	l32i.n	a11, a1, 0              # 40000a51
	l32r	a12, lit_3ffe1a8c       # 40000a53  = 0x3ffe2d70
	addx2	a11, a11, a12           # 40000a56
	l16ui	a11, a11, 0             # 40000a59
	s32i.n	a11, a1, 4              # 40000a5c
	l32i.n	a9, a1, 4               # 40000a5e
	addi	a10, a1, 16             # 40000a60
	addx4	a9, a9, a10             # 40000a63
	l32i.n	a10, a1, 4              # 40000a66
	addi	a11, a1, 16             # 40000a68
	addx4	a10, a10, a11           # 40000a6b
	l32i.n	a10, a10, 0             # 40000a6e
	l32i.n	a8, a1, 0               # 40000a70
	l32i	a11, a1, 144            # 40000a72
	addx2	a8, a8, a11             # 40000a75
	l16ui	a8, a8, 0               # 40000a78
	add.n	a8, a8, a10             # 40000a7b
	s32i.n	a8, a9, 0               # 40000a7d
	l32i.n	a7, a1, 0               # 40000a7f
	addi.n	a7, a7, 1               # 40000a81
	s32i.n	a7, a1, 0               # 40000a83
	l32r	a6, lit_3ffe1a88        # 40000a85  = data_3ffe2760
	l32i.n	a6, a6, 0               # 40000a88
	l32i.n	a5, a1, 0               # 40000a8a
	bltu	a5, a6, .L40000a51      # 40000a8c
.L40000a8f:
	movi.n	a15, 0                  # 40000a8f
	s32i.n	a15, a1, 4              # 40000a91
	l32r	a14, lit_3ffe1a98       # 40000a93  = data_3ffe2390
	l32i.n	a14, a14, 0             # 40000a96
	l32i.n	a13, a1, 4              # 40000a98
	bgeu	a13, a14, .L40000af9    # 40000a9a
.L40000a9d:
	l32i.n	a6, a1, 4               # 40000a9d
	l32i	a7, a1, 148             # 40000a9f
	addx4	a6, a6, a7              # 40000aa2
	l32i.n	a7, a1, 4               # 40000aa5
	l32r	a8, lit_3ffe1a94        # 40000aa7  = 0x3ffe3d70
	addx2	a7, a7, a8              # 40000aaa
	l16ui	a7, a7, 0               # 40000aad
	l32i.n	a5, a1, 4               # 40000ab0
	addi	a8, a1, 16              # 40000ab2
	addx4	a5, a5, a8              # 40000ab5
	l32i.n	a5, a5, 0               # 40000ab8
	quou	a5, a5, a7              # 40000aba
	s32i.n	a5, a6, 0               # 40000abd
	l32i.n	a3, a1, 4               # 40000abf
	addi	a4, a1, 16              # 40000ac1
	addx4	a3, a3, a4              # 40000ac4
	l32i.n	a3, a3, 0               # 40000ac7
	movi.n	a2, 10                  # 40000ac9
	bgeu	a2, a3, .L40000ae9      # 40000acb
	l32i.n	a9, a1, 4               # 40000ace
	l32i	a10, a1, 148            # 40000ad0
	addx4	a9, a9, a10             # 40000ad3
	l32i.n	a9, a9, 0               # 40000ad6
	movi.n	a8, 9                   # 40000ad8
	bltu	a8, a9, .L40000ae9      # 40000ada
	l32i.n	a12, a1, 4              # 40000add
	l32i	a13, a1, 148            # 40000adf
	addx4	a12, a12, a13           # 40000ae2
	movi.n	a11, 10                 # 40000ae5
	s32i.n	a11, a12, 0             # 40000ae7
.L40000ae9:
	l32i.n	a2, a1, 4               # 40000ae9
	addi.n	a2, a2, 1               # 40000aeb
	s32i.n	a2, a1, 4               # 40000aed
	l32r	a15, lit_3ffe1a98       # 40000aef  = data_3ffe2390
	l32i.n	a15, a15, 0             # 40000af2
	l32i.n	a14, a1, 4              # 40000af4
	bltu	a14, a15, .L40000a9d    # 40000af6
.L40000af9:
	retw.n                          # 40000af9
	.size	fn_40000a08, . - fn_40000a08
