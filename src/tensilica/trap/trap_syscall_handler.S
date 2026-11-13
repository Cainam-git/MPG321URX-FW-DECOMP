# trap_syscall_handler  (fn_4000a458): 0x4000a458-0x4000a4b7 (firmware file offset 0x3a458-0x3a4b7), 36 instructions
# Name basis: derived - entry 1 of cause table trap_exception_cause_table; EPC1+3 with loop fix; a2 code
#   test
# Entered without a call: by jx from the user exception vector (0x40000340), through the exception-cause
# table at trap_exception_cause_table.
# Handler of exception cause 1 (entry 1 of the cause table trap_exception_cause_table). It moves EPC1 three bytes on (past the
# instruction that raised the exception; to LBEG with LCOUNT - 1 when that lands on LEND of a running loop),
# then looks at the a2 the program had: not 0 -> return with a2 = -1 (exit .L4000a4bf in the next file);
# 0 -> it saves a3..a5 below the program's stack pointer, sets PS = 0x00050023, makes a call12 to
# trap_syscall_touch_a15 from a fresh window (entry at 0x4000a497) and comes back through a retw whose return address it
# builds as a12 + 0x80000007 = 0x4000a4a4 (see src/tensilica/README.md); there it restores PS, EPC1 and
# a3..a5 and returns from the exception with a2 = 0.
# On entry (from the vector): a1 = stack pointer - 0x100, a1+16 = program's a2, a1+20 = a3, a1+24 = a4;
#   a2 = EXCCAUSE, a3 = this handler's address.
# Returns: to the program (rfe) with a2 = 0, or a2 = -1 through .L4000a4bf.
# Address stored in the words at: 0x4000c6f8
# Calls: trap_syscall_touch_a15
# Other literal values: 0x00050023, 0x80000007
# Special registers: epc1, lend, lcount, lbeg, ps
# 8 instructions after an unconditional jump or return: no branch, jump, call or stored address leads to them.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	trap_syscall_handler, @function
trap_syscall_handler:                   # fn_4000a458
	# epc = EPC1 + 3;
	rsr.epc1	a3              # 4000a458
	rsr.lend	a2              # 4000a45b
	addi.n	a3, a3, 3               # 4000a45e
	# if (LEND == epc && LCOUNT != 0) { LCOUNT = LCOUNT - 1; epc = LBEG; }
	bne	a2, a3, .L4000a470      # 4000a460
	rsr.lcount	a2              # 4000a463
	beqz.n	a2, .L4000a470          # 4000a466
	addi.n	a2, a2, -1              # 4000a468
	wsr.lcount	a2              # 4000a46a
	rsr.lbeg	a3              # 4000a46d
.L4000a470:
	# code = saved a2; EPC1 = epc; a3 = saved a3;
	l32i.n	a2, a1, 16              # 4000a470
	wsr.epc1	a3              # 4000a472
	l32i.n	a3, a1, 20              # 4000a475
	# if (code != 0) goto .L4000a4bf;   (return a2 = -1)
	bnez	a2, .L4000a4bf          # 4000a477
	# save a3, a4, a5 at stack pointer - 28, - 24, - 20;
	s32i	a3, a1, 228             # 4000a47a
	s32i	a4, a1, 232             # 4000a47d
	s32i	a5, a1, 236             # 4000a480
	# saved_ps = PS; PS = 0x00050023; epc = EPC1; a1 = stack pointer;
	l32r	a3, lit_3ffe2344        # 4000a483  = 0x00050023
	rsr.ps	a2                      # 4000a486
	wsr.ps	a3                      # 4000a489
	rsr.epc1	a3              # 4000a48c
	addmi	a1, a1, 0x100           # 4000a48f
	rsync                           # 4000a492
	# open a window (a0 of the new window = 0) and call12 trap_syscall_touch_a15();
	movi.n	a4, 0                   # 4000a495
	entry	a1, 64                  # 4000a497
	call12	trap_syscall_touch_a15  # 4000a49a
	# return address = a12 + 0x80000007 (= 0x4000a4a4); retw to it;
	l32r	a14, lit_3ffe2348       # 4000a49d  = 0x80000007
	add.n	a0, a12, a14            # 4000a4a0
	retw.n                          # 4000a4a2
	# 0x4000a4a4: PS = saved_ps; a2 = 0; restore a4, EPC1, a3, a5; return from the exception;
	wsr.ps	a2                      # 4000a4a4
	movi.n	a2, 0                   # 4000a4a7
	l32i.n	a4, a5, 40              # 4000a4a9
	rsync                           # 4000a4ab
	wsr.epc1	a3              # 4000a4ae
	l32i.n	a3, a5, 36              # 4000a4b1
	l32i.n	a5, a5, 44              # 4000a4b3
	rfe                             # 4000a4b5
	.size	trap_syscall_handler, . - trap_syscall_handler
