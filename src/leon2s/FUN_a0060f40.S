! leon2s FUN_a0060f40 @ 0xa0060f40  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060f40
	.type FUN_a0060f40, #function
FUN_a0060f40:
	or  %g1, 0x380, %o3
	ld  [ %o3 + %o5 ], %g1
	call  %g1
	nop
	.size FUN_a0060f40, .-FUN_a0060f40
