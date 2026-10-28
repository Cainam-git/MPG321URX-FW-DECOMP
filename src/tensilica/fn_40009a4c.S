# fn_40009a4c: 0x40009a4c-0x40009a8d (firmware file offset 0x39a4c-0x39a8d), 31 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40009218
# Other literal values: 0x00000030, 0x00000010

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40009a4c, @function
fn_40009a4c:
	entry	a1, 80                  # 40009a4c
	s32i.n	a2, a1, 16              # 40009a4f
	s32i.n	a3, a1, 20              # 40009a51
	s32i.n	a4, a1, 24              # 40009a53
	s32i.n	a5, a1, 28              # 40009a55
	s32i.n	a6, a1, 32              # 40009a57
	s32i.n	a7, a1, 36              # 40009a59
	mov.n	a15, a1                 # 40009a5b
	l32r	a14, lit_3ffe22a8       # 40009a5d  = 0x00000030
	add.n	a14, a1, a14            # 40009a60
	mov.n	a14, a14                # 40009a62
	s32i.n	a14, a15, 0             # 40009a64
	mov.n	a14, a1                 # 40009a66
	l32r	a13, lit_3ffe22ac       # 40009a68  = 0x00000010
	add.n	a13, a1, a13            # 40009a6b
	mov.n	a13, a13                # 40009a6d
	s32i.n	a13, a14, 4             # 40009a6f
	mov.n	a12, a1                 # 40009a71
	movi.n	a11, 8                  # 40009a73
	s32i.n	a11, a12, 8             # 40009a75
	l32i.n	a10, a1, 16             # 40009a77
	l32i.n	a11, a1, 20             # 40009a79
	mov.n	a14, a1                 # 40009a7b
	l32i.n	a12, a14, 0             # 40009a7d
	l32i.n	a13, a14, 4             # 40009a7f
	l32i.n	a14, a14, 8             # 40009a81
	call8	fn_40009218             # 40009a83
	s32i.n	a10, a1, 12             # 40009a86
	mov.n	a15, a1                 # 40009a88
	l32i.n	a2, a1, 12              # 40009a8a
	retw.n                          # 40009a8c
	.size	fn_40009a4c, . - fn_40009a4c
