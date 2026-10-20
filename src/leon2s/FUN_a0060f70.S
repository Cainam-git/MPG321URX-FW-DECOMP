! leon2s FUN_a0060f70 @ 0xa0060f70  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060f70
	.type FUN_a0060f70, #function
FUN_a0060f70:
	ld  [ %o3 + %o5 ], %g1
	call  %g1
	nop
	inc  %l2
	.size FUN_a0060f70, .-FUN_a0060f70
