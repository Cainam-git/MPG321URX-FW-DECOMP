# fn_4000ac08: 0x4000ac08-0x4000ac27 (firmware file offset 0x3ac08-0x3ac27), 12 instructions
# Called from: fn_40008f84, fn_40008fd8, fn_4000902c
# Special registers: ccompare0, ccompare1, ccompare2

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000ac08, @function
fn_4000ac08:
	entry	a1, 16                  # 4000ac08
	bnez.n	a2, .L4000ac14          # 4000ac0b
	rsr.ccompare0	a2              # 4000ac0d
	retw.n                          # 4000ac10
	.balign	4, 0                    # 2 zero bytes up to the 4-byte boundary 0x4000ac14
.L4000ac14:
	bnei	a2, 1, .L4000ac1c       # 4000ac14
	rsr.ccompare1	a2              # 4000ac17
	retw.n                          # 4000ac1a
.L4000ac1c:
	bnei	a2, 2, .L4000ac24       # 4000ac1c
	rsr.ccompare2	a2              # 4000ac1f
	retw.n                          # 4000ac22
.L4000ac24:
	movi.n	a2, 0                   # 4000ac24
	retw.n                          # 4000ac26
	.size	fn_4000ac08, . - fn_4000ac08
