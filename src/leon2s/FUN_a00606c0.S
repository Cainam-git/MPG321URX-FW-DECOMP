! leon2s FUN_a00606c0 @ 0xa00606c0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00606c0
	.type FUN_a00606c0, #function
FUN_a00606c0:
	mov  %g0, %o7
	save
	cmp  %g1, 7
	bne ext_a0060684
	.size FUN_a00606c0, .-FUN_a00606c0
