! leon2s FUN_a00609d0 @ 0xa00609d0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00609d0
	.type FUN_a00609d0, #function
FUN_a00609d0:
	st  %o3, [ %g1 ]
	or  %o5, 0x28, %o5
	ld  [ %o5 ], %g1
	and  %g1, -3, %g1
	.size FUN_a00609d0, .-FUN_a00609d0
