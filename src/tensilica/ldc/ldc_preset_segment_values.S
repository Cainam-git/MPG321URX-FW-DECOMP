# ldc_preset_segment_values  (fn_40006180): 0x40006180-0x400061ac (firmware file offset 0x36180-0x361ac), 18 instructions
# Name basis: derived - fill loop; the array is refilled from 0xE0083000 by the interrupt routine
# Called from: ldc_hw_init
# Fills the 2048 16-bit entries of the segment value array at 0x3ffe4490 with 0xFFC. The interrupt routine
# ldc_irq_handler later refills the array from the dimming block (ldc_read_segment_values).
# Arguments: none.
# Locals: a1+0 i.
# Returns: nothing.
# Other literal values: 0x3ffe4490, 0x00000ffc

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_preset_segment_values, @function
ldc_preset_segment_values:              # fn_40006180
	entry	a1, 48                  # 40006180
	# for (i = 0; i <= 0x7FF; i++)
	movi.n	a4, 0                   # 40006183
	s32i.n	a4, a1, 0               # 40006185
	l32i.n	a3, a1, 0               # 40006187
	movi	a2, 0x7ff               # 40006189
	bltu	a2, a3, .L400061ab      # 4000618c
.L4000618f:
	#     segment_values[i] = 0xFFC;   /* u16 array at 0x3ffe4490 */
	l32i.n	a9, a1, 0               # 4000618f
	l32r	a10, lit_3ffe1b88       # 40006191  = 0x3ffe4490
	addx2	a9, a9, a10             # 40006194
	l32r	a8, lit_3ffe1bdc        # 40006197  = 0x00000ffc
	s16i	a8, a9, 0               # 4000619a
	#     /* i++, loop while i <= 0x7FF */
	l32i.n	a7, a1, 0               # 4000619d
	addi.n	a7, a7, 1               # 4000619f
	s32i.n	a7, a1, 0               # 400061a1
	l32i.n	a6, a1, 0               # 400061a3
	movi	a5, 0x7ff               # 400061a5
	bgeu	a5, a6, .L4000618f      # 400061a8
.L400061ab:
	retw.n                          # 400061ab
	.size	ldc_preset_segment_values, . - ldc_preset_segment_values
