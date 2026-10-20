! leon2s FUN_a0060c10 @ 0xa0060c10  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060c10
	.type FUN_a0060c10, #function
FUN_a0060c10:
	be ext_a0060c68
	sll  %l2, 2, %o5
	sethi  %hi(0xa8078400), %g1
	or  %g1, 0x370, %g1
	.size FUN_a0060c10, .-FUN_a0060c10
