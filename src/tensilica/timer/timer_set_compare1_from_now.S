# timer_set_compare1_from_now  (fn_4000ab94): 0x4000ab94-0x4000aba0 (firmware file offset 0x3ab94-0x3aba0), 5 instructions
# Name basis: proven - code; used by timer_arm_timer1
# Called from: timer_arm_timer1
# Sets CCOMPARE1 = CCOUNT + cycles (timer 1, interrupt 10; used by timer_arm_timer1).
# a2 = cycles: distance from the current cycle count.
# No locals.
# Returns: nothing.
# Special registers: ccount, ccompare1

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_set_compare1_from_now, @function
timer_set_compare1_from_now:            # fn_4000ab94
	entry	a1, 16                  # 4000ab94
	# CCOMPARE1 = CCOUNT + cycles;
	rsr.ccount	a3              # 4000ab97
	add.n	a3, a3, a2              # 4000ab9a
	wsr.ccompare1	a3              # 4000ab9c
	retw.n                          # 4000ab9f
	.size	timer_set_compare1_from_now, . - timer_set_compare1_from_now
