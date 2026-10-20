! leon2m FUN_a00280b0 @ 0xa00280b0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00280b0
	.type FUN_a00280b0, #function
FUN_a00280b0:
	rd  %psr, %l0
	sethi  %hi(0xa0029000), %l4
	jmp  %l4 + 0x220
	rd  %tbr, %l3
	.size FUN_a00280b0, .-FUN_a00280b0
