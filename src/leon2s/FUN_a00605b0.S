! leon2s FUN_a00605b0 @ 0xa00605b0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00605b0
	.type FUN_a00605b0, #function
FUN_a00605b0:
	restore
	restore
	ldd  [%sp + 0], %l0
	ldd  [ %sp + 8 ], %l2
	.size FUN_a00605b0, .-FUN_a00605b0
