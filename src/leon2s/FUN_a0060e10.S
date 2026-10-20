! leon2s FUN_a0060e10 @ 0xa0060e10  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060e10
	.type FUN_a0060e10, #function
FUN_a0060e10:
	st  %g1, [ %o2 ]
	retl
	nop
	.size FUN_a0060e10, .-FUN_a0060e10
