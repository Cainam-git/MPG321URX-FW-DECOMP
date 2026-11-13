# timer_service_timer0  (fn_40008f84): 0x40008f84-0x40008fd6 (firmware file offset 0x38f84-0x38fd6), 33 instructions
# Name basis: derived - installed by timer_arm_timer0; ccompare0, record 0x3ffe5598 +0..+8
# Address stored in the words at: 0x4000cf58
# Handler of interrupt 6 (installed by timer_arm_timer0): reads CCOMPARE0; when timer_state.t0_one_shot
# (0x3FFE5598 +0) is set disables interrupt 6 (irq_disable, mask 0x40), otherwise sets CCOMPARE0 to the old
# value + t0_period; calls t0_callback when it is not 0; repeats while CCOUNT - old value is greater than
# the period.
# Arguments: none.
# Locals: a1+0 compare (CCOMPARE0 on entry to the pass), a1+4 elapsed.
# Returns: nothing.
# Calls: timer_read_compare, irq_disable, timer_write_compare, timer_read_cycle_count
# Indirect calls (callx): 1
# Other literal values: 0x3ffe5598

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_service_timer0, @function
timer_service_timer0:                   # fn_40008f84
	entry	a1, 48                  # 40008f84
.L40008f87:
	# do { compare = CCOMPARE0;   (timer_read_compare(0))
	movi.n	a10, 0                  # 40008f87
	call8	timer_read_compare      # 40008f89
	s32i.n	a10, a1, 0              # 40008f8c
	# if (timer_state.t0_one_shot != 0) irq_disable(0x40);   (disable interrupt 6)
	movi.n	a3, 0                   # 40008f8e
	l32r	a2, lit_3ffe2258        # 40008f90  = 0x3ffe5598
	l8ui	a2, a2, 0               # 40008f93
	beq	a2, a3, .L40008fa1      # 40008f96
	movi.n	a10, 64                 # 40008f99
	call8	irq_disable             # 40008f9b
	j	.L40008faf              # 40008f9e
.L40008fa1:
	# else CCOMPARE0 = compare + timer_state.t0_period;   (timer_write_compare(0, ...))
	movi.n	a10, 0                  # 40008fa1
	l32i.n	a12, a1, 0              # 40008fa3
	l32r	a11, lit_3ffe2258       # 40008fa5  = 0x3ffe5598
	l32i.n	a11, a11, 4             # 40008fa8
	add.n	a11, a11, a12           # 40008faa
	call8	timer_write_compare     # 40008fac
.L40008faf:
	# if (timer_state.t0_callback != 0) timer_state.t0_callback();
	movi.n	a13, 0                  # 40008faf
	l32r	a12, lit_3ffe2258       # 40008fb1  = 0x3ffe5598
	l32i.n	a12, a12, 8             # 40008fb4
	beq	a12, a13, .L40008fc1    # 40008fb6
	l32r	a8, lit_3ffe2258        # 40008fb9  = 0x3ffe5598
	l32i.n	a8, a8, 8               # 40008fbc
	callx8	a8                      # 40008fbe
.L40008fc1:
	# elapsed = CCOUNT - compare;   (timer_read_cycle_count)
	call8	timer_read_cycle_count  # 40008fc1
	l32i.n	a11, a1, 0              # 40008fc4
	sub	a10, a10, a11           # 40008fc6
	s32i.n	a10, a1, 4              # 40008fc9
	# } while (elapsed > timer_state.t0_period);
	l32i.n	a10, a1, 4              # 40008fcb
	l32r	a9, lit_3ffe2258        # 40008fcd  = 0x3ffe5598
	l32i.n	a9, a9, 4               # 40008fd0
	bltu	a9, a10, .L40008f87     # 40008fd2
	retw.n                          # 40008fd5
	.size	timer_service_timer0, . - timer_service_timer0
