! leon2s FUN_a0060b60 @ 0xa0060b60  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060b60
	.type FUN_a0060b60, #function
FUN_a0060b60:
	nop
	inc  %l2
	cmp  %l2, 6
	bleu ext_a0060b04
	.size FUN_a0060b60, .-FUN_a0060b60
