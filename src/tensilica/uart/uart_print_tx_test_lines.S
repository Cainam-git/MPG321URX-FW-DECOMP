# uart_print_tx_test_lines  (fn_40009a90): 0x40009a90-0x40009b4d (firmware file offset 0x39a90-0x39b4d), 74 instructions
# Name basis: proven - texts 'printf test', 'TEST result should be'; called between UART TX Test Start/End
# Called from: uart_selftest
# Prints the printf test lines of the serial port test: "Hello world!", "printf test", a null pointer with %p,
# 5 with %d, 1 << 31 with %d and %ld, 'a' with %c, 0xFF with %x, 0 with %02x, -3 and -5 with signed / unsigned /
# hex, "%d %s(s)%" with 0 and "message", a "\n", "%d %s(s) with %%" with 0 and "message", then
# "TEST result should be" followed by the text at ro_3ffe180c, which lists the expected lines
# ("        * Hello world!", "        * printf test", "        * 0x00000000 is null pointer", ...).
# Caller: uart_selftest, between "*** UART TX Test Start ***" and "*** UART TX Test End ***".
# Arguments: none.
# Locals: a1+0 text ("Hello world!"), a1+4 ptr (0), a1+8 five (5), a1+12 int_bits (32), a1+16 int_min (1 << 31),
#   a1+20 long_bits (32), a1+24 long_min (1 << 31).
# Returns: nothing.
# Calls: dbg_printf
# Text loaded: "Hello world!", "%s\n", "printf test\n", "%p is null pointer\n", "%d = 5\n",
#              "%d = - max int\n", "%ld = - max long\n", "char %c = 'a'\n", "hex %x = ff\n",
#              "hex %02x = 00\n", "int: signed %d = unsigned %u = hex %x\n",
#              "long: signed %ld = unsigned %lu = hex %lx\n", "%d %s(s)%", "message", "%d %s(s) with %%\n",
#              "TEST result should be \n"
# Addresses loaded: ro_3ffe17dc, ro_3ffe180c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	uart_print_tx_test_lines, @function
uart_print_tx_test_lines:               # fn_40009a90
	entry	a1, 64                  # 40009a90
# text = "Hello world!"; ptr = 0; five = 5;
	l32r	a10, lit_3ffe22b0       # 40009a93  = ro_3ffe16e0 "Hello world!"
	s32i.n	a10, a1, 0              # 40009a96
	movi.n	a9, 0                   # 40009a98
	s32i.n	a9, a1, 4               # 40009a9a
	movi.n	a8, 5                   # 40009a9c
	s32i.n	a8, a1, 8               # 40009a9e
# int_bits = 32; int_min = 1 << (int_bits - 1);
	movi.n	a7, 32                  # 40009aa0
	s32i.n	a7, a1, 12              # 40009aa2
	movi.n	a5, 1                   # 40009aa4
	l32i.n	a6, a1, 12              # 40009aa6
	addi.n	a6, a6, -1              # 40009aa8
	ssl	a6                      # 40009aaa
	sll	a5, a5                  # 40009aad
	s32i.n	a5, a1, 16              # 40009ab0
# long_bits = 32; long_min = 1 << (long_bits - 1);
	movi.n	a4, 32                  # 40009ab2
	s32i.n	a4, a1, 20              # 40009ab4
	movi.n	a2, 1                   # 40009ab6
	l32i.n	a3, a1, 20              # 40009ab8
	addi.n	a3, a3, -1              # 40009aba
	ssl	a3                      # 40009abc
	sll	a2, a2                  # 40009abf
	s32i.n	a2, a1, 24              # 40009ac2
# dbg_printf("%s\n", text); dbg_printf("printf test\n");
	l32r	a10, lit_3ffe22b4       # 40009ac4  = ro_3ffe16f0 "%s\n"
	l32i.n	a11, a1, 0              # 40009ac7
	call8	dbg_printf              # 40009ac9
	l32r	a10, lit_3ffe22b8       # 40009acc  = ro_3ffe16f4 "printf test\n"
	call8	dbg_printf              # 40009acf
