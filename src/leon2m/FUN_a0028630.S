! leon2m FUN_a0028630 @ 0xa0028630  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0028630
	.type FUN_a0028630, #function
FUN_a0028630:
	ta  0
	nop
	nop
	nop
	.size FUN_a0028630, .-FUN_a0028630
