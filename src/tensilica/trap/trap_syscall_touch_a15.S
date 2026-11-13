# trap_syscall_touch_a15  (fn_4000a4b8): 0x4000a4b8-0x4000a4c6 (firmware file offset 0x3a4b8-0x3a4c6), 6 instructions
# Name basis: descriptive - call12 target of trap_syscall_handler; .L4000a4bf rfe exit
# Called from: trap_syscall_handler
# Called with call12 by trap_syscall_handler: opens a window, writes a15 to itself and returns.
# The same file holds .L4000a4bf, the other exit of trap_syscall_handler: a2 = -1, stack pointer back up by 0x100,
# return from the exception.
# No arguments, no locals.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	trap_syscall_touch_a15, @function
trap_syscall_touch_a15:                 # fn_4000a4b8
	entry	a1, 48                  # 4000a4b8
	# a15 = a15;
	mov.n	a15, a15                # 4000a4bb
	retw.n                          # 4000a4bd
.L4000a4bf:
	# exit of trap_syscall_handler for code != 0: a2 = -1; a1 += 0x100; return from the exception;
	movi.n	a2, -1                  # 4000a4bf
	addmi	a1, a1, 0x100           # 4000a4c1
	rfe                             # 4000a4c4
	.size	trap_syscall_touch_a15, . - trap_syscall_touch_a15
