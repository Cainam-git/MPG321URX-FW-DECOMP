! leon2m FUN_a0028bb0 @ 0xa0028bb0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0028bb0
	.type FUN_a0028bb0, #function
FUN_a0028bb0:
	ta  0
	nop
	nop
	nop
	.size FUN_a0028bb0, .-FUN_a0028bb0
