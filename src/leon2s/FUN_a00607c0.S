! leon2s FUN_a00607c0 @ 0xa00607c0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00607c0
	.type FUN_a00607c0, #function
FUN_a00607c0:
	st  %i7, [ %g3 + 0x7c ]
	st  %l0, [ %g3 + 0x80 ]
	st  %l1, [ %g3 + 0x84 ]
	st  %l2, [ %g3 + 0x88 ]
	.size FUN_a00607c0, .-FUN_a00607c0
