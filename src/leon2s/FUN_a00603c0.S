! leon2s FUN_a00603c0 @ 0xa00603c0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00603c0
	.type FUN_a00603c0, #function
FUN_a00603c0:
	wr  %l0, 0x20, %psr
	nop
	nop
	nop
	.size FUN_a00603c0, .-FUN_a00603c0
