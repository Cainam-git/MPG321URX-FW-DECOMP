! leon2s FUN_a0060760 @ 0xa0060760  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060760
	.type FUN_a0060760, #function
FUN_a0060760:
	st  %l0, [ %g3 + 0x20 ]
	st  %l1, [ %g3 + 0x24 ]
	st  %l2, [ %g3 + 0x28 ]
	st  %l3, [ %g3 + 0x2c ]
	.size FUN_a0060760, .-FUN_a0060760
