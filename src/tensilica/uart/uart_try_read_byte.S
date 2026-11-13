# uart_try_read_byte  (fn_40009ec0): 0x40009ec0-0x40009ee7 (firmware file offset 0x39ec0-0x39ee7), 16 instructions
# Name basis: derived - code; caller dbg_memcmd_poll_console
# Called from: dbg_memcmd_poll_console
# Returns the word at 0xE00A0000 when bit 0 of 0xE00A0014 is set, else -1, without waiting.
# Caller: dbg_memcmd_poll_console.
# Arguments: none.
# Locals: a1+0 result.
# Returns: the value read from 0xE00A0000, or -1 when bit 0 of 0xE00A0014 is clear.
# Other literal values: 0xe00a0014, 0xe00a0000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	uart_try_read_byte, @function
uart_try_read_byte:                     # fn_40009ec0
	entry	a1, 48                  # 40009ec0
# if (reg[0xE00A0014] & 1) result = reg[0xE00A0000];
	l32r	a2, lit_3ffe2318        # 40009ec3  = 0xe00a0014
	memw                            # 40009ec6
	l32i.n	a2, a2, 0               # 40009ec9
	extui	a2, a2, 0, 1            # 40009ecb
	beqz.n	a2, .L40009edd          # 40009ece
	l32r	a3, lit_3ffe2300        # 40009ed0  = 0xe00a0000
	memw                            # 40009ed3
	l32i.n	a3, a3, 0               # 40009ed6
	s32i.n	a3, a1, 0               # 40009ed8
	j	.L40009ee4              # 40009eda
.L40009edd:
# else result = -1;
	movi.n	a4, -1                  # 40009edd
	s32i.n	a4, a1, 0               # 40009edf
	j	.L40009ee4              # 40009ee1
.L40009ee4:
# return result;
	l32i.n	a2, a1, 0               # 40009ee4
	retw.n                          # 40009ee6
	.size	uart_try_read_byte, . - uart_try_read_byte
