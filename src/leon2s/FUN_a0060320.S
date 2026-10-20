! leon2s FUN_a0060320 @ 0xa0060320  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060320
	.type FUN_a0060320, #function
FUN_a0060320:
	save  %sp, -64, %sp
	rd  %psr, %l0
	or  %l0, 0xf00, %l0
	mov  %l0, %psr
	.size FUN_a0060320, .-FUN_a0060320
