! leon2s FUN_a0060960 @ 0xa0060960  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060960
	.type FUN_a0060960, #function
FUN_a0060960:
	ld  [ %g1 + %o5 ], %o5
	cmp  %o5, 0
	be,a ext_a00609ac
	inc  %l2
	.size FUN_a0060960, .-FUN_a0060960
