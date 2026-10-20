! leon2s FUN_a0060980 @ 0xa0060980  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060980
	.type FUN_a0060980, #function
FUN_a0060980:
	nop
	sethi  %hi(0x9f120000), %g1
	or  %g1, 0x70, %g1
	st  %l0, [ %g1 ]
	.size FUN_a0060980, .-FUN_a0060980
