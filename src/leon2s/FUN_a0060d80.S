! leon2s FUN_a0060d80 @ 0xa0060d80  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060d80
	.type FUN_a0060d80, #function
FUN_a0060d80:
	or  %o5, 0x34, %g1
	mov  0x40, %o3
	st  %o3, [ %g1 ]
	sethi  %hi(0x9f100000), %o4
	.size FUN_a0060d80, .-FUN_a0060d80
