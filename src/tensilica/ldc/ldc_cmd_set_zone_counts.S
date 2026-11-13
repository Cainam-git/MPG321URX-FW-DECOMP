# ldc_cmd_set_zone_counts  (fn_400013e0): 0x400013e0-0x40001403 (firmware file offset 0x313e0-0x31403), 15 instructions
# Name basis: derived - command table; sender ldc_send_zone_counts (docs/MAP.md)
# Address stored in the words at: 0x4000d2b4
# Calls: ldc_set_zone_count_exponents, ldc_hw_set_zone_area_factors
#
# Command 0x2B (sent by ldc_send_zone_counts; docs/MAP.md: zone counts as powers of two, 5 and 6): passes the
# low byte and the next byte of the value to ldc_set_zone_count_exponents (stores them at 0x3FFE4450 +24 / +28 and in bits
# 16..23 / 24..31 of register 0xE0080000), then runs ldc_hw_set_zone_area_factors.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = low, a1+4 = high.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_zone_counts, @function
ldc_cmd_set_zone_counts:                # fn_400013e0
	entry	a1, 64                  # 400013e0
	s32i.n	a2, a1, 16              # 400013e3
	s32i.n	a3, a1, 20              # 400013e5
	# low = value & 0xFF; high = (value >> 8) & 0xFF
	l32i.n	a6, a1, 20              # 400013e7
	extui	a6, a6, 0, 8            # 400013e9
	s32i.n	a6, a1, 0               # 400013ec
	l32i.n	a5, a1, 20              # 400013ee
	srli	a5, a5, 8               # 400013f0
	extui	a5, a5, 0, 8            # 400013f3
	s32i.n	a5, a1, 4               # 400013f6
	# ldc_set_zone_count_exponents(low, high)
	l32i.n	a10, a1, 0              # 400013f8
	l32i.n	a11, a1, 4              # 400013fa
	call8	ldc_set_zone_count_exponents # 400013fc
	# ldc_hw_set_zone_area_factors()
	call8	ldc_hw_set_zone_area_factors # 400013ff
	retw.n                          # 40001402
	.size	ldc_cmd_set_zone_counts, . - ldc_cmd_set_zone_counts
