# fn_40005de8: 0x40005de8-0x40005e40 (firmware file offset 0x35de8-0x35e40), 30 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_400099bc, fn_40009a90, fn_400091f4
# Text loaded: "*** UART TX Test Start ***\n", "*** UART TX Test End ***\n\n",
#              "*** UART RX Test Start ***\n", "Please input a character ('q' to exit):\n",
#              "User input: \\n\n", "User input: %c\n", "*** UART RX Test End ***\n\n", "UART test done!\n"
# 1 instruction after an unconditional jump or return: no branch, jump, call or stored address leads to it.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005de8, @function
fn_40005de8:
	entry	a1, 48                  # 40005de8
	l32r	a10, lit_3ffe1e40       # 40005deb  = ro_3ffe09e4 "*** UART TX Test Start ***\n"
	call8	fn_400099bc             # 40005dee
	call8	fn_40009a90             # 40005df1
	l32r	a10, lit_3ffe1e44       # 40005df4  = ro_3ffe0a00 "*** UART TX Test End ***\n\n"
	call8	fn_400099bc             # 40005df7
	l32r	a10, lit_3ffe1e48       # 40005dfa  = ro_3ffe0a1c "*** UART RX Test Start ***\n"
	call8	fn_400099bc             # 40005dfd
.L40005e00:
	l32r	a10, lit_3ffe1e4c       # 40005e00  = ro_3ffe0a38 "Please input a character ('q' to exit):\n"
	call8	fn_400099bc             # 40005e03
	call8	fn_400091f4             # 40005e06
	s8i	a10, a1, 0              # 40005e09
	movi	a3, 113                 # 40005e0c
	l8ui	a2, a1, 0               # 40005e0f
	beq	a2, a3, .L40005e30      # 40005e12
	l8ui	a4, a1, 0               # 40005e15
	bnei	a4, 10, .L40005e24      # 40005e18
	l32r	a10, lit_3ffe1e50       # 40005e1b  = ro_3ffe0a64 "User input: \\n\n"
	call8	fn_400099bc             # 40005e1e
	j	.L40005e2d              # 40005e21
.L40005e24:
	l32r	a10, lit_3ffe1e54       # 40005e24  = ro_3ffe0a74 "User input: %c\n"
	l8ui	a11, a1, 0              # 40005e27
	call8	fn_400099bc             # 40005e2a
.L40005e2d:
	j	.L40005e00              # 40005e2d
.L40005e30:
	l32r	a10, lit_3ffe1e58       # 40005e30  = ro_3ffe0a84 "*** UART RX Test End ***\n\n"
	call8	fn_400099bc             # 40005e33
	l32r	a10, lit_3ffe1e5c       # 40005e36  = ro_3ffe0aa0 "UART test done!\n"
	call8	fn_400099bc             # 40005e39
.L40005e3c:
	j	.L40005e3c              # 40005e3c
	retw.n                          # 40005e3f
	.size	fn_40005de8, . - fn_40005de8
