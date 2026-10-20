! leon2s FUN_a0060c20 @ 0xa0060c20  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060c20
	.type FUN_a0060c20, #function
FUN_a0060c20:
	ld  [ %g1 + %o5 ], %o5
	cmp  %o5, 0
	be,a ext_a0060c6c
	inc  %l2
	.size FUN_a0060c20, .-FUN_a0060c20
