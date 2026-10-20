! leon2s FUN_a00602f0 @ 0xa00602f0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00602f0
	.type FUN_a00602f0, #function
FUN_a00602f0:
	sub  %g3, 0x60, %sp
	sethi  %hi(0xa0060000), %g1
	mov  %g1, %tbr
	nop
	.size FUN_a00602f0, .-FUN_a00602f0
