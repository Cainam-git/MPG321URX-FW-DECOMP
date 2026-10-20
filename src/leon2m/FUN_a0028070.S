! leon2m FUN_a0028070 @ 0xa0028070  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0028070
	.type FUN_a0028070, #function
FUN_a0028070:
	rd  %psr, %l0
	sethi  %hi(0xa0029400), %l4
	jmp  %l4 + 0x60
	rd  %tbr, %l3
	.size FUN_a0028070, .-FUN_a0028070
