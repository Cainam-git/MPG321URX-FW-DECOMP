! leon2s FUN_a0060d60 @ 0xa0060d60  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060d60
	.type FUN_a0060d60, #function
FUN_a0060d60:
	st  %l0, [ %g1 ]
	call  %o5
	nop
	inc  %l2
	.size FUN_a0060d60, .-FUN_a0060d60
