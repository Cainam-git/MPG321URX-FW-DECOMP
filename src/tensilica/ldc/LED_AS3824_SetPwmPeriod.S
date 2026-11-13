# LED_AS3824_SetPwmPeriod  (fn_400077a4): 0x400077a4-0x400077d1 (firmware file offset 0x377a4-0x377d1), 19 instructions
# Name basis: proven - original name, printed in 'LED_AS3824_SetPwmPeriod = 0x%X'
# Called from: LED_AS3824_Init
# Stores the period in AS3824Buf.PWM_Period, writes it as a 16-bit value to AS3824 register 20 (0x14) and prints
# "LED_AS3824_SetPwmPeriod = 0x%X". The name is the one the routine prints.
# Arguments: a2 period.
# Locals: a1+0 unused[2] (8 bytes copied from ro_3ffe0c48, never read), a1+16 period.
# Returns: nothing.
# Calls: ldc_as3824_write_word, dbg_printf
# Text loaded: "LED_AS3824_SetPwmPeriod = 0x%X \n"
# Addresses loaded: ro_3ffe0c48
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	LED_AS3824_SetPwmPeriod, @function
LED_AS3824_SetPwmPeriod:                # fn_400077a4
	entry	a1, 64                  # 400077a4
	s32i.n	a2, a1, 16              # 400077a7
	# u32 unused[2] = 8 bytes copied from ro_3ffe0c48;
	l32r	a13, lit_3ffe20bc       # 400077a9  = ro_3ffe0c48
	l32i.n	a14, a13, 4             # 400077ac
	s32i.n	a14, a1, 4              # 400077ae
	l32i.n	a13, a13, 0             # 400077b0
	s32i.n	a13, a1, 0              # 400077b2
	# AS3824Buf.PWM_Period = period;
	l32r	a13, lit_3ffe20ac       # 400077b4  = 0x3ffe54a0
	l32i.n	a12, a1, 16             # 400077b7
	s32i.n	a12, a13, 24            # 400077b9
	# ldc_as3824_write_word(20, AS3824Buf.PWM_Period);
	movi.n	a10, 20                 # 400077bb
	l32r	a11, lit_3ffe20ac       # 400077bd  = 0x3ffe54a0
	l32i.n	a11, a11, 24            # 400077c0
	call8	ldc_as3824_write_word   # 400077c2
	# printf("LED_AS3824_SetPwmPeriod = 0x%X \n", AS3824Buf.PWM_Period);
	l32r	a10, lit_3ffe20c0       # 400077c5  = ro_3ffe0c20 "LED_AS3824_SetPwmPeriod = 0x%X \n"
	l32r	a11, lit_3ffe20ac       # 400077c8  = 0x3ffe54a0
	l32i.n	a11, a11, 24            # 400077cb
	call8	dbg_printf              # 400077cd
	retw.n                          # 400077d0
	.size	LED_AS3824_SetPwmPeriod, . - LED_AS3824_SetPwmPeriod
