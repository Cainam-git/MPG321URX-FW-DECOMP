# ldc_as3824_set_dacref_bit  (fn_400078a0): 0x400078a0-0x400078e4 (firmware file offset 0x378a0-0x378e4), 27 instructions
# Name basis: proven - prints 'LED AS3824 CURR CTRL(DACref): 0x%04X'
# Called from: ldc_as3824_update
# Clears bit 2 of AS3824Buf.CurrCtrl when the LED mode is below 4 and sets it otherwise, writes CurrCtrl to
# AS3824 register 7 and prints "LED AS3824 CURR CTRL(DACref): 0x%04X". Called by ldc_as3824_update when LED_Mode
# changes.
# Arguments: a2 led_mode (panel LED_Mode, 0x3FFE2D30).
# Locals: a1+0 led_mode.
# Returns: nothing.
# Calls: ldc_as3824_write_byte, dbg_printf
# Text loaded: "LED AS3824 CURR CTRL(DACref): 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_set_dacref_bit, @function
ldc_as3824_set_dacref_bit:              # fn_400078a0
	entry	a1, 48                  # 400078a0
	s32i.n	a2, a1, 0               # 400078a3
	# if (led_mode < 4)
	l32i.n	a4, a1, 0               # 400078a5
	bgeui	a4, 4, .L400078bc       # 400078a7
	#     AS3824Buf.CurrCtrl &= ~4;
	l32r	a6, lit_3ffe20ac        # 400078aa  = 0x3ffe54a0
	movi.n	a7, -5                  # 400078ad
	l32r	a5, lit_3ffe20ac        # 400078af  = 0x3ffe54a0
	l32i.n	a5, a5, 16              # 400078b2
	and	a5, a5, a7              # 400078b4
	s32i.n	a5, a6, 16              # 400078b7
	j	.L400078cb              # 400078b9
.L400078bc:
	# else AS3824Buf.CurrCtrl |= 4;
	l32r	a7, lit_3ffe20ac        # 400078bc  = 0x3ffe54a0
	movi.n	a8, 4                   # 400078bf
	l32r	a6, lit_3ffe20ac        # 400078c1  = 0x3ffe54a0
	l32i.n	a6, a6, 16              # 400078c4
	or	a6, a6, a8              # 400078c6
	s32i.n	a6, a7, 16              # 400078c9
.L400078cb:
	# ldc_as3824_write_byte(7, AS3824Buf.CurrCtrl & 0xFF);
	movi.n	a10, 7                  # 400078cb
	l32r	a11, lit_3ffe20ac       # 400078cd  = 0x3ffe54a0
	l32i.n	a11, a11, 16            # 400078d0
	extui	a11, a11, 0, 8          # 400078d2
	call8	ldc_as3824_write_byte   # 400078d5
	# printf("LED AS3824 CURR CTRL(DACref): 0x%04X\n", AS3824Buf.CurrCtrl);
	l32r	a10, lit_3ffe20d4       # 400078d8  = ro_3ffe0cd0 "LED AS3824 CURR CTRL(DACref): 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 400078db  = 0x3ffe54a0
	l32i.n	a11, a11, 16            # 400078de
	call8	dbg_printf              # 400078e0
	retw.n                          # 400078e3
	.size	ldc_as3824_set_dacref_bit, . - ldc_as3824_set_dacref_bit
