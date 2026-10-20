! leon2s FUN_a0060aa0 @ 0xa0060aa0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060aa0
	.type FUN_a0060aa0, #function
FUN_a0060aa0:
	ld  [ %o2 ], %g1
	or  %g1, 8, %g1
	st  %g1, [ %o2 ]
	retl
	.size FUN_a0060aa0, .-FUN_a0060aa0
