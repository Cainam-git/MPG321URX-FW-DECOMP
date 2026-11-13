# irq_install_step_empty_timer1  (fn_4000ab6c): 0x4000ab6c-0x4000ab70 (firmware file offset 0x3ab6c-0x3ab70), 2 instructions
# Name basis: descriptive - empty body; caller timer_arm_timer1
# Called from: timer_arm_timer1
# Empty routine, called right after irq_set_handler by timer_arm_timer1 (interrupt 10); same as
# irq_install_step_empty.
# No arguments, no locals.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_install_step_empty_timer1, @function
irq_install_step_empty_timer1:          # fn_4000ab6c
	# return;
	entry	a1, 16                  # 4000ab6c
	retw.n                          # 4000ab6f
	.size	irq_install_step_empty_timer1, . - irq_install_step_empty_timer1
