# timer_service_timer1  (fn_40008fd8): 0x40008fd8-0x4000902b (firmware file offset 0x38fd8-0x3902b), 33 instructions
# Name basis: derived - installed by timer_arm_timer1; ccompare1, record 0x3ffe5598 +12..+20
# Address stored in the words at: 0x4000cf5c
# Handler of interrupt 10 (installed by timer_arm_timer1): reads CCOMPARE1; when timer_state.t1_one_shot
# (0x3FFE5598 +12) is set disables interrupt 10 (irq_disable, mask 0x400), otherwise sets CCOMPARE1 to the old
# value + t1_period; calls t1_callback when it is not 0; repeats while CCOUNT - old value is greater than
# the period.
# Arguments: none.
# Locals: a1+0 compare (CCOMPARE1 on entry to the pass), a1+4 elapsed.
# Returns: nothing.
# Calls: timer_read_compare, irq_disable, timer_write_compare, timer_read_cycle_count
# Indirect calls (callx): 1
# Other literal values: 0x3ffe5598

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_service_timer1, @function
timer_service_timer1:                   # fn_40008fd8
	entry	a1, 48                  # 40008fd8
.L40008fdb:
	# do { compare = CCOMPARE1;   (timer_read_compare(1))
	movi.n	a10, 1                  # 40008fdb
	call8	timer_read_compare      # 40008fdd
	s32i.n	a10, a1, 0              # 40008fe0
	# if (timer_state.t1_one_shot != 0) irq_disable(0x400);   (disable interrupt 10)
	movi.n	a3, 0                   # 40008fe2
	l32r	a2, lit_3ffe2258        # 40008fe4  = 0x3ffe5598
	l8ui	a2, a2, 12              # 40008fe7
	beq	a2, a3, .L40008ff6      # 40008fea
	movi	a10, 0x400              # 40008fed
	call8	irq_disable             # 40008ff0
	j	.L40009004              # 40008ff3
.L40008ff6:
	# else CCOMPARE1 = compare + timer_state.t1_period;   (timer_write_compare(1, ...))
	movi.n	a10, 1                  # 40008ff6
	l32i.n	a12, a1, 0              # 40008ff8
	l32r	a11, lit_3ffe2258       # 40008ffa  = 0x3ffe5598
	l32i.n	a11, a11, 16            # 40008ffd
	add.n	a11, a11, a12           # 40008fff
	call8	timer_write_compare     # 40009001
.L40009004:
	# if (timer_state.t1_callback != 0) timer_state.t1_callback();
	movi.n	a13, 0                  # 40009004
	l32r	a12, lit_3ffe2258       # 40009006  = 0x3ffe5598
	l32i.n	a12, a12, 20            # 40009009
	beq	a12, a13, .L40009016    # 4000900b
	l32r	a8, lit_3ffe2258        # 4000900e  = 0x3ffe5598
	l32i.n	a8, a8, 20              # 40009011
	callx8	a8                      # 40009013
.L40009016:
	# elapsed = CCOUNT - compare;   (timer_read_cycle_count)
	call8	timer_read_cycle_count  # 40009016
	l32i.n	a11, a1, 0              # 40009019
	sub	a10, a10, a11           # 4000901b
	s32i.n	a10, a1, 4              # 4000901e
	# } while (elapsed > timer_state.t1_period);
	l32i.n	a10, a1, 4              # 40009020
	l32r	a9, lit_3ffe2258        # 40009022  = 0x3ffe5598
	l32i.n	a9, a9, 16              # 40009025
	bltu	a9, a10, .L40008fdb     # 40009027
	retw.n                          # 4000902a
	.size	timer_service_timer1, . - timer_service_timer1
