# ldc_run_pass_on_new_frame  (fn_40003764): 0x40003764-0x400037c9 (firmware file offset 0x33764-0x337c9), 35 instructions
# Name basis: derived - counters panel +0x160/+0x168/+0x170 written by IRQ ldc_irq_handler
# Called from: sys_init_and_run_main_loop
# Calls: ldc_run_frame_pass
# Addresses loaded: ldc_dpll_init_done
# Other literal values: 0x3ffe2bf0
#
# Main-loop step (sys_init_and_run_main_loop). Does nothing until ldc_dpll_init_done is set (command 0x40).
# The dimming block's interrupt handler ldc_irq_handler counts three status bits of register 0xE0080404 in the panel
# record: +0x160 (bit 0), +0x168 (bit 1), +0x170 (bit 4); each has a kept copy 4 bytes further on. When the
# bit 1 count differs from its copy, one processing pass (ldc_run_frame_pass) runs; the other two
# copies are only brought up to date.
# Arguments: none.
# Locals: none.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_run_pass_on_new_frame, @function
ldc_run_pass_on_new_frame:              # fn_40003764
	entry	a1, 32                  # 40003764
	# if (ldc_dpll_init_done != 0)
	movi.n	a3, 0                   # 40003767
	l32r	a2, lit_3ffe1b34        # 40003769  = ldc_dpll_init_done
	l32i.n	a2, a2, 0               # 4000376c
	bne	a2, a3, .L40003774      # 4000376e
	j	.L400037c8              # 40003771
.L40003774:
	# if (panel.irq_bit0_count != panel.irq_bit0_seen) panel.irq_bit0_seen = panel.irq_bit0_count
	l32r	a4, lit_3ffe1a80        # 40003774  = 0x3ffe2bf0
	l32i	a4, a4, 0x164           # 40003777
	l32r	a3, lit_3ffe1a80        # 4000377a  = 0x3ffe2bf0
	l32i	a3, a3, 0x160           # 4000377d
	beq	a3, a4, .L4000378f      # 40003780
	l32r	a6, lit_3ffe1a80        # 40003783  = 0x3ffe2bf0
	l32r	a5, lit_3ffe1a80        # 40003786  = 0x3ffe2bf0
	l32i	a5, a5, 0x160           # 40003789
	s32i	a5, a6, 0x164           # 4000378c
.L4000378f:
	# if (panel.irq_bit1_count != panel.irq_bit1_seen) { ldc_run_frame_pass(); panel.irq_bit1_seen = panel.irq_bit1_count; }
	l32r	a7, lit_3ffe1a80        # 4000378f  = 0x3ffe2bf0
	l32i	a7, a7, 0x16c           # 40003792
	l32r	a6, lit_3ffe1a80        # 40003795  = 0x3ffe2bf0
	l32i	a6, a6, 0x168           # 40003798
	beq	a6, a7, .L400037ad      # 4000379b
	call8	ldc_run_frame_pass      # 4000379e
	l32r	a9, lit_3ffe1a80        # 400037a1  = 0x3ffe2bf0
	l32r	a8, lit_3ffe1a80        # 400037a4  = 0x3ffe2bf0
	l32i	a8, a8, 0x168           # 400037a7
	s32i	a8, a9, 0x16c           # 400037aa
.L400037ad:
	# if (panel.irq_bit4_count != panel.irq_bit4_seen) panel.irq_bit4_seen = panel.irq_bit4_count
	l32r	a10, lit_3ffe1a80       # 400037ad  = 0x3ffe2bf0
	l32i	a10, a10, 0x174         # 400037b0
	l32r	a9, lit_3ffe1a80        # 400037b3  = 0x3ffe2bf0
	l32i	a9, a9, 0x170           # 400037b6
	beq	a9, a10, .L400037c8     # 400037b9
	l32r	a12, lit_3ffe1a80       # 400037bc  = 0x3ffe2bf0
	l32r	a11, lit_3ffe1a80       # 400037bf  = 0x3ffe2bf0
	l32i	a11, a11, 0x170         # 400037c2
	s32i	a11, a12, 0x174         # 400037c5
.L400037c8:
	retw.n                          # 400037c8
	.size	ldc_run_pass_on_new_frame, . - ldc_run_pass_on_new_frame
