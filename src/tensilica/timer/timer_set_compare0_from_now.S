# timer_set_compare0_from_now  (fn_4000ab84): 0x4000ab84-0x4000ab90 (firmware file offset 0x3ab84-0x3ab90), 5 instructions
# Name basis: proven - code; used by timer_arm_timer0
# Called from: timer_arm_timer0
# Sets CCOMPARE0 = CCOUNT + cycles (timer 0, interrupt 6; used by timer_arm_timer0).
# a2 = cycles: distance from the current cycle count.
# No locals.
# Returns: nothing.
# Special registers: ccount, ccompare0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_set_compare0_from_now, @function
timer_set_compare0_from_now:            # fn_4000ab84
	entry	a1, 16                  # 4000ab84
	# CCOMPARE0 = CCOUNT + cycles;
	rsr.ccount	a3              # 4000ab87
	add.n	a3, a3, a2              # 4000ab8a
	wsr.ccompare0	a3              # 4000ab8c
	retw.n                          # 4000ab8f
	.size	timer_set_compare0_from_now, . - timer_set_compare0_from_now
