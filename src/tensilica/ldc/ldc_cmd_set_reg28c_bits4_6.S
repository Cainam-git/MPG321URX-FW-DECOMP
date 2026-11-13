# ldc_cmd_set_reg28c_bits4_6  (fn_40001734): 0x40001734-0x40001744 (firmware file offset 0x31734-0x31744), 7 instructions
# Name basis: descriptive - code only, through ldc_hw_set_reg28c_bits4_6
# Address stored in the words at: 0x4000d344
# Calls: ldc_hw_set_reg28c_bits4_6
#
# Command 0x42 (sent by ldc_send_cmd_0x42): passes the low byte of the value to ldc_hw_set_reg28c_bits4_6, which writes its
# bits 0..2 into bits 4..6 of register 0xE008028C.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_reg28c_bits4_6, @function
ldc_cmd_set_reg28c_bits4_6:             # fn_40001734
	entry	a1, 48                  # 40001734
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 40001737
	s32i.n	a3, a1, 4               # 40001739
	# ldc_hw_set_reg28c_bits4_6((uint8_t)value)   (bits 4..6 of 0xE008028C = value & 7)
	l32i.n	a10, a1, 4              # 4000173b
	extui	a10, a10, 0, 8          # 4000173d
	call8	ldc_hw_set_reg28c_bits4_6 # 40001740
	retw.n                          # 40001743
	.size	ldc_cmd_set_reg28c_bits4_6, . - ldc_cmd_set_reg28c_bits4_6
