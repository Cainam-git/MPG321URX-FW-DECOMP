! leon2s FUN_a0060d20 @ 0xa0060d20  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060d20
	.type FUN_a0060d20, #function
FUN_a0060d20:
	or  %g1, 0x388, %g1
	ld  [ %g1 + %o5 ], %o5
	cmp  %o5, 0
	be,a ext_a0060d70
	.size FUN_a0060d20, .-FUN_a0060d20
