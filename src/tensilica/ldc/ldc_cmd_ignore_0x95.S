# ldc_cmd_ignore_0x95  (fn_400019f0): 0x400019f0-0x400019f8 (firmware file offset 0x319f0-0x319f8), 4 instructions
# Name basis: proven - empty body; table entry 0x95
# Address stored in the words at: 0x4000d3bc
#
# Command 0x95: stores its arguments and does nothing else.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_ignore_0x95, @function
ldc_cmd_ignore_0x95:                    # fn_400019f0
	entry	a1, 48                  # 400019f0
	# sub = a2; value = a3   (nothing else)
	s32i.n	a2, a1, 0               # 400019f3
	s32i.n	a3, a1, 4               # 400019f5
	retw.n                          # 400019f7
	.size	ldc_cmd_ignore_0x95, . - ldc_cmd_ignore_0x95
