! leon2s FUN_a0060600 @ 0xa0060600  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060600
	.type FUN_a0060600, #function
FUN_a0060600:
	nop
	save
	save
	save
	.size FUN_a0060600, .-FUN_a0060600
