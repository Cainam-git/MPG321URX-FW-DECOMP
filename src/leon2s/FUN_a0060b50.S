! leon2s FUN_a0060b50 @ 0xa0060b50  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060b50
	.type FUN_a0060b50, #function
FUN_a0060b50:
	inc  %l2
	or  %g1, 0x7c, %g1
	st  %l0, [ %g1 ]
	call  %o5
	.size FUN_a0060b50, .-FUN_a0060b50
