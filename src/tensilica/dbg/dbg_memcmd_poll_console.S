# dbg_memcmd_poll_console  (fn_40003cd0): 0x40003cd0-0x40003f0d (firmware file offset 0x33cd0-0x33f0d), 221 instructions
# Name basis: derived - text 'Please enter the command: '; table dbg_memcmd_table; uncalled
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: uart_try_read_byte, dbg_memcmd_echo_char, dbg_printf
# Indirect calls (callx): 1
# Text loaded: "Please enter the command: "
# Addresses loaded: dbg_memcmd_verbose, dbg_memcmd_table
# Other literal values: 0x3ffe41c0, 0x3ffe41d0, 0x3ffe4210
#
# Line reader of a second command console with the commands "mr", "mw", "md" and "cfg" (table dbg_memcmd_table,
# {name, handler} pairs; the number of entries is the byte at dbg_memcmd_verbose + 20, the low byte of the word 4 at
# 0x3FFE2714). Takes one character from uart_try_read_byte (negative = none) and edits the line buffer 0x3FFE41D0
# (state 0x3FFE41C0: +0 length, +1 line complete): backspace removes the last character, CR or LF ends the
# line, spaces and tabs are stored as one space except at the start, other characters are stored; characters are
# echoed through dbg_memcmd_echo_char. At the end of a line the first word is compared with the command names;
# on a match the handler gets the text after the word (spaces skipped) and the remaining length. Then the line
# is emptied and, while dbg_memcmd_verbose is not 0, "Please enter the command: " is printed. A line longer than 64
# characters is cut off at 0x3FFE4210 and emptied. Nothing calls this routine and its address is not stored.
# Arguments: none.
# Locals: a1+0 = found, a1+4 = ch, then the table index k, a1+8 = j (position in the line), a1+12 = c (name
# character).
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_memcmd_poll_console, @function
dbg_memcmd_poll_console:                # fn_40003cd0
	entry	a1, 48                  # 40003cd0
	# found = 0
	movi.n	a2, 0                   # 40003cd3
	s8i	a2, a1, 0               # 40003cd5
	# if ((ch = uart_try_read_byte()) < 0) return
	call8	uart_try_read_byte      # 40003cd8
	s32i.n	a10, a1, 4              # 40003cdb
	movi.n	a4, 0                   # 40003cdd
	l32i.n	a3, a1, 4               # 40003cdf
	bge	a3, a4, .L40003ce7      # 40003ce1
	j	.L40003f0c              # 40003ce4
.L40003ce7:
	# if (ch == 8) { if (line.length > 0) { echo(ch); echo(' '); echo(ch); line.length--; line.buf[line.length] = 0; } return; }
	l32i.n	a5, a1, 4               # 40003ce7
	bnei	a5, 8, .L40003d33       # 40003ce9
	movi.n	a7, 0                   # 40003cec
	l32r	a6, lit_3ffe1d20        # 40003cee  = 0x3ffe41c0
	l8ui	a6, a6, 0               # 40003cf1
	beq	a6, a7, .L40003d30      # 40003cf4
	l32i.n	a10, a1, 4              # 40003cf7
	sext	a10, a10, 7             # 40003cf9
	extui	a10, a10, 0, 8          # 40003cfc
	call8	dbg_memcmd_echo_char    # 40003cff
	movi.n	a10, 32                 # 40003d02
	call8	dbg_memcmd_echo_char    # 40003d04
	l32i.n	a10, a1, 4              # 40003d07
	sext	a10, a10, 7             # 40003d09
	extui	a10, a10, 0, 8          # 40003d0c
	call8	dbg_memcmd_echo_char    # 40003d0f
	l32r	a14, lit_3ffe1d20       # 40003d12  = 0x3ffe41c0
	l32r	a13, lit_3ffe1d20       # 40003d15  = 0x3ffe41c0
	l8ui	a13, a13, 0             # 40003d18
	addi.n	a13, a13, -1            # 40003d1b
	s8i	a13, a14, 0             # 40003d1d
	l32r	a13, lit_3ffe1d24       # 40003d20  = 0x3ffe41d0
	l32r	a12, lit_3ffe1d20       # 40003d23  = 0x3ffe41c0
	l8ui	a12, a12, 0             # 40003d26
	add.n	a12, a12, a13           # 40003d29
	movi.n	a11, 0                  # 40003d2b
	s8i	a11, a12, 0             # 40003d2d
