# irq_enable  (fn_4000a524): 0x4000a524-0x4000a545 (firmware file offset 0x3a524-0x3a545), 13 instructions
# Name basis: proven - code: irq_enable_state +0 |= mask, INTENABLE = enabled & allowed
# Called from: irq_sw_install, ldc_irq_install, timer_arm_timer0, timer_arm_timer1, timer_start_tick,
#              uart_init
# Adds the bits of mask to the enabled-interrupt word irq_enable_state.enabled (irq_enable_state +0) and writes
# INTENABLE = enabled & irq_enable_state.allowed (+4), with interrupts up to level 6 held off (RSIL 6)
# while it does so.
# a2 = mask: one bit per interrupt.
# No stack locals.
# Returns: the enabled word as it was before.
# Addresses loaded: irq_enable_state
# Special registers: intenable, ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_enable, @function
irq_enable:                             # fn_4000a524
	entry	a1, 16                  # 4000a524
	# saved_ps = RSIL(6);
	l32r	a4, lit_3ffe2358        # 4000a527  = irq_enable_state
	rsil	a7, 6                   # 4000a52a
	# old = irq_enable_state.enabled; irq_enable_state.enabled = old | mask;
	l32i.n	a3, a4, 0               # 4000a52d
	l32i.n	a6, a4, 4               # 4000a52f
	or	a5, a3, a2              # 4000a531
	s32i.n	a5, a4, 0               # 4000a534
	# INTENABLE = irq_enable_state.enabled & irq_enable_state.allowed;
	and	a5, a5, a6              # 4000a536
	wsr.intenable	a5              # 4000a539
	# PS = saved_ps;
	wsr.ps	a7                      # 4000a53c
	rsync                           # 4000a53f
	# return old;
	mov.n	a2, a3                  # 4000a542
	retw.n                          # 4000a544
	.size	irq_enable, . - irq_enable
