# irq_dispatch_level5  (fn_4000a74c): 0x4000a74c-0x4000a88e (firmware file offset 0x3a74c-0x3a88e), 119 instructions
# Name basis: proven - EXCSAVE5 target from reset; INTCLEAR 0x2000, table entry 8 = interrupt 13
# Entered without a call: entered from the level-5 vector (0x40000240) by jx through EXCSAVE5, which the
# reset code sets from lit_40000430.
# Runs the handler of interrupt 13 (the tick timer, see timer_start_tick), the only interrupt whose byte in
# irq_level_of_interrupt is 5. It saves the 32 address registers (window rotated four times by
# eight registers), WINDOWSTART/WINDOWBASE, EPC1, EXCCAUSE, EXCVADDR, EXCSAVE1, SAR, the loop and MAC
# registers into the save area at 0x3FFE62F0, puts its own address back into EXCSAVE5 (from irq_level5_handler_address),
# runs with WINDOWSTART = 1, WINDOWBASE = 0, PS = 0x00050025 and the save area as stack, clears interrupt 13
# (INTCLEAR 0x2000) and calls handler(arg) from irq_handler_table entry 8 (irq_handler_table +64/+68). Then it
# loads everything back, sets PS = 0x35 and returns with rfi 5.
# On entry: a2 = this handler's address (EXCSAVE5 holds the program's a2).
# Save area 0x3FFE62F0: +0 SAR, +4 WINDOWSTART, +8 WINDOWBASE, +12 EPC1, +16 EXCCAUSE, +20 EXCVADDR,
#   +24 EXCSAVE1, +32 ACCLO, +36 ACCHI, +40 LCOUNT, +44 LBEG, +48 LEND, +52..+176 registers 0..31
#   (+52 a0, +56 a1, +60 a2, +64 a3, ...).
# Returns: to the interrupted code (rfi 5).
# Address stored in the words at: 0x40000430
# Indirect calls (callx): 1
# Addresses loaded: irq_level5_handler_address, irq_handler_table
# Other literal values: 0x3ffe62f0, 0x00050025, 0x00002000
# Special registers: excsave5, epc1, exccause, excvaddr, excsave1, windowstart, windowbase, ps, sar, lcount,
#                    lbeg, lend, acclo, acchi, intclear

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	irq_dispatch_level5, @function
irq_dispatch_level5:                    # fn_4000a74c
	# save = 0x3FFE62F0; save.a0 = a0; save.a1 = a1; save.a3 = a3; save.a4 = a4;
	# save.a2 = EXCSAVE5 (program's a2); EXCSAVE5 = irq_level5_handler_address (this handler);
	l32r	a2, lit_3ffe2370        # 4000a74c  = 0x3ffe62f0
	s32i.n	a0, a2, 52              # 4000a74f
	l32r	a0, lit_3ffe2374        # 4000a751  = irq_level5_handler_address
	s32i.n	a1, a2, 56              # 4000a754
	l32i.n	a0, a0, 0               # 4000a756
	s32i	a3, a2, 64              # 4000a758
	xsr.excsave5	a0              # 4000a75b
	s32i	a4, a2, 68              # 4000a75e
	s32i.n	a0, a2, 60              # 4000a761
	# save.epc1 = EPC1; save.exccause = EXCCAUSE; save.excvaddr = EXCVADDR; save.excsave1 = EXCSAVE1;
	rsr.epc1	a3              # 4000a763
	rsr.exccause	a4              # 4000a766
	s32i.n	a3, a2, 12              # 4000a769
	s32i.n	a4, a2, 16              # 4000a76b
	rsr.excvaddr	a3              # 4000a76d
	s32i.n	a3, a2, 20              # 4000a770
	rsr.excsave1	a4              # 4000a772
	s32i	a4, a2, 24              # 4000a775
	# save a5..a7; then for (left = 24; ; ) { save a8..a15; rotate the window by 8 registers; }
	movi	a0, 24                  # 4000a778
	s32i	a5, a2, 72              # 4000a77b
	s32i	a6, a2, 76              # 4000a77e
	s32i	a7, a2, 80              # 4000a781
