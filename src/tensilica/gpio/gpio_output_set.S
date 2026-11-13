# gpio_output_set  (fn_40008af8): 0x40008af8-0x40008be4 (firmware file offset 0x38af8-0x38be4), 82 instructions
# Name basis: derived - setb_expstate per case; error text 'gpio_set_output'; dbg_cmd_gpio_test
# Called from: dbg_cmd_gpio_test
# Sets bit gpio (0..31) of the EXPSTATE register with setb_expstate (one case per bit, jump table ro_3ffe1550).
# For gpio 32 or more prints "[ERR] gpio_set_output: gpio index out of range (%bu)\n" (the text both this
# routine and gpio_output_clear print). Called by dbg_cmd_gpio_test (debug command "gpio [port]").
# a2 = gpio: bit number.
# Locals: a1+16 gpio, a1+0 / a1+4 switch value (copies of gpio).
# Returns: nothing.
# Calls: dbg_printf
# Text loaded: "[ERR] gpio_set_output: gpio index out of range (%bu)\n"
# Addresses loaded: ro_3ffe1550

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	gpio_output_set, @function
gpio_output_set:                        # fn_40008af8
	entry	a1, 64                  # 40008af8
	s32i.n	a2, a1, 16              # 40008afb
	l32i.n	a5, a1, 16              # 40008afd
	# switch (gpio)   (32 cases; default prints the error)
	s32i.n	a5, a1, 0               # 40008aff
	l32i.n	a4, a1, 0               # 40008b01
	s32i.n	a4, a1, 4               # 40008b03
	bltui	a4, 32, .L40008b0b      # 40008b05
	j	.L40008bd8              # 40008b08
.L40008b0b:
	l32r	a7, lit_3ffe2218        # 40008b0b  = ro_3ffe1550
	l32i.n	a6, a1, 4               # 40008b0e
	addx4	a6, a6, a7              # 40008b10
	l32i.n	a6, a6, 0               # 40008b13
	jx	a6                      # 40008b15
.L40008b18:
	# case 0: EXPSTATE bit 0 = 1; break;
	setb_expstate	0               # 40008b18
	j	.L40008be3              # 40008b1b
.L40008b1e:
	# case 1: EXPSTATE bit 1 = 1; break;
	setb_expstate	1               # 40008b1e
	j	.L40008be3              # 40008b21
.L40008b24:
	# case 2: EXPSTATE bit 2 = 1; break;
	setb_expstate	2               # 40008b24
	j	.L40008be3              # 40008b27
.L40008b2a:
	# case 3: EXPSTATE bit 3 = 1; break;
	setb_expstate	3               # 40008b2a
	j	.L40008be3              # 40008b2d
.L40008b30:
	# case 4: EXPSTATE bit 4 = 1; break;
	setb_expstate	4               # 40008b30
	j	.L40008be3              # 40008b33
.L40008b36:
	# case 5: EXPSTATE bit 5 = 1; break;
	setb_expstate	5               # 40008b36
	j	.L40008be3              # 40008b39
.L40008b3c:
	# case 6: EXPSTATE bit 6 = 1; break;
	setb_expstate	6               # 40008b3c
	j	.L40008be3              # 40008b3f
.L40008b42:
	# case 7: EXPSTATE bit 7 = 1; break;
	setb_expstate	7               # 40008b42
	j	.L40008be3              # 40008b45
.L40008b48:
	# case 8: EXPSTATE bit 8 = 1; break;
	setb_expstate	8               # 40008b48
	j	.L40008be3              # 40008b4b
.L40008b4e:
	# case 9: EXPSTATE bit 9 = 1; break;
	setb_expstate	9               # 40008b4e
	j	.L40008be3              # 40008b51
.L40008b54:
	# case 10: EXPSTATE bit 10 = 1; break;
	setb_expstate	10              # 40008b54
	j	.L40008be3              # 40008b57
.L40008b5a:
	# case 11: EXPSTATE bit 11 = 1; break;
	setb_expstate	11              # 40008b5a
	j	.L40008be3              # 40008b5d
