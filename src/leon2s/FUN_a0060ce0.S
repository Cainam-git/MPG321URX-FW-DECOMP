! leon2s FUN_a0060ce0 @ 0xa0060ce0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060ce0
	.type FUN_a0060ce0, #function
FUN_a0060ce0:
	or  %g1, 0x40, %g1
	st  %g1, [ %o5 ]
	or  %o4, 0x84, %g1
	ld  [ %g1 ], %l1
	.size FUN_a0060ce0, .-FUN_a0060ce0
