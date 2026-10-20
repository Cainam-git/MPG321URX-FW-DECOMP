! leon2s FUN_a0060b20 @ 0xa0060b20  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060b20
	.type FUN_a0060b20, #function
FUN_a0060b20:
	cmp  %o5, 0
	be,a ext_a0060b68
	inc  %l2
	btst  %l3, %l0
	.size FUN_a0060b20, .-FUN_a0060b20
