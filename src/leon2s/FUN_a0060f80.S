! leon2s FUN_a0060f80 @ 0xa0060f80  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060f80
	.type FUN_a0060f80, #function
FUN_a0060f80:
	cmp  %l2, 1
	bleu ext_a0060f24
	mov  1, %g1
	sethi  %hi(0x9f120000), %o5
	.size FUN_a0060f80, .-FUN_a0060f80
