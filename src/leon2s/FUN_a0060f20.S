! leon2s FUN_a0060f20 @ 0xa0060f20  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060f20
	.type FUN_a0060f20, #function
FUN_a0060f20:
	mov  1, %g1
	sll  %g1, %l2, %l0
	btst  %l1, %l0
	sll  %l2, 2, %o5
	.size FUN_a0060f20, .-FUN_a0060f20
