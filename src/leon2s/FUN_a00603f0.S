! leon2s FUN_a00603f0 @ 0xa00603f0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00603f0
	.type FUN_a00603f0, #function
FUN_a00603f0:
	or  %l4, 0x360, %l4
	ld  [%l4 + 0], %l3
	ld  [ %l4 + 4 ], %l5
	ld  [ %l4 + 8 ], %l6
	.size FUN_a00603f0, .-FUN_a00603f0
