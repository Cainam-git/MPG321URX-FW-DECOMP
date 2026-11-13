# ldc_cmd_set_gain_table2_point  (fn_40001908): 0x40001908-0x4000191c (firmware file offset 0x31908-0x3191c), 9 instructions
# Name basis: proven - table ldc_gain_table_anv2 printed as 'LDC_GainTable_ANV2'
# Address stored in the words at: 0x4000d374
# Calls: ldc_gain_table_set_point
# Addresses loaded: ldc_gain_table_anv2
#
# Command 0x52 (sent by ldc_send_gain_table2_point): changes one point of the 5-point gain table ldc_gain_table_anv2 (printed
# as "LDC_GainTable_ANV2") through ldc_gain_table_set_point; the sub-code selects the point and x or y.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word), the point selector
# a3 = value: 16-bit value of the command (bits 0..15), the new x or y
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_gain_table2_point, @function
ldc_cmd_set_gain_table2_point:          # fn_40001908
	entry	a1, 48                  # 40001908
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 4000190b
	s32i.n	a3, a1, 4               # 4000190d
	# ldc_gain_table_set_point(gain_table_anv2, 5, value, sub)
	l32r	a10, lit_3ffe1b60       # 4000190f  = ldc_gain_table_anv2
	movi.n	a11, 5                  # 40001912
	l32i.n	a12, a1, 4              # 40001914
	l32i.n	a13, a1, 0              # 40001916
	call8	ldc_gain_table_set_point # 40001918
	retw.n                          # 4000191b
	.size	ldc_cmd_set_gain_table2_point, . - ldc_cmd_set_gain_table2_point
