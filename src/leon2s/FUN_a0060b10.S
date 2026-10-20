! leon2s FUN_a0060b10 @ 0xa0060b10  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060b10
	.type FUN_a0060b10, #function
FUN_a0060b10:
	sll  %l2, 2, %o5
	sethi  %hi(0xa8078400), %g1
	or  %g1, 0x3a8, %g1
	ld  [ %g1 + %o5 ], %o5
	.size FUN_a0060b10, .-FUN_a0060b10
