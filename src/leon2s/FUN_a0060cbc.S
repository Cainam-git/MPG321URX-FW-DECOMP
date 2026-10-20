! leon2s FUN_a0060cbc @ 0xa0060cbc  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060cbc
	.type FUN_a0060cbc, #function
FUN_a0060cbc:
	save  %sp, -104, %sp
	.size FUN_a0060cbc, .-FUN_a0060cbc
