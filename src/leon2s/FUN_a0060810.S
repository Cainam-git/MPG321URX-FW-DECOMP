! leon2s FUN_a0060810 @ 0xa0060810  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060810
	.type FUN_a0060810, #function
FUN_a0060810:
	call  %l7
	nop
	restore
	save
	.size FUN_a0060810, .-FUN_a0060810
