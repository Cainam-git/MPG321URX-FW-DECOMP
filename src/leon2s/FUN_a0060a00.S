! leon2s FUN_a0060a00 @ 0xa0060a00  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060a00
	.type FUN_a0060a00, #function
FUN_a0060a00:
	or  %o3, 0x90, %o2
	ld  [ %o2 ], %g1
	and  %g1, -5, %g1
	sethi  %hi(0x9f120000), %o5
	.size FUN_a0060a00, .-FUN_a0060a00
