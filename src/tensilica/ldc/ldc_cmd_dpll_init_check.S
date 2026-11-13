# ldc_cmd_dpll_init_check  (fn_400016a4): 0x400016a4-0x400016d0 (firmware file offset 0x316a4-0x316d0), 18 instructions
# Name basis: proven - prints 'MAILBOX_DPLL INIT DONE!!' / 'NOT INIT!!'; docs/MAP.md command 0x40
# Address stored in the words at: 0x4000d334
# Calls: dbg_printf
# Text loaded: "MAILBOX_DPLL INIT DONE!!\n", "MAILBOX_DPLL NOT INIT!!\n"
# Addresses loaded: ldc_dpll_init_done
#
# Command 0x40 (sent by ldc_send_dpll_init_check). A value above 0 sets the flag ldc_dpll_init_done to 1 and prints
# "MAILBOX_DPLL INIT DONE!!"; value 0 clears the flag and prints "MAILBOX_DPLL NOT INIT!!". The per-frame pass
# ldc_run_pass_on_new_frame does nothing while the flag is 0.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_dpll_init_check, @function
ldc_cmd_dpll_init_check:                # fn_400016a4
	entry	a1, 48                  # 400016a4
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 400016a7
	s32i.n	a3, a1, 4               # 400016a9
	# if (value > 0)
	l32i.n	a6, a1, 4               # 400016ab
	movi.n	a5, 0                   # 400016ad
	bgeu	a5, a6, .L400016c2      # 400016af
	# dpll_init_done = 1   (ldc_dpll_init_done)
	l32r	a8, lit_3ffe1b34        # 400016b2  = ldc_dpll_init_done
	movi.n	a7, 1                   # 400016b5
	s32i.n	a7, a8, 0               # 400016b7
	# printf("MAILBOX_DPLL INIT DONE!!\n")
	l32r	a10, lit_3ffe1b38       # 400016b9  = ro_3ffe017c "MAILBOX_DPLL INIT DONE!!\n"
	call8	dbg_printf              # 400016bc
	j	.L400016cf              # 400016bf
.L400016c2:
	# else { dpll_init_done = 0; printf("MAILBOX_DPLL NOT INIT!!\n"); }
	l32r	a10, lit_3ffe1b34       # 400016c2  = ldc_dpll_init_done
	movi.n	a9, 0                   # 400016c5
	s32i.n	a9, a10, 0              # 400016c7
	l32r	a10, lit_3ffe1b3c       # 400016c9  = ro_3ffe0198 "MAILBOX_DPLL NOT INIT!!\n"
	call8	dbg_printf              # 400016cc
.L400016cf:
	retw.n                          # 400016cf
	.size	ldc_cmd_dpll_init_check, . - ldc_cmd_dpll_init_check
