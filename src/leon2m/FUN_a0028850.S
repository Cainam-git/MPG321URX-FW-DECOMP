! leon2m FUN_a0028850 @ 0xa0028850  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0028850
	.type FUN_a0028850, #function
FUN_a0028850:
	ta  0
	nop
	nop
	nop
	.size FUN_a0028850, .-FUN_a0028850
