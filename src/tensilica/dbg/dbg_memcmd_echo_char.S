# dbg_memcmd_echo_char  (fn_400038e8): 0x400038e8-0x40003903 (firmware file offset 0x338e8-0x33903), 10 instructions
# Name basis: derived - uart_putc writes 0xE00A0000; gated by dbg_memcmd_verbose
# Called from: dbg_memcmd_poll_console
# Calls: uart_putc
# Addresses loaded: dbg_memcmd_verbose
#
# Sends one character to the serial port (uart_putc: waits for bit 5 of 0xE00A0014, writes 0xE00A0000) when the
# byte flag dbg_memcmd_verbose is not 0. Used by the line reader of the second command console (dbg_memcmd_poll_console) to echo
# what is typed.
# Arguments: a2 = ch (8-bit).
# Locals: a1+0 = ch.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_memcmd_echo_char, @function
dbg_memcmd_echo_char:                   # fn_400038e8
	entry	a1, 48                  # 400038e8
	extui	a2, a2, 0, 8            # 400038eb
	s8i	a2, a1, 0               # 400038ee
	# if (dbg_memcmd_verbose != 0) uart_putc(ch)
	movi.n	a5, 0                   # 400038f1
	l32r	a4, lit_3ffe1ce0        # 400038f3  = dbg_memcmd_verbose
	l8ui	a4, a4, 0               # 400038f6
	beq	a4, a5, .L40003902      # 400038f9
	l8ui	a10, a1, 0              # 400038fc
	call8	uart_putc               # 400038ff
.L40003902:
	retw.n                          # 40003902
	.size	dbg_memcmd_echo_char, . - dbg_memcmd_echo_char