.L40003d30:
	j	.L40003f0c              # 40003d30
.L40003d33:
	# if (ch == 9) echo(' '); else echo(ch)
	movi.n	a15, 9                  # 40003d33
	l32i.n	a14, a1, 4              # 40003d35
	bne	a14, a15, .L40003d42    # 40003d37
	movi.n	a10, 32                 # 40003d3a
	call8	dbg_memcmd_echo_char    # 40003d3c
	j	.L40003d4d              # 40003d3f
.L40003d42:
	l32i.n	a10, a1, 4              # 40003d42
	sext	a10, a10, 7             # 40003d44
	extui	a10, a10, 0, 8          # 40003d47
	call8	dbg_memcmd_echo_char    # 40003d4a
.L40003d4d:
	# if (ch == 10 || ch == 13) { echo('\n'); line.buf[line.length] = 0; line.complete = 1; }
	l32i.n	a11, a1, 4              # 40003d4d
	beqi	a11, 10, .L40003d59     # 40003d4f
	movi.n	a13, 13                 # 40003d52
	l32i.n	a12, a1, 4              # 40003d54
	bne	a12, a13, .L40003d79    # 40003d56
.L40003d59:
	movi.n	a10, 10                 # 40003d59
	call8	dbg_memcmd_echo_char    # 40003d5b
	l32r	a4, lit_3ffe1d24        # 40003d5e  = 0x3ffe41d0
	l32r	a3, lit_3ffe1d20        # 40003d61  = 0x3ffe41c0
	l8ui	a3, a3, 0               # 40003d64
	add.n	a3, a3, a4              # 40003d67
	movi.n	a2, 0                   # 40003d69
	s8i	a2, a3, 0               # 40003d6b
	l32r	a15, lit_3ffe1d20       # 40003d6e  = 0x3ffe41c0
	movi.n	a14, 1                  # 40003d71
	s8i	a14, a15, 1             # 40003d73
	j	.L40003dd2              # 40003d76
.L40003d79:
	# else if (ch == ' ' || ch == 9) { if (line.length > 0) line.buf[line.length++] = ' '; }
	l32i.n	a4, a1, 4               # 40003d79
	beqi	a4, 32, .L40003d85      # 40003d7b
	movi.n	a6, 9                   # 40003d7e
	l32i.n	a5, a1, 4               # 40003d80
	bne	a5, a6, .L40003db1      # 40003d82
.L40003d85:
	movi.n	a8, 0                   # 40003d85
	l32r	a7, lit_3ffe1d20        # 40003d87  = 0x3ffe41c0
	l8ui	a7, a7, 0               # 40003d8a
	beq	a7, a8, .L40003dae      # 40003d8d
	l32r	a8, lit_3ffe1d20        # 40003d90  = 0x3ffe41c0
	l8ui	a8, a8, 0               # 40003d93
	l32r	a11, lit_3ffe1d24       # 40003d96  = 0x3ffe41d0
	l32r	a10, lit_3ffe1d20       # 40003d99  = 0x3ffe41c0
	l8ui	a10, a10, 0             # 40003d9c
	add.n	a10, a10, a11           # 40003d9f
	movi.n	a9, 32                  # 40003da1
	s8i	a9, a10, 0              # 40003da3
	l32r	a9, lit_3ffe1d20        # 40003da6  = 0x3ffe41c0
	addi.n	a8, a8, 1               # 40003da9
	s8i	a8, a9, 0               # 40003dab
.L40003dae:
	j	.L40003dd2              # 40003dae
.L40003db1:
	# else line.buf[line.length++] = ch
	l32r	a9, lit_3ffe1d20        # 40003db1  = 0x3ffe41c0
	l8ui	a9, a9, 0               # 40003db4
	l32r	a12, lit_3ffe1d24       # 40003db7  = 0x3ffe41d0
	l32r	a11, lit_3ffe1d20       # 40003dba  = 0x3ffe41c0
	l8ui	a11, a11, 0             # 40003dbd
	add.n	a11, a11, a12           # 40003dc0
	l32i.n	a10, a1, 4              # 40003dc2
	sext	a10, a10, 7             # 40003dc4
	s8i	a10, a11, 0             # 40003dc7
	l32r	a10, lit_3ffe1d20       # 40003dca  = 0x3ffe41c0
	addi.n	a9, a9, 1               # 40003dcd
	s8i	a9, a10, 0              # 40003dcf
