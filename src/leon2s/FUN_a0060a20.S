! leon2s FUN_a0060a20 @ 0xa0060a20  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060a20
	.type FUN_a0060a20, #function
FUN_a0060a20:
	st  %g1, [ %o4 ]
	mov  4, %g1
	or  %o5, 0x34, %o5
	st  %g1, [ %o5 ]
	.size FUN_a0060a20, .-FUN_a0060a20
