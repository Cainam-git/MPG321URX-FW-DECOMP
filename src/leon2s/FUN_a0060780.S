! leon2s FUN_a0060780 @ 0xa0060780  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060780
	.type FUN_a0060780, #function
FUN_a0060780:
	st  %i0, [ %g3 + 0x40 ]
	st  %i1, [ %g3 + 0x44 ]
	st  %i2, [ %g3 + 0x48 ]
	st  %i3, [ %g3 + 0x4c ]
	.size FUN_a0060780, .-FUN_a0060780
