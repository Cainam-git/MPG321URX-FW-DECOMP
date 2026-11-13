# ldc_hw_set_reg290_high_half  (fn_4000686c): 0x4000686c-0x40006883 (firmware file offset 0x3686c-0x36883), 9 instructions
# Name basis: descriptive - command 0x44 handler; mechanics only
# Called from: ldc_cmd_set_reg290_high
# Writes the low 16 bits of the value to bits 16..31 of register 0xE0080290. Called by the command 0x44
# handler ldc_cmd_set_reg290_high.
# Arguments: a2 value.
# Locals: a1+0 value.
# Returns: nothing.
# Calls: reg_write32_masked
# Other literal values: 0xe0080290, 0xffff0000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_set_reg290_high_half, @function
ldc_hw_set_reg290_high_half:            # fn_4000686c
	entry	a1, 48                  # 4000686c
	s32i.n	a2, a1, 0               # 4000686f
	# reg_write32_masked(0xE0080290, (value & 0xFFFF) << 16, 0xFFFF0000);
	l32r	a10, lit_3ffe1f0c       # 40006871  = 0xe0080290
	l32i.n	a11, a1, 0              # 40006874
	extui	a11, a11, 0, 16         # 40006876
	slli	a11, a11, 16            # 40006879
	l32r	a12, lit_3ffe1eec       # 4000687c  = 0xffff0000
	call8	reg_write32_masked      # 4000687f
	retw.n                          # 40006882
	.size	ldc_hw_set_reg290_high_half, . - ldc_hw_set_reg290_high_half
