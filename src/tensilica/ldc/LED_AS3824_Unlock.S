# LED_AS3824_Unlock  (fn_40007998): 0x40007998-0x400079b7 (firmware file offset 0x37998-0x379b7), 12 instructions
# Name basis: proven - original name, printed in 'LED_AS3824_Unlock'
# Called from: LED_AS3824_Init
# Stores 0xCA in AS3824Buf.LockUnlock, writes it to AS3824 register 54 (0x36) and prints "LED_AS3824_Unlock".
# The name is the text the routine prints.
# Arguments: none. Locals: none. Returns: nothing.
# Calls: ldc_as3824_write_byte, dbg_printf
# Text loaded: "LED_AS3824_Unlock\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	LED_AS3824_Unlock, @function
LED_AS3824_Unlock:                      # fn_40007998
	entry	a1, 32                  # 40007998
	# AS3824Buf.LockUnlock = 0xCA;
	l32r	a13, lit_3ffe20ac       # 4000799b  = 0x3ffe54a0
	movi	a12, 202                # 4000799e
	s32i.n	a12, a13, 4             # 400079a1
	# ldc_as3824_write_byte(54, AS3824Buf.LockUnlock & 0xFF);
	movi.n	a10, 54                 # 400079a3
	l32r	a11, lit_3ffe20ac       # 400079a5  = 0x3ffe54a0
	l32i.n	a11, a11, 4             # 400079a8
	extui	a11, a11, 0, 8          # 400079aa
	call8	ldc_as3824_write_byte   # 400079ad
	# printf("LED_AS3824_Unlock\n");
	l32r	a10, lit_3ffe20e4       # 400079b0  = ro_3ffe0d34 "LED_AS3824_Unlock\n"
	call8	dbg_printf              # 400079b3
	retw.n                          # 400079b6
	.size	LED_AS3824_Unlock, . - LED_AS3824_Unlock
