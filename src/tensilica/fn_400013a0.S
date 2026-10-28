# fn_400013a0: 0x400013a0-0x400013b3 (firmware file offset 0x313a0-0x313b3), 8 instructions
# Address stored in the words at: 0x4000d2a4
# Calls: fn_40006f00, fn_400079b8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400013a0, @function
fn_400013a0:
	entry	a1, 48                  # 400013a0
	s32i.n	a2, a1, 0               # 400013a3
	s32i.n	a3, a1, 4               # 400013a5
	l32i.n	a5, a1, 4               # 400013a7
	bnei	a5, 1, .L400013b2       # 400013a9
	call8	fn_40006f00             # 400013ac
	call8	fn_400079b8             # 400013af
.L400013b2:
	retw.n                          # 400013b2
	.size	fn_400013a0, . - fn_400013a0
