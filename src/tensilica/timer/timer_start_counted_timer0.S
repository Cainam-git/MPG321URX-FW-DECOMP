# timer_start_counted_timer0  (fn_40005f2c): 0x40005f2c-0x40005f4c (firmware file offset 0x35f2c-0x35f4c), 13 instructions
# Name basis: derived - timer_arm_timer0(.., timer_count_tick_timer0); no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Starts timer 0 (timer_arm_timer0, CCOMPARE0) with timer_count_tick_timer0 as its interrupt callback, which only counts ticks,
# and stores the caller's callback in tick.callback0 (0x3ffe4438 + 8) for timer_run_pending_callbacks. Nothing calls it and no
# stored word holds its address.
# Arguments: a2 a (byte, passed on as the first argument of timer_arm_timer0), a3 period (second argument; timer_arm_timer0
#   uses it for CCOMPARE0), a4 callback.
# Locals: a1+0 a, a1+4 period, a1+8 callback.
# Returns: nothing.
# Calls: timer_arm_timer0
# Addresses loaded: timer_count_tick_timer0
# Other literal values: 0x3ffe4438

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_start_counted_timer0, @function
timer_start_counted_timer0:             # fn_40005f2c
	entry	a1, 48                  # 40005f2c
	extui	a6, a2, 0, 8            # 40005f2f
	s8i	a6, a1, 0               # 40005f32
	s32i.n	a3, a1, 4               # 40005f35
	s32i.n	a4, a1, 8               # 40005f37
	# timer_arm_timer0(a, period, timer_count_tick_timer0);
	l8ui	a10, a1, 0              # 40005f39
	l32i.n	a11, a1, 4              # 40005f3c
	l32r	a12, lit_3ffe1e64       # 40005f3e  = timer_count_tick_timer0
	call8	timer_arm_timer0        # 40005f41
	# tick.callback0 = callback;
	l32r	a12, lit_3ffe1e60       # 40005f44  = 0x3ffe4438
	l32i.n	a11, a1, 8              # 40005f47
	s32i.n	a11, a12, 8             # 40005f49
	retw.n                          # 40005f4b
	.size	timer_start_counted_timer0, . - timer_start_counted_timer0
