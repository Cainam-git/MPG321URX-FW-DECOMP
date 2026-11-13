# ldc_hw_set_reg168_fields  (fn_40006724): 0x40006724-0x4000674c (firmware file offset 0x36724-0x3674c), 17 instructions
# Name basis: derived - command 0x84 handler; MAP: command 0x84 value written to 0xE0080168
# Called from: ldc_cmd_set_reg168, ldc_hw_init
# Stores two values in the segment grid record (+32, +36) and writes (first << 8) + second to bits 0..23 of
# register 0xE0080168. ldc_hw_init passes 56 and 20; command 0x84 (ldc_cmd_set_reg168, sender ldc_send_cmd_0x84 on
# the main processor) passes its two words in swapped order.
# Arguments: a2 high_field, a3 low_field.
# Locals: a1+0 high_field, a1+4 low_field.
# Returns: nothing.
# Calls: reg_write32_masked
# Other literal values: 0x3ffe4450, 0xe0080168, 0x00ffffff

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_set_reg168_fields, @function
ldc_hw_set_reg168_fields:               # fn_40006724
	entry	a1, 48                  # 40006724
	s32i.n	a2, a1, 0               # 40006727
	s32i.n	a3, a1, 4               # 40006729
	# grid.reg168_high = high_field;   /* 0x3ffe4450 +32 */
	l32r	a15, lit_3ffe1a84       # 4000672b  = 0x3ffe4450
	l32i.n	a14, a1, 0              # 4000672e
	s32i.n	a14, a15, 32            # 40006730
	# grid.reg168_low = low_field;   /* +36 */
	l32r	a14, lit_3ffe1a84       # 40006732  = 0x3ffe4450
	l32i.n	a13, a1, 4              # 40006735
	s32i.n	a13, a14, 36            # 40006737
	# reg_write32_masked(0xE0080168, low_field + (high_field << 8), 0xFFFFFF);
	l32r	a10, lit_3ffe1ef0       # 40006739  = 0xe0080168
	l32i.n	a12, a1, 0              # 4000673c
	slli	a12, a12, 8             # 4000673e
	l32i.n	a11, a1, 4              # 40006741
	add.n	a11, a11, a12           # 40006743
	l32r	a12, lit_3ffe1ef4       # 40006745  = 0x00ffffff
	call8	reg_write32_masked      # 40006748
	retw.n                          # 4000674b
	.size	ldc_hw_set_reg168_fields, . - ldc_hw_set_reg168_fields
