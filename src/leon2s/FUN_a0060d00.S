! leon2s FUN_a0060d00 @ 0xa0060d00  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060d00
	.type FUN_a0060d00, #function
FUN_a0060d00:
	srl  %o5, 0x10, %l3
	or %g0, 0, %l2
	mov  1, %g1
	sll  %g1, %l2, %l0
	.size FUN_a0060d00, .-FUN_a0060d00
