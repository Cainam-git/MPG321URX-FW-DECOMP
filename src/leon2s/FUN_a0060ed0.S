! leon2s FUN_a0060ed0 @ 0xa0060ed0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060ed0
	.type FUN_a0060ed0, #function
FUN_a0060ed0:
	nop
	.size FUN_a0060ed0, .-FUN_a0060ed0
