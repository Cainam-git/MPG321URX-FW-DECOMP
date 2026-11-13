# ldc_cmd_set_reg168  (fn_40001ab8): 0x40001ab8-0x40001ac7 (firmware file offset 0x31ab8-0x31ac7), 7 instructions
# Name basis: derived - ldc_hw_set_reg168_fields; docs/MAP.md: 0x84 written to 0xE0080168
# Address stored in the words at: 0x4000d3dc
# Calls: ldc_hw_set_reg168_fields
#
# Command 0x84 (sent by ldc_send_cmd_0x84): calls ldc_hw_set_reg168_fields(value, sub), which keeps value at segment_grid
# +32 and sub at segment_grid +36 (0x3FFE4450) and writes (value << 8) + sub into bits 0..23 of register
# 0xE0080168.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_reg168, @function
ldc_cmd_set_reg168:                     # fn_40001ab8
	entry	a1, 48                  # 40001ab8
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 40001abb
	s32i.n	a3, a1, 4               # 40001abd
	# ldc_hw_set_reg168_fields(value, sub)
	l32i.n	a10, a1, 4              # 40001abf
	l32i.n	a11, a1, 0              # 40001ac1
	call8	ldc_hw_set_reg168_fields # 40001ac3
	retw.n                          # 40001ac6
	.size	ldc_cmd_set_reg168, . - ldc_cmd_set_reg168
