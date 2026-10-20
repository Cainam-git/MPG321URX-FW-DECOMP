! leon2s FUN_a0060b40 @ 0xa0060b40  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060b40
	.type FUN_a0060b40, #function
FUN_a0060b40:
	sethi  %hi(0x9f120000), %g1
	or  %g1, 0x7c, %g1
	st  %l0, [ %g1 ]
	b ext_a0060b68
	.size FUN_a0060b40, .-FUN_a0060b40
