! leon2s FUN_a0060f30 @ 0xa0060f30  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060f30
	.type FUN_a0060f30, #function
FUN_a0060f30:
	be ext_a0060f7c
	sethi  %hi(0xa8079000), %g1
	btst  %l3, %l0
	be ext_a0060f64
	.size FUN_a0060f30, .-FUN_a0060f30
