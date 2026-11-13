# ldc_cmd_set_direct_pwm  (fn_40001994): 0x40001994-0x400019c1 (firmware file offset 0x31994-0x319c1), 18 instructions
# Name basis: derived - type 1 -> ldc_as3824_apply_direct_pwm ('LED AS3824 Direct PWM', 'CURR CTRL',
#   'Options'); type 0 -> ldc_set_direct_pwm_type0
# Address stored in the words at: 0x4000d3a4
# Calls: ldc_as3824_apply_direct_pwm, ldc_set_direct_pwm_type0
# Other literal values: 0x3ffe2bf0
#
# Command 0x60 (sent by ldc_send_direct_pwm): with LED driver type 1 (panel +24) passes the low byte of the value
# to ldc_as3824_apply_direct_pwm, which for 1 writes "LED AS3824 Direct PWM" 1, "CURR CTRL" 6 and "Options" 0x60, and for
# other values Direct PWM 0, CURR CTRL 0x80 or 0x84 and Options 0. With driver type 0 passes it to
# ldc_set_direct_pwm_type0, which for 1 calls ldc_units_copy_words_and_start(2, {0x238007AA, 0x55}, 1) and sets 0x3FFE5594 to 1,
# and for other values clears 0x3FFE5594. Other driver types do nothing.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_direct_pwm, @function
ldc_cmd_set_direct_pwm:                 # fn_40001994
	entry	a1, 48                  # 40001994
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 40001997
	s32i.n	a3, a1, 4               # 40001999
	# if (panel.driver_type == 1) ldc_as3824_apply_direct_pwm((uint8_t)value)
	l32r	a5, lit_3ffe1a80        # 4000199b  = 0x3ffe2bf0
	l32i.n	a5, a5, 24              # 4000199e
	bnei	a5, 1, .L400019ae       # 400019a0
	l32i.n	a10, a1, 4              # 400019a3
	extui	a10, a10, 0, 8          # 400019a5
	call8	ldc_as3824_apply_direct_pwm # 400019a8
	j	.L400019c0              # 400019ab
.L400019ae:
	# else if (panel.driver_type == 0) ldc_set_direct_pwm_type0((uint8_t)value)
	movi.n	a12, 0                  # 400019ae
	l32r	a11, lit_3ffe1a80       # 400019b0  = 0x3ffe2bf0
	l32i.n	a11, a11, 24            # 400019b3
	bne	a11, a12, .L400019c0    # 400019b5
	l32i.n	a10, a1, 4              # 400019b8
	extui	a10, a10, 0, 8          # 400019ba
	call8	ldc_set_direct_pwm_type0 # 400019bd
.L400019c0:
	retw.n                          # 400019c0
	.size	ldc_cmd_set_direct_pwm, . - ldc_cmd_set_direct_pwm
