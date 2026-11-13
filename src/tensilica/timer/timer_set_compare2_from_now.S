# timer_set_compare2_from_now  (fn_4000aba4): 0x4000aba4-0x4000abcb (firmware file offset 0x3aba4-0x3abcb), 15 instructions
# Name basis: proven - code; used by timer_start_tick; .L4000abb4 return address of irq_dispatch_level1
# Called from: timer_start_tick
# Sets CCOMPARE2 = CCOUNT + cycles (the tick, interrupt 13; used by timer_start_tick).
# The same file holds .L4000abb4, the exit of irq_dispatch_level1: it restores PS, EPC1 and
# a2..a5 from the area the user exception vector and irq_dispatch_level1 filled below the program's stack pointer
# (a5 points to it) and returns from the exception (rfe).
# a2 = cycles: distance from the current cycle count.
# No locals.
# Returns: nothing.
# Special registers: ccount, ccompare2, ps, epc1

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_set_compare2_from_now, @function
timer_set_compare2_from_now:            # fn_4000aba4
	entry	a1, 16                  # 4000aba4
	# CCOMPARE2 = CCOUNT + cycles;
	rsr.ccount	a3              # 4000aba7
	add.n	a3, a3, a2              # 4000abaa
	wsr.ccompare2	a3              # 4000abac
	retw.n                          # 4000abaf
	.balign	4, 0                    # 3 zero bytes up to the 4-byte boundary 0x4000abb4
.L4000abb4:
	# exit of irq_dispatch_level1: PS = area[1]; EPC1 = area[0]; a2 = area[4]; a4 = area[6]; a3 = area[5];
	# a5 = area[7]; return from the exception;
	l32i.n	a2, a5, 4               # 4000abb4
	l32i.n	a3, a5, 0               # 4000abb6
	wsr.ps	a2                      # 4000abb8
	l32i.n	a2, a5, 16              # 4000abbb
	l32i.n	a4, a5, 24              # 4000abbd
	rsync                           # 4000abbf
	wsr.epc1	a3              # 4000abc2
	l32i.n	a3, a5, 20              # 4000abc5
	l32i.n	a5, a5, 28              # 4000abc7
	rfe                             # 4000abc9
	.size	timer_set_compare2_from_now, . - timer_set_compare2_from_now
