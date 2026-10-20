! leon2s FUN_a0060fd0 @ 0xa0060fd0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060fd0
	.type FUN_a0060fd0, #function
FUN_a0060fd0:
	sethi  %hi(0x9f100000), %o3
	or  %o3, 0x90, %o2
	ld  [ %o2 ], %g1
	and  %g1, -2049, %g1
	.size FUN_a0060fd0, .-FUN_a0060fd0
