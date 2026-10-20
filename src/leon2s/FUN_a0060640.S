! leon2s FUN_a0060640 @ 0xa0060640  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060640
	.type FUN_a0060640, #function
FUN_a0060640:
	jmp  %l2
	.size FUN_a0060640, .-FUN_a0060640
