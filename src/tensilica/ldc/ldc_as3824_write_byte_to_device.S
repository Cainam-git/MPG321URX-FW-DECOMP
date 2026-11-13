# ldc_as3824_write_byte_to_device  (fn_400074ec): 0x400074ec-0x4000752f (firmware file offset 0x374ec-0x3752f), 25 instructions
# Name basis: descriptive - same frame as ldc_as3824_write_byte with a device number; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Sends a 3-byte frame through unit 0: header (device | 0x40), register, value; then waits 2 ticks.
# Not called anywhere and its address is not stored.
# Arguments: a2 device (u8), a3 reg (u8), a4 value (u8).
# Locals: a1+0 frame[1], a1+16 device, a1+20 reg, a1+24 value.
# Returns: nothing.
# Calls: ldc_units_copy_words_and_start, timer_wait_ticks

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_write_byte_to_device, @function
ldc_as3824_write_byte_to_device:        # fn_400074ec
	entry	a1, 64                  # 400074ec
	extui	a7, a2, 0, 8            # 400074ef
	s8i	a7, a1, 16              # 400074f2
	extui	a5, a3, 0, 8            # 400074f5
	s8i	a5, a1, 20              # 400074f8
	extui	a2, a4, 0, 8            # 400074fb
	s8i	a2, a1, 24              # 400074fe
	# frame[0] = ((device | 0x40) & 0xFF) | (reg << 8) | (value << 16);
	l8ui	a10, a1, 24             # 40007501
	slli	a10, a10, 16            # 40007504
	l8ui	a11, a1, 20             # 40007507
	slli	a11, a11, 8             # 4000750a
	movi.n	a12, 64                 # 4000750d
	l8ui	a9, a1, 16              # 4000750f
	or	a9, a9, a12             # 40007512
	extui	a9, a9, 0, 8            # 40007515
	or	a9, a9, a11             # 40007518
	or	a9, a9, a10             # 4000751b
	s32i.n	a9, a1, 0               # 4000751e
	# ldc_units_copy_words_and_start(1, frame, 1);
	movi.n	a10, 1                  # 40007520
	mov.n	a11, a1                 # 40007522
	movi.n	a12, 1                  # 40007524
	call8	ldc_units_copy_words_and_start # 40007526
	# wait_ticks(2);
	movi.n	a10, 2                  # 40007529
	call8	timer_wait_ticks        # 4000752b
	retw.n                          # 4000752e
	.size	ldc_as3824_write_byte_to_device, . - ldc_as3824_write_byte_to_device
