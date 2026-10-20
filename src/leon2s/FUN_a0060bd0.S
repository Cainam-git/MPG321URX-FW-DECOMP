! leon2s FUN_a0060bd0 @ 0xa0060bd0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060bd0
	.type FUN_a0060bd0, #function
FUN_a0060bd0:
	sethi  %hi(0x9f120000), %o4
	or  %o4, 0x28, %o5
	ld  [ %o5 ], %g1
	or  %g1, 0x20, %g1
	.size FUN_a0060bd0, .-FUN_a0060bd0
