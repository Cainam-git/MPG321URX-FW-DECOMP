# ldc_cmd_ignore  (fn_400037cc): 0x400037cc-0x400037d4 (firmware file offset 0x337cc-0x337d4), 4 instructions
# Name basis: proven - ldc_command_table entries 0 and 0x36
# Address stored in the words at: 0x4000d28c, 0x4000d2f4
#
# Command handler that does nothing: entry of commands 0x00 and 0x36 in the command table ldc_command_table
# (ldc_command_table). It only stores its two arguments.
# Arguments: a2 = sub (byte 2 of the mailbox command word), a3 = value (bits 0..15).
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_ignore, @function
ldc_cmd_ignore:                         # fn_400037cc
	entry	a1, 48                  # 400037cc
	s32i.n	a2, a1, 0               # 400037cf
	s32i.n	a3, a1, 4               # 400037d1
	retw.n                          # 400037d3
	.size	ldc_cmd_ignore, . - ldc_cmd_ignore
