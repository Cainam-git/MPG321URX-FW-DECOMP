# irq_dispatch_level3  (fn_4000a680): 0x4000a680-0x4000a74a (firmware file offset 0x3a680-0x3a74a), 74 instructions
# Name basis: proven - EXCSAVE3 target from reset; mask 0x00200E00 = level-3 bytes in irq_level_of_interrupt
# Entered without a call: entered from the level-3 vector (0x400001c0) by jx through EXCSAVE3, which the
# reset code sets from lit_40000424.
# Runs the handlers of the pending interrupts among 9, 10, 11 and 21 (mask 0x00200E00; the interrupts whose
# byte in irq_level_of_interrupt is 3). It puts its own address back into EXCSAVE3, saves a2, a4,
# a5 below the program's stack pointer, opens a window of 0x100 bytes (from 0x4000a6a4), and while
# INTERRUPT & INTENABLE & 0x00200E00 is not 0 it takes the lowest set bit n, clears it (INTCLEAR) and calls
# the handler of n from irq_handler_table (entry at +8 * (21 - n)) as handler(arg, frame), with SAR,
# LCOUNT/LBEG/LEND and ACCLO/ACCHI kept. It leaves through .L4000a742: restore a2, a4, a5, rfi 3.
# On entry: a2 = this handler's address (EXCSAVE3 holds the program's a2).
# Frame of the opened window: a1+8 SAR, a1+36 LCOUNT, a1+40 LBEG, a1+44 LEND, a1+48 ACCLO, a1+52 ACCHI.
#   Below the program's stack pointer: -0xF0 a2, -0xE8 a4, -0xE4 a5.
# Returns: to the interrupted code (rfi 3).
# Address stored in the words at: 0x40000424
# Indirect calls (callx): 1
# Addresses loaded: irq_handler_table, .L4000a742
# Other literal values: 0x00050023, 0xc0000000, 0x00200e00
# Special registers: excsave3, ps, epc3, interrupt, intenable, sar, lcount, lbeg, lend, acclo, acchi, intclear

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_dispatch_level3, @function
irq_dispatch_level3:                    # fn_4000a680
	# swap a2 and EXCSAVE3 (a2 = program's a2, EXCSAVE3 = this handler again); save a2, a4, a5;
	xsr.excsave3	a2              # 4000a680
	addmi	a1, a1, 0xffffff00      # 4000a683
	s32i.n	a2, a1, 16              # 4000a686
	l32r	a2, lit_3ffe2344        # 4000a688  = 0x00050023
	s32i.n	a4, a1, 24              # 4000a68b
	s32i.n	a5, a1, 28              # 4000a68d
	# PS = 0x00050023; a1 = stack pointer;
	wsr.ps	a2                      # 4000a68f
	rsync                           # 4000a692
	addmi	a1, a1, 0x100           # 4000a695
	# a4 = (EPC3 | 0xC0000000) + 0x80000000;   (a0 of the window opened next)
	rsr.epc3	a4              # 4000a698
	l32r	a5, lit_3ffe1f78        # 4000a69b  = 0xc0000000
	or	a4, a5, a4              # 4000a69e
	addx2	a4, a5, a4              # 4000a6a1
	# open a window with a 0x100-byte frame; RSIL(3);
	entry	a1, 0x100               # 4000a6a4
	rsil	a15, 3                  # 4000a6a7
	# pending = INTERRUPT & INTENABLE & 0x00200E00; sar = SAR;
	rsr.interrupt	a15             # 4000a6aa
	rsr.intenable	a12             # 4000a6ad
	l32r	a13, lit_3ffe2368       # 4000a6b0  = 0x00200e00
	and	a15, a15, a12           # 4000a6b3
	and	a15, a15, a13           # 4000a6b6
	rsr.sar	a14                     # 4000a6b9
	# if (pending == 0) goto exit;
	beqz	a15, .L4000a731         # 4000a6bc
	# frame.sar = sar; frame.lcount/lbeg/lend/acclo/acchi = LCOUNT/LBEG/LEND/ACCLO/ACCHI;
	s32i.n	a14, a1, 8              # 4000a6bf
	rsr.lcount	a13             # 4000a6c1
	rsr.lbeg	a14             # 4000a6c4
	s32i.n	a13, a1, 36             # 4000a6c7
	rsr.lend	a13             # 4000a6c9
	s32i.n	a14, a1, 40             # 4000a6cc
	s32i	a13, a1, 44             # 4000a6ce
	rsr.acclo	a13             # 4000a6d1
	rsr.acchi	a14             # 4000a6d4
	s32i	a13, a1, 48             # 4000a6d7
	s32i.n	a14, a1, 52             # 4000a6da
.L4000a6dc:
	# do { bit = pending & -pending; INTCLEAR = bit; n = 31 - nsau(bit);
	neg	a12, a15                # 4000a6dc
	and	a12, a12, a15           # 4000a6df
	wsr.intclear	a12             # 4000a6e2
	l32r	a13, lit_3ffe2350       # 4000a6e5  = irq_handler_table
	movi.n	a14, 31                 # 4000a6e8
	nsau	a12, a12                # 4000a6ea
	sub	a15, a14, a12           # 4000a6ed
	#   e = &irq_handler_table[21 - n]; e->handler(e->arg, frame);
	neg	a15, a15                # 4000a6f0
	addi	a15, a15, 21            # 4000a6f3
	addx8	a12, a15, a13           # 4000a6f6
	l32i	a13, a12, 0             # 4000a6f9
	l32i.n	a14, a12, 4             # 4000a6fc
	or	a15, a1, a1             # 4000a6fe
	callx12	a13                     # 4000a701
	#   pending = INTERRUPT & INTENABLE & 0x00200E00;
	rsr.interrupt	a15             # 4000a704
	rsr.intenable	a12             # 4000a707
	l32r	a13, lit_3ffe2368       # 4000a70a  = 0x00200e00
	and	a15, a15, a12           # 4000a70d
	and	a15, a15, a13           # 4000a710
	# } while (pending != 0);
	bnez	a15, .L4000a6dc         # 4000a713
	# LCOUNT/LBEG/LEND/ACCLO/ACCHI = frame values; sar = frame.sar;
	l32i.n	a13, a1, 36             # 4000a716
	l32i.n	a14, a1, 40             # 4000a718
	l32i.n	a15, a1, 44             # 4000a71a
	wsr.lcount	a13             # 4000a71c
	wsr.lbeg	a14             # 4000a71f
	wsr.lend	a15             # 4000a722
	l32i.n	a13, a1, 48             # 4000a725
	l32i.n	a14, a1, 52             # 4000a727
	wsr.acclo	a13             # 4000a729
	wsr.acchi	a14             # 4000a72c
	l32i.n	a14, a1, 8              # 4000a72f
.L4000a731:
	# exit: return address = (.L4000a742 | 0xC0000000) + 0x80000000; SAR = sar; retw;
	l32r	a0, lit_3ffe236c        # 4000a731  = .L4000a742
	l32r	a13, lit_3ffe1f78       # 4000a734  = 0xc0000000
	wsr.sar	a14                     # 4000a737
	or	a0, a0, a13             # 4000a73a
	addx2	a0, a13, a0             # 4000a73d
	retw.n                          # 4000a740
.L4000a742:
	# restore a2, a4, a5; return from the level-3 interrupt;
	l32i.n	a2, a5, 16              # 4000a742
	l32i.n	a4, a5, 24              # 4000a744
	l32i.n	a5, a5, 28              # 4000a746
	rfi	3                       # 4000a748
	.size	irq_dispatch_level3, . - irq_dispatch_level3
