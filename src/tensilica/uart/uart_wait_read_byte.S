# uart_wait_read_byte  (fn_40009ee8): 0x40009ee8-0x40009f0f (firmware file offset 0x39ee8-0x39f0f), 15 instructions
# Name basis: derived - code; caller uart_getchar (UART RX test)
# Called from: uart_getchar
# Waits until bit 0 of 0xE00A0014 is set and returns the word at 0xE00A0000. Caller: uart_getchar.
# Arguments: none.
# Locals: none.
# Returns: the value read from 0xE00A0000.
# Other literal values: 0xe00a0014, 0xe00a0000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	uart_wait_read_byte, @function
uart_wait_read_byte:                    # fn_40009ee8
	entry	a1, 32                  # 40009ee8
# while (!(reg[0xE00A0014] & 1));
	l32r	a2, lit_3ffe2318        # 40009eeb  = 0xe00a0014
	memw                            # 40009eee
	l32i.n	a2, a2, 0               # 40009ef1
	bbsi	a2, 0, .L40009f06       # 40009ef3
.L40009ef6:
	movi.n	a4, 0                   # 40009ef6
	l32r	a3, lit_3ffe2318        # 40009ef8  = 0xe00a0014
	memw                            # 40009efb
	l32i.n	a3, a3, 0               # 40009efe
	extui	a3, a3, 0, 1            # 40009f00
	beq	a3, a4, .L40009ef6      # 40009f03
.L40009f06:
# return reg[0xE00A0000];
	l32r	a2, lit_3ffe2300        # 40009f06  = 0xe00a0000
	memw                            # 40009f09
	l32i.n	a2, a2, 0               # 40009f0c
	retw.n                          # 40009f0e
	.size	uart_wait_read_byte, . - uart_wait_read_byte
