! leon2s FUN_a008b2b4 @ 0xa008b2b4  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a008b2b4
	.type FUN_a008b2b4, #function
FUN_a008b2b4:
	ret
	restore
	.size FUN_a008b2b4, .-FUN_a008b2b4
