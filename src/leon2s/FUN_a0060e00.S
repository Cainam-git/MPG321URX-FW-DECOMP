! leon2s FUN_a0060e00 @ 0xa0060e00  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060e00
	.type FUN_a0060e00, #function
FUN_a0060e00:
	and  %g1, -129, %g1
	st  %g1, [ %o4 ]
	ld  [ %o2 ], %g1
	or  %g1, 0x80, %g1
	.size FUN_a0060e00, .-FUN_a0060e00
