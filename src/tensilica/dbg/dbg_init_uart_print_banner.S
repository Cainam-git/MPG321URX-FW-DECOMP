# dbg_init_uart_print_banner  (fn_40003c94): 0x40003c94-0x40003ccd (firmware file offset 0x33c94-0x33ccd), 21 instructions
# Name basis: proven - texts 'NT68500 FW Version', 'Built time'; config 115200 in dbg_uart_config
# Called from: sys_init_and_run_main_loop
# Calls: uart_init, dbg_printf
# Text loaded: "\n-----------------------------------------\n", "Core %s\n", "NVT_Formal_RG20189",
#              "NT68500 FW Version: %d.%d.%d (customer id = %d)\n", "Built time: %s %s\n", "Nov 10 2025",
#              "09:47:58", "--------------------------------------------\n"
# Addresses loaded: dbg_uart_config
#
# Called once from the main routine sys_init_and_run_main_loop. Sets up the serial port with the record dbg_uart_config (first
# word 115200) through uart_init, then prints the banner: "Core NVT_Formal_RG20189", "NT68500 FW Version:
# 0.1.0 (customer id = 1)" and "Built time: Nov 10 2025 09:47:58" between two dashed lines.
# Arguments: none.
# Locals: none.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_init_uart_print_banner, @function
dbg_init_uart_print_banner:             # fn_40003c94
	entry	a1, 32                  # 40003c94
	# uart_init(&dbg_uart_config)   (serial port set-up)
	l32r	a10, lit_3ffe1cfc       # 40003c97  = dbg_uart_config
	call8	uart_init               # 40003c9a
	# printf("\n-----...\n")
	l32r	a10, lit_3ffe1d00       # 40003c9d  = ro_3ffe0538 "\n-----------------------------------------\n"
	call8	dbg_printf              # 40003ca0
	# printf("Core %s\n", "NVT_Formal_RG20189")
	l32r	a10, lit_3ffe1d04       # 40003ca3  = ro_3ffe0564 "Core %s\n"
	l32r	a11, lit_3ffe1d08       # 40003ca6  = ro_3ffe0570 "NVT_Formal_RG20189"
	call8	dbg_printf              # 40003ca9
	# printf("NT68500 FW Version: %d.%d.%d (customer id = %d)\n", 0, 1, 0, 1)
	l32r	a10, lit_3ffe1d0c       # 40003cac  = ro_3ffe0584 "NT68500 FW Version: %d.%d.%d (customer id = %d)\n"
	movi.n	a11, 0                  # 40003caf
	movi.n	a12, 1                  # 40003cb1
	movi.n	a13, 0                  # 40003cb3
	movi.n	a14, 1                  # 40003cb5
	call8	dbg_printf              # 40003cb7
	# printf("Built time: %s %s\n", "Nov 10 2025", "09:47:58")
	l32r	a10, lit_3ffe1d10       # 40003cba  = ro_3ffe05b8 "Built time: %s %s\n"
	l32r	a11, lit_3ffe1d14       # 40003cbd  = ro_3ffe05cc "Nov 10 2025"
	l32r	a12, lit_3ffe1d18       # 40003cc0  = ro_3ffe05d8 "09:47:58"
	call8	dbg_printf              # 40003cc3
	# printf("-----...\n")
	l32r	a10, lit_3ffe1d1c       # 40003cc6  = ro_3ffe05e4 "--------------------------------------------\n"
	call8	dbg_printf              # 40003cc9
	retw.n                          # 40003ccc
	.size	dbg_init_uart_print_banner, . - dbg_init_uart_print_banner
