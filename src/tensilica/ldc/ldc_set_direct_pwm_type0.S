# ldc_set_direct_pwm_type0  (fn_400082cc): 0x400082cc-0x400082fe (firmware file offset 0x382cc-0x382fe), 22 instructions
# Name basis: derived - called by ldc_cmd_set_direct_pwm for driver type 0; flag stops
#   ldc_led_driver_type0_update
# Called from: ldc_cmd_set_direct_pwm
# Direct PWM switch for LED driver type 0 (called by ldc_cmd_set_direct_pwm, command 0x60). For on = 1 sends
# the 2-word frame {0x238007AA, 0x55} through unit 0 and sets ldc_direct_pwm_on (0x3FFE5594) to 1, which stops
# ldc_led_driver_type0_update; for any other value clears ldc_direct_pwm_on.
# a2 = on (low byte of the command value).
# Locals: a1+48 on, a1+0..a1+4 buf[2].
# Returns: nothing.
# Calls: ldc_units_copy_words_and_start
# Other literal values: 0x238007aa, 0x3ffe5594

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_set_direct_pwm_type0, @function
ldc_set_direct_pwm_type0:               # fn_400082cc
	entry	a1, 96                  # 400082cc
	# if (on == 1)
	s32i.n	a2, a1, 48              # 400082cf
	l32i.n	a4, a1, 48              # 400082d1
	bnei	a4, 1, .L400082f6       # 400082d3
	# buf[0] = 0x238007AA; buf[1] = 0x55;
	mov.n	a8, a1                  # 400082d6
	l32r	a7, lit_3ffe21c0        # 400082d8  = 0x238007aa
	s32i.n	a7, a8, 0               # 400082db
	addi.n	a6, a1, 4               # 400082dd
	movi.n	a5, 85                  # 400082df
	s32i.n	a5, a6, 0               # 400082e1
	movi.n	a10, 2                  # 400082e3
	# ldc_units_copy_words_and_start(2, buf, 1);
	mov.n	a11, a1                 # 400082e5
	movi.n	a12, 1                  # 400082e7
	call8	ldc_units_copy_words_and_start # 400082e9
	l32r	a10, lit_3ffe2158       # 400082ec  = 0x3ffe5594
	# ldc_direct_pwm_on = 1;
	movi.n	a9, 1                   # 400082ef
	s32i.n	a9, a10, 0              # 400082f1
	j	.L400082fd              # 400082f3
.L400082f6:
	l32r	a12, lit_3ffe2158       # 400082f6  = 0x3ffe5594
	# else ldc_direct_pwm_on = 0;
	movi.n	a11, 0                  # 400082f9
	s32i.n	a11, a12, 0             # 400082fb
.L400082fd:
	retw.n                          # 400082fd
	.size	ldc_set_direct_pwm_type0, . - ldc_set_direct_pwm_type0
