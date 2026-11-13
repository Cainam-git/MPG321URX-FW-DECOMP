# uart_selftest  (fn_40005de8): 0x40005de8-0x40005e40 (firmware file offset 0x35de8-0x35e40), 30 instructions
# Name basis: proven - texts 'UART TX/RX Test', 'UART test done!'; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Serial port test: prints the TX test texts around uart_print_tx_test_lines (which prints test lines), then repeatedly asks
# for a character (uart_getchar) and echoes it until 'q' is typed, prints "UART test done!" and stays in an endless
# loop. Nothing calls it and no stored word holds its address.
# Arguments: none.
# Locals: a1+0 c (character read).
# Returns: never.
# Calls: dbg_printf, uart_print_tx_test_lines, uart_getchar
# Text loaded: "*** UART TX Test Start ***\n", "*** UART TX Test End ***\n\n",
#              "*** UART RX Test Start ***\n", "Please input a character ('q' to exit):\n",
#              "User input: \\n\n", "User input: %c\n", "*** UART RX Test End ***\n\n", "UART test done!\n"
# 1 instruction after an unconditional jump or return: no branch, jump, call or stored address leads to it.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	uart_selftest, @function
uart_selftest:                          # fn_40005de8
	entry	a1, 48                  # 40005de8
	# printf("*** UART TX Test Start ***\n"); uart_print_tx_test_lines(); printf("*** UART TX Test End ***\n\n");
	l32r	a10, lit_3ffe1e40       # 40005deb  = ro_3ffe09e4 "*** UART TX Test Start ***\n"
	call8	dbg_printf              # 40005dee
	call8	uart_print_tx_test_lines # 40005df1
	l32r	a10, lit_3ffe1e44       # 40005df4  = ro_3ffe0a00 "*** UART TX Test End ***\n\n"
	call8	dbg_printf              # 40005df7
	# printf("*** UART RX Test Start ***\n");
	l32r	a10, lit_3ffe1e48       # 40005dfa  = ro_3ffe0a1c "*** UART RX Test Start ***\n"
	call8	dbg_printf              # 40005dfd
.L40005e00:
	# for (;;) { printf("Please input a character ('q' to exit):\n");
	l32r	a10, lit_3ffe1e4c       # 40005e00  = ro_3ffe0a38 "Please input a character ('q' to exit):\n"
	call8	dbg_printf              # 40005e03
	# c = uart_getchar();
	call8	uart_getchar            # 40005e06
	s8i	a10, a1, 0              # 40005e09
	# if (c == 'q') break;
	movi	a3, 113                 # 40005e0c
	l8ui	a2, a1, 0               # 40005e0f
	beq	a2, a3, .L40005e30      # 40005e12
	# if (c == '\n') printf("User input: \\n\n");
	l8ui	a4, a1, 0               # 40005e15
	bnei	a4, 10, .L40005e24      # 40005e18
	l32r	a10, lit_3ffe1e50       # 40005e1b  = ro_3ffe0a64 "User input: \\n\n"
	call8	dbg_printf              # 40005e1e
	j	.L40005e2d              # 40005e21
.L40005e24:
	# else printf("User input: %c\n", c);
	l32r	a10, lit_3ffe1e54       # 40005e24  = ro_3ffe0a74 "User input: %c\n"
	l8ui	a11, a1, 0              # 40005e27
	call8	dbg_printf              # 40005e2a
.L40005e2d:
	# }
	j	.L40005e00              # 40005e2d
.L40005e30:
	# printf("*** UART RX Test End ***\n\n"); printf("UART test done!\n");
	l32r	a10, lit_3ffe1e58       # 40005e30  = ro_3ffe0a84 "*** UART RX Test End ***\n\n"
	call8	dbg_printf              # 40005e33
	l32r	a10, lit_3ffe1e5c       # 40005e36  = ro_3ffe0aa0 "UART test done!\n"
	call8	dbg_printf              # 40005e39
.L40005e3c:
	# for (;;) ;   /* the retw.n after it is never reached */
	j	.L40005e3c              # 40005e3c
	retw.n                          # 40005e3f
	.size	uart_selftest, . - uart_selftest
