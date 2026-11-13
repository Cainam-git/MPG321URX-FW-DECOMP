# irq_set_handler  (fn_4000a514): 0x4000a514-0x4000a523 (firmware file offset 0x3a514-0x3a523), 7 instructions
# Name basis: proven - irq_set_handler_and_arg(n, handler, n); used by every interrupt set-up routine
# Called from: irq_sw_install, ldc_irq_install, timer_arm_timer0, timer_arm_timer1, timer_start_tick,
#              uart_init
# Installs handler for interrupt n with the interrupt number itself as the handler's argument:
# irq_set_handler_and_arg(n, handler, n).
# a2 = n: interrupt number (0..21). a3 = handler (0 = default handler).
# No locals.
# Returns: the previous handler, or 0 (see irq_set_handler_and_arg).
# Calls: irq_set_handler_and_arg

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_set_handler, @function
irq_set_handler:                        # fn_4000a514
	entry	a1, 32                  # 4000a514
	# return irq_set_handler_and_arg(n, handler, n);
	mov.n	a11, a3                 # 4000a517
	mov.n	a10, a2                 # 4000a519
	mov.n	a12, a2                 # 4000a51b
	call8	irq_set_handler_and_arg # 4000a51d
	mov.n	a2, a10                 # 4000a520
	retw.n                          # 4000a522
	.size	irq_set_handler, . - irq_set_handler
