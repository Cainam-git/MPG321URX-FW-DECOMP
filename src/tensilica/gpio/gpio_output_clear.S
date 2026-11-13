# gpio_output_clear  (fn_400089e8): 0x400089e8-0x40008ad4 (firmware file offset 0x389e8-0x38ad4), 82 instructions
# Name basis: derived - clrb_expstate per case; error text 'gpio_set_output'; dbg_cmd_gpio_test
# Called from: dbg_cmd_gpio_test
# Clears bit gpio (0..31) of the EXPSTATE register with clrb_expstate (one case per bit, jump table ro_3ffe14d0).
# For gpio 32 or more prints "[ERR] gpio_set_output: gpio index out of range (%bu)\n" (the text both this
# routine and gpio_output_set print). Called by dbg_cmd_gpio_test (debug command "gpio [port]").
# a2 = gpio: bit number.
# Locals: a1+16 gpio, a1+0 / a1+4 switch value (copies of gpio).
# Returns: nothing.
# Calls: dbg_printf
# Text loaded: "[ERR] gpio_set_output: gpio index out of range (%bu)\n"
# Addresses loaded: ro_3ffe14d0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	gpio_output_clear, @function
gpio_output_clear:                      # fn_400089e8
	entry	a1, 64                  # 400089e8
	s32i.n	a2, a1, 16              # 400089eb
	l32i.n	a5, a1, 16              # 400089ed
	# switch (gpio)   (32 cases; default prints the error)
	s32i.n	a5, a1, 0               # 400089ef
	l32i.n	a4, a1, 0               # 400089f1
	s32i.n	a4, a1, 4               # 400089f3
	bltui	a4, 32, .L400089fb      # 400089f5
	j	.L40008ac8              # 400089f8
.L400089fb:
	l32r	a7, lit_3ffe2210        # 400089fb  = ro_3ffe14d0
	l32i.n	a6, a1, 4               # 400089fe
	addx4	a6, a6, a7              # 40008a00
	l32i.n	a6, a6, 0               # 40008a03
	jx	a6                      # 40008a05
.L40008a08:
	# case 0: EXPSTATE bit 0 = 0; break;
	clrb_expstate	0               # 40008a08
	j	.L40008ad3              # 40008a0b
.L40008a0e:
	# case 1: EXPSTATE bit 1 = 0; break;
	clrb_expstate	1               # 40008a0e
	j	.L40008ad3              # 40008a11
.L40008a14:
	# case 2: EXPSTATE bit 2 = 0; break;
	clrb_expstate	2               # 40008a14
	j	.L40008ad3              # 40008a17
.L40008a1a:
	# case 3: EXPSTATE bit 3 = 0; break;
	clrb_expstate	3               # 40008a1a
	j	.L40008ad3              # 40008a1d
.L40008a20:
	# case 4: EXPSTATE bit 4 = 0; break;
	clrb_expstate	4               # 40008a20
	j	.L40008ad3              # 40008a23
.L40008a26:
	# case 5: EXPSTATE bit 5 = 0; break;
	clrb_expstate	5               # 40008a26
	j	.L40008ad3              # 40008a29
.L40008a2c:
	# case 6: EXPSTATE bit 6 = 0; break;
	clrb_expstate	6               # 40008a2c
	j	.L40008ad3              # 40008a2f
.L40008a32:
	# case 7: EXPSTATE bit 7 = 0; break;
	clrb_expstate	7               # 40008a32
	j	.L40008ad3              # 40008a35
.L40008a38:
	# case 8: EXPSTATE bit 8 = 0; break;
	clrb_expstate	8               # 40008a38
	j	.L40008ad3              # 40008a3b
.L40008a3e:
	# case 9: EXPSTATE bit 9 = 0; break;
	clrb_expstate	9               # 40008a3e
	j	.L40008ad3              # 40008a41
.L40008a44:
	# case 10: EXPSTATE bit 10 = 0; break;
	clrb_expstate	10              # 40008a44
	j	.L40008ad3              # 40008a47
.L40008a4a:
	# case 11: EXPSTATE bit 11 = 0; break;
	clrb_expstate	11              # 40008a4a
	j	.L40008ad3              # 40008a4d
