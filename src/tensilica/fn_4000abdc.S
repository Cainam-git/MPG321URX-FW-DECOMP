# fn_4000abdc: 0x4000abdc-0x4000abe3 (firmware file offset 0x3abdc-0x3abe3), 3 instructions
# Called from: fn_40008f84, fn_40008fd8, fn_4000902c
# Special registers: ccount

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000abdc, @function
fn_4000abdc:
	entry	a1, 16                  # 4000abdc
	rsr.ccount	a2              # 4000abdf
	retw.n                          # 4000abe2
	.size	fn_4000abdc, . - fn_4000abdc