.L40003dd2:
	# if (line.complete)
	movi.n	a11, 0                  # 40003dd2
	l32r	a10, lit_3ffe1d20       # 40003dd4  = 0x3ffe41c0
	l8ui	a10, a10, 1             # 40003dd7
	bne	a10, a11, .L40003de0    # 40003dda
	j	.L40003ef1              # 40003ddd
.L40003de0:
	# for (k = 0; k < command_count; k++)
	movi.n	a13, 0                  # 40003de0
	s32i.n	a13, a1, 4              # 40003de2
	l32r	a12, lit_3ffe1ce0       # 40003de4  = dbg_memcmd_verbose
	l8ui	a12, a12, 20            # 40003de7
	l32i.n	a11, a1, 4              # 40003dea
	blt	a11, a12, .L40003df2    # 40003dec
	j	.L40003e85              # 40003def
.L40003df2:
	# for (j = 0; j <= 64; j++)
	movi.n	a2, 0                   # 40003df2
	s32i.n	a2, a1, 8               # 40003df4
	l32i.n	a15, a1, 8              # 40003df6
	movi.n	a14, 64                 # 40003df8
	blt	a14, a15, .L40003e69    # 40003dfa
.L40003dfd:
	# c = table[k].name[j]
	l32i.n	a6, a1, 8               # 40003dfd
	l32i.n	a5, a1, 4               # 40003dff
	l32r	a7, lit_3ffe1d28        # 40003e01  = dbg_memcmd_table
	addx8	a5, a5, a7              # 40003e04
	l32i.n	a5, a5, 0               # 40003e07
	add.n	a5, a5, a6              # 40003e09
	l8ui	a5, a5, 0               # 40003e0b
	s8i	a5, a1, 12              # 40003e0e
	# if (c == 0) { if (line.buf[j] == 0 || line.buf[j] == ' ' || line.buf[j] == 9) found = 1; break; }
	movi.n	a4, 0                   # 40003e11
	l8ui	a3, a1, 12              # 40003e13
	bne	a3, a4, .L40003e4c      # 40003e16
	movi.n	a9, 0                   # 40003e19
	l32r	a10, lit_3ffe1d24       # 40003e1b  = 0x3ffe41d0
	l32i.n	a8, a1, 8               # 40003e1e
	add.n	a8, a8, a10             # 40003e20
	l8ui	a8, a8, 0               # 40003e22
	beq	a8, a9, .L40003e44      # 40003e25
	l32r	a12, lit_3ffe1d24       # 40003e28  = 0x3ffe41d0
	l32i.n	a11, a1, 8              # 40003e2b
	add.n	a11, a11, a12           # 40003e2d
	l8ui	a11, a11, 0             # 40003e2f
	beqi	a11, 32, .L40003e44     # 40003e32
	movi.n	a14, 9                  # 40003e35
	l32r	a15, lit_3ffe1d24       # 40003e37  = 0x3ffe41d0
	l32i.n	a13, a1, 8              # 40003e3a
	add.n	a13, a13, a15           # 40003e3c
	l8ui	a13, a13, 0             # 40003e3e
	bne	a13, a14, .L40003e49    # 40003e41
.L40003e44:
	movi.n	a2, 1                   # 40003e44
	s8i	a2, a1, 0               # 40003e46
.L40003e49:
	j	.L40003e69              # 40003e49
.L40003e4c:
	# if (line.buf[j] != c) break
	l8ui	a4, a1, 12              # 40003e4c
	l32r	a5, lit_3ffe1d24        # 40003e4f  = 0x3ffe41d0
	l32i.n	a3, a1, 8               # 40003e52
	add.n	a3, a3, a5              # 40003e54
	l8ui	a3, a3, 0               # 40003e56
	bne	a3, a4, .L40003e69      # 40003e59
	l32i.n	a8, a1, 8               # 40003e5c
	addi.n	a8, a8, 1               # 40003e5e
	s32i.n	a8, a1, 8               # 40003e60
	l32i.n	a7, a1, 8               # 40003e62
	movi.n	a6, 64                  # 40003e64
	bge	a6, a7, .L40003dfd      # 40003e66
