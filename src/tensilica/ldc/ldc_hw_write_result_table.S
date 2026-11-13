# ldc_hw_write_result_table  (fn_40006a08): 0x40006a08-0x40006a57 (firmware file offset 0x36a08-0x36a57), 33 instructions
# Name basis: derived - MAP: results written back to the table at 0xE0082000; count = segment count
# Called from: ldc_write_table_and_global_gain
# When bit 7 of register 0xE008000C is set, copies count / 2 words from the buffer to the table of the
# dimming block at 0xE0082000 (two 16-bit values per word). The caller ldc_write_table_and_global_gain passes the segment count
# (ldc_segment_count) as count.
# Arguments: a2 src (word buffer), a3 count (number of 16-bit values).
# Locals: a1+0 i, a1+16 src, a1+20 count.
# Returns: nothing.
# Other literal values: 0xe008000c, 0xe0082000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_write_result_table, @function
ldc_hw_write_result_table:              # fn_40006a08
	entry	a1, 64                  # 40006a08
	s32i.n	a2, a1, 16              # 40006a0b
	s32i.n	a3, a1, 20              # 40006a0d
	# if (!(reg[0x00C] & 0x80)) return;   /* reg[x] = 32-bit register at 0xE0080000 + x */
	l32r	a5, lit_3ffe1e74        # 40006a0f  = 0xe008000c
	memw                            # 40006a12
	l32i.n	a5, a5, 0               # 40006a15
	bbsi	a5, 7, .L40006a1d       # 40006a17
	j	.L40006a56              # 40006a1a
.L40006a1d:
	# for (i = 0; i < count / 2; i++)
	movi.n	a8, 0                   # 40006a1d
	s32i.n	a8, a1, 0               # 40006a1f
	l32i.n	a7, a1, 20              # 40006a21
	srli	a7, a7, 1               # 40006a23
	l32i.n	a6, a1, 0               # 40006a26
	bgeu	a6, a7, .L40006a56      # 40006a28
.L40006a2b:
	#     ((volatile u32 *)0xE0082000)[i] = src[i];
	l32i.n	a13, a1, 0              # 40006a2b
	slli	a13, a13, 2             # 40006a2d
	l32i.n	a12, a1, 0              # 40006a30
	l32i.n	a14, a1, 16             # 40006a32
	addx4	a12, a12, a14           # 40006a34
	l32i.n	a12, a12, 0             # 40006a37
	memw                            # 40006a39
	l32r	a14, lit_3ffe1f28       # 40006a3c  = 0xe0082000
	add.n	a13, a13, a14           # 40006a3f
	memw                            # 40006a41
	s32i.n	a12, a13, 0             # 40006a44
	#     /* i++, loop while i < count / 2 */
	l32i.n	a11, a1, 0              # 40006a46
	addi.n	a11, a11, 1             # 40006a48
	s32i.n	a11, a1, 0              # 40006a4a
	l32i.n	a10, a1, 20             # 40006a4c
	srli	a10, a10, 1             # 40006a4e
	l32i.n	a9, a1, 0               # 40006a51
	bltu	a9, a10, .L40006a2b     # 40006a53
.L40006a56:
	retw.n                          # 40006a56
	.size	ldc_hw_write_result_table, . - ldc_hw_write_result_table
