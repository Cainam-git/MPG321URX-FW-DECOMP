! leon2s FUN_a00609e0 @ 0xa00609e0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00609e0
	.type FUN_a00609e0, #function
FUN_a00609e0:
	st  %g1, [ %o5 ]
	or  %o4, 0x90, %o4
	ld  [ %o4 ], %g1
	or  %g1, 2, %g1
	.size FUN_a00609e0, .-FUN_a00609e0
