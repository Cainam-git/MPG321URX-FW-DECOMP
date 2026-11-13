# ldc_hw_set_reg280_low_bytes  (fn_40006410): 0x40006410-0x40006431 (firmware file offset 0x36410-0x36431), 13 instructions
# Name basis: descriptive - called by the command 0x85 handler; mechanics only
# Called from: ldc_cmd_set_reg280_bytes
# Writes the second argument to bits 0..7 and the first to bits 8..15 of register 0xE0080280. Called by the
# command 0x85 handler ldc_cmd_set_reg280_bytes.
# Arguments: a2 high_byte, a3 low_byte.
# Locals: a1+0 high_byte, a1+4 low_byte.
# Returns: nothing.
# Calls: reg_write32_masked
# Other literal values: 0xe0080280, 0x0000ff00

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_set_reg280_low_bytes, @function
ldc_hw_set_reg280_low_bytes:            # fn_40006410
	entry	a1, 48                  # 40006410
	s32i.n	a2, a1, 0               # 40006413
	s32i.n	a3, a1, 4               # 40006415
	# reg_write32_masked(0xE0080280, low_byte, 0xFF);
	l32r	a10, lit_3ffe1eac       # 40006417  = 0xe0080280
	l32i.n	a11, a1, 4              # 4000641a
	movi	a12, 255                # 4000641c
	call8	reg_write32_masked      # 4000641f
	# reg_write32_masked(0xE0080280, high_byte << 8, 0xFF00);
	l32r	a10, lit_3ffe1eac       # 40006422  = 0xe0080280
	l32i.n	a11, a1, 0              # 40006425
	slli	a11, a11, 8             # 40006427
	l32r	a12, lit_3ffe1d3c       # 4000642a  = 0x0000ff00
	call8	reg_write32_masked      # 4000642d
	retw.n                          # 40006430
	.size	ldc_hw_set_reg280_low_bytes, . - ldc_hw_set_reg280_low_bytes
