# ldc_as3824_send_dev1_reg_bit7  (fn_40007530): 0x40007530-0x40007569 (firmware file offset 0x37530-0x37569), 23 instructions
# Name basis: descriptive - mechanics only
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Sends a 2-word frame through unit 0 whose bytes are 0x41, (reg | 0x80), then zeros; then waits 2 ticks.
# What the frame asks of the device is not shown. Not called anywhere and its address is not stored.
# Arguments: a2 reg (u8).
# Locals: a1+0 frame[2], a1+16 reg.
# Returns: nothing.
# Calls: ldc_units_copy_words_and_start, timer_wait_ticks
# Addresses loaded: ro_3ffe0bf0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_send_dev1_reg_bit7, @function
ldc_as3824_send_dev1_reg_bit7:          # fn_40007530
	entry	a1, 64                  # 40007530
	extui	a2, a2, 0, 8            # 40007533
	s8i	a2, a1, 16              # 40007536
	# u32 frame[2] = { 0, 0 };   (copied from ro_3ffe0bf0)
	l32r	a5, lit_3ffe20a8        # 40007539  = ro_3ffe0bf0
	l32i.n	a6, a5, 4               # 4000753c
	s32i.n	a6, a1, 4               # 4000753e
	l32i.n	a5, a5, 0               # 40007540
	s32i.n	a5, a1, 0               # 40007542
	# frame[0] = (((reg | 0x80) & 0xFF) << 8) + 0x41;
	mov.n	a5, a1                  # 40007544
	movi	a6, 128                 # 40007546
	l8ui	a4, a1, 16              # 40007549
	or	a4, a4, a6              # 4000754c
	extui	a4, a4, 0, 8            # 4000754f
	slli	a4, a4, 8               # 40007552
	addi	a4, a4, 65              # 40007555
	s32i.n	a4, a5, 0               # 40007558
	# ldc_units_copy_words_and_start(2, frame, 1);
	movi.n	a10, 2                  # 4000755a
	mov.n	a11, a1                 # 4000755c
	movi.n	a12, 1                  # 4000755e
	call8	ldc_units_copy_words_and_start # 40007560
	# wait_ticks(2);
	movi.n	a10, 2                  # 40007563
	call8	timer_wait_ticks        # 40007565
	retw.n                          # 40007568
	.size	ldc_as3824_send_dev1_reg_bit7, . - ldc_as3824_send_dev1_reg_bit7
