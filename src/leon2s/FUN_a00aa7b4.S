! leon2s FUN_a00aa7b4 @ 0xa00aa7b4  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00aa7b4
	.type FUN_a00aa7b4, #function
FUN_a00aa7b4:
	ret
	restore
	.size FUN_a00aa7b4, .-FUN_a00aa7b4
