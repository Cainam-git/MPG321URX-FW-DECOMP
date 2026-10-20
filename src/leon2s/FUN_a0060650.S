! leon2s FUN_a0060650 @ 0xa0060650  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060650
	.type FUN_a0060650, #function
FUN_a0060650:
	rett  %l2 + 4
	nop
	.size FUN_a0060650, .-FUN_a0060650
