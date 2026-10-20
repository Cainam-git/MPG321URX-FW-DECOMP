! leon2s FUN_a0060c40 @ 0xa0060c40  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060c40
	.type FUN_a0060c40, #function
FUN_a0060c40:
	nop
	sethi  %hi(0x9f120000), %g1
	or  %g1, 0x80, %g1
	st  %l0, [ %g1 ]
	.size FUN_a0060c40, .-FUN_a0060c40
