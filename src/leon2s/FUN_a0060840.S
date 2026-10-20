! leon2s FUN_a0060840 @ 0xa0060840  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060840
	.type FUN_a0060840, #function
FUN_a0060840:
	nop
	nop
	nop
	.size FUN_a0060840, .-FUN_a0060840
