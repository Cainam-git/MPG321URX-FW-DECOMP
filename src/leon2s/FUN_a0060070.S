! leon2s FUN_a0060070 @ 0xa0060070  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060070
	.type FUN_a0060070, #function
FUN_a0060070:
	rd  %psr, %l0
	sethi  %hi(0xa0060400), %l4
	jmp  %l4 + 0x320
	rd  %tbr, %l3
	.size FUN_a0060070, .-FUN_a0060070
