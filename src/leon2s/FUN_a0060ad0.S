! leon2s FUN_a0060ad0 @ 0xa0060ad0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060ad0
	.type FUN_a0060ad0, #function
FUN_a0060ad0:
	or  %o4, 0x28, %o5
	ld  [ %o5 ], %g1
	or  %g1, 0x10, %g1
	st  %g1, [ %o5 ]
	.size FUN_a0060ad0, .-FUN_a0060ad0
