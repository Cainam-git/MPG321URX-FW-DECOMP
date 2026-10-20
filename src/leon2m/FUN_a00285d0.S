! leon2m FUN_a00285d0 @ 0xa00285d0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00285d0
	.type FUN_a00285d0, #function
FUN_a00285d0:
	ta  0
	nop
	nop
	nop
	.size FUN_a00285d0, .-FUN_a00285d0
