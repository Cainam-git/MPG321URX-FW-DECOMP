! leon2s FUN_a008cba0 @ 0xa008cba0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a008cba0
	.type FUN_a008cba0, #function
FUN_a008cba0:
	ret
	restore
	.size FUN_a008cba0, .-FUN_a008cba0
