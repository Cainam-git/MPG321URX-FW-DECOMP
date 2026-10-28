# fn_40005e74: 0x40005e74-0x40005ea1 (firmware file offset 0x35e74-0x35ea1), 20 instructions
# Address stored in the words at: 0x4000cb60
# Other literal values: 0x3ffe4438
# Special registers: ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005e74, @function
fn_40005e74:
	entry	a1, 64                  # 40005e74
	rsil	a2, 15                  # 40005e77
	s32i.n	a2, a1, 16              # 40005e7a
	l32i.n	a4, a1, 16              # 40005e7c
	s32i.n	a4, a1, 0               # 40005e7e
	l32i.n	a3, a1, 0               # 40005e80
	s32i.n	a3, a1, 4               # 40005e82
	l32i.n	a6, a1, 4               # 40005e84
	s32i.n	a6, a1, 8               # 40005e86
	l32r	a6, lit_3ffe1e60        # 40005e88  = 0x3ffe4438
	l32r	a5, lit_3ffe1e60        # 40005e8b  = 0x3ffe4438
	l32i.n	a5, a5, 4               # 40005e8e
	addi.n	a5, a5, 1               # 40005e90
	s32i.n	a5, a6, 4               # 40005e92
	l32i.n	a8, a1, 8               # 40005e94
	s32i.n	a8, a1, 12              # 40005e96
	l32i.n	a7, a1, 12              # 40005e98
	wsr.ps	a7                      # 40005e9a
	rsync                           # 40005e9d
	retw.n                          # 40005ea0
	.size	fn_40005e74, . - fn_40005e74
