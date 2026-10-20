! leon2s FUN_a0060400 @ 0xa0060400  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060400
	.type FUN_a0060400, #function
FUN_a0060400:
	rd  %psr, %l0
	nop
	nop
	srl  %l3, 4, %l3
	.size FUN_a0060400, .-FUN_a0060400
