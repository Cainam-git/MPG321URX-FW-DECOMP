! leon2m FUN_a0028150 @ 0xa0028150  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0028150
	.type FUN_a0028150, #function
FUN_a0028150:
	rd  %psr, %l0
	sethi  %hi(0xa0029000), %l4
	jmp  %l4 + 0xec
	rd  %tbr, %l3
	.size FUN_a0028150, .-FUN_a0028150
