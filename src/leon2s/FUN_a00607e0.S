! leon2s FUN_a00607e0 @ 0xa00607e0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00607e0
	.type FUN_a00607e0, #function
FUN_a00607e0:
	st  %l7, [ %g3 + 0x9c ]
	save
	sethi  %hi(0xa807fc00), %l7
	or  %l7, 0x360, %l7
	.size FUN_a00607e0, .-FUN_a00607e0