.L4000a784:
	s32i	a8, a2, 84              # 4000a784
	s32i	a9, a2, 88              # 4000a787
	s32i	a10, a2, 92             # 4000a78a
	s32i	a11, a2, 96             # 4000a78d
	s32i	a12, a2, 100            # 4000a790
	s32i	a13, a2, 104            # 4000a793
	s32i	a14, a2, 108            # 4000a796
	s32i	a15, a2, 112            # 4000a799
	addi	a8, a0, -8              # 4000a79c
	addi	a10, a2, 32             # 4000a79f
	rotw	2                       # 4000a7a2
	# (loop while the rotated left count != 0)
	bnez	a0, .L4000a784          # 4000a7a5
	rotw	2                       # 4000a7a8
	# save.windowstart = WINDOWSTART; save.windowbase = WINDOWBASE; WINDOWSTART = 1; WINDOWBASE = 0;
	rsr.windowstart	a3              # 4000a7ab
	rsr.windowbase	a4              # 4000a7ae
	s32i.n	a3, a2, 4               # 4000a7b1
	s32i.n	a4, a2, 8               # 4000a7b3
	movi.n	a3, 1                   # 4000a7b5
	movi.n	a4, 0                   # 4000a7b7
	wsr.windowstart	a3              # 4000a7b9
	wsr.windowbase	a4              # 4000a7bc
	rsync                           # 4000a7bf
	# a1 = save area; a0 = 0; PS = 0x00050025;
	l32r	a1, lit_3ffe2370        # 4000a7c2  = 0x3ffe62f0
	movi.n	a0, 0                   # 4000a7c5
	l32r	a2, lit_3ffe2378        # 4000a7c7  = 0x00050025
	wsr.ps	a2                      # 4000a7ca
	rsync                           # 4000a7cd
	# save.sar/lcount/lbeg/lend/acclo/acchi = SAR/LCOUNT/LBEG/LEND/ACCLO/ACCHI;
	rsr.sar	a14                     # 4000a7d0
	s32i.n	a14, a1, 0              # 4000a7d3
	rsr.lcount	a14             # 4000a7d5
	s32i.n	a14, a1, 40             # 4000a7d8
	rsr.lbeg	a14             # 4000a7da
	s32i.n	a14, a1, 44             # 4000a7dd
	rsr.lend	a14             # 4000a7df
	s32i.n	a14, a1, 48             # 4000a7e2
	rsr.acclo	a14             # 4000a7e4
	s32i.n	a14, a1, 32             # 4000a7e7
	rsr.acchi	a14             # 4000a7e9
	s32i	a14, a1, 36             # 4000a7ec
	# INTCLEAR = 0x2000;   (interrupt 13)
	l32r	a13, lit_3ffe1fa8       # 4000a7ef  = 0x00002000
	l32r	a12, lit_3ffe2350       # 4000a7f2  = irq_handler_table
	wsr.intclear	a13             # 4000a7f5
	# irq_handler_table[8].handler(irq_handler_table[8].arg);   (entry of interrupt 13)
	l32i	a13, a12, 64            # 4000a7f8
	l32i	a6, a12, 68             # 4000a7fb
	callx4	a13                     # 4000a7fe
	# LCOUNT/LBEG/LEND/ACCLO/ACCHI/SAR = saved values; PS = 0x35;
	l32i.n	a13, a1, 40             # 4000a801
	l32i.n	a14, a1, 44             # 4000a803
	l32i.n	a15, a1, 48             # 4000a805
	wsr.lcount	a13             # 4000a807
	wsr.lbeg	a14             # 4000a80a
	wsr.lend	a15             # 4000a80d
	l32i.n	a13, a1, 32             # 4000a810
	l32i.n	a14, a1, 36             # 4000a812
	wsr.acclo	a13             # 4000a814
	wsr.acchi	a14             # 4000a817
	l32i.n	a15, a1, 0              # 4000a81a
	wsr.sar	a15                     # 4000a81c
	movi.n	a2, 53                  # 4000a81f
	wsr.ps	a2                      # 4000a821
	rsync                           # 4000a824
	# WINDOWSTART = save.windowstart; WINDOWBASE = save.windowbase;
	l32i.n	a2, a1, 4               # 4000a827
	l32i.n	a3, a1, 8               # 4000a829
	wsr.windowstart	a2              # 4000a82b
	wsr.windowbase	a3              # 4000a82e
	rsync                           # 4000a831
	# reload registers 4..27 in groups of eight, rotating the window by 8 registers each time;
	l32r	a1, lit_3ffe2370        # 4000a834  = 0x3ffe62f0
	movi.n	a6, 24                  # 4000a837
	addi	a7, a1, -32             # 4000a839
.L4000a83c:
	addi	a14, a6, -8             # 4000a83c
	addi	a15, a7, 32             # 4000a83f
	l32i	a4, a15, 68             # 4000a842
	l32i	a5, a15, 72             # 4000a845
	l32i	a6, a15, 76             # 4000a848
	l32i	a7, a15, 80             # 4000a84b
	l32i	a8, a15, 84             # 4000a84e
	l32i	a9, a15, 88             # 4000a851
	l32i	a10, a15, 92            # 4000a854
	l32i	a11, a15, 96            # 4000a857
	rotw	2                       # 4000a85a
	bnez	a6, .L4000a83c          # 4000a85d
	# reload registers 28..31; rotate back to the program's window;
	l32i	a4, a7, 100             # 4000a860
	l32i	a5, a7, 104             # 4000a863
	l32i	a6, a7, 108             # 4000a866
	l32i	a7, a7, 112             # 4000a869
	rotw	2                       # 4000a86c
	# EPC1/EXCCAUSE/EXCVADDR/EXCSAVE1 = saved values; reload a0, a2, a3, a1; return (rfi 5);
	l32i.n	a2, a1, 12              # 4000a86f
	l32i.n	a3, a1, 16              # 4000a871
	wsr.epc1	a2              # 4000a873
	wsr.exccause	a3              # 4000a876
	l32i.n	a2, a1, 20              # 4000a879
	wsr.excvaddr	a2              # 4000a87b
	l32i.n	a3, a1, 24              # 4000a87e
	wsr.excsave1	a3              # 4000a880
	l32i.n	a0, a1, 52              # 4000a883
	l32i.n	a2, a1, 60              # 4000a885
	l32i	a3, a1, 64              # 4000a887
	l32i.n	a1, a1, 56              # 4000a88a
	rfi	5                       # 4000a88c
	.size	irq_dispatch_level5, . - irq_dispatch_level5
