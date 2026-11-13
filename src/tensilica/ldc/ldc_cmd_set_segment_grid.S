# ldc_cmd_set_segment_grid  (fn_400013b4): 0x400013b4-0x400013dd (firmware file offset 0x313b4-0x313dd), 17 instructions
# Name basis: derived - command table; sender ldc_send_zone_grid_32x16 value 0x1020; DRV_LDC_SetLDCSegment
# Address stored in the words at: 0x4000d2ac
# Calls: DRV_LDC_SetLDCSegment, ldc_build_segment_channel_map
#
# Command 0x2A (sent by ldc_send_zone_grid_32x16 with value 0x1020, and by ldc_api_set_zone_grid): sets the
# segment grid to (value & 0xFF) columns by ((value >> 8) & 0xFF) rows with DRV_LDC_SetLDCSegment
# ("DRV_LDC_SetLDCSegment", which limits them to 1..64 and 1..32 and stores the segment count), then rebuilds
# the segment-to-channel map.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = cols, a1+4 = rows.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_segment_grid, @function
ldc_cmd_set_segment_grid:               # fn_400013b4
	entry	a1, 64                  # 400013b4
	s32i.n	a2, a1, 16              # 400013b7
	s32i.n	a3, a1, 20              # 400013b9
	# cols = value & 0xFF; rows = (value >> 8) & 0xFF
	l32i.n	a12, a1, 20             # 400013bb
	extui	a12, a12, 0, 8          # 400013bd
	s32i.n	a12, a1, 0              # 400013c0
	l32i.n	a11, a1, 20             # 400013c2
	srli	a11, a11, 8             # 400013c4
	extui	a11, a11, 0, 8          # 400013c7
	s32i.n	a11, a1, 4              # 400013ca
	# DRV_LDC_SetLDCSegment(cols, rows)
	l32i.n	a10, a1, 0              # 400013cc
	extui	a10, a10, 0, 8          # 400013ce
	l32i.n	a11, a1, 4              # 400013d1
	extui	a11, a11, 0, 8          # 400013d3
	call8	DRV_LDC_SetLDCSegment   # 400013d6
	# ldc_build_segment_channel_map()
	call8	ldc_build_segment_channel_map # 400013d9
	retw.n                          # 400013dc
	.size	ldc_cmd_set_segment_grid, . - ldc_cmd_set_segment_grid
