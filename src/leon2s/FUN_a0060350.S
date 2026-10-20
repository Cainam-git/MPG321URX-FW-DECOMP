! leon2s FUN_a0060350 @ 0xa0060350  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060350
	.type FUN_a0060350, #function
FUN_a0060350:
	or  %l4, 0x224, %l4
	mov  %l4, %l7
	mov  %g0, %l1
	mov  %g1, %l2
	.size FUN_a0060350, .-FUN_a0060350
