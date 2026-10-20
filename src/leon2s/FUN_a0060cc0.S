! leon2s FUN_a0060cc0 @ 0xa0060cc0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060cc0
	.type FUN_a0060cc0, #function
FUN_a0060cc0:
	sethi  %hi(0x9f100000), %o5
	or  %o5, 0x90, %o5
	ld  [ %o5 ], %g1
	and  %g1, -65, %g1
	.size FUN_a0060cc0, .-FUN_a0060cc0