# dbg_printf("%p is null pointer\n", ptr); dbg_printf("%d = 5\n", five);
	l32r	a10, lit_3ffe22bc       # 40009ad2  = ro_3ffe1704 "%p is null pointer\n"
	l32i.n	a11, a1, 4              # 40009ad5
	call8	dbg_printf              # 40009ad7
	l32r	a10, lit_3ffe22c0       # 40009ada  = ro_3ffe1718 "%d = 5\n"
	l32i.n	a11, a1, 8              # 40009add
	call8	dbg_printf              # 40009adf
# dbg_printf("%d = - max int\n", int_min); dbg_printf("%ld = - max long\n", long_min);
	l32r	a10, lit_3ffe22c4       # 40009ae2  = ro_3ffe1720 "%d = - max int\n"
	l32i.n	a11, a1, 16             # 40009ae5
	call8	dbg_printf              # 40009ae7
	l32r	a10, lit_3ffe22c8       # 40009aea  = ro_3ffe1730 "%ld = - max long\n"
	l32i.n	a11, a1, 24             # 40009aed
	call8	dbg_printf              # 40009aef
# dbg_printf("char %c = 'a'\n", 'a'); dbg_printf("hex %x = ff\n", 255); dbg_printf("hex %02x = 00\n", 0);
	l32r	a10, lit_3ffe22cc       # 40009af2  = ro_3ffe1744 "char %c = 'a'\n"
	movi	a11, 97                 # 40009af5
	call8	dbg_printf              # 40009af8
	l32r	a10, lit_3ffe22d0       # 40009afb  = ro_3ffe1754 "hex %x = ff\n"
	movi	a11, 255                # 40009afe
	call8	dbg_printf              # 40009b01
	l32r	a10, lit_3ffe22d4       # 40009b04  = ro_3ffe1764 "hex %02x = 00\n"
	movi.n	a11, 0                  # 40009b07
	call8	dbg_printf              # 40009b09
# dbg_printf("int: signed %d = unsigned %u = hex %x\n", -3, -3, -3);
	l32r	a10, lit_3ffe22d8       # 40009b0c  = ro_3ffe1774 "int: signed %d = unsigned %u = hex %x\n"
	movi.n	a11, -3                 # 40009b0f
	movi.n	a12, -3                 # 40009b11
	movi.n	a13, -3                 # 40009b13
	call8	dbg_printf              # 40009b15
# dbg_printf("long: signed %ld = unsigned %lu = hex %lx\n", -5, -5, -5);
	l32r	a10, lit_3ffe22dc       # 40009b18  = ro_3ffe179c "long: signed %ld = unsigned %lu = hex %lx\n"
	movi.n	a11, -5                 # 40009b1b
	movi.n	a12, -5                 # 40009b1d
	movi.n	a13, -5                 # 40009b1f
	call8	dbg_printf              # 40009b21
# dbg_printf("%d %s(s)%", 0, "message"); dbg_printf("\n");
	l32r	a10, lit_3ffe22e0       # 40009b24  = ro_3ffe17c8 "%d %s(s)%"
	movi.n	a11, 0                  # 40009b27
	l32r	a12, lit_3ffe22e4       # 40009b29  = ro_3ffe17d4 "message"
	call8	dbg_printf              # 40009b2c
	l32r	a10, lit_3ffe22e8       # 40009b2f  = ro_3ffe17dc
	call8	dbg_printf              # 40009b32
# dbg_printf("%d %s(s) with %%\n", 0, "message");
	l32r	a10, lit_3ffe22ec       # 40009b35  = ro_3ffe17e0 "%d %s(s) with %%\n"
	movi.n	a11, 0                  # 40009b38
	l32r	a12, lit_3ffe22e4       # 40009b3a  = ro_3ffe17d4 "message"
	call8	dbg_printf              # 40009b3d
# dbg_printf("TEST result should be \n"); dbg_printf(expected_lines);
	l32r	a10, lit_3ffe22f0       # 40009b40  = ro_3ffe17f4 "TEST result should be \n"
	call8	dbg_printf              # 40009b43
	l32r	a10, lit_3ffe22f4       # 40009b46  = ro_3ffe180c
	call8	dbg_printf              # 40009b49
# return;
	retw.n                          # 40009b4c
	.size	uart_print_tx_test_lines, . - uart_print_tx_test_lines
