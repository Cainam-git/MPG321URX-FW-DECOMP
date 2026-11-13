# dbg_run_text_command  (fn_40004fc0): 0x40004fc0-0x4000504e (firmware file offset 0x34fc0-0x3504e), 58 instructions
# Name basis: proven - prints ' OK.', 'Command Not Found!', 'TDBG >>'; calls the table lookup
#   dbg_find_and_run_command
# Called from: dbg_console_poll
# Runs one typed command line: splits it into words (dbg_split_command_words), looks the first word up in the command table
# at dbg_command_table and runs it (dbg_find_and_run_command), prints "<command> OK." or "Command Not Found!", clears the words and
# the word count, then prints the prompt "TDBG >>".
# Arguments: a2 line (the typed line, con.line at 0x3ffe42f0).
# Locals: a1+0 split result, a1+4 i (word index), a1+8 j (byte index).
# Returns: 0.
# Note: an empty line (split result -1) prints only the prompt and leaves the words as they are.
# Calls: dbg_split_command_words, dbg_find_and_run_command, dbg_printf
# Text loaded: " OK.\n\r", "\n\rCommand Not Found!\n\r", "TDBG >>"
# Addresses loaded: ro_3ffe08e8
# Other literal values: 0x3ffe4240, 0x3ffe4270

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_run_text_command, @function
dbg_run_text_command:                   # fn_40004fc0
	entry	a1, 64                  # 40004fc0
	s32i.n	a2, a1, 16              # 40004fc3
	# if (dbg_split_command_words(line, &con.word_count, con.words) == 0) {
	l32i.n	a10, a1, 16             # 40004fc5
	l32r	a11, lit_3ffe1d70       # 40004fc7  = 0x3ffe4240
	l32r	a12, lit_3ffe1d74       # 40004fca  = 0x3ffe4270
	call8	dbg_split_command_words # 40004fcd
	s32i.n	a10, a1, 0              # 40004fd0
	movi.n	a12, 0                  # 40004fd2
	l32i.n	a11, a1, 0              # 40004fd4
	bne	a11, a12, .L40005045    # 40004fd6
	# if (dbg_find_and_run_command(con.words) == 0) {   /* command found and run */
	l32r	a10, lit_3ffe1d74       # 40004fd9  = 0x3ffe4270
	call8	dbg_find_and_run_command # 40004fdc
	movi.n	a13, 0                  # 40004fdf
	bne	a10, a13, .L40004ff9    # 40004fe1
	# printf("\n\r"); printf(con.words[0]); printf(" OK.\n\r");
	l32r	a10, lit_3ffe1d6c       # 40004fe4  = ro_3ffe08e8
	call8	dbg_printf              # 40004fe7
	l32r	a10, lit_3ffe1d74       # 40004fea  = 0x3ffe4270
	call8	dbg_printf              # 40004fed
	l32r	a10, lit_3ffe1d78       # 40004ff0  = ro_3ffe08ec " OK.\n\r"
	call8	dbg_printf              # 40004ff3
	j	.L40004fff              # 40004ff6
.L40004ff9:
	# } else printf("\n\rCommand Not Found!\n\r");
	l32r	a10, lit_3ffe1d7c       # 40004ff9  = ro_3ffe08f4 "\n\rCommand Not Found!\n\r"
	call8	dbg_printf              # 40004ffc
.L40004fff:
	# for (i = 0; i < 4; i++)
	movi.n	a15, 0                  # 40004fff
	s32i.n	a15, a1, 4              # 40005001
	l32i.n	a14, a1, 4              # 40005003
	bgei	a14, 4, .L4000503e      # 40005005
.L40005008:
	# for (j = 0; j <= 31; j++)
	movi.n	a4, 0                   # 40005008
	s32i.n	a4, a1, 8               # 4000500a
	l32i.n	a3, a1, 8               # 4000500c
	movi.n	a2, 31                  # 4000500e
	blt	a2, a3, .L40005033      # 40005010
.L40005013:
	# con.words[i][j] = 0;
	l32r	a10, lit_3ffe1d74       # 40005013  = 0x3ffe4270
	l32i.n	a11, a1, 4              # 40005016
	slli	a11, a11, 5             # 40005018
	l32i.n	a9, a1, 8               # 4000501b
	add.n	a9, a9, a11             # 4000501d
	add.n	a9, a9, a10             # 4000501f
	movi.n	a8, 0                   # 40005021
	s8i	a8, a9, 0               # 40005023
	l32i.n	a7, a1, 8               # 40005026
	addi.n	a7, a7, 1               # 40005028
	s32i.n	a7, a1, 8               # 4000502a
	l32i.n	a6, a1, 8               # 4000502c
	movi.n	a5, 31                  # 4000502e
	bge	a5, a6, .L40005013      # 40005030
.L40005033:
	l32i.n	a13, a1, 4              # 40005033
	addi.n	a13, a13, 1             # 40005035
	s32i.n	a13, a1, 4              # 40005037
	l32i.n	a12, a1, 4              # 40005039
	blti	a12, 4, .L40005008      # 4000503b
.L4000503e:
	# con.word_count = 0; }
	l32r	a15, lit_3ffe1d70       # 4000503e  = 0x3ffe4240
	movi.n	a14, 0                  # 40005041
	s32i.n	a14, a15, 0             # 40005043
.L40005045:
	# printf("TDBG >>"); return 0;
	l32r	a10, lit_3ffe1d80       # 40005045  = ro_3ffe090c "TDBG >>"
	call8	dbg_printf              # 40005048
	movi.n	a2, 0                   # 4000504b
	retw.n                          # 4000504d
	.size	dbg_run_text_command, . - dbg_run_text_command
