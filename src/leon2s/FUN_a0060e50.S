! leon2s FUN_a0060e50 @ 0xa0060e50  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060e50
	.type FUN_a0060e50, #function
FUN_a0060e50:
	or  %o3, 0x9c, %o3
	st  %g1, [ %o3 ]
	ld  [ %o4 ], %g1
	and  %g1, -257, %g1
	.size FUN_a0060e50, .-FUN_a0060e50
