! leon2s FUN_a0060af0 @ 0xa0060af0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060af0
	.type FUN_a0060af0, #function
FUN_a0060af0:
	ld  [ %o4 ], %o5
	andn  %l1, %g1, %l1
	srl  %o5, 0x10, %l3
	or %g0, 0, %l2
	.size FUN_a0060af0, .-FUN_a0060af0
