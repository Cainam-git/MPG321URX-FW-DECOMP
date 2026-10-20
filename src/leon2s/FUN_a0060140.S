! leon2s FUN_a0060140 @ 0xa0060140  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060140
	.type FUN_a0060140, #function
FUN_a0060140:
	rd  %psr, %l0
	sethi  %hi(0xa0060000), %l4
	jmp  %l4 + 0x3ac
	rd  %tbr, %l3
	.size FUN_a0060140, .-FUN_a0060140
