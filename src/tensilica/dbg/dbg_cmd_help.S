# dbg_cmd_help  (fn_40005c3c): 0x40005c3c-0x40005c76 (firmware file offset 0x35c3c-0x35c76), 24 instructions
# Name basis: proven - command table entry 'help'; prints the help text list
# Address stored in the words at: 0x4000b3fc
# Command "help" of the debug command line (table entry at 0x4000b3fc): prints each text of the NULL-terminated
# list at dbg_help_texts on a new line. The five texts describe "mem", "wmem", "mdw", "proc" and "gpio".
# Arguments: none used.
# Locals: a1+0 i.
# Returns: nothing.
# Calls: dbg_printf
# Text loaded: "\n%s"
# Addresses loaded: dbg_help_texts

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_cmd_help, @function
dbg_cmd_help:                           # fn_40005c3c
	entry	a1, 48                  # 40005c3c
	# for (i = 0; help_texts[i] != NULL; i++)
	movi.n	a5, 0                   # 40005c3f
	s32i.n	a5, a1, 0               # 40005c41
	movi.n	a3, 0                   # 40005c43
	l32i.n	a2, a1, 0               # 40005c45
	l32r	a4, lit_3ffe1e18        # 40005c47  = dbg_help_texts
	addx4	a2, a2, a4              # 40005c4a
	l32i.n	a2, a2, 0               # 40005c4d
	beq	a2, a3, .L40005c75      # 40005c4f
.L40005c52:
	# printf("\n%s", help_texts[i]);
	l32i.n	a11, a1, 0              # 40005c52
	addi.n	a13, a11, 1             # 40005c54
	s32i.n	a13, a1, 0              # 40005c56
	l32r	a10, lit_3ffe1e1c       # 40005c58  = ro_3ffe09d0 "\n%s"
	l32r	a12, lit_3ffe1e18       # 40005c5b  = dbg_help_texts
	addx4	a11, a11, a12           # 40005c5e
	l32i.n	a11, a11, 0             # 40005c61
	call8	dbg_printf              # 40005c63
	movi.n	a15, 0                  # 40005c66
	l32i.n	a14, a1, 0              # 40005c68
	l32r	a2, lit_3ffe1e18        # 40005c6a  = dbg_help_texts
	addx4	a14, a14, a2            # 40005c6d
	l32i.n	a14, a14, 0             # 40005c70
	bne	a14, a15, .L40005c52    # 40005c72
.L40005c75:
	retw.n                          # 40005c75
	.size	dbg_cmd_help, . - dbg_cmd_help
