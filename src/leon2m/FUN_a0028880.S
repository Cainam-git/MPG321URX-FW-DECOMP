! leon2m FUN_a0028880 @ 0xa0028880  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0028880
	.type FUN_a0028880, #function
FUN_a0028880:
	ta  0
	nop
	nop
	nop
	.size FUN_a0028880, .-FUN_a0028880
