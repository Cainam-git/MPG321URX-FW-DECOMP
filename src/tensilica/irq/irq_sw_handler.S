# irq_sw_handler  (fn_40008e88): 0x40008e88-0x40008e9a (firmware file offset 0x38e88-0x38e9a), 8 instructions
# Name basis: derived - installed for interrupt 0; main loop prints 'SW_IRQ!!' on the flag
# Address stored in the words at: 0x4000cf30
# Handler of interrupt 0 (installed by irq_sw_install): sets irq_sw_pending (0x3FFE5EDC) to 1 and runs
# irq_line_ack(0, 0). The main loop (sys_init_and_run_main_loop) prints "SW_IRQ!!" when it finds the flag set and clears it.
# Arguments: none. Locals: none. Returns: nothing.
# Calls: irq_line_ack
# Other literal values: 0x3ffe5edc

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_sw_handler, @function
irq_sw_handler:                         # fn_40008e88
	entry	a1, 32                  # 40008e88
	# irq_sw_pending = 1;
	l32r	a3, lit_3ffe2234        # 40008e8b  = 0x3ffe5edc
	movi.n	a2, 1                   # 40008e8e
	s32i.n	a2, a3, 0               # 40008e90
	# irq_line_ack(0, 0);
	movi.n	a10, 0                  # 40008e92
	movi.n	a11, 0                  # 40008e94
	call8	irq_line_ack            # 40008e96
	retw.n                          # 40008e99
	.size	irq_sw_handler, . - irq_sw_handler
