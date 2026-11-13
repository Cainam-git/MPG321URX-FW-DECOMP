# ldc_as3824_write_word  (fn_4000756c): 0x4000756c-0x400075ab (firmware file offset 0x3756c-0x375ab), 26 instructions
# Name basis: derived - used for PWM_Period (reg 20) and CurrOnOff (reg 1) with their prints
# Called from: LED_AS3824_SetPwmPeriod, ldc_as3824_set_current_on
# Sends a 5-byte frame through unit 0: header 0x80 (no device number), 0x02, register, low byte, high byte of
# the value; then waits 2 ticks. Used for PWM_Period (register 20) and CurrOnOff (register 1).
# Arguments: a2 reg (u8), a3 value (16 bits used).
# Locals: a1+0 frame[2], a1+16 reg, a1+20 value.
# Returns: nothing.
# Calls: ldc_units_copy_words_and_start, timer_wait_ticks

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_write_word, @function
ldc_as3824_write_word:                  # fn_4000756c
	entry	a1, 64                  # 4000756c
	extui	a4, a2, 0, 8            # 4000756f
	s8i	a4, a1, 16              # 40007572
	s32i.n	a3, a1, 20              # 40007575
	# frame[0] = 0x280 + (reg << 16) + ((value & 0xFF) << 24);
	mov.n	a8, a1                  # 40007577
	movi	a9, 0x280               # 40007579
	l32i.n	a10, a1, 20             # 4000757c
	extui	a10, a10, 0, 8          # 4000757e
	slli	a10, a10, 24            # 40007581
	l8ui	a7, a1, 16              # 40007584
	slli	a7, a7, 16              # 40007587
	add.n	a7, a7, a10             # 4000758a
	add.n	a7, a7, a9              # 4000758c
	s32i.n	a7, a8, 0               # 4000758e
	# frame[1] = (value >> 8) & 0xFF;
	addi.n	a7, a1, 4               # 40007590
	l32i.n	a6, a1, 20              # 40007592
	srli	a6, a6, 8               # 40007594
	extui	a6, a6, 0, 8            # 40007597
	s32i.n	a6, a7, 0               # 4000759a
	# ldc_units_copy_words_and_start(2, frame, 1);
	movi.n	a10, 2                  # 4000759c
	mov.n	a11, a1                 # 4000759e
	movi.n	a12, 1                  # 400075a0
	call8	ldc_units_copy_words_and_start # 400075a2
	# wait_ticks(2);
	movi.n	a10, 2                  # 400075a5
	call8	timer_wait_ticks        # 400075a7
	retw.n                          # 400075aa
	.size	ldc_as3824_write_word, . - ldc_as3824_write_word
