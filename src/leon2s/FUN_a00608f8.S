! leon2s FUN_a00608f8 @ 0xa00608f8  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00608f8
	.type FUN_a00608f8, #function
FUN_a00608f8:
	save  %sp, -104, %sp
	sethi  %hi(0x9f100000), %o5
	.size FUN_a00608f8, .-FUN_a00608f8
