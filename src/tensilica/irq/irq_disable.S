# irq_disable  (fn_4000a548): 0x4000a548-0x4000a56c (firmware file offset 0x3a548-0x3a56c), 14 instructions
# Name basis: proven - code: irq_enable_state +0 &= ~mask, INTENABLE = enabled & allowed
# Called from: timer_service_timer0, timer_service_timer1
# Removes the bits of mask from the enabled-interrupt word irq_enable_state.enabled (irq_enable_state +0) and
# writes INTENABLE = enabled & irq_enable_state.allowed (+4), with interrupts up to level 6 held off (RSIL 6)
# while it does so. Counterpart of irq_enable.
# a2 = mask: one bit per interrupt.
# No stack locals.
# Returns: the enabled word as it was before.
# Addresses loaded: irq_enable_state
# Special registers: intenable, ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_disable, @function
irq_disable:                            # fn_4000a548
	entry	a1, 16                  # 4000a548
	# saved_ps = RSIL(6);
	l32r	a4, lit_3ffe2358        # 4000a54b  = irq_enable_state
	rsil	a7, 6                   # 4000a54e
	# old = irq_enable_state.enabled; irq_enable_state.enabled = old & ~mask;   ((old | mask) ^ mask)
	l32i.n	a3, a4, 0               # 4000a551
	l32i.n	a6, a4, 4               # 4000a553
	or	a5, a3, a2              # 4000a555
	xor	a5, a5, a2              # 4000a558
	s32i.n	a5, a4, 0               # 4000a55b
	# INTENABLE = irq_enable_state.enabled & irq_enable_state.allowed;
	and	a5, a5, a6              # 4000a55d
	wsr.intenable	a5              # 4000a560
	# PS = saved_ps;
	wsr.ps	a7                      # 4000a563
	rsync                           # 4000a566
	# return old;
	mov.n	a2, a3                  # 4000a569
	retw.n                          # 4000a56b
	.size	irq_disable, . - irq_disable
