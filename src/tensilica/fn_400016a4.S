# fn_400016a4: 0x400016a4-0x400016d0 (firmware file offset 0x316a4-0x316d0), 18 instructions
# Address stored in the words at: 0x4000d334
# Calls: fn_400099bc
# Text loaded: "MAILBOX_DPLL INIT DONE!!\n", "MAILBOX_DPLL NOT INIT!!\n"
# Addresses loaded: data_3ffe2764

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400016a4, @function
fn_400016a4:
	entry	a1, 48                  # 400016a4
	s32i.n	a2, a1, 0               # 400016a7
	s32i.n	a3, a1, 4               # 400016a9
	l32i.n	a6, a1, 4               # 400016ab
	movi.n	a5, 0                   # 400016ad
	bgeu	a5, a6, .L400016c2      # 400016af
	l32r	a8, lit_3ffe1b34        # 400016b2  = data_3ffe2764
	movi.n	a7, 1                   # 400016b5
	s32i.n	a7, a8, 0               # 400016b7
	l32r	a10, lit_3ffe1b38       # 400016b9  = ro_3ffe017c "MAILBOX_DPLL INIT DONE!!\n"
	call8	fn_400099bc             # 400016bc
	j	.L400016cf              # 400016bf
.L400016c2:
	l32r	a10, lit_3ffe1b34       # 400016c2  = data_3ffe2764
	movi.n	a9, 0                   # 400016c5
	s32i.n	a9, a10, 0              # 400016c7
	l32r	a10, lit_3ffe1b3c       # 400016c9  = ro_3ffe0198 "MAILBOX_DPLL NOT INIT!!\n"
	call8	fn_400099bc             # 400016cc
.L400016cf:
	retw.n                          # 400016cf
	.size	fn_400016a4, . - fn_400016a4
