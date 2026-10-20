! leon2s FUN_a0060210 @ 0xa0060210  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060210
	.type FUN_a0060210, #function
FUN_a0060210:
	ta  0
	nop
	nop
	nop
	.size FUN_a0060210, .-FUN_a0060210
