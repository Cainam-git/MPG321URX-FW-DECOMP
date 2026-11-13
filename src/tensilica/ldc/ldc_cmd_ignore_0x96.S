# ldc_cmd_ignore_0x96  (fn_400019fc): 0x400019fc-0x40001a04 (firmware file offset 0x319fc-0x31a04), 4 instructions
# Name basis: proven - empty body; table entry 0x96
# Address stored in the words at: 0x4000d3c4
#
# Command 0x96: stores its arguments and does nothing else.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_ignore_0x96, @function
ldc_cmd_ignore_0x96:                    # fn_400019fc
	entry	a1, 48                  # 400019fc
	# sub = a2; value = a3   (nothing else)
	s32i.n	a2, a1, 0               # 400019ff
	s32i.n	a3, a1, 4               # 40001a01
	retw.n                          # 40001a03
	.size	ldc_cmd_ignore_0x96, . - ldc_cmd_ignore_0x96
