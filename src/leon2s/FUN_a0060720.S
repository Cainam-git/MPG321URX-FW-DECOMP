! leon2s FUN_a0060720 @ 0xa0060720  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060720
	.type FUN_a0060720, #function
FUN_a0060720:
	rd  %wim, %l4
	mov  %sp, %l5
	rd  %y, %l6
	sethi  %hi(0xa807fc00), %l7
	.size FUN_a0060720, .-FUN_a0060720
