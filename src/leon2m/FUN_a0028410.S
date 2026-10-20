! leon2m FUN_a0028410 @ 0xa0028410  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0028410
	.type FUN_a0028410, #function
FUN_a0028410:
	ta  0
	nop
	nop
	nop
	.size FUN_a0028410, .-FUN_a0028410
