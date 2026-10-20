! leon2s FUN_a0060be0 @ 0xa0060be0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060be0
	.type FUN_a0060be0, #function
FUN_a0060be0:
	st  %g1, [ %o5 ]
	or  %o4, 0x80, %g1
	ld  [ %g1 ], %l1
	or  %o4, 0x48, %o4
	.size FUN_a0060be0, .-FUN_a0060be0
