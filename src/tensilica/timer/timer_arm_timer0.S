# timer_arm_timer0  (fn_4000908c): 0x4000908c-0x400090c6 (firmware file offset 0x3908c-0x390c6), 23 instructions
# Name basis: derived - wrapped by timer_start_timer0 / timer_start_counted_timer0; ccompare0
# Called from: timer_start_counted_timer0, timer_start_timer0
# Stores one_shot, period and callback in timer_state (0x3FFE5598 +0, +4, +8), installs
# timer_service_timer0 for interrupt 6 (irq_set_handler), runs the empty irq_install_step_empty, sets CCOMPARE0 = CCOUNT + period
# (timer_set_compare0_from_now) and enables interrupt 6 (irq_enable, mask 0x40). Called by timer_start_timer0 and timer_start_counted_timer0.
# a2 = one_shot (u8: 0 = repeat every period). a3 = period (CCOUNT cycles). a4 = callback (0 = none).
# Locals: a1+0 one_shot (u8), a1+4 period, a1+8 callback.
# Returns: nothing.
# Calls: irq_set_handler, irq_install_step_empty, timer_set_compare0_from_now, irq_enable
# Addresses loaded: timer_service_timer0
# Other literal values: 0x3ffe5598

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_arm_timer0, @function
timer_arm_timer0:                       # fn_4000908c
	entry	a1, 48                  # 4000908c
	# timer_state.t0_one_shot = one_shot;
	extui	a6, a2, 0, 8            # 4000908f
	s8i	a6, a1, 0               # 40009092
	s32i.n	a3, a1, 4               # 40009095
	s32i.n	a4, a1, 8               # 40009097
	l32r	a11, lit_3ffe2258       # 40009099  = 0x3ffe5598
	l8ui	a10, a1, 0              # 4000909c
	s8i	a10, a11, 0             # 4000909f
	# timer_state.t0_period = period;
	l32r	a10, lit_3ffe2258       # 400090a2  = 0x3ffe5598
	l32i.n	a9, a1, 4               # 400090a5
	s32i.n	a9, a10, 4              # 400090a7
	# timer_state.t0_callback = callback;
	l32r	a9, lit_3ffe2258        # 400090a9  = 0x3ffe5598
	l32i.n	a8, a1, 8               # 400090ac
	s32i.n	a8, a9, 8               # 400090ae
	# irq_set_handler(6, timer_service_timer0);   (install the handler of interrupt 6)
	movi.n	a10, 6                  # 400090b0
	l32r	a11, lit_3ffe2260       # 400090b2  = timer_service_timer0
	call8	irq_set_handler         # 400090b5
	# irq_install_step_empty();   (empty routine)
	call8	irq_install_step_empty  # 400090b8
	# CCOMPARE0 = CCOUNT + period;   (timer_set_compare0_from_now)
	l32i.n	a10, a1, 4              # 400090bb
	call8	timer_set_compare0_from_now # 400090bd
	# irq_enable(0x40);   (enable mask: interrupt 6)
	movi.n	a10, 64                 # 400090c0
	call8	irq_enable              # 400090c2
	retw.n                          # 400090c5
	.size	timer_arm_timer0, . - timer_arm_timer0