.L40008a50:
	# case 12: EXPSTATE bit 12 = 0; break;
	clrb_expstate	12              # 40008a50
	j	.L40008ad3              # 40008a53
.L40008a56:
	# case 13: EXPSTATE bit 13 = 0; break;
	clrb_expstate	13              # 40008a56
	j	.L40008ad3              # 40008a59
.L40008a5c:
	# case 14: EXPSTATE bit 14 = 0; break;
	clrb_expstate	14              # 40008a5c
	j	.L40008ad3              # 40008a5f
.L40008a62:
	# case 15: EXPSTATE bit 15 = 0; break;
	clrb_expstate	15              # 40008a62
	j	.L40008ad3              # 40008a65
.L40008a68:
	# case 16: EXPSTATE bit 16 = 0; break;
	clrb_expstate	16              # 40008a68
	j	.L40008ad3              # 40008a6b
.L40008a6e:
	# case 17: EXPSTATE bit 17 = 0; break;
	clrb_expstate	17              # 40008a6e
	j	.L40008ad3              # 40008a71
.L40008a74:
	# case 18: EXPSTATE bit 18 = 0; break;
	clrb_expstate	18              # 40008a74
	j	.L40008ad3              # 40008a77
.L40008a7a:
	# case 19: EXPSTATE bit 19 = 0; break;
	clrb_expstate	19              # 40008a7a
	j	.L40008ad3              # 40008a7d
.L40008a80:
	# case 20: EXPSTATE bit 20 = 0; break;
	clrb_expstate	20              # 40008a80
	j	.L40008ad3              # 40008a83
.L40008a86:
	# case 21: EXPSTATE bit 21 = 0; break;
	clrb_expstate	21              # 40008a86
	j	.L40008ad3              # 40008a89
.L40008a8c:
	# case 22: EXPSTATE bit 22 = 0; break;
	clrb_expstate	22              # 40008a8c
	j	.L40008ad3              # 40008a8f
.L40008a92:
	# case 23: EXPSTATE bit 23 = 0; break;
	clrb_expstate	23              # 40008a92
	j	.L40008ad3              # 40008a95
.L40008a98:
	# case 24: EXPSTATE bit 24 = 0; break;
	clrb_expstate	24              # 40008a98
	j	.L40008ad3              # 40008a9b
.L40008a9e:
	# case 25: EXPSTATE bit 25 = 0; break;
	clrb_expstate	25              # 40008a9e
	j	.L40008ad3              # 40008aa1
.L40008aa4:
	# case 26: EXPSTATE bit 26 = 0; break;
	clrb_expstate	26              # 40008aa4
	j	.L40008ad3              # 40008aa7
.L40008aaa:
	# case 27: EXPSTATE bit 27 = 0; break;
	clrb_expstate	27              # 40008aaa
	j	.L40008ad3              # 40008aad
.L40008ab0:
	# case 28: EXPSTATE bit 28 = 0; break;
	clrb_expstate	28              # 40008ab0
	j	.L40008ad3              # 40008ab3
.L40008ab6:
	# case 29: EXPSTATE bit 29 = 0; break;
	clrb_expstate	29              # 40008ab6
	j	.L40008ad3              # 40008ab9
.L40008abc:
	# case 30: EXPSTATE bit 30 = 0; break;
	clrb_expstate	30              # 40008abc
	j	.L40008ad3              # 40008abf
.L40008ac2:
	# case 31: EXPSTATE bit 31 = 0; break;
	clrb_expstate	31              # 40008ac2
	j	.L40008ad3              # 40008ac5
.L40008ac8:
	# default: printf("[ERR] gpio_set_output: gpio index out of range (%bu)\n", gpio);
	l32r	a10, lit_3ffe2214       # 40008ac8  = ro_3ffe1490 "[ERR] gpio_set_output: gpio index out of range (%bu)\n"
	l32i.n	a11, a1, 16             # 40008acb
	call8	dbg_printf              # 40008acd
	j	.L40008ad3              # 40008ad0
.L40008ad3:
	retw.n                          # 40008ad3
	.size	gpio_output_clear, . - gpio_output_clear
