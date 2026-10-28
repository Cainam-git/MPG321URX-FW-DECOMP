# fn_4000a524: 0x4000a524-0x4000a545 (firmware file offset 0x3a524-0x3a545), 13 instructions
# Called from: fn_40008e9c, fn_40008f58, fn_4000908c, fn_400090c8, fn_40009104, fn_40009ca8
# Addresses loaded: data_3ffe2a78
# Special registers: intenable, ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a524, @function
fn_4000a524:
	entry	a1, 16                  # 4000a524
	l32r	a4, lit_3ffe2358        # 4000a527  = data_3ffe2a78
	rsil	a7, 6                   # 4000a52a
	l32i.n	a3, a4, 0               # 4000a52d
	l32i.n	a6, a4, 4               # 4000a52f
	or	a5, a3, a2              # 4000a531
	s32i.n	a5, a4, 0               # 4000a534
	and	a5, a5, a6              # 4000a536
	wsr.intenable	a5              # 4000a539
	wsr.ps	a7                      # 4000a53c
	rsync                           # 4000a53f
	mov.n	a2, a3                  # 4000a542
	retw.n                          # 4000a544
	.size	fn_4000a524, . - fn_4000a524
