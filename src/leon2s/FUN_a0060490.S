! leon2s FUN_a0060490 @ 0xa0060490  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060490
	.type FUN_a0060490, #function
FUN_a0060490:
	sethi  %hi(0xa8076000), %l4
	or  %l4, 0x40, %l4
	srl  %l3, 4, %l3
	and  %l3, 0xff, %l3
	.size FUN_a0060490, .-FUN_a0060490
