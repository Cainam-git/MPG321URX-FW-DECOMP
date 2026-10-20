! leon2s FUN_a0060660 @ 0xa0060660  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060660
	.type FUN_a0060660, #function
FUN_a0060660:
	mov  %g0, %g4
	mov  %g0, %g5
	mov  %g0, %g6
	mov  %g0, %g7
	.size FUN_a0060660, .-FUN_a0060660
