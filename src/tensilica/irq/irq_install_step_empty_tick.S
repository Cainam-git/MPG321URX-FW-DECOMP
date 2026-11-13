# irq_install_step_empty_tick  (fn_4000ab74): 0x4000ab74-0x4000ab78 (firmware file offset 0x3ab74-0x3ab78), 2 instructions
# Name basis: descriptive - empty body; caller timer_start_tick
# Called from: timer_start_tick
# Empty routine, called right after irq_set_handler by timer_start_tick (interrupt 13); same as
# irq_install_step_empty.
# No arguments, no locals.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_install_step_empty_tick, @function
irq_install_step_empty_tick:            # fn_4000ab74
	# return;
	entry	a1, 16                  # 4000ab74
	retw.n                          # 4000ab77
	.size	irq_install_step_empty_tick, . - irq_install_step_empty_tick
