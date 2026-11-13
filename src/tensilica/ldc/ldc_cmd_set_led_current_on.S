# ldc_cmd_set_led_current_on  (fn_40001a08): 0x40001a08-0x40001a4b (firmware file offset 0x31a08-0x31a4b), 26 instructions
# Name basis: derived - calls ldc_as3824_set_current_on 'LED AS3824 Current On: 0x%04X'; driver type 1 only
# Address stored in the words at: 0x4000d2bc
# Calls: timer_wait_ticks, ldc_as3824_set_current_on
# Addresses loaded: ldc_first_current_on
# Other literal values: 0x3ffe2bf0, 0x00001388, 0x0000ffff
#
# Command 0x38 (sent by ldc_send_led_current_on): only with LED driver type 1 (panel +24). Bit 0 of the value set:
# calls timer_wait_ticks(5000) the first time (flag ldc_first_current_on, 1 at start, then cleared) and timer_wait_ticks(2000)
# on later calls, then ldc_as3824_set_current_on(0xFFFF), which sends the value with ldc_as3824_write_word(1, value) and prints
# "LED AS3824 Current On: 0x%04X". Bit 0 clear: ldc_as3824_set_current_on(0).
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15), bit 0 = on
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_led_current_on, @function
ldc_cmd_set_led_current_on:             # fn_40001a08
	entry	a1, 48                  # 40001a08
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 40001a0b
	s32i.n	a3, a1, 4               # 40001a0d
	# if (panel.driver_type == 1)
	l32r	a5, lit_3ffe1a80        # 40001a0f  = 0x3ffe2bf0
	l32i.n	a5, a5, 24              # 40001a12
	bnei	a5, 1, .L40001a4a       # 40001a14
	# if (value & 1)
	l32i.n	a6, a1, 4               # 40001a17
	extui	a6, a6, 0, 1            # 40001a19
	beqz.n	a6, .L40001a45          # 40001a1c
	# if (first_current_on == 1) { timer_wait_ticks(5000); first_current_on = 0; }   (ldc_first_current_on)
	l32r	a7, lit_3ffe1b68        # 40001a1e  = ldc_first_current_on
	l32i.n	a7, a7, 0               # 40001a21
	bnei	a7, 1, .L40001a36       # 40001a23
	l32r	a10, lit_3ffe1b6c       # 40001a26  = 0x00001388
	call8	timer_wait_ticks        # 40001a29
	l32r	a9, lit_3ffe1b68        # 40001a2c  = ldc_first_current_on
	movi.n	a8, 0                   # 40001a2f
	s32i.n	a8, a9, 0               # 40001a31
	j	.L40001a3c              # 40001a33
.L40001a36:
	# else timer_wait_ticks(2000)
	movi	a10, 0x7d0              # 40001a36
	call8	timer_wait_ticks        # 40001a39
.L40001a3c:
	# ldc_as3824_set_current_on(0xFFFF)   ("LED AS3824 Current On")
	l32r	a10, lit_3ffe1b70       # 40001a3c  = 0x0000ffff
	call8	ldc_as3824_set_current_on # 40001a3f
	j	.L40001a4a              # 40001a42
.L40001a45:
	# else ldc_as3824_set_current_on(0)
	movi.n	a10, 0                  # 40001a45
	call8	ldc_as3824_set_current_on # 40001a47
.L40001a4a:
	retw.n                          # 40001a4a
	.size	ldc_cmd_set_led_current_on, . - ldc_cmd_set_led_current_on
