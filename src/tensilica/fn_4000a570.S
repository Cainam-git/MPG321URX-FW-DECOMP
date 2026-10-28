# fn_4000a570: 0x4000a570-0x4000a67f (firmware file offset 0x3a570-0x3a67f), 100 instructions
# Entered without a call: by jx from the user exception vector (0x40000340), through the exception-cause
# table at ro_3ffe19fc.
# Address stored in the words at: 0x4000c704
# Indirect calls (callx): 1
# Addresses loaded: data_3ffe2a78, data_3ffe2a30, .L4000abb4
# Other literal values: 0x00050023, 0xc0000000, 0x80000000
# Special registers: epc1, ps, interrupt, intenable, sar, intclear, lcount, lbeg, lend, acclo, acchi

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a570, @function
fn_4000a570:
	s32i.n	a5, a1, 28              # 4000a570
	l32r	a2, lit_3ffe2344        # 4000a572  = 0x00050023
	rsr.epc1	a3              # 4000a575
	xsr.ps	a2                      # 4000a578
	s32i.n	a3, a1, 0               # 4000a57b
	s32i.n	a2, a1, 4               # 4000a57d
	addmi	a1, a1, 0x100           # 4000a57f
	rsync                           # 4000a582
	l32r	a4, lit_3ffe1f78        # 4000a585  = 0xc0000000
	or	a3, a4, a3              # 4000a588
	addx2	a4, a4, a3              # 4000a58b
	entry	a1, 0x100               # 4000a58e
	rsil	a15, 1                  # 4000a591
	l32r	a14, lit_3ffe2358       # 4000a594  = data_3ffe2a78
	rsr.interrupt	a15             # 4000a597
	rsr.intenable	a12             # 4000a59a
	l32i.n	a13, a14, 4             # 4000a59d
	and	a15, a15, a12           # 4000a59f
	rsr.sar	a12                     # 4000a5a2
	s32i.n	a13, a1, 12             # 4000a5a5
	beqz	a15, .L4000a63c         # 4000a5a7
	s32i.n	a12, a1, 8              # 4000a5aa
	s32i.n	a2, a1, 32              # 4000a5ac
	movi	a2, -1                  # 4000a5ae
.L4000a5b1:
	nsau	a12, a15                # 4000a5b1
	l32r	a15, lit_3ffe235c       # 4000a5b4  = 0x80000000
	ssr	a12                     # 4000a5b7
	srl	a15, a15                # 4000a5ba
	xor	a2, a2, a15             # 4000a5bd
	l32r	a13, lit_3ffe2360       # 4000a5c0  = data_3ffe2a30
	wsr.intclear	a15             # 4000a5c3
	addx8	a12, a12, a13           # 4000a5c6
.L4000a5c9:
	l32i	a13, a12, 176           # 4000a5c9
	rsil	a15, 6                  # 4000a5cc
	l32i.n	a15, a14, 0             # 4000a5cf
	s32i.n	a13, a14, 4             # 4000a5d1
	and	a15, a15, a13           # 4000a5d3
	wsr.intenable	a15             # 4000a5d6
	rsync                           # 4000a5d9
	rsil	a15, 0                  # 4000a5dc
	rsr.lcount	a13             # 4000a5df
	rsr.lbeg	a15             # 4000a5e2
	s32i.n	a13, a1, 36             # 4000a5e5
	rsr.lend	a13             # 4000a5e7
	s32i.n	a15, a1, 40             # 4000a5ea
	s32i.n	a13, a1, 44             # 4000a5ec
	rsr.acclo	a13             # 4000a5ee
	rsr.acchi	a15             # 4000a5f1
	s32i.n	a13, a1, 48             # 4000a5f4
	s32i.n	a15, a1, 52             # 4000a5f6
	l32i.n	a13, a12, 0             # 4000a5f8
	mov.n	a15, a1                 # 4000a5fa
	l32i.n	a14, a12, 4             # 4000a5fc
	callx12	a13                     # 4000a5fe
	l32i.n	a13, a1, 36             # 4000a601
	l32i.n	a14, a1, 40             # 4000a603
	l32i.n	a15, a1, 44             # 4000a605
	wsr.lcount	a13             # 4000a607
	wsr.lbeg	a14             # 4000a60a
	wsr.lend	a15             # 4000a60d
	l32i.n	a13, a1, 48             # 4000a610
	l32i.n	a14, a1, 52             # 4000a612
	wsr.acclo	a13             # 4000a614
	wsr.acchi	a14             # 4000a617
	l32r	a14, lit_3ffe2358       # 4000a61a  = data_3ffe2a78
	rsr.interrupt	a15             # 4000a61d
	rsil	a13, 6                  # 4000a620
	l32i.n	a13, a14, 0             # 4000a623
	l32i.n	a12, a1, 12             # 4000a625
	and	a13, a13, a12           # 4000a627
	and	a15, a15, a13           # 4000a62a
	bnez	a15, .L4000a650         # 4000a62d
	l32i.n	a2, a1, 32              # 4000a630
	s32i.n	a12, a14, 4             # 4000a632
	l32i.n	a12, a1, 8              # 4000a634
	wsr.intenable	a13             # 4000a636
	rsil	a13, 3                  # 4000a639
.L4000a63c:
	l32r	a0, lit_3ffe2364        # 4000a63c  = .L4000abb4
	l32r	a13, lit_3ffe1f78       # 4000a63f  = 0xc0000000
	wsr.sar	a12                     # 4000a642
	or	a0, a0, a13             # 4000a645
	addx2	a0, a13, a0             # 4000a648
	rsil	a13, 3                  # 4000a64b
	retw.n                          # 4000a64e
.L4000a650:
	nsau	a13, a15                # 4000a650
	l32r	a12, lit_3ffe2360       # 4000a653  = data_3ffe2a30
	addx8	a12, a13, a12           # 4000a656
	l32i	a14, a12, 180           # 4000a659
	and	a15, a15, a2            # 4000a65c
	and	a15, a15, a14           # 4000a65f
	l32r	a14, lit_3ffe2358       # 4000a662  = data_3ffe2a78
	bnez	a15, .L4000a5b1         # 4000a665
	l32r	a15, lit_3ffe235c       # 4000a668  = 0x80000000
	ssr	a13                     # 4000a66b
	srl	a13, a15                # 4000a66e
	l32i	a15, a12, 180           # 4000a671
	wsr.intclear	a13             # 4000a674
	or	a2, a2, a15             # 4000a677
	xor	a2, a2, a13             # 4000a67a
	j	.L4000a5c9              # 4000a67d
	.size	fn_4000a570, . - fn_4000a570
