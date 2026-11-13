# irq_install_step_empty  (fn_4000ab64): 0x4000ab64-0x4000ab68 (firmware file offset 0x3ab64-0x3ab68), 2 instructions
# Name basis: descriptive - empty body; callers irq_sw_install, ldc_irq_install, timer_arm_timer0, uart_init
# Called from: irq_sw_install, ldc_irq_install, timer_arm_timer0, uart_init
# Empty routine, called right after irq_set_handler by irq_sw_install, ldc_irq_install, timer_arm_timer0 and
# uart_init (interrupts 0, 9, 6 and 2).
# No arguments, no locals.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_install_step_empty, @function
irq_install_step_empty:                 # fn_4000ab64
	# return;
	entry	a1, 16                  # 4000ab64
	retw.n                          # 4000ab67
	.size	irq_install_step_empty, . - irq_install_step_empty
