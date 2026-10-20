! leon2s FUN_a0060620 @ 0xa0060620  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060620
	.type FUN_a0060620, #function
FUN_a0060620:
	restore
	restore
	restore
	restore
	.size FUN_a0060620, .-FUN_a0060620
