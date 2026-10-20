! leon2s FUN_a0060740 @ 0xa0060740  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060740
	.type FUN_a0060740, #function
FUN_a0060740:
	st  %g3, [ %l7 + 0xc ]
	st  %g4, [ %l7 + 0x10 ]
	st  %g5, [ %l7 + 0x14 ]
	st  %g6, [ %l7 + 0x18 ]
	.size FUN_a0060740, .-FUN_a0060740
