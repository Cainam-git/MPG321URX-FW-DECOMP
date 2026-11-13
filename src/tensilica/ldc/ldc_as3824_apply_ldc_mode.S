# ldc_as3824_apply_ldc_mode  (fn_4000770c): 0x4000770c-0x4000775c (firmware file offset 0x3770c-0x3775c), 29 instructions
# Name basis: derived - prints 'AS3824Buf.HdrMode'; called with LDC_Mode on change
# Called from: ldc_as3824_update
# Sets bit 4 of AS3824Buf.HdrMode when the LDC mode is 1 or 2 and clears it otherwise, writes HdrMode to AS3824
# register 103 (0x67) and prints "AS3824Buf.HdrMode = 0x%02X". Called by ldc_as3824_update when LDC_Mode changes.
# Arguments: a2 ldc_mode (panel LDC_Mode, 0x3FFE2D34).
# Locals: a1+0 ldc_mode.
# Returns: nothing.
# Note: AS3824Buf is the record at 0x3ffe54a0 (field names from ldc_as3824_print_state's texts).
# Calls: ldc_as3824_write_byte, dbg_printf
# Text loaded: "AS3824Buf.HdrMode = 0x%02X \n"
# Other literal values: 0x3ffe54a0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_apply_ldc_mode, @function
ldc_as3824_apply_ldc_mode:              # fn_4000770c
	entry	a1, 48                  # 4000770c
	s32i.n	a2, a1, 0               # 4000770f
	# if (ldc_mode == 1 || ldc_mode == 2)
	l32i.n	a4, a1, 0               # 40007711
	beqi	a4, 1, .L4000771b       # 40007713
	l32i.n	a5, a1, 0               # 40007716
	bnei	a5, 2, .L4000772f       # 40007718
.L4000771b:
	#     AS3824Buf.HdrMode |= 0x10;
	l32r	a7, lit_3ffe20ac        # 4000771b  = 0x3ffe54a0
	movi.n	a8, 16                  # 4000771e
	l32r	a6, lit_3ffe20ac        # 40007720  = 0x3ffe54a0
	l32i	a6, a6, 164             # 40007723
	or	a6, a6, a8              # 40007726
	s32i	a6, a7, 164             # 40007729
	j	.L40007740              # 4000772c
.L4000772f:
	# else AS3824Buf.HdrMode &= ~0x10;
	l32r	a8, lit_3ffe20ac        # 4000772f  = 0x3ffe54a0
	movi.n	a9, -17                 # 40007732
	l32r	a7, lit_3ffe20ac        # 40007734  = 0x3ffe54a0
	l32i	a7, a7, 164             # 40007737
	and	a7, a7, a9              # 4000773a
	s32i	a7, a8, 164             # 4000773d
.L40007740:
	# ldc_as3824_write_byte(103, AS3824Buf.HdrMode & 0xFF);
	movi	a10, 103                # 40007740
	l32r	a11, lit_3ffe20ac       # 40007743  = 0x3ffe54a0
	l32i	a11, a11, 164           # 40007746
	extui	a11, a11, 0, 8          # 40007749
	call8	ldc_as3824_write_byte   # 4000774c
	# printf("AS3824Buf.HdrMode = 0x%02X \n", AS3824Buf.HdrMode);
	l32r	a10, lit_3ffe20b0       # 4000774f  = ro_3ffe0bf8 "AS3824Buf.HdrMode = 0x%02X \n"
	l32r	a11, lit_3ffe20ac       # 40007752  = 0x3ffe54a0
	l32i	a11, a11, 164           # 40007755
	call8	dbg_printf              # 40007758
	retw.n                          # 4000775b
	.size	ldc_as3824_apply_ldc_mode, . - ldc_as3824_apply_ldc_mode
