! leon2s FUN_a0060b80 @ 0xa0060b80  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060b80
	.type FUN_a0060b80, #function
FUN_a0060b80:
	st  %o3, [ %g1 ]
	sethi  %hi(0x9f100000), %o4
	or  %o4, 0x9c, %g1
	st  %o3, [ %g1 ]
	.size FUN_a0060b80, .-FUN_a0060b80
