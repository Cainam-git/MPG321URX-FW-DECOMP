# lib_blend_by_weight_1024  (fn_40002660): 0x40002660-0x40002686 (firmware file offset 0x32660-0x32686), 16 instructions
# Name basis: proven - code: whole routine is the formula
# Called from: ldc_pdim_smooth_toward_target, ldc_adim_smooth_toward_target, ldc_smooth_and_apply_global_gain
#
# Returns the weighted mix of two values with a weight out of 1024, rounded: (a * w + b * (1024 - w) + 512) >> 10.
# The smoothing steps call it with a = target << 8, b = the kept value (also scaled by 256) and w = a weight from
# the dimming settings (+36..+56).
# Arguments: a2 = a, a3 = b, a4 = w (0..1024).
# Locals: a1+0 = a, a1+4 = b, a1+8 = w.
# Returns: the mixed value.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_blend_by_weight_1024, @function
lib_blend_by_weight_1024:               # fn_40002660
	entry	a1, 48                  # 40002660
	s32i.n	a2, a1, 0               # 40002663
	s32i.n	a3, a1, 4               # 40002665
	s32i.n	a4, a1, 8               # 40002667
	# return (a * w + b * (0x400 - w) + 0x200) >> 10
	l32i.n	a5, a1, 8               # 40002669
	movi	a4, 0x400               # 4000266b
	sub	a4, a4, a5              # 4000266e
	l32i.n	a3, a1, 4               # 40002671
	mull	a3, a3, a4              # 40002673
	l32i.n	a4, a1, 8               # 40002676
	l32i.n	a2, a1, 0               # 40002678
	mull	a2, a2, a4              # 4000267a
	add.n	a2, a2, a3              # 4000267d
	addmi	a2, a2, 0x200           # 4000267f
	srli	a2, a2, 10              # 40002682
	retw.n                          # 40002685
	.size	lib_blend_by_weight_1024, . - lib_blend_by_weight_1024
