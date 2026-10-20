! leon2s FUN_a0060c60 @ 0xa0060c60  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060c60
	.type FUN_a0060c60, #function
FUN_a0060c60:
	call  %o5
	nop
	inc  %l2
	cmp  %l2, 0xd
	.size FUN_a0060c60, .-FUN_a0060c60
