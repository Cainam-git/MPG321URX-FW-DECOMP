! leon2s FUN_a00607a0 @ 0xa00607a0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00607a0
	.type FUN_a00607a0, #function
FUN_a00607a0:
	restore
	st  %i0, [ %g3 + 0x60 ]
	st  %i1, [ %g3 + 0x64 ]
	st  %i2, [ %g3 + 0x68 ]
	.size FUN_a00607a0, .-FUN_a00607a0
