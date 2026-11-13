# ldc_cmd_set_gain_table3_point  (fn_40001920): 0x40001920-0x40001934 (firmware file offset 0x31920-0x31934), 9 instructions
# Name basis: proven - table ldc_gain_table_anv3 printed as 'LDC_GainTable_ANV3'
# Address stored in the words at: 0x4000d37c
# Calls: ldc_gain_table_set_point
# Addresses loaded: ldc_gain_table_anv3
#
# Command 0x53 (sent by ldc_send_gain_table3_point): changes one point of the 5-point gain table ldc_gain_table_anv3 (printed
# as "LDC_GainTable_ANV3") through ldc_gain_table_set_point; the sub-code selects the point and x or y.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word), the point selector
# a3 = value: 16-bit value of the command (bits 0..15), the new x or y
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_gain_table3_point, @function
ldc_cmd_set_gain_table3_point:          # fn_40001920
	entry	a1, 48                  # 40001920
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 40001923
	s32i.n	a3, a1, 4               # 40001925
	# ldc_gain_table_set_point(gain_table_anv3, 5, value, sub)
	l32r	a10, lit_3ffe1b64       # 40001927  = ldc_gain_table_anv3
	movi.n	a11, 5                  # 4000192a
	l32i.n	a12, a1, 4              # 4000192c
	l32i.n	a13, a1, 0              # 4000192e
	call8	ldc_gain_table_set_point # 40001930
	retw.n                          # 40001933
	.size	ldc_cmd_set_gain_table3_point, . - ldc_cmd_set_gain_table3_point
