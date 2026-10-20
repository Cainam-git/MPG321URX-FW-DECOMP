! leon2s FUN_a00605c0 @ 0xa00605c0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00605c0
	.type FUN_a00605c0, #function
FUN_a00605c0:
	ldd  [ %sp + 0x10 ], %l4
	ldd  [ %sp + 0x18 ], %l6
	ldd  [ %sp + 0x20 ], %i0
	ldd  [ %sp + 0x28 ], %i2
	.size FUN_a00605c0, .-FUN_a00605c0
