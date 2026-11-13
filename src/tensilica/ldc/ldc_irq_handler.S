# ldc_irq_handler  (fn_40008ef0): 0x40008ef0-0x40008f56 (firmware file offset 0x38ef0-0x38f56), 41 instructions
# Name basis: derived - installed for interrupt 9; status 0xE0080404; main loop runs
#   ldc_run_pass_on_new_frame
# Address stored in the words at: 0x4000cf4c
# Handler of interrupt 9 (installed by ldc_irq_install): sets ldc_irq_pending (0x3FFE5EE0) to 1, runs
# irq_line_ack(7, 0), then reads the status word 0xE0080404: bit 0 set -> ldc_read_segment_values() and
# panel +0x160 counter + 1; bit 1 -> panel +0x168 counter + 1; bit 4 -> panel +0x170 counter + 1; finally
# writes 0xFFFFFFFF to 0xE0080404. The main loop (sys_init_and_run_main_loop) runs ldc_run_pass_on_new_frame when it finds
# ldc_irq_pending set and clears it.
# Arguments: none. Locals: none. Returns: nothing.
# Calls: irq_line_ack, ldc_read_segment_values
# Other literal values: 0x3ffe5ee0, 0xe0080404, 0x3ffe2d50, 0x3ffe2d58, 0x3ffe2d60

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_irq_handler, @function
ldc_irq_handler:                        # fn_40008ef0
	entry	a1, 32                  # 40008ef0
	# ldc_irq_pending = 1;
	l32r	a3, lit_3ffe2240        # 40008ef3  = 0x3ffe5ee0
	movi.n	a2, 1                   # 40008ef6
	s32i.n	a2, a3, 0               # 40008ef8
	# irq_line_ack(7, 0);
	movi.n	a10, 7                  # 40008efa
	movi.n	a11, 0                  # 40008efc
	call8	irq_line_ack            # 40008efe
	# if (reg[0xE0080404] & 0x01) {
	l32r	a4, lit_3ffe2244        # 40008f01  = 0xe0080404
	memw                            # 40008f04
	l32i.n	a4, a4, 0               # 40008f07
	extui	a4, a4, 0, 1            # 40008f09
	beqz.n	a4, .L40008f1d          # 40008f0c
	# ldc_read_segment_values();
	call8	ldc_read_segment_values # 40008f0e
	# panel.count_0x160++; }
	l32r	a6, lit_3ffe2248        # 40008f11  = 0x3ffe2d50
	l32r	a5, lit_3ffe2248        # 40008f14  = 0x3ffe2d50
	l32i.n	a5, a5, 0               # 40008f17
	addi.n	a5, a5, 1               # 40008f19
	s32i.n	a5, a6, 0               # 40008f1b
.L40008f1d:
	# if (reg[0xE0080404] & 0x02) panel.count_0x168++;
	l32r	a6, lit_3ffe2244        # 40008f1d  = 0xe0080404
	memw                            # 40008f20
	l32i.n	a6, a6, 0               # 40008f23
	bbci	a6, 1, .L40008f34       # 40008f25
	l32r	a8, lit_3ffe224c        # 40008f28  = 0x3ffe2d58
	l32r	a7, lit_3ffe224c        # 40008f2b  = 0x3ffe2d58
	l32i.n	a7, a7, 0               # 40008f2e
	addi.n	a7, a7, 1               # 40008f30
	s32i.n	a7, a8, 0               # 40008f32
.L40008f34:
	# if (reg[0xE0080404] & 0x10) panel.count_0x170++;
	l32r	a8, lit_3ffe2244        # 40008f34  = 0xe0080404
	memw                            # 40008f37
	l32i.n	a8, a8, 0               # 40008f3a
	bbci	a8, 4, .L40008f4b       # 40008f3c
	l32r	a10, lit_3ffe2250       # 40008f3f  = 0x3ffe2d60
	l32r	a9, lit_3ffe2250        # 40008f42  = 0x3ffe2d60
	l32i.n	a9, a9, 0               # 40008f45
	addi.n	a9, a9, 1               # 40008f47
	s32i.n	a9, a10, 0              # 40008f49
.L40008f4b:
	# reg[0xE0080404] = 0xFFFFFFFF;
	l32r	a11, lit_3ffe2244       # 40008f4b  = 0xe0080404
	movi.n	a10, -1                 # 40008f4e
	memw                            # 40008f50
	s32i.n	a10, a11, 0             # 40008f53
	retw.n                          # 40008f55
	.size	ldc_irq_handler, . - ldc_irq_handler
