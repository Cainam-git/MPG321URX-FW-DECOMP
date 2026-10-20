! leon2s FUN_a0060df0 @ 0xa0060df0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060df0
	.type FUN_a0060df0, #function
FUN_a0060df0:
	st  %g1, [ %o5 ]
	or  %o3, 0x9c, %o3
	st  %g1, [ %o3 ]
	ld  [ %o4 ], %g1
	.size FUN_a0060df0, .-FUN_a0060df0
