! leon2s FUN_a00607d0 @ 0xa00607d0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00607d0
	.type FUN_a00607d0, #function
FUN_a00607d0:
	st  %l3, [ %g3 + 0x8c ]
	st  %l4, [ %g3 + 0x90 ]
	st  %l5, [ %g3 + 0x94 ]
	st  %l6, [ %g3 + 0x98 ]
	.size FUN_a00607d0, .-FUN_a00607d0
