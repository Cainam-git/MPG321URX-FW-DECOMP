# sys_init_and_run_main_loop  (fn_4000a3cc): 0x4000a3cc-0x4000a457 (firmware file offset 0x3a3cc-0x3a457), 51 instructions
# Name basis: proven - called once by startup; texts 'Got power down command..', 'Enter to Idle loop',
#   'SW_IRQ!!'
# Called from: startup_zero_bss_and_run_main
# The program's main routine (called once by startup_zero_bss_and_run_main, never returns). It sets up the
# serial port and banner, the debug command line, interrupt 0, the tick timer (with the empty callback
# timer_tick_callback_empty), timer 0, the LED driver units, the dimming block, the panel defaults, interrupt 9 and the
# command index. Then it loops: when the word at 0xE0091000 (portal 2, word +0) holds 0x11223344 it writes
# back the inverted value (0xEEDDCCBB), prints "Got power down command.." and "Enter to Idle loop" and stops
# in an endless loop; otherwise it reports and clears the interrupt-0 flag, runs a processing pass when the
# interrupt-9 flag is set, polls the mailbox command slot and feeds the debug command line.
# No arguments.
# Locals: a1+0 unused (written 0 once).
# Returns: never.
# Calls: dbg_init_uart_print_banner, dbg_console_init, irq_sw_install, timer_start_tick,
#        timer_start_expstate_toggle, ldc_units_init, ldc_hw_init, ldc_init_panel_defaults, ldc_irq_install,
#        ldc_build_command_index, dbg_printf, ldc_run_pass_on_new_frame, ldc_poll_mailbox_command,
#        dbg_console_poll
# Text loaded: "\nGot power down command..\n", "Enter to Idle loop", "SW_IRQ!!\n"
# Addresses loaded: timer_tick_callback_empty
# Other literal values: 0x11223344, 0xe0091000, 0x3ffe5edc
# 1 instruction after an unconditional jump or return: no branch, jump, call or stored address leads to it.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	sys_init_and_run_main_loop, @function
sys_init_and_run_main_loop:             # fn_4000a3cc
	entry	a1, 48                  # 4000a3cc
	# dbg_init_uart_print_banner();
	call8	dbg_init_uart_print_banner # 4000a3cf
	# dbg_console_init();
	call8	dbg_console_init        # 4000a3d2
	# irq_sw_install();   (interrupt 0)
	call8	irq_sw_install          # 4000a3d5
	# unused = 0;
	movi.n	a2, 0                   # 4000a3d8
	s32i.n	a2, a1, 0               # 4000a3da
	# timer_start_tick(timer_tick_callback_empty);
	l32r	a10, lit_3ffe232c       # 4000a3dc  = timer_tick_callback_empty
	call8	timer_start_tick        # 4000a3df
	# timer_start_expstate_toggle();
	call8	timer_start_expstate_toggle # 4000a3e2
	# ldc_units_init();
	call8	ldc_units_init          # 4000a3e5
	# ldc_hw_init();
	call8	ldc_hw_init             # 4000a3e8
	# ldc_init_panel_defaults();
	call8	ldc_init_panel_defaults # 4000a3eb
	# ldc_irq_install();   (interrupt 9)
	call8	ldc_irq_install         # 4000a3ee
	# ldc_build_command_index();
	call8	ldc_build_command_index # 4000a3f1
.L4000a3f4:
	# for (;;) {
	#   if (*(volatile u32 *)0xE0091000 == 0x11223344) {
	l32r	a4, lit_3ffe2330        # 4000a3f4  = 0x11223344
	l32r	a3, lit_3ffe2334        # 4000a3f7  = 0xe0091000
	memw                            # 4000a3fa
	l32i.n	a3, a3, 0               # 4000a3fd
	bne	a3, a4, .L4000a426      # 4000a3ff
	#     *(volatile u32 *)0xE0091000 = *(volatile u32 *)0xE0091000 ^ 0xFFFFFFFF;
	l32r	a5, lit_3ffe2334        # 4000a402  = 0xe0091000
	movi.n	a6, -1                  # 4000a405
	l32r	a4, lit_3ffe2334        # 4000a407  = 0xe0091000
	memw                            # 4000a40a
	l32i.n	a4, a4, 0               # 4000a40d
	xor	a4, a4, a6              # 4000a40f
	memw                            # 4000a412
	s32i.n	a4, a5, 0               # 4000a415
	#     dbg_printf("\nGot power down command..\n");
	l32r	a10, lit_3ffe2338       # 4000a417  = ro_3ffe19c0 "\nGot power down command..\n"
	call8	dbg_printf              # 4000a41a
	#     dbg_printf("Enter to Idle loop");
	l32r	a10, lit_3ffe233c       # 4000a41d  = ro_3ffe19dc "Enter to Idle loop"
	call8	dbg_printf              # 4000a420
.L4000a423:
	#     for (;;) ;
	j	.L4000a423              # 4000a423
.L4000a426:
	#   }
	#   if (irq_sw_pending == 1) { dbg_printf("SW_IRQ!!\n"); irq_sw_pending = 0; }   (0x3FFE5EDC)
	l32r	a5, lit_3ffe2234        # 4000a426  = 0x3ffe5edc
	l32i.n	a5, a5, 0               # 4000a429
	bnei	a5, 1, .L4000a43b       # 4000a42b
	l32r	a10, lit_3ffe2340       # 4000a42e  = ro_3ffe19f0 "SW_IRQ!!\n"
	call8	dbg_printf              # 4000a431
	l32r	a7, lit_3ffe2234        # 4000a434  = 0x3ffe5edc
	movi.n	a6, 0                   # 4000a437
	s32i.n	a6, a7, 0               # 4000a439
.L4000a43b:
	#   if (ldc_irq_pending == 1) { ldc_run_pass_on_new_frame(); ldc_irq_pending = 0; }   (0x3FFE5EE0)
	l32r	a8, lit_3ffe2234        # 4000a43b  = 0x3ffe5edc
	l32i.n	a8, a8, 4               # 4000a43e
	bnei	a8, 1, .L4000a44d       # 4000a440
	call8	ldc_run_pass_on_new_frame # 4000a443
	l32r	a10, lit_3ffe2234       # 4000a446  = 0x3ffe5edc
	movi.n	a9, 0                   # 4000a449
	s32i.n	a9, a10, 4              # 4000a44b
.L4000a44d:
	#   ldc_poll_mailbox_command();
	call8	ldc_poll_mailbox_command # 4000a44d
	#   dbg_console_poll();
	call8	dbg_console_poll        # 4000a450
	# }
	j	.L4000a3f4              # 4000a453
	# (end of routine: never reached)
	retw.n                          # 4000a456
	.size	sys_init_and_run_main_loop, . - sys_init_and_run_main_loop
