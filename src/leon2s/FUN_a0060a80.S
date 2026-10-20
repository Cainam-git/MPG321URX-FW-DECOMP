! leon2s FUN_a0060a80 @ 0xa0060a80  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060a80
	.type FUN_a0060a80, #function
FUN_a0060a80:
	mov  8, %g1
	or  %o5, 0x34, %o5
	st  %g1, [ %o5 ]
	or  %o3, 0x9c, %o3
	.size FUN_a0060a80, .-FUN_a0060a80
