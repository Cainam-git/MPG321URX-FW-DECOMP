# ldc_irq_install  (fn_40008f58): 0x40008f58-0x40008f81 (firmware file offset 0x38f58-0x38f81), 16 instructions
# Name basis: derived - irq_set_handler(9, ldc_irq_handler), INTCLEAR/INTENABLE mask 0x200
# Called from: sys_init_and_run_main_loop
# Installs ldc_irq_handler for interrupt 9 (irq_set_handler), runs the empty irq_install_step_empty, clears interrupt 9 in
# INTCLEAR (irq_clear, mask 0x200), enables it (irq_enable, mask 0x200), then runs irq_line_config(7, 0, 0)
# (writes nothing for line 7) and irq_line_init(7). Called once by the start-up routine sys_init_and_run_main_loop.
# Arguments: none. Locals: none. Returns: nothing.
# Calls: irq_set_handler, irq_install_step_empty, irq_clear, irq_enable, irq_line_config, irq_line_init
# Addresses loaded: ldc_irq_handler

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_irq_install, @function
ldc_irq_install:                        # fn_40008f58
	entry	a1, 32                  # 40008f58
	# irq_set_handler(9, ldc_irq_handler);   (install the handler of interrupt 9)
	movi.n	a10, 9                  # 40008f5b
	l32r	a11, lit_3ffe2254       # 40008f5d  = ldc_irq_handler
	call8	irq_set_handler         # 40008f60
	# irq_install_step_empty();   (empty routine)
	call8	irq_install_step_empty  # 40008f63
	# INTCLEAR = 0x200;   (irq_clear)
	movi	a10, 0x200              # 40008f66
	call8	irq_clear               # 40008f69
	# irq_enable(0x200);   (enable mask: interrupt 9)
	movi	a10, 0x200              # 40008f6c
	call8	irq_enable              # 40008f6f
	# irq_line_config(7, 0, 0);
	movi.n	a10, 7                  # 40008f72
	movi.n	a11, 0                  # 40008f74
	movi.n	a12, 0                  # 40008f76
	call8	irq_line_config         # 40008f78
	# irq_line_init(7);
	movi.n	a10, 7                  # 40008f7b
	call8	irq_line_init           # 40008f7d
	retw.n                          # 40008f80
	.size	ldc_irq_install, . - ldc_irq_install
