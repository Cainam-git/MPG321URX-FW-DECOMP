# ldc_cmd_set_zone_peaking_percent  (fn_40001880): 0x40001880-0x40001890 (firmware file offset 0x31880-0x31890), 7 instructions
# Name basis: proven - cfg +68 printed as 'ZonePeakingPercent'
# Address stored in the words at: 0x4000d30c
# Addresses loaded: ldc_dimming_settings
#
# Command 0x3A: stores the value as ZonePeakingPercent (cfg +68).
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_zone_peaking_percent, @function
ldc_cmd_set_zone_peaking_percent:       # fn_40001880
	entry	a1, 48                  # 40001880
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 40001883
	s32i.n	a3, a1, 4               # 40001885
	# cfg.zone_peaking_percent = value
	l32r	a6, lit_3ffe1a98        # 40001887  = ldc_dimming_settings
	l32i.n	a5, a1, 4               # 4000188a
	s32i	a5, a6, 68              # 4000188c
	retw.n                          # 4000188f
	.size	ldc_cmd_set_zone_peaking_percent, . - ldc_cmd_set_zone_peaking_percent
