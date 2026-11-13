# ldc_cmd_load_gain_table  (fn_40001938): 0x40001938-0x40001990 (firmware file offset 0x31938-0x31990), 35 instructions
# Name basis: proven - calls DRV_LDC_Intensity_Gain_Update 'DRV_LDC_Intensity_Gain_Update' with the selected
#   table
# Address stored in the words at: 0x4000d364
# Calls: DRV_LDC_Intensity_Gain_Update
# Addresses loaded: ldc_gain_table_flat, ldc_gain_table_anv1, ldc_gain_table_anv2, ldc_gain_table_anv3
#
# Command 0x50 (sent by ldc_send_load_gain_table): loads a gain table into the hardware with
# DRV_LDC_Intensity_Gain_Update: 1 = ANV1 (ldc_gain_table_anv1, 5 points), 2 = ANV2 (ldc_gain_table_anv2,
# 5 points), 3 = ANV3 (ldc_gain_table_anv3, 5 points), 0 or any other value = the 2-point table ldc_gain_table_flat
# ({0, 0x400}, {0xFF, 0x400}).
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15), the table number
# Locals: a1+0 = table (low byte of value), a1+4 = switch copy of table, a1+16 = sub, a1+20 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_load_gain_table, @function
ldc_cmd_load_gain_table:                # fn_40001938
	entry	a1, 64                  # 40001938
	# sub = a2; value = a3
	s32i.n	a2, a1, 16              # 4000193b
	s32i.n	a3, a1, 20              # 4000193d
	# table = (uint8_t)value
	l32i.n	a8, a1, 20              # 4000193f
	extui	a8, a8, 0, 8            # 40001941
	s32i.n	a8, a1, 0               # 40001944
	# switch (table)
	l32i.n	a7, a1, 0               # 40001946
	s32i.n	a7, a1, 4               # 40001948
	movi.n	a6, 0                   # 4000194a
	l32i.n	a5, a1, 4               # 4000194c
	beq	a5, a6, .L40001963      # 4000194e
	l32i.n	a9, a1, 4               # 40001951
	beqi	a9, 1, .L4000196e       # 40001953
	l32i.n	a10, a1, 4              # 40001956
	beqi	a10, 2, .L40001979      # 40001958
	l32i.n	a11, a1, 4              # 4000195b
	beqi	a11, 3, .L40001984      # 4000195d
	j	.L40001963              # 40001960
.L40001963:
	# case 0, default: DRV_LDC_Intensity_Gain_Update(ldc_gain_table_flat, 2)
	l32r	a10, lit_3ffe1b24       # 40001963  = ldc_gain_table_flat
	movi.n	a11, 2                  # 40001966
	call8	DRV_LDC_Intensity_Gain_Update # 40001968
	j	.L4000198f              # 4000196b
.L4000196e:
	# case 1: DRV_LDC_Intensity_Gain_Update(gain_table_anv1, 5)
	l32r	a10, lit_3ffe1b20       # 4000196e  = ldc_gain_table_anv1
	movi.n	a11, 5                  # 40001971
	call8	DRV_LDC_Intensity_Gain_Update # 40001973
	j	.L4000198f              # 40001976
.L40001979:
	# case 2: DRV_LDC_Intensity_Gain_Update(gain_table_anv2, 5)
	l32r	a10, lit_3ffe1b60       # 40001979  = ldc_gain_table_anv2
	movi.n	a11, 5                  # 4000197c
	call8	DRV_LDC_Intensity_Gain_Update # 4000197e
	j	.L4000198f              # 40001981
.L40001984:
	# case 3: DRV_LDC_Intensity_Gain_Update(gain_table_anv3, 5)
	l32r	a10, lit_3ffe1b64       # 40001984  = ldc_gain_table_anv3
	movi.n	a11, 5                  # 40001987
	call8	DRV_LDC_Intensity_Gain_Update # 40001989
	j	.L4000198f              # 4000198c
.L4000198f:
	retw.n                          # 4000198f
	.size	ldc_cmd_load_gain_table, . - ldc_cmd_load_gain_table
