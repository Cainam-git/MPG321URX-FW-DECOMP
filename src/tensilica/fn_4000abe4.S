# fn_4000abe4: 0x4000abe4-0x4000ac06 (firmware file offset 0x3abe4-0x3ac06), 13 instructions
# Called from: fn_40008f84, fn_40008fd8, fn_4000902c
# Special registers: ccompare0, ccompare1, ccompare2

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000abe4, @function
fn_4000abe4:
	entry	a1, 16                  # 4000abe4
	bnez.n	a2, .L4000abf1          # 4000abe7
	wsr.ccompare0	a3              # 4000abe9
	rsync                           # 4000abec
	retw.n                          # 4000abef
.L4000abf1:
	bnei	a2, 1, .L4000abfc       # 4000abf1
	wsr.ccompare1	a3              # 4000abf4
	rsync                           # 4000abf7
	retw.n                          # 4000abfa
.L4000abfc:
	bnei	a2, 2, .L4000ac05       # 4000abfc
	wsr.ccompare2	a3              # 4000abff
	rsync                           # 4000ac02
.L4000ac05:
	retw.n                          # 4000ac05
	.size	fn_4000abe4, . - fn_4000abe4
