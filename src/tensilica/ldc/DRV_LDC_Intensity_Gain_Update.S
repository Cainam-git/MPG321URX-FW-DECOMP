# DRV_LDC_Intensity_Gain_Update  (fn_40006904): 0x40006904-0x400069db (firmware file offset 0x36904-0x369db), 93 instructions
# Name basis: proven - original name printed 'DRV_LDC_Intensity_Gain_Update'
# Called from: ldc_cmd_set_ldc_mode, ldc_cmd_load_gain_table
# Original name: the routine prints "DRV_LDC_Intensity_Gain_Update". Takes a curve of count {x, y} points
# (8 bytes each, x rising) and fills the register table at 0xE0080C00 (one word per x) by straight-line
# interpolation between neighbouring points: for each x from p[i].x up to p[i+1].x - 1 the value
# v = p[i].y - (x - p[i].x + 1) * (p[i].y - p[i+1].y) / (p[i+1].x - p[i].x) is computed and the word
# prev + ((prev - v) << 16) is written, prev being the value of the x before. The last point's y goes to
# 0xE0080FFC. Callers: ldc_cmd_set_ldc_mode (command 0x20, curves ldc_gain_table_anv1 with 5 points / ldc_gain_table_flat with 2)
# and ldc_cmd_load_gain_table (command 0x50, one of four curves).
# Arguments: a2 points (array of {x, y} words), a3 count.
# Locals: a1+0 i (segment of the curve), a1+4 prev, a1+8 x0, a1+12 x1, a1+16 y0, a1+20 y1, a1+24 x,
#   a1+28 v, a1+32 word, a1+48 points, a1+52 count.
# Returns: nothing.
# Note: reg_write32(addr, value) is reg_write32: *addr = value.
# Calls: dbg_printf, reg_write32
# Text loaded: "DRV_LDC_Intensity_Gain_Update\n"
# Other literal values: 0xe0080c00, 0xe0080ffc

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	DRV_LDC_Intensity_Gain_Update, @function
DRV_LDC_Intensity_Gain_Update:          # fn_40006904
	entry	a1, 96                  # 40006904
	s32i.n	a2, a1, 48              # 40006907
	s32i.n	a3, a1, 52              # 40006909
	# printf("DRV_LDC_Intensity_Gain_Update\n");
	l32r	a10, lit_3ffe1f14       # 4000690b  = ro_3ffe0b2c "DRV_LDC_Intensity_Gain_Update\n"
	call8	dbg_printf              # 4000690e
	# for (i = 0; i < count - 1; i++) {
	movi.n	a7, 0                   # 40006911
	s32i.n	a7, a1, 0               # 40006913
	l32i.n	a6, a1, 52              # 40006915
	addi.n	a6, a6, -1              # 40006917
	l32i.n	a5, a1, 0               # 40006919
	bltu	a5, a6, .L40006921      # 4000691b
	j	.L400069c7              # 4000691e
.L40006921:
	#     prev = points[i].y;
	l32i.n	a5, a1, 0               # 40006921
	l32i.n	a6, a1, 48              # 40006923
	addx8	a5, a5, a6              # 40006925
	l32i.n	a5, a5, 4               # 40006928
	s32i.n	a5, a1, 4               # 4000692a
	#     x0 = points[i].x;
	l32i.n	a3, a1, 0               # 4000692c
	l32i.n	a4, a1, 48              # 4000692e
	addx8	a3, a3, a4              # 40006930
	l32i.n	a3, a3, 0               # 40006933
	s32i.n	a3, a1, 8               # 40006935
	#     x1 = points[i + 1].x;
	l32i.n	a15, a1, 0              # 40006937
	l32i.n	a2, a1, 48              # 40006939
	addx8	a15, a15, a2            # 4000693b
	l32i.n	a15, a15, 8             # 4000693e
	s32i.n	a15, a1, 12             # 40006940
	#     y0 = points[i].y;
	l32i.n	a13, a1, 0              # 40006942
	l32i.n	a14, a1, 48             # 40006944
	addx8	a13, a13, a14           # 40006946
	l32i.n	a13, a13, 4             # 40006949
	s32i.n	a13, a1, 16             # 4000694b
	#     y1 = points[i + 1].y;
	l32i.n	a11, a1, 0              # 4000694d
	l32i.n	a12, a1, 48             # 4000694f
	addx8	a11, a11, a12           # 40006951
	l32i.n	a11, a11, 12            # 40006954
	s32i.n	a11, a1, 20             # 40006956
	#     for (x = x0; x < x1; x++) {
	l32i.n	a10, a1, 8              # 40006958
	s32i.n	a10, a1, 24             # 4000695a
	l32i.n	a9, a1, 12              # 4000695c
	l32i.n	a8, a1, 24              # 4000695e
	bgeu	a8, a9, .L400069b5      # 40006960
