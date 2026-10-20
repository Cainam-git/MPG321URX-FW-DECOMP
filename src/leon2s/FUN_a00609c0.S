! leon2s FUN_a00609c0 @ 0xa00609c0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00609c0
	.type FUN_a00609c0, #function
FUN_a00609c0:
	mov  2, %o3
	st  %o3, [ %g1 ]
	sethi  %hi(0x9f100000), %o4
	or  %o4, 0x9c, %g1
	.size FUN_a00609c0, .-FUN_a00609c0
