! leon2s FUN_a0060000 @ 0xa0060000  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060000
	.type FUN_a0060000, #function
FUN_a0060000:
	mov  %g0, %l0
	sethi  %hi(0xa0060000), %l4
	jmp  %l4 + 0x2c0
	nop
	.size FUN_a0060000, .-FUN_a0060000
