# fn_40009104: 0x40009104-0x40009128 (firmware file offset 0x39104-0x39128), 14 instructions
# Called from: fn_4000a3cc
# Calls: fn_4000a514, fn_4000ab74, fn_4000aba4, fn_4000a524
# Addresses loaded: fn_4000902c
# Other literal values: 0x3ffe5598, 0x00006c34, 0x00002000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40009104, @function
fn_40009104:
	entry	a1, 48                  # 40009104
	s32i.n	a2, a1, 0               # 40009107
	l32r	a5, lit_3ffe2258        # 40009109  = 0x3ffe5598
	l32i.n	a4, a1, 0               # 4000910c
	s32i.n	a4, a5, 28              # 4000910e
	movi.n	a10, 13                 # 40009110
	l32r	a11, lit_3ffe2268       # 40009112  = fn_4000902c
	call8	fn_4000a514             # 40009115
	call8	fn_4000ab74             # 40009118
	l32r	a10, lit_3ffe225c       # 4000911b  = 0x00006c34
	call8	fn_4000aba4             # 4000911e
	l32r	a10, lit_3ffe1fa8       # 40009121  = 0x00002000
	call8	fn_4000a524             # 40009124
	retw.n                          # 40009127
	.size	fn_40009104, . - fn_40009104
