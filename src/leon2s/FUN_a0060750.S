! leon2s FUN_a0060750 @ 0xa0060750  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060750
	.type FUN_a0060750, #function
FUN_a0060750:
	st  %g7, [ %l7 + 0x1c ]
	sethi  %hi(0xa807fc00), %g3
	or  %g3, 0x360, %g3
	mov  %fp, %l7
	.size FUN_a0060750, .-FUN_a0060750
