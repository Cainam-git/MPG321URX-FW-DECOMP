# timer_start_timer0  (fn_40005f50): 0x40005f50-0x40005f68 (firmware file offset 0x35f50-0x35f68), 10 instructions
# Name basis: derived - wrapper of timer_arm_timer0 (ccompare0)
# Called from: timer_start_expstate_toggle
# Passes its three arguments to timer_arm_timer0, which stores them at 0x3ffe5598 and starts timer 0 (CCOMPARE0,
# interrupt 6) with the callback.
# Arguments: a2 a (byte), a3 period, a4 callback.
# Locals: a1+0 a, a1+4 period, a1+8 callback.
# Returns: nothing.
# Calls: timer_arm_timer0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_start_timer0, @function
timer_start_timer0:                     # fn_40005f50
	entry	a1, 48                  # 40005f50
	extui	a6, a2, 0, 8            # 40005f53
	s8i	a6, a1, 0               # 40005f56
	s32i.n	a3, a1, 4               # 40005f59
	s32i.n	a4, a1, 8               # 40005f5b
	# timer_arm_timer0(a, period, callback);
	l8ui	a10, a1, 0              # 40005f5d
	l32i.n	a11, a1, 4              # 40005f60
	l32i.n	a12, a1, 8              # 40005f62
	call8	timer_arm_timer0        # 40005f64
	retw.n                          # 40005f67
	.size	timer_start_timer0, . - timer_start_timer0
