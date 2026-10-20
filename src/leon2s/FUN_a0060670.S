! leon2s FUN_a0060670 @ 0xa0060670  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060670
	.type FUN_a0060670, #function
FUN_a0060670:
	rd  %wim, %g7
	mov  %g0, %wim
	nop
	nop
	.size FUN_a0060670, .-FUN_a0060670
