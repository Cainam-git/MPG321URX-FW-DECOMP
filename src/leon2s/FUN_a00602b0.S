! leon2s FUN_a00602b0 @ 0xa00602b0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00602b0
	.type FUN_a00602b0, #function
FUN_a00602b0:
	rd  %psr, %l0
	sethi  %hi(0xa0060400), %l4
	jmp  %l4 + 0x104
	rd  %tbr, %l3
	.size FUN_a00602b0, .-FUN_a00602b0
