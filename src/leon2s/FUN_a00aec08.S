! leon2s FUN_a00aec08 @ 0xa00aec08  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00aec08
	.type FUN_a00aec08, #function
FUN_a00aec08:
	ret
	restore
	.size FUN_a00aec08, .-FUN_a00aec08
