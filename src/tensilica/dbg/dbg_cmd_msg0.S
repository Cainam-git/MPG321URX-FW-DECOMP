# dbg_cmd_msg0  (fn_40005c9c): 0x40005c9c-0x40005caa (firmware file offset 0x35c9c-0x35caa), 6 instructions
# Name basis: derived - command table entry 'msg0'
# Address stored in the words at: 0x4000b468
# Command "msg0" of the debug command line (table entry at 0x4000b468): writes 0 to 0xE0091084 (mailbox portal
# 2 as this program addresses it, offset 0x84).
# Arguments: none used.
# Returns: nothing.
# Other literal values: 0xe0091084

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_cmd_msg0, @function
dbg_cmd_msg0:                           # fn_40005c9c
	entry	a1, 32                  # 40005c9c
	# *(volatile unsigned *)0xE0091084 = 0;
	l32r	a3, lit_3ffe1bf4        # 40005c9f  = 0xe0091084
	movi.n	a2, 0                   # 40005ca2
	memw                            # 40005ca4
	s32i.n	a2, a3, 0               # 40005ca7
	retw.n                          # 40005ca9
	.size	dbg_cmd_msg0, . - dbg_cmd_msg0
