! leon2s FUN_a0060860 @ 0xa0060860  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060860
	.type FUN_a0060860, #function
FUN_a0060860:
	call FUN_70060860
	.size FUN_a0060860, .-FUN_a0060860
