! leon2s FUN_a0060530 @ 0xa0060530  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060530
	.type FUN_a0060530, #function
FUN_a0060530:
	nop
	ta  0
	rd  %wim, %l3
	mov  %g1, %l7
	.size FUN_a0060530, .-FUN_a0060530
