# dbg_cmd_rsa  (fn_40005c78): 0x40005c78-0x40005c8b (firmware file offset 0x35c78-0x35c8b), 8 instructions
# Name basis: derived - command table entry 'rsa'; purpose of the value not shown
# Address stored in the words at: 0x4000b420
# Command "rsa" of the debug command line (table entry at 0x4000b420): writes 0x68500DEF to address 0xB70910FC.
# 0xB7091000 is the address of mailbox portal 2 on the main processor's side (docs/MAP.md); this program itself
# reads the portal at 0xE0091000.
# Arguments: none used.
# Locals: a1+0 p (the address).
# Returns: nothing.
# Other literal values: 0xb70910fc, 0x68500def

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_cmd_rsa, @function
dbg_cmd_rsa:                            # fn_40005c78
	entry	a1, 48                  # 40005c78
	# p = (volatile unsigned *)0xB70910FC;
	l32r	a4, lit_3ffe1e20        # 40005c7b  = 0xb70910fc
	s32i.n	a4, a1, 0               # 40005c7e
	# *p = 0x68500DEF;
	l32i.n	a3, a1, 0               # 40005c80
	l32r	a2, lit_3ffe1e24        # 40005c82  = 0x68500def
	memw                            # 40005c85
	s32i.n	a2, a3, 0               # 40005c88
	retw.n                          # 40005c8a
	.size	dbg_cmd_rsa, . - dbg_cmd_rsa
