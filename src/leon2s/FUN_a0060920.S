! leon2s FUN_a0060920 @ 0xa0060920  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060920
	.type FUN_a0060920, #function
FUN_a0060920:
	st  %g1, [ %o5 ]
	or  %o4, 0x70, %g1
	ld  [ %g1 ], %l1
	or  %o4, 0x38, %o4
	.size FUN_a0060920, .-FUN_a0060920
