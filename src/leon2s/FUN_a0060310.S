! leon2s FUN_a0060310 @ 0xa0060310  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060310
	.type FUN_a0060310, #function
FUN_a0060310:
	nop
	.size FUN_a0060310, .-FUN_a0060310
