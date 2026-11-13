# timer_start_counted_timer1  (fn_40005f6c): 0x40005f6c-0x40005f8c (firmware file offset 0x35f6c-0x35f8c), 13 instructions
# Name basis: derived - timer_arm_timer1(.., timer_count_tick_timer1); no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Starts timer 1 (timer_arm_timer1, CCOMPARE1) with timer_count_tick_timer1 as its interrupt callback, which only counts ticks,
# and stores the caller's callback in tick.callback1 (0x3ffe4438 + 12) for timer_run_pending_callbacks. Nothing calls it and no
# stored word holds its address.
# Arguments: a2 a (byte), a3 period, a4 callback.
# Locals: a1+0 a, a1+4 period, a1+8 callback.
# Returns: nothing.
# Calls: timer_arm_timer1
# Addresses loaded: timer_count_tick_timer1
# Other literal values: 0x3ffe4438

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_start_counted_timer1, @function
timer_start_counted_timer1:             # fn_40005f6c
	entry	a1, 48                  # 40005f6c
	extui	a6, a2, 0, 8            # 40005f6f
	s8i	a6, a1, 0               # 40005f72
	s32i.n	a3, a1, 4               # 40005f75
	s32i.n	a4, a1, 8               # 40005f77
	# timer_arm_timer1(a, period, timer_count_tick_timer1);
	l8ui	a10, a1, 0              # 40005f79
	l32i.n	a11, a1, 4              # 40005f7c
	l32r	a12, lit_3ffe1e68       # 40005f7e  = timer_count_tick_timer1
	call8	timer_arm_timer1        # 40005f81
	# tick.callback1 = callback;
	l32r	a12, lit_3ffe1e60       # 40005f84  = 0x3ffe4438
	l32i.n	a11, a1, 8              # 40005f87
	s32i.n	a11, a12, 12            # 40005f89
	retw.n                          # 40005f8b
	.size	timer_start_counted_timer1, . - timer_start_counted_timer1
