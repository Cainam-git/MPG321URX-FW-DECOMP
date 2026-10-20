! leon2s FUN_a0060420 @ 0xa0060420  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060420
	.type FUN_a0060420, #function
FUN_a0060420:
	or  %l1, 0x40, %l1
	ld  [ %l1 + %l3 ], %l7
	std  %g2, [%l4 + 0]
	std  %g4, [ %l4 + 8 ]
	.size FUN_a0060420, .-FUN_a0060420
