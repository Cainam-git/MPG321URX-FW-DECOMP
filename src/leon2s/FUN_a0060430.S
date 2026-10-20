! leon2s FUN_a0060430 @ 0xa0060430  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060430
	.type FUN_a0060430, #function
FUN_a0060430:
	std  %g6, [ %l4 + 0x10 ]
	st  %g1, [ %l4 + 0x18 ]
	rd  %y, %l3
	st  %l3, [ %l4 + 0x1c ]
	.size FUN_a0060430, .-FUN_a0060430
