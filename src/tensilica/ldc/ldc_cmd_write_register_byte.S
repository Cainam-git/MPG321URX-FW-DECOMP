# ldc_cmd_write_register_byte  (fn_40001a4c): 0x40001a4c-0x40001aa4 (firmware file offset 0x31a4c-0x31aa4), 36 instructions
# Name basis: derived - read-modify-write of one byte lane
# Address stored in the words at: 0x4000d3cc
# Other literal values: 0xe0080000
#
# Command 0x77: writes the sub-code as one byte into the register block at 0xE0080000. The value is the byte
# offset: the word at 0xE0080000 + (value & ~3) is read, its byte (value & 3) (bits 8 * (value & 3) and up)
# is replaced by the sub-code, and the word is written back.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word), the byte to write
# a3 = value: 16-bit value of the command (bits 0..15), the byte offset from 0xE0080000
# Locals: a1+0 = reg (word address), a1+4 = mask, a1+8 = bits (sub shifted into place), a1+16 = sub,
#   a1+20 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_write_register_byte, @function
ldc_cmd_write_register_byte:            # fn_40001a4c
	entry	a1, 64                  # 40001a4c
	# sub = a2; value = a3
	s32i.n	a2, a1, 16              # 40001a4f
	s32i.n	a3, a1, 20              # 40001a51
	# reg = 0xE0080000 + (value & ~3)
	l32r	a14, lit_3ffe1b74       # 40001a53  = 0xe0080000
	movi.n	a15, -4                 # 40001a56
	l32i.n	a13, a1, 20             # 40001a58
	and	a13, a13, a15           # 40001a5a
	add.n	a13, a13, a14           # 40001a5d
	s32i.n	a13, a1, 0              # 40001a5f
	# mask = 0xFF << (8 * (value & 3))
	movi	a11, 255                # 40001a61
	l32i.n	a12, a1, 20             # 40001a64
	extui	a12, a12, 0, 2          # 40001a66
	slli	a12, a12, 3             # 40001a69
	ssl	a12                     # 40001a6c
	sll	a11, a11                # 40001a6f
	s32i.n	a11, a1, 4              # 40001a72
	# bits = sub << (8 * (value & 3))
	l32i.n	a10, a1, 16             # 40001a74
	l32i.n	a11, a1, 20             # 40001a76
	extui	a11, a11, 0, 2          # 40001a78
	slli	a11, a11, 3             # 40001a7b
	ssl	a11                     # 40001a7e
	sll	a10, a10                # 40001a81
	s32i.n	a10, a1, 8              # 40001a84
	# *reg = (*reg & ~mask) | bits
	l32i.n	a6, a1, 0               # 40001a86
	l32i.n	a7, a1, 8               # 40001a88
	movi.n	a9, -1                  # 40001a8a
	l32i.n	a8, a1, 4               # 40001a8c
	xor	a8, a8, a9              # 40001a8e
	l32i.n	a5, a1, 0               # 40001a91
	memw                            # 40001a93
	l32i.n	a5, a5, 0               # 40001a96
	and	a5, a5, a8              # 40001a98
	or	a5, a5, a7              # 40001a9b
	memw                            # 40001a9e
	s32i.n	a5, a6, 0               # 40001aa1
	retw.n                          # 40001aa3
	.size	ldc_cmd_write_register_byte, . - ldc_cmd_write_register_byte
