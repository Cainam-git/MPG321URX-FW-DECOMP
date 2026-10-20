! leon2s FUN_a0060820 @ 0xa0060820  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060820
	.type FUN_a0060820, #function
FUN_a0060820:
	mov  %l3, %g0
	mov  %l4, %g1
	mov  %l5, %g2
	mov  %l6, %g3
	.size FUN_a0060820, .-FUN_a0060820
