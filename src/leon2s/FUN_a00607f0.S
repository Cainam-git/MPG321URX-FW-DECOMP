! leon2s FUN_a00607f0 @ 0xa00607f0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00607f0
	.type FUN_a00607f0, #function
FUN_a00607f0:
	ld  [ %l7 + 0xc ], %g3
	sethi  %hi(0xa8076000), %l3
	or  %l3, 0x88, %l3
	ld  [ %l3 ], %l7
	.size FUN_a00607f0, .-FUN_a00607f0
