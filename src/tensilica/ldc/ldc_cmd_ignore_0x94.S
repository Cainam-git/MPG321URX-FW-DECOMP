# ldc_cmd_ignore_0x94  (fn_400019e4): 0x400019e4-0x400019ec (firmware file offset 0x319e4-0x319ec), 4 instructions
# Name basis: proven - empty body; table entry 0x94
# Address stored in the words at: 0x4000d3b4
#
# Command 0x94: stores its arguments and does nothing else.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_ignore_0x94, @function
ldc_cmd_ignore_0x94:                    # fn_400019e4
	entry	a1, 48                  # 400019e4
	# sub = a2; value = a3   (nothing else)
	s32i.n	a2, a1, 0               # 400019e7
	s32i.n	a3, a1, 4               # 400019e9
	retw.n                          # 400019eb
	.size	ldc_cmd_ignore_0x94, . - ldc_cmd_ignore_0x94
