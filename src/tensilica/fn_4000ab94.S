# fn_4000ab94: 0x4000ab94-0x4000aba0 (firmware file offset 0x3ab94-0x3aba0), 5 instructions
# Called from: fn_400090c8
# Special registers: ccount, ccompare1

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000ab94, @function
fn_4000ab94:
	entry	a1, 16                  # 4000ab94
	rsr.ccount	a3              # 4000ab97
	add.n	a3, a3, a2              # 4000ab9a
	wsr.ccompare1	a3              # 4000ab9c
	retw.n                          # 4000ab9f
	.size	fn_4000ab94, . - fn_4000ab94
