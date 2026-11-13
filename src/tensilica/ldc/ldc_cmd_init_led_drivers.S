# ldc_cmd_init_led_drivers  (fn_400013a0): 0x400013a0-0x400013b3 (firmware file offset 0x313a0-0x313b3), 8 instructions
# Name basis: derived - command table; docs/MAP.md: only set-up of the LED driver chips
# Address stored in the words at: 0x4000d2a4
# Calls: ldc_units_init, LED_AS3824_Init
#
# Command 0x22 (its sender ldc_send_init_led_drivers on the main processor has no caller). With value 1 runs
# ldc_units_init and LED_AS3824_Init (which prints "LED_AS3824_Init Done!!"). Other values do nothing.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_init_led_drivers, @function
ldc_cmd_init_led_drivers:               # fn_400013a0
	entry	a1, 48                  # 400013a0
	s32i.n	a2, a1, 0               # 400013a3
	s32i.n	a3, a1, 4               # 400013a5
	# if (value == 1) { ldc_units_init(); LED_AS3824_Init(); }
	l32i.n	a5, a1, 4               # 400013a7
	bnei	a5, 1, .L400013b2       # 400013a9
	call8	ldc_units_init          # 400013ac
	call8	LED_AS3824_Init         # 400013af
.L400013b2:
	retw.n                          # 400013b2
	.size	ldc_cmd_init_led_drivers, . - ldc_cmd_init_led_drivers
