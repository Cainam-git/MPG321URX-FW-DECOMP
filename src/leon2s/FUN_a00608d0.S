! leon2s FUN_a00608d0 @ 0xa00608d0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00608d0
	.type FUN_a00608d0, #function
FUN_a00608d0:
	call FUN_9f1c3c40
	nop
	sethi  %hi(0xcf03c800), %g1
	or  %g1, 0x20, %o5
	.size FUN_a00608d0, .-FUN_a00608d0
