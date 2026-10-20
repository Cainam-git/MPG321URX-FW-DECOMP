! leon2s FUN_a0060500 @ 0xa0060500  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060500
	.type FUN_a0060500, #function
FUN_a0060500:
	rett  %l2 + 4
	sethi  %hi(0xa8076000), %l4
	.size FUN_a0060500, .-FUN_a0060500
