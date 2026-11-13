# timer_service_tick  (fn_4000902c): 0x4000902c-0x40009089 (firmware file offset 0x3902c-0x39089), 38 instructions
# Name basis: derived - installed by timer_start_tick; ccompare2, tick count read by timer_wait_ticks
# Address stored in the words at: 0x4000cf60
# Handler of interrupt 13 (installed by timer_start_tick): adds 1 to timer_state.tick_count (0x3FFE5598 +24),
# calls timer_state.tick_callback (+28) when it is not 0, adds 1 to tick_wraps (+32) when tick_count has
# become 0, and moves CCOMPARE2 on by 0x6C34; repeats while CCOUNT - old CCOMPARE2 is greater than 0x6C34.
# Arguments: none.
# Locals: a1+0 compare (CCOMPARE2 before the move), a1+4 elapsed.
# Returns: nothing.
# Calls: timer_read_compare, timer_write_compare, timer_read_cycle_count
# Indirect calls (callx): 1
# Other literal values: 0x3ffe5598, 0x00006c34

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_service_tick, @function
timer_service_tick:                     # fn_4000902c
	entry	a1, 48                  # 4000902c
.L4000902f:
	# do { timer_state.tick_count++;
	l32r	a4, lit_3ffe2258        # 4000902f  = 0x3ffe5598
	l32r	a3, lit_3ffe2258        # 40009032  = 0x3ffe5598
	l32i.n	a3, a3, 24              # 40009035
	addi.n	a3, a3, 1               # 40009037
	s32i.n	a3, a4, 24              # 40009039
	# if (timer_state.tick_callback != 0) timer_state.tick_callback();
	movi.n	a3, 0                   # 4000903b
	l32r	a2, lit_3ffe2258        # 4000903d  = 0x3ffe5598
	l32i.n	a2, a2, 28              # 40009040
	beq	a2, a3, .L4000904d      # 40009042
	l32r	a8, lit_3ffe2258        # 40009045  = 0x3ffe5598
	l32i.n	a8, a8, 28              # 40009048
	callx8	a8                      # 4000904a
.L4000904d:
	# if (timer_state.tick_count == 0) timer_state.tick_wraps++;
	movi.n	a10, 0                  # 4000904d
	l32r	a9, lit_3ffe2258        # 4000904f  = 0x3ffe5598
	l32i.n	a9, a9, 24              # 40009052
	bne	a9, a10, .L40009063     # 40009054
	l32r	a11, lit_3ffe2258       # 40009057  = 0x3ffe5598
	l32r	a10, lit_3ffe2258       # 4000905a  = 0x3ffe5598
	l32i.n	a10, a10, 32            # 4000905d
	addi.n	a10, a10, 1             # 4000905f
	s32i.n	a10, a11, 32            # 40009061
.L40009063:
	# compare = CCOMPARE2;   (timer_read_compare(2))
	movi.n	a10, 2                  # 40009063
	call8	timer_read_compare      # 40009065
	s32i.n	a10, a1, 0              # 40009068
	# CCOMPARE2 = compare + 0x6C34;   (timer_write_compare(2, ...))
	movi.n	a10, 2                  # 4000906a
	l32r	a12, lit_3ffe225c       # 4000906c  = 0x00006c34
	l32i.n	a11, a1, 0              # 4000906f
	add.n	a11, a11, a12           # 40009071
	call8	timer_write_compare     # 40009073
	# elapsed = CCOUNT - compare;   (timer_read_cycle_count)
	call8	timer_read_cycle_count  # 40009076
	l32i.n	a15, a1, 0              # 40009079
	sub	a15, a10, a15           # 4000907b
	s32i.n	a15, a1, 4              # 4000907e
	# } while (elapsed > 0x6C34);
	l32i.n	a14, a1, 4              # 40009080
	l32r	a13, lit_3ffe225c       # 40009082  = 0x00006c34
	bltu	a13, a14, .L4000902f    # 40009085
	retw.n                          # 40009088
	.size	timer_service_tick, . - timer_service_tick
