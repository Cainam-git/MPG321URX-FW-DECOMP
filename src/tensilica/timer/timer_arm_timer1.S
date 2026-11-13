# timer_arm_timer1  (fn_400090c8): 0x400090c8-0x40009103 (firmware file offset 0x390c8-0x39103), 23 instructions
# Name basis: derived - wrapped by timer_start_timer1 / timer_start_counted_timer1; ccompare1
# Called from: timer_start_counted_timer1, timer_start_timer1
# Stores one_shot, period and callback in timer_state (0x3FFE5598 +12, +16, +20), installs
# timer_service_timer1 for interrupt 10 (irq_set_handler), runs the empty irq_install_step_empty_timer1, sets CCOMPARE1 = CCOUNT + period
# (timer_set_compare1_from_now) and enables interrupt 10 (irq_enable, mask 0x400). Called by timer_start_timer1 and timer_start_counted_timer1.
# a2 = one_shot (u8: 0 = repeat every period). a3 = period (CCOUNT cycles). a4 = callback (0 = none).
# Locals: a1+0 one_shot (u8), a1+4 period, a1+8 callback.
# Returns: nothing.
# Calls: irq_set_handler, irq_install_step_empty_timer1, timer_set_compare1_from_now, irq_enable
# Addresses loaded: timer_service_timer1
# Other literal values: 0x3ffe5598

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_arm_timer1, @function
timer_arm_timer1:                       # fn_400090c8
	entry	a1, 48                  # 400090c8
	# timer_state.t1_one_shot = one_shot;
	extui	a6, a2, 0, 8            # 400090cb
	s8i	a6, a1, 0               # 400090ce
	s32i.n	a3, a1, 4               # 400090d1
	s32i.n	a4, a1, 8               # 400090d3
	l32r	a11, lit_3ffe2258       # 400090d5  = 0x3ffe5598
	l8ui	a10, a1, 0              # 400090d8
	s8i	a10, a11, 12            # 400090db
	# timer_state.t1_period = period;
	l32r	a10, lit_3ffe2258       # 400090de  = 0x3ffe5598
	l32i.n	a9, a1, 4               # 400090e1
	s32i.n	a9, a10, 16             # 400090e3
	# timer_state.t1_callback = callback;
	l32r	a9, lit_3ffe2258        # 400090e5  = 0x3ffe5598
	l32i.n	a8, a1, 8               # 400090e8
	s32i.n	a8, a9, 20              # 400090ea
	# irq_set_handler(10, timer_service_timer1);   (install the handler of interrupt 10)
	movi.n	a10, 10                 # 400090ec
	l32r	a11, lit_3ffe2264       # 400090ee  = timer_service_timer1
	call8	irq_set_handler         # 400090f1
	# irq_install_step_empty_timer1();   (empty routine)
	call8	irq_install_step_empty_timer1 # 400090f4
	# CCOMPARE1 = CCOUNT + period;   (timer_set_compare1_from_now)
	l32i.n	a10, a1, 4              # 400090f7
	call8	timer_set_compare1_from_now # 400090f9
	# irq_enable(0x400);   (enable mask: interrupt 10)
	movi	a10, 0x400              # 400090fc
	call8	irq_enable              # 400090ff
	retw.n                          # 40009102
	.size	timer_arm_timer1, . - timer_arm_timer1
