# ldc_as3824_set_current_on  (fn_400077fc): 0x400077fc-0x4000781e (firmware file offset 0x377fc-0x3781e), 14 instructions
# Name basis: proven - prints 'LED AS3824 Current On: 0x%04X'
# Called from: ldc_cmd_set_led_current_on, LED_AS3824_Init
# Stores the value in AS3824Buf.CurrOnOff, writes it as a 16-bit value to AS3824 register 1 and prints
# "LED AS3824 Current On: 0x%04X". Command 0x38 passes 0xFFFF (on) or 0 (off); LED_AS3824_Init passes 0.
# Arguments: a2 value.
# Locals: a1+0 value.
# Returns: nothing.
# Calls: ldc_as3824_write_word, dbg_printf
# Text loaded: "LED AS3824 Current On: 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_set_current_on, @function
ldc_as3824_set_current_on:              # fn_400077fc
	entry	a1, 48                  # 400077fc
	s32i.n	a2, a1, 0               # 400077ff
	# AS3824Buf.CurrOnOff = value;
	l32r	a13, lit_3ffe20ac       # 40007801  = 0x3ffe54a0
	l32i.n	a12, a1, 0              # 40007804
	s32i.n	a12, a13, 8             # 40007806
	# ldc_as3824_write_word(1, AS3824Buf.CurrOnOff);
	movi.n	a10, 1                  # 40007808
	l32r	a11, lit_3ffe20ac       # 4000780a  = 0x3ffe54a0
	l32i.n	a11, a11, 8             # 4000780d
	call8	ldc_as3824_write_word   # 4000780f
	# printf("LED AS3824 Current On: 0x%04X\n", AS3824Buf.CurrOnOff);
	l32r	a10, lit_3ffe20c4       # 40007812  = ro_3ffe0c50 "LED AS3824 Current On: 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007815  = 0x3ffe54a0
	l32i.n	a11, a11, 8             # 40007818
	call8	dbg_printf              # 4000781a
	retw.n                          # 4000781d
	.size	ldc_as3824_set_current_on, . - ldc_as3824_set_current_on
