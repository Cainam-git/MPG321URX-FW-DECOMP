! leon2s FUN_a00602d0 @ 0xa00602d0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00602d0
	.type FUN_a00602d0, #function
FUN_a00602d0:
	mov  1, %g1
	mov  %g1, %wim
	sethi  %hi(0x1000), %g1
	or  %g1, 0xe0, %g1
	.size FUN_a00602d0, .-FUN_a00602d0
