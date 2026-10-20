! leon2s FUN_a0060d40 @ 0xa0060d40  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060d40
	.type FUN_a0060d40, #function
FUN_a0060d40:
	call  %o5
	nop
	sethi  %hi(0x9f120000), %g1
	or  %g1, 0x84, %g1
	.size FUN_a0060d40, .-FUN_a0060d40
