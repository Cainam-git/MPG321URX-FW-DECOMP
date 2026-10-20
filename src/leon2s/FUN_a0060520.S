! leon2s FUN_a0060520 @ 0xa0060520  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060520
	.type FUN_a0060520, #function
FUN_a0060520:
	jmp  %l1
	.size FUN_a0060520, .-FUN_a0060520
