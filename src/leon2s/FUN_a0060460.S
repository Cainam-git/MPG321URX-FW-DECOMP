! leon2s FUN_a0060460 @ 0xa0060460  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060460
	.type FUN_a0060460, #function
FUN_a0060460:
	ld  [ %l4 + 0x1c ], %l3
	mov  %l3, %y
	nop
	wr  %l0, 0x20, %psr
	.size FUN_a0060460, .-FUN_a0060460
