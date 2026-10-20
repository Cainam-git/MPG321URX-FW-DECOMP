! leon2s FUN_a0060770 @ 0xa0060770  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060770
	.type FUN_a0060770, #function
FUN_a0060770:
	st  %l4, [ %g3 + 0x30 ]
	st  %l5, [ %g3 + 0x34 ]
	st  %l6, [ %g3 + 0x38 ]
	st  %l7, [ %g3 + 0x3c ]
	.size FUN_a0060770, .-FUN_a0060770
