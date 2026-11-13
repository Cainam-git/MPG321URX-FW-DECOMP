# ldc_as3824_set_hdr_mode  (fn_40007820): 0x40007820-0x40007849 (firmware file offset 0x37820-0x37849), 15 instructions
# Name basis: proven - prints 'LED AS3824 HDR Mode: 0x%04X'
# Called from: LED_AS3824_Init
# Stores the value in AS3824Buf.HdrMode, writes its low byte to AS3824 register 103 (0x67) and prints
# "LED AS3824 HDR Mode: 0x%04X".
# Arguments: a2 value.
# Locals: a1+0 value.
# Returns: nothing.
# Calls: ldc_as3824_write_byte, dbg_printf
# Text loaded: "LED AS3824 HDR Mode: 0x%04X\n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_set_hdr_mode, @function
ldc_as3824_set_hdr_mode:                # fn_40007820
	entry	a1, 48                  # 40007820
	s32i.n	a2, a1, 0               # 40007823
	# AS3824Buf.HdrMode = value;
	l32r	a13, lit_3ffe20ac       # 40007825  = 0x3ffe54a0
	l32i.n	a12, a1, 0              # 40007828
	s32i	a12, a13, 164           # 4000782a
	# ldc_as3824_write_byte(103, AS3824Buf.HdrMode & 0xFF);
	movi	a10, 103                # 4000782d
	l32r	a11, lit_3ffe20ac       # 40007830  = 0x3ffe54a0
	l32i	a11, a11, 164           # 40007833
	extui	a11, a11, 0, 8          # 40007836
	call8	ldc_as3824_write_byte   # 40007839
	# printf("LED AS3824 HDR Mode: 0x%04X\n", AS3824Buf.HdrMode);
	l32r	a10, lit_3ffe20c8       # 4000783c  = ro_3ffe0c70 "LED AS3824 HDR Mode: 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 4000783f  = 0x3ffe54a0
	l32i	a11, a11, 164           # 40007842
	call8	dbg_printf              # 40007845
	retw.n                          # 40007848
	.size	ldc_as3824_set_hdr_mode, . - ldc_as3824_set_hdr_mode
