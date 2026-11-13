# timer_start_timer1  (fn_40005f90): 0x40005f90-0x40005fa8 (firmware file offset 0x35f90-0x35fa8), 10 instructions
# Name basis: derived - wrapper of timer_arm_timer1 (ccompare1); no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Passes its three arguments to timer_arm_timer1, which starts timer 1 (CCOMPARE1) with the callback. Nothing calls
# it and no stored word holds its address.
# Arguments: a2 a (byte), a3 period, a4 callback.
# Locals: a1+0 a, a1+4 period, a1+8 callback.
# Returns: nothing.
# Calls: timer_arm_timer1

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_start_timer1, @function
timer_start_timer1:                     # fn_40005f90
	entry	a1, 48                  # 40005f90
	extui	a6, a2, 0, 8            # 40005f93
	s8i	a6, a1, 0               # 40005f96
	s32i.n	a3, a1, 4               # 40005f99
	s32i.n	a4, a1, 8               # 40005f9b
	# timer_arm_timer1(a, period, callback);
	l8ui	a10, a1, 0              # 40005f9d
	l32i.n	a11, a1, 4              # 40005fa0
	l32i.n	a12, a1, 8              # 40005fa2
	call8	timer_arm_timer1        # 40005fa4
	retw.n                          # 40005fa7
	.size	timer_start_timer1, . - timer_start_timer1
