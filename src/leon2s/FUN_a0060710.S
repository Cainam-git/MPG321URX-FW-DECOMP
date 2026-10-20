! leon2s FUN_a0060710 @ 0xa0060710  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060710
	.type FUN_a0060710, #function
FUN_a0060710:
	mov  %l4, %psr
	and  %l5, 0xf, %i0
	.size FUN_a0060710, .-FUN_a0060710
