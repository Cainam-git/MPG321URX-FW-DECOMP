# timer_read_cycle_count  (fn_4000abdc): 0x4000abdc-0x4000abe3 (firmware file offset 0x3abdc-0x3abe3), 3 instructions
# Name basis: proven - code: rsr.ccount
# Called from: timer_service_timer0, timer_service_timer1, timer_service_tick
# Returns CCOUNT, the processor's cycle counter (used by the three timer service routines to measure how far
# the counter has run past the compare value).
# No arguments, no locals.
# Returns: CCOUNT.
# Special registers: ccount

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_read_cycle_count, @function
timer_read_cycle_count:                 # fn_4000abdc
	entry	a1, 16                  # 4000abdc
	# return CCOUNT;
	rsr.ccount	a2              # 4000abdf
	retw.n                          # 4000abe2
	.size	timer_read_cycle_count, . - timer_read_cycle_count
