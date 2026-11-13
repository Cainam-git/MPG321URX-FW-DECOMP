# timer_write_compare  (fn_4000abe4): 0x4000abe4-0x4000ac06 (firmware file offset 0x3abe4-0x3ac06), 13 instructions
# Name basis: proven - code; timer service routines re-arm with it
# Called from: timer_service_timer0, timer_service_timer1, timer_service_tick
# Writes value to CCOMPAREn for n = 0, 1 or 2 (other n: nothing). Used by the timer service routines to
# re-arm a timer.
# a2 = n: compare register number. a3 = value.
# No locals.
# Returns: nothing.
# Special registers: ccompare0, ccompare1, ccompare2

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_write_compare, @function
timer_write_compare:                    # fn_4000abe4
	entry	a1, 16                  # 4000abe4
	# if (n == 0) { CCOMPARE0 = value; return; }
	bnez.n	a2, .L4000abf1          # 4000abe7
	wsr.ccompare0	a3              # 4000abe9
	rsync                           # 4000abec
	retw.n                          # 4000abef
.L4000abf1:
	# if (n == 1) { CCOMPARE1 = value; return; }
	bnei	a2, 1, .L4000abfc       # 4000abf1
	wsr.ccompare1	a3              # 4000abf4
	rsync                           # 4000abf7
	retw.n                          # 4000abfa
.L4000abfc:
	# if (n == 2) CCOMPARE2 = value;
	bnei	a2, 2, .L4000ac05       # 4000abfc
	wsr.ccompare2	a3              # 4000abff
	rsync                           # 4000ac02
.L4000ac05:
	retw.n                          # 4000ac05
	.size	timer_write_compare, . - timer_write_compare
