! leon2s FUN_a0060870 @ 0xa0060870  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060870
	.type FUN_a0060870, #function
FUN_a0060870:
	call FUN_a0072958
	nop
	call FUN_a006d31c
	nop
	.size FUN_a0060870, .-FUN_a0060870
