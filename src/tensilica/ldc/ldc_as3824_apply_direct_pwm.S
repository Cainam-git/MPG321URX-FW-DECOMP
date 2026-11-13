# ldc_as3824_apply_direct_pwm  (fn_40007958): 0x40007958-0x40007997 (firmware file offset 0x37958-0x37997), 24 instructions
# Name basis: derived - called by ldc_cmd_set_direct_pwm (command 0x60)
# Called from: ldc_cmd_set_direct_pwm
# Command 0x60's work (ldc_cmd_set_direct_pwm): on = 1 sets the direct-PWM bit, CurrCtrl 6 and Options 96;
# otherwise clears the bit, sets CurrCtrl 128 (LED_Mode below 4) or 132, and Options 0.
# Arguments: a2 on.
# Locals: a1+0 on.
# Returns: nothing.
# Calls: ldc_as3824_set_direct_pwm_bit, ldc_as3824_set_curr_ctrl, ldc_as3824_set_options
# Other literal values: 0x3ffe2d30

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_as3824_apply_direct_pwm, @function
ldc_as3824_apply_direct_pwm:            # fn_40007958
	entry	a1, 48                  # 40007958
	s32i.n	a2, a1, 0               # 4000795b
	# if (on == 1) {
	l32i.n	a4, a1, 0               # 4000795d
	bnei	a4, 1, .L40007975       # 4000795f
	#     ldc_as3824_set_direct_pwm_bit(1);
	movi.n	a10, 1                  # 40007962
	call8	ldc_as3824_set_direct_pwm_bit # 40007964
	#     ldc_as3824_set_curr_ctrl(6);
	movi.n	a10, 6                  # 40007967
	call8	ldc_as3824_set_curr_ctrl # 40007969
	#     ldc_as3824_set_options(96);
	movi	a10, 96                 # 4000796c
	call8	ldc_as3824_set_options  # 4000796f
	j	.L40007996              # 40007972
.L40007975:
	# } else {
	#     ldc_as3824_set_direct_pwm_bit(0);
	movi.n	a10, 0                  # 40007975
	call8	ldc_as3824_set_direct_pwm_bit # 40007977
	#     if (panel.LED_Mode < 4) ldc_as3824_set_curr_ctrl(128);
	l32r	a5, lit_3ffe20e0        # 4000797a  = 0x3ffe2d30
	l32i.n	a5, a5, 0               # 4000797d
	bgeui	a5, 4, .L4000798b       # 4000797f
	movi	a10, 128                # 40007982
	call8	ldc_as3824_set_curr_ctrl # 40007985
	j	.L40007991              # 40007988
.L4000798b:
	#     else ldc_as3824_set_curr_ctrl(132);
	movi	a10, 132                # 4000798b
	call8	ldc_as3824_set_curr_ctrl # 4000798e
.L40007991:
	#     ldc_as3824_set_options(0);
	movi.n	a10, 0                  # 40007991
	call8	ldc_as3824_set_options  # 40007993
.L40007996:
	# }
	retw.n                          # 40007996
	.size	ldc_as3824_apply_direct_pwm, . - ldc_as3824_apply_direct_pwm
