# startup_zero_bss_and_run_main  (fn_40000800): 0x40000800-0x40000829 (firmware file offset 0x30800-0x30829), 15 instructions
# Name basis: proven - call0 from reset code; fill loop and call4 sys_init_and_run_main_loop
# Called with call0 from the reset code; it does not start with entry.
# Called from: reset_40000400
# Calls: sys_init_and_run_main_loop
# Other literal values: 0x3ffef000, 0x00040020, 0x3ffe2bf0, 0x3ffe6448
# Special registers: ps
#
# Start of the program after the reset code: sets the stack pointer and the PS register, fills the RAM area
# 0x3FFE2BF0..0x3FFE6447 with zeros, then calls the main routine sys_init_and_run_main_loop. If that returns, it stays in a
# loop of break instructions.
# Arguments: none (entered with call0; no entry instruction and no stack frame).
# Locals: none; registers only: a6 = fill pointer, a7 = end of the area.
# Returns: never.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	startup_zero_bss_and_run_main, @function
startup_zero_bss_and_run_main:          # fn_40000800
	# a0 = 0 (fill value); sp = 0x3FFEF000 (top of the stack)
	movi	a0, 0                   # 40000800
	l32r	a1, lit_3ffe1a70        # 40000803  = 0x3ffef000
	# PS = 0x00040020
	l32r	a3, lit_3ffe1a74        # 40000806  = 0x00040020
	nop.n                           # 40000809
	wsr.ps	a3                      # 4000080b
	rsync                           # 4000080e
	# for (p = 0x3FFE2BF0; p < 0x3FFE6448; p += 4) *p = 0
	l32r	a6, lit_3ffe1a78        # 40000811  = 0x3ffe2bf0
	l32r	a7, lit_3ffe1a7c        # 40000814  = 0x3ffe6448
	bgeu	a6, a7, .L40000821      # 40000817
.L4000081a:
	s32i.n	a0, a6, 0               # 4000081a
	addi.n	a6, a6, 4               # 4000081c
	bltu	a6, a7, .L4000081a      # 4000081e
.L40000821:
	# sys_init_and_run_main_loop()   (main routine)
	call4	sys_init_and_run_main_loop # 40000821
.L40000824:
	# for (;;) break 1, 15
	break	1, 15                   # 40000824
	j	.L40000824              # 40000827
	.size	startup_zero_bss_and_run_main, . - startup_zero_bss_and_run_main
