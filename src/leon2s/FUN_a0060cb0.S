! leon2s FUN_a0060cb0 @ 0xa0060cb0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060cb0
	.type FUN_a0060cb0, #function
FUN_a0060cb0:
	st  %g1, [ %o4 ]
	ret
	restore
	.size FUN_a0060cb0, .-FUN_a0060cb0