.L40003e69:
	# if (found) break
	movi.n	a10, 0                  # 40003e69
	l8ui	a9, a1, 0               # 40003e6b
	bne	a9, a10, .L40003e85     # 40003e6e
	l32i.n	a13, a1, 4              # 40003e71
	addi.n	a13, a13, 1             # 40003e73
	s32i.n	a13, a1, 4              # 40003e75
	l32r	a12, lit_3ffe1ce0       # 40003e77  = dbg_memcmd_verbose
	l8ui	a12, a12, 20            # 40003e7a
	l32i.n	a11, a1, 4              # 40003e7d
	bge	a11, a12, .L40003e85    # 40003e7f
	j	.L40003df2              # 40003e82
.L40003e85:
	# if (found) { while (j <= 64 && line.buf[j] == ' ') j++;
	movi.n	a15, 0                  # 40003e85
	l8ui	a14, a1, 0              # 40003e87
	beq	a14, a15, .L40003ecd    # 40003e8a
	l32i.n	a3, a1, 8               # 40003e8d
	movi.n	a2, 64                  # 40003e8f
	blt	a2, a3, .L40003eae      # 40003e91
.L40003e94:
	l32r	a5, lit_3ffe1d24        # 40003e94  = 0x3ffe41d0
	l32i.n	a4, a1, 8               # 40003e97
	add.n	a4, a4, a5              # 40003e99
	l8ui	a4, a4, 0               # 40003e9b
	bnei	a4, 32, .L40003eae      # 40003e9e
	l32i.n	a8, a1, 8               # 40003ea1
	addi.n	a8, a8, 1               # 40003ea3
	s32i.n	a8, a1, 8               # 40003ea5
	l32i.n	a7, a1, 8               # 40003ea7
	movi.n	a6, 64                  # 40003ea9
	bge	a6, a7, .L40003e94      # 40003eab
.L40003eae:
	# table[k].handler(&line.buf[j], line.length - j); }
	l32r	a11, lit_3ffe1d24       # 40003eae  = 0x3ffe41d0
	l32i.n	a10, a1, 8              # 40003eb1
	add.n	a10, a10, a11           # 40003eb3
	l32i.n	a12, a1, 8              # 40003eb5
	l32r	a11, lit_3ffe1d20       # 40003eb7  = 0x3ffe41c0
	l8ui	a11, a11, 0             # 40003eba
	sub	a11, a11, a12           # 40003ebd
	l32i.n	a8, a1, 4               # 40003ec0
	l32r	a9, lit_3ffe1d28        # 40003ec2  = dbg_memcmd_table
	addx8	a8, a8, a9              # 40003ec5
	l32i.n	a8, a8, 4               # 40003ec8
	callx8	a8                      # 40003eca
.L40003ecd:
	# line.complete = 0; line.length = 0
	l32r	a2, lit_3ffe1d20        # 40003ecd  = 0x3ffe41c0
	movi.n	a15, 0                  # 40003ed0
	s8i	a15, a2, 1              # 40003ed2
	l32r	a14, lit_3ffe1d20       # 40003ed5  = 0x3ffe41c0
	movi.n	a13, 0                  # 40003ed8
	s8i	a13, a14, 0             # 40003eda
	# if (dbg_memcmd_verbose) printf("Please enter the command: ")
	movi.n	a13, 0                  # 40003edd
	l32r	a12, lit_3ffe1ce0       # 40003edf  = dbg_memcmd_verbose
	l8ui	a12, a12, 0             # 40003ee2
	beq	a12, a13, .L40003eee    # 40003ee5
	l32r	a10, lit_3ffe1d2c       # 40003ee8  = ro_3ffe0614 "Please enter the command: "
	call8	dbg_printf              # 40003eeb
.L40003eee:
	j	.L40003f0c              # 40003eee
.L40003ef1:
	# else if (line.length > 64) { line.buf[64] = 0; line.length = 0; }
	l32r	a4, lit_3ffe1d20        # 40003ef1  = 0x3ffe41c0
	l8ui	a4, a4, 0               # 40003ef4
	movi.n	a3, 64                  # 40003ef7
	bgeu	a3, a4, .L40003f0c      # 40003ef9
	l32r	a8, lit_3ffe1d30        # 40003efc  = 0x3ffe4210
	movi.n	a7, 0                   # 40003eff
	s8i	a7, a8, 0               # 40003f01
	l32r	a6, lit_3ffe1d20        # 40003f04  = 0x3ffe41c0
	movi.n	a5, 0                   # 40003f07
	s8i	a5, a6, 0               # 40003f09
.L40003f0c:
	retw.n                          # 40003f0c
	.size	dbg_memcmd_poll_console, . - dbg_memcmd_poll_console
