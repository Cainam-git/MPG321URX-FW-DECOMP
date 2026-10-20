! leon2s FUN_a0060c90 @ 0xa0060c90  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060c90
	.type FUN_a0060c90, #function
FUN_a0060c90:
	st  %o3, [ %g1 ]
	or  %o5, 0x28, %o5
	ld  [ %o5 ], %g1
	and  %g1, -33, %g1
	.size FUN_a0060c90, .-FUN_a0060c90
