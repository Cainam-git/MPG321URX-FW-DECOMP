! leon2m FUN_a0028030 @ 0xa0028030  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0028030
	.type FUN_a0028030, #function
FUN_a0028030:
	rd  %psr, %l0
	sethi  %hi(0xa0029400), %l4
	jmp  %l4 + 0x60
	rd  %tbr, %l3
	.size FUN_a0028030, .-FUN_a0028030
