# irq_sw_install  (fn_40008e9c): 0x40008e9c-0x40008ec3 (firmware file offset 0x38e9c-0x38ec3), 16 instructions
# Name basis: derived - irq_set_handler(0, irq_sw_handler), INTCLEAR/INTENABLE mask 1
# Called from: sys_init_and_run_main_loop
# Installs irq_sw_handler for interrupt 0 (irq_set_handler), runs the empty irq_install_step_empty, clears interrupt 0 in
# INTCLEAR (irq_clear, mask 1), enables it (irq_enable, mask 1), then sets up line 0 of the block at
# 0xE00A1000: irq_line_config(0, 0, 0) and irq_line_init(0). Called once by the start-up routine sys_init_and_run_main_loop.
# Arguments: none. Locals: none. Returns: nothing.
# Calls: irq_set_handler, irq_install_step_empty, irq_clear, irq_enable, irq_line_config, irq_line_init
# Addresses loaded: irq_sw_handler

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_sw_install, @function
irq_sw_install:                         # fn_40008e9c
	entry	a1, 32                  # 40008e9c
	# irq_set_handler(0, irq_sw_handler);   (install the handler of interrupt 0)
	movi.n	a10, 0                  # 40008e9f
	l32r	a11, lit_3ffe2238       # 40008ea1  = irq_sw_handler
	call8	irq_set_handler         # 40008ea4
	# irq_install_step_empty();   (empty routine)
	call8	irq_install_step_empty  # 40008ea7
	# INTCLEAR = 1;   (irq_clear)
	movi.n	a10, 1                  # 40008eaa
	call8	irq_clear               # 40008eac
	# irq_enable(1);   (enable mask: interrupt 0)
	movi.n	a10, 1                  # 40008eaf
	call8	irq_enable              # 40008eb1
	# irq_line_config(0, 0, 0);
	movi.n	a10, 0                  # 40008eb4
	movi.n	a11, 0                  # 40008eb6
	movi.n	a12, 0                  # 40008eb8
	call8	irq_line_config         # 40008eba
	# irq_line_init(0);
	movi.n	a10, 0                  # 40008ebd
	call8	irq_line_init           # 40008ebf
	retw.n                          # 40008ec2
	.size	irq_sw_install, . - irq_sw_install
