! leon2s FUN_a0060c50 @ 0xa0060c50  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060c50
	.type FUN_a0060c50, #function
FUN_a0060c50:
	b ext_a0060c6c
	inc  %l2
	.size FUN_a0060c50, .-FUN_a0060c50
