! leon2s FUN_a0060390 @ 0xa0060390  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060390
	.type FUN_a0060390, #function
FUN_a0060390:
	andn  %l0, 0xf00, %l4
	wr  %l4, 0x20, %psr
	nop
	nop
	.size FUN_a0060390, .-FUN_a0060390
