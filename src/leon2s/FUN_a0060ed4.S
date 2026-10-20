! leon2s FUN_a0060ed4 @ 0xa0060ed4  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060ed4
	.type FUN_a0060ed4, #function
FUN_a0060ed4:
	save  %sp, -104, %sp
	sethi  %hi(0x9f100000), %o5
	or  %o5, 0x90, %o5
	.size FUN_a0060ed4, .-FUN_a0060ed4
