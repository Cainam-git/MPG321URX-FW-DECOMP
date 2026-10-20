! leon2s FUN_a0060d10 @ 0xa0060d10  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060d10
	.type FUN_a0060d10, #function
FUN_a0060d10:
	btst  %l1, %l0
	be ext_a0060d6c
	sll  %l2, 2, %o5
	sethi  %hi(0xa8079000), %g1
	.size FUN_a0060d10, .-FUN_a0060d10
