! leon2s FUN_a0060330 @ 0xa0060330  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060330
	.type FUN_a0060330, #function
FUN_a0060330:
	wr  %l0, 0x20, %psr
	nop
	nop
	nop
	.size FUN_a0060330, .-FUN_a0060330
