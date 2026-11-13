# ldc_as3824_set_curr_ctrl  (fn_40007878): 0x40007878-0x4000789d (firmware file offset 0x37878-0x3789d), 15 instructions
# Name basis: proven - prints 'LED AS3824 CURR CTRL: 0x%04X'
# Called from: ldc_as3824_apply_direct_pwm, LED_AS3824_Init
# Stores the value in AS3824Buf.CurrCtrl, writes its low byte to AS3824 register 7 and prints
# "LED AS3824 CURR CTRL: 0x%04X".
# Arguments: a2 value.
# Locals: a1+0 value.
# Returns: nothing.
# Calls: ldc_as3824_write_byte, dbg_printf
# Text loaded: "LED AS3824 CURR CTRL: 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_set_curr_ctrl, @function
ldc_as3824_set_curr_ctrl:               # fn_40007878
	entry	a1, 48                  # 40007878
	s32i.n	a2, a1, 0               # 4000787b
	# AS3824Buf.CurrCtrl = value;
	l32r	a13, lit_3ffe20ac       # 4000787d  = 0x3ffe54a0
	l32i.n	a12, a1, 0              # 40007880
	s32i.n	a12, a13, 16            # 40007882
	# ldc_as3824_write_byte(7, AS3824Buf.CurrCtrl & 0xFF);
	movi.n	a10, 7                  # 40007884
	l32r	a11, lit_3ffe20ac       # 40007886  = 0x3ffe54a0
	l32i.n	a11, a11, 16            # 40007889
	extui	a11, a11, 0, 8          # 4000788b
	call8	ldc_as3824_write_byte   # 4000788e
	# printf("LED AS3824 CURR CTRL: 0x%04X\n", AS3824Buf.CurrCtrl);
	l32r	a10, lit_3ffe20d0       # 40007891  = ro_3ffe0cb0 "LED AS3824 CURR CTRL: 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007894  = 0x3ffe54a0
	l32i.n	a11, a11, 16            # 40007897
	call8	dbg_printf              # 40007899
	retw.n                          # 4000789c
	.size	ldc_as3824_set_curr_ctrl, . - ldc_as3824_set_curr_ctrl
