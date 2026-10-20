! leon2s FUN_a00d661c @ 0xa00d661c  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00d661c
	.type FUN_a00d661c, #function
FUN_a00d661c:
	ret
	restore
	.size FUN_a00d661c, .-FUN_a00d661c
