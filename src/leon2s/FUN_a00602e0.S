! leon2s FUN_a00602e0 @ 0xa00602e0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00602e0
	.type FUN_a00602e0, #function
FUN_a00602e0:
	mov  %g1, %psr
	sethi  %hi(0xa807fc00), %g3
	or  %g3, 0x350, %g3
	mov  %g3, %fp
	.size FUN_a00602e0, .-FUN_a00602e0
