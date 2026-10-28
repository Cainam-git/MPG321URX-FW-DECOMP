# fn_4000abcc: 0x4000abcc-0x4000abd8 (firmware file offset 0x3abcc-0x3abd8), 5 instructions
# Entered without a call: by jx from the user exception vector (0x40000340), through the exception-cause
# table at ro_3ffe19fc.
# Address stored in the words at: 0x4000c6f4, 0x4000c6fc, 0x4000c700

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000abcc, @function
fn_4000abcc:
	l32i.n	a2, a1, 16              # 4000abcc
	l32i.n	a3, a1, 20              # 4000abce
	addmi	a1, a1, 0x100           # 4000abd0
	break	1, 1                    # 4000abd3
	rfe                             # 4000abd6
	.size	fn_4000abcc, . - fn_4000abcc
