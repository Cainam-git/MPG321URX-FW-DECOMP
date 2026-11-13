# ldc_hw_apply_gain_filter_mode  (fn_4000679c): 0x4000679c-0x40006802 (firmware file offset 0x3679c-0x36802), 41 instructions
# Name basis: derived - all callers pass GainFilterMode (settings +4); MAP: command 0x97 written to
#   0xE0080388
# Called from: ldc_init_panel_defaults, ldc_cmd_set_ldc_mode, ldc_cmd_set_gain_filter_mode,
#              ldc_cmd_enable_input_duty_check, ldc_hw_init
# Copies bits 1 and 2 of the value into bits 1 and 2 of register 0xE0080388. The callers pass GainFilterMode
# (dimming settings +4): ldc_cmd_set_gain_filter_mode (command 0x5D), ldc_cmd_set_ldc_mode (command 0x20), ldc_init_panel_defaults, and ldc_cmd_enable_input_duty_check
# (command 0x97, in one branch with bit 2 cleared); ldc_hw_init passes 4.
# Arguments: a2 mode.
# Locals: a1+0 / a1+4 new register values, a1+16 mode.
# Returns: nothing.
# Other literal values: 0xe0080388

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_apply_gain_filter_mode, @function
ldc_hw_apply_gain_filter_mode:          # fn_4000679c
	entry	a1, 64                  # 4000679c
	s32i.n	a2, a1, 16              # 4000679f
	# if (mode & 2) v = reg[0x388] | 2;   /* reg[x] = 32-bit register at 0xE0080000 + x */
	l32i.n	a4, a1, 16              # 400067a1
	bbci	a4, 1, .L400067b8       # 400067a3
	movi.n	a6, 2                   # 400067a6
	l32r	a5, lit_3ffe1f00        # 400067a8  = 0xe0080388
	memw                            # 400067ab
	l32i.n	a5, a5, 0               # 400067ae
	or	a5, a5, a6              # 400067b0
	s32i.n	a5, a1, 0               # 400067b3
	j	.L400067c7              # 400067b5
.L400067b8:
	# else v = reg[0x388] & ~2;
	movi.n	a7, -3                  # 400067b8
	l32r	a6, lit_3ffe1f00        # 400067ba  = 0xe0080388
	memw                            # 400067bd
	l32i.n	a6, a6, 0               # 400067c0
	and	a6, a6, a7              # 400067c2
	s32i.n	a6, a1, 0               # 400067c5
.L400067c7:
	# reg[0x388] = v;
	l32r	a9, lit_3ffe1f00        # 400067c7  = 0xe0080388
	memw                            # 400067ca
	l32i.n	a8, a1, 0               # 400067cd
	s32i.n	a8, a9, 0               # 400067cf
	# if (mode & 4) v2 = reg[0x388] | 4;
	l32i.n	a7, a1, 16              # 400067d1
	bbci	a7, 2, .L400067e8       # 400067d3
	movi.n	a11, 4                  # 400067d6
	l32r	a10, lit_3ffe1f00       # 400067d8  = 0xe0080388
	memw                            # 400067db
	l32i.n	a10, a10, 0             # 400067de
	or	a10, a10, a11           # 400067e0
	s32i.n	a10, a1, 4              # 400067e3
	j	.L400067f7              # 400067e5
.L400067e8:
	# else v2 = reg[0x388] & ~4;
	movi.n	a12, -5                 # 400067e8
	l32r	a11, lit_3ffe1f00       # 400067ea  = 0xe0080388
	memw                            # 400067ed
	l32i.n	a11, a11, 0             # 400067f0
	and	a11, a11, a12           # 400067f2
	s32i.n	a11, a1, 4              # 400067f5
.L400067f7:
	# reg[0x388] = v2;
	l32r	a13, lit_3ffe1f00       # 400067f7  = 0xe0080388
	memw                            # 400067fa
	l32i.n	a12, a1, 4              # 400067fd
	s32i.n	a12, a13, 0             # 400067ff
	retw.n                          # 40006801
	.size	ldc_hw_apply_gain_filter_mode, . - ldc_hw_apply_gain_filter_mode
