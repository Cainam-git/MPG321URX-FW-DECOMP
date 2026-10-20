! leon2s FUN_a0060a60 @ 0xa0060a60  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060a60
	.type FUN_a0060a60, #function
FUN_a0060a60:
	ld  [ %o2 ], %g1
	and  %g1, -9, %g1
	sethi  %hi(0x9f120000), %o5
	st  %g1, [ %o2 ]
	.size FUN_a0060a60, .-FUN_a0060a60
