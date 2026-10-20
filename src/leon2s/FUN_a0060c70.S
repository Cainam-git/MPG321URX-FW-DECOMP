! leon2s FUN_a0060c70 @ 0xa0060c70  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060c70
	.type FUN_a0060c70, #function
FUN_a0060c70:
	bleu ext_a0060c08
	mov  1, %g1
	sethi  %hi(0x9f120000), %o5
	or  %o5, 0x34, %g1
	.size FUN_a0060c70, .-FUN_a0060c70
