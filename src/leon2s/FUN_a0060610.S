! leon2s FUN_a0060610 @ 0xa0060610  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060610
	.type FUN_a0060610, #function
FUN_a0060610:
	save
	save
	save
	restore
	.size FUN_a0060610, .-FUN_a0060610
