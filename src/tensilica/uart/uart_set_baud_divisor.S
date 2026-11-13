# uart_set_baud_divisor  (fn_40009b50): 0x40009b50-0x40009bc6 (firmware file offset 0x39b50-0x39bc6), 47 instructions
# Name basis: derived - baud word of dbg_uart_config (115200); called by uart_init
# Called from: uart_init
# Computes the divisor (48 * 1000000 >> 4) / baud from the first word of the serial port settings record and
# writes it: bit 7 of 0xE00A000C is set, the low byte goes to 0xE00A0000, the rest to 0xE00A0004, the whole
# divisor to mailbox word 0xE009101C, then bit 7 of 0xE00A000C is cleared. For the program's settings
# (dbg_uart_config, 115200) the divisor is 26. Caller: uart_init.
# Arguments: a2 cfg (serial port settings record; +0 baud).
# Locals: a1+16 cfg (argument), a1+0 baud, a1+4 clock_mhz (48), a1+8 divisor.
# Returns: nothing.
# Other literal values: 0x000f4240, 0xe00a000c, 0xe00a0000, 0xe00a0004, 0xe009101c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	uart_set_baud_divisor, @function
uart_set_baud_divisor:                  # fn_40009b50
	entry	a1, 64                  # 40009b50
	s32i.n	a2, a1, 16              # 40009b53
# baud = cfg->baud; clock_mhz = 48; divisor = 0;
	l32i.n	a15, a1, 16             # 40009b55
	l32i.n	a15, a15, 0             # 40009b57
	s32i.n	a15, a1, 0              # 40009b59
	movi.n	a14, 48                 # 40009b5b
	s32i.n	a14, a1, 4              # 40009b5d
	movi.n	a13, 0                  # 40009b5f
	s32i.n	a13, a1, 8              # 40009b61
# divisor = (clock_mhz * 1000000 >> 4) / baud;
	l32i.n	a11, a1, 0              # 40009b63
	l32r	a12, lit_3ffe22f8       # 40009b65  = 0x000f4240
	l32i.n	a10, a1, 4              # 40009b68
	mull	a10, a10, a12           # 40009b6a
	srli	a10, a10, 4             # 40009b6d
	quou	a10, a10, a11           # 40009b70
	s32i.n	a10, a1, 8              # 40009b73
# reg[0xE00A000C] |= 0x80;
	l32r	a10, lit_3ffe22fc       # 40009b75  = 0xe00a000c
	movi	a11, 128                # 40009b78
	l32r	a9, lit_3ffe22fc        # 40009b7b  = 0xe00a000c
	memw                            # 40009b7e
	l32i.n	a9, a9, 0               # 40009b81
	or	a9, a9, a11             # 40009b83
	memw                            # 40009b86
	s32i.n	a9, a10, 0              # 40009b89
# reg[0xE00A0000] = divisor & 0xFF;
	l32r	a9, lit_3ffe2300        # 40009b8b  = 0xe00a0000
	l32i.n	a8, a1, 8               # 40009b8e
	extui	a8, a8, 0, 8            # 40009b90
	memw                            # 40009b93
	s32i.n	a8, a9, 0               # 40009b96
# reg[0xE00A0004] = divisor >> 8;
	l32r	a8, lit_3ffe2304        # 40009b98  = 0xe00a0004
	l32i.n	a7, a1, 8               # 40009b9b
	srli	a7, a7, 8               # 40009b9d
	memw                            # 40009ba0
	s32i.n	a7, a8, 0               # 40009ba3
# reg[0xE009101C] = divisor;   (mailbox word +0x1C)
	l32r	a6, lit_3ffe2308        # 40009ba5  = 0xe009101c
	l32i.n	a5, a1, 8               # 40009ba8
	memw                            # 40009baa
	s32i.n	a5, a6, 0               # 40009bad
# reg[0xE00A000C] &= ~0x80;
	l32r	a5, lit_3ffe22fc        # 40009baf  = 0xe00a000c
	movi	a6, -129                # 40009bb2
	l32r	a4, lit_3ffe22fc        # 40009bb5  = 0xe00a000c
	memw                            # 40009bb8
	l32i.n	a4, a4, 0               # 40009bbb
	and	a4, a4, a6              # 40009bbd
	memw                            # 40009bc0
	s32i.n	a4, a5, 0               # 40009bc3
	retw.n                          # 40009bc5
	.size	uart_set_baud_divisor, . - uart_set_baud_divisor
