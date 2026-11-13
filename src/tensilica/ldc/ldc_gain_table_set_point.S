# ldc_gain_table_set_point  (fn_40001894): 0x40001894-0x400018ed (firmware file offset 0x31894-0x318ed), 38 instructions
# Name basis: derived - 'Selected entry is out of range of table!'; tables printed as LDC_GainTable_ANVn
# Called from: ldc_cmd_set_gain_table1_point, ldc_cmd_set_gain_table2_point, ldc_cmd_set_gain_table3_point
# Calls: dbg_printf
# Text loaded: "Selected entry is out of range of table!\n"
#
# Changes one point of a gain table (an array of {x, y} word pairs, printed as "LDC_GainTable_ANVn" by
# ldc_print_debug_dump). Bits 0..6 of the selector give the point index; an index at or above count prints "Selected
# entry is out of range of table!". With selector bit 7 set the value becomes the point's x, but only for an
# inner point (not the first or the last) and only when the value is at most 254; otherwise nothing changes.
# With bit 7 clear the value becomes the point's y.
# a2 = table: array of {x, y} word pairs
# a3 = count: number of points in the table
# a4 = value: new x or y
# a5 = selector: bits 0..6 point index, bit 7 = 1 for x, 0 for y
# Locals: a1+0 = index.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_gain_table_set_point, @function
ldc_gain_table_set_point:               # fn_40001894
	entry	a1, 64                  # 40001894
	# table = a2; count = a3; value = a4; selector = a5   (a1+16..a1+28)
	s32i.n	a2, a1, 16              # 40001897
	s32i.n	a3, a1, 20              # 40001899
	s32i.n	a4, a1, 24              # 4000189b
	s32i.n	a5, a1, 28              # 4000189d
	# index = selector & 0x7F
	l32i.n	a10, a1, 28             # 4000189f
	extui	a10, a10, 0, 7          # 400018a1
	s32i.n	a10, a1, 0              # 400018a4
	# if (index >= count) { printf("Selected entry is out of range of table!\n"); return; }
	l32i.n	a9, a1, 20              # 400018a6
	l32i.n	a8, a1, 0               # 400018a8
	bltu	a8, a9, .L400018b6      # 400018aa
	l32r	a10, lit_3ffe1b5c       # 400018ad  = ro_3ffe0240 "Selected entry is out of range of table!\n"
	call8	dbg_printf              # 400018b0
	j	.L400018ec              # 400018b3
.L400018b6:
	# if (selector & 0x80)
	l32i.n	a11, a1, 28             # 400018b6
	bbci	a11, 7, .L400018e1      # 400018b8
	# if (index > 0 && index < count - 1 && value <= 254) table[index].x = value
	l32i.n	a13, a1, 0              # 400018bb
	movi.n	a12, 0                  # 400018bd
	bgeu	a12, a13, .L400018de    # 400018bf
	l32i.n	a15, a1, 20             # 400018c2
	addi.n	a15, a15, -1            # 400018c4
	l32i.n	a14, a1, 0              # 400018c6
	bgeu	a14, a15, .L400018de    # 400018c8
	l32i.n	a3, a1, 24              # 400018cb
	movi	a2, 254                 # 400018cd
	bltu	a2, a3, .L400018de      # 400018d0
	l32i.n	a5, a1, 0               # 400018d3
	l32i.n	a6, a1, 16              # 400018d5
	addx8	a5, a5, a6              # 400018d7
	l32i.n	a4, a1, 24              # 400018da
	s32i.n	a4, a5, 0               # 400018dc
.L400018de:
	j	.L400018ec              # 400018de
.L400018e1:
	# else table[index].y = value
	l32i.n	a8, a1, 0               # 400018e1
	l32i.n	a9, a1, 16              # 400018e3
	addx8	a8, a8, a9              # 400018e5
	l32i.n	a7, a1, 24              # 400018e8
	s32i.n	a7, a8, 4               # 400018ea
.L400018ec:
	retw.n                          # 400018ec
	.size	ldc_gain_table_set_point, . - ldc_gain_table_set_point
