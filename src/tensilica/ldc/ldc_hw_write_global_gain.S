# ldc_hw_write_global_gain  (fn_400069f0): 0x400069f0-0x40006a04 (firmware file offset 0x369f0-0x36a04), 8 instructions
# Name basis: derived - caller passes ApplyGlobalGain (settings +72) right after storing it
# Called from: ldc_smooth_and_apply_global_gain
# Writes the low 12 bits of the value to bits 16..27 of register 0xE0080378 (whole-word write, other bits 0).
# The caller ldc_smooth_and_apply_global_gain passes ApplyGlobalGain (dimming settings +72) right after storing it.
# Arguments: a2 gain.
# Locals: a1+0 gain.
# Returns: nothing.
# Calls: reg_write32
# Other literal values: 0xe0080378

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_write_global_gain, @function
ldc_hw_write_global_gain:               # fn_400069f0
	entry	a1, 48                  # 400069f0
	s32i.n	a2, a1, 0               # 400069f3
	# reg_write32(0xE0080378, (gain & 0xFFF) << 16);
	l32r	a10, lit_3ffe1f20       # 400069f5  = 0xe0080378
	l32i.n	a11, a1, 0              # 400069f8
	extui	a11, a11, 0, 12         # 400069fa
	slli	a11, a11, 16            # 400069fd
	call8	reg_write32             # 40006a00
	retw.n                          # 40006a03
	.size	ldc_hw_write_global_gain, . - ldc_hw_write_global_gain
