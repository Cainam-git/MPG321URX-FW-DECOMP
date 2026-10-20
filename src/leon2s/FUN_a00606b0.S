! leon2s FUN_a00606b0 @ 0xa00606b0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00606b0
	.type FUN_a00606b0, #function
FUN_a00606b0:
	mov  %g0, %o3
	mov  %g0, %o4
	mov  %g0, %o5
	mov  %g0, %sp
	.size FUN_a00606b0, .-FUN_a00606b0
