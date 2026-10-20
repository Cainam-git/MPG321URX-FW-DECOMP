! leon2s FUN_a00608b0 @ 0xa00608b0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00608b0
	.type FUN_a00608b0, #function
FUN_a00608b0:
	call FUN_a006fa28
	nop
	call FUN_a00b28d0
	nop
	.size FUN_a00608b0, .-FUN_a00608b0
