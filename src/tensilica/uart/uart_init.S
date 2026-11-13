# uart_init  (fn_40009ca8): 0x40009ca8-0x40009de4 (firmware file offset 0x39ca8-0x39de4), 124 instructions
# Name basis: derived - called by dbg_init_uart_print_banner with dbg_uart_config before the banner prints
# Called from: dbg_init_uart_print_banner
# Sets up the serial port block 0xE00A0000 from a settings record: clears bits 0..2 of 0xE00A0004, writes the
# divisor (uart_set_baud_divisor) and the line format (uart_set_line_format), steps the bits of 0xE00A0008
# through its memory copy at 0x3ffe5cd0 (bit 0 off, bit 1 on, bit 1 off, bit 2 on, bit 2 off, bit 3 on, bit 0 on,
# writing the copy after each step), writes 1 to 0xE00A0004, installs uart_rx_irq_handler as the
# handler of interrupt 2, clears and enables interrupt 2 (mask 4) and sets up line bit 2 of block 0xE00A1000
# the way irq_line_init does. Caller: dbg_init_uart_print_banner with dbg_uart_config.
# Arguments: a2 cfg (serial port settings record: +0 baud, +4 / +8 / +12 line format fields).
# Locals: a1+0 cfg (argument).
# Data: 0x3ffe5cd0 uart_rx_state: +0 reg8_copy (copy of the value written to 0xE00A0008), +4 ring[128] words,
#   +0x204 head (write index), +0x208 tail (read index).
# Returns: nothing.
# Calls: uart_set_baud_divisor, uart_set_line_format, irq_set_handler, irq_install_step_empty, irq_clear,
#        irq_enable
# Addresses loaded: uart_rx_irq_handler
# Other literal values: 0xe00a0004, 0x3ffe5cd0, 0xe00a0008, 0xe00a106c, 0xe00a1070, 0xe00a1068

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	uart_init, @function
uart_init:                              # fn_40009ca8
	entry	a1, 48                  # 40009ca8
	s32i.n	a2, a1, 0               # 40009cab
# reg[0xE00A0004] &= ~7;
	l32r	a12, lit_3ffe2304       # 40009cad  = 0xe00a0004
	movi.n	a13, -8                 # 40009cb0
	l32r	a11, lit_3ffe2304       # 40009cb2  = 0xe00a0004
	memw                            # 40009cb5
	l32i.n	a11, a11, 0             # 40009cb8
	and	a11, a11, a13           # 40009cba
	memw                            # 40009cbd
	s32i.n	a11, a12, 0             # 40009cc0
# uart_set_baud_divisor(cfg); uart_set_line_format(cfg);
	l32i.n	a10, a1, 0              # 40009cc2
	call8	uart_set_baud_divisor   # 40009cc4
	l32i.n	a10, a1, 0              # 40009cc7
	call8	uart_set_line_format    # 40009cc9
# uart_rx_state.reg8_copy &= ~1; reg[0xE00A0008] = uart_rx_state.reg8_copy;
	l32r	a13, lit_3ffe230c       # 40009ccc  = 0x3ffe5cd0
	movi.n	a14, -2                 # 40009ccf
	l32r	a12, lit_3ffe230c       # 40009cd1  = 0x3ffe5cd0
	l32i.n	a12, a12, 0             # 40009cd4
	and	a12, a12, a14           # 40009cd6
	s32i.n	a12, a13, 0             # 40009cd9
	l32r	a12, lit_3ffe2310       # 40009cdb  = 0xe00a0008
	l32r	a11, lit_3ffe230c       # 40009cde  = 0x3ffe5cd0
	l32i.n	a11, a11, 0             # 40009ce1
	memw                            # 40009ce3
	s32i.n	a11, a12, 0             # 40009ce6
# uart_rx_state.reg8_copy |= 2; reg[0xE00A0008] = uart_rx_state.reg8_copy;
	l32r	a11, lit_3ffe230c       # 40009ce8  = 0x3ffe5cd0
	movi.n	a12, 2                  # 40009ceb
	l32r	a10, lit_3ffe230c       # 40009ced  = 0x3ffe5cd0
	l32i.n	a10, a10, 0             # 40009cf0
	or	a10, a10, a12           # 40009cf2
	s32i.n	a10, a11, 0             # 40009cf5
	l32r	a10, lit_3ffe2310       # 40009cf7  = 0xe00a0008
	l32r	a9, lit_3ffe230c        # 40009cfa  = 0x3ffe5cd0
	l32i.n	a9, a9, 0               # 40009cfd
	memw                            # 40009cff
	s32i.n	a9, a10, 0              # 40009d02
# uart_rx_state.reg8_copy &= ~2; reg[0xE00A0008] = uart_rx_state.reg8_copy;
	l32r	a9, lit_3ffe230c        # 40009d04  = 0x3ffe5cd0
	movi.n	a10, -3                 # 40009d07
	l32r	a8, lit_3ffe230c        # 40009d09  = 0x3ffe5cd0
	l32i.n	a8, a8, 0               # 40009d0c
	and	a8, a8, a10             # 40009d0e
	s32i.n	a8, a9, 0               # 40009d11
	l32r	a8, lit_3ffe2310        # 40009d13  = 0xe00a0008
	l32r	a7, lit_3ffe230c        # 40009d16  = 0x3ffe5cd0
	l32i.n	a7, a7, 0               # 40009d19
	memw                            # 40009d1b
	s32i.n	a7, a8, 0               # 40009d1e
