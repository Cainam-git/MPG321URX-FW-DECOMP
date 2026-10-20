! leon2s FUN_a00608c0 @ 0xa00608c0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00608c0
	.type FUN_a00608c0, #function
FUN_a00608c0:
	call FUN_a00700cc
	nop
	call FUN_a006cfe8
	nop
	.size FUN_a00608c0, .-FUN_a00608c0
