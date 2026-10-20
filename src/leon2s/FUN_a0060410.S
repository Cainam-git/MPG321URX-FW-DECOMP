! leon2s FUN_a0060410 @ 0xa0060410  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060410
	.type FUN_a0060410, #function
FUN_a0060410:
	and  %l3, 0xff, %l3
	sub  %l3, 0x11, %l3
	sll  %l3, 2, %l3
	sethi  %hi(0xa8076000), %l1
	.size FUN_a0060410, .-FUN_a0060410
