! leon2s FUN_a0060ff0 @ 0xa0060ff0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060ff0
	.type FUN_a0060ff0, #function
FUN_a0060ff0:
	or  %g1, 0x800, %g1
	st  %g1, [ %o4 ]
	mov  0x800, %g1
	or  %o5, 0x34, %o5
	st  %g1, [ %o5 ]
	or  %o3, 0x9c, %o3
	st  %g1, [ %o3 ]
	ld  [ %o4 ], %g1
	and  %g1, -2049, %g1
	st  %g1, [ %o4 ]
	ld  [ %o2 ], %g1
	or  %g1, 0x800, %g1
	st  %g1, [ %o2 ]
	retl
	nop
	.size FUN_a0060ff0, .-FUN_a0060ff0
