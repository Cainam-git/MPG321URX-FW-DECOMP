! leon2s FUN_a0060f60 @ 0xa0060f60  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060f60
	.type FUN_a0060f60, #function
FUN_a0060f60:
	inc  %l2
	sethi  %hi(0x9f120000), %g1
	or  %g1, 0x94, %g1
	st  %l0, [ %g1 ]
	.size FUN_a0060f60, .-FUN_a0060f60
