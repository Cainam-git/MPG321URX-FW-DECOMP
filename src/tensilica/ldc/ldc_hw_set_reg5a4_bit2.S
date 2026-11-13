# ldc_hw_set_reg5a4_bit2  (fn_40006764): 0x40006764-0x4000679a (firmware file offset 0x36764-0x3679a), 22 instructions
# Name basis: descriptive - command 0x83 handler; mechanics only
# Called from: ldc_cmd_set_reg5a4_bit2
# Sets bit 2 of register 0xE00805A4 when the value is 1 and clears it otherwise. Called by the command 0x83
# handler ldc_cmd_set_reg5a4_bit2.
# Arguments: a2 on.
# Locals: a1+0 v (new register value), a1+16 on.
# Returns: nothing.
# Other literal values: 0xe00805a4

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_set_reg5a4_bit2, @function
ldc_hw_set_reg5a4_bit2:                 # fn_40006764
	entry	a1, 64                  # 40006764
	s32i.n	a2, a1, 16              # 40006767
	# if (on == 1) v = reg[0x5A4] | 4;   /* reg[x] = 32-bit register at 0xE0080000 + x */
	l32i.n	a4, a1, 16              # 40006769
	bnei	a4, 1, .L40006780       # 4000676b
	movi.n	a6, 4                   # 4000676e
	l32r	a5, lit_3ffe1efc        # 40006770  = 0xe00805a4
	memw                            # 40006773
	l32i.n	a5, a5, 0               # 40006776
	or	a5, a5, a6              # 40006778
	s32i.n	a5, a1, 0               # 4000677b
	j	.L4000678f              # 4000677d
.L40006780:
	# else v = reg[0x5A4] & ~4;
	movi.n	a7, -5                  # 40006780
	l32r	a6, lit_3ffe1efc        # 40006782  = 0xe00805a4
	memw                            # 40006785
	l32i.n	a6, a6, 0               # 40006788
	and	a6, a6, a7              # 4000678a
	s32i.n	a6, a1, 0               # 4000678d
.L4000678f:
	# reg[0x5A4] = v;
	l32r	a8, lit_3ffe1efc        # 4000678f  = 0xe00805a4
	memw                            # 40006792
	l32i.n	a7, a1, 0               # 40006795
	s32i.n	a7, a8, 0               # 40006797
	retw.n                          # 40006799
	.size	ldc_hw_set_reg5a4_bit2, . - ldc_hw_set_reg5a4_bit2
