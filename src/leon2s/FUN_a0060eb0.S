! leon2s FUN_a0060eb0 @ 0xa0060eb0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060eb0
	.type FUN_a0060eb0, #function
FUN_a0060eb0:
	st  %g1, [ %o3 ]
	ld  [ %o4 ], %g1
	and  %g1, -513, %g1
	st  %g1, [ %o4 ]
	.size FUN_a0060eb0, .-FUN_a0060eb0
