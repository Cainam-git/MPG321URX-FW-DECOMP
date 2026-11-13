# ldc_cmd_set_reg5a4_bit2  (fn_40001aa8): 0x40001aa8-0x40001ab5 (firmware file offset 0x31aa8-0x31ab5), 6 instructions
# Name basis: descriptive - code only, through ldc_hw_set_reg5a4_bit2
# Address stored in the words at: 0x4000d3d4
# Calls: ldc_hw_set_reg5a4_bit2
#
# Command 0x83: passes the value to ldc_hw_set_reg5a4_bit2, which sets bit 2 of register 0xE00805A4 for value 1 and clears
# it for any other value.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_reg5a4_bit2, @function
ldc_cmd_set_reg5a4_bit2:                # fn_40001aa8
	entry	a1, 48                  # 40001aa8
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 40001aab
	s32i.n	a3, a1, 4               # 40001aad
	# ldc_hw_set_reg5a4_bit2(value)   (bit 2 of 0xE00805A4 = (value == 1))
	l32i.n	a10, a1, 4              # 40001aaf
	call8	ldc_hw_set_reg5a4_bit2  # 40001ab1
	retw.n                          # 40001ab4
	.size	ldc_cmd_set_reg5a4_bit2, . - ldc_cmd_set_reg5a4_bit2
