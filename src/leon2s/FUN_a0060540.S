! leon2s FUN_a0060540 @ 0xa0060540  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060540
	.type FUN_a0060540, #function
FUN_a0060540:
	srl  %l3, 1, %g1
	sll  %l3, 0xf, %l4
	or  %l4, %g1, %g1
	save
	.size FUN_a0060540, .-FUN_a0060540
