# ldc_cmd_set_reg00c_bit7  (fn_4000176c): 0x4000176c-0x4000177c (firmware file offset 0x3176c-0x3177c), 7 instructions
# Name basis: descriptive - code only, through ldc_hw_set_reg00c_bit7
# Address stored in the words at: 0x4000d34c
# Calls: ldc_hw_set_reg00c_bit7
#
# Command 0x43: passes the low byte of the value to ldc_hw_set_reg00c_bit7, which sets bit 7 of the byte register
# 0xE008000C when it is not 0 and clears that bit when it is 0.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_reg00c_bit7, @function
ldc_cmd_set_reg00c_bit7:                # fn_4000176c
	entry	a1, 48                  # 4000176c
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 4000176f
	s32i.n	a3, a1, 4               # 40001771
	# ldc_hw_set_reg00c_bit7((uint8_t)value)   (bit 7 of 0xE008000C = (value != 0))
	l32i.n	a10, a1, 4              # 40001773
	extui	a10, a10, 0, 8          # 40001775
	call8	ldc_hw_set_reg00c_bit7  # 40001778
	retw.n                          # 4000177b
	.size	ldc_cmd_set_reg00c_bit7, . - ldc_cmd_set_reg00c_bit7
