# ldc_as3824_write_byte  (fn_400074b4): 0x400074b4-0x400074e9 (firmware file offset 0x374b4-0x374e9), 20 instructions
# Name basis: derived - callers are the AS3824 register setters that print the register name
# Called from: ldc_cmd_write_as3824_register, ldc_as3824_apply_ldc_mode, ldc_as3824_set_hdr_bit0_and_init,
#              ldc_as3824_set_hdr_mode, ldc_as3824_set_pwm_ctrl, ldc_as3824_set_curr_ctrl,
#              ldc_as3824_set_dacref_bit, ldc_as3824_set_options, ldc_as3824_set_direct_pwm_bit,
#              LED_AS3824_Unlock, LED_AS3824_Init
# Sends a 3-byte frame through unit 0: header 0xC0 (no device number), register, value; then waits 2 ticks.
# Used for every AS3824 byte register the program sets (AS3824Buf setters, LED_AS3824_Init, command 0x61).
# Arguments: a2 reg (u8), a3 value (u8).
# Locals: a1+0 frame[1], a1+16 reg, a1+20 value.
# Returns: nothing.
# Calls: ldc_units_copy_words_and_start, timer_wait_ticks

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_write_byte, @function
ldc_as3824_write_byte:                  # fn_400074b4
	entry	a1, 64                  # 400074b4
	# (u8 arguments stored)
	extui	a4, a2, 0, 8            # 400074b7
	s8i	a4, a1, 16              # 400074ba
	extui	a2, a3, 0, 8            # 400074bd
	s8i	a2, a1, 20              # 400074c0
	# frame[0] = 0xC0 | (reg << 8) | (value << 16);
	movi	a7, 192                 # 400074c3
	l8ui	a8, a1, 20              # 400074c6
	slli	a8, a8, 16              # 400074c9
	l8ui	a6, a1, 16              # 400074cc
	slli	a6, a6, 8               # 400074cf
	or	a6, a6, a8              # 400074d2
	or	a6, a6, a7              # 400074d5
	s32i.n	a6, a1, 0               # 400074d8
	# ldc_units_copy_words_and_start(1, frame, 1);
	movi.n	a10, 1                  # 400074da
	mov.n	a11, a1                 # 400074dc
	movi.n	a12, 1                  # 400074de
	call8	ldc_units_copy_words_and_start # 400074e0
	# wait_ticks(2);
	movi.n	a10, 2                  # 400074e3
	call8	timer_wait_ticks        # 400074e5
	retw.n                          # 400074e8
	.size	ldc_as3824_write_byte, . - ldc_as3824_write_byte
