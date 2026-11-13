# ldc_cmd_set_gain_table1_point  (fn_400018f0): 0x400018f0-0x40001904 (firmware file offset 0x318f0-0x31904), 9 instructions
# Name basis: proven - table ldc_gain_table_anv1 printed as 'LDC_GainTable_ANV1'
# Address stored in the words at: 0x4000d36c
# Calls: ldc_gain_table_set_point
# Addresses loaded: ldc_gain_table_anv1
#
# Command 0x51 (sent by ldc_send_gain_table1_point): changes one point of the 5-point gain table ldc_gain_table_anv1 (printed
# as "LDC_GainTable_ANV1") through ldc_gain_table_set_point; the sub-code selects the point and x or y.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word), the point selector
# a3 = value: 16-bit value of the command (bits 0..15), the new x or y
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_gain_table1_point, @function
ldc_cmd_set_gain_table1_point:          # fn_400018f0
	entry	a1, 48                  # 400018f0
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 400018f3
	s32i.n	a3, a1, 4               # 400018f5
	# ldc_gain_table_set_point(gain_table_anv1, 5, value, sub)
	l32r	a10, lit_3ffe1b20       # 400018f7  = ldc_gain_table_anv1
	movi.n	a11, 5                  # 400018fa
	l32i.n	a12, a1, 4              # 400018fc
	l32i.n	a13, a1, 0              # 400018fe
	call8	ldc_gain_table_set_point # 40001900
	retw.n                          # 40001903
	.size	ldc_cmd_set_gain_table1_point, . - ldc_cmd_set_gain_table1_point
