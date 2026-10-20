! leon2s FUN_a0060fa0 @ 0xa0060fa0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060fa0
	.type FUN_a0060fa0, #function
FUN_a0060fa0:
	or  %o4, 0x9c, %g1
	st  %o3, [ %g1 ]
	or  %o5, 0x28, %o5
	ld  [ %o5 ], %g1
	.size FUN_a0060fa0, .-FUN_a0060fa0
