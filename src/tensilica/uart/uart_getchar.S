# uart_getchar  (fn_400091f4): 0x400091f4-0x40009214 (firmware file offset 0x391f4-0x39214), 14 instructions
# Name basis: derived - uart_selftest reads 'Please input a character' through it
# Called from: uart_selftest
# Waits for one received byte through uart_wait_read_byte and returns it; a negative value read
# becomes -1. Caller: uart_selftest, which echoes the byte.
# Arguments: none.
# Locals: a1+0 c (value read), a1+4 result.
# Returns: the value read from 0xE00A0000, or -1 when that value is negative.
# Calls: uart_wait_read_byte

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	uart_getchar, @function
uart_getchar:                           # fn_400091f4
	entry	a1, 48                  # 400091f4
# c = uart_wait_read_byte();
	call8	uart_wait_read_byte     # 400091f7
	s32i.n	a10, a1, 0              # 400091fa
# if (c >= 0) result = c; else result = -1;
	movi.n	a3, 0                   # 400091fc
	l32i.n	a2, a1, 0               # 400091fe
	blt	a2, a3, .L4000920a      # 40009200
	l32i.n	a4, a1, 0               # 40009203
	s32i.n	a4, a1, 4               # 40009205
	j	.L40009211              # 40009207
.L4000920a:
	movi.n	a5, -1                  # 4000920a
	s32i.n	a5, a1, 4               # 4000920c
	j	.L40009211              # 4000920e
.L40009211:
# return result;
	l32i.n	a2, a1, 4               # 40009211
	retw.n                          # 40009213
	.size	uart_getchar, . - uart_getchar
