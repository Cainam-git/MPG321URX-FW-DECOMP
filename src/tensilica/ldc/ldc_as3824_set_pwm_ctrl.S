# ldc_as3824_set_pwm_ctrl  (fn_4000784c): 0x4000784c-0x40007874 (firmware file offset 0x3784c-0x37874), 16 instructions
# Name basis: proven - prints 'LED AS3824 PWM CTRL: 0x%04X'
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Stores the low byte of the value in AS3824Buf.PWM_Ctrl, writes it to AS3824 register 19 (0x13) and prints
# "LED AS3824 PWM CTRL: 0x%04X". Not called anywhere and its address is not stored.
# Arguments: a2 value.
# Locals: a1+0 value.
# Returns: nothing.
# Calls: ldc_as3824_write_byte, dbg_printf
# Text loaded: "LED AS3824 PWM CTRL: 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_set_pwm_ctrl, @function
ldc_as3824_set_pwm_ctrl:                # fn_4000784c
	entry	a1, 48                  # 4000784c
	s32i.n	a2, a1, 0               # 4000784f
	# AS3824Buf.PWM_Ctrl = value & 0xFF;
	l32r	a13, lit_3ffe20ac       # 40007851  = 0x3ffe54a0
	l32i.n	a12, a1, 0              # 40007854
	extui	a12, a12, 0, 8          # 40007856
	s32i.n	a12, a13, 20            # 40007859
	# ldc_as3824_write_byte(19, AS3824Buf.PWM_Ctrl & 0xFF);
	movi.n	a10, 19                 # 4000785b
	l32r	a11, lit_3ffe20ac       # 4000785d  = 0x3ffe54a0
	l32i.n	a11, a11, 20            # 40007860
	extui	a11, a11, 0, 8          # 40007862
	call8	ldc_as3824_write_byte   # 40007865
	# printf("LED AS3824 PWM CTRL: 0x%04X\n", AS3824Buf.PWM_Ctrl);
	l32r	a10, lit_3ffe20cc       # 40007868  = ro_3ffe0c90 "LED AS3824 PWM CTRL: 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 4000786b  = 0x3ffe54a0
	l32i.n	a11, a11, 20            # 4000786e
	call8	dbg_printf              # 40007870
	retw.n                          # 40007873
	.size	ldc_as3824_set_pwm_ctrl, . - ldc_as3824_set_pwm_ctrl
