! leon2s FUN_a00606a0 @ 0xa00606a0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00606a0
	.type FUN_a00606a0, #function
FUN_a00606a0:
	mov  %g0, %l7
	mov  %g0, %o0
	mov  %g0, %o1
	mov  %g0, %o2
	.size FUN_a00606a0, .-FUN_a00606a0
