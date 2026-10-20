! leon2s FUN_a0060990 @ 0xa0060990  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060990
	.type FUN_a0060990, #function
FUN_a0060990:
	b ext_a00609ac
	inc  %l2
	.size FUN_a0060990, .-FUN_a0060990
