! leon2s FUN_a0060ae0 @ 0xa0060ae0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060ae0
	.type FUN_a0060ae0, #function
FUN_a0060ae0:
	or  %o4, 0x7c, %g1
	ld  [ %g1 ], %l1
	or  %o4, 0x44, %o4
	ld  [ %o4 ], %g1
	.size FUN_a0060ae0, .-FUN_a0060ae0
