! leon2s FUN_a0060340 @ 0xa0060340  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060340
	.type FUN_a0060340, #function
FUN_a0060340:
	rd  %psr, %l0
	nop
	nop
	sethi  %hi(0xa0061000), %l4
	.size FUN_a0060340, .-FUN_a0060340
