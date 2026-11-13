# ldc_cmd_set_peaking  (fn_4000165c): 0x4000165c-0x400016a2 (firmware file offset 0x3165c-0x316a2), 28 instructions
# Name basis: proven - prints 'Current Stress Staus = %d (Peaking OFF/ON)'; table entry 0x82
# Address stored in the words at: 0x4000d3ec
# Calls: dbg_printf, ldc_post_brightness_status
# Text loaded: "Current Stress Staus = %d (Peaking OFF)\n", "Current Stress Staus = %d (Peaking ON)\n"
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0x3ffe2bf0
#
# Command 0x82 (sent by ldc_send_peaking). Value 0 switches peaking off: clears panel +0x150, sets cfg +60 to 1,
# sets LED_Mode (panel +0x140) to 3 and prints "Current Stress Staus = 0 (Peaking OFF)". Any other value sets
# LED_Mode to 6 and prints "Current Stress Staus = 1 (Peaking ON)". Both then post the brightness status at once.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_peaking, @function
ldc_cmd_set_peaking:                    # fn_4000165c
	entry	a1, 48                  # 4000165c
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 4000165f
	s32i.n	a3, a1, 4               # 40001661
	# if (value == 0)
	movi.n	a6, 0                   # 40001663
	l32i.n	a5, a1, 4               # 40001665
	bne	a5, a6, .L4000168c      # 40001667
	# panel[0x150] = 0
	l32r	a11, lit_3ffe1a80       # 4000166a  = 0x3ffe2bf0
	movi.n	a10, 0                  # 4000166d
	s32i	a10, a11, 0x150         # 4000166f
	# cfg[60] = 1
	l32r	a9, lit_3ffe1a98        # 40001672  = ldc_dimming_settings
	movi.n	a8, 1                   # 40001675
	s32i.n	a8, a9, 60              # 40001677
	# panel.led_mode = 3   (printed as LED_Mode)
	l32r	a7, lit_3ffe1a80        # 40001679  = 0x3ffe2bf0
	movi.n	a6, 3                   # 4000167c
	s32i	a6, a7, 0x140           # 4000167e
	# printf("Current Stress Staus = %d (Peaking OFF)\n", 0)
	l32r	a10, lit_3ffe1b2c       # 40001681  = ro_3ffe0128 "Current Stress Staus = %d (Peaking OFF)\n"
	movi.n	a11, 0                  # 40001684
	call8	dbg_printf              # 40001686
	j	.L4000169c              # 40001689
.L4000168c:
	# else { panel.led_mode = 6; printf("Current Stress Staus = %d (Peaking ON)\n", 1); }
	l32r	a13, lit_3ffe1a80       # 4000168c  = 0x3ffe2bf0
	movi.n	a12, 6                  # 4000168f
	s32i	a12, a13, 0x140         # 40001691
	l32r	a10, lit_3ffe1b30       # 40001694  = ro_3ffe0154 "Current Stress Staus = %d (Peaking ON)\n"
	movi.n	a11, 1                  # 40001697
	call8	dbg_printf              # 40001699
.L4000169c:
	# ldc_post_brightness_status(1)
	movi.n	a10, 1                  # 4000169c
	call8	ldc_post_brightness_status # 4000169e
	retw.n                          # 400016a1
	.size	ldc_cmd_set_peaking, . - ldc_cmd_set_peaking
