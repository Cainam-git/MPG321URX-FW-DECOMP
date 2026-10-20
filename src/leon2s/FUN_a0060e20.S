! leon2s FUN_a0060e20 @ 0xa0060e20  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060e20
	.type FUN_a0060e20, #function
FUN_a0060e20:
	or  %o3, 0x90, %o2
	ld  [ %o2 ], %g1
	and  %g1, -257, %g1
	sethi  %hi(0x9f120000), %o5
	.size FUN_a0060e20, .-FUN_a0060e20
