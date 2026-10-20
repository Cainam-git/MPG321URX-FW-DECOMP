! leon2s FUN_a0060450 @ 0xa0060450  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060450
	.type FUN_a0060450, #function
FUN_a0060450:
	ldd  [%l4 + 0], %g2
	ldd  [ %l4 + 8 ], %g4
	ldd  [ %l4 + 0x10 ], %g6
	ld  [ %l4 + 0x18 ], %g1
	.size FUN_a0060450, .-FUN_a0060450
