# ldc_check_pure_pattern  (fn_400030b4): 0x400030b4-0x400030c4 (firmware file offset 0x330b4-0x330c4), 7 instructions
# Name basis: derived - rec word 0 printed as 'Pure Pattern: %d' by ldc_print_debug_dump
# Called from: ldc_run_frame_pass
# Calls: ldc_check_input_duty_edges, ldc_post_segment_percent
#
# Step of the processing pass (ldc_run_frame_pass, only while panel +0x154 is 1): stores the flag returned by
# ldc_check_input_duty_edges in word 0 of the pass record, which ldc_print_debug_dump prints as
# "Pure Pattern", then runs ldc_post_segment_percent.
# Arguments: a2 = rec (the pass record of ldc_run_frame_pass, 8 words).
# Locals: a1+0 = rec.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_check_pure_pattern, @function
ldc_check_pure_pattern:                 # fn_400030b4
	entry	a1, 48                  # 400030b4
	# rec->pure_pattern = ldc_check_input_duty_edges()
	s32i.n	a2, a1, 0               # 400030b7
	call8	ldc_check_input_duty_edges # 400030b9
	l32i.n	a4, a1, 0               # 400030bc
	s32i.n	a10, a4, 0              # 400030be
	# ldc_post_segment_percent()
	call8	ldc_post_segment_percent # 400030c0
	retw.n                          # 400030c3
	.size	ldc_check_pure_pattern, . - ldc_check_pure_pattern
