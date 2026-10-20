! leon2m FUN_a0028ba0 @ 0xa0028ba0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0028ba0
	.type FUN_a0028ba0, #function
FUN_a0028ba0:
	ta  0
	nop
	nop
	nop
	.size FUN_a0028ba0, .-FUN_a0028ba0
