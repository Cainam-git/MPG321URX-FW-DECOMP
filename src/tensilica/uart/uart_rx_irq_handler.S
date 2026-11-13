# uart_rx_irq_handler  (fn_40009f10): 0x40009f10-0x40009f6f (firmware file offset 0x39f10-0x39f6f), 37 instructions
# Name basis: derived - installed by uart_init via irq_set_handler(2, ...); ring read by uart_rx_ring_get
# Address stored in the words at: 0x4000d00c
# Handler of interrupt 2 (installed by uart_init): when bit 0 of 0xE00A0014 is set it reads 0xE00A0000 and stores
# the value in the 128-word receive ring of uart_rx_state (0x3ffe5cd0) at head, unless the ring is full (the
# next head would equal tail; the value is then dropped). Always writes 4 to 0xE00A1070 at the end.
# The stored address is in the word at 0x4000d00c (literal used by uart_init).
# Arguments: none.
# Locals: a1+0 c (value read), a1+4 next (next head).
# Returns: nothing.
# Other literal values: 0xe00a0014, 0xe00a0000, 0x3ffe5cd0, 0x3ffe5cd4, 0xe00a1070

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	uart_rx_irq_handler, @function
uart_rx_irq_handler:                    # fn_40009f10
	entry	a1, 48                  # 40009f10
# if (reg[0xE00A0014] & 1) {
	l32r	a2, lit_3ffe2318        # 40009f13  = 0xe00a0014
	memw                            # 40009f16
	l32i.n	a2, a2, 0               # 40009f19
	extui	a2, a2, 0, 1            # 40009f1b
	beqz	a2, .L40009f64          # 40009f1e
#   c = reg[0xE00A0000];
	l32r	a6, lit_3ffe2300        # 40009f21  = 0xe00a0000
	memw                            # 40009f24
	l32i.n	a6, a6, 0               # 40009f27
	s32i.n	a6, a1, 0               # 40009f29
#   next = uart_rx_state.head + 1; if (next > 127) next = 0;
	l32r	a5, lit_3ffe230c        # 40009f2b  = 0x3ffe5cd0
	l32i	a5, a5, 0x204           # 40009f2e
	addi.n	a5, a5, 1               # 40009f31
	s32i.n	a5, a1, 4               # 40009f33
	l32i.n	a4, a1, 4               # 40009f35
	movi	a3, 127                 # 40009f37
	bgeu	a3, a4, .L40009f41      # 40009f3a
	movi.n	a7, 0                   # 40009f3d
	s32i.n	a7, a1, 4               # 40009f3f
.L40009f41:
#   if (next != uart_rx_state.tail) { uart_rx_state.ring[uart_rx_state.head] = c; uart_rx_state.head = next; }
	l32i.n	a9, a1, 4               # 40009f41
	l32r	a8, lit_3ffe230c        # 40009f43  = 0x3ffe5cd0
	l32i	a8, a8, 0x208           # 40009f46
	beq	a8, a9, .L40009f64      # 40009f49
	l32r	a12, lit_3ffe230c       # 40009f4c  = 0x3ffe5cd0
	l32i	a12, a12, 0x204         # 40009f4f
	l32r	a13, lit_3ffe231c       # 40009f52  = 0x3ffe5cd4
	addx4	a12, a12, a13           # 40009f55
	l32i.n	a11, a1, 0              # 40009f58
	s32i.n	a11, a12, 0             # 40009f5a
	l32r	a10, lit_3ffe230c       # 40009f5c  = 0x3ffe5cd0
	l32i.n	a9, a1, 4               # 40009f5f
	s32i	a9, a10, 0x204          # 40009f61
.L40009f64:
# }
# reg[0xE00A1070] = 4;
	l32r	a14, lit_3ffe2220       # 40009f64  = 0xe00a1070
	movi.n	a13, 4                  # 40009f67
	memw                            # 40009f69
	s32i.n	a13, a14, 0             # 40009f6c
	retw.n                          # 40009f6e
	.size	uart_rx_irq_handler, . - uart_rx_irq_handler
