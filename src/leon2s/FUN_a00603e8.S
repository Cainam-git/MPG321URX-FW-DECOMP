! leon2s FUN_a00603e8 @ 0xa00603e8  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00603e8
	.type FUN_a00603e8, #function
FUN_a00603e8:
	save  %sp, -64, %sp
	sethi  %hi(0xa807fc00), %l4
	.size FUN_a00603e8, .-FUN_a00603e8
