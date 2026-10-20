! leon2s FUN_a0060d30 @ 0xa0060d30  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060d30
	.type FUN_a0060d30, #function
FUN_a0060d30:
	inc  %l2
	btst  %l3, %l0
	be ext_a0060d5c
	sethi  %hi(0x9f120000), %g1
	.size FUN_a0060d30, .-FUN_a0060d30
