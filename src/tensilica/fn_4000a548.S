# fn_4000a548: 0x4000a548-0x4000a56c (firmware file offset 0x3a548-0x3a56c), 14 instructions
# Called from: fn_40008f84, fn_40008fd8
# Addresses loaded: data_3ffe2a78
# Special registers: intenable, ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a548, @function
fn_4000a548:
	entry	a1, 16                  # 4000a548
	l32r	a4, lit_3ffe2358        # 4000a54b  = data_3ffe2a78
	rsil	a7, 6                   # 4000a54e
	l32i.n	a3, a4, 0               # 4000a551
	l32i.n	a6, a4, 4               # 4000a553
	or	a5, a3, a2              # 4000a555
	xor	a5, a5, a2              # 4000a558
	s32i.n	a5, a4, 0               # 4000a55b
	and	a5, a5, a6              # 4000a55d
	wsr.intenable	a5              # 4000a560
	wsr.ps	a7                      # 4000a563
	rsync                           # 4000a566
	mov.n	a2, a3                  # 4000a569
	retw.n                          # 4000a56b
	.size	fn_4000a548, . - fn_4000a548
