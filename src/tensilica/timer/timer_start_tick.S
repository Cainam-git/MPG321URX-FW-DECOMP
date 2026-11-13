# timer_start_tick  (fn_40009104): 0x40009104-0x40009128 (firmware file offset 0x39104-0x39128), 14 instructions
# Name basis: derived - called once at start-up; installs timer_service_tick
# Called from: sys_init_and_run_main_loop
# Starts the tick timer: stores callback as timer_state.tick_callback (0x3FFE5598 +28), installs
# timer_service_tick for interrupt 13 (irq_set_handler), runs the empty irq_install_step_empty_tick, sets CCOMPARE2 = CCOUNT +
# 0x6C34 (timer_set_compare2_from_now) and enables interrupt 13 (irq_enable, mask 0x2000). Called once by the start-up
# routine sys_init_and_run_main_loop.
# a2 = callback: run on every tick (0 = none).
# Locals: a1+0 callback.
# Returns: nothing.
# Calls: irq_set_handler, irq_install_step_empty_tick, timer_set_compare2_from_now, irq_enable
# Addresses loaded: timer_service_tick
# Other literal values: 0x3ffe5598, 0x00006c34, 0x00002000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_start_tick, @function
timer_start_tick:                       # fn_40009104
	entry	a1, 48                  # 40009104
	# timer_state.tick_callback = callback;
	s32i.n	a2, a1, 0               # 40009107
	l32r	a5, lit_3ffe2258        # 40009109  = 0x3ffe5598
	l32i.n	a4, a1, 0               # 4000910c
	s32i.n	a4, a5, 28              # 4000910e
	# irq_set_handler(13, timer_service_tick);   (install the handler of interrupt 13)
	movi.n	a10, 13                 # 40009110
	l32r	a11, lit_3ffe2268       # 40009112  = timer_service_tick
	call8	irq_set_handler         # 40009115
	# irq_install_step_empty_tick();   (empty routine)
	call8	irq_install_step_empty_tick # 40009118
	# CCOMPARE2 = CCOUNT + 0x6C34;   (timer_set_compare2_from_now)
	l32r	a10, lit_3ffe225c       # 4000911b  = 0x00006c34
	call8	timer_set_compare2_from_now # 4000911e
	# irq_enable(0x2000);   (enable mask: interrupt 13)
	l32r	a10, lit_3ffe1fa8       # 40009121  = 0x00002000
	call8	irq_enable              # 40009124
	retw.n                          # 40009127
	.size	timer_start_tick, . - timer_start_tick
