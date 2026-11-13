# ldc_as3824_set_direct_pwm_bit  (fn_40007914): 0x40007914-0x40007955 (firmware file offset 0x37914-0x37955), 26 instructions
# Name basis: proven - prints 'LED AS3824 Direct PWM: 0x%04X'
# Called from: ldc_as3824_apply_direct_pwm, LED_AS3824_Init
# Sets bit 2 of AS3824Buf.PWM_Ctrl when the argument is 1 and clears it otherwise, writes PWM_Ctrl to AS3824
# register 19 (0x13) and prints "LED AS3824 Direct PWM: 0x%04X" with the argument.
# Arguments: a2 on.
# Locals: a1+0 on.
# Returns: nothing.
# Calls: ldc_as3824_write_byte, dbg_printf
# Text loaded: "LED AS3824 Direct PWM: 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_set_direct_pwm_bit, @function
ldc_as3824_set_direct_pwm_bit:          # fn_40007914
	entry	a1, 48                  # 40007914
	s32i.n	a2, a1, 0               # 40007917
	# if (on == 1)
	l32i.n	a4, a1, 0               # 40007919
	bnei	a4, 1, .L40007930       # 4000791b
	#     AS3824Buf.PWM_Ctrl |= 4;
	l32r	a6, lit_3ffe20ac        # 4000791e  = 0x3ffe54a0
	movi.n	a7, 4                   # 40007921
	l32r	a5, lit_3ffe20ac        # 40007923  = 0x3ffe54a0
	l32i.n	a5, a5, 20              # 40007926
	or	a5, a5, a7              # 40007928
	s32i.n	a5, a6, 20              # 4000792b
	j	.L4000793f              # 4000792d
.L40007930:
	# else AS3824Buf.PWM_Ctrl &= ~4;
	l32r	a7, lit_3ffe20ac        # 40007930  = 0x3ffe54a0
	movi.n	a8, -5                  # 40007933
	l32r	a6, lit_3ffe20ac        # 40007935  = 0x3ffe54a0
	l32i.n	a6, a6, 20              # 40007938
	and	a6, a6, a8              # 4000793a
	s32i.n	a6, a7, 20              # 4000793d
.L4000793f:
	# ldc_as3824_write_byte(19, AS3824Buf.PWM_Ctrl & 0xFF);
	movi.n	a10, 19                 # 4000793f
	l32r	a11, lit_3ffe20ac       # 40007941  = 0x3ffe54a0
	l32i.n	a11, a11, 20            # 40007944
	extui	a11, a11, 0, 8          # 40007946
	call8	ldc_as3824_write_byte   # 40007949
	# printf("LED AS3824 Direct PWM: 0x%04X\n", on);
	l32r	a10, lit_3ffe20dc       # 4000794c  = ro_3ffe0d14 "LED AS3824 Direct PWM: 0x%04X\n"
	l32i.n	a11, a1, 0              # 4000794f
	call8	dbg_printf              # 40007951
	retw.n                          # 40007954
	.size	ldc_as3824_set_direct_pwm_bit, . - ldc_as3824_set_direct_pwm_bit
