! leon2s FUN_a0060680 @ 0xa0060680  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060680
	.type FUN_a0060680, #function
FUN_a0060680:
	nop
	mov  %g0, %l0
	mov  %g0, %l1
	mov  %g0, %l2
	.size FUN_a0060680, .-FUN_a0060680
