! leon2s FUN_a00603d0 @ 0xa00603d0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00603d0
	.type FUN_a00603d0, #function
FUN_a00603d0:
	sethi  %hi(0xa807fc00), %l4
	or  %l4, 0x360, %l4
	st  %l3, [%l4 + 0]
	st  %l5, [ %l4 + 4 ]
	.size FUN_a00603d0, .-FUN_a00603d0
