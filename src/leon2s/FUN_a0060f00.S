! leon2s FUN_a0060f00 @ 0xa0060f00  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060f00
	.type FUN_a0060f00, #function
FUN_a0060f00:
	or  %o4, 0x94, %g1
	ld  [ %g1 ], %l1
	or  %o4, 0x5c, %o4
	ld  [ %o4 ], %g1
	.size FUN_a0060f00, .-FUN_a0060f00
