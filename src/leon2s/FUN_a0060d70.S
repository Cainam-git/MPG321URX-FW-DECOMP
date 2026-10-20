! leon2s FUN_a0060d70 @ 0xa0060d70  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060d70
	.type FUN_a0060d70, #function
FUN_a0060d70:
	cmp  %l2, 4
	bleu ext_a0060d0c
	mov  1, %g1
	sethi  %hi(0x9f120000), %o5
	.size FUN_a0060d70, .-FUN_a0060d70
