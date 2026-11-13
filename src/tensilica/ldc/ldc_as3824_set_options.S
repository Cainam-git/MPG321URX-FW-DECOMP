# ldc_as3824_set_options  (fn_400078e8): 0x400078e8-0x40007910 (firmware file offset 0x378e8-0x37910), 15 instructions
# Name basis: proven - prints 'LED AS3824 Options: 0x%04X'
# Called from: ldc_as3824_apply_direct_pwm, LED_AS3824_Init
# Stores the value in AS3824Buf.Options, writes its low byte to AS3824 register 89 (0x59) and prints
# "LED AS3824 Options: 0x%04X".
# Arguments: a2 value.
# Locals: a1+0 value.
# Returns: nothing.
# Calls: ldc_as3824_write_byte, dbg_printf
# Text loaded: "LED AS3824 Options: 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_set_options, @function
ldc_as3824_set_options:                 # fn_400078e8
	entry	a1, 48                  # 400078e8
	s32i.n	a2, a1, 0               # 400078eb
	# AS3824Buf.Options = value;
	l32r	a13, lit_3ffe20ac       # 400078ed  = 0x3ffe54a0
	l32i.n	a12, a1, 0              # 400078f0
	s32i	a12, a13, 160           # 400078f2
	# ldc_as3824_write_byte(89, AS3824Buf.Options & 0xFF);
	movi.n	a10, 89                 # 400078f5
	l32r	a11, lit_3ffe20ac       # 400078f7  = 0x3ffe54a0
	l32i	a11, a11, 160           # 400078fa
	extui	a11, a11, 0, 8          # 400078fd
	call8	ldc_as3824_write_byte   # 40007900
	# printf("LED AS3824 Options: 0x%04X\n", AS3824Buf.Options);
	l32r	a10, lit_3ffe20d8       # 40007903  = ro_3ffe0cf8 "LED AS3824 Options: 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007906  = 0x3ffe54a0
	l32i	a11, a11, 160           # 40007909
	call8	dbg_printf              # 4000790c
	retw.n                          # 4000790f
	.size	ldc_as3824_set_options, . - ldc_as3824_set_options
