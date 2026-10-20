! leon2s FUN_a0060a70 @ 0xa0060a70  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060a70
	.type FUN_a0060a70, #function
FUN_a0060a70:
	or  %o5, 0x28, %o4
	ld  [ %o4 ], %g1
	or  %g1, 8, %g1
	st  %g1, [ %o4 ]
	.size FUN_a0060a70, .-FUN_a0060a70
