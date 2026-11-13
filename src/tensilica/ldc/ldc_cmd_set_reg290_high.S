# ldc_cmd_set_reg290_high  (fn_40001748): 0x40001748-0x40001755 (firmware file offset 0x31748-0x31755), 6 instructions
# Name basis: descriptive - code only, through ldc_hw_set_reg290_high_half
# Address stored in the words at: 0x4000d354
# Calls: ldc_hw_set_reg290_high_half
#
# Command 0x44: passes the value to ldc_hw_set_reg290_high_half, which writes it into bits 16..31 of register 0xE0080290.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_reg290_high, @function
ldc_cmd_set_reg290_high:                # fn_40001748
	entry	a1, 48                  # 40001748
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 4000174b
	s32i.n	a3, a1, 4               # 4000174d
	# ldc_hw_set_reg290_high_half(value)   (bits 16..31 of 0xE0080290 = value)
	l32i.n	a10, a1, 4              # 4000174f
	call8	ldc_hw_set_reg290_high_half # 40001751
	retw.n                          # 40001754
	.size	ldc_cmd_set_reg290_high, . - ldc_cmd_set_reg290_high
