! leon2s FUN_a0060f10 @ 0xa0060f10  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060f10
	.type FUN_a0060f10, #function
FUN_a0060f10:
	ld  [ %o4 ], %o5
	andn  %l1, %g1, %l1
	srl  %o5, 0x10, %l3
	or %g0, 0, %l2
	.size FUN_a0060f10, .-FUN_a0060f10
