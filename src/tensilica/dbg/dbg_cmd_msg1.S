# dbg_cmd_msg1  (fn_40005c8c): 0x40005c8c-0x40005c9a (firmware file offset 0x35c8c-0x35c9a), 6 instructions
# Name basis: derived - command table entry 'msg1'
# Address stored in the words at: 0x4000b444
# Command "msg1" of the debug command line (table entry at 0x4000b444): writes 1 to 0xE0091084 (mailbox portal
# 2 as this program addresses it, offset 0x84).
# Arguments: none used.
# Returns: nothing.
# Other literal values: 0xe0091084

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_cmd_msg1, @function
dbg_cmd_msg1:                           # fn_40005c8c
	entry	a1, 32                  # 40005c8c
	# *(volatile unsigned *)0xE0091084 = 1;
	l32r	a3, lit_3ffe1bf4        # 40005c8f  = 0xe0091084
	movi.n	a2, 1                   # 40005c92
	memw                            # 40005c94
	s32i.n	a2, a3, 0               # 40005c97
	retw.n                          # 40005c99
	.size	dbg_cmd_msg1, . - dbg_cmd_msg1
