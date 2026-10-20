! leon2s FUN_a0060590 @ 0xa0060590  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060590
	.type FUN_a0060590, #function
FUN_a0060590:
	rd  %wim, %l3
	sll  %l3, 1, %l4
	srl  %l3, 0xf, %l5
	or  %l5, %l4, %l5
	.size FUN_a0060590, .-FUN_a0060590
