! leon2s FUN_a00606d0 @ 0xa00606d0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00606d0
	.type FUN_a00606d0, #function
FUN_a00606d0:
	inc  %g1
	mov  %g7, %wim
	nop
	nop
	.size FUN_a00606d0, .-FUN_a00606d0
