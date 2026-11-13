# timer_count_tick_timer1  (fn_40005e74): 0x40005e74-0x40005ea1 (firmware file offset 0x35e74-0x35ea1), 20 instructions
# Name basis: derived - installed by timer_start_counted_timer1; consumed by timer_run_pending_callbacks
# Address stored in the words at: 0x4000cb60
# Timer 1 callback installed by timer_start_counted_timer1: with interrupts off, adds 1 to the pending count of timer 1
# (word 0x3ffe4438 + 4). timer_run_pending_callbacks consumes the count.
# Arguments: none.
# Locals: a1+0 / a1+4 / a1+8 / a1+12 copies of the saved PS, a1+16 PS returned by rsil.
# Returns: nothing.
# Other literal values: 0x3ffe4438
# Special registers: ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_count_tick_timer1, @function
timer_count_tick_timer1:                # fn_40005e74
	entry	a1, 64                  # 40005e74
	# ps = rsil(15);
	rsil	a2, 15                  # 40005e77
	s32i.n	a2, a1, 16              # 40005e7a
	l32i.n	a4, a1, 16              # 40005e7c
	s32i.n	a4, a1, 0               # 40005e7e
	l32i.n	a3, a1, 0               # 40005e80
	s32i.n	a3, a1, 4               # 40005e82
	l32i.n	a6, a1, 4               # 40005e84
	s32i.n	a6, a1, 8               # 40005e86
	# tick.pending1++;
	l32r	a6, lit_3ffe1e60        # 40005e88  = 0x3ffe4438
	l32r	a5, lit_3ffe1e60        # 40005e8b  = 0x3ffe4438
	l32i.n	a5, a5, 4               # 40005e8e
	addi.n	a5, a5, 1               # 40005e90
	s32i.n	a5, a6, 4               # 40005e92
	# PS = ps;
	l32i.n	a8, a1, 8               # 40005e94
	s32i.n	a8, a1, 12              # 40005e96
	l32i.n	a7, a1, 12              # 40005e98
	wsr.ps	a7                      # 40005e9a
	rsync                           # 40005e9d
	retw.n                          # 40005ea0
	.size	timer_count_tick_timer1, . - timer_count_tick_timer1
