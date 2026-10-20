! leon2s FUN_a0060260 @ 0xa0060260  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060260
	.type FUN_a0060260, #function
FUN_a0060260:
	ta  0
	nop
	nop
	nop
	.size FUN_a0060260, .-FUN_a0060260
