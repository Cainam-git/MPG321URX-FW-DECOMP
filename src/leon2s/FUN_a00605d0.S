! leon2s FUN_a00605d0 @ 0xa00605d0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00605d0
	.type FUN_a00605d0, #function
FUN_a00605d0:
	ldd  [ %sp + 0x30 ], %i4
	ldd  [ %sp + 0x38 ], %fp
	save
	save
	.size FUN_a00605d0, .-FUN_a00605d0
