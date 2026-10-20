! leon2s FUN_a008c530 @ 0xa008c530  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a008c530
	.type FUN_a008c530, #function
FUN_a008c530:
	ret
	restore
	.size FUN_a008c530, .-FUN_a008c530
