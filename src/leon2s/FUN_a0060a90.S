! leon2s FUN_a0060a90 @ 0xa0060a90  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060a90
	.type FUN_a0060a90, #function
FUN_a0060a90:
	st  %g1, [ %o3 ]
	ld  [ %o4 ], %g1
	and  %g1, -9, %g1
	st  %g1, [ %o4 ]
	.size FUN_a0060a90, .-FUN_a0060a90
