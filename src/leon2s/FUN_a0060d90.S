! leon2s FUN_a0060d90 @ 0xa0060d90  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060d90
	.type FUN_a0060d90, #function
FUN_a0060d90:
	or  %o4, 0x9c, %g1
	st  %o3, [ %g1 ]
	or  %o5, 0x28, %o5
	ld  [ %o5 ], %g1
	.size FUN_a0060d90, .-FUN_a0060d90
