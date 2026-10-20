! leon2s FUN_a00604a0 @ 0xa00604a0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00604a0
	.type FUN_a00604a0, #function
FUN_a00604a0:
	sub  %l3, 0x11, %l3
	sll  %l3, 2, %l3
	ld  [ %l4 + %l3 ], %l3
	call  %l3
	.size FUN_a00604a0, .-FUN_a00604a0
