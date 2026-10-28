# fn_4000ab84: 0x4000ab84-0x4000ab90 (firmware file offset 0x3ab84-0x3ab90), 5 instructions
# Called from: fn_4000908c
# Special registers: ccount, ccompare0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000ab84, @function
fn_4000ab84:
	entry	a1, 16                  # 4000ab84
	rsr.ccount	a3              # 4000ab87
	add.n	a3, a3, a2              # 4000ab8a
	wsr.ccompare0	a3              # 4000ab8c
	retw.n                          # 4000ab8f
	.size	fn_4000ab84, . - fn_4000ab84
