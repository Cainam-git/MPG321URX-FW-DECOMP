! leon2s FUN_a0060864 @ 0xa0060864  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060864
	.type FUN_a0060864, #function
FUN_a0060864:
	save  %sp, -104, %sp
	call FUN_a00b18d0
	nop
	.size FUN_a0060864, .-FUN_a0060864
