! leon2m FUN_a00281e0 @ 0xa00281e0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00281e0
	.type FUN_a00281e0, #function
FUN_a00281e0:
	rd  %psr, %l0
	sethi  %hi(0xa0029000), %l4
	jmp  %l4 + 0xec
	rd  %tbr, %l3
	.size FUN_a00281e0, .-FUN_a00281e0
