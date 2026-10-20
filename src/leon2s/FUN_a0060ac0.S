! leon2s FUN_a0060ac0 @ 0xa0060ac0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060ac0
	.type FUN_a0060ac0, #function
FUN_a0060ac0:
	ld  [ %o5 ], %g1
	and  %g1, -17, %g1
	st  %g1, [ %o5 ]
	sethi  %hi(0x9f120000), %o4
	.size FUN_a0060ac0, .-FUN_a0060ac0
