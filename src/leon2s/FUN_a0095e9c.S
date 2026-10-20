! leon2s FUN_a0095e9c @ 0xa0095e9c  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0095e9c
	.type FUN_a0095e9c, #function
FUN_a0095e9c:
	ret
	restore
	.size FUN_a0095e9c, .-FUN_a0095e9c
