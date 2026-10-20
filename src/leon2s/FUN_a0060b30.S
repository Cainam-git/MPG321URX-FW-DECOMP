! leon2s FUN_a0060b30 @ 0xa0060b30  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060b30
	.type FUN_a0060b30, #function
FUN_a0060b30:
	be ext_a0060b54
	sethi  %hi(0x9f120000), %g1
	call  %o5
	nop
	.size FUN_a0060b30, .-FUN_a0060b30
