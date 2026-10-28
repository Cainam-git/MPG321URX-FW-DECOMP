# fn_4000aba4: 0x4000aba4-0x4000abcb (firmware file offset 0x3aba4-0x3abcb), 15 instructions
# Called from: fn_40009104
# Special registers: ccount, ccompare2, ps, epc1

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000aba4, @function
fn_4000aba4:
	entry	a1, 16                  # 4000aba4
	rsr.ccount	a3              # 4000aba7
	add.n	a3, a3, a2              # 4000abaa
	wsr.ccompare2	a3              # 4000abac
	retw.n                          # 4000abaf
	.balign	4, 0                    # 3 zero bytes up to the 4-byte boundary 0x4000abb4
.L4000abb4:
	l32i.n	a2, a5, 4               # 4000abb4
	l32i.n	a3, a5, 0               # 4000abb6
	wsr.ps	a2                      # 4000abb8
	l32i.n	a2, a5, 16              # 4000abbb
	l32i.n	a4, a5, 24              # 4000abbd
	rsync                           # 4000abbf
	wsr.epc1	a3              # 4000abc2
	l32i.n	a3, a5, 20              # 4000abc5
	l32i.n	a5, a5, 28              # 4000abc7
	rfe                             # 4000abc9
	.size	fn_4000aba4, . - fn_4000aba4
