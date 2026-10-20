! leon2s FUN_a00609a0 @ 0xa00609a0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00609a0
	.type FUN_a00609a0, #function
FUN_a00609a0:
	call  %o5
	nop
	inc  %l2
	cmp  %l2, 5
	.size FUN_a00609a0, .-FUN_a00609a0
