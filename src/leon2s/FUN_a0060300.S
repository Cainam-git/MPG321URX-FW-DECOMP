! leon2s FUN_a0060300 @ 0xa0060300  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060300
	.type FUN_a0060300, #function
FUN_a0060300:
	call FUN_a0060864
	nop
.La0060308:
	ta  1
	b .La0060308
	.size FUN_a0060300, .-FUN_a0060300
