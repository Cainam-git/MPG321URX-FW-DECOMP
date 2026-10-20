! leon2s FUN_a00604f0 @ 0xa00604f0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00604f0
	.type FUN_a00604f0, #function
FUN_a00604f0:
	mov  %l2, %g1
	.size FUN_a00604f0, .-FUN_a00604f0
