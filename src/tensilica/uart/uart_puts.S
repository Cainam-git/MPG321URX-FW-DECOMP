# uart_puts  (fn_400091d0): 0x400091d0-0x400091f0 (firmware file offset 0x391d0-0x391f0), 14 instructions
# Name basis: derived - only caller dbg_printf passes its formatted buffer; firmware texts 'UART TX Test'
# Called from: dbg_printf
# Sends a text through uart_send_text and turns its result into 0 or -1. Only caller: dbg_printf
# (dbg_printf), which passes the text it has just formatted.
# Arguments: a2 text (address of a zero-ended text).
# Locals: a1+16 text (argument), a1+0 result.
# Returns: 0 when uart_send_text returned 0 or more, -1 when it returned a negative value (text address 0).
# Calls: uart_send_text

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	uart_puts, @function
uart_puts:                              # fn_400091d0
	entry	a1, 64                  # 400091d0
# if (uart_send_text(text) < 0) result = -1; else result = 0;
	s32i.n	a2, a1, 16              # 400091d3
	l32i.n	a10, a1, 16             # 400091d5
	call8	uart_send_text          # 400091d7
	movi.n	a11, 0                  # 400091da
	blt	a10, a11, .L400091e6    # 400091dc
	movi.n	a12, 0                  # 400091df
	s32i.n	a12, a1, 0              # 400091e1
	j	.L400091ed              # 400091e3
.L400091e6:
	movi.n	a13, -1                 # 400091e6
	s32i.n	a13, a1, 0              # 400091e8
	j	.L400091ed              # 400091ea
.L400091ed:
# return result;
	l32i.n	a2, a1, 0               # 400091ed
	retw.n                          # 400091ef
	.size	uart_puts, . - uart_puts
