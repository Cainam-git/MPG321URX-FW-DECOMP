# ldc_as3824_set_hdr_bit0_and_init  (fn_400077d4): 0x400077d4-0x400077fb (firmware file offset 0x377d4-0x377fb), 14 instructions
# Name basis: descriptive - mechanics only
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Sets bit 0 of AS3824Buf.HdrMode, writes HdrMode to AS3824 register 103 (0x67), then runs LED_AS3824_Init
# (which sets HdrMode to 6 again). Not called anywhere and its address is not stored.
# Arguments: none. Locals: none. Returns: nothing.
# Calls: ldc_as3824_write_byte, LED_AS3824_Init
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_set_hdr_bit0_and_init, @function
ldc_as3824_set_hdr_bit0_and_init:       # fn_400077d4
	entry	a1, 32                  # 400077d4
	# AS3824Buf.HdrMode |= 1;
	l32r	a13, lit_3ffe20ac       # 400077d7  = 0x3ffe54a0
	movi.n	a14, 1                  # 400077da
	l32r	a12, lit_3ffe20ac       # 400077dc  = 0x3ffe54a0
	l32i	a12, a12, 164           # 400077df
	or	a12, a12, a14           # 400077e2
	s32i	a12, a13, 164           # 400077e5
	# ldc_as3824_write_byte(103, AS3824Buf.HdrMode & 0xFF);
	movi	a10, 103                # 400077e8
	l32r	a11, lit_3ffe20ac       # 400077eb  = 0x3ffe54a0
	l32i	a11, a11, 164           # 400077ee
	extui	a11, a11, 0, 8          # 400077f1
	call8	ldc_as3824_write_byte   # 400077f4
	# LED_AS3824_Init();
	call8	LED_AS3824_Init         # 400077f7
	retw.n                          # 400077fa
	.size	ldc_as3824_set_hdr_bit0_and_init, . - ldc_as3824_set_hdr_bit0_and_init
