# fn_40005e44: 0x40005e44-0x40005e71 (firmware file offset 0x35e44-0x35e71), 20 instructions
# Address stored in the words at: 0x4000cb5c
# Other literal values: 0x3ffe4438
# Special registers: ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005e44, @function
fn_40005e44:
	entry	a1, 64                  # 40005e44
	rsil	a2, 15                  # 40005e47
	s32i.n	a2, a1, 16              # 40005e4a
	l32i.n	a4, a1, 16              # 40005e4c
	s32i.n	a4, a1, 0               # 40005e4e
	l32i.n	a3, a1, 0               # 40005e50
	s32i.n	a3, a1, 4               # 40005e52
	l32i.n	a6, a1, 4               # 40005e54
	s32i.n	a6, a1, 8               # 40005e56
	l32r	a6, lit_3ffe1e60        # 40005e58  = 0x3ffe4438
	l32r	a5, lit_3ffe1e60        # 40005e5b  = 0x3ffe4438
	l32i.n	a5, a5, 0               # 40005e5e
	addi.n	a5, a5, 1               # 40005e60
	s32i.n	a5, a6, 0               # 40005e62
	l32i.n	a8, a1, 8               # 40005e64
	s32i.n	a8, a1, 12              # 40005e66
	l32i.n	a7, a1, 12              # 40005e68
	wsr.ps	a7                      # 40005e6a
	rsync                           # 40005e6d
	retw.n                          # 40005e70
	.size	fn_40005e44, . - fn_40005e44
