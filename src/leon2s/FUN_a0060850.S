! leon2s FUN_a0060850 @ 0xa0060850  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060850
	.type FUN_a0060850, #function
FUN_a0060850:
	rett  %l2
	.size FUN_a0060850, .-FUN_a0060850