# uart_rx_state.reg8_copy |= 4; reg[0xE00A0008] = uart_rx_state.reg8_copy;
	l32r	a7, lit_3ffe230c        # 40009d20  = 0x3ffe5cd0
	movi.n	a8, 4                   # 40009d23
	l32r	a6, lit_3ffe230c        # 40009d25  = 0x3ffe5cd0
	l32i.n	a6, a6, 0               # 40009d28
	or	a6, a6, a8              # 40009d2a
	s32i.n	a6, a7, 0               # 40009d2d
	l32r	a6, lit_3ffe2310        # 40009d2f  = 0xe00a0008
	l32r	a5, lit_3ffe230c        # 40009d32  = 0x3ffe5cd0
	l32i.n	a5, a5, 0               # 40009d35
	memw                            # 40009d37
	s32i.n	a5, a6, 0               # 40009d3a
# uart_rx_state.reg8_copy &= ~4; reg[0xE00A0008] = uart_rx_state.reg8_copy;
	l32r	a5, lit_3ffe230c        # 40009d3c  = 0x3ffe5cd0
	movi.n	a6, -5                  # 40009d3f
	l32r	a4, lit_3ffe230c        # 40009d41  = 0x3ffe5cd0
	l32i.n	a4, a4, 0               # 40009d44
	and	a4, a4, a6              # 40009d46
	s32i.n	a4, a5, 0               # 40009d49
	l32r	a4, lit_3ffe2310        # 40009d4b  = 0xe00a0008
	l32r	a3, lit_3ffe230c        # 40009d4e  = 0x3ffe5cd0
	l32i.n	a3, a3, 0               # 40009d51
	memw                            # 40009d53
	s32i.n	a3, a4, 0               # 40009d56
# uart_rx_state.reg8_copy |= 8; reg[0xE00A0008] = uart_rx_state.reg8_copy;
	l32r	a3, lit_3ffe230c        # 40009d58  = 0x3ffe5cd0
	movi.n	a4, 8                   # 40009d5b
	l32r	a2, lit_3ffe230c        # 40009d5d  = 0x3ffe5cd0
	l32i.n	a2, a2, 0               # 40009d60
	or	a2, a2, a4              # 40009d62
	s32i.n	a2, a3, 0               # 40009d65
	l32r	a2, lit_3ffe2310        # 40009d67  = 0xe00a0008
	l32r	a15, lit_3ffe230c       # 40009d6a  = 0x3ffe5cd0
	l32i.n	a15, a15, 0             # 40009d6d
	memw                            # 40009d6f
	s32i.n	a15, a2, 0              # 40009d72
# uart_rx_state.reg8_copy |= 1; reg[0xE00A0008] = uart_rx_state.reg8_copy;
	l32r	a15, lit_3ffe230c       # 40009d74  = 0x3ffe5cd0
	movi.n	a2, 1                   # 40009d77
	l32r	a14, lit_3ffe230c       # 40009d79  = 0x3ffe5cd0
	l32i.n	a14, a14, 0             # 40009d7c
	or	a14, a14, a2            # 40009d7e
	s32i.n	a14, a15, 0             # 40009d81
	l32r	a14, lit_3ffe2310       # 40009d83  = 0xe00a0008
	l32r	a13, lit_3ffe230c       # 40009d86  = 0x3ffe5cd0
	l32i.n	a13, a13, 0             # 40009d89
	memw                            # 40009d8b
	s32i.n	a13, a14, 0             # 40009d8e
# reg[0xE00A0004] = 1;
	l32r	a12, lit_3ffe2304       # 40009d90  = 0xe00a0004
	movi.n	a11, 1                  # 40009d93
	memw                            # 40009d95
	s32i.n	a11, a12, 0             # 40009d98
# irq_set_handler(2, uart_rx_irq_handler);   (install the handler of interrupt 2)
	movi.n	a10, 2                  # 40009d9a
	l32r	a11, lit_3ffe2314       # 40009d9c  = uart_rx_irq_handler
	call8	irq_set_handler         # 40009d9f
# irq_install_step_empty();   (returns at once)
	call8	irq_install_step_empty  # 40009da2
# irq_clear(4); irq_enable(4);   (clear, then enable interrupt 2)
	movi.n	a10, 4                  # 40009da5
	call8	irq_clear               # 40009da7
	movi.n	a10, 4                  # 40009daa
	call8	irq_enable              # 40009dac
# reg[0xE00A106C] |= 4;
	l32r	a3, lit_3ffe221c        # 40009daf  = 0xe00a106c
	movi.n	a4, 4                   # 40009db2
	l32r	a2, lit_3ffe221c        # 40009db4  = 0xe00a106c
	memw                            # 40009db7
	l32i.n	a2, a2, 0               # 40009dba
	or	a2, a2, a4              # 40009dbc
	memw                            # 40009dbf
	s32i.n	a2, a3, 0               # 40009dc2
# reg[0xE00A1070] = 4;
	l32r	a15, lit_3ffe2220       # 40009dc4  = 0xe00a1070
	movi.n	a14, 4                  # 40009dc7
	memw                            # 40009dc9
	s32i.n	a14, a15, 0             # 40009dcc
# reg[0xE00A1068] &= ~4;
	l32r	a14, lit_3ffe2224       # 40009dce  = 0xe00a1068
	movi.n	a15, -5                 # 40009dd1
	l32r	a13, lit_3ffe2224       # 40009dd3  = 0xe00a1068
	memw                            # 40009dd6
	l32i.n	a13, a13, 0             # 40009dd9
	and	a13, a13, a15           # 40009ddb
	memw                            # 40009dde
	s32i.n	a13, a14, 0             # 40009de1
	retw.n                          # 40009de3
	.size	uart_init, . - uart_init
