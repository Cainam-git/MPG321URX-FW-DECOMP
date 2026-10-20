! leon2s FUN_a0060580 @ 0xa0060580  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060580
	.type FUN_a0060580, #function
FUN_a0060580:
	restore
	mov  %l7, %g1
	.size FUN_a0060580, .-FUN_a0060580
