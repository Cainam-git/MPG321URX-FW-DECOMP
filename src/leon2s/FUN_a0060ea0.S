! leon2s FUN_a0060ea0 @ 0xa0060ea0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060ea0
	.type FUN_a0060ea0, #function
FUN_a0060ea0:
	mov  0x200, %g1
	or  %o5, 0x34, %o5
	st  %g1, [ %o5 ]
	or  %o3, 0x9c, %o3
	.size FUN_a0060ea0, .-FUN_a0060ea0
