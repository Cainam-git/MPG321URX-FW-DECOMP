! leon2s FUN_a00604e0 @ 0xa00604e0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00604e0
	.type FUN_a00604e0, #function
FUN_a00604e0:
	ld  [ %l1 ], %l5
	sethi  %hi(0xa8076000), %l6
	or  %l6, 0x8c, %l6
	st  %l5, [ %l6 ]
	.size FUN_a00604e0, .-FUN_a00604e0
