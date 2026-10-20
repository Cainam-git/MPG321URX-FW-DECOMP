! leon2s FUN_a0060910 @ 0xa0060910  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060910
	.type FUN_a0060910, #function
FUN_a0060910:
	sethi  %hi(0x9f120000), %o4
	or  %o4, 0x28, %o5
	ld  [ %o5 ], %g1
	or  %g1, 2, %g1
	.size FUN_a0060910, .-FUN_a0060910
