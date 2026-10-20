! leon2m FUN_a0028810 @ 0xa0028810  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0028810
	.type FUN_a0028810, #function
FUN_a0028810:
	jmp  %l2
	.size FUN_a0028810, .-FUN_a0028810
