! leon2s FUN_a0060f90 @ 0xa0060f90  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060f90
	.type FUN_a0060f90, #function
FUN_a0060f90:
	or  %o5, 0x34, %g1
	mov  0x400, %o3
	st  %o3, [ %g1 ]
	sethi  %hi(0x9f100000), %o4
	.size FUN_a0060f90, .-FUN_a0060f90
