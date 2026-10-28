# fn_4000a458: 0x4000a458-0x4000a4b7 (firmware file offset 0x3a458-0x3a4b7), 36 instructions
# Entered without a call: by jx from the user exception vector (0x40000340), through the exception-cause
# table at ro_3ffe19fc.
# Address stored in the words at: 0x4000c6f8
# Calls: fn_4000a4b8
# Other literal values: 0x00050023, 0x80000007
# Special registers: epc1, lend, lcount, lbeg, ps
# 8 instructions after an unconditional jump or return: no branch, jump, call or stored address leads to them.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a458, @function
fn_4000a458:
	rsr.epc1	a3              # 4000a458
	rsr.lend	a2              # 4000a45b
	addi.n	a3, a3, 3               # 4000a45e
	bne	a2, a3, .L4000a470      # 4000a460
	rsr.lcount	a2              # 4000a463
	beqz.n	a2, .L4000a470          # 4000a466
	addi.n	a2, a2, -1              # 4000a468
	wsr.lcount	a2              # 4000a46a
	rsr.lbeg	a3              # 4000a46d
.L4000a470:
	l32i.n	a2, a1, 16              # 4000a470
	wsr.epc1	a3              # 4000a472
	l32i.n	a3, a1, 20              # 4000a475
	bnez	a2, .L4000a4bf          # 4000a477
	s32i	a3, a1, 228             # 4000a47a
	s32i	a4, a1, 232             # 4000a47d
	s32i	a5, a1, 236             # 4000a480
	l32r	a3, lit_3ffe2344        # 4000a483  = 0x00050023
	rsr.ps	a2                      # 4000a486
	wsr.ps	a3                      # 4000a489
	rsr.epc1	a3              # 4000a48c
	addmi	a1, a1, 0x100           # 4000a48f
	rsync                           # 4000a492
	movi.n	a4, 0                   # 4000a495
	entry	a1, 64                  # 4000a497
	call12	fn_4000a4b8             # 4000a49a
	l32r	a14, lit_3ffe2348       # 4000a49d  = 0x80000007
	add.n	a0, a12, a14            # 4000a4a0
	retw.n                          # 4000a4a2
	wsr.ps	a2                      # 4000a4a4
	movi.n	a2, 0                   # 4000a4a7
	l32i.n	a4, a5, 40              # 4000a4a9
	rsync                           # 4000a4ab
	wsr.epc1	a3              # 4000a4ae
	l32i.n	a3, a5, 36              # 4000a4b1
	l32i.n	a5, a5, 44              # 4000a4b3
	rfe                             # 4000a4b5
	.size	fn_4000a458, . - fn_4000a458
