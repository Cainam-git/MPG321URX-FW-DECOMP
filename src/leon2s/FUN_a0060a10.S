! leon2s FUN_a0060a10 @ 0xa0060a10  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060a10
	.type FUN_a0060a10, #function
FUN_a0060a10:
	st  %g1, [ %o2 ]
	or  %o5, 0x28, %o4
	ld  [ %o4 ], %g1
	or  %g1, 4, %g1
	.size FUN_a0060a10, .-FUN_a0060a10
