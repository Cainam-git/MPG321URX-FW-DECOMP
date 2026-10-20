! leon2s FUN_a00608e0 @ 0xa00608e0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00608e0
	.type FUN_a00608e0, #function
FUN_a00608e0:
	ld  [ %o5 ], %o5
	or  %g1, 0x30, %g1
	st  %o5, [ %g1 ]
	b,a ext_a00608a0
	.size FUN_a00608e0, .-FUN_a00608e0
