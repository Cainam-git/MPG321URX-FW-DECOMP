! leon2s FUN_a0060cd0 @ 0xa0060cd0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060cd0
	.type FUN_a0060cd0, #function
FUN_a0060cd0:
	st  %g1, [ %o5 ]
	sethi  %hi(0x9f120000), %o4
	or  %o4, 0x28, %o5
	ld  [ %o5 ], %g1
	.size FUN_a0060cd0, .-FUN_a0060cd0
