! leon2s FUN_a0060700 @ 0xa0060700  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060700
	.type FUN_a0060700, #function
FUN_a0060700:
	andn  %l4, 0xf00, %l4
	sll  %i0, 8, %i0
	and  %i0, 0xf00, %i0
	or  %i0, %l4, %l4
	.size FUN_a0060700, .-FUN_a0060700