.L40006963:
	#         v = y0 - (x - x0 + 1) * (y0 - y1) / (x1 - x0);
	l32i.n	a4, a1, 8               # 40006963
	l32i.n	a3, a1, 12              # 40006965
	sub	a3, a3, a4              # 40006967
	l32i.n	a5, a1, 20              # 4000696a
	l32i.n	a4, a1, 16              # 4000696c
	sub	a4, a4, a5              # 4000696e
	l32i.n	a5, a1, 8               # 40006971
	l32i.n	a2, a1, 24              # 40006973
	sub	a2, a2, a5              # 40006975
	addi.n	a2, a2, 1               # 40006978
	mull	a2, a2, a4              # 4000697a
	quou	a2, a2, a3              # 4000697d
	l32i.n	a15, a1, 16             # 40006980
	sub	a15, a15, a2            # 40006982
	s32i.n	a15, a1, 28             # 40006985
	#         word = prev + ((prev - v) << 16);
	l32i.n	a14, a1, 28             # 40006987
	l32i.n	a13, a1, 4              # 40006989
	sub	a13, a13, a14           # 4000698b
	slli	a13, a13, 16            # 4000698e
	l32i.n	a12, a1, 4              # 40006991
	add.n	a12, a12, a13           # 40006993
	s32i.n	a12, a1, 32             # 40006995
	#         reg_write32(0xE0080C00 + x * 4, word);
	l32i.n	a10, a1, 24             # 40006997
	l32r	a11, lit_3ffe1f18       # 40006999  = 0xe0080c00
	addx4	a10, a10, a11           # 4000699c
	l32i.n	a11, a1, 32             # 4000699f
	call8	reg_write32             # 400069a1
	#         prev = v;
	l32i.n	a8, a1, 28              # 400069a4
	s32i.n	a8, a1, 4               # 400069a6
	#         /* x++, loop while x < x1 */
	#     }
	l32i.n	a7, a1, 24              # 400069a8
	addi.n	a7, a7, 1               # 400069aa
	s32i.n	a7, a1, 24              # 400069ac
	l32i.n	a6, a1, 12              # 400069ae
	l32i.n	a5, a1, 24              # 400069b0
	bltu	a5, a6, .L40006963      # 400069b2
.L400069b5:
	#     /* i++, loop while i < count - 1 */
	# }
	l32i.n	a11, a1, 0              # 400069b5
	addi.n	a11, a11, 1             # 400069b7
	s32i.n	a11, a1, 0              # 400069b9
	l32i.n	a10, a1, 52             # 400069bb
	addi.n	a10, a10, -1            # 400069bd
	l32i.n	a9, a1, 0               # 400069bf
	bgeu	a9, a10, .L400069c7     # 400069c1
	j	.L40006921              # 400069c4
.L400069c7:
	# reg_write32(0xE0080FFC, points[count - 1].y);
	l32r	a10, lit_3ffe1f1c       # 400069c7  = 0xe0080ffc
	l32i.n	a11, a1, 52             # 400069ca
	l32i.n	a12, a1, 48             # 400069cc
	addx8	a11, a11, a12           # 400069ce
	addmi	a11, a11, 0xffffff00    # 400069d1
	l32i	a11, a11, 252           # 400069d4
	call8	reg_write32             # 400069d7
	retw.n                          # 400069da
	.size	DRV_LDC_Intensity_Gain_Update, . - DRV_LDC_Intensity_Gain_Update