.L40008b60:
	# case 12: EXPSTATE bit 12 = 1; break;
	setb_expstate	12              # 40008b60
	j	.L40008be3              # 40008b63
.L40008b66:
	# case 13: EXPSTATE bit 13 = 1; break;
	setb_expstate	13              # 40008b66
	j	.L40008be3              # 40008b69
.L40008b6c:
	# case 14: EXPSTATE bit 14 = 1; break;
	setb_expstate	14              # 40008b6c
	j	.L40008be3              # 40008b6f
.L40008b72:
	# case 15: EXPSTATE bit 15 = 1; break;
	setb_expstate	15              # 40008b72
	j	.L40008be3              # 40008b75
.L40008b78:
	# case 16: EXPSTATE bit 16 = 1; break;
	setb_expstate	16              # 40008b78
	j	.L40008be3              # 40008b7b
.L40008b7e:
	# case 17: EXPSTATE bit 17 = 1; break;
	setb_expstate	17              # 40008b7e
	j	.L40008be3              # 40008b81
.L40008b84:
	# case 18: EXPSTATE bit 18 = 1; break;
	setb_expstate	18              # 40008b84
	j	.L40008be3              # 40008b87
.L40008b8a:
	# case 19: EXPSTATE bit 19 = 1; break;
	setb_expstate	19              # 40008b8a
	j	.L40008be3              # 40008b8d
.L40008b90:
	# case 20: EXPSTATE bit 20 = 1; break;
	setb_expstate	20              # 40008b90
	j	.L40008be3              # 40008b93
.L40008b96:
	# case 21: EXPSTATE bit 21 = 1; break;
	setb_expstate	21              # 40008b96
	j	.L40008be3              # 40008b99
.L40008b9c:
	# case 22: EXPSTATE bit 22 = 1; break;
	setb_expstate	22              # 40008b9c
	j	.L40008be3              # 40008b9f
.L40008ba2:
	# case 23: EXPSTATE bit 23 = 1; break;
	setb_expstate	23              # 40008ba2
	j	.L40008be3              # 40008ba5
.L40008ba8:
	# case 24: EXPSTATE bit 24 = 1; break;
	setb_expstate	24              # 40008ba8
	j	.L40008be3              # 40008bab
.L40008bae:
	# case 25: EXPSTATE bit 25 = 1; break;
	setb_expstate	25              # 40008bae
	j	.L40008be3              # 40008bb1
.L40008bb4:
	# case 26: EXPSTATE bit 26 = 1; break;
	setb_expstate	26              # 40008bb4
	j	.L40008be3              # 40008bb7
.L40008bba:
	# case 27: EXPSTATE bit 27 = 1; break;
	setb_expstate	27              # 40008bba
	j	.L40008be3              # 40008bbd
.L40008bc0:
	# case 28: EXPSTATE bit 28 = 1; break;
	setb_expstate	28              # 40008bc0
	j	.L40008be3              # 40008bc3
.L40008bc6:
	# case 29: EXPSTATE bit 29 = 1; break;
	setb_expstate	29              # 40008bc6
	j	.L40008be3              # 40008bc9
.L40008bcc:
	# case 30: EXPSTATE bit 30 = 1; break;
	setb_expstate	30              # 40008bcc
	j	.L40008be3              # 40008bcf
.L40008bd2:
	# case 31: EXPSTATE bit 31 = 1; break;
	setb_expstate	31              # 40008bd2
	j	.L40008be3              # 40008bd5
.L40008bd8:
	# default: printf("[ERR] gpio_set_output: gpio index out of range (%bu)\n", gpio);
	l32r	a10, lit_3ffe2214       # 40008bd8  = ro_3ffe1490 "[ERR] gpio_set_output: gpio index out of range (%bu)\n"
	l32i.n	a11, a1, 16             # 40008bdb
	call8	dbg_printf              # 40008bdd
	j	.L40008be3              # 40008be0
.L40008be3:
	retw.n                          # 40008be3
	.size	gpio_output_set, . - gpio_output_set
