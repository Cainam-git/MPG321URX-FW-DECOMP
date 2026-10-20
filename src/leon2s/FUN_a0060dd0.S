! leon2s FUN_a0060dd0 @ 0xa0060dd0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060dd0
	.type FUN_a0060dd0, #function
FUN_a0060dd0:
	sethi  %hi(0x9f120000), %o5
	st  %g1, [ %o2 ]
	or  %o5, 0x28, %o4
	ld  [ %o4 ], %g1
	.size FUN_a0060dd0, .-FUN_a0060dd0
