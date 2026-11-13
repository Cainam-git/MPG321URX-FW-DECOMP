# timer_start_expstate_toggle  (fn_40005dd8): 0x40005dd8-0x40005de7 (firmware file offset 0x35dd8-0x35de7), 6 instructions
# Name basis: derived - timer_start_timer0(0, 0x454, timer_toggle_expstate_bit9)
# Called from: sys_init_and_run_main_loop
# Starts timer 0 (timer_start_timer0 -> timer_arm_timer0, CCOMPARE0) with 0 and 0x454 and the callback timer_toggle_expstate_bit9, which
# changes EXPSTATE bit 9 on every call. The main loop sys_init_and_run_main_loop calls it once at start.
# Arguments: none.
# Returns: nothing.
# Calls: timer_start_timer0
# Addresses loaded: timer_toggle_expstate_bit9

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_start_expstate_toggle, @function
timer_start_expstate_toggle:            # fn_40005dd8
	entry	a1, 32                  # 40005dd8
	# timer_start_timer0(0, 0x454, timer_toggle_expstate_bit9);
	movi.n	a10, 0                  # 40005ddb
	movi	a11, 0x454              # 40005ddd
	l32r	a12, lit_3ffe1e3c       # 40005de0  = timer_toggle_expstate_bit9
	call8	timer_start_timer0      # 40005de3
	retw.n                          # 40005de6
	.size	timer_start_expstate_toggle, . - timer_start_expstate_toggle
