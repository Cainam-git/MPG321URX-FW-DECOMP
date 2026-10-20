! leon2s FUN_a0060360 @ 0xa0060360  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060360
	.type FUN_a0060360, #function
FUN_a0060360:
	mov  %g2, %l3
	mov  %g3, %l4
	call  %l7
	nop
	.size FUN_a0060360, .-FUN_a0060360
