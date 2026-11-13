# dbg_cmd_gpio_test  (fn_40005cac): 0x40005cac-0x40005cf5 (firmware file offset 0x35cac-0x35cf5), 30 instructions
# Name basis: proven - command 'gpio', help 'gpio [port]: GPIO test', 'GPIOtest done!!'
# Address stored in the words at: 0x4000b3d8
# Command "gpio [port]" of the debug command line (table entry at 0x4000b3d8; help text "gpio [port]: GPIO
# test"): clears the EXPSTATE register, then 1000 times calls gpio_output_clear(port) on even passes and
# gpio_output_set(port) on odd passes, each followed by timer_wait_ticks(1), and prints "GPIOtest done!!". Both callees
# print "gpio_set_output" when the index is out of range.
# Arguments: a2 port (first number typed after the command).
# Locals: a1+0 saved (EXPSTATE before clearing; not used again), a1+4 i, a1+16 port.
# Returns: nothing.
# Calls: gpio_output_clear, gpio_output_set, timer_wait_ticks, dbg_printf
# Text loaded: "GPIOtest done!!"

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_cmd_gpio_test, @function
dbg_cmd_gpio_test:                      # fn_40005cac
	entry	a1, 64                  # 40005cac
	s32i.n	a2, a1, 16              # 40005caf
	# saved = EXPSTATE; EXPSTATE = 0;
	rur.expstate	a9              # 40005cb1
	s32i.n	a9, a1, 0               # 40005cb4
	movi.n	a7, 0                   # 40005cb6
	movi.n	a8, -1                  # 40005cb8
	wrmsk_expstate	a7, a8          # 40005cba
	# for (i = 0; i <= 999; i++) {
	movi.n	a6, 0                   # 40005cbd
	s32i.n	a6, a1, 4               # 40005cbf
	l32i.n	a5, a1, 4               # 40005cc1
	movi	a4, 0x3e7               # 40005cc3
	blt	a4, a5, .L40005cee      # 40005cc6
.L40005cc9:
	# if ((i & 1) == 0) gpio_output_clear(port);
	l32i.n	a10, a1, 4              # 40005cc9
	bbsi	a10, 0, .L40005cd6      # 40005ccb
	l32i.n	a10, a1, 16             # 40005cce
	call8	gpio_output_clear       # 40005cd0
	j	.L40005cdb              # 40005cd3
.L40005cd6:
	# else gpio_output_set(port);
	l32i.n	a10, a1, 16             # 40005cd6
	call8	gpio_output_set         # 40005cd8
.L40005cdb:
	# timer_wait_ticks(1); }
	movi.n	a10, 1                  # 40005cdb
	call8	timer_wait_ticks        # 40005cdd
	l32i.n	a13, a1, 4              # 40005ce0
	addi.n	a13, a13, 1             # 40005ce2
	s32i.n	a13, a1, 4              # 40005ce4
	l32i.n	a12, a1, 4              # 40005ce6
	movi	a11, 0x3e7              # 40005ce8
	bge	a11, a12, .L40005cc9    # 40005ceb
.L40005cee:
	# printf("GPIOtest done!!");
	l32r	a10, lit_3ffe1e28       # 40005cee  = ro_3ffe09d4 "GPIOtest done!!"
	call8	dbg_printf              # 40005cf1
	retw.n                          # 40005cf4
	.size	dbg_cmd_gpio_test, . - dbg_cmd_gpio_test
