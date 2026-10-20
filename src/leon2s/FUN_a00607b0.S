! leon2s FUN_a00607b0 @ 0xa00607b0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00607b0
	.type FUN_a00607b0, #function
FUN_a00607b0:
	st  %i3, [ %g3 + 0x6c ]
	st  %i4, [ %g3 + 0x70 ]
	st  %i5, [ %g3 + 0x74 ]
	st  %fp, [ %g3 + 0x78 ]
	.size FUN_a00607b0, .-FUN_a00607b0
