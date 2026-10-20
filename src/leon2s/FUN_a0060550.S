! leon2s FUN_a0060550 @ 0xa0060550  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060550
	.type FUN_a0060550, #function
FUN_a0060550:
	mov  %g1, %wim
	nop
	nop
	nop
	.size FUN_a0060550, .-FUN_a0060550
