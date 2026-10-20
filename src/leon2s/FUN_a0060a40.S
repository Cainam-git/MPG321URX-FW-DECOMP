! leon2s FUN_a0060a40 @ 0xa0060a40  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060a40
	.type FUN_a0060a40, #function
FUN_a0060a40:
	st  %g1, [ %o4 ]
	ld  [ %o2 ], %g1
	or  %g1, 4, %g1
	st  %g1, [ %o2 ]
	.size FUN_a0060a40, .-FUN_a0060a40
