# dbg_print_sw_value  (fn_40005c24): 0x40005c24-0x40005c3b (firmware file offset 0x35c24-0x35c3b), 9 instructions
# Name basis: derived - texts; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Prints "NT68500 Tensilica S/W : ", the argument as eight hex digits (uart_put_hex_word writes them straight to the
# serial output) and "#\n". Nothing calls it and no stored word holds its address.
# Arguments: a2 value.
# Locals: a1+0 value.
# Returns: nothing.
# Calls: dbg_printf, uart_put_hex_word
# Text loaded: "NT68500 Tensilica S/W : "
# Addresses loaded: ro_3ffe09cc

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_print_sw_value, @function
dbg_print_sw_value:                     # fn_40005c24
	entry	a1, 48                  # 40005c24
	s32i.n	a2, a1, 0               # 40005c27
	# printf("NT68500 Tensilica S/W : ");
	l32r	a10, lit_3ffe1e10       # 40005c29  = ro_3ffe09b0 "NT68500 Tensilica S/W : "
	call8	dbg_printf              # 40005c2c
	# uart_put_hex_word(value);
	l32i.n	a10, a1, 0              # 40005c2f
	call8	uart_put_hex_word       # 40005c31
	# printf("#\n");
	l32r	a10, lit_3ffe1e14       # 40005c34  = ro_3ffe09cc
	call8	dbg_printf              # 40005c37
	retw.n                          # 40005c3a
	.size	dbg_print_sw_value, . - dbg_print_sw_value
