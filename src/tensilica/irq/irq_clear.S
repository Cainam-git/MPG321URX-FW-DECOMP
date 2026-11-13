# irq_clear  (fn_4000ab7c): 0x4000ab7c-0x4000ab83 (firmware file offset 0x3ab7c-0x3ab83), 3 instructions
# Name basis: proven - code: wsr.intclear
# Called from: irq_sw_install, ldc_irq_install, uart_init
# Writes mask to INTCLEAR: clears the pending state of the interrupts whose bits are set.
# a2 = mask: one bit per interrupt.
# No locals.
# Returns: nothing.
# Special registers: intclear

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_clear, @function
irq_clear:                              # fn_4000ab7c
	entry	a1, 16                  # 4000ab7c
	# INTCLEAR = mask;
	wsr.intclear	a2              # 4000ab7f
	retw.n                          # 4000ab82
	.size	irq_clear, . - irq_clear
