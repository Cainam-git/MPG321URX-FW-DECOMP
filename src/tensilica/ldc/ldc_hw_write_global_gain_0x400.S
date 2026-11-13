# ldc_hw_write_global_gain_0x400  (fn_400069dc): 0x400069dc-0x400069ed (firmware file offset 0x369dc-0x369ed), 7 instructions
# Name basis: descriptive - same field as ldc_hw_write_global_gain; arguments unused; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Writes 0x04000000 (0x400 in bits 16..27, the field that ldc_hw_write_global_gain fills with ApplyGlobalGain) to register
# 0xE0080378. Both arguments are stored and not used. Nothing calls it.
# Arguments: a2, a3 (unused).
# Locals: a1+0 / a1+4 the two arguments.
# Returns: nothing.
# Calls: reg_write32
# Other literal values: 0xe0080378, 0x04000000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_write_global_gain_0x400, @function
ldc_hw_write_global_gain_0x400:         # fn_400069dc
	entry	a1, 48                  # 400069dc
	s32i.n	a2, a1, 0               # 400069df
	s32i.n	a3, a1, 4               # 400069e1
	# reg_write32(0xE0080378, 0x04000000);
	l32r	a10, lit_3ffe1f20       # 400069e3  = 0xe0080378
	l32r	a11, lit_3ffe1f24       # 400069e6  = 0x04000000
	call8	reg_write32             # 400069e9
	retw.n                          # 400069ec
	.size	ldc_hw_write_global_gain_0x400, . - ldc_hw_write_global_gain_0x400
