# timer_toggle_expstate_bit19  (fn_40005d68): 0x40005d68-0x40005dd7 (firmware file offset 0x35d68-0x35dd7), 46 instructions
# Name basis: descriptive - code only; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Same as timer_toggle_expstate_bit9 for EXPSTATE bit 19 with its own flags (data_3ffe275c, 0x3ffe4434): on the first call
# copies bit 19 into the state, then clears bit 19 when the state is 1, sets it when 0, and inverts the state.
# Nothing calls it and no stored word holds its address.
# Arguments: none.
# Locals: a1+0 / a1+4 / a1+8 / a1+12 copies of the saved PS, a1+16 PS returned by rsil.
# Returns: nothing.
# Addresses loaded: data_3ffe275c
# Other literal values: 0x3ffe4434
# Special registers: ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	timer_toggle_expstate_bit19, @function
timer_toggle_expstate_bit19:            # fn_40005d68
	entry	a1, 64                  # 40005d68
	# ps = rsil(15);   /* interrupts off, old PS kept */
	rsil	a2, 15                  # 40005d6b
	s32i.n	a2, a1, 16              # 40005d6e
	l32i.n	a4, a1, 16              # 40005d70
	s32i.n	a4, a1, 0               # 40005d72
	l32i.n	a3, a1, 0               # 40005d74
	s32i.n	a3, a1, 4               # 40005d76
	l32i.n	a6, a1, 4               # 40005d78
	s32i.n	a6, a1, 8               # 40005d7a
	# if (first_call != 0) { first_call = 0;
	movi.n	a6, 0                   # 40005d7c
	l32r	a5, lit_3ffe1e34        # 40005d7e  = data_3ffe275c
	l32i.n	a5, a5, 0               # 40005d81
	beq	a5, a6, .L40005da4      # 40005d83
	l32r	a9, lit_3ffe1e34        # 40005d86  = data_3ffe275c
	movi.n	a8, 0                   # 40005d89
	s32i.n	a8, a9, 0               # 40005d8b
	# state = (EXPSTATE >> 19) & 1; }
	rur.expstate	a7              # 40005d8d
	bbci	a7, 19, .L40005d9d      # 40005d90
	l32r	a11, lit_3ffe1e38       # 40005d93  = 0x3ffe4434
	movi.n	a10, 1                  # 40005d96
	s32i.n	a10, a11, 0             # 40005d98
	j	.L40005da4              # 40005d9a
.L40005d9d:
	l32r	a13, lit_3ffe1e38       # 40005d9d  = 0x3ffe4434
	movi.n	a12, 0                  # 40005da0
	s32i.n	a12, a13, 0             # 40005da2
.L40005da4:
	# if (state != 0) EXPSTATE &= ~(1 << 19);
	movi.n	a15, 0                  # 40005da4
	l32r	a14, lit_3ffe1e38       # 40005da6  = 0x3ffe4434
	l32i.n	a14, a14, 0             # 40005da9
	beq	a14, a15, .L40005db4    # 40005dab
	clrb_expstate	19              # 40005dae
	j	.L40005db7              # 40005db1
.L40005db4:
	# else EXPSTATE |= 1 << 19;
	setb_expstate	19              # 40005db4
.L40005db7:
	# state = (state == 0);
	l32r	a2, lit_3ffe1e38        # 40005db7  = 0x3ffe4434
	movi.n	a5, 0                   # 40005dba
	l32r	a4, lit_3ffe1e38        # 40005dbc  = 0x3ffe4434
	l32i.n	a4, a4, 0               # 40005dbf
	movi.n	a3, 1                   # 40005dc1
	movi.n	a15, 0                  # 40005dc3
	moveqz	a15, a3, a4             # 40005dc5
	s32i.n	a15, a2, 0              # 40005dc8
	# PS = ps;
	l32i.n	a7, a1, 8               # 40005dca
	s32i.n	a7, a1, 12              # 40005dcc
	l32i.n	a6, a1, 12              # 40005dce
	wsr.ps	a6                      # 40005dd0
	rsync                           # 40005dd3
	retw.n                          # 40005dd6
	.size	timer_toggle_expstate_bit19, . - timer_toggle_expstate_bit19
