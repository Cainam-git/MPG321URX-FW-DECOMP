! leon2s FUN_a0060880 @ 0xa0060880  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060880
	.type FUN_a0060880, #function
FUN_a0060880:
	call FUN_a006d3c8
	nop
	call FUN_a00b34a8
	nop
	.size FUN_a0060880, .-FUN_a0060880
