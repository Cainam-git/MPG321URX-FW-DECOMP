# trap_break_on_other_cause  (fn_4000abcc): 0x4000abcc-0x4000abd8 (firmware file offset 0x3abcc-0x3abd8), 5 instructions
# Name basis: derived - entries 0, 2, 3 of cause table trap_exception_cause_table
# Entered without a call: by jx from the user exception vector (0x40000340), through the exception-cause
# table at trap_exception_cause_table.
# Handler of exception causes 0, 2 and 3 (entries 0, 2 and 3 of the cause table trap_exception_cause_table): restores the
# program's a2 and a3, moves the stack pointer back up by 0x100, executes BREAK 1, 1 and returns from the
# exception (rfe) to EPC1 unchanged.
# On entry (from the vector): a1 = stack pointer - 0x100, a1+16 = program's a2, a1+20 = a3.
# Returns: to the program (rfe).
# Address stored in the words at: 0x4000c6f4, 0x4000c6fc, 0x4000c700

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	trap_break_on_other_cause, @function
trap_break_on_other_cause:              # fn_4000abcc
	# restore a2, a3; a1 += 0x100;
	l32i.n	a2, a1, 16              # 4000abcc
	l32i.n	a3, a1, 20              # 4000abce
	addmi	a1, a1, 0x100           # 4000abd0
	# break(1, 1); return from the exception;
	break	1, 1                    # 4000abd3
	rfe                             # 4000abd6
	.size	trap_break_on_other_cause, . - trap_break_on_other_cause
