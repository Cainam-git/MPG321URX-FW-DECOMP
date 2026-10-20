! leon2s FUN_a0060cf0 @ 0xa0060cf0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060cf0
	.type FUN_a0060cf0, #function
FUN_a0060cf0:
	or  %o4, 0x4c, %o4
	ld  [ %o4 ], %g1
	ld  [ %o4 ], %o5
	andn  %l1, %g1, %l1
	.size FUN_a0060cf0, .-FUN_a0060cf0
