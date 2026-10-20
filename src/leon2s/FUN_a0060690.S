! leon2s FUN_a0060690 @ 0xa0060690  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060690
	.type FUN_a0060690, #function
FUN_a0060690:
	mov  %g0, %l3
	mov  %g0, %l4
	mov  %g0, %l5
	mov  %g0, %l6
	.size FUN_a0060690, .-FUN_a0060690
