! leon2s FUN_a0060730 @ 0xa0060730  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060730
	.type FUN_a0060730, #function
FUN_a0060730:
	or  %l7, 0x360, %l7
	clr  [%l7 + 0]
	st  %g1, [ %l7 + 4 ]
	st  %g2, [ %l7 + 8 ]
	.size FUN_a0060730, .-FUN_a0060730
