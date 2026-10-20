! leon2s FUN_a0060790 @ 0xa0060790  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060790
	.type FUN_a0060790, #function
FUN_a0060790:
	st  %i4, [ %g3 + 0x50 ]
	st  %i5, [ %g3 + 0x54 ]
	st  %fp, [ %g3 + 0x58 ]
	st  %i7, [ %g3 + 0x5c ]
	.size FUN_a0060790, .-FUN_a0060790
