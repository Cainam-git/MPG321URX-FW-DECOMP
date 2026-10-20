! leon2s FUN_a0060890 @ 0xa0060890  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060890
	.type FUN_a0060890, #function
FUN_a0060890:
	call FUN_9f1c27fc
	mov  1, %o0
	call FUN_a006fb00
	nop
	.size FUN_a0060890, .-FUN_a0060890
