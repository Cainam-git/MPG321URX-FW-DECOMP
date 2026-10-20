! leon2s FUN_a0060940 @ 0xa0060940  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060940
	.type FUN_a0060940, #function
FUN_a0060940:
	or %g0, 0, %l2
	mov  1, %g1
	sll  %g1, %l2, %l0
	btst  %l1, %l0
	.size FUN_a0060940, .-FUN_a0060940
