! leon2s FUN_a0060370 @ 0xa0060370  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060370
	.type FUN_a0060370, #function
FUN_a0060370:
	restore
	save
	mov  %l1, %g0
	mov  %l2, %g1
	.size FUN_a0060370, .-FUN_a0060370
