# ldc_cmd_set_reg280_bytes  (fn_40001404): 0x40001404-0x40001424 (firmware file offset 0x31404-0x31424), 14 instructions
# Name basis: descriptive - command table; ldc_hw_set_reg280_low_bytes register writes
# Address stored in the words at: 0x4000d3e4
# Calls: ldc_hw_set_reg280_low_bytes
#
# Command 0x85: writes the low byte of the value to bits 0..7 and the next byte to bits 8..15 of register
# 0xE0080280 (through ldc_hw_set_reg280_low_bytes, which takes the high byte first).
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = low, a1+4 = high.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_reg280_bytes, @function
ldc_cmd_set_reg280_bytes:               # fn_40001404
	entry	a1, 64                  # 40001404
	s32i.n	a2, a1, 16              # 40001407
	s32i.n	a3, a1, 20              # 40001409
	# low = value & 0xFF; high = (value >> 8) & 0xFF
	l32i.n	a6, a1, 20              # 4000140b
	extui	a6, a6, 0, 8            # 4000140d
	s32i.n	a6, a1, 0               # 40001410
	l32i.n	a5, a1, 20              # 40001412
	srli	a5, a5, 8               # 40001414
	extui	a5, a5, 0, 8            # 40001417
	s32i.n	a5, a1, 4               # 4000141a
	# ldc_hw_set_reg280_low_bytes(high, low)
	l32i.n	a10, a1, 4              # 4000141c
	l32i.n	a11, a1, 0              # 4000141e
	call8	ldc_hw_set_reg280_low_bytes # 40001420
	retw.n                          # 40001423
	.size	ldc_cmd_set_reg280_bytes, . - ldc_cmd_set_reg280_bytes
