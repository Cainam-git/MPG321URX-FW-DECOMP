! leon2s FUN_a0060ba0 @ 0xa0060ba0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060ba0
	.type FUN_a0060ba0, #function
FUN_a0060ba0:
	or  %o4, 0x90, %o4
	ld  [ %o4 ], %g1
	or  %g1, 0x10, %g1
	st  %g1, [ %o4 ]
	.size FUN_a0060ba0, .-FUN_a0060ba0
