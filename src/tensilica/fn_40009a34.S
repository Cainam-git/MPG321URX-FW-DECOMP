# fn_40009a34: 0x40009a34-0x40009a4a (firmware file offset 0x39a34-0x39a4a), 11 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40009a34, @function
fn_40009a34:
	entry	a1, 64                  # 40009a34
	s32i.n	a2, a1, 0               # 40009a37
	s32i.n	a3, a1, 4               # 40009a39
	s32i.n	a4, a1, 8               # 40009a3b
	s32i.n	a5, a1, 12              # 40009a3d
	s32i.n	a6, a1, 16              # 40009a3f
	s32i.n	a7, a1, 20              # 40009a41
	l32i.n	a11, a1, 0              # 40009a43
	s32i.n	a11, a1, 0              # 40009a45
	movi.n	a2, 0                   # 40009a47
	retw.n                          # 40009a49
	.size	fn_40009a34, . - fn_40009a34
