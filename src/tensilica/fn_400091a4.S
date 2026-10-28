# fn_400091a4: 0x400091a4-0x400091ce (firmware file offset 0x391a4-0x391ce), 19 instructions
# Called from: fn_400020d0, fn_400024e4
# Other literal values: 0x3ffe5598
# Special registers: ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400091a4, @function
fn_400091a4:
	entry	a1, 64                  # 400091a4
	rsil	a2, 15                  # 400091a7
	s32i.n	a2, a1, 20              # 400091aa
	l32i.n	a4, a1, 20              # 400091ac
	s32i.n	a4, a1, 0               # 400091ae
	l32i.n	a3, a1, 0               # 400091b0
	s32i.n	a3, a1, 4               # 400091b2
	l32i.n	a6, a1, 4               # 400091b4
	s32i.n	a6, a1, 8               # 400091b6
	l32r	a5, lit_3ffe2258        # 400091b8  = 0x3ffe5598
	l32i.n	a5, a5, 24              # 400091bb
	s32i.n	a5, a1, 12              # 400091bd
	l32i.n	a8, a1, 8               # 400091bf
	s32i.n	a8, a1, 16              # 400091c1
	l32i.n	a7, a1, 16              # 400091c3
	wsr.ps	a7                      # 400091c5
	rsync                           # 400091c8
	l32i.n	a2, a1, 12              # 400091cb
	retw.n                          # 400091cd
	.size	fn_400091a4, . - fn_400091a4
